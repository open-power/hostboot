/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_a.H $       */
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

#ifndef __p10_scom_iohs_a_H_
#define __p10_scom_iohs_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_LINK0_TX_LANE_CONTROL]
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
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_FAILED = 48;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_FAILED_LEN = 9;
//<< [DLP_LINK0_TX_LANE_CONTROL]
// iohs/reg00042.H

//>> [CONFIG]
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
//<< [CONFIG]
// iohs/reg00042.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00042.H"
#include "iohs/reg00043.H"
#include "iohs/reg00044.H"
#include "iohs/reg00045.H"
#endif
#endif
