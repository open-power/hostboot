/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_8.H $       */
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

#ifndef __p10_scom_iohs_8_H_
#define __p10_scom_iohs_8_H_


namespace scomt
{
namespace iohs
{


static const uint64_t ASSIST_INTERRUPT_REG = 0x180f0011ull;
// iohs/reg00036.H

static const uint64_t AXON_CPLT_CONF1_RW = 0x18000009ull;
static const uint64_t AXON_CPLT_CONF1_WO_CLEAR = 0x18000029ull;
static const uint64_t AXON_CPLT_CONF1_WO_OR = 0x18000019ull;

static const uint32_t AXON_CPLT_CONF1_OD_IOVALID_DC = 0;
static const uint32_t AXON_CPLT_CONF1_EV_IOVALID_DC = 1;
// iohs/reg00036.H

static const uint64_t AXON_CPLT_CTRL1_RW = 0x18000001ull;
static const uint64_t AXON_CPLT_CTRL1_WO_CLEAR = 0x18000021ull;
static const uint64_t AXON_CPLT_CTRL1_WO_OR = 0x18000011ull;

static const uint32_t AXON_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t AXON_CPLT_CTRL1_VITL_FENCE_DC = 3;
static const uint32_t AXON_CPLT_CTRL1_REGION0_FENCE_DC = 4;
static const uint32_t AXON_CPLT_CTRL1_REGION1_FENCE_DC = 5;
static const uint32_t AXON_CPLT_CTRL1_REGION2_FENCE_DC = 6;
static const uint32_t AXON_CPLT_CTRL1_REGION3_FENCE_DC = 7;
static const uint32_t AXON_CPLT_CTRL1_REGION4_FENCE_DC = 8;
static const uint32_t AXON_CPLT_CTRL1_REGION5_FENCE_DC = 9;
static const uint32_t AXON_CPLT_CTRL1_REGION6_FENCE_DC = 10;
static const uint32_t AXON_CPLT_CTRL1_REGION7_FENCE_DC = 11;
static const uint32_t AXON_CPLT_CTRL1_REGION8_FENCE_DC = 12;
static const uint32_t AXON_CPLT_CTRL1_REGION9_FENCE_DC = 13;
static const uint32_t AXON_CPLT_CTRL1_REGION10_FENCE_DC = 14;
static const uint32_t AXON_CPLT_CTRL1_REGION11_FENCE_DC = 15;
static const uint32_t AXON_CPLT_CTRL1_REGION12_FENCE_DC = 16;
static const uint32_t AXON_CPLT_CTRL1_REGION13_FENCE_DC = 17;
static const uint32_t AXON_CPLT_CTRL1_REGION14_FENCE_DC = 18;
// iohs/reg00036.H

static const uint64_t AXON_EPS_DBG_MODE_REG = 0x180107c0ull;

static const uint32_t AXON_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t AXON_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t AXON_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t AXON_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t AXON_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t AXON_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION = 11;
static const uint32_t AXON_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 12;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t AXON_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t AXON_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t AXON_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t AXON_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t AXON_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// iohs/reg00036.H

static const uint64_t AXON_EPS_THERM_WSUB_SKITTER_DATA2 = 0x1805001bull;
// iohs/reg00036.H

static const uint64_t AXON_EPS_THERM_WSUB_MODE_REG = 0x1805000full;

static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// iohs/reg00036.H

static const uint64_t AXON_XSTOP_UNMASKED = 0x18040010ull;

static const uint32_t AXON_XSTOP_UNMASKED_XSTOP_UNMASKED_IN = 1;
static const uint32_t AXON_XSTOP_UNMASKED_XSTOP_UNMASKED_IN_LEN = 53;
// iohs/reg00036.H

static const uint64_t DLP_LINK0_RX_LANE_CONTROL = 0x18011012ull;

static const uint32_t DLP_LINK0_RX_LANE_CONTROL_DISABLED = 0;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_DISABLED_LEN = 9;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_BRINGUP = 12;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_BRINGUP_LEN = 9;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_SPARED = 24;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_SPARED_LEN = 9;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_LOCKED = 36;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_LOCKED_LEN = 9;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_FAILED = 48;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_FAILED_LEN = 9;
// iohs/reg00036.H

static const uint64_t DLP_LINK1_EDPL_STATUS = 0x18011025ull;

static const uint32_t DLP_LINK1_EDPL_STATUS_0 = 0;
static const uint32_t DLP_LINK1_EDPL_STATUS_0_LEN = 4;
static const uint32_t DLP_LINK1_EDPL_STATUS_1 = 7;
static const uint32_t DLP_LINK1_EDPL_STATUS_1_LEN = 4;
static const uint32_t DLP_LINK1_EDPL_STATUS_2 = 14;
static const uint32_t DLP_LINK1_EDPL_STATUS_2_LEN = 4;
static const uint32_t DLP_LINK1_EDPL_STATUS_3 = 21;
static const uint32_t DLP_LINK1_EDPL_STATUS_3_LEN = 4;
static const uint32_t DLP_LINK1_EDPL_STATUS_4 = 28;
static const uint32_t DLP_LINK1_EDPL_STATUS_4_LEN = 4;
static const uint32_t DLP_LINK1_EDPL_STATUS_5 = 35;
static const uint32_t DLP_LINK1_EDPL_STATUS_5_LEN = 4;
static const uint32_t DLP_LINK1_EDPL_STATUS_6 = 42;
static const uint32_t DLP_LINK1_EDPL_STATUS_6_LEN = 4;
static const uint32_t DLP_LINK1_EDPL_STATUS_7 = 49;
static const uint32_t DLP_LINK1_EDPL_STATUS_7_LEN = 4;
static const uint32_t DLP_LINK1_EDPL_STATUS_8 = 56;
static const uint32_t DLP_LINK1_EDPL_STATUS_8_LEN = 4;
// iohs/reg00036.H

static const uint64_t DLP_OPTICAL_CONFIG = 0x1801100full;

static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT = 0;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_DISABLE_CLEAR_BAD_LANE_COUNT = 1;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE = 2;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR = 3;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION_LEN = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX = 9;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX_LEN = 7;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT = 16;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION = 20;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION_LEN = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX = 25;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX_LEN = 7;
static const uint32_t DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER = 32;
static const uint32_t DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER = 33;
static const uint32_t DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP = 39;
static const uint32_t DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP = 40;
static const uint32_t DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP = 41;
static const uint32_t DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP = 42;
static const uint32_t DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP = 43;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW = 44;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW_LEN = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START = 48;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START_LEN = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH = 52;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH_LEN = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE = 58;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS = 59;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT = 60;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT_LEN = 4;
// iohs/reg00036.H

static const uint64_t DLP_PERF_COUNT_LSB_1 = 0x18011021ull;
// iohs/reg00036.H

static const uint64_t DLP_PERF_SEL_CONFIG = 0x1801101dull;

static const uint32_t DLP_PERF_SEL_CONFIG_0 = 0;
static const uint32_t DLP_PERF_SEL_CONFIG_0_LEN = 8;
static const uint32_t DLP_PERF_SEL_CONFIG_1 = 8;
static const uint32_t DLP_PERF_SEL_CONFIG_1_LEN = 8;
static const uint32_t DLP_PERF_SEL_CONFIG_2 = 16;
static const uint32_t DLP_PERF_SEL_CONFIG_2_LEN = 8;
static const uint32_t DLP_PERF_SEL_CONFIG_3 = 24;
static const uint32_t DLP_PERF_SEL_CONFIG_3_LEN = 8;
static const uint32_t DLP_PERF_SEL_CONFIG_4 = 32;
static const uint32_t DLP_PERF_SEL_CONFIG_4_LEN = 8;
static const uint32_t DLP_PERF_SEL_CONFIG_5 = 40;
static const uint32_t DLP_PERF_SEL_CONFIG_5_LEN = 8;
static const uint32_t DLP_PERF_SEL_CONFIG_6 = 48;
static const uint32_t DLP_PERF_SEL_CONFIG_6_LEN = 8;
static const uint32_t DLP_PERF_SEL_CONFIG_7 = 56;
static const uint32_t DLP_PERF_SEL_CONFIG_7_LEN = 8;
// iohs/reg00036.H

static const uint64_t EDRAM_STATUS = 0x180f0029ull;

static const uint32_t EDRAM_STATUS_EDRAM_STAT = 0;
static const uint32_t EDRAM_STATUS_EDRAM_STAT_LEN = 4;
// iohs/reg00036.H

static const uint64_t ERROR_REG = 0x180f001full;

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
// iohs/reg00036.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE18_PG = 0x8008900010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES = 53;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES_LEN = 2;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH = 55;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH_LEN = 4;
// iohs/reg00036.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL9_PG = 0x8009c80010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15_LEN = 16;
// iohs/reg00036.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT9_PG = 0x800ad00010012c3full;
// iohs/reg00036.H

static const uint64_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL3_PL = 0x8003d80e10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00036.H

static const uint64_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL = 0x8003d00c10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00036.H

static const uint64_t IOO_RX0_RXCTL_DATASM_16_PLREGS_RX_CNTL2_PL = 0x8003c80a10012c3full;
// iohs/reg00036.H

static const uint64_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL1_PL = 0x8003c00210012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00036.H

static const uint64_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_STAT1_PL = 0x8003e00210012c3full;
// iohs/reg00036.H

static const uint64_t IOO_RX0_RXCTL_DATASM_20_PLREGS_RX_CNTL2_PL = 0x8003c81410012c3full;
// iohs/reg00036.H

static const uint64_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL = 0x8003d01610012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL = 0x8003600010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a80010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f80010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001480010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001980010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b00010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL1_PL = 0x8000080010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTLX9_PL = 0x8000480010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE3_PL = 0x8003300110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_STAT5_PL = 0x8003b00110012c3full;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d00110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002100110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002600110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL4_PL = 0x8000200110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000000110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL2_PL = 0x8003680210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE4_PL = 0x8003380210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_STAT2_PL = 0x8003980210012c3full;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001100210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001600210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b00210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002200210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002700210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002980210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL18_PL = 0x8000900210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE8_PL = 0x8003580310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00036.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX5_PL = 0x8003800410012c3full;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a00410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f00410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001400410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001900410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b80410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL11_PL = 0x8000580410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL11_PL_TERM_PD = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST = 49;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST_LEN = 5;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL11_PL_OFF_CM = 54;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL11_PL_OFF_CM_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL11_PL_OFF_DM = 58;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL11_PL_OFF_DM_LEN = 6;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE6_PL = 0x8003480510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_FIR_PL = 0x8003080510012c3full;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x8002180510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x8002680510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL17_PL = 0x8000880510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00037.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL8_PL = 0x8000400510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT_LEN = 2;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL = 50;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL_LEN = 2;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B = 52;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL = 0x8003680610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE4_PL = 0x8003380610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_STAT2_PL = 0x8003980610012c3full;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_FIR_PL = 0x8003080610012c3full;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e80610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002380610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL1_PL = 0x8000080610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_MODE8_PL = 0x8003580710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8003180710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001200710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001700710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c00710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002880710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL4_PL = 0x8000200710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTLX9_PL = 0x8000480710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e00810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001300810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001800810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d00810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c00810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002000810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002500810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE3_PL = 0x8003301110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_STAT5_PL = 0x8003b01110012c3full;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001081110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001581110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a81110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a01110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL18_PL = 0x8000901110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL = 0x8003201010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e01010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002301010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL17_PL = 0x8000881010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00037.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d80f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001280f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001780f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c80f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002800f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d00f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL11_PL = 0x8000580f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL11_PL_TERM_PD = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST = 49;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST_LEN = 5;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL11_PL_OFF_CM = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL11_PL_OFF_CM_LEN = 4;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL11_PL_OFF_DM = 58;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL11_PL_OFF_DM_LEN = 6;
// iohs/reg00038.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL = 0x8000400f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT_LEN = 2;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL = 50;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL_LEN = 2;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B = 52;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002100e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002600e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL = 0x8000680e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN = 4;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL = 0x8003480d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8003180d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a80d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f80d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001480d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001980d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b00d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL = 0x8000780d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_CNTLX5_PL = 0x8003800c10012c3full;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL = 0x8003200c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL = 0x8000700c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001100b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001600b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b00b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002200b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002700b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002980b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL5_PL = 0x8000280b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN = 4;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x8002180a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x8002680a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL = 0x8000300a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN = 4;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL = 0x8003300910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_STAT5_PL = 0x8003b00910012c3full;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL = 0x8003100910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a00910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f00910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001400910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001900910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b80910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00038.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL = 0x8000180910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_ZERO = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_ZERO_LEN = 3;
// iohs/reg00038.H

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG = 0x800c440010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN = 3;
// iohs/reg00038.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG = 0x800ce40010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN = 16;
// iohs/reg00038.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG = 0x800d640010012c3full;
// iohs/reg00038.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004140010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00038.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL = 0x80040c0010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL = 0x80047c0110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL = 0x8004cc0110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL = 0x80051c0110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL = 0x8004440110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL = 0x8004ac0210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL = 0x8004fc0210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL = 0x8004640210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL = 0x80041c0210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN = 52;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN = 53;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL11_PL = 0x8004840410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL1G_PL = 0x8004340410012c3full;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL21_PL = 0x8004d40410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL4_PL = 0x80044c0410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_MODE2_PL = 0x8004240410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL9_PL = 0x8004740510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00039.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_FIR_PL = 0x8004040510012c3full;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL11_PL = 0x8004840710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL1G_PL = 0x8004340710012c3full;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL21_PL = 0x8004d40710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL = 0x8004b40810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL27_PL = 0x8005040810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL9_PL = 0x8004740810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL4_PL = 0x80044c1110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_FIR_MASK_PL = 0x80040c1110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_MODE2_PL = 0x8004241110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL10_PL = 0x80047c1010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL20_PL = 0x8004cc1010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL30_PL = 0x80051c1010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL7_PL = 0x8004640f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL = 0x80041c0f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN = 52;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN = 53;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL13_PL = 0x8004940e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL23_PL = 0x8004e40e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_STAT1_PL = 0x8005240e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL19_PL = 0x8004c40d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL29_PL = 0x8005140d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL8_PL = 0x80046c0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL15_PL = 0x8004a40b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL25_PL = 0x8004f40b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL5_PL = 0x8004540b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE3_PL = 0x80042c0b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL18_PL = 0x8004bc0a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL28_PL = 0x80050c0a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL12_PL = 0x80048c0910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL22_PL = 0x8004dc0910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL6_PL = 0x80045c0910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00039.H

static const uint64_t REGS_PRX1_DLR_APST = 0x1801103full;
// iohs/reg00039.H

}
}
#ifndef __PPE_HCODE__
    #include "iohs/reg00036.H"
    #include "iohs/reg00037.H"
    #include "iohs/reg00038.H"
    #include "iohs/reg00039.H"
#endif
#endif
