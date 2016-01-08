#include <mali_kbase.h>
#include <mali_kbase_mem.h>

#include <linux/proc_fs.h>

#include <platform/mtk_platform_common.h>

#ifdef ENABLE_MTK_MEMINFO
/*
   Add by mediatek, Hook the memory query function pointer to (*mtk_get_gpu_memory_usage_fp) in order to
   provide the gpu total memory usage to mlogger module
*/
extern unsigned int (*mtk_get_gpu_memory_usage_fp)(void);

/*
   Add by mediatek, Hook the memory dump function pointer to (*ged_mem_dump_gpu_memory_usag_fp) in order to
   provide the gpu detail memory usage by PID to mlogger module
*/
extern bool (*mtk_dump_gpu_memory_usage_fp)(void);

int g_mtk_gpu_total_memory_usage_in_pages_debugfs;
atomic_t g_mtk_gpu_total_memory_usage_in_pages;
atomic_t g_mtk_gpu_peak_memory_usage_in_pages;
static mtk_gpu_meminfo_type g_mtk_gpu_meminfo[MTK_MEMINFO_SIZE];

void mtk_kbase_gpu_memory_debug_init()
{
	mtk_dump_gpu_memory_usage_fp = mtk_kbase_dump_gpu_memory_usage;
	mtk_get_gpu_memory_usage_fp = mtk_kbase_report_gpu_memory_usage;
}

void mtk_kbase_gpu_memory_debug_remove()
{
	mtk_dump_gpu_memory_usage_fp = NULL;
	mtk_get_gpu_memory_usage_fp = NULL;
}

void mtk_kbase_reset_gpu_meminfo()
{
	int i = 0;
	for(i = 0; i < MTK_MEMINFO_SIZE; i++) {
		g_mtk_gpu_meminfo[i].pid = 0;
		g_mtk_gpu_meminfo[i].used_pages = 0;
	}
}

void mtk_kbase_set_gpu_meminfo(ssize_t index, int pid, int used_pages)
{
	g_mtk_gpu_meminfo[index].pid = pid;
	g_mtk_gpu_meminfo[index].used_pages = used_pages;
}

KBASE_EXPORT_TEST_API(mtk_kbase_dump_gpu_memory_usage)
bool mtk_kbase_dump_gpu_memory_usage()
{
	int i = 0;

	//output the total memory usage and cap for this device
	pr_warn(KERN_DEBUG "%10s\t%16s\n", "PID", "Memory by Page");
	pr_warn(KERN_DEBUG "============================\n");

	for(i = 0; (i < MTK_MEMINFO_SIZE) && (g_mtk_gpu_meminfo[i].pid != 0); i++) {
		pr_warn(KERN_DEBUG "%10d\t%16d\n", g_mtk_gpu_meminfo[i].pid, \
                                        g_mtk_gpu_meminfo[i].used_pages);
        }

	pr_warn(KERN_DEBUG "============================\n");
	pr_warn(KERN_DEBUG "%10s\t%16u\n", \
			"Total", \
			g_mtk_gpu_total_memory_usage_in_pages_debugfs);
	pr_warn(KERN_DEBUG "============================\n");
	return true;
}

KBASE_EXPORT_TEST_API(mtk_kbase_report_gpu_memory_usage)
unsigned int mtk_kbase_report_gpu_memory_usage()
{
#if 0
	ssize_t ret = 0;
	struct list_head *entry;
	const struct list_head *kbdev_list;
   int pages = 0;
	kbdev_list = kbase_dev_list_get();
	list_for_each(entry, kbdev_list) {
		struct kbase_device *kbdev = NULL;
		kbasep_kctx_list_element *element;
		kbdev = list_entry(entry, struct kbase_device, entry);
		pages = atomic_read(&(kbdev->memdev.used_pages));
	}
	kbase_dev_list_put(kbdev_list);
#endif
	/// printk(KERN_EMERG "gpu total memory %d\n", pages*4096);
	return (atomic_read(&g_mtk_gpu_total_memory_usage_in_pages)*4096);
}

int mtk_kbase_report_gpu_memory_peak()
{
    return (atomic_read(&g_mtk_gpu_peak_memory_usage_in_pages)*4096);
}

void mtk_kbase_set_gpu_memory_peak()
{
	int curr;
	int peak;

	curr = atomic_read(&g_mtk_gpu_total_memory_usage_in_pages);
	peak = atomic_read(&g_mtk_gpu_peak_memory_usage_in_pages);

	if (curr > peak)
		atomic_set(&g_mtk_gpu_peak_memory_usage_in_pages, curr);
}
#endif /* ENABLE_MTK_MEMINFO */

#ifdef CONFIG_PROC_FS

/// 0. For query the support command
static int proc_gpu_help_show(struct seq_file *m, void *v)
{
	seq_printf(m, "======================================================================\n");
	seq_printf(m, "A.For Query GPU/CPU related Command:\n");
//	seq_printf(m, "  cat /proc/mali/utilization\n");
//	seq_printf(m, "  cat /proc/mali/frequency\n");
	seq_printf(m, "  cat /proc/mali/memory_usage\n");
//	seq_printf(m, "  cat /proc/gpufreq/gpufreq_var_dump\n");
//	seq_printf(m, "  cat /proc/pm_init/ckgen_meter_test\n");
//	seq_printf(m, "  cat /proc/cpufreq/cpufreq_cur_freq\n");
	seq_printf(m, "======================================================================\n");
	seq_printf(m, "B.For Fix GPU Frequency:\n");
	seq_printf(m, "  echo > (450000, 280000) /proc/gpufreq/gpufreq_opp_freq\n");
	seq_printf(m, "  echo 0 > /proc/gpufreq/gpufreq_opp_freq(re-enable GPU DVFS)\n");
	seq_printf(m, "C.For Turn On/Off CPU core number:\n");
	seq_printf(m, "  echo (1, 0) > /sys/devices/system/cpu/cpu1/online\n");
	seq_printf(m, "  echo (1, 0) > /sys/devices/system/cpu/cpu2/online\n");
	seq_printf(m, "  echo (1, 0) > /sys/devices/system/cpu/cpuN/online\n");
	seq_printf(m, "D.For CPU Performance mode(Force CPU to run at highest speed:\n");
	seq_printf(m, " echo performance > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor\n");
	seq_printf(m, " echo interactive > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor(re-enable CPU DVFS)\n");
	seq_printf(m, "==============================================================================================\n");
	seq_printf(m, "E.For GPU advanced debugging command:\n");
	seq_printf(m, " echo [dvfs_freq(ms)] > /proc/mali/dvfs_freq\n");
	seq_printf(m, " echo [dvfs_thr_max] [dvfs_thr_min] > /proc/mali/dvfs_threshold\n");
	seq_printf(m, " echo [dvfs_deferred_count] > /proc/mali/dvfs_deferred_count\n");
	seq_printf(m, "==============================================================================================\n");

		return 0;
}

static int kbasep_gpu_help_debugfs_open(struct inode *in, struct file *file)
{
	return single_open(file, proc_gpu_help_show , NULL);
}

static const struct file_operations kbasep_gpu_help_debugfs_fops = {
	.open    = kbasep_gpu_help_debugfs_open,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.release = single_release,
};

/// 1. For GPU memory usage
static int proc_gpu_memoryusage_show(struct seq_file *m, void *v)
{
	ssize_t ret = 0;

#ifdef ENABLE_MTK_MEMINFO
	int total_size_in_bytes;
	int peak_size_in_bytes;

	total_size_in_bytes = mtk_kbase_report_gpu_memory_usage();
	peak_size_in_bytes = mtk_kbase_report_gpu_memory_peak();

	ret = seq_printf(m, "curr: %10u, peak %10u\n", total_size_in_bytes, peak_size_in_bytes);
#endif /* ENABLE_MTK_MEMINFO */

	return ret;
}

static int kbasep_gpu_memoryusage_debugfs_open(struct inode *in, struct file *file)
{
	return single_open(file, proc_gpu_memoryusage_show, NULL);
}

static const struct file_operations kbasep_gpu_memory_usage_debugfs_open = {
	.open    = kbasep_gpu_memoryusage_debugfs_open,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.release = single_release,
};

static struct proc_dir_entry *mali_pentry;

void proc_mali_register(void)
{
    mali_pentry = proc_mkdir("mali", NULL);

    if (!mali_pentry)
        return;

    proc_create("help", 0, mali_pentry, &kbasep_gpu_help_debugfs_fops);
    proc_create("memory_usage", 0, mali_pentry, &kbasep_gpu_memory_usage_debugfs_open);
//    proc_create("utilization", 0, mali_pentry, &kbasep_gpu_utilization_debugfs_fops);
//    proc_create("frequency", 0, mali_pentry, &kbasep_gpu_frequency_debugfs_fops);
//    proc_create("dvfs_enable", S_IRUGO | S_IWUSR, mali_pentry, &kbasep_gpu_dvfs_enable_debugfs_fops);
//    proc_create("input_boost", S_IRUGO | S_IWUSR, mali_pentry, &kbasep_gpu_input_boost_debugfs_fops);
//    proc_create("dvfs_freq", S_IRUGO | S_IWUSR, mali_pentry, &kbasep_gpu_dvfs_freq_debugfs_fops);
//    proc_create("dvfs_threshold", S_IRUGO | S_IWUSR, mali_pentry, &kbasep_gpu_dvfs_threshold_debugfs_fops);
//    proc_create("dvfs_deferred_count", S_IRUGO | S_IWUSR, mali_pentry, &kbasep_gpu_dvfs_deferred_count_debugfs_fops);
}

void proc_mali_unregister(void)
{
    if (!mali_pentry)
        return;

    remove_proc_entry("help", mali_pentry);
    remove_proc_entry("memory_usage", mali_pentry);
//    remove_proc_entry("utilization", mali_pentry);
//    remove_proc_entry("frequency", mali_pentry);
//    remove_proc_entry("mali", NULL);
    mali_pentry = NULL;
}
#else
#define proc_mali_register() do{}while(0)
#define proc_mali_unregister() do{}while(0)
#endif /* CONFIG_PROC_FS */