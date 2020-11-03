/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_d.H $        */
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

#ifndef __p10_scom_pau_d_H_
#define __p10_scom_pau_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [CS_CTL_MISC_STATUS1]
static const uint64_t CS_CTL_MISC_STATUS1 = 0x1001098cull;

static const uint32_t CS_CTL_MISC_STATUS1_SM_MMIO0 = 0;
static const uint32_t CS_CTL_MISC_STATUS1_SM_MMIO1 = 1;
static const uint32_t CS_CTL_MISC_STATUS1_SM_MMIO2 = 2;
static const uint32_t CS_CTL_MISC_STATUS1_SM_MMIO3 = 3;
static const uint32_t CS_CTL_MISC_STATUS1_MRBGP = 4;
static const uint32_t CS_CTL_MISC_STATUS1_MRBGP_LEN = 4;
static const uint32_t CS_CTL_MISC_STATUS1_MRBSP = 8;
static const uint32_t CS_CTL_MISC_STATUS1_MRBSP_LEN = 4;
static const uint32_t CS_CTL_MISC_STATUS1_MRBCP = 12;
static const uint32_t CS_CTL_MISC_STATUS1_MRBCP_LEN = 4;
static const uint32_t CS_CTL_MISC_STATUS1_LPCTH = 16;
static const uint32_t CS_CTL_MISC_STATUS1_LPCTH_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS1_ATS_SYNC = 18;
static const uint32_t CS_CTL_MISC_STATUS1_NMMU = 19;
static const uint32_t CS_CTL_MISC_STATUS1_PBLN = 20;
static const uint32_t CS_CTL_MISC_STATUS1_PBNNG = 21;
static const uint32_t CS_CTL_MISC_STATUS1_PBRNVG = 22;
static const uint32_t CS_CTL_MISC_STATUS1_ATSREQ = 23;
static const uint32_t CS_CTL_MISC_STATUS1_MMIO = 24;
static const uint32_t CS_CTL_MISC_STATUS1_MMIOSUE = 25;
static const uint32_t CS_CTL_MISC_STATUS1_PBRS = 26;
static const uint32_t CS_CTL_MISC_STATUS1_XARS = 27;
static const uint32_t CS_CTL_MISC_STATUS1_ATRR = 28;
static const uint32_t CS_CTL_MISC_STATUS1_REPLAY = 29;
static const uint32_t CS_CTL_MISC_STATUS1_XSL_FAST_FENCE = 30;
static const uint32_t CS_CTL_MISC_STATUS1_RESERVED = 31;
static const uint32_t CS_CTL_MISC_STATUS1_FENCE0 = 32;
static const uint32_t CS_CTL_MISC_STATUS1_FENCE0_LEN = 5;
static const uint32_t CS_CTL_MISC_STATUS1_BRK0_RLX = 37;
static const uint32_t CS_CTL_MISC_STATUS1_NVREQ0 = 38;
static const uint32_t CS_CTL_MISC_STATUS1_NVDGD0 = 39;
static const uint32_t CS_CTL_MISC_STATUS1_NVRS0 = 40;
static const uint32_t CS_CTL_MISC_STATUS1_BRK0_AM_FENCED = 41;
static const uint32_t CS_CTL_MISC_STATUS1_BRK0_AM_FENCED_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE = 43;
static const uint32_t CS_CTL_MISC_STATUS1_BRK0_NTL_REQ_FENCE_LEN = 2;
static const uint32_t CS_CTL_MISC_STATUS1_BRK0_MISC_FENCE = 45;
static const uint32_t CS_CTL_MISC_STATUS1_BRK0_RESERVED = 46;
static const uint32_t CS_CTL_MISC_STATUS1_BRK0_RESERVED_LEN = 2;
//<< [CS_CTL_MISC_STATUS1]
// pau/reg00016.H

//>> [CS_SM2_SNP_MISC_NDT0_BAR]
static const uint64_t CS_SM2_SNP_MISC_NDT0_BAR = 0x100108f7ull;

static const uint32_t CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 = 2;
static const uint32_t CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR = 3;
static const uint32_t CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON = 36;
static const uint32_t CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 = 37;
static const uint32_t CS_SM2_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE = 39;
static const uint32_t CS_SM2_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN = 5;
//<< [CS_SM2_SNP_MISC_NDT0_BAR]
// pau/reg00016.H

//>> [CS_SM2_SNP_MISC_NDT1_BAR]
static const uint64_t CS_SM2_SNP_MISC_NDT1_BAR = 0x100108f8ull;

static const uint32_t CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 = 2;
static const uint32_t CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR = 3;
static const uint32_t CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON = 36;
static const uint32_t CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 = 37;
static const uint32_t CS_SM2_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE = 39;
static const uint32_t CS_SM2_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN = 5;
//<< [CS_SM2_SNP_MISC_NDT1_BAR]
// pau/reg00016.H

//>> [CS_SM2_SNP_MISC_TOPOLOGY_TABLE0]
static const uint64_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0 = 0x1001091cull;

static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 = 0;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0 = 8;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1 = 12;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2 = 16;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3 = 20;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4 = 24;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5 = 28;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6 = 32;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7 = 36;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN = 4;
//<< [CS_SM2_SNP_MISC_TOPOLOGY_TABLE0]
// pau/reg00016.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00016.H"
#endif
#endif
