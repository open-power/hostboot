/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_4.H $        */
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

#ifndef __p10_scom_pau_4_H_
#define __p10_scom_pau_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [CS_CTL_MISC_FENCE_CONTROL1]
static const uint64_t CS_CTL_MISC_FENCE_CONTROL1 = 0x100109a2ull;

static const uint32_t CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE = 0;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE_LEN = 2;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED = 2;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED_LEN = 2;
//<< [CS_CTL_MISC_FENCE_CONTROL1]
// pau/reg00004.H

//>> [CS_SM1_SNP_MISC_NDT0_BAR]
static const uint64_t CS_SM1_SNP_MISC_NDT0_BAR = 0x10010897ull;

static const uint32_t CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 = 2;
static const uint32_t CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR = 3;
static const uint32_t CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON = 36;
static const uint32_t CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 = 37;
static const uint32_t CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE = 39;
static const uint32_t CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN = 5;
//<< [CS_SM1_SNP_MISC_NDT0_BAR]
// pau/reg00004.H

//>> [CS_SM1_SNP_MISC_NDT1_BAR]
static const uint64_t CS_SM1_SNP_MISC_NDT1_BAR = 0x10010898ull;

static const uint32_t CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 = 2;
static const uint32_t CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR = 3;
static const uint32_t CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON = 36;
static const uint32_t CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 = 37;
static const uint32_t CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE = 39;
static const uint32_t CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN = 5;
//<< [CS_SM1_SNP_MISC_NDT1_BAR]
// pau/reg00004.H

//>> [CS_SM3_SNP_MISC_GENID_BAR]
static const uint64_t CS_SM3_SNP_MISC_GENID_BAR = 0x1001095dull;

static const uint32_t CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1 = 2;
static const uint32_t CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR = 3;
static const uint32_t CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN = 30;
static const uint32_t CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2 = 33;
static const uint32_t CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON = 35;
//<< [CS_SM3_SNP_MISC_GENID_BAR]
// pau/reg00004.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00004.H"
#include "pau/reg00005.H"
#endif
#endif
