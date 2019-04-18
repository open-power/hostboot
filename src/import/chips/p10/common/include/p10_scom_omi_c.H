/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_c.H $        */
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

#ifndef __p10_scom_omi_c_H_
#define __p10_scom_omi_c_H_


namespace scomt
{
namespace omi
{


static const uint64_t DLX_INFO = 0x0c011769ull;

static const uint32_t DLX_INFO_DL1_STS_DLX_INFO = 0;
static const uint32_t DLX_INFO_DL1_STS_DLX_INFO_LEN = 64;
// omi/reg00108.H

static const uint64_t PM_REGS_DLR_APSR = 0x0c011eb9ull;
// omi/reg00108.H

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
// omi/reg00108.H

}
}
#include "omi/reg00108.H"
#endif
