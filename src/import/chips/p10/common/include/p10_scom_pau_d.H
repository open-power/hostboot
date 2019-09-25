/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_d.H $        */
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

#ifndef __p10_scom_pau_d_H_
#define __p10_scom_pau_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


static const uint64_t AME_AME0_MISC_PMU_CONFIG1 = 0x10010bc6ull;

static const uint32_t AME_AME0_MISC_PMU_CONFIG1_0_SEL = 28;
static const uint32_t AME_AME0_MISC_PMU_CONFIG1_0_SEL_LEN = 9;
static const uint32_t AME_AME0_MISC_PMU_CONFIG1_1_SEL = 37;
static const uint32_t AME_AME0_MISC_PMU_CONFIG1_1_SEL_LEN = 9;
static const uint32_t AME_AME0_MISC_PMU_CONFIG1_2_SEL = 46;
static const uint32_t AME_AME0_MISC_PMU_CONFIG1_2_SEL_LEN = 9;
static const uint32_t AME_AME0_MISC_PMU_CONFIG1_3_SEL = 55;
static const uint32_t AME_AME0_MISC_PMU_CONFIG1_3_SEL_LEN = 9;
// pau/reg00016.H

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
// pau/reg00016.H

static const uint64_t CS_CTL_MISC_ELOGGER_BAR = 0x100109a8ull;

static const uint32_t CS_CTL_MISC_ELOGGER_BAR_LOG_UNEXP = 0;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_LOG_BSTAT = 1;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_LOG_BQDFL = 2;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_LOG_BSDFL = 3;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_LOG_L2BF = 4;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_LOG_BARBF = 5;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_RESERVED1 = 6;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_RESERVED1_LEN = 2;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_SIZE = 8;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_SIZE_LEN = 4;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_ADDR = 12;
static const uint32_t CS_CTL_MISC_ELOGGER_BAR_ADDR_LEN = 36;
// pau/reg00016.H

static const uint64_t CS_CTL_MISC_LCO_CONFIG = 0x100109a7ull;

static const uint32_t CS_CTL_MISC_LCO_CONFIG_V_TARG = 0;
static const uint32_t CS_CTL_MISC_LCO_CONFIG_V_TARG_LEN = 32;
static const uint32_t CS_CTL_MISC_LCO_CONFIG_RESERVED1 = 32;
static const uint32_t CS_CTL_MISC_LCO_CONFIG_RESERVED1_LEN = 3;
static const uint32_t CS_CTL_MISC_LCO_CONFIG_E_TARG_MIN = 35;
static const uint32_t CS_CTL_MISC_LCO_CONFIG_E_TARG_MIN_LEN = 5;
static const uint32_t CS_CTL_MISC_LCO_CONFIG_RAND_EVENT = 40;
static const uint32_t CS_CTL_MISC_LCO_CONFIG_RAND_EVENT_LEN = 4;
// pau/reg00016.H

static const uint64_t CS_CTL_MISC_MMIOPA4_CONFIG = 0x10010997ull;

static const uint32_t CS_CTL_MISC_MMIOPA4_CONFIG_RESERVED1 = 0;
static const uint32_t CS_CTL_MISC_MMIOPA4_CONFIG_ADDR = 1;
static const uint32_t CS_CTL_MISC_MMIOPA4_CONFIG_ADDR_LEN = 35;
static const uint32_t CS_CTL_MISC_MMIOPA4_CONFIG_RESERVED2 = 36;
static const uint32_t CS_CTL_MISC_MMIOPA4_CONFIG_RESERVED2_LEN = 3;
static const uint32_t CS_CTL_MISC_MMIOPA4_CONFIG_SIZE = 39;
static const uint32_t CS_CTL_MISC_MMIOPA4_CONFIG_SIZE_LEN = 5;
// pau/reg00016.H

static const uint64_t CS_SM0_MCP_MISC_SM_STATUS = 0x1001080eull;

static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_MRBGP = 0;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_MRBGP_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_MRBSP = 4;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_MRBSP_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FENCE0 = 8;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FENCE0_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FENCE1 = 12;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FENCE1_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FENCE2 = 16;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FENCE2_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FENCE3 = 20;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FENCE3_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FENCE4 = 24;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FENCE4_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_PBLN = 28;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_PBNNG = 29;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_PBRNVG = 30;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B0REQ = 31;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B0DGD = 32;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B1REQ = 33;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B1DGD = 34;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B2REQ = 35;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B2DGD = 36;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B3REQ = 37;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B3DGD = 38;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B4REQ = 39;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B4DGD = 40;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_MMIO = 41;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_MMIOSUE = 42;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_ATSXLATE = 43;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_REPLAY = 44;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_PBRSP = 45;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B0RSP = 46;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B1RSP = 47;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B2RSP = 48;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B3RSP = 49;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_B4RSP = 50;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_XARSP = 51;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_FREE = 52;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_DIRUPD = 53;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_SACOLL = 54;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_MRBCP = 55;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_MRBCP_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_PERF_LSTATE = 59;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_PERF_LSTATE_LEN = 2;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_RESERVED2 = 61;
static const uint32_t CS_SM0_MCP_MISC_SM_STATUS_RESERVED2_LEN = 3;
// pau/reg00016.H

static const uint64_t CS_SM0_SNP_MISC_CERR_FIRST0 = 0x10010853ull;

static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NCF_0 = 0;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NCF_1 = 1;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NCF_2 = 2;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NCF_3 = 3;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NCF_4 = 4;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NCF_5 = 5;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NCF_6 = 6;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NCF_7 = 7;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBR_0 = 8;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBR_1 = 9;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBR_2 = 10;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBR_3 = 11;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBR_4 = 12;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBR_5 = 13;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBR_6 = 14;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBR_7 = 15;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBP_0 = 16;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBP_1 = 17;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBP_2 = 18;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBP_3 = 19;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBP_4 = 20;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBP_5 = 21;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBP_6 = 22;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBP_7 = 23;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_0 = 24;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_1 = 25;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_2 = 26;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_3 = 27;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_4 = 28;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_5 = 29;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_6 = 30;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_7 = 31;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_8 = 32;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_9 = 33;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_10 = 34;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBC_11 = 35;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_0 = 36;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_1 = 37;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_2 = 38;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_3 = 39;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_4 = 40;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_5 = 41;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_6 = 42;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_7 = 43;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_8 = 44;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_9 = 45;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_10 = 46;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_11 = 47;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_12 = 48;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_13 = 49;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_14 = 50;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_15 = 51;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_16 = 52;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_17 = 53;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_18 = 54;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_19 = 55;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_20 = 56;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_21 = 57;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_22 = 58;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_NLG_23 = 59;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBF_0 = 60;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBF_1 = 61;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBF_2 = 62;
static const uint32_t CS_SM0_SNP_MISC_CERR_FIRST0_PBF_3 = 63;
// pau/reg00016.H

static const uint64_t CS_SM0_SNP_MISC_CERR_MESSAGE1 = 0x10010851ull;

static const uint32_t CS_SM0_SNP_MISC_CERR_MESSAGE1_CERR_MESSAGE_BITS1 = 0;
static const uint32_t CS_SM0_SNP_MISC_CERR_MESSAGE1_CERR_MESSAGE_BITS1_LEN = 64;
// pau/reg00016.H

static const uint64_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6 = 0x10010844ull;

static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_TAG = 0;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_TAG_LEN = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_TAGMASK = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_TAGMASK_LEN = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_PAU = 28;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_PCIE = 29;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_L2L3 = 30;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_RESERVED1 = 31;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_RDSTART = 32;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_RDSTART_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_RDEND = 40;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_RDEND_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_WRSTART = 48;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_WRSTART_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_WREND = 56;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC6_WREND_LEN = 8;
// pau/reg00016.H

static const uint64_t CS_SM0_SNP_MISC_DEBUG1_CONFIG = 0x1001085aull;

static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD0 = 0;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD1 = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD2 = 10;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD3 = 15;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD4 = 20;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD5 = 25;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD6 = 30;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD7 = 35;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD8 = 40;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD9 = 45;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD10 = 50;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_DEBUG1_CONFIG_ACT = 63;
// pau/reg00016.H

static const uint64_t CS_SM1_MCP_MISC_CERR_HOLD1 = 0x10010876ull;

static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_NLGX_0 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_NLGX_1 = 1;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_NLGX_2 = 2;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_NLGX_3 = 3;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_FWD_0 = 4;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_FWD_1 = 5;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_FWD_2 = 6;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_FWD_3 = 7;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_AUE_0 = 8;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_AUE_1 = 9;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_AUE_2 = 10;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_AUE_3 = 11;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_AUE_4 = 12;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_AUE_5 = 13;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_AUE_6 = 14;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_AUE_7 = 15;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_0 = 16;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_1 = 17;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_2 = 18;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_3 = 19;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_4 = 20;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_5 = 21;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_6 = 22;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_7 = 23;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_8 = 24;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_9 = 25;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_10 = 26;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_PBF_11 = 27;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_LDA_0 = 28;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_LDA_1 = 29;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_LDA_2 = 30;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_LDA_3 = 31;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_STA_0 = 32;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_STA_1 = 33;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_STA_2 = 34;
static const uint32_t CS_SM1_MCP_MISC_CERR_HOLD1_STA_3 = 35;
// pau/reg00016.H

static const uint64_t CS_SM1_MCP_MISC_CERR_MESSAGE7 = 0x1001086dull;

static const uint32_t CS_SM1_MCP_MISC_CERR_MESSAGE7_CERR_MESSAGE_BITS7 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_MESSAGE7_CERR_MESSAGE_BITS7_LEN = 40;
// pau/reg00016.H

static const uint64_t CS_SM1_SNP_MISC_CERR_FIRST0 = 0x100108b3ull;

static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NCF_0 = 0;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NCF_1 = 1;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NCF_2 = 2;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NCF_3 = 3;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NCF_4 = 4;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NCF_5 = 5;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NCF_6 = 6;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NCF_7 = 7;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBR_0 = 8;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBR_1 = 9;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBR_2 = 10;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBR_3 = 11;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBR_4 = 12;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBR_5 = 13;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBR_6 = 14;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBR_7 = 15;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBP_0 = 16;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBP_1 = 17;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBP_2 = 18;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBP_3 = 19;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBP_4 = 20;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBP_5 = 21;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBP_6 = 22;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBP_7 = 23;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_0 = 24;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_1 = 25;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_2 = 26;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_3 = 27;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_4 = 28;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_5 = 29;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_6 = 30;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_7 = 31;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_8 = 32;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_9 = 33;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_10 = 34;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBC_11 = 35;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_0 = 36;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_1 = 37;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_2 = 38;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_3 = 39;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_4 = 40;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_5 = 41;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_6 = 42;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_7 = 43;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_8 = 44;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_9 = 45;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_10 = 46;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_11 = 47;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_12 = 48;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_13 = 49;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_14 = 50;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_15 = 51;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_16 = 52;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_17 = 53;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_18 = 54;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_19 = 55;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_20 = 56;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_21 = 57;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_22 = 58;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_NLG_23 = 59;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBF_0 = 60;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBF_1 = 61;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBF_2 = 62;
static const uint32_t CS_SM1_SNP_MISC_CERR_FIRST0_PBF_3 = 63;
// pau/reg00016.H

static const uint64_t CS_SM1_SNP_MISC_CERR_MASK0 = 0x100108b4ull;

static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NCF_0 = 0;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NCF_1 = 1;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NCF_2 = 2;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NCF_3 = 3;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NCF_4 = 4;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NCF_5 = 5;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NCF_6 = 6;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NCF_7 = 7;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBR_0 = 8;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBR_1 = 9;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBR_2 = 10;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBR_3 = 11;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBR_4 = 12;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBR_5 = 13;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBR_6 = 14;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBR_7 = 15;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBP_0 = 16;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBP_1 = 17;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBP_2 = 18;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBP_3 = 19;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBP_4 = 20;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBP_5 = 21;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBP_6 = 22;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBP_7 = 23;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_0 = 24;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_1 = 25;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_2 = 26;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_3 = 27;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_4 = 28;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_5 = 29;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_6 = 30;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_7 = 31;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_8 = 32;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_9 = 33;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_10 = 34;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBC_11 = 35;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_0 = 36;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_1 = 37;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_2 = 38;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_3 = 39;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_4 = 40;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_5 = 41;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_6 = 42;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_7 = 43;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_8 = 44;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_9 = 45;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_10 = 46;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_11 = 47;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_12 = 48;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_13 = 49;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_14 = 50;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_15 = 51;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_16 = 52;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_17 = 53;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_18 = 54;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_19 = 55;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_20 = 56;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_21 = 57;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_22 = 58;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_NLG_23 = 59;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBF_0 = 60;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBF_1 = 61;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBF_2 = 62;
static const uint32_t CS_SM1_SNP_MISC_CERR_MASK0_PBF_3 = 63;
// pau/reg00016.H

static const uint64_t CS_SM2_MCP_MISC_CONFIG0 = 0x100108c0ull;

static const uint32_t CS_SM2_MCP_MISC_CONFIG0_MA_DSA_OPT_CLAIM_UR = 0;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_MA_DSA_OPT_FLUSH_UR = 1;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_MA_DSA_OPT_RP_MODE = 2;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_ADR_BAR_MODE = 3;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_DISABLE_NN_RN = 4;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_DISABLE_VG_NOT_SYS = 5;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_DISABLE_G = 6;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_DISABLE_LN = 7;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_SKIP_G = 8;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_MA_MCRESP_OPT_WRP = 9;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_USE_CL_DMA_W = 10;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_USE_DMA_PR_W = 11;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_INC_PRI_MASK = 12;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_INC_PRI_MASK_LEN = 3;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_MACH_CORRENAB = 15;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_MACH_INJECT_ENABLE1 = 16;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_MACH_INJECT_ENABLE2 = 17;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_RXO_CORRENAB = 18;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_RXO_INJECT_ENABLE1 = 19;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_RXO_INJECT_ENABLE2 = 20;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_RSI_CORRENAB = 21;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_RSI_INJECT_ENABLE1 = 22;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_RSI_INJECT_ENABLE2 = 23;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_MA_DSA_OPT_DMA_UPG = 24;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_EVAPORATE_BY_LCO = 25;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_ENABLE_PBUS = 26;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_ENABLE_SNARF_CPM = 27;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_DISABLE_INJECT = 28;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_DCACHE_MODE = 29;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_DCACHE_REPORTS_PHYSICAL = 30;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_RSI_DISABLE_DATIN_FASTPATH = 31;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_FORBID_MMIO_READ_GT_32 = 32;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_FORBID_MMIO_ATOMIC = 33;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_0_RESERVED1 = 34;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_0_RESERVED1_LEN = 2;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_ENABLE_CONTEXT_LCO = 36;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_MA_DSA_OPT_FAIL_WAKE = 37;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_ENABLE_FAST_DIR_UPDATE = 38;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_OPT_MES_USE_GO_M = 39;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_OPT_LCO_M_USE_MU = 40;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_OPT_SNOOP_EX_LCO = 41;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_ENABLE_CP_ME = 42;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_FENCE_ON_DERR_MMIO = 43;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK0_OCAPI_MODE = 44;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK1_OCAPI_MODE = 45;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK2_OCAPI_MODE = 46;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK3_OCAPI_MODE = 47;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK4_OCAPI_MODE = 48;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK0_NVLINK_MODE = 49;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK1_NVLINK_MODE = 50;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK2_NVLINK_MODE = 51;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK3_NVLINK_MODE = 52;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK4_NVLINK_MODE = 53;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK0_POISON_FENCE_L2 = 54;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK1_POISON_FENCE_L2 = 55;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_0_RESERVED0 = 56;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_0_RESERVED0_LEN = 3;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK0_IMP_TAGS_MODE_ENABLE = 59;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK1_IMP_TAGS_MODE_ENABLE = 60;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK2_IMP_TAGS_MODE_ENABLE = 61;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK3_IMP_TAGS_MODE_ENABLE = 62;
static const uint32_t CS_SM2_MCP_MISC_CONFIG0_BRK4_IMP_TAGS_MODE_ENABLE = 63;
// pau/reg00016.H

static const uint64_t CS_SM2_MCP_MISC_DEBUG3_CONFIG = 0x100108dcull;

static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE0 = 0;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE0_LEN = 7;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE1 = 7;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE1_LEN = 7;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE2 = 14;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE2_LEN = 7;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE3 = 21;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE3_LEN = 7;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE4 = 28;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE4_LEN = 7;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE5 = 35;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE5_LEN = 7;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE6 = 42;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE6_LEN = 7;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE7 = 49;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE7_LEN = 7;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE8 = 56;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_BYTE8_LEN = 7;
static const uint32_t CS_SM2_MCP_MISC_DEBUG3_CONFIG_ACT = 63;
// pau/reg00016.H

static const uint64_t CS_SM2_SNP_MISC_CERR_FIRST0 = 0x10010913ull;

static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NCF_0 = 0;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NCF_1 = 1;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NCF_2 = 2;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NCF_3 = 3;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NCF_4 = 4;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NCF_5 = 5;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NCF_6 = 6;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NCF_7 = 7;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBR_0 = 8;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBR_1 = 9;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBR_2 = 10;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBR_3 = 11;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBR_4 = 12;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBR_5 = 13;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBR_6 = 14;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBR_7 = 15;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBP_0 = 16;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBP_1 = 17;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBP_2 = 18;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBP_3 = 19;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBP_4 = 20;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBP_5 = 21;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBP_6 = 22;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBP_7 = 23;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_0 = 24;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_1 = 25;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_2 = 26;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_3 = 27;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_4 = 28;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_5 = 29;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_6 = 30;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_7 = 31;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_8 = 32;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_9 = 33;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_10 = 34;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBC_11 = 35;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_0 = 36;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_1 = 37;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_2 = 38;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_3 = 39;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_4 = 40;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_5 = 41;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_6 = 42;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_7 = 43;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_8 = 44;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_9 = 45;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_10 = 46;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_11 = 47;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_12 = 48;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_13 = 49;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_14 = 50;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_15 = 51;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_16 = 52;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_17 = 53;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_18 = 54;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_19 = 55;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_20 = 56;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_21 = 57;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_22 = 58;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_NLG_23 = 59;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBF_0 = 60;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBF_1 = 61;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBF_2 = 62;
static const uint32_t CS_SM2_SNP_MISC_CERR_FIRST0_PBF_3 = 63;
// pau/reg00016.H

static const uint64_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6 = 0x10010904ull;

static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_TAG = 0;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_TAG_LEN = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_TAGMASK = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_TAGMASK_LEN = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_PAU = 28;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_PCIE = 29;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_L2L3 = 30;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_RESERVED1 = 31;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_RDSTART = 32;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_RDSTART_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_RDEND = 40;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_RDEND_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_WRSTART = 48;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_WRSTART_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_WREND = 56;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC6_WREND_LEN = 8;
// pau/reg00016.H

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
// pau/reg00016.H

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
// pau/reg00016.H

static const uint64_t CS_SM2_SNP_MISC_NDT2_BAR = 0x100108f9ull;

static const uint32_t CS_SM2_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM2_SNP_MISC_NDT2_BAR_NDT2_RESERVED1 = 2;
static const uint32_t CS_SM2_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_ADDR = 3;
static const uint32_t CS_SM2_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM2_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_POISON = 36;
static const uint32_t CS_SM2_SNP_MISC_NDT2_BAR_NDT2_RESERVED2 = 37;
static const uint32_t CS_SM2_SNP_MISC_NDT2_BAR_NDT2_RESERVED2_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_SIZE = 39;
static const uint32_t CS_SM2_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_SIZE_LEN = 5;
// pau/reg00016.H

static const uint64_t CS_SM2_SNP_MISC_NDT3_BAR = 0x100108faull;

static const uint32_t CS_SM2_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM2_SNP_MISC_NDT3_BAR_NDT3_RESERVED1 = 2;
static const uint32_t CS_SM2_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_ADDR = 3;
static const uint32_t CS_SM2_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM2_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_POISON = 36;
static const uint32_t CS_SM2_SNP_MISC_NDT3_BAR_NDT3_RESERVED2 = 37;
static const uint32_t CS_SM2_SNP_MISC_NDT3_BAR_NDT3_RESERVED2_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_SIZE = 39;
static const uint32_t CS_SM2_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_SIZE_LEN = 5;
// pau/reg00016.H

static const uint64_t CS_SM2_SNP_MISC_NDT4_BAR = 0x100108fbull;

static const uint32_t CS_SM2_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_ENABLE = 0;
static const uint32_t CS_SM2_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM2_SNP_MISC_NDT4_BAR_NDT4_RESERVED1 = 2;
static const uint32_t CS_SM2_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_ADDR = 3;
static const uint32_t CS_SM2_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM2_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_POISON = 36;
static const uint32_t CS_SM2_SNP_MISC_NDT4_BAR_NDT4_RESERVED2 = 37;
static const uint32_t CS_SM2_SNP_MISC_NDT4_BAR_NDT4_RESERVED2_LEN = 2;
static const uint32_t CS_SM2_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_SIZE = 39;
static const uint32_t CS_SM2_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_SIZE_LEN = 5;
// pau/reg00016.H

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
// pau/reg00016.H

static const uint64_t CS_SM3_MCP_MISC_CERR_MESSAGE2 = 0x10010928ull;

static const uint32_t CS_SM3_MCP_MISC_CERR_MESSAGE2_CERR_MESSAGE_BITS2 = 0;
static const uint32_t CS_SM3_MCP_MISC_CERR_MESSAGE2_CERR_MESSAGE_BITS2_LEN = 64;
// pau/reg00016.H

static const uint64_t CS_SM3_SNP_MISC_CERR_FIRST0 = 0x10010973ull;

static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NCF_0 = 0;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NCF_1 = 1;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NCF_2 = 2;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NCF_3 = 3;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NCF_4 = 4;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NCF_5 = 5;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NCF_6 = 6;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NCF_7 = 7;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBR_0 = 8;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBR_1 = 9;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBR_2 = 10;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBR_3 = 11;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBR_4 = 12;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBR_5 = 13;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBR_6 = 14;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBR_7 = 15;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBP_0 = 16;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBP_1 = 17;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBP_2 = 18;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBP_3 = 19;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBP_4 = 20;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBP_5 = 21;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBP_6 = 22;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBP_7 = 23;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_0 = 24;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_1 = 25;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_2 = 26;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_3 = 27;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_4 = 28;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_5 = 29;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_6 = 30;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_7 = 31;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_8 = 32;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_9 = 33;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_10 = 34;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBC_11 = 35;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_0 = 36;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_1 = 37;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_2 = 38;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_3 = 39;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_4 = 40;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_5 = 41;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_6 = 42;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_7 = 43;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_8 = 44;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_9 = 45;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_10 = 46;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_11 = 47;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_12 = 48;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_13 = 49;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_14 = 50;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_15 = 51;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_16 = 52;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_17 = 53;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_18 = 54;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_19 = 55;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_20 = 56;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_21 = 57;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_22 = 58;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_NLG_23 = 59;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBF_0 = 60;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBF_1 = 61;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBF_2 = 62;
static const uint32_t CS_SM3_SNP_MISC_CERR_FIRST0_PBF_3 = 63;
// pau/reg00016.H

static const uint64_t DAT_MISC_DEBUG1_CONFIG = 0x100109d1ull;

static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD0 = 0;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD0_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD1 = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD1_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD2 = 10;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD2_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD3 = 15;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD3_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD4 = 20;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD4_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD5 = 25;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD5_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD6 = 30;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD6_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD7 = 35;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD7_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD8 = 40;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD8_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD9 = 45;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD9_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD10 = 50;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_POD10_LEN = 5;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_RESERVED1 = 55;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_RESERVED1_LEN = 8;
static const uint32_t DAT_MISC_DEBUG1_CONFIG_ACT = 63;
// pau/reg00016.H

static const uint64_t MISC_REGS_BDF2PE_10_CONFIG = 0x10010b5aull;

static const uint32_t MISC_REGS_BDF2PE_10_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_10_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_10_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_10_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_10_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_10_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_10_CONFIG_BDF_LEN = 16;
// pau/reg00016.H

static const uint64_t OTL0_MISC_C_ERR_RPT_HOLD0 = 0x10010a26ull;

static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_TL_CRD_OVF = 0;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_ACTAG_IDX = 1;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_ACTAG_INV = 2;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_OPC_RSVD = 3;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_RTC_POS = 4;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_TMPL = 5;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_TMPL_UNS = 6;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_TMPL_X00 = 7;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CTLFLIT_OVERRUN = 8;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_UNEXPECTED_DATA_FLIT = 9;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_LINK_DOWN = 10;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_BAD_DATA_RECEIVED_CMD = 11;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_BAD_DATA_RECEIVED_RESP = 12;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_RESPONSE_NOT_ALLOWED = 13;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_MISC_PERR = 14;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_TXO_PERR = 15;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_PERR_FRMD = 16;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_PERR_FRMC = 17;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_TXO_CBUF_CE = 18;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_TXO_CBUF_UE = 19;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_TXI_DBUF_CE = 20;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_TXI_DBUF_UE = 21;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CDFIFO_LO_CE = 22;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CDFIFO_LO_UE = 23;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CDFIFO_HI_CE = 24;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CDFIFO_HI_UE = 25;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_RDFIFO_LO_CE = 26;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_RDFIFO_LO_UE = 27;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_RDFIFO_HI_CE = 28;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_RDFIFO_HI_UE = 29;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO0_LO_CE = 30;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO0_LO_UE = 31;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO0_HI_CE = 32;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO0_HI_UE = 33;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO1_CE = 34;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO1_UE = 35;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_RFIFO_CE = 36;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_RFIFO_UE = 37;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_ACTAG_CE = 38;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_ACTAG_UE = 39;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_SBE11 = 40;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_UE11 = 41;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_SBE12 = 42;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_UE12 = 43;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_SBE2 = 44;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_UE2 = 45;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_ILLEGAL_BDF_PASID_ERROR = 46;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_BAD_PE_HANDLE_ERROR = 47;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_OPCODE_VIOLATION_ERROR = 48;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_0B_WR_VIOLATION_ERROR = 49;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_PL_VIOLATION_INTRP_REQ_D = 50;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_HASHCAM_DECR_ERROR = 51;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_HASHCAM_OVERFLOW_ERROR = 52;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_HASHCAM_UNDERFLOW_ERROR = 53;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_CMD_ARRAY_OVERFLOW = 54;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_ARB_S2_POSTED_WRT_FAIL = 55;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_DAT_ARY_CE = 56;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXO_DAT_ARY_UE = 57;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO_OVERRUN = 58;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_RFIFO_OVERRUN = 59;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_CDFIFO_OVERRUN = 60;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_RDFIFO_OVERRUN = 61;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_DRL_RANGE = 62;
static const uint32_t OTL0_MISC_C_ERR_RPT_HOLD0_RXI_PKTFIELDRSVDVAL_DLEQ0 = 63;
// pau/reg00016.H

static const uint64_t OTL0_MISC_HAPPI_BAR1 = 0x10010a3cull;

static const uint32_t OTL0_MISC_HAPPI_BAR1_ENABLE = 0;
static const uint32_t OTL0_MISC_HAPPI_BAR1_ADDR = 1;
static const uint32_t OTL0_MISC_HAPPI_BAR1_ADDR_LEN = 21;
static const uint32_t OTL0_MISC_HAPPI_BAR1_MASK = 22;
static const uint32_t OTL0_MISC_HAPPI_BAR1_MASK_LEN = 21;
static const uint32_t OTL0_MISC_HAPPI_BAR1_SUB = 43;
static const uint32_t OTL0_MISC_HAPPI_BAR1_SUB_LEN = 21;
// pau/reg00016.H

static const uint64_t OTL0_MISC_PSL_TFC_AN = 0x10010a4aull;

static const uint32_t OTL0_MISC_PSL_TFC_AN_TFC_ACK = 28;
static const uint32_t OTL0_MISC_PSL_TFC_AN_C = 29;
static const uint32_t OTL0_MISC_PSL_TFC_AN_AE = 30;
static const uint32_t OTL0_MISC_PSL_TFC_AN_R = 31;
// pau/reg00016.H

static const uint64_t OTL1_MISC_ALTER_CREDIT_COUNTERS = 0x10010a60ull;

static const uint32_t OTL1_MISC_ALTER_CREDIT_COUNTERS_ENABLE = 0;
static const uint32_t OTL1_MISC_ALTER_CREDIT_COUNTERS_RESERVED = 1;
static const uint32_t OTL1_MISC_ALTER_CREDIT_COUNTERS_RESERVED_LEN = 3;
static const uint32_t OTL1_MISC_ALTER_CREDIT_COUNTERS_TARGET = 4;
static const uint32_t OTL1_MISC_ALTER_CREDIT_COUNTERS_TARGET_LEN = 4;
static const uint32_t OTL1_MISC_ALTER_CREDIT_COUNTERS_VALUE = 8;
static const uint32_t OTL1_MISC_ALTER_CREDIT_COUNTERS_VALUE_LEN = 16;
// pau/reg00016.H

static const uint64_t OTL1_MISC_CONFIG0 = 0x10010a50ull;

static const uint32_t OTL1_MISC_CONFIG0_EN = 0;
static const uint32_t OTL1_MISC_CONFIG0_BLOCK_PE_HANDLE = 1;
static const uint32_t OTL1_MISC_CONFIG0_BRICKID = 2;
static const uint32_t OTL1_MISC_CONFIG0_BRICKID_LEN = 2;
static const uint32_t OTL1_MISC_CONFIG0_PE_MASK = 4;
static const uint32_t OTL1_MISC_CONFIG0_PE_MASK_LEN = 4;
static const uint32_t OTL1_MISC_CONFIG0_RXO_RR2 = 8;
static const uint32_t OTL1_MISC_CONFIG0_RXO_RR2_LEN = 3;
static const uint32_t OTL1_MISC_CONFIG0_SPARE21 = 11;
static const uint32_t OTL1_MISC_CONFIG0_SPARE21_LEN = 21;
static const uint32_t OTL1_MISC_CONFIG0_CFIFO0_LO_ENABLE1 = 32;
static const uint32_t OTL1_MISC_CONFIG0_CFIFO0_LO_ENABLE2 = 33;
static const uint32_t OTL1_MISC_CONFIG0_CFIFO0_HI_ENABLE1 = 34;
static const uint32_t OTL1_MISC_CONFIG0_CFIFO0_HI_ENABLE2 = 35;
static const uint32_t OTL1_MISC_CONFIG0_CFIFO1_ENABLE1 = 36;
static const uint32_t OTL1_MISC_CONFIG0_CFIFO1_ENABLE2 = 37;
static const uint32_t OTL1_MISC_CONFIG0_RFIFO_ENABLE1 = 38;
static const uint32_t OTL1_MISC_CONFIG0_RFIFO_ENABLE2 = 39;
static const uint32_t OTL1_MISC_CONFIG0_ACTAG_ENABLE1 = 40;
static const uint32_t OTL1_MISC_CONFIG0_ACTAG_ENABLE2 = 41;
static const uint32_t OTL1_MISC_CONFIG0_CDFIFO_LO_ENABLE1 = 42;
static const uint32_t OTL1_MISC_CONFIG0_CDFIFO_LO_ENABLE2 = 43;
static const uint32_t OTL1_MISC_CONFIG0_CDFIFO_HI_ENABLE1 = 44;
static const uint32_t OTL1_MISC_CONFIG0_CDFIFO_HI_ENABLE2 = 45;
static const uint32_t OTL1_MISC_CONFIG0_RDFIFO_LO_ENABLE1 = 46;
static const uint32_t OTL1_MISC_CONFIG0_RDFIFO_LO_ENABLE2 = 47;
static const uint32_t OTL1_MISC_CONFIG0_RDFIFO_HI_ENABLE1 = 48;
static const uint32_t OTL1_MISC_CONFIG0_RDFIFO_HI_ENABLE2 = 49;
static const uint32_t OTL1_MISC_CONFIG0_BLOCK_TID_OVERRIDE = 50;
static const uint32_t OTL1_MISC_CONFIG0_ENABLE_4_0 = 51;
static const uint32_t OTL1_MISC_CONFIG0_VC1FIFO_LO_ENABLE1 = 52;
static const uint32_t OTL1_MISC_CONFIG0_VC1FIFO_LO_ENABLE2 = 53;
static const uint32_t OTL1_MISC_CONFIG0_VC1FIFO_HI_ENABLE1 = 54;
static const uint32_t OTL1_MISC_CONFIG0_VC1FIFO_HI_ENABLE2 = 55;
static const uint32_t OTL1_MISC_CONFIG0_VC2FIFO_LO_ENABLE1 = 56;
static const uint32_t OTL1_MISC_CONFIG0_VC2FIFO_LO_ENABLE2 = 57;
static const uint32_t OTL1_MISC_CONFIG0_DCP2FIFO_LO_ENABLE1 = 58;
static const uint32_t OTL1_MISC_CONFIG0_DCP2FIFO_LO_ENABLE2 = 59;
static const uint32_t OTL1_MISC_CONFIG0_DCP2FIFO_HI_ENABLE1 = 60;
static const uint32_t OTL1_MISC_CONFIG0_DCP2FIFO_HI_ENABLE2 = 61;
static const uint32_t OTL1_MISC_CONFIG0_XLATE_RELEASE_HAS_NO_ITAG = 62;
static const uint32_t OTL1_MISC_CONFIG0_ENABLE_5_0 = 63;
// pau/reg00016.H

static const uint64_t OTL1_MISC_C_ERR_RPT_HOLD0 = 0x10010a56ull;

static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_TL_CRD_OVF = 0;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_ACTAG_IDX = 1;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_ACTAG_INV = 2;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_OPC_RSVD = 3;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_RTC_POS = 4;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_TMPL = 5;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_TMPL_UNS = 6;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_TMPL_X00 = 7;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CTLFLIT_OVERRUN = 8;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_UNEXPECTED_DATA_FLIT = 9;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_LINK_DOWN = 10;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_BAD_DATA_RECEIVED_CMD = 11;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_BAD_DATA_RECEIVED_RESP = 12;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_RESPONSE_NOT_ALLOWED = 13;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_MISC_PERR = 14;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_TXO_PERR = 15;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_PERR_FRMD = 16;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_PERR_FRMC = 17;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_TXO_CBUF_CE = 18;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_TXO_CBUF_UE = 19;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_TXI_DBUF_CE = 20;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_TXI_DBUF_UE = 21;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CDFIFO_LO_CE = 22;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CDFIFO_LO_UE = 23;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CDFIFO_HI_CE = 24;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CDFIFO_HI_UE = 25;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_RDFIFO_LO_CE = 26;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_RDFIFO_LO_UE = 27;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_RDFIFO_HI_CE = 28;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_RDFIFO_HI_UE = 29;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO0_LO_CE = 30;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO0_LO_UE = 31;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO0_HI_CE = 32;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO0_HI_UE = 33;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO1_CE = 34;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO1_UE = 35;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_RFIFO_CE = 36;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_RFIFO_UE = 37;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_ACTAG_CE = 38;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_ACTAG_UE = 39;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_SBE11 = 40;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_UE11 = 41;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_SBE12 = 42;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_UE12 = 43;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_SBE2 = 44;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_UE2 = 45;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_ILLEGAL_BDF_PASID_ERROR = 46;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_BAD_PE_HANDLE_ERROR = 47;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_OPCODE_VIOLATION_ERROR = 48;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_0B_WR_VIOLATION_ERROR = 49;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_PL_VIOLATION_INTRP_REQ_D = 50;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_HASHCAM_DECR_ERROR = 51;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_HASHCAM_OVERFLOW_ERROR = 52;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_HASHCAM_UNDERFLOW_ERROR = 53;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_CMD_ARRAY_OVERFLOW = 54;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_ARB_S2_POSTED_WRT_FAIL = 55;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_DAT_ARY_CE = 56;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXO_DAT_ARY_UE = 57;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CFIFO_OVERRUN = 58;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_RFIFO_OVERRUN = 59;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_CDFIFO_OVERRUN = 60;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_RDFIFO_OVERRUN = 61;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_DRL_RANGE = 62;
static const uint32_t OTL1_MISC_C_ERR_RPT_HOLD0_RXI_PKTFIELDRSVDVAL_DLEQ0 = 63;
// pau/reg00016.H

static const uint64_t OTL1_MISC_ERROR_SIG_RXO = 0x10010a5full;

static const uint32_t OTL1_MISC_ERROR_SIG_RXO_TYPE = 0;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_TYPE_LEN = 3;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_XSL_RSP0 = 3;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_AFUTAG = 4;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_AFUTAG_LEN = 16;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_OPCODE = 20;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_OPCODE_LEN = 8;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_ACTAG = 28;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_ACTAG_LEN = 12;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_QINDEX = 40;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_QINDEX_LEN = 6;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_PE_HANDLE = 46;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_PE_HANDLE_LEN = 16;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_XSL_RSP12 = 62;
static const uint32_t OTL1_MISC_ERROR_SIG_RXO_XSL_RSP12_LEN = 2;
// pau/reg00016.H

static const uint64_t OTL1_MISC_OTL_REM0 = 0x10010a5dull;

static const uint32_t OTL1_MISC_OTL_REM0_VC0 = 0;
static const uint32_t OTL1_MISC_OTL_REM0_VC1 = 1;
static const uint32_t OTL1_MISC_OTL_REM0_VC2 = 2;
static const uint32_t OTL1_MISC_OTL_REM0_RSVD3 = 3;
static const uint32_t OTL1_MISC_OTL_REM0_DCP0 = 4;
static const uint32_t OTL1_MISC_OTL_REM0_DCP1 = 5;
static const uint32_t OTL1_MISC_OTL_REM0_RSVD6 = 6;
static const uint32_t OTL1_MISC_OTL_REM0_RSVD7 = 7;
// pau/reg00016.H

static const uint64_t OTL1_MISC_TLX_CREDIT_STATUS = 0x10010a61ull;

static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_VC0_COUNT = 0;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_VC0_COUNT_LEN = 8;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_VC1_COUNT = 8;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_VC1_COUNT_LEN = 8;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_VC2_COUNT = 16;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_VC2_COUNT_LEN = 8;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_VC3_COUNT = 24;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_VC3_COUNT_LEN = 8;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_DCP0_COUNT = 32;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_DCP0_COUNT_LEN = 8;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_DCP2_COUNT = 40;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_DCP2_COUNT_LEN = 8;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_DCP3_COUNT = 48;
static const uint32_t OTL1_MISC_TLX_CREDIT_STATUS_DCP3_COUNT_LEN = 8;
// pau/reg00016.H

static const uint64_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_SPAP_A0 = 0x10010a80ull;

static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_SPAP_A0_ADDR_DIAL = 4;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_SPAP_A0_ADDR_DIAL_LEN = 48;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_SPAP_A0_VALID_DIAL = 63;
// pau/reg00016.H

static const uint64_t XSL_MAIN_XSLOP_VLOG_RGS_ATD = 0x10010a96ull;

static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_ATD_XSL_ATD_DIAL = 0;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_ATD_XSL_ATD_DIAL_LEN = 64;
// pau/reg00016.H

static const uint64_t XSL_MAIN_WRAP_ERROR_2 = 0x10010aa8ull;

static const uint32_t XSL_MAIN_WRAP_ERROR_2_KILL_XLATE_EPOCH_TIMEOUT = 0;
static const uint32_t XSL_MAIN_WRAP_ERROR_2_BAR_SECURE_SMF_INSECURE = 1;
static const uint32_t XSL_MAIN_WRAP_ERROR_2_XLATE_IN_SUSPEND = 2;
static const uint32_t XSL_MAIN_WRAP_ERROR_2_UNSUPPORTED_PAGE_SIZE = 3;
static const uint32_t XSL_MAIN_WRAP_ERROR_2_XLAT_REL_FAIL_PI = 4;
static const uint32_t XSL_MAIN_WRAP_ERROR_2_KILL_XLATE_DONE_FAIL = 5;
static const uint32_t XSL_MAIN_WRAP_ERROR_2_XSL_INT_PAR_ERR = 6;
static const uint32_t XSL_MAIN_WRAP_ERROR_2_RESERVED_XSLO_2 = 7;
static const uint32_t XSL_MAIN_WRAP_ERROR_2_RESERVED_XSLO_2_LEN = 3;
static const uint32_t XSL_MAIN_WRAP_ERROR_2_XSL_WRAP_PAR_ERR = 10;
static const uint32_t XSL_MAIN_WRAP_ERROR_2_INVLD_PEHANDLE_ATL = 11;
// pau/reg00016.H

static const uint64_t XTS_ATSD_HYP4 = 0x10010b14ull;

static const uint32_t XTS_ATSD_HYP4_MSRHV = 51;
static const uint32_t XTS_ATSD_HYP4_LPARID = 52;
static const uint32_t XTS_ATSD_HYP4_LPARID_LEN = 12;
// pau/reg00016.H

static const uint64_t XTS_REG_ATRMISS2 = 0x10010afcull;

static const uint32_t XTS_REG_ATRMISS2_GPA = 27;
static const uint32_t XTS_REG_ATRMISS2_BDF = 28;
static const uint32_t XTS_REG_ATRMISS2_BDF_LEN = 16;
static const uint32_t XTS_REG_ATRMISS2_PASID = 44;
static const uint32_t XTS_REG_ATRMISS2_PASID_LEN = 20;
// pau/reg00016.H

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00016.H"
#endif
#endif
