/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_omi_odc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
#pragma once
#include <stdint.h>

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif

static const uint64_t D_REG_CMN_CONFIG = 0x801240Eull;

static const uint32_t D_REG_CMN_CONFIG_SPARE = 0;
static const uint32_t D_REG_CMN_CONFIG_SPARE_LEN = 6;
static const uint32_t D_REG_CMN_CONFIG_RX_EDGE_ENA = 6;
static const uint32_t D_REG_CMN_CONFIG_RX_EDGE_MARGIN = 7;
static const uint32_t D_REG_CMN_CONFIG_RX_EDGE_MARGIN_LEN = 5;
static const uint32_t D_REG_CMN_CONFIG_DISABLE_XSTOPIN = 12;
static const uint32_t D_REG_CMN_CONFIG_RECAL_TIMER = 13;
static const uint32_t D_REG_CMN_CONFIG_RECAL_TIMER_LEN = 3;
static const uint32_t D_REG_CMN_CONFIG_1US_TMR = 16;
static const uint32_t D_REG_CMN_CONFIG_1US_TMR_LEN = 12;
static const uint32_t D_REG_CMN_CONFIG_DBG_EN = 28;
static const uint32_t D_REG_CMN_CONFIG_DBG_SEL = 29;
static const uint32_t D_REG_CMN_CONFIG_DBG_SEL_LEN = 3;
static const uint32_t D_REG_CMN_CONFIG_RD_RST = 32;
static const uint32_t D_REG_CMN_CONFIG_PRE_SCALAR = 33;
static const uint32_t D_REG_CMN_CONFIG_PRE_SCALAR_LEN = 3;
static const uint32_t D_REG_CMN_CONFIG_FREEZE = 36;
static const uint32_t D_REG_CMN_CONFIG_PORT_SEL = 37;
static const uint32_t D_REG_CMN_CONFIG_PORT_SEL_LEN = 3;
static const uint32_t D_REG_CMN_CONFIG_CNTR3_PS = 40;
static const uint32_t D_REG_CMN_CONFIG_CNTR3_PS_LEN = 2;
static const uint32_t D_REG_CMN_CONFIG_CNTR3_ES = 42;
static const uint32_t D_REG_CMN_CONFIG_CNTR3_ES_LEN = 2;
static const uint32_t D_REG_CMN_CONFIG_CNTR2_PS = 44;
static const uint32_t D_REG_CMN_CONFIG_CNTR2_PS_LEN = 2;
static const uint32_t D_REG_CMN_CONFIG_CNTR2_ES = 46;
static const uint32_t D_REG_CMN_CONFIG_CNTR2_ES_LEN = 2;
static const uint32_t D_REG_CMN_CONFIG_CNTR1_PS = 48;
static const uint32_t D_REG_CMN_CONFIG_CNTR1_PS_LEN = 2;
static const uint32_t D_REG_CMN_CONFIG_CNTR1_ES = 50;
static const uint32_t D_REG_CMN_CONFIG_CNTR1_ES_LEN = 2;
static const uint32_t D_REG_CMN_CONFIG_CNTR0_PS = 52;
static const uint32_t D_REG_CMN_CONFIG_CNTR0_PS_LEN = 2;
static const uint32_t D_REG_CMN_CONFIG_CNTR0_ES = 54;
static const uint32_t D_REG_CMN_CONFIG_CNTR0_ES_LEN = 2;
static const uint32_t D_REG_CMN_CONFIG_CNTR3_PE = 56;
static const uint32_t D_REG_CMN_CONFIG_CNTR2_PE = 57;
static const uint32_t D_REG_CMN_CONFIG_CNTR1_PE = 58;
static const uint32_t D_REG_CMN_CONFIG_CNTR0_PE = 59;
static const uint32_t D_REG_CMN_CONFIG_CNTR3_EN = 60;
static const uint32_t D_REG_CMN_CONFIG_CNTR2_EN = 61;
static const uint32_t D_REG_CMN_CONFIG_CNTR1_EN = 62;
static const uint32_t D_REG_CMN_CONFIG_CNTR0_EN = 63;


static const uint64_t D_REG_DL0_CONFIG0 = 0x8012410ull;

static const uint32_t D_REG_DL0_CONFIG0_ENABLE = 0;
static const uint32_t D_REG_DL0_CONFIG0_CFG0_SPARE_61_58 = 1;
static const uint32_t D_REG_DL0_CONFIG0_CFG0_SPARE_61_58_LEN = 5;
static const uint32_t D_REG_DL0_CONFIG0_CFG_TL_CREDITS = 6;
static const uint32_t D_REG_DL0_CONFIG0_CFG_TL_CREDITS_LEN = 6;
static const uint32_t D_REG_DL0_CONFIG0_TL_EVENT_ACTIONS = 12;
static const uint32_t D_REG_DL0_CONFIG0_TL_EVENT_ACTIONS_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG0_TL_ERROR_ACTIONS = 16;
static const uint32_t D_REG_DL0_CONFIG0_TL_ERROR_ACTIONS_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG0_FWD_PROGRESS_TIMER = 20;
static const uint32_t D_REG_DL0_CONFIG0_FWD_PROGRESS_TIMER_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG0_REPLAY_RSVD_ENTRIES = 24;
static const uint32_t D_REG_DL0_CONFIG0_REPLAY_RSVD_ENTRIES_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG0_DEBUG_SELECT = 28;
static const uint32_t D_REG_DL0_CONFIG0_DEBUG_SELECT_LEN = 3;
static const uint32_t D_REG_DL0_CONFIG0_DEBUG_ENABLE = 31;
static const uint32_t D_REG_DL0_CONFIG0_DL2TL_DATA_PARITY_INJECT = 32;
static const uint32_t D_REG_DL0_CONFIG0_CONTROL_PARITY_INJECT = 33;
static const uint32_t D_REG_DL0_CONFIG0_ECC_UE_INJECTION = 34;
static const uint32_t D_REG_DL0_CONFIG0_ECC_CE_INJECTION = 35;
static const uint32_t D_REG_DL0_CONFIG0_FP_DISABLE = 36;
static const uint32_t D_REG_DL0_CONFIG0_RX_LN_REV_ENA = 37;
static const uint32_t D_REG_DL0_CONFIG0_TX_LN_REV_ENA = 38;
static const uint32_t D_REG_DL0_CONFIG0_CFG0_SPARE_24 = 39;
static const uint32_t D_REG_DL0_CONFIG0_PHY_CNTR_LIMIT = 40;
static const uint32_t D_REG_DL0_CONFIG0_PHY_CNTR_LIMIT_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG0_RUNLANE_OVRD_ENABLE = 44;
static const uint32_t D_REG_DL0_CONFIG0_PWRMGT_ENABLE = 45;
static const uint32_t D_REG_DL0_CONFIG0_CFG0_SPARE_17 = 46;
static const uint32_t D_REG_DL0_CONFIG0_HALF_WIDTH_BACKOFF_ENABLE = 47;
static const uint32_t D_REG_DL0_CONFIG0_SUPPORTED_MODES = 48;
static const uint32_t D_REG_DL0_CONFIG0_SUPPORTED_MODES_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG0_TRAIN_MODE = 52;
static const uint32_t D_REG_DL0_CONFIG0_TRAIN_MODE_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG0_VERSION = 56;
static const uint32_t D_REG_DL0_CONFIG0_VERSION_LEN = 6;
static const uint32_t D_REG_DL0_CONFIG0_RETRAIN = 62;
static const uint32_t D_REG_DL0_CONFIG0_RESET = 63;


static const uint64_t D_REG_DL0_CONFIG1 = 0x8012411ull;

static const uint32_t D_REG_DL0_CONFIG1_CFG1_SPARE_63_62 = 0;
static const uint32_t D_REG_DL0_CONFIG1_CFG1_SPARE_63_62_LEN = 2;
static const uint32_t D_REG_DL0_CONFIG1_LANE_WIDTH = 2;
static const uint32_t D_REG_DL0_CONFIG1_LANE_WIDTH_LEN = 2;
static const uint32_t D_REG_DL0_CONFIG1_PREIPL_PRBS_ENA = 4;
static const uint32_t D_REG_DL0_CONFIG1_PREIPL_PRBS_TIME = 5;
static const uint32_t D_REG_DL0_CONFIG1_PREIPL_PRBS_TIME_LEN = 3;
static const uint32_t D_REG_DL0_CONFIG1_B_HYSTERESIS = 8;
static const uint32_t D_REG_DL0_CONFIG1_B_HYSTERESIS_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG1_A_HYSTERESIS = 12;
static const uint32_t D_REG_DL0_CONFIG1_A_HYSTERESIS_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG1_B_PATTERN_LENGTH = 16;
static const uint32_t D_REG_DL0_CONFIG1_B_PATTERN_LENGTH_LEN = 2;
static const uint32_t D_REG_DL0_CONFIG1_A_PATTERN_LENGTH = 18;
static const uint32_t D_REG_DL0_CONFIG1_A_PATTERN_LENGTH_LEN = 2;
static const uint32_t D_REG_DL0_CONFIG1_TX_PERF_DEGRADED = 20;
static const uint32_t D_REG_DL0_CONFIG1_TX_PERF_DEGRADED_LEN = 2;
static const uint32_t D_REG_DL0_CONFIG1_RX_PERF_DEGRADED = 22;
static const uint32_t D_REG_DL0_CONFIG1_RX_PERF_DEGRADED_LEN = 2;
static const uint32_t D_REG_DL0_CONFIG1_TX_LANES_DISABLE = 24;
static const uint32_t D_REG_DL0_CONFIG1_TX_LANES_DISABLE_LEN = 8;
static const uint32_t D_REG_DL0_CONFIG1_RX_LANES_DISABLE = 32;
static const uint32_t D_REG_DL0_CONFIG1_RX_LANES_DISABLE_LEN = 8;
static const uint32_t D_REG_DL0_CONFIG1_MACRO_DBG_SEL = 40;
static const uint32_t D_REG_DL0_CONFIG1_MACRO_DBG_SEL_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG1_RESET_ERR_HLD = 44;
static const uint32_t D_REG_DL0_CONFIG1_RESET_ERR_CAP = 45;
static const uint32_t D_REG_DL0_CONFIG1_RESET_TSHD_REG = 46;
static const uint32_t D_REG_DL0_CONFIG1_RESET_RMT_MSG = 47;
static const uint32_t D_REG_DL0_CONFIG1_INJECT_CRC_DIRECTION = 48;
static const uint32_t D_REG_DL0_CONFIG1_INJECT_CRC_RATE = 49;
static const uint32_t D_REG_DL0_CONFIG1_INJECT_CRC_RATE_LEN = 3;
static const uint32_t D_REG_DL0_CONFIG1_INJECT_CRC_LANE = 52;
static const uint32_t D_REG_DL0_CONFIG1_INJECT_CRC_LANE_LEN = 3;
static const uint32_t D_REG_DL0_CONFIG1_INJECT_CRC_ERROR = 55;
static const uint32_t D_REG_DL0_CONFIG1_EDPL_TIME = 56;
static const uint32_t D_REG_DL0_CONFIG1_EDPL_TIME_LEN = 4;
static const uint32_t D_REG_DL0_CONFIG1_EDPL_THRESHOLD = 60;
static const uint32_t D_REG_DL0_CONFIG1_EDPL_THRESHOLD_LEN = 3;
static const uint32_t D_REG_DL0_CONFIG1_EDPL_ENA = 63;


static const uint64_t D_REG_DL0_CYA2 = 0x801241Cull;

static const uint32_t D_REG_DL0_CYA2_3_SELECT = 48;
static const uint32_t D_REG_DL0_CYA2_3_SELECT_LEN = 4;
static const uint32_t D_REG_DL0_CYA2_2_SELECT = 52;
static const uint32_t D_REG_DL0_CYA2_2_SELECT_LEN = 4;
static const uint32_t D_REG_DL0_CYA2_1_SELECT = 56;
static const uint32_t D_REG_DL0_CYA2_1_SELECT_LEN = 4;
static const uint32_t D_REG_DL0_CYA2_0_SELECT = 60;
static const uint32_t D_REG_DL0_CYA2_0_SELECT_LEN = 4;


static const uint64_t D_REG_DL0_CYA_BITS = 0x801241Full;

static const uint32_t D_REG_DL0_CYA_BITS_PRBS15_NPRBS7 = 0;
static const uint32_t D_REG_DL0_CYA_BITS_ALLOW_UNDEGRADE = 1;
static const uint32_t D_REG_DL0_CYA_BITS_KEEP_DEGRADED_TX_ON = 2;
static const uint32_t D_REG_DL0_CYA_BITS_KEEP_DEGRADED_RX_ON = 3;
static const uint32_t D_REG_DL0_CYA_BITS_SERIAL_PM_RECAL = 4;
static const uint32_t D_REG_DL0_CYA_BITS_FAST_PM_WIDEN = 5;
static const uint32_t D_REG_DL0_CYA_BITS_FULL_RETRAINS = 6;
static const uint32_t D_REG_DL0_CYA_BITS_SKIP_AB_TEST = 7;
static const uint32_t D_REG_DL0_CYA_BITS_SKIP_SYNC_WAIT = 8;
static const uint32_t D_REG_DL0_CYA_BITS_Z_LANE_NUMS = 9;
static const uint32_t D_REG_DL0_CYA_BITS_PM_TIMEOUT = 10;
static const uint32_t D_REG_DL0_CYA_BITS_PM_TIMEOUT_LEN = 2;
static const uint32_t D_REG_DL0_CYA_BITS_LEAK_DISABLE = 12;
static const uint32_t D_REG_DL0_CYA_BITS_RECAL_NOWAIT = 13;
static const uint32_t D_REG_DL0_CYA_BITS_RECAL_OVERRUN_EN = 14;
static const uint32_t D_REG_DL0_CYA_BITS_REDO_CLK_ALIGN = 15;
static const uint32_t D_REG_DL0_CYA_BITS_MESO_LO_THR = 16;
static const uint32_t D_REG_DL0_CYA_BITS_MESO_LO_THR_LEN = 2;
static const uint32_t D_REG_DL0_CYA_BITS_MESO_HI_THR = 18;
static const uint32_t D_REG_DL0_CYA_BITS_MESO_HI_THR_LEN = 2;
static const uint32_t D_REG_DL0_CYA_BITS_MESO_LO_ACTION = 20;
static const uint32_t D_REG_DL0_CYA_BITS_MESO_HI_ACTION = 21;
static const uint32_t D_REG_DL0_CYA_BITS_SPARE_41 = 22;
static const uint32_t D_REG_DL0_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT = 23;
static const uint32_t D_REG_DL0_CYA_BITS_RX_PN_SWAP_OVERRIDE = 24;
static const uint32_t D_REG_DL0_CYA_BITS_RX_PN_SWAP_OVERRIDE_LEN = 8;
static const uint32_t D_REG_DL0_CYA_BITS_TRIG_SEL = 32;
static const uint32_t D_REG_DL0_CYA_BITS_TRIG_SEL_LEN = 4;
static const uint32_t D_REG_DL0_CYA_BITS_SPARE_27_20 = 36;
static const uint32_t D_REG_DL0_CYA_BITS_SPARE_27_20_LEN = 8;
static const uint32_t D_REG_DL0_CYA_BITS_TX_PSAVE_DELAY_TIMER = 44;
static const uint32_t D_REG_DL0_CYA_BITS_TX_PSAVE_DELAY_TIMER_LEN = 3;
static const uint32_t D_REG_DL0_CYA_BITS_FAST_RETRAIN_DISABLE = 47;
static const uint32_t D_REG_DL0_CYA_BITS_SPARE15 = 48;
static const uint32_t D_REG_DL0_CYA_BITS_KILL_CRC_REPLAY = 49;
static const uint32_t D_REG_DL0_CYA_BITS_RETRAIN_CRC_REPLAY = 50;
static const uint32_t D_REG_DL0_CYA_BITS_PM_DISABLE_EDPL = 51;
static const uint32_t D_REG_DL0_CYA_BITS_RETRAIN_CRC = 52;
static const uint32_t D_REG_DL0_CYA_BITS_RETRAIN_CRC_RESET = 53;
static const uint32_t D_REG_DL0_CYA_BITS_FRBUF_FULL = 54;
static const uint32_t D_REG_DL0_CYA_BITS_FRBUF_FULL_REPLAY = 55;
static const uint32_t D_REG_DL0_CYA_BITS_PM_RETRAIN = 56;
static const uint32_t D_REG_DL0_CYA_BITS_PM_RESET = 57;
static const uint32_t D_REG_DL0_CYA_BITS_CRC_RETRAIN = 58;
static const uint32_t D_REG_DL0_CYA_BITS_CRC_RESET = 59;
static const uint32_t D_REG_DL0_CYA_BITS_MESO_BUFFER_ENABLE = 60;
static const uint32_t D_REG_DL0_CYA_BITS_MESO_BUFFER_START = 61;
static const uint32_t D_REG_DL0_CYA_BITS_MESO_BUFFER_DEPTH = 62;
static const uint32_t D_REG_DL0_CYA_BITS_MESO_BUFFER_DEPTH_LEN = 2;


static const uint64_t D_REG_DL0_DEBUG_AID = 0x801241Eull;

static const uint32_t D_REG_DL0_DEBUG_AID_RX_RECAL_MAX_LANE = 32;
static const uint32_t D_REG_DL0_DEBUG_AID_RX_RECAL_MAX_LANE_LEN = 3;
static const uint32_t D_REG_DL0_DEBUG_AID_RX_RECAL_MAX_TIME = 35;
static const uint32_t D_REG_DL0_DEBUG_AID_RX_RECAL_MAX_TIME_LEN = 5;
static const uint32_t D_REG_DL0_DEBUG_AID_RX_LANE_INVERTED = 40;
static const uint32_t D_REG_DL0_DEBUG_AID_RX_LANE_INVERTED_LEN = 8;
static const uint32_t D_REG_DL0_DEBUG_AID_PRBS_RESET = 55;
static const uint32_t D_REG_DL0_DEBUG_AID_PRBS_STATUS = 56;
static const uint32_t D_REG_DL0_DEBUG_AID_PRBS_STATUS_LEN = 8;


static const uint64_t D_REG_DL0_EDPL_MAX_COUNT = 0x8012415ull;

static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_7_MAX_COUNT = 0;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_7_MAX_COUNT_LEN = 8;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_6_MAX_COUNT = 8;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_6_MAX_COUNT_LEN = 8;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_5_MAX_COUNT = 16;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_5_MAX_COUNT_LEN = 8;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_4_MAX_COUNT = 24;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_4_MAX_COUNT_LEN = 8;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_3_MAX_COUNT = 32;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_3_MAX_COUNT_LEN = 8;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_2_MAX_COUNT = 40;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_2_MAX_COUNT_LEN = 8;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_1_MAX_COUNT = 48;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_1_MAX_COUNT_LEN = 8;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_0_MAX_COUNT = 56;
static const uint32_t D_REG_DL0_EDPL_MAX_COUNT_0_MAX_COUNT_LEN = 8;


static const uint64_t D_REG_DL0_ERROR_ACTION = 0x801241Dull;

static const uint32_t D_REG_DL0_ERROR_ACTION_12_ACTION = 16;
static const uint32_t D_REG_DL0_ERROR_ACTION_12_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_11_ACTION = 20;
static const uint32_t D_REG_DL0_ERROR_ACTION_11_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_10_ACTION = 24;
static const uint32_t D_REG_DL0_ERROR_ACTION_10_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_9_ACTION = 28;
static const uint32_t D_REG_DL0_ERROR_ACTION_9_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_8_ACTION = 32;
static const uint32_t D_REG_DL0_ERROR_ACTION_8_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_7_ACTION = 36;
static const uint32_t D_REG_DL0_ERROR_ACTION_7_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_6_ACTION = 40;
static const uint32_t D_REG_DL0_ERROR_ACTION_6_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_5_ACTION = 44;
static const uint32_t D_REG_DL0_ERROR_ACTION_5_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_4_ACTION = 48;
static const uint32_t D_REG_DL0_ERROR_ACTION_4_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_3_ACTION = 52;
static const uint32_t D_REG_DL0_ERROR_ACTION_3_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_2_ACTION = 56;
static const uint32_t D_REG_DL0_ERROR_ACTION_2_ACTION_LEN = 4;
static const uint32_t D_REG_DL0_ERROR_ACTION_1_ACTION = 60;
static const uint32_t D_REG_DL0_ERROR_ACTION_1_ACTION_LEN = 4;


static const uint64_t D_REG_DL0_ERROR_HOLD = 0x8012413ull;

static const uint32_t D_REG_DL0_ERROR_HOLD_47 = 16;
static const uint32_t D_REG_DL0_ERROR_HOLD_46 = 17;
static const uint32_t D_REG_DL0_ERROR_HOLD_45 = 18;
static const uint32_t D_REG_DL0_ERROR_HOLD_44 = 19;
static const uint32_t D_REG_DL0_ERROR_HOLD_43 = 20;
static const uint32_t D_REG_DL0_ERROR_HOLD_42 = 21;
static const uint32_t D_REG_DL0_ERROR_HOLD_41 = 22;
static const uint32_t D_REG_DL0_ERROR_HOLD_40 = 23;
static const uint32_t D_REG_DL0_ERROR_HOLD_39 = 24;
static const uint32_t D_REG_DL0_ERROR_HOLD_38 = 25;
static const uint32_t D_REG_DL0_ERROR_HOLD_37 = 26;
static const uint32_t D_REG_DL0_ERROR_HOLD_36 = 27;
static const uint32_t D_REG_DL0_ERROR_HOLD_35 = 28;
static const uint32_t D_REG_DL0_ERROR_HOLD_34 = 29;
static const uint32_t D_REG_DL0_ERROR_HOLD_33 = 30;
static const uint32_t D_REG_DL0_ERROR_HOLD_32 = 31;
static const uint32_t D_REG_DL0_ERROR_HOLD_31 = 32;
static const uint32_t D_REG_DL0_ERROR_HOLD_30 = 33;
static const uint32_t D_REG_DL0_ERROR_HOLD_29 = 34;
static const uint32_t D_REG_DL0_ERROR_HOLD_28 = 35;
static const uint32_t D_REG_DL0_ERROR_HOLD_27 = 36;
static const uint32_t D_REG_DL0_ERROR_HOLD_26 = 37;
static const uint32_t D_REG_DL0_ERROR_HOLD_25 = 38;
static const uint32_t D_REG_DL0_ERROR_HOLD_24 = 39;
static const uint32_t D_REG_DL0_ERROR_HOLD_23 = 40;
static const uint32_t D_REG_DL0_ERROR_HOLD_22 = 41;
static const uint32_t D_REG_DL0_ERROR_HOLD_21 = 42;
static const uint32_t D_REG_DL0_ERROR_HOLD_20 = 43;
static const uint32_t D_REG_DL0_ERROR_HOLD_19 = 44;
static const uint32_t D_REG_DL0_ERROR_HOLD_18 = 45;
static const uint32_t D_REG_DL0_ERROR_HOLD_17 = 46;
static const uint32_t D_REG_DL0_ERROR_HOLD_16 = 47;
static const uint32_t D_REG_DL0_ERROR_HOLD_15 = 48;
static const uint32_t D_REG_DL0_ERROR_HOLD_14 = 49;
static const uint32_t D_REG_DL0_ERROR_HOLD_13 = 50;
static const uint32_t D_REG_DL0_ERROR_HOLD_12 = 51;
static const uint32_t D_REG_DL0_ERROR_HOLD_11 = 52;
static const uint32_t D_REG_DL0_ERROR_HOLD_10 = 53;
static const uint32_t D_REG_DL0_ERROR_HOLD_09 = 54;
static const uint32_t D_REG_DL0_ERROR_HOLD_08 = 55;
static const uint32_t D_REG_DL0_ERROR_HOLD_07 = 56;
static const uint32_t D_REG_DL0_ERROR_HOLD_06 = 57;
static const uint32_t D_REG_DL0_ERROR_HOLD_05 = 58;
static const uint32_t D_REG_DL0_ERROR_HOLD_04 = 59;
static const uint32_t D_REG_DL0_ERROR_HOLD_03 = 60;
static const uint32_t D_REG_DL0_ERROR_HOLD_02 = 61;
static const uint32_t D_REG_DL0_ERROR_HOLD_01 = 62;
static const uint32_t D_REG_DL0_ERROR_HOLD_00 = 63;


static const uint64_t D_REG_DL0_ERROR_MASK = 0x8012412ull;

static const uint32_t D_REG_DL0_ERROR_MASK_47 = 16;
static const uint32_t D_REG_DL0_ERROR_MASK_46 = 17;
static const uint32_t D_REG_DL0_ERROR_MASK_45 = 18;
static const uint32_t D_REG_DL0_ERROR_MASK_44 = 19;
static const uint32_t D_REG_DL0_ERROR_MASK_43 = 20;
static const uint32_t D_REG_DL0_ERROR_MASK_42 = 21;
static const uint32_t D_REG_DL0_ERROR_MASK_41 = 22;
static const uint32_t D_REG_DL0_ERROR_MASK_40 = 23;
static const uint32_t D_REG_DL0_ERROR_MASK_39 = 24;
static const uint32_t D_REG_DL0_ERROR_MASK_38 = 25;
static const uint32_t D_REG_DL0_ERROR_MASK_37 = 26;
static const uint32_t D_REG_DL0_ERROR_MASK_36 = 27;
static const uint32_t D_REG_DL0_ERROR_MASK_35 = 28;
static const uint32_t D_REG_DL0_ERROR_MASK_34 = 29;
static const uint32_t D_REG_DL0_ERROR_MASK_33 = 30;
static const uint32_t D_REG_DL0_ERROR_MASK_32 = 31;
static const uint32_t D_REG_DL0_ERROR_MASK_31 = 32;
static const uint32_t D_REG_DL0_ERROR_MASK_30 = 33;
static const uint32_t D_REG_DL0_ERROR_MASK_29 = 34;
static const uint32_t D_REG_DL0_ERROR_MASK_28 = 35;
static const uint32_t D_REG_DL0_ERROR_MASK_27 = 36;
static const uint32_t D_REG_DL0_ERROR_MASK_26 = 37;
static const uint32_t D_REG_DL0_ERROR_MASK_25 = 38;
static const uint32_t D_REG_DL0_ERROR_MASK_24 = 39;
static const uint32_t D_REG_DL0_ERROR_MASK_23 = 40;
static const uint32_t D_REG_DL0_ERROR_MASK_22 = 41;
static const uint32_t D_REG_DL0_ERROR_MASK_21 = 42;
static const uint32_t D_REG_DL0_ERROR_MASK_20 = 43;
static const uint32_t D_REG_DL0_ERROR_MASK_19 = 44;
static const uint32_t D_REG_DL0_ERROR_MASK_18 = 45;
static const uint32_t D_REG_DL0_ERROR_MASK_17 = 46;
static const uint32_t D_REG_DL0_ERROR_MASK_16 = 47;
static const uint32_t D_REG_DL0_ERROR_MASK_15 = 48;
static const uint32_t D_REG_DL0_ERROR_MASK_14 = 49;
static const uint32_t D_REG_DL0_ERROR_MASK_13 = 50;
static const uint32_t D_REG_DL0_ERROR_MASK_12 = 51;
static const uint32_t D_REG_DL0_ERROR_MASK_11 = 52;
static const uint32_t D_REG_DL0_ERROR_MASK_10 = 53;
static const uint32_t D_REG_DL0_ERROR_MASK_09 = 54;
static const uint32_t D_REG_DL0_ERROR_MASK_08 = 55;
static const uint32_t D_REG_DL0_ERROR_MASK_07 = 56;
static const uint32_t D_REG_DL0_ERROR_MASK_06 = 57;
static const uint32_t D_REG_DL0_ERROR_MASK_05 = 58;
static const uint32_t D_REG_DL0_ERROR_MASK_04 = 59;
static const uint32_t D_REG_DL0_ERROR_MASK_03 = 60;
static const uint32_t D_REG_DL0_ERROR_MASK_02 = 61;
static const uint32_t D_REG_DL0_ERROR_MASK_01 = 62;
static const uint32_t D_REG_DL0_ERROR_MASK_00 = 63;


static const uint64_t D_REG_DL0_RMT_CONFIG = 0x8012418ull;

static const uint32_t D_REG_DL0_RMT_CONFIG_CFG_DL0_RMT_CONFIG = 32;
static const uint32_t D_REG_DL0_RMT_CONFIG_CFG_DL0_RMT_CONFIG_LEN = 32;


static const uint64_t D_REG_DL0_RMT_INFO = 0x8012419ull;

static const uint32_t D_REG_DL0_RMT_INFO_DL0_RMT_MESSAGE = 0;
static const uint32_t D_REG_DL0_RMT_INFO_DL0_RMT_MESSAGE_LEN = 64;


static const uint64_t D_REG_DL0_STATUS = 0x8012416ull;

static const uint32_t D_REG_DL0_STATUS_TRAINED_MODE = 0;
static const uint32_t D_REG_DL0_STATUS_TRAINED_MODE_LEN = 4;
static const uint32_t D_REG_DL0_STATUS_RX_LANE_REVERSED = 4;
static const uint32_t D_REG_DL0_STATUS_TX_LANE_REVERSED = 5;
static const uint32_t D_REG_DL0_STATUS_IDLE_SIZE = 6;
static const uint32_t D_REG_DL0_STATUS_ACK_PTRS_EQUAL = 7;
static const uint32_t D_REG_DL0_STATUS_CLK_ALIGN_PENDING = 8;
static const uint32_t D_REG_DL0_STATUS_SPARE_54 = 9;
static const uint32_t D_REG_DL0_STATUS_ACTUAL_RX_WIDTH = 10;
static const uint32_t D_REG_DL0_STATUS_ACTUAL_RX_WIDTH_LEN = 2;
static const uint32_t D_REG_DL0_STATUS_REQUESTED_LN_WIDTH = 12;
static const uint32_t D_REG_DL0_STATUS_REQUESTED_LN_WIDTH_LEN = 2;
static const uint32_t D_REG_DL0_STATUS_ACTUAL_TX_WIDTH = 14;
static const uint32_t D_REG_DL0_STATUS_ACTUAL_TX_WIDTH_LEN = 2;
static const uint32_t D_REG_DL0_STATUS_TX_TRAINED_LANES = 16;
static const uint32_t D_REG_DL0_STATUS_TX_TRAINED_LANES_LEN = 8;
static const uint32_t D_REG_DL0_STATUS_RX_TRAINED_LANES = 24;
static const uint32_t D_REG_DL0_STATUS_RX_TRAINED_LANES_LEN = 8;
static const uint32_t D_REG_DL0_STATUS_ENDPOINT_INFO = 32;
static const uint32_t D_REG_DL0_STATUS_ENDPOINT_INFO_LEN = 15;
static const uint32_t D_REG_DL0_STATUS_PM_DISABLED = 47;
static const uint32_t D_REG_DL0_STATUS_SPARE_15 = 48;
static const uint32_t D_REG_DL0_STATUS_TRAINING_STATE_MACHINE = 49;
static const uint32_t D_REG_DL0_STATUS_TRAINING_STATE_MACHINE_LEN = 3;
static const uint32_t D_REG_DL0_STATUS_SPARE_11_9 = 52;
static const uint32_t D_REG_DL0_STATUS_SPARE_11_9_LEN = 3;
static const uint32_t D_REG_DL0_STATUS_DESKEW_DONE = 55;
static const uint32_t D_REG_DL0_STATUS_LANES_DISABLED = 56;
static const uint32_t D_REG_DL0_STATUS_LANES_DISABLED_LEN = 8;


static const uint64_t D_REG_DL0_TRAINING_STATUS = 0x8012417ull;

static const uint32_t D_REG_DL0_TRAINING_STATUS_RX_PATTERN_A = 0;
static const uint32_t D_REG_DL0_TRAINING_STATUS_RX_PATTERN_A_LEN = 8;
static const uint32_t D_REG_DL0_TRAINING_STATUS_RX_PATTERN_B = 8;
static const uint32_t D_REG_DL0_TRAINING_STATUS_RX_PATTERN_B_LEN = 8;
static const uint32_t D_REG_DL0_TRAINING_STATUS_SYNC_PATTERN = 16;
static const uint32_t D_REG_DL0_TRAINING_STATUS_SYNC_PATTERN_LEN = 8;
static const uint32_t D_REG_DL0_TRAINING_STATUS_PHY_INIT_DONE = 24;
static const uint32_t D_REG_DL0_TRAINING_STATUS_PHY_INIT_DONE_LEN = 8;
static const uint32_t D_REG_DL0_TRAINING_STATUS_BLOCK_LOCKED = 32;
static const uint32_t D_REG_DL0_TRAINING_STATUS_BLOCK_LOCKED_LEN = 8;
static const uint32_t D_REG_DL0_TRAINING_STATUS_RX_TS1 = 40;
static const uint32_t D_REG_DL0_TRAINING_STATUS_RX_TS1_LEN = 8;
static const uint32_t D_REG_DL0_TRAINING_STATUS_RX_TS2 = 48;
static const uint32_t D_REG_DL0_TRAINING_STATUS_RX_TS2_LEN = 8;
static const uint32_t D_REG_DL0_TRAINING_STATUS_RX_TS3 = 56;
static const uint32_t D_REG_DL0_TRAINING_STATUS_RX_TS3_LEN = 8;


static const uint64_t D_REG_MC_OMI_FIR_WO_OR = 0x8012401ull;
static const uint64_t D_REG_MC_OMI_FIR_RW_WCLEAR = 0x8012400ull;

static const uint32_t D_REG_MC_OMI_FIR_LFIR_PAR_ERR = 0;
static const uint32_t D_REG_MC_OMI_FIR_DL0_FATAL_ERROR = 1;
static const uint32_t D_REG_MC_OMI_FIR_DL0_DATA_UE = 2;
static const uint32_t D_REG_MC_OMI_FIR_DL0_FLIT_CE = 3;
static const uint32_t D_REG_MC_OMI_FIR_DL0_CRC_ERROR = 4;
static const uint32_t D_REG_MC_OMI_FIR_DL0_NACK = 5;
static const uint32_t D_REG_MC_OMI_FIR_DL0_X4_MODE = 6;
static const uint32_t D_REG_MC_OMI_FIR_DL0_EDPL = 7;
static const uint32_t D_REG_MC_OMI_FIR_DL0_TIMEOUT = 8;
static const uint32_t D_REG_MC_OMI_FIR_DL0_REMOTE_RETRAIN = 9;
static const uint32_t D_REG_MC_OMI_FIR_DL0_ERROR_RETRAIN = 10;
static const uint32_t D_REG_MC_OMI_FIR_DL0_EDPL_RETRAIN = 11;
static const uint32_t D_REG_MC_OMI_FIR_DL0_TRAINED = 12;
static const uint32_t D_REG_MC_OMI_FIR_DL0_ENDPOINT_FIR0 = 13;
static const uint32_t D_REG_MC_OMI_FIR_DL0_ENDPOINT_FIR1 = 14;
static const uint32_t D_REG_MC_OMI_FIR_DL0_ENDPOINT_FIR2 = 15;
static const uint32_t D_REG_MC_OMI_FIR_DL0_ENDPOINT_FIR3 = 16;
static const uint32_t D_REG_MC_OMI_FIR_DL0_ENDPOINT_FIR4 = 17;
static const uint32_t D_REG_MC_OMI_FIR_DL0_ENDPOINT_FIR5 = 18;
static const uint32_t D_REG_MC_OMI_FIR_DL0_ENDPOINT_FIR6 = 19;
static const uint32_t D_REG_MC_OMI_FIR_DL0_ENDPOINT_FIR7 = 20;


static const uint64_t D_REG_MC_OMI_FIR_CFGLXSTOP = 0x8012407ull;



static const uint64_t D_REG_MC_OMI_FIR_CFGRECOV = 0x8012405ull;



static const uint64_t D_REG_MC_OMI_FIR_CFGSPATTN = 0x8012406ull;



static const uint64_t D_REG_MC_OMI_FIR_CFGXSTOP = 0x8012404ull;



static const uint64_t D_REG_MC_OMI_FIR_MASK_WO_OR = 0x8012403ull;
static const uint64_t D_REG_MC_OMI_FIR_MASK_RW_WCLEAR = 0x8012402ull;



static const uint64_t D_REG_MC_OMI_FIR_WOF = 0x8012408ull;

static const uint32_t D_REG_MC_OMI_FIR_WOF_MC_OMI_FIR_WOF = 0;
static const uint32_t D_REG_MC_OMI_FIR_WOF_MC_OMI_FIR_WOF_LEN = 43;


static const uint64_t D_REG_PMU_CNTR = 0x801240Full;

static const uint32_t D_REG_PMU_CNTR_3 = 0;
static const uint32_t D_REG_PMU_CNTR_3_LEN = 16;
static const uint32_t D_REG_PMU_CNTR_2 = 16;
static const uint32_t D_REG_PMU_CNTR_2_LEN = 16;
static const uint32_t D_REG_PMU_CNTR_1 = 32;
static const uint32_t D_REG_PMU_CNTR_1_LEN = 16;
static const uint32_t D_REG_PMU_CNTR_0 = 48;
static const uint32_t D_REG_PMU_CNTR_0_LEN = 16;



#ifndef __PPE_HCODE__
}
}
#endif

#ifndef SCOMT_OMIT_FIELD_ACCESSORS
    #include "ody_scom_omi_odc_fields.H"
#endif
