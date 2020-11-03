/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_7.H $         */
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

#ifndef __p10_scom_eq_7_H_
#define __p10_scom_eq_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [EPS_THERM_WSUB_CONTROL_REG]
static const uint64_t EPS_THERM_WSUB_CONTROL_REG = 0x20050012ull;

static const uint32_t EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY = 0;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT = 1;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD = 2;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR = 3;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS = 4;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS = 5;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE = 6;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS = 7;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS = 8;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS = 9;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE = 10;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT = 11;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR = 12;
//<< [EPS_THERM_WSUB_CONTROL_REG]
// eq/reg00007.H

//>> [HANG_PULSE_0_REG]
static const uint64_t HANG_PULSE_0_REG = 0x200f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
//<< [HANG_PULSE_0_REG]
// eq/reg00007.H

//>> [HANG_PULSE_1_REG]
static const uint64_t HANG_PULSE_1_REG = 0x200f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
//<< [HANG_PULSE_1_REG]
// eq/reg00007.H

//>> [HANG_PULSE_2_REG]
static const uint64_t HANG_PULSE_2_REG = 0x200f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
//<< [HANG_PULSE_2_REG]
// eq/reg00007.H

//>> [HANG_PULSE_3_REG]
static const uint64_t HANG_PULSE_3_REG = 0x200f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
//<< [HANG_PULSE_3_REG]
// eq/reg00007.H

//>> [HANG_PULSE_4_REG]
static const uint64_t HANG_PULSE_4_REG = 0x200f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
//<< [HANG_PULSE_4_REG]
// eq/reg00007.H

//>> [HANG_PULSE_5_REG]
static const uint64_t HANG_PULSE_5_REG = 0x200f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
//<< [HANG_PULSE_5_REG]
// eq/reg00007.H

//>> [OPCG_CAPT2]
static const uint64_t OPCG_CAPT2 = 0x20030011ull;

static const uint32_t OPCG_CAPT2_13_01EVEN = 4;
static const uint32_t OPCG_CAPT2_13_01EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_14_01ODD = 9;
static const uint32_t OPCG_CAPT2_14_01ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_15_02EVEN = 14;
static const uint32_t OPCG_CAPT2_15_02EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_16_02ODD = 19;
static const uint32_t OPCG_CAPT2_16_02ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_17_03EVEN = 24;
static const uint32_t OPCG_CAPT2_17_03EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_18_03ODD = 29;
static const uint32_t OPCG_CAPT2_18_03ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_19_04EVEN = 34;
static const uint32_t OPCG_CAPT2_19_04EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_20_04ODD = 39;
static const uint32_t OPCG_CAPT2_20_04ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_21_05EVEN = 44;
static const uint32_t OPCG_CAPT2_21_05EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_22_05ODD = 49;
static const uint32_t OPCG_CAPT2_22_05ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_23_06EVEN = 54;
static const uint32_t OPCG_CAPT2_23_06EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_24_06ODD = 59;
static const uint32_t OPCG_CAPT2_24_06ODD_LEN = 5;
//<< [OPCG_CAPT2]
// eq/reg00007.H

//>> [QME_ERR]
static const uint64_t QME_ERR = 0x200e0010ull;

static const uint32_t QME_ERR_PPE_INTERNAL_ERROR = 0;
static const uint32_t QME_ERR_PPE_EXTERNAL_ERROR = 1;
static const uint32_t QME_ERR_PPE_PROGRESS_ERROR = 2;
static const uint32_t QME_ERR_PPE_BREAKPOINT_ERROR = 3;
static const uint32_t QME_ERR_RESCLK_FREEZE = 4;
static const uint32_t QME_ERR_RESCLK_FREEZE_LEN = 4;
static const uint32_t QME_ERR_SPECIAL_WKUP_PROTOCOL_ERR = 8;
static const uint32_t QME_ERR_SPECIAL_WKUP_PROTOCOL_ERR_LEN = 4;
static const uint32_t QME_ERR_SPECIAL_WKUP_DONE_WINDOW = 12;
static const uint32_t QME_ERR_SPECIAL_WKUP_DONE_WINDOW_LEN = 4;
static const uint32_t QME_ERR_DISABLED_INTR = 16;
static const uint32_t QME_ERR_DISABLED_INTR_LEN = 4;
static const uint32_t QME_ERR_DECONFIGURED_INTR = 20;
static const uint32_t QME_ERR_DECONFIGURED_INTR_LEN = 4;
static const uint32_t QME_ERR_CTFS_ERR = 24;
static const uint32_t QME_ERR_CTFS_ERR_LEN = 4;
static const uint32_t QME_ERR_CPMS_ERR = 28;
static const uint32_t QME_ERR_CPMS_ERR_LEN = 4;
static const uint32_t QME_ERR_PCB_ENDPOINT_RESET = 32;
static const uint32_t QME_ERR_PCB_NETWORK_RESET = 33;
static const uint32_t QME_ERR_PIG_PENDING_SOURCE_LOST = 34;
static const uint32_t QME_ERR_PIG_PENDING_SOURCE_LOST_LEN = 6;
static const uint32_t QME_ERR_SPARE = 40;
static const uint32_t QME_ERR_SPARE_LEN = 4;
static const uint32_t QME_ERR_PCB_NETWORK_RESET_REQ = 40; // p10:20,
static const uint32_t QME_ERR_PCB_NETWORK_RESET_PIG_REQ = 41; // p10:20,
// ERROR Duplicate Dial         static const uint32_t QME_ERR_SPARE = 42; // p10:20,
// ERROR Duplicate Dial         static const uint32_t QME_ERR_SPARE_LEN = 2;
static const uint32_t QME_ERR_LOCAL_ACCESS_PROTECT_ERR = 44;
static const uint32_t QME_ERR_LOCAL_ACCESS_REGION_ERR = 45;
static const uint32_t QME_ERR_LOCAL_ACCESS_PARTIAL_ERR = 46;
//<< [QME_ERR]
// eq/reg00007.H

//>> [QME_QHTTRIG]
static const uint64_t QME_QHTTRIG = 0x200e01b0ull;

static const uint32_t QME_QHTTRIG_START = 0;
static const uint32_t QME_QHTTRIG_STOP = 1;
static const uint32_t QME_QHTTRIG_PAUSE = 2;
//<< [QME_QHTTRIG]
// eq/reg00007.H

//>> [QME_QMCR]
static const uint64_t QME_QMCR = 0x200e0088ull;
static const uint64_t QME_QMCR_SCOM2 = 0x200e008aull;
static const uint64_t QME_QMCR_WO_CLEAR = 0x200e008bull;

static const uint32_t QME_QMCR_PMCR_OVERRIDE_EN = 0;
static const uint32_t QME_QMCR_PSCR_OVERRIDE_EN = 1;
static const uint32_t QME_QMCR_CHAR_REGS_READ_ENABLE = 2;
static const uint32_t QME_QMCR_BCECSR_OVERRIDE_EN = 3;
static const uint32_t QME_QMCR_PSREQ_SCOM_READ_EN = 4;
static const uint32_t QME_QMCR_LOCK_QUEUE_ON_PCB_ERR = 5;
static const uint32_t QME_QMCR_STOP_OVERRIDE_MODE = 6;
static const uint32_t QME_QMCR_STOP_ACTIVE_MASK = 7;
static const uint32_t QME_QMCR_AUTO_PMCR_UPDATE = 8;
static const uint32_t QME_QMCR_PMCR_RECENT_MODE = 9;
static const uint32_t QME_QMCR_FUSED_CORE_PAIR_MODE = 10;
static const uint32_t QME_QMCR_CYCLE_REPRO_MODE = 11;
static const uint32_t QME_QMCR_QUEUED_WR_EN = 12;
static const uint32_t QME_QMCR_QUEUED_RD_EN = 13;
static const uint32_t QME_QMCR_RESET_IMPRECISE_QERR = 14;
static const uint32_t QME_QMCR_RESET_PB_RAMP = 15;
static const uint32_t QME_QMCR_LOPRI_STOP_WKUP_SEL = 16;
static const uint32_t QME_QMCR_LOPRI_STOP_WKUP_SEL_LEN = 4;
static const uint32_t QME_QMCR_LOPRI_STOP_ENTRY_SEL = 20;
static const uint32_t QME_QMCR_LOPRI_STOP_ENTRY_SEL_LEN = 4;
static const uint32_t QME_QMCR_WRITE_PROTECT_ENABLE = 24;
static const uint32_t QME_QMCR_TTSR_READ_ENABLE = 25;
static const uint32_t QME_QMCR_PTSR_READ_ENABLE = 26;
static const uint32_t QME_QMCR_RESET_QME_PCB_MASTER_INTERFACE = 27;
static const uint32_t QME_QMCR_OCP_REQUEST_ENABLE = 28;
static const uint32_t QME_QMCR_STOP_SHIFTREG_OVERRIDE_EN = 29;
static const uint32_t QME_QMCR_CPMS_PG_CLKOFF_DISABLE = 30;
static const uint32_t QME_QMCR_CTFS_PG_CLKOFF_DISABLE = 31;
static const uint32_t QME_QMCR_DTC_SEQUENCER_ENABLE = 32;
static const uint32_t QME_QMCR_WOF_AUTO_SEQ_ENABLE = 33;
static const uint32_t QME_QMCR_QOS_AUTO_SEQ_ENABLE = 34;
static const uint32_t QME_QMCR_QOSR_SPR_UPDATE_ENABLE = 35;
static const uint32_t QME_QMCR_SPARE2 = 36;
static const uint32_t QME_QMCR_SPARE2_LEN = 4;
static const uint32_t QME_QMCR_MIXED_LPAR_MODE_DISABLE = 36; // p10:20,
static const uint32_t QME_QMCR_RESET_QME_PCB_INTERRUPT_INTERFACE = 37; // p10:20,
static const uint32_t QME_QMCR_PCB_RESET_ALL_REQ = 38; // p10:20,
static const uint32_t QME_QMCR_CR_STEP_SYNC_TOGGLE_DISABLE = 39; // p10:20,
static const uint32_t QME_QMCR_CR_SYNC_PULSE_DIS = 40; // p10:20,
// ERROR Duplicate Dial         static const uint32_t QME_QMCR_SPARE2 = 41; // p10:20,
// ERROR Duplicate Dial         static const uint32_t QME_QMCR_SPARE2_LEN = 6;
static const uint32_t QME_QMCR_FUSED_CORE_MODE = 47;
static const uint32_t QME_QMCR_TOD_STEP_MS = 48; // p10:20,
static const uint32_t QME_QMCR_TOD_SYNC_MS = 49; // p10:20,
static const uint32_t QME_QMCR_TOD_STEP_ACTUAL = 50; // p10:20,
static const uint32_t QME_QMCR_TOD_SYNC_ACTUAL = 51; // p10:20,
static const uint32_t QME_QMCR_CORE_PARTIAL_GOOD = 60;
static const uint32_t QME_QMCR_CORE_PARTIAL_GOOD_LEN = 4;
//<< [QME_QMCR]
// eq/reg00007.H

//>> [QME_SCOM_XIDBGINF]
static const uint64_t QME_SCOM_XIDBGINF = 0x200e023cull;

static const uint32_t QME_SCOM_XIDBGINF_SRR0_TOP = 0;
static const uint32_t QME_SCOM_XIDBGINF_SRR0_TOP_LEN = 30;
static const uint32_t QME_SCOM_XIDBGINF_LR = 32;
static const uint32_t QME_SCOM_XIDBGINF_LR_LEN = 32;
//<< [QME_SCOM_XIDBGINF]
// eq/reg00007.H

//>> [QME_SWPR1]
static const uint64_t QME_SWPR1 = 0x200e0094ull;

static const uint32_t QME_SWPR1_BAR = 0;
static const uint32_t QME_SWPR1_BAR_LEN = 27;
static const uint32_t QME_SWPR1_SIZE = 44;
static const uint32_t QME_SWPR1_SIZE_LEN = 15;
//<< [QME_SWPR1]
// eq/reg00007.H

//>> [SYNC_CONFIG]
static const uint64_t SYNC_CONFIG = 0x20030000ull;

static const uint32_t SYNC_CONFIG_SYNC_PULSE_DELAY = 0;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_DELAY_LEN = 4;
static const uint32_t SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS = 4;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_INPUT_SEL = 5;
static const uint32_t SYNC_CONFIG_USE_SYNC_FOR_SCAN = 6;
static const uint32_t SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED = 7;
static const uint32_t SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD = 8;
static const uint32_t SYNC_CONFIG_DISABLE_PCB_ITR = 9;
static const uint32_t SYNC_CONFIG_CONT_SCAN_DISABLE = 10;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_OUT_DIS = 11;
static const uint32_t SYNC_CONFIG_REGION_PGOOD_OVERRIDE = 12;
static const uint32_t SYNC_CONFIG_CONT_SCAN_SHORT_WAIT = 13;
static const uint32_t SYNC_CONFIG_PCIE32_MODE = 14; // p10:20,
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN = 15;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE = 16;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN = 8;
//<< [SYNC_CONFIG]
// eq/reg00007.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00007.H"
#endif
#endif
