/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_6.H $         */
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

#ifndef __p10_scom_eq_6_H_
#define __p10_scom_eq_6_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_MEASURE_ONLY_MODE = 0x20018311ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1 = 4;
// eq/reg00006.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_IGNORE_CNT = 0x20018329ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_IGNORE_CNT_IGNORE_CNT_VALUE = 0;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_IGNORE_CNT_IGNORE_CNT_VALUE_LEN = 3;
// eq/reg00006.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_IS_LATE = 0x2001832bull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_IS_LATE_CACHE_IS_LATE_INVERT = 0;
// eq/reg00006.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_STICK_CORE_SYNC_DONE = 0x20018332ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_STICK_CORE_SYNC_DONE_CORE_SYNC_DONE_STICK = 0;
// eq/reg00006.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_SWAP_CORE_INC_DEC = 0x2001832eull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_SWAP_CORE_INC_DEC_CORE_INC_DEC_INVERT = 0;
// eq/reg00006.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG = 0x2001431bull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_MODE_FSM_STATE = 2;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_MODE_FSM_STATE_LEN = 6;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_INIT = 13;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_HOLD = 14;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_START = 15;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_LOAD_LP = 16;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_WAIT_LP = 17;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_LOAD_DAC = 18;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_WAIT_DAC = 19;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_LOAD_SENS_EN = 20;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_MEASURE = 21;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_COMP = 22;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_EVAL = 23;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_FINISH = 24;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_ERROR = 25;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_WAIT_LOCK = 26;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_MODEFSM_HOLD = 27;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_MODEFSM_ADJUST = 28;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_MODEFSM_ONE_SHOT = 29;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_MODEFSM_SINGLE_STP = 30;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_MODEFSM_MEAS_ONLY = 31;
// eq/reg00006.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_MEAS_MODE_VEC = 0x2001430dull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_MEAS_MODE_VEC_MEASURE_MODE_VECTOR = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_MEAS_MODE_VEC_MEASURE_MODE_VECTOR_LEN = 2;
// eq/reg00006.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_SINGLE_STEP_MODE = 0x20014304ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_SINGLE_STEP_MODE_ET_SINGLE_STEP_MD_SET = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_SINGLE_STEP_MODE_TEP_COUNT = 1;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_SINGLE_STEP_MODE_TEP_COUNT_LEN = 16;
// eq/reg00006.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_CORE_OVERRIDE = 0x20014326ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_CORE_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_CORE_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_CORE_OVERRIDE_VALUE_LEN = 4;
// eq/reg00006.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG = 0x2001231bull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_MODE_FSM_STATE = 2;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_MODE_FSM_STATE_LEN = 6;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_INIT = 13;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_HOLD = 14;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_START = 15;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_LOAD_LP = 16;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_WAIT_LP = 17;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_LOAD_DAC = 18;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_WAIT_DAC = 19;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_LOAD_SENS_EN = 20;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_MEASURE = 21;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_COMP = 22;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_EVAL = 23;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_FINISH = 24;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_ERROR = 25;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_STATE_WAIT_LOCK = 26;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_MODEFSM_HOLD = 27;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_MODEFSM_ADJUST = 28;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_MODEFSM_ONE_SHOT = 29;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_MODEFSM_SINGLE_STP = 30;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_MODE_FSM_STATE_REG_IS_MODEFSM_MEAS_ONLY = 31;
// eq/reg00006.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_ONE_SHOT_MODE = 0x20012303ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_ONE_SHOT_MODE_SET_ONE_SHOT_MD_SET1 = 3;
// eq/reg00006.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT = 0x2001231aull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_LOCK = 4;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_ADJUST_ERR = 5;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_DCSENSE_IN = 6;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_CHANGE = 7;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_CHANGE_LEN = 2;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_CHKSW_NO_OVR_PARATIY_ERROR = 9;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_CHKSW_NO_DCC_CONFIG_VISIBLE = 10;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_FSM_STATE = 11;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_FSM_STATE_LEN = 5;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_STEP_COUNT = 16;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SINGLE_STEP_COUNT_STEP_COUNT_LEN = 16;
// eq/reg00006.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CACHE_SYNC_ENABLE = 0x20011331ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CACHE_SYNC_ENABLE_ENABLE_OVERRIDE = 0;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CACHE_SYNC_ENABLE_VALUE_OVERRIDE = 1;
// eq/reg00006.H

static const uint64_t CPLT_CONF1_RW = 0x20000009ull;
static const uint64_t CPLT_CONF1_WO_CLEAR = 0x20000029ull;
static const uint64_t CPLT_CONF1_WO_OR = 0x20000019ull;

static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_DC = 0;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_DC_LEN = 3;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC = 3;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC_LEN = 4;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC = 7;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC_LEN = 3;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC = 10;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC_LEN = 2;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC = 12;
static const uint32_t CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC = 13;
static const uint32_t CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC = 14;
static const uint32_t CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC = 15;
// eq/reg00006.H

static const uint64_t CPLT_CTRL1_RW = 0x20000001ull;
static const uint64_t CPLT_CTRL1_WO_CLEAR = 0x20000021ull;
static const uint64_t CPLT_CTRL1_WO_OR = 0x20000011ull;

static const uint32_t CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t CPLT_CTRL1_REGION0_FENCE_DC = 4;
static const uint32_t CPLT_CTRL1_REGION1_FENCE_DC = 5;
static const uint32_t CPLT_CTRL1_REGION2_FENCE_DC = 6;
static const uint32_t CPLT_CTRL1_REGION3_FENCE_DC = 7;
static const uint32_t CPLT_CTRL1_REGION4_FENCE_DC = 8;
static const uint32_t CPLT_CTRL1_REGION5_FENCE_DC = 9;
static const uint32_t CPLT_CTRL1_REGION6_FENCE_DC = 10;
static const uint32_t CPLT_CTRL1_REGION7_FENCE_DC = 11;
static const uint32_t CPLT_CTRL1_REGION8_FENCE_DC = 12;
static const uint32_t CPLT_CTRL1_REGION9_FENCE_DC = 13;
static const uint32_t CPLT_CTRL1_REGION10_FENCE_DC = 14;
static const uint32_t CPLT_CTRL1_REGION11_FENCE_DC = 15;
static const uint32_t CPLT_CTRL1_REGION12_FENCE_DC = 16;
static const uint32_t CPLT_CTRL1_REGION13_FENCE_DC = 17;
static const uint32_t CPLT_CTRL1_REGION14_FENCE_DC = 18;
static const uint32_t CPLT_CTRL1_STG_ACT_EN_DC = 22;
// eq/reg00006.H

static const uint64_t EPS_DBG_INST1_COND_REG_3 = 0x200183e3ull;
// eq/reg00006.H

static const uint64_t EPS_DBG_INST2_COND_REG_3 = 0x200183e6ull;
// eq/reg00006.H

static const uint64_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ = 0x2005001cull;

static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// eq/reg00006.H

static const uint64_t L3TRA0_TR0_CONFIG_5 = 0x20018208ull;

static const uint32_t L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// eq/reg00006.H

static const uint64_t L3TRA1_TR1_TRACE_HI_DATA_REG = 0x20018260ull;

static const uint32_t L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// eq/reg00006.H

static const uint64_t L3TRA1_TR1_CONFIG_3 = 0x20018266ull;

static const uint32_t L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// eq/reg00006.H

static const uint64_t L3TRA2_TR0_TRACE_LO_DATA_REG = 0x20018281ull;

static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// eq/reg00006.H

static const uint64_t L3TRA2_TR1_CONFIG_4 = 0x200182a7ull;

static const uint32_t L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// eq/reg00006.H

static const uint64_t L3TRA3_TR0_CONFIG_2 = 0x200182c5ull;

static const uint32_t L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// eq/reg00006.H

static const uint64_t LOCAL_XSTOP_MASK_RW = 0x20040043ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_CLEAR = 0x20040063ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_OR = 0x20040053ull;

static const uint32_t LOCAL_XSTOP_MASK_01 = 1;
static const uint32_t LOCAL_XSTOP_MASK_02 = 2;
static const uint32_t LOCAL_XSTOP_MASK_03 = 3;
static const uint32_t LOCAL_XSTOP_MASK_04 = 4;
static const uint32_t LOCAL_XSTOP_MASK_05 = 5;
static const uint32_t LOCAL_XSTOP_MASK_06 = 6;
static const uint32_t LOCAL_XSTOP_MASK_07 = 7;
static const uint32_t LOCAL_XSTOP_MASK_08 = 8;
static const uint32_t LOCAL_XSTOP_MASK_09 = 9;
static const uint32_t LOCAL_XSTOP_MASK_10 = 10;
static const uint32_t LOCAL_XSTOP_MASK_11 = 11;
static const uint32_t LOCAL_XSTOP_MASK_12 = 12;
static const uint32_t LOCAL_XSTOP_MASK_13 = 13;
static const uint32_t LOCAL_XSTOP_MASK_14 = 14;
static const uint32_t LOCAL_XSTOP_MASK_15 = 15;
// eq/reg00006.H

static const uint64_t LOCAL_XSTOP_UNMASKED = 0x20040013ull;

static const uint32_t LOCAL_XSTOP_UNMASKED_IN = 1;
static const uint32_t LOCAL_XSTOP_UNMASKED_IN_LEN = 15;
// eq/reg00006.H

static const uint64_t QMETRA0_TR0_TRACE_LO_DATA_REG = 0x20018401ull;

static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t QMETRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// eq/reg00006.H

static const uint64_t QMETRA0_TR1_CONFIG_5 = 0x20018448ull;

static const uint32_t QMETRA0_TR1_CONFIG_5_C = 0;
static const uint32_t QMETRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t QMETRA0_TR1_CONFIG_5_D = 24;
static const uint32_t QMETRA0_TR1_CONFIG_5_D_LEN = 24;
// eq/reg00006.H

static const uint64_t QME_PPEBAR = 0x200e0050ull;

static const uint32_t QME_PPEBAR_BASE = 8;
static const uint32_t QME_PPEBAR_BASE_LEN = 36;
static const uint32_t QME_PPEBAR_SIZE = 61;
static const uint32_t QME_PPEBAR_SIZE_LEN = 3;
// eq/reg00006.H

static const uint64_t QME_QHTMEM = 0x200e01a4ull;

static const uint32_t QME_QHTMEM_ALLOC = 0;
static const uint32_t QME_QHTMEM_SCOPE = 1;
static const uint32_t QME_QHTMEM_SCOPE_LEN = 3;
static const uint32_t QME_QHTMEM_PRIORITY = 4;
static const uint32_t QME_QHTMEM_BASE = 8;
static const uint32_t QME_QHTMEM_BASE_LEN = 32;
static const uint32_t QME_QHTMEM_SIZE = 40;
static const uint32_t QME_QHTMEM_SIZE_LEN = 9;
// eq/reg00006.H

static const uint64_t QME_RCTAR2 = 0x200e0198ull;

static const uint32_t QME_RCTAR2_DATA = 0;
static const uint32_t QME_RCTAR2_DATA_LEN = 64;
// eq/reg00006.H

static const uint64_t QME_SCOM_PBTXTR3 = 0x200e0043ull;

static const uint32_t QME_SCOM_PBTXTR3_VALID = 0;
static const uint32_t QME_SCOM_PBTXTR3_VALID_LEN = 8;
static const uint32_t QME_SCOM_PBTXTR3_0 = 8;
static const uint32_t QME_SCOM_PBTXTR3_0_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_1 = 12;
static const uint32_t QME_SCOM_PBTXTR3_1_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_2 = 16;
static const uint32_t QME_SCOM_PBTXTR3_2_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_3 = 20;
static const uint32_t QME_SCOM_PBTXTR3_3_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_4 = 24;
static const uint32_t QME_SCOM_PBTXTR3_4_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_5 = 28;
static const uint32_t QME_SCOM_PBTXTR3_5_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_6 = 32;
static const uint32_t QME_SCOM_PBTXTR3_6_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_7 = 36;
static const uint32_t QME_SCOM_PBTXTR3_7_LEN = 4;
// eq/reg00006.H

static const uint64_t QME_SCOM_XIRAMEDR = 0x200e0210ull;

static const uint32_t QME_SCOM_XIRAMEDR_IR = 0;
static const uint32_t QME_SCOM_XIRAMEDR_IR_LEN = 32;
static const uint32_t QME_SCOM_XIRAMEDR_EDR = 32;
static const uint32_t QME_SCOM_XIRAMEDR_EDR_LEN = 32;
// eq/reg00006.H

static const uint64_t QME_SCOM_XIVDR2 = 0x200e0284ull;

static const uint32_t QME_SCOM_XIVDR2_2 = 0;
static const uint32_t QME_SCOM_XIVDR2_2_LEN = 32;
static const uint32_t QME_SCOM_XIVDR2_3 = 32;
static const uint32_t QME_SCOM_XIVDR2_3_LEN = 32;
// eq/reg00006.H

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00006.H"
#endif
#endif
