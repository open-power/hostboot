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


static const uint64_t AME_AME1_MISC_AMM_CONFIG1 = 0x10010bd1ull;

static const uint32_t AME_AME1_MISC_AMM_CONFIG1_1_RESERVED = 32;
static const uint32_t AME_AME1_MISC_AMM_CONFIG1_1_RESERVED_LEN = 19;
static const uint32_t AME_AME1_MISC_AMM_CONFIG1_MRQ_WD_CRD = 51;
static const uint32_t AME_AME1_MISC_AMM_CONFIG1_MRQ_WD_CRD_LEN = 3;
static const uint32_t AME_AME1_MISC_AMM_CONFIG1_MRQ_SD_CRD = 54;
static const uint32_t AME_AME1_MISC_AMM_CONFIG1_MRQ_SD_CRD_LEN = 3;
static const uint32_t AME_AME1_MISC_AMM_CONFIG1_MRQ_ACT_TIMER = 57;
static const uint32_t AME_AME1_MISC_AMM_CONFIG1_MRQ_VC2_CRD_SMR = 58;
static const uint32_t AME_AME1_MISC_AMM_CONFIG1_MRQ_SMR_MAX = 59;
static const uint32_t AME_AME1_MISC_AMM_CONFIG1_MRQ_SMR_MAX_LEN = 5;
// pau/reg00017.H

static const uint64_t AME_AME2_MISC_DEBUG_CONFIG1 = 0x10010be5ull;

static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_0_B6_CSEL = 0;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_1_B6_CSEL = 1;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL0_B6_SEL = 2;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL0_B6_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL1_B6_SEL = 6;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL1_B6_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_0_B7_CSEL = 10;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_1_B7_CSEL = 11;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL0_B7_SEL = 12;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL0_B7_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL1_B7_SEL = 16;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL1_B7_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_0_B8_CSEL = 20;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_1_B8_CSEL = 21;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL0_B8_SEL = 22;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL0_B8_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL1_B8_SEL = 26;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL1_B8_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_0_B9_CSEL = 30;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_1_B9_CSEL = 31;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL0_B9_SEL = 32;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL0_B9_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL1_B9_SEL = 36;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL1_B9_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_0_B10_CSEL = 40;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_1_B10_CSEL = 41;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL0_B10_SEL = 42;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL0_B10_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL1_B10_SEL = 46;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_CL1_B10_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_RESERVED1 = 50;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG1_RESERVED1_LEN = 14;
// pau/reg00017.H

static const uint64_t AME_AME2_MISC_PMU_CONFIG1 = 0x10010be6ull;

static const uint32_t AME_AME2_MISC_PMU_CONFIG1_0_SEL = 28;
static const uint32_t AME_AME2_MISC_PMU_CONFIG1_0_SEL_LEN = 9;
static const uint32_t AME_AME2_MISC_PMU_CONFIG1_1_SEL = 37;
static const uint32_t AME_AME2_MISC_PMU_CONFIG1_1_SEL_LEN = 9;
static const uint32_t AME_AME2_MISC_PMU_CONFIG1_2_SEL = 46;
static const uint32_t AME_AME2_MISC_PMU_CONFIG1_2_SEL_LEN = 9;
static const uint32_t AME_AME2_MISC_PMU_CONFIG1_3_SEL = 55;
static const uint32_t AME_AME2_MISC_PMU_CONFIG1_3_SEL_LEN = 9;
// pau/reg00017.H

static const uint64_t CS_CTL_MISC_BDF2PE_14_CONFIG = 0x100109beull;

static const uint32_t CS_CTL_MISC_BDF2PE_14_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_14_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_14_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_14_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_14_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_14_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_14_CONFIG_BDF_LEN = 16;
// pau/reg00017.H

static const uint64_t CS_CTL_MISC_CONFIG3 = 0x10010983ull;

static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR0 = 0;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR0_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR0 = 0;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR0_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR1 = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR1_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR1 = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR1_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR2 = 6;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR2_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR2 = 6;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PWR2_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_XATS = 9;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_XATS_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_XATS = 9;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_XATS_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_INTS = 12;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_INTS_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_INTS = 12;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_INTS_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ0 = 15;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ0_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ0 = 15;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ0_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST0 = 18;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST0_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST0 = 18;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST0_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB0 = 21;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB0_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB0 = 21;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB0_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ1 = 24;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ1_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ1 = 24;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ1_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST1 = 27;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST1_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST1 = 27;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST1_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB1 = 30;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB1_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB1 = 30;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB1_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ2 = 33;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ2_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ2 = 33;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ2_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST2 = 36;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST2_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST2 = 36;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST2_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB2 = 39;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB2_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB2 = 39;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB2_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ3 = 42;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ3_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ3 = 42;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ3_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST3 = 45;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST3_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST3 = 45;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST3_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB3 = 48;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB3_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB3 = 48;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB3_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ4 = 51;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ4_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ4 = 51;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_REQ4_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST4 = 54;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST4_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST4 = 54;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_CST4_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB4 = 57;
static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB4_LEN = 3;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB4 = 57;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG3_THROTTLE_MODE_PRB4_LEN = 3;
static const uint32_t CS_CTL_MISC_CONFIG3_3_RESERVED1 = 60;
static const uint32_t CS_CTL_MISC_CONFIG3_3_RESERVED1_LEN = 4;
// pau/reg00017.H

static const uint64_t CS_CTL_MISC_FENCE_CONTROL2 = 0x100109a3ull;

static const uint32_t CS_CTL_MISC_FENCE_CONTROL2_2_REQUEST_FENCE = 0;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL2_2_REQUEST_FENCE_LEN = 2;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL2_CONTROL2_RESERVED = 2;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL2_CONTROL2_RESERVED_LEN = 2;
// pau/reg00017.H

static const uint64_t CS_CTL_MISC_PERF_MATCH_CONFIG = 0x10010984ull;

static const uint32_t CS_CTL_MISC_PERF_MATCH_CONFIG_TTYPE = 0;
static const uint32_t CS_CTL_MISC_PERF_MATCH_CONFIG_TTYPE_LEN = 12;
static const uint32_t CS_CTL_MISC_PERF_MATCH_CONFIG_TSIZE = 12;
static const uint32_t CS_CTL_MISC_PERF_MATCH_CONFIG_TSIZE_LEN = 8;
static const uint32_t CS_CTL_MISC_PERF_MATCH_CONFIG_PE = 20;
static const uint32_t CS_CTL_MISC_PERF_MATCH_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_PERF_MATCH_CONFIG_BE = 24;
static const uint32_t CS_CTL_MISC_PERF_MATCH_CONFIG_RESERVED = 25;
static const uint32_t CS_CTL_MISC_PERF_MATCH_CONFIG_RESERVED_LEN = 3;
// pau/reg00017.H

static const uint64_t CS_SM0_MCP_MISC_CONFIG0 = 0x10010800ull;

static const uint32_t CS_SM0_MCP_MISC_CONFIG0_MA_DSA_OPT_CLAIM_UR = 0;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_MA_DSA_OPT_FLUSH_UR = 1;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_MA_DSA_OPT_RP_MODE = 2;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_ADR_BAR_MODE = 3;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_DISABLE_NN_RN = 4;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_DISABLE_VG_NOT_SYS = 5;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_DISABLE_G = 6;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_DISABLE_LN = 7;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_SKIP_G = 8;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_MA_MCRESP_OPT_WRP = 9;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_USE_CL_DMA_W = 10;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_USE_DMA_PR_W = 11;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_INC_PRI_MASK = 12;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_INC_PRI_MASK_LEN = 3;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_MACH_CORRENAB = 15;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_MACH_INJECT_ENABLE1 = 16;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_MACH_INJECT_ENABLE2 = 17;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_RXO_CORRENAB = 18;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_RXO_INJECT_ENABLE1 = 19;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_RXO_INJECT_ENABLE2 = 20;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_RSI_CORRENAB = 21;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_RSI_INJECT_ENABLE1 = 22;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_RSI_INJECT_ENABLE2 = 23;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_MA_DSA_OPT_DMA_UPG = 24;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_EVAPORATE_BY_LCO = 25;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_ENABLE_PBUS = 26;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_ENABLE_SNARF_CPM = 27;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_DISABLE_INJECT = 28;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_DCACHE_MODE = 29;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_DCACHE_REPORTS_PHYSICAL = 30;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_RSI_DISABLE_DATIN_FASTPATH = 31;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_FORBID_MMIO_READ_GT_32 = 32;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_FORBID_MMIO_ATOMIC = 33;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_0_RESERVED1 = 34;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_0_RESERVED1_LEN = 2;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_ENABLE_CONTEXT_LCO = 36;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_MA_DSA_OPT_FAIL_WAKE = 37;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_ENABLE_FAST_DIR_UPDATE = 38;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_OPT_MES_USE_GO_M = 39;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_OPT_LCO_M_USE_MU = 40;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_OPT_SNOOP_EX_LCO = 41;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_ENABLE_CP_ME = 42;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_FENCE_ON_DERR_MMIO = 43;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK0_OCAPI_MODE = 44;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK1_OCAPI_MODE = 45;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK2_OCAPI_MODE = 46;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK3_OCAPI_MODE = 47;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK4_OCAPI_MODE = 48;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK0_NVLINK_MODE = 49;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK1_NVLINK_MODE = 50;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK2_NVLINK_MODE = 51;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK3_NVLINK_MODE = 52;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK4_NVLINK_MODE = 53;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK0_POISON_FENCE_L2 = 54;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK1_POISON_FENCE_L2 = 55;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_0_RESERVED0 = 56;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_0_RESERVED0_LEN = 3;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK0_IMP_TAGS_MODE_ENABLE = 59;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK1_IMP_TAGS_MODE_ENABLE = 60;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK2_IMP_TAGS_MODE_ENABLE = 61;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK3_IMP_TAGS_MODE_ENABLE = 62;
static const uint32_t CS_SM0_MCP_MISC_CONFIG0_BRK4_IMP_TAGS_MODE_ENABLE = 63;
// pau/reg00017.H

static const uint64_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1 = 0x1001083full;

static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_TAG = 0;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_TAG_LEN = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_TAGMASK = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_TAGMASK_LEN = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_PAU = 28;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_PCIE = 29;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_L2L3 = 30;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_RESERVED1 = 31;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_RDSTART = 32;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_RDSTART_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_RDEND = 40;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_RDEND_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_WRSTART = 48;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_WRSTART_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_WREND = 56;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC1_WREND_LEN = 8;
// pau/reg00017.H

static const uint64_t CS_SM0_SNP_MISC_GENID_BAR = 0x1001083dull;

static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE = 0;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1 = 2;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR = 3;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN = 30;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2 = 33;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON = 35;
// pau/reg00017.H

static const uint64_t CS_SM0_SNP_MISC_SM_STATUS = 0x10010852ull;

static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_PWR0 = 0;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_PWR1 = 1;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_PWR2 = 2;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_XATS = 3;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_INTS = 4;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CREQ0 = 5;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CST0 = 6;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_PRB0 = 7;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CREQ1 = 8;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CST1 = 9;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_PRB1 = 10;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CREQ2 = 11;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CST2 = 12;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_PRB2 = 13;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CREQ3 = 14;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CST3 = 15;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_PRB3 = 16;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CREQ4 = 17;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CST4 = 18;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_PRB4 = 19;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_CHGRATE = 20;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_RESERVED1 = 21;
static const uint32_t CS_SM0_SNP_MISC_SM_STATUS_RESERVED1_LEN = 3;
// pau/reg00017.H

static const uint64_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2 = 0x1001085eull;

static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_ABLE_16_23 = 0;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_ABLE_16_23_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY16 = 8;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY16_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY17 = 12;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY17_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY18 = 16;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY18_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY19 = 20;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY19_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY20 = 24;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY20_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY21 = 28;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY21_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY22 = 32;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY22_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY23 = 36;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE2_TRY23_LEN = 4;
// pau/reg00017.H

static const uint64_t CS_SM1_DIR_MISC_SCOM_L2_DATA = 0x1001088cull;

static const uint32_t CS_SM1_DIR_MISC_SCOM_L2_DATA_L2_SCOM_READ_DATA = 0;
static const uint32_t CS_SM1_DIR_MISC_SCOM_L2_DATA_L2_SCOM_READ_DATA_LEN = 64;
// pau/reg00017.H

static const uint64_t CS_SM1_MCP_MISC_CERR_MESSAGE0 = 0x10010866ull;

static const uint32_t CS_SM1_MCP_MISC_CERR_MESSAGE0_CERR_MESSAGE_BITS0 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_MESSAGE0_CERR_MESSAGE_BITS0_LEN = 64;
// pau/reg00017.H

static const uint64_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2 = 0x100108a8ull;

static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_W = 0;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_W_HP = 1;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_INJ = 2;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_PR_DMA_INJ = 3;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_DMA_PR_W = 4;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_RD_NC_F0 = 5;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMAX_U = 6;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMAX_S = 7;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMIN_U = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMIN_S = 9;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_ADD = 10;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_AND = 11;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_OR = 12;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_XOR = 13;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMAX_U = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMAX_S = 15;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMIN_U = 16;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMIN_S = 17;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_ADD = 18;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_AND = 19;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_OR = 20;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_XOR = 21;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_E = 22;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_U = 23;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_T = 24;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_NE = 25;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_INC_B = 26;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_INC_E = 27;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_DEC_B = 28;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_RESERVED1 = 29;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_RESERVED1_LEN = 3;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_WRENA = 32;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_RDENA = 33;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_AWENA = 34;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_ARENA = 35;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_WRENA = 36;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_RDENA = 37;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_AWENA = 38;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_ARENA = 39;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_WRENA = 40;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_RDENA = 41;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_AWENA = 42;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_ARENA = 43;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_WRENA = 44;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_RDENA = 45;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_AWENA = 46;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_ARENA = 47;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_WRENA = 48;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_RDENA = 49;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_AWENA = 50;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_ARENA = 51;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_WRENA = 52;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_RDENA = 53;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_AWENA = 54;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_ARENA = 55;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_WRENA = 56;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_RDENA = 57;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_AWENA = 58;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_ARENA = 59;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_WRENA = 60;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_RDENA = 61;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_AWENA = 62;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_ARENA = 63;
// pau/reg00017.H

static const uint64_t CS_SM1_SNP_MISC_LOW_WATER = 0x100108abull;

static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_PWR0 = 0;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_PWR1 = 1;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_PWR2 = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_XATS = 3;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_INTS = 4;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_REQ0 = 5;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_CST0 = 6;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_PRB0 = 7;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_REQ1 = 8;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_CST1 = 9;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_PRB1 = 10;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_REQ2 = 11;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_CST2 = 12;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_PRB2 = 13;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_REQ3 = 14;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_CST3 = 15;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_PRB3 = 16;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_REQ4 = 17;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_CST4 = 18;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_PRB4 = 19;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_XI_SHARED = 20;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_REQX_SHARED = 21;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_CSTX_SHARED = 22;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_LOW_WATER_PRBX_SHARED = 23;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PWR0 = 24;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PWR0_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PWR1 = 26;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PWR1_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PWR2 = 28;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PWR2_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_XATS = 30;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_XATS_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_INTS = 32;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_INTS_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_REQ0 = 34;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_REQ0_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_CST0 = 36;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_CST0_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PRB0 = 38;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PRB0_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_REQ1 = 40;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_REQ1_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_CST1 = 42;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_CST1_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PRB1 = 44;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PRB1_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_REQ2 = 46;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_REQ2_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_CST2 = 48;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_CST2_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PRB2 = 50;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PRB2_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_REQ3 = 52;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_REQ3_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_CST3 = 54;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_CST3_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PRB3 = 56;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PRB3_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_REQ4 = 58;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_REQ4_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_CST4 = 60;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_CST4_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PRB4 = 62;
static const uint32_t CS_SM1_SNP_MISC_LOW_WATER_WEIGHT_PRB4_LEN = 2;
// pau/reg00017.H

static const uint64_t CS_SM1_SNP_MISC_SCOM_L2_ADDR = 0x100108bbull;

static const uint32_t CS_SM1_SNP_MISC_SCOM_L2_ADDR_VALID = 0;
static const uint32_t CS_SM1_SNP_MISC_SCOM_L2_ADDR_ADDR_RESERVED1 = 1;
static const uint32_t CS_SM1_SNP_MISC_SCOM_L2_ADDR_ADDR_RESERVED1_LEN = 3;
static const uint32_t CS_SM1_SNP_MISC_SCOM_L2_ADDR_CCI = 4;
static const uint32_t CS_SM1_SNP_MISC_SCOM_L2_ADDR_CCI_LEN = 10;
static const uint32_t CS_SM1_SNP_MISC_SCOM_L2_ADDR_WAY = 14;
static const uint32_t CS_SM1_SNP_MISC_SCOM_L2_ADDR_WAY_LEN = 2;
// pau/reg00017.H

static const uint64_t CS_SM2_MCP_MISC_CERR_HOLD1 = 0x100108d6ull;

static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_NLGX_0 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_NLGX_1 = 1;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_NLGX_2 = 2;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_NLGX_3 = 3;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_FWD_0 = 4;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_FWD_1 = 5;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_FWD_2 = 6;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_FWD_3 = 7;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_AUE_0 = 8;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_AUE_1 = 9;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_AUE_2 = 10;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_AUE_3 = 11;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_AUE_4 = 12;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_AUE_5 = 13;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_AUE_6 = 14;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_AUE_7 = 15;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_0 = 16;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_1 = 17;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_2 = 18;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_3 = 19;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_4 = 20;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_5 = 21;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_6 = 22;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_7 = 23;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_8 = 24;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_9 = 25;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_10 = 26;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_PBF_11 = 27;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_LDA_0 = 28;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_LDA_1 = 29;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_LDA_2 = 30;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_LDA_3 = 31;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_STA_0 = 32;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_STA_1 = 33;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_STA_2 = 34;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD1_STA_3 = 35;
// pau/reg00017.H

static const uint64_t CS_SM2_MCP_MISC_DEBUG0_CONFIG = 0x100108daull;

static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM2_MCP_MISC_DEBUG0_CONFIG_ACT = 63;
// pau/reg00017.H

static const uint64_t CS_SM2_SNP_MISC_CERR_MASK0 = 0x10010914ull;

static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NCF_0 = 0;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NCF_1 = 1;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NCF_2 = 2;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NCF_3 = 3;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NCF_4 = 4;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NCF_5 = 5;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NCF_6 = 6;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NCF_7 = 7;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBR_0 = 8;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBR_1 = 9;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBR_2 = 10;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBR_3 = 11;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBR_4 = 12;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBR_5 = 13;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBR_6 = 14;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBR_7 = 15;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBP_0 = 16;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBP_1 = 17;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBP_2 = 18;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBP_3 = 19;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBP_4 = 20;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBP_5 = 21;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBP_6 = 22;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBP_7 = 23;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_0 = 24;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_1 = 25;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_2 = 26;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_3 = 27;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_4 = 28;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_5 = 29;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_6 = 30;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_7 = 31;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_8 = 32;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_9 = 33;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_10 = 34;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBC_11 = 35;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_0 = 36;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_1 = 37;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_2 = 38;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_3 = 39;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_4 = 40;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_5 = 41;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_6 = 42;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_7 = 43;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_8 = 44;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_9 = 45;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_10 = 46;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_11 = 47;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_12 = 48;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_13 = 49;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_14 = 50;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_15 = 51;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_16 = 52;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_17 = 53;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_18 = 54;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_19 = 55;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_20 = 56;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_21 = 57;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_22 = 58;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_NLG_23 = 59;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBF_0 = 60;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBF_1 = 61;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBF_2 = 62;
static const uint32_t CS_SM2_SNP_MISC_CERR_MASK0_PBF_3 = 63;
// pau/reg00017.H

static const uint64_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1 = 0x100108ffull;

static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_TAG = 0;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_TAG_LEN = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_TAGMASK = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_TAGMASK_LEN = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_PAU = 28;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_PCIE = 29;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_MASK_L2L3 = 30;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_RESERVED1 = 31;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_RDSTART = 32;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_RDSTART_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_RDEND = 40;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_RDEND_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_WRSTART = 48;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_WRSTART_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_WREND = 56;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC1_WREND_LEN = 8;
// pau/reg00017.H

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
// pau/reg00017.H

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
// pau/reg00017.H

static const uint64_t CS_SM2_SNP_MISC_GPU2_BAR = 0x100108f4ull;

static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_SL_MODE = 36;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_4T_SELECT = 38;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_MODE = 40;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_MODE_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_GRANULE = 44;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_POISON = 45;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_M2MODE = 46;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM2_SNP_MISC_GPU2_BAR_RESERVED = 51;
// pau/reg00017.H

static const uint64_t CS_SM2_SNP_MISC_GPU3_BAR = 0x100108f5ull;

static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_SL_MODE = 36;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_4T_SELECT = 38;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_MODE = 40;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_MODE_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_GRANULE = 44;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_POISON = 45;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_M2MODE = 46;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM2_SNP_MISC_GPU3_BAR_RESERVED = 51;
// pau/reg00017.H

static const uint64_t CS_SM2_SNP_MISC_GPU4_BAR = 0x100108f6ull;

static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_ADDR_MASK = 1;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_SL_MODE = 36;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_4T_LIMIT = 37;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_4T_SELECT = 38;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_MODE = 40;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_MODE_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_GRANULE = 44;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_POISON = 45;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_M2MODE = 46;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_SECURE_A12 = 48;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_SM2_SNP_MISC_GPU4_BAR_RESERVED = 51;
// pau/reg00017.H

static const uint64_t CS_SM3_DIR_MISC_DEBUG0_CONFIG = 0x1001094aull;

static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM3_DIR_MISC_DEBUG0_CONFIG_ACT = 63;
// pau/reg00017.H

static const uint64_t CS_SM3_MCP_MISC_CERR_MESSAGE5 = 0x1001092bull;

static const uint32_t CS_SM3_MCP_MISC_CERR_MESSAGE5_CERR_MESSAGE_BITS5 = 0;
static const uint32_t CS_SM3_MCP_MISC_CERR_MESSAGE5_CERR_MESSAGE_BITS5_LEN = 64;
// pau/reg00017.H

static const uint64_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2 = 0x10010968ull;

static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_W = 0;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_W_HP = 1;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_DMA_INJ = 2;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_PR_DMA_INJ = 3;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_DMA_PR_W = 4;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_CL_RD_NC_F0 = 5;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMAX_U = 6;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMAX_S = 7;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMIN_U = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_IMIN_S = 9;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_ADD = 10;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_AND = 11;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_OR = 12;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_XOR = 13;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMAX_U = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMAX_S = 15;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMIN_U = 16;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_IMIN_S = 17;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_ADD = 18;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_AND = 19;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_OR = 20;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_XOR = 21;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_E = 22;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_U = 23;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMW_CAS_T = 24;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_CAS_NE = 25;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_INC_B = 26;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_INC_E = 27;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_CMD_ARMWF_DEC_B = 28;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_RESERVED1 = 29;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_RESERVED1_LEN = 3;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_WRENA = 32;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_RDENA = 33;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_AWENA = 34;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE0_ARENA = 35;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_WRENA = 36;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_RDENA = 37;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_AWENA = 38;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE1_ARENA = 39;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_WRENA = 40;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_RDENA = 41;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_AWENA = 42;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE2_ARENA = 43;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_WRENA = 44;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_RDENA = 45;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_AWENA = 46;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE3_ARENA = 47;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_WRENA = 48;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_RDENA = 49;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_AWENA = 50;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE4_ARENA = 51;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_WRENA = 52;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_RDENA = 53;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_AWENA = 54;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE5_ARENA = 55;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_WRENA = 56;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_RDENA = 57;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_AWENA = 58;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE6_ARENA = 59;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_WRENA = 60;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_RDENA = 61;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_AWENA = 62;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK2_SOURCE7_ARENA = 63;
// pau/reg00017.H

static const uint64_t DAT_MISC_CERR_LOG_MASK = 0x100109cbull;

static const uint32_t DAT_MISC_CERR_LOG_MASK_CERR_LOG_MASK_BITS = 47;
static const uint32_t DAT_MISC_CERR_LOG_MASK_CERR_LOG_MASK_BITS_LEN = 17;
// pau/reg00017.H

static const uint64_t DAT_MISC_REM1 = 0x100109ceull;

static const uint32_t DAT_MISC_REM1_PBRX_RTAG = 34;
static const uint32_t DAT_MISC_REM1_PBRX_RTAG_LEN = 22;
static const uint32_t DAT_MISC_REM1_ALU_ADR = 56;
static const uint32_t DAT_MISC_REM1_ALU_ADR_LEN = 3;
static const uint32_t DAT_MISC_REM1_ALU_TYPE = 59;
static const uint32_t DAT_MISC_REM1_ALU_TYPE_LEN = 4;
static const uint32_t DAT_MISC_REM1_ALU_SZ = 63;
// pau/reg00017.H

static const uint64_t DAT_MISC_SCRATCH0 = 0x100109c3ull;

static const uint32_t DAT_MISC_SCRATCH0_SCRATCH0_IDIAL = 0;
static const uint32_t DAT_MISC_SCRATCH0_SCRATCH0_IDIAL_LEN = 64;
// pau/reg00017.H

static const uint64_t MISC_REGS_BDF2PE_13_CONFIG = 0x10010b5dull;

static const uint32_t MISC_REGS_BDF2PE_13_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_13_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_13_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_13_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_13_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_13_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_13_CONFIG_BDF_LEN = 16;
// pau/reg00017.H

static const uint64_t MISC_REGS_INT_0_CONFIG = 0x10010b3cull;

static const uint32_t MISC_REGS_INT_0_CONFIG_CONFIG_INT_0 = 0;
static const uint32_t MISC_REGS_INT_0_CONFIG_CONFIG_INT_0_LEN = 64;
// pau/reg00017.H

static const uint64_t MISC_REGS_INT_LOG_0_PE9 = 0x10010b99ull;

static const uint32_t MISC_REGS_INT_LOG_0_PE9_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE9_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE9_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE9_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE9_RSVD0_LEN = 3;
// pau/reg00017.H

static const uint64_t MISC_REGS_INT_LOG_1_PE9 = 0x10010ba9ull;

static const uint32_t MISC_REGS_INT_LOG_1_PE9_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE9_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE9_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE9_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE9_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE9_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE9_RSVD0_LEN = 7;
// pau/reg00017.H

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
// pau/reg00017.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE9 = 0x10010b89ull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE9_DMA_STOPPED_STATE_ADDR_PE9 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE9_DMA_STOPPED_STATE_ADDR_PE9_LEN = 37;
// pau/reg00017.H

static const uint64_t OTL0_MISC_CONFIG_DEBUG0 = 0x10010a28ull;

static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE0 = 0;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE0_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE1 = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE1_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE2 = 10;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE2_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE3 = 15;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE3_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE4 = 20;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE4_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE5 = 25;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE5_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE6 = 30;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE6_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE7 = 35;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE7_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE8 = 40;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE8_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE9 = 45;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE9_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE10 = 50;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_BYTE10_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_RESERVED = 55;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_0_RESERVED_LEN = 8;
static const uint32_t OTL0_MISC_CONFIG_DEBUG0_ACT = 63;
// pau/reg00017.H

static const uint64_t OTL0_MISC_CONFIG_TX_DLC = 0x10010a2cull;

static const uint32_t OTL0_MISC_CONFIG_TX_DLC_CONFIG_TX_DL_CREDITS = 0;
static const uint32_t OTL0_MISC_CONFIG_TX_DLC_CONFIG_TX_DL_CREDITS_LEN = 10;
// pau/reg00017.H

static const uint64_t OTL0_MISC_ERROR_SIG_RXI = 0x10010a2eull;

static const uint32_t OTL0_MISC_ERROR_SIG_RXI_CAPTURED = 0;
static const uint32_t OTL0_MISC_ERROR_SIG_RXI_ENCODE = 1;
static const uint32_t OTL0_MISC_ERROR_SIG_RXI_ENCODE_LEN = 7;
static const uint32_t OTL0_MISC_ERROR_SIG_RXI_SIGNATURE = 8;
static const uint32_t OTL0_MISC_ERROR_SIG_RXI_SIGNATURE_LEN = 56;
// pau/reg00017.H

static const uint64_t OTL1_MISC_CONFIG_DEBUG1 = 0x10010a59ull;

static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE0 = 0;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE0_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE1 = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE1_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE2 = 10;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE2_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE3 = 15;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE3_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE4 = 20;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE4_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE5 = 25;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE5_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE6 = 30;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE6_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE7 = 35;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE7_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE8 = 40;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE8_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE9 = 45;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE9_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE10 = 50;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_BYTE10_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_RESERVED = 55;
static const uint32_t OTL1_MISC_CONFIG_DEBUG1_RESERVED_LEN = 9;
// pau/reg00017.H

static const uint64_t OTL1_MISC_HAPPI_BAR1 = 0x10010a6cull;

static const uint32_t OTL1_MISC_HAPPI_BAR1_ENABLE = 0;
static const uint32_t OTL1_MISC_HAPPI_BAR1_ADDR = 1;
static const uint32_t OTL1_MISC_HAPPI_BAR1_ADDR_LEN = 21;
static const uint32_t OTL1_MISC_HAPPI_BAR1_MASK = 22;
static const uint32_t OTL1_MISC_HAPPI_BAR1_MASK_LEN = 21;
static const uint32_t OTL1_MISC_HAPPI_BAR1_SUB = 43;
static const uint32_t OTL1_MISC_HAPPI_BAR1_SUB_LEN = 21;
// pau/reg00017.H

static const uint64_t OTL1_MISC_PMU_CONTROL2 = 0x10010a54ull;

static const uint32_t OTL1_MISC_PMU_CONTROL2_C01_DCMASKA = 0;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C01_DCMASKA_LEN = 8;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C01_DCMASKB = 8;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C01_DCMASKB_LEN = 8;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C23_DCMASKA = 16;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C23_DCMASKA_LEN = 8;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C23_DCMASKB = 24;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C23_DCMASKB_LEN = 8;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C01_DCMASKDLA = 32;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C01_DCMASKDLA_LEN = 2;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C01_DCMASKDLB = 34;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C01_DCMASKDLB_LEN = 2;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C23_DCMASKDLA = 36;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C23_DCMASKDLA_LEN = 2;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C23_DCMASKDLB = 38;
static const uint32_t OTL1_MISC_PMU_CONTROL2_C23_DCMASKDLB_LEN = 2;
static const uint32_t OTL1_MISC_PMU_CONTROL2_DCMASK_LATENCY = 40;
static const uint32_t OTL1_MISC_PMU_CONTROL2_DCMASK_LATENCY_LEN = 8;
static const uint32_t OTL1_MISC_PMU_CONTROL2_RESERVED2 = 48;
static const uint32_t OTL1_MISC_PMU_CONTROL2_RESERVED2_LEN = 16;
// pau/reg00017.H

static const uint64_t OTL1_MISC_PSL_TFC_AN = 0x10010a7aull;

static const uint32_t OTL1_MISC_PSL_TFC_AN_TFC_ACK = 28;
static const uint32_t OTL1_MISC_PSL_TFC_AN_C = 29;
static const uint32_t OTL1_MISC_PSL_TFC_AN_AE = 30;
static const uint32_t OTL1_MISC_PSL_TFC_AN_R = 31;
// pau/reg00017.H

static const uint64_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0 = 0x10010a88ull;

static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL = 0;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL = 3;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL = 32;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL = 33;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL_LEN = 2;
// pau/reg00017.H

static const uint64_t XTS_ATSD_HYP3 = 0x10010b13ull;

static const uint32_t XTS_ATSD_HYP3_MSRHV = 51;
static const uint32_t XTS_ATSD_HYP3_LPARID = 52;
static const uint32_t XTS_ATSD_HYP3_LPARID_LEN = 12;
// pau/reg00017.H

static const uint64_t XTS_REG_DEBUG0_CONFIG = 0x10010af6ull;

static const uint32_t XTS_REG_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t XTS_REG_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t XTS_REG_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t XTS_REG_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t XTS_REG_DEBUG0_CONFIG_ACT = 63;
// pau/reg00017.H

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00017.H"
#endif
#endif
