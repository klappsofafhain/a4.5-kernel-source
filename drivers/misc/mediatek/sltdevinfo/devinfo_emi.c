/*
 * (c) MediaTek Inc. 2008
 */


/********************************************************************************
 *------------------------------------------------------------------------------
 * WARNING!!!  WARNING!!!   WARNING!!!  WARNING!!!  WARNING!!!  WARNING!!! 
 * This file is generated by EMI Auto-gen Tool.
 * Please do not modify the content directly!  It could be overwritten!
 * More information: 
 * This file is auto generated by emigen.pl;
 * Pls remake or new preloader to generate!
 * By shaohui mods 20140306 @ longcheer.shanghai
 *------------------------------------------------------------------------------
*********************************************************************************/

#include "devinfo_emi.h"

#define NUM_EMI_RECORD (4)

int num_of_emi_records = NUM_EMI_RECORD ;

EMI_SETTINGS emi_settings[] =
{
     
	//KMQ72000SM_B316
	{
		"KMQ72000SM_B316",/* LC--qindh add This Section for eMCP DEVinfo */ 
		0x0,		/* sub_version */
		0x0203,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		0,		/* FW length */
		{0x15,0x01,0x00,0x51,0x37,0x32,0x53,0x4D,0x42,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x00025052,		/* EMI_CONA_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL0_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL1_VAL */
		0x44584493,		/* DRAMC_ACTIM_VAL */
		0x01000000,		/* DRAMC_GDDR3CTL1_VAL */
		0xF0048683,		/* DRAMC_CONF1_VAL */
		0xA00631D1,		/* DRAMC_DDR2CTL_VAL */
		0xBF080401,		/* DRAMC_TEST2_3_VAL */
		0x01806C3F,		/* DRAMC_CONF2_VAL */
		0xD1642342,		/* DRAMC_PD_CTRL_VAL */
		0x00008888,		/* DRAMC_PADCTL3_VAL */
		0x88888888,		/* DRAMC_DQODLY_VAL */
		0x00000000,		/* DRAMC_ADDR_OUTPUT_DLY */
		0x00000000,		/* DRAMC_CLK_OUTPUT_DLY */
		0x11000510,		/* DRAMC_ACTIM1_VAL*/
		0x07800000,		/* DRAMC_MISCTL0_VAL*/
		0x04002600,		/* DRAMC_ACTIM05T_VAL*/
		{0x20000000,0x20000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00C30001,		/* LPDDR3_MODE_REG1 */
		0x00060002,		/* LPDDR3_MODE_REG2 */
		0x00020003,		/* LPDDR3_MODE_REG3 */
		0x00000001,		/* LPDDR3_MODE_REG5 */
		0x00FF000A,		/* LPDDR3_MODE_REG10 */
		0x0000003F,		/* LPDDR3_MODE_REG63 */
	} ,
	//KMR820001M_B609
	{
		"KMR820001M_B609",/* LC--qindh add This Section for eMCP DEVinfo */ 
		0x0,		/* sub_version */
		0x0203,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		0,		/* FW length */
		{0x15,0x01,0x00,0x52,0x38,0x32,0x31,0x4D,0x42,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x000250A2,		/* EMI_CONA_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL0_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL1_VAL */
		0x44584493,		/* DRAMC_ACTIM_VAL */
		0x01000000,		/* DRAMC_GDDR3CTL1_VAL */
		0xF0048783,		/* DRAMC_CONF1_VAL */
		0xA00631D1,		/* DRAMC_DDR2CTL_VAL */
		0xBF080401,		/* DRAMC_TEST2_3_VAL */
		0x01806C3F,		/* DRAMC_CONF2_VAL */
		0xD1642342,		/* DRAMC_PD_CTRL_VAL */
		0x00008888,		/* DRAMC_PADCTL3_VAL */
		0x88888888,		/* DRAMC_DQODLY_VAL */
		0x00000000,		/* DRAMC_ADDR_OUTPUT_DLY */
		0x00000000,		/* DRAMC_CLK_OUTPUT_DLY */
		0x11000510,		/* DRAMC_ACTIM1_VAL*/
		0x07800000,		/* DRAMC_MISCTL0_VAL*/
		0x04002600,		/* DRAMC_ACTIM05T_VAL*/
		{0x40000000,0x40000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00C30001,		/* LPDDR3_MODE_REG1 */
		0x00060002,		/* LPDDR3_MODE_REG2 */
		0x00020003,		/* LPDDR3_MODE_REG3 */
		0x00000001,		/* LPDDR3_MODE_REG5 */
		0x00FF000A,		/* LPDDR3_MODE_REG10 */
		0x0000003F,		/* LPDDR3_MODE_REG63 */
	} ,
	//KMQ8X000SA_B414
	{
		"KMQ8X000SA_B414",/* LC--qindh add This Section for eMCP DEVinfo */ 
		0x0,		/* sub_version */
		0x0203,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		0,		/* FW length */
		{0x15,0x01,0x00,0x51,0x38,0x58,0x53,0x41,0x42,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x00025052,		/* EMI_CONA_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL0_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL1_VAL */
		0x44584493,		/* DRAMC_ACTIM_VAL */
		0x01000000,		/* DRAMC_GDDR3CTL1_VAL */
		0xF0048683,		/* DRAMC_CONF1_VAL */
		0xA00631D1,		/* DRAMC_DDR2CTL_VAL */
		0xBF080401,		/* DRAMC_TEST2_3_VAL */
		0x01806C3F,		/* DRAMC_CONF2_VAL */
		0xD1642342,		/* DRAMC_PD_CTRL_VAL */
		0x00008888,		/* DRAMC_PADCTL3_VAL */
		0x88888888,		/* DRAMC_DQODLY_VAL */
		0x00000000,		/* DRAMC_ADDR_OUTPUT_DLY */
		0x00000000,		/* DRAMC_CLK_OUTPUT_DLY */
		0x11000510,		/* DRAMC_ACTIM1_VAL*/
		0x07800000,		/* DRAMC_MISCTL0_VAL*/
		0x04002600,		/* DRAMC_ACTIM05T_VAL*/
		{0x20000000,0x20000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00C30001,		/* LPDDR3_MODE_REG1 */
		0x00060002,		/* LPDDR3_MODE_REG2 */
		0x00020003,		/* LPDDR3_MODE_REG3 */
		0x00000001,		/* LPDDR3_MODE_REG5 */
		0x00FF000A,		/* LPDDR3_MODE_REG10 */
		0x0000003F,		/* LPDDR3_MODE_REG63 */
	} ,
	//KMQ82000SM_B418
	{
		"KMQ82000SM_B418",/* LC--qindh add This Section for eMCP DEVinfo */ 
		0x0,		/* sub_version */
		0x0203,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		0,		/* FW length */
		{0x15,0x01,0x00,0x51,0x38,0x32,0x53,0x4D,0x42,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x00025052,		/* EMI_CONA_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL0_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL1_VAL */
		0x44584493,		/* DRAMC_ACTIM_VAL */
		0x01000000,		/* DRAMC_GDDR3CTL1_VAL */
		0xF0048683,		/* DRAMC_CONF1_VAL */
		0xA00631D1,		/* DRAMC_DDR2CTL_VAL */
		0xBF080401,		/* DRAMC_TEST2_3_VAL */
		0x01806C3F,		/* DRAMC_CONF2_VAL */
		0xD1642342,		/* DRAMC_PD_CTRL_VAL */
		0x00008888,		/* DRAMC_PADCTL3_VAL */
		0x88888888,		/* DRAMC_DQODLY_VAL */
		0x00000000,		/* DRAMC_ADDR_OUTPUT_DLY */
		0x00000000,		/* DRAMC_CLK_OUTPUT_DLY */
		0x11000510,		/* DRAMC_ACTIM1_VAL*/
		0x07800000,		/* DRAMC_MISCTL0_VAL*/
		0x04002600,		/* DRAMC_ACTIM05T_VAL*/
		{0x20000000,0x20000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00C30001,		/* LPDDR3_MODE_REG1 */
		0x00060002,		/* LPDDR3_MODE_REG2 */
		0x00020003,		/* LPDDR3_MODE_REG3 */
		0x00000001,		/* LPDDR3_MODE_REG5 */
		0x00FF000A,		/* LPDDR3_MODE_REG10 */
		0x0000003F,		/* LPDDR3_MODE_REG63 */
	} ,
};


