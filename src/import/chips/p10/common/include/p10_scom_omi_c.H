/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_c.H $        */
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

#ifndef __p10_scom_omi_c_H_
#define __p10_scom_omi_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [DLX_INFO]
static const uint64_t DLX_INFO = 0x0c011419ull;

static const uint32_t DLX_INFO_DL0_STS_DLX_INFO = 0;
static const uint32_t DLX_INFO_DL0_STS_DLX_INFO_LEN = 64;
static const uint32_t DLX_INFO_DL1_STS_DLX_INFO = 0;
static const uint32_t DLX_INFO_DL1_STS_DLX_INFO_LEN = 64;
//<< [DLX_INFO]
// omi/reg00024.H

//>> [TRAINING_STATUS]
static const uint64_t TRAINING_STATUS = 0x0c011417ull;

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
//<< [TRAINING_STATUS]
// omi/reg00025.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00024.H"
#include "omi/reg00025.H"
#endif
#endif
