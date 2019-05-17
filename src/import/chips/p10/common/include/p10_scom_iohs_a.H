/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_a.H $       */
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

#include "proc_scomt.H"

#ifndef __p10_scom_iohs_a_H_
#define __p10_scom_iohs_a_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CC_ATOMIC_LOCK_REG = 0x180303ffull;

static const uint32_t AXON_CC_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t AXON_CC_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t AXON_CC_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t AXON_CC_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t AXON_CC_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// iohs/reg00042.H

static const uint64_t AXON_EPS_DBG_TRACE_MODE_REG_2 = 0x180107cfull;

static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// iohs/reg00042.H

static const uint64_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3 = 0x18040083ull;

static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_XSTOP_ERR = 0;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_RECOV_ERR = 1;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_SPATTN_ERR = 2;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_LXSTOP_ERR = 3;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_HOSTATTN_ERR = 4;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYSTEM_XSTOP = 5;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_OOB1 = 6;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 = 21;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 = 22;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 = 23;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 = 24;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 = 25;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 = 26;
// iohs/reg00042.H

static const uint64_t AXON_EPS_FIR_LOCAL_ACTION1 = 0x18040107ull;

static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_00 = 0;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_01 = 1;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_02 = 2;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_03 = 3;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_04 = 4;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_05 = 5;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_06 = 6;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_07 = 7;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_08 = 8;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_09 = 9;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_10 = 10;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_11 = 11;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_12 = 12;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_13 = 13;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_14 = 14;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_15 = 15;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_16 = 16;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_17 = 17;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_18 = 18;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_19 = 19;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_20 = 20;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_21 = 21;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_22 = 22;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_23 = 23;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_24 = 24;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_25 = 25;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_26 = 26;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_27 = 27;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_28 = 28;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_29 = 29;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_30 = 30;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_31 = 31;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_32 = 32;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_33 = 33;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_34 = 34;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_35 = 35;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_36 = 36;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_37 = 37;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_38 = 38;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_39 = 39;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_40 = 40;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_41 = 41;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_42 = 42;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_43 = 43;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_44 = 44;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_45 = 45;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_46 = 46;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_47 = 47;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_48 = 48;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_49 = 49;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_50 = 50;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_51 = 51;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_52 = 52;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_53 = 53;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_54 = 54;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_55 = 55;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_56 = 56;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_57 = 57;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_58 = 58;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_59 = 59;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_60 = 60;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_61 = 61;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_62 = 62;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_63 = 63;
// iohs/reg00042.H

static const uint64_t AXON_SCAN_UPDATEDR_LONG = 0x1803b000ull;
// iohs/reg00042.H

static const uint64_t AXON_SYNC_CONFIG = 0x18030000ull;

static const uint32_t AXON_SYNC_CONFIG_SYNC_PULSE_DELAY = 0;
static const uint32_t AXON_SYNC_CONFIG_SYNC_PULSE_DELAY_LEN = 4;
static const uint32_t AXON_SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS = 4;
static const uint32_t AXON_SYNC_CONFIG_SYNC_PULSE_INPUT_SEL = 5;
static const uint32_t AXON_SYNC_CONFIG_USE_SYNC_FOR_SCAN = 6;
static const uint32_t AXON_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED = 7;
static const uint32_t AXON_SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD = 8;
static const uint32_t AXON_SYNC_CONFIG_DISABLE_PCB_ITR = 9;
static const uint32_t AXON_SYNC_CONFIG_CONT_SCAN_DISABLE = 10;
static const uint32_t AXON_SYNC_CONFIG_SYNC_PULSE_OUT_DIS = 11;
static const uint32_t AXON_SYNC_CONFIG_REGION_PGOOD_OVERRIDE = 12;
static const uint32_t AXON_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN = 15;
static const uint32_t AXON_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE = 16;
static const uint32_t AXON_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN = 8;
// iohs/reg00042.H

static const uint64_t AXON_TRA0_TR0_CONFIG_0 = 0x18010403ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// iohs/reg00042.H

static const uint64_t AXON_XSTOP2 = 0x1803000dull;

static const uint32_t AXON_XSTOP2_XSTOP2_MASK_B = 0;
static const uint32_t AXON_XSTOP2_ALIGNED_XSTOP2 = 1;
static const uint32_t AXON_XSTOP2_TRIGGER_OPCG_ON_XSTOP2 = 2;
static const uint32_t AXON_XSTOP2_XSTOP2_WAIT_ALLWAYS = 3;
static const uint32_t AXON_XSTOP2_XSTOP2_PERV = 4;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT1 = 5;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT2 = 6;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT3 = 7;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT4 = 8;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT5 = 9;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT6 = 10;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT7 = 11;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT8 = 12;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT9 = 13;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT10 = 14;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT11 = 15;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT12 = 16;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT13 = 17;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT14 = 18;
static const uint32_t AXON_XSTOP2_XSTOP2_WAIT_CYCLES = 48;
static const uint32_t AXON_XSTOP2_XSTOP2_WAIT_CYCLES_LEN = 12;
// iohs/reg00042.H

static const uint64_t CONFIG = 0x1801102bull;

static const uint32_t CONFIG_RESET = 0;
static const uint32_t CONFIG_RETRAIN = 1;
static const uint32_t CONFIG_VERSION = 2;
static const uint32_t CONFIG_VERSION_LEN = 6;
static const uint32_t CONFIG_TRAIN_MODE = 8;
static const uint32_t CONFIG_TRAIN_MODE_LEN = 4;
static const uint32_t CONFIG_SUPPORTED_MODES = 12;
static const uint32_t CONFIG_SUPPORTED_MODES_LEN = 4;
static const uint32_t CONFIG_X4_BACKOFF_ENABLE = 16;
static const uint32_t CONFIG_X1_BACKOFF_ENABLE = 17;
static const uint32_t CONFIG_PWRMGT_ENABLE = 18;
static const uint32_t CONFIG_TX_EP_MODE = 19;
static const uint32_t CONFIG_PHY_CNTR_LIMIT = 20;
static const uint32_t CONFIG_PHY_CNTR_LIMIT_LEN = 4;
static const uint32_t CONFIG_128_130_ENCODING_ENABLED = 24;
static const uint32_t CONFIG_TRAINING_STATUS_REGISTER_SELECT = 25;
static const uint32_t CONFIG_CRC_TX_INJECTION = 27;
static const uint32_t CONFIG_ECC_CE_INJECTION = 28;
static const uint32_t CONFIG_ECC_UE_INJECTION = 29;
static const uint32_t CONFIG_DL2TL_CONTROL_PARITY_INJECT = 30;
static const uint32_t CONFIG_DL2TL_DATA_PARITY_INJECT = 31;
static const uint32_t CONFIG_DEBUG_ENABLE = 33;
static const uint32_t CONFIG_DEBUG_SELECT = 34;
static const uint32_t CONFIG_DEBUG_SELECT_LEN = 2;
static const uint32_t CONFIG_REPLAY_RSVD_ENTRIES = 36;
static const uint32_t CONFIG_REPLAY_RSVD_ENTRIES_LEN = 4;
static const uint32_t CONFIG_FWD_PROGRESS_TIMER = 40;
static const uint32_t CONFIG_FWD_PROGRESS_TIMER_LEN = 4;
static const uint32_t CONFIG_TLERROR_LINKDOWN = 44;
static const uint32_t CONFIG_TLERROR_ILATRIG = 45;
static const uint32_t CONFIG_TLERROR_AFUFREEZE = 46;
static const uint32_t CONFIG_TLERROR_ALLFREEZE = 47;
static const uint32_t CONFIG_TLEVENT_LINKDOWN = 48;
static const uint32_t CONFIG_TLEVENT_ILATRIG = 49;
static const uint32_t CONFIG_TLEVENT_AFUFREEZE = 50;
static const uint32_t CONFIG_TLEVENT_ALLFREEZE = 51;
static const uint32_t CONFIG_CFG_SPARE = 52;
static const uint32_t CONFIG_CFG_SPARE_LEN = 12;
// iohs/reg00042.H

static const uint64_t DLP_LINK0_TX_LANE_CONTROL = 0x18011010ull;

static const uint32_t DLP_LINK0_TX_LANE_CONTROL_00_CONTROL = 0;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_00_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_01_CONTROL = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_01_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_02_CONTROL = 8;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_02_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_03_CONTROL = 12;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_03_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_04_CONTROL = 16;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_04_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_05_CONTROL = 20;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_05_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_06_CONTROL = 24;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_06_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_07_CONTROL = 28;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_07_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL = 32;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL__FAILED = 48;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL__FAILED_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT19_PG = 0x800b200010012c3full;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL = 0x8003c00010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL = 0x8003e00010012c3full;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL3_PL = 0x8003d81010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL2_PL = 0x8003c80c10012c3full;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL = 0x8003d00a10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL1_PL = 0x8003c01310012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_STAT1_PL = 0x8003e01310012c3full;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL = 0x8003d01410012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL2_PL = 0x8003c81610012c3full;
// iohs/reg00042.H

static const uint64_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL3_PL = 0x8003d81110012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001100010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001600010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b00010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002200010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002700010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002980010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL = 0x8000200010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTLX5_PL = 0x8003800110012c3full;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE6_PL = 0x8003480110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_FIR_MASK_PL = 0x8003100110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL1_PL = 0x8000080110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE1_PL = 0x8003200210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a80210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f80210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001480210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001980210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b00210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8003180310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d00310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002100310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002600310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001180410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001680410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b80410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d80410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002280410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002780410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002900410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL14_PL = 0x8000700410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00043.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL8_PL = 0x8000400410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// iohs/reg00043.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL = 0x8003600510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// iohs/reg00043.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE3_PL = 0x8003300510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_STAT5_PL = 0x8003b00510012c3full;
// iohs/reg00043.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f00510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x8002400510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c80510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE1_PL = 0x8003200610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e00610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001300610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001800610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d00610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c00610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002000610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002500610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL4_PL = 0x8000200610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000000610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001080710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001580710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a80710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a00710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL1_PL = 0x8000080710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL = 0x8003000810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e80810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002380810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE6_PL = 0x8003481110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001201110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001701110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c01110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002881110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTL2_PL = 0x8003681010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE4_PL = 0x8003381010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_STAT2_PL = 0x8003981010012c3full;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000981010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e81010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001381010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001881010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c81010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002081010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002581010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL8_PL = 0x8000401010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE8_PL = 0x8003580f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b00f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001000f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001500f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a00f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00043.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a80f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL = 0x8000700f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL = 0x8000800e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL = 0x8003300d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_STAT5_PL = 0x8003b00d10012c3full;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001100d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001600d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b00d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002200d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002700d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002980d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL = 0x8003680c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL = 0x8003380c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_STAT2_PL = 0x8003980c10012c3full;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL = 0x8003100c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d00c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002100c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002600c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL = 0x8003600b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL = 0x8003580b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a80b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f80b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001480b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001980b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b00b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL = 0x8000880b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f00a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x8002400a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c80a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL = 0x8000900a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL = 0x8000180a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL = 0x8003480910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001180910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001680910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b80910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d80910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002280910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002780910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002900910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00044.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL = 0x8000300910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// iohs/reg00044.H

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG = 0x800c5c0010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN = 8;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL = 57;
// iohs/reg00044.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL = 0x8004a40110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00044.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL = 0x8004f40110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00044.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL = 0x80045c0110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00044.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL = 0x8004940210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// iohs/reg00044.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL = 0x8004e40210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00044.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL2_PL = 0x80043c0210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00045.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004140210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00045.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_MASK_PL = 0x80040c0210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00045.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL19_PL = 0x8004c40310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00045.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL29_PL = 0x8005140310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00045.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL14_PL = 0x80049c0410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00045.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL24_PL = 0x8004ec0410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00045.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_STAT1_PL = 0x8005240410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL = 0x8004540610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL = 0x80042c0610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL14_PL = 0x80049c0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL24_PL = 0x8004ec0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL8_PL = 0x80046c0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_FIR_MASK_PL = 0x80040c0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL = 0x80048c0810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL = 0x8004dc0810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL = 0x8004bc1110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL28_PL = 0x80050c1110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_STAT1_PL = 0x8005241110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL15_PL = 0x8004a41010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL25_PL = 0x8004f41010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL2_PL = 0x80043c0f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00045.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_PL = 0x8004040f10012c3full;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL16_PL = 0x8004ac0e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL26_PL = 0x8004fc0e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL4_PL = 0x80044c0e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE2_PL = 0x8004240e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL9_PL = 0x8004740d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_FIR_PL = 0x8004040c10012c3full;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL10_PL = 0x80047c0b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL20_PL = 0x8004cc0b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL30_PL = 0x80051c0b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL17_PL = 0x8004b40910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL27_PL = 0x8005040910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL3_PL = 0x8004440910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00045.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_FIR_MASK_PL = 0x80040c0910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00045.H

}
}
#include "iohs/reg00042.H"
#include "iohs/reg00043.H"
#include "iohs/reg00044.H"
#include "iohs/reg00045.H"
#endif
