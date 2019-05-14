/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_c.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#include "proc_scomt.H"

#ifndef __p10_scom_pau_c_H_
#define __p10_scom_pau_c_H_


namespace scomt
{
namespace pau
{


static const uint64_t AME_AME0_MISC_ECC_CONFIG = 0x10010bc2ull;

static const uint32_t AME_AME0_MISC_ECC_CONFIG_ERAT_RA_COREN = 0;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_ERAT_RA_ERRINJ = 1;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_ERAT_RA_ERRINJ_LEN = 8;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_ERAT_PE_COREN = 9;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_ERAT_PE_ERRINJ = 10;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_ERAT_PE_ERRINJ_LEN = 2;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_MRQ_XCT_COREN = 12;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_MRQ_XCT_ERRINJ = 13;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_MRQ_XCT_ERRINJ_LEN = 4;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL0_WB_COREN = 17;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL0_WB_ERRINJ = 18;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL0_WB_ERRINJ_LEN = 16;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL0_CBA_COREN = 34;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL0_CBA_ERRINJ = 35;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL0_CBA_ERRINJ_LEN = 2;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL0_PCT_COREN = 37;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL0_PCT_ERRINJ = 38;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL0_PCT_ERRINJ_LEN = 2;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL1_WB_COREN = 40;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL1_WB_ERRINJ = 41;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL1_WB_ERRINJ_LEN = 16;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL1_CBA_COREN = 57;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL1_CBA_ERRINJ = 58;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL1_CBA_ERRINJ_LEN = 2;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL1_PCT_COREN = 60;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL1_PCT_ERRINJ = 61;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_CL1_PCT_ERRINJ_LEN = 2;
static const uint32_t AME_AME0_MISC_ECC_CONFIG_ECC_SPARE = 63;
// pau/reg00016.H

static const uint64_t AME_AME1_MISC_PMU_CONFIG1 = 0x10010bd6ull;

static const uint32_t AME_AME1_MISC_PMU_CONFIG1_0_SEL = 28;
static const uint32_t AME_AME1_MISC_PMU_CONFIG1_0_SEL_LEN = 9;
static const uint32_t AME_AME1_MISC_PMU_CONFIG1_1_SEL = 37;
static const uint32_t AME_AME1_MISC_PMU_CONFIG1_1_SEL_LEN = 9;
static const uint32_t AME_AME1_MISC_PMU_CONFIG1_2_SEL = 46;
static const uint32_t AME_AME1_MISC_PMU_CONFIG1_2_SEL_LEN = 9;
static const uint32_t AME_AME1_MISC_PMU_CONFIG1_3_SEL = 55;
static const uint32_t AME_AME1_MISC_PMU_CONFIG1_3_SEL_LEN = 9;
// pau/reg00016.H

static const uint64_t AME_AME2_MISC_AMM_CONFIG1 = 0x10010be1ull;

static const uint32_t AME_AME2_MISC_AMM_CONFIG1_1_RESERVED = 32;
static const uint32_t AME_AME2_MISC_AMM_CONFIG1_1_RESERVED_LEN = 19;
static const uint32_t AME_AME2_MISC_AMM_CONFIG1__MRQ_WD_CRD = 51;
static const uint32_t AME_AME2_MISC_AMM_CONFIG1__MRQ_WD_CRD_LEN = 3;
static const uint32_t AME_AME2_MISC_AMM_CONFIG1__MRQ_SD_CRD = 54;
static const uint32_t AME_AME2_MISC_AMM_CONFIG1__MRQ_SD_CRD_LEN = 3;
static const uint32_t AME_AME2_MISC_AMM_CONFIG1__MRQ_ACT_TIMER = 57;
static const uint32_t AME_AME2_MISC_AMM_CONFIG1__MRQ_VC2_CRD_SMR = 58;
static const uint32_t AME_AME2_MISC_AMM_CONFIG1__MRQ_SMR_MAX = 59;
static const uint32_t AME_AME2_MISC_AMM_CONFIG1__MRQ_SMR_MAX_LEN = 5;
// pau/reg00016.H

static const uint64_t AME_AME2_MISC_CERR_RPT_HOLD = 0x10010be8ull;

static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_FIRMWARE = 47;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_CREGA_PERR = 48;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_CREGM_PERR = 49;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_LDW_UE = 50;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_FU_UE = 51;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_WB_UE = 52;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_PCT_UE = 53;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_CBA_UE = 54;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_ERAT_UE = 55;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_PE_UE = 56;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_XCT_UE = 57;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_WB_CE = 58;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_PCT_CE = 59;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_CBA_CE = 60;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_ERAT_CE = 61;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_PE_CE = 62;
static const uint32_t AME_AME2_MISC_CERR_RPT_HOLD_XCT_CE = 63;
// pau/reg00016.H

static const uint64_t AME_AME2_MISC_CERR_RPT_INFO = 0x10010beaull;

static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_FU_ETYPE = 1;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_FU_ETYPE_LEN = 13;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_FW_ECODE = 14;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_FW_ECODE_LEN = 4;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_XCTS = 18;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_XCTS_LEN = 2;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_ERATS = 20;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_ERATS_LEN = 4;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_WBS = 24;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_WBS_LEN = 8;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_FIRST_AMES = 32;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_FIRST_AMES_LEN = 8;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_AMES = 40;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_AMES_LEN = 8;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_FIRST_UE = 48;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_FIRST_UE_LEN = 10;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_FIRST_CE = 58;
static const uint32_t AME_AME2_MISC_CERR_RPT_INFO_FIRST_CE_LEN = 6;
// pau/reg00016.H

static const uint64_t AME_ATL_MISC_DEBUG_CONFIG0 = 0x10010bf4ull;

static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_0_B0_SEL = 0;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_0_B0_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_1_B0_SEL = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_1_B0_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B0_G0_SEL = 6;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B0_G0_SEL_LEN = 4;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B0_G1_SEL = 10;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B0_G1_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B0_G2_SEL = 13;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B0_G2_SEL_LEN = 2;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_0_B1_SEL = 15;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_0_B1_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_1_B1_SEL = 18;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_1_B1_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B1_G0_SEL = 21;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B1_G0_SEL_LEN = 4;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B1_G1_SEL = 25;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B1_G1_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B1_G2_SEL = 28;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B1_G2_SEL_LEN = 2;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_0_B2_SEL = 30;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_0_B2_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_1_B2_SEL = 33;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_1_B2_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B2_G0_SEL = 36;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B2_G0_SEL_LEN = 4;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B2_G1_SEL = 40;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B2_G1_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B2_G2_SEL = 43;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B2_G2_SEL_LEN = 2;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_0_B3_SEL = 45;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_0_B3_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_1_B3_SEL = 48;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_1_B3_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B3_G0_SEL = 51;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B3_G0_SEL_LEN = 4;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B3_G1_SEL = 55;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B3_G1_SEL_LEN = 3;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B3_G2_SEL = 58;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__B3_G2_SEL_LEN = 2;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__RESERVED0 = 60;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0__RESERVED0_LEN = 2;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_0_ENABLE = 62;
static const uint32_t AME_ATL_MISC_DEBUG_CONFIG0_1_ENABLE = 63;
// pau/reg00016.H

static const uint64_t ATS_REG_CKSW = 0x10010ab4ull;

static const uint32_t ATS_REG_CKSW_ATS_CKSW_SPARE = 0;
static const uint32_t ATS_REG_CKSW_ATS_CKSW_SPARE_LEN = 64;
// pau/reg00016.H

static const uint64_t ATS_REG_CTRL = 0x10010ad0ull;

static const uint32_t ATS_REG_CTRL_ATS_ARB_STOP = 0;
static const uint32_t ATS_REG_CTRL_ATS_ARB_STALL = 1;
static const uint32_t ATS_REG_CTRL_ATS_TCE_CACHE_DISABLE = 2;
static const uint32_t ATS_REG_CTRL_ATS_TCE_CACHE_1W = 3;
static const uint32_t ATS_REG_CTRL_ATS_CONFIG_BRAZOS = 4;
static const uint32_t ATS_REG_CTRL_CONFIG_SYNC_WAIT = 5;
static const uint32_t ATS_REG_CTRL_CONFIG_SYNC_WAIT_LEN = 5;
static const uint32_t ATS_REG_CTRL_ATS_CTRL_SPARE = 10;
static const uint32_t ATS_REG_CTRL_ATS_CTRL_SPARE_LEN = 54;
// pau/reg00016.H

static const uint64_t ATS_REG_PAU_AT_FESMR = 0x10010adaull;

static const uint32_t ATS_REG_PAU_AT_FESMR_IDIAL_ATS_FER_MSK = 0;
static const uint32_t ATS_REG_PAU_AT_FESMR_IDIAL_ATS_FER_MSK_LEN = 20;
// pau/reg00016.H

static const uint64_t CS_CTL_MISC_BDF2PE_1_CONFIG = 0x100109b1ull;

static const uint32_t CS_CTL_MISC_BDF2PE_1_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_1_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_1_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_1_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_1_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_1_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_1_CONFIG_BDF_LEN = 16;
// pau/reg00016.H

static const uint64_t CS_CTL_MISC_DEBUG0_CONFIG = 0x10010988ull;

static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_CTL_MISC_DEBUG0_CONFIG_ACT = 63;
// pau/reg00016.H

static const uint64_t CS_SM0_MCP_MISC_CERR_FIRST2 = 0x10010811ull;

static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_0 = 0;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_1 = 1;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_2 = 2;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_3 = 3;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_4 = 4;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_5 = 5;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_6 = 6;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_7 = 7;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_8 = 8;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_9 = 9;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_10 = 10;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_11 = 11;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_12 = 12;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_13 = 13;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_14 = 14;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_15 = 15;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_16 = 16;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_17 = 17;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_18 = 18;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_19 = 19;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_20 = 20;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_21 = 21;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_22 = 22;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_23 = 23;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_24 = 24;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_25 = 25;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_26 = 26;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_27 = 27;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_28 = 28;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_29 = 29;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_30 = 30;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_31 = 31;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_32 = 32;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_33 = 33;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_34 = 34;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_35 = 35;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_36 = 36;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_37 = 37;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_38 = 38;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_39 = 39;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_40 = 40;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_41 = 41;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_42 = 42;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_43 = 43;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_44 = 44;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_45 = 45;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_46 = 46;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_47 = 47;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_48 = 48;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_49 = 49;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_50 = 50;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_51 = 51;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_52 = 52;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_53 = 53;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_54 = 54;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_55 = 55;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_56 = 56;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_57 = 57;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_58 = 58;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_59 = 59;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_60 = 60;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_61 = 61;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_62 = 62;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST2_63 = 63;
// pau/reg00016.H

static const uint64_t CS_SM0_MCP_MISC_CERR_MESSAGE6 = 0x1001080cull;

static const uint32_t CS_SM0_MCP_MISC_CERR_MESSAGE6_CERR_MESSAGE_BITS6 = 0;
static const uint32_t CS_SM0_MCP_MISC_CERR_MESSAGE6_CERR_MESSAGE_BITS6_LEN = 64;
// pau/reg00016.H

static const uint64_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1 = 0x10010847ull;

static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_CL_DMA_W = 0;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_CL_DMA_W_HP = 1;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_CL_DMA_INJ = 2;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_PR_DMA_INJ = 3;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_DMA_PR_W = 4;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_CL_RD_NC_F0 = 5;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_CAS_IMAX_U = 6;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_CAS_IMAX_S = 7;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_CAS_IMIN_U = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_CAS_IMIN_S = 9;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_ADD = 10;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_AND = 11;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_OR = 12;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_XOR = 13;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_IMAX_U = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_IMAX_S = 15;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_IMIN_U = 16;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_IMIN_S = 17;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_ADD = 18;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_AND = 19;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_OR = 20;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_XOR = 21;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_E = 22;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_U = 23;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_CAS_T = 24;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_NE = 25;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_INC_B = 26;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_INC_E = 27;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_DEC_B = 28;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_RESERVED1 = 29;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_RESERVED1_LEN = 3;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE0_WRENA = 32;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE0_RDENA = 33;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE0_AWENA = 34;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE0_ARENA = 35;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE1_WRENA = 36;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE1_RDENA = 37;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE1_AWENA = 38;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE1_ARENA = 39;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE2_WRENA = 40;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE2_RDENA = 41;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE2_AWENA = 42;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE2_ARENA = 43;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE3_WRENA = 44;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE3_RDENA = 45;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE3_AWENA = 46;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE3_ARENA = 47;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE4_WRENA = 48;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE4_RDENA = 49;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE4_AWENA = 50;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE4_ARENA = 51;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE5_WRENA = 52;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE5_RDENA = 53;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE5_AWENA = 54;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE5_ARENA = 55;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE6_WRENA = 56;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE6_RDENA = 57;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE6_AWENA = 58;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE6_ARENA = 59;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE7_WRENA = 60;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE7_RDENA = 61;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE7_AWENA = 62;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE7_ARENA = 63;
// pau/reg00016.H

static const uint64_t CS_SM0_SNP_MISC_NDT0_BAR = 0x10010837ull;

static const uint32_t CS_SM0_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM0_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 = 2;
static const uint32_t CS_SM0_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR = 3;
static const uint32_t CS_SM0_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM0_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON = 36;
static const uint32_t CS_SM0_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 = 37;
static const uint32_t CS_SM0_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE = 39;
static const uint32_t CS_SM0_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN = 5;
// pau/reg00016.H

static const uint64_t CS_SM0_SNP_MISC_NDT1_BAR = 0x10010838ull;

static const uint32_t CS_SM0_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM0_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 = 2;
static const uint32_t CS_SM0_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR = 3;
static const uint32_t CS_SM0_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM0_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON = 36;
static const uint32_t CS_SM0_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 = 37;
static const uint32_t CS_SM0_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE = 39;
static const uint32_t CS_SM0_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN = 5;
// pau/reg00016.H

static const uint64_t CS_SM0_SNP_MISC_NDT2_BAR = 0x10010839ull;

static const uint32_t CS_SM0_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM0_SNP_MISC_NDT2_BAR_NDT2_RESERVED1 = 2;
static const uint32_t CS_SM0_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_ADDR = 3;
static const uint32_t CS_SM0_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM0_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_POISON = 36;
static const uint32_t CS_SM0_SNP_MISC_NDT2_BAR_NDT2_RESERVED2 = 37;
static const uint32_t CS_SM0_SNP_MISC_NDT2_BAR_NDT2_RESERVED2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_SIZE = 39;
static const uint32_t CS_SM0_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_SIZE_LEN = 5;
// pau/reg00016.H

static const uint64_t CS_SM0_SNP_MISC_NDT3_BAR = 0x1001083aull;

static const uint32_t CS_SM0_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM0_SNP_MISC_NDT3_BAR_NDT3_RESERVED1 = 2;
static const uint32_t CS_SM0_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_ADDR = 3;
static const uint32_t CS_SM0_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM0_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_POISON = 36;
static const uint32_t CS_SM0_SNP_MISC_NDT3_BAR_NDT3_RESERVED2 = 37;
static const uint32_t CS_SM0_SNP_MISC_NDT3_BAR_NDT3_RESERVED2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_SIZE = 39;
static const uint32_t CS_SM0_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_SIZE_LEN = 5;
// pau/reg00016.H

static const uint64_t CS_SM0_SNP_MISC_NDT4_BAR = 0x1001083bull;

static const uint32_t CS_SM0_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM0_SNP_MISC_NDT4_BAR_NDT4_RESERVED1 = 2;
static const uint32_t CS_SM0_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_ADDR = 3;
static const uint32_t CS_SM0_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM0_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_POISON = 36;
static const uint32_t CS_SM0_SNP_MISC_NDT4_BAR_NDT4_RESERVED2 = 37;
static const uint32_t CS_SM0_SNP_MISC_NDT4_BAR_NDT4_RESERVED2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_SIZE = 39;
static const uint32_t CS_SM0_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_SIZE_LEN = 5;
// pau/reg00016.H

static const uint64_t CS_SM1_MCP_MISC_CERR_FIRST2 = 0x10010871ull;

static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_0 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_1 = 1;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_2 = 2;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_3 = 3;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_4 = 4;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_5 = 5;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_6 = 6;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_7 = 7;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_8 = 8;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_9 = 9;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_10 = 10;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_11 = 11;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_12 = 12;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_13 = 13;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_14 = 14;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_15 = 15;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_16 = 16;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_17 = 17;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_18 = 18;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_19 = 19;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_20 = 20;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_21 = 21;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_22 = 22;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_23 = 23;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_24 = 24;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_25 = 25;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_26 = 26;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_27 = 27;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_28 = 28;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_29 = 29;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_30 = 30;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_31 = 31;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_32 = 32;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_33 = 33;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_34 = 34;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_35 = 35;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_36 = 36;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_37 = 37;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_38 = 38;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_39 = 39;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_40 = 40;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_41 = 41;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_42 = 42;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_43 = 43;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_44 = 44;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_45 = 45;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_46 = 46;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_47 = 47;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_48 = 48;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_49 = 49;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_50 = 50;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_51 = 51;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_52 = 52;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_53 = 53;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_54 = 54;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_55 = 55;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_56 = 56;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_57 = 57;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_58 = 58;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_59 = 59;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_60 = 60;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_61 = 61;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_62 = 62;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST2_63 = 63;
// pau/reg00016.H

static const uint64_t CS_SM1_MCP_MISC_CERR_MASK1 = 0x10010873ull;

static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_NLGX_0 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_NLGX_1 = 1;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_NLGX_2 = 2;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_NLGX_3 = 3;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_FWD_0 = 4;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_FWD_1 = 5;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_FWD_2 = 6;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_FWD_3 = 7;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_AUE_0 = 8;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_AUE_1 = 9;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_AUE_2 = 10;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_AUE_3 = 11;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_AUE_4 = 12;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_AUE_5 = 13;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_AUE_6 = 14;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_AUE_7 = 15;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_0 = 16;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_1 = 17;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_2 = 18;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_3 = 19;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_4 = 20;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_5 = 21;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_6 = 22;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_7 = 23;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_8 = 24;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_9 = 25;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_10 = 26;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK1_PBF_11 = 27;
// pau/reg00016.H

static const uint64_t CS_SM1_MCP_MISC_DEBUG4_CONFIG = 0x1001087dull;

static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE9 = 0;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE9_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE10 = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE10_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE11 = 14;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE11_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE12 = 21;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE12_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE13 = 28;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE13_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE14 = 35;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE14_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE15 = 42;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_BYTE15_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_RESERVED1 = 49;
static const uint32_t CS_SM1_MCP_MISC_DEBUG4_CONFIG_RESERVED1_LEN = 3;
// pau/reg00016.H

static const uint64_t CS_SM1_MCP_MISC_XTIMER_CONFIG = 0x10010863ull;

static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_POCKET_LONG_RATE1 = 0;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_POCKET_LONG_RATE1_LEN = 2;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_POCKET_LONG_RATE2 = 2;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_POCKET_LONG_RATE2_LEN = 6;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_POCKET_SHORT_RATE2 = 8;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_POCKET_SHORT_RATE2_LEN = 6;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_FWD_PROG_RATE2 = 14;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_FWD_PROG_RATE2_LEN = 6;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_XTIMER_RESERVED1 = 20;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_XTIMER_RESERVED1_LEN = 6;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_INH0_TICK = 26;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_INH0_TICK_LEN = 6;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_INH1_TICK = 32;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_INH1_TICK_LEN = 6;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_NV_RESP_RATE1 = 38;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_NV_RESP_RATE1_LEN = 2;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_NV_RESP_RATE2 = 40;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_NV_RESP_RATE2_LEN = 6;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_POCKET_SHORT_RATE1 = 46;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_POCKET_SHORT_RATE1_LEN = 2;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_SCAN_WAIT_RATE = 48;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_SCAN_WAIT_RATE_LEN = 6;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_EPOCH_RATE = 54;
static const uint32_t CS_SM1_MCP_MISC_XTIMER_CONFIG_EPOCH_RATE_LEN = 6;
// pau/reg00016.H

static const uint64_t CS_SM1_SNP_MISC_CERR_HOLD0 = 0x100108b5ull;

static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NCF_0 = 0;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NCF_1 = 1;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NCF_2 = 2;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NCF_3 = 3;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NCF_4 = 4;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NCF_5 = 5;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NCF_6 = 6;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NCF_7 = 7;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBR_0 = 8;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBR_1 = 9;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBR_2 = 10;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBR_3 = 11;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBR_4 = 12;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBR_5 = 13;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBR_6 = 14;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBR_7 = 15;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBP_0 = 16;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBP_1 = 17;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBP_2 = 18;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBP_3 = 19;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBP_4 = 20;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBP_5 = 21;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBP_6 = 22;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBP_7 = 23;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_0 = 24;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_1 = 25;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_2 = 26;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_3 = 27;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_4 = 28;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_5 = 29;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_6 = 30;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_7 = 31;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_8 = 32;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_9 = 33;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_10 = 34;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_PBC_11 = 35;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_0 = 36;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_1 = 37;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_2 = 38;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_3 = 39;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_4 = 40;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_5 = 41;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_6 = 42;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_7 = 43;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_8 = 44;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_9 = 45;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_10 = 46;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_11 = 47;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_12 = 48;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_13 = 49;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_14 = 50;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_15 = 51;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_16 = 52;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_17 = 53;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_18 = 54;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_19 = 55;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_20 = 56;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_21 = 57;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_22 = 58;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_NLG_23 = 59;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_SMV_0 = 60;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_SMV_1 = 61;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_SMV_2 = 62;
static const uint32_t CS_SM1_SNP_MISC_CERR_HOLD0_SMV_3 = 63;
// pau/reg00016.H

static const uint64_t CS_SM1_SNP_MISC_CERR_MESSAGE0 = 0x100108b0ull;

static const uint32_t CS_SM1_SNP_MISC_CERR_MESSAGE0_CERR_MESSAGE_BITS0 = 0;
static const uint32_t CS_SM1_SNP_MISC_CERR_MESSAGE0_CERR_MESSAGE_BITS0_LEN = 64;
// pau/reg00016.H

static const uint64_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2 = 0x100108a0ull;

static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_TAG = 0;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_TAG_LEN = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_TAGMASK = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_TAGMASK_LEN = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_MASK_PAU = 28;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_MASK_PCIE = 29;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_MASK_L2L3 = 30;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_RESERVED1 = 31;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_RDSTART = 32;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_RDSTART_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_RDEND = 40;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_RDEND_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_WRSTART = 48;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_WRSTART_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_WREND = 56;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC2_WREND_LEN = 8;
// pau/reg00016.H

static const uint64_t CS_SM2_MCP_MISC_CERR_FIRST2 = 0x100108d1ull;

static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_0 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_1 = 1;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_2 = 2;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_3 = 3;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_4 = 4;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_5 = 5;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_6 = 6;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_7 = 7;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_8 = 8;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_9 = 9;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_10 = 10;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_11 = 11;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_12 = 12;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_13 = 13;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_14 = 14;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_15 = 15;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_16 = 16;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_17 = 17;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_18 = 18;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_19 = 19;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_20 = 20;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_21 = 21;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_22 = 22;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_23 = 23;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_24 = 24;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_25 = 25;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_26 = 26;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_27 = 27;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_28 = 28;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_29 = 29;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_30 = 30;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_31 = 31;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_32 = 32;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_33 = 33;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_34 = 34;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_35 = 35;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_36 = 36;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_37 = 37;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_38 = 38;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_39 = 39;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_40 = 40;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_41 = 41;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_42 = 42;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_43 = 43;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_44 = 44;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_45 = 45;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_46 = 46;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_47 = 47;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_48 = 48;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_49 = 49;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_50 = 50;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_51 = 51;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_52 = 52;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_53 = 53;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_54 = 54;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_55 = 55;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_56 = 56;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_57 = 57;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_58 = 58;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_59 = 59;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_60 = 60;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_61 = 61;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_62 = 62;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST2_63 = 63;
// pau/reg00016.H

static const uint64_t CS_SM2_MCP_MISC_CERR_MESSAGE3 = 0x100108c9ull;

static const uint32_t CS_SM2_MCP_MISC_CERR_MESSAGE3_CERR_MESSAGE_BITS3 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_MESSAGE3_CERR_MESSAGE_BITS3_LEN = 64;
// pau/reg00016.H

static const uint64_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1 = 0x10010907ull;

static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_CL_DMA_W = 0;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_CL_DMA_W_HP = 1;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_CL_DMA_INJ = 2;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_PR_DMA_INJ = 3;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_DMA_PR_W = 4;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_CL_RD_NC_F0 = 5;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_CAS_IMAX_U = 6;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_CAS_IMAX_S = 7;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_CAS_IMIN_U = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_CAS_IMIN_S = 9;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_ADD = 10;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_AND = 11;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_OR = 12;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_XOR = 13;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_IMAX_U = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_IMAX_S = 15;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_IMIN_U = 16;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_IMIN_S = 17;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_ADD = 18;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_AND = 19;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_OR = 20;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_XOR = 21;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_E = 22;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_U = 23;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMW_CAS_T = 24;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_CAS_NE = 25;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_INC_B = 26;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_INC_E = 27;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_CMD_ARMWF_DEC_B = 28;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_RESERVED1 = 29;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_RESERVED1_LEN = 3;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE0_WRENA = 32;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE0_RDENA = 33;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE0_AWENA = 34;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE0_ARENA = 35;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE1_WRENA = 36;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE1_RDENA = 37;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE1_AWENA = 38;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE1_ARENA = 39;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE2_WRENA = 40;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE2_RDENA = 41;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE2_AWENA = 42;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE2_ARENA = 43;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE3_WRENA = 44;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE3_RDENA = 45;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE3_AWENA = 46;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE3_ARENA = 47;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE4_WRENA = 48;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE4_RDENA = 49;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE4_AWENA = 50;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE4_ARENA = 51;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE5_WRENA = 52;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE5_RDENA = 53;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE5_AWENA = 54;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE5_ARENA = 55;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE6_WRENA = 56;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE6_RDENA = 57;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE6_AWENA = 58;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE6_ARENA = 59;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE7_WRENA = 60;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE7_RDENA = 61;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE7_AWENA = 62;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK1_SOURCE7_ARENA = 63;
// pau/reg00016.H

static const uint64_t CS_SM2_SNP_MISC_DEBUG0_CONFIG = 0x10010919ull;

static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_DEBUG0_CONFIG_ACT = 63;
// pau/reg00016.H

static const uint64_t CS_SM3_MCP_MISC_CERR_FIRST2 = 0x10010931ull;

static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_0 = 0;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_1 = 1;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_2 = 2;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_3 = 3;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_4 = 4;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_5 = 5;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_6 = 6;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_7 = 7;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_8 = 8;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_9 = 9;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_10 = 10;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_11 = 11;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_12 = 12;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_13 = 13;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_14 = 14;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_15 = 15;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_16 = 16;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_17 = 17;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_18 = 18;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_19 = 19;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_20 = 20;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_21 = 21;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_22 = 22;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_23 = 23;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_24 = 24;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_25 = 25;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_26 = 26;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_27 = 27;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_28 = 28;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_29 = 29;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_30 = 30;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_31 = 31;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_32 = 32;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_33 = 33;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_34 = 34;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_35 = 35;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_36 = 36;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_37 = 37;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_38 = 38;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_39 = 39;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_40 = 40;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_41 = 41;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_42 = 42;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_43 = 43;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_44 = 44;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_45 = 45;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_46 = 46;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_47 = 47;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_48 = 48;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_49 = 49;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_50 = 50;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_51 = 51;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_52 = 52;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_53 = 53;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_54 = 54;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_55 = 55;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_56 = 56;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_57 = 57;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_58 = 58;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_59 = 59;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_60 = 60;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_61 = 61;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_62 = 62;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST2_63 = 63;
// pau/reg00016.H

static const uint64_t CS_SM3_MCP_MISC_CONFIG0 = 0x10010920ull;

static const uint32_t CS_SM3_MCP_MISC_CONFIG0__MA_DSA_OPT_CLAIM_UR = 0;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__MA_DSA_OPT_FLUSH_UR = 1;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__MA_DSA_OPT_RP_MODE = 2;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__ADR_BAR_MODE = 3;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__DISABLE_NN_RN = 4;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__DISABLE_VG_NOT_SYS = 5;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__DISABLE_G = 6;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__DISABLE_LN = 7;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__SKIP_G = 8;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__MA_MCRESP_OPT_WRP = 9;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__USE_CL_DMA_W = 10;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__USE_DMA_PR_W = 11;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__INC_PRI_MASK = 12;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__INC_PRI_MASK_LEN = 3;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__MACH_CORRENAB = 15;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__MACH_INJECT_ENABLE1 = 16;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__MACH_INJECT_ENABLE2 = 17;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__RXO_CORRENAB = 18;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__RXO_INJECT_ENABLE1 = 19;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__RXO_INJECT_ENABLE2 = 20;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__RSI_CORRENAB = 21;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__RSI_INJECT_ENABLE1 = 22;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__RSI_INJECT_ENABLE2 = 23;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__MA_DSA_OPT_DMA_UPG = 24;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__EVAPORATE_BY_LCO = 25;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__ENABLE_PBUS = 26;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__ENABLE_SNARF_CPM = 27;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__DISABLE_INJECT = 28;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__DCACHE_MODE = 29;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__DCACHE_REPORTS_PHYSICAL = 30;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__RSI_DISABLE_DATIN_FASTPATH = 31;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__FORBID_MMIO_READ_GT_32 = 32;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__FORBID_MMIO_ATOMIC = 33;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0_0_RESERVED1 = 34;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0_0_RESERVED1_LEN = 2;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__ENABLE_CONTEXT_LCO = 36;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__MA_DSA_OPT_FAIL_WAKE = 37;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__ENABLE_FAST_DIR_UPDATE = 38;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__OPT_MES_USE_GO_M = 39;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__OPT_LCO_M_USE_MU = 40;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__OPT_SNOOP_EX_LCO = 41;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__ENABLE_CP_ME = 42;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__FENCE_ON_DERR_MMIO = 43;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK0_OCAPI_MODE = 44;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK1_OCAPI_MODE = 45;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK2_OCAPI_MODE = 46;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK3_OCAPI_MODE = 47;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK4_OCAPI_MODE = 48;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK0_NVLINK_MODE = 49;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK1_NVLINK_MODE = 50;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK2_NVLINK_MODE = 51;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK3_NVLINK_MODE = 52;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK4_NVLINK_MODE = 53;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK0_POISON_FENCE_L2 = 54;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0__BRK1_POISON_FENCE_L2 = 55;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0_0_RESERVED0 = 56;
static const uint32_t CS_SM3_MCP_MISC_CONFIG0_0_RESERVED0_LEN = 8;
// pau/reg00016.H

static const uint64_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2 = 0x10010960ull;

static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_TAG = 0;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_TAG_LEN = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_TAGMASK = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_TAGMASK_LEN = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_MASK_PAU = 28;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_MASK_PCIE = 29;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_MASK_L2L3 = 30;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_RESERVED1 = 31;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_RDSTART = 32;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_RDSTART_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_RDEND = 40;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_RDEND_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_WRSTART = 48;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_WRSTART_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_WREND = 56;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC2_WREND_LEN = 8;
// pau/reg00016.H

static const uint64_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1 = 0x1001097dull;

static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_ABLE_8_15 = 0;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_ABLE_8_15_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY8 = 8;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY8_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY9 = 12;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY9_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY10 = 16;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY10_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY11 = 20;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY11_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY12 = 24;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY12_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY13 = 28;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY13_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY14 = 32;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY14_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY15 = 36;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE1_TRY15_LEN = 4;
// pau/reg00016.H

static const uint64_t FIR_ACTION0_REG_2 = 0x10010c86ull;

static const uint32_t FIR_ACTION0_REG_2_FIR_ACTION0_2 = 0;
static const uint32_t FIR_ACTION0_REG_2_FIR_ACTION0_2_LEN = 62;
// pau/reg00016.H

static const uint64_t MISC_REGS_BDF2PE_1_CONFIG = 0x10010b51ull;

static const uint32_t MISC_REGS_BDF2PE_1_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_1_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_1_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_1_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_1_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_1_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_1_CONFIG_BDF_LEN = 16;
// pau/reg00016.H

static const uint64_t MISC_REGS_DEBUG_CONFIG = 0x10010b30ull;

static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE0 = 0;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE0_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE1 = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE1_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE2 = 4;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE2_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE3 = 6;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE3_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE4 = 8;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE4_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE5 = 10;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE5_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE6 = 12;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE6_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE7 = 14;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE7_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE8 = 16;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE8_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE9 = 18;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE9_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE10 = 20;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS0BYTE10_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE0 = 22;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE0_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE1 = 24;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE1_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE2 = 26;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE2_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE3 = 28;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE3_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE4 = 30;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE4_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE5 = 32;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE5_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE6 = 34;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE6_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE7 = 36;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE7_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE8 = 38;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE8_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE9 = 40;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE9_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE10 = 42;
static const uint32_t MISC_REGS_DEBUG_CONFIG_MISC_DEBUG_CONFIG_BUS1BYTE10_LEN = 2;
static const uint32_t MISC_REGS_DEBUG_CONFIG_RESERVED = 44;
static const uint32_t MISC_REGS_DEBUG_CONFIG_RESERVED_LEN = 19;
static const uint32_t MISC_REGS_DEBUG_CONFIG_ACT_DEBUG = 63;
// pau/reg00016.H

static const uint64_t MISC_REGS_INT_LOG_0_PE1 = 0x10010b91ull;

static const uint32_t MISC_REGS_INT_LOG_0_PE1_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE1_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE1_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE1_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE1_RSVD0_LEN = 3;
// pau/reg00016.H

static const uint64_t MISC_REGS_INT_LOG_0_PE13 = 0x10010b9dull;

static const uint32_t MISC_REGS_INT_LOG_0_PE13_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE13_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE13_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE13_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE13_RSVD0_LEN = 3;
// pau/reg00016.H

static const uint64_t MISC_REGS_INT_LOG_1_PE1 = 0x10010ba1ull;

static const uint32_t MISC_REGS_INT_LOG_1_PE1_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE1_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE1_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE1_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE1_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE1_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE1_RSVD0_LEN = 7;
// pau/reg00016.H

static const uint64_t MISC_REGS_INT_LOG_1_PE15 = 0x10010bafull;

static const uint32_t MISC_REGS_INT_LOG_1_PE15_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE15_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE15_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE15_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE15_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE15_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE15_RSVD0_LEN = 7;
// pau/reg00016.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE1 = 0x10010b81ull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE1_DMA_STOPPED_STATE_ADDR_PE1 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE1_DMA_STOPPED_STATE_ADDR_PE1_LEN = 37;
// pau/reg00016.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE14 = 0x10010b8eull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE14_DMA_STOPPED_STATE_ADDR_PE14 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE14_DMA_STOPPED_STATE_ADDR_PE14_LEN = 37;
// pau/reg00016.H

static const uint64_t MISC_REGS_PESTB_DATA_PE14 = 0x10010b7eull;

static const uint32_t MISC_REGS_PESTB_DATA_PE14_DMA_STOPPED_STATE_PE14 = 0;
// pau/reg00016.H

static const uint64_t MISC_REGS_PESTB_DATA_PE2 = 0x10010b72ull;

static const uint32_t MISC_REGS_PESTB_DATA_PE2_DMA_STOPPED_STATE_PE2 = 0;
// pau/reg00016.H

static const uint64_t NTL0_REGS_CERR_HOLD2 = 0x100109e6ull;

static const uint32_t NTL0_REGS_CERR_HOLD2_0 = 0;
static const uint32_t NTL0_REGS_CERR_HOLD2_1 = 1;
static const uint32_t NTL0_REGS_CERR_HOLD2_2 = 2;
static const uint32_t NTL0_REGS_CERR_HOLD2_3 = 3;
static const uint32_t NTL0_REGS_CERR_HOLD2_4 = 4;
static const uint32_t NTL0_REGS_CERR_HOLD2_5 = 5;
static const uint32_t NTL0_REGS_CERR_HOLD2_6 = 6;
static const uint32_t NTL0_REGS_CERR_HOLD2_7 = 7;
static const uint32_t NTL0_REGS_CERR_HOLD2_8 = 8;
static const uint32_t NTL0_REGS_CERR_HOLD2_9 = 9;
static const uint32_t NTL0_REGS_CERR_HOLD2_10 = 10;
static const uint32_t NTL0_REGS_CERR_HOLD2_11 = 11;
static const uint32_t NTL0_REGS_CERR_HOLD2_12 = 12;
static const uint32_t NTL0_REGS_CERR_HOLD2_13 = 13;
static const uint32_t NTL0_REGS_CERR_HOLD2_14 = 14;
static const uint32_t NTL0_REGS_CERR_HOLD2_15 = 15;
static const uint32_t NTL0_REGS_CERR_HOLD2_16 = 16;
static const uint32_t NTL0_REGS_CERR_HOLD2_17 = 17;
static const uint32_t NTL0_REGS_CERR_HOLD2_18 = 18;
static const uint32_t NTL0_REGS_CERR_HOLD2_19 = 19;
static const uint32_t NTL0_REGS_CERR_HOLD2_20 = 20;
static const uint32_t NTL0_REGS_CERR_HOLD2_21 = 21;
static const uint32_t NTL0_REGS_CERR_HOLD2_22 = 22;
static const uint32_t NTL0_REGS_CERR_HOLD2_23 = 23;
static const uint32_t NTL0_REGS_CERR_HOLD2_24 = 24;
static const uint32_t NTL0_REGS_CERR_HOLD2_25 = 25;
static const uint32_t NTL0_REGS_CERR_HOLD2_26 = 26;
static const uint32_t NTL0_REGS_CERR_HOLD2_27 = 27;
static const uint32_t NTL0_REGS_CERR_HOLD2_28 = 28;
static const uint32_t NTL0_REGS_CERR_HOLD2_29 = 29;
static const uint32_t NTL0_REGS_CERR_HOLD2_30 = 30;
static const uint32_t NTL0_REGS_CERR_HOLD2_31 = 31;
static const uint32_t NTL0_REGS_CERR_HOLD2_32 = 32;
static const uint32_t NTL0_REGS_CERR_HOLD2_33 = 33;
static const uint32_t NTL0_REGS_CERR_HOLD2_34 = 34;
static const uint32_t NTL0_REGS_CERR_HOLD2_35 = 35;
static const uint32_t NTL0_REGS_CERR_HOLD2_36 = 36;
static const uint32_t NTL0_REGS_CERR_HOLD2_37 = 37;
static const uint32_t NTL0_REGS_CERR_HOLD2_38 = 38;
static const uint32_t NTL0_REGS_CERR_HOLD2_39 = 39;
static const uint32_t NTL0_REGS_CERR_HOLD2_40 = 40;
static const uint32_t NTL0_REGS_CERR_HOLD2_41 = 41;
static const uint32_t NTL0_REGS_CERR_HOLD2_42 = 42;
static const uint32_t NTL0_REGS_CERR_HOLD2_43 = 43;
static const uint32_t NTL0_REGS_CERR_HOLD2_44 = 44;
static const uint32_t NTL0_REGS_CERR_HOLD2_45 = 45;
static const uint32_t NTL0_REGS_CERR_HOLD2_46 = 46;
static const uint32_t NTL0_REGS_CERR_HOLD2_47 = 47;
static const uint32_t NTL0_REGS_CERR_HOLD2_48 = 48;
static const uint32_t NTL0_REGS_CERR_HOLD2_49 = 49;
static const uint32_t NTL0_REGS_CERR_HOLD2_50 = 50;
static const uint32_t NTL0_REGS_CERR_HOLD2_51 = 51;
static const uint32_t NTL0_REGS_CERR_HOLD2_52 = 52;
static const uint32_t NTL0_REGS_CERR_HOLD2_53 = 53;
static const uint32_t NTL0_REGS_CERR_HOLD2_54 = 54;
static const uint32_t NTL0_REGS_CERR_HOLD2_55 = 55;
static const uint32_t NTL0_REGS_CERR_HOLD2_56 = 56;
static const uint32_t NTL0_REGS_CERR_HOLD2_57 = 57;
static const uint32_t NTL0_REGS_CERR_HOLD2_58 = 58;
static const uint32_t NTL0_REGS_CERR_HOLD2_59 = 59;
static const uint32_t NTL0_REGS_CERR_HOLD2_60 = 60;
static const uint32_t NTL0_REGS_CERR_HOLD2_61 = 61;
static const uint32_t NTL0_REGS_CERR_HOLD2_62 = 62;
static const uint32_t NTL0_REGS_CERR_HOLD2_63 = 63;
// pau/reg00016.H

static const uint64_t NTL0_REGS_RSP_HA_PTR = 0x100109f3ull;

static const uint32_t NTL0_REGS_RSP_HA_PTR_RESERVED1 = 0;
static const uint32_t NTL0_REGS_RSP_HA_PTR_RESERVED1_LEN = 5;
static const uint32_t NTL0_REGS_RSP_HA_PTR_START = 5;
static const uint32_t NTL0_REGS_RSP_HA_PTR_START_LEN = 7;
static const uint32_t NTL0_REGS_RSP_HA_PTR_RESERVED2 = 12;
static const uint32_t NTL0_REGS_RSP_HA_PTR_RESERVED2_LEN = 5;
static const uint32_t NTL0_REGS_RSP_HA_PTR_END = 17;
static const uint32_t NTL0_REGS_RSP_HA_PTR_END_LEN = 7;
// pau/reg00016.H

static const uint64_t NTL1_REGS_DEBUG0_CONFIG = 0x10010a0cull;

static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t NTL1_REGS_DEBUG0_CONFIG_ACT = 63;
// pau/reg00016.H

static const uint64_t NTL1_REGS_PRI_CONFIG = 0x10010a16ull;

static const uint32_t NTL1_REGS_PRI_CONFIG_DISABLE = 0;
static const uint32_t NTL1_REGS_PRI_CONFIG_NDL = 1;
static const uint32_t NTL1_REGS_PRI_CONFIG_NDL_LEN = 2;
static const uint32_t NTL1_REGS_PRI_CONFIG_PHY = 3;
static const uint32_t NTL1_REGS_PRI_CONFIG_PHY_LEN = 2;
// pau/reg00016.H

static const uint64_t OTL0_MISC_C_ERR_RPT_MASK0 = 0x10010a27ull;

static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_00 = 0;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_01 = 1;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_02 = 2;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_03 = 3;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_04 = 4;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_05 = 5;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_06 = 6;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_07 = 7;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_08 = 8;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_09 = 9;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_10 = 10;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_11 = 11;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_12 = 12;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_13 = 13;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_14 = 14;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_15 = 15;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_16 = 16;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_17 = 17;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_18 = 18;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_19 = 19;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_20 = 20;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_21 = 21;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_22 = 22;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_23 = 23;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_24 = 24;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_25 = 25;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_26 = 26;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_27 = 27;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_28 = 28;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_29 = 29;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_30 = 30;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_31 = 31;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_32 = 32;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_33 = 33;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_34 = 34;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_35 = 35;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_36 = 36;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_37 = 37;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_38 = 38;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_39 = 39;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_40 = 40;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_41 = 41;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_42 = 42;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_43 = 43;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_44 = 44;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_45 = 45;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_46 = 46;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_47 = 47;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_48 = 48;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_49 = 49;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_50 = 50;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_51 = 51;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_52 = 52;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_53 = 53;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_54 = 54;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_55 = 55;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_56 = 56;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_57 = 57;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_58 = 58;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_59 = 59;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_60 = 60;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_61 = 61;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_62 = 62;
static const uint32_t OTL0_MISC_C_ERR_RPT_MASK0_63 = 63;
// pau/reg00016.H

static const uint64_t OTL0_MISC_ERROR_SIG_TXI = 0x10010a3aull;

static const uint32_t OTL0_MISC_ERROR_SIG_TXI_ERRSIGTXI_BAD_OPCODE = 0;
static const uint32_t OTL0_MISC_ERROR_SIG_TXI_ERRSIGTXI_BAD_OPCODE_LEN = 8;
// pau/reg00017.H

static const uint64_t OTL0_MISC_PMU_CONTROL1 = 0x10010a23ull;

static const uint32_t OTL0_MISC_PMU_CONTROL1_C01_OPCODEA = 0;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C01_OPCODEA_LEN = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C01_OPCODEB = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C01_OPCODEB_LEN = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C23_OPCODEA = 16;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C23_OPCODEA_LEN = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C23_OPCODEB = 24;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C23_OPCODEB_LEN = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C01_DLA = 32;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C01_DLA_LEN = 2;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C01_DLB = 34;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C01_DLB_LEN = 2;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C23_DLA = 36;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C23_DLA_LEN = 2;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C23_DLB = 38;
static const uint32_t OTL0_MISC_PMU_CONTROL1_C23_DLB_LEN = 2;
static const uint32_t OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY = 40;
static const uint32_t OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY_LEN = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL1_RESERVED1 = 48;
static const uint32_t OTL0_MISC_PMU_CONTROL1_RESERVED1_LEN = 16;
// pau/reg00017.H

static const uint64_t OTL0_MISC_PSL_DAR_AN = 0x10010a49ull;

static const uint32_t OTL0_MISC_PSL_DAR_AN_CO_EA = 0;
static const uint32_t OTL0_MISC_PSL_DAR_AN_CO_EA_LEN = 52;
// pau/reg00017.H

static const uint64_t OTL0_MISC_TX_DL_CREDIT_STATUS = 0x10010a34ull;

static const uint32_t OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT = 0;
static const uint32_t OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT_LEN = 12;
// pau/reg00017.H

static const uint64_t OTL1_MISC_CONFIG_TLX_CREDITS = 0x10010a5aull;

static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS = 0;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS_LEN = 8;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS = 8;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS_LEN = 8;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS = 16;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS_LEN = 8;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS = 24;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS_LEN = 8;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS = 32;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS_LEN = 8;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_SPARE = 40;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_SPARE_LEN = 8;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS = 48;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS_LEN = 8;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS = 56;
static const uint32_t OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS_LEN = 8;
// pau/reg00017.H

static const uint64_t OTL1_MISC_CONFIG_TX2 = 0x10010a68ull;

static const uint32_t OTL1_MISC_CONFIG_TX2_TX_SEND_EN = 0;
static const uint32_t OTL1_MISC_CONFIG_TX2_TX_SPARE4 = 1;
static const uint32_t OTL1_MISC_CONFIG_TX2_TX_SPARE4_LEN = 3;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC1_THRESH1 = 4;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC1_THRESH1_LEN = 4;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC2_THRESH1 = 8;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC2_THRESH1_LEN = 4;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC3_THRESH1 = 12;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC3_THRESH1_LEN = 4;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC1_THRESH2 = 16;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC1_THRESH2_LEN = 4;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC2_THRESH2 = 20;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC2_THRESH2_LEN = 4;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC3_THRESH2 = 24;
static const uint32_t OTL1_MISC_CONFIG_TX2_VC3_THRESH2_LEN = 4;
// pau/reg00017.H

static const uint64_t OTL1_MISC_C_ERR_RPT_MASK0 = 0x10010a57ull;

static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_00 = 0;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_01 = 1;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_02 = 2;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_03 = 3;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_04 = 4;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_05 = 5;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_06 = 6;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_07 = 7;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_08 = 8;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_09 = 9;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_10 = 10;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_11 = 11;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_12 = 12;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_13 = 13;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_14 = 14;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_15 = 15;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_16 = 16;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_17 = 17;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_18 = 18;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_19 = 19;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_20 = 20;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_21 = 21;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_22 = 22;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_23 = 23;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_24 = 24;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_25 = 25;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_26 = 26;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_27 = 27;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_28 = 28;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_29 = 29;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_30 = 30;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_31 = 31;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_32 = 32;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_33 = 33;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_34 = 34;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_35 = 35;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_36 = 36;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_37 = 37;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_38 = 38;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_39 = 39;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_40 = 40;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_41 = 41;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_42 = 42;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_43 = 43;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_44 = 44;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_45 = 45;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_46 = 46;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_47 = 47;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_48 = 48;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_49 = 49;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_50 = 50;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_51 = 51;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_52 = 52;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_53 = 53;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_54 = 54;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_55 = 55;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_56 = 56;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_57 = 57;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_58 = 58;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_59 = 59;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_60 = 60;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_61 = 61;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_62 = 62;
static const uint32_t OTL1_MISC_C_ERR_RPT_MASK0_63 = 63;
// pau/reg00017.H

static const uint64_t XSL_MAIN_XSLOP_VLOG_RGS_EEI = 0x10010a95ull;

static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL = 0;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL_LEN = 6;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL = 8;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL_LEN = 8;
// pau/reg00017.H

static const uint64_t XSL_MAIN_ARY_RD_ADDR_REG = 0x10010aa1ull;

static const uint32_t XSL_MAIN_ARY_RD_ADDR_REG_SELECT = 0;
static const uint32_t XSL_MAIN_ARY_RD_ADDR_REG_SELECT_LEN = 3;
static const uint32_t XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS = 3;
static const uint32_t XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS_LEN = 10;
static const uint32_t XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT = 13;
static const uint32_t XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT_LEN = 2;
// pau/reg00017.H

static const uint64_t XSL_MAIN_DEBUG0_CONFIG = 0x10010aa3ull;

static const uint32_t XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL = 0;
static const uint32_t XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL_LEN = 64;
// pau/reg00017.H

static const uint64_t XSL_MAIN_WRAP_ERR_MASK_0 = 0x10010aaaull;

static const uint32_t XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL = 0;
static const uint32_t XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL_LEN = 54;
// pau/reg00017.H

static const uint64_t XTS_ATSD_HYP11 = 0x10010b1bull;

static const uint32_t XTS_ATSD_HYP11_MSRHV = 51;
static const uint32_t XTS_ATSD_HYP11_LPARID = 52;
static const uint32_t XTS_ATSD_HYP11_LPARID_LEN = 12;
// pau/reg00017.H

static const uint64_t XTS_REG_ATRMISS = 0x10010afaull;

static const uint32_t XTS_REG_ATRMISS_ADDR = 15;
static const uint32_t XTS_REG_ATRMISS_ADDR_LEN = 37;
static const uint32_t XTS_REG_ATRMISS_FLAG_OTHER = 54;
static const uint32_t XTS_REG_ATRMISS_FLAG_PREF = 55;
static const uint32_t XTS_REG_ATRMISS_FLAG_DMD = 56;
static const uint32_t XTS_REG_ATRMISS_FLAG_MAP = 57;
static const uint32_t XTS_REG_ATRMISS_FLAG_FENCE = 58;
static const uint32_t XTS_REG_ATRMISS_RETIRE = 59;
static const uint32_t XTS_REG_ATRMISS_IRQENA = 60;
static const uint32_t XTS_REG_ATRMISS_SECOND = 61;
static const uint32_t XTS_REG_ATRMISS_TRIGGERED = 62;
static const uint32_t XTS_REG_ATRMISS_ENA = 63;
// pau/reg00017.H

}
}
#include "pau/reg00016.H"
#include "pau/reg00017.H"
#endif
