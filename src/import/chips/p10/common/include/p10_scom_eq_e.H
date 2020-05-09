/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_e.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __p10_scom_eq_e_H_
#define __p10_scom_eq_e_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS]
static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS = 0x2001832cull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS_CORE_PDLYS_INVERT = 0;
//<< [CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS]
// eq/reg00014.H

//>> [CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE]
static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE = 0x20018330ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE_ENABLE_OVERRIDE = 0;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE_VALUE_OVERRIDE = 1;
//<< [CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE]
// eq/reg00014.H

//>> [CLK_ADJ_01_DCADJ_WRAP_MEASURE_HISTORY]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_MEASURE_HISTORY = 0x20014316ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MEASURE_HISTORY_1 = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MEASURE_HISTORY_1_LEN = 8;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MEASURE_HISTORY_2 = 8;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MEASURE_HISTORY_2_LEN = 8;
//<< [CLK_ADJ_01_DCADJ_WRAP_MEASURE_HISTORY]
// eq/reg00014.H

//>> [CLK_ADJ_01_DCADJ_WRAP_SET_ADJUST_MODE]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_ADJUST_MODE = 0x20014302ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_ADJUST_MODE_SET_ADJUST_MD = 1;
//<< [CLK_ADJ_01_DCADJ_WRAP_SET_ADJUST_MODE]
// eq/reg00014.H

//>> [CLK_ADJ_01_DCADJ_WRAP_SET_HOLD_MODE]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_HOLD_MODE = 0x20014301ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD = 0;
//<< [CLK_ADJ_01_DCADJ_WRAP_SET_HOLD_MODE]
// eq/reg00014.H

//>> [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_IS_LATE]
static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_IS_LATE = 0x2001432aull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_IS_LATE_CORE_IS_LATE_INVERT = 0;
//<< [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_IS_LATE]
// eq/reg00014.H

//>> [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT]
static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT = 0x20014328ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE = 0;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE_LEN = 6;
//<< [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT]
// eq/reg00014.H

//>> [CLK_ADJ_03_DCADJ_WRAP_DCC_OVERRIDE]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_DCC_OVERRIDE = 0x20011306ull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_DCC_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_DCC_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_DCC_OVERRIDE_VALUE_LEN = 8;
//<< [CLK_ADJ_03_DCADJ_WRAP_DCC_OVERRIDE]
// eq/reg00014.H

//>> [CLK_ADJ_03_DCADJ_WRAP_SET_MEASURE_ONLY_MODE]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_MEASURE_ONLY_MODE = 0x20011311ull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1 = 4;
//<< [CLK_ADJ_03_DCADJ_WRAP_SET_MEASURE_ONLY_MODE]
// eq/reg00014.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE = 0x20011321ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_SINGLE_STEP_MD_SET = 0;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_ONE_SHOT_MD_SET = 1;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_ADJUST_MD_SET = 2;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_HOLD_MD_SET = 3;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_INIT_MD_SET = 4;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE]
// eq/reg00014.H

//>> [EPS_DBG_TRACE_REG_1]
static const uint64_t EPS_DBG_TRACE_REG_1 = 0x200183eeull;

static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
//<< [EPS_DBG_TRACE_REG_1]
// eq/reg00014.H

//>> [EPS_FIR_LOCAL_ACTION1]
static const uint64_t EPS_FIR_LOCAL_ACTION1 = 0x20040107ull;

static const uint32_t EPS_FIR_LOCAL_ACTION1_00 = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION1_01 = 1;
static const uint32_t EPS_FIR_LOCAL_ACTION1_02 = 2;
static const uint32_t EPS_FIR_LOCAL_ACTION1_03 = 3;
static const uint32_t EPS_FIR_LOCAL_ACTION1_04 = 4;
static const uint32_t EPS_FIR_LOCAL_ACTION1_05 = 5;
static const uint32_t EPS_FIR_LOCAL_ACTION1_06 = 6;
static const uint32_t EPS_FIR_LOCAL_ACTION1_07 = 7;
static const uint32_t EPS_FIR_LOCAL_ACTION1_08 = 8;
static const uint32_t EPS_FIR_LOCAL_ACTION1_09 = 9;
static const uint32_t EPS_FIR_LOCAL_ACTION1_10 = 10;
static const uint32_t EPS_FIR_LOCAL_ACTION1_11 = 11;
static const uint32_t EPS_FIR_LOCAL_ACTION1_12 = 12;
static const uint32_t EPS_FIR_LOCAL_ACTION1_13 = 13;
static const uint32_t EPS_FIR_LOCAL_ACTION1_14 = 14;
static const uint32_t EPS_FIR_LOCAL_ACTION1_15 = 15;
static const uint32_t EPS_FIR_LOCAL_ACTION1_16 = 16;
static const uint32_t EPS_FIR_LOCAL_ACTION1_17 = 17;
static const uint32_t EPS_FIR_LOCAL_ACTION1_18 = 18;
static const uint32_t EPS_FIR_LOCAL_ACTION1_19 = 19;
static const uint32_t EPS_FIR_LOCAL_ACTION1_20 = 20;
static const uint32_t EPS_FIR_LOCAL_ACTION1_21 = 21;
static const uint32_t EPS_FIR_LOCAL_ACTION1_22 = 22;
static const uint32_t EPS_FIR_LOCAL_ACTION1_23 = 23;
static const uint32_t EPS_FIR_LOCAL_ACTION1_24 = 24;
static const uint32_t EPS_FIR_LOCAL_ACTION1_25 = 25;
static const uint32_t EPS_FIR_LOCAL_ACTION1_26 = 26;
static const uint32_t EPS_FIR_LOCAL_ACTION1_27 = 27;
static const uint32_t EPS_FIR_LOCAL_ACTION1_28 = 28;
static const uint32_t EPS_FIR_LOCAL_ACTION1_29 = 29;
static const uint32_t EPS_FIR_LOCAL_ACTION1_30 = 30;
static const uint32_t EPS_FIR_LOCAL_ACTION1_31 = 31;
static const uint32_t EPS_FIR_LOCAL_ACTION1_32 = 32;
static const uint32_t EPS_FIR_LOCAL_ACTION1_33 = 33;
static const uint32_t EPS_FIR_LOCAL_ACTION1_34 = 34;
static const uint32_t EPS_FIR_LOCAL_ACTION1_35 = 35;
static const uint32_t EPS_FIR_LOCAL_ACTION1_36 = 36;
static const uint32_t EPS_FIR_LOCAL_ACTION1_37 = 37;
static const uint32_t EPS_FIR_LOCAL_ACTION1_38 = 38;
static const uint32_t EPS_FIR_LOCAL_ACTION1_39 = 39;
static const uint32_t EPS_FIR_LOCAL_ACTION1_40 = 40;
static const uint32_t EPS_FIR_LOCAL_ACTION1_41 = 41;
static const uint32_t EPS_FIR_LOCAL_ACTION1_42 = 42;
static const uint32_t EPS_FIR_LOCAL_ACTION1_43 = 43;
static const uint32_t EPS_FIR_LOCAL_ACTION1_44 = 44;
static const uint32_t EPS_FIR_LOCAL_ACTION1_45 = 45;
static const uint32_t EPS_FIR_LOCAL_ACTION1_46 = 46;
static const uint32_t EPS_FIR_LOCAL_ACTION1_47 = 47;
static const uint32_t EPS_FIR_LOCAL_ACTION1_48 = 48;
static const uint32_t EPS_FIR_LOCAL_ACTION1_49 = 49;
static const uint32_t EPS_FIR_LOCAL_ACTION1_50 = 50;
static const uint32_t EPS_FIR_LOCAL_ACTION1_51 = 51;
static const uint32_t EPS_FIR_LOCAL_ACTION1_52 = 52;
static const uint32_t EPS_FIR_LOCAL_ACTION1_53 = 53;
static const uint32_t EPS_FIR_LOCAL_ACTION1_54 = 54;
static const uint32_t EPS_FIR_LOCAL_ACTION1_55 = 55;
static const uint32_t EPS_FIR_LOCAL_ACTION1_56 = 56;
static const uint32_t EPS_FIR_LOCAL_ACTION1_57 = 57;
static const uint32_t EPS_FIR_LOCAL_ACTION1_58 = 58;
static const uint32_t EPS_FIR_LOCAL_ACTION1_59 = 59;
static const uint32_t EPS_FIR_LOCAL_ACTION1_60 = 60;
static const uint32_t EPS_FIR_LOCAL_ACTION1_61 = 61;
static const uint32_t EPS_FIR_LOCAL_ACTION1_62 = 62;
static const uint32_t EPS_FIR_LOCAL_ACTION1_63 = 63;
//<< [EPS_FIR_LOCAL_ACTION1]
// eq/reg00014.H

//>> [L3TRA0_TR0_CONFIG]
static const uint64_t L3TRA0_TR0_CONFIG = 0x20018202ull;

static const uint32_t L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t L3TRA0_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t L3TRA0_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
//<< [L3TRA0_TR0_CONFIG]
// eq/reg00014.H

//>> [L3TRA1_TR0_TRACE_HI_DATA_REG]
static const uint64_t L3TRA1_TR0_TRACE_HI_DATA_REG = 0x20018240ull;

static const uint32_t L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
//<< [L3TRA1_TR0_TRACE_HI_DATA_REG]
// eq/reg00014.H

//>> [L3TRA1_TR0_CONFIG_1]
static const uint64_t L3TRA1_TR0_CONFIG_1 = 0x20018244ull;

static const uint32_t L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
//<< [L3TRA1_TR0_CONFIG_1]
// eq/reg00014.H

//>> [L3TRA1_TR1_CONFIG]
static const uint64_t L3TRA1_TR1_CONFIG = 0x20018262ull;

static const uint32_t L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t L3TRA1_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t L3TRA1_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
//<< [L3TRA1_TR1_CONFIG]
// eq/reg00014.H

//>> [L3TRA2_TR1_TRACE_LO_DATA_REG]
static const uint64_t L3TRA2_TR1_TRACE_LO_DATA_REG = 0x200182a1ull;

static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
//<< [L3TRA2_TR1_TRACE_LO_DATA_REG]
// eq/reg00014.H

//>> [L3TRA3_TR0_CONFIG_9]
static const uint64_t L3TRA3_TR0_CONFIG_9 = 0x200182c9ull;

static const uint32_t L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t L3TRA3_TR0_CONFIG_9_SPARE_LT = 37;
//<< [L3TRA3_TR0_CONFIG_9]
// eq/reg00014.H

//>> [L3TRA3_TR1_CONFIG_0]
static const uint64_t L3TRA3_TR1_CONFIG_0 = 0x200182e3ull;

static const uint32_t L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
//<< [L3TRA3_TR1_CONFIG_0]
// eq/reg00014.H

//>> [OPCG_REG1]
static const uint64_t OPCG_REG1 = 0x20030003ull;

static const uint32_t OPCG_REG1_SCAN_COUNT = 0;
static const uint32_t OPCG_REG1_SCAN_COUNT_LEN = 12;
static const uint32_t OPCG_REG1_MISR_A_VAL = 12;
static const uint32_t OPCG_REG1_MISR_A_VAL_LEN = 12;
static const uint32_t OPCG_REG1_MISR_B_VAL = 24;
static const uint32_t OPCG_REG1_MISR_B_VAL_LEN = 12;
static const uint32_t OPCG_REG1_MISR_INIT_WAIT = 36;
static const uint32_t OPCG_REG1_MISR_INIT_WAIT_LEN = 12;
static const uint32_t OPCG_REG1_SCAN_CLK_USE_EVEN = 49;
static const uint32_t OPCG_REG1_DISABLE_FCE_DURING_FILL = 50;
static const uint32_t OPCG_REG1_RTIM_THOLD_FORCE = 52;
static const uint32_t OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL = 53;
static const uint32_t OPCG_REG1_SG_HIGH_DURING_FILL = 54;
static const uint32_t OPCG_REG1_LBIST_SKITTER_CTL = 55;
static const uint32_t OPCG_REG1_LBIST_SKITTER_CTL_LEN = 2;
static const uint32_t OPCG_REG1_MISR_MODE = 57;
static const uint32_t OPCG_REG1_INFINITE_MODE = 58;
static const uint32_t OPCG_REG1_NSL_FILL_COUNT = 59;
static const uint32_t OPCG_REG1_NSL_FILL_COUNT_LEN = 5;
//<< [OPCG_REG1]
// eq/reg00014.H

//>> [QMETRA0_TR1_TRACE_LO_DATA_REG]
static const uint64_t QMETRA0_TR1_TRACE_LO_DATA_REG = 0x20018441ull;

static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t QMETRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
//<< [QMETRA0_TR1_TRACE_LO_DATA_REG]
// eq/reg00014.H

//>> [QMETRA0_TR1_CONFIG]
static const uint64_t QMETRA0_TR1_CONFIG = 0x20018442ull;

static const uint32_t QMETRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t QMETRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t QMETRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t QMETRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t QMETRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t QMETRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t QMETRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t QMETRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t QMETRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t QMETRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t QMETRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t QMETRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t QMETRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t QMETRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t QMETRA0_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t QMETRA0_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
//<< [QMETRA0_TR1_CONFIG]
// eq/reg00014.H

//>> [QME_CRCR]
static const uint64_t QME_CRCR = 0x200e0300ull;

static const uint32_t QME_CRCR_COMPARE_VALUE = 0;
static const uint32_t QME_CRCR_COMPARE_VALUE_LEN = 8;
//<< [QME_CRCR]
// eq/reg00014.H

//>> [QME_DERP]
static const uint64_t QME_DERP = 0x200e0250ull;

static const uint32_t QME_DERP_DEND = 0;
static const uint32_t QME_DERP_DEND_LEN = 32;
static const uint32_t QME_DERP_SOR = 32;
static const uint32_t QME_DERP_SOR_LEN = 32;
//<< [QME_DERP]
// eq/reg00014.H

//>> [QME_EINR]
static const uint64_t QME_EINR = 0x200e0274ull;

static const uint32_t QME_EINR_INTERRUPT_INPUT = 0;
static const uint32_t QME_EINR_INTERRUPT_INPUT_LEN = 64;
//<< [QME_EINR]
// eq/reg00014.H

//>> [QME_LFIR]
static const uint64_t QME_LFIR_RW = 0x200e0000ull;
static const uint64_t QME_LFIR_WO_AND = 0x200e0001ull;
static const uint64_t QME_LFIR_WO_OR = 0x200e0002ull;

static const uint32_t QME_LFIR_PPE_HALT_ERROR = 0;
static const uint32_t QME_LFIR_DEBUG_TRIGGER = 1;
static const uint32_t QME_LFIR_SPARE_TRIGGER = 2;
static const uint32_t QME_LFIR_PPE_WATCHDOG = 3;
static const uint32_t QME_LFIR_LOCAL_PCB_TIMEOUT = 4;
static const uint32_t QME_LFIR_FABRIC_ERROR = 5;
static const uint32_t QME_LFIR_SRAM_UE = 6;
static const uint32_t QME_LFIR_SRAM_CE = 7;
static const uint32_t QME_LFIR_RESCLK_ARRAY_PARITY_ERR = 8;
static const uint32_t QME_LFIR_PCB_INTERRUPT_PROTOCOL_ERR = 9;
static const uint32_t QME_LFIR_SRAM_SCRUB_ERR = 10;
static const uint32_t QME_LFIR_CTFS_ERR = 11;
static const uint32_t QME_LFIR_CPMS_ERR = 12;
static const uint32_t QME_LFIR_PGPE_HEARTBEAT_LOST = 13;
static const uint32_t QME_LFIR_BCE_TIMEOUT = 14;
static const uint32_t QME_LFIR_RESCLK_PROTOCOL_ERR = 15;
static const uint32_t QME_LFIR_PCB_RESET_WHEN_ACTIVE = 16;
static const uint32_t QME_LFIR_SPECIAL_WKUP_PROTOCOL_ERR = 17;
static const uint32_t QME_LFIR_SPECIAL_WKUP_DONE_WINDOW = 18;
static const uint32_t QME_LFIR_DISABLED_INTR = 19;
static const uint32_t QME_LFIR_DECONFIGURED_INTR = 20;
static const uint32_t QME_LFIR_RS4_TIMEOUT = 21;
static const uint32_t QME_LFIR_PB_DATA_HANG = 22;
static const uint32_t QME_LFIR_WRITE_PROTECT_FAIL = 23;
static const uint32_t QME_LFIR_DTC_ERROR = 24;
static const uint32_t QME_LFIR_PB_CE = 25;
static const uint32_t QME_LFIR_PB_UE = 26;
static const uint32_t QME_LFIR_PB_SUE = 27;
static const uint32_t QME_LFIR_PB_INVALID_TOPOTABLE_ENTRY = 28;
static const uint32_t QME_LFIR_PB_TAG_PERR = 29;
static const uint32_t QME_LFIR_PIG_PROTOCOL_ERR = 30;
static const uint32_t QME_LFIR_LOCAL_ACCESS_ERR = 31;
static const uint32_t QME_LFIR_PB_SSA_CE = 32;
static const uint32_t QME_LFIR_PB_SSA_UE = 33;
static const uint32_t QME_LFIR_SPARE1 = 34;
static const uint32_t QME_LFIR_SPARE1_LEN = 2;
//<< [QME_LFIR]
// eq/reg00014.H

//>> [QME_PCBSII]
static const uint64_t QME_PCBSII = 0x200e0038ull;

static const uint32_t QME_PCBSII_PCB_REQ_ACK = 0;
static const uint32_t QME_PCBSII_PCB_RSP_P = 1;
static const uint32_t QME_PCBSII_PCB_RSP_VLD = 4;
static const uint32_t QME_PCBSII_PCB_RSP_INFO = 5;
static const uint32_t QME_PCBSII_PCB_RSP_INFO_LEN = 3;
static const uint32_t QME_PCBSII_QUAD_ID = 33;
static const uint32_t QME_PCBSII_QUAD_ID_LEN = 3;
//<< [QME_PCBSII]
// eq/reg00014.H

//>> [SLAVE_CONFIG_REG]
static const uint64_t SLAVE_CONFIG_REG = 0x200f001eull;

static const uint32_t SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK = 0;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN = 1;
static const uint32_t SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP = 2;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK = 3;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_HEARTBEAT = 4;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO = 5;
static const uint32_t SLAVE_CONFIG_REG_PM_DISABLE = 6;
static const uint32_t SLAVE_CONFIG_REG_PM_MUX_DISABLE = 7;
static const uint32_t SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS = 8;
static const uint32_t SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS = 9;
static const uint32_t SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS = 10;
static const uint32_t SLAVE_CONFIG_REG_MASK_PCBSL_ERRS = 11;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS = 12;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN = 8;
static const uint32_t SLAVE_CONFIG_REG_QME_PAR_DIS = 20;
static const uint32_t SLAVE_CONFIG_REG_FORCE_0_QME = 21;
//<< [SLAVE_CONFIG_REG]
// eq/reg00014.H

//>> [XSTOP2]
static const uint64_t XSTOP2 = 0x2003000dull;

static const uint32_t XSTOP2_ENABLE = 0;
static const uint32_t XSTOP2_WAIT_SNOPA = 1;
static const uint32_t XSTOP2_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP2_WAIT_ALWAYS = 3;
static const uint32_t XSTOP2_REGION_PERV = 4;
static const uint32_t XSTOP2_REGION_UNIT1 = 5;
static const uint32_t XSTOP2_REGION_UNIT2 = 6;
static const uint32_t XSTOP2_REGION_UNIT3 = 7;
static const uint32_t XSTOP2_REGION_UNIT4 = 8;
static const uint32_t XSTOP2_REGION_UNIT5 = 9;
static const uint32_t XSTOP2_REGION_UNIT6 = 10;
static const uint32_t XSTOP2_REGION_UNIT7 = 11;
static const uint32_t XSTOP2_REGION_UNIT8 = 12;
static const uint32_t XSTOP2_REGION_UNIT9 = 13;
static const uint32_t XSTOP2_REGION_UNIT10 = 14;
static const uint32_t XSTOP2_REGION_UNIT11 = 15;
static const uint32_t XSTOP2_REGION_UNIT12 = 16;
static const uint32_t XSTOP2_REGION_UNIT13 = 17;
static const uint32_t XSTOP2_REGION_UNIT14 = 18;
static const uint32_t XSTOP2_WAIT_CYCLES = 48;
static const uint32_t XSTOP2_WAIT_CYCLES_LEN = 12;
//<< [XSTOP2]
// eq/reg00014.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00014.H"
#endif
#endif
