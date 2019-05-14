/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_9.H $        */
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

#ifndef __p10_scom_pau_9_H_
#define __p10_scom_pau_9_H_


namespace scomt
{
namespace pau
{


static const uint64_t AME_AME0_MISC_TEST_CERR_RPT = 0x10010bcbull;

static const uint32_t AME_AME0_MISC_TEST_CERR_RPT_TEST_CERR_BITSEL = 59;
static const uint32_t AME_AME0_MISC_TEST_CERR_RPT_TEST_CERR_BITSEL_LEN = 5;
// pau/reg00012.H

static const uint64_t AME_AME2_MISC_INHIBIT_CONFIG = 0x10010be3ull;

static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_LFREQ0 = 0;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_LFREQ0_LEN = 4;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_RESERVED0 = 4;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_RESERVED0_LEN = 2;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_TFREQ0 = 6;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_TFREQ0_LEN = 6;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_PFREQ0 = 12;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_PFREQ0_LEN = 2;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_BLOCKY0 = 14;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_ONESHOT0 = 15;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_DEST0 = 16;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_DEST0_LEN = 8;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_LFREQ1 = 24;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_LFREQ1_LEN = 4;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_RESERVED1 = 28;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_RESERVED1_LEN = 2;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_TFREQ1 = 30;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_TFREQ1_LEN = 6;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_PFREQ1 = 36;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_PFREQ1_LEN = 2;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_BLOCKY1 = 38;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_ONESHOT1 = 39;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_DEST1 = 40;
static const uint32_t AME_AME2_MISC_INHIBIT_CONFIG_DEST1_LEN = 8;
// pau/reg00012.H

static const uint64_t ATS_REG_PAU_AT_ESMR = 0x10010ad8ull;

static const uint32_t ATS_REG_PAU_AT_ESMR_IDIAL_ATS_ESR_MSK = 0;
static const uint32_t ATS_REG_PAU_AT_ESMR_IDIAL_ATS_ESR_MSK_LEN = 20;
// pau/reg00012.H

static const uint64_t CS_CTL_MISC_BDF2PE_12_CONFIG = 0x100109bcull;

static const uint32_t CS_CTL_MISC_BDF2PE_12_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_12_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_12_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_12_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_12_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_12_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_12_CONFIG_BDF_LEN = 16;
// pau/reg00012.H

static const uint64_t CS_CTL_MISC_BDF2PE_9_CONFIG = 0x100109b9ull;

static const uint32_t CS_CTL_MISC_BDF2PE_9_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_9_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_9_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_9_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_9_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_9_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_9_CONFIG_BDF_LEN = 16;
// pau/reg00012.H

static const uint64_t CS_CTL_MISC_MMIOPA1_CONFIG = 0x10010994ull;

static const uint32_t CS_CTL_MISC_MMIOPA1_CONFIG_RESERVED1 = 0;
static const uint32_t CS_CTL_MISC_MMIOPA1_CONFIG_ADDR = 1;
static const uint32_t CS_CTL_MISC_MMIOPA1_CONFIG_ADDR_LEN = 35;
static const uint32_t CS_CTL_MISC_MMIOPA1_CONFIG_RESERVED2 = 36;
static const uint32_t CS_CTL_MISC_MMIOPA1_CONFIG_RESERVED2_LEN = 3;
static const uint32_t CS_CTL_MISC_MMIOPA1_CONFIG_SIZE = 39;
static const uint32_t CS_CTL_MISC_MMIOPA1_CONFIG_SIZE_LEN = 5;
// pau/reg00012.H

static const uint64_t CS_CTL_MISC_SCOPE_PREDICT1 = 0x100109acull;

static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_LN_FAIL_THRESH = 0;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_LN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_NN_FAIL_THRESH = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_NN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_RN_FAIL_THRESH = 6;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_RN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_G_FAIL_THRESH = 9;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_G_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_LN_INTV_THRESH = 12;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_LN_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_G_INTV_THRESH = 15;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_G_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1RD_VG_ENABLE = 18;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1_1_RESERVED1 = 19;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_LN_FAIL_THRESH = 20;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_LN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_NN_FAIL_THRESH = 23;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_NN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_RN_FAIL_THRESH = 26;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_RN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_G_FAIL_THRESH = 29;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_G_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_LN_INTV_THRESH = 32;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_LN_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_G_INTV_THRESH = 35;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_G_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__B1WR_VG_ENABLE = 38;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1_1_RESERVED2 = 39;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__TIMER_RAND = 40;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__TIMER_RAND_LEN = 4;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__TIMER_MAX = 44;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT1__TIMER_MAX_LEN = 4;
// pau/reg00012.H

static const uint64_t CS_SM0_MCP_MISC_CERR_HOLD2 = 0x10010817ull;

static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_0 = 0;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_1 = 1;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_2 = 2;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_3 = 3;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_4 = 4;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_5 = 5;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_6 = 6;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_7 = 7;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_8 = 8;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_9 = 9;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_10 = 10;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_11 = 11;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_12 = 12;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_13 = 13;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_14 = 14;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_15 = 15;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_16 = 16;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_17 = 17;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_18 = 18;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_19 = 19;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_20 = 20;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_21 = 21;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_22 = 22;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_23 = 23;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_24 = 24;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_25 = 25;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_26 = 26;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_27 = 27;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_28 = 28;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_29 = 29;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_30 = 30;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_31 = 31;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_32 = 32;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_33 = 33;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_34 = 34;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_35 = 35;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_36 = 36;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_37 = 37;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_38 = 38;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_39 = 39;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_40 = 40;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_41 = 41;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_42 = 42;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_43 = 43;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_44 = 44;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_45 = 45;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_46 = 46;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_47 = 47;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_48 = 48;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_49 = 49;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_50 = 50;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_51 = 51;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_52 = 52;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_53 = 53;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_54 = 54;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_55 = 55;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_56 = 56;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_57 = 57;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_58 = 58;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_59 = 59;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_60 = 60;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_61 = 61;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_62 = 62;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD2_63 = 63;
// pau/reg00012.H

static const uint64_t CS_SM0_MCP_MISC_CERR_MESSAGE0 = 0x10010806ull;

static const uint32_t CS_SM0_MCP_MISC_CERR_MESSAGE0_CERR_MESSAGE_BITS0 = 0;
static const uint32_t CS_SM0_MCP_MISC_CERR_MESSAGE0_CERR_MESSAGE_BITS0_LEN = 64;
// pau/reg00012.H

static const uint64_t CS_SM1_MCP_MISC_CONFIG1 = 0x10010861ull;

static const uint32_t CS_SM1_MCP_MISC_CONFIG1__RANDOM_BACKOFF_DUR_MASK = 0;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__RANDOM_BACKOFF_DUR_MASK_LEN = 4;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_REQ = 4;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_REQ_LEN = 4;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_CST = 8;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_CST_LEN = 4;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_PRB = 12;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_PRB_LEN = 4;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__EPSILON_WLN_COUNT = 16;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__EPSILON_WLN_COUNT_LEN = 12;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1_1_RESERVED2 = 28;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1_1_RESERVED2_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__PCKT_LONG_CL_DMA_INJ = 35;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__PCKT_LONG_PR_DMA_INJ = 36;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__PCKT_LONG_MIN_COUNT = 37;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__PCKT_LONG_MIN_COUNT_LEN = 6;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__PCKT_LONG_USES_HANG = 43;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__DONT_RETRY_LCO_LONG = 44;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__DONT_RETRY_LCO_LONG_STRESSED = 45;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__DONT_RETRY_LCO_SHORT = 46;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__DONT_RETRY_LCO_SHORT_STRESSED = 47;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__STOP_ASB_AT_LN_SCOPE = 48;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__STOP_ASB_AT_G_SCOPE = 49;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__INITIAL_HPC_PROBE_PRIORITY = 50;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1__NVLINK_P9P9_MODE = 51;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1_1_RESERVED = 52;
static const uint32_t CS_SM1_MCP_MISC_CONFIG1_1_RESERVED_LEN = 12;
// pau/reg00012.H

static const uint64_t CS_SM1_MCP_MISC_EPSILON_CONFIG = 0x10010862ull;

static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_RATE = 0;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_RATE_LEN = 4;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_W0_COUNT = 4;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_W0_COUNT_LEN = 12;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_W1_COUNT = 16;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_W1_COUNT_LEN = 12;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_R0_COUNT = 28;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_R0_COUNT_LEN = 12;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_R1_COUNT = 40;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_R1_COUNT_LEN = 12;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_R2_COUNT = 52;
static const uint32_t CS_SM1_MCP_MISC_EPSILON_CONFIG_R2_COUNT_LEN = 12;
// pau/reg00012.H

static const uint64_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4 = 0x100108a2ull;

static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_TAG = 0;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_TAG_LEN = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_TAGMASK = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_TAGMASK_LEN = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_PAU = 28;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_PCIE = 29;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_L2L3 = 30;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_RESERVED1 = 31;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_RDSTART = 32;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_RDSTART_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_RDEND = 40;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_RDEND_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_WRSTART = 48;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_WRSTART_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_WREND = 56;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC4_WREND_LEN = 8;
// pau/reg00012.H

static const uint64_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2 = 0x100108beull;

static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_ABLE_16_23 = 0;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_ABLE_16_23_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY16 = 8;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY16_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY17 = 12;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY17_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY18 = 16;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY18_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY19 = 20;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY19_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY20 = 24;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY20_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY21 = 28;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY21_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY22 = 32;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY22_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY23 = 36;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE2_TRY23_LEN = 4;
// pau/reg00012.H

static const uint64_t CS_SM2_DIR_MISC_DEBUG0_CONFIG = 0x100108eaull;

static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM2_DIR_MISC_DEBUG0_CONFIG_ACT = 63;
// pau/reg00012.H

static const uint64_t CS_SM2_MCP_MISC_CERR_MASK0 = 0x100108d2ull;

static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_0 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_1 = 1;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_2 = 2;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_3 = 3;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_4 = 4;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_5 = 5;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_6 = 6;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_7 = 7;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_8 = 8;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_9 = 9;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_10 = 10;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_11 = 11;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_12 = 12;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_13 = 13;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_14 = 14;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_15 = 15;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_16 = 16;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_17 = 17;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_18 = 18;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_NVF_19 = 19;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_ASBE_0 = 20;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_ASBE_1 = 21;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_ASBE_2 = 22;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_ASBE_3 = 23;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_ASBE_4 = 24;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_ASBE_5 = 25;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_ASBE_6 = 26;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_ASBE_7 = 27;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_PBR_0 = 28;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_PBR_1 = 29;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_PBR_2 = 30;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_PBR_3 = 31;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_REG_0 = 32;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_REG_1 = 33;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_REG_2 = 34;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_REG_3 = 35;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_0 = 36;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_1 = 37;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_2 = 38;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_3 = 39;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_4 = 40;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_5 = 41;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_6 = 42;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_7 = 43;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_8 = 44;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_9 = 45;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_10 = 46;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_11 = 47;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_12 = 48;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_13 = 49;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_14 = 50;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK0_OCR_15 = 51;
// pau/reg00012.H

static const uint64_t CS_SM2_MCP_MISC_CERR_MESSAGE5 = 0x100108cbull;

static const uint32_t CS_SM2_MCP_MISC_CERR_MESSAGE5_CERR_MESSAGE_BITS5 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_MESSAGE5_CERR_MESSAGE_BITS5_LEN = 64;
// pau/reg00012.H

static const uint64_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG = 0x10010918ull;

static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_ALLOC_CLASS = 0;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_ALLOC_CLASS_LEN = 5;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_TTYPE = 5;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_TTYPE_LEN = 12;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_TSIZE = 17;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_TSIZE_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_NVBE = 25;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_UT = 26;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_ATYPE = 27;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_ATYPE_LEN = 7;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_ALLOC = 34;
static const uint32_t CS_SM2_SNP_MISC_PERF_MASK_CONFIG_ALLOC_LEN = 6;
// pau/reg00012.H

static const uint64_t CS_SM3_DIR_MISC_CONFIG0 = 0x10010948ull;

static const uint32_t CS_SM3_DIR_MISC_CONFIG0__HOST_TAG_SIZE = 0;
static const uint32_t CS_SM3_DIR_MISC_CONFIG0__HOST_TAG_SIZE_LEN = 4;
static const uint32_t CS_SM3_DIR_MISC_CONFIG0_0_RESERVED = 4;
static const uint32_t CS_SM3_DIR_MISC_CONFIG0_0_RESERVED_LEN = 59;
static const uint32_t CS_SM3_DIR_MISC_CONFIG0__DEBUG0_ACT = 63;
// pau/reg00012.H

static const uint64_t CS_SM3_MCP_MISC_DEBUG0_CONFIG = 0x1001093aull;

static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD0 = 0;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD1 = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD2 = 10;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD3 = 15;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD4 = 20;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD5 = 25;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD6 = 30;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD7 = 35;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD8 = 40;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD9 = 45;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD10 = 50;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM3_MCP_MISC_DEBUG0_CONFIG_ACT = 63;
// pau/reg00012.H

static const uint64_t CS_SM3_MCP_MISC_XTIMER2_CONFIG = 0x1001093full;

static const uint32_t CS_SM3_MCP_MISC_XTIMER2_CONFIG_2_TICK = 0;
static const uint32_t CS_SM3_MCP_MISC_XTIMER2_CONFIG_2_TICK_LEN = 6;
static const uint32_t CS_SM3_MCP_MISC_XTIMER2_CONFIG_3_TICK = 6;
static const uint32_t CS_SM3_MCP_MISC_XTIMER2_CONFIG_3_TICK_LEN = 6;
// pau/reg00012.H

static const uint64_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4 = 0x10010962ull;

static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_TAG = 0;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_TAG_LEN = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_TAGMASK = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_TAGMASK_LEN = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_PAU = 28;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_PCIE = 29;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_MASK_L2L3 = 30;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_RESERVED1 = 31;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_RDSTART = 32;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_RDSTART_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_RDEND = 40;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_RDEND_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_WRSTART = 48;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_WRSTART_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_WREND = 56;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC4_WREND_LEN = 8;
// pau/reg00012.H

static const uint64_t DAT_MISC_CERR_LOG_HOLD = 0x100109caull;

static const uint32_t DAT_MISC_CERR_LOG_HOLD_BBUF_RDWR = 47;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_IBUF_RDWR = 48;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_OBUF_RDWR = 49;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_RQIN_OVF = 50;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_RQIN_OVF_LEN = 6;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_IBUF_CTL_PIPE = 56;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_PBTX_PIPE = 57;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_MRG_IR_PIPE = 58;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_MRG_OR_PIPE = 59;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_AMO_ADDR = 60;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_PBRX_RTAG = 61;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_IBUF_WRITE = 62;
static const uint32_t DAT_MISC_CERR_LOG_HOLD_IBUF_WARB = 63;
// pau/reg00012.H

static const uint64_t DAT_MISC_CERR_PTY_FIRST = 0x100109c9ull;

static const uint32_t DAT_MISC_CERR_PTY_FIRST_CERR_PTY_FIRST_BITS = 37;
static const uint32_t DAT_MISC_CERR_PTY_FIRST_CERR_PTY_FIRST_BITS_LEN = 27;
// pau/reg00012.H

static const uint64_t FIR_REG_1_SCOM = 0x10010c40ull;
static const uint64_t FIR_REG_1_SCOM1 = 0x10010c41ull;
static const uint64_t FIR_REG_1_SCOM2 = 0x10010c42ull;

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
// pau/reg00012.H

static const uint64_t MISC_REGS_BDF2PE_15_CONFIG = 0x10010b5full;

static const uint32_t MISC_REGS_BDF2PE_15_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_15_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_15_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_15_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_15_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_15_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_15_CONFIG_BDF_LEN = 16;
// pau/reg00012.H

static const uint64_t MISC_REGS_BDF2PE_9_CONFIG = 0x10010b59ull;

static const uint32_t MISC_REGS_BDF2PE_9_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_9_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_9_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_9_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_9_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_9_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_9_CONFIG_BDF_LEN = 16;
// pau/reg00012.H

static const uint64_t MISC_REGS_DA_DATA = 0x10010b3full;
// pau/reg00012.H

static const uint64_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG = 0x10010b44ull;

static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG_0 = 0;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG_0_LEN = 12;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG_1 = 12;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG_1_LEN = 12;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG_2 = 24;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG_2_LEN = 12;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG_3 = 36;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG_3_LEN = 12;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG_4 = 48;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG_4_LEN = 12;
// pau/reg00012.H

static const uint64_t MISC_REGS_ERR_SCOPE_CTL_CONFIG = 0x10010b41ull;

static const uint32_t MISC_REGS_ERR_SCOPE_CTL_CONFIG_CONFIG_ERR_SCOPE_CTL = 0;
static const uint32_t MISC_REGS_ERR_SCOPE_CTL_CONFIG_CONFIG_ERR_SCOPE_CTL_LEN = 16;
// pau/reg00012.H

static const uint64_t MISC_REGS_FENCE_0_CONFIG = 0x10010b3aull;

static const uint32_t MISC_REGS_FENCE_0_CONFIG_CONFIG_FENCE_0 = 0;
static const uint32_t MISC_REGS_FENCE_0_CONFIG_CONFIG_FENCE_0_LEN = 64;
// pau/reg00012.H

static const uint64_t MISC_REGS_INT_LOG_0_PE15 = 0x10010b9full;

static const uint32_t MISC_REGS_INT_LOG_0_PE15_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE15_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE15_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE15_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE15_RSVD0_LEN = 3;
// pau/reg00012.H

static const uint64_t MISC_REGS_INT_LOG_0_PE7 = 0x10010b97ull;

static const uint32_t MISC_REGS_INT_LOG_0_PE7_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE7_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE7_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE7_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE7_RSVD0_LEN = 3;
// pau/reg00012.H

static const uint64_t MISC_REGS_INT_LOG_1_PE13 = 0x10010badull;

static const uint32_t MISC_REGS_INT_LOG_1_PE13_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE13_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE13_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE13_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE13_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE13_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE13_RSVD0_LEN = 7;
// pau/reg00012.H

static const uint64_t MISC_REGS_INT_LOG_1_PE7 = 0x10010ba7ull;

static const uint32_t MISC_REGS_INT_LOG_1_PE7_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE7_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE7_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE7_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE7_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE7_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE7_RSVD0_LEN = 7;
// pau/reg00012.H

static const uint64_t MISC_REGS_PAU_VERSION = 0x10010b40ull;

static const uint32_t MISC_REGS_PAU_VERSION_RSVD0 = 0;
static const uint32_t MISC_REGS_PAU_VERSION_RSVD0_LEN = 24;
static const uint32_t MISC_REGS_PAU_VERSION_MAJOR = 24;
static const uint32_t MISC_REGS_PAU_VERSION_MAJOR_LEN = 8;
static const uint32_t MISC_REGS_PAU_VERSION_P10 = 32;
static const uint32_t MISC_REGS_PAU_VERSION_P10_LEN = 4;
static const uint32_t MISC_REGS_PAU_VERSION_RSVD1 = 36;
static const uint32_t MISC_REGS_PAU_VERSION_RSVD1_LEN = 12;
static const uint32_t MISC_REGS_PAU_VERSION_MINOR = 48;
static const uint32_t MISC_REGS_PAU_VERSION_MINOR_LEN = 16;
// pau/reg00012.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE12 = 0x10010b8cull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE12_DMA_STOPPED_STATE_ADDR_PE12 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE12_DMA_STOPPED_STATE_ADDR_PE12_LEN = 37;
// pau/reg00012.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE7 = 0x10010b87ull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE7_DMA_STOPPED_STATE_ADDR_PE7 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE7_DMA_STOPPED_STATE_ADDR_PE7_LEN = 37;
// pau/reg00012.H

static const uint64_t MISC_REGS_PESTB_DATA_PE12 = 0x10010b7cull;

static const uint32_t MISC_REGS_PESTB_DATA_PE12_DMA_STOPPED_STATE_PE12 = 0;
// pau/reg00012.H

static const uint64_t MISC_REGS_PESTB_DATA_PE4 = 0x10010b74ull;

static const uint32_t MISC_REGS_PESTB_DATA_PE4_DMA_STOPPED_STATE_PE4 = 0;
// pau/reg00012.H

static const uint64_t NTL1_REGS_CREQ_DA_PTR = 0x10010a14ull;

static const uint32_t NTL1_REGS_CREQ_DA_PTR_RESERVED1 = 0;
static const uint32_t NTL1_REGS_CREQ_DA_PTR_RESERVED1_LEN = 3;
static const uint32_t NTL1_REGS_CREQ_DA_PTR_START = 3;
static const uint32_t NTL1_REGS_CREQ_DA_PTR_START_LEN = 9;
static const uint32_t NTL1_REGS_CREQ_DA_PTR_RESERVED2 = 12;
static const uint32_t NTL1_REGS_CREQ_DA_PTR_RESERVED2_LEN = 3;
static const uint32_t NTL1_REGS_CREQ_DA_PTR_END = 15;
static const uint32_t NTL1_REGS_CREQ_DA_PTR_END_LEN = 9;
// pau/reg00012.H

static const uint64_t OTL0_MISC_TL_DCP_CREDIT_STATUS = 0x10010a33ull;

static const uint32_t OTL0_MISC_TL_DCP_CREDIT_STATUS_0_COUNT = 0;
static const uint32_t OTL0_MISC_TL_DCP_CREDIT_STATUS_0_COUNT_LEN = 16;
static const uint32_t OTL0_MISC_TL_DCP_CREDIT_STATUS_1_COUNT = 16;
static const uint32_t OTL0_MISC_TL_DCP_CREDIT_STATUS_1_COUNT_LEN = 16;
// pau/reg00012.H

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
// pau/reg00012.H

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
// pau/reg00012.H

static const uint64_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0 = 0x10010a84ull;

static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_CC_DIAL = 3;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_CS_DIAL = 6;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_CS_DIAL_LEN = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_DAT_DIAL = 9;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_DAT_DIAL_LEN = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_AC_DIAL = 11;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_AS_DIAL = 14;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_AS_DIAL_LEN = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_DABDF_DIAL = 16;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_DABDF_DIAL_LEN = 16;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_DAPASID_DIAL = 32;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_DAPASID_DIAL_LEN = 20;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_SS_DIAL = 54;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_SS_DIAL_LEN = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CNTL0_SC_DIAL = 63;
// pau/reg00012.H

static const uint64_t XSL_MAIN_ARY_RD_FUNC = 0x10010aa2ull;

static const uint32_t XSL_MAIN_ARY_RD_FUNC_XSL_ARY_DATA = 0;
static const uint32_t XSL_MAIN_ARY_RD_FUNC_XSL_ARY_DATA_LEN = 64;
// pau/reg00012.H

}
}
#include "pau/reg00012.H"
#endif
