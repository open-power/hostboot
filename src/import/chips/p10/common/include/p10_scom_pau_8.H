/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_8.H $        */
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

#ifndef __p10_scom_pau_8_H_
#define __p10_scom_pau_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [CS_SM1_SNP_MISC_GENID_BAR]
static const uint64_t CS_SM1_SNP_MISC_GENID_BAR = 0x1001089dull;

static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1 = 2;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR = 3;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN = 30;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2 = 33;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON = 35;
//<< [CS_SM1_SNP_MISC_GENID_BAR]
// pau/reg00009.H

//>> [MISC_FENCE_STATE]
static const uint64_t MISC_FENCE_STATE = 0x10010b46ull;

static const uint32_t MISC_FENCE_STATE_0 = 0;
static const uint32_t MISC_FENCE_STATE_1 = 1;
static const uint32_t MISC_FENCE_STATE_2 = 2;
static const uint32_t MISC_FENCE_STATE_3 = 3;
static const uint32_t MISC_FENCE_STATE_4 = 4;
//<< [MISC_FENCE_STATE]
// pau/reg00009.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00009.H"
#include "pau/reg00010.H"
#endif
#endif
