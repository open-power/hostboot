/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_e.H $        */
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

#ifndef __p10_scom_pau_e_H_
#define __p10_scom_pau_e_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [CS_SM0_SNP_MISC_GENID_BAR]
static const uint64_t CS_SM0_SNP_MISC_GENID_BAR = 0x1001083dull;

static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1 = 2;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR = 3;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN = 30;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2 = 33;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON = 35;
//<< [CS_SM0_SNP_MISC_GENID_BAR]
// pau/reg00017.H

//>> [CS_SM2_SNP_MISC_GPU0_BAR]
static const uint64_t CS_SM2_SNP_MISC_GPU0_BAR = 0x100108f2ull;

static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE = 36;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT = 38;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_MODE = 40;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_MODE_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_GRANULE = 44;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_POISON = 45;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_M2MODE = 46;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM2_SNP_MISC_GPU0_BAR_RESERVED = 51;
//<< [CS_SM2_SNP_MISC_GPU0_BAR]
// pau/reg00017.H

//>> [CS_SM2_SNP_MISC_GPU1_BAR]
static const uint64_t CS_SM2_SNP_MISC_GPU1_BAR = 0x100108f3ull;

static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE = 36;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT = 38;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_MODE = 40;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_MODE_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_GRANULE = 44;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_POISON = 45;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_M2MODE = 46;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM2_SNP_MISC_GPU1_BAR_RESERVED = 51;
//<< [CS_SM2_SNP_MISC_GPU1_BAR]
// pau/reg00017.H

//>> [MISC_REGS_INT_REQ]
static const uint64_t MISC_REGS_INT_REQ = 0x10010b47ull;

static const uint32_t MISC_REGS_INT_REQ_00 = 0;
static const uint32_t MISC_REGS_INT_REQ_01 = 1;
static const uint32_t MISC_REGS_INT_REQ_02 = 2;
static const uint32_t MISC_REGS_INT_REQ_03 = 3;
static const uint32_t MISC_REGS_INT_REQ_12 = 12;
static const uint32_t MISC_REGS_INT_REQ_13 = 13;
static const uint32_t MISC_REGS_INT_REQ_18 = 18;
static const uint32_t MISC_REGS_INT_REQ_19 = 19;
static const uint32_t MISC_REGS_INT_REQ_20 = 20;
static const uint32_t MISC_REGS_INT_REQ_21 = 21;
static const uint32_t MISC_REGS_INT_REQ_23 = 23;
static const uint32_t MISC_REGS_INT_REQ_24 = 24;
static const uint32_t MISC_REGS_INT_REQ_35 = 35;
static const uint32_t MISC_REGS_INT_REQ_36 = 36;
static const uint32_t MISC_REGS_INT_REQ_37 = 37;
static const uint32_t MISC_REGS_INT_REQ_38 = 38;
static const uint32_t MISC_REGS_INT_REQ_39 = 39;
static const uint32_t MISC_REGS_INT_REQ_40 = 40;
//<< [MISC_REGS_INT_REQ]
// pau/reg00017.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00017.H"
#endif
#endif
