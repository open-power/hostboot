/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_b.H $        */
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

#ifndef __p10_scom_pau_b_H_
#define __p10_scom_pau_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [CS_SM0_SNP_MISC_PAUMMIO_BAR]
static const uint64_t CS_SM0_SNP_MISC_PAUMMIO_BAR = 0x1001083cull;

static const uint32_t CS_SM0_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM0_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED1 = 2;
static const uint32_t CS_SM0_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ADDR = 3;
static const uint32_t CS_SM0_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ADDR_LEN = 25;
static const uint32_t CS_SM0_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED2 = 28;
static const uint32_t CS_SM0_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED2_LEN = 3;
static const uint32_t CS_SM0_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_POISON = 31;
//<< [CS_SM0_SNP_MISC_PAUMMIO_BAR]
// pau/reg00013.H

//>> [CS_SM1_SNP_MISC_PAUMMIO_BAR]
static const uint64_t CS_SM1_SNP_MISC_PAUMMIO_BAR = 0x1001089cull;

static const uint32_t CS_SM1_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM1_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED1 = 2;
static const uint32_t CS_SM1_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ADDR = 3;
static const uint32_t CS_SM1_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ADDR_LEN = 25;
static const uint32_t CS_SM1_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED2 = 28;
static const uint32_t CS_SM1_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED2_LEN = 3;
static const uint32_t CS_SM1_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_POISON = 31;
//<< [CS_SM1_SNP_MISC_PAUMMIO_BAR]
// pau/reg00013.H

//>> [CS_SM2_SNP_MISC_PAUMMIO_BAR]
static const uint64_t CS_SM2_SNP_MISC_PAUMMIO_BAR = 0x100108fcull;

static const uint32_t CS_SM2_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM2_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED1 = 2;
static const uint32_t CS_SM2_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ADDR = 3;
static const uint32_t CS_SM2_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ADDR_LEN = 25;
static const uint32_t CS_SM2_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED2 = 28;
static const uint32_t CS_SM2_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED2_LEN = 3;
static const uint32_t CS_SM2_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_POISON = 31;
//<< [CS_SM2_SNP_MISC_PAUMMIO_BAR]
// pau/reg00013.H

//>> [CS_SM3_SNP_MISC_PAUMMIO_BAR]
static const uint64_t CS_SM3_SNP_MISC_PAUMMIO_BAR = 0x1001095cull;

static const uint32_t CS_SM3_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM3_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED1 = 2;
static const uint32_t CS_SM3_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ADDR = 3;
static const uint32_t CS_SM3_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ADDR_LEN = 25;
static const uint32_t CS_SM3_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED2 = 28;
static const uint32_t CS_SM3_SNP_MISC_PAUMMIO_BAR_PAUMMIO_RESERVED2_LEN = 3;
static const uint32_t CS_SM3_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_POISON = 31;
//<< [CS_SM3_SNP_MISC_PAUMMIO_BAR]
// pau/reg00013.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00013.H"
#endif
#endif
