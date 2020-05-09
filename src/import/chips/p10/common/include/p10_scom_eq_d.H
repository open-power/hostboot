/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_d.H $         */
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

#ifndef __p10_scom_eq_d_H_
#define __p10_scom_eq_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [CC_ATOMIC_LOCK_REG]
static const uint64_t CC_ATOMIC_LOCK_REG = 0x200303ffull;

static const uint32_t CC_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CC_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CC_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [CC_ATOMIC_LOCK_REG]
// eq/reg00013.H

//>> [CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE]
static const uint64_t CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE = 0x20018306ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE_VALUE_LEN = 8;
//<< [CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE]
// eq/reg00013.H

//>> [CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG]
static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG = 0x2001830cull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE = 0;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR = 1;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR = 2;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE = 3;
//<< [CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG]
// eq/reg00013.H

//>> [CLK_ADJ_00_DCADJ_WRAP_SET_ONE_SHOT_MODE]
static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_ONE_SHOT_MODE = 0x20018303ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_ONE_SHOT_MODE_SET_ONE_SHOT_MD_SET1 = 3;
//<< [CLK_ADJ_00_DCADJ_WRAP_SET_ONE_SHOT_MODE]
// eq/reg00013.H

//>> [CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT]
static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT = 0x2001831aull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_LOCK = 4;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_ADJUST_ERR = 5;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_DCSENSE_IN = 6;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_CHANGE = 7;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_CHANGE_LEN = 2;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_CHKSW_NO_OVR_PARATIY_ERROR = 9;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_CHKSW_NO_DCC_CONFIG_VISIBLE = 10;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_FSM_STATE = 11;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_FSM_STATE_LEN = 5;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_STEP_COUNT = 16;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT_STEP_COUNT_LEN = 16;
//<< [CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT]
// eq/reg00013.H

//>> [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES]
static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES = 0x20014337ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_STATE = 0;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_STATE_LEN = 4;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_0 = 4;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_0_LEN = 4;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_1 = 8;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_1_LEN = 4;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_2 = 12;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_2_LEN = 4;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_3 = 16;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_3_LEN = 4;
//<< [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES]
// eq/reg00013.H

//>> [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE]
static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE = 0x20014330ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE_ENABLE_OVERRIDE = 0;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE_VALUE_OVERRIDE = 1;
//<< [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE]
// eq/reg00013.H

//>> [CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE]
static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE = 0x20012304ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE_ET_SINGLE_STEP_MD_SET = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE_TEP_COUNT = 1;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE_TEP_COUNT_LEN = 16;
//<< [CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE]
// eq/reg00013.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE = 0x20012327ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE_LEN = 4;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]
// eq/reg00013.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE = 0x20012321ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_SINGLE_STEP_MD_SET = 0;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_ONE_SHOT_MD_SET = 1;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_ADJUST_MD_SET = 2;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_HOLD_MD_SET = 3;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_INIT_MD_SET = 4;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE]
// eq/reg00013.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS = 0x2001232cull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS_CORE_PDLYS_INVERT = 0;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS]
// eq/reg00013.H

//>> [CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT = 0x20011319ull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT_MEASURE_HIST_VAL1 = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT_MEASURE_HIST_VAL1_LEN = 8;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q = 9;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q_LEN = 7;
// ERROR Duplicate Dial         static const uint32_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q = 9;
// ERROR Duplicate Dial         static const uint32_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q_LEN = 7;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT_DCADJ_DCS_SEL_INT = 17;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT_DCADJ_DCS_SEL_INT_LEN = 7;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT_TARGET_VALUE = 25;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT_TARGET_VALUE_LEN = 7;
//<< [CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT]
// eq/reg00013.H

//>> [CLK_ADJ_03_DCADJ_WRAP_SET_MEAS_MODE_VEC]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_MEAS_MODE_VEC = 0x2001130dull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_MEAS_MODE_VEC_MEASURE_MODE_VECTOR = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_MEAS_MODE_VEC_MEASURE_MODE_VECTOR_LEN = 2;
//<< [CLK_ADJ_03_DCADJ_WRAP_SET_MEAS_MODE_VEC]
// eq/reg00013.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE = 0x20011333ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK = 0;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]
// eq/reg00013.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES = 0x20011338ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_CORE_SYNC_DONE_STATE = 2;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_CORE_SYNC_DONE_STATE_LEN = 2;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_CACHE_SYNC_DONE_STATE = 6;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_CACHE_SYNC_DONE_STATE_LEN = 2;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_CORE_ENABLE = 10;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_CORE_SYNC_DONE = 11;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_CACHE_ENABLE = 14;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_CACHE_SYNC_DONE = 15;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_CORE_PDLY_ERR = 18;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_CACHE_PDLY_ERR = 19;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_HOLD_MODE_ACTIVE = 20;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_ADJUST_MODE_ACTIVE = 21;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_SINGLE_STEP_MODE_ACTIVE = 22;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_INIT_MODE_ACTIVE = 23;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_ONE_SHOT_MODE_ACTIVE = 26;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_ONE_SHOT_ADJUSTED = 27;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES_SKEW_ADJ_ACTIVE = 31;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES]
// eq/reg00013.H

//>> [CTRL_ATOMIC_LOCK_REG]
static const uint64_t CTRL_ATOMIC_LOCK_REG = 0x200003ffull;

static const uint32_t CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [CTRL_ATOMIC_LOCK_REG]
// eq/reg00013.H

//>> [EPS_DBG_DEBUG_TRACE_CONTROL]
static const uint64_t EPS_DBG_DEBUG_TRACE_CONTROL = 0x200183f0ull;

static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_START = 0;
static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_STOP = 1;
static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_RESET = 2;
//<< [EPS_DBG_DEBUG_TRACE_CONTROL]
// eq/reg00013.H

//>> [EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ]
static const uint64_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ = 0x2005003cull;

static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
//<< [EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ]
// eq/reg00013.H

//>> [L3TRA0_TR0_CONFIG_9]
static const uint64_t L3TRA0_TR0_CONFIG_9 = 0x20018209ull;

static const uint32_t L3TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t L3TRA0_TR0_CONFIG_9_SPARE_LT = 37;
//<< [L3TRA0_TR0_CONFIG_9]
// eq/reg00013.H

//>> [L3TRA0_TR1_CONFIG_0]
static const uint64_t L3TRA0_TR1_CONFIG_0 = 0x20018223ull;

static const uint32_t L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
//<< [L3TRA0_TR1_CONFIG_0]
// eq/reg00013.H

//>> [L3TRA2_TR0_CONFIG_1]
static const uint64_t L3TRA2_TR0_CONFIG_1 = 0x20018284ull;

static const uint32_t L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
//<< [L3TRA2_TR0_CONFIG_1]
// eq/reg00013.H

//>> [L3TRA2_TR1_CONFIG]
static const uint64_t L3TRA2_TR1_CONFIG = 0x200182a2ull;

static const uint32_t L3TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t L3TRA2_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t L3TRA2_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
//<< [L3TRA2_TR1_CONFIG]
// eq/reg00013.H

//>> [L3TRA3_TR0_CONFIG]
static const uint64_t L3TRA3_TR0_CONFIG = 0x200182c2ull;

static const uint32_t L3TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t L3TRA3_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t L3TRA3_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
//<< [L3TRA3_TR0_CONFIG]
// eq/reg00013.H

//>> [OPCG_CAPT1]
static const uint64_t OPCG_CAPT1 = 0x20030010ull;

static const uint32_t OPCG_CAPT1_COUNT = 0;
static const uint32_t OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t OPCG_CAPT1_SEQ_12_LEN = 5;
//<< [OPCG_CAPT1]
// eq/reg00013.H

//>> [PRIMARY_ADDRESS_REG]
static const uint64_t PRIMARY_ADDRESS_REG = 0x200f0000ull;

static const uint32_t PRIMARY_ADDRESS_REG_PRIMARY_ADDRESS = 0;
static const uint32_t PRIMARY_ADDRESS_REG_PRIMARY_ADDRESS_LEN = 6;
//<< [PRIMARY_ADDRESS_REG]
// eq/reg00013.H

//>> [QMETRA0_TR0_CONFIG_0]
static const uint64_t QMETRA0_TR0_CONFIG_0 = 0x20018403ull;

static const uint32_t QMETRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t QMETRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
//<< [QMETRA0_TR0_CONFIG_0]
// eq/reg00013.H

//>> [QMETRA0_TR1_CONFIG_9]
static const uint64_t QMETRA0_TR1_CONFIG_9 = 0x20018449ull;

static const uint32_t QMETRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t QMETRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t QMETRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t QMETRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t QMETRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t QMETRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t QMETRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t QMETRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t QMETRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t QMETRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t QMETRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t QMETRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t QMETRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t QMETRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t QMETRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t QMETRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t QMETRA0_TR1_CONFIG_9_SPARE_LT = 37;
//<< [QMETRA0_TR1_CONFIG_9]
// eq/reg00013.H

//>> [QME_EIMR]
static const uint64_t QME_EIMR_RW = 0x200e0264ull;
static const uint64_t QME_EIMR_WO_CLEAR = 0x200e0267ull;
static const uint64_t QME_EIMR_WO_OR = 0x200e0266ull;

static const uint32_t QME_EIMR_INTERRUPT_MASK = 0;
static const uint32_t QME_EIMR_INTERRUPT_MASK_LEN = 64;
//<< [QME_EIMR]
// eq/reg00013.H

//>> [QME_PIG]
static const uint64_t QME_PIG = 0x200e0030ull;

static const uint32_t QME_PIG_REQ_INTR_TYPE = 1;
static const uint32_t QME_PIG_REQ_INTR_TYPE_LEN = 4;
static const uint32_t QME_PIG_REQ_INTR_PAYLOAD = 5;
static const uint32_t QME_PIG_REQ_INTR_PAYLOAD_LEN = 19;
static const uint32_t QME_PIG_PENDING_SOURCE = 24;
static const uint32_t QME_PIG_PENDING_SOURCE_LEN = 6;
static const uint32_t QME_PIG_INTR_GRANTED = 32;
static const uint32_t QME_PIG_GRANTED_SOURCE = 33;
static const uint32_t QME_PIG_GRANTED_SOURCE_LEN = 3;
static const uint32_t QME_PIG_QUAD_ID = 37;
static const uint32_t QME_PIG_QUAD_ID_LEN = 3;
static const uint32_t QME_PIG_GRANTED_PACKET = 40;
static const uint32_t QME_PIG_GRANTED_PACKET_LEN = 24;
//<< [QME_PIG]
// eq/reg00013.H

//>> [QME_QSCR]
static const uint64_t QME_QSCR_RW = 0x200e0070ull;
static const uint64_t QME_QSCR_WO_CLEAR = 0x200e0073ull;
static const uint64_t QME_QSCR_WO_OR = 0x200e0072ull;

static const uint32_t QME_QSCR_SRAM_ACCESS_MODE = 0;
static const uint32_t QME_QSCR_SRAM_SCRUB_ENABLE = 1;
static const uint32_t QME_QSCR_ECC_CORRECT_DIS = 2;
static const uint32_t QME_QSCR_ECC_DETECT_DIS = 3;
static const uint32_t QME_QSCR_ECC_INJECT_TYPE = 4;
static const uint32_t QME_QSCR_ECC_INJECT_ERR = 5;
static const uint32_t QME_QSCR_SPARE_6_7 = 6;
static const uint32_t QME_QSCR_SPARE_6_7_LEN = 2;
static const uint32_t QME_QSCR_DTCBASE = 32;
static const uint32_t QME_QSCR_DTCBASE_LEN = 8;
static const uint32_t QME_QSCR_SRAM_SCRUB_INDEX = 47;
static const uint32_t QME_QSCR_SRAM_SCRUB_INDEX_LEN = 13;
//<< [QME_QSCR]
// eq/reg00013.H

//>> [QME_RCMR]
static const uint64_t QME_RCMR = 0x200e0180ull;
static const uint64_t QME_RCMR_WO_CLEAR = 0x200e0183ull;
static const uint64_t QME_RCMR_WO_OR = 0x200e0182ull;

static const uint32_t QME_RCMR_STEP_ENABLE = 0;
static const uint32_t QME_RCMR_AUTO_ACK_ENABLE = 1;
static const uint32_t QME_RCMR_AUTO_TARGET_DISABLE = 2;
static const uint32_t QME_RCMR_AUTO_DONE_DISABLE = 3;
static const uint32_t QME_RCMR_STEP_DELAY = 4;
static const uint32_t QME_RCMR_STEP_DELAY_LEN = 4;
static const uint32_t QME_RCMR_CORE0_CONTROL_INDEX = 35;
static const uint32_t QME_RCMR_CORE0_CONTROL_INDEX_LEN = 5;
static const uint32_t QME_RCMR_CORE1_CONTROL_INDEX = 43;
static const uint32_t QME_RCMR_CORE1_CONTROL_INDEX_LEN = 5;
static const uint32_t QME_RCMR_CORE2_CONTROL_INDEX = 51;
static const uint32_t QME_RCMR_CORE2_CONTROL_INDEX_LEN = 5;
static const uint32_t QME_RCMR_CORE3_CONTROL_INDEX = 59;
static const uint32_t QME_RCMR_CORE3_CONTROL_INDEX_LEN = 5;
//<< [QME_RCMR]
// eq/reg00013.H

//>> [QME_WCOR]
static const uint64_t QME_WCOR = 0x200e0174ull;

static const uint32_t QME_WCOR_0_OVER_THROTTLED = 1;
static const uint32_t QME_WCOR_0_THROTTLE_INDEX = 2;
static const uint32_t QME_WCOR_0_THROTTLE_INDEX_LEN = 6;
static const uint32_t QME_WCOR_1_OVER_THROTTLED = 9;
static const uint32_t QME_WCOR_1_THROTTLE_INDEX = 10;
static const uint32_t QME_WCOR_1_THROTTLE_INDEX_LEN = 6;
static const uint32_t QME_WCOR_2_OVER_THROTTLED = 17;
static const uint32_t QME_WCOR_2_THROTTLE_INDEX = 18;
static const uint32_t QME_WCOR_2_THROTTLE_INDEX_LEN = 6;
static const uint32_t QME_WCOR_3_OVER_THROTTLED = 25;
static const uint32_t QME_WCOR_3_THROTTLE_INDEX = 26;
static const uint32_t QME_WCOR_3_THROTTLE_INDEX_LEN = 6;
//<< [QME_WCOR]
// eq/reg00013.H

//>> [RECOV_MASK]
static const uint64_t RECOV_MASK_RW = 0x20040041ull;
static const uint64_t RECOV_MASK_WO_CLEAR = 0x20040061ull;
static const uint64_t RECOV_MASK_WO_OR = 0x20040051ull;

static const uint32_t RECOV_MASK_1 = 1;
static const uint32_t RECOV_MASK_2 = 2;
static const uint32_t RECOV_MASK_3 = 3;
static const uint32_t RECOV_MASK_4 = 4;
static const uint32_t RECOV_MASK_5 = 5;
static const uint32_t RECOV_MASK_6 = 6;
static const uint32_t RECOV_MASK_7 = 7;
static const uint32_t RECOV_MASK_8 = 8;
static const uint32_t RECOV_MASK_9 = 9;
static const uint32_t RECOV_MASK_10 = 10;
static const uint32_t RECOV_MASK_11 = 11;
static const uint32_t RECOV_MASK_12 = 12;
static const uint32_t RECOV_MASK_13 = 13;
static const uint32_t RECOV_MASK_14 = 14;
static const uint32_t RECOV_MASK_15 = 15;
static const uint32_t RECOV_MASK_16 = 16;
static const uint32_t RECOV_MASK_17 = 17;
static const uint32_t RECOV_MASK_18 = 18;
static const uint32_t RECOV_MASK_19 = 19;
static const uint32_t RECOV_MASK_20 = 20;
static const uint32_t RECOV_MASK_21 = 21;
static const uint32_t RECOV_MASK_22 = 22;
static const uint32_t RECOV_MASK_23 = 23;
static const uint32_t RECOV_MASK_24 = 24;
static const uint32_t RECOV_MASK_25 = 25;
static const uint32_t RECOV_MASK_26 = 26;
static const uint32_t RECOV_MASK_27 = 27;
static const uint32_t RECOV_MASK_28 = 28;
static const uint32_t RECOV_MASK_29 = 29;
static const uint32_t RECOV_MASK_30 = 30;
static const uint32_t RECOV_MASK_31 = 31;
static const uint32_t RECOV_MASK_32 = 32;
static const uint32_t RECOV_MASK_33 = 33;
static const uint32_t RECOV_MASK_34 = 34;
static const uint32_t RECOV_MASK_35 = 35;
static const uint32_t RECOV_MASK_36 = 36;
static const uint32_t RECOV_MASK_37 = 37;
static const uint32_t RECOV_MASK_38 = 38;
static const uint32_t RECOV_MASK_39 = 39;
static const uint32_t RECOV_MASK_40 = 40;
static const uint32_t RECOV_MASK_41 = 41;
static const uint32_t RECOV_MASK_42 = 42;
static const uint32_t RECOV_MASK_43 = 43;
static const uint32_t RECOV_MASK_44 = 44;
static const uint32_t RECOV_MASK_45 = 45;
static const uint32_t RECOV_MASK_46 = 46;
static const uint32_t RECOV_MASK_47 = 47;
static const uint32_t RECOV_MASK_48 = 48;
static const uint32_t RECOV_MASK_49 = 49;
static const uint32_t RECOV_MASK_50 = 50;
static const uint32_t RECOV_MASK_51 = 51;
static const uint32_t RECOV_MASK_52 = 52;
static const uint32_t RECOV_MASK_53 = 53;
//<< [RECOV_MASK]
// eq/reg00013.H

//>> [SCAN_UPDATEDR_LONG]
static const uint64_t SCAN_UPDATEDR_LONG = 0x2003b000ull;

static const uint32_t SCAN_UPDATEDR_LONG_SCAN_UPDATEDR_LONG_REG = 0;
static const uint32_t SCAN_UPDATEDR_LONG_SCAN_UPDATEDR_LONG_REG_LEN = 32;
//<< [SCAN_UPDATEDR_LONG]
// eq/reg00013.H

//>> [XSTOP5]
static const uint64_t XSTOP5 = 0x20030015ull;

static const uint32_t XSTOP5_ENABLE = 0;
static const uint32_t XSTOP5_WAIT_SNOPA = 1;
static const uint32_t XSTOP5_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP5_WAIT_ALWAYS = 3;
static const uint32_t XSTOP5_REGION_PERV = 4;
static const uint32_t XSTOP5_REGION_UNIT1 = 5;
static const uint32_t XSTOP5_REGION_UNIT2 = 6;
static const uint32_t XSTOP5_REGION_UNIT3 = 7;
static const uint32_t XSTOP5_REGION_UNIT4 = 8;
static const uint32_t XSTOP5_REGION_UNIT5 = 9;
static const uint32_t XSTOP5_REGION_UNIT6 = 10;
static const uint32_t XSTOP5_REGION_UNIT7 = 11;
static const uint32_t XSTOP5_REGION_UNIT8 = 12;
static const uint32_t XSTOP5_REGION_UNIT9 = 13;
static const uint32_t XSTOP5_REGION_UNIT10 = 14;
static const uint32_t XSTOP5_REGION_UNIT11 = 15;
static const uint32_t XSTOP5_REGION_UNIT12 = 16;
static const uint32_t XSTOP5_REGION_UNIT13 = 17;
static const uint32_t XSTOP5_REGION_UNIT14 = 18;
static const uint32_t XSTOP5_WAIT_CYCLES = 48;
static const uint32_t XSTOP5_WAIT_CYCLES_LEN = 12;
//<< [XSTOP5]
// eq/reg00013.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00013.H"
#endif
#endif
