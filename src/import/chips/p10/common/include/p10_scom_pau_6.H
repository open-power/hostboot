/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_6.H $        */
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

#ifndef __p10_scom_pau_6_H_
#define __p10_scom_pau_6_H_


namespace scomt
{
namespace pau
{


static const uint64_t AME_AME1_MISC_CERR_RPT_HOLD = 0x10010bd8ull;

static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_CREGA_PERR = 48;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_CREGM_PERR = 49;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_LDW_UE = 50;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_FU_UE = 51;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_WB_UE = 52;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_PCT_UE = 53;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_CBA_UE = 54;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_ERAT_UE = 55;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_PE_UE = 56;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_XCT_UE = 57;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_WB_CE = 58;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_PCT_CE = 59;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_CBA_CE = 60;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_ERAT_CE = 61;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_PE_CE = 62;
static const uint32_t AME_AME1_MISC_CERR_RPT_HOLD_XCT_CE = 63;
// pau/reg00007.H

static const uint64_t AME_AME1_MISC_CERR_RPT_INFO = 0x10010bdaull;

static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_FU_ETYPE = 5;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_FU_ETYPE_LEN = 13;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_XCTS = 18;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_XCTS_LEN = 2;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_ERATS = 20;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_ERATS_LEN = 4;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_WBS = 24;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_WBS_LEN = 8;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_FIRST_AMES = 32;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_FIRST_AMES_LEN = 8;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_AMES = 40;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_AMES_LEN = 8;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_FIRST_UE = 48;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_FIRST_UE_LEN = 10;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_FIRST_CE = 58;
static const uint32_t AME_AME1_MISC_CERR_RPT_INFO_FIRST_CE_LEN = 6;
// pau/reg00007.H

static const uint64_t AME_AME1_MISC_PMU_CONFIG2 = 0x10010bd7ull;

static const uint32_t AME_AME1_MISC_PMU_CONFIG2_PE_TYPE = 5;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_PE_TYPE_LEN = 3;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_INST_CAT = 8;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_INST_CAT_LEN = 4;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_PC0 = 12;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_PC0_LEN = 13;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_PC1 = 25;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_PC1_LEN = 13;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_PCR_S = 38;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_PCR_S_LEN = 13;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_PCR_E = 51;
static const uint32_t AME_AME1_MISC_PMU_CONFIG2_PCR_E_LEN = 13;
// pau/reg00007.H

static const uint64_t ATS_REG_MASK = 0x10010ab6ull;

static const uint32_t ATS_REG_MASK_IDIAL_ATS_MASK = 0;
static const uint32_t ATS_REG_MASK_IDIAL_ATS_MASK_LEN = 20;
// pau/reg00007.H

static const uint64_t ATS_REG_IODA_ADDR = 0x10010ad1ull;

static const uint32_t ATS_REG_IODA_ADDR_AUTO_INCREMENT = 0;
static const uint32_t ATS_REG_IODA_ADDR_TABLE_SELECT = 11;
static const uint32_t ATS_REG_IODA_ADDR_TABLE_SELECT_LEN = 5;
static const uint32_t ATS_REG_IODA_ADDR_TABLE_ADDRESS = 54;
static const uint32_t ATS_REG_IODA_ADDR_TABLE_ADDRESS_LEN = 10;
// pau/reg00007.H

static const uint64_t ATS_REG_PAU_DEBUG = 0x10010ab3ull;

static const uint32_t ATS_REG_PAU_DEBUG_ENABLE = 0;
static const uint32_t ATS_REG_PAU_DEBUG_0_SELECT = 1;
static const uint32_t ATS_REG_PAU_DEBUG_0_SELECT_LEN = 3;
static const uint32_t ATS_REG_PAU_DEBUG_1_SELECT = 4;
static const uint32_t ATS_REG_PAU_DEBUG_1_SELECT_LEN = 3;
// pau/reg00007.H

static const uint64_t ATS_REG_TCE_KILL = 0x10010ad4ull;

static const uint32_t ATS_REG_TCE_KILL_ALL = 0;
static const uint32_t ATS_REG_TCE_KILL_ONE = 2;
static const uint32_t ATS_REG_TCE_KILL_PE_NUMBER = 4;
static const uint32_t ATS_REG_TCE_KILL_PE_NUMBER_LEN = 4;
static const uint32_t ATS_REG_TCE_KILL_ADDRESS = 15;
static const uint32_t ATS_REG_TCE_KILL_ADDRESS_LEN = 37;
// pau/reg00007.H

static const uint64_t CS_CTL_MISC_BDF2PE_5_CONFIG = 0x100109b5ull;

static const uint32_t CS_CTL_MISC_BDF2PE_5_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_5_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_5_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_5_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_5_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_5_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_5_CONFIG_BDF_LEN = 16;
// pau/reg00007.H

static const uint64_t CS_CTL_MISC_CERR_MASK1 = 0x1001099eull;

static const uint32_t CS_CTL_MISC_CERR_MASK1_PEF_0 = 0;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PEF_1 = 1;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PEF_2 = 2;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PEF_3 = 3;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PEF_4 = 4;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PEF_5 = 5;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PEF_6 = 6;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PEF_7 = 7;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_0 = 8;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_1 = 9;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_2 = 10;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_3 = 11;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_4 = 12;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_5 = 13;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_6 = 14;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_7 = 15;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_8 = 16;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_9 = 17;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_10 = 18;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_11 = 19;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_12 = 20;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_13 = 21;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_14 = 22;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_15 = 23;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_16 = 24;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_17 = 25;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_18 = 26;
static const uint32_t CS_CTL_MISC_CERR_MASK1_NLG_19 = 27;
static const uint32_t CS_CTL_MISC_CERR_MASK1_FWD_0 = 28;
static const uint32_t CS_CTL_MISC_CERR_MASK1_FWD_1 = 29;
static const uint32_t CS_CTL_MISC_CERR_MASK1_FWD_2 = 30;
static const uint32_t CS_CTL_MISC_CERR_MASK1_FWD_3 = 31;
static const uint32_t CS_CTL_MISC_CERR_MASK1_AUE_0 = 32;
static const uint32_t CS_CTL_MISC_CERR_MASK1_AUE_1 = 33;
static const uint32_t CS_CTL_MISC_CERR_MASK1_AUE_2 = 34;
static const uint32_t CS_CTL_MISC_CERR_MASK1_AUE_3 = 35;
static const uint32_t CS_CTL_MISC_CERR_MASK1_AUE_4 = 36;
static const uint32_t CS_CTL_MISC_CERR_MASK1_AUE_5 = 37;
static const uint32_t CS_CTL_MISC_CERR_MASK1_AUE_6 = 38;
static const uint32_t CS_CTL_MISC_CERR_MASK1_AUE_7 = 39;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBP_0 = 40;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBP_1 = 41;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBP_2 = 42;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBP_3 = 43;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBF_0 = 44;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBF_1 = 45;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBF_2 = 46;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBF_3 = 47;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBF_4 = 48;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBF_5 = 49;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBF_6 = 50;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBF_7 = 51;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBC_0 = 52;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBC_1 = 53;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBC_2 = 54;
static const uint32_t CS_CTL_MISC_CERR_MASK1_PBC_3 = 55;
static const uint32_t CS_CTL_MISC_CERR_MASK1_SMV_0 = 56;
static const uint32_t CS_CTL_MISC_CERR_MASK1_SMV_1 = 57;
static const uint32_t CS_CTL_MISC_CERR_MASK1_SMV_2 = 58;
static const uint32_t CS_CTL_MISC_CERR_MASK1_SMV_3 = 59;
static const uint32_t CS_CTL_MISC_CERR_MASK1_RSV3_0 = 60;
static const uint32_t CS_CTL_MISC_CERR_MASK1_RSV3_1 = 61;
static const uint32_t CS_CTL_MISC_CERR_MASK1_RSV3_2 = 62;
static const uint32_t CS_CTL_MISC_CERR_MASK1_RSV3_3 = 63;
// pau/reg00007.H

static const uint64_t CS_CTL_MISC_SCOPE_PREDICT4 = 0x100109afull;

static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_LN_FAIL_THRESH = 0;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_LN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_NN_FAIL_THRESH = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_NN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_RN_FAIL_THRESH = 6;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_RN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_G_FAIL_THRESH = 9;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_G_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_LN_INTV_THRESH = 12;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_LN_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_G_INTV_THRESH = 15;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_G_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4RD_VG_ENABLE = 18;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4_4_RESERVED1 = 19;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_LN_FAIL_THRESH = 20;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_LN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_NN_FAIL_THRESH = 23;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_NN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_RN_FAIL_THRESH = 26;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_RN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_G_FAIL_THRESH = 29;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_G_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_LN_INTV_THRESH = 32;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_LN_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_G_INTV_THRESH = 35;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_G_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4__B4WR_VG_ENABLE = 38;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT4_4_RESERVED2 = 39;
// pau/reg00007.H

static const uint64_t CS_SM0_DIR_MISC_DEBUG0_CONFIG = 0x1001082aull;

static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM0_DIR_MISC_DEBUG0_CONFIG_ACT = 63;
// pau/reg00007.H

static const uint64_t CS_SM0_MCP_MISC_CERR_FIRST1 = 0x10010810ull;

static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_NLGX_0 = 0;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_NLGX_1 = 1;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_NLGX_2 = 2;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_NLGX_3 = 3;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_FWD_0 = 4;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_FWD_1 = 5;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_FWD_2 = 6;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_FWD_3 = 7;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_AUE_0 = 8;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_AUE_1 = 9;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_AUE_2 = 10;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_AUE_3 = 11;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_AUE_4 = 12;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_AUE_5 = 13;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_AUE_6 = 14;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_AUE_7 = 15;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_0 = 16;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_1 = 17;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_2 = 18;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_3 = 19;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_4 = 20;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_5 = 21;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_6 = 22;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_7 = 23;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_8 = 24;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_9 = 25;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_10 = 26;
static const uint32_t CS_SM0_MCP_MISC_CERR_FIRST1_PBF_11 = 27;
// pau/reg00007.H

static const uint64_t CS_SM0_MCP_MISC_CERR_MESSAGE5 = 0x1001080bull;

static const uint32_t CS_SM0_MCP_MISC_CERR_MESSAGE5_CERR_MESSAGE_BITS5 = 0;
static const uint32_t CS_SM0_MCP_MISC_CERR_MESSAGE5_CERR_MESSAGE_BITS5_LEN = 64;
// pau/reg00007.H

static const uint64_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2 = 0x10010848ull;

static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_W = 0;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_W_HP = 1;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_INJ = 2;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_PR_DMA_INJ = 3;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_DMA_PR_W = 4;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_RD_NC_F0 = 5;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMAX_U = 6;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMAX_S = 7;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMIN_U = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMIN_S = 9;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_ADD = 10;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_AND = 11;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_OR = 12;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_XOR = 13;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMAX_U = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMAX_S = 15;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMIN_U = 16;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMIN_S = 17;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_ADD = 18;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_AND = 19;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_OR = 20;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_XOR = 21;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_E = 22;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_U = 23;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_T = 24;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_NE = 25;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_INC_B = 26;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_INC_E = 27;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_DEC_B = 28;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_RESERVED1 = 29;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_RESERVED1_LEN = 3;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_WRENA = 32;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_RDENA = 33;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_AWENA = 34;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_ARENA = 35;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_WRENA = 36;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_RDENA = 37;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_AWENA = 38;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_ARENA = 39;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_WRENA = 40;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_RDENA = 41;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_AWENA = 42;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_ARENA = 43;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_WRENA = 44;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_RDENA = 45;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_AWENA = 46;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_ARENA = 47;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_WRENA = 48;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_RDENA = 49;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_AWENA = 50;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_ARENA = 51;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_WRENA = 52;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_RDENA = 53;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_AWENA = 54;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_ARENA = 55;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_WRENA = 56;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_RDENA = 57;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_AWENA = 58;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_ARENA = 59;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_WRENA = 60;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_RDENA = 61;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_AWENA = 62;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_ARENA = 63;
// pau/reg00007.H

static const uint64_t CS_SM1_MCP_MISC_CERR_FIRST1 = 0x10010870ull;

static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_NLGX_0 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_NLGX_1 = 1;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_NLGX_2 = 2;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_NLGX_3 = 3;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_FWD_0 = 4;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_FWD_1 = 5;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_FWD_2 = 6;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_FWD_3 = 7;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_AUE_0 = 8;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_AUE_1 = 9;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_AUE_2 = 10;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_AUE_3 = 11;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_AUE_4 = 12;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_AUE_5 = 13;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_AUE_6 = 14;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_AUE_7 = 15;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_0 = 16;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_1 = 17;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_2 = 18;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_3 = 19;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_4 = 20;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_5 = 21;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_6 = 22;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_7 = 23;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_8 = 24;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_9 = 25;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_10 = 26;
static const uint32_t CS_SM1_MCP_MISC_CERR_FIRST1_PBF_11 = 27;
// pau/reg00007.H

static const uint64_t CS_SM1_MCP_MISC_CERR_MASK2 = 0x10010874ull;

static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_0 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_1 = 1;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_2 = 2;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_3 = 3;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_4 = 4;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_5 = 5;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_6 = 6;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_7 = 7;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_8 = 8;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_9 = 9;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_10 = 10;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_11 = 11;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_12 = 12;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_13 = 13;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_14 = 14;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_15 = 15;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_16 = 16;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_17 = 17;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_18 = 18;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_19 = 19;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_20 = 20;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_21 = 21;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_22 = 22;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_23 = 23;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_24 = 24;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_25 = 25;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_26 = 26;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_27 = 27;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_28 = 28;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_29 = 29;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_30 = 30;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_31 = 31;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_32 = 32;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_33 = 33;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_34 = 34;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_35 = 35;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_36 = 36;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_37 = 37;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_38 = 38;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_39 = 39;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_40 = 40;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_41 = 41;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_42 = 42;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_43 = 43;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_44 = 44;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_45 = 45;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_46 = 46;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_47 = 47;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_48 = 48;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_49 = 49;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_50 = 50;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_51 = 51;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_52 = 52;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_53 = 53;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_54 = 54;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_55 = 55;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_56 = 56;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_57 = 57;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_58 = 58;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_59 = 59;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_60 = 60;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_61 = 61;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_62 = 62;
static const uint32_t CS_SM1_MCP_MISC_CERR_MASK2_63 = 63;
// pau/reg00007.H

static const uint64_t CS_SM1_MCP_MISC_DEBUG0_CONFIG = 0x1001087aull;

static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM1_MCP_MISC_DEBUG0_CONFIG_ACT = 63;
// pau/reg00007.H

static const uint64_t CS_SM1_MCP_MISC_INHIBIT_CONFIG = 0x10010865ull;

static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_LFREQ0 = 0;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_LFREQ0_LEN = 4;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_PFREQ0 = 4;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_PFREQ0_LEN = 2;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_BLOCKY0 = 6;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_ONESHOT0 = 7;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_DEST0 = 8;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_DEST0_LEN = 8;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_LFREQ1 = 16;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_LFREQ1_LEN = 4;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_PFREQ1 = 20;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_PFREQ1_LEN = 2;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_BLOCKY1 = 22;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_ONESHOT1 = 23;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_DEST1 = 24;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_DEST1_LEN = 8;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_LFREQ2 = 32;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_LFREQ2_LEN = 4;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_PFREQ2 = 36;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_PFREQ2_LEN = 2;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_BLOCKY2 = 38;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_ONESHOT2 = 39;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_DEST2 = 40;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_DEST2_LEN = 8;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_LFREQ3 = 48;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_LFREQ3_LEN = 4;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_PFREQ3 = 52;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_PFREQ3_LEN = 2;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_BLOCKY3 = 54;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_ONESHOT3 = 55;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_DEST3 = 56;
static const uint32_t CS_SM1_MCP_MISC_INHIBIT_CONFIG_DEST3_LEN = 8;
// pau/reg00007.H

static const uint64_t CS_SM1_SNP_MISC_CONFIG0 = 0x10010890ull;

static const uint32_t CS_SM1_SNP_MISC_CONFIG0__MA_RSNOOP_OPT_DCLAIM = 0;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__MA_RSNOOP_OPT_DCLAIM_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__ENABLE_PBUS = 2;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRAZOS_MODE = 3;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__PCKT_BLK_PRB = 4;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__ADR_BAR_MODE = 5;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__RESTRICT_CHIP_GROUP = 6;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED3 = 7;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED3_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__SNP_FIR_TO_INHIBIT_MASK = 9;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__SNP_FIR_TO_INHIBIT_MASK_LEN = 7;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK0_FENCE_TO_INHIBIT_MASK = 16;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK1_FENCE_TO_INHIBIT_MASK = 17;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK2_FENCE_TO_INHIBIT_MASK = 18;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK3_FENCE_TO_INHIBIT_MASK = 19;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK4_FENCE_TO_INHIBIT_MASK = 20;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__MRBGP_TRACK_ALL = 21;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__MRBSP_TRACK_ALL = 22;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__MRBCP_TRACK_ALL = 23;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__ADDR_EX_MASK_ENA = 24;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__ADDR_EX_MASK_ENA_LEN = 7;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__SINGLE_AFU_DUAL_BRICK = 31;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK0_OCAPI_MODE = 32;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK1_OCAPI_MODE = 33;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK2_OCAPI_MODE = 34;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK3_OCAPI_MODE = 35;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK4_OCAPI_MODE = 36;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK0_NVLINK_MODE = 37;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK1_NVLINK_MODE = 38;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK2_NVLINK_MODE = 39;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK3_NVLINK_MODE = 40;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__BRK4_NVLINK_MODE = 41;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__ENABLE_BLOCKING_RCMD_DIR = 42;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__DISABLE_DIR_POWERSAVE = 43;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__DISABLE_PRESP_POWERSAVE = 44;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__ENABLE_BRK0_OCAPI_C2 = 45;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__ENABLE_BRK1_OCAPI_C2 = 46;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__ENABLE_BRK2_OCAPI_C2 = 47;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__ENABLE_BRK3_OCAPI_C2 = 48;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__ENABLE_BRK4_OCAPI_C2 = 49;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__DISABLE_CAN_BY_CP = 50;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED1 = 51;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED2 = 52;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED4 = 53;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED5 = 54;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED6 = 55;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED7 = 56;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED8 = 57;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED9 = 58;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED10 = 59;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0__DISABLE_CAN_BY_PROBE = 60;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED0 = 61;
static const uint32_t CS_SM1_SNP_MISC_CONFIG0_0_RESERVED0_LEN = 3;
// pau/reg00007.H

static const uint64_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1 = 0x1001089full;

static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_TAG = 0;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_TAG_LEN = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_TAGMASK = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_TAGMASK_LEN = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_PAU = 28;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_PCIE = 29;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_L2L3 = 30;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_RESERVED1 = 31;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_RDSTART = 32;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_RDSTART_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_RDEND = 40;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_RDEND_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_WRSTART = 48;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_WRSTART_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_WREND = 56;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC1_WREND_LEN = 8;
// pau/reg00007.H

static const uint64_t CS_SM1_SNP_MISC_INHIBIT_CONFIG = 0x100108afull;

static const uint32_t CS_SM1_SNP_MISC_INHIBIT_CONFIG_0 = 0;
static const uint32_t CS_SM1_SNP_MISC_INHIBIT_CONFIG_0_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_INHIBIT_CONFIG_1 = 8;
static const uint32_t CS_SM1_SNP_MISC_INHIBIT_CONFIG_1_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_INHIBIT_CONFIG_2 = 16;
static const uint32_t CS_SM1_SNP_MISC_INHIBIT_CONFIG_2_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_INHIBIT_CONFIG_3 = 24;
static const uint32_t CS_SM1_SNP_MISC_INHIBIT_CONFIG_3_LEN = 8;
// pau/reg00007.H

static const uint64_t CS_SM2_MCP_MISC_CERR_FIRST1 = 0x100108d0ull;

static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_NLGX_0 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_NLGX_1 = 1;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_NLGX_2 = 2;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_NLGX_3 = 3;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_FWD_0 = 4;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_FWD_1 = 5;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_FWD_2 = 6;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_FWD_3 = 7;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_AUE_0 = 8;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_AUE_1 = 9;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_AUE_2 = 10;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_AUE_3 = 11;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_AUE_4 = 12;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_AUE_5 = 13;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_AUE_6 = 14;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_AUE_7 = 15;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_0 = 16;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_1 = 17;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_2 = 18;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_3 = 19;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_4 = 20;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_5 = 21;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_6 = 22;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_7 = 23;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_8 = 24;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_9 = 25;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_10 = 26;
static const uint32_t CS_SM2_MCP_MISC_CERR_FIRST1_PBF_11 = 27;
// pau/reg00007.H

static const uint64_t CS_SM2_MCP_MISC_CERR_MESSAGE0 = 0x100108c6ull;

static const uint32_t CS_SM2_MCP_MISC_CERR_MESSAGE0_CERR_MESSAGE_BITS0 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_MESSAGE0_CERR_MESSAGE_BITS0_LEN = 64;
// pau/reg00007.H

static const uint64_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2 = 0x10010908ull;

static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_W = 0;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_W_HP = 1;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_INJ = 2;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_PR_DMA_INJ = 3;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_DMA_PR_W = 4;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_RD_NC_F0 = 5;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMAX_U = 6;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMAX_S = 7;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMIN_U = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMIN_S = 9;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_ADD = 10;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_AND = 11;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_OR = 12;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_XOR = 13;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMAX_U = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMAX_S = 15;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMIN_U = 16;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMIN_S = 17;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_ADD = 18;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_AND = 19;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_OR = 20;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_XOR = 21;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_E = 22;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_U = 23;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_T = 24;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_NE = 25;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_INC_B = 26;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_INC_E = 27;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_DEC_B = 28;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_RESERVED1 = 29;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_RESERVED1_LEN = 3;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_WRENA = 32;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_RDENA = 33;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_AWENA = 34;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_ARENA = 35;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_WRENA = 36;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_RDENA = 37;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_AWENA = 38;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_ARENA = 39;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_WRENA = 40;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_RDENA = 41;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_AWENA = 42;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_ARENA = 43;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_WRENA = 44;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_RDENA = 45;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_AWENA = 46;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_ARENA = 47;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_WRENA = 48;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_RDENA = 49;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_AWENA = 50;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_ARENA = 51;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_WRENA = 52;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_RDENA = 53;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_AWENA = 54;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_ARENA = 55;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_WRENA = 56;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_RDENA = 57;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_AWENA = 58;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_ARENA = 59;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_WRENA = 60;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_RDENA = 61;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_AWENA = 62;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_ARENA = 63;
// pau/reg00007.H

static const uint64_t CS_SM3_MCP_MISC_CERR_FIRST1 = 0x10010930ull;

static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_NLGX_0 = 0;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_NLGX_1 = 1;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_NLGX_2 = 2;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_NLGX_3 = 3;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_FWD_0 = 4;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_FWD_1 = 5;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_FWD_2 = 6;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_FWD_3 = 7;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_AUE_0 = 8;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_AUE_1 = 9;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_AUE_2 = 10;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_AUE_3 = 11;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_AUE_4 = 12;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_AUE_5 = 13;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_AUE_6 = 14;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_AUE_7 = 15;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_0 = 16;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_1 = 17;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_2 = 18;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_3 = 19;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_4 = 20;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_5 = 21;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_6 = 22;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_7 = 23;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_8 = 24;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_9 = 25;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_10 = 26;
static const uint32_t CS_SM3_MCP_MISC_CERR_FIRST1_PBF_11 = 27;
// pau/reg00007.H

static const uint64_t CS_SM3_MCP_MISC_CERR_HOLD0 = 0x10010935ull;

static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_0 = 0;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_1 = 1;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_2 = 2;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_3 = 3;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_4 = 4;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_5 = 5;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_6 = 6;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_7 = 7;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_8 = 8;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_9 = 9;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_10 = 10;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_11 = 11;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_12 = 12;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_13 = 13;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_14 = 14;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_15 = 15;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_16 = 16;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_17 = 17;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_18 = 18;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_NVF_19 = 19;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_ASBE_0 = 20;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_ASBE_1 = 21;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_ASBE_2 = 22;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_ASBE_3 = 23;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_ASBE_4 = 24;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_ASBE_5 = 25;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_ASBE_6 = 26;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_ASBE_7 = 27;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_PBR_0 = 28;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_PBR_1 = 29;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_PBR_2 = 30;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_PBR_3 = 31;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_REG_0 = 32;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_REG_1 = 33;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_REG_2 = 34;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_REG_3 = 35;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_0 = 36;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_1 = 37;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_2 = 38;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_3 = 39;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_4 = 40;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_5 = 41;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_6 = 42;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_7 = 43;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_8 = 44;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_9 = 45;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_10 = 46;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_11 = 47;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_12 = 48;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_13 = 49;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_14 = 50;
static const uint32_t CS_SM3_MCP_MISC_CERR_HOLD0_OCR_15 = 51;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1 = 0x1001095full;

static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_TAG = 0;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_TAG_LEN = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_TAGMASK = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_TAGMASK_LEN = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_PAU = 28;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_PCIE = 29;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_L2L3 = 30;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_RESERVED1 = 31;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_RDSTART = 32;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_RDSTART_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_RDEND = 40;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_RDEND_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_WRSTART = 48;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_WRSTART_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_WREND = 56;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC1_WREND_LEN = 8;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_GPU0_BAR = 0x10010952ull;

static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_SL_MODE = 36;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_4T_SELECT = 38;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_MODE = 40;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_MODE_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_GRANULE = 44;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_POISON = 45;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_M2MODE = 46;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_RESERVED = 50;
static const uint32_t CS_SM3_SNP_MISC_GPU0_BAR_RESERVED_LEN = 2;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_GPU1_BAR = 0x10010953ull;

static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_SL_MODE = 36;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_4T_SELECT = 38;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_MODE = 40;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_MODE_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_GRANULE = 44;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_POISON = 45;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_M2MODE = 46;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_RESERVED = 50;
static const uint32_t CS_SM3_SNP_MISC_GPU1_BAR_RESERVED_LEN = 2;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_GPU2_BAR = 0x10010954ull;

static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_SL_MODE = 36;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_4T_SELECT = 38;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_MODE = 40;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_MODE_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_GRANULE = 44;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_POISON = 45;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_M2MODE = 46;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_RESERVED = 50;
static const uint32_t CS_SM3_SNP_MISC_GPU2_BAR_RESERVED_LEN = 2;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_GPU3_BAR = 0x10010955ull;

static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_SL_MODE = 36;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_4T_SELECT = 38;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_MODE = 40;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_MODE_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_GRANULE = 44;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_POISON = 45;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_M2MODE = 46;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_RESERVED = 50;
static const uint32_t CS_SM3_SNP_MISC_GPU3_BAR_RESERVED_LEN = 2;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_GPU4_BAR = 0x10010956ull;

static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_SL_MODE = 36;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_4T_SELECT = 38;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_MODE = 40;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_MODE_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_GRANULE = 44;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_POISON = 45;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_M2MODE = 46;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_RESERVED = 50;
static const uint32_t CS_SM3_SNP_MISC_GPU4_BAR_RESERVED_LEN = 2;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2 = 0x1001097eull;

static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_ABLE_16_23 = 0;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_ABLE_16_23_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY16 = 8;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY16_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY17 = 12;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY17_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY18 = 16;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY18_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY19 = 20;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY19_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY20 = 24;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY20_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY21 = 28;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY21_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY22 = 32;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY22_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY23 = 36;
static const uint32_t CS_SM3_SNP_MISC_TOPOLOGY_TABLE2_TRY23_LEN = 4;
// pau/reg00007.H

static const uint64_t FIR_ACTION0_REG_1 = 0x10010c46ull;

static const uint32_t FIR_ACTION0_REG_1_FIR_ACTION0_1 = 0;
static const uint32_t FIR_ACTION0_REG_1_FIR_ACTION0_1_LEN = 62;
// pau/reg00007.H

static const uint64_t MISC_FREEZE_STATE = 0x10010b45ull;

static const uint32_t MISC_FREEZE_STATE_0 = 0;
static const uint32_t MISC_FREEZE_STATE_1 = 1;
static const uint32_t MISC_FREEZE_STATE_2 = 2;
static const uint32_t MISC_FREEZE_STATE_3 = 3;
static const uint32_t MISC_FREEZE_STATE_4 = 4;
static const uint32_t MISC_FREEZE_STATE_5 = 5;
static const uint32_t MISC_FREEZE_STATE_6 = 6;
static const uint32_t MISC_FREEZE_STATE_7 = 7;
static const uint32_t MISC_FREEZE_STATE_8 = 8;
static const uint32_t MISC_FREEZE_STATE_9 = 9;
static const uint32_t MISC_FREEZE_STATE_10 = 10;
static const uint32_t MISC_FREEZE_STATE_11 = 11;
static const uint32_t MISC_FREEZE_STATE_12 = 12;
static const uint32_t MISC_FREEZE_STATE_13 = 13;
static const uint32_t MISC_FREEZE_STATE_14 = 14;
static const uint32_t MISC_FREEZE_STATE_15 = 15;
// pau/reg00007.H

static const uint64_t MISC_REGS_BDF2PE_5_CONFIG = 0x10010b55ull;

static const uint32_t MISC_REGS_BDF2PE_5_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_5_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_5_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_5_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_5_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_5_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_5_CONFIG_BDF_LEN = 16;
// pau/reg00007.H

static const uint64_t MISC_REGS_INT_LOG_0_PE10 = 0x10010b9aull;

static const uint32_t MISC_REGS_INT_LOG_0_PE10_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE10_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE10_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE10_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE10_RSVD0_LEN = 3;
// pau/reg00007.H

static const uint64_t MISC_REGS_INT_LOG_0_PE2 = 0x10010b92ull;

static const uint32_t MISC_REGS_INT_LOG_0_PE2_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE2_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE2_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE2_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE2_RSVD0_LEN = 3;
// pau/reg00007.H

static const uint64_t MISC_REGS_INT_LOG_1_PE2 = 0x10010ba2ull;

static const uint32_t MISC_REGS_INT_LOG_1_PE2_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE2_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE2_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE2_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE2_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE2_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE2_RSVD0_LEN = 7;
// pau/reg00007.H

static const uint64_t MISC_REGS_MASK = 0x10010b35ull;

static const uint32_t MISC_REGS_MASK_IDIAL_MISC_MASK = 0;
static const uint32_t MISC_REGS_MASK_IDIAL_MISC_MASK_LEN = 15;
// pau/reg00007.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE2 = 0x10010b82ull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE2_DMA_STOPPED_STATE_ADDR_PE2 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE2_DMA_STOPPED_STATE_ADDR_PE2_LEN = 37;
// pau/reg00007.H

static const uint64_t MISC_REGS_PESTB_DATA_PE1 = 0x10010b71ull;

static const uint32_t MISC_REGS_PESTB_DATA_PE1_DMA_STOPPED_STATE_PE1 = 0;
// pau/reg00007.H

static const uint64_t NTL0_REGS_CERR_HOLD1 = 0x100109e2ull;

static const uint32_t NTL0_REGS_CERR_HOLD1_0 = 0;
static const uint32_t NTL0_REGS_CERR_HOLD1_1 = 1;
static const uint32_t NTL0_REGS_CERR_HOLD1_2 = 2;
static const uint32_t NTL0_REGS_CERR_HOLD1_3 = 3;
static const uint32_t NTL0_REGS_CERR_HOLD1_4 = 4;
static const uint32_t NTL0_REGS_CERR_HOLD1_5 = 5;
static const uint32_t NTL0_REGS_CERR_HOLD1_6 = 6;
static const uint32_t NTL0_REGS_CERR_HOLD1_7 = 7;
static const uint32_t NTL0_REGS_CERR_HOLD1_8 = 8;
static const uint32_t NTL0_REGS_CERR_HOLD1_9 = 9;
static const uint32_t NTL0_REGS_CERR_HOLD1_10 = 10;
static const uint32_t NTL0_REGS_CERR_HOLD1_11 = 11;
static const uint32_t NTL0_REGS_CERR_HOLD1_12 = 12;
static const uint32_t NTL0_REGS_CERR_HOLD1_13 = 13;
static const uint32_t NTL0_REGS_CERR_HOLD1_14 = 14;
static const uint32_t NTL0_REGS_CERR_HOLD1_15 = 15;
static const uint32_t NTL0_REGS_CERR_HOLD1_16 = 16;
static const uint32_t NTL0_REGS_CERR_HOLD1_17 = 17;
static const uint32_t NTL0_REGS_CERR_HOLD1_18 = 18;
static const uint32_t NTL0_REGS_CERR_HOLD1_19 = 19;
static const uint32_t NTL0_REGS_CERR_HOLD1_20 = 20;
static const uint32_t NTL0_REGS_CERR_HOLD1_21 = 21;
static const uint32_t NTL0_REGS_CERR_HOLD1_22 = 22;
static const uint32_t NTL0_REGS_CERR_HOLD1_23 = 23;
static const uint32_t NTL0_REGS_CERR_HOLD1_24 = 24;
static const uint32_t NTL0_REGS_CERR_HOLD1_25 = 25;
static const uint32_t NTL0_REGS_CERR_HOLD1_26 = 26;
static const uint32_t NTL0_REGS_CERR_HOLD1_27 = 27;
static const uint32_t NTL0_REGS_CERR_HOLD1_28 = 28;
static const uint32_t NTL0_REGS_CERR_HOLD1_29 = 29;
static const uint32_t NTL0_REGS_CERR_HOLD1_30 = 30;
static const uint32_t NTL0_REGS_CERR_HOLD1_31 = 31;
static const uint32_t NTL0_REGS_CERR_HOLD1_32 = 32;
static const uint32_t NTL0_REGS_CERR_HOLD1_33 = 33;
static const uint32_t NTL0_REGS_CERR_HOLD1_34 = 34;
static const uint32_t NTL0_REGS_CERR_HOLD1_35 = 35;
static const uint32_t NTL0_REGS_CERR_HOLD1_36 = 36;
static const uint32_t NTL0_REGS_CERR_HOLD1_37 = 37;
static const uint32_t NTL0_REGS_CERR_HOLD1_38 = 38;
static const uint32_t NTL0_REGS_CERR_HOLD1_39 = 39;
static const uint32_t NTL0_REGS_CERR_HOLD1_40 = 40;
static const uint32_t NTL0_REGS_CERR_HOLD1_41 = 41;
static const uint32_t NTL0_REGS_CERR_HOLD1_42 = 42;
static const uint32_t NTL0_REGS_CERR_HOLD1_43 = 43;
static const uint32_t NTL0_REGS_CERR_HOLD1_44 = 44;
static const uint32_t NTL0_REGS_CERR_HOLD1_45 = 45;
static const uint32_t NTL0_REGS_CERR_HOLD1_46 = 46;
static const uint32_t NTL0_REGS_CERR_HOLD1_47 = 47;
static const uint32_t NTL0_REGS_CERR_HOLD1_48 = 48;
static const uint32_t NTL0_REGS_CERR_HOLD1_49 = 49;
static const uint32_t NTL0_REGS_CERR_HOLD1_50 = 50;
static const uint32_t NTL0_REGS_CERR_HOLD1_51 = 51;
static const uint32_t NTL0_REGS_CERR_HOLD1_52 = 52;
static const uint32_t NTL0_REGS_CERR_HOLD1_53 = 53;
static const uint32_t NTL0_REGS_CERR_HOLD1_54 = 54;
static const uint32_t NTL0_REGS_CERR_HOLD1_55 = 55;
static const uint32_t NTL0_REGS_CERR_HOLD1_56 = 56;
static const uint32_t NTL0_REGS_CERR_HOLD1_57 = 57;
static const uint32_t NTL0_REGS_CERR_HOLD1_58 = 58;
static const uint32_t NTL0_REGS_CERR_HOLD1_59 = 59;
static const uint32_t NTL0_REGS_CERR_HOLD1_60 = 60;
static const uint32_t NTL0_REGS_CERR_HOLD1_61 = 61;
static const uint32_t NTL0_REGS_CERR_HOLD1_62 = 62;
static const uint32_t NTL0_REGS_CERR_HOLD1_63 = 63;
// pau/reg00007.H

static const uint64_t NTL0_REGS_SCRATCH3 = 0x100109ebull;

static const uint32_t NTL0_REGS_SCRATCH3_IDIAL_SCRATCH3 = 0;
static const uint32_t NTL0_REGS_SCRATCH3_IDIAL_SCRATCH3_LEN = 64;
// pau/reg00007.H

static const uint64_t OTL0_MISC_PMU_CONTROL2 = 0x10010a24ull;

static const uint32_t OTL0_MISC_PMU_CONTROL2_C01_DCMASKA = 0;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C01_DCMASKA_LEN = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C01_DCMASKB = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C01_DCMASKB_LEN = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C23_DCMASKA = 16;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C23_DCMASKA_LEN = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C23_DCMASKB = 24;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C23_DCMASKB_LEN = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C01_DCMASKDLA = 32;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C01_DCMASKDLA_LEN = 2;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C01_DCMASKDLB = 34;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C01_DCMASKDLB_LEN = 2;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C23_DCMASKDLA = 36;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C23_DCMASKDLA_LEN = 2;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C23_DCMASKDLB = 38;
static const uint32_t OTL0_MISC_PMU_CONTROL2_C23_DCMASKDLB_LEN = 2;
static const uint32_t OTL0_MISC_PMU_CONTROL2_DCMASK_LATENCY = 40;
static const uint32_t OTL0_MISC_PMU_CONTROL2_DCMASK_LATENCY_LEN = 8;
static const uint32_t OTL0_MISC_PMU_CONTROL2_RESERVED2 = 48;
static const uint32_t OTL0_MISC_PMU_CONTROL2_RESERVED2_LEN = 16;
// pau/reg00007.H

static const uint64_t XTS_ATSD_HYP12 = 0x10010b1cull;

static const uint32_t XTS_ATSD_HYP12_MSRHV = 51;
static const uint32_t XTS_ATSD_HYP12_LPARID = 52;
static const uint32_t XTS_ATSD_HYP12_LPARID_LEN = 12;
// pau/reg00007.H

static const uint64_t XTS_ATSD_HYP8 = 0x10010b18ull;

static const uint32_t XTS_ATSD_HYP8_MSRHV = 51;
static const uint32_t XTS_ATSD_HYP8_LPARID = 52;
static const uint32_t XTS_ATSD_HYP8_LPARID_LEN = 12;
// pau/reg00007.H

}
}
#include "pau/reg00007.H"
#endif
