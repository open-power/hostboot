/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi.H $          */
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

#ifndef __omi_H_
#define __omi_H_


namespace scomt
{
namespace omi
{


static const uint64_t CONFIG = 0x1000002bull;

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
static const uint32_t CONFIG_UNUSED2 = 26;
static const uint32_t CONFIG_CRC_TX_INJECTION = 27;
static const uint32_t CONFIG_ECC_CE_INJECTION = 28;
static const uint32_t CONFIG_ECC_UE_INJECTION = 29;
static const uint32_t CONFIG_DL2TL_CONTROL_PARITY_INJECT = 30;
static const uint32_t CONFIG_DL2TL_DATA_PARITY_INJECT = 31;
static const uint32_t CONFIG_UNUSED1 = 32;
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
// omi/reg00000.H

static const uint64_t CONFIG0 = 0x0c011760ull;

static const uint32_t CONFIG0_ENABLE = 0;
static const uint32_t CONFIG0_CFG_SPARE = 1;
static const uint32_t CONFIG0_CFG_SPARE_LEN = 5;
static const uint32_t CONFIG0_CFG_TL_CREDITS = 6;
static const uint32_t CONFIG0_CFG_TL_CREDITS_LEN = 6;
static const uint32_t CONFIG0_TL_EVENT_ACTIONS = 12;
static const uint32_t CONFIG0_TL_EVENT_ACTIONS_LEN = 4;
static const uint32_t CONFIG0_TL_ERROR_ACTIONS = 16;
static const uint32_t CONFIG0_TL_ERROR_ACTIONS_LEN = 4;
static const uint32_t CONFIG0_FWD_PROGRESS_TIMER = 20;
static const uint32_t CONFIG0_FWD_PROGRESS_TIMER_LEN = 4;
static const uint32_t CONFIG0_REPLAY_RSVD_ENTRIES = 24;
static const uint32_t CONFIG0_REPLAY_RSVD_ENTRIES_LEN = 4;
static const uint32_t CONFIG0_DEBUG_SELECT = 28;
static const uint32_t CONFIG0_DEBUG_SELECT_LEN = 3;
static const uint32_t CONFIG0_DEBUG_ENABLE = 31;
static const uint32_t CONFIG0_DL2TL_DATA_PARITY_INJECT = 32;
static const uint32_t CONFIG0_DL2TL_CONTROL_PARITY_INJECT = 33;
static const uint32_t CONFIG0_ECC_UE_INJECTION = 34;
static const uint32_t CONFIG0_ECC_CE_INJECTION = 35;
static const uint32_t CONFIG0_FP_DISABLE = 36;
static const uint32_t CONFIG0_UNUSED2 = 37;
static const uint32_t CONFIG0_TX_LN_REV_ENA = 38;
static const uint32_t CONFIG0_128_130_ENCODING_ENABLED = 39;
static const uint32_t CONFIG0_PHY_CNTR_LIMIT = 40;
static const uint32_t CONFIG0_PHY_CNTR_LIMIT_LEN = 4;
static const uint32_t CONFIG0_UNUSED = 44;
static const uint32_t CONFIG0_PWRMGT_ENABLE = 45;
static const uint32_t CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE = 46;
static const uint32_t CONFIG0_HALF_WIDTH_BACKOFF_ENABLE = 47;
static const uint32_t CONFIG0_SUPPORTED_MODES = 48;
static const uint32_t CONFIG0_SUPPORTED_MODES_LEN = 4;
static const uint32_t CONFIG0_TRAIN_MODE = 52;
static const uint32_t CONFIG0_TRAIN_MODE_LEN = 4;
static const uint32_t CONFIG0_VERSION = 56;
static const uint32_t CONFIG0_VERSION_LEN = 6;
static const uint32_t CONFIG0_RETRAIN = 62;
static const uint32_t CONFIG0_RESET = 63;
// omi/reg00000.H

static const uint64_t CONFIG1 = 0x0c011761ull;

static const uint32_t CONFIG1_CFG1_SPARE = 0;
static const uint32_t CONFIG1_CFG1_SPARE_LEN = 2;
static const uint32_t CONFIG1_LANE_WIDTH = 2;
static const uint32_t CONFIG1_LANE_WIDTH_LEN = 2;
static const uint32_t CONFIG1_PREIPL_PRBS_ENA = 4;
static const uint32_t CONFIG1_PREIPL_PRBS_TIME = 5;
static const uint32_t CONFIG1_PREIPL_PRBS_TIME_LEN = 3;
static const uint32_t CONFIG1_B_HYSTERESIS = 8;
static const uint32_t CONFIG1_B_HYSTERESIS_LEN = 4;
static const uint32_t CONFIG1_A_HYSTERESIS = 12;
static const uint32_t CONFIG1_A_HYSTERESIS_LEN = 4;
static const uint32_t CONFIG1_B_PATTERN_LENGTH = 16;
static const uint32_t CONFIG1_B_PATTERN_LENGTH_LEN = 2;
static const uint32_t CONFIG1_A_PATTERN_LENGTH = 18;
static const uint32_t CONFIG1_A_PATTERN_LENGTH_LEN = 2;
static const uint32_t CONFIG1_TX_PERF_DEGRADED = 20;
static const uint32_t CONFIG1_TX_PERF_DEGRADED_LEN = 2;
static const uint32_t CONFIG1_RX_PERF_DEGRADED = 22;
static const uint32_t CONFIG1_RX_PERF_DEGRADED_LEN = 2;
static const uint32_t CONFIG1_TX_LANES_DISABLE = 24;
static const uint32_t CONFIG1_TX_LANES_DISABLE_LEN = 8;
static const uint32_t CONFIG1_RX_LANES_DISABLE = 32;
static const uint32_t CONFIG1_RX_LANES_DISABLE_LEN = 8;
static const uint32_t CONFIG1_MACRO_DBG_SEL = 40;
static const uint32_t CONFIG1_MACRO_DBG_SEL_LEN = 4;
static const uint32_t CONFIG1_RESET_ERR_HLD = 44;
static const uint32_t CONFIG1_RESET_ERR_CAP = 45;
static const uint32_t CONFIG1_RESET_TSHD_REG = 46;
static const uint32_t CONFIG1_RESET_RMT_MSG = 47;
static const uint32_t CONFIG1_INJECT_CRC_DIRECTION = 48;
static const uint32_t CONFIG1_INJECT_CRC_RATE = 49;
static const uint32_t CONFIG1_INJECT_CRC_RATE_LEN = 3;
static const uint32_t CONFIG1_INJECT_CRC_LANE = 52;
static const uint32_t CONFIG1_INJECT_CRC_LANE_LEN = 3;
static const uint32_t CONFIG1_INJECT_CRC_ERROR = 55;
static const uint32_t CONFIG1_EDPL_TIME = 56;
static const uint32_t CONFIG1_EDPL_TIME_LEN = 4;
static const uint32_t CONFIG1_EDPL_THRESHOLD = 60;
static const uint32_t CONFIG1_EDPL_THRESHOLD_LEN = 3;
static const uint32_t CONFIG1_EDPL_ENA = 63;
// omi/reg00000.H

static const uint64_t CYA_BITS = 0x0c01176full;

static const uint32_t CYA_BITS_BITS1 = 32;
static const uint32_t CYA_BITS_BITS1_LEN = 17;
static const uint32_t CYA_BITS_KILL_CRC_REPLAY1 = 49;
static const uint32_t CYA_BITS_RETRAIN_CRC_REPLAY1 = 50;
static const uint32_t CYA_BITS_PM_DISABLE_EDPL1 = 51;
static const uint32_t CYA_BITS_RETRAIN_CRC_RETRAIN1 = 52;
static const uint32_t CYA_BITS_RETRAIN_CRC_RESET1 = 53;
static const uint32_t CYA_BITS_FRBUF_FULL1 = 54;
static const uint32_t CYA_BITS_FRBUF_FULL_REPLAY1 = 55;
static const uint32_t CYA_BITS_PM_RETRAIN1 = 56;
static const uint32_t CYA_BITS_PM_RESET1 = 57;
static const uint32_t CYA_BITS_CRC_RETRAIN1 = 58;
static const uint32_t CYA_BITS_CRC_RESET1 = 59;
static const uint32_t CYA_BITS_RESERVED1 = 60;
static const uint32_t CYA_BITS_RESERVED1_LEN = 4;
// omi/reg00000.H

static const uint64_t DLM0_REG0_CMN_CONFIG = 0x0c01174eull;

static const uint32_t DLM0_REG0_CMN_CONFIG_SPARE = 0;
static const uint32_t DLM0_REG0_CMN_CONFIG_SPARE_LEN = 4;
static const uint32_t DLM0_REG0_CMN_CONFIG_PM_CDR_TIMER = 4;
static const uint32_t DLM0_REG0_CMN_CONFIG_PM_CDR_TIMER_LEN = 4;
static const uint32_t DLM0_REG0_CMN_CONFIG_PM_DIDT_TIMER = 8;
static const uint32_t DLM0_REG0_CMN_CONFIG_PM_DIDT_TIMER_LEN = 4;
static const uint32_t DLM0_REG0_CMN_CONFIG_PSAV_STS_ENABLE = 12;
static const uint32_t DLM0_REG0_CMN_CONFIG_RECAL_TIMER = 13;
static const uint32_t DLM0_REG0_CMN_CONFIG_RECAL_TIMER_LEN = 3;
static const uint32_t DLM0_REG0_CMN_CONFIG_1US_TMR = 16;
static const uint32_t DLM0_REG0_CMN_CONFIG_1US_TMR_LEN = 12;
static const uint32_t DLM0_REG0_CMN_CONFIG_DBG_EN = 28;
static const uint32_t DLM0_REG0_CMN_CONFIG_DBG_SEL = 29;
static const uint32_t DLM0_REG0_CMN_CONFIG_DBG_SEL_LEN = 3;
static const uint32_t DLM0_REG0_CMN_CONFIG_RD_RST = 32;
static const uint32_t DLM0_REG0_CMN_CONFIG_PRE_SCALAR = 33;
static const uint32_t DLM0_REG0_CMN_CONFIG_PRE_SCALAR_LEN = 3;
static const uint32_t DLM0_REG0_CMN_CONFIG_FREEZE = 36;
static const uint32_t DLM0_REG0_CMN_CONFIG_PORT_SEL = 37;
static const uint32_t DLM0_REG0_CMN_CONFIG_PORT_SEL_LEN = 3;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR3_PS = 40;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR3_PS_LEN = 2;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR3_ES = 42;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR3_ES_LEN = 2;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR2_PS = 44;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR2_PS_LEN = 2;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR2_ES = 46;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR2_ES_LEN = 2;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR1_PS = 48;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR1_PS_LEN = 2;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR1_ES = 50;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR1_ES_LEN = 2;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR0_PS = 52;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR0_PS_LEN = 2;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR0_ES = 54;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR0_ES_LEN = 2;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR3_PE = 56;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR2_PE = 57;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR1_PE = 58;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR0_PE = 59;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR3_EN = 60;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR2_EN = 61;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR1_EN = 62;
static const uint32_t DLM0_REG0_CMN_CONFIG_CNTR0_EN = 63;
// omi/reg00000.H

static const uint64_t DLM0_REG0_MC_OMI_FIR_ACTION0_REG = 0x0c011746ull;

static const uint32_t DLM0_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t DLM0_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM0_REG0_MC_OMI_FIR_ACTION1_REG = 0x0c011747ull;

static const uint32_t DLM0_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t DLM0_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM0_REG0_MC_OMI_FIR_MASK_REG_ = 0x0c011743ull;

static const uint32_t DLM0_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t DLM0_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM0_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t DLM0_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM0_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t DLM0_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM0_REG0_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
// omi/reg00000.H

static const uint64_t DLM0_REG0_MC_OMI_FIR_REG_ = 0x0c011740ull;

static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_FATAL_ERROR = 0;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_DATA_UE = 1;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_FLIT_CE = 2;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_CRC_ERROR = 3;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_NACK = 4;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_X4_MODE = 5;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_EDPL = 6;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_TIMEOUT = 7;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN = 8;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN = 9;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN = 10;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_TRAINED = 11;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 = 12;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 = 13;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 = 14;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 = 15;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 = 16;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 = 17;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 = 18;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 = 19;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_FATAL_ERROR = 20;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_DATA_UE = 21;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_FLIT_CE = 22;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_CRC_ERROR = 23;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_NACK = 24;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_X4_MODE = 25;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_EDPL = 26;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_TIMEOUT = 27;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN = 28;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN = 29;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN = 30;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_TRAINED = 31;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 = 32;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 = 33;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 = 34;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 = 35;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 = 36;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 = 37;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 = 38;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 = 39;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL2_UNUSED = 40;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_DL2_UNUSED_LEN = 20;
static const uint32_t DLM0_REG0_MC_OMI_FIR_REG_PERF_MON_WRAPPED = 60;
// omi/reg00000.H

static const uint64_t DLM0_REG0_MC_OMI_FIR_WOF_REG = 0x0c011748ull;

static const uint32_t DLM0_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF = 0;
static const uint32_t DLM0_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM0_REG0_PMU_CNTR = 0x0c01174full;

static const uint32_t DLM0_REG0_PMU_CNTR_3 = 0;
static const uint32_t DLM0_REG0_PMU_CNTR_3_LEN = 16;
static const uint32_t DLM0_REG0_PMU_CNTR_2 = 16;
static const uint32_t DLM0_REG0_PMU_CNTR_2_LEN = 16;
static const uint32_t DLM0_REG0_PMU_CNTR_1 = 32;
static const uint32_t DLM0_REG0_PMU_CNTR_1_LEN = 16;
static const uint32_t DLM0_REG0_PMU_CNTR_0 = 48;
static const uint32_t DLM0_REG0_PMU_CNTR_0_LEN = 16;
// omi/reg00000.H

static const uint64_t DLM1_REG0_CMN_CONFIG = 0x0c01174eull;

static const uint32_t DLM1_REG0_CMN_CONFIG_SPARE = 0;
static const uint32_t DLM1_REG0_CMN_CONFIG_SPARE_LEN = 4;
static const uint32_t DLM1_REG0_CMN_CONFIG_PM_CDR_TIMER = 4;
static const uint32_t DLM1_REG0_CMN_CONFIG_PM_CDR_TIMER_LEN = 4;
static const uint32_t DLM1_REG0_CMN_CONFIG_PM_DIDT_TIMER = 8;
static const uint32_t DLM1_REG0_CMN_CONFIG_PM_DIDT_TIMER_LEN = 4;
static const uint32_t DLM1_REG0_CMN_CONFIG_PSAV_STS_ENABLE = 12;
static const uint32_t DLM1_REG0_CMN_CONFIG_RECAL_TIMER = 13;
static const uint32_t DLM1_REG0_CMN_CONFIG_RECAL_TIMER_LEN = 3;
static const uint32_t DLM1_REG0_CMN_CONFIG_1US_TMR = 16;
static const uint32_t DLM1_REG0_CMN_CONFIG_1US_TMR_LEN = 12;
static const uint32_t DLM1_REG0_CMN_CONFIG_DBG_EN = 28;
static const uint32_t DLM1_REG0_CMN_CONFIG_DBG_SEL = 29;
static const uint32_t DLM1_REG0_CMN_CONFIG_DBG_SEL_LEN = 3;
static const uint32_t DLM1_REG0_CMN_CONFIG_RD_RST = 32;
static const uint32_t DLM1_REG0_CMN_CONFIG_PRE_SCALAR = 33;
static const uint32_t DLM1_REG0_CMN_CONFIG_PRE_SCALAR_LEN = 3;
static const uint32_t DLM1_REG0_CMN_CONFIG_FREEZE = 36;
static const uint32_t DLM1_REG0_CMN_CONFIG_PORT_SEL = 37;
static const uint32_t DLM1_REG0_CMN_CONFIG_PORT_SEL_LEN = 3;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR3_PS = 40;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR3_PS_LEN = 2;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR3_ES = 42;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR3_ES_LEN = 2;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR2_PS = 44;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR2_PS_LEN = 2;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR2_ES = 46;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR2_ES_LEN = 2;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR1_PS = 48;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR1_PS_LEN = 2;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR1_ES = 50;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR1_ES_LEN = 2;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR0_PS = 52;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR0_PS_LEN = 2;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR0_ES = 54;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR0_ES_LEN = 2;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR3_PE = 56;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR2_PE = 57;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR1_PE = 58;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR0_PE = 59;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR3_EN = 60;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR2_EN = 61;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR1_EN = 62;
static const uint32_t DLM1_REG0_CMN_CONFIG_CNTR0_EN = 63;
// omi/reg00000.H

static const uint64_t DLM1_REG0_MC_OMI_FIR_ACTION0_REG = 0x0c011746ull;

static const uint32_t DLM1_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t DLM1_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM1_REG0_MC_OMI_FIR_ACTION1_REG = 0x0c011747ull;

static const uint32_t DLM1_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t DLM1_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM1_REG0_MC_OMI_FIR_MASK_REG_ = 0x0c011743ull;

static const uint32_t DLM1_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t DLM1_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM1_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t DLM1_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM1_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t DLM1_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM1_REG0_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
// omi/reg00000.H

static const uint64_t DLM1_REG0_MC_OMI_FIR_REG_ = 0x0c011740ull;

static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_FATAL_ERROR = 0;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_DATA_UE = 1;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_FLIT_CE = 2;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_CRC_ERROR = 3;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_NACK = 4;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_X4_MODE = 5;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_EDPL = 6;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_TIMEOUT = 7;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN = 8;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN = 9;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN = 10;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_TRAINED = 11;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 = 12;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 = 13;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 = 14;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 = 15;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 = 16;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 = 17;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 = 18;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 = 19;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_FATAL_ERROR = 20;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_DATA_UE = 21;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_FLIT_CE = 22;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_CRC_ERROR = 23;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_NACK = 24;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_X4_MODE = 25;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_EDPL = 26;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_TIMEOUT = 27;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN = 28;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN = 29;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN = 30;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_TRAINED = 31;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 = 32;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 = 33;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 = 34;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 = 35;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 = 36;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 = 37;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 = 38;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 = 39;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL2_UNUSED = 40;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_DL2_UNUSED_LEN = 20;
static const uint32_t DLM1_REG0_MC_OMI_FIR_REG_PERF_MON_WRAPPED = 60;
// omi/reg00000.H

static const uint64_t DLM1_REG0_MC_OMI_FIR_WOF_REG = 0x0c011748ull;

static const uint32_t DLM1_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF = 0;
static const uint32_t DLM1_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM1_REG0_PMU_CNTR = 0x0c01174full;

static const uint32_t DLM1_REG0_PMU_CNTR_3 = 0;
static const uint32_t DLM1_REG0_PMU_CNTR_3_LEN = 16;
static const uint32_t DLM1_REG0_PMU_CNTR_2 = 16;
static const uint32_t DLM1_REG0_PMU_CNTR_2_LEN = 16;
static const uint32_t DLM1_REG0_PMU_CNTR_1 = 32;
static const uint32_t DLM1_REG0_PMU_CNTR_1_LEN = 16;
static const uint32_t DLM1_REG0_PMU_CNTR_0 = 48;
static const uint32_t DLM1_REG0_PMU_CNTR_0_LEN = 16;
// omi/reg00000.H

static const uint64_t DLM2_REG0_CMN_CONFIG = 0x0c01174eull;

static const uint32_t DLM2_REG0_CMN_CONFIG_SPARE = 0;
static const uint32_t DLM2_REG0_CMN_CONFIG_SPARE_LEN = 4;
static const uint32_t DLM2_REG0_CMN_CONFIG_PM_CDR_TIMER = 4;
static const uint32_t DLM2_REG0_CMN_CONFIG_PM_CDR_TIMER_LEN = 4;
static const uint32_t DLM2_REG0_CMN_CONFIG_PM_DIDT_TIMER = 8;
static const uint32_t DLM2_REG0_CMN_CONFIG_PM_DIDT_TIMER_LEN = 4;
static const uint32_t DLM2_REG0_CMN_CONFIG_PSAV_STS_ENABLE = 12;
static const uint32_t DLM2_REG0_CMN_CONFIG_RECAL_TIMER = 13;
static const uint32_t DLM2_REG0_CMN_CONFIG_RECAL_TIMER_LEN = 3;
static const uint32_t DLM2_REG0_CMN_CONFIG_1US_TMR = 16;
static const uint32_t DLM2_REG0_CMN_CONFIG_1US_TMR_LEN = 12;
static const uint32_t DLM2_REG0_CMN_CONFIG_DBG_EN = 28;
static const uint32_t DLM2_REG0_CMN_CONFIG_DBG_SEL = 29;
static const uint32_t DLM2_REG0_CMN_CONFIG_DBG_SEL_LEN = 3;
static const uint32_t DLM2_REG0_CMN_CONFIG_RD_RST = 32;
static const uint32_t DLM2_REG0_CMN_CONFIG_PRE_SCALAR = 33;
static const uint32_t DLM2_REG0_CMN_CONFIG_PRE_SCALAR_LEN = 3;
static const uint32_t DLM2_REG0_CMN_CONFIG_FREEZE = 36;
static const uint32_t DLM2_REG0_CMN_CONFIG_PORT_SEL = 37;
static const uint32_t DLM2_REG0_CMN_CONFIG_PORT_SEL_LEN = 3;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR3_PS = 40;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR3_PS_LEN = 2;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR3_ES = 42;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR3_ES_LEN = 2;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR2_PS = 44;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR2_PS_LEN = 2;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR2_ES = 46;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR2_ES_LEN = 2;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR1_PS = 48;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR1_PS_LEN = 2;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR1_ES = 50;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR1_ES_LEN = 2;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR0_PS = 52;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR0_PS_LEN = 2;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR0_ES = 54;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR0_ES_LEN = 2;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR3_PE = 56;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR2_PE = 57;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR1_PE = 58;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR0_PE = 59;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR3_EN = 60;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR2_EN = 61;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR1_EN = 62;
static const uint32_t DLM2_REG0_CMN_CONFIG_CNTR0_EN = 63;
// omi/reg00000.H

static const uint64_t DLM2_REG0_MC_OMI_FIR_ACTION0_REG = 0x0c011746ull;

static const uint32_t DLM2_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t DLM2_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM2_REG0_MC_OMI_FIR_ACTION1_REG = 0x0c011747ull;

static const uint32_t DLM2_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t DLM2_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM2_REG0_MC_OMI_FIR_MASK_REG_ = 0x0c011743ull;

static const uint32_t DLM2_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t DLM2_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM2_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t DLM2_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM2_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t DLM2_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM2_REG0_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
// omi/reg00000.H

static const uint64_t DLM2_REG0_MC_OMI_FIR_REG_ = 0x0c011740ull;

static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_FATAL_ERROR = 0;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_DATA_UE = 1;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_FLIT_CE = 2;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_CRC_ERROR = 3;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_NACK = 4;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_X4_MODE = 5;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_EDPL = 6;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_TIMEOUT = 7;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN = 8;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN = 9;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN = 10;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_TRAINED = 11;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 = 12;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 = 13;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 = 14;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 = 15;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 = 16;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 = 17;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 = 18;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 = 19;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_FATAL_ERROR = 20;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_DATA_UE = 21;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_FLIT_CE = 22;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_CRC_ERROR = 23;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_NACK = 24;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_X4_MODE = 25;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_EDPL = 26;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_TIMEOUT = 27;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN = 28;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN = 29;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN = 30;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_TRAINED = 31;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 = 32;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 = 33;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 = 34;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 = 35;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 = 36;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 = 37;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 = 38;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 = 39;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL2_UNUSED = 40;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_DL2_UNUSED_LEN = 20;
static const uint32_t DLM2_REG0_MC_OMI_FIR_REG_PERF_MON_WRAPPED = 60;
// omi/reg00000.H

static const uint64_t DLM2_REG0_MC_OMI_FIR_WOF_REG = 0x0c011748ull;

static const uint32_t DLM2_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF = 0;
static const uint32_t DLM2_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM2_REG0_PMU_CNTR = 0x0c01174full;

static const uint32_t DLM2_REG0_PMU_CNTR_3 = 0;
static const uint32_t DLM2_REG0_PMU_CNTR_3_LEN = 16;
static const uint32_t DLM2_REG0_PMU_CNTR_2 = 16;
static const uint32_t DLM2_REG0_PMU_CNTR_2_LEN = 16;
static const uint32_t DLM2_REG0_PMU_CNTR_1 = 32;
static const uint32_t DLM2_REG0_PMU_CNTR_1_LEN = 16;
static const uint32_t DLM2_REG0_PMU_CNTR_0 = 48;
static const uint32_t DLM2_REG0_PMU_CNTR_0_LEN = 16;
// omi/reg00000.H

static const uint64_t DLM3_REG0_CMN_CONFIG = 0x0c01174eull;

static const uint32_t DLM3_REG0_CMN_CONFIG_SPARE = 0;
static const uint32_t DLM3_REG0_CMN_CONFIG_SPARE_LEN = 4;
static const uint32_t DLM3_REG0_CMN_CONFIG_PM_CDR_TIMER = 4;
static const uint32_t DLM3_REG0_CMN_CONFIG_PM_CDR_TIMER_LEN = 4;
static const uint32_t DLM3_REG0_CMN_CONFIG_PM_DIDT_TIMER = 8;
static const uint32_t DLM3_REG0_CMN_CONFIG_PM_DIDT_TIMER_LEN = 4;
static const uint32_t DLM3_REG0_CMN_CONFIG_PSAV_STS_ENABLE = 12;
static const uint32_t DLM3_REG0_CMN_CONFIG_RECAL_TIMER = 13;
static const uint32_t DLM3_REG0_CMN_CONFIG_RECAL_TIMER_LEN = 3;
static const uint32_t DLM3_REG0_CMN_CONFIG_1US_TMR = 16;
static const uint32_t DLM3_REG0_CMN_CONFIG_1US_TMR_LEN = 12;
static const uint32_t DLM3_REG0_CMN_CONFIG_DBG_EN = 28;
static const uint32_t DLM3_REG0_CMN_CONFIG_DBG_SEL = 29;
static const uint32_t DLM3_REG0_CMN_CONFIG_DBG_SEL_LEN = 3;
static const uint32_t DLM3_REG0_CMN_CONFIG_RD_RST = 32;
static const uint32_t DLM3_REG0_CMN_CONFIG_PRE_SCALAR = 33;
static const uint32_t DLM3_REG0_CMN_CONFIG_PRE_SCALAR_LEN = 3;
static const uint32_t DLM3_REG0_CMN_CONFIG_FREEZE = 36;
static const uint32_t DLM3_REG0_CMN_CONFIG_PORT_SEL = 37;
static const uint32_t DLM3_REG0_CMN_CONFIG_PORT_SEL_LEN = 3;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR3_PS = 40;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR3_PS_LEN = 2;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR3_ES = 42;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR3_ES_LEN = 2;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR2_PS = 44;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR2_PS_LEN = 2;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR2_ES = 46;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR2_ES_LEN = 2;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR1_PS = 48;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR1_PS_LEN = 2;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR1_ES = 50;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR1_ES_LEN = 2;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR0_PS = 52;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR0_PS_LEN = 2;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR0_ES = 54;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR0_ES_LEN = 2;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR3_PE = 56;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR2_PE = 57;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR1_PE = 58;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR0_PE = 59;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR3_EN = 60;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR2_EN = 61;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR1_EN = 62;
static const uint32_t DLM3_REG0_CMN_CONFIG_CNTR0_EN = 63;
// omi/reg00000.H

static const uint64_t DLM3_REG0_MC_OMI_FIR_ACTION0_REG = 0x0c011746ull;

static const uint32_t DLM3_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t DLM3_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM3_REG0_MC_OMI_FIR_ACTION1_REG = 0x0c011747ull;

static const uint32_t DLM3_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t DLM3_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM3_REG0_MC_OMI_FIR_MASK_REG_ = 0x0c011743ull;

static const uint32_t DLM3_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t DLM3_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM3_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t DLM3_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM3_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t DLM3_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM3_REG0_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
// omi/reg00000.H

static const uint64_t DLM3_REG0_MC_OMI_FIR_REG_ = 0x0c011740ull;

static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_FATAL_ERROR = 0;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_DATA_UE = 1;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_FLIT_CE = 2;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_CRC_ERROR = 3;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_NACK = 4;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_X4_MODE = 5;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_EDPL = 6;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_TIMEOUT = 7;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN = 8;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN = 9;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN = 10;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_TRAINED = 11;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 = 12;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 = 13;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 = 14;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 = 15;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 = 16;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 = 17;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 = 18;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 = 19;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_FATAL_ERROR = 20;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_DATA_UE = 21;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_FLIT_CE = 22;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_CRC_ERROR = 23;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_NACK = 24;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_X4_MODE = 25;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_EDPL = 26;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_TIMEOUT = 27;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN = 28;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN = 29;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN = 30;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_TRAINED = 31;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 = 32;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 = 33;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 = 34;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 = 35;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 = 36;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 = 37;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 = 38;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 = 39;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL2_UNUSED = 40;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_DL2_UNUSED_LEN = 20;
static const uint32_t DLM3_REG0_MC_OMI_FIR_REG_PERF_MON_WRAPPED = 60;
// omi/reg00000.H

static const uint64_t DLM3_REG0_MC_OMI_FIR_WOF_REG = 0x0c011748ull;

static const uint32_t DLM3_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF = 0;
static const uint32_t DLM3_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM3_REG0_PMU_CNTR = 0x0c01174full;

static const uint32_t DLM3_REG0_PMU_CNTR_3 = 0;
static const uint32_t DLM3_REG0_PMU_CNTR_3_LEN = 16;
static const uint32_t DLM3_REG0_PMU_CNTR_2 = 16;
static const uint32_t DLM3_REG0_PMU_CNTR_2_LEN = 16;
static const uint32_t DLM3_REG0_PMU_CNTR_1 = 32;
static const uint32_t DLM3_REG0_PMU_CNTR_1_LEN = 16;
static const uint32_t DLM3_REG0_PMU_CNTR_0 = 48;
static const uint32_t DLM3_REG0_PMU_CNTR_0_LEN = 16;
// omi/reg00000.H

static const uint64_t DLM4_REG0_CMN_CONFIG = 0x0c01174eull;

static const uint32_t DLM4_REG0_CMN_CONFIG_SPARE = 0;
static const uint32_t DLM4_REG0_CMN_CONFIG_SPARE_LEN = 4;
static const uint32_t DLM4_REG0_CMN_CONFIG_PM_CDR_TIMER = 4;
static const uint32_t DLM4_REG0_CMN_CONFIG_PM_CDR_TIMER_LEN = 4;
static const uint32_t DLM4_REG0_CMN_CONFIG_PM_DIDT_TIMER = 8;
static const uint32_t DLM4_REG0_CMN_CONFIG_PM_DIDT_TIMER_LEN = 4;
static const uint32_t DLM4_REG0_CMN_CONFIG_PSAV_STS_ENABLE = 12;
static const uint32_t DLM4_REG0_CMN_CONFIG_RECAL_TIMER = 13;
static const uint32_t DLM4_REG0_CMN_CONFIG_RECAL_TIMER_LEN = 3;
static const uint32_t DLM4_REG0_CMN_CONFIG_1US_TMR = 16;
static const uint32_t DLM4_REG0_CMN_CONFIG_1US_TMR_LEN = 12;
static const uint32_t DLM4_REG0_CMN_CONFIG_DBG_EN = 28;
static const uint32_t DLM4_REG0_CMN_CONFIG_DBG_SEL = 29;
static const uint32_t DLM4_REG0_CMN_CONFIG_DBG_SEL_LEN = 3;
static const uint32_t DLM4_REG0_CMN_CONFIG_RD_RST = 32;
static const uint32_t DLM4_REG0_CMN_CONFIG_PRE_SCALAR = 33;
static const uint32_t DLM4_REG0_CMN_CONFIG_PRE_SCALAR_LEN = 3;
static const uint32_t DLM4_REG0_CMN_CONFIG_FREEZE = 36;
static const uint32_t DLM4_REG0_CMN_CONFIG_PORT_SEL = 37;
static const uint32_t DLM4_REG0_CMN_CONFIG_PORT_SEL_LEN = 3;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR3_PS = 40;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR3_PS_LEN = 2;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR3_ES = 42;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR3_ES_LEN = 2;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR2_PS = 44;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR2_PS_LEN = 2;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR2_ES = 46;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR2_ES_LEN = 2;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR1_PS = 48;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR1_PS_LEN = 2;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR1_ES = 50;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR1_ES_LEN = 2;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR0_PS = 52;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR0_PS_LEN = 2;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR0_ES = 54;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR0_ES_LEN = 2;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR3_PE = 56;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR2_PE = 57;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR1_PE = 58;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR0_PE = 59;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR3_EN = 60;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR2_EN = 61;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR1_EN = 62;
static const uint32_t DLM4_REG0_CMN_CONFIG_CNTR0_EN = 63;
// omi/reg00000.H

static const uint64_t DLM4_REG0_MC_OMI_FIR_ACTION0_REG = 0x0c011746ull;

static const uint32_t DLM4_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t DLM4_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM4_REG0_MC_OMI_FIR_ACTION1_REG = 0x0c011747ull;

static const uint32_t DLM4_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t DLM4_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM4_REG0_MC_OMI_FIR_MASK_REG_ = 0x0c011743ull;

static const uint32_t DLM4_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t DLM4_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM4_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t DLM4_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM4_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t DLM4_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM4_REG0_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
// omi/reg00000.H

static const uint64_t DLM4_REG0_MC_OMI_FIR_REG_ = 0x0c011740ull;

static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_FATAL_ERROR = 0;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_DATA_UE = 1;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_FLIT_CE = 2;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_CRC_ERROR = 3;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_NACK = 4;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_X4_MODE = 5;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_EDPL = 6;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_TIMEOUT = 7;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN = 8;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN = 9;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN = 10;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_TRAINED = 11;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 = 12;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 = 13;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 = 14;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 = 15;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 = 16;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 = 17;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 = 18;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 = 19;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_FATAL_ERROR = 20;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_DATA_UE = 21;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_FLIT_CE = 22;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_CRC_ERROR = 23;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_NACK = 24;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_X4_MODE = 25;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_EDPL = 26;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_TIMEOUT = 27;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN = 28;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN = 29;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN = 30;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_TRAINED = 31;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 = 32;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 = 33;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 = 34;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 = 35;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 = 36;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 = 37;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 = 38;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 = 39;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL2_UNUSED = 40;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_DL2_UNUSED_LEN = 20;
static const uint32_t DLM4_REG0_MC_OMI_FIR_REG_PERF_MON_WRAPPED = 60;
// omi/reg00000.H

static const uint64_t DLM4_REG0_MC_OMI_FIR_WOF_REG = 0x0c011748ull;

static const uint32_t DLM4_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF = 0;
static const uint32_t DLM4_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM4_REG0_PMU_CNTR = 0x0c01174full;

static const uint32_t DLM4_REG0_PMU_CNTR_3 = 0;
static const uint32_t DLM4_REG0_PMU_CNTR_3_LEN = 16;
static const uint32_t DLM4_REG0_PMU_CNTR_2 = 16;
static const uint32_t DLM4_REG0_PMU_CNTR_2_LEN = 16;
static const uint32_t DLM4_REG0_PMU_CNTR_1 = 32;
static const uint32_t DLM4_REG0_PMU_CNTR_1_LEN = 16;
static const uint32_t DLM4_REG0_PMU_CNTR_0 = 48;
static const uint32_t DLM4_REG0_PMU_CNTR_0_LEN = 16;
// omi/reg00000.H

static const uint64_t DLM5_REG0_CMN_CONFIG = 0x0c01174eull;

static const uint32_t DLM5_REG0_CMN_CONFIG_SPARE = 0;
static const uint32_t DLM5_REG0_CMN_CONFIG_SPARE_LEN = 4;
static const uint32_t DLM5_REG0_CMN_CONFIG_PM_CDR_TIMER = 4;
static const uint32_t DLM5_REG0_CMN_CONFIG_PM_CDR_TIMER_LEN = 4;
static const uint32_t DLM5_REG0_CMN_CONFIG_PM_DIDT_TIMER = 8;
static const uint32_t DLM5_REG0_CMN_CONFIG_PM_DIDT_TIMER_LEN = 4;
static const uint32_t DLM5_REG0_CMN_CONFIG_PSAV_STS_ENABLE = 12;
static const uint32_t DLM5_REG0_CMN_CONFIG_RECAL_TIMER = 13;
static const uint32_t DLM5_REG0_CMN_CONFIG_RECAL_TIMER_LEN = 3;
static const uint32_t DLM5_REG0_CMN_CONFIG_1US_TMR = 16;
static const uint32_t DLM5_REG0_CMN_CONFIG_1US_TMR_LEN = 12;
static const uint32_t DLM5_REG0_CMN_CONFIG_DBG_EN = 28;
static const uint32_t DLM5_REG0_CMN_CONFIG_DBG_SEL = 29;
static const uint32_t DLM5_REG0_CMN_CONFIG_DBG_SEL_LEN = 3;
static const uint32_t DLM5_REG0_CMN_CONFIG_RD_RST = 32;
static const uint32_t DLM5_REG0_CMN_CONFIG_PRE_SCALAR = 33;
static const uint32_t DLM5_REG0_CMN_CONFIG_PRE_SCALAR_LEN = 3;
static const uint32_t DLM5_REG0_CMN_CONFIG_FREEZE = 36;
static const uint32_t DLM5_REG0_CMN_CONFIG_PORT_SEL = 37;
static const uint32_t DLM5_REG0_CMN_CONFIG_PORT_SEL_LEN = 3;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR3_PS = 40;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR3_PS_LEN = 2;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR3_ES = 42;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR3_ES_LEN = 2;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR2_PS = 44;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR2_PS_LEN = 2;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR2_ES = 46;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR2_ES_LEN = 2;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR1_PS = 48;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR1_PS_LEN = 2;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR1_ES = 50;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR1_ES_LEN = 2;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR0_PS = 52;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR0_PS_LEN = 2;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR0_ES = 54;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR0_ES_LEN = 2;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR3_PE = 56;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR2_PE = 57;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR1_PE = 58;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR0_PE = 59;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR3_EN = 60;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR2_EN = 61;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR1_EN = 62;
static const uint32_t DLM5_REG0_CMN_CONFIG_CNTR0_EN = 63;
// omi/reg00000.H

static const uint64_t DLM5_REG0_MC_OMI_FIR_ACTION0_REG = 0x0c011746ull;

static const uint32_t DLM5_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t DLM5_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM5_REG0_MC_OMI_FIR_ACTION1_REG = 0x0c011747ull;

static const uint32_t DLM5_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t DLM5_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM5_REG0_MC_OMI_FIR_MASK_REG_ = 0x0c011743ull;

static const uint32_t DLM5_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t DLM5_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM5_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t DLM5_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM5_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t DLM5_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM5_REG0_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
// omi/reg00000.H

static const uint64_t DLM5_REG0_MC_OMI_FIR_REG_ = 0x0c011740ull;

static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_FATAL_ERROR = 0;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_DATA_UE = 1;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_FLIT_CE = 2;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_CRC_ERROR = 3;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_NACK = 4;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_X4_MODE = 5;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_EDPL = 6;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_TIMEOUT = 7;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN = 8;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN = 9;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN = 10;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_TRAINED = 11;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 = 12;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 = 13;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 = 14;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 = 15;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 = 16;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 = 17;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 = 18;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 = 19;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_FATAL_ERROR = 20;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_DATA_UE = 21;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_FLIT_CE = 22;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_CRC_ERROR = 23;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_NACK = 24;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_X4_MODE = 25;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_EDPL = 26;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_TIMEOUT = 27;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN = 28;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN = 29;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN = 30;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_TRAINED = 31;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 = 32;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 = 33;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 = 34;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 = 35;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 = 36;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 = 37;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 = 38;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 = 39;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL2_UNUSED = 40;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_DL2_UNUSED_LEN = 20;
static const uint32_t DLM5_REG0_MC_OMI_FIR_REG_PERF_MON_WRAPPED = 60;
// omi/reg00000.H

static const uint64_t DLM5_REG0_MC_OMI_FIR_WOF_REG = 0x0c011748ull;

static const uint32_t DLM5_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF = 0;
static const uint32_t DLM5_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM5_REG0_PMU_CNTR = 0x0c01174full;

static const uint32_t DLM5_REG0_PMU_CNTR_3 = 0;
static const uint32_t DLM5_REG0_PMU_CNTR_3_LEN = 16;
static const uint32_t DLM5_REG0_PMU_CNTR_2 = 16;
static const uint32_t DLM5_REG0_PMU_CNTR_2_LEN = 16;
static const uint32_t DLM5_REG0_PMU_CNTR_1 = 32;
static const uint32_t DLM5_REG0_PMU_CNTR_1_LEN = 16;
static const uint32_t DLM5_REG0_PMU_CNTR_0 = 48;
static const uint32_t DLM5_REG0_PMU_CNTR_0_LEN = 16;
// omi/reg00000.H

static const uint64_t DLM6_REG0_CMN_CONFIG = 0x0c01174eull;

static const uint32_t DLM6_REG0_CMN_CONFIG_SPARE = 0;
static const uint32_t DLM6_REG0_CMN_CONFIG_SPARE_LEN = 4;
static const uint32_t DLM6_REG0_CMN_CONFIG_PM_CDR_TIMER = 4;
static const uint32_t DLM6_REG0_CMN_CONFIG_PM_CDR_TIMER_LEN = 4;
static const uint32_t DLM6_REG0_CMN_CONFIG_PM_DIDT_TIMER = 8;
static const uint32_t DLM6_REG0_CMN_CONFIG_PM_DIDT_TIMER_LEN = 4;
static const uint32_t DLM6_REG0_CMN_CONFIG_PSAV_STS_ENABLE = 12;
static const uint32_t DLM6_REG0_CMN_CONFIG_RECAL_TIMER = 13;
static const uint32_t DLM6_REG0_CMN_CONFIG_RECAL_TIMER_LEN = 3;
static const uint32_t DLM6_REG0_CMN_CONFIG_1US_TMR = 16;
static const uint32_t DLM6_REG0_CMN_CONFIG_1US_TMR_LEN = 12;
static const uint32_t DLM6_REG0_CMN_CONFIG_DBG_EN = 28;
static const uint32_t DLM6_REG0_CMN_CONFIG_DBG_SEL = 29;
static const uint32_t DLM6_REG0_CMN_CONFIG_DBG_SEL_LEN = 3;
static const uint32_t DLM6_REG0_CMN_CONFIG_RD_RST = 32;
static const uint32_t DLM6_REG0_CMN_CONFIG_PRE_SCALAR = 33;
static const uint32_t DLM6_REG0_CMN_CONFIG_PRE_SCALAR_LEN = 3;
static const uint32_t DLM6_REG0_CMN_CONFIG_FREEZE = 36;
static const uint32_t DLM6_REG0_CMN_CONFIG_PORT_SEL = 37;
static const uint32_t DLM6_REG0_CMN_CONFIG_PORT_SEL_LEN = 3;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR3_PS = 40;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR3_PS_LEN = 2;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR3_ES = 42;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR3_ES_LEN = 2;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR2_PS = 44;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR2_PS_LEN = 2;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR2_ES = 46;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR2_ES_LEN = 2;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR1_PS = 48;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR1_PS_LEN = 2;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR1_ES = 50;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR1_ES_LEN = 2;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR0_PS = 52;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR0_PS_LEN = 2;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR0_ES = 54;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR0_ES_LEN = 2;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR3_PE = 56;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR2_PE = 57;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR1_PE = 58;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR0_PE = 59;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR3_EN = 60;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR2_EN = 61;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR1_EN = 62;
static const uint32_t DLM6_REG0_CMN_CONFIG_CNTR0_EN = 63;
// omi/reg00000.H

static const uint64_t DLM6_REG0_MC_OMI_FIR_ACTION0_REG = 0x0c011746ull;

static const uint32_t DLM6_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t DLM6_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM6_REG0_MC_OMI_FIR_ACTION1_REG = 0x0c011747ull;

static const uint32_t DLM6_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t DLM6_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
// omi/reg00000.H

static const uint64_t DLM6_REG0_MC_OMI_FIR_MASK_REG_ = 0x0c011743ull;

static const uint32_t DLM6_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t DLM6_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM6_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t DLM6_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM6_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t DLM6_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM6_REG0_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
// omi/reg00000.H

static const uint64_t DLM6_REG0_MC_OMI_FIR_REG_ = 0x0c011740ull;

static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_FATAL_ERROR = 0;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_DATA_UE = 1;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_FLIT_CE = 2;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_CRC_ERROR = 3;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_NACK = 4;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_X4_MODE = 5;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_EDPL = 6;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_TIMEOUT = 7;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN = 8;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN = 9;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN = 10;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_TRAINED = 11;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 = 12;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 = 13;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 = 14;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 = 15;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 = 16;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 = 17;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 = 18;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 = 19;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_FATAL_ERROR = 20;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_DATA_UE = 21;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_FLIT_CE = 22;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_CRC_ERROR = 23;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_NACK = 24;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_X4_MODE = 25;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_EDPL = 26;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_TIMEOUT = 27;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN = 28;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN = 29;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN = 30;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_TRAINED = 31;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 = 32;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 = 33;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 = 34;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 = 35;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 = 36;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 = 37;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 = 38;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 = 39;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL2_UNUSED = 40;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_DL2_UNUSED_LEN = 20;
static const uint32_t DLM6_REG0_MC_OMI_FIR_REG_PERF_MON_WRAPPED = 60;
// omi/reg00001.H

static const uint64_t DLM6_REG0_MC_OMI_FIR_WOF_REG = 0x0c011748ull;

static const uint32_t DLM6_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF = 0;
static const uint32_t DLM6_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF_LEN = 62;
// omi/reg00001.H

static const uint64_t DLM6_REG0_PMU_CNTR = 0x0c01174full;

static const uint32_t DLM6_REG0_PMU_CNTR_3 = 0;
static const uint32_t DLM6_REG0_PMU_CNTR_3_LEN = 16;
static const uint32_t DLM6_REG0_PMU_CNTR_2 = 16;
static const uint32_t DLM6_REG0_PMU_CNTR_2_LEN = 16;
static const uint32_t DLM6_REG0_PMU_CNTR_1 = 32;
static const uint32_t DLM6_REG0_PMU_CNTR_1_LEN = 16;
static const uint32_t DLM6_REG0_PMU_CNTR_0 = 48;
static const uint32_t DLM6_REG0_PMU_CNTR_0_LEN = 16;
// omi/reg00001.H

static const uint64_t DLM7_REG0_CMN_CONFIG = 0x0c01174eull;

static const uint32_t DLM7_REG0_CMN_CONFIG_SPARE = 0;
static const uint32_t DLM7_REG0_CMN_CONFIG_SPARE_LEN = 4;
static const uint32_t DLM7_REG0_CMN_CONFIG_PM_CDR_TIMER = 4;
static const uint32_t DLM7_REG0_CMN_CONFIG_PM_CDR_TIMER_LEN = 4;
static const uint32_t DLM7_REG0_CMN_CONFIG_PM_DIDT_TIMER = 8;
static const uint32_t DLM7_REG0_CMN_CONFIG_PM_DIDT_TIMER_LEN = 4;
static const uint32_t DLM7_REG0_CMN_CONFIG_PSAV_STS_ENABLE = 12;
static const uint32_t DLM7_REG0_CMN_CONFIG_RECAL_TIMER = 13;
static const uint32_t DLM7_REG0_CMN_CONFIG_RECAL_TIMER_LEN = 3;
static const uint32_t DLM7_REG0_CMN_CONFIG_1US_TMR = 16;
static const uint32_t DLM7_REG0_CMN_CONFIG_1US_TMR_LEN = 12;
static const uint32_t DLM7_REG0_CMN_CONFIG_DBG_EN = 28;
static const uint32_t DLM7_REG0_CMN_CONFIG_DBG_SEL = 29;
static const uint32_t DLM7_REG0_CMN_CONFIG_DBG_SEL_LEN = 3;
static const uint32_t DLM7_REG0_CMN_CONFIG_RD_RST = 32;
static const uint32_t DLM7_REG0_CMN_CONFIG_PRE_SCALAR = 33;
static const uint32_t DLM7_REG0_CMN_CONFIG_PRE_SCALAR_LEN = 3;
static const uint32_t DLM7_REG0_CMN_CONFIG_FREEZE = 36;
static const uint32_t DLM7_REG0_CMN_CONFIG_PORT_SEL = 37;
static const uint32_t DLM7_REG0_CMN_CONFIG_PORT_SEL_LEN = 3;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR3_PS = 40;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR3_PS_LEN = 2;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR3_ES = 42;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR3_ES_LEN = 2;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR2_PS = 44;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR2_PS_LEN = 2;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR2_ES = 46;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR2_ES_LEN = 2;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR1_PS = 48;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR1_PS_LEN = 2;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR1_ES = 50;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR1_ES_LEN = 2;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR0_PS = 52;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR0_PS_LEN = 2;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR0_ES = 54;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR0_ES_LEN = 2;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR3_PE = 56;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR2_PE = 57;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR1_PE = 58;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR0_PE = 59;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR3_EN = 60;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR2_EN = 61;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR1_EN = 62;
static const uint32_t DLM7_REG0_CMN_CONFIG_CNTR0_EN = 63;
// omi/reg00001.H

static const uint64_t DLM7_REG0_MC_OMI_FIR_ACTION0_REG = 0x0c011746ull;

static const uint32_t DLM7_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t DLM7_REG0_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
// omi/reg00001.H

static const uint64_t DLM7_REG0_MC_OMI_FIR_ACTION1_REG = 0x0c011747ull;

static const uint32_t DLM7_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t DLM7_REG0_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
// omi/reg00001.H

static const uint64_t DLM7_REG0_MC_OMI_FIR_MASK_REG_ = 0x0c011743ull;

static const uint32_t DLM7_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t DLM7_REG0_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM7_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t DLM7_REG0_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM7_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t DLM7_REG0_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t DLM7_REG0_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
// omi/reg00001.H

static const uint64_t DLM7_REG0_MC_OMI_FIR_REG_ = 0x0c011740ull;

static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_FATAL_ERROR = 0;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_DATA_UE = 1;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_FLIT_CE = 2;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_CRC_ERROR = 3;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_NACK = 4;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_X4_MODE = 5;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_EDPL = 6;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_TIMEOUT = 7;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN = 8;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN = 9;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN = 10;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_TRAINED = 11;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 = 12;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 = 13;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 = 14;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 = 15;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 = 16;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 = 17;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 = 18;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 = 19;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_FATAL_ERROR = 20;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_DATA_UE = 21;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_FLIT_CE = 22;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_CRC_ERROR = 23;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_NACK = 24;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_X4_MODE = 25;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_EDPL = 26;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_TIMEOUT = 27;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN = 28;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN = 29;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN = 30;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_TRAINED = 31;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 = 32;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 = 33;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 = 34;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 = 35;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 = 36;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 = 37;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 = 38;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 = 39;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL2_UNUSED = 40;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_DL2_UNUSED_LEN = 20;
static const uint32_t DLM7_REG0_MC_OMI_FIR_REG_PERF_MON_WRAPPED = 60;
// omi/reg00001.H

static const uint64_t DLM7_REG0_MC_OMI_FIR_WOF_REG = 0x0c011748ull;

static const uint32_t DLM7_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF = 0;
static const uint32_t DLM7_REG0_MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF_LEN = 62;
// omi/reg00001.H

static const uint64_t DLM7_REG0_PMU_CNTR = 0x0c01174full;

static const uint32_t DLM7_REG0_PMU_CNTR_3 = 0;
static const uint32_t DLM7_REG0_PMU_CNTR_3_LEN = 16;
static const uint32_t DLM7_REG0_PMU_CNTR_2 = 16;
static const uint32_t DLM7_REG0_PMU_CNTR_2_LEN = 16;
static const uint32_t DLM7_REG0_PMU_CNTR_1 = 32;
static const uint32_t DLM7_REG0_PMU_CNTR_1_LEN = 16;
static const uint32_t DLM7_REG0_PMU_CNTR_0 = 48;
static const uint32_t DLM7_REG0_PMU_CNTR_0_LEN = 16;
// omi/reg00001.H

static const uint64_t DLX_CONFIG = 0x0c011768ull;

static const uint32_t DLX_CONFIG_CFG_DLX1 = 32;
static const uint32_t DLX_CONFIG_CFG_DLX1_LEN = 32;
// omi/reg00001.H

static const uint64_t DLX_INFO = 0x0c011769ull;

static const uint32_t DLX_INFO_DL1_STS_DLX_INFO = 0;
static const uint32_t DLX_INFO_DL1_STS_DLX_INFO_LEN = 64;
// omi/reg00001.H

static const uint64_t EDPL_MAX_COUNT = 0x0c011765ull;

static const uint32_t EDPL_MAX_COUNT_7_MAX_COUNT = 0;
static const uint32_t EDPL_MAX_COUNT_7_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_6_MAX_COUNT = 8;
static const uint32_t EDPL_MAX_COUNT_6_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_5_MAX_COUNT = 16;
static const uint32_t EDPL_MAX_COUNT_5_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_4_MAX_COUNT = 24;
static const uint32_t EDPL_MAX_COUNT_4_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_3_MAX_COUNT = 32;
static const uint32_t EDPL_MAX_COUNT_3_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_2_MAX_COUNT = 40;
static const uint32_t EDPL_MAX_COUNT_2_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_1_MAX_COUNT = 48;
static const uint32_t EDPL_MAX_COUNT_1_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_0_MAX_COUNT = 56;
static const uint32_t EDPL_MAX_COUNT_0_MAX_COUNT_LEN = 8;
// omi/reg00001.H

static const uint64_t ERROR_ACTION = 0x0c01176dull;

static const uint32_t ERROR_ACTION_11_ACTION = 16;
static const uint32_t ERROR_ACTION_11_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_10_ACTION = 20;
static const uint32_t ERROR_ACTION_10_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_9_ACTION = 24;
static const uint32_t ERROR_ACTION_9_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_8_ACTION = 28;
static const uint32_t ERROR_ACTION_8_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_7_ACTION = 32;
static const uint32_t ERROR_ACTION_7_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_6_ACTION = 36;
static const uint32_t ERROR_ACTION_6_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_5_ACTION = 40;
static const uint32_t ERROR_ACTION_5_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_4_ACTION = 44;
static const uint32_t ERROR_ACTION_4_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_3_ACTION = 48;
static const uint32_t ERROR_ACTION_3_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_2_ACTION = 52;
static const uint32_t ERROR_ACTION_2_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_1_ACTION = 56;
static const uint32_t ERROR_ACTION_1_ACTION_LEN = 4;
static const uint32_t ERROR_ACTION_0_ACTION = 60;
static const uint32_t ERROR_ACTION_0_ACTION_LEN = 4;
// omi/reg00001.H

static const uint64_t ERROR_CAPTURE = 0x0c011764ull;

static const uint32_t ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO = 1;
static const uint32_t ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO_LEN = 63;
// omi/reg00001.H

static const uint64_t ERROR_HOLD = 0x0c011763ull;

static const uint32_t ERROR_HOLD_47 = 16;
static const uint32_t ERROR_HOLD_46 = 17;
static const uint32_t ERROR_HOLD_45 = 18;
static const uint32_t ERROR_HOLD_44 = 19;
static const uint32_t ERROR_HOLD_43 = 20;
static const uint32_t ERROR_HOLD_42 = 21;
static const uint32_t ERROR_HOLD_41 = 22;
static const uint32_t ERROR_HOLD_40 = 23;
static const uint32_t ERROR_HOLD_39 = 24;
static const uint32_t ERROR_HOLD_38 = 25;
static const uint32_t ERROR_HOLD_37 = 26;
static const uint32_t ERROR_HOLD_36 = 27;
static const uint32_t ERROR_HOLD_35 = 28;
static const uint32_t ERROR_HOLD_34 = 29;
static const uint32_t ERROR_HOLD_33 = 30;
static const uint32_t ERROR_HOLD_32 = 31;
static const uint32_t ERROR_HOLD_31 = 32;
static const uint32_t ERROR_HOLD_30 = 33;
static const uint32_t ERROR_HOLD_29 = 34;
static const uint32_t ERROR_HOLD_28 = 35;
static const uint32_t ERROR_HOLD_27 = 36;
static const uint32_t ERROR_HOLD_26 = 37;
static const uint32_t ERROR_HOLD_25 = 38;
static const uint32_t ERROR_HOLD_24 = 39;
static const uint32_t ERROR_HOLD_23 = 40;
static const uint32_t ERROR_HOLD_22 = 41;
static const uint32_t ERROR_HOLD_21 = 42;
static const uint32_t ERROR_HOLD_20 = 43;
static const uint32_t ERROR_HOLD_19 = 44;
static const uint32_t ERROR_HOLD_18 = 45;
static const uint32_t ERROR_HOLD_17 = 46;
static const uint32_t ERROR_HOLD_16 = 47;
static const uint32_t ERROR_HOLD_15 = 48;
static const uint32_t ERROR_HOLD_14 = 49;
static const uint32_t ERROR_HOLD_13 = 50;
static const uint32_t ERROR_HOLD_12 = 51;
static const uint32_t ERROR_HOLD_11 = 52;
static const uint32_t ERROR_HOLD_10 = 53;
static const uint32_t ERROR_HOLD_09 = 54;
static const uint32_t ERROR_HOLD_08 = 55;
static const uint32_t ERROR_HOLD_07 = 56;
static const uint32_t ERROR_HOLD_06 = 57;
static const uint32_t ERROR_HOLD_05 = 58;
static const uint32_t ERROR_HOLD_04 = 59;
static const uint32_t ERROR_HOLD_03 = 60;
static const uint32_t ERROR_HOLD_02 = 61;
static const uint32_t ERROR_HOLD_01 = 62;
static const uint32_t ERROR_HOLD_00 = 63;
// omi/reg00001.H

static const uint64_t ERROR_MASK = 0x0c011762ull;

static const uint32_t ERROR_MASK_47 = 16;
static const uint32_t ERROR_MASK_46 = 17;
static const uint32_t ERROR_MASK_45 = 18;
static const uint32_t ERROR_MASK_44 = 19;
static const uint32_t ERROR_MASK_43 = 20;
static const uint32_t ERROR_MASK_42 = 21;
static const uint32_t ERROR_MASK_41 = 22;
static const uint32_t ERROR_MASK_40 = 23;
static const uint32_t ERROR_MASK_39 = 24;
static const uint32_t ERROR_MASK_38 = 25;
static const uint32_t ERROR_MASK_37 = 26;
static const uint32_t ERROR_MASK_36 = 27;
static const uint32_t ERROR_MASK_35 = 28;
static const uint32_t ERROR_MASK_34 = 29;
static const uint32_t ERROR_MASK_33 = 30;
static const uint32_t ERROR_MASK_32 = 31;
static const uint32_t ERROR_MASK_31 = 32;
static const uint32_t ERROR_MASK_30 = 33;
static const uint32_t ERROR_MASK_29 = 34;
static const uint32_t ERROR_MASK_28 = 35;
static const uint32_t ERROR_MASK_27 = 36;
static const uint32_t ERROR_MASK_26 = 37;
static const uint32_t ERROR_MASK_25 = 38;
static const uint32_t ERROR_MASK_24 = 39;
static const uint32_t ERROR_MASK_23 = 40;
static const uint32_t ERROR_MASK_22 = 41;
static const uint32_t ERROR_MASK_21 = 42;
static const uint32_t ERROR_MASK_20 = 43;
static const uint32_t ERROR_MASK_19 = 44;
static const uint32_t ERROR_MASK_18 = 45;
static const uint32_t ERROR_MASK_17 = 46;
static const uint32_t ERROR_MASK_16 = 47;
static const uint32_t ERROR_MASK_15 = 48;
static const uint32_t ERROR_MASK_14 = 49;
static const uint32_t ERROR_MASK_13 = 50;
static const uint32_t ERROR_MASK_12 = 51;
static const uint32_t ERROR_MASK_11 = 52;
static const uint32_t ERROR_MASK_10 = 53;
static const uint32_t ERROR_MASK_09 = 54;
static const uint32_t ERROR_MASK_08 = 55;
static const uint32_t ERROR_MASK_07 = 56;
static const uint32_t ERROR_MASK_06 = 57;
static const uint32_t ERROR_MASK_05 = 58;
static const uint32_t ERROR_MASK_04 = 59;
static const uint32_t ERROR_MASK_03 = 60;
static const uint32_t ERROR_MASK_02 = 61;
static const uint32_t ERROR_MASK_01 = 62;
static const uint32_t ERROR_MASK_00 = 63;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSLTWAT = 0x0c010d11ull;

static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU = 0;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN = 6;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN = 10;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN = 12;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN = 14;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN = 16;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN = 18;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN = 20;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN = 22;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_RESERVED_24_62 = 24;
static const uint32_t MC0_CHAN0_DSTL_DSLTWAT_RESERVED_24_62_LEN = 39;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLCFG = 0x0c010d0bull;

static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_TMPL0_ONLY = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_RESERVED_1 = 1;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_TMPL7_ENABLE = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_TMPL1_DIS = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_FAST_RD_DISABLE = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_RESERVED_5 = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_TMPL4_DISABLE = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS = 7;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_READ_THRESHOLD = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_READ_THRESHOLD_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_WR_TMP4_THRESHOLD = 16;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_RESERVED_20_23 = 20;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_RESERVED_20_23_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_WR_DBL_THRESHOLD = 24;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_CRITICAL_OW_DIS = 28;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_ENABLE_SPEC_ATTN = 29;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_ENABLE_HOST_ATTN = 30;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_DEBUG_EN = 31;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_DEBUG_LOCAL_SWAP = 32;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_DEBUG_PASSTHRU = 33;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_DEBUG_PASSTHRU_LEN = 11;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_WRAP_MODE_EN = 44;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH = 45;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_TIMEOUT_MODE = 49;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_TIMEOUT_MODE_LEN = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_MMIO_ADDRBIT_POS = 52;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_RESET_CREDITS = 57;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET = 58;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET = 59;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_CREDITS_ON_DEBUG_BUS = 60;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_RESERVED_61_63 = 61;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG_RESERVED_61_63_LEN = 3;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLCFG2 = 0x0c010d0eull;

static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING = 12;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET = 16;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET = 17;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE = 18;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE = 19;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED = 20;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED = 21;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN = 22;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN = 23;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT = 24;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT = 25;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP = 26;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP = 27;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR = 28;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR = 29;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE = 30;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE = 31;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_RESERVED_32_35 = 32;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_RESERVED_32_35_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS = 36;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT = 37;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT = 38;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS = 39;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE = 40;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET = 43;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT = 44;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_RESERVED_45 = 45;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL = 46;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_RESERVED_47_62 = 47;
static const uint32_t MC0_CHAN0_DSTL_DSTLCFG2_RESERVED_47_62_LEN = 16;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLCREDIT = 0x0c010d0aull;

static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT = 12;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT = 17;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN = 7;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_VC0_CREDIT_INIT = 28;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_VC1_CREDIT_INIT = 36;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT = 42;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL = 50;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL = 58;
static const uint32_t MC0_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN = 6;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLERRRPT = 0x0c010d0cull;

static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 1;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT = 7;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT = 9;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT = 10;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 11;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 12;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT = 13;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT = 14;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 15;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT = 16;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT = 17;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT = 18;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT = 19;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT = 20;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT = 21;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT = 22;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT = 23;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT = 24;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT = 25;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT = 26;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT = 27;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT = 28;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT = 29;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT = 30;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT = 31;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT = 32;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT = 33;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT = 34;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT = 35;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 36;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 37;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 38;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 39;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT = 40;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT = 41;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE = 62;
static const uint32_t MC0_CHAN0_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE = 63;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLFIR_RWX = 0x0c010d00ull;
static const uint64_t MC0_CHAN0_DSTL_DSTLFIR_WOX_AND = 0x0c010d01ull;
static const uint64_t MC0_CHAN0_DSTL_DSTLFIR_WOX_OR = 0x0c010d02ull;

static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION = 1;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT = 7;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_CMD_WRDATA_PARITY_ERROR = 9;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR = 10;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR = 11;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR = 12;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR = 13;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR = 14;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR = 15;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR = 16;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR = 17;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN = 18;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN = 19;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT = 22;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT = 23;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SPARE24 = 24;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_SPARE25 = 25;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_DECRYPT_ERR_INFO = 26;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_ENCRYPT_ERR_INFO = 29;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN = 4;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLFIRACT0 = 0x0c010d06ull;

static const uint32_t MC0_CHAN0_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 33;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLFIRMASK_RW = 0x0c010d03ull;
static const uint64_t MC0_CHAN0_DSTL_DSTLFIRMASK_WO_AND = 0x0c010d04ull;
static const uint64_t MC0_CHAN0_DSTL_DSTLFIRMASK_WO_OR = 0x0c010d05ull;

static const uint32_t MC0_CHAN0_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 33;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLFIRWOF = 0x0c010d08ull;

static const uint32_t MC0_CHAN0_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN = 33;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLINJ = 0x0c010d0dull;

static const uint32_t MC0_CHAN0_DSTL_DSTLINJ_ERR_INJ_TRIGGER = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLINJ_ERR_INJ_CONT_MODE = 1;
static const uint32_t MC0_CHAN0_DSTL_DSTLINJ_ERR_INJ_TYPE = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLINJ_RESERVED_4_15 = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLINJ_RESERVED_4_15_LEN = 12;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLPSAVE0 = 0x0c010d12ull;

static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE = 16;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH = 18;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE = 21;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT = 24;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL = 32;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL = 36;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_RESERVED_40_47 = 40;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE0_RESERVED_40_47_LEN = 8;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLPSAVE1 = 0x0c010d13ull;

static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_RESERVED_59_63 = 59;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE1_RESERVED_59_63_LEN = 5;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLPSAVE2 = 0x0c010d14ull;

static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_RESERVED_59_63 = 59;
static const uint32_t MC0_CHAN0_DSTL_DSTLPSAVE2_RESERVED_59_63_LEN = 5;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLSTATUS = 0x0c010d10ull;

static const uint32_t MC0_CHAN0_DSTL_DSTLSTATUS_A_FAIL_WOF = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLSTATUS_A_FAIL_WOF_LEN = 10;
static const uint32_t MC0_CHAN0_DSTL_DSTLSTATUS_B_FAIL_WOF = 10;
static const uint32_t MC0_CHAN0_DSTL_DSTLSTATUS_B_FAIL_WOF_LEN = 10;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_DSTL_DSTLTRACK = 0x0c010d0full;

static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE = 0;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE = 12;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE = 18;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE = 24;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE = 28;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW = 34;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN = 6;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW = 44;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN = 4;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW = 50;
static const uint32_t MC0_CHAN0_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN = 7;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLBADRESP = 0x0c010e10ull;

static const uint32_t MC0_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_VAL = 0;
static const uint32_t MC0_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE = 1;
static const uint32_t MC0_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD = 2;
static const uint32_t MC0_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_TAG = 3;
static const uint32_t MC0_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN = 6;
static const uint32_t MC0_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_VAL = 9;
static const uint32_t MC0_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE = 10;
static const uint32_t MC0_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD = 11;
static const uint32_t MC0_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_TAG = 12;
static const uint32_t MC0_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN = 6;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLCFG = 0x0c010e0bull;

static const uint32_t MC0_CHAN0_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE = 0;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE = 1;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_FAIL_CAPTURE_CONFIG = 2;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE = 4;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA = 5;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA_LEN = 2;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO = 7;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE = 8;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_LOWLAT_MISS_015_DELAY = 9;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN = 3;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_ET_DISABLE = 16;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE = 17;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE = 18;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_TEMPLATE1_ENABLE = 19;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_ENABLE = 20;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT = 21;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT_LEN = 3;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE = 24;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN = 7;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE = 32;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT = 33;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN = 3;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS = 36;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_DL_WIDTH_HALF_ENABLE = 37;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD = 40;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN = 4;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_CFG_ENABLE_SPEC_ATTN = 44;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_CFG_ENABLE_HOST_ATTN = 45;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_CFG_WRAP_MODE = 46;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_RESERVED_47 = 47;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE = 48;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_LOL_LFSR_RATE_SEL = 49;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN = 3;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_LOL_CAPTURE_CONFIG = 54;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_LAST_OPENCAPI_ENABLE = 56;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW = 57;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_PMU_SELECT_FAIL_RSP = 58;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_PMU_ENABLE = 59;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_PMU_SELECT_ALT_PERF = 60;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_CS_HW477424_DISABLE = 61;
static const uint32_t MC0_CHAN0_USTL_USTLCFG_CS_HW475333_DISABLE = 62;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLCFWOF = 0x0c010e15ull;

static const uint32_t MC0_CHAN0_USTL_USTLCFWOF_A_CHANFAIL_WOF = 0;
static const uint32_t MC0_CHAN0_USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN = 16;
static const uint32_t MC0_CHAN0_USTL_USTLCFWOF_B_CHANFAIL_WOF = 16;
static const uint32_t MC0_CHAN0_USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN = 16;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLDBG = 0x0c010e0dull;

static const uint32_t MC0_CHAN0_USTL_USTLDBG_ENABLE = 0;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_SEL_TOP = 8;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_SEL_WR_TOP = 9;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_SEL_BOT = 10;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_SEL_WR_BOT = 11;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_SEL_FLIT = 12;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_SEL_FLIT_CHANB = 13;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_SEL_MIRRORLOG_VLDS = 14;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_SPARE = 15;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_WAT_ENABLE0 = 16;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_WAT_ENABLE0_LEN = 2;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_WAT_ENABLE1 = 18;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_WAT_ENABLE1_LEN = 2;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_WAT_ENABLE2 = 20;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_WAT_ENABLE2_LEN = 2;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_WAT_ENABLE3 = 22;
static const uint32_t MC0_CHAN0_USTL_USTLDBG_WAT_ENABLE3_LEN = 2;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLERRPT = 0x0c010e16ull;

static const uint32_t MC0_CHAN0_USTL_USTLERRPT_WDF_CMT_PAR_ERR = 0;
static const uint32_t MC0_CHAN0_USTL_USTLERRPT_WDF_CMD_PAR_ERR = 1;
static const uint32_t MC0_CHAN0_USTL_USTLERRPT_WRT_NO_BUFF_ERR = 2;
static const uint32_t MC0_CHAN0_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR = 3;
static const uint32_t MC0_CHAN0_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR = 4;
static const uint32_t MC0_CHAN0_USTL_USTLERRPT_WDF_NO_BUFF_ERR = 5;
static const uint32_t MC0_CHAN0_USTL_USTLERRPT_RESERVED = 6;
static const uint32_t MC0_CHAN0_USTL_USTLERRPT_RESERVED_LEN = 10;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLERRRPT = 0x0c010e0eull;

static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT = 0;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 1;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 2;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT = 3;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT = 4;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 5;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 6;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT = 7;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT = 8;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT = 9;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT = 10;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT = 11;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT = 12;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT = 13;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT = 14;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT = 15;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 16;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT = 17;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT = 18;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT = 19;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT = 20;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT = 21;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT = 22;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 23;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT = 24;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT = 25;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT = 26;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT = 27;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT = 28;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT = 29;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT = 30;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA = 31;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT = 32;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT = 33;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT = 34;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT = 36;
static const uint32_t MC0_CHAN0_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT = 37;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLFAILMASK = 0x0c010e13ull;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLFIR_RWX = 0x0c010e00ull;
static const uint64_t MC0_CHAN0_USTL_USTLFIR_WOX_AND = 0x0c010e01ull;
static const uint64_t MC0_CHAN0_USTL_USTLFIR_WOX_OR = 0x0c010e02ull;

static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR = 0;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR = 1;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR = 2;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR = 3;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_HALF_SPEED_MODE = 4;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_HALF_SPEED_MODE = 5;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WDF_BUFFER_CE = 6;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WDF_BUFFER_UE = 7;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WDF_BUFFER_SUE = 8;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WDF_BUFFER_OVERRUN = 9;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WDF_TAG_PARITY_ERROR = 10;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR = 11;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR = 12;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR = 13;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_RESERVED_14 = 14;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 = 15;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WDF_CMT_PARITY_ERROR = 16;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_READ_SPARE_1 = 17;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_READ_SPARE_2 = 18;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR = 19;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WRT_BUFFER_CE = 20;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WRT_BUFFER_UE = 21;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WRT_BUFFER_SUE = 22;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR = 23;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR = 24;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 = 25;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_WRT_BUFF_ERR = 26;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP = 27;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP = 28;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER = 29;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER = 30;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP = 31;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP = 32;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER = 33;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER = 34;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR = 35;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR = 36;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR = 37;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR = 38;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL = 39;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL = 40;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS = 41;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS = 42;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO = 43;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO = 44;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE = 45;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE = 46;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_BAD_DATA = 47;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_BAD_DATA = 48;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR = 49;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR = 50;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR = 51;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR = 52;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR = 53;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR = 54;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR = 55;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR = 56;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_FATAL_REG_PARITY_ERROR = 57;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_RECOV_REG_PARITY_ERROR = 58;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO = 59;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO = 60;
static const uint32_t MC0_CHAN0_USTL_USTLFIR_SPARE_61 = 61;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLFIRACT0 = 0x0c010e06ull;

static const uint32_t MC0_CHAN0_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC0_CHAN0_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN = 62;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLFIRMASK_RW = 0x0c010e03ull;
static const uint64_t MC0_CHAN0_USTL_USTLFIRMASK_WO_AND = 0x0c010e04ull;
static const uint64_t MC0_CHAN0_USTL_USTLFIRMASK_WO_OR = 0x0c010e05ull;

static const uint32_t MC0_CHAN0_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC0_CHAN0_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN = 62;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLFIRWOF = 0x0c010e08ull;

static const uint32_t MC0_CHAN0_USTL_USTLFIRWOF_USTLFIRWOF_WOF = 0;
static const uint32_t MC0_CHAN0_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN = 62;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLINJ = 0x0c010e0cull;

static const uint32_t MC0_CHAN0_USTL_USTLINJ_FAIL_RESP_TYPE = 3;
static const uint32_t MC0_CHAN0_USTL_USTLINJ_FAIL_RESP_TYPE_LEN = 3;
static const uint32_t MC0_CHAN0_USTL_USTLINJ_FIR_INJECT = 8;
static const uint32_t MC0_CHAN0_USTL_USTLINJ_FIR_INJECT_LEN = 5;
static const uint32_t MC0_CHAN0_USTL_USTLINJ_US_DATA = 20;
static const uint32_t MC0_CHAN0_USTL_USTLINJ_US_DATA_LEN = 3;
static const uint32_t MC0_CHAN0_USTL_USTLINJ_CHAN_SEL = 24;
static const uint32_t MC0_CHAN0_USTL_USTLINJ_DATA_DW_SEL = 25;
static const uint32_t MC0_CHAN0_USTL_USTLINJ_US_DATA_ERR_EN = 26;
static const uint32_t MC0_CHAN0_USTL_USTLINJ_ONE_SHOT = 27;
static const uint32_t MC0_CHAN0_USTL_USTLINJ_DATA_OUT = 28;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLLOLDROP = 0x0c010e11ull;

static const uint32_t MC0_CHAN0_USTL_USTLLOLDROP_A_DROP_REASON = 0;
static const uint32_t MC0_CHAN0_USTL_USTLLOLDROP_A_DROP_REASON_LEN = 16;
static const uint32_t MC0_CHAN0_USTL_USTLLOLDROP_B_DROP_REASON = 32;
static const uint32_t MC0_CHAN0_USTL_USTLLOLDROP_B_DROP_REASON_LEN = 16;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLLOLMASK = 0x0c010e12ull;

static const uint32_t MC0_CHAN0_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t MC0_CHAN0_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN = 16;
static const uint32_t MC0_CHAN0_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK = 32;
static const uint32_t MC0_CHAN0_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN = 16;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLMCHWFM = 0x0c010e0full;

static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_ENABLE = 0;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_FAIL_THRESH = 1;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_FAIL_THRESH_LEN = 6;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_WINDOW_SIZE = 7;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_WINDOW_SIZE_LEN = 7;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_TSCALE = 14;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_TSCALE_LEN = 2;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_SCOM_COMMAND_VALID = 16;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_SCOM_COMMAND = 17;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT = 18;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_HWFM_STATUS = 19;
static const uint32_t MC0_CHAN0_USTL_USTLMCHWFM_HWFM_STATUS_LEN = 4;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLOCAPIERROR = 0x0c010e14ull;

static const uint32_t MC0_CHAN0_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID = 0;
static const uint32_t MC0_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE = 1;
static const uint32_t MC0_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN = 8;
static const uint32_t MC0_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION = 9;
static const uint32_t MC0_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN = 31;
// omi/reg00001.H

static const uint64_t MC0_CHAN0_USTL_USTLSTATUS = 0x0c010e0aull;

static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_LOL_MODE = 0;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_LOL_MODE = 1;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD = 2;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR = 3;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD = 4;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR = 5;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD = 6;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR = 7;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD = 8;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR = 9;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_FAIL_RESP = 10;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_FAIL_RESP_LEN = 4;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_WAT_FIRED = 24;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_WAT_FIRED = 25;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY = 32;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR = 33;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR = 34;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR = 35;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR = 36;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR = 37;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 38;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP = 39;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP = 40;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE = 41;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY = 42;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY = 43;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR = 44;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR = 45;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR = 46;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR = 47;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR = 48;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 49;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP = 50;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP = 51;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE = 52;
static const uint32_t MC0_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY = 53;
// omi/reg00001.H

static const uint64_t MC0_CHAN1_DSTL_DSLTWAT = 0x0c010d51ull;

static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU = 0;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN = 6;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN = 10;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN = 12;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN = 14;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN = 16;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN = 18;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN = 20;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN = 22;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_RESERVED_24_62 = 24;
static const uint32_t MC0_CHAN1_DSTL_DSLTWAT_RESERVED_24_62_LEN = 39;
// omi/reg00001.H

static const uint64_t MC0_CHAN1_DSTL_DSTLCFG = 0x0c010d4bull;

static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_TMPL0_ONLY = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_RESERVED_1 = 1;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_TMPL7_ENABLE = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_TMPL1_DIS = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_FAST_RD_DISABLE = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_RESERVED_5 = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_TMPL4_DISABLE = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS = 7;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_READ_THRESHOLD = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_READ_THRESHOLD_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_WR_TMP4_THRESHOLD = 16;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_RESERVED_20_23 = 20;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_RESERVED_20_23_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_WR_DBL_THRESHOLD = 24;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_CRITICAL_OW_DIS = 28;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_ENABLE_SPEC_ATTN = 29;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_ENABLE_HOST_ATTN = 30;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_DEBUG_EN = 31;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_DEBUG_LOCAL_SWAP = 32;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_DEBUG_PASSTHRU = 33;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_DEBUG_PASSTHRU_LEN = 11;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_WRAP_MODE_EN = 44;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH = 45;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_TIMEOUT_MODE = 49;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_TIMEOUT_MODE_LEN = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_MMIO_ADDRBIT_POS = 52;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_RESET_CREDITS = 57;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET = 58;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET = 59;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_CREDITS_ON_DEBUG_BUS = 60;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_RESERVED_61_63 = 61;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG_RESERVED_61_63_LEN = 3;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLCFG2 = 0x0c010d4eull;

static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING = 12;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET = 16;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET = 17;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE = 18;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE = 19;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED = 20;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED = 21;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN = 22;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN = 23;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT = 24;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT = 25;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP = 26;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP = 27;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR = 28;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR = 29;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE = 30;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE = 31;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_RESERVED_32_35 = 32;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_RESERVED_32_35_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS = 36;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT = 37;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT = 38;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS = 39;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE = 40;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET = 43;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT = 44;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_RESERVED_45 = 45;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL = 46;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_RESERVED_47_62 = 47;
static const uint32_t MC0_CHAN1_DSTL_DSTLCFG2_RESERVED_47_62_LEN = 16;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLCREDIT = 0x0c010d4aull;

static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT = 12;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT = 17;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN = 7;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_VC0_CREDIT_INIT = 28;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_VC1_CREDIT_INIT = 36;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT = 42;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL = 50;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL = 58;
static const uint32_t MC0_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN = 6;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLERRRPT = 0x0c010d4cull;

static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 1;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT = 7;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT = 9;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT = 10;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 11;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 12;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT = 13;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT = 14;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 15;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT = 16;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT = 17;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT = 18;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT = 19;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT = 20;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT = 21;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT = 22;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT = 23;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT = 24;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT = 25;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT = 26;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT = 27;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT = 28;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT = 29;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT = 30;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT = 31;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT = 32;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT = 33;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT = 34;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT = 35;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 36;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 37;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 38;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 39;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT = 40;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT = 41;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE = 62;
static const uint32_t MC0_CHAN1_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE = 63;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLFIR_RWX = 0x0c010d40ull;
static const uint64_t MC0_CHAN1_DSTL_DSTLFIR_WOX_AND = 0x0c010d41ull;
static const uint64_t MC0_CHAN1_DSTL_DSTLFIR_WOX_OR = 0x0c010d42ull;

static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION = 1;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT = 7;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_CMD_WRDATA_PARITY_ERROR = 9;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR = 10;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR = 11;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR = 12;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR = 13;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR = 14;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR = 15;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR = 16;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR = 17;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN = 18;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN = 19;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT = 22;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT = 23;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SPARE24 = 24;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_SPARE25 = 25;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_DECRYPT_ERR_INFO = 26;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_ENCRYPT_ERR_INFO = 29;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN = 4;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLFIRACT0 = 0x0c010d46ull;

static const uint32_t MC0_CHAN1_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 33;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLFIRMASK_RW = 0x0c010d43ull;
static const uint64_t MC0_CHAN1_DSTL_DSTLFIRMASK_WO_AND = 0x0c010d44ull;
static const uint64_t MC0_CHAN1_DSTL_DSTLFIRMASK_WO_OR = 0x0c010d45ull;

static const uint32_t MC0_CHAN1_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 33;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLFIRWOF = 0x0c010d48ull;

static const uint32_t MC0_CHAN1_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN = 33;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLINJ = 0x0c010d4dull;

static const uint32_t MC0_CHAN1_DSTL_DSTLINJ_ERR_INJ_TRIGGER = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLINJ_ERR_INJ_CONT_MODE = 1;
static const uint32_t MC0_CHAN1_DSTL_DSTLINJ_ERR_INJ_TYPE = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLINJ_RESERVED_4_15 = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLINJ_RESERVED_4_15_LEN = 12;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLPSAVE0 = 0x0c010d52ull;

static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE = 16;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH = 18;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE = 21;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT = 24;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL = 32;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL = 36;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_RESERVED_40_47 = 40;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE0_RESERVED_40_47_LEN = 8;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLPSAVE1 = 0x0c010d53ull;

static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_RESERVED_59_63 = 59;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE1_RESERVED_59_63_LEN = 5;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLPSAVE2 = 0x0c010d54ull;

static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_RESERVED_59_63 = 59;
static const uint32_t MC0_CHAN1_DSTL_DSTLPSAVE2_RESERVED_59_63_LEN = 5;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLSTATUS = 0x0c010d50ull;

static const uint32_t MC0_CHAN1_DSTL_DSTLSTATUS_A_FAIL_WOF = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLSTATUS_A_FAIL_WOF_LEN = 10;
static const uint32_t MC0_CHAN1_DSTL_DSTLSTATUS_B_FAIL_WOF = 10;
static const uint32_t MC0_CHAN1_DSTL_DSTLSTATUS_B_FAIL_WOF_LEN = 10;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_DSTL_DSTLTRACK = 0x0c010d4full;

static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE = 0;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE = 12;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE = 18;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE = 24;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE = 28;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW = 34;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN = 6;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW = 44;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN = 4;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW = 50;
static const uint32_t MC0_CHAN1_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN = 7;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLBADRESP = 0x0c010e50ull;

static const uint32_t MC0_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_VAL = 0;
static const uint32_t MC0_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE = 1;
static const uint32_t MC0_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD = 2;
static const uint32_t MC0_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_TAG = 3;
static const uint32_t MC0_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN = 6;
static const uint32_t MC0_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_VAL = 9;
static const uint32_t MC0_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE = 10;
static const uint32_t MC0_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD = 11;
static const uint32_t MC0_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_TAG = 12;
static const uint32_t MC0_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN = 6;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLCFG = 0x0c010e4bull;

static const uint32_t MC0_CHAN1_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE = 0;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE = 1;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_FAIL_CAPTURE_CONFIG = 2;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE = 4;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA = 5;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA_LEN = 2;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO = 7;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE = 8;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_LOWLAT_MISS_015_DELAY = 9;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN = 3;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_ET_DISABLE = 16;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE = 17;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE = 18;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_TEMPLATE1_ENABLE = 19;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_ENABLE = 20;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT = 21;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT_LEN = 3;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE = 24;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN = 7;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE = 32;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT = 33;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN = 3;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS = 36;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_DL_WIDTH_HALF_ENABLE = 37;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD = 40;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN = 4;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_CFG_ENABLE_SPEC_ATTN = 44;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_CFG_ENABLE_HOST_ATTN = 45;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_CFG_WRAP_MODE = 46;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_RESERVED_47 = 47;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE = 48;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_LOL_LFSR_RATE_SEL = 49;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN = 3;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_LOL_CAPTURE_CONFIG = 54;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_LAST_OPENCAPI_ENABLE = 56;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW = 57;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_PMU_SELECT_FAIL_RSP = 58;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_PMU_ENABLE = 59;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_PMU_SELECT_ALT_PERF = 60;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_CS_HW477424_DISABLE = 61;
static const uint32_t MC0_CHAN1_USTL_USTLCFG_CS_HW475333_DISABLE = 62;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLCFWOF = 0x0c010e55ull;

static const uint32_t MC0_CHAN1_USTL_USTLCFWOF_A_CHANFAIL_WOF = 0;
static const uint32_t MC0_CHAN1_USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN = 16;
static const uint32_t MC0_CHAN1_USTL_USTLCFWOF_B_CHANFAIL_WOF = 16;
static const uint32_t MC0_CHAN1_USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN = 16;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLDBG = 0x0c010e4dull;

static const uint32_t MC0_CHAN1_USTL_USTLDBG_ENABLE = 0;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_SEL_TOP = 8;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_SEL_WR_TOP = 9;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_SEL_BOT = 10;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_SEL_WR_BOT = 11;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_SEL_FLIT = 12;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_SEL_FLIT_CHANB = 13;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_SEL_MIRRORLOG_VLDS = 14;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_SPARE = 15;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_WAT_ENABLE0 = 16;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_WAT_ENABLE0_LEN = 2;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_WAT_ENABLE1 = 18;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_WAT_ENABLE1_LEN = 2;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_WAT_ENABLE2 = 20;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_WAT_ENABLE2_LEN = 2;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_WAT_ENABLE3 = 22;
static const uint32_t MC0_CHAN1_USTL_USTLDBG_WAT_ENABLE3_LEN = 2;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLERRPT = 0x0c010e56ull;

static const uint32_t MC0_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR = 0;
static const uint32_t MC0_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR = 1;
static const uint32_t MC0_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR = 2;
static const uint32_t MC0_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR = 3;
static const uint32_t MC0_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR = 4;
static const uint32_t MC0_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR = 5;
static const uint32_t MC0_CHAN1_USTL_USTLERRPT_RESERVED = 6;
static const uint32_t MC0_CHAN1_USTL_USTLERRPT_RESERVED_LEN = 10;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLERRRPT = 0x0c010e4eull;

static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT = 0;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 1;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 2;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT = 3;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT = 4;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 5;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 6;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT = 7;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT = 8;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT = 9;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT = 10;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT = 11;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT = 12;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT = 13;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT = 14;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT = 15;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 16;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT = 17;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT = 18;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT = 19;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT = 20;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT = 21;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT = 22;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 23;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT = 24;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT = 25;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT = 26;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT = 27;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT = 28;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT = 29;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT = 30;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA = 31;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT = 32;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT = 33;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT = 34;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT = 36;
static const uint32_t MC0_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT = 37;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLFAILMASK = 0x0c010e53ull;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLFIR_RWX = 0x0c010e40ull;
static const uint64_t MC0_CHAN1_USTL_USTLFIR_WOX_AND = 0x0c010e41ull;
static const uint64_t MC0_CHAN1_USTL_USTLFIR_WOX_OR = 0x0c010e42ull;

static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR = 0;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR = 1;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR = 2;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR = 3;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE = 4;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE = 5;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE = 6;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE = 7;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE = 8;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN = 9;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR = 10;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR = 11;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR = 12;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR = 13;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_RESERVED_14 = 14;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 = 15;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR = 16;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_READ_SPARE_1 = 17;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_READ_SPARE_2 = 18;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR = 19;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE = 20;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE = 21;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE = 22;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR = 23;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR = 24;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 = 25;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR = 26;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP = 27;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP = 28;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER = 29;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER = 30;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP = 31;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP = 32;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER = 33;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER = 34;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR = 35;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR = 36;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR = 37;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR = 38;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL = 39;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL = 40;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS = 41;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS = 42;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO = 43;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO = 44;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE = 45;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE = 46;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA = 47;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA = 48;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR = 49;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR = 50;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR = 51;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR = 52;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR = 53;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR = 54;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR = 55;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR = 56;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR = 57;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR = 58;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO = 59;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO = 60;
static const uint32_t MC0_CHAN1_USTL_USTLFIR_SPARE_61 = 61;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLFIRACT0 = 0x0c010e46ull;

static const uint32_t MC0_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC0_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN = 62;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLFIRMASK_RW = 0x0c010e43ull;
static const uint64_t MC0_CHAN1_USTL_USTLFIRMASK_WO_AND = 0x0c010e44ull;
static const uint64_t MC0_CHAN1_USTL_USTLFIRMASK_WO_OR = 0x0c010e45ull;

static const uint32_t MC0_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC0_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN = 62;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLFIRWOF = 0x0c010e48ull;

static const uint32_t MC0_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF = 0;
static const uint32_t MC0_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN = 62;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLINJ = 0x0c010e4cull;

static const uint32_t MC0_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE = 3;
static const uint32_t MC0_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE_LEN = 3;
static const uint32_t MC0_CHAN1_USTL_USTLINJ_FIR_INJECT = 8;
static const uint32_t MC0_CHAN1_USTL_USTLINJ_FIR_INJECT_LEN = 5;
static const uint32_t MC0_CHAN1_USTL_USTLINJ_US_DATA = 20;
static const uint32_t MC0_CHAN1_USTL_USTLINJ_US_DATA_LEN = 3;
static const uint32_t MC0_CHAN1_USTL_USTLINJ_CHAN_SEL = 24;
static const uint32_t MC0_CHAN1_USTL_USTLINJ_DATA_DW_SEL = 25;
static const uint32_t MC0_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN = 26;
static const uint32_t MC0_CHAN1_USTL_USTLINJ_ONE_SHOT = 27;
static const uint32_t MC0_CHAN1_USTL_USTLINJ_DATA_OUT = 28;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLLOLDROP = 0x0c010e51ull;

static const uint32_t MC0_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON = 0;
static const uint32_t MC0_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON_LEN = 16;
static const uint32_t MC0_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON = 32;
static const uint32_t MC0_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON_LEN = 16;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLLOLMASK = 0x0c010e52ull;

static const uint32_t MC0_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t MC0_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN = 16;
static const uint32_t MC0_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK = 32;
static const uint32_t MC0_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN = 16;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLMCHWFM = 0x0c010e4full;

static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_ENABLE = 0;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH = 1;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH_LEN = 6;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE = 7;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE_LEN = 7;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_TSCALE = 14;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_TSCALE_LEN = 2;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID = 16;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND = 17;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT = 18;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS = 19;
static const uint32_t MC0_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS_LEN = 4;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLOCAPIERROR = 0x0c010e54ull;

static const uint32_t MC0_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID = 0;
static const uint32_t MC0_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE = 1;
static const uint32_t MC0_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN = 8;
static const uint32_t MC0_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION = 9;
static const uint32_t MC0_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN = 31;
// omi/reg00002.H

static const uint64_t MC0_CHAN1_USTL_USTLSTATUS = 0x0c010e4aull;

static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE = 0;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE = 1;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD = 2;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR = 3;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD = 4;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR = 5;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD = 6;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR = 7;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD = 8;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR = 9;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_FAIL_RESP = 10;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_FAIL_RESP_LEN = 4;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED = 24;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED = 25;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY = 32;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR = 33;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR = 34;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR = 35;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR = 36;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR = 37;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 38;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP = 39;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP = 40;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE = 41;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY = 42;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY = 43;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR = 44;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR = 45;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR = 46;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR = 47;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR = 48;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 49;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP = 50;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP = 51;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE = 52;
static const uint32_t MC0_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY = 53;
// omi/reg00002.H

static const uint64_t MC0_MISC_CLKMON_MONM_CLKRATIO = 0x0c010ff0ull;

static const uint32_t MC0_MISC_CLKMON_MONM_CLKRATIO_RATIO = 0;
static const uint32_t MC0_MISC_CLKMON_MONM_CLKRATIO_RATIO_LEN = 12;
static const uint32_t MC0_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE = 12;
static const uint32_t MC0_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE = 13;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_AACR = 0x0c010f29ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_AACR_BUFFER = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_AACR_ADDRESS = 1;
static const uint32_t MC0_MISC_MBA_SCOMFIR_AACR_ADDRESS_LEN = 10;
static const uint32_t MC0_MISC_MBA_SCOMFIR_AACR_AUTOINC = 11;
static const uint32_t MC0_MISC_MBA_SCOMFIR_AACR_ECCGEN = 12;
static const uint32_t MC0_MISC_MBA_SCOMFIR_AACR_CHANNEL = 13;
static const uint32_t MC0_MISC_MBA_SCOMFIR_AACR_CHANNEL_LEN = 2;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_AADR = 0x0c010f2aull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_AADR_AADR_DATA_LEN = 64;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_AAER = 0x0c010f2bull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC_LEN = 9;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_DBG0_SCOM0Q = 0x0c010f94ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63 = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63_LEN = 64;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_DBG0_SCOM1Q = 0x0c010f95ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87 = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87_LEN = 24;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED = 24;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED_LEN = 40;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_DBG1_SCOM0Q = 0x0c010f96ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN = 64;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_DBG1_SCOM1Q = 0x0c010f97ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87 = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87_LEN = 24;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED = 24;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED_LEN = 40;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q = 0x0c010fe8ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01 = 1;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01_LEN = 11;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23 = 12;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23_LEN = 11;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI = 23;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44 = 24;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44_LEN = 21;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER = 45;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET = 46;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM = 47;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q = 0x0c010fe9ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT = 1;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL = 3;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL_LEN = 20;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL = 23;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL_LEN = 20;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL = 43;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL_LEN = 20;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63 = 63;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_DBGCFG2Q = 0x0c010feaull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL_LEN = 20;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL = 20;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL_LEN = 20;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL = 40;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL_LEN = 20;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63 = 60;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63_LEN = 4;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q = 0x0c010febull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL_LEN = 20;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL = 20;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22 = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL = 23;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25 = 25;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL = 26;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28 = 28;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL = 29;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32 = 31;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE = 33;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE = 37;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE = 41;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE = 45;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE_LEN = 6;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE = 51;
static const uint32_t MC0_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE_LEN = 8;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ = 0x0c010fe7ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT = 1;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT = 5;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT = 6;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT = 7;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT = 8;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT = 9;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT = 10;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT = 11;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT = 12;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT = 13;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT = 14;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT = 15;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT = 16;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT = 17;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT = 18;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT = 19;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT = 20;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBCFGQ = 0x0c010fe0ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER = 10;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN = 62;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN = 63;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRACT0 = 0x0c010f06ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0 = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0_LEN = 14;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRMASK_RW = 0x0c010f03ull;
static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_AND = 0x0c010f04ull;
static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_OR = 0x0c010f05ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK_LEN = 14;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_RWX = 0x0c010f00ull;
static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_AND = 0x0c010f01ull;
static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_OR = 0x0c010f02ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE = 1;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3 = 3;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT = 5;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT = 6;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT = 7;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT = 8;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT = 9;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT = 10;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT = 11;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR = 12;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE = 13;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRWOF = 0x0c010f08ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF_LEN = 14;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCBPARMQ = 0x0c010fafull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN = 59;
// omi/reg00002.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG = 0x0c010f98ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE = 1;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE = 3;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN0 = 0x0c010fa4ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN1 = 0x0c010fa5ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN2 = 0x0c010fa6ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN3 = 0x0c010fa7ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN3_N = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN3_N_LEN = 16;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE = 16;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT = 17;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT_LEN = 3;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL = 0x0c010f99ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM = 1;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER = 3;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT = 8;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT = 10;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT = 12;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL = 14;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15 = 15;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT = 16;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18 = 18;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT = 19;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21 = 21;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24 = 24;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT = 25;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27 = 27;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE = 28;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT = 29;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT = 33;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT_LEN = 7;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT = 40;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT_LEN = 5;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT = 45;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG = 49;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG_LEN = 9;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59 = 58;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59_LEN = 2;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE = 60;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET = 61;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS = 62;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63 = 63;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0 = 0x0c010f9aull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN = 6;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE = 6;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN = 8;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT = 16;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT = 20;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT = 24;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT = 28;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT = 32;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN = 4;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT = 36;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN = 4;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATDATA1 = 0x0c010f9bull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A_LEN = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A_LEN = 22;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATDATA2 = 0x0c010f9cull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B_LEN = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B_LEN = 22;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATDATA3 = 0x0c010f9dull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A_LEN = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A_LEN = 22;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATDATA4 = 0x0c010f9eull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN = 22;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATDATA5 = 0x0c010f9full;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A_LEN = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A_LEN = 22;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATDATA6 = 0x0c010fa0ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN = 22;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATDATA7 = 0x0c010fa1ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A_LEN = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A_LEN = 22;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATDATA8 = 0x0c010fa2ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B = 22;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN = 22;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_MCWATDATA9 = 0x0c010fa3ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN = 46;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL = 47;
static const uint32_t MC0_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN = 17;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_SPARE = 0x0c010f0full;

static const uint32_t MC0_MISC_MBA_SCOMFIR_SPARE_SPARE = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_SPARE_SPARE_LEN = 8;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_WATCFG0AQ = 0x0c010f80ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN = 48;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_WATCFG0BQ = 0x0c010f81ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA_LEN = 44;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL = 44;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL_LEN = 17;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_WATCFG0CQ = 0x0c010f82ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB_LEN = 44;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_WATCFG0DQ = 0x0c010f83ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA_LEN = 44;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_WATCFG0EQ = 0x0c010f84ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB_LEN = 44;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_WATCFG1AQ = 0x0c010f85ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL_LEN = 48;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_WATCFG1BQ = 0x0c010f86ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA_LEN = 44;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL = 44;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL_LEN = 17;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_WATCFG1CQ = 0x0c010f87ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB_LEN = 44;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_WATCFG1DQ = 0x0c010f88ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA_LEN = 44;
// omi/reg00003.H

static const uint64_t MC0_MISC_MBA_SCOMFIR_WATCFG1EQ = 0x0c010f89ull;

static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB = 0;
static const uint32_t MC0_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB_LEN = 44;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_AACR = 0x0c010c2cull;

static const uint32_t MC0_PBI01_SCOMFIR_AACR_BUFFER = 0;
static const uint32_t MC0_PBI01_SCOMFIR_AACR_ADDRESS = 1;
static const uint32_t MC0_PBI01_SCOMFIR_AACR_ADDRESS_LEN = 9;
static const uint32_t MC0_PBI01_SCOMFIR_AACR_AUTOINC = 10;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_AADR = 0x0c010c2dull;

static const uint32_t MC0_PBI01_SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t MC0_PBI01_SCOMFIR_AADR_AADR_DATA_LEN = 64;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_AAER = 0x0c010c2eull;

static const uint32_t MC0_PBI01_SCOMFIR_AAER_AAER_TAG_ECC = 0;
static const uint32_t MC0_PBI01_SCOMFIR_AAER_AAER_TAG_ECC_LEN = 9;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCERPT0 = 0x0c010c1eull;

static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR = 5;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR = 9;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR = 10;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR = 11;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR = 12;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR = 13;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR = 14;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR = 17;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR = 18;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR = 20;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR = 21;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR = 22;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR = 23;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR = 29;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR = 30;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR = 31;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR = 32;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR = 33;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR = 38;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR = 39;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR = 40;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR = 41;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR = 42;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR = 43;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR = 44;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR = 45;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR = 46;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR = 47;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR = 48;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR = 49;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 = 51;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR = 52;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 = 53;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR = 54;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 = 55;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR = 56;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 = 57;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR = 58;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR = 59;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR = 60;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR = 61;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCERPT1 = 0x0c010c1full;

static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT = 23;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT = 33;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT = 34;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q = 44;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q_LEN = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q = 51;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q_LEN = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3 = 60;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3 = 61;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3 = 62;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3 = 63;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCERPT2 = 0x0c010c1aull;

static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR = 5;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR = 9;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE = 11;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE = 12;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT = 13;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT = 14;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR = 17;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR = 18;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT = 20;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT = 21;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT = 22;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT = 23;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT = 25;
static const uint32_t MC0_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT = 26;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGP0 = 0x0c010c0aull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_0_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE = 25;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP = 40;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION = 43;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE = 46;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE = 54;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN = 8;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGP0A = 0x0c010c0eull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21 = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21_LEN = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_SMF_VALID = 22;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGP0E = 0x0c010c16ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0E_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS = 21;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS_LEN = 19;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGP1 = 0x0c010c0bull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_1_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE = 25;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE_LEN = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP = 40;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP_LEN = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION = 43;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION_LEN = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE = 46;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE_LEN = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE = 54;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE_LEN = 8;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGP1A = 0x0c010c0full;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21 = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21_LEN = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_SMF_VALID = 22;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGP1E = 0x0c010c17ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1E_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS = 21;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN = 19;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGPM0 = 0x0c010c20ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE = 25;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE_LEN = 15;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGPM0A = 0x0c010c21ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21 = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID = 22;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGPM0E = 0x0c010c1cull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0E_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS = 21;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS_LEN = 19;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGPM1 = 0x0c010c30ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE = 25;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE_LEN = 15;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGPM1A = 0x0c010c31ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21 = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21_LEN = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID = 22;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGPM1E = 0x0c010c1dull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1E_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS = 21;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS_LEN = 19;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGPR0 = 0x0c010c0cull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS_LEN = 31;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS = 33;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS_LEN = 31;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFGPR1 = 0x0c010c0dull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS_LEN = 31;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS = 33;
static const uint32_t MC0_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS_LEN = 31;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFIR_RWX = 0x0c010c00ull;
static const uint64_t MC0_PBI01_SCOMFIR_MCFIR_WOX_AND = 0x0c010c01ull;
static const uint64_t MC0_PBI01_SCOMFIR_MCFIR_WOX_OR = 0x0c010c02ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 = 5;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_RESERVED_6 = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_RESERVED_7 = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_RESERVED_9 = 9;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_RESERVED_10 = 10;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_MCS_WAT0 = 11;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_MCS_WAT1 = 12;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_MCS_WAT2 = 13;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_MCS_WAT3 = 14;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR = 17;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_RESERVED_18 = 18;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_RESERVED_19 = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_RESERVED_20 = 20;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_RESERVED_21 = 21;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS = 22;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIR_RESERVED_23 = 23;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFIRACT0 = 0x0c010c06ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN = 24;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFIRMASK_RW = 0x0c010c03ull;
static const uint64_t MC0_PBI01_SCOMFIR_MCFIRMASK_WO_AND = 0x0c010c04ull;
static const uint64_t MC0_PBI01_SCOMFIR_MCFIRMASK_WO_OR = 0x0c010c05ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK_LEN = 24;
// omi/reg00003.H

static const uint64_t MC0_PBI01_SCOMFIR_MCFIRWOF = 0x0c010c08ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF_LEN = 24;
// omi/reg00004.H

static const uint64_t MC0_PBI01_SCOMFIR_MCLFSR = 0x0c010c14ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT_LEN = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCLFSR_SERVED_2_4 = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCLFSR_SERVED_2_4_LEN = 3;
// omi/reg00004.H

static const uint64_t MC0_PBI01_SCOMFIR_MCMODE0 = 0x0c010c11ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_RESERVED_4 = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID = 5;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND = 9;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND = 10;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_RESERVED_11 = 11;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC = 12;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_RESERVED_13 = 13;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT = 14;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN = 10;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE = 25;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY = 32;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE = 36;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS = 37;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH = 40;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63 = 41;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63_LEN = 23;
// omi/reg00004.H

static const uint64_t MC0_PBI01_SCOMFIR_MCMODE1 = 0x0c010c12ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN = 10;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT = 10;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS = 11;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS = 17;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY = 18;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN = 9;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH = 28;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS = 32;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP = 33;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_CI = 52;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_CI_LEN = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS = 54;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_RESERVED_60 = 60;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS = 61;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW = 62;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE1_RESERVED_63 = 63;
// omi/reg00004.H

static const uint64_t MC0_PBI01_SCOMFIR_MCMODE2 = 0x0c010c13ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0 = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0_LEN = 13;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15 = 14;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15_LEN = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM = 17;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22 = 18;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22_LEN = 5;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR = 23;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES_LEN = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH = 40;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH_LEN = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN = 44;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN = 45;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52 = 46;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52_LEN = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE = 53;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE = 54;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE = 55;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE = 56;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63 = 57;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63_LEN = 7;
// omi/reg00004.H

static const uint64_t MC0_PBI01_SCOMFIR_MCMODE3 = 0x0c010c2full;

static const uint32_t MC0_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10 = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10_LEN = 11;
// omi/reg00004.H

static const uint64_t MC0_PBI01_SCOMFIR_MCPERF1 = 0x0c010c10ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_DISABLE_FASTPATH = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT = 5;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH = 10;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT = 17;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST = 21;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE = 22;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH = 23;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE = 30;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE = 32;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN = 5;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD = 37;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE = 38;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN = 5;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_RESERVED_43_63 = 43;
static const uint32_t MC0_PBI01_SCOMFIR_MCPERF1_RESERVED_43_63_LEN = 21;
// omi/reg00004.H

static const uint64_t MC0_PBI01_SCOMFIR_MCSYNC = 0x0c010c15ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCSYNC_CHANNEL_SELECT = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCSYNC_CHANNEL_SELECT_LEN = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCSYNC_SYNC_TYPE = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCSYNC_SYNC_TYPE_LEN = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCSYNC_SYNC_GO = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCSYNC_SYNC_RESERVED = 17;
static const uint32_t MC0_PBI01_SCOMFIR_MCSYNC_SYNC_RESERVED_LEN = 8;
// omi/reg00004.H

static const uint64_t MC0_PBI01_SCOMFIR_MCTO = 0x0c010c1bull;

static const uint32_t MC0_PBI01_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_RPT_HANG_SELECT = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_RPT_HANG_SELECT_LEN = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_RESERVED_4 = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_CL_TIMEOUT_VALUE = 5;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_CL_TIMEOUT_VALUE_LEN = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_LOCAL_HANG_COMP = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_LOCAL_HANG_COMP_LEN = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_HANG_COMP = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_HANG_COMP_LEN = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG = 32;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG = 33;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_ENABLE_APO_HANG = 34;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_ENABLE_CLIB_HANG = 35;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG = 36;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE = 37;
static const uint32_t MC0_PBI01_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE_LEN = 3;
// omi/reg00004.H

static const uint64_t MC0_PBI01_SCOMFIR_MCWATACT = 0x0c010c18ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION = 1;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION = 2;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION = 3;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS = 4;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS = 5;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS = 6;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH = 8;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH = 9;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH = 10;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH = 11;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH = 12;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH = 13;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH = 14;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH = 15;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT = 16;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT = 17;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT = 18;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT = 19;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 = 20;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 = 21;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 = 22;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 = 23;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_RESERVED_36_47 = 24;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATACT_RESERVED_36_47_LEN = 16;
// omi/reg00004.H

static const uint64_t MC0_PBI01_SCOMFIR_MCWATCNTL2 = 0x0c010c19ull;

static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL0 = 0;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL0_LEN = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL1 = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL1_LEN = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL2 = 14;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL2_LEN = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL3 = 21;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL3_LEN = 7;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_RESERVED_28_49 = 28;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_RESERVED_28_49_LEN = 22;
static const uint32_t MC0_PBI01_SCOMFIR_MCWATCNTL2_CL_EARLY_HANG_MODE = 50;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSLTWAT = 0x0c010d11ull;

static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU = 0;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN = 6;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN = 10;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN = 12;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN = 14;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN = 16;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN = 18;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN = 20;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN = 22;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_RESERVED_24_62 = 24;
static const uint32_t MC1_CHAN0_DSTL_DSLTWAT_RESERVED_24_62_LEN = 39;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLCFG = 0x0c010d0bull;

static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_TMPL0_ONLY = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_RESERVED_1 = 1;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_TMPL7_ENABLE = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_TMPL1_DIS = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_FAST_RD_DISABLE = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_RESERVED_5 = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_TMPL4_DISABLE = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS = 7;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_READ_THRESHOLD = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_READ_THRESHOLD_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_WR_TMP4_THRESHOLD = 16;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_RESERVED_20_23 = 20;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_RESERVED_20_23_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_WR_DBL_THRESHOLD = 24;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_CRITICAL_OW_DIS = 28;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_ENABLE_SPEC_ATTN = 29;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_ENABLE_HOST_ATTN = 30;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_DEBUG_EN = 31;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_DEBUG_LOCAL_SWAP = 32;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_DEBUG_PASSTHRU = 33;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_DEBUG_PASSTHRU_LEN = 11;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_WRAP_MODE_EN = 44;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH = 45;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_TIMEOUT_MODE = 49;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_TIMEOUT_MODE_LEN = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_MMIO_ADDRBIT_POS = 52;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_RESET_CREDITS = 57;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET = 58;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET = 59;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_CREDITS_ON_DEBUG_BUS = 60;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_RESERVED_61_63 = 61;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG_RESERVED_61_63_LEN = 3;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLCFG2 = 0x0c010d0eull;

static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING = 12;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET = 16;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET = 17;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE = 18;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE = 19;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED = 20;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED = 21;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN = 22;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN = 23;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT = 24;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT = 25;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP = 26;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP = 27;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR = 28;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR = 29;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE = 30;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE = 31;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_RESERVED_32_35 = 32;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_RESERVED_32_35_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS = 36;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT = 37;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT = 38;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS = 39;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE = 40;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET = 43;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT = 44;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_RESERVED_45 = 45;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL = 46;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_RESERVED_47_62 = 47;
static const uint32_t MC1_CHAN0_DSTL_DSTLCFG2_RESERVED_47_62_LEN = 16;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLCREDIT = 0x0c010d0aull;

static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT = 12;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT = 17;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN = 7;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_VC0_CREDIT_INIT = 28;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_VC1_CREDIT_INIT = 36;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT = 42;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL = 50;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL = 58;
static const uint32_t MC1_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN = 6;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLERRRPT = 0x0c010d0cull;

static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 1;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT = 7;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT = 9;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT = 10;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 11;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 12;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT = 13;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT = 14;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 15;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT = 16;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT = 17;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT = 18;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT = 19;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT = 20;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT = 21;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT = 22;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT = 23;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT = 24;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT = 25;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT = 26;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT = 27;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT = 28;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT = 29;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT = 30;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT = 31;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT = 32;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT = 33;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT = 34;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT = 35;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 36;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 37;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 38;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 39;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT = 40;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT = 41;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE = 62;
static const uint32_t MC1_CHAN0_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE = 63;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLFIR_RWX = 0x0c010d00ull;
static const uint64_t MC1_CHAN0_DSTL_DSTLFIR_WOX_AND = 0x0c010d01ull;
static const uint64_t MC1_CHAN0_DSTL_DSTLFIR_WOX_OR = 0x0c010d02ull;

static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION = 1;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT = 7;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_CMD_WRDATA_PARITY_ERROR = 9;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR = 10;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR = 11;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR = 12;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR = 13;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR = 14;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR = 15;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR = 16;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR = 17;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN = 18;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN = 19;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT = 22;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT = 23;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SPARE24 = 24;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_SPARE25 = 25;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_DECRYPT_ERR_INFO = 26;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_ENCRYPT_ERR_INFO = 29;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN = 4;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLFIRACT0 = 0x0c010d06ull;

static const uint32_t MC1_CHAN0_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 33;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLFIRMASK_RW = 0x0c010d03ull;
static const uint64_t MC1_CHAN0_DSTL_DSTLFIRMASK_WO_AND = 0x0c010d04ull;
static const uint64_t MC1_CHAN0_DSTL_DSTLFIRMASK_WO_OR = 0x0c010d05ull;

static const uint32_t MC1_CHAN0_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 33;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLFIRWOF = 0x0c010d08ull;

static const uint32_t MC1_CHAN0_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN = 33;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLINJ = 0x0c010d0dull;

static const uint32_t MC1_CHAN0_DSTL_DSTLINJ_ERR_INJ_TRIGGER = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLINJ_ERR_INJ_CONT_MODE = 1;
static const uint32_t MC1_CHAN0_DSTL_DSTLINJ_ERR_INJ_TYPE = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLINJ_RESERVED_4_15 = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLINJ_RESERVED_4_15_LEN = 12;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLPSAVE0 = 0x0c010d12ull;

static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE = 16;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH = 18;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE = 21;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT = 24;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL = 32;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL = 36;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_RESERVED_40_47 = 40;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE0_RESERVED_40_47_LEN = 8;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLPSAVE1 = 0x0c010d13ull;

static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_RESERVED_59_63 = 59;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE1_RESERVED_59_63_LEN = 5;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLPSAVE2 = 0x0c010d14ull;

static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_RESERVED_59_63 = 59;
static const uint32_t MC1_CHAN0_DSTL_DSTLPSAVE2_RESERVED_59_63_LEN = 5;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLSTATUS = 0x0c010d10ull;

static const uint32_t MC1_CHAN0_DSTL_DSTLSTATUS_A_FAIL_WOF = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLSTATUS_A_FAIL_WOF_LEN = 10;
static const uint32_t MC1_CHAN0_DSTL_DSTLSTATUS_B_FAIL_WOF = 10;
static const uint32_t MC1_CHAN0_DSTL_DSTLSTATUS_B_FAIL_WOF_LEN = 10;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_DSTL_DSTLTRACK = 0x0c010d0full;

static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE = 0;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE = 12;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE = 18;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE = 24;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE = 28;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW = 34;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN = 6;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW = 44;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN = 4;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW = 50;
static const uint32_t MC1_CHAN0_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN = 7;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLBADRESP = 0x0c010e10ull;

static const uint32_t MC1_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_VAL = 0;
static const uint32_t MC1_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE = 1;
static const uint32_t MC1_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD = 2;
static const uint32_t MC1_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_TAG = 3;
static const uint32_t MC1_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN = 6;
static const uint32_t MC1_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_VAL = 9;
static const uint32_t MC1_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE = 10;
static const uint32_t MC1_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD = 11;
static const uint32_t MC1_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_TAG = 12;
static const uint32_t MC1_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN = 6;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLCFG = 0x0c010e0bull;

static const uint32_t MC1_CHAN0_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE = 0;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE = 1;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_FAIL_CAPTURE_CONFIG = 2;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE = 4;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA = 5;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA_LEN = 2;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO = 7;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE = 8;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_LOWLAT_MISS_015_DELAY = 9;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN = 3;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_ET_DISABLE = 16;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE = 17;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE = 18;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_TEMPLATE1_ENABLE = 19;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_ENABLE = 20;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT = 21;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT_LEN = 3;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE = 24;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN = 7;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE = 32;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT = 33;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN = 3;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS = 36;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_DL_WIDTH_HALF_ENABLE = 37;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD = 40;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN = 4;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_CFG_ENABLE_SPEC_ATTN = 44;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_CFG_ENABLE_HOST_ATTN = 45;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_CFG_WRAP_MODE = 46;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_RESERVED_47 = 47;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE = 48;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_LOL_LFSR_RATE_SEL = 49;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN = 3;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_LOL_CAPTURE_CONFIG = 54;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_LAST_OPENCAPI_ENABLE = 56;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW = 57;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_PMU_SELECT_FAIL_RSP = 58;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_PMU_ENABLE = 59;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_PMU_SELECT_ALT_PERF = 60;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_CS_HW477424_DISABLE = 61;
static const uint32_t MC1_CHAN0_USTL_USTLCFG_CS_HW475333_DISABLE = 62;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLCFWOF = 0x0c010e15ull;

static const uint32_t MC1_CHAN0_USTL_USTLCFWOF_A_CHANFAIL_WOF = 0;
static const uint32_t MC1_CHAN0_USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN = 16;
static const uint32_t MC1_CHAN0_USTL_USTLCFWOF_B_CHANFAIL_WOF = 16;
static const uint32_t MC1_CHAN0_USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN = 16;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLDBG = 0x0c010e0dull;

static const uint32_t MC1_CHAN0_USTL_USTLDBG_ENABLE = 0;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_SEL_TOP = 8;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_SEL_WR_TOP = 9;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_SEL_BOT = 10;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_SEL_WR_BOT = 11;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_SEL_FLIT = 12;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_SEL_FLIT_CHANB = 13;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_SEL_MIRRORLOG_VLDS = 14;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_SPARE = 15;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_WAT_ENABLE0 = 16;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_WAT_ENABLE0_LEN = 2;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_WAT_ENABLE1 = 18;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_WAT_ENABLE1_LEN = 2;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_WAT_ENABLE2 = 20;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_WAT_ENABLE2_LEN = 2;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_WAT_ENABLE3 = 22;
static const uint32_t MC1_CHAN0_USTL_USTLDBG_WAT_ENABLE3_LEN = 2;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLERRPT = 0x0c010e16ull;

static const uint32_t MC1_CHAN0_USTL_USTLERRPT_WDF_CMT_PAR_ERR = 0;
static const uint32_t MC1_CHAN0_USTL_USTLERRPT_WDF_CMD_PAR_ERR = 1;
static const uint32_t MC1_CHAN0_USTL_USTLERRPT_WRT_NO_BUFF_ERR = 2;
static const uint32_t MC1_CHAN0_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR = 3;
static const uint32_t MC1_CHAN0_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR = 4;
static const uint32_t MC1_CHAN0_USTL_USTLERRPT_WDF_NO_BUFF_ERR = 5;
static const uint32_t MC1_CHAN0_USTL_USTLERRPT_RESERVED = 6;
static const uint32_t MC1_CHAN0_USTL_USTLERRPT_RESERVED_LEN = 10;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLERRRPT = 0x0c010e0eull;

static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT = 0;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 1;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 2;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT = 3;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT = 4;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 5;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 6;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT = 7;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT = 8;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT = 9;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT = 10;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT = 11;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT = 12;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT = 13;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT = 14;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT = 15;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 16;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT = 17;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT = 18;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT = 19;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT = 20;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT = 21;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT = 22;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 23;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT = 24;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT = 25;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT = 26;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT = 27;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT = 28;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT = 29;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT = 30;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA = 31;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT = 32;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT = 33;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT = 34;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT = 36;
static const uint32_t MC1_CHAN0_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT = 37;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLFAILMASK = 0x0c010e13ull;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLFIR_RWX = 0x0c010e00ull;
static const uint64_t MC1_CHAN0_USTL_USTLFIR_WOX_AND = 0x0c010e01ull;
static const uint64_t MC1_CHAN0_USTL_USTLFIR_WOX_OR = 0x0c010e02ull;

static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR = 0;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR = 1;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR = 2;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR = 3;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_HALF_SPEED_MODE = 4;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_HALF_SPEED_MODE = 5;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WDF_BUFFER_CE = 6;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WDF_BUFFER_UE = 7;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WDF_BUFFER_SUE = 8;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WDF_BUFFER_OVERRUN = 9;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WDF_TAG_PARITY_ERROR = 10;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR = 11;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR = 12;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR = 13;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_RESERVED_14 = 14;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 = 15;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WDF_CMT_PARITY_ERROR = 16;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_READ_SPARE_1 = 17;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_READ_SPARE_2 = 18;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR = 19;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WRT_BUFFER_CE = 20;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WRT_BUFFER_UE = 21;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WRT_BUFFER_SUE = 22;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR = 23;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR = 24;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 = 25;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_WRT_BUFF_ERR = 26;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP = 27;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP = 28;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER = 29;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER = 30;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP = 31;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP = 32;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER = 33;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER = 34;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR = 35;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR = 36;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR = 37;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR = 38;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL = 39;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL = 40;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS = 41;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS = 42;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO = 43;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO = 44;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE = 45;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE = 46;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_BAD_DATA = 47;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_BAD_DATA = 48;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR = 49;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR = 50;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR = 51;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR = 52;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR = 53;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR = 54;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR = 55;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR = 56;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_FATAL_REG_PARITY_ERROR = 57;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_RECOV_REG_PARITY_ERROR = 58;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO = 59;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO = 60;
static const uint32_t MC1_CHAN0_USTL_USTLFIR_SPARE_61 = 61;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLFIRACT0 = 0x0c010e06ull;

static const uint32_t MC1_CHAN0_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC1_CHAN0_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN = 62;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLFIRMASK_RW = 0x0c010e03ull;
static const uint64_t MC1_CHAN0_USTL_USTLFIRMASK_WO_AND = 0x0c010e04ull;
static const uint64_t MC1_CHAN0_USTL_USTLFIRMASK_WO_OR = 0x0c010e05ull;

static const uint32_t MC1_CHAN0_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC1_CHAN0_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN = 62;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLFIRWOF = 0x0c010e08ull;

static const uint32_t MC1_CHAN0_USTL_USTLFIRWOF_USTLFIRWOF_WOF = 0;
static const uint32_t MC1_CHAN0_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN = 62;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLINJ = 0x0c010e0cull;

static const uint32_t MC1_CHAN0_USTL_USTLINJ_FAIL_RESP_TYPE = 3;
static const uint32_t MC1_CHAN0_USTL_USTLINJ_FAIL_RESP_TYPE_LEN = 3;
static const uint32_t MC1_CHAN0_USTL_USTLINJ_FIR_INJECT = 8;
static const uint32_t MC1_CHAN0_USTL_USTLINJ_FIR_INJECT_LEN = 5;
static const uint32_t MC1_CHAN0_USTL_USTLINJ_US_DATA = 20;
static const uint32_t MC1_CHAN0_USTL_USTLINJ_US_DATA_LEN = 3;
static const uint32_t MC1_CHAN0_USTL_USTLINJ_CHAN_SEL = 24;
static const uint32_t MC1_CHAN0_USTL_USTLINJ_DATA_DW_SEL = 25;
static const uint32_t MC1_CHAN0_USTL_USTLINJ_US_DATA_ERR_EN = 26;
static const uint32_t MC1_CHAN0_USTL_USTLINJ_ONE_SHOT = 27;
static const uint32_t MC1_CHAN0_USTL_USTLINJ_DATA_OUT = 28;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLLOLDROP = 0x0c010e11ull;

static const uint32_t MC1_CHAN0_USTL_USTLLOLDROP_A_DROP_REASON = 0;
static const uint32_t MC1_CHAN0_USTL_USTLLOLDROP_A_DROP_REASON_LEN = 16;
static const uint32_t MC1_CHAN0_USTL_USTLLOLDROP_B_DROP_REASON = 32;
static const uint32_t MC1_CHAN0_USTL_USTLLOLDROP_B_DROP_REASON_LEN = 16;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLLOLMASK = 0x0c010e12ull;

static const uint32_t MC1_CHAN0_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t MC1_CHAN0_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN = 16;
static const uint32_t MC1_CHAN0_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK = 32;
static const uint32_t MC1_CHAN0_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN = 16;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLMCHWFM = 0x0c010e0full;

static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_ENABLE = 0;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_FAIL_THRESH = 1;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_FAIL_THRESH_LEN = 6;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_WINDOW_SIZE = 7;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_WINDOW_SIZE_LEN = 7;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_TSCALE = 14;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_TSCALE_LEN = 2;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_SCOM_COMMAND_VALID = 16;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_SCOM_COMMAND = 17;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT = 18;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_HWFM_STATUS = 19;
static const uint32_t MC1_CHAN0_USTL_USTLMCHWFM_HWFM_STATUS_LEN = 4;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLOCAPIERROR = 0x0c010e14ull;

static const uint32_t MC1_CHAN0_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID = 0;
static const uint32_t MC1_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE = 1;
static const uint32_t MC1_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN = 8;
static const uint32_t MC1_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION = 9;
static const uint32_t MC1_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN = 31;
// omi/reg00004.H

static const uint64_t MC1_CHAN0_USTL_USTLSTATUS = 0x0c010e0aull;

static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_LOL_MODE = 0;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_LOL_MODE = 1;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD = 2;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR = 3;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD = 4;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR = 5;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD = 6;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR = 7;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD = 8;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR = 9;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_FAIL_RESP = 10;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_FAIL_RESP_LEN = 4;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_WAT_FIRED = 24;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_WAT_FIRED = 25;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY = 32;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR = 33;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR = 34;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR = 35;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR = 36;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR = 37;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 38;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP = 39;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP = 40;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE = 41;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY = 42;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY = 43;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR = 44;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR = 45;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR = 46;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR = 47;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR = 48;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 49;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP = 50;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP = 51;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE = 52;
static const uint32_t MC1_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY = 53;
// omi/reg00004.H

static const uint64_t MC1_CHAN1_DSTL_DSLTWAT = 0x0c010d51ull;

static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU = 0;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN = 6;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN = 10;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN = 12;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN = 14;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN = 16;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN = 18;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN = 20;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN = 22;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_RESERVED_24_62 = 24;
static const uint32_t MC1_CHAN1_DSTL_DSLTWAT_RESERVED_24_62_LEN = 39;
// omi/reg00004.H

static const uint64_t MC1_CHAN1_DSTL_DSTLCFG = 0x0c010d4bull;

static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_TMPL0_ONLY = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_RESERVED_1 = 1;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_TMPL7_ENABLE = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_TMPL1_DIS = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_FAST_RD_DISABLE = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_RESERVED_5 = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_TMPL4_DISABLE = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS = 7;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_READ_THRESHOLD = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_READ_THRESHOLD_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_WR_TMP4_THRESHOLD = 16;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_RESERVED_20_23 = 20;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_RESERVED_20_23_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_WR_DBL_THRESHOLD = 24;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_CRITICAL_OW_DIS = 28;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_ENABLE_SPEC_ATTN = 29;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_ENABLE_HOST_ATTN = 30;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_DEBUG_EN = 31;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_DEBUG_LOCAL_SWAP = 32;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_DEBUG_PASSTHRU = 33;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_DEBUG_PASSTHRU_LEN = 11;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_WRAP_MODE_EN = 44;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH = 45;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_TIMEOUT_MODE = 49;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_TIMEOUT_MODE_LEN = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_MMIO_ADDRBIT_POS = 52;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_RESET_CREDITS = 57;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET = 58;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET = 59;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_CREDITS_ON_DEBUG_BUS = 60;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_RESERVED_61_63 = 61;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG_RESERVED_61_63_LEN = 3;
// omi/reg00004.H

static const uint64_t MC1_CHAN1_DSTL_DSTLCFG2 = 0x0c010d4eull;

static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING = 12;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET = 16;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET = 17;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE = 18;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE = 19;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED = 20;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED = 21;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN = 22;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN = 23;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT = 24;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT = 25;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP = 26;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP = 27;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR = 28;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR = 29;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE = 30;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE = 31;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_RESERVED_32_35 = 32;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_RESERVED_32_35_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS = 36;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT = 37;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT = 38;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS = 39;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE = 40;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET = 43;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT = 44;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_RESERVED_45 = 45;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL = 46;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_RESERVED_47_62 = 47;
static const uint32_t MC1_CHAN1_DSTL_DSTLCFG2_RESERVED_47_62_LEN = 16;
// omi/reg00004.H

static const uint64_t MC1_CHAN1_DSTL_DSTLCREDIT = 0x0c010d4aull;

static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT = 12;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT = 17;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN = 7;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_VC0_CREDIT_INIT = 28;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_VC1_CREDIT_INIT = 36;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT = 42;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL = 50;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL = 58;
static const uint32_t MC1_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN = 6;
// omi/reg00004.H

static const uint64_t MC1_CHAN1_DSTL_DSTLERRRPT = 0x0c010d4cull;

static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 1;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT = 7;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT = 9;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT = 10;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 11;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 12;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT = 13;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT = 14;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 15;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT = 16;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT = 17;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT = 18;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT = 19;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT = 20;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT = 21;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT = 22;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT = 23;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT = 24;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT = 25;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT = 26;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT = 27;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT = 28;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT = 29;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT = 30;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT = 31;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT = 32;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT = 33;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT = 34;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT = 35;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 36;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 37;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 38;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 39;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT = 40;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT = 41;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE = 62;
static const uint32_t MC1_CHAN1_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE = 63;
// omi/reg00004.H

static const uint64_t MC1_CHAN1_DSTL_DSTLFIR_RWX = 0x0c010d40ull;
static const uint64_t MC1_CHAN1_DSTL_DSTLFIR_WOX_AND = 0x0c010d41ull;
static const uint64_t MC1_CHAN1_DSTL_DSTLFIR_WOX_OR = 0x0c010d42ull;

static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION = 1;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT = 7;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_CMD_WRDATA_PARITY_ERROR = 9;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR = 10;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR = 11;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR = 12;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR = 13;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR = 14;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR = 15;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR = 16;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR = 17;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN = 18;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN = 19;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT = 22;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT = 23;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SPARE24 = 24;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_SPARE25 = 25;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_DECRYPT_ERR_INFO = 26;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_ENCRYPT_ERR_INFO = 29;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN = 4;
// omi/reg00004.H

static const uint64_t MC1_CHAN1_DSTL_DSTLFIRACT0 = 0x0c010d46ull;

static const uint32_t MC1_CHAN1_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 33;
// omi/reg00004.H

static const uint64_t MC1_CHAN1_DSTL_DSTLFIRMASK_RW = 0x0c010d43ull;
static const uint64_t MC1_CHAN1_DSTL_DSTLFIRMASK_WO_AND = 0x0c010d44ull;
static const uint64_t MC1_CHAN1_DSTL_DSTLFIRMASK_WO_OR = 0x0c010d45ull;

static const uint32_t MC1_CHAN1_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 33;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_DSTL_DSTLFIRWOF = 0x0c010d48ull;

static const uint32_t MC1_CHAN1_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN = 33;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_DSTL_DSTLINJ = 0x0c010d4dull;

static const uint32_t MC1_CHAN1_DSTL_DSTLINJ_ERR_INJ_TRIGGER = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLINJ_ERR_INJ_CONT_MODE = 1;
static const uint32_t MC1_CHAN1_DSTL_DSTLINJ_ERR_INJ_TYPE = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLINJ_RESERVED_4_15 = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLINJ_RESERVED_4_15_LEN = 12;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_DSTL_DSTLPSAVE0 = 0x0c010d52ull;

static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE = 16;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH = 18;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE = 21;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT = 24;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL = 32;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL = 36;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_RESERVED_40_47 = 40;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE0_RESERVED_40_47_LEN = 8;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_DSTL_DSTLPSAVE1 = 0x0c010d53ull;

static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_RESERVED_59_63 = 59;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE1_RESERVED_59_63_LEN = 5;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_DSTL_DSTLPSAVE2 = 0x0c010d54ull;

static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_RESERVED_59_63 = 59;
static const uint32_t MC1_CHAN1_DSTL_DSTLPSAVE2_RESERVED_59_63_LEN = 5;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_DSTL_DSTLSTATUS = 0x0c010d50ull;

static const uint32_t MC1_CHAN1_DSTL_DSTLSTATUS_A_FAIL_WOF = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLSTATUS_A_FAIL_WOF_LEN = 10;
static const uint32_t MC1_CHAN1_DSTL_DSTLSTATUS_B_FAIL_WOF = 10;
static const uint32_t MC1_CHAN1_DSTL_DSTLSTATUS_B_FAIL_WOF_LEN = 10;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_DSTL_DSTLTRACK = 0x0c010d4full;

static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE = 0;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE = 12;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE = 18;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE = 24;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE = 28;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW = 34;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN = 6;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW = 44;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN = 4;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW = 50;
static const uint32_t MC1_CHAN1_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN = 7;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLBADRESP = 0x0c010e50ull;

static const uint32_t MC1_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_VAL = 0;
static const uint32_t MC1_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE = 1;
static const uint32_t MC1_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD = 2;
static const uint32_t MC1_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_TAG = 3;
static const uint32_t MC1_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN = 6;
static const uint32_t MC1_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_VAL = 9;
static const uint32_t MC1_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE = 10;
static const uint32_t MC1_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD = 11;
static const uint32_t MC1_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_TAG = 12;
static const uint32_t MC1_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN = 6;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLCFG = 0x0c010e4bull;

static const uint32_t MC1_CHAN1_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE = 0;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE = 1;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_FAIL_CAPTURE_CONFIG = 2;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE = 4;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA = 5;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA_LEN = 2;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO = 7;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE = 8;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_LOWLAT_MISS_015_DELAY = 9;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN = 3;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_ET_DISABLE = 16;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE = 17;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE = 18;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_TEMPLATE1_ENABLE = 19;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_ENABLE = 20;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT = 21;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT_LEN = 3;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE = 24;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN = 7;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE = 32;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT = 33;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN = 3;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS = 36;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_DL_WIDTH_HALF_ENABLE = 37;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD = 40;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN = 4;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_CFG_ENABLE_SPEC_ATTN = 44;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_CFG_ENABLE_HOST_ATTN = 45;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_CFG_WRAP_MODE = 46;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_RESERVED_47 = 47;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE = 48;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_LOL_LFSR_RATE_SEL = 49;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN = 3;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_LOL_CAPTURE_CONFIG = 54;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_LAST_OPENCAPI_ENABLE = 56;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW = 57;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_PMU_SELECT_FAIL_RSP = 58;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_PMU_ENABLE = 59;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_PMU_SELECT_ALT_PERF = 60;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_CS_HW477424_DISABLE = 61;
static const uint32_t MC1_CHAN1_USTL_USTLCFG_CS_HW475333_DISABLE = 62;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLCFWOF = 0x0c010e55ull;

static const uint32_t MC1_CHAN1_USTL_USTLCFWOF_A_CHANFAIL_WOF = 0;
static const uint32_t MC1_CHAN1_USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN = 16;
static const uint32_t MC1_CHAN1_USTL_USTLCFWOF_B_CHANFAIL_WOF = 16;
static const uint32_t MC1_CHAN1_USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN = 16;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLDBG = 0x0c010e4dull;

static const uint32_t MC1_CHAN1_USTL_USTLDBG_ENABLE = 0;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_SEL_TOP = 8;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_SEL_WR_TOP = 9;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_SEL_BOT = 10;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_SEL_WR_BOT = 11;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_SEL_FLIT = 12;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_SEL_FLIT_CHANB = 13;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_SEL_MIRRORLOG_VLDS = 14;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_SPARE = 15;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_WAT_ENABLE0 = 16;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_WAT_ENABLE0_LEN = 2;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_WAT_ENABLE1 = 18;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_WAT_ENABLE1_LEN = 2;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_WAT_ENABLE2 = 20;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_WAT_ENABLE2_LEN = 2;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_WAT_ENABLE3 = 22;
static const uint32_t MC1_CHAN1_USTL_USTLDBG_WAT_ENABLE3_LEN = 2;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLERRPT = 0x0c010e56ull;

static const uint32_t MC1_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR = 0;
static const uint32_t MC1_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR = 1;
static const uint32_t MC1_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR = 2;
static const uint32_t MC1_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR = 3;
static const uint32_t MC1_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR = 4;
static const uint32_t MC1_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR = 5;
static const uint32_t MC1_CHAN1_USTL_USTLERRPT_RESERVED = 6;
static const uint32_t MC1_CHAN1_USTL_USTLERRPT_RESERVED_LEN = 10;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLERRRPT = 0x0c010e4eull;

static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT = 0;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 1;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 2;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT = 3;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT = 4;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 5;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 6;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT = 7;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT = 8;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT = 9;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT = 10;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT = 11;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT = 12;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT = 13;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT = 14;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT = 15;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 16;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT = 17;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT = 18;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT = 19;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT = 20;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT = 21;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT = 22;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 23;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT = 24;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT = 25;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT = 26;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT = 27;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT = 28;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT = 29;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT = 30;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA = 31;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT = 32;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT = 33;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT = 34;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT = 36;
static const uint32_t MC1_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT = 37;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLFAILMASK = 0x0c010e53ull;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLFIR_RWX = 0x0c010e40ull;
static const uint64_t MC1_CHAN1_USTL_USTLFIR_WOX_AND = 0x0c010e41ull;
static const uint64_t MC1_CHAN1_USTL_USTLFIR_WOX_OR = 0x0c010e42ull;

static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR = 0;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR = 1;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR = 2;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR = 3;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE = 4;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE = 5;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE = 6;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE = 7;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE = 8;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN = 9;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR = 10;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR = 11;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR = 12;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR = 13;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_RESERVED_14 = 14;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 = 15;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR = 16;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_READ_SPARE_1 = 17;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_READ_SPARE_2 = 18;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR = 19;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE = 20;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE = 21;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE = 22;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR = 23;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR = 24;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 = 25;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR = 26;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP = 27;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP = 28;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER = 29;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER = 30;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP = 31;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP = 32;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER = 33;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER = 34;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR = 35;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR = 36;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR = 37;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR = 38;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL = 39;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL = 40;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS = 41;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS = 42;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO = 43;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO = 44;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE = 45;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE = 46;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA = 47;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA = 48;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR = 49;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR = 50;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR = 51;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR = 52;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR = 53;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR = 54;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR = 55;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR = 56;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR = 57;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR = 58;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO = 59;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO = 60;
static const uint32_t MC1_CHAN1_USTL_USTLFIR_SPARE_61 = 61;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLFIRACT0 = 0x0c010e46ull;

static const uint32_t MC1_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC1_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN = 62;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLFIRMASK_RW = 0x0c010e43ull;
static const uint64_t MC1_CHAN1_USTL_USTLFIRMASK_WO_AND = 0x0c010e44ull;
static const uint64_t MC1_CHAN1_USTL_USTLFIRMASK_WO_OR = 0x0c010e45ull;

static const uint32_t MC1_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC1_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN = 62;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLFIRWOF = 0x0c010e48ull;

static const uint32_t MC1_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF = 0;
static const uint32_t MC1_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN = 62;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLINJ = 0x0c010e4cull;

static const uint32_t MC1_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE = 3;
static const uint32_t MC1_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE_LEN = 3;
static const uint32_t MC1_CHAN1_USTL_USTLINJ_FIR_INJECT = 8;
static const uint32_t MC1_CHAN1_USTL_USTLINJ_FIR_INJECT_LEN = 5;
static const uint32_t MC1_CHAN1_USTL_USTLINJ_US_DATA = 20;
static const uint32_t MC1_CHAN1_USTL_USTLINJ_US_DATA_LEN = 3;
static const uint32_t MC1_CHAN1_USTL_USTLINJ_CHAN_SEL = 24;
static const uint32_t MC1_CHAN1_USTL_USTLINJ_DATA_DW_SEL = 25;
static const uint32_t MC1_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN = 26;
static const uint32_t MC1_CHAN1_USTL_USTLINJ_ONE_SHOT = 27;
static const uint32_t MC1_CHAN1_USTL_USTLINJ_DATA_OUT = 28;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLLOLDROP = 0x0c010e51ull;

static const uint32_t MC1_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON = 0;
static const uint32_t MC1_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON_LEN = 16;
static const uint32_t MC1_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON = 32;
static const uint32_t MC1_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON_LEN = 16;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLLOLMASK = 0x0c010e52ull;

static const uint32_t MC1_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t MC1_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN = 16;
static const uint32_t MC1_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK = 32;
static const uint32_t MC1_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN = 16;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLMCHWFM = 0x0c010e4full;

static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_ENABLE = 0;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH = 1;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH_LEN = 6;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE = 7;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE_LEN = 7;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_TSCALE = 14;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_TSCALE_LEN = 2;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID = 16;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND = 17;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT = 18;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS = 19;
static const uint32_t MC1_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS_LEN = 4;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLOCAPIERROR = 0x0c010e54ull;

static const uint32_t MC1_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID = 0;
static const uint32_t MC1_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE = 1;
static const uint32_t MC1_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN = 8;
static const uint32_t MC1_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION = 9;
static const uint32_t MC1_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN = 31;
// omi/reg00005.H

static const uint64_t MC1_CHAN1_USTL_USTLSTATUS = 0x0c010e4aull;

static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE = 0;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE = 1;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD = 2;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR = 3;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD = 4;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR = 5;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD = 6;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR = 7;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD = 8;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR = 9;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_FAIL_RESP = 10;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_FAIL_RESP_LEN = 4;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED = 24;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED = 25;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY = 32;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR = 33;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR = 34;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR = 35;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR = 36;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR = 37;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 38;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP = 39;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP = 40;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE = 41;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY = 42;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY = 43;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR = 44;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR = 45;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR = 46;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR = 47;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR = 48;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 49;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP = 50;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP = 51;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE = 52;
static const uint32_t MC1_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY = 53;
// omi/reg00005.H

static const uint64_t MC1_MISC_CLKMON_MONM_CLKRATIO = 0x0c010ff0ull;

static const uint32_t MC1_MISC_CLKMON_MONM_CLKRATIO_RATIO = 0;
static const uint32_t MC1_MISC_CLKMON_MONM_CLKRATIO_RATIO_LEN = 12;
static const uint32_t MC1_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE = 12;
static const uint32_t MC1_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE = 13;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_AACR = 0x0c010f29ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_AACR_BUFFER = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_AACR_ADDRESS = 1;
static const uint32_t MC1_MISC_MBA_SCOMFIR_AACR_ADDRESS_LEN = 10;
static const uint32_t MC1_MISC_MBA_SCOMFIR_AACR_AUTOINC = 11;
static const uint32_t MC1_MISC_MBA_SCOMFIR_AACR_ECCGEN = 12;
static const uint32_t MC1_MISC_MBA_SCOMFIR_AACR_CHANNEL = 13;
static const uint32_t MC1_MISC_MBA_SCOMFIR_AACR_CHANNEL_LEN = 2;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_AADR = 0x0c010f2aull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_AADR_AADR_DATA_LEN = 64;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_AAER = 0x0c010f2bull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC_LEN = 9;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_DBG0_SCOM0Q = 0x0c010f94ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63 = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63_LEN = 64;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_DBG0_SCOM1Q = 0x0c010f95ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87 = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87_LEN = 24;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED = 24;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED_LEN = 40;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_DBG1_SCOM0Q = 0x0c010f96ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN = 64;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_DBG1_SCOM1Q = 0x0c010f97ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87 = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87_LEN = 24;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED = 24;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED_LEN = 40;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q = 0x0c010fe8ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01 = 1;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01_LEN = 11;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23 = 12;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23_LEN = 11;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI = 23;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44 = 24;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44_LEN = 21;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER = 45;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET = 46;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM = 47;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q = 0x0c010fe9ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT = 1;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL = 3;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL_LEN = 20;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL = 23;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL_LEN = 20;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL = 43;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL_LEN = 20;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63 = 63;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_DBGCFG2Q = 0x0c010feaull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL_LEN = 20;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL = 20;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL_LEN = 20;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL = 40;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL_LEN = 20;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63 = 60;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63_LEN = 4;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q = 0x0c010febull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL_LEN = 20;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL = 20;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22 = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL = 23;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25 = 25;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL = 26;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28 = 28;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL = 29;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32 = 31;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE = 33;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE = 37;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE = 41;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE = 45;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE_LEN = 6;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE = 51;
static const uint32_t MC1_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE_LEN = 8;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ = 0x0c010fe7ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT = 1;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT = 5;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT = 6;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT = 7;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT = 8;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT = 9;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT = 10;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT = 11;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT = 12;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT = 13;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT = 14;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT = 15;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT = 16;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT = 17;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT = 18;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT = 19;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT = 20;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBCFGQ = 0x0c010fe0ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER = 10;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN = 62;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN = 63;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRACT0 = 0x0c010f06ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0 = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0_LEN = 14;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRMASK_RW = 0x0c010f03ull;
static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_AND = 0x0c010f04ull;
static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_OR = 0x0c010f05ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK_LEN = 14;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_RWX = 0x0c010f00ull;
static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_AND = 0x0c010f01ull;
static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_OR = 0x0c010f02ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE = 1;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3 = 3;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT = 5;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT = 6;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT = 7;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT = 8;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT = 9;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT = 10;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT = 11;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR = 12;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE = 13;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRWOF = 0x0c010f08ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF_LEN = 14;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCBPARMQ = 0x0c010fafull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN = 59;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG = 0x0c010f98ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE = 1;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE = 3;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN0 = 0x0c010fa4ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN1 = 0x0c010fa5ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN2 = 0x0c010fa6ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN3 = 0x0c010fa7ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN3_N = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN3_N_LEN = 16;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE = 16;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT = 17;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT_LEN = 3;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL = 0x0c010f99ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM = 1;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER = 3;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT = 8;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT = 10;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT = 12;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL = 14;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15 = 15;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT = 16;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18 = 18;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT = 19;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21 = 21;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24 = 24;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT = 25;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27 = 27;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE = 28;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT = 29;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT = 33;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT_LEN = 7;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT = 40;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT_LEN = 5;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT = 45;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG = 49;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG_LEN = 9;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59 = 58;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59_LEN = 2;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE = 60;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET = 61;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS = 62;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63 = 63;
// omi/reg00005.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0 = 0x0c010f9aull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN = 6;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE = 6;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN = 8;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT = 16;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT = 20;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT = 24;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT = 28;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT = 32;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN = 4;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT = 36;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN = 4;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATDATA1 = 0x0c010f9bull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A_LEN = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A_LEN = 22;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATDATA2 = 0x0c010f9cull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B_LEN = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B_LEN = 22;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATDATA3 = 0x0c010f9dull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A_LEN = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A_LEN = 22;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATDATA4 = 0x0c010f9eull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN = 22;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATDATA5 = 0x0c010f9full;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A_LEN = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A_LEN = 22;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATDATA6 = 0x0c010fa0ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN = 22;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATDATA7 = 0x0c010fa1ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A_LEN = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A_LEN = 22;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATDATA8 = 0x0c010fa2ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B = 22;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN = 22;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_MCWATDATA9 = 0x0c010fa3ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN = 46;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL = 47;
static const uint32_t MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN = 17;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_SPARE = 0x0c010f0full;

static const uint32_t MC1_MISC_MBA_SCOMFIR_SPARE_SPARE = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_SPARE_SPARE_LEN = 8;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_WATCFG0AQ = 0x0c010f80ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN = 48;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_WATCFG0BQ = 0x0c010f81ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA_LEN = 44;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL = 44;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL_LEN = 17;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_WATCFG0CQ = 0x0c010f82ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB_LEN = 44;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_WATCFG0DQ = 0x0c010f83ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA_LEN = 44;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_WATCFG0EQ = 0x0c010f84ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB_LEN = 44;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_WATCFG1AQ = 0x0c010f85ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL_LEN = 48;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_WATCFG1BQ = 0x0c010f86ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA_LEN = 44;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL = 44;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL_LEN = 17;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_WATCFG1CQ = 0x0c010f87ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB_LEN = 44;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_WATCFG1DQ = 0x0c010f88ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA_LEN = 44;
// omi/reg00006.H

static const uint64_t MC1_MISC_MBA_SCOMFIR_WATCFG1EQ = 0x0c010f89ull;

static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB = 0;
static const uint32_t MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB_LEN = 44;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_AACR = 0x0c010c2cull;

static const uint32_t MC1_PBI01_SCOMFIR_AACR_BUFFER = 0;
static const uint32_t MC1_PBI01_SCOMFIR_AACR_ADDRESS = 1;
static const uint32_t MC1_PBI01_SCOMFIR_AACR_ADDRESS_LEN = 9;
static const uint32_t MC1_PBI01_SCOMFIR_AACR_AUTOINC = 10;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_AADR = 0x0c010c2dull;

static const uint32_t MC1_PBI01_SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t MC1_PBI01_SCOMFIR_AADR_AADR_DATA_LEN = 64;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_AAER = 0x0c010c2eull;

static const uint32_t MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC = 0;
static const uint32_t MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC_LEN = 9;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCERPT0 = 0x0c010c1eull;

static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR = 5;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR = 9;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR = 10;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR = 11;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR = 12;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR = 13;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR = 14;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR = 17;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR = 18;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR = 20;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR = 21;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR = 22;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR = 23;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR = 29;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR = 30;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR = 31;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR = 32;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR = 33;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR = 38;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR = 39;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR = 40;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR = 41;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR = 42;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR = 43;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR = 44;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR = 45;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR = 46;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR = 47;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR = 48;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR = 49;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 = 51;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR = 52;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 = 53;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR = 54;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 = 55;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR = 56;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 = 57;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR = 58;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR = 59;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR = 60;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR = 61;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCERPT1 = 0x0c010c1full;

static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT = 23;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT = 33;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT = 34;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q = 44;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q_LEN = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q = 51;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q_LEN = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3 = 60;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3 = 61;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3 = 62;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3 = 63;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCERPT2 = 0x0c010c1aull;

static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR = 5;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR = 9;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE = 11;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE = 12;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT = 13;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT = 14;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR = 17;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR = 18;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT = 20;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT = 21;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT = 22;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT = 23;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT = 25;
static const uint32_t MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT = 26;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGP0 = 0x0c010c0aull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_0_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE = 25;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP = 40;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION = 43;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE = 46;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE = 54;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN = 8;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGP0A = 0x0c010c0eull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21 = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21_LEN = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID = 22;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGP0E = 0x0c010c16ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0E_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS = 21;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS_LEN = 19;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGP1 = 0x0c010c0bull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_1_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE = 25;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE_LEN = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP = 40;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP_LEN = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION = 43;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION_LEN = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE = 46;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE_LEN = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE = 54;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE_LEN = 8;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGP1A = 0x0c010c0full;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21 = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21_LEN = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID = 22;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGP1E = 0x0c010c17ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1E_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS = 21;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN = 19;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGPM0 = 0x0c010c20ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE = 25;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE_LEN = 15;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGPM0A = 0x0c010c21ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21 = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID = 22;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGPM0E = 0x0c010c1cull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0E_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS = 21;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS_LEN = 19;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGPM1 = 0x0c010c30ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE = 25;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE_LEN = 15;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGPM1A = 0x0c010c31ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21 = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21_LEN = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID = 22;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGPM1E = 0x0c010c1dull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1E_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS = 21;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS_LEN = 19;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGPR0 = 0x0c010c0cull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS_LEN = 31;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS = 33;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS_LEN = 31;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFGPR1 = 0x0c010c0dull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS_LEN = 31;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS = 33;
static const uint32_t MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS_LEN = 31;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFIR_RWX = 0x0c010c00ull;
static const uint64_t MC1_PBI01_SCOMFIR_MCFIR_WOX_AND = 0x0c010c01ull;
static const uint64_t MC1_PBI01_SCOMFIR_MCFIR_WOX_OR = 0x0c010c02ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 = 5;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6 = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7 = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9 = 9;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10 = 10;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0 = 11;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1 = 12;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2 = 13;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3 = 14;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR = 17;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18 = 18;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19 = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20 = 20;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21 = 21;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS = 22;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23 = 23;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFIRACT0 = 0x0c010c06ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN = 24;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFIRMASK_RW = 0x0c010c03ull;
static const uint64_t MC1_PBI01_SCOMFIR_MCFIRMASK_WO_AND = 0x0c010c04ull;
static const uint64_t MC1_PBI01_SCOMFIR_MCFIRMASK_WO_OR = 0x0c010c05ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK_LEN = 24;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCFIRWOF = 0x0c010c08ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF_LEN = 24;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCLFSR = 0x0c010c14ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT_LEN = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4 = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4_LEN = 3;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCMODE0 = 0x0c010c11ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4 = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID = 5;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND = 9;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND = 10;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11 = 11;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC = 12;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13 = 13;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT = 14;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN = 10;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE = 25;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY = 32;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE = 36;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS = 37;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH = 40;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63 = 41;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63_LEN = 23;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCMODE1 = 0x0c010c12ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN = 10;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT = 10;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS = 11;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS = 17;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY = 18;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN = 9;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH = 28;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS = 32;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP = 33;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI = 52;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI_LEN = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS = 54;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60 = 60;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS = 61;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW = 62;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63 = 63;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCMODE2 = 0x0c010c13ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0 = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0_LEN = 13;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15 = 14;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15_LEN = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM = 17;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22 = 18;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22_LEN = 5;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR = 23;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES_LEN = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH = 40;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH_LEN = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN = 44;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN = 45;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52 = 46;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52_LEN = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE = 53;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE = 54;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE = 55;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE = 56;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63 = 57;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63_LEN = 7;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCMODE3 = 0x0c010c2full;

static const uint32_t MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10 = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10_LEN = 11;
// omi/reg00006.H

static const uint64_t MC1_PBI01_SCOMFIR_MCPERF1 = 0x0c010c10ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_DISABLE_FASTPATH = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT = 5;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH = 10;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT = 17;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST = 21;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE = 22;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH = 23;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE = 30;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE = 32;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN = 5;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD = 37;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE = 38;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN = 5;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_RESERVED_43_63 = 43;
static const uint32_t MC1_PBI01_SCOMFIR_MCPERF1_RESERVED_43_63_LEN = 21;
// omi/reg00007.H

static const uint64_t MC1_PBI01_SCOMFIR_MCSYNC = 0x0c010c15ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCSYNC_CHANNEL_SELECT = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCSYNC_CHANNEL_SELECT_LEN = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCSYNC_SYNC_TYPE = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCSYNC_SYNC_TYPE_LEN = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCSYNC_SYNC_GO = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCSYNC_SYNC_RESERVED = 17;
static const uint32_t MC1_PBI01_SCOMFIR_MCSYNC_SYNC_RESERVED_LEN = 8;
// omi/reg00007.H

static const uint64_t MC1_PBI01_SCOMFIR_MCTO = 0x0c010c1bull;

static const uint32_t MC1_PBI01_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_RPT_HANG_SELECT = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_RPT_HANG_SELECT_LEN = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_RESERVED_4 = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_CL_TIMEOUT_VALUE = 5;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_CL_TIMEOUT_VALUE_LEN = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_LOCAL_HANG_COMP = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_LOCAL_HANG_COMP_LEN = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_HANG_COMP = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_HANG_COMP_LEN = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG = 32;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG = 33;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_ENABLE_APO_HANG = 34;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_ENABLE_CLIB_HANG = 35;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG = 36;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE = 37;
static const uint32_t MC1_PBI01_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE_LEN = 3;
// omi/reg00007.H

static const uint64_t MC1_PBI01_SCOMFIR_MCWATACT = 0x0c010c18ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION = 1;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION = 2;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION = 3;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS = 4;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS = 5;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS = 6;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH = 8;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH = 9;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH = 10;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH = 11;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH = 12;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH = 13;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH = 14;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH = 15;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT = 16;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT = 17;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT = 18;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT = 19;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 = 20;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 = 21;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 = 22;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 = 23;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_RESERVED_36_47 = 24;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATACT_RESERVED_36_47_LEN = 16;
// omi/reg00007.H

static const uint64_t MC1_PBI01_SCOMFIR_MCWATCNTL2 = 0x0c010c19ull;

static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL0 = 0;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL0_LEN = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL1 = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL1_LEN = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL2 = 14;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL2_LEN = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL3 = 21;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL3_LEN = 7;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_RESERVED_28_49 = 28;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_RESERVED_28_49_LEN = 22;
static const uint32_t MC1_PBI01_SCOMFIR_MCWATCNTL2_CL_EARLY_HANG_MODE = 50;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSLTWAT = 0x0c010d11ull;

static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU = 0;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN = 6;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN = 10;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN = 12;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN = 14;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN = 16;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN = 18;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN = 20;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN = 22;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_RESERVED_24_62 = 24;
static const uint32_t MC2_CHAN0_DSTL_DSLTWAT_RESERVED_24_62_LEN = 39;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLCFG = 0x0c010d0bull;

static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_TMPL0_ONLY = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_RESERVED_1 = 1;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_TMPL7_ENABLE = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_TMPL1_DIS = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_FAST_RD_DISABLE = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_RESERVED_5 = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_TMPL4_DISABLE = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS = 7;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_READ_THRESHOLD = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_READ_THRESHOLD_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_WR_TMP4_THRESHOLD = 16;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_RESERVED_20_23 = 20;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_RESERVED_20_23_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_WR_DBL_THRESHOLD = 24;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_CRITICAL_OW_DIS = 28;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_ENABLE_SPEC_ATTN = 29;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_ENABLE_HOST_ATTN = 30;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_DEBUG_EN = 31;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_DEBUG_LOCAL_SWAP = 32;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_DEBUG_PASSTHRU = 33;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_DEBUG_PASSTHRU_LEN = 11;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_WRAP_MODE_EN = 44;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH = 45;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_TIMEOUT_MODE = 49;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_TIMEOUT_MODE_LEN = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_MMIO_ADDRBIT_POS = 52;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_RESET_CREDITS = 57;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET = 58;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET = 59;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_CREDITS_ON_DEBUG_BUS = 60;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_RESERVED_61_63 = 61;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG_RESERVED_61_63_LEN = 3;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLCFG2 = 0x0c010d0eull;

static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING = 12;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET = 16;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET = 17;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE = 18;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE = 19;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED = 20;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED = 21;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN = 22;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN = 23;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT = 24;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT = 25;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP = 26;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP = 27;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR = 28;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR = 29;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE = 30;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE = 31;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_RESERVED_32_35 = 32;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_RESERVED_32_35_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS = 36;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT = 37;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT = 38;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS = 39;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE = 40;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET = 43;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT = 44;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_RESERVED_45 = 45;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL = 46;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_RESERVED_47_62 = 47;
static const uint32_t MC2_CHAN0_DSTL_DSTLCFG2_RESERVED_47_62_LEN = 16;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLCREDIT = 0x0c010d0aull;

static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT = 12;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT = 17;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN = 7;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_VC0_CREDIT_INIT = 28;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_VC1_CREDIT_INIT = 36;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT = 42;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL = 50;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL = 58;
static const uint32_t MC2_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN = 6;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLERRRPT = 0x0c010d0cull;

static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 1;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT = 7;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT = 9;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT = 10;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 11;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 12;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT = 13;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT = 14;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 15;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT = 16;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT = 17;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT = 18;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT = 19;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT = 20;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT = 21;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT = 22;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT = 23;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT = 24;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT = 25;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT = 26;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT = 27;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT = 28;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT = 29;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT = 30;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT = 31;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT = 32;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT = 33;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT = 34;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT = 35;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 36;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 37;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 38;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 39;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT = 40;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT = 41;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE = 62;
static const uint32_t MC2_CHAN0_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE = 63;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLFIR_RWX = 0x0c010d00ull;
static const uint64_t MC2_CHAN0_DSTL_DSTLFIR_WOX_AND = 0x0c010d01ull;
static const uint64_t MC2_CHAN0_DSTL_DSTLFIR_WOX_OR = 0x0c010d02ull;

static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION = 1;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT = 7;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_CMD_WRDATA_PARITY_ERROR = 9;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR = 10;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR = 11;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR = 12;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR = 13;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR = 14;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR = 15;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR = 16;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR = 17;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN = 18;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN = 19;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT = 22;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT = 23;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SPARE24 = 24;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_SPARE25 = 25;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_DECRYPT_ERR_INFO = 26;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_ENCRYPT_ERR_INFO = 29;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN = 4;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLFIRACT0 = 0x0c010d06ull;

static const uint32_t MC2_CHAN0_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 33;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLFIRMASK_RW = 0x0c010d03ull;
static const uint64_t MC2_CHAN0_DSTL_DSTLFIRMASK_WO_AND = 0x0c010d04ull;
static const uint64_t MC2_CHAN0_DSTL_DSTLFIRMASK_WO_OR = 0x0c010d05ull;

static const uint32_t MC2_CHAN0_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 33;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLFIRWOF = 0x0c010d08ull;

static const uint32_t MC2_CHAN0_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN = 33;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLINJ = 0x0c010d0dull;

static const uint32_t MC2_CHAN0_DSTL_DSTLINJ_ERR_INJ_TRIGGER = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLINJ_ERR_INJ_CONT_MODE = 1;
static const uint32_t MC2_CHAN0_DSTL_DSTLINJ_ERR_INJ_TYPE = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLINJ_RESERVED_4_15 = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLINJ_RESERVED_4_15_LEN = 12;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLPSAVE0 = 0x0c010d12ull;

static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE = 16;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH = 18;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE = 21;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT = 24;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL = 32;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL = 36;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_RESERVED_40_47 = 40;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE0_RESERVED_40_47_LEN = 8;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLPSAVE1 = 0x0c010d13ull;

static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_RESERVED_59_63 = 59;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE1_RESERVED_59_63_LEN = 5;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLPSAVE2 = 0x0c010d14ull;

static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_RESERVED_59_63 = 59;
static const uint32_t MC2_CHAN0_DSTL_DSTLPSAVE2_RESERVED_59_63_LEN = 5;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLSTATUS = 0x0c010d10ull;

static const uint32_t MC2_CHAN0_DSTL_DSTLSTATUS_A_FAIL_WOF = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLSTATUS_A_FAIL_WOF_LEN = 10;
static const uint32_t MC2_CHAN0_DSTL_DSTLSTATUS_B_FAIL_WOF = 10;
static const uint32_t MC2_CHAN0_DSTL_DSTLSTATUS_B_FAIL_WOF_LEN = 10;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_DSTL_DSTLTRACK = 0x0c010d0full;

static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE = 0;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE = 12;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE = 18;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE = 24;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE = 28;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW = 34;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN = 6;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW = 44;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN = 4;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW = 50;
static const uint32_t MC2_CHAN0_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN = 7;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLBADRESP = 0x0c010e10ull;

static const uint32_t MC2_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_VAL = 0;
static const uint32_t MC2_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE = 1;
static const uint32_t MC2_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD = 2;
static const uint32_t MC2_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_TAG = 3;
static const uint32_t MC2_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN = 6;
static const uint32_t MC2_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_VAL = 9;
static const uint32_t MC2_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE = 10;
static const uint32_t MC2_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD = 11;
static const uint32_t MC2_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_TAG = 12;
static const uint32_t MC2_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN = 6;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLCFG = 0x0c010e0bull;

static const uint32_t MC2_CHAN0_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE = 0;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE = 1;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_FAIL_CAPTURE_CONFIG = 2;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE = 4;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA = 5;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA_LEN = 2;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO = 7;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE = 8;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_LOWLAT_MISS_015_DELAY = 9;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN = 3;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_ET_DISABLE = 16;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE = 17;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE = 18;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_TEMPLATE1_ENABLE = 19;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_ENABLE = 20;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT = 21;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT_LEN = 3;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE = 24;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN = 7;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE = 32;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT = 33;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN = 3;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS = 36;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_DL_WIDTH_HALF_ENABLE = 37;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD = 40;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN = 4;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_CFG_ENABLE_SPEC_ATTN = 44;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_CFG_ENABLE_HOST_ATTN = 45;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_CFG_WRAP_MODE = 46;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_RESERVED_47 = 47;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE = 48;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_LOL_LFSR_RATE_SEL = 49;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN = 3;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_LOL_CAPTURE_CONFIG = 54;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_LAST_OPENCAPI_ENABLE = 56;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW = 57;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_PMU_SELECT_FAIL_RSP = 58;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_PMU_ENABLE = 59;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_PMU_SELECT_ALT_PERF = 60;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_CS_HW477424_DISABLE = 61;
static const uint32_t MC2_CHAN0_USTL_USTLCFG_CS_HW475333_DISABLE = 62;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLCFWOF = 0x0c010e15ull;

static const uint32_t MC2_CHAN0_USTL_USTLCFWOF_A_CHANFAIL_WOF = 0;
static const uint32_t MC2_CHAN0_USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN = 16;
static const uint32_t MC2_CHAN0_USTL_USTLCFWOF_B_CHANFAIL_WOF = 16;
static const uint32_t MC2_CHAN0_USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN = 16;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLDBG = 0x0c010e0dull;

static const uint32_t MC2_CHAN0_USTL_USTLDBG_ENABLE = 0;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_SEL_TOP = 8;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_SEL_WR_TOP = 9;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_SEL_BOT = 10;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_SEL_WR_BOT = 11;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_SEL_FLIT = 12;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_SEL_FLIT_CHANB = 13;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_SEL_MIRRORLOG_VLDS = 14;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_SPARE = 15;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_WAT_ENABLE0 = 16;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_WAT_ENABLE0_LEN = 2;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_WAT_ENABLE1 = 18;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_WAT_ENABLE1_LEN = 2;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_WAT_ENABLE2 = 20;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_WAT_ENABLE2_LEN = 2;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_WAT_ENABLE3 = 22;
static const uint32_t MC2_CHAN0_USTL_USTLDBG_WAT_ENABLE3_LEN = 2;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLERRPT = 0x0c010e16ull;

static const uint32_t MC2_CHAN0_USTL_USTLERRPT_WDF_CMT_PAR_ERR = 0;
static const uint32_t MC2_CHAN0_USTL_USTLERRPT_WDF_CMD_PAR_ERR = 1;
static const uint32_t MC2_CHAN0_USTL_USTLERRPT_WRT_NO_BUFF_ERR = 2;
static const uint32_t MC2_CHAN0_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR = 3;
static const uint32_t MC2_CHAN0_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR = 4;
static const uint32_t MC2_CHAN0_USTL_USTLERRPT_WDF_NO_BUFF_ERR = 5;
static const uint32_t MC2_CHAN0_USTL_USTLERRPT_RESERVED = 6;
static const uint32_t MC2_CHAN0_USTL_USTLERRPT_RESERVED_LEN = 10;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLERRRPT = 0x0c010e0eull;

static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT = 0;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 1;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 2;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT = 3;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT = 4;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 5;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 6;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT = 7;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT = 8;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT = 9;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT = 10;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT = 11;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT = 12;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT = 13;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT = 14;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT = 15;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 16;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT = 17;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT = 18;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT = 19;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT = 20;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT = 21;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT = 22;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 23;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT = 24;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT = 25;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT = 26;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT = 27;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT = 28;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT = 29;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT = 30;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA = 31;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT = 32;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT = 33;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT = 34;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT = 36;
static const uint32_t MC2_CHAN0_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT = 37;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLFAILMASK = 0x0c010e13ull;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLFIR_RWX = 0x0c010e00ull;
static const uint64_t MC2_CHAN0_USTL_USTLFIR_WOX_AND = 0x0c010e01ull;
static const uint64_t MC2_CHAN0_USTL_USTLFIR_WOX_OR = 0x0c010e02ull;

static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR = 0;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR = 1;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR = 2;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR = 3;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_HALF_SPEED_MODE = 4;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_HALF_SPEED_MODE = 5;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WDF_BUFFER_CE = 6;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WDF_BUFFER_UE = 7;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WDF_BUFFER_SUE = 8;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WDF_BUFFER_OVERRUN = 9;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WDF_TAG_PARITY_ERROR = 10;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR = 11;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR = 12;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR = 13;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_RESERVED_14 = 14;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 = 15;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WDF_CMT_PARITY_ERROR = 16;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_READ_SPARE_1 = 17;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_READ_SPARE_2 = 18;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR = 19;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WRT_BUFFER_CE = 20;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WRT_BUFFER_UE = 21;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WRT_BUFFER_SUE = 22;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR = 23;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR = 24;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 = 25;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_WRT_BUFF_ERR = 26;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP = 27;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP = 28;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER = 29;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER = 30;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP = 31;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP = 32;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER = 33;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER = 34;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR = 35;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR = 36;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR = 37;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR = 38;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL = 39;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL = 40;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS = 41;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS = 42;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO = 43;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO = 44;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE = 45;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE = 46;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_BAD_DATA = 47;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_BAD_DATA = 48;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR = 49;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR = 50;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR = 51;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR = 52;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR = 53;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR = 54;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR = 55;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR = 56;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_FATAL_REG_PARITY_ERROR = 57;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_RECOV_REG_PARITY_ERROR = 58;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO = 59;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO = 60;
static const uint32_t MC2_CHAN0_USTL_USTLFIR_SPARE_61 = 61;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLFIRACT0 = 0x0c010e06ull;

static const uint32_t MC2_CHAN0_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC2_CHAN0_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN = 62;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLFIRMASK_RW = 0x0c010e03ull;
static const uint64_t MC2_CHAN0_USTL_USTLFIRMASK_WO_AND = 0x0c010e04ull;
static const uint64_t MC2_CHAN0_USTL_USTLFIRMASK_WO_OR = 0x0c010e05ull;

static const uint32_t MC2_CHAN0_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC2_CHAN0_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN = 62;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLFIRWOF = 0x0c010e08ull;

static const uint32_t MC2_CHAN0_USTL_USTLFIRWOF_USTLFIRWOF_WOF = 0;
static const uint32_t MC2_CHAN0_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN = 62;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLINJ = 0x0c010e0cull;

static const uint32_t MC2_CHAN0_USTL_USTLINJ_FAIL_RESP_TYPE = 3;
static const uint32_t MC2_CHAN0_USTL_USTLINJ_FAIL_RESP_TYPE_LEN = 3;
static const uint32_t MC2_CHAN0_USTL_USTLINJ_FIR_INJECT = 8;
static const uint32_t MC2_CHAN0_USTL_USTLINJ_FIR_INJECT_LEN = 5;
static const uint32_t MC2_CHAN0_USTL_USTLINJ_US_DATA = 20;
static const uint32_t MC2_CHAN0_USTL_USTLINJ_US_DATA_LEN = 3;
static const uint32_t MC2_CHAN0_USTL_USTLINJ_CHAN_SEL = 24;
static const uint32_t MC2_CHAN0_USTL_USTLINJ_DATA_DW_SEL = 25;
static const uint32_t MC2_CHAN0_USTL_USTLINJ_US_DATA_ERR_EN = 26;
static const uint32_t MC2_CHAN0_USTL_USTLINJ_ONE_SHOT = 27;
static const uint32_t MC2_CHAN0_USTL_USTLINJ_DATA_OUT = 28;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLLOLDROP = 0x0c010e11ull;

static const uint32_t MC2_CHAN0_USTL_USTLLOLDROP_A_DROP_REASON = 0;
static const uint32_t MC2_CHAN0_USTL_USTLLOLDROP_A_DROP_REASON_LEN = 16;
static const uint32_t MC2_CHAN0_USTL_USTLLOLDROP_B_DROP_REASON = 32;
static const uint32_t MC2_CHAN0_USTL_USTLLOLDROP_B_DROP_REASON_LEN = 16;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLLOLMASK = 0x0c010e12ull;

static const uint32_t MC2_CHAN0_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t MC2_CHAN0_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN = 16;
static const uint32_t MC2_CHAN0_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK = 32;
static const uint32_t MC2_CHAN0_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN = 16;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLMCHWFM = 0x0c010e0full;

static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_ENABLE = 0;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_FAIL_THRESH = 1;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_FAIL_THRESH_LEN = 6;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_WINDOW_SIZE = 7;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_WINDOW_SIZE_LEN = 7;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_TSCALE = 14;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_TSCALE_LEN = 2;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_SCOM_COMMAND_VALID = 16;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_SCOM_COMMAND = 17;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT = 18;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_HWFM_STATUS = 19;
static const uint32_t MC2_CHAN0_USTL_USTLMCHWFM_HWFM_STATUS_LEN = 4;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLOCAPIERROR = 0x0c010e14ull;

static const uint32_t MC2_CHAN0_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID = 0;
static const uint32_t MC2_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE = 1;
static const uint32_t MC2_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN = 8;
static const uint32_t MC2_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION = 9;
static const uint32_t MC2_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN = 31;
// omi/reg00007.H

static const uint64_t MC2_CHAN0_USTL_USTLSTATUS = 0x0c010e0aull;

static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_LOL_MODE = 0;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_LOL_MODE = 1;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD = 2;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR = 3;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD = 4;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR = 5;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD = 6;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR = 7;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD = 8;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR = 9;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_FAIL_RESP = 10;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_FAIL_RESP_LEN = 4;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_WAT_FIRED = 24;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_WAT_FIRED = 25;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY = 32;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR = 33;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR = 34;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR = 35;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR = 36;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR = 37;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 38;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP = 39;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP = 40;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE = 41;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY = 42;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY = 43;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR = 44;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR = 45;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR = 46;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR = 47;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR = 48;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 49;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP = 50;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP = 51;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE = 52;
static const uint32_t MC2_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY = 53;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSLTWAT = 0x0c010d51ull;

static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU = 0;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN = 6;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN = 10;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN = 12;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN = 14;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN = 16;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN = 18;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN = 20;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN = 22;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_RESERVED_24_62 = 24;
static const uint32_t MC2_CHAN1_DSTL_DSLTWAT_RESERVED_24_62_LEN = 39;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLCFG = 0x0c010d4bull;

static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_TMPL0_ONLY = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_RESERVED_1 = 1;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_TMPL7_ENABLE = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_TMPL1_DIS = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_FAST_RD_DISABLE = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_RESERVED_5 = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_TMPL4_DISABLE = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS = 7;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_READ_THRESHOLD = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_READ_THRESHOLD_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_WR_TMP4_THRESHOLD = 16;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_RESERVED_20_23 = 20;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_RESERVED_20_23_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_WR_DBL_THRESHOLD = 24;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_CRITICAL_OW_DIS = 28;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_ENABLE_SPEC_ATTN = 29;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_ENABLE_HOST_ATTN = 30;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_DEBUG_EN = 31;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_DEBUG_LOCAL_SWAP = 32;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_DEBUG_PASSTHRU = 33;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_DEBUG_PASSTHRU_LEN = 11;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_WRAP_MODE_EN = 44;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH = 45;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_TIMEOUT_MODE = 49;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_TIMEOUT_MODE_LEN = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_MMIO_ADDRBIT_POS = 52;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_RESET_CREDITS = 57;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET = 58;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET = 59;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_CREDITS_ON_DEBUG_BUS = 60;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_RESERVED_61_63 = 61;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG_RESERVED_61_63_LEN = 3;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLCFG2 = 0x0c010d4eull;

static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING = 12;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET = 16;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET = 17;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE = 18;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE = 19;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED = 20;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED = 21;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN = 22;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN = 23;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT = 24;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT = 25;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP = 26;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP = 27;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR = 28;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR = 29;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE = 30;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE = 31;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_RESERVED_32_35 = 32;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_RESERVED_32_35_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS = 36;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT = 37;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT = 38;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS = 39;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE = 40;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET = 43;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT = 44;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_RESERVED_45 = 45;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL = 46;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_RESERVED_47_62 = 47;
static const uint32_t MC2_CHAN1_DSTL_DSTLCFG2_RESERVED_47_62_LEN = 16;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLCREDIT = 0x0c010d4aull;

static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT = 12;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT = 17;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN = 7;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_VC0_CREDIT_INIT = 28;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_VC1_CREDIT_INIT = 36;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT = 42;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL = 50;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL = 58;
static const uint32_t MC2_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN = 6;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLERRRPT = 0x0c010d4cull;

static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 1;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT = 7;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT = 9;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT = 10;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 11;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 12;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT = 13;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT = 14;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 15;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT = 16;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT = 17;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT = 18;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT = 19;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT = 20;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT = 21;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT = 22;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT = 23;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT = 24;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT = 25;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT = 26;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT = 27;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT = 28;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT = 29;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT = 30;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT = 31;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT = 32;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT = 33;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT = 34;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT = 35;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 36;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 37;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 38;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 39;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT = 40;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT = 41;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE = 62;
static const uint32_t MC2_CHAN1_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE = 63;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLFIR_RWX = 0x0c010d40ull;
static const uint64_t MC2_CHAN1_DSTL_DSTLFIR_WOX_AND = 0x0c010d41ull;
static const uint64_t MC2_CHAN1_DSTL_DSTLFIR_WOX_OR = 0x0c010d42ull;

static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION = 1;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT = 7;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_CMD_WRDATA_PARITY_ERROR = 9;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR = 10;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR = 11;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR = 12;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR = 13;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR = 14;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR = 15;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR = 16;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR = 17;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN = 18;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN = 19;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT = 22;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT = 23;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SPARE24 = 24;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_SPARE25 = 25;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_DECRYPT_ERR_INFO = 26;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_ENCRYPT_ERR_INFO = 29;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN = 4;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLFIRACT0 = 0x0c010d46ull;

static const uint32_t MC2_CHAN1_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 33;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLFIRMASK_RW = 0x0c010d43ull;
static const uint64_t MC2_CHAN1_DSTL_DSTLFIRMASK_WO_AND = 0x0c010d44ull;
static const uint64_t MC2_CHAN1_DSTL_DSTLFIRMASK_WO_OR = 0x0c010d45ull;

static const uint32_t MC2_CHAN1_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 33;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLFIRWOF = 0x0c010d48ull;

static const uint32_t MC2_CHAN1_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN = 33;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLINJ = 0x0c010d4dull;

static const uint32_t MC2_CHAN1_DSTL_DSTLINJ_ERR_INJ_TRIGGER = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLINJ_ERR_INJ_CONT_MODE = 1;
static const uint32_t MC2_CHAN1_DSTL_DSTLINJ_ERR_INJ_TYPE = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLINJ_RESERVED_4_15 = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLINJ_RESERVED_4_15_LEN = 12;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLPSAVE0 = 0x0c010d52ull;

static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE = 16;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH = 18;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE = 21;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT = 24;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL = 32;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL = 36;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_RESERVED_40_47 = 40;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE0_RESERVED_40_47_LEN = 8;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLPSAVE1 = 0x0c010d53ull;

static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_RESERVED_59_63 = 59;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE1_RESERVED_59_63_LEN = 5;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLPSAVE2 = 0x0c010d54ull;

static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_RESERVED_59_63 = 59;
static const uint32_t MC2_CHAN1_DSTL_DSTLPSAVE2_RESERVED_59_63_LEN = 5;
// omi/reg00007.H

static const uint64_t MC2_CHAN1_DSTL_DSTLSTATUS = 0x0c010d50ull;

static const uint32_t MC2_CHAN1_DSTL_DSTLSTATUS_A_FAIL_WOF = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLSTATUS_A_FAIL_WOF_LEN = 10;
static const uint32_t MC2_CHAN1_DSTL_DSTLSTATUS_B_FAIL_WOF = 10;
static const uint32_t MC2_CHAN1_DSTL_DSTLSTATUS_B_FAIL_WOF_LEN = 10;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_DSTL_DSTLTRACK = 0x0c010d4full;

static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE = 0;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE = 12;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE = 18;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE = 24;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE = 28;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW = 34;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN = 6;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW = 44;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN = 4;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW = 50;
static const uint32_t MC2_CHAN1_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN = 7;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLBADRESP = 0x0c010e50ull;

static const uint32_t MC2_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_VAL = 0;
static const uint32_t MC2_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE = 1;
static const uint32_t MC2_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD = 2;
static const uint32_t MC2_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_TAG = 3;
static const uint32_t MC2_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN = 6;
static const uint32_t MC2_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_VAL = 9;
static const uint32_t MC2_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE = 10;
static const uint32_t MC2_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD = 11;
static const uint32_t MC2_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_TAG = 12;
static const uint32_t MC2_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN = 6;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLCFG = 0x0c010e4bull;

static const uint32_t MC2_CHAN1_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE = 0;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE = 1;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_FAIL_CAPTURE_CONFIG = 2;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE = 4;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA = 5;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA_LEN = 2;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO = 7;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE = 8;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_LOWLAT_MISS_015_DELAY = 9;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN = 3;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_ET_DISABLE = 16;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE = 17;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE = 18;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_TEMPLATE1_ENABLE = 19;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_ENABLE = 20;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT = 21;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT_LEN = 3;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE = 24;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN = 7;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE = 32;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT = 33;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN = 3;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS = 36;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_DL_WIDTH_HALF_ENABLE = 37;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD = 40;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN = 4;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_CFG_ENABLE_SPEC_ATTN = 44;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_CFG_ENABLE_HOST_ATTN = 45;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_CFG_WRAP_MODE = 46;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_RESERVED_47 = 47;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE = 48;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_LOL_LFSR_RATE_SEL = 49;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN = 3;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_LOL_CAPTURE_CONFIG = 54;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_LAST_OPENCAPI_ENABLE = 56;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW = 57;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_PMU_SELECT_FAIL_RSP = 58;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_PMU_ENABLE = 59;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_PMU_SELECT_ALT_PERF = 60;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_CS_HW477424_DISABLE = 61;
static const uint32_t MC2_CHAN1_USTL_USTLCFG_CS_HW475333_DISABLE = 62;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLCFWOF = 0x0c010e55ull;

static const uint32_t MC2_CHAN1_USTL_USTLCFWOF_A_CHANFAIL_WOF = 0;
static const uint32_t MC2_CHAN1_USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN = 16;
static const uint32_t MC2_CHAN1_USTL_USTLCFWOF_B_CHANFAIL_WOF = 16;
static const uint32_t MC2_CHAN1_USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN = 16;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLDBG = 0x0c010e4dull;

static const uint32_t MC2_CHAN1_USTL_USTLDBG_ENABLE = 0;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_SEL_TOP = 8;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_SEL_WR_TOP = 9;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_SEL_BOT = 10;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_SEL_WR_BOT = 11;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_SEL_FLIT = 12;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_SEL_FLIT_CHANB = 13;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_SEL_MIRRORLOG_VLDS = 14;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_SPARE = 15;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_WAT_ENABLE0 = 16;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_WAT_ENABLE0_LEN = 2;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_WAT_ENABLE1 = 18;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_WAT_ENABLE1_LEN = 2;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_WAT_ENABLE2 = 20;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_WAT_ENABLE2_LEN = 2;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_WAT_ENABLE3 = 22;
static const uint32_t MC2_CHAN1_USTL_USTLDBG_WAT_ENABLE3_LEN = 2;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLERRPT = 0x0c010e56ull;

static const uint32_t MC2_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR = 0;
static const uint32_t MC2_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR = 1;
static const uint32_t MC2_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR = 2;
static const uint32_t MC2_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR = 3;
static const uint32_t MC2_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR = 4;
static const uint32_t MC2_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR = 5;
static const uint32_t MC2_CHAN1_USTL_USTLERRPT_RESERVED = 6;
static const uint32_t MC2_CHAN1_USTL_USTLERRPT_RESERVED_LEN = 10;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLERRRPT = 0x0c010e4eull;

static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT = 0;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 1;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 2;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT = 3;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT = 4;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 5;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 6;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT = 7;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT = 8;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT = 9;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT = 10;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT = 11;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT = 12;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT = 13;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT = 14;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT = 15;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 16;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT = 17;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT = 18;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT = 19;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT = 20;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT = 21;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT = 22;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 23;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT = 24;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT = 25;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT = 26;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT = 27;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT = 28;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT = 29;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT = 30;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA = 31;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT = 32;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT = 33;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT = 34;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT = 36;
static const uint32_t MC2_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT = 37;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLFAILMASK = 0x0c010e53ull;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLFIR_RWX = 0x0c010e40ull;
static const uint64_t MC2_CHAN1_USTL_USTLFIR_WOX_AND = 0x0c010e41ull;
static const uint64_t MC2_CHAN1_USTL_USTLFIR_WOX_OR = 0x0c010e42ull;

static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR = 0;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR = 1;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR = 2;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR = 3;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE = 4;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE = 5;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE = 6;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE = 7;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE = 8;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN = 9;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR = 10;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR = 11;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR = 12;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR = 13;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_RESERVED_14 = 14;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 = 15;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR = 16;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_READ_SPARE_1 = 17;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_READ_SPARE_2 = 18;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR = 19;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE = 20;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE = 21;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE = 22;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR = 23;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR = 24;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 = 25;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR = 26;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP = 27;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP = 28;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER = 29;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER = 30;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP = 31;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP = 32;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER = 33;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER = 34;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR = 35;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR = 36;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR = 37;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR = 38;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL = 39;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL = 40;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS = 41;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS = 42;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO = 43;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO = 44;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE = 45;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE = 46;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA = 47;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA = 48;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR = 49;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR = 50;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR = 51;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR = 52;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR = 53;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR = 54;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR = 55;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR = 56;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR = 57;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR = 58;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO = 59;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO = 60;
static const uint32_t MC2_CHAN1_USTL_USTLFIR_SPARE_61 = 61;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLFIRACT0 = 0x0c010e46ull;

static const uint32_t MC2_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC2_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN = 62;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLFIRMASK_RW = 0x0c010e43ull;
static const uint64_t MC2_CHAN1_USTL_USTLFIRMASK_WO_AND = 0x0c010e44ull;
static const uint64_t MC2_CHAN1_USTL_USTLFIRMASK_WO_OR = 0x0c010e45ull;

static const uint32_t MC2_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC2_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN = 62;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLFIRWOF = 0x0c010e48ull;

static const uint32_t MC2_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF = 0;
static const uint32_t MC2_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN = 62;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLINJ = 0x0c010e4cull;

static const uint32_t MC2_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE = 3;
static const uint32_t MC2_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE_LEN = 3;
static const uint32_t MC2_CHAN1_USTL_USTLINJ_FIR_INJECT = 8;
static const uint32_t MC2_CHAN1_USTL_USTLINJ_FIR_INJECT_LEN = 5;
static const uint32_t MC2_CHAN1_USTL_USTLINJ_US_DATA = 20;
static const uint32_t MC2_CHAN1_USTL_USTLINJ_US_DATA_LEN = 3;
static const uint32_t MC2_CHAN1_USTL_USTLINJ_CHAN_SEL = 24;
static const uint32_t MC2_CHAN1_USTL_USTLINJ_DATA_DW_SEL = 25;
static const uint32_t MC2_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN = 26;
static const uint32_t MC2_CHAN1_USTL_USTLINJ_ONE_SHOT = 27;
static const uint32_t MC2_CHAN1_USTL_USTLINJ_DATA_OUT = 28;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLLOLDROP = 0x0c010e51ull;

static const uint32_t MC2_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON = 0;
static const uint32_t MC2_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON_LEN = 16;
static const uint32_t MC2_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON = 32;
static const uint32_t MC2_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON_LEN = 16;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLLOLMASK = 0x0c010e52ull;

static const uint32_t MC2_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t MC2_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN = 16;
static const uint32_t MC2_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK = 32;
static const uint32_t MC2_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN = 16;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLMCHWFM = 0x0c010e4full;

static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_ENABLE = 0;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH = 1;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH_LEN = 6;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE = 7;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE_LEN = 7;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_TSCALE = 14;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_TSCALE_LEN = 2;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID = 16;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND = 17;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT = 18;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS = 19;
static const uint32_t MC2_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS_LEN = 4;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLOCAPIERROR = 0x0c010e54ull;

static const uint32_t MC2_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID = 0;
static const uint32_t MC2_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE = 1;
static const uint32_t MC2_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN = 8;
static const uint32_t MC2_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION = 9;
static const uint32_t MC2_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN = 31;
// omi/reg00008.H

static const uint64_t MC2_CHAN1_USTL_USTLSTATUS = 0x0c010e4aull;

static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE = 0;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE = 1;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD = 2;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR = 3;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD = 4;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR = 5;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD = 6;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR = 7;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD = 8;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR = 9;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_FAIL_RESP = 10;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_FAIL_RESP_LEN = 4;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED = 24;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED = 25;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY = 32;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR = 33;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR = 34;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR = 35;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR = 36;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR = 37;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 38;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP = 39;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP = 40;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE = 41;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY = 42;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY = 43;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR = 44;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR = 45;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR = 46;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR = 47;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR = 48;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 49;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP = 50;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP = 51;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE = 52;
static const uint32_t MC2_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY = 53;
// omi/reg00008.H

static const uint64_t MC2_MISC_CLKMON_MONM_CLKRATIO = 0x0c010ff0ull;

static const uint32_t MC2_MISC_CLKMON_MONM_CLKRATIO_RATIO = 0;
static const uint32_t MC2_MISC_CLKMON_MONM_CLKRATIO_RATIO_LEN = 12;
static const uint32_t MC2_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE = 12;
static const uint32_t MC2_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE = 13;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_AACR = 0x0c010f29ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_AACR_BUFFER = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_AACR_ADDRESS = 1;
static const uint32_t MC2_MISC_MBA_SCOMFIR_AACR_ADDRESS_LEN = 10;
static const uint32_t MC2_MISC_MBA_SCOMFIR_AACR_AUTOINC = 11;
static const uint32_t MC2_MISC_MBA_SCOMFIR_AACR_ECCGEN = 12;
static const uint32_t MC2_MISC_MBA_SCOMFIR_AACR_CHANNEL = 13;
static const uint32_t MC2_MISC_MBA_SCOMFIR_AACR_CHANNEL_LEN = 2;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_AADR = 0x0c010f2aull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_AADR_AADR_DATA_LEN = 64;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_AAER = 0x0c010f2bull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC_LEN = 9;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_DBG0_SCOM0Q = 0x0c010f94ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63 = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63_LEN = 64;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_DBG0_SCOM1Q = 0x0c010f95ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87 = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87_LEN = 24;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED = 24;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED_LEN = 40;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_DBG1_SCOM0Q = 0x0c010f96ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN = 64;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_DBG1_SCOM1Q = 0x0c010f97ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87 = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87_LEN = 24;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED = 24;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED_LEN = 40;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q = 0x0c010fe8ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01 = 1;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01_LEN = 11;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23 = 12;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23_LEN = 11;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI = 23;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44 = 24;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44_LEN = 21;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER = 45;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET = 46;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM = 47;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q = 0x0c010fe9ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT = 1;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL = 3;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL_LEN = 20;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL = 23;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL_LEN = 20;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL = 43;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL_LEN = 20;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63 = 63;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_DBGCFG2Q = 0x0c010feaull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL_LEN = 20;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL = 20;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL_LEN = 20;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL = 40;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL_LEN = 20;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63 = 60;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63_LEN = 4;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q = 0x0c010febull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL_LEN = 20;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL = 20;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22 = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL = 23;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25 = 25;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL = 26;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28 = 28;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL = 29;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32 = 31;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE = 33;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE = 37;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE = 41;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE = 45;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE_LEN = 6;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE = 51;
static const uint32_t MC2_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE_LEN = 8;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ = 0x0c010fe7ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT = 1;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT = 5;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT = 6;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT = 7;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT = 8;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT = 9;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT = 10;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT = 11;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT = 12;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT = 13;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT = 14;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT = 15;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT = 16;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT = 17;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT = 18;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT = 19;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT = 20;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBCFGQ = 0x0c010fe0ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER = 10;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN = 62;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN = 63;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRACT0 = 0x0c010f06ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0 = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0_LEN = 14;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRMASK_RW = 0x0c010f03ull;
static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_AND = 0x0c010f04ull;
static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_OR = 0x0c010f05ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK_LEN = 14;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_RWX = 0x0c010f00ull;
static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_AND = 0x0c010f01ull;
static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_OR = 0x0c010f02ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE = 1;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3 = 3;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT = 5;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT = 6;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT = 7;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT = 8;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT = 9;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT = 10;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT = 11;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR = 12;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE = 13;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRWOF = 0x0c010f08ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF_LEN = 14;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCBPARMQ = 0x0c010fafull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN = 59;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG = 0x0c010f98ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE = 1;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE = 3;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN0 = 0x0c010fa4ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN1 = 0x0c010fa5ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN2 = 0x0c010fa6ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN3 = 0x0c010fa7ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN3_N = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN3_N_LEN = 16;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE = 16;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT = 17;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT_LEN = 3;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL = 0x0c010f99ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM = 1;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER = 3;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT = 8;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT = 10;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT = 12;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL = 14;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15 = 15;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT = 16;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18 = 18;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT = 19;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21 = 21;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24 = 24;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT = 25;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27 = 27;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE = 28;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT = 29;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT = 33;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT_LEN = 7;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT = 40;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT_LEN = 5;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT = 45;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG = 49;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG_LEN = 9;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59 = 58;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59_LEN = 2;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE = 60;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET = 61;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS = 62;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63 = 63;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0 = 0x0c010f9aull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN = 6;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE = 6;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN = 8;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT = 16;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT = 20;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT = 24;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT = 28;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT = 32;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN = 4;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT = 36;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN = 4;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATDATA1 = 0x0c010f9bull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A_LEN = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A_LEN = 22;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATDATA2 = 0x0c010f9cull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B_LEN = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B_LEN = 22;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATDATA3 = 0x0c010f9dull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A_LEN = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A_LEN = 22;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATDATA4 = 0x0c010f9eull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN = 22;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATDATA5 = 0x0c010f9full;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A_LEN = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A_LEN = 22;
// omi/reg00008.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATDATA6 = 0x0c010fa0ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN = 22;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATDATA7 = 0x0c010fa1ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A_LEN = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A_LEN = 22;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATDATA8 = 0x0c010fa2ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B = 22;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN = 22;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_MCWATDATA9 = 0x0c010fa3ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN = 46;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL = 47;
static const uint32_t MC2_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN = 17;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_SPARE = 0x0c010f0full;

static const uint32_t MC2_MISC_MBA_SCOMFIR_SPARE_SPARE = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_SPARE_SPARE_LEN = 8;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_WATCFG0AQ = 0x0c010f80ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN = 48;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_WATCFG0BQ = 0x0c010f81ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA_LEN = 44;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL = 44;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL_LEN = 17;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_WATCFG0CQ = 0x0c010f82ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB_LEN = 44;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_WATCFG0DQ = 0x0c010f83ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA_LEN = 44;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_WATCFG0EQ = 0x0c010f84ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB_LEN = 44;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_WATCFG1AQ = 0x0c010f85ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL_LEN = 48;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_WATCFG1BQ = 0x0c010f86ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA_LEN = 44;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL = 44;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL_LEN = 17;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_WATCFG1CQ = 0x0c010f87ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB_LEN = 44;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_WATCFG1DQ = 0x0c010f88ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA_LEN = 44;
// omi/reg00009.H

static const uint64_t MC2_MISC_MBA_SCOMFIR_WATCFG1EQ = 0x0c010f89ull;

static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB = 0;
static const uint32_t MC2_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB_LEN = 44;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_AACR = 0x0c010c2cull;

static const uint32_t MC2_PBI01_SCOMFIR_AACR_BUFFER = 0;
static const uint32_t MC2_PBI01_SCOMFIR_AACR_ADDRESS = 1;
static const uint32_t MC2_PBI01_SCOMFIR_AACR_ADDRESS_LEN = 9;
static const uint32_t MC2_PBI01_SCOMFIR_AACR_AUTOINC = 10;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_AADR = 0x0c010c2dull;

static const uint32_t MC2_PBI01_SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t MC2_PBI01_SCOMFIR_AADR_AADR_DATA_LEN = 64;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_AAER = 0x0c010c2eull;

static const uint32_t MC2_PBI01_SCOMFIR_AAER_AAER_TAG_ECC = 0;
static const uint32_t MC2_PBI01_SCOMFIR_AAER_AAER_TAG_ECC_LEN = 9;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCERPT0 = 0x0c010c1eull;

static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR = 5;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR = 9;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR = 10;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR = 11;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR = 12;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR = 13;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR = 14;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR = 17;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR = 18;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR = 20;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR = 21;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR = 22;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR = 23;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR = 29;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR = 30;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR = 31;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR = 32;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR = 33;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR = 38;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR = 39;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR = 40;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR = 41;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR = 42;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR = 43;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR = 44;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR = 45;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR = 46;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR = 47;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR = 48;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR = 49;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 = 51;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR = 52;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 = 53;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR = 54;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 = 55;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR = 56;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 = 57;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR = 58;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR = 59;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR = 60;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR = 61;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCERPT1 = 0x0c010c1full;

static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT = 23;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT = 33;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT = 34;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q = 44;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q_LEN = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q = 51;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q_LEN = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3 = 60;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3 = 61;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3 = 62;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3 = 63;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCERPT2 = 0x0c010c1aull;

static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR = 5;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR = 9;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE = 11;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE = 12;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT = 13;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT = 14;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR = 17;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR = 18;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT = 20;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT = 21;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT = 22;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT = 23;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT = 25;
static const uint32_t MC2_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT = 26;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGP0 = 0x0c010c0aull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_0_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE = 25;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP = 40;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION = 43;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE = 46;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE = 54;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN = 8;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGP0A = 0x0c010c0eull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21 = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21_LEN = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_SMF_VALID = 22;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGP0E = 0x0c010c16ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0E_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS = 21;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS_LEN = 19;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGP1 = 0x0c010c0bull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_1_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE = 25;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE_LEN = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP = 40;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP_LEN = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION = 43;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION_LEN = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE = 46;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE_LEN = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE = 54;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE_LEN = 8;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGP1A = 0x0c010c0full;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21 = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21_LEN = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_SMF_VALID = 22;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGP1E = 0x0c010c17ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1E_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS = 21;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN = 19;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGPM0 = 0x0c010c20ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE = 25;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE_LEN = 15;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGPM0A = 0x0c010c21ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21 = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID = 22;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGPM0E = 0x0c010c1cull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0E_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS = 21;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS_LEN = 19;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGPM1 = 0x0c010c30ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE = 25;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE_LEN = 15;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGPM1A = 0x0c010c31ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21 = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21_LEN = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID = 22;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGPM1E = 0x0c010c1dull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1E_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS = 21;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS_LEN = 19;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGPR0 = 0x0c010c0cull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS_LEN = 31;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS = 33;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS_LEN = 31;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFGPR1 = 0x0c010c0dull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS_LEN = 31;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS = 33;
static const uint32_t MC2_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS_LEN = 31;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFIR_RWX = 0x0c010c00ull;
static const uint64_t MC2_PBI01_SCOMFIR_MCFIR_WOX_AND = 0x0c010c01ull;
static const uint64_t MC2_PBI01_SCOMFIR_MCFIR_WOX_OR = 0x0c010c02ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 = 5;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_RESERVED_6 = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_RESERVED_7 = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_RESERVED_9 = 9;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_RESERVED_10 = 10;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_MCS_WAT0 = 11;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_MCS_WAT1 = 12;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_MCS_WAT2 = 13;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_MCS_WAT3 = 14;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR = 17;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_RESERVED_18 = 18;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_RESERVED_19 = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_RESERVED_20 = 20;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_RESERVED_21 = 21;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS = 22;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIR_RESERVED_23 = 23;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFIRACT0 = 0x0c010c06ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN = 24;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFIRMASK_RW = 0x0c010c03ull;
static const uint64_t MC2_PBI01_SCOMFIR_MCFIRMASK_WO_AND = 0x0c010c04ull;
static const uint64_t MC2_PBI01_SCOMFIR_MCFIRMASK_WO_OR = 0x0c010c05ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK_LEN = 24;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCFIRWOF = 0x0c010c08ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF_LEN = 24;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCLFSR = 0x0c010c14ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT_LEN = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCLFSR_SERVED_2_4 = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCLFSR_SERVED_2_4_LEN = 3;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCMODE0 = 0x0c010c11ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_RESERVED_4 = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID = 5;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND = 9;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND = 10;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_RESERVED_11 = 11;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC = 12;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_RESERVED_13 = 13;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT = 14;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN = 10;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE = 25;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY = 32;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE = 36;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS = 37;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH = 40;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63 = 41;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63_LEN = 23;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCMODE1 = 0x0c010c12ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN = 10;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT = 10;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS = 11;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS = 17;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY = 18;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN = 9;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH = 28;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS = 32;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP = 33;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_CI = 52;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_CI_LEN = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS = 54;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_RESERVED_60 = 60;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS = 61;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW = 62;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE1_RESERVED_63 = 63;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCMODE2 = 0x0c010c13ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0 = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0_LEN = 13;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15 = 14;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15_LEN = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM = 17;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22 = 18;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22_LEN = 5;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR = 23;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES_LEN = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH = 40;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH_LEN = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN = 44;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN = 45;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52 = 46;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52_LEN = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE = 53;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE = 54;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE = 55;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE = 56;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63 = 57;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63_LEN = 7;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCMODE3 = 0x0c010c2full;

static const uint32_t MC2_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10 = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10_LEN = 11;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCPERF1 = 0x0c010c10ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_DISABLE_FASTPATH = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT = 5;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH = 10;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT = 17;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST = 21;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE = 22;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH = 23;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE = 30;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE = 32;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN = 5;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD = 37;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE = 38;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN = 5;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_RESERVED_43_63 = 43;
static const uint32_t MC2_PBI01_SCOMFIR_MCPERF1_RESERVED_43_63_LEN = 21;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCSYNC = 0x0c010c15ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCSYNC_CHANNEL_SELECT = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCSYNC_CHANNEL_SELECT_LEN = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCSYNC_SYNC_TYPE = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCSYNC_SYNC_TYPE_LEN = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCSYNC_SYNC_GO = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCSYNC_SYNC_RESERVED = 17;
static const uint32_t MC2_PBI01_SCOMFIR_MCSYNC_SYNC_RESERVED_LEN = 8;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCTO = 0x0c010c1bull;

static const uint32_t MC2_PBI01_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_RPT_HANG_SELECT = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_RPT_HANG_SELECT_LEN = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_RESERVED_4 = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_CL_TIMEOUT_VALUE = 5;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_CL_TIMEOUT_VALUE_LEN = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_LOCAL_HANG_COMP = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_LOCAL_HANG_COMP_LEN = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_HANG_COMP = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_HANG_COMP_LEN = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG = 32;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG = 33;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_ENABLE_APO_HANG = 34;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_ENABLE_CLIB_HANG = 35;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG = 36;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE = 37;
static const uint32_t MC2_PBI01_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE_LEN = 3;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCWATACT = 0x0c010c18ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION = 1;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION = 2;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION = 3;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS = 4;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS = 5;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS = 6;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH = 8;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH = 9;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH = 10;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH = 11;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH = 12;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH = 13;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH = 14;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH = 15;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT = 16;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT = 17;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT = 18;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT = 19;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 = 20;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 = 21;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 = 22;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 = 23;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_RESERVED_36_47 = 24;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATACT_RESERVED_36_47_LEN = 16;
// omi/reg00009.H

static const uint64_t MC2_PBI01_SCOMFIR_MCWATCNTL2 = 0x0c010c19ull;

static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL0 = 0;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL0_LEN = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL1 = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL1_LEN = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL2 = 14;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL2_LEN = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL3 = 21;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL3_LEN = 7;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_RESERVED_28_49 = 28;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_RESERVED_28_49_LEN = 22;
static const uint32_t MC2_PBI01_SCOMFIR_MCWATCNTL2_CL_EARLY_HANG_MODE = 50;
// omi/reg00009.H

static const uint64_t MC3_CHAN0_DSTL_DSLTWAT = 0x0c010d11ull;

static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU = 0;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN = 6;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN = 10;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN = 12;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN = 14;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN = 16;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN = 18;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN = 20;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN = 22;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_RESERVED_24_62 = 24;
static const uint32_t MC3_CHAN0_DSTL_DSLTWAT_RESERVED_24_62_LEN = 39;
// omi/reg00009.H

static const uint64_t MC3_CHAN0_DSTL_DSTLCFG = 0x0c010d0bull;

static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_TMPL0_ONLY = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_RESERVED_1 = 1;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_TMPL7_ENABLE = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_TMPL1_DIS = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_FAST_RD_DISABLE = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_RESERVED_5 = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_TMPL4_DISABLE = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS = 7;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_READ_THRESHOLD = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_READ_THRESHOLD_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_WR_TMP4_THRESHOLD = 16;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_RESERVED_20_23 = 20;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_RESERVED_20_23_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_WR_DBL_THRESHOLD = 24;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_CRITICAL_OW_DIS = 28;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_ENABLE_SPEC_ATTN = 29;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_ENABLE_HOST_ATTN = 30;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_DEBUG_EN = 31;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_DEBUG_LOCAL_SWAP = 32;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_DEBUG_PASSTHRU = 33;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_DEBUG_PASSTHRU_LEN = 11;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_WRAP_MODE_EN = 44;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH = 45;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_TIMEOUT_MODE = 49;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_TIMEOUT_MODE_LEN = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_MMIO_ADDRBIT_POS = 52;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_RESET_CREDITS = 57;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET = 58;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET = 59;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_CREDITS_ON_DEBUG_BUS = 60;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_RESERVED_61_63 = 61;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG_RESERVED_61_63_LEN = 3;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLCFG2 = 0x0c010d0eull;

static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING = 12;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET = 16;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET = 17;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE = 18;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE = 19;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED = 20;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED = 21;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN = 22;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN = 23;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT = 24;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT = 25;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP = 26;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP = 27;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR = 28;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR = 29;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE = 30;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE = 31;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_RESERVED_32_35 = 32;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_RESERVED_32_35_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS = 36;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT = 37;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT = 38;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS = 39;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE = 40;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET = 43;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT = 44;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_RESERVED_45 = 45;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL = 46;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_RESERVED_47_62 = 47;
static const uint32_t MC3_CHAN0_DSTL_DSTLCFG2_RESERVED_47_62_LEN = 16;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLCREDIT = 0x0c010d0aull;

static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT = 12;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT = 17;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN = 7;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_VC0_CREDIT_INIT = 28;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_VC1_CREDIT_INIT = 36;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT = 42;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL = 50;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL = 58;
static const uint32_t MC3_CHAN0_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN = 6;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLERRRPT = 0x0c010d0cull;

static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 1;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT = 7;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT = 9;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT = 10;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 11;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 12;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT = 13;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT = 14;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 15;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT = 16;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT = 17;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT = 18;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT = 19;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT = 20;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT = 21;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT = 22;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT = 23;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT = 24;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT = 25;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT = 26;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT = 27;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT = 28;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT = 29;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT = 30;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT = 31;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT = 32;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT = 33;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT = 34;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT = 35;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 36;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 37;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 38;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 39;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT = 40;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT = 41;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE = 62;
static const uint32_t MC3_CHAN0_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE = 63;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLFIR_RWX = 0x0c010d00ull;
static const uint64_t MC3_CHAN0_DSTL_DSTLFIR_WOX_AND = 0x0c010d01ull;
static const uint64_t MC3_CHAN0_DSTL_DSTLFIR_WOX_OR = 0x0c010d02ull;

static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION = 1;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT = 7;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_CMD_WRDATA_PARITY_ERROR = 9;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR = 10;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR = 11;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR = 12;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR = 13;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR = 14;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR = 15;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR = 16;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR = 17;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN = 18;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN = 19;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT = 22;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT = 23;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SPARE24 = 24;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_SPARE25 = 25;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_DECRYPT_ERR_INFO = 26;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_ENCRYPT_ERR_INFO = 29;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN = 4;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLFIRACT0 = 0x0c010d06ull;

static const uint32_t MC3_CHAN0_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 33;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLFIRMASK_RW = 0x0c010d03ull;
static const uint64_t MC3_CHAN0_DSTL_DSTLFIRMASK_WO_AND = 0x0c010d04ull;
static const uint64_t MC3_CHAN0_DSTL_DSTLFIRMASK_WO_OR = 0x0c010d05ull;

static const uint32_t MC3_CHAN0_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 33;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLFIRWOF = 0x0c010d08ull;

static const uint32_t MC3_CHAN0_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN = 33;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLINJ = 0x0c010d0dull;

static const uint32_t MC3_CHAN0_DSTL_DSTLINJ_ERR_INJ_TRIGGER = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLINJ_ERR_INJ_CONT_MODE = 1;
static const uint32_t MC3_CHAN0_DSTL_DSTLINJ_ERR_INJ_TYPE = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLINJ_RESERVED_4_15 = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLINJ_RESERVED_4_15_LEN = 12;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLPSAVE0 = 0x0c010d12ull;

static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE = 16;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH = 18;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE = 21;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT = 24;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL = 32;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL = 36;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_RESERVED_40_47 = 40;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE0_RESERVED_40_47_LEN = 8;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLPSAVE1 = 0x0c010d13ull;

static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_RESERVED_59_63 = 59;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE1_RESERVED_59_63_LEN = 5;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLPSAVE2 = 0x0c010d14ull;

static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_RESERVED_59_63 = 59;
static const uint32_t MC3_CHAN0_DSTL_DSTLPSAVE2_RESERVED_59_63_LEN = 5;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLSTATUS = 0x0c010d10ull;

static const uint32_t MC3_CHAN0_DSTL_DSTLSTATUS_A_FAIL_WOF = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLSTATUS_A_FAIL_WOF_LEN = 10;
static const uint32_t MC3_CHAN0_DSTL_DSTLSTATUS_B_FAIL_WOF = 10;
static const uint32_t MC3_CHAN0_DSTL_DSTLSTATUS_B_FAIL_WOF_LEN = 10;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_DSTL_DSTLTRACK = 0x0c010d0full;

static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE = 0;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE = 12;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE = 18;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE = 24;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE = 28;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW = 34;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN = 6;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW = 44;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN = 4;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW = 50;
static const uint32_t MC3_CHAN0_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN = 7;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLBADRESP = 0x0c010e10ull;

static const uint32_t MC3_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_VAL = 0;
static const uint32_t MC3_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE = 1;
static const uint32_t MC3_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD = 2;
static const uint32_t MC3_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_TAG = 3;
static const uint32_t MC3_CHAN0_USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN = 6;
static const uint32_t MC3_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_VAL = 9;
static const uint32_t MC3_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE = 10;
static const uint32_t MC3_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD = 11;
static const uint32_t MC3_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_TAG = 12;
static const uint32_t MC3_CHAN0_USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN = 6;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLCFG = 0x0c010e0bull;

static const uint32_t MC3_CHAN0_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE = 0;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE = 1;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_FAIL_CAPTURE_CONFIG = 2;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE = 4;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA = 5;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_DEFAULT_META_DATA_LEN = 2;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO = 7;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE = 8;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_LOWLAT_MISS_015_DELAY = 9;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN = 3;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_ET_DISABLE = 16;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE = 17;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE = 18;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_TEMPLATE1_ENABLE = 19;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_ENABLE = 20;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT = 21;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT_LEN = 3;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE = 24;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN = 7;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE = 32;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT = 33;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN = 3;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS = 36;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_DL_WIDTH_HALF_ENABLE = 37;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD = 40;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN = 4;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_CFG_ENABLE_SPEC_ATTN = 44;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_CFG_ENABLE_HOST_ATTN = 45;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_CFG_WRAP_MODE = 46;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_RESERVED_47 = 47;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE = 48;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_LOL_LFSR_RATE_SEL = 49;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN = 3;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_LOL_CAPTURE_CONFIG = 54;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_LAST_OPENCAPI_ENABLE = 56;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW = 57;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_PMU_SELECT_FAIL_RSP = 58;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_PMU_ENABLE = 59;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_PMU_SELECT_ALT_PERF = 60;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_CS_HW477424_DISABLE = 61;
static const uint32_t MC3_CHAN0_USTL_USTLCFG_CS_HW475333_DISABLE = 62;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLCFWOF = 0x0c010e15ull;

static const uint32_t MC3_CHAN0_USTL_USTLCFWOF_A_CHANFAIL_WOF = 0;
static const uint32_t MC3_CHAN0_USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN = 16;
static const uint32_t MC3_CHAN0_USTL_USTLCFWOF_B_CHANFAIL_WOF = 16;
static const uint32_t MC3_CHAN0_USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN = 16;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLDBG = 0x0c010e0dull;

static const uint32_t MC3_CHAN0_USTL_USTLDBG_ENABLE = 0;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_SEL_TOP = 8;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_SEL_WR_TOP = 9;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_SEL_BOT = 10;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_SEL_WR_BOT = 11;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_SEL_FLIT = 12;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_SEL_FLIT_CHANB = 13;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_SEL_MIRRORLOG_VLDS = 14;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_SPARE = 15;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_WAT_ENABLE0 = 16;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_WAT_ENABLE0_LEN = 2;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_WAT_ENABLE1 = 18;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_WAT_ENABLE1_LEN = 2;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_WAT_ENABLE2 = 20;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_WAT_ENABLE2_LEN = 2;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_WAT_ENABLE3 = 22;
static const uint32_t MC3_CHAN0_USTL_USTLDBG_WAT_ENABLE3_LEN = 2;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLERRPT = 0x0c010e16ull;

static const uint32_t MC3_CHAN0_USTL_USTLERRPT_WDF_CMT_PAR_ERR = 0;
static const uint32_t MC3_CHAN0_USTL_USTLERRPT_WDF_CMD_PAR_ERR = 1;
static const uint32_t MC3_CHAN0_USTL_USTLERRPT_WRT_NO_BUFF_ERR = 2;
static const uint32_t MC3_CHAN0_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR = 3;
static const uint32_t MC3_CHAN0_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR = 4;
static const uint32_t MC3_CHAN0_USTL_USTLERRPT_WDF_NO_BUFF_ERR = 5;
static const uint32_t MC3_CHAN0_USTL_USTLERRPT_RESERVED = 6;
static const uint32_t MC3_CHAN0_USTL_USTLERRPT_RESERVED_LEN = 10;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLERRRPT = 0x0c010e0eull;

static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT = 0;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 1;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 2;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT = 3;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT = 4;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 5;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 6;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT = 7;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT = 8;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT = 9;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT = 10;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT = 11;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT = 12;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT = 13;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT = 14;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT = 15;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 16;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT = 17;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT = 18;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT = 19;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT = 20;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT = 21;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT = 22;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 23;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT = 24;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT = 25;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT = 26;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT = 27;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT = 28;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT = 29;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT = 30;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA = 31;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT = 32;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT = 33;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT = 34;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT = 36;
static const uint32_t MC3_CHAN0_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT = 37;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLFAILMASK = 0x0c010e13ull;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLFIR_RWX = 0x0c010e00ull;
static const uint64_t MC3_CHAN0_USTL_USTLFIR_WOX_AND = 0x0c010e01ull;
static const uint64_t MC3_CHAN0_USTL_USTLFIR_WOX_OR = 0x0c010e02ull;

static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR = 0;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR = 1;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR = 2;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR = 3;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_HALF_SPEED_MODE = 4;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_HALF_SPEED_MODE = 5;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WDF_BUFFER_CE = 6;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WDF_BUFFER_UE = 7;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WDF_BUFFER_SUE = 8;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WDF_BUFFER_OVERRUN = 9;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WDF_TAG_PARITY_ERROR = 10;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR = 11;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR = 12;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR = 13;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_RESERVED_14 = 14;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 = 15;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WDF_CMT_PARITY_ERROR = 16;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_READ_SPARE_1 = 17;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_READ_SPARE_2 = 18;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR = 19;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WRT_BUFFER_CE = 20;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WRT_BUFFER_UE = 21;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WRT_BUFFER_SUE = 22;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR = 23;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR = 24;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 = 25;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_WRT_BUFF_ERR = 26;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP = 27;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP = 28;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER = 29;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER = 30;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP = 31;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP = 32;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER = 33;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER = 34;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR = 35;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR = 36;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR = 37;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR = 38;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL = 39;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL = 40;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS = 41;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS = 42;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO = 43;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO = 44;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE = 45;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE = 46;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_BAD_DATA = 47;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_BAD_DATA = 48;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR = 49;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR = 50;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR = 51;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR = 52;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR = 53;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR = 54;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR = 55;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR = 56;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_FATAL_REG_PARITY_ERROR = 57;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_RECOV_REG_PARITY_ERROR = 58;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO = 59;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO = 60;
static const uint32_t MC3_CHAN0_USTL_USTLFIR_SPARE_61 = 61;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLFIRACT0 = 0x0c010e06ull;

static const uint32_t MC3_CHAN0_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC3_CHAN0_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN = 62;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLFIRMASK_RW = 0x0c010e03ull;
static const uint64_t MC3_CHAN0_USTL_USTLFIRMASK_WO_AND = 0x0c010e04ull;
static const uint64_t MC3_CHAN0_USTL_USTLFIRMASK_WO_OR = 0x0c010e05ull;

static const uint32_t MC3_CHAN0_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC3_CHAN0_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN = 62;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLFIRWOF = 0x0c010e08ull;

static const uint32_t MC3_CHAN0_USTL_USTLFIRWOF_USTLFIRWOF_WOF = 0;
static const uint32_t MC3_CHAN0_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN = 62;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLINJ = 0x0c010e0cull;

static const uint32_t MC3_CHAN0_USTL_USTLINJ_FAIL_RESP_TYPE = 3;
static const uint32_t MC3_CHAN0_USTL_USTLINJ_FAIL_RESP_TYPE_LEN = 3;
static const uint32_t MC3_CHAN0_USTL_USTLINJ_FIR_INJECT = 8;
static const uint32_t MC3_CHAN0_USTL_USTLINJ_FIR_INJECT_LEN = 5;
static const uint32_t MC3_CHAN0_USTL_USTLINJ_US_DATA = 20;
static const uint32_t MC3_CHAN0_USTL_USTLINJ_US_DATA_LEN = 3;
static const uint32_t MC3_CHAN0_USTL_USTLINJ_CHAN_SEL = 24;
static const uint32_t MC3_CHAN0_USTL_USTLINJ_DATA_DW_SEL = 25;
static const uint32_t MC3_CHAN0_USTL_USTLINJ_US_DATA_ERR_EN = 26;
static const uint32_t MC3_CHAN0_USTL_USTLINJ_ONE_SHOT = 27;
static const uint32_t MC3_CHAN0_USTL_USTLINJ_DATA_OUT = 28;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLLOLDROP = 0x0c010e11ull;

static const uint32_t MC3_CHAN0_USTL_USTLLOLDROP_A_DROP_REASON = 0;
static const uint32_t MC3_CHAN0_USTL_USTLLOLDROP_A_DROP_REASON_LEN = 16;
static const uint32_t MC3_CHAN0_USTL_USTLLOLDROP_B_DROP_REASON = 32;
static const uint32_t MC3_CHAN0_USTL_USTLLOLDROP_B_DROP_REASON_LEN = 16;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLLOLMASK = 0x0c010e12ull;

static const uint32_t MC3_CHAN0_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t MC3_CHAN0_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN = 16;
static const uint32_t MC3_CHAN0_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK = 32;
static const uint32_t MC3_CHAN0_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN = 16;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLMCHWFM = 0x0c010e0full;

static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_ENABLE = 0;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_FAIL_THRESH = 1;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_FAIL_THRESH_LEN = 6;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_WINDOW_SIZE = 7;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_WINDOW_SIZE_LEN = 7;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_TSCALE = 14;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_TSCALE_LEN = 2;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_SCOM_COMMAND_VALID = 16;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_SCOM_COMMAND = 17;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT = 18;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_HWFM_STATUS = 19;
static const uint32_t MC3_CHAN0_USTL_USTLMCHWFM_HWFM_STATUS_LEN = 4;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLOCAPIERROR = 0x0c010e14ull;

static const uint32_t MC3_CHAN0_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID = 0;
static const uint32_t MC3_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE = 1;
static const uint32_t MC3_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN = 8;
static const uint32_t MC3_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION = 9;
static const uint32_t MC3_CHAN0_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN = 31;
// omi/reg00010.H

static const uint64_t MC3_CHAN0_USTL_USTLSTATUS = 0x0c010e0aull;

static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_LOL_MODE = 0;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_LOL_MODE = 1;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD = 2;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR = 3;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD = 4;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR = 5;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD = 6;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR = 7;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD = 8;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR = 9;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_FAIL_RESP = 10;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_FAIL_RESP_LEN = 4;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_WAT_FIRED = 24;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_WAT_FIRED = 25;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY = 32;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR = 33;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR = 34;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR = 35;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR = 36;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR = 37;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 38;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP = 39;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP = 40;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE = 41;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY = 42;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY = 43;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR = 44;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR = 45;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR = 46;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR = 47;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR = 48;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 49;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP = 50;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP = 51;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE = 52;
static const uint32_t MC3_CHAN0_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY = 53;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSLTWAT = 0x0c010d51ull;

static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU = 0;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN = 6;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN = 10;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN = 12;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN = 14;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN = 16;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN = 18;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN = 20;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN = 22;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_RESERVED_24_62 = 24;
static const uint32_t MC3_CHAN1_DSTL_DSLTWAT_RESERVED_24_62_LEN = 39;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLCFG = 0x0c010d4bull;

static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_TMPL0_ONLY = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_RESERVED_1 = 1;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_TMPL7_ENABLE = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_TMPL1_DIS = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_FAST_RD_DISABLE = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_RESERVED_5 = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_TMPL4_DISABLE = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS = 7;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_READ_THRESHOLD = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_READ_THRESHOLD_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_WR_TMP4_THRESHOLD = 16;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_RESERVED_20_23 = 20;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_RESERVED_20_23_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_WR_DBL_THRESHOLD = 24;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_CRITICAL_OW_DIS = 28;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_ENABLE_SPEC_ATTN = 29;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_ENABLE_HOST_ATTN = 30;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_DEBUG_EN = 31;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_DEBUG_LOCAL_SWAP = 32;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_DEBUG_PASSTHRU = 33;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_DEBUG_PASSTHRU_LEN = 11;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_WRAP_MODE_EN = 44;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH = 45;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_TIMEOUT_MODE = 49;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_TIMEOUT_MODE_LEN = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_MMIO_ADDRBIT_POS = 52;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_RESET_CREDITS = 57;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET = 58;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET = 59;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_CREDITS_ON_DEBUG_BUS = 60;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_RESERVED_61_63 = 61;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG_RESERVED_61_63_LEN = 3;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLCFG2 = 0x0c010d4eull;

static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING = 12;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET = 16;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET = 17;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE = 18;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE = 19;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED = 20;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED = 21;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN = 22;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN = 23;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT = 24;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT = 25;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP = 26;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP = 27;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR = 28;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR = 29;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE = 30;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE = 31;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_RESERVED_32_35 = 32;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_RESERVED_32_35_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS = 36;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT = 37;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT = 38;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS = 39;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE = 40;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET = 43;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT = 44;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_RESERVED_45 = 45;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL = 46;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_RESERVED_47_62 = 47;
static const uint32_t MC3_CHAN1_DSTL_DSTLCFG2_RESERVED_47_62_LEN = 16;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLCREDIT = 0x0c010d4aull;

static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT = 12;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT = 17;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN = 7;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_VC0_CREDIT_INIT = 28;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_VC1_CREDIT_INIT = 36;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT = 42;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL = 50;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL = 58;
static const uint32_t MC3_CHAN1_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN = 6;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLERRRPT = 0x0c010d4cull;

static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 1;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT = 7;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT = 9;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT = 10;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 11;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 12;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT = 13;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT = 14;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 15;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT = 16;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT = 17;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT = 18;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT = 19;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT = 20;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT = 21;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT = 22;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT = 23;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT = 24;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT = 25;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT = 26;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT = 27;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT = 28;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT = 29;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT = 30;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT = 31;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT = 32;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT = 33;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT = 34;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT = 35;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 36;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 37;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 38;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 39;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT = 40;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT = 41;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE = 62;
static const uint32_t MC3_CHAN1_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE = 63;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLFIR_RWX = 0x0c010d40ull;
static const uint64_t MC3_CHAN1_DSTL_DSTLFIR_WOX_AND = 0x0c010d41ull;
static const uint64_t MC3_CHAN1_DSTL_DSTLFIR_WOX_OR = 0x0c010d42ull;

static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION = 1;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT = 7;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_CMD_WRDATA_PARITY_ERROR = 9;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR = 10;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR = 11;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR = 12;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR = 13;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR = 14;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR = 15;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR = 16;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR = 17;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN = 18;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN = 19;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT = 22;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT = 23;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SPARE24 = 24;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_SPARE25 = 25;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_DECRYPT_ERR_INFO = 26;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_ENCRYPT_ERR_INFO = 29;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN = 4;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLFIRACT0 = 0x0c010d46ull;

static const uint32_t MC3_CHAN1_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 33;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLFIRMASK_RW = 0x0c010d43ull;
static const uint64_t MC3_CHAN1_DSTL_DSTLFIRMASK_WO_AND = 0x0c010d44ull;
static const uint64_t MC3_CHAN1_DSTL_DSTLFIRMASK_WO_OR = 0x0c010d45ull;

static const uint32_t MC3_CHAN1_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 33;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLFIRWOF = 0x0c010d48ull;

static const uint32_t MC3_CHAN1_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN = 33;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLINJ = 0x0c010d4dull;

static const uint32_t MC3_CHAN1_DSTL_DSTLINJ_ERR_INJ_TRIGGER = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLINJ_ERR_INJ_CONT_MODE = 1;
static const uint32_t MC3_CHAN1_DSTL_DSTLINJ_ERR_INJ_TYPE = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLINJ_RESERVED_4_15 = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLINJ_RESERVED_4_15_LEN = 12;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLPSAVE0 = 0x0c010d52ull;

static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE = 16;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH = 18;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE = 21;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT = 24;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL = 32;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL = 36;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_RESERVED_40_47 = 40;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE0_RESERVED_40_47_LEN = 8;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLPSAVE1 = 0x0c010d53ull;

static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_RESERVED_59_63 = 59;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE1_RESERVED_59_63_LEN = 5;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLPSAVE2 = 0x0c010d54ull;

static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT = 16;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT = 21;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC = 28;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC = 36;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT = 44;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT = 49;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE = 56;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_RESERVED_59_63 = 59;
static const uint32_t MC3_CHAN1_DSTL_DSTLPSAVE2_RESERVED_59_63_LEN = 5;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLSTATUS = 0x0c010d50ull;

static const uint32_t MC3_CHAN1_DSTL_DSTLSTATUS_A_FAIL_WOF = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLSTATUS_A_FAIL_WOF_LEN = 10;
static const uint32_t MC3_CHAN1_DSTL_DSTLSTATUS_B_FAIL_WOF = 10;
static const uint32_t MC3_CHAN1_DSTL_DSTLSTATUS_B_FAIL_WOF_LEN = 10;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_DSTL_DSTLTRACK = 0x0c010d4full;

static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE = 0;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE = 12;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE = 18;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE = 24;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE = 28;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW = 34;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN = 6;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW = 44;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN = 4;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW = 50;
static const uint32_t MC3_CHAN1_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN = 7;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_USTL_USTLBADRESP = 0x0c010e50ull;

static const uint32_t MC3_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_VAL = 0;
static const uint32_t MC3_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE = 1;
static const uint32_t MC3_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD = 2;
static const uint32_t MC3_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_TAG = 3;
static const uint32_t MC3_CHAN1_USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN = 6;
static const uint32_t MC3_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_VAL = 9;
static const uint32_t MC3_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE = 10;
static const uint32_t MC3_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD = 11;
static const uint32_t MC3_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_TAG = 12;
static const uint32_t MC3_CHAN1_USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN = 6;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_USTL_USTLCFG = 0x0c010e4bull;

static const uint32_t MC3_CHAN1_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE = 0;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE = 1;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_FAIL_CAPTURE_CONFIG = 2;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE = 4;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA = 5;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_DEFAULT_META_DATA_LEN = 2;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO = 7;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE = 8;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_LOWLAT_MISS_015_DELAY = 9;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN = 3;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_RESERVED_12_15 = 12;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_ET_DISABLE = 16;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE = 17;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE = 18;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_TEMPLATE1_ENABLE = 19;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_ENABLE = 20;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT = 21;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT_LEN = 3;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE = 24;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN = 7;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE = 32;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT = 33;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN = 3;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS = 36;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_DL_WIDTH_HALF_ENABLE = 37;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD = 40;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN = 4;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_CFG_ENABLE_SPEC_ATTN = 44;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_CFG_ENABLE_HOST_ATTN = 45;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_CFG_WRAP_MODE = 46;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_RESERVED_47 = 47;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE = 48;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_LOL_LFSR_RATE_SEL = 49;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN = 3;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_LOL_CAPTURE_CONFIG = 54;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_LAST_OPENCAPI_ENABLE = 56;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW = 57;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_PMU_SELECT_FAIL_RSP = 58;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_PMU_ENABLE = 59;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_PMU_SELECT_ALT_PERF = 60;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_CS_HW477424_DISABLE = 61;
static const uint32_t MC3_CHAN1_USTL_USTLCFG_CS_HW475333_DISABLE = 62;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_USTL_USTLCFWOF = 0x0c010e55ull;

static const uint32_t MC3_CHAN1_USTL_USTLCFWOF_A_CHANFAIL_WOF = 0;
static const uint32_t MC3_CHAN1_USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN = 16;
static const uint32_t MC3_CHAN1_USTL_USTLCFWOF_B_CHANFAIL_WOF = 16;
static const uint32_t MC3_CHAN1_USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN = 16;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_USTL_USTLDBG = 0x0c010e4dull;

static const uint32_t MC3_CHAN1_USTL_USTLDBG_ENABLE = 0;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_SEL_TOP = 8;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_SEL_WR_TOP = 9;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_SEL_BOT = 10;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_SEL_WR_BOT = 11;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_SEL_FLIT = 12;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_SEL_FLIT_CHANB = 13;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_SEL_MIRRORLOG_VLDS = 14;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_SPARE = 15;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_WAT_ENABLE0 = 16;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_WAT_ENABLE0_LEN = 2;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_WAT_ENABLE1 = 18;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_WAT_ENABLE1_LEN = 2;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_WAT_ENABLE2 = 20;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_WAT_ENABLE2_LEN = 2;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_WAT_ENABLE3 = 22;
static const uint32_t MC3_CHAN1_USTL_USTLDBG_WAT_ENABLE3_LEN = 2;
// omi/reg00010.H

static const uint64_t MC3_CHAN1_USTL_USTLERRPT = 0x0c010e56ull;

static const uint32_t MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR = 0;
static const uint32_t MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR = 1;
static const uint32_t MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR = 2;
static const uint32_t MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR = 3;
static const uint32_t MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR = 4;
static const uint32_t MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR = 5;
static const uint32_t MC3_CHAN1_USTL_USTLERRPT_RESERVED = 6;
static const uint32_t MC3_CHAN1_USTL_USTLERRPT_RESERVED_LEN = 10;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLERRRPT = 0x0c010e4eull;

static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT = 0;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 1;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 2;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT = 3;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT = 4;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 5;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 6;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT = 7;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT = 8;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT = 9;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT = 10;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT = 11;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT = 12;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT = 13;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT = 14;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT = 15;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 16;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT = 17;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT = 18;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT = 19;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT = 20;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT = 21;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT = 22;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 23;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT = 24;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT = 25;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT = 26;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT = 27;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT = 28;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT = 29;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT = 30;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA = 31;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT = 32;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT = 33;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT = 34;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT = 36;
static const uint32_t MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT = 37;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLFAILMASK = 0x0c010e53ull;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLFIR_RWX = 0x0c010e40ull;
static const uint64_t MC3_CHAN1_USTL_USTLFIR_WOX_AND = 0x0c010e41ull;
static const uint64_t MC3_CHAN1_USTL_USTLFIR_WOX_OR = 0x0c010e42ull;

static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR = 0;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR = 1;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR = 2;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR = 3;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE = 4;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE = 5;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE = 6;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE = 7;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE = 8;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN = 9;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR = 10;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR = 11;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR = 12;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR = 13;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_RESERVED_14 = 14;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 = 15;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR = 16;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1 = 17;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2 = 18;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR = 19;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE = 20;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE = 21;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE = 22;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR = 23;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR = 24;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 = 25;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR = 26;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP = 27;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP = 28;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER = 29;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER = 30;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP = 31;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP = 32;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER = 33;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER = 34;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR = 35;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR = 36;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR = 37;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR = 38;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL = 39;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL = 40;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS = 41;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS = 42;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO = 43;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO = 44;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE = 45;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE = 46;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA = 47;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA = 48;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR = 49;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR = 50;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR = 51;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR = 52;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR = 53;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR = 54;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR = 55;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR = 56;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR = 57;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR = 58;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO = 59;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO = 60;
static const uint32_t MC3_CHAN1_USTL_USTLFIR_SPARE_61 = 61;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLFIRACT0 = 0x0c010e46ull;

static const uint32_t MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 = 0;
static const uint32_t MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN = 62;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLFIRMASK_RW = 0x0c010e43ull;
static const uint64_t MC3_CHAN1_USTL_USTLFIRMASK_WO_AND = 0x0c010e44ull;
static const uint64_t MC3_CHAN1_USTL_USTLFIRMASK_WO_OR = 0x0c010e45ull;

static const uint32_t MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK = 0;
static const uint32_t MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN = 62;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLFIRWOF = 0x0c010e48ull;

static const uint32_t MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF = 0;
static const uint32_t MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN = 62;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLINJ = 0x0c010e4cull;

static const uint32_t MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE = 3;
static const uint32_t MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE_LEN = 3;
static const uint32_t MC3_CHAN1_USTL_USTLINJ_FIR_INJECT = 8;
static const uint32_t MC3_CHAN1_USTL_USTLINJ_FIR_INJECT_LEN = 5;
static const uint32_t MC3_CHAN1_USTL_USTLINJ_US_DATA = 20;
static const uint32_t MC3_CHAN1_USTL_USTLINJ_US_DATA_LEN = 3;
static const uint32_t MC3_CHAN1_USTL_USTLINJ_CHAN_SEL = 24;
static const uint32_t MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL = 25;
static const uint32_t MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN = 26;
static const uint32_t MC3_CHAN1_USTL_USTLINJ_ONE_SHOT = 27;
static const uint32_t MC3_CHAN1_USTL_USTLINJ_DATA_OUT = 28;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLLOLDROP = 0x0c010e51ull;

static const uint32_t MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON = 0;
static const uint32_t MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON_LEN = 16;
static const uint32_t MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON = 32;
static const uint32_t MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON_LEN = 16;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLLOLMASK = 0x0c010e52ull;

static const uint32_t MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN = 16;
static const uint32_t MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK = 32;
static const uint32_t MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN = 16;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLMCHWFM = 0x0c010e4full;

static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_ENABLE = 0;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH = 1;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH_LEN = 6;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE = 7;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE_LEN = 7;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_TSCALE = 14;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_TSCALE_LEN = 2;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID = 16;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND = 17;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT = 18;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS = 19;
static const uint32_t MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS_LEN = 4;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLOCAPIERROR = 0x0c010e54ull;

static const uint32_t MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID = 0;
static const uint32_t MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE = 1;
static const uint32_t MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN = 8;
static const uint32_t MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION = 9;
static const uint32_t MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN = 31;
// omi/reg00011.H

static const uint64_t MC3_CHAN1_USTL_USTLSTATUS = 0x0c010e4aull;

static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE = 0;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE = 1;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD = 2;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR = 3;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD = 4;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR = 5;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD = 6;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR = 7;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD = 8;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR = 9;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP = 10;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP_LEN = 4;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED = 24;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED = 25;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY = 32;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR = 33;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR = 34;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR = 35;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR = 36;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR = 37;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 38;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP = 39;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP = 40;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE = 41;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY = 42;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY = 43;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR = 44;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR = 45;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR = 46;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR = 47;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR = 48;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 49;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP = 50;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP = 51;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE = 52;
static const uint32_t MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY = 53;
// omi/reg00011.H

static const uint64_t MC3_MISC_CLKMON_MONM_CLKRATIO = 0x0c010ff0ull;

static const uint32_t MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO = 0;
static const uint32_t MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO_LEN = 12;
static const uint32_t MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE = 12;
static const uint32_t MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE = 13;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_AACR = 0x0c010f29ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_AACR_BUFFER = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS = 1;
static const uint32_t MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS_LEN = 10;
static const uint32_t MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC = 11;
static const uint32_t MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN = 12;
static const uint32_t MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL = 13;
static const uint32_t MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL_LEN = 2;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_AADR = 0x0c010f2aull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA_LEN = 64;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_AAER = 0x0c010f2bull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC_LEN = 9;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q = 0x0c010f94ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63 = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63_LEN = 64;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q = 0x0c010f95ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87 = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87_LEN = 24;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED = 24;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED_LEN = 40;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q = 0x0c010f96ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN = 64;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q = 0x0c010f97ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87 = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87_LEN = 24;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED = 24;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED_LEN = 40;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q = 0x0c010fe8ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01 = 1;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01_LEN = 11;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23 = 12;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23_LEN = 11;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI = 23;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44 = 24;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44_LEN = 21;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER = 45;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET = 46;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM = 47;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q = 0x0c010fe9ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT = 1;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL = 3;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL_LEN = 20;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL = 23;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL_LEN = 20;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL = 43;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL_LEN = 20;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63 = 63;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_DBGCFG2Q = 0x0c010feaull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL_LEN = 20;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL = 20;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL_LEN = 20;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL = 40;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL_LEN = 20;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63 = 60;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63_LEN = 4;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q = 0x0c010febull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL_LEN = 20;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL = 20;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22 = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL = 23;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25 = 25;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL = 26;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28 = 28;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL = 29;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32 = 31;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE = 33;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE = 37;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE = 41;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE = 45;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE_LEN = 6;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE = 51;
static const uint32_t MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE_LEN = 8;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ = 0x0c010fe7ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT = 1;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT = 5;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT = 6;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT = 7;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT = 8;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT = 9;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT = 10;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT = 11;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT = 12;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT = 13;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT = 14;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT = 15;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT = 16;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT = 17;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT = 18;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT = 19;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT = 20;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBCFGQ = 0x0c010fe0ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER = 10;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN = 62;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN = 63;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0 = 0x0c010f06ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0 = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0_LEN = 14;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_RW = 0x0c010f03ull;
static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_AND = 0x0c010f04ull;
static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_OR = 0x0c010f05ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK_LEN = 14;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RWX = 0x0c010f00ull;
static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_AND = 0x0c010f01ull;
static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_OR = 0x0c010f02ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE = 1;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3 = 3;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT = 5;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT = 6;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT = 7;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT = 8;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT = 9;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT = 10;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT = 11;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR = 12;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE = 13;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF = 0x0c010f08ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF_LEN = 14;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCBPARMQ = 0x0c010fafull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN = 59;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG = 0x0c010f98ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE = 1;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE = 3;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN0 = 0x0c010fa4ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN1 = 0x0c010fa5ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN2 = 0x0c010fa6ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS_LEN = 64;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN3 = 0x0c010fa7ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N_LEN = 16;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE = 16;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT = 17;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT_LEN = 3;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL = 0x0c010f99ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM = 1;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER = 3;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT = 8;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT = 10;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT = 12;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL = 14;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15 = 15;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT = 16;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18 = 18;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT = 19;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21 = 21;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24 = 24;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT = 25;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27 = 27;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE = 28;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT = 29;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT = 33;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT_LEN = 7;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT = 40;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT_LEN = 5;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT = 45;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG = 49;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG_LEN = 9;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59 = 58;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59_LEN = 2;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE = 60;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET = 61;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS = 62;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63 = 63;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0 = 0x0c010f9aull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN = 6;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE = 6;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN = 8;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT = 16;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT = 20;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT = 24;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT = 28;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT = 32;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN = 4;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT = 36;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN = 4;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATDATA1 = 0x0c010f9bull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A_LEN = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A_LEN = 22;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATDATA2 = 0x0c010f9cull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B_LEN = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B_LEN = 22;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATDATA3 = 0x0c010f9dull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A_LEN = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A_LEN = 22;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATDATA4 = 0x0c010f9eull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN = 22;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATDATA5 = 0x0c010f9full;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A_LEN = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A_LEN = 22;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATDATA6 = 0x0c010fa0ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN = 22;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATDATA7 = 0x0c010fa1ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A_LEN = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A_LEN = 22;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATDATA8 = 0x0c010fa2ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B = 22;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN = 22;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_MCWATDATA9 = 0x0c010fa3ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN = 46;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL = 47;
static const uint32_t MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN = 17;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_SPARE = 0x0c010f0full;

static const uint32_t MC3_MISC_MBA_SCOMFIR_SPARE_SPARE = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_SPARE_SPARE_LEN = 8;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_WATCFG0AQ = 0x0c010f80ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN = 48;
// omi/reg00011.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_WATCFG0BQ = 0x0c010f81ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA_LEN = 44;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL = 44;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL_LEN = 17;
// omi/reg00012.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_WATCFG0CQ = 0x0c010f82ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB_LEN = 44;
// omi/reg00012.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_WATCFG0DQ = 0x0c010f83ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA_LEN = 44;
// omi/reg00012.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_WATCFG0EQ = 0x0c010f84ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB_LEN = 44;
// omi/reg00012.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_WATCFG1AQ = 0x0c010f85ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL_LEN = 48;
// omi/reg00012.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_WATCFG1BQ = 0x0c010f86ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA_LEN = 44;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL = 44;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL_LEN = 17;
// omi/reg00012.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_WATCFG1CQ = 0x0c010f87ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB_LEN = 44;
// omi/reg00012.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_WATCFG1DQ = 0x0c010f88ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA_LEN = 44;
// omi/reg00012.H

static const uint64_t MC3_MISC_MBA_SCOMFIR_WATCFG1EQ = 0x0c010f89ull;

static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB = 0;
static const uint32_t MC3_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB_LEN = 44;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_AACR = 0x0c010c2cull;

static const uint32_t MC3_PBI01_SCOMFIR_AACR_BUFFER = 0;
static const uint32_t MC3_PBI01_SCOMFIR_AACR_ADDRESS = 1;
static const uint32_t MC3_PBI01_SCOMFIR_AACR_ADDRESS_LEN = 9;
static const uint32_t MC3_PBI01_SCOMFIR_AACR_AUTOINC = 10;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_AADR = 0x0c010c2dull;

static const uint32_t MC3_PBI01_SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t MC3_PBI01_SCOMFIR_AADR_AADR_DATA_LEN = 64;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_AAER = 0x0c010c2eull;

static const uint32_t MC3_PBI01_SCOMFIR_AAER_AAER_TAG_ECC = 0;
static const uint32_t MC3_PBI01_SCOMFIR_AAER_AAER_TAG_ECC_LEN = 9;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCERPT0 = 0x0c010c1eull;

static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR = 5;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR = 9;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR = 10;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR = 11;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR = 12;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR = 13;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR = 14;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR = 17;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR = 18;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR = 20;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR = 21;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR = 22;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR = 23;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR = 29;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR = 30;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR = 31;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR = 32;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR = 33;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR = 38;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR = 39;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR = 40;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR = 41;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR = 42;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR = 43;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR = 44;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR = 45;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR = 46;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR = 47;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR = 48;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR = 49;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 = 51;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR = 52;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 = 53;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR = 54;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 = 55;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR = 56;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 = 57;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR = 58;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR = 59;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR = 60;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR = 61;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCERPT1 = 0x0c010c1full;

static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT = 23;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT = 33;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT = 34;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q = 44;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q_LEN = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q = 51;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q_LEN = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3 = 60;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3 = 61;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3 = 62;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3 = 63;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCERPT2 = 0x0c010c1aull;

static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR = 5;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR = 9;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE = 11;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE = 12;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT = 13;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT = 14;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR = 17;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR = 18;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT = 20;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT = 21;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT = 22;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT = 23;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT = 25;
static const uint32_t MC3_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT = 26;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGP0 = 0x0c010c0aull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_0_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE = 25;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP = 40;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION = 43;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE = 46;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE = 54;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN = 8;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGP0A = 0x0c010c0eull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21 = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21_LEN = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_SMF_VALID = 22;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGP0E = 0x0c010c16ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0E_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS = 21;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS_LEN = 19;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGP1 = 0x0c010c0bull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_1_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE = 25;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE_LEN = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP = 40;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP_LEN = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION = 43;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION_LEN = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE = 46;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE_LEN = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE = 54;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE_LEN = 8;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGP1A = 0x0c010c0full;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21 = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21_LEN = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_SMF_VALID = 22;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGP1E = 0x0c010c17ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1E_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS = 21;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN = 19;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGPM0 = 0x0c010c20ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE = 25;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE_LEN = 15;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGPM0A = 0x0c010c21ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21 = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID = 22;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGPM0E = 0x0c010c1cull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0E_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS = 21;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS_LEN = 19;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGPM1 = 0x0c010c30ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE = 25;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE_LEN = 15;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGPM1A = 0x0c010c31ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21 = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21_LEN = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID = 22;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS = 43;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS_LEN = 19;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGPM1E = 0x0c010c1dull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1E_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS = 21;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS_LEN = 19;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGPR0 = 0x0c010c0cull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS_LEN = 31;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS = 33;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS_LEN = 31;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFGPR1 = 0x0c010c0dull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS_LEN = 31;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS = 33;
static const uint32_t MC3_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS_LEN = 31;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFIR_RWX = 0x0c010c00ull;
static const uint64_t MC3_PBI01_SCOMFIR_MCFIR_WOX_AND = 0x0c010c01ull;
static const uint64_t MC3_PBI01_SCOMFIR_MCFIR_WOX_OR = 0x0c010c02ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 = 5;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_RESERVED_6 = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_RESERVED_7 = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_RESERVED_9 = 9;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_RESERVED_10 = 10;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_MCS_WAT0 = 11;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_MCS_WAT1 = 12;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_MCS_WAT2 = 13;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_MCS_WAT3 = 14;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR = 17;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_RESERVED_18 = 18;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_RESERVED_19 = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_RESERVED_20 = 20;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_RESERVED_21 = 21;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS = 22;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIR_RESERVED_23 = 23;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFIRACT0 = 0x0c010c06ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN = 24;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFIRMASK_RW = 0x0c010c03ull;
static const uint64_t MC3_PBI01_SCOMFIR_MCFIRMASK_WO_AND = 0x0c010c04ull;
static const uint64_t MC3_PBI01_SCOMFIR_MCFIRMASK_WO_OR = 0x0c010c05ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK_LEN = 24;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCFIRWOF = 0x0c010c08ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF_LEN = 24;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCLFSR = 0x0c010c14ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT_LEN = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCLFSR_SERVED_2_4 = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCLFSR_SERVED_2_4_LEN = 3;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCMODE0 = 0x0c010c11ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_RESERVED_4 = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID = 5;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND = 9;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND = 10;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_RESERVED_11 = 11;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC = 12;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_RESERVED_13 = 13;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT = 14;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN = 10;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE = 25;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY = 32;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE = 36;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS = 37;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH = 40;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63 = 41;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63_LEN = 23;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCMODE1 = 0x0c010c12ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN = 10;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT = 10;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS = 11;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS = 17;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY = 18;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN = 9;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH = 28;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS = 32;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP = 33;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_CI = 52;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_CI_LEN = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS = 54;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_RESERVED_60 = 60;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS = 61;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW = 62;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE1_RESERVED_63 = 63;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCMODE2 = 0x0c010c13ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0 = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0_LEN = 13;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15 = 14;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15_LEN = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM = 17;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22 = 18;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22_LEN = 5;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR = 23;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES_LEN = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH = 40;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH_LEN = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN = 44;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN = 45;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52 = 46;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52_LEN = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE = 53;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE = 54;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE = 55;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE = 56;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63 = 57;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63_LEN = 7;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCMODE3 = 0x0c010c2full;

static const uint32_t MC3_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10 = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10_LEN = 11;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCPERF1 = 0x0c010c10ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_DISABLE_FASTPATH = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT = 5;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH = 10;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT = 17;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST = 21;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE = 22;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH = 23;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE = 30;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE = 32;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN = 5;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD = 37;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE = 38;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN = 5;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_RESERVED_43_63 = 43;
static const uint32_t MC3_PBI01_SCOMFIR_MCPERF1_RESERVED_43_63_LEN = 21;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCSYNC = 0x0c010c15ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCSYNC_CHANNEL_SELECT = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCSYNC_CHANNEL_SELECT_LEN = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCSYNC_SYNC_TYPE = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCSYNC_SYNC_TYPE_LEN = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCSYNC_SYNC_GO = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCSYNC_SYNC_RESERVED = 17;
static const uint32_t MC3_PBI01_SCOMFIR_MCSYNC_SYNC_RESERVED_LEN = 8;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCTO = 0x0c010c1bull;

static const uint32_t MC3_PBI01_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_RPT_HANG_SELECT = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_RPT_HANG_SELECT_LEN = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_RESERVED_4 = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_CL_TIMEOUT_VALUE = 5;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_CL_TIMEOUT_VALUE_LEN = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_LOCAL_HANG_COMP = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_LOCAL_HANG_COMP_LEN = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_HANG_COMP = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_HANG_COMP_LEN = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG = 32;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG = 33;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_ENABLE_APO_HANG = 34;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_ENABLE_CLIB_HANG = 35;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG = 36;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE = 37;
static const uint32_t MC3_PBI01_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE_LEN = 3;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCWATACT = 0x0c010c18ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION = 1;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION = 2;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION = 3;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS = 4;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS = 5;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS = 6;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH = 8;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH = 9;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH = 10;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH = 11;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH = 12;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH = 13;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH = 14;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH = 15;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT = 16;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT = 17;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT = 18;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT = 19;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 = 20;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 = 21;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 = 22;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 = 23;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_RESERVED_36_47 = 24;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATACT_RESERVED_36_47_LEN = 16;
// omi/reg00012.H

static const uint64_t MC3_PBI01_SCOMFIR_MCWATCNTL2 = 0x0c010c19ull;

static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL0 = 0;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL0_LEN = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL1 = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL1_LEN = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL2 = 14;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL2_LEN = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL3 = 21;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL3_LEN = 7;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_RESERVED_28_49 = 28;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_RESERVED_28_49_LEN = 22;
static const uint32_t MC3_PBI01_SCOMFIR_MCWATCNTL2_CL_EARLY_HANG_MODE = 50;
// omi/reg00012.H

static const uint64_t STATUS = 0x0c011766ull;

static const uint32_t STATUS_TRAINED_MODE = 0;
static const uint32_t STATUS_TRAINED_MODE_LEN = 4;
static const uint32_t STATUS_RX_LANE_REVERSED = 4;
static const uint32_t STATUS_TX_LANE_REVERSED = 5;
static const uint32_t STATUS_RSVD0 = 6;
static const uint32_t STATUS_ACK_PTRS_EQUAL = 7;
static const uint32_t STATUS_RSVD1 = 8;
static const uint32_t STATUS_RSVD1_LEN = 4;
static const uint32_t STATUS_REQUESTED_LN_WIDTH = 12;
static const uint32_t STATUS_REQUESTED_LN_WIDTH_LEN = 2;
static const uint32_t STATUS_ACTUAL_LN_WIDTH = 14;
static const uint32_t STATUS_ACTUAL_LN_WIDTH_LEN = 2;
static const uint32_t STATUS_TX_TRAINED_LANES = 16;
static const uint32_t STATUS_TX_TRAINED_LANES_LEN = 8;
static const uint32_t STATUS_RX_TRAINED_LANES = 24;
static const uint32_t STATUS_RX_TRAINED_LANES_LEN = 8;
static const uint32_t STATUS_ENDPOINT_INFO = 32;
static const uint32_t STATUS_ENDPOINT_INFO_LEN = 16;
static const uint32_t STATUS_RSVD2 = 48;
static const uint32_t STATUS_TRAINING_STATE_MACHINE = 49;
static const uint32_t STATUS_TRAINING_STATE_MACHINE_LEN = 3;
static const uint32_t STATUS_RSVD3 = 52;
static const uint32_t STATUS_RSVD3_LEN = 3;
static const uint32_t STATUS_DESKEW_DONE = 55;
static const uint32_t STATUS_LANES_DISABLED = 56;
static const uint32_t STATUS_LANES_DISABLED_LEN = 8;
// omi/reg00012.H

static const uint64_t TRAINING_STATUS = 0x0c011767ull;

static const uint32_t TRAINING_STATUS_RX_PATTERN_A = 0;
static const uint32_t TRAINING_STATUS_RX_PATTERN_A_LEN = 8;
static const uint32_t TRAINING_STATUS_RX_PATTERN_B = 8;
static const uint32_t TRAINING_STATUS_RX_PATTERN_B_LEN = 8;
static const uint32_t TRAINING_STATUS_SYNC_PATTERN = 16;
static const uint32_t TRAINING_STATUS_SYNC_PATTERN_LEN = 8;
static const uint32_t TRAINING_STATUS_PHY_INIT_DONE = 24;
static const uint32_t TRAINING_STATUS_PHY_INIT_DONE_LEN = 8;
static const uint32_t TRAINING_STATUS_BLOCK_LOCKED = 32;
static const uint32_t TRAINING_STATUS_BLOCK_LOCKED_LEN = 8;
static const uint32_t TRAINING_STATUS_RX_TS1 = 40;
static const uint32_t TRAINING_STATUS_RX_TS1_LEN = 8;
static const uint32_t TRAINING_STATUS_RX_TS2 = 48;
static const uint32_t TRAINING_STATUS_RX_TS2_LEN = 8;
static const uint32_t TRAINING_STATUS_RX_TS3 = 56;
static const uint32_t TRAINING_STATUS_RX_TS3_LEN = 8;
// omi/reg00012.H

}
}
#include "omi/reg00000.H"
#include "omi/reg00001.H"
#include "omi/reg00002.H"
#include "omi/reg00003.H"
#include "omi/reg00004.H"
#include "omi/reg00005.H"
#include "omi/reg00006.H"
#include "omi/reg00007.H"
#include "omi/reg00008.H"
#include "omi/reg00009.H"
#include "omi/reg00010.H"
#include "omi/reg00011.H"
#include "omi/reg00012.H"
#endif
