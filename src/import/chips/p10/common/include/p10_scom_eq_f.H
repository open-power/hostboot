/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_f.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_eq_f_H_
#define __p10_scom_eq_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


static const uint64_t BIST = 0x2003000bull;

static const uint32_t BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t BIST_REGION_PERV = 4;
static const uint32_t BIST_REGION_UNIT1 = 5;
static const uint32_t BIST_REGION_UNIT2 = 6;
static const uint32_t BIST_REGION_UNIT3 = 7;
static const uint32_t BIST_REGION_UNIT4 = 8;
static const uint32_t BIST_REGION_UNIT5 = 9;
static const uint32_t BIST_REGION_UNIT6 = 10;
static const uint32_t BIST_REGION_UNIT7 = 11;
static const uint32_t BIST_REGION_UNIT8 = 12;
static const uint32_t BIST_REGION_UNIT9 = 13;
static const uint32_t BIST_REGION_UNIT10 = 14;
static const uint32_t BIST_REGION_UNIT11 = 15;
static const uint32_t BIST_REGION_UNIT12 = 16;
static const uint32_t BIST_REGION_UNIT13 = 17;
static const uint32_t BIST_REGION_UNIT14 = 18;
static const uint32_t BIST_STROBE_WINDOW_EN = 48;
// eq/reg00015.H

static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_DCC_TARGET = 0x20018308ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE = 0;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE_LEN = 7;
// eq/reg00015.H

static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_DEC = 0x20018310ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_DEC_DCC_VALUE = 0;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_DEC_DCC_VALUE_LEN = 8;
// eq/reg00015.H

static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_SINGLE_STEP_MODE = 0x20018304ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_SINGLE_STEP_MODE_STEP_COUNT = 0;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_SINGLE_STEP_MODE_STEP_COUNT_LEN = 16;
// eq/reg00015.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES = 0x20018337ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_INC_DEC_STATE = 28;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_INC_DEC_STATE_LEN = 4;
// eq/reg00015.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_INIT_MODE = 0x20014300ull;
// eq/reg00015.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS = 0x2001432cull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS_CORE_PDLYS_INVERT = 0;
// eq/reg00015.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_SYNC_ENABLE = 0x20014330ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_SYNC_ENABLE_CORE_SYNC_ENABLE_INVERT = 0;
// eq/reg00015.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT = 0x20012319ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT_MEASURE_HIST_VAL1 = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT_MEASURE_HIST_VAL1_LEN = 8;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q = 9;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q_LEN = 7;
// ERROR Duplicate Dial         static const uint32_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q = 9;
// ERROR Duplicate Dial         static const uint32_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q_LEN = 7;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT_DCADJ_DCS_SEL_INT = 17;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT_DCADJ_DCS_SEL_INT_LEN = 7;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT_TARGET_VALUE = 25;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_AVERAGE_MEASUREMENT_TARGET_VALUE_LEN = 7;
// eq/reg00015.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_DCC_OVERRIDE = 0x20012306ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_DCC_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_DCC_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_DCC_OVERRIDE_VALUE_LEN = 8;
// eq/reg00015.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INIT_MODE = 0x20011320ull;
// eq/reg00015.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC = 0x2001132full;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT = 0;
// eq/reg00015.H

static const uint64_t CPLT_CTRL5_RW = 0x20000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x20000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x20000015ull;

static const uint32_t CPLT_CTRL5_VITL_DFT_FENCE_DC = 3;
static const uint32_t CPLT_CTRL5_REGION0_DFT_FENCE_DC = 4;
static const uint32_t CPLT_CTRL5_REGION1_DFT_FENCE_DC = 5;
static const uint32_t CPLT_CTRL5_REGION2_DFT_FENCE_DC = 6;
static const uint32_t CPLT_CTRL5_REGION3_DFT_FENCE_DC = 7;
static const uint32_t CPLT_CTRL5_REGION4_DFT_FENCE_DC = 8;
static const uint32_t CPLT_CTRL5_REGION5_DFT_FENCE_DC = 9;
static const uint32_t CPLT_CTRL5_REGION6_DFT_FENCE_DC = 10;
static const uint32_t CPLT_CTRL5_REGION7_DFT_FENCE_DC = 11;
static const uint32_t CPLT_CTRL5_REGION8_DFT_FENCE_DC = 12;
static const uint32_t CPLT_CTRL5_REGION9_DFT_FENCE_DC = 13;
static const uint32_t CPLT_CTRL5_REGION10_DFT_FENCE_DC = 14;
static const uint32_t CPLT_CTRL5_REGION11_DFT_FENCE_DC = 15;
static const uint32_t CPLT_CTRL5_REGION12_DFT_FENCE_DC = 16;
static const uint32_t CPLT_CTRL5_REGION13_DFT_FENCE_DC = 17;
static const uint32_t CPLT_CTRL5_REGION14_DFT_FENCE_DC = 18;
// eq/reg00015.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2 = 0x20040082ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_STAGED_ERR = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR = 7;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010 = 21;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011 = 22;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012 = 23;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013 = 24;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014 = 25;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015 = 26;
// eq/reg00015.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x20050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
// eq/reg00015.H

static const uint64_t EPS_THERM_WSUB2_DTS_RESULT2 = 0x20050022ull;

static const uint32_t EPS_THERM_WSUB2_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// eq/reg00015.H

static const uint64_t L3TRA0_TR0_TRACE_LO_DATA_REG = 0x20018201ull;

static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// eq/reg00015.H

static const uint64_t L3TRA0_TR0_CONFIG_1 = 0x20018204ull;

static const uint32_t L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// eq/reg00015.H

static const uint64_t L3TRA2_TR0_CONFIG_9 = 0x20018289ull;

static const uint32_t L3TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// eq/reg00015.H

static const uint64_t L3TRA2_TR1_CONFIG_0 = 0x200182a3ull;

static const uint32_t L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// eq/reg00015.H

static const uint64_t L3TRA3_TR1_TRACE_HI_DATA_REG = 0x200182e0ull;

static const uint32_t L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// eq/reg00015.H

static const uint64_t MULTICAST_GROUP_3 = 0x200f0003ull;

static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP = 3;
static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN = 3;
// eq/reg00015.H

static const uint64_t PROTECT_MODE_REG = 0x200f03feull;

static const uint32_t PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// eq/reg00015.H

static const uint64_t QME_PBCR_RW = 0x200e0044ull;
static const uint64_t QME_PBCR_WO_CLEAR = 0x200e0047ull;
static const uint64_t QME_PBCR_WO_OR = 0x200e0046ull;

static const uint32_t QME_PBCR_DISABLE_LN_RD = 0;
static const uint32_t QME_PBCR_DISABLE_NN_RN_RD = 1;
static const uint32_t QME_PBCR_DISABLE_GROUP_RD = 2;
static const uint32_t QME_PBCR_DISABLE_VG_RD = 3;
static const uint32_t QME_PBCR_DISABLE_LN_WR = 4;
static const uint32_t QME_PBCR_DISABLE_NN_RN_WR = 5;
static const uint32_t QME_PBCR_DISABLE_GROUP_WR = 6;
static const uint32_t QME_PBCR_DISABLE_VG_WR = 7;
static const uint32_t QME_PBCR_SKIP_GROUP_SCOPE = 8;
static const uint32_t QME_PBCR_USE_DMA_PR_W = 9;
static const uint32_t QME_PBCR_FREEZE_ON_CRESP_ERR = 10;
static const uint32_t QME_PBCR_SPARE = 11;
static const uint32_t QME_PBCR_SPARE_LEN = 2;
static const uint32_t QME_PBCR_TYPE = 13;
static const uint32_t QME_PBCR_TYPE_LEN = 3;
static const uint32_t QME_PBCR_HANG_POLL_MAX_CNT = 16;
static const uint32_t QME_PBCR_HANG_POLL_MAX_CNT_LEN = 4;
static const uint32_t QME_PBCR_HANG_DATA_MAX_CNT = 20;
static const uint32_t QME_PBCR_HANG_DATA_MAX_CNT_LEN = 4;
static const uint32_t QME_PBCR_DISABLE_PB_CACHE = 24;
// eq/reg00015.H

static const uint64_t QME_QSAR = 0x200e0074ull;

static const uint32_t QME_QSAR_SRAM_ADDRESS = 16;
static const uint32_t QME_QSAR_SRAM_ADDRESS_LEN = 13;
// eq/reg00015.H

static const uint64_t QME_SCOM_XIVDR6 = 0x200e028cull;

static const uint32_t QME_SCOM_XIVDR6_6 = 0;
static const uint32_t QME_SCOM_XIVDR6_6_LEN = 32;
static const uint32_t QME_SCOM_XIVDR6_7 = 32;
static const uint32_t QME_SCOM_XIVDR6_7_LEN = 32;
// eq/reg00015.H

static const uint64_t TIMEOUT_REG = 0x200f0010ull;
// eq/reg00015.H

static const uint64_t VITAL_SCAN_OUT = 0x200f0017ull;
// eq/reg00015.H

static const uint64_t XSTOP_UNMASKED = 0x20040010ull;

static const uint32_t XSTOP_UNMASKED_IN = 1;
static const uint32_t XSTOP_UNMASKED_IN_LEN = 53;
// eq/reg00015.H

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00015.H"
#endif
#endif
