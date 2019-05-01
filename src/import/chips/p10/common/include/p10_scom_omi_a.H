/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_a.H $        */
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

#ifndef __p10_scom_omi_a_H_
#define __p10_scom_omi_a_H_


namespace scomt
{
namespace omi
{


static const uint64_t CONFIG = 0x10010c2bull;

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
// omi/reg00010.H

static const uint64_t ERROR_CAPTURE = 0x0c011764ull;

static const uint32_t ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO = 1;
static const uint32_t ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO_LEN = 63;
// omi/reg00010.H

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
// omi/reg00010.H

}
}
#include "omi/reg00010.H"
#endif
