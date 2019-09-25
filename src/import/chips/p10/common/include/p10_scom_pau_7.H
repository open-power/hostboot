/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_7.H $        */
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

#ifndef __p10_scom_pau_7_H_
#define __p10_scom_pau_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


static const uint64_t AME_AME0_MISC_CERR_RPT_MASK = 0x10010bc9ull;

static const uint32_t AME_AME0_MISC_CERR_RPT_MASK_CONFIG_CERR_RPT_MASK = 46;
static const uint32_t AME_AME0_MISC_CERR_RPT_MASK_CONFIG_CERR_RPT_MASK_LEN = 18;
// pau/reg00008.H

static const uint64_t AME_AME0_MISC_PMU_CONFIG2 = 0x10010bc7ull;

static const uint32_t AME_AME0_MISC_PMU_CONFIG2_PE_TYPE = 5;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_PE_TYPE_LEN = 3;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_INST_CAT = 8;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_INST_CAT_LEN = 4;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_PC0 = 12;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_PC0_LEN = 13;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_PC1 = 25;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_PC1_LEN = 13;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_PCR_S = 38;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_PCR_S_LEN = 13;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_PCR_E = 51;
static const uint32_t AME_AME0_MISC_PMU_CONFIG2_PCR_E_LEN = 13;
// pau/reg00008.H

static const uint64_t CS_CTL_MISC_BDF2PE_13_CONFIG = 0x100109bdull;

static const uint32_t CS_CTL_MISC_BDF2PE_13_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_13_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_13_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_13_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_13_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_13_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_13_CONFIG_BDF_LEN = 16;
// pau/reg00008.H

static const uint64_t CS_CTL_MISC_BDF2PE_8_CONFIG = 0x100109b8ull;

static const uint32_t CS_CTL_MISC_BDF2PE_8_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_8_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_8_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_8_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_8_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_8_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_8_CONFIG_BDF_LEN = 16;
// pau/reg00008.H

static const uint64_t CS_CTL_MISC_CERR_HOLD1 = 0x100109a0ull;

static const uint32_t CS_CTL_MISC_CERR_HOLD1_PEF_0 = 0;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PEF_1 = 1;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PEF_2 = 2;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PEF_3 = 3;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PEF_4 = 4;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PEF_5 = 5;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PEF_6 = 6;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PEF_7 = 7;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_0 = 8;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_1 = 9;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_2 = 10;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_3 = 11;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_4 = 12;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_5 = 13;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_6 = 14;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_7 = 15;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_8 = 16;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_9 = 17;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_10 = 18;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_11 = 19;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_12 = 20;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_13 = 21;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_14 = 22;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_15 = 23;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_16 = 24;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_17 = 25;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_18 = 26;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_NLG_19 = 27;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_FWD_0 = 28;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_FWD_1 = 29;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_FWD_2 = 30;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_FWD_3 = 31;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_AUE_0 = 32;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_AUE_1 = 33;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_AUE_2 = 34;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_AUE_3 = 35;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_AUE_4 = 36;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_AUE_5 = 37;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_AUE_6 = 38;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_AUE_7 = 39;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBP_0 = 40;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBP_1 = 41;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBP_2 = 42;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBP_3 = 43;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBF_0 = 44;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBF_1 = 45;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBF_2 = 46;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBF_3 = 47;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBF_4 = 48;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBF_5 = 49;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBF_6 = 50;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBF_7 = 51;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBC_0 = 52;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBC_1 = 53;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBC_2 = 54;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_PBC_3 = 55;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_LDA_0 = 56;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_LDA_1 = 57;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_LDA_2 = 58;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_LDA_3 = 59;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_STA_0 = 60;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_STA_1 = 61;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_STA_2 = 62;
static const uint32_t CS_CTL_MISC_CERR_HOLD1_STA_3 = 63;
// pau/reg00008.H

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
// pau/reg00008.H

static const uint64_t CS_CTL_MISC_MMIOPA0_CONFIG = 0x10010993ull;

static const uint32_t CS_CTL_MISC_MMIOPA0_CONFIG_RESERVED1 = 0;
static const uint32_t CS_CTL_MISC_MMIOPA0_CONFIG_ADDR = 1;
static const uint32_t CS_CTL_MISC_MMIOPA0_CONFIG_ADDR_LEN = 35;
static const uint32_t CS_CTL_MISC_MMIOPA0_CONFIG_RESERVED2 = 36;
static const uint32_t CS_CTL_MISC_MMIOPA0_CONFIG_RESERVED2_LEN = 3;
static const uint32_t CS_CTL_MISC_MMIOPA0_CONFIG_SIZE = 39;
static const uint32_t CS_CTL_MISC_MMIOPA0_CONFIG_SIZE_LEN = 5;
// pau/reg00008.H

static const uint64_t CS_SM0_MCP_MISC_EPSILON_CONFIG = 0x10010802ull;

static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_RATE = 0;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_RATE_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_W0_COUNT = 4;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_W0_COUNT_LEN = 12;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_W1_COUNT = 16;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_W1_COUNT_LEN = 12;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_R0_COUNT = 28;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_R0_COUNT_LEN = 12;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_R1_COUNT = 40;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_R1_COUNT_LEN = 12;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_R2_COUNT = 52;
static const uint32_t CS_SM0_MCP_MISC_EPSILON_CONFIG_R2_COUNT_LEN = 12;
// pau/reg00008.H

static const uint64_t CS_SM0_MCP_MISC_PERF_CONFIG = 0x10010804ull;

static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_LATSTART = 0;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_LATSTART_LEN = 9;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_LATCANCEL = 9;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_LATCANCEL_LEN = 9;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_LATFINISH = 18;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_LATFINISH_LEN = 9;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_RESERVED1 = 27;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_EVENT0 = 28;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_EVENT0_LEN = 8;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_EVENT1 = 36;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_EVENT1_LEN = 8;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_EVENT2 = 44;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_EVENT2_LEN = 8;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_EVENT3 = 52;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_EVENT3_LEN = 8;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_RESERVED2 = 60;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_RESERVED2_LEN = 2;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_LATFILTER = 62;
static const uint32_t CS_SM0_MCP_MISC_PERF_CONFIG_ACT = 63;
// pau/reg00008.H

static const uint64_t CS_SM0_SNP_MISC_CONFIG0 = 0x10010830ull;

static const uint32_t CS_SM0_SNP_MISC_CONFIG0_MA_RSNOOP_OPT_DCLAIM = 0;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_MA_RSNOOP_OPT_DCLAIM_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_ENABLE_PBUS = 2;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRAZOS_MODE = 3;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_PCKT_BLK_PRB = 4;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_ADR_BAR_MODE = 5;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_RESTRICT_CHIP_GROUP = 6;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED3 = 7;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED3_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_SNP_FIR_TO_INHIBIT_MASK = 9;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_SNP_FIR_TO_INHIBIT_MASK_LEN = 7;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK0_FENCE_TO_INHIBIT_MASK = 16;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK1_FENCE_TO_INHIBIT_MASK = 17;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK2_FENCE_TO_INHIBIT_MASK = 18;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK3_FENCE_TO_INHIBIT_MASK = 19;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK4_FENCE_TO_INHIBIT_MASK = 20;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_MRBGP_TRACK_ALL = 21;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_MRBSP_TRACK_ALL = 22;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_MRBCP_TRACK_ALL = 23;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_ADDR_EX_MASK_ENA = 24;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_ADDR_EX_MASK_ENA_LEN = 7;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_SINGLE_AFU_DUAL_BRICK = 31;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK0_OCAPI_MODE = 32;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK1_OCAPI_MODE = 33;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK2_OCAPI_MODE = 34;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK3_OCAPI_MODE = 35;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK4_OCAPI_MODE = 36;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK0_NVLINK_MODE = 37;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK1_NVLINK_MODE = 38;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK2_NVLINK_MODE = 39;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK3_NVLINK_MODE = 40;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_BRK4_NVLINK_MODE = 41;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_ENABLE_BLOCKING_RCMD_DIR = 42;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_DISABLE_DIR_POWERSAVE = 43;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_DISABLE_PRESP_POWERSAVE = 44;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_ENABLE_BRK0_OCAPI_C2 = 45;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_ENABLE_BRK1_OCAPI_C2 = 46;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_ENABLE_BRK2_OCAPI_C2 = 47;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_ENABLE_BRK3_OCAPI_C2 = 48;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_ENABLE_BRK4_OCAPI_C2 = 49;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_DISABLE_CAN_BY_CP = 50;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED1 = 51;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED2 = 52;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED4 = 53;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED5 = 54;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED6 = 55;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED7 = 56;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED8 = 57;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED9 = 58;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED10 = 59;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_DISABLE_CAN_BY_PROBE = 60;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_HANG_ON_ADDRESS_ERRORS = 61;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED0 = 62;
static const uint32_t CS_SM0_SNP_MISC_CONFIG0_0_RESERVED0_LEN = 2;
// pau/reg00008.H

static const uint64_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5 = 0x10010843ull;

static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_TAG = 0;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_TAG_LEN = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_TAGMASK = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_TAGMASK_LEN = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_PAU = 28;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_PCIE = 29;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_L2L3 = 30;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_RESERVED1 = 31;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_RDSTART = 32;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_RDSTART_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_RDEND = 40;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_RDEND_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_WRSTART = 48;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_WRSTART_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_WREND = 56;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC5_WREND_LEN = 8;
// pau/reg00008.H

static const uint64_t CS_SM1_MCP_MISC_CERR_HOLD2 = 0x10010877ull;

static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_0 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_1 = 1;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_2 = 2;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_3 = 3;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_4 = 4;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_5 = 5;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_6 = 6;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_7 = 7;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_8 = 8;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_9 = 9;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_10 = 10;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_11 = 11;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_12 = 12;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_13 = 13;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_14 = 14;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_15 = 15;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_16 = 16;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_17 = 17;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_18 = 18;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_19 = 19;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_20 = 20;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_21 = 21;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_22 = 22;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_23 = 23;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_24 = 24;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_25 = 25;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_26 = 26;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_27 = 27;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_28 = 28;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_29 = 29;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_30 = 30;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_31 = 31;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_32 = 32;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_33 = 33;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_34 = 34;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_35 = 35;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_36 = 36;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_37 = 37;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_38 = 38;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_39 = 39;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_40 = 40;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_41 = 41;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_42 = 42;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_43 = 43;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_44 = 44;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_45 = 45;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_46 = 46;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_47 = 47;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_48 = 48;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_49 = 49;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_50 = 50;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_51 = 51;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_52 = 52;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_53 = 53;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_54 = 54;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_55 = 55;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_56 = 56;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_57 = 57;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_58 = 58;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_59 = 59;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_60 = 60;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_61 = 61;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_62 = 62;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD2_63 = 63;
// pau/reg00008.H

static const uint64_t CS_SM1_MCP_MISC_CERR_MESSAGE4 = 0x1001086aull;

static const uint32_t CS_SM1_MCP_MISC_CERR_MESSAGE4_CERR_MESSAGE_BITS4 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_MESSAGE4_CERR_MESSAGE_BITS4_LEN = 64;
// pau/reg00008.H

static const uint64_t CS_SM1_MCP_MISC_PERF_CONFIG = 0x10010864ull;

static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_LATSTART = 0;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_LATSTART_LEN = 9;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_LATCANCEL = 9;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_LATCANCEL_LEN = 9;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_LATFINISH = 18;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_LATFINISH_LEN = 9;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_RESERVED1 = 27;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_EVENT0 = 28;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_EVENT0_LEN = 8;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_EVENT1 = 36;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_EVENT1_LEN = 8;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_EVENT2 = 44;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_EVENT2_LEN = 8;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_EVENT3 = 52;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_EVENT3_LEN = 8;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_RESERVED2 = 60;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_RESERVED2_LEN = 2;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_LATFILTER = 62;
static const uint32_t CS_SM1_MCP_MISC_PERF_CONFIG_ACT = 63;
// pau/reg00008.H

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
// pau/reg00008.H

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
// pau/reg00008.H

static const uint64_t CS_SM1_SNP_MISC_GPU2_BAR = 0x10010894ull;

static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_SL_MODE = 36;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_4T_SELECT = 38;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_MODE = 40;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_MODE_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_GRANULE = 44;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_POISON = 45;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_M2MODE = 46;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM1_SNP_MISC_GPU2_BAR_RESERVED = 51;
// pau/reg00008.H

static const uint64_t CS_SM1_SNP_MISC_GPU3_BAR = 0x10010895ull;

static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_SL_MODE = 36;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_4T_SELECT = 38;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_MODE = 40;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_MODE_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_GRANULE = 44;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_POISON = 45;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_M2MODE = 46;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM1_SNP_MISC_GPU3_BAR_RESERVED = 51;
// pau/reg00008.H

static const uint64_t CS_SM1_SNP_MISC_GPU4_BAR = 0x10010896ull;

static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_SL_MODE = 36;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_4T_SELECT = 38;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_MODE = 40;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_MODE_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_GRANULE = 44;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_POISON = 45;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_M2MODE = 46;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM1_SNP_MISC_GPU4_BAR_RESERVED = 51;
// pau/reg00008.H

static const uint64_t CS_SM2_DIR_MISC_DEBUG1_CONFIG = 0x100108ebull;

static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD0 = 0;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD1 = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD2 = 10;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD3 = 15;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD4 = 20;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD5 = 25;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD6 = 30;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD7 = 35;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD8 = 40;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD9 = 45;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD10 = 50;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM2_DIR_MISC_DEBUG1_CONFIG_ACT = 63;
// pau/reg00008.H

static const uint64_t CS_SM2_MCP_MISC_PERF_CONFIG = 0x100108c4ull;

static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_LATSTART = 0;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_LATSTART_LEN = 9;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_LATCANCEL = 9;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_LATCANCEL_LEN = 9;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_LATFINISH = 18;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_LATFINISH_LEN = 9;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_RESERVED1 = 27;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_EVENT0 = 28;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_EVENT0_LEN = 8;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_EVENT1 = 36;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_EVENT1_LEN = 8;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_EVENT2 = 44;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_EVENT2_LEN = 8;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_EVENT3 = 52;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_EVENT3_LEN = 8;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_RESERVED2 = 60;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_RESERVED2_LEN = 2;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_LATFILTER = 62;
static const uint32_t CS_SM2_MCP_MISC_PERF_CONFIG_ACT = 63;
// pau/reg00008.H

static const uint64_t CS_SM2_MCP_MISC_XTIMER2_CONFIG = 0x100108dfull;

static const uint32_t CS_SM2_MCP_MISC_XTIMER2_CONFIG_2_TICK = 0;
static const uint32_t CS_SM2_MCP_MISC_XTIMER2_CONFIG_2_TICK_LEN = 6;
static const uint32_t CS_SM2_MCP_MISC_XTIMER2_CONFIG_3_TICK = 6;
static const uint32_t CS_SM2_MCP_MISC_XTIMER2_CONFIG_3_TICK_LEN = 6;
// pau/reg00008.H

static const uint64_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5 = 0x10010903ull;

static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_TAG = 0;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_TAG_LEN = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_TAGMASK = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_TAGMASK_LEN = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_PAU = 28;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_PCIE = 29;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_MASK_L2L3 = 30;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_RESERVED1 = 31;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_RDSTART = 32;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_RDSTART_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_RDEND = 40;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_RDEND_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_WRSTART = 48;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_WRSTART_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_WREND = 56;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC5_WREND_LEN = 8;
// pau/reg00008.H

static const uint64_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3 = 0x1001091full;

static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_ABLE_24_31 = 0;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_ABLE_24_31_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY24 = 8;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY24_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY25 = 12;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY25_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY26 = 16;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY26_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY27 = 20;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY27_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY28 = 24;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY28_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY29 = 28;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY29_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY30 = 32;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY30_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY31 = 36;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE3_TRY31_LEN = 4;
// pau/reg00008.H

static const uint64_t CS_SM3_DIR_MISC_SCOM_L2_DATA = 0x1001094cull;

static const uint32_t CS_SM3_DIR_MISC_SCOM_L2_DATA_L2_SCOM_READ_DATA = 0;
static const uint32_t CS_SM3_DIR_MISC_SCOM_L2_DATA_L2_SCOM_READ_DATA_LEN = 64;
// pau/reg00008.H

static const uint64_t CS_SM3_MCP_MISC_CERR_MASK0 = 0x10010932ull;

static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_0 = 0;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_1 = 1;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_2 = 2;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_3 = 3;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_4 = 4;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_5 = 5;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_6 = 6;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_7 = 7;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_8 = 8;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_9 = 9;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_10 = 10;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_11 = 11;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_12 = 12;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_13 = 13;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_14 = 14;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_15 = 15;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_16 = 16;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_17 = 17;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_18 = 18;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_NVF_19 = 19;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_ASBE_0 = 20;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_ASBE_1 = 21;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_ASBE_2 = 22;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_ASBE_3 = 23;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_ASBE_4 = 24;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_ASBE_5 = 25;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_ASBE_6 = 26;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_ASBE_7 = 27;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_PBR_0 = 28;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_PBR_1 = 29;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_PBR_2 = 30;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_PBR_3 = 31;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_PBR_4 = 32;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_PBR_5 = 33;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_PBR_6 = 34;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_PBR_7 = 35;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_REG_0 = 36;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_REG_1 = 37;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_REG_2 = 38;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_REG_3 = 39;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_0 = 40;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_1 = 41;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_2 = 42;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_3 = 43;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_4 = 44;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_5 = 45;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_6 = 46;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_7 = 47;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_8 = 48;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_9 = 49;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_10 = 50;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_11 = 51;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_12 = 52;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_13 = 53;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_14 = 54;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK0_OCR_15 = 55;
// pau/reg00008.H

static const uint64_t CS_SM3_MCP_MISC_CERR_MESSAGE1 = 0x10010927ull;

static const uint32_t CS_SM3_MCP_MISC_CERR_MESSAGE1_CERR_MESSAGE_BITS1 = 0;
static const uint32_t CS_SM3_MCP_MISC_CERR_MESSAGE1_CERR_MESSAGE_BITS1_LEN = 64;
// pau/reg00008.H

static const uint64_t CS_SM3_MCP_MISC_DEBUG1_CONFIG = 0x1001093bull;

static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD0 = 0;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD1 = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD2 = 10;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD3 = 15;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD4 = 20;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD5 = 25;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD6 = 30;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD7 = 35;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD8 = 40;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD9 = 45;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD10 = 50;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM3_MCP_MISC_DEBUG1_CONFIG_ACT = 63;
// pau/reg00008.H

static const uint64_t CS_SM3_MCP_MISC_PERF_CONFIG = 0x10010924ull;

static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_LATSTART = 0;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_LATSTART_LEN = 9;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_LATCANCEL = 9;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_LATCANCEL_LEN = 9;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_LATFINISH = 18;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_LATFINISH_LEN = 9;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_RESERVED1 = 27;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_EVENT0 = 28;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_EVENT0_LEN = 8;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_EVENT1 = 36;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_EVENT1_LEN = 8;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_EVENT2 = 44;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_EVENT2_LEN = 8;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_EVENT3 = 52;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_EVENT3_LEN = 8;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_RESERVED2 = 60;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_RESERVED2_LEN = 2;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_LATFILTER = 62;
static const uint32_t CS_SM3_MCP_MISC_PERF_CONFIG_ACT = 63;
// pau/reg00008.H

static const uint64_t CS_SM3_MCP_MISC_SM_STATUS = 0x1001092eull;

static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_MRBGP = 0;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_MRBGP_LEN = 4;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_MRBSP = 4;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_MRBSP_LEN = 4;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FENCE0 = 8;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FENCE0_LEN = 4;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FENCE1 = 12;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FENCE1_LEN = 4;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FENCE2 = 16;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FENCE2_LEN = 4;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FENCE3 = 20;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FENCE3_LEN = 4;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FENCE4 = 24;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FENCE4_LEN = 4;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_PBLN = 28;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_PBNNG = 29;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_PBRNVG = 30;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B0REQ = 31;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B0DGD = 32;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B1REQ = 33;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B1DGD = 34;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B2REQ = 35;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B2DGD = 36;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B3REQ = 37;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B3DGD = 38;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B4REQ = 39;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B4DGD = 40;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_MMIO = 41;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_MMIOSUE = 42;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_ATSXLATE = 43;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_REPLAY = 44;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_PBRSP = 45;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B0RSP = 46;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B1RSP = 47;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B2RSP = 48;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B3RSP = 49;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_B4RSP = 50;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_XARSP = 51;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_FREE = 52;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_DIRUPD = 53;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_SACOLL = 54;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_MRBCP = 55;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_MRBCP_LEN = 4;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_PERF_LSTATE = 59;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_PERF_LSTATE_LEN = 2;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_RESERVED2 = 61;
static const uint32_t CS_SM3_MCP_MISC_SM_STATUS_RESERVED2_LEN = 3;
// pau/reg00008.H

static const uint64_t CS_SM3_SNP_MISC_MACHINE_ALLOC = 0x1001096dull;

static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_ENABLE_MACHINE_ALLOC = 0;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_ENABLE_EXCEED_HIGH = 1;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_MAX_MACHINES = 2;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_MAX_MACHINES_LEN = 6;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_HIGH_WATER_IDLE = 8;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_HIGH_WATER_IDLE_LEN = 6;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS1 = 14;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS1_LEN = 6;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_HIGH_MIN_SHARE = 20;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_HIGH_MIN_SHARE_LEN = 10;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS2 = 30;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS2_LEN = 10;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_MAX_HIGH_RESERVED = 40;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_MAX_HIGH_RESERVED_LEN = 4;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL0 = 44;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL0_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL1 = 49;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL1_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL2 = 54;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL2_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL3 = 59;
static const uint32_t CS_SM3_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL3_LEN = 5;
// pau/reg00008.H

static const uint64_t CS_SM3_SNP_MISC_SCOM_L2_ADDR = 0x1001097bull;

static const uint32_t CS_SM3_SNP_MISC_SCOM_L2_ADDR_VALID = 0;
static const uint32_t CS_SM3_SNP_MISC_SCOM_L2_ADDR_ADDR_RESERVED1 = 1;
static const uint32_t CS_SM3_SNP_MISC_SCOM_L2_ADDR_ADDR_RESERVED1_LEN = 3;
static const uint32_t CS_SM3_SNP_MISC_SCOM_L2_ADDR_CCI = 4;
static const uint32_t CS_SM3_SNP_MISC_SCOM_L2_ADDR_CCI_LEN = 10;
static const uint32_t CS_SM3_SNP_MISC_SCOM_L2_ADDR_WAY = 14;
static const uint32_t CS_SM3_SNP_MISC_SCOM_L2_ADDR_WAY_LEN = 2;
// pau/reg00008.H

static const uint64_t DAT_MISC_CERR_ECC_MASK = 0x100109c5ull;

static const uint32_t DAT_MISC_CERR_ECC_MASK_CERR_ECC_MASK_BITS = 10;
static const uint32_t DAT_MISC_CERR_ECC_MASK_CERR_ECC_MASK_BITS_LEN = 54;
// pau/reg00008.H

static const uint64_t MISC_REGS_BDF2PE_14_CONFIG = 0x10010b5eull;

static const uint32_t MISC_REGS_BDF2PE_14_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_14_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_14_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_14_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_14_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_14_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_14_CONFIG_BDF_LEN = 16;
// pau/reg00008.H

static const uint64_t MISC_REGS_BDF2PE_8_CONFIG = 0x10010b58ull;

static const uint32_t MISC_REGS_BDF2PE_8_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_8_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_8_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_8_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_8_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_8_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_8_CONFIG_BDF_LEN = 16;
// pau/reg00008.H

static const uint64_t MISC_REGS_ERR_INFO_PAU_RING_ADDR = 0x10010b42ull;

static const uint32_t MISC_REGS_ERR_INFO_PAU_RING_ADDR_ADDR = 0;
static const uint32_t MISC_REGS_ERR_INFO_PAU_RING_ADDR_ADDR_LEN = 24;
static const uint32_t MISC_REGS_ERR_INFO_PAU_RING_ADDR_LENR = 24;
static const uint32_t MISC_REGS_ERR_INFO_PAU_RING_ADDR_LENR_LEN = 2;
static const uint32_t MISC_REGS_ERR_INFO_PAU_RING_ADDR_RNW = 26;
static const uint32_t MISC_REGS_ERR_INFO_PAU_RING_ADDR_DA_OP = 27;
// pau/reg00008.H

static const uint64_t MISC_REGS_FENCE_1_CONFIG = 0x10010b3bull;

static const uint32_t MISC_REGS_FENCE_1_CONFIG_CONFIG_FENCE_1 = 0;
static const uint32_t MISC_REGS_FENCE_1_CONFIG_CONFIG_FENCE_1_LEN = 64;
// pau/reg00008.H

static const uint64_t OTL0_MISC_HAPPI_BAR2 = 0x10010a3dull;

static const uint32_t OTL0_MISC_HAPPI_BAR2_ENABLE = 0;
static const uint32_t OTL0_MISC_HAPPI_BAR2_ADDR = 1;
static const uint32_t OTL0_MISC_HAPPI_BAR2_ADDR_LEN = 21;
static const uint32_t OTL0_MISC_HAPPI_BAR2_MASK = 22;
static const uint32_t OTL0_MISC_HAPPI_BAR2_MASK_LEN = 21;
static const uint32_t OTL0_MISC_HAPPI_BAR2_SUB = 43;
static const uint32_t OTL0_MISC_HAPPI_BAR2_SUB_LEN = 21;
// pau/reg00008.H

static const uint64_t OTL1_MISC_CONFIG3 = 0x10010a6full;

static const uint32_t OTL1_MISC_CONFIG3_ENABLE_HAPPI = 0;
static const uint32_t OTL1_MISC_CONFIG3_CONFIG3_SPARE = 1;
static const uint32_t OTL1_MISC_CONFIG3_CONFIG3_SPARE_LEN = 31;
// pau/reg00008.H

static const uint64_t OTL1_MISC_CONFIG_ERAT_HASH = 0x10010a69ull;

static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_0 = 0;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_0_LEN = 6;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_1 = 6;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_1_LEN = 6;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_2 = 12;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_2_LEN = 6;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_3 = 18;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_3_LEN = 6;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_4 = 24;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_4_LEN = 6;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_5 = 30;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_5_LEN = 6;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_6 = 36;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_6_LEN = 6;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_7 = 42;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_7_LEN = 6;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_8 = 48;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_8_LEN = 6;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_9 = 54;
static const uint32_t OTL1_MISC_CONFIG_ERAT_HASH_9_LEN = 6;
// pau/reg00008.H

static const uint64_t XSL_MAIN_WRAP_ERROR_1 = 0x10010aa7ull;

static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT0_LO_UE_ERROR = 0;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT0_MID_UE_ERROR = 1;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT0_HI_UE_ERROR = 2;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT1_LO_UE_ERROR = 3;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT1_MID_UE_ERROR = 4;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT1_HI_UE_ERROR = 5;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT2_LO_UE_ERROR = 6;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT2_MID_UE_ERROR = 7;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT2_HI_UE_ERROR = 8;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT3_LO_UE_ERROR = 9;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT3_MID_UE_ERROR = 10;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_ERT3_HI_UE_ERROR = 11;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_TADB_LO_UE_ERROR = 12;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_TADB_MID_UE_ERROR = 13;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_TADB_HI_UE_ERROR = 14;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_COSB_LO_UE_ERROR = 15;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_COSB_MID_UE_ERROR = 16;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_COSB_HI_UE_ERROR = 17;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_RQDB_PE = 18;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_RSDB_PE = 19;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_MDB0_PE = 20;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_MDB1_PE = 21;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_STLBI_PE = 22;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_STLBI_OVERFLOW_ERR = 23;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_CORESP_DATA_CE = 24;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_CORESP_DATA_UE = 25;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_CORESP_DATA_SUE = 26;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_PEE_DATA_CE = 27;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_PEE_DATA_UE = 28;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_PEE_DATA_SUE = 29;
static const uint32_t XSL_MAIN_WRAP_ERROR_1_MEMHIT_W_BAR_MODE_NONZERO_ERROR = 30;
// pau/reg00008.H

static const uint64_t XTS_ATSD_HYP7 = 0x10010b17ull;

static const uint32_t XTS_ATSD_HYP7_MSRHV = 51;
static const uint32_t XTS_ATSD_HYP7_LPARID = 52;
static const uint32_t XTS_ATSD_HYP7_LPARID_LEN = 12;
// pau/reg00008.H

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00008.H"
#endif
#endif
