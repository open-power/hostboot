/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_b.H $        */
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

#ifndef __p10_scom_omi_b_H_
#define __p10_scom_omi_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [CONFIG0]
static const uint64_t CONFIG0 = 0x0c011410ull;

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
static const uint32_t CONFIG0_TX_LN_REV_ENA = 38;
static const uint32_t CONFIG0_128_130_ENCODING_ENABLED = 39;
static const uint32_t CONFIG0_PHY_CNTR_LIMIT = 40;
static const uint32_t CONFIG0_PHY_CNTR_LIMIT_LEN = 4;
static const uint32_t CONFIG0_RUNLANE_OVRD_ENABLE = 44;
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
//<< [CONFIG0]
// omi/reg00022.H

//>> [DLX_CONFIG]
static const uint64_t DLX_CONFIG = 0x0c011418ull;

static const uint32_t DLX_CONFIG_CFG_DLX0 = 32;
static const uint32_t DLX_CONFIG_CFG_DLX0_LEN = 32;
static const uint32_t DLX_CONFIG_CFG_DLX1 = 32;
static const uint32_t DLX_CONFIG_CFG_DLX1_LEN = 32;
//<< [DLX_CONFIG]
// omi/reg00022.H

//>> [ERROR_ACTION]
static const uint64_t ERROR_ACTION = 0x0c01141dull;

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
//<< [ERROR_ACTION]
// omi/reg00022.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00022.H"
#include "omi/reg00023.H"
#endif
#endif
