/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_2.H $        */
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

#ifndef __p10_scom_pau_2_H_
#define __p10_scom_pau_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [CS_CTL_MISC_FENCE_CONTROL0]
static const uint64_t CS_CTL_MISC_FENCE_CONTROL0 = 0x100109a1ull;

static const uint32_t CS_CTL_MISC_FENCE_CONTROL0_0_REQUEST_FENCE = 0;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL0_0_REQUEST_FENCE_LEN = 2;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL0_CONTROL0_RESERVED = 2;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL0_CONTROL0_RESERVED_LEN = 2;
//<< [CS_CTL_MISC_FENCE_CONTROL0]
// pau/reg00002.H

//>> [CS_SM0_SNP_MISC_TOPOLOGY_TABLE0]
static const uint64_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0 = 0x1001085cull;

static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 = 0;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY0 = 8;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY1 = 12;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY2 = 16;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY3 = 20;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY4 = 24;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY5 = 28;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY6 = 32;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY7 = 36;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN = 4;
//<< [CS_SM0_SNP_MISC_TOPOLOGY_TABLE0]
// pau/reg00002.H

//>> [CS_SM2_SNP_MISC_GENID_BAR]
static const uint64_t CS_SM2_SNP_MISC_GENID_BAR = 0x100108fdull;

static const uint32_t CS_SM2_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM2_SNP_MISC_GENID_BAR_GENID_RESERVED1 = 2;
static const uint32_t CS_SM2_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR = 3;
static const uint32_t CS_SM2_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN = 30;
static const uint32_t CS_SM2_SNP_MISC_GENID_BAR_GENID_RESERVED2 = 33;
static const uint32_t CS_SM2_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON = 35;
//<< [CS_SM2_SNP_MISC_GENID_BAR]
// pau/reg00002.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00002.H"
#endif
#endif
