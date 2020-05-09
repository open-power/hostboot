/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_d.H $       */
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

#ifndef __p10_scom_perv_d_H_
#define __p10_scom_perv_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [CC_ATOMIC_LOCK_REG]
static const uint64_t CC_ATOMIC_LOCK_REG = 0x000303ffull;

static const uint32_t CC_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CC_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CC_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [CC_ATOMIC_LOCK_REG]
// perv/reg00026.H

//>> [CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE]
static const uint64_t CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE = 0x00018306ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE_VALUE_LEN = 8;
//<< [CLK_ADJ_00_DCADJ_WRAP_DCC_OVERRIDE]
// perv/reg00026.H

//>> [CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG]
static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG = 0x0001830cull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE = 0;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR = 1;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR = 2;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE = 3;
//<< [CLK_ADJ_00_DCADJ_WRAP_SET_CONFIG]
// perv/reg00026.H

//>> [CLK_ADJ_00_DCADJ_WRAP_SET_ONE_SHOT_MODE]
static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_ONE_SHOT_MODE = 0x00018303ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_ONE_SHOT_MODE_SET_ONE_SHOT_MD_SET1 = 3;
//<< [CLK_ADJ_00_DCADJ_WRAP_SET_ONE_SHOT_MODE]
// perv/reg00026.H

//>> [CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT]
static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SINGLE_STEP_COUNT = 0x0001831aull;

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
// perv/reg00026.H

//>> [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES]
static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_INC_DEC_FSM_STATES = 0x00014337ull;

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
// perv/reg00026.H

//>> [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE]
static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE = 0x00014330ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE_ENABLE_OVERRIDE = 0;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE_VALUE_OVERRIDE = 1;
//<< [CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CORE_SYNC_ENABLE]
// perv/reg00026.H

//>> [CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE]
static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE = 0x00012304ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE_ET_SINGLE_STEP_MD_SET = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE_TEP_COUNT = 1;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE_TEP_COUNT_LEN = 16;
//<< [CLK_ADJ_02_DCADJ_WRAP_SET_SINGLE_STEP_MODE]
// perv/reg00026.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE = 0x00012327ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE_LEN = 4;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]
// perv/reg00026.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE = 0x00012321ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_SINGLE_STEP_MD_SET = 0;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_ONE_SHOT_MD_SET = 1;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_ADJUST_MD_SET = 2;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_HOLD_MD_SET = 3;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE_INIT_MD_SET = 4;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE]
// perv/reg00026.H

//>> [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS]
static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS = 0x0001232cull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS_CORE_PDLYS_INVERT = 0;
//<< [CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS]
// perv/reg00026.H

//>> [CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_AVERAGE_MEASUREMENT = 0x00011319ull;

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
// perv/reg00026.H

//>> [CLK_ADJ_03_DCADJ_WRAP_SET_MEAS_MODE_VEC]
static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_MEAS_MODE_VEC = 0x0001130dull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_MEAS_MODE_VEC_MEASURE_MODE_VECTOR = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_MEAS_MODE_VEC_MEASURE_MODE_VECTOR_LEN = 2;
//<< [CLK_ADJ_03_DCADJ_WRAP_SET_MEAS_MODE_VEC]
// perv/reg00026.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE = 0x00011333ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK = 0;
//<< [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]
// perv/reg00026.H

//>> [CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES]
static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SYNC_DONE_FSM_STATES = 0x00011338ull;

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
// perv/reg00026.H

//>> [CTRL_ATOMIC_LOCK_REG]
static const uint64_t CTRL_ATOMIC_LOCK_REG = 0x000003ffull;

static const uint32_t CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [CTRL_ATOMIC_LOCK_REG]
// perv/reg00026.H

//>> [EPS_DBG_DEBUG_TRACE_CONTROL]
static const uint64_t EPS_DBG_DEBUG_TRACE_CONTROL = 0x000107d0ull;

static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_START = 0;
static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_STOP = 1;
static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_RESET = 2;
//<< [EPS_DBG_DEBUG_TRACE_CONTROL]
// perv/reg00026.H

//>> [EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ]
static const uint64_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ = 0x0005003cull;

static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
//<< [EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_CBS_EL_HIST]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_CBS_EL_HIST = 0x00050006ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_EL_HIST_FSI = 0x00002806ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE = 0x00002818ull;
//<< [FSXCOMP_FSXLOG_CBS_EL_HIST]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_M1A_DATA_AREA_0]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_0_FSI = 0x00002840ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_0_FSI_BYTE = 0x00002900ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_0_RW = 0x00050040ull;

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_0_MDA_M1A_DATA_AREA_0 = 0;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_0_MDA_M1A_DATA_AREA_0_LEN = 32;
//<< [FSXCOMP_FSXLOG_M1A_DATA_AREA_0]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_M2A_DATA_AREA_13]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_13_FSI = 0x000028cdull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_13_FSI_BYTE = 0x00002b34ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_13_RW = 0x000500cdull;

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_13_MDA_M2A_DATA_AREA_13 = 0;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_13_MDA_M2A_DATA_AREA_13_LEN = 32;
//<< [FSXCOMP_FSXLOG_M2A_DATA_AREA_13]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_M2B_DATA_AREA_6]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_6_FSI = 0x00002906ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_6_FSI_BYTE = 0x00002c18ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_6_RO = 0x00050106ull;

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_6_MDA_M2B_DATA_AREA_6 = 0;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_6_MDA_M2B_DATA_AREA_6_LEN = 32;
//<< [FSXCOMP_FSXLOG_M2B_DATA_AREA_6]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL0_COPY]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI = 0x00002910ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE = 0x00002c40ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW = 0x00050110ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG_LEN = 32;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL0_COPY]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL5]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FSI = 0x00002815ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE = 0x00002854ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_RW = 0x00050015ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FILT = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FILT_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT_LEN = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL5]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_FSI = 0x00002936ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_FSI_BYTE = 0x00002cd8ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_WO_CLEAR = 0x00050136ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_SYS0_RX_REFCLK_TERM = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_SYS0_RX_REFCLK_TERM_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_SYS1_RX_REFCLK_TERM = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_SYS1_RX_REFCLK_TERM_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_PCI0_RX_REFCLK_TERM = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_PCI0_RX_REFCLK_TERM_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_PCI1_RX_REFCLK_TERM = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_PCI1_RX_REFCLK_TERM_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_8_31 = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_8_31_LEN = 24;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_SB_MSG]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SB_MSG = 0x00050009ull;
static const uint32_t FSXCOMP_FSXLOG_SB_MSG_FSI = 0x00002809ull;
static const uint32_t FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE = 0x00002824ull;
//<< [FSXCOMP_FSXLOG_SB_MSG]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_SCRATCH_REGISTER_1]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI = 0x00002838ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE = 0x000028e0ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW = 0x00050038ull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1_LEN = 32;
//<< [FSXCOMP_FSXLOG_SCRATCH_REGISTER_1]
// perv/reg00026.H

//>> [L3TRA0_TR0_CONFIG_9]
static const uint64_t L3TRA0_TR0_CONFIG_9 = 0x00018209ull;

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
// perv/reg00026.H

//>> [L3TRA0_TR1_CONFIG_0]
static const uint64_t L3TRA0_TR1_CONFIG_0 = 0x00018223ull;

static const uint32_t L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
//<< [L3TRA0_TR1_CONFIG_0]
// perv/reg00026.H

//>> [L3TRA2_TR0_CONFIG_1]
static const uint64_t L3TRA2_TR0_CONFIG_1 = 0x00018284ull;

static const uint32_t L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
//<< [L3TRA2_TR0_CONFIG_1]
// perv/reg00026.H

//>> [L3TRA2_TR1_CONFIG]
static const uint64_t L3TRA2_TR1_CONFIG = 0x000182a2ull;

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
// perv/reg00026.H

//>> [L3TRA3_TR0_CONFIG]
static const uint64_t L3TRA3_TR0_CONFIG = 0x000182c2ull;

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
// perv/reg00026.H

//>> [OPCG_CAPT1]
static const uint64_t OPCG_CAPT1 = 0x00030010ull;

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
// perv/reg00026.H

//>> [OTPC_M_COMMAND_REGISTER]
static const uint64_t OTPC_M_COMMAND_REGISTER = 0x00010000ull;

static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_BIT_WITHSTART = 0;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_BIT_WITHADDR = 1;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_BIT_READCONT = 2;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_BIT_WITHSTOP = 3;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_LENGTH = 4;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_LENGTH_LEN = 4;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_BIT_RNW = 15;
static const uint32_t OTPC_M_COMMAND_REGISTER_REG_ADDR_LEN = 23;
static const uint32_t OTPC_M_COMMAND_REGISTER_REG_ADDR_LEN_LEN = 3;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_1 = 32;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_1_LEN = 8;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_2 = 40;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_2_LEN = 8;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_3 = 48;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_3_LEN = 8;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_4 = 56;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_4_LEN = 8;
//<< [OTPC_M_COMMAND_REGISTER]
// perv/reg00026.H

//>> [OTPC_M_MEASURE_REG0]
static const uint64_t OTPC_M_MEASURE_REG0 = 0x00010010ull;

static const uint32_t OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA_LEN = 64;
//<< [OTPC_M_MEASURE_REG0]
// perv/reg00026.H

//>> [PRIMARY_ADDRESS_REG]
static const uint64_t PRIMARY_ADDRESS_REG = 0x000f0000ull;

static const uint32_t PRIMARY_ADDRESS_REG_PRIMARY_ADDRESS = 0;
static const uint32_t PRIMARY_ADDRESS_REG_PRIMARY_ADDRESS_LEN = 6;
//<< [PRIMARY_ADDRESS_REG]
// perv/reg00026.H

//>> [QMETRA0_TR0_CONFIG_0]
static const uint64_t QMETRA0_TR0_CONFIG_0 = 0x00018403ull;

static const uint32_t QMETRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t QMETRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
//<< [QMETRA0_TR0_CONFIG_0]
// perv/reg00026.H

//>> [QMETRA0_TR1_CONFIG_9]
static const uint64_t QMETRA0_TR1_CONFIG_9 = 0x00018449ull;

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
// perv/reg00026.H

//>> [RECOV_MASK]
static const uint64_t RECOV_MASK_RW = 0x00040041ull;
static const uint64_t RECOV_MASK_WO_CLEAR = 0x00040061ull;
static const uint64_t RECOV_MASK_WO_OR = 0x00040051ull;

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
// perv/reg00026.H

//>> [REC_ERR_MST4_REG3]
static const uint64_t REC_ERR_MST4_REG3 = 0x000f0053ull;

static const uint32_t REC_ERR_MST4_REG3_48_MST4_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST4_REG3_48_MST4_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST4_REG3_48_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_49_MST4_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST4_REG3_49_MST4_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST4_REG3_49_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_50_MST4_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST4_REG3_50_MST4_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST4_REG3_50_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_51_MST4_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST4_REG3_51_MST4_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST4_REG3_51_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_52_MST4_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST4_REG3_52_MST4_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST4_REG3_52_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_53_MST4_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST4_REG3_53_MST4_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST4_REG3_53_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_54_MST4_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST4_REG3_54_MST4_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST4_REG3_54_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_55_MST4_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST4_REG3_55_MST4_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST4_REG3_55_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_56_MST4_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST4_REG3_56_MST4_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST4_REG3_56_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_57_MST4_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST4_REG3_57_MST4_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST4_REG3_57_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_58_MST4_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST4_REG3_58_MST4_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST4_REG3_58_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_59_MST4_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST4_REG3_59_MST4_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST4_REG3_59_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_60_MST4_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST4_REG3_60_MST4_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST4_REG3_60_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_61_MST4_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST4_REG3_61_MST4_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST4_REG3_61_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_62_MST4_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST4_REG3_62_MST4_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST4_REG3_62_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_63_MST4_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST4_REG3_63_MST4_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST4_REG3_63_MST4_ERROR_CODE_LEN = 3;
//<< [REC_ERR_MST4_REG3]
// perv/reg00026.H

//>> [SCAN_UPDATEDR_LONG]
static const uint64_t SCAN_UPDATEDR_LONG = 0x0003b000ull;

static const uint32_t SCAN_UPDATEDR_LONG_SCAN_UPDATEDR_LONG_REG = 0;
static const uint32_t SCAN_UPDATEDR_LONG_SCAN_UPDATEDR_LONG_REG_LEN = 32;
//<< [SCAN_UPDATEDR_LONG]
// perv/reg00026.H

//>> [SINGLE_OTP_ROM_OTPROM_REG102]
static const uint64_t SINGLE_OTP_ROM_OTPROM_REG102 = 0x00018066ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG102_REGISTER102 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG102_REGISTER102_LEN = 64;
//<< [SINGLE_OTP_ROM_OTPROM_REG102]
// perv/reg00026.H

//>> [SINGLE_OTP_ROM_OTPROM_REG13]
static const uint64_t SINGLE_OTP_ROM_OTPROM_REG13 = 0x0001800dull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG13_REGISTER13 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG13_REGISTER13_LEN = 64;
//<< [SINGLE_OTP_ROM_OTPROM_REG13]
// perv/reg00026.H

//>> [SINGLE_OTP_ROM_OTPROM_REG24]
static const uint64_t SINGLE_OTP_ROM_OTPROM_REG24 = 0x00018018ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG24_REGISTER24 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG24_REGISTER24_LEN = 64;
//<< [SINGLE_OTP_ROM_OTPROM_REG24]
// perv/reg00026.H

//>> [SINGLE_OTP_ROM_OTPROM_REG3]
static const uint64_t SINGLE_OTP_ROM_OTPROM_REG3 = 0x00018003ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG3_REGISTER3 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG3_REGISTER3_LEN = 64;
//<< [SINGLE_OTP_ROM_OTPROM_REG3]
// perv/reg00026.H

//>> [SINGLE_OTP_ROM_OTPROM_REG45]
static const uint64_t SINGLE_OTP_ROM_OTPROM_REG45 = 0x0001802dull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG45_REGISTER45 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG45_REGISTER45_LEN = 64;
//<< [SINGLE_OTP_ROM_OTPROM_REG45]
// perv/reg00026.H

//>> [SINGLE_OTP_ROM_OTPROM_REG72]
static const uint64_t SINGLE_OTP_ROM_OTPROM_REG72 = 0x00018048ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG72_REGISTER72 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG72_REGISTER72_LEN = 64;
//<< [SINGLE_OTP_ROM_OTPROM_REG72]
// perv/reg00026.H

//>> [SINGLE_OTP_ROM_OTPROM_REG87]
static const uint64_t SINGLE_OTP_ROM_OTPROM_REG87 = 0x00018057ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG87_REGISTER87 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG87_REGISTER87_LEN = 64;
//<< [SINGLE_OTP_ROM_OTPROM_REG87]
// perv/reg00026.H

//>> [SINGLE_OTP_ROM_OTPROM_REG98]
static const uint64_t SINGLE_OTP_ROM_OTPROM_REG98 = 0x00018062ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG98_REGISTER98 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG98_REGISTER98_LEN = 64;
//<< [SINGLE_OTP_ROM_OTPROM_REG98]
// perv/reg00026.H

//>> [TOD_FSM_REG]
static const uint64_t TOD_FSM_REG = 0x00040024ull;

static const uint32_t TOD_FSM_REG_I_PATH_FSM_STATE = 0;
static const uint32_t TOD_FSM_REG_I_PATH_FSM_STATE_LEN = 4;
static const uint32_t TOD_FSM_REG_TOD_IS_RUNNING = 4;
static const uint32_t TOD_FSM_REG_REG_0X24_SPARE_05_07 = 5;
static const uint32_t TOD_FSM_REG_REG_0X24_SPARE_05_07_LEN = 3;
//<< [TOD_FSM_REG]
// perv/reg00026.H

//>> [TOD_PSS_MSS_STATUS_REG]
static const uint64_t TOD_PSS_MSS_STATUS_REG = 0x00040008ull;

static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT = 0;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN = 3;
static const uint32_t TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 = 3;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS = 4;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS = 5;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID = 6;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID = 7;
static const uint32_t TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID = 8;
static const uint32_t TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID = 9;
static const uint32_t TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID = 10;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS = 11;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS = 12;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS = 13;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS = 14;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS = 15;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS = 16;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS = 17;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS = 18;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS = 19;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_RUNNING = 20;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_PRIMARY = 21;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_SECONDARY = 22;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER = 23;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER = 24;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_SLAVE = 25;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT = 26;
static const uint32_t TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT = 27;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH = 28;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH = 29;
static const uint32_t TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 = 30;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER = 31;
//<< [TOD_PSS_MSS_STATUS_REG]
// perv/reg00027.H

//>> [TOD_S_PATH_STATUS_REG]
static const uint64_t TOD_S_PATH_STATUS_REG = 0x0004000aull;

static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE = 0;
static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE_LEN = 4;
static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE = 4;
static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE_LEN = 4;
static const uint32_t TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO_LEN = 5;
static const uint32_t TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15 = 13;
static const uint32_t TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15_LEN = 3;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_CPS = 16;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_CPS_LEN = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_CPS = 24;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_CPS_LEN = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT = 32;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT_LEN = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT = 40;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT_LEN = 8;
//<< [TOD_S_PATH_STATUS_REG]
// perv/reg00027.H

//>> [TRA0_TR0_CONFIG_9]
static const uint64_t TRA0_TR0_CONFIG_9 = 0x00010409ull;

static const uint32_t TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t TRA0_TR0_CONFIG_9_SPARE_LT = 37;
//<< [TRA0_TR0_CONFIG_9]
// perv/reg00027.H

//>> [TRA0_TR1_CONFIG_0]
static const uint64_t TRA0_TR1_CONFIG_0 = 0x00010443ull;

static const uint32_t TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
//<< [TRA0_TR1_CONFIG_0]
// perv/reg00027.H

//>> [TRA1_TR1_TRACE_HI_DATA_REG]
static const uint64_t TRA1_TR1_TRACE_HI_DATA_REG = 0x000104c0ull;

static const uint32_t TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
//<< [TRA1_TR1_TRACE_HI_DATA_REG]
// perv/reg00027.H

//>> [TRA2_TR0_TRACE_LO_DATA_REG]
static const uint64_t TRA2_TR0_TRACE_LO_DATA_REG = 0x00010501ull;

static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
//<< [TRA2_TR0_TRACE_LO_DATA_REG]
// perv/reg00027.H

//>> [TRA2_TR0_CONFIG_1]
static const uint64_t TRA2_TR0_CONFIG_1 = 0x00010504ull;

static const uint32_t TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
//<< [TRA2_TR0_CONFIG_1]
// perv/reg00027.H

//>> [TRA4_TR1_CONFIG]
static const uint64_t TRA4_TR1_CONFIG = 0x00010642ull;

static const uint32_t TRA4_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA4_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA4_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA4_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA4_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TRA4_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA4_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA4_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA4_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA4_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA4_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA4_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA4_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TRA4_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TRA4_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
//<< [TRA4_TR1_CONFIG]
// perv/reg00027.H

//>> [TRA5_TR0_CONFIG]
static const uint64_t TRA5_TR0_CONFIG = 0x00010682ull;

static const uint32_t TRA5_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA5_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA5_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA5_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA5_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA5_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA5_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA5_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA5_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA5_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA5_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA5_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA5_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TRA5_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TRA5_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
//<< [TRA5_TR0_CONFIG]
// perv/reg00027.H

//>> [TRA5_TR0_CONFIG_0]
static const uint64_t TRA5_TR0_CONFIG_0 = 0x00010683ull;

static const uint32_t TRA5_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA5_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
//<< [TRA5_TR0_CONFIG_0]
// perv/reg00027.H

//>> [TRA5_TR1_CONFIG_9]
static const uint64_t TRA5_TR1_CONFIG_9 = 0x000106c9ull;

static const uint32_t TRA5_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA5_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA5_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA5_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA5_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA5_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t TRA5_TR1_CONFIG_9_SPARE_LT = 37;
//<< [TRA5_TR1_CONFIG_9]
// perv/reg00027.H

//>> [XSTOP5]
static const uint64_t XSTOP5 = 0x00030015ull;

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
// perv/reg00027.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00026.H"
#include "perv/reg00027.H"
#endif
#endif
