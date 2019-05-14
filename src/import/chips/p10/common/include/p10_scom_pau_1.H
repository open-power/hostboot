/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_1.H $        */
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

#ifndef __p10_scom_pau_1_H_
#define __p10_scom_pau_1_H_


namespace scomt
{
namespace pau
{


static const uint64_t AME_AME1_MISC_CERR_RPT_MASK = 0x10010bd9ull;

static const uint32_t AME_AME1_MISC_CERR_RPT_MASK_CONFIG_CERR_RPT_MASK = 47;
static const uint32_t AME_AME1_MISC_CERR_RPT_MASK_CONFIG_CERR_RPT_MASK_LEN = 17;
// pau/reg00001.H

static const uint64_t AME_ATL_MISC_CERR_RPT_CONTROL = 0x10010bf9ull;

static const uint32_t AME_ATL_MISC_CERR_RPT_CONTROL_FIRSEL_UE = 19;
static const uint32_t AME_ATL_MISC_CERR_RPT_CONTROL_FIRSEL_UE_LEN = 8;
static const uint32_t AME_ATL_MISC_CERR_RPT_CONTROL_FIRSEL_DATA_UE = 27;
static const uint32_t AME_ATL_MISC_CERR_RPT_CONTROL_FIRSEL_DATA_UE_LEN = 5;
static const uint32_t AME_ATL_MISC_CERR_RPT_CONTROL_RPT_MASK = 32;
static const uint32_t AME_ATL_MISC_CERR_RPT_CONTROL_RPT_MASK_LEN = 32;
// pau/reg00001.H

static const uint64_t AME_ATL_MISC_PMU_CONFIG = 0x10010bf3ull;

static const uint32_t AME_ATL_MISC_PMU_CONFIG_ENABLE = 0;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_RESETMODE = 1;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_FREEZEMODE = 2;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_DISABLE_PMISC = 3;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_PMISC_MODE = 4;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_CASCADE = 5;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_CASCADE_LEN = 3;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_PRESCALE_C0 = 8;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_PRESCALE_C0_LEN = 2;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_PRESCALE_C1 = 10;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_PRESCALE_C1_LEN = 2;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_PRESCALE_C2 = 12;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_PRESCALE_C2_LEN = 2;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_PRESCALE_C3 = 14;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_PRESCALE_C3_LEN = 2;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_OPERATION_C0 = 16;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_OPERATION_C0_LEN = 2;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_OPERATION_C1 = 18;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_OPERATION_C1_LEN = 2;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_OPERATION_C2 = 20;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_OPERATION_C2_LEN = 2;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_OPERATION_C3 = 22;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_OPERATION_C3_LEN = 2;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_EVENTS_C0 = 24;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_EVENTS_C0_LEN = 8;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_EVENTS_C1 = 32;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_EVENTS_C1_LEN = 8;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_EVENTS_C2 = 40;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_EVENTS_C2_LEN = 8;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_EVENTS_C3 = 48;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_EVENTS_C3_LEN = 8;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_RESERVED0 = 56;
static const uint32_t AME_ATL_MISC_PMU_CONFIG_RESERVED0_LEN = 8;
// pau/reg00001.H

static const uint64_t AME_ATL_MISC_TEST_CERR_RPT = 0x10010bfbull;

static const uint32_t AME_ATL_MISC_TEST_CERR_RPT_TEST_CERR_BITSEL = 59;
static const uint32_t AME_ATL_MISC_TEST_CERR_RPT_TEST_CERR_BITSEL_LEN = 5;
// pau/reg00001.H

static const uint64_t ATS_REG_HOLD = 0x10010ab5ull;

static const uint32_t ATS_REG_HOLD_TVT_ENTRY_INVALID_ESR = 0;
static const uint32_t ATS_REG_HOLD_TVT_ADDR_RANGE_ERR_ESR = 1;
static const uint32_t ATS_REG_HOLD_TCE_PAGE_ACCESS_ERR_ESR = 2;
static const uint32_t ATS_REG_HOLD_TCE_CACHE_MULT_HIT_ERR_ESR = 3;
static const uint32_t ATS_REG_HOLD_MLC_ACCESS_ERR_ESR = 4;
static const uint32_t ATS_REG_HOLD_TCE_REQ_TO_ERR_ESR = 5;
static const uint32_t ATS_REG_HOLD_TCD_PERR_ESR = 6;
static const uint32_t ATS_REG_HOLD_TDR_PERR_ESR = 7;
static const uint32_t ATS_REG_HOLD_AT_EA_UE_ESR = 8;
static const uint32_t ATS_REG_HOLD_AT_EA_CE_ESR = 9;
static const uint32_t ATS_REG_HOLD_AT_TDRMEM_UE_ESR = 10;
static const uint32_t ATS_REG_HOLD_AT_TDRMEM_CE_ESR = 11;
static const uint32_t ATS_REG_HOLD_RSPOUT_UE_ESR = 12;
static const uint32_t ATS_REG_HOLD_RSPOUT_CE_ESR = 13;
static const uint32_t ATS_REG_HOLD_TVT_PERR_ESR = 14;
static const uint32_t ATS_REG_HOLD_IODA_ADDR_PERR_ESR = 15;
static const uint32_t ATS_REG_HOLD_ATS_CTRLR_PERR_ESR = 16;
static const uint32_t ATS_REG_HOLD_ATS_TOR_PERR_ESR = 17;
static const uint32_t ATS_REG_HOLD_INVAL_IODA_TBL_SEL_ESR = 18;
static const uint32_t ATS_REG_HOLD_ESR_RSVD_19 = 19;
// pau/reg00001.H

static const uint64_t CS_CTL_MISC_BDF2PE_3_CONFIG = 0x100109b3ull;

static const uint32_t CS_CTL_MISC_BDF2PE_3_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_3_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_3_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_3_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_3_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_3_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_3_CONFIG_BDF_LEN = 16;
// pau/reg00001.H

static const uint64_t CS_CTL_MISC_CERR_HOLD0 = 0x1001099full;

static const uint32_t CS_CTL_MISC_CERR_HOLD0_NCF_0 = 0;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NCF_1 = 1;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NCF_2 = 2;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NCF_3 = 3;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_0 = 4;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_1 = 5;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_2 = 6;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_3 = 7;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_4 = 8;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_5 = 9;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_6 = 10;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_7 = 11;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_8 = 12;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_9 = 13;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_10 = 14;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_11 = 15;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_12 = 16;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_13 = 17;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_14 = 18;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_15 = 19;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_16 = 20;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_17 = 21;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_18 = 22;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_19 = 23;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_20 = 24;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_21 = 25;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_22 = 26;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_NVF_23 = 27;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_0 = 28;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_1 = 29;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_2 = 30;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_3 = 31;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_4 = 32;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_5 = 33;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_6 = 34;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_7 = 35;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_8 = 36;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_9 = 37;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_10 = 38;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_OCR_11 = 39;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_ASBE_0 = 40;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_ASBE_1 = 41;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_ASBE_2 = 42;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_ASBE_3 = 43;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_ASBE_4 = 44;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_ASBE_5 = 45;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_ASBE_6 = 46;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_ASBE_7 = 47;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_PBR_0 = 48;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_PBR_1 = 49;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_PBR_2 = 50;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_PBR_3 = 51;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_REG_0 = 52;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_REG_1 = 53;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_REG_2 = 54;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_REG_3 = 55;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_DUE_0 = 56;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_DUE_1 = 57;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_DUE_2 = 58;
static const uint32_t CS_CTL_MISC_CERR_HOLD0_DUE_3 = 59;
// pau/reg00001.H

static const uint64_t CS_SM0_MCP_MISC_DEBUG0_CONFIG = 0x1001081aull;

static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM0_MCP_MISC_DEBUG0_CONFIG_ACT = 63;
// pau/reg00001.H

static const uint64_t CS_SM0_SNP_MISC_CONFIG1 = 0x10010831ull;

static const uint32_t CS_SM0_SNP_MISC_CONFIG1__SCALE_RPT_HANG_POLL = 0;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__SCALE_RPT_HANG_POLL_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__SCALE_RPT_HANG_DATA = 4;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__SCALE_RPT_HANG_DATA_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__HOST_TAG_SIZE = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__HOST_TAG_SIZE_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__ARB_NONCRR_SAFETY = 12;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__ARB_NONCRR_SAFETY_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__REPLAY_IP_LIMIT = 16;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__REPLAY_IP_LIMIT_LEN = 3;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1_1_RESERVED1 = 19;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__BLOCK_FOR_REPLAY_TIME = 20;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__BLOCK_FOR_REPLAY_TIME_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__BLOCK_FOR_DIRSCAN_TIME = 24;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__BLOCK_FOR_DIRSCAN_TIME_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__THROT_ADDR_HASH = 28;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1__THROT_ADDR_HASH_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1_1_RESERVED2 = 30;
static const uint32_t CS_SM0_SNP_MISC_CONFIG1_1_RESERVED2_LEN = 34;
// pau/reg00001.H

static const uint64_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4 = 0x10010842ull;

static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_TAG = 0;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_TAG_LEN = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_TAGMASK = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_TAGMASK_LEN = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_PAU = 28;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_PCIE = 29;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_L2L3 = 30;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_RESERVED1 = 31;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_RDSTART = 32;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_RDSTART_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_RDEND = 40;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_RDEND_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_WRSTART = 48;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_WRSTART_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_WREND = 56;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC4_WREND_LEN = 8;
// pau/reg00001.H

static const uint64_t CS_SM1_DIR_MISC_DEBUG0_CONFIG = 0x1001088aull;

static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM1_DIR_MISC_DEBUG0_CONFIG_ACT = 63;
// pau/reg00001.H

static const uint64_t CS_SM1_MCP_MISC_CERR_MESSAGE5 = 0x1001086bull;

static const uint32_t CS_SM1_MCP_MISC_CERR_MESSAGE5_CERR_MESSAGE_BITS5 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_MESSAGE5_CERR_MESSAGE_BITS5_LEN = 64;
// pau/reg00001.H

static const uint64_t CS_SM1_SNP_MISC_PERF_ADDR_CONFIG = 0x100108b6ull;

static const uint32_t CS_SM1_SNP_MISC_PERF_ADDR_CONFIG_SIZE_ADDR = 0;
static const uint32_t CS_SM1_SNP_MISC_PERF_ADDR_CONFIG_SIZE_ADDR_LEN = 6;
static const uint32_t CS_SM1_SNP_MISC_PERF_ADDR_CONFIG_MATCH_ADDR = 6;
static const uint32_t CS_SM1_SNP_MISC_PERF_ADDR_CONFIG_MATCH_ADDR_LEN = 36;
static const uint32_t CS_SM1_SNP_MISC_PERF_ADDR_CONFIG_ADDR_RESERVED1 = 42;
static const uint32_t CS_SM1_SNP_MISC_PERF_ADDR_CONFIG_ADDR_RESERVED1_LEN = 2;
// pau/reg00001.H

static const uint64_t CS_SM2_MCP_MISC_CONFIG2 = 0x100108deull;

static const uint32_t CS_SM2_MCP_MISC_CONFIG2__MCP_FIR_TO_INHIBIT_MASK = 0;
static const uint32_t CS_SM2_MCP_MISC_CONFIG2__MCP_FIR_TO_INHIBIT_MASK_LEN = 12;
static const uint32_t CS_SM2_MCP_MISC_CONFIG2__BRK0_FENCE_TO_INHIBIT_MASK = 12;
static const uint32_t CS_SM2_MCP_MISC_CONFIG2__BRK1_FENCE_TO_INHIBIT_MASK = 13;
static const uint32_t CS_SM2_MCP_MISC_CONFIG2__BRK2_FENCE_TO_INHIBIT_MASK = 14;
static const uint32_t CS_SM2_MCP_MISC_CONFIG2__BRK3_FENCE_TO_INHIBIT_MASK = 15;
static const uint32_t CS_SM2_MCP_MISC_CONFIG2__BRK4_FENCE_TO_INHIBIT_MASK = 16;
static const uint32_t CS_SM2_MCP_MISC_CONFIG2_2_RESERVED = 17;
static const uint32_t CS_SM2_MCP_MISC_CONFIG2_2_RESERVED_LEN = 47;
// pau/reg00001.H

static const uint64_t CS_SM2_MCP_MISC_SM_STATUS = 0x100108ceull;

static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_MRBGP = 0;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_MRBGP_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_MRBSP = 4;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_MRBSP_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FENCE0 = 8;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FENCE0_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FENCE1 = 12;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FENCE1_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FENCE2 = 16;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FENCE2_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FENCE3 = 20;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FENCE3_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FENCE4 = 24;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FENCE4_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_PBLN = 28;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_PBNNG = 29;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_PBRNVG = 30;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B0REQ = 31;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B0DGD = 32;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B1REQ = 33;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B1DGD = 34;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B2REQ = 35;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B2DGD = 36;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B3REQ = 37;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B3DGD = 38;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B4REQ = 39;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B4DGD = 40;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_MMIO = 41;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_MMIOSUE = 42;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_ATSXLATE = 43;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_REPLAY = 44;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_PBRSP = 45;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B0RSP = 46;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B1RSP = 47;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B2RSP = 48;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B3RSP = 49;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_B4RSP = 50;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_XARSP = 51;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_FREE = 52;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_DIRUPD = 53;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_SACOLL = 54;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_MRBCP = 55;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_MRBCP_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_PERF_LSTATE = 59;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_PERF_LSTATE_LEN = 2;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_RESERVED2 = 61;
static const uint32_t CS_SM2_MCP_MISC_SM_STATUS_RESERVED2_LEN = 3;
// pau/reg00001.H

static const uint64_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4 = 0x10010902ull;

static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_TAG = 0;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_TAG_LEN = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_TAGMASK = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_TAGMASK_LEN = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_PAU = 28;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_PCIE = 29;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_L2L3 = 30;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_RESERVED1 = 31;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_RDSTART = 32;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_RDSTART_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_RDEND = 40;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_RDEND_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_WRSTART = 48;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_WRSTART_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_WREND = 56;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC4_WREND_LEN = 8;
// pau/reg00001.H

static const uint64_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2 = 0x1001091eull;

static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_ABLE_16_23 = 0;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_ABLE_16_23_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY16 = 8;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY16_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY17 = 12;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY17_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY18 = 16;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY18_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY19 = 20;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY19_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY20 = 24;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY20_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY21 = 28;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY21_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY22 = 32;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY22_LEN = 4;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY23 = 36;
static const uint32_t CS_SM2_SNP_MISC_TOPOLOGY_TABLE2_TRY23_LEN = 4;
// pau/reg00001.H

static const uint64_t CS_SM3_MCP_MISC_CERR_MASK1 = 0x10010933ull;

static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_NLGX_0 = 0;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_NLGX_1 = 1;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_NLGX_2 = 2;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_NLGX_3 = 3;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_FWD_0 = 4;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_FWD_1 = 5;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_FWD_2 = 6;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_FWD_3 = 7;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_AUE_0 = 8;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_AUE_1 = 9;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_AUE_2 = 10;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_AUE_3 = 11;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_AUE_4 = 12;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_AUE_5 = 13;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_AUE_6 = 14;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_AUE_7 = 15;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_0 = 16;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_1 = 17;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_2 = 18;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_3 = 19;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_4 = 20;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_5 = 21;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_6 = 22;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_7 = 23;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_8 = 24;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_9 = 25;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_10 = 26;
static const uint32_t CS_SM3_MCP_MISC_CERR_MASK1_PBF_11 = 27;
// pau/reg00001.H

static const uint64_t CS_SM3_MCP_MISC_CERR_MESSAGE0 = 0x10010926ull;

static const uint32_t CS_SM3_MCP_MISC_CERR_MESSAGE0_CERR_MESSAGE_BITS0 = 0;
static const uint32_t CS_SM3_MCP_MISC_CERR_MESSAGE0_CERR_MESSAGE_BITS0_LEN = 64;
// pau/reg00001.H

static const uint64_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG = 0x10010939ull;

static const uint32_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG_RESERVED2 = 0;
static const uint32_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG_RESERVED2_LEN = 24;
static const uint32_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG_CRESP = 24;
static const uint32_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG_CRESP_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG_SCOPE = 29;
static const uint32_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG_SCOPE_LEN = 3;
static const uint32_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG_MCMD = 32;
static const uint32_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG_MCMD_LEN = 10;
static const uint32_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG_RESERVED1 = 42;
static const uint32_t CS_SM3_MCP_MISC_PERF_MASK_CONFIG_RESERVED1_LEN = 2;
// pau/reg00001.H

static const uint64_t CS_SM3_SNP_MISC_CERR_HOLD0 = 0x10010975ull;

static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NCF_0 = 0;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NCF_1 = 1;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NCF_2 = 2;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NCF_3 = 3;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NCF_4 = 4;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NCF_5 = 5;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NCF_6 = 6;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NCF_7 = 7;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBR_0 = 8;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBR_1 = 9;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBR_2 = 10;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBR_3 = 11;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBR_4 = 12;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBR_5 = 13;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBR_6 = 14;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBR_7 = 15;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBP_0 = 16;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBP_1 = 17;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBP_2 = 18;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBP_3 = 19;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBP_4 = 20;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBP_5 = 21;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBP_6 = 22;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBP_7 = 23;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_0 = 24;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_1 = 25;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_2 = 26;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_3 = 27;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_4 = 28;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_5 = 29;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_6 = 30;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_7 = 31;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_8 = 32;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_9 = 33;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_10 = 34;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_PBC_11 = 35;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_0 = 36;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_1 = 37;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_2 = 38;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_3 = 39;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_4 = 40;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_5 = 41;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_6 = 42;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_7 = 43;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_8 = 44;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_9 = 45;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_10 = 46;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_11 = 47;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_12 = 48;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_13 = 49;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_14 = 50;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_15 = 51;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_16 = 52;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_17 = 53;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_18 = 54;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_19 = 55;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_20 = 56;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_21 = 57;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_22 = 58;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_NLG_23 = 59;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_SMV_0 = 60;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_SMV_1 = 61;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_SMV_2 = 62;
static const uint32_t CS_SM3_SNP_MISC_CERR_HOLD0_SMV_3 = 63;
// pau/reg00001.H

static const uint64_t MISC_REGS_BDF2PE_3_CONFIG = 0x10010b53ull;

static const uint32_t MISC_REGS_BDF2PE_3_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_3_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_3_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_3_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_3_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_3_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_3_CONFIG_BDF_LEN = 16;
// pau/reg00001.H

static const uint64_t MISC_REGS_HOLD = 0x10010b34ull;

static const uint32_t MISC_REGS_HOLD_NDL0_STALL = 0;
static const uint32_t MISC_REGS_HOLD_NDL0_NOSTALL = 1;
static const uint32_t MISC_REGS_HOLD_NDL1_STALL = 2;
static const uint32_t MISC_REGS_HOLD_NDL1_NOSTALL = 3;
static const uint32_t MISC_REGS_HOLD_MISC_RING_ERRP = 4;
static const uint32_t MISC_REGS_HOLD_MISC_IBAR_ERRP = 5;
static const uint32_t MISC_REGS_HOLD_MISC_SCOMDAA_ERRP = 6;
static const uint32_t MISC_REGS_HOLD_MISC_CNTL_ERRP = 7;
static const uint32_t MISC_REGS_HOLD_RESERVED = 8;
static const uint32_t MISC_REGS_HOLD_RX00_FAULT = 9;
static const uint32_t MISC_REGS_HOLD_RX01_FAULT = 10;
static const uint32_t MISC_REGS_HOLD_RX20_FAULT = 11;
// pau/reg00001.H

static const uint64_t NTL1_REGS_CONFIG1 = 0x10010a18ull;

static const uint32_t NTL1_REGS_CONFIG1_COMPRESSED_RSP_ENA = 0;
static const uint32_t NTL1_REGS_CONFIG1_CONFIG1_RESERVED1 = 1;
static const uint32_t NTL1_REGS_CONFIG1_CONFIG1_RESERVED1_LEN = 3;
static const uint32_t NTL1_REGS_CONFIG1_CREQ_AE_ALWAYS = 4;
static const uint32_t NTL1_REGS_CONFIG1_DGD_AE_ALWAYS = 5;
static const uint32_t NTL1_REGS_CONFIG1_RSP_AE_ALWAYS = 6;
static const uint32_t NTL1_REGS_CONFIG1_CONFIG1_RESERVED2 = 7;
static const uint32_t NTL1_REGS_CONFIG1_NTL_RESET = 8;
static const uint32_t NTL1_REGS_CONFIG1_NTL_RESET_LEN = 2;
static const uint32_t NTL1_REGS_CONFIG1_CONFIG1_RESERVED3 = 10;
static const uint32_t NTL1_REGS_CONFIG1_CONFIG1_RESERVED3_LEN = 54;
// pau/reg00001.H

static const uint64_t OTL0_MISC_CONFIG3 = 0x10010a3full;

static const uint32_t OTL0_MISC_CONFIG3_ENABLE_HAPPI = 0;
static const uint32_t OTL0_MISC_CONFIG3_CONFIG3_SPARE = 1;
static const uint32_t OTL0_MISC_CONFIG3_CONFIG3_SPARE_LEN = 31;
// pau/reg00001.H

static const uint64_t OTL0_MISC_HAPPI_BAR3 = 0x10010a3eull;

static const uint32_t OTL0_MISC_HAPPI_BAR3_ENABLE = 0;
static const uint32_t OTL0_MISC_HAPPI_BAR3_ADDR = 1;
static const uint32_t OTL0_MISC_HAPPI_BAR3_ADDR_LEN = 21;
static const uint32_t OTL0_MISC_HAPPI_BAR3_MASK = 22;
static const uint32_t OTL0_MISC_HAPPI_BAR3_MASK_LEN = 21;
static const uint32_t OTL0_MISC_HAPPI_BAR3_SUB = 43;
static const uint32_t OTL0_MISC_HAPPI_BAR3_SUB_LEN = 21;
// pau/reg00001.H

static const uint64_t OTL0_MISC_PSL_PEHANDLE_AN = 0x10010a4bull;

static const uint32_t OTL0_MISC_PSL_PEHANDLE_AN_AFUTAG = 16;
static const uint32_t OTL0_MISC_PSL_PEHANDLE_AN_AFUTAG_LEN = 16;
static const uint32_t OTL0_MISC_PSL_PEHANDLE_AN_PE_HANDLE = 48;
static const uint32_t OTL0_MISC_PSL_PEHANDLE_AN_PE_HANDLE_LEN = 16;
// pau/reg00001.H

static const uint64_t OTL1_MISC_PSL_PEHANDLE_AN = 0x10010a7bull;

static const uint32_t OTL1_MISC_PSL_PEHANDLE_AN_AFUTAG = 16;
static const uint32_t OTL1_MISC_PSL_PEHANDLE_AN_AFUTAG_LEN = 16;
static const uint32_t OTL1_MISC_PSL_PEHANDLE_AN_PE_HANDLE = 48;
static const uint32_t OTL1_MISC_PSL_PEHANDLE_AN_PE_HANDLE_LEN = 16;
// pau/reg00001.H

static const uint64_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_SPAP_A2 = 0x10010a82ull;

static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_SPAP_A2_ADDR_DIAL = 4;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_SPAP_A2_ADDR_DIAL_LEN = 48;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_SPAP_A2_VALID_DIAL = 63;
// pau/reg00001.H

static const uint64_t XSL_MAIN_WRAP_ERROR_0 = 0x10010aa6ull;

static const uint32_t XSL_MAIN_WRAP_ERROR_0_MMIO_INVALIDATE_REQ_WHILE_1_INPROG = 0;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_UNEXPECTED_ITAG_PORT_0 = 1;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_UNEXPECTED_ITAG_PORT_1 = 2;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_UNEXPECTED_RD_PEE_COMPLETION = 3;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_UNEXPECTED_CO_RESP = 4;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_XLAT_REQ_WHILE_SPAP_INVALID = 5;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_INVALID_PEE = 6;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_BLOOM_FILTER_ARY_ERROR = 7;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_TRANSLATION_REQ_TO_INVALID_TA = 8;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_TA_XLATE_RELEASE_TO_INVALID = 9;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_TRKR0_SBE_ERROR = 10;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_TRKR1_SBE_ERROR = 11;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_IDBA0_SBE_ERROR = 12;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_IDBA1_SBE_ERROR = 13;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_FITA_SBE_ERROR = 14;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX0A_SBE_ERROR = 15;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX0B_SBE_ERROR = 16;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX1A_SBE_ERROR = 17;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX1B_SBE_ERROR = 18;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX2A_SBE_ERROR = 19;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX2B_SBE_ERROR = 20;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX3A_SBE_ERROR = 21;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX3B_SBE_ERROR = 22;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT0_LO_SBE_ERROR = 23;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT0_MID_SBE_ERROR = 24;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT0_HI_SBE_ERROR = 25;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT1_LO_SBE_ERROR = 26;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT1_MID_SBE_ERROR = 27;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT1_HI_SBE_ERROR = 28;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT2_LO_SBE_ERROR = 29;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT2_MID_SBE_ERROR = 30;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT2_HI_SBE_ERROR = 31;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT3_LO_SBE_ERROR = 32;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT3_MID_SBE_ERROR = 33;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_ERT3_HI_SBE_ERROR = 34;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_TADB_LO_SBE_ERROR = 35;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_TADB_MID_SBE_ERROR = 36;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_TADB_HI_SBE_ERROR = 37;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_COSB_LO_SBE_ERROR = 38;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_COSB_MID_SBE_ERROR = 39;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_COSB_HI_SBE_ERROR = 40;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_TRKR0_UE_ERROR = 41;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_TRKR1_UE_ERROR = 42;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_IDBA0_UE_ERROR = 43;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_IDBA1_UE_ERROR = 44;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_FITA_UE_ERROR = 45;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX0A_UE_ERROR = 46;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX0B_UE_ERROR = 47;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX1A_UE_ERROR = 48;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX1B_UE_ERROR = 49;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX2A_UE_ERROR = 50;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX2B_UE_ERROR = 51;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX3A_UE_ERROR = 52;
static const uint32_t XSL_MAIN_WRAP_ERROR_0_CTX3B_UE_ERROR = 53;
// pau/reg00001.H

static const uint64_t XTS_ATSD_HYP6 = 0x10010b16ull;

static const uint32_t XTS_ATSD_HYP6_MSRHV = 51;
static const uint32_t XTS_ATSD_HYP6_LPARID = 52;
static const uint32_t XTS_ATSD_HYP6_LPARID_LEN = 12;
// pau/reg00001.H

}
}
#include "pau/reg00001.H"
#endif
