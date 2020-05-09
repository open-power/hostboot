/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_8.H $         */
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

#ifndef __p10_scom_eq_8_H_
#define __p10_scom_eq_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [ASSIST_INTERRUPT_REG]
static const uint64_t ASSIST_INTERRUPT_REG = 0x200f0011ull;

static const uint32_t ASSIST_INTERRUPT_REG_ATTN = 0;
static const uint32_t ASSIST_INTERRUPT_REG_RECOV = 1;
static const uint32_t ASSIST_INTERRUPT_REG_XSTOP = 2;
static const uint32_t ASSIST_INTERRUPT_REG_LXSTOP = 3;
static const uint32_t ASSIST_INTERRUPT_REG_TYPE4 = 4;
//<< [ASSIST_INTERRUPT_REG]
// eq/reg00008.H

//>> [CLK_ADJ_00_DCADJ_WRAP_MEASURE_HISTORY]
static const uint64_t CLK_ADJ_00_DCADJ_WRAP_MEASURE_HISTORY = 0x20018316ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_MEASURE_HISTORY_1 = 0;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_MEASURE_HISTORY_1_LEN = 8;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_MEASURE_HISTORY_2 = 8;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_MEASURE_HISTORY_2_LEN = 8;
//<< [CLK_ADJ_00_DCADJ_WRAP_MEASURE_HISTORY]
// eq/reg00008.H

//>> [CLK_ADJ_00_DCADJ_WRAP_SET_ADJUST_MODE]
static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_ADJUST_MODE = 0x20018302ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_ADJUST_MODE_SET_ADJUST_MD = 1;
//<< [CLK_ADJ_00_DCADJ_WRAP_SET_ADJUST_MODE]
// eq/reg00008.H

//>> [CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]
static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE = 0x20018333ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK = 0;
//<< [CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]
// eq/reg00008.H

//>> [CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT = 0x20014319ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT_MEASURE_HIST_VAL1 = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT_MEASURE_HIST_VAL1_LEN = 8;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q = 9;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q_LEN = 7;
// ERROR Duplicate Dial         static const uint32_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q = 9;
// ERROR Duplicate Dial         static const uint32_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT_INTERVAL_Q_LEN = 7;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT_DCADJ_DCS_SEL_INT = 17;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT_DCADJ_DCS_SEL_INT_LEN = 7;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT_TARGET_VALUE = 25;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT_TARGET_VALUE_LEN = 7;
//<< [CLK_ADJ_01_DCADJ_WRAP_AVERAGE_MEASUREMENT]
// eq/reg00008.H

//>> [CLK_ADJ_01_DCADJ_WRAP_SET_DAC_DLY]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_DAC_DLY = 0x2001430aull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_DAC_DLY_DAC_DELAY_VALUE = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_DAC_DLY_DAC_DELAY_VALUE_LEN = 16;
//<< [CLK_ADJ_01_DCADJ_WRAP_SET_DAC_DLY]
// eq/reg00008.H

//>> [CLK_ADJ_01_DCADJ_WRAP_SET_DEC]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_DEC = 0x20014310ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_DEC_DCC_VALUE = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_DEC_DCC_VALUE_LEN = 8;
//<< [CLK_ADJ_01_DCADJ_WRAP_SET_DEC]
// eq/reg00008.H

//>> [CLK_ADJ_01_DCADJ_WRAP_SET_INC_DCC]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_INC_DCC = 0x2001430eull;
//<< [CLK_ADJ_01_DCADJ_WRAP_SET_INC_DCC]
// eq/reg00008.H

//>> [CLK_ADJ_01_DCADJ_WRAP_SET_ONE_SHOT_MODE]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_ONE_SHOT_MODE = 0x20014303ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_ONE_SHOT_MODE_SET_ONE_SHOT_MD_SET1 = 3;
//<< [CLK_ADJ_01_DCADJ_WRAP_SET_ONE_SHOT_MODE]
// eq/reg00008.H

//>> [CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT]
static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT = 0x2001431aull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_LOCK = 4;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_ADJUST_ERR = 5;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_DCSENSE_IN = 6;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_CHANGE = 7;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_CHANGE_LEN = 2;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_CHKSW_NO_OVR_PARATIY_ERROR = 9;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_CHKSW_NO_DCC_CONFIG_VISIBLE = 10;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_FSM_STATE = 11;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_FSM_STATE_LEN = 5;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_STEP_COUNT = 16;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT_STEP_COUNT_LEN = 16;
//<< [CLK_ADJ_01_DCADJ_WRAP_SINGLE_STEP_COUNT]
// eq/reg00008.H

//>> [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SENSOR_DATA]
static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SENSOR_DATA = 0x20014339ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ORE_IS_LATE = 3;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ORE_IS_LATE_HIST = 4;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ORE_IS_LATE_HIST_LEN = 4;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ACHE_IS_LATE = 11;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ACHE_IS_LATE_HIST = 12;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ACHE_IS_LATE_HIST_LEN = 4;
//<< [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SENSOR_DATA]
// eq/reg00008.H

//>> [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE]
static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE = 0x20014321ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_SINGLE_STEP_MD_SET = 0;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_ONE_SHOT_MD_SET = 1;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_ADJUST_MD_SET = 2;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_HOLD_MD_SET = 3;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_INIT_MD_SET = 4;
//<< [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE]
// eq/reg00008.H

//>> [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ONE_SHOT_MODE]
static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ONE_SHOT_MODE = 0x20014323ull;
//<< [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ONE_SHOT_MODE]
// eq/reg00008.H

//>> [CLK_ADJ_02_DCADJ_WRAP_SET_COMP_DLY]
static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_COMP_DLY = 0x2001230bull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE_LEN = 16;
//<< [CLK_ADJ_02_DCADJ_WRAP_SET_COMP_DLY]
// eq/reg00008.H

//>> [CLK_ADJ_02_DCADJ_WRAP_SET_MEAS_MODE_VEC]
static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_MEAS_MODE_VEC = 0x2001230dull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_MEAS_MODE_VEC_MEASURE_MODE_VECTOR = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_MEAS_MODE_VEC_MEASURE_MODE_VECTOR_LEN = 2;
//<< [CLK_ADJ_02_DCADJ_WRAP_SET_MEAS_MODE_VEC]
// eq/reg00008.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES = 0x20012336ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE = 10;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE_LEN = 6;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE = 26;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE_LEN = 6;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES]
// eq/reg00008.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_ONE_SHOT_MODE]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_ONE_SHOT_MODE = 0x20012323ull;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_ONE_SHOT_MODE]
// eq/reg00008.H

//>> [CLK_ADJ_03_DCADJ_WRAP_SET_DAC_DLY]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_DAC_DLY = 0x2001130aull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_DAC_DLY_DAC_DELAY_VALUE = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_DAC_DLY_DAC_DELAY_VALUE_LEN = 16;
//<< [CLK_ADJ_03_DCADJ_WRAP_SET_DAC_DLY]
// eq/reg00008.H

//>> [CLK_ADJ_03_DCADJ_WRAP_SET_INC_DCC]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_INC_DCC = 0x2001130eull;
//<< [CLK_ADJ_03_DCADJ_WRAP_SET_INC_DCC]
// eq/reg00008.H

//>> [CLK_ADJ_03_DCADJ_WRAP_SOFT_RESET]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SOFT_RESET = 0x20011305ull;
//<< [CLK_ADJ_03_DCADJ_WRAP_SOFT_RESET]
// eq/reg00008.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES = 0x20011337ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_STATE = 0;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_STATE_LEN = 4;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_0 = 4;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_0_LEN = 4;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_1 = 8;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_1_LEN = 4;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_2 = 12;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_2_LEN = 4;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_3 = 16;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES_FMS_HIST_3_LEN = 4;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES]
// eq/reg00008.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE = 0x20011322ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET = 0;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET = 1;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET = 2;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET = 3;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET = 4;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE]
// eq/reg00008.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_IS_LATE]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_IS_LATE = 0x2001132aull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_IS_LATE_CORE_IS_LATE_INVERT = 0;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_IS_LATE]
// eq/reg00008.H

//>> [EDRAM_STATUS]
static const uint64_t EDRAM_STATUS = 0x200f0029ull;

static const uint32_t EDRAM_STATUS_EDRAM_STAT = 0;
static const uint32_t EDRAM_STATUS_EDRAM_STAT_LEN = 4;
//<< [EDRAM_STATUS]
// eq/reg00008.H

//>> [EPS_DBG_TRACE_REG_0]
static const uint64_t EPS_DBG_TRACE_REG_0 = 0x200183edull;

static const uint32_t EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
//<< [EPS_DBG_TRACE_REG_0]
// eq/reg00008.H

//>> [EPS_FIR_LOCAL_ACTION0]
static const uint64_t EPS_FIR_LOCAL_ACTION0 = 0x20040106ull;

static const uint32_t EPS_FIR_LOCAL_ACTION0_00 = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION0_01 = 1;
static const uint32_t EPS_FIR_LOCAL_ACTION0_02 = 2;
static const uint32_t EPS_FIR_LOCAL_ACTION0_03 = 3;
static const uint32_t EPS_FIR_LOCAL_ACTION0_04 = 4;
static const uint32_t EPS_FIR_LOCAL_ACTION0_05 = 5;
static const uint32_t EPS_FIR_LOCAL_ACTION0_06 = 6;
static const uint32_t EPS_FIR_LOCAL_ACTION0_07 = 7;
static const uint32_t EPS_FIR_LOCAL_ACTION0_08 = 8;
static const uint32_t EPS_FIR_LOCAL_ACTION0_09 = 9;
static const uint32_t EPS_FIR_LOCAL_ACTION0_10 = 10;
static const uint32_t EPS_FIR_LOCAL_ACTION0_11 = 11;
static const uint32_t EPS_FIR_LOCAL_ACTION0_12 = 12;
static const uint32_t EPS_FIR_LOCAL_ACTION0_13 = 13;
static const uint32_t EPS_FIR_LOCAL_ACTION0_14 = 14;
static const uint32_t EPS_FIR_LOCAL_ACTION0_15 = 15;
static const uint32_t EPS_FIR_LOCAL_ACTION0_16 = 16;
static const uint32_t EPS_FIR_LOCAL_ACTION0_17 = 17;
static const uint32_t EPS_FIR_LOCAL_ACTION0_18 = 18;
static const uint32_t EPS_FIR_LOCAL_ACTION0_19 = 19;
static const uint32_t EPS_FIR_LOCAL_ACTION0_20 = 20;
static const uint32_t EPS_FIR_LOCAL_ACTION0_21 = 21;
static const uint32_t EPS_FIR_LOCAL_ACTION0_22 = 22;
static const uint32_t EPS_FIR_LOCAL_ACTION0_23 = 23;
static const uint32_t EPS_FIR_LOCAL_ACTION0_24 = 24;
static const uint32_t EPS_FIR_LOCAL_ACTION0_25 = 25;
static const uint32_t EPS_FIR_LOCAL_ACTION0_26 = 26;
static const uint32_t EPS_FIR_LOCAL_ACTION0_27 = 27;
static const uint32_t EPS_FIR_LOCAL_ACTION0_28 = 28;
static const uint32_t EPS_FIR_LOCAL_ACTION0_29 = 29;
static const uint32_t EPS_FIR_LOCAL_ACTION0_30 = 30;
static const uint32_t EPS_FIR_LOCAL_ACTION0_31 = 31;
static const uint32_t EPS_FIR_LOCAL_ACTION0_32 = 32;
static const uint32_t EPS_FIR_LOCAL_ACTION0_33 = 33;
static const uint32_t EPS_FIR_LOCAL_ACTION0_34 = 34;
static const uint32_t EPS_FIR_LOCAL_ACTION0_35 = 35;
static const uint32_t EPS_FIR_LOCAL_ACTION0_36 = 36;
static const uint32_t EPS_FIR_LOCAL_ACTION0_37 = 37;
static const uint32_t EPS_FIR_LOCAL_ACTION0_38 = 38;
static const uint32_t EPS_FIR_LOCAL_ACTION0_39 = 39;
static const uint32_t EPS_FIR_LOCAL_ACTION0_40 = 40;
static const uint32_t EPS_FIR_LOCAL_ACTION0_41 = 41;
static const uint32_t EPS_FIR_LOCAL_ACTION0_42 = 42;
static const uint32_t EPS_FIR_LOCAL_ACTION0_43 = 43;
static const uint32_t EPS_FIR_LOCAL_ACTION0_44 = 44;
static const uint32_t EPS_FIR_LOCAL_ACTION0_45 = 45;
static const uint32_t EPS_FIR_LOCAL_ACTION0_46 = 46;
static const uint32_t EPS_FIR_LOCAL_ACTION0_47 = 47;
static const uint32_t EPS_FIR_LOCAL_ACTION0_48 = 48;
static const uint32_t EPS_FIR_LOCAL_ACTION0_49 = 49;
static const uint32_t EPS_FIR_LOCAL_ACTION0_50 = 50;
static const uint32_t EPS_FIR_LOCAL_ACTION0_51 = 51;
static const uint32_t EPS_FIR_LOCAL_ACTION0_52 = 52;
static const uint32_t EPS_FIR_LOCAL_ACTION0_53 = 53;
static const uint32_t EPS_FIR_LOCAL_ACTION0_54 = 54;
static const uint32_t EPS_FIR_LOCAL_ACTION0_55 = 55;
static const uint32_t EPS_FIR_LOCAL_ACTION0_56 = 56;
static const uint32_t EPS_FIR_LOCAL_ACTION0_57 = 57;
static const uint32_t EPS_FIR_LOCAL_ACTION0_58 = 58;
static const uint32_t EPS_FIR_LOCAL_ACTION0_59 = 59;
static const uint32_t EPS_FIR_LOCAL_ACTION0_60 = 60;
static const uint32_t EPS_FIR_LOCAL_ACTION0_61 = 61;
static const uint32_t EPS_FIR_LOCAL_ACTION0_62 = 62;
static const uint32_t EPS_FIR_LOCAL_ACTION0_63 = 63;
//<< [EPS_FIR_LOCAL_ACTION0]
// eq/reg00008.H

//>> [ERROR_REG]
static const uint64_t ERROR_REG = 0x200f001full;

static const uint32_t ERROR_REG_CE_ERROR = 0;
static const uint32_t ERROR_REG_CHIPLET_ERRORS = 1;
static const uint32_t ERROR_REG_CHIPLET_ERRORS_LEN = 3;
static const uint32_t ERROR_REG_PARITY_ERROR = 4;
static const uint32_t ERROR_REG_DATA_BUFFER_ERROR = 5;
static const uint32_t ERROR_REG_ADDR_BUFFER_ERROR = 6;
static const uint32_t ERROR_REG_PCB_FSM_ERROR = 7;
static const uint32_t ERROR_REG_CL_FSM_ERROR = 8;
static const uint32_t ERROR_REG_INT_RX_FSM_ERROR = 9;
static const uint32_t ERROR_REG_INT_TX_FSM_ERROR = 10;
static const uint32_t ERROR_REG_INT_TYPE_ERROR = 11;
static const uint32_t ERROR_REG_CL_DATA_ERROR = 12;
static const uint32_t ERROR_REG_INFO_ERROR = 13;
static const uint32_t ERROR_REG_SEQ_ERROR = 14;
static const uint32_t ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR = 15;
static const uint32_t ERROR_REG_PCB_INTERFACE_ERROR = 16;
static const uint32_t ERROR_REG_CHIPLET_OFFLINE = 17;
static const uint32_t ERROR_REG_EDRAM_SEQUENCE_ERR = 18;
static const uint32_t ERROR_REG_CTRL_REG_PARITY_ERROR = 19;
static const uint32_t ERROR_REG_ADDRESS_REG_PARITY_ERROR = 20;
static const uint32_t ERROR_REG_TIMEOUT_REG_PARITY_ERROR = 21;
static const uint32_t ERROR_REG_CONFIG_REG_PARITY_ERROR = 22;
static const uint32_t ERROR_REG_DIV_REG_PARITY_ERROR = 23;
static const uint32_t ERROR_REG_PLL_UNLOCK_ERROR = 24;
static const uint32_t ERROR_REG_PLL_UNLOCK_ERROR_LEN = 8;
static const uint32_t ERROR_REG_QME_INTERFACE_PARITY_ERROR = 32;
static const uint32_t ERROR_REG_QME_DATA_PARITY_ERROR = 33;
static const uint32_t ERROR_REG_QME_ADDR_PARITY_ERROR = 34;
static const uint32_t ERROR_REG_QME_FSM_ERROR = 35;
//<< [ERROR_REG]
// eq/reg00008.H

//>> [L3TRA1_TR0_CONFIG_0]
static const uint64_t L3TRA1_TR0_CONFIG_0 = 0x20018243ull;

static const uint32_t L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
//<< [L3TRA1_TR0_CONFIG_0]
// eq/reg00008.H

//>> [L3TRA1_TR1_CONFIG_9]
static const uint64_t L3TRA1_TR1_CONFIG_9 = 0x20018269ull;

static const uint32_t L3TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t L3TRA1_TR1_CONFIG_9_SPARE_LT = 37;
//<< [L3TRA1_TR1_CONFIG_9]
// eq/reg00008.H

//>> [L3TRA3_TR1_CONFIG_1]
static const uint64_t L3TRA3_TR1_CONFIG_1 = 0x200182e4ull;

static const uint32_t L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
//<< [L3TRA3_TR1_CONFIG_1]
// eq/reg00008.H

//>> [OPCG_REG0]
static const uint64_t OPCG_REG0 = 0x20030002ull;

static const uint32_t OPCG_REG0_RUNN_MODE = 0;
static const uint32_t OPCG_REG0_OPCG_GO = 1;
static const uint32_t OPCG_REG0_RUN_SCAN0 = 2;
static const uint32_t OPCG_REG0_SCAN0_MODE = 3;
static const uint32_t OPCG_REG0_OPCG_IN_SLAVE_MODE = 4;
static const uint32_t OPCG_REG0_OPCG_IN_MASTER_MODE = 5;
static const uint32_t OPCG_REG0_KEEP_MS_MODE = 6;
static const uint32_t OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL = 7;
static const uint32_t OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL = 8;
static const uint32_t OPCG_REG0_RUN_OPCG_ON_UPDATE_DR = 11;
static const uint32_t OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR = 12;
static const uint32_t OPCG_REG0_STOP_RUNN_ON_XSTOP = 13;
static const uint32_t OPCG_REG0_OPCG_STARTS_BIST = 14;
static const uint32_t OPCG_REG0_RUNN_HLD_DLY_EN = 15;
static const uint32_t OPCG_REG0_LOOP_COUNT = 21;
static const uint32_t OPCG_REG0_LOOP_COUNT_LEN = 43;
//<< [OPCG_REG0]
// eq/reg00008.H

//>> [QME_DORP]
static const uint64_t QME_DORP = 0x200e0254ull;

static const uint32_t QME_DORP_QUOTIENT = 0;
static const uint32_t QME_DORP_QUOTIENT_LEN = 32;
static const uint32_t QME_DORP_REMAINDER = 32;
static const uint32_t QME_DORP_REMAINDER_LEN = 32;
//<< [QME_DORP]
// eq/reg00008.H

//>> [QME_RVCR]
static const uint64_t QME_RVCR = 0x200e0084ull;

static const uint32_t QME_RVCR_RVID_VALUE = 1;
static const uint32_t QME_RVCR_RVID_VALUE_LEN = 7;
//<< [QME_RVCR]
// eq/reg00008.H

//>> [QME_SCOM_XIRAMRA]
static const uint64_t QME_SCOM_XIRAMRA = 0x200e0204ull;

static const uint32_t QME_SCOM_XIRAMRA_QME_SCOM_XIXCR_XCR = 1;
static const uint32_t QME_SCOM_XIRAMRA_QME_SCOM_XIXCR_XCR_LEN = 3;
static const uint32_t QME_SCOM_XIRAMRA_SPRG0 = 32;
static const uint32_t QME_SCOM_XIRAMRA_SPRG0_LEN = 32;
//<< [QME_SCOM_XIRAMRA]
// eq/reg00008.H

//>> [QME_SCOM_XIVDR28]
static const uint64_t QME_SCOM_XIVDR28 = 0x200e0298ull;

static const uint32_t QME_SCOM_XIVDR28_8 = 0;
static const uint32_t QME_SCOM_XIVDR28_8_LEN = 32;
static const uint32_t QME_SCOM_XIVDR28_9 = 32;
static const uint32_t QME_SCOM_XIVDR28_9_LEN = 32;
//<< [QME_SCOM_XIVDR28]
// eq/reg00008.H

//>> [QME_SCOM_XIVDR8]
static const uint64_t QME_SCOM_XIVDR8 = 0x200e0290ull;

static const uint32_t QME_SCOM_XIVDR8_8 = 0;
static const uint32_t QME_SCOM_XIVDR8_8_LEN = 32;
static const uint32_t QME_SCOM_XIVDR8_9 = 32;
static const uint32_t QME_SCOM_XIVDR8_9_LEN = 32;
//<< [QME_SCOM_XIVDR8]
// eq/reg00008.H

//>> [QME_SCRA]
static const uint64_t QME_SCRA_RW = 0x200e0124ull;
static const uint64_t QME_SCRA_WO_CLEAR = 0x200e0127ull;
static const uint64_t QME_SCRA_WO_OR = 0x200e0126ull;

static const uint32_t QME_SCRA_DATA = 0;
static const uint32_t QME_SCRA_DATA_LEN = 32;
//<< [QME_SCRA]
// eq/reg00008.H

//>> [SCAN_CAPTUREDR_LONG]
static const uint64_t SCAN_CAPTUREDR_LONG = 0x2003d000ull;

static const uint32_t SCAN_CAPTUREDR_LONG_SCAN_CAPTUREDR_LONG_REG = 0;
static const uint32_t SCAN_CAPTUREDR_LONG_SCAN_CAPTUREDR_LONG_REG_LEN = 32;
//<< [SCAN_CAPTUREDR_LONG]
// eq/reg00008.H

//>> [SCAN_REGION_TYPE]
static const uint64_t SCAN_REGION_TYPE = 0x20030005ull;

static const uint32_t SCAN_REGION_TYPE_SYSTEM_FAST_INIT = 0;
static const uint32_t SCAN_REGION_TYPE_PARALLEL_SCAN = 1;
static const uint32_t SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR = 2;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_VITL = 3;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_PERV = 4;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT1 = 5;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT2 = 6;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT3 = 7;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT4 = 8;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT5 = 9;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT6 = 10;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT7 = 11;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT8 = 12;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT9 = 13;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT10 = 14;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT11 = 15;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT12 = 16;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT13 = 17;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT14 = 18;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_FUNC = 48;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CFG = 49;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR = 50;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_REGF = 51;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_LBIST = 52;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_ABIST = 53;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_REPR = 54;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_TIME = 55;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_BNDY = 56;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_FARR = 57;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CMSK = 58;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_INEX = 59;
//<< [SCAN_REGION_TYPE]
// eq/reg00008.H

//>> [WOF]
static const uint64_t WOF = 0x20040021ull;

static const uint32_t WOF_ANY_WOF = 0;
static const uint32_t WOF_RESERVED1W = 1;
static const uint32_t WOF_ANY_LOCAL_XSTOP = 2;
static const uint32_t WOF_RESERVED3W = 3;
static const uint32_t WOF_PERV = 4;
static const uint32_t WOF_IN05 = 5;
static const uint32_t WOF_IN06 = 6;
static const uint32_t WOF_IN07 = 7;
static const uint32_t WOF_IN08 = 8;
static const uint32_t WOF_IN09 = 9;
static const uint32_t WOF_IN010 = 10;
static const uint32_t WOF_IN011 = 11;
static const uint32_t WOF_IN012 = 12;
static const uint32_t WOF_IN013 = 13;
static const uint32_t WOF_IN014 = 14;
static const uint32_t WOF_IN015 = 15;
static const uint32_t WOF_IN016 = 16;
static const uint32_t WOF_IN017 = 17;
static const uint32_t WOF_IN018 = 18;
static const uint32_t WOF_IN019 = 19;
static const uint32_t WOF_IN020 = 20;
static const uint32_t WOF_IN021 = 21;
static const uint32_t WOF_IN022 = 22;
static const uint32_t WOF_IN023 = 23;
static const uint32_t WOF_IN024 = 24;
static const uint32_t WOF_IN025 = 25;
static const uint32_t WOF_IN026 = 26;
static const uint32_t WOF_IN027 = 27;
static const uint32_t WOF_IN028 = 28;
static const uint32_t WOF_IN029 = 29;
static const uint32_t WOF_IN030 = 30;
static const uint32_t WOF_IN031 = 31;
static const uint32_t WOF_IN032 = 32;
static const uint32_t WOF_IN033 = 33;
static const uint32_t WOF_IN034 = 34;
static const uint32_t WOF_IN035 = 35;
static const uint32_t WOF_IN036 = 36;
static const uint32_t WOF_IN037 = 37;
static const uint32_t WOF_IN038 = 38;
static const uint32_t WOF_IN039 = 39;
static const uint32_t WOF_IN040 = 40;
static const uint32_t WOF_IN041 = 41;
static const uint32_t WOF_IN042 = 42;
static const uint32_t WOF_IN043 = 43;
static const uint32_t WOF_IN044 = 44;
static const uint32_t WOF_IN045 = 45;
static const uint32_t WOF_IN046 = 46;
static const uint32_t WOF_IN047 = 47;
static const uint32_t WOF_IN048 = 48;
static const uint32_t WOF_IN049 = 49;
static const uint32_t WOF_IN050 = 50;
static const uint32_t WOF_IN051 = 51;
static const uint32_t WOF_IN052 = 52;
static const uint32_t WOF_IN053 = 53;
//<< [WOF]
// eq/reg00008.H

//>> [XSTOP3]
static const uint64_t XSTOP3 = 0x2003000eull;

static const uint32_t XSTOP3_ENABLE = 0;
static const uint32_t XSTOP3_WAIT_SNOPA = 1;
static const uint32_t XSTOP3_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP3_WAIT_ALWAYS = 3;
static const uint32_t XSTOP3_REGION_PERV = 4;
static const uint32_t XSTOP3_REGION_UNIT1 = 5;
static const uint32_t XSTOP3_REGION_UNIT2 = 6;
static const uint32_t XSTOP3_REGION_UNIT3 = 7;
static const uint32_t XSTOP3_REGION_UNIT4 = 8;
static const uint32_t XSTOP3_REGION_UNIT5 = 9;
static const uint32_t XSTOP3_REGION_UNIT6 = 10;
static const uint32_t XSTOP3_REGION_UNIT7 = 11;
static const uint32_t XSTOP3_REGION_UNIT8 = 12;
static const uint32_t XSTOP3_REGION_UNIT9 = 13;
static const uint32_t XSTOP3_REGION_UNIT10 = 14;
static const uint32_t XSTOP3_REGION_UNIT11 = 15;
static const uint32_t XSTOP3_REGION_UNIT12 = 16;
static const uint32_t XSTOP3_REGION_UNIT13 = 17;
static const uint32_t XSTOP3_REGION_UNIT14 = 18;
static const uint32_t XSTOP3_WAIT_CYCLES = 48;
static const uint32_t XSTOP3_WAIT_CYCLES_LEN = 12;
//<< [XSTOP3]
// eq/reg00008.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00008.H"
#endif
#endif
