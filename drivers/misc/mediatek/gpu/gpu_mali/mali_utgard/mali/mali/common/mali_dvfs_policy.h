/*
 * (c) ARM Limited 2010-2012, 2014-2015
 */


#ifndef __MALI_DVFS_POLICY_H__
#define __MALI_DVFS_POLICY_H__

#ifdef __cplusplus
extern "C" {
#endif

void mali_dvfs_policy_realize(struct mali_gpu_utilization_data *data, u64 time_period);

_mali_osk_errcode_t mali_dvfs_policy_init(void);

void mali_dvfs_policy_new_period(void);

mali_bool mali_dvfs_policy_enabled(void);

#if defined(CONFIG_MALI400_PROFILING)
void mali_get_current_gpu_clk_item(struct mali_gpu_clk_item *clk_item);
#endif

#ifdef __cplusplus
}
#endif

#endif/* __MALI_DVFS_POLICY_H__ */


