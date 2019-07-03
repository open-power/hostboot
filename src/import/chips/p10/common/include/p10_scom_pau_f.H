/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_f.H $        */
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


static const uint64_t AME_AME0_MISC_AMM_CONFIG1 = 0x10010bc1ull;

static const uint32_t AME_AME0_MISC_AMM_CONFIG1_1_RESERVED = 32;
static const uint32_t AME_AME0_MISC_AMM_CONFIG1_1_RESERVED_LEN = 19;
static const uint32_t AME_AME0_MISC_AMM_CONFIG1__MRQ_WD_CRD = 51;
static const uint32_t AME_AME0_MISC_AMM_CONFIG1__MRQ_WD_CRD_LEN = 3;
static const uint32_t AME_AME0_MISC_AMM_CONFIG1__MRQ_SD_CRD = 54;
static const uint32_t AME_AME0_MISC_AMM_CONFIG1__MRQ_SD_CRD_LEN = 3;
static const uint32_t AME_AME0_MISC_AMM_CONFIG1__MRQ_ACT_TIMER = 57;
static const uint32_t AME_AME0_MISC_AMM_CONFIG1__MRQ_VC2_CRD_SMR = 58;
static const uint32_t AME_AME0_MISC_AMM_CONFIG1__MRQ_SMR_MAX = 59;
static const uint32_t AME_AME0_MISC_AMM_CONFIG1__MRQ_SMR_MAX_LEN = 5;
// pau/reg00021.H

static const uint64_t AME_AME1_MISC_ECC_CONFIG = 0x10010bd2ull;

static const uint32_t AME_AME1_MISC_ECC_CONFIG_ERAT_RA_COREN = 0;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_ERAT_RA_ERRINJ = 1;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_ERAT_RA_ERRINJ_LEN = 8;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_ERAT_PE_COREN = 9;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_ERAT_PE_ERRINJ = 10;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_ERAT_PE_ERRINJ_LEN = 2;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_MRQ_XCT_COREN = 12;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_MRQ_XCT_ERRINJ = 13;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_MRQ_XCT_ERRINJ_LEN = 4;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL0_WB_COREN = 17;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL0_WB_ERRINJ = 18;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL0_WB_ERRINJ_LEN = 16;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL0_CBA_COREN = 34;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL0_CBA_ERRINJ = 35;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL0_CBA_ERRINJ_LEN = 2;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL0_PCT_COREN = 37;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL0_PCT_ERRINJ = 38;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL0_PCT_ERRINJ_LEN = 2;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL1_WB_COREN = 40;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL1_WB_ERRINJ = 41;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL1_WB_ERRINJ_LEN = 16;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL1_CBA_COREN = 57;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL1_CBA_ERRINJ = 58;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL1_CBA_ERRINJ_LEN = 2;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL1_PCT_COREN = 60;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL1_PCT_ERRINJ = 61;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_CL1_PCT_ERRINJ_LEN = 2;
static const uint32_t AME_AME1_MISC_ECC_CONFIG_ECC_SPARE = 63;
// pau/reg00021.H

static const uint64_t AME_AME1_MISC_TEST_CERR_RPT = 0x10010bdbull;

static const uint32_t AME_AME1_MISC_TEST_CERR_RPT_TEST_CERR_BITSEL = 59;
static const uint32_t AME_AME1_MISC_TEST_CERR_RPT_TEST_CERR_BITSEL_LEN = 5;
// pau/reg00021.H

static const uint64_t AME_ATL_MISC_PMU_COUNT = 0x10010bfcull;

static const uint32_t AME_ATL_MISC_PMU_COUNT_0 = 0;
static const uint32_t AME_ATL_MISC_PMU_COUNT_0_LEN = 16;
static const uint32_t AME_ATL_MISC_PMU_COUNT_1 = 16;
static const uint32_t AME_ATL_MISC_PMU_COUNT_1_LEN = 16;
static const uint32_t AME_ATL_MISC_PMU_COUNT_2 = 32;
static const uint32_t AME_ATL_MISC_PMU_COUNT_2_LEN = 16;
static const uint32_t AME_ATL_MISC_PMU_COUNT_3 = 48;
static const uint32_t AME_ATL_MISC_PMU_COUNT_3_LEN = 16;
// pau/reg00021.H

static const uint64_t CS_CTL_MISC_BDF2PE_2_CONFIG = 0x100109b2ull;

static const uint32_t CS_CTL_MISC_BDF2PE_2_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_2_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_2_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_2_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_2_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_2_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_2_CONFIG_BDF_LEN = 16;
// pau/reg00021.H

static const uint64_t CS_CTL_MISC_PERF_MASK_CONFIG = 0x10010985ull;

static const uint32_t CS_CTL_MISC_PERF_MASK_CONFIG_TTYPE = 0;
static const uint32_t CS_CTL_MISC_PERF_MASK_CONFIG_TTYPE_LEN = 12;
static const uint32_t CS_CTL_MISC_PERF_MASK_CONFIG_TSIZE = 12;
static const uint32_t CS_CTL_MISC_PERF_MASK_CONFIG_TSIZE_LEN = 8;
static const uint32_t CS_CTL_MISC_PERF_MASK_CONFIG_PE = 20;
static const uint32_t CS_CTL_MISC_PERF_MASK_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_PERF_MASK_CONFIG_BE = 24;
static const uint32_t CS_CTL_MISC_PERF_MASK_CONFIG_RESERVED = 25;
static const uint32_t CS_CTL_MISC_PERF_MASK_CONFIG_RESERVED_LEN = 3;
// pau/reg00021.H

static const uint64_t CS_CTL_MISC_SCOPE_PREDICT0 = 0x100109abull;

static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_LN_FAIL_THRESH = 0;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_LN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_NN_FAIL_THRESH = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_NN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_RN_FAIL_THRESH = 6;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_RN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_G_FAIL_THRESH = 9;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_G_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_LN_INTV_THRESH = 12;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_LN_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_G_INTV_THRESH = 15;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_G_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0RD_VG_ENABLE = 18;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0_0_RESERVED1 = 19;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_LN_FAIL_THRESH = 20;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_LN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_NN_FAIL_THRESH = 23;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_NN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_RN_FAIL_THRESH = 26;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_RN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_G_FAIL_THRESH = 29;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_G_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_LN_INTV_THRESH = 32;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_LN_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_G_INTV_THRESH = 35;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_G_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__B0WR_VG_ENABLE = 38;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0_0_RESERVED2 = 39;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_LN_FAIL_THRESH = 40;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_LN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_NN_FAIL_THRESH = 43;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_NN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_RN_FAIL_THRESH = 46;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_RN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_G_FAIL_THRESH = 49;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_G_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_LN_INTV_THRESH = 52;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_LN_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_G_INTV_THRESH = 55;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_G_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0__OTH_VG_ENABLE = 58;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT0_0_RESERVED3 = 59;
// pau/reg00021.H

static const uint64_t CS_SM0_MCP_MISC_CERR_MESSAGE1 = 0x10010807ull;

static const uint32_t CS_SM0_MCP_MISC_CERR_MESSAGE1_CERR_MESSAGE_BITS1 = 0;
static const uint32_t CS_SM0_MCP_MISC_CERR_MESSAGE1_CERR_MESSAGE_BITS1_LEN = 64;
// pau/reg00021.H

static const uint64_t CS_SM0_MCP_MISC_DEBUG1_CONFIG = 0x1001081bull;

static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD0 = 0;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD1 = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD2 = 10;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD3 = 15;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD4 = 20;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD5 = 25;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD6 = 30;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD7 = 35;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD8 = 40;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD9 = 45;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD10 = 50;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM0_MCP_MISC_DEBUG1_CONFIG_ACT = 63;
// pau/reg00021.H

static const uint64_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG = 0x10010818ull;

static const uint32_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG_RESERVED2 = 0;
static const uint32_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG_RESERVED2_LEN = 24;
static const uint32_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG_CRESP = 24;
static const uint32_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG_CRESP_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG_SCOPE = 29;
static const uint32_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG_SCOPE_LEN = 3;
static const uint32_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG_MCMD = 32;
static const uint32_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG_MCMD_LEN = 10;
static const uint32_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG_RESERVED1 = 42;
static const uint32_t CS_SM0_MCP_MISC_PERF_MATCH_CONFIG_RESERVED1_LEN = 2;
// pau/reg00021.H

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
// pau/reg00021.H

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
// pau/reg00021.H

static const uint64_t CS_SM0_SNP_MISC_GPU2_BAR = 0x10010834ull;

static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_SL_MODE = 36;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_4T_SELECT = 38;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_MODE = 40;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_MODE_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_GRANULE = 44;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_POISON = 45;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_M2MODE = 46;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM0_SNP_MISC_GPU2_BAR_RESERVED = 51;
// pau/reg00021.H

static const uint64_t CS_SM0_SNP_MISC_GPU3_BAR = 0x10010835ull;

static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_SL_MODE = 36;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_4T_SELECT = 38;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_MODE = 40;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_MODE_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_GRANULE = 44;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_POISON = 45;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_M2MODE = 46;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM0_SNP_MISC_GPU3_BAR_RESERVED = 51;
// pau/reg00021.H

static const uint64_t CS_SM0_SNP_MISC_GPU4_BAR = 0x10010836ull;

static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_SL_MODE = 36;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_4T_SELECT = 38;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_MODE = 40;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_MODE_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_GRANULE = 44;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_POISON = 45;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_M2MODE = 46;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM0_SNP_MISC_GPU4_BAR_RESERVED = 51;
// pau/reg00021.H

static const uint64_t CS_SM0_SNP_MISC_MACHINE_ALLOC = 0x1001084dull;

static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_ENABLE_MACHINE_ALLOC = 0;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_ENABLE_EXCEED_HIGH = 1;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_MAX_MACHINES = 2;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_MAX_MACHINES_LEN = 6;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_HIGH_WATER_IDLE = 8;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_HIGH_WATER_IDLE_LEN = 6;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS1 = 14;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS1_LEN = 6;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_HIGH_MIN_SHARE = 20;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_HIGH_MIN_SHARE_LEN = 10;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS2 = 30;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS2_LEN = 10;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_MAX_HIGH_RESERVED = 40;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_MAX_HIGH_RESERVED_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL0 = 44;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL0_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL1 = 49;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL1_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL2 = 54;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL2_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL3 = 59;
static const uint32_t CS_SM0_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL3_LEN = 5;
// pau/reg00021.H

static const uint64_t CS_SM1_DIR_MISC_DEBUG1_CONFIG = 0x1001088bull;

static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD0 = 0;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD1 = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD2 = 10;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD3 = 15;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD4 = 20;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD5 = 25;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD6 = 30;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD7 = 35;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD8 = 40;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD9 = 45;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD10 = 50;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM1_DIR_MISC_DEBUG1_CONFIG_ACT = 63;
// pau/reg00021.H

static const uint64_t CS_SM1_MCP_MISC_CONFIG0 = 0x10010860ull;

static const uint32_t CS_SM1_MCP_MISC_CONFIG0__MA_DSA_OPT_CLAIM_UR = 0;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__MA_DSA_OPT_FLUSH_UR = 1;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__MA_DSA_OPT_RP_MODE = 2;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__ADR_BAR_MODE = 3;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__DISABLE_NN_RN = 4;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__DISABLE_VG_NOT_SYS = 5;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__DISABLE_G = 6;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__DISABLE_LN = 7;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__SKIP_G = 8;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__MA_MCRESP_OPT_WRP = 9;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__USE_CL_DMA_W = 10;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__USE_DMA_PR_W = 11;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__INC_PRI_MASK = 12;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__INC_PRI_MASK_LEN = 3;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__MACH_CORRENAB = 15;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__MACH_INJECT_ENABLE1 = 16;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__MACH_INJECT_ENABLE2 = 17;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__RXO_CORRENAB = 18;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__RXO_INJECT_ENABLE1 = 19;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__RXO_INJECT_ENABLE2 = 20;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__RSI_CORRENAB = 21;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__RSI_INJECT_ENABLE1 = 22;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__RSI_INJECT_ENABLE2 = 23;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__MA_DSA_OPT_DMA_UPG = 24;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__EVAPORATE_BY_LCO = 25;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__ENABLE_PBUS = 26;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__ENABLE_SNARF_CPM = 27;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__DISABLE_INJECT = 28;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__DCACHE_MODE = 29;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__DCACHE_REPORTS_PHYSICAL = 30;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__RSI_DISABLE_DATIN_FASTPATH = 31;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__FORBID_MMIO_READ_GT_32 = 32;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__FORBID_MMIO_ATOMIC = 33;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0_0_RESERVED1 = 34;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0_0_RESERVED1_LEN = 2;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__ENABLE_CONTEXT_LCO = 36;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__MA_DSA_OPT_FAIL_WAKE = 37;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__ENABLE_FAST_DIR_UPDATE = 38;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__OPT_MES_USE_GO_M = 39;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__OPT_LCO_M_USE_MU = 40;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__OPT_SNOOP_EX_LCO = 41;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__ENABLE_CP_ME = 42;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__FENCE_ON_DERR_MMIO = 43;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK0_OCAPI_MODE = 44;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK1_OCAPI_MODE = 45;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK2_OCAPI_MODE = 46;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK3_OCAPI_MODE = 47;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK4_OCAPI_MODE = 48;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK0_NVLINK_MODE = 49;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK1_NVLINK_MODE = 50;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK2_NVLINK_MODE = 51;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK3_NVLINK_MODE = 52;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK4_NVLINK_MODE = 53;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK0_POISON_FENCE_L2 = 54;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0__BRK1_POISON_FENCE_L2 = 55;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0_0_RESERVED0 = 56;
static const uint32_t CS_SM1_MCP_MISC_CONFIG0_0_RESERVED0_LEN = 8;
// pau/reg00021.H

static const uint64_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5 = 0x100108a3ull;

static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_TAG = 0;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_TAG_LEN = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_TAGMASK = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_TAGMASK_LEN = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_PAU = 28;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_PCIE = 29;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_L2L3 = 30;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_RESERVED1 = 31;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_RDSTART = 32;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_RDSTART_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_RDEND = 40;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_RDEND_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_WRSTART = 48;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_WRSTART_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_WREND = 56;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC5_WREND_LEN = 8;
// pau/reg00021.H

static const uint64_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3 = 0x100108bfull;

static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_ABLE_24_31 = 0;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_ABLE_24_31_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY24 = 8;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY24_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY25 = 12;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY25_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY26 = 16;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY26_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY27 = 20;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY27_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY28 = 24;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY28_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY29 = 28;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY29_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY30 = 32;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY30_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY31 = 36;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE3_TRY31_LEN = 4;
// pau/reg00021.H

static const uint64_t CS_SM2_MCP_MISC_CERR_MASK1 = 0x100108d3ull;

static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_NLGX_0 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_NLGX_1 = 1;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_NLGX_2 = 2;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_NLGX_3 = 3;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_FWD_0 = 4;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_FWD_1 = 5;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_FWD_2 = 6;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_FWD_3 = 7;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_AUE_0 = 8;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_AUE_1 = 9;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_AUE_2 = 10;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_AUE_3 = 11;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_AUE_4 = 12;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_AUE_5 = 13;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_AUE_6 = 14;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_AUE_7 = 15;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_0 = 16;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_1 = 17;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_2 = 18;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_3 = 19;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_4 = 20;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_5 = 21;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_6 = 22;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_7 = 23;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_8 = 24;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_9 = 25;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_10 = 26;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK1_PBF_11 = 27;
// pau/reg00021.H

static const uint64_t CS_SM2_MCP_MISC_CERR_MESSAGE4 = 0x100108caull;

static const uint32_t CS_SM2_MCP_MISC_CERR_MESSAGE4_CERR_MESSAGE_BITS4 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_MESSAGE4_CERR_MESSAGE_BITS4_LEN = 64;
// pau/reg00021.H

static const uint64_t CS_SM2_SNP_MISC_CERR_HOLD0 = 0x10010915ull;

static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NCF_0 = 0;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NCF_1 = 1;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NCF_2 = 2;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NCF_3 = 3;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NCF_4 = 4;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NCF_5 = 5;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NCF_6 = 6;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NCF_7 = 7;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBR_0 = 8;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBR_1 = 9;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBR_2 = 10;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBR_3 = 11;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBR_4 = 12;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBR_5 = 13;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBR_6 = 14;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBR_7 = 15;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBP_0 = 16;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBP_1 = 17;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBP_2 = 18;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBP_3 = 19;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBP_4 = 20;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBP_5 = 21;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBP_6 = 22;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBP_7 = 23;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_0 = 24;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_1 = 25;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_2 = 26;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_3 = 27;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_4 = 28;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_5 = 29;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_6 = 30;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_7 = 31;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_8 = 32;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_9 = 33;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_10 = 34;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_PBC_11 = 35;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_0 = 36;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_1 = 37;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_2 = 38;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_3 = 39;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_4 = 40;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_5 = 41;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_6 = 42;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_7 = 43;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_8 = 44;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_9 = 45;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_10 = 46;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_11 = 47;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_12 = 48;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_13 = 49;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_14 = 50;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_15 = 51;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_16 = 52;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_17 = 53;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_18 = 54;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_19 = 55;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_20 = 56;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_21 = 57;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_22 = 58;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_NLG_23 = 59;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_SMV_0 = 60;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_SMV_1 = 61;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_SMV_2 = 62;
static const uint32_t CS_SM2_SNP_MISC_CERR_HOLD0_SMV_3 = 63;
// pau/reg00021.H

static const uint64_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5 = 0x10010963ull;

static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_TAG = 0;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_TAG_LEN = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_TAGMASK = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_TAGMASK_LEN = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_PAU = 28;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_PCIE = 29;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_L2L3 = 30;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_RESERVED1 = 31;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_RDSTART = 32;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_RDSTART_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_RDEND = 40;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_RDEND_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_WRSTART = 48;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_WRSTART_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_WREND = 56;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC5_WREND_LEN = 8;
// pau/reg00021.H

static const uint64_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG = 0x10010977ull;

static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_ALLOC_CLASS = 0;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_ALLOC_CLASS_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_TTYPE = 5;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_TTYPE_LEN = 12;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_TSIZE = 17;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_TSIZE_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_NVBE = 25;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_UT = 26;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_ATYPE = 27;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_ATYPE_LEN = 7;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_ALLOC = 34;
static const uint32_t CS_SM3_SNP_MISC_PERF_MATCH_CONFIG_ALLOC_LEN = 6;
// pau/reg00021.H

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
static const uint32_t FIR_REG_0_CTL_SMF_INVALID_ACC = 27;
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
static const uint32_t FIR_REG_0_XTS_RSVD_7 = 47;
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
// pau/reg00021.H

static const uint64_t MISC_REGS_BDF2PE_2_CONFIG = 0x10010b52ull;

static const uint32_t MISC_REGS_BDF2PE_2_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_2_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_2_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_2_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_2_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_2_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_2_CONFIG_BDF_LEN = 16;
// pau/reg00021.H

static const uint64_t MISC_REGS_DA_ADDR = 0x10010b3eull;

static const uint32_t MISC_REGS_DA_ADDR_ADDR = 0;
static const uint32_t MISC_REGS_DA_ADDR_ADDR_LEN = 24;
static const uint32_t MISC_REGS_DA_ADDR_LEN = 24;
static const uint32_t MISC_REGS_DA_ADDR_LEN_LEN = 2;
static const uint32_t MISC_REGS_DA_ADDR_RSVD = 26;
static const uint32_t MISC_REGS_DA_ADDR_RSVD_LEN = 38;
// pau/reg00021.H

static const uint64_t MISC_REGS_INT_LOG_0_PE14 = 0x10010b9eull;

static const uint32_t MISC_REGS_INT_LOG_0_PE14_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE14_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE14_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE14_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE14_RSVD0_LEN = 3;
// pau/reg00021.H

static const uint64_t MISC_REGS_INT_LOG_0_PE6 = 0x10010b96ull;

static const uint32_t MISC_REGS_INT_LOG_0_PE6_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE6_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE6_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE6_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE6_RSVD0_LEN = 3;
// pau/reg00021.H

static const uint64_t MISC_REGS_INT_LOG_1_PE12 = 0x10010bacull;

static const uint32_t MISC_REGS_INT_LOG_1_PE12_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE12_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE12_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE12_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE12_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE12_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE12_RSVD0_LEN = 7;
// pau/reg00021.H

static const uint64_t MISC_REGS_INT_LOG_1_PE6 = 0x10010ba6ull;

static const uint32_t MISC_REGS_INT_LOG_1_PE6_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE6_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE6_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE6_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE6_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE6_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE6_RSVD0_LEN = 7;
// pau/reg00021.H

static const uint64_t MISC_REGS_CONFIG = 0x10010b36ull;

static const uint32_t MISC_REGS_CONFIG_CONFIG_SYNC_WAIT = 0;
static const uint32_t MISC_REGS_CONFIG_CONFIG_SYNC_WAIT_LEN = 5;
static const uint32_t MISC_REGS_CONFIG_PERF_CONFIG_ENABLE = 5;
static const uint32_t MISC_REGS_CONFIG_PERF_CONFIG_PE_MASK = 6;
static const uint32_t MISC_REGS_CONFIG_PERF_CONFIG_PE_MATCH = 7;
static const uint32_t MISC_REGS_CONFIG_PERF_CONFIG_PE_MATCH_LEN = 4;
static const uint32_t MISC_REGS_CONFIG_IPI_PS = 11;
static const uint32_t MISC_REGS_CONFIG_IPI_OS = 12;
static const uint32_t MISC_REGS_CONFIG_OC_ATS_SYNC_START = 13;
static const uint32_t MISC_REGS_CONFIG_CQ_RESP_VALID_ENABLE = 14;
static const uint32_t MISC_REGS_CONFIG_CONFIG_MISC_RSVD = 15;
static const uint32_t MISC_REGS_CONFIG_CONFIG_MISC_RSVD_LEN = 49;
// pau/reg00021.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE13 = 0x10010b8dull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE13_DMA_STOPPED_STATE_ADDR_PE13 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE13_DMA_STOPPED_STATE_ADDR_PE13_LEN = 37;
// pau/reg00021.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE6 = 0x10010b86ull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE6_DMA_STOPPED_STATE_ADDR_PE6 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE6_DMA_STOPPED_STATE_ADDR_PE6_LEN = 37;
// pau/reg00021.H

static const uint64_t MISC_REGS_PESTB_DATA_PE13 = 0x10010b7dull;

static const uint32_t MISC_REGS_PESTB_DATA_PE13_DMA_STOPPED_STATE_PE13 = 0;
// pau/reg00021.H

static const uint64_t MISC_REGS_PESTB_DATA_PE5 = 0x10010b75ull;

static const uint32_t MISC_REGS_PESTB_DATA_PE5_DMA_STOPPED_STATE_PE5 = 0;
// pau/reg00021.H

static const uint64_t NTL0_REGS_PERF_CONFIG = 0x100109eeull;

static const uint32_t NTL0_REGS_PERF_CONFIG_ENABLE = 0;
static const uint32_t NTL0_REGS_PERF_CONFIG_RESETMODE = 1;
static const uint32_t NTL0_REGS_PERF_CONFIG_FREEZEMODE = 2;
static const uint32_t NTL0_REGS_PERF_CONFIG_DISABLE_PMISC = 3;
static const uint32_t NTL0_REGS_PERF_CONFIG_PMISC_MODE = 4;
static const uint32_t NTL0_REGS_PERF_CONFIG_CASCADE = 5;
static const uint32_t NTL0_REGS_PERF_CONFIG_CASCADE_LEN = 3;
static const uint32_t NTL0_REGS_PERF_CONFIG_PRESCALE_C0 = 8;
static const uint32_t NTL0_REGS_PERF_CONFIG_PRESCALE_C0_LEN = 2;
static const uint32_t NTL0_REGS_PERF_CONFIG_PRESCALE_C1 = 10;
static const uint32_t NTL0_REGS_PERF_CONFIG_PRESCALE_C1_LEN = 2;
static const uint32_t NTL0_REGS_PERF_CONFIG_PRESCALE_C2 = 12;
static const uint32_t NTL0_REGS_PERF_CONFIG_PRESCALE_C2_LEN = 2;
static const uint32_t NTL0_REGS_PERF_CONFIG_PRESCALE_C3 = 14;
static const uint32_t NTL0_REGS_PERF_CONFIG_PRESCALE_C3_LEN = 2;
static const uint32_t NTL0_REGS_PERF_CONFIG_EVENT0 = 16;
static const uint32_t NTL0_REGS_PERF_CONFIG_EVENT0_LEN = 8;
static const uint32_t NTL0_REGS_PERF_CONFIG_EVENT1 = 24;
static const uint32_t NTL0_REGS_PERF_CONFIG_EVENT1_LEN = 8;
static const uint32_t NTL0_REGS_PERF_CONFIG_EVENT2 = 32;
static const uint32_t NTL0_REGS_PERF_CONFIG_EVENT2_LEN = 8;
static const uint32_t NTL0_REGS_PERF_CONFIG_EVENT3 = 40;
static const uint32_t NTL0_REGS_PERF_CONFIG_EVENT3_LEN = 8;
static const uint32_t NTL0_REGS_PERF_CONFIG_LATENCY = 48;
static const uint32_t NTL0_REGS_PERF_CONFIG_LATENCY_LEN = 3;
static const uint32_t NTL0_REGS_PERF_CONFIG_OPERATION_C0 = 51;
static const uint32_t NTL0_REGS_PERF_CONFIG_OPERATION_C0_LEN = 2;
static const uint32_t NTL0_REGS_PERF_CONFIG_OPERATION_C1 = 53;
static const uint32_t NTL0_REGS_PERF_CONFIG_OPERATION_C1_LEN = 2;
static const uint32_t NTL0_REGS_PERF_CONFIG_OPERATION_C2 = 55;
static const uint32_t NTL0_REGS_PERF_CONFIG_OPERATION_C2_LEN = 2;
static const uint32_t NTL0_REGS_PERF_CONFIG_OPERATION_C3 = 57;
static const uint32_t NTL0_REGS_PERF_CONFIG_OPERATION_C3_LEN = 2;
static const uint32_t NTL0_REGS_PERF_CONFIG_RESERVED = 59;
static const uint32_t NTL0_REGS_PERF_CONFIG_RESERVED_LEN = 5;
// pau/reg00021.H

static const uint64_t NTL0_REGS_PRI_CONFIG = 0x100109f6ull;

static const uint32_t NTL0_REGS_PRI_CONFIG_DISABLE = 0;
static const uint32_t NTL0_REGS_PRI_CONFIG_NDL = 1;
static const uint32_t NTL0_REGS_PRI_CONFIG_NDL_LEN = 2;
static const uint32_t NTL0_REGS_PRI_CONFIG_PHY = 3;
static const uint32_t NTL0_REGS_PRI_CONFIG_PHY_LEN = 2;
// pau/reg00021.H

static const uint64_t NTL1_REGS_CERR_FIRST1 = 0x10010a04ull;

static const uint32_t NTL1_REGS_CERR_FIRST1_0 = 0;
static const uint32_t NTL1_REGS_CERR_FIRST1_1 = 1;
static const uint32_t NTL1_REGS_CERR_FIRST1_2 = 2;
static const uint32_t NTL1_REGS_CERR_FIRST1_3 = 3;
static const uint32_t NTL1_REGS_CERR_FIRST1_4 = 4;
static const uint32_t NTL1_REGS_CERR_FIRST1_5 = 5;
static const uint32_t NTL1_REGS_CERR_FIRST1_6 = 6;
static const uint32_t NTL1_REGS_CERR_FIRST1_7 = 7;
static const uint32_t NTL1_REGS_CERR_FIRST1_8 = 8;
static const uint32_t NTL1_REGS_CERR_FIRST1_9 = 9;
static const uint32_t NTL1_REGS_CERR_FIRST1_10 = 10;
static const uint32_t NTL1_REGS_CERR_FIRST1_11 = 11;
static const uint32_t NTL1_REGS_CERR_FIRST1_12 = 12;
static const uint32_t NTL1_REGS_CERR_FIRST1_13 = 13;
static const uint32_t NTL1_REGS_CERR_FIRST1_14 = 14;
static const uint32_t NTL1_REGS_CERR_FIRST1_15 = 15;
static const uint32_t NTL1_REGS_CERR_FIRST1_16 = 16;
static const uint32_t NTL1_REGS_CERR_FIRST1_17 = 17;
static const uint32_t NTL1_REGS_CERR_FIRST1_18 = 18;
static const uint32_t NTL1_REGS_CERR_FIRST1_19 = 19;
static const uint32_t NTL1_REGS_CERR_FIRST1_20 = 20;
static const uint32_t NTL1_REGS_CERR_FIRST1_21 = 21;
static const uint32_t NTL1_REGS_CERR_FIRST1_22 = 22;
static const uint32_t NTL1_REGS_CERR_FIRST1_23 = 23;
static const uint32_t NTL1_REGS_CERR_FIRST1_24 = 24;
static const uint32_t NTL1_REGS_CERR_FIRST1_25 = 25;
static const uint32_t NTL1_REGS_CERR_FIRST1_26 = 26;
static const uint32_t NTL1_REGS_CERR_FIRST1_27 = 27;
static const uint32_t NTL1_REGS_CERR_FIRST1_28 = 28;
static const uint32_t NTL1_REGS_CERR_FIRST1_29 = 29;
static const uint32_t NTL1_REGS_CERR_FIRST1_30 = 30;
static const uint32_t NTL1_REGS_CERR_FIRST1_31 = 31;
static const uint32_t NTL1_REGS_CERR_FIRST1_32 = 32;
static const uint32_t NTL1_REGS_CERR_FIRST1_33 = 33;
static const uint32_t NTL1_REGS_CERR_FIRST1_34 = 34;
static const uint32_t NTL1_REGS_CERR_FIRST1_35 = 35;
static const uint32_t NTL1_REGS_CERR_FIRST1_36 = 36;
static const uint32_t NTL1_REGS_CERR_FIRST1_37 = 37;
static const uint32_t NTL1_REGS_CERR_FIRST1_38 = 38;
static const uint32_t NTL1_REGS_CERR_FIRST1_39 = 39;
static const uint32_t NTL1_REGS_CERR_FIRST1_40 = 40;
static const uint32_t NTL1_REGS_CERR_FIRST1_41 = 41;
static const uint32_t NTL1_REGS_CERR_FIRST1_42 = 42;
static const uint32_t NTL1_REGS_CERR_FIRST1_43 = 43;
static const uint32_t NTL1_REGS_CERR_FIRST1_44 = 44;
static const uint32_t NTL1_REGS_CERR_FIRST1_45 = 45;
static const uint32_t NTL1_REGS_CERR_FIRST1_46 = 46;
static const uint32_t NTL1_REGS_CERR_FIRST1_47 = 47;
static const uint32_t NTL1_REGS_CERR_FIRST1_48 = 48;
static const uint32_t NTL1_REGS_CERR_FIRST1_49 = 49;
static const uint32_t NTL1_REGS_CERR_FIRST1_50 = 50;
static const uint32_t NTL1_REGS_CERR_FIRST1_51 = 51;
static const uint32_t NTL1_REGS_CERR_FIRST1_52 = 52;
static const uint32_t NTL1_REGS_CERR_FIRST1_53 = 53;
static const uint32_t NTL1_REGS_CERR_FIRST1_54 = 54;
static const uint32_t NTL1_REGS_CERR_FIRST1_55 = 55;
static const uint32_t NTL1_REGS_CERR_FIRST1_56 = 56;
static const uint32_t NTL1_REGS_CERR_FIRST1_57 = 57;
static const uint32_t NTL1_REGS_CERR_FIRST1_58 = 58;
static const uint32_t NTL1_REGS_CERR_FIRST1_59 = 59;
static const uint32_t NTL1_REGS_CERR_FIRST1_60 = 60;
static const uint32_t NTL1_REGS_CERR_FIRST1_61 = 61;
static const uint32_t NTL1_REGS_CERR_FIRST1_62 = 62;
static const uint32_t NTL1_REGS_CERR_FIRST1_63 = 63;
// pau/reg00021.H

static const uint64_t NTL1_REGS_CERR_HOLD2 = 0x10010a06ull;

static const uint32_t NTL1_REGS_CERR_HOLD2_0 = 0;
static const uint32_t NTL1_REGS_CERR_HOLD2_1 = 1;
static const uint32_t NTL1_REGS_CERR_HOLD2_2 = 2;
static const uint32_t NTL1_REGS_CERR_HOLD2_3 = 3;
static const uint32_t NTL1_REGS_CERR_HOLD2_4 = 4;
static const uint32_t NTL1_REGS_CERR_HOLD2_5 = 5;
static const uint32_t NTL1_REGS_CERR_HOLD2_6 = 6;
static const uint32_t NTL1_REGS_CERR_HOLD2_7 = 7;
static const uint32_t NTL1_REGS_CERR_HOLD2_8 = 8;
static const uint32_t NTL1_REGS_CERR_HOLD2_9 = 9;
static const uint32_t NTL1_REGS_CERR_HOLD2_10 = 10;
static const uint32_t NTL1_REGS_CERR_HOLD2_11 = 11;
static const uint32_t NTL1_REGS_CERR_HOLD2_12 = 12;
static const uint32_t NTL1_REGS_CERR_HOLD2_13 = 13;
static const uint32_t NTL1_REGS_CERR_HOLD2_14 = 14;
static const uint32_t NTL1_REGS_CERR_HOLD2_15 = 15;
static const uint32_t NTL1_REGS_CERR_HOLD2_16 = 16;
static const uint32_t NTL1_REGS_CERR_HOLD2_17 = 17;
static const uint32_t NTL1_REGS_CERR_HOLD2_18 = 18;
static const uint32_t NTL1_REGS_CERR_HOLD2_19 = 19;
static const uint32_t NTL1_REGS_CERR_HOLD2_20 = 20;
static const uint32_t NTL1_REGS_CERR_HOLD2_21 = 21;
static const uint32_t NTL1_REGS_CERR_HOLD2_22 = 22;
static const uint32_t NTL1_REGS_CERR_HOLD2_23 = 23;
static const uint32_t NTL1_REGS_CERR_HOLD2_24 = 24;
static const uint32_t NTL1_REGS_CERR_HOLD2_25 = 25;
static const uint32_t NTL1_REGS_CERR_HOLD2_26 = 26;
static const uint32_t NTL1_REGS_CERR_HOLD2_27 = 27;
static const uint32_t NTL1_REGS_CERR_HOLD2_28 = 28;
static const uint32_t NTL1_REGS_CERR_HOLD2_29 = 29;
static const uint32_t NTL1_REGS_CERR_HOLD2_30 = 30;
static const uint32_t NTL1_REGS_CERR_HOLD2_31 = 31;
static const uint32_t NTL1_REGS_CERR_HOLD2_32 = 32;
static const uint32_t NTL1_REGS_CERR_HOLD2_33 = 33;
static const uint32_t NTL1_REGS_CERR_HOLD2_34 = 34;
static const uint32_t NTL1_REGS_CERR_HOLD2_35 = 35;
static const uint32_t NTL1_REGS_CERR_HOLD2_36 = 36;
static const uint32_t NTL1_REGS_CERR_HOLD2_37 = 37;
static const uint32_t NTL1_REGS_CERR_HOLD2_38 = 38;
static const uint32_t NTL1_REGS_CERR_HOLD2_39 = 39;
static const uint32_t NTL1_REGS_CERR_HOLD2_40 = 40;
static const uint32_t NTL1_REGS_CERR_HOLD2_41 = 41;
static const uint32_t NTL1_REGS_CERR_HOLD2_42 = 42;
static const uint32_t NTL1_REGS_CERR_HOLD2_43 = 43;
static const uint32_t NTL1_REGS_CERR_HOLD2_44 = 44;
static const uint32_t NTL1_REGS_CERR_HOLD2_45 = 45;
static const uint32_t NTL1_REGS_CERR_HOLD2_46 = 46;
static const uint32_t NTL1_REGS_CERR_HOLD2_47 = 47;
static const uint32_t NTL1_REGS_CERR_HOLD2_48 = 48;
static const uint32_t NTL1_REGS_CERR_HOLD2_49 = 49;
static const uint32_t NTL1_REGS_CERR_HOLD2_50 = 50;
static const uint32_t NTL1_REGS_CERR_HOLD2_51 = 51;
static const uint32_t NTL1_REGS_CERR_HOLD2_52 = 52;
static const uint32_t NTL1_REGS_CERR_HOLD2_53 = 53;
static const uint32_t NTL1_REGS_CERR_HOLD2_54 = 54;
static const uint32_t NTL1_REGS_CERR_HOLD2_55 = 55;
static const uint32_t NTL1_REGS_CERR_HOLD2_56 = 56;
static const uint32_t NTL1_REGS_CERR_HOLD2_57 = 57;
static const uint32_t NTL1_REGS_CERR_HOLD2_58 = 58;
static const uint32_t NTL1_REGS_CERR_HOLD2_59 = 59;
static const uint32_t NTL1_REGS_CERR_HOLD2_60 = 60;
static const uint32_t NTL1_REGS_CERR_HOLD2_61 = 61;
static const uint32_t NTL1_REGS_CERR_HOLD2_62 = 62;
static const uint32_t NTL1_REGS_CERR_HOLD2_63 = 63;
// pau/reg00021.H

static const uint64_t NTL1_REGS_PERF_CONFIG2 = 0x10010a17ull;

static const uint32_t NTL1_REGS_PERF_CONFIG2_EVENT4 = 0;
static const uint32_t NTL1_REGS_PERF_CONFIG2_EVENT4_LEN = 8;
static const uint32_t NTL1_REGS_PERF_CONFIG2_EVENT5 = 8;
static const uint32_t NTL1_REGS_PERF_CONFIG2_EVENT5_LEN = 8;
static const uint32_t NTL1_REGS_PERF_CONFIG2_EVENT6 = 16;
static const uint32_t NTL1_REGS_PERF_CONFIG2_EVENT6_LEN = 8;
static const uint32_t NTL1_REGS_PERF_CONFIG2_EVENT7 = 24;
static const uint32_t NTL1_REGS_PERF_CONFIG2_EVENT7_LEN = 8;
static const uint32_t NTL1_REGS_PERF_CONFIG2_RESERVED = 32;
static const uint32_t NTL1_REGS_PERF_CONFIG2_RESERVED_LEN = 32;
// pau/reg00021.H

static const uint64_t NTL1_REGS_RSP_HA_PTR = 0x10010a13ull;

static const uint32_t NTL1_REGS_RSP_HA_PTR_RESERVED1 = 0;
static const uint32_t NTL1_REGS_RSP_HA_PTR_RESERVED1_LEN = 5;
static const uint32_t NTL1_REGS_RSP_HA_PTR_START = 5;
static const uint32_t NTL1_REGS_RSP_HA_PTR_START_LEN = 7;
static const uint32_t NTL1_REGS_RSP_HA_PTR_RESERVED2 = 12;
static const uint32_t NTL1_REGS_RSP_HA_PTR_RESERVED2_LEN = 5;
static const uint32_t NTL1_REGS_RSP_HA_PTR_END = 17;
static const uint32_t NTL1_REGS_RSP_HA_PTR_END_LEN = 7;
// pau/reg00021.H

static const uint64_t OTL0_MISC_CHKSW0 = 0x10010a21ull;

static const uint32_t OTL0_MISC_CHKSW0_INHIBIT_EN = 0;
static const uint32_t OTL0_MISC_CHKSW0_INHIBIT_PACE_ENABLE_CMD = 1;
static const uint32_t OTL0_MISC_CHKSW0_INHIBIT_PACE_ENABLE_CMD_LEN = 3;
static const uint32_t OTL0_MISC_CHKSW0_INHIBIT_PACE_DISABLE_CMD = 4;
static const uint32_t OTL0_MISC_CHKSW0_INHIBIT_PACE_DISABLE_CMD_LEN = 3;
static const uint32_t OTL0_MISC_CHKSW0_INHIBIT_PACE_ENABLE_RESP = 7;
static const uint32_t OTL0_MISC_CHKSW0_INHIBIT_PACE_ENABLE_RESP_LEN = 3;
static const uint32_t OTL0_MISC_CHKSW0_INHIBIT_PACE_DISABLE_RESP = 10;
static const uint32_t OTL0_MISC_CHKSW0_INHIBIT_PACE_DISABLE_RESP_LEN = 3;
static const uint32_t OTL0_MISC_CHKSW0_OTL_RXO_SNGLTHRD_XSL_OPS = 13;
static const uint32_t OTL0_MISC_CHKSW0_OTL_RXO_DIS_EARLY_READ = 14;
static const uint32_t OTL0_MISC_CHKSW0_OTL_RXO_HW407209_DISABLE = 15;
static const uint32_t OTL0_MISC_CHKSW0_OTL_RXO_HW407443_DISABLE = 16;
static const uint32_t OTL0_MISC_CHKSW0_OTL_RXO_CONVERT_DOTN_TO_NORMAL = 17;
static const uint32_t OTL0_MISC_CHKSW0_OTL_CHKSW00 = 18;
static const uint32_t OTL0_MISC_CHKSW0_OTL_CHKSW00_LEN = 14;
static const uint32_t OTL0_MISC_CHKSW0_OTL_CHKSW01 = 32;
static const uint32_t OTL0_MISC_CHKSW0_OTL_CHKSW01_LEN = 32;
// pau/reg00021.H

static const uint64_t OTL0_MISC_CONFIG_TX2 = 0x10010a38ull;

static const uint32_t OTL0_MISC_CONFIG_TX2_TX_SEND_EN = 0;
static const uint32_t OTL0_MISC_CONFIG_TX2_TX_SPARE4 = 1;
static const uint32_t OTL0_MISC_CONFIG_TX2_TX_SPARE4_LEN = 3;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC1_THRESH1 = 4;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC1_THRESH1_LEN = 4;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC2_THRESH1 = 8;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC2_THRESH1_LEN = 4;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC3_THRESH1 = 12;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC3_THRESH1_LEN = 4;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC1_THRESH2 = 16;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC1_THRESH2_LEN = 4;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC2_THRESH2 = 20;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC2_THRESH2_LEN = 4;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC3_THRESH2 = 24;
static const uint32_t OTL0_MISC_CONFIG_TX2_VC3_THRESH2_LEN = 4;
// pau/reg00021.H

static const uint64_t OTL1_MISC_PSL_DAR_AN = 0x10010a79ull;

static const uint32_t OTL1_MISC_PSL_DAR_AN_CO_EA = 0;
static const uint32_t OTL1_MISC_PSL_DAR_AN_CO_EA_LEN = 52;
// pau/reg00021.H

static const uint64_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_EPOCH_CTL = 0x10010a93ull;

static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_EPOCH_CTL_CNT_DIAL = 0;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_EPOCH_CTL_CNT_DIAL_LEN = 32;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_EPOCH_CTL_TO_DIAL = 33;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_EPOCH_CTL_TO_DIAL_LEN = 3;
// pau/reg00021.H

static const uint64_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1 = 0x10010a85ull;

static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_CC_DIAL = 3;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_CS_DIAL = 6;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_CS_DIAL_LEN = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_DAT_DIAL = 9;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_DAT_DIAL_LEN = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_AC_DIAL = 11;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_AS_DIAL = 14;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_AS_DIAL_LEN = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_DABDF_DIAL = 16;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_DABDF_DIAL_LEN = 16;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_DAPASID_DIAL = 32;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL1_DAPASID_DIAL_LEN = 20;
// pau/reg00021.H

static const uint64_t XSL_MAIN_WRAP_CFG = 0x10010aa0ull;

static const uint32_t XSL_MAIN_WRAP_CFG_XSLO_CLOCK_ENABLE = 0;
static const uint32_t XSL_MAIN_WRAP_CFG_XSLO_BLOCK_MEMHIT = 1;
static const uint32_t XSL_MAIN_WRAP_CFG_RESERVED = 2;
static const uint32_t XSL_MAIN_WRAP_CFG_RESERVED_LEN = 2;
static const uint32_t XSL_MAIN_WRAP_CFG_XSLO_OTL_REQ_LIMIT = 4;
static const uint32_t XSL_MAIN_WRAP_CFG_XSLO_OTL_REQ_LIMIT_LEN = 4;
// pau/reg00021.H

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00021.H"
#endif
#endif
