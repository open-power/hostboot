/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_3.H $         */
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

#ifndef __p10_scom_eq_3_H_
#define __p10_scom_eq_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_DEC_DCC = 0x2001830full;
// eq/reg00003.H

static const uint64_t CLK_ADJ_00_DCADJ_WRAP_SET_MEAS_MODE_VEC = 0x2001830dull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_MEAS_MODE_VEC_MEASURE_MODE_VECTOR = 0;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_SET_MEAS_MODE_VEC_MEASURE_MODE_VECTOR_LEN = 2;
// eq/reg00003.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE = 0x20018324ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE_STEP_COUNT = 0;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE_STEP_COUNT_LEN = 32;
// eq/reg00003.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_CHICKEN_SWITCHES = 0x20014335ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_CHICKEN_SWITCHES_STOP_ON_ERROR = 0;
// eq/reg00003.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_DEC_DCC = 0x2001230full;
// eq/reg00003.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_LOW_PASS_DLY = 0x20012309ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_LOW_PASS_DLY_LOW_PASS_DELAY_VALUE = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_LOW_PASS_DLY_LOW_PASS_DELAY_VALUE_LEN = 16;
// eq/reg00003.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_OVERRIDE = 0x20012326ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CORE_OVERRIDE_VALUE_LEN = 4;
// eq/reg00003.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_IS_LATE = 0x2001232aull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_IS_LATE_CORE_IS_LATE_INVERT = 0;
// eq/reg00003.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_ONE_SHOT_MODE = 0x20011303ull;
// eq/reg00003.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT = 0x2001131aull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_MODE_FSM_STATE = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_MODE_FSM_STATE_LEN = 3;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_LOCK = 4;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_ADJUST_ERR = 5;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_DCSENSE_IN = 6;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_CHANGE = 7;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_DCC_CHANGE_LEN = 2;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_CHKSW_NO_OVR_PARATIY_ERROR = 9;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_CHKSW_NO_DCC_CONFIG_VISIBLE = 10;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_FSM_STATE = 11;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_FSM_STATE_LEN = 5;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_STEP_COUNT = 16;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SINGLE_STEP_COUNT_STEP_COUNT_LEN = 16;
// eq/reg00003.H

static const uint64_t CLOCK_STAT_NSL = 0x20030009ull;

static const uint32_t CLOCK_STAT_NSL_PERV_NSL = 4;
static const uint32_t CLOCK_STAT_NSL_UNIT1_NSL = 5;
static const uint32_t CLOCK_STAT_NSL_UNIT2_NSL = 6;
static const uint32_t CLOCK_STAT_NSL_UNIT3_NSL = 7;
static const uint32_t CLOCK_STAT_NSL_UNIT4_NSL = 8;
static const uint32_t CLOCK_STAT_NSL_UNIT5_NSL = 9;
static const uint32_t CLOCK_STAT_NSL_UNIT6_NSL = 10;
static const uint32_t CLOCK_STAT_NSL_UNIT7_NSL = 11;
static const uint32_t CLOCK_STAT_NSL_UNIT8_NSL = 12;
static const uint32_t CLOCK_STAT_NSL_UNIT9_NSL = 13;
static const uint32_t CLOCK_STAT_NSL_UNIT10_NSL = 14;
static const uint32_t CLOCK_STAT_NSL_UNIT11_NSL = 15;
static const uint32_t CLOCK_STAT_NSL_UNIT12_NSL = 16;
static const uint32_t CLOCK_STAT_NSL_UNIT13_NSL = 17;
static const uint32_t CLOCK_STAT_NSL_UNIT14_NSL = 18;
// eq/reg00003.H

static const uint64_t EPS_FIR_ANY_LOCAL_ERR_MASK = 0x20040080ull;

static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_XSTOP_TO_PCB = 0;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_RECOV_TO_PCB = 1;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_SPATTN_TO_PCB = 2;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_LOCAL_XSTOP_TO_PCB = 3;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_HOSTATTN_TO_PCB = 4;
// eq/reg00003.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT2 = 0x20050002ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// eq/reg00003.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA1 = 0x2005001aull;
// eq/reg00003.H

static const uint64_t EPS_THERM_WSUB_MODE_REG = 0x2005000full;

static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// eq/reg00003.H

static const uint64_t EPS_THERM_WSUB2_DTS_RESULT0 = 0x20050020ull;

static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_2_RESULT_LEN = 16;
// eq/reg00003.H

static const uint64_t EPS_THERM_WSUB2_INJECT_REG = 0x20050031ull;

static const uint32_t EPS_THERM_WSUB2_INJECT_REG_TRIP = 0;
static const uint32_t EPS_THERM_WSUB2_INJECT_REG_TRIP_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_INJECT_REG_MODE = 2;
static const uint32_t EPS_THERM_WSUB2_INJECT_REG_MODE_LEN = 2;
// eq/reg00003.H

static const uint64_t L3TRA0_TR0_CONFIG_3 = 0x20018206ull;

static const uint32_t L3TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t L3TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t L3TRA0_TR0_CONFIG_3_D_LEN = 24;
// eq/reg00003.H

static const uint64_t L3TRA1_TR1_TRACE_LO_DATA_REG = 0x20018261ull;

static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// eq/reg00003.H

static const uint64_t L3TRA1_TR1_CONFIG_5 = 0x20018268ull;

static const uint32_t L3TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t L3TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t L3TRA1_TR1_CONFIG_5_D_LEN = 24;
// eq/reg00003.H

static const uint64_t L3TRA2_TR0_TRACE_HI_DATA_REG = 0x20018280ull;

static const uint32_t L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// eq/reg00003.H

static const uint64_t L3TRA2_TR0_CONFIG = 0x20018282ull;

static const uint32_t L3TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t L3TRA2_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t L3TRA2_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// eq/reg00003.H

static const uint64_t L3TRA2_TR1_CONFIG_2 = 0x200182a5ull;

static const uint32_t L3TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t L3TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t L3TRA2_TR1_CONFIG_2_B_LEN = 24;
// eq/reg00003.H

static const uint64_t L3TRA3_TR0_CONFIG_4 = 0x200182c7ull;

static const uint32_t L3TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t L3TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t L3TRA3_TR0_CONFIG_4_B_LEN = 24;
// eq/reg00003.H

static const uint64_t L3TRA3_TR1_CONFIG = 0x200182e2ull;

static const uint32_t L3TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t L3TRA3_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t L3TRA3_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// eq/reg00003.H

static const uint64_t LOCAL_XSTOP = 0x20040003ull;

static const uint32_t LOCAL_XSTOP_ANY_LOCAL_XSTOP = 0;
static const uint32_t LOCAL_XSTOP_RESERVED1L = 1;
static const uint32_t LOCAL_XSTOP_RESERVED2L = 2;
static const uint32_t LOCAL_XSTOP_RESERVED3L = 3;
static const uint32_t LOCAL_XSTOP_PERV = 4;
static const uint32_t LOCAL_XSTOP_IN05 = 5;
static const uint32_t LOCAL_XSTOP_IN06 = 6;
static const uint32_t LOCAL_XSTOP_IN07 = 7;
static const uint32_t LOCAL_XSTOP_IN08 = 8;
static const uint32_t LOCAL_XSTOP_IN09 = 9;
static const uint32_t LOCAL_XSTOP_IN10 = 10;
static const uint32_t LOCAL_XSTOP_IN11 = 11;
static const uint32_t LOCAL_XSTOP_IN12 = 12;
static const uint32_t LOCAL_XSTOP_IN13 = 13;
static const uint32_t LOCAL_XSTOP_IN14 = 14;
static const uint32_t LOCAL_XSTOP_IN15 = 15;
// eq/reg00003.H

static const uint64_t LXSTOP_INTERRUPT_REG = 0x200f002aull;
// eq/reg00003.H

static const uint64_t MULTICAST_GROUP_1 = 0x200f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// eq/reg00003.H

static const uint64_t NET_CTRL0_RW = 0x200f0040ull;
static const uint64_t NET_CTRL0_RW_WAND = 0x200f0041ull;
static const uint64_t NET_CTRL0_RW_WOR = 0x200f0042ull;

static const uint32_t NET_CTRL0_CHIPLET_ENABLE = 0;
static const uint32_t NET_CTRL0_PCB_EP_RESET = 1;
static const uint32_t NET_CTRL0_CLK_ASYNC_RESET = 2;
static const uint32_t NET_CTRL0_PLL_TEST_EN = 3;
static const uint32_t NET_CTRL0_PLL_RESET = 4;
static const uint32_t NET_CTRL0_PLL_BYPASS = 5;
static const uint32_t NET_CTRL0_VITAL_SCAN = 6;
static const uint32_t NET_CTRL0_VITAL_SCAN_IN = 7;
static const uint32_t NET_CTRL0_VITAL_PHASE = 8;
static const uint32_t NET_CTRL0_FLUSH_ALIGN_OVR = 9;
static const uint32_t NET_CTRL0_VITAL_AL = 10;
static const uint32_t NET_CTRL0_ACT_DIS = 11;
static const uint32_t NET_CTRL0_TOADMODE_EN = 12;
static const uint32_t NET_CTRL0_SYNC_PULSE = 13;
static const uint32_t NET_CTRL0_MPW3 = 14;
static const uint32_t NET_CTRL0_DELAY_LCLKR = 15;
static const uint32_t NET_CTRL0_VITAL_THOLD = 16;
static const uint32_t NET_CTRL0_FLUSH_SCAN_N = 17;
static const uint32_t NET_CTRL0_FENCE_EN = 18;
static const uint32_t NET_CTRL0_CPLT_RCTRL = 19;
static const uint32_t NET_CTRL0_CPLT_DCTRL = 20;
static const uint32_t NET_CTRL0_CPLT_RCTRL2 = 21;
static const uint32_t NET_CTRL0_ADJ_FUNC_CLKSEL = 22;
static const uint32_t NET_CTRL0_PM_ACCESS = 23;
static const uint32_t NET_CTRL0_FUNC_LCB_EDIS = 24;
static const uint32_t NET_CTRL0_TP_FENCE_PCB = 25;
static const uint32_t NET_CTRL0_LVLTRANS_FENCE = 26;
static const uint32_t NET_CTRL0_ARRAY_WRITE_ASSIST_EN = 27;
static const uint32_t NET_CTRL0_HTB_INTEST = 28;
static const uint32_t NET_CTRL0_HTB_EXTEST = 29;
// ERROR Duplicate Dial         static const uint32_t NET_CTRL0_PM_ACCESS = 30;
static const uint32_t NET_CTRL0_PLLFORCE_OUT_EN = 31;
// eq/reg00003.H

static const uint64_t PHASE_COUNTER_RESET = 0x20030028ull;

static const uint32_t PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// eq/reg00003.H

static const uint64_t PLL_LOCK_REG = 0x200f0019ull;
// eq/reg00003.H

static const uint64_t QME_DB1 = 0x200e0104ull;

static const uint32_t QME_DB1_NUMBER = 0;
static const uint32_t QME_DB1_NUMBER_LEN = 8;
static const uint32_t QME_DB1_DATA = 8;
static const uint32_t QME_DB1_DATA_LEN = 56;
// eq/reg00003.H

static const uint64_t QME_PCBSID = 0x200e0034ull;

static const uint32_t QME_PCBSID_EQ_VLD = 0;
static const uint32_t QME_PCBSID_EQ_MERGING_SCHEME = 2;
static const uint32_t QME_PCBSID_EQ_MERGING_SCHEME_LEN = 3;
static const uint32_t QME_PCBSID_SP_ACK = 7;
static const uint32_t QME_PCBSID_EQ_RD_NOT_WR = 8;
static const uint32_t QME_PCBSID_EQ_P = 9;
static const uint32_t QME_PCBSID_EQ_LOCAL_ADDR_P = 10;
static const uint32_t QME_PCBSID_EQ_PORT = 12;
static const uint32_t QME_PCBSID_EQ_PORT_LEN = 4;
static const uint32_t QME_PCBSID_EQ_LOCAL_ADDR = 16;
static const uint32_t QME_PCBSID_EQ_LOCAL_ADDR_LEN = 16;
// eq/reg00003.H

static const uint64_t QME_RS4DBGS = 0x200e015cull;

static const uint32_t QME_RS4DBGS_ACTUAL_BITS = 16;
static const uint32_t QME_RS4DBGS_ACTUAL_BITS_LEN = 16;
static const uint32_t QME_RS4DBGS_MACHINE_STATE = 32;
static const uint32_t QME_RS4DBGS_MACHINE_STATE_LEN = 4;
static const uint32_t QME_RS4DBGS_STATE_COUNT = 36;
static const uint32_t QME_RS4DBGS_STATE_COUNT_LEN = 4;
static const uint32_t QME_RS4DBGS_CURRENT_NIBBLE = 40;
static const uint32_t QME_RS4DBGS_CURRENT_NIBBLE_LEN = 4;
static const uint32_t QME_RS4DBGS_CARE_MASK = 44;
static const uint32_t QME_RS4DBGS_CARE_MASK_LEN = 4;
static const uint32_t QME_RS4DBGS_TERMINATE_COUNT = 48;
static const uint32_t QME_RS4DBGS_TERMINATE_COUNT_LEN = 4;
static const uint32_t QME_RS4DBGS_SCAN_MODE = 52;
static const uint32_t QME_RS4DBGS_SCAN_COUNT = 58;
static const uint32_t QME_RS4DBGS_SCAN_COUNT_LEN = 6;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIVDR4 = 0x200e0288ull;

static const uint32_t QME_SCOM_XIVDR4_4 = 0;
static const uint32_t QME_SCOM_XIVDR4_4_LEN = 32;
static const uint32_t QME_SCOM_XIVDR4_5 = 32;
static const uint32_t QME_SCOM_XIVDR4_5_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIXCR = 0x200e0200ull;

static const uint32_t QME_SCOM_XIXCR_CTR = 32;
static const uint32_t QME_SCOM_XIXCR_CTR_LEN = 32;
// eq/reg00003.H

static const uint64_t SPATTN_MASK_RW = 0x20040042ull;
static const uint64_t SPATTN_MASK_WO_CLEAR = 0x20040062ull;
static const uint64_t SPATTN_MASK_WO_OR = 0x20040052ull;

static const uint32_t SPATTN_MASK_01 = 1;
static const uint32_t SPATTN_MASK_02 = 2;
static const uint32_t SPATTN_MASK_03 = 3;
static const uint32_t SPATTN_MASK_04 = 4;
static const uint32_t SPATTN_MASK_05 = 5;
static const uint32_t SPATTN_MASK_06 = 6;
static const uint32_t SPATTN_MASK_07 = 7;
static const uint32_t SPATTN_MASK_08 = 8;
static const uint32_t SPATTN_MASK_09 = 9;
static const uint32_t SPATTN_MASK_10 = 10;
static const uint32_t SPATTN_MASK_11 = 11;
static const uint32_t SPATTN_MASK_12 = 12;
static const uint32_t SPATTN_MASK_13 = 13;
static const uint32_t SPATTN_MASK_14 = 14;
static const uint32_t SPATTN_MASK_15 = 15;
static const uint32_t SPATTN_MASK_16 = 16;
static const uint32_t SPATTN_MASK_17 = 17;
static const uint32_t SPATTN_MASK_18 = 18;
static const uint32_t SPATTN_MASK_19 = 19;
static const uint32_t SPATTN_MASK_20 = 20;
static const uint32_t SPATTN_MASK_21 = 21;
static const uint32_t SPATTN_MASK_22 = 22;
static const uint32_t SPATTN_MASK_23 = 23;
static const uint32_t SPATTN_MASK_24 = 24;
static const uint32_t SPATTN_MASK_25 = 25;
static const uint32_t SPATTN_MASK_26 = 26;
static const uint32_t SPATTN_MASK_27 = 27;
static const uint32_t SPATTN_MASK_28 = 28;
static const uint32_t SPATTN_MASK_29 = 29;
static const uint32_t SPATTN_MASK_30 = 30;
static const uint32_t SPATTN_MASK_31 = 31;
static const uint32_t SPATTN_MASK_32 = 32;
static const uint32_t SPATTN_MASK_33 = 33;
static const uint32_t SPATTN_MASK_34 = 34;
static const uint32_t SPATTN_MASK_35 = 35;
// eq/reg00003.H

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00003.H"
#endif
#endif
