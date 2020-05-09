/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_b.H $         */
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

#ifndef __p10_scom_eq_b_H_
#define __p10_scom_eq_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [ATOMIC_LOCK_REG]
static const uint64_t ATOMIC_LOCK_REG = 0x200f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [ATOMIC_LOCK_REG]
// eq/reg00011.H

//>> [ATTN_INTERRUPT_REG]
static const uint64_t ATTN_INTERRUPT_REG = 0x200f001aull;

static const uint32_t ATTN_INTERRUPT_REG_ATTN = 0;
//<< [ATTN_INTERRUPT_REG]
// eq/reg00011.H

//>> [CLK_ADJ_00_SKEW_WRAP_SKEWADJ_OP_MODE_FSM_STATE]
static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_OP_MODE_FSM_STATE = 0x2001833cull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_OP_MODE_FSM_STATE_OP_MODE_FSM = 3;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_OP_MODE_FSM_STATE_OP_MODE_FSM_LEN = 5;
//<< [CLK_ADJ_00_SKEW_WRAP_SKEWADJ_OP_MODE_FSM_STATE]
// eq/reg00011.H

//>> [CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE]
static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE = 0x20018321ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_SINGLE_STEP_MD_SET = 0;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_ONE_SHOT_MD_SET = 1;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_ADJUST_MD_SET = 2;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_HOLD_MD_SET = 3;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_INIT_MD_SET = 4;
//<< [CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE]
// eq/reg00011.H

//>> [CLK_ADJ_01_DCADJ_WRAP_SET_COMP_DLY]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_COMP_DLY = 0x2001430bull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE_LEN = 16;
//<< [CLK_ADJ_01_DCADJ_WRAP_SET_COMP_DLY]
// eq/reg00011.H

//>> [CLK_ADJ_01_DCADJ_WRAP_SET_DEC_DCC]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_DEC_DCC = 0x2001430full;
//<< [CLK_ADJ_01_DCADJ_WRAP_SET_DEC_DCC]
// eq/reg00011.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES = 0x2001233aull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_0 = 2;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_0_LEN = 6;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_1 = 10;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_1_LEN = 6;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_2 = 18;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_2_LEN = 6;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_3 = 26;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_3_LEN = 6;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES]
// eq/reg00011.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA = 0x20012339ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ORE_IS_LATE = 3;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ORE_IS_LATE_HIST = 4;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ORE_IS_LATE_HIST_LEN = 4;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ACHE_IS_LATE = 11;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ACHE_IS_LATE_HIST = 12;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ACHE_IS_LATE_HIST_LEN = 4;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA]
// eq/reg00011.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_CHICKEN_SWITCHES]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_CHICKEN_SWITCHES = 0x20012335ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_CHICKEN_SWITCHES_STOP_ON_ERROR = 0;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_CHICKEN_SWITCHES]
// eq/reg00011.H

//>> [CLK_ADJ_03_DCADJ_WRAP_SET_DEC_DCC]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_DEC_DCC = 0x2001130full;
//<< [CLK_ADJ_03_DCADJ_WRAP_SET_DEC_DCC]
// eq/reg00011.H

//>> [CLK_ADJ_03_DCADJ_WRAP_SET_HOLD_MODE]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_HOLD_MODE = 0x20011301ull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD = 0;
//<< [CLK_ADJ_03_DCADJ_WRAP_SET_HOLD_MODE]
// eq/reg00011.H

//>> [CLK_ADJ_03_DCADJ_WRAP_SET_LOW_PASS_DLY]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_LOW_PASS_DLY = 0x20011309ull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_LOW_PASS_DLY_LOW_PASS_DELAY_VALUE = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_LOW_PASS_DLY_LOW_PASS_DELAY_VALUE_LEN = 16;
//<< [CLK_ADJ_03_DCADJ_WRAP_SET_LOW_PASS_DLY]
// eq/reg00011.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE = 0x20011327ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE_LEN = 4;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]
// eq/reg00011.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_OP_MODE_FSM_STATE]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_OP_MODE_FSM_STATE = 0x2001133cull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_OP_MODE_FSM_STATE_OP_MODE_FSM = 3;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_OP_MODE_FSM_STATE_OP_MODE_FSM_LEN = 5;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_OP_MODE_FSM_STATE]
// eq/reg00011.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE = 0x20011324ull;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE]
// eq/reg00011.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT = 0x20011328ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE = 0;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE_LEN = 6;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT]
// eq/reg00011.H

//>> [EPS_DBG_TRACE_MODE_REG_2]
static const uint64_t EPS_DBG_TRACE_MODE_REG_2 = 0x200183efull;

static const uint32_t EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
//<< [EPS_DBG_TRACE_MODE_REG_2]
// eq/reg00011.H

//>> [EPS_FIR_LOCAL_MASK]
static const uint64_t EPS_FIR_LOCAL_MASK_RW = 0x20040103ull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_AND = 0x20040104ull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_OR = 0x20040105ull;

static const uint32_t EPS_FIR_LOCAL_MASK_00 = 0;
static const uint32_t EPS_FIR_LOCAL_MASK_01 = 1;
static const uint32_t EPS_FIR_LOCAL_MASK_02 = 2;
static const uint32_t EPS_FIR_LOCAL_MASK_03 = 3;
static const uint32_t EPS_FIR_LOCAL_MASK_04 = 4;
static const uint32_t EPS_FIR_LOCAL_MASK_05 = 5;
static const uint32_t EPS_FIR_LOCAL_MASK_06 = 6;
static const uint32_t EPS_FIR_LOCAL_MASK_07 = 7;
static const uint32_t EPS_FIR_LOCAL_MASK_08 = 8;
static const uint32_t EPS_FIR_LOCAL_MASK_09 = 9;
static const uint32_t EPS_FIR_LOCAL_MASK_10 = 10;
static const uint32_t EPS_FIR_LOCAL_MASK_11 = 11;
static const uint32_t EPS_FIR_LOCAL_MASK_12 = 12;
static const uint32_t EPS_FIR_LOCAL_MASK_13 = 13;
static const uint32_t EPS_FIR_LOCAL_MASK_14 = 14;
static const uint32_t EPS_FIR_LOCAL_MASK_15 = 15;
static const uint32_t EPS_FIR_LOCAL_MASK_16 = 16;
static const uint32_t EPS_FIR_LOCAL_MASK_17 = 17;
static const uint32_t EPS_FIR_LOCAL_MASK_18 = 18;
static const uint32_t EPS_FIR_LOCAL_MASK_19 = 19;
static const uint32_t EPS_FIR_LOCAL_MASK_20 = 20;
static const uint32_t EPS_FIR_LOCAL_MASK_21 = 21;
static const uint32_t EPS_FIR_LOCAL_MASK_22 = 22;
static const uint32_t EPS_FIR_LOCAL_MASK_23 = 23;
static const uint32_t EPS_FIR_LOCAL_MASK_24 = 24;
static const uint32_t EPS_FIR_LOCAL_MASK_25 = 25;
static const uint32_t EPS_FIR_LOCAL_MASK_26 = 26;
static const uint32_t EPS_FIR_LOCAL_MASK_27 = 27;
static const uint32_t EPS_FIR_LOCAL_MASK_28 = 28;
static const uint32_t EPS_FIR_LOCAL_MASK_29 = 29;
static const uint32_t EPS_FIR_LOCAL_MASK_30 = 30;
static const uint32_t EPS_FIR_LOCAL_MASK_31 = 31;
static const uint32_t EPS_FIR_LOCAL_MASK_32 = 32;
static const uint32_t EPS_FIR_LOCAL_MASK_33 = 33;
static const uint32_t EPS_FIR_LOCAL_MASK_34 = 34;
static const uint32_t EPS_FIR_LOCAL_MASK_35 = 35;
static const uint32_t EPS_FIR_LOCAL_MASK_36 = 36;
static const uint32_t EPS_FIR_LOCAL_MASK_37 = 37;
static const uint32_t EPS_FIR_LOCAL_MASK_38 = 38;
static const uint32_t EPS_FIR_LOCAL_MASK_39 = 39;
static const uint32_t EPS_FIR_LOCAL_MASK_40 = 40;
static const uint32_t EPS_FIR_LOCAL_MASK_41 = 41;
static const uint32_t EPS_FIR_LOCAL_MASK_42 = 42;
static const uint32_t EPS_FIR_LOCAL_MASK_43 = 43;
static const uint32_t EPS_FIR_LOCAL_MASK_44 = 44;
static const uint32_t EPS_FIR_LOCAL_MASK_45 = 45;
static const uint32_t EPS_FIR_LOCAL_MASK_46 = 46;
static const uint32_t EPS_FIR_LOCAL_MASK_47 = 47;
static const uint32_t EPS_FIR_LOCAL_MASK_48 = 48;
static const uint32_t EPS_FIR_LOCAL_MASK_49 = 49;
static const uint32_t EPS_FIR_LOCAL_MASK_50 = 50;
static const uint32_t EPS_FIR_LOCAL_MASK_51 = 51;
static const uint32_t EPS_FIR_LOCAL_MASK_52 = 52;
static const uint32_t EPS_FIR_LOCAL_MASK_53 = 53;
static const uint32_t EPS_FIR_LOCAL_MASK_54 = 54;
static const uint32_t EPS_FIR_LOCAL_MASK_55 = 55;
static const uint32_t EPS_FIR_LOCAL_MASK_56 = 56;
static const uint32_t EPS_FIR_LOCAL_MASK_57 = 57;
static const uint32_t EPS_FIR_LOCAL_MASK_58 = 58;
static const uint32_t EPS_FIR_LOCAL_MASK_59 = 59;
static const uint32_t EPS_FIR_LOCAL_MASK_60 = 60;
static const uint32_t EPS_FIR_LOCAL_MASK_61 = 61;
static const uint32_t EPS_FIR_LOCAL_MASK_62 = 62;
static const uint32_t EPS_FIR_LOCAL_MASK_63 = 63;
//<< [EPS_FIR_LOCAL_MASK]
// eq/reg00011.H

//>> [EPS_THERM_WSUB2_CONTROL_REG]
static const uint64_t EPS_THERM_WSUB2_CONTROL_REG = 0x20050032ull;

static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_RESET_TRIP_HISTORY = 0;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_RESET_SAMPLE_PULSE_CNT = 1;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_F_RESET_CPM_RD = 2;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_F_RESET_CPM_WR = 3;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_RESET_SAMPLE_DTS = 4;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_SAMPLE_DTS = 5;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE = 6;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS = 7;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS = 8;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS = 9;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE = 10;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_RESET_MEASURE_VOLT = 11;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_SHIFT_SENSOR = 12;
//<< [EPS_THERM_WSUB2_CONTROL_REG]
// eq/reg00011.H

//>> [EPS_THERM_WSUB2_SKITTER_DATA2]
static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA2 = 0x2005003bull;
//<< [EPS_THERM_WSUB2_SKITTER_DATA2]
// eq/reg00011.H

//>> [L3TRA0_TR1_CONFIG_1]
static const uint64_t L3TRA0_TR1_CONFIG_1 = 0x20018224ull;

static const uint32_t L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
//<< [L3TRA0_TR1_CONFIG_1]
// eq/reg00011.H

//>> [L3TRA1_TR0_TRACE_LO_DATA_REG]
static const uint64_t L3TRA1_TR0_TRACE_LO_DATA_REG = 0x20018241ull;

static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
//<< [L3TRA1_TR0_TRACE_LO_DATA_REG]
// eq/reg00011.H

//>> [L3TRA2_TR0_CONFIG_0]
static const uint64_t L3TRA2_TR0_CONFIG_0 = 0x20018283ull;

static const uint32_t L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
//<< [L3TRA2_TR0_CONFIG_0]
// eq/reg00011.H

//>> [L3TRA2_TR1_TRACE_HI_DATA_REG]
static const uint64_t L3TRA2_TR1_TRACE_HI_DATA_REG = 0x200182a0ull;

static const uint32_t L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
//<< [L3TRA2_TR1_TRACE_HI_DATA_REG]
// eq/reg00011.H

//>> [L3TRA2_TR1_CONFIG_9]
static const uint64_t L3TRA2_TR1_CONFIG_9 = 0x200182a9ull;

static const uint32_t L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t L3TRA2_TR1_CONFIG_9_SPARE_LT = 37;
//<< [L3TRA2_TR1_CONFIG_9]
// eq/reg00011.H

//>> [LOCAL_FIR]
static const uint64_t LOCAL_FIR_RW = 0x20040100ull;
static const uint64_t LOCAL_FIR_WO_AND = 0x20040101ull;
static const uint64_t LOCAL_FIR_WO_OR = 0x20040102ull;

static const uint32_t LOCAL_FIR_CFIR = 0;
static const uint32_t LOCAL_FIR_CPLT_CTRL = 1;
static const uint32_t LOCAL_FIR_CC_PCB = 2;
static const uint32_t LOCAL_FIR_CC_OTHERS = 3;
static const uint32_t LOCAL_FIR_IN04 = 4;
static const uint32_t LOCAL_FIR_IN05 = 5;
static const uint32_t LOCAL_FIR_IN06 = 6;
static const uint32_t LOCAL_FIR_IN07 = 7;
static const uint32_t LOCAL_FIR_IN08 = 8;
static const uint32_t LOCAL_FIR_IN09 = 9;
static const uint32_t LOCAL_FIR_IN10 = 10;
static const uint32_t LOCAL_FIR_IN11 = 11;
static const uint32_t LOCAL_FIR_IN12 = 12;
static const uint32_t LOCAL_FIR_IN13 = 13;
static const uint32_t LOCAL_FIR_IN14 = 14;
static const uint32_t LOCAL_FIR_IN15 = 15;
static const uint32_t LOCAL_FIR_IN16 = 16;
static const uint32_t LOCAL_FIR_IN17 = 17;
static const uint32_t LOCAL_FIR_IN18 = 18;
static const uint32_t LOCAL_FIR_IN19 = 19;
static const uint32_t LOCAL_FIR_IN20 = 20;
static const uint32_t LOCAL_FIR_IN21 = 21;
static const uint32_t LOCAL_FIR_IN22 = 22;
static const uint32_t LOCAL_FIR_IN23 = 23;
static const uint32_t LOCAL_FIR_IN24 = 24;
static const uint32_t LOCAL_FIR_IN25 = 25;
static const uint32_t LOCAL_FIR_IN26 = 26;
static const uint32_t LOCAL_FIR_IN27 = 27;
static const uint32_t LOCAL_FIR_IN28 = 28;
static const uint32_t LOCAL_FIR_IN29 = 29;
static const uint32_t LOCAL_FIR_IN30 = 30;
static const uint32_t LOCAL_FIR_IN31 = 31;
static const uint32_t LOCAL_FIR_IN32 = 32;
static const uint32_t LOCAL_FIR_IN33 = 33;
static const uint32_t LOCAL_FIR_IN34 = 34;
static const uint32_t LOCAL_FIR_IN35 = 35;
static const uint32_t LOCAL_FIR_IN36 = 36;
static const uint32_t LOCAL_FIR_IN37 = 37;
static const uint32_t LOCAL_FIR_IN38 = 38;
static const uint32_t LOCAL_FIR_IN39 = 39;
static const uint32_t LOCAL_FIR_IN40 = 40;
static const uint32_t LOCAL_FIR_IN41 = 41;
static const uint32_t LOCAL_FIR_IN42 = 42;
static const uint32_t LOCAL_FIR_IN43 = 43;
static const uint32_t LOCAL_FIR_IN44 = 44;
static const uint32_t LOCAL_FIR_IN45 = 45;
static const uint32_t LOCAL_FIR_IN46 = 46;
static const uint32_t LOCAL_FIR_IN47 = 47;
static const uint32_t LOCAL_FIR_IN48 = 48;
static const uint32_t LOCAL_FIR_IN49 = 49;
static const uint32_t LOCAL_FIR_IN50 = 50;
static const uint32_t LOCAL_FIR_IN51 = 51;
static const uint32_t LOCAL_FIR_IN52 = 52;
static const uint32_t LOCAL_FIR_IN53 = 53;
static const uint32_t LOCAL_FIR_IN54 = 54;
static const uint32_t LOCAL_FIR_IN55 = 55;
static const uint32_t LOCAL_FIR_IN56 = 56;
static const uint32_t LOCAL_FIR_IN57 = 57;
static const uint32_t LOCAL_FIR_IN58 = 58;
static const uint32_t LOCAL_FIR_IN59 = 59;
static const uint32_t LOCAL_FIR_IN60 = 60;
static const uint32_t LOCAL_FIR_IN61 = 61;
static const uint32_t LOCAL_FIR_IN62 = 62;
static const uint32_t LOCAL_FIR_EXT_LOCAL_XSTOP = 63;
//<< [LOCAL_FIR]
// eq/reg00011.H

//>> [QMETRA0_TR0_CONFIG_1]
static const uint64_t QMETRA0_TR0_CONFIG_1 = 0x20018404ull;

static const uint32_t QMETRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t QMETRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
//<< [QMETRA0_TR0_CONFIG_1]
// eq/reg00011.H

//>> [QMETRA0_TR1_TRACE_HI_DATA_REG]
static const uint64_t QMETRA0_TR1_TRACE_HI_DATA_REG = 0x20018440ull;

static const uint32_t QMETRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t QMETRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
//<< [QMETRA0_TR1_TRACE_HI_DATA_REG]
// eq/reg00011.H

//>> [QME_PCBQBI]
static const uint64_t QME_PCBQBI = 0x200e003cull;

static const uint32_t QME_PCBQBI_ENTRY_VALID = 0;
static const uint32_t QME_PCBQBI_MERGING_SCHEME = 2;
static const uint32_t QME_PCBQBI_MERGING_SCHEME_LEN = 3;
static const uint32_t QME_PCBQBI_R_NW = 8;
static const uint32_t QME_PCBQBI_PORT = 12;
static const uint32_t QME_PCBQBI_PORT_LEN = 4;
static const uint32_t QME_PCBQBI_ADDR = 16;
static const uint32_t QME_PCBQBI_ADDR_LEN = 16;
//<< [QME_PCBQBI]
// eq/reg00011.H

//>> [QME_QHTLAST]
static const uint64_t QME_QHTLAST = 0x200e01acull;

static const uint32_t QME_QHTLAST_LAST_ADDRESS = 8;
static const uint32_t QME_QHTLAST_LAST_ADDRESS_LEN = 49;
//<< [QME_QHTLAST]
// eq/reg00011.H

//>> [QME_RCPTR]
static const uint64_t QME_RCPTR = 0x200e0188ull;

static const uint32_t QME_RCPTR_TARGET_PSTATE = 0;
static const uint32_t QME_RCPTR_TARGET_PSTATE_LEN = 8;
static const uint32_t QME_RCPTR_PSTATE_CHANGE_PENDING = 8;
static const uint32_t QME_RCPTR_TARGET_INDEX = 59;
static const uint32_t QME_RCPTR_TARGET_INDEX_LEN = 5;
//<< [QME_RCPTR]
// eq/reg00011.H

//>> [QME_SCOM_XIMEM]
static const uint64_t QME_SCOM_XIMEM = 0x200e021cull;

static const uint32_t QME_SCOM_XIMEM_ADDR = 0;
static const uint32_t QME_SCOM_XIMEM_ADDR_LEN = 32;
static const uint32_t QME_SCOM_XIMEM_R_NW = 32;
static const uint32_t QME_SCOM_XIMEM_BUSY = 33;
static const uint32_t QME_SCOM_XIMEM_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t QME_SCOM_XIMEM_BYTE_ENABLE = 35;
static const uint32_t QME_SCOM_XIMEM_BYTE_ENABLE_LEN = 8;
static const uint32_t QME_SCOM_XIMEM_LINE_MODE = 43;
static const uint32_t QME_SCOM_XIMEM_ERROR = 49;
static const uint32_t QME_SCOM_XIMEM_ERROR_LEN = 3;
static const uint32_t QME_SCOM_XIMEM_IFETCH_PENDING = 62;
static const uint32_t QME_SCOM_XIMEM_DATAOP_PENDING = 63;
//<< [QME_SCOM_XIMEM]
// eq/reg00011.H

//>> [QME_SCOM_XIVDR30]
static const uint64_t QME_SCOM_XIVDR30 = 0x200e029cull;

static const uint32_t QME_SCOM_XIVDR30_0 = 0;
static const uint32_t QME_SCOM_XIVDR30_0_LEN = 32;
static const uint32_t QME_SCOM_XIVDR30_1 = 32;
static const uint32_t QME_SCOM_XIVDR30_1_LEN = 32;
//<< [QME_SCOM_XIVDR30]
// eq/reg00011.H

//>> [QME_TTSR]
static const uint64_t QME_TTSR = 0x200e0138ull;

static const uint32_t QME_TTSR_0_DATA = 0;
static const uint32_t QME_TTSR_0_DATA_LEN = 8;
static const uint32_t QME_TTSR_1_DATA = 8;
static const uint32_t QME_TTSR_1_DATA_LEN = 8;
static const uint32_t QME_TTSR_2_DATA = 16;
static const uint32_t QME_TTSR_2_DATA_LEN = 8;
static const uint32_t QME_TTSR_3_DATA = 24;
static const uint32_t QME_TTSR_3_DATA_LEN = 8;
static const uint32_t QME_TTSR_4_DATA = 32;
static const uint32_t QME_TTSR_4_DATA_LEN = 8;
static const uint32_t QME_TTSR_5_DATA = 40;
static const uint32_t QME_TTSR_5_DATA_LEN = 8;
static const uint32_t QME_TTSR_6_DATA = 48;
static const uint32_t QME_TTSR_6_DATA_LEN = 8;
static const uint32_t QME_TTSR_7_DATA = 56;
static const uint32_t QME_TTSR_7_DATA_LEN = 8;
//<< [QME_TTSR]
// eq/reg00011.H

//>> [RECOV]
static const uint64_t RECOV = 0x20040001ull;

static const uint32_t RECOV_ANY_RECOV = 0;
static const uint32_t RECOV_RESERVED1R = 1;
static const uint32_t RECOV_ANY_LOCAL_XSTOP = 2;
static const uint32_t RECOV_RESERVED3R = 3;
static const uint32_t RECOV_PERV = 4;
static const uint32_t RECOV_IN05 = 5;
static const uint32_t RECOV_IN06 = 6;
static const uint32_t RECOV_IN07 = 7;
static const uint32_t RECOV_IN08 = 8;
static const uint32_t RECOV_IN09 = 9;
static const uint32_t RECOV_IN10 = 10;
static const uint32_t RECOV_IN11 = 11;
static const uint32_t RECOV_IN12 = 12;
static const uint32_t RECOV_IN13 = 13;
static const uint32_t RECOV_IN14 = 14;
static const uint32_t RECOV_IN15 = 15;
static const uint32_t RECOV_IN16 = 16;
static const uint32_t RECOV_IN17 = 17;
static const uint32_t RECOV_IN18 = 18;
static const uint32_t RECOV_IN19 = 19;
static const uint32_t RECOV_IN20 = 20;
static const uint32_t RECOV_IN21 = 21;
static const uint32_t RECOV_IN22 = 22;
static const uint32_t RECOV_IN23 = 23;
static const uint32_t RECOV_IN24 = 24;
static const uint32_t RECOV_IN25 = 25;
static const uint32_t RECOV_IN26 = 26;
static const uint32_t RECOV_IN27 = 27;
static const uint32_t RECOV_IN28 = 28;
static const uint32_t RECOV_IN29 = 29;
static const uint32_t RECOV_IN30 = 30;
static const uint32_t RECOV_IN31 = 31;
static const uint32_t RECOV_IN32 = 32;
static const uint32_t RECOV_IN33 = 33;
static const uint32_t RECOV_IN34 = 34;
static const uint32_t RECOV_IN35 = 35;
static const uint32_t RECOV_IN36 = 36;
static const uint32_t RECOV_IN37 = 37;
static const uint32_t RECOV_IN38 = 38;
static const uint32_t RECOV_IN39 = 39;
static const uint32_t RECOV_IN40 = 40;
static const uint32_t RECOV_IN41 = 41;
static const uint32_t RECOV_IN42 = 42;
static const uint32_t RECOV_IN43 = 43;
static const uint32_t RECOV_IN44 = 44;
static const uint32_t RECOV_IN45 = 45;
static const uint32_t RECOV_IN46 = 46;
static const uint32_t RECOV_IN47 = 47;
static const uint32_t RECOV_IN48 = 48;
static const uint32_t RECOV_IN49 = 49;
static const uint32_t RECOV_IN50 = 50;
static const uint32_t RECOV_IN51 = 51;
static const uint32_t RECOV_IN52 = 52;
static const uint32_t RECOV_IN53 = 53;
//<< [RECOV]
// eq/reg00011.H

//>> [XSTOP4]
static const uint64_t XSTOP4 = 0x20030014ull;

static const uint32_t XSTOP4_ENABLE = 0;
static const uint32_t XSTOP4_WAIT_SNOPA = 1;
static const uint32_t XSTOP4_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP4_WAIT_ALWAYS = 3;
static const uint32_t XSTOP4_REGION_PERV = 4;
static const uint32_t XSTOP4_REGION_UNIT1 = 5;
static const uint32_t XSTOP4_REGION_UNIT2 = 6;
static const uint32_t XSTOP4_REGION_UNIT3 = 7;
static const uint32_t XSTOP4_REGION_UNIT4 = 8;
static const uint32_t XSTOP4_REGION_UNIT5 = 9;
static const uint32_t XSTOP4_REGION_UNIT6 = 10;
static const uint32_t XSTOP4_REGION_UNIT7 = 11;
static const uint32_t XSTOP4_REGION_UNIT8 = 12;
static const uint32_t XSTOP4_REGION_UNIT9 = 13;
static const uint32_t XSTOP4_REGION_UNIT10 = 14;
static const uint32_t XSTOP4_REGION_UNIT11 = 15;
static const uint32_t XSTOP4_REGION_UNIT12 = 16;
static const uint32_t XSTOP4_REGION_UNIT13 = 17;
static const uint32_t XSTOP4_REGION_UNIT14 = 18;
static const uint32_t XSTOP4_WAIT_CYCLES = 48;
static const uint32_t XSTOP4_WAIT_CYCLES_LEN = 12;
//<< [XSTOP4]
// eq/reg00011.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00011.H"
#endif
#endif
