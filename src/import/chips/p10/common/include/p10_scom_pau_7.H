/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_7.H $        */
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

#ifndef __p10_scom_pau_7_H_
#define __p10_scom_pau_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [CS_CTL_MISC_STATUS2]
static const uint64_t CS_CTL_MISC_STATUS2 = 0x1001098dull;

static const uint32_t CS_CTL_MISC_STATUS2_FENCE1 = 0;
static const uint32_t CS_CTL_MISC_STATUS2_FENCE1_LEN = 5;
static const uint32_t CS_CTL_MISC_STATUS2_BRK1_RLX = 5;
static const uint32_t CS_CTL_MISC_STATUS2_NVREQ1 = 6;
static const uint32_t CS_CTL_MISC_STATUS2_NVDGD1 = 7;
static const uint32_t CS_CTL_MISC_STATUS2_NVRS1 = 8;
static const uint32_t CS_CTL_MISC_STATUS2_BRK1_AM_FENCED = 9;
static const uint32_t CS_CTL_MISC_STATUS2_BRK1_AM_FENCED_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE = 11;
static const uint32_t CS_CTL_MISC_STATUS2_BRK1_NTL_REQ_FENCE_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_BRK1_MISC_FENCE = 13;
static const uint32_t CS_CTL_MISC_STATUS2_BRK1_RESERVED = 14;
static const uint32_t CS_CTL_MISC_STATUS2_BRK1_RESERVED_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_FENCE2 = 16;
static const uint32_t CS_CTL_MISC_STATUS2_FENCE2_LEN = 5;
static const uint32_t CS_CTL_MISC_STATUS2_BRK2_RLX = 21;
static const uint32_t CS_CTL_MISC_STATUS2_NVREQ2 = 22;
static const uint32_t CS_CTL_MISC_STATUS2_NVDGD2 = 23;
static const uint32_t CS_CTL_MISC_STATUS2_NVRS2 = 24;
static const uint32_t CS_CTL_MISC_STATUS2_BRK2_AM_FENCED = 25;
static const uint32_t CS_CTL_MISC_STATUS2_BRK2_AM_FENCED_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE = 27;
static const uint32_t CS_CTL_MISC_STATUS2_BRK2_NTL_REQ_FENCE_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_BRK2_MISC_FENCE = 29;
static const uint32_t CS_CTL_MISC_STATUS2_BRK2_RESERVED = 30;
static const uint32_t CS_CTL_MISC_STATUS2_BRK2_RESERVED_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_FENCE3 = 32;
static const uint32_t CS_CTL_MISC_STATUS2_FENCE3_LEN = 5;
static const uint32_t CS_CTL_MISC_STATUS2_BRK3_RLX = 37;
static const uint32_t CS_CTL_MISC_STATUS2_NVREQ3 = 38;
static const uint32_t CS_CTL_MISC_STATUS2_NVDGD3 = 39;
static const uint32_t CS_CTL_MISC_STATUS2_NVRS3 = 40;
static const uint32_t CS_CTL_MISC_STATUS2_BRK3_AM_FENCED = 41;
static const uint32_t CS_CTL_MISC_STATUS2_BRK3_AM_FENCED_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE = 43;
static const uint32_t CS_CTL_MISC_STATUS2_BRK3_NTL_REQ_FENCE_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_BRK3_MISC_FENCE = 45;
static const uint32_t CS_CTL_MISC_STATUS2_BRK3_RESERVED = 46;
static const uint32_t CS_CTL_MISC_STATUS2_BRK3_RESERVED_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_FENCE4 = 48;
static const uint32_t CS_CTL_MISC_STATUS2_FENCE4_LEN = 5;
static const uint32_t CS_CTL_MISC_STATUS2_BRK4_RLX = 53;
static const uint32_t CS_CTL_MISC_STATUS2_NVREQ4 = 54;
static const uint32_t CS_CTL_MISC_STATUS2_NVDGD4 = 55;
static const uint32_t CS_CTL_MISC_STATUS2_NVRS4 = 56;
static const uint32_t CS_CTL_MISC_STATUS2_BRK4_AM_FENCED = 57;
static const uint32_t CS_CTL_MISC_STATUS2_BRK4_AM_FENCED_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE = 59;
static const uint32_t CS_CTL_MISC_STATUS2_BRK4_NTL_REQ_FENCE_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS2_BRK4_MISC_FENCE = 61;
static const uint32_t CS_CTL_MISC_STATUS2_BRK4_RESERVED = 62;
static const uint32_t CS_CTL_MISC_STATUS2_BRK4_RESERVED_LEN = 2;
//<< [CS_CTL_MISC_STATUS2]
// pau/reg00008.H

//>> [CS_SM1_SNP_MISC_GPU0_BAR]
static const uint64_t CS_SM1_SNP_MISC_GPU0_BAR = 0x10010892ull;

static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_SL_MODE = 36;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT = 38;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_MODE = 40;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_MODE_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_GRANULE = 44;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_POISON = 45;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_M2MODE = 46;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM1_SNP_MISC_GPU0_BAR_RESERVED = 51;
//<< [CS_SM1_SNP_MISC_GPU0_BAR]
// pau/reg00008.H

//>> [CS_SM1_SNP_MISC_GPU1_BAR]
static const uint64_t CS_SM1_SNP_MISC_GPU1_BAR = 0x10010893ull;

static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_SL_MODE = 36;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT = 38;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_MODE = 40;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_MODE_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_GRANULE = 44;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_POISON = 45;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_M2MODE = 46;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM1_SNP_MISC_GPU1_BAR_RESERVED = 51;
//<< [CS_SM1_SNP_MISC_GPU1_BAR]
// pau/reg00008.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00008.H"
#endif
#endif
