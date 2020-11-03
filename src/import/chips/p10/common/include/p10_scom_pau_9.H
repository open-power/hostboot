/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_9.H $        */
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

#ifndef __p10_scom_pau_9_H_
#define __p10_scom_pau_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [FIR_REG_1]
static const uint64_t FIR_REG_1_RW = 0x10010c40ull;
static const uint64_t FIR_REG_1_WO_AND = 0x10010c41ull;
static const uint64_t FIR_REG_1_WO_OR = 0x10010c42ull;

static const uint32_t FIR_REG_1_NDL_BRK0_STALL = 0;
static const uint32_t FIR_REG_1_NDL_BRK0_NOSTALL = 1;
static const uint32_t FIR_REG_1_NDL_BRK1_STALL = 2;
static const uint32_t FIR_REG_1_NDL_BRK1_NOSTALL = 3;
static const uint32_t FIR_REG_1_NDL_BRK2_STALL = 4;
static const uint32_t FIR_REG_1_NDL_BRK2_NOSTALL = 5;
static const uint32_t FIR_REG_1_NDL_BRK3_STALL = 6;
static const uint32_t FIR_REG_1_NDL_BRK3_NOSTALL = 7;
static const uint32_t FIR_REG_1_NDL_BRK4_STALL = 8;
static const uint32_t FIR_REG_1_NDL_BRK4_NOSTALL = 9;
static const uint32_t FIR_REG_1_NDL_BRK5_STALL = 10;
static const uint32_t FIR_REG_1_NDL_BRK5_NOSTALL = 11;
static const uint32_t FIR_REG_1_MISC_REG_RING_ERR = 12;
static const uint32_t FIR_REG_1_MISC_INT_RA_PERR = 13;
static const uint32_t FIR_REG_1_MISC_DA_ADDR_PERR = 14;
static const uint32_t FIR_REG_1_MISC_CTRL_PERR = 15;
static const uint32_t FIR_REG_1_FIR1_RSVD_16 = 16;
static const uint32_t FIR_REG_1_ATS_TVT_ENTRY_INVALID = 17;
static const uint32_t FIR_REG_1_ATS_TVT_ADDR_RANGE_ERR = 18;
static const uint32_t FIR_REG_1_ATS_TCE_PAGE_ACCESS_CA_ERR = 19;
static const uint32_t FIR_REG_1_ATS_TCE_CACHE_MULT_HIT_ERR = 20;
static const uint32_t FIR_REG_1_ATS_TCE_PAGE_ACCESS_TW_ERR = 21;
static const uint32_t FIR_REG_1_ATS_TCE_REQ_TO_ERR = 22;
static const uint32_t FIR_REG_1_ATS_TCD_PERR = 23;
static const uint32_t FIR_REG_1_ATS_TDR_PERR = 24;
static const uint32_t FIR_REG_1_ATS_AT_EA_UE = 25;
static const uint32_t FIR_REG_1_ATS_AT_EA_CE = 26;
static const uint32_t FIR_REG_1_ATS_AT_TDRMEM_UE = 27;
static const uint32_t FIR_REG_1_ATS_AT_TDRMEM_CE = 28;
static const uint32_t FIR_REG_1_ATS_AT_RSPOUT_UE = 29;
static const uint32_t FIR_REG_1_ATS_AT_RSPOUT_CE = 30;
static const uint32_t FIR_REG_1_ATS_TVT_PERR = 31;
static const uint32_t FIR_REG_1_ATS_IODA_ADDR_PERR = 32;
static const uint32_t FIR_REG_1_ATS_PAU_CTRL_PERR = 33;
static const uint32_t FIR_REG_1_ATS_PAU_TOR_PERR = 34;
static const uint32_t FIR_REG_1_ATS_INVAL_IODA_TBL_SEL = 35;
static const uint32_t FIR_REG_1_ATS_RSVD_19 = 36;
static const uint32_t FIR_REG_1_XSL_KILL_XLATE_EPOCH_TIMEOUT = 37;
static const uint32_t FIR_REG_1_XSL_RSVD_19 = 38;
static const uint32_t FIR_REG_1_XSL_RSVD_20 = 39;
static const uint32_t FIR_REG_1_XSL_RSVD_21 = 40;
static const uint32_t FIR_REG_1_XSL_RSVD_22 = 41;
static const uint32_t FIR_REG_1_XSL_RSVD_23 = 42;
static const uint32_t FIR_REG_1_XSL_RSVD_24 = 43;
static const uint32_t FIR_REG_1_XSL_RSVD_25 = 44;
static const uint32_t FIR_REG_1_XSL_RSVD_26 = 45;
static const uint32_t FIR_REG_1_XSL_RSVD_27 = 46;
static const uint32_t FIR_REG_1_NDL_BRK6_STALL = 47;
static const uint32_t FIR_REG_1_NDL_BRK6_NOSTALL = 48;
static const uint32_t FIR_REG_1_NDL_BRK7_STALL = 49;
static const uint32_t FIR_REG_1_NDL_BRK7_NOSTALL = 50;
static const uint32_t FIR_REG_1_NDL_BRK8_STALL = 51;
static const uint32_t FIR_REG_1_NDL_BRK8_NOSTALL = 52;
static const uint32_t FIR_REG_1_NDL_BRK9_STALL = 53;
static const uint32_t FIR_REG_1_NDL_BRK9_NOSTALL = 54;
static const uint32_t FIR_REG_1_NDL_BRK10_STALL = 55;
static const uint32_t FIR_REG_1_NDL_BRK10_NOSTALL = 56;
static const uint32_t FIR_REG_1_NDL_BRK11_STALL = 57;
static const uint32_t FIR_REG_1_NDL_BRK11_NOSTALL = 58;
static const uint32_t FIR_REG_1_AME_RSVD_2 = 59;
static const uint32_t FIR_REG_1_SCOMSAT00_ERR = 60;
static const uint32_t FIR_REG_1_SCOMSAT01_ERR = 61;
static const uint32_t FIR_REG_1_FIR1_RSVD_62 = 62;
static const uint32_t FIR_REG_1_FIR1_RSVD_63 = 63;
//<< [FIR_REG_1]
// pau/reg00011.H

//>> [XSL_MAIN_GPU0_BAR]
static const uint64_t XSL_MAIN_GPU0_BAR = 0x10010a9aull;

static const uint32_t XSL_MAIN_GPU0_BAR_ENABLE = 0;
static const uint32_t XSL_MAIN_GPU0_BAR_ADDR_MASK = 1;
static const uint32_t XSL_MAIN_GPU0_BAR_ADDR_MASK_LEN = 35;
static const uint32_t XSL_MAIN_GPU0_BAR_SL_MODE = 36;
static const uint32_t XSL_MAIN_GPU0_BAR_4T_LIMIT = 37;
static const uint32_t XSL_MAIN_GPU0_BAR_4T_SELECT = 38;
static const uint32_t XSL_MAIN_GPU0_BAR_4T_SELECT_LEN = 2;
static const uint32_t XSL_MAIN_GPU0_BAR_MODE = 40;
static const uint32_t XSL_MAIN_GPU0_BAR_MODE_LEN = 4;
static const uint32_t XSL_MAIN_GPU0_BAR_GRANULE = 44;
static const uint32_t XSL_MAIN_GPU0_BAR_POISON = 45;
static const uint32_t XSL_MAIN_GPU0_BAR_M2MODE = 46;
static const uint32_t XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE = 47;
static const uint32_t XSL_MAIN_GPU0_BAR_SECURE_A12 = 48;
static const uint32_t XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t XSL_MAIN_GPU0_BAR_EXTENDED_MODE = 50;
static const uint32_t XSL_MAIN_GPU0_BAR_RESERVED = 51;
//<< [XSL_MAIN_GPU0_BAR]
// pau/reg00011.H

//>> [XSL_MAIN_GPU1_BAR]
static const uint64_t XSL_MAIN_GPU1_BAR = 0x10010a9bull;

static const uint32_t XSL_MAIN_GPU1_BAR_ENABLE = 0;
static const uint32_t XSL_MAIN_GPU1_BAR_ADDR_MASK = 1;
static const uint32_t XSL_MAIN_GPU1_BAR_ADDR_MASK_LEN = 35;
static const uint32_t XSL_MAIN_GPU1_BAR_SL_MODE = 36;
static const uint32_t XSL_MAIN_GPU1_BAR_4T_LIMIT = 37;
static const uint32_t XSL_MAIN_GPU1_BAR_4T_SELECT = 38;
static const uint32_t XSL_MAIN_GPU1_BAR_4T_SELECT_LEN = 2;
static const uint32_t XSL_MAIN_GPU1_BAR_MODE = 40;
static const uint32_t XSL_MAIN_GPU1_BAR_MODE_LEN = 4;
static const uint32_t XSL_MAIN_GPU1_BAR_GRANULE = 44;
static const uint32_t XSL_MAIN_GPU1_BAR_POISON = 45;
static const uint32_t XSL_MAIN_GPU1_BAR_M2MODE = 46;
static const uint32_t XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE = 47;
static const uint32_t XSL_MAIN_GPU1_BAR_SECURE_A12 = 48;
static const uint32_t XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t XSL_MAIN_GPU1_BAR_EXTENDED_MODE = 50;
static const uint32_t XSL_MAIN_GPU1_BAR_RESERVED = 51;
//<< [XSL_MAIN_GPU1_BAR]
// pau/reg00011.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00011.H"
#endif
#endif
