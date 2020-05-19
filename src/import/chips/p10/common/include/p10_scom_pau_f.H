/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_f.H $        */
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

#ifndef __p10_scom_pau_f_H_
#define __p10_scom_pau_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [CS_SM0_SNP_MISC_GPU0_BAR]
static const uint64_t CS_SM0_SNP_MISC_GPU0_BAR = 0x10010832ull;

static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE = 36;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT = 38;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_MODE = 40;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_MODE_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_GRANULE = 44;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_POISON = 45;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_M2MODE = 46;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM0_SNP_MISC_GPU0_BAR_RESERVED = 51;
//<< [CS_SM0_SNP_MISC_GPU0_BAR]
// pau/reg00018.H

//>> [CS_SM0_SNP_MISC_GPU1_BAR]
static const uint64_t CS_SM0_SNP_MISC_GPU1_BAR = 0x10010833ull;

static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE = 36;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT = 38;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_MODE = 40;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_MODE_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_GRANULE = 44;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_POISON = 45;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_M2MODE = 46;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM0_SNP_MISC_GPU1_BAR_RESERVED = 51;
//<< [CS_SM0_SNP_MISC_GPU1_BAR]
// pau/reg00018.H

//>> [FIR_REG_0]
static const uint64_t FIR_REG_0_RW = 0x10010c00ull;
static const uint64_t FIR_REG_0_WO_AND = 0x10010c01ull;
static const uint64_t FIR_REG_0_WO_OR = 0x10010c02ull;

static const uint32_t FIR_REG_0_NTL_ARRAY_CE = 0;
static const uint32_t FIR_REG_0_NTL_ARRAY_HDR_UE = 1;
static const uint32_t FIR_REG_0_NTL_ARRAY_DATA_UE = 2;
static const uint32_t FIR_REG_0_NTL_NVL_FLIT_PERR = 3;
static const uint32_t FIR_REG_0_NTL_NVL_DATA_PERR = 4;
static const uint32_t FIR_REG_0_NTL_NVL_PKT_MALFOR = 5;
static const uint32_t FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED = 6;
static const uint32_t FIR_REG_0_NTL_NVL_CONFIG_ERR = 7;
static const uint32_t FIR_REG_0_NTL_NVL_CRC_ERR = 8;
static const uint32_t FIR_REG_0_NTL_PRI_ERR = 9;
static const uint32_t FIR_REG_0_NTL_LOGIC_ERR = 10;
static const uint32_t FIR_REG_0_NTL_LMD_POISON = 11;
static const uint32_t FIR_REG_0_NTL_ARRAY_DATA_SUE = 12;
static const uint32_t FIR_REG_0_CTL_ARRAY_CE = 13;
static const uint32_t FIR_REG_0_CTL_PBUS_RECOV_ERR = 14;
static const uint32_t FIR_REG_0_CTL_REG_RING_ERR = 15;
static const uint32_t FIR_REG_0_CTL_MMIO_ST_DATA_UE = 16;
static const uint32_t FIR_REG_0_CTL_PEF = 17;
static const uint32_t FIR_REG_0_CTL_NVL_CFG_ERR = 18;
static const uint32_t FIR_REG_0_CTL_NVL_FATAL_ERR = 19;
static const uint32_t FIR_REG_0_RESERVED_1 = 20;
static const uint32_t FIR_REG_0_CTL_ARRAY_UE = 21;
static const uint32_t FIR_REG_0_CTL_PBUS_PERR = 22;
static const uint32_t FIR_REG_0_CTL_PBUS_FATAL_ERR = 23;
static const uint32_t FIR_REG_0_CTL_PBUS_CONFIG_ERR = 24;
static const uint32_t FIR_REG_0_CTL_FWD_PROGRESS_ERR = 25;
static const uint32_t FIR_REG_0_CTL_LOGIC_ERR = 26;
static const uint32_t FIR_REG_0_CTL_RSVD_14 = 27;
static const uint32_t FIR_REG_0_CTL_RSVD_15 = 28;
static const uint32_t FIR_REG_0_DAT_DATA_BE_UE = 29;
static const uint32_t FIR_REG_0_DAT_DATA_BE_CE = 30;
static const uint32_t FIR_REG_0_DAT_DATA_BE_PERR = 31;
static const uint32_t FIR_REG_0_DAT_CREG_PERR = 32;
static const uint32_t FIR_REG_0_DAT_RTAG_PERR = 33;
static const uint32_t FIR_REG_0_DAT_STATE_PERR = 34;
static const uint32_t FIR_REG_0_DAT_LOGIC_ERR = 35;
static const uint32_t FIR_REG_0_DAT_DATA_BE_SUE = 36;
static const uint32_t FIR_REG_0_DAT_PBRX_SUE = 37;
static const uint32_t FIR_REG_0_DAT_RSVD_9 = 38;
static const uint32_t FIR_REG_0_DAT_RSVD_10 = 39;
static const uint32_t FIR_REG_0_XTS_INT = 40;
static const uint32_t FIR_REG_0_XTS_SRAM_CE = 41;
static const uint32_t FIR_REG_0_XTS_SRAM_UE = 42;
static const uint32_t FIR_REG_0_XTS_PROTOCOL_CE = 43;
static const uint32_t FIR_REG_0_XTS_PROTOCOL_UE = 44;
static const uint32_t FIR_REG_0_XTS_PBUS_PROTOCOL = 45;
static const uint32_t FIR_REG_0_XTS_RSVD_6 = 46;
static const uint32_t FIR_REG_0_XTS_EARLY_HANG_WARN = 47;
static const uint32_t FIR_REG_0_XTS_RSVD_8 = 48;
static const uint32_t FIR_REG_0_XTS_RSVD_9 = 49;
static const uint32_t FIR_REG_0_XTS_RSVD_10 = 50;
static const uint32_t FIR_REG_0_XTS_RSVD_11 = 51;
static const uint32_t FIR_REG_0_XTS_RSVD_12 = 52;
static const uint32_t FIR_REG_0_XTS_RSVD_13 = 53;
static const uint32_t FIR_REG_0_XTS_RSVD_14 = 54;
static const uint32_t FIR_REG_0_XTS_RSVD_15 = 55;
static const uint32_t FIR_REG_0_XTS_RSVD_16 = 56;
static const uint32_t FIR_REG_0_XTS_RSVD_17 = 57;
static const uint32_t FIR_REG_0_XTS_RSVD_18 = 58;
static const uint32_t FIR_REG_0_AME_RSVD_INT = 59;
static const uint32_t FIR_REG_0_AME_RSVD_0 = 60;
static const uint32_t FIR_REG_0_AME_RSVD_1 = 61;
static const uint32_t FIR_REG_0_FIR0_RSVD_62 = 62;
static const uint32_t FIR_REG_0_FIR0_RSVD_63 = 63;
//<< [FIR_REG_0]
// pau/reg00018.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00018.H"
#endif
#endif
