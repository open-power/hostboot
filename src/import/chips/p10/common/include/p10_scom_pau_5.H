/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_5.H $        */
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

#ifndef __p10_scom_pau_5_H_
#define __p10_scom_pau_5_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


static const uint64_t AME_AME2_MISC_TEST_CERR_RPT = 0x10010bebull;

static const uint32_t AME_AME2_MISC_TEST_CERR_RPT_TEST_CERR_BITSEL = 59;
static const uint32_t AME_AME2_MISC_TEST_CERR_RPT_TEST_CERR_BITSEL_LEN = 5;
// pau/reg00007.H

static const uint64_t ATS_REG_DMA_SYNC = 0x10010ad3ull;

static const uint32_t ATS_REG_DMA_SYNC_START_READ_SYNC = 0;
static const uint32_t ATS_REG_DMA_SYNC_READ_SYNC_COMPLETE = 1;
static const uint32_t ATS_REG_DMA_SYNC_START_WRITE_SYNC = 2;
static const uint32_t ATS_REG_DMA_SYNC_WRITE_SYNC_COMPLETE = 3;
// pau/reg00007.H

static const uint64_t ATS_REG_PAU_Q_DMA_R = 0x10010ad5ull;

static const uint32_t ATS_REG_PAU_Q_DMA_R_QUIESCE_DMA = 0;
static const uint32_t ATS_REG_PAU_Q_DMA_R_QUIESCE_AUTO_RESET = 1;
static const uint32_t ATS_REG_PAU_Q_DMA_R_DMA_RESPONSE = 4;
static const uint32_t ATS_REG_PAU_Q_DMA_R_TCE_RESPONSE = 6;
// pau/reg00007.H

static const uint64_t CS_CTL_MISC_BDF2PE_6_CONFIG = 0x100109b6ull;

static const uint32_t CS_CTL_MISC_BDF2PE_6_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_6_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_6_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_6_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_6_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_6_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_6_CONFIG_BDF_LEN = 16;
// pau/reg00007.H

static const uint64_t CS_CTL_MISC_CERR_FIRST1 = 0x1001099cull;

static const uint32_t CS_CTL_MISC_CERR_FIRST1_PEF_0 = 0;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PEF_1 = 1;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PEF_2 = 2;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PEF_3 = 3;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PEF_4 = 4;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PEF_5 = 5;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PEF_6 = 6;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PEF_7 = 7;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_0 = 8;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_1 = 9;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_2 = 10;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_3 = 11;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_4 = 12;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_5 = 13;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_6 = 14;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_7 = 15;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_8 = 16;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_9 = 17;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_10 = 18;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_11 = 19;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_12 = 20;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_13 = 21;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_14 = 22;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_15 = 23;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_16 = 24;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_17 = 25;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_18 = 26;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_NLG_19 = 27;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_FWD_0 = 28;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_FWD_1 = 29;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_FWD_2 = 30;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_FWD_3 = 31;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_AUE_0 = 32;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_AUE_1 = 33;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_AUE_2 = 34;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_AUE_3 = 35;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_AUE_4 = 36;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_AUE_5 = 37;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_AUE_6 = 38;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_AUE_7 = 39;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBP_0 = 40;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBP_1 = 41;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBP_2 = 42;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBP_3 = 43;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBF_0 = 44;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBF_1 = 45;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBF_2 = 46;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBF_3 = 47;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBF_4 = 48;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBF_5 = 49;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBF_6 = 50;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBF_7 = 51;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBC_0 = 52;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBC_1 = 53;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBC_2 = 54;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_PBC_3 = 55;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_LDA_0 = 56;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_LDA_1 = 57;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_LDA_2 = 58;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_LDA_3 = 59;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_STA_0 = 60;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_STA_1 = 61;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_STA_2 = 62;
static const uint32_t CS_CTL_MISC_CERR_FIRST1_STA_3 = 63;
// pau/reg00007.H

static const uint64_t CS_CTL_MISC_GPU0_BAR = 0x1001098eull;

static const uint32_t CS_CTL_MISC_GPU0_BAR_ENABLE = 0;
static const uint32_t CS_CTL_MISC_GPU0_BAR_ADDR_MASK = 1;
static const uint32_t CS_CTL_MISC_GPU0_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_CTL_MISC_GPU0_BAR_SL_MODE = 36;
static const uint32_t CS_CTL_MISC_GPU0_BAR_4T_LIMIT = 37;
static const uint32_t CS_CTL_MISC_GPU0_BAR_4T_SELECT = 38;
static const uint32_t CS_CTL_MISC_GPU0_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_CTL_MISC_GPU0_BAR_MODE = 40;
static const uint32_t CS_CTL_MISC_GPU0_BAR_MODE_LEN = 4;
static const uint32_t CS_CTL_MISC_GPU0_BAR_GRANULE = 44;
static const uint32_t CS_CTL_MISC_GPU0_BAR_POISON = 45;
static const uint32_t CS_CTL_MISC_GPU0_BAR_M2MODE = 46;
static const uint32_t CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_CTL_MISC_GPU0_BAR_SECURE_A12 = 48;
static const uint32_t CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_CTL_MISC_GPU0_BAR_RESERVED = 51;
// pau/reg00007.H

static const uint64_t CS_CTL_MISC_GPU1_BAR = 0x1001098full;

static const uint32_t CS_CTL_MISC_GPU1_BAR_ENABLE = 0;
static const uint32_t CS_CTL_MISC_GPU1_BAR_ADDR_MASK = 1;
static const uint32_t CS_CTL_MISC_GPU1_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_CTL_MISC_GPU1_BAR_SL_MODE = 36;
static const uint32_t CS_CTL_MISC_GPU1_BAR_4T_LIMIT = 37;
static const uint32_t CS_CTL_MISC_GPU1_BAR_4T_SELECT = 38;
static const uint32_t CS_CTL_MISC_GPU1_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_CTL_MISC_GPU1_BAR_MODE = 40;
static const uint32_t CS_CTL_MISC_GPU1_BAR_MODE_LEN = 4;
static const uint32_t CS_CTL_MISC_GPU1_BAR_GRANULE = 44;
static const uint32_t CS_CTL_MISC_GPU1_BAR_POISON = 45;
static const uint32_t CS_CTL_MISC_GPU1_BAR_M2MODE = 46;
static const uint32_t CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_CTL_MISC_GPU1_BAR_SECURE_A12 = 48;
static const uint32_t CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_CTL_MISC_GPU1_BAR_RESERVED = 51;
// pau/reg00007.H

static const uint64_t CS_CTL_MISC_GPU4_BAR = 0x10010992ull;

static const uint32_t CS_CTL_MISC_GPU4_BAR_ENABLE = 0;
static const uint32_t CS_CTL_MISC_GPU4_BAR_ADDR_MASK = 1;
static const uint32_t CS_CTL_MISC_GPU4_BAR_ADDR_MASK_LEN = 35;
static const uint32_t CS_CTL_MISC_GPU4_BAR_SL_MODE = 36;
static const uint32_t CS_CTL_MISC_GPU4_BAR_4T_LIMIT = 37;
static const uint32_t CS_CTL_MISC_GPU4_BAR_4T_SELECT = 38;
static const uint32_t CS_CTL_MISC_GPU4_BAR_4T_SELECT_LEN = 2;
static const uint32_t CS_CTL_MISC_GPU4_BAR_MODE = 40;
static const uint32_t CS_CTL_MISC_GPU4_BAR_MODE_LEN = 4;
static const uint32_t CS_CTL_MISC_GPU4_BAR_GRANULE = 44;
static const uint32_t CS_CTL_MISC_GPU4_BAR_POISON = 45;
static const uint32_t CS_CTL_MISC_GPU4_BAR_M2MODE = 46;
static const uint32_t CS_CTL_MISC_GPU4_BAR_PA_IGNORE_MODE = 47;
static const uint32_t CS_CTL_MISC_GPU4_BAR_SECURE_A12 = 48;
static const uint32_t CS_CTL_MISC_GPU4_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t CS_CTL_MISC_GPU4_BAR_EXTENDED_MODE = 50;
static const uint32_t CS_CTL_MISC_GPU4_BAR_RESERVED = 51;
// pau/reg00007.H

static const uint64_t CS_CTL_MISC_SCOPE_PREDICT3 = 0x100109aeull;

static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_LN_FAIL_THRESH = 0;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_LN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_NN_FAIL_THRESH = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_NN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_RN_FAIL_THRESH = 6;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_RN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_G_FAIL_THRESH = 9;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_G_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_LN_INTV_THRESH = 12;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_LN_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_G_INTV_THRESH = 15;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_G_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3RD_VG_ENABLE = 18;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3_3_RESERVED1 = 19;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_LN_FAIL_THRESH = 20;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_LN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_NN_FAIL_THRESH = 23;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_NN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_RN_FAIL_THRESH = 26;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_RN_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_G_FAIL_THRESH = 29;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_G_FAIL_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_LN_INTV_THRESH = 32;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_LN_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_G_INTV_THRESH = 35;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_G_INTV_THRESH_LEN = 3;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3__B3WR_VG_ENABLE = 38;
static const uint32_t CS_CTL_MISC_SCOPE_PREDICT3_3_RESERVED2 = 39;
// pau/reg00007.H

static const uint64_t CS_SM0_MCP_MISC_CERR_HOLD0 = 0x10010815ull;

static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_0 = 0;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_1 = 1;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_2 = 2;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_3 = 3;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_4 = 4;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_5 = 5;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_6 = 6;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_7 = 7;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_8 = 8;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_9 = 9;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_10 = 10;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_11 = 11;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_12 = 12;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_13 = 13;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_14 = 14;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_15 = 15;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_16 = 16;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_17 = 17;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_18 = 18;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_NVF_19 = 19;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_ASBE_0 = 20;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_ASBE_1 = 21;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_ASBE_2 = 22;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_ASBE_3 = 23;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_ASBE_4 = 24;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_ASBE_5 = 25;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_ASBE_6 = 26;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_ASBE_7 = 27;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_PBR_0 = 28;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_PBR_1 = 29;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_PBR_2 = 30;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_PBR_3 = 31;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_PBR_4 = 32;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_PBR_5 = 33;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_PBR_6 = 34;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_PBR_7 = 35;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_REG_0 = 36;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_REG_1 = 37;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_REG_2 = 38;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_REG_3 = 39;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_0 = 40;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_1 = 41;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_2 = 42;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_3 = 43;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_4 = 44;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_5 = 45;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_6 = 46;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_7 = 47;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_8 = 48;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_9 = 49;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_10 = 50;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_11 = 51;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_12 = 52;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_13 = 53;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_14 = 54;
static const uint32_t CS_SM0_MCP_MISC_CERR_HOLD0_OCR_15 = 55;
// pau/reg00007.H

static const uint64_t CS_SM0_MCP_MISC_CERR_MESSAGE2 = 0x10010808ull;

static const uint32_t CS_SM0_MCP_MISC_CERR_MESSAGE2_CERR_MESSAGE_BITS2 = 0;
static const uint32_t CS_SM0_MCP_MISC_CERR_MESSAGE2_CERR_MESSAGE_BITS2_LEN = 64;
// pau/reg00007.H

static const uint64_t CS_SM1_MCP_MISC_DEBUG3_CONFIG = 0x1001087cull;

static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE0 = 0;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE0_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE1 = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE1_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE2 = 14;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE2_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE3 = 21;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE3_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE4 = 28;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE4_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE5 = 35;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE5_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE6 = 42;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE6_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE7 = 49;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE7_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE8 = 56;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_BYTE8_LEN = 7;
static const uint32_t CS_SM1_MCP_MISC_DEBUG3_CONFIG_ACT = 63;
// pau/reg00007.H

static const uint64_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6 = 0x100108a4ull;

static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_TAG = 0;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_TAG_LEN = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_TAGMASK = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_TAGMASK_LEN = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_PAU = 28;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_PCIE = 29;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_L2L3 = 30;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_RESERVED1 = 31;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_RDSTART = 32;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_RDSTART_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_RDEND = 40;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_RDEND_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_WRSTART = 48;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_WRSTART_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_WREND = 56;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_SRC6_WREND_LEN = 8;
// pau/reg00007.H

static const uint64_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG = 0x100108b7ull;

static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_ALLOC_CLASS = 0;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_ALLOC_CLASS_LEN = 5;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_TTYPE = 5;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_TTYPE_LEN = 12;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_TSIZE = 17;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_TSIZE_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_NVBE = 25;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_UT = 26;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_ATYPE = 27;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_ATYPE_LEN = 7;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_ALLOC = 34;
static const uint32_t CS_SM1_SNP_MISC_PERF_MATCH_CONFIG_ALLOC_LEN = 6;
// pau/reg00007.H

static const uint64_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0 = 0x100108bcull;

static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 = 0;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN = 8;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0 = 8;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1 = 12;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2 = 16;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3 = 20;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4 = 24;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5 = 28;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6 = 32;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7 = 36;
static const uint32_t CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN = 4;
// pau/reg00007.H

static const uint64_t CS_SM2_MCP_MISC_CERR_MASK2 = 0x100108d4ull;

static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_0 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_1 = 1;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_2 = 2;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_3 = 3;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_4 = 4;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_5 = 5;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_6 = 6;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_7 = 7;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_8 = 8;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_9 = 9;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_10 = 10;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_11 = 11;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_12 = 12;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_13 = 13;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_14 = 14;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_15 = 15;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_16 = 16;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_17 = 17;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_18 = 18;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_19 = 19;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_20 = 20;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_21 = 21;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_22 = 22;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_23 = 23;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_24 = 24;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_25 = 25;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_26 = 26;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_27 = 27;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_28 = 28;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_29 = 29;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_30 = 30;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_31 = 31;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_32 = 32;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_33 = 33;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_34 = 34;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_35 = 35;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_36 = 36;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_37 = 37;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_38 = 38;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_39 = 39;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_40 = 40;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_41 = 41;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_42 = 42;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_43 = 43;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_44 = 44;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_45 = 45;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_46 = 46;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_47 = 47;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_48 = 48;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_49 = 49;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_50 = 50;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_51 = 51;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_52 = 52;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_53 = 53;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_54 = 54;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_55 = 55;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_56 = 56;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_57 = 57;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_58 = 58;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_59 = 59;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_60 = 60;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_61 = 61;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_62 = 62;
static const uint32_t CS_SM2_MCP_MISC_CERR_MASK2_63 = 63;
// pau/reg00007.H

static const uint64_t CS_SM2_MCP_MISC_CERR_MESSAGE7 = 0x100108cdull;

static const uint32_t CS_SM2_MCP_MISC_CERR_MESSAGE7_CERR_MESSAGE_BITS7 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_MESSAGE7_CERR_MESSAGE_BITS7_LEN = 40;
// pau/reg00007.H

static const uint64_t CS_SM2_MCP_MISC_INHIBIT_CONFIG = 0x100108c5ull;

static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_LFREQ0 = 0;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_LFREQ0_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_PFREQ0 = 4;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_PFREQ0_LEN = 2;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_BLOCKY0 = 6;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_ONESHOT0 = 7;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_DEST0 = 8;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_DEST0_LEN = 8;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_LFREQ1 = 16;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_LFREQ1_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_PFREQ1 = 20;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_PFREQ1_LEN = 2;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_BLOCKY1 = 22;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_ONESHOT1 = 23;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_DEST1 = 24;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_DEST1_LEN = 8;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_LFREQ2 = 32;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_LFREQ2_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_PFREQ2 = 36;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_PFREQ2_LEN = 2;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_BLOCKY2 = 38;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_ONESHOT2 = 39;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_DEST2 = 40;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_DEST2_LEN = 8;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_LFREQ3 = 48;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_LFREQ3_LEN = 4;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_PFREQ3 = 52;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_PFREQ3_LEN = 2;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_BLOCKY3 = 54;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_ONESHOT3 = 55;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_DEST3 = 56;
static const uint32_t CS_SM2_MCP_MISC_INHIBIT_CONFIG_DEST3_LEN = 8;
// pau/reg00007.H

static const uint64_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG = 0x100108d8ull;

static const uint32_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG_RESERVED2 = 0;
static const uint32_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG_RESERVED2_LEN = 24;
static const uint32_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG_CRESP = 24;
static const uint32_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG_CRESP_LEN = 5;
static const uint32_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG_SCOPE = 29;
static const uint32_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG_SCOPE_LEN = 3;
static const uint32_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG_MCMD = 32;
static const uint32_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG_MCMD_LEN = 10;
static const uint32_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG_RESERVED1 = 42;
static const uint32_t CS_SM2_MCP_MISC_PERF_MATCH_CONFIG_RESERVED1_LEN = 2;
// pau/reg00007.H

static const uint64_t CS_SM2_SNP_MISC_INHIBIT_CONFIG = 0x1001090full;

static const uint32_t CS_SM2_SNP_MISC_INHIBIT_CONFIG_0 = 0;
static const uint32_t CS_SM2_SNP_MISC_INHIBIT_CONFIG_0_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_INHIBIT_CONFIG_1 = 8;
static const uint32_t CS_SM2_SNP_MISC_INHIBIT_CONFIG_1_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_INHIBIT_CONFIG_2 = 16;
static const uint32_t CS_SM2_SNP_MISC_INHIBIT_CONFIG_2_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_INHIBIT_CONFIG_3 = 24;
static const uint32_t CS_SM2_SNP_MISC_INHIBIT_CONFIG_3_LEN = 8;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_CERR_MESSAGE1 = 0x10010971ull;

static const uint32_t CS_SM3_SNP_MISC_CERR_MESSAGE1_CERR_MESSAGE_BITS1 = 0;
static const uint32_t CS_SM3_SNP_MISC_CERR_MESSAGE1_CERR_MESSAGE_BITS1_LEN = 64;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_CONFIG0 = 0x10010950ull;

static const uint32_t CS_SM3_SNP_MISC_CONFIG0__MA_RSNOOP_OPT_DCLAIM = 0;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__MA_RSNOOP_OPT_DCLAIM_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__ENABLE_PBUS = 2;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRAZOS_MODE = 3;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__PCKT_BLK_PRB = 4;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__ADR_BAR_MODE = 5;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__RESTRICT_CHIP_GROUP = 6;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED3 = 7;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED3_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__SNP_FIR_TO_INHIBIT_MASK = 9;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__SNP_FIR_TO_INHIBIT_MASK_LEN = 7;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK0_FENCE_TO_INHIBIT_MASK = 16;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK1_FENCE_TO_INHIBIT_MASK = 17;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK2_FENCE_TO_INHIBIT_MASK = 18;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK3_FENCE_TO_INHIBIT_MASK = 19;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK4_FENCE_TO_INHIBIT_MASK = 20;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__MRBGP_TRACK_ALL = 21;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__MRBSP_TRACK_ALL = 22;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__MRBCP_TRACK_ALL = 23;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__ADDR_EX_MASK_ENA = 24;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__ADDR_EX_MASK_ENA_LEN = 7;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__SINGLE_AFU_DUAL_BRICK = 31;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK0_OCAPI_MODE = 32;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK1_OCAPI_MODE = 33;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK2_OCAPI_MODE = 34;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK3_OCAPI_MODE = 35;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK4_OCAPI_MODE = 36;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK0_NVLINK_MODE = 37;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK1_NVLINK_MODE = 38;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK2_NVLINK_MODE = 39;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK3_NVLINK_MODE = 40;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__BRK4_NVLINK_MODE = 41;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__ENABLE_BLOCKING_RCMD_DIR = 42;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__DISABLE_DIR_POWERSAVE = 43;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__DISABLE_PRESP_POWERSAVE = 44;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__ENABLE_BRK0_OCAPI_C2 = 45;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__ENABLE_BRK1_OCAPI_C2 = 46;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__ENABLE_BRK2_OCAPI_C2 = 47;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__ENABLE_BRK3_OCAPI_C2 = 48;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__ENABLE_BRK4_OCAPI_C2 = 49;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__DISABLE_CAN_BY_CP = 50;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED1 = 51;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED2 = 52;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED4 = 53;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED5 = 54;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED6 = 55;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED7 = 56;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED8 = 57;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED9 = 58;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED10 = 59;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__DISABLE_CAN_BY_PROBE = 60;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0__HANG_ON_ADDRESS_ERRORS = 61;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED0 = 62;
static const uint32_t CS_SM3_SNP_MISC_CONFIG0_0_RESERVED0_LEN = 2;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6 = 0x10010964ull;

static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_TAG = 0;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_TAG_LEN = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_TAGMASK = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_TAGMASK_LEN = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_PAU = 28;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_PCIE = 29;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_MASK_L2L3 = 30;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_RESERVED1 = 31;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_RDSTART = 32;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_RDSTART_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_RDEND = 40;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_RDEND_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_WRSTART = 48;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_WRSTART_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_WREND = 56;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_SRC6_WREND_LEN = 8;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_DEBUG1_CONFIG = 0x1001097aull;

static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD0 = 0;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD1 = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD2 = 10;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD3 = 15;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD4 = 20;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD5 = 25;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD6 = 30;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD7 = 35;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD8 = 40;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD9 = 45;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD10 = 50;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_DEBUG1_CONFIG_ACT = 63;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_NDT0_BAR = 0x10010957ull;

static const uint32_t CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 = 2;
static const uint32_t CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR = 3;
static const uint32_t CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON = 36;
static const uint32_t CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 = 37;
static const uint32_t CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE = 39;
static const uint32_t CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN = 5;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_NDT1_BAR = 0x10010958ull;

static const uint32_t CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 = 2;
static const uint32_t CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR = 3;
static const uint32_t CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON = 36;
static const uint32_t CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 = 37;
static const uint32_t CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE = 39;
static const uint32_t CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN = 5;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_NDT2_BAR = 0x10010959ull;

static const uint32_t CS_SM3_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM3_SNP_MISC_NDT2_BAR_NDT2_RESERVED1 = 2;
static const uint32_t CS_SM3_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_ADDR = 3;
static const uint32_t CS_SM3_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM3_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_POISON = 36;
static const uint32_t CS_SM3_SNP_MISC_NDT2_BAR_NDT2_RESERVED2 = 37;
static const uint32_t CS_SM3_SNP_MISC_NDT2_BAR_NDT2_RESERVED2_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_SIZE = 39;
static const uint32_t CS_SM3_SNP_MISC_NDT2_BAR_CONFIG_NDT2_BAR_SIZE_LEN = 5;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_NDT3_BAR = 0x1001095aull;

static const uint32_t CS_SM3_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM3_SNP_MISC_NDT3_BAR_NDT3_RESERVED1 = 2;
static const uint32_t CS_SM3_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_ADDR = 3;
static const uint32_t CS_SM3_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM3_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_POISON = 36;
static const uint32_t CS_SM3_SNP_MISC_NDT3_BAR_NDT3_RESERVED2 = 37;
static const uint32_t CS_SM3_SNP_MISC_NDT3_BAR_NDT3_RESERVED2_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_SIZE = 39;
static const uint32_t CS_SM3_SNP_MISC_NDT3_BAR_CONFIG_NDT3_BAR_SIZE_LEN = 5;
// pau/reg00007.H

static const uint64_t CS_SM3_SNP_MISC_NDT4_BAR = 0x1001095bull;

static const uint32_t CS_SM3_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_ENABLE = 0;
static const uint32_t CS_SM3_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM3_SNP_MISC_NDT4_BAR_NDT4_RESERVED1 = 2;
static const uint32_t CS_SM3_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_ADDR = 3;
static const uint32_t CS_SM3_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_ADDR_LEN = 33;
static const uint32_t CS_SM3_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_POISON = 36;
static const uint32_t CS_SM3_SNP_MISC_NDT4_BAR_NDT4_RESERVED2 = 37;
static const uint32_t CS_SM3_SNP_MISC_NDT4_BAR_NDT4_RESERVED2_LEN = 2;
static const uint32_t CS_SM3_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_SIZE = 39;
static const uint32_t CS_SM3_SNP_MISC_NDT4_BAR_CONFIG_NDT4_BAR_SIZE_LEN = 5;
// pau/reg00007.H

static const uint64_t DAT_MISC_CERR_ECC_FIRST = 0x100109c6ull;

static const uint32_t DAT_MISC_CERR_ECC_FIRST_CERR_ECC_FIRST_BITS = 10;
static const uint32_t DAT_MISC_CERR_ECC_FIRST_CERR_ECC_FIRST_BITS_LEN = 54;
// pau/reg00007.H

static const uint64_t DAT_MISC_CERR_PTY_MASK = 0x100109c8ull;

static const uint32_t DAT_MISC_CERR_PTY_MASK_CERR_PTY_MASK_BITS = 37;
static const uint32_t DAT_MISC_CERR_PTY_MASK_CERR_PTY_MASK_BITS_LEN = 27;
// pau/reg00007.H

static const uint64_t DAT_MISC_ECC_CONFIG = 0x100109c2ull;

static const uint32_t DAT_MISC_ECC_CONFIG_PBTX_AMO_IGNORE_XUE = 0;
static const uint32_t DAT_MISC_ECC_CONFIG_SUE_DIS_BR_PERR = 1;
static const uint32_t DAT_MISC_ECC_CONFIG_SUE_DIS_IR_PERR = 2;
static const uint32_t DAT_MISC_ECC_CONFIG_SUE_DIS_OR_PERR = 3;
static const uint32_t DAT_MISC_ECC_CONFIG_CORR_DIS_PT = 4;
static const uint32_t DAT_MISC_ECC_CONFIG_CORR_DIS_PR = 5;
static const uint32_t DAT_MISC_ECC_CONFIG_CORR_DIS_BR = 6;
static const uint32_t DAT_MISC_ECC_CONFIG_CORR_DIS_IR = 7;
static const uint32_t DAT_MISC_ECC_CONFIG_CORR_DIS_OR = 8;
static const uint32_t DAT_MISC_ECC_CONFIG_SUE_DIS_PT = 9;
static const uint32_t DAT_MISC_ECC_CONFIG_SUE_DIS_PR = 10;
static const uint32_t DAT_MISC_ECC_CONFIG_SUE_DIS_BR = 11;
static const uint32_t DAT_MISC_ECC_CONFIG_SUE_DIS_IR = 12;
static const uint32_t DAT_MISC_ECC_CONFIG_SUE_DIS_OR = 13;
static const uint32_t DAT_MISC_ECC_CONFIG_RESERVED = 14;
static const uint32_t DAT_MISC_ECC_CONFIG_RESERVED_LEN = 18;
// pau/reg00007.H

static const uint64_t MISC_REGS_BDF2PE_6_CONFIG = 0x10010b56ull;

static const uint32_t MISC_REGS_BDF2PE_6_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_6_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_6_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_6_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_6_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_6_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_6_CONFIG_BDF_LEN = 16;
// pau/reg00007.H

static const uint64_t MISC_REGS_INT_LOG_0_PE5 = 0x10010b95ull;

static const uint32_t MISC_REGS_INT_LOG_0_PE5_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE5_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE5_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE5_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE5_RSVD0_LEN = 3;
// pau/reg00007.H

static const uint64_t MISC_REGS_INT_LOG_1_PE11 = 0x10010babull;

static const uint32_t MISC_REGS_INT_LOG_1_PE11_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE11_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE11_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE11_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE11_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE11_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE11_RSVD0_LEN = 7;
// pau/reg00007.H

static const uint64_t MISC_REGS_INT_LOG_1_PE5 = 0x10010ba5ull;

static const uint32_t MISC_REGS_INT_LOG_1_PE5_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE5_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE5_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE5_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE5_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE5_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE5_RSVD0_LEN = 7;
// pau/reg00007.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE10 = 0x10010b8aull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE10_DMA_STOPPED_STATE_ADDR_PE10 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE10_DMA_STOPPED_STATE_ADDR_PE10_LEN = 37;
// pau/reg00007.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE5 = 0x10010b85ull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE5_DMA_STOPPED_STATE_ADDR_PE5 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE5_DMA_STOPPED_STATE_ADDR_PE5_LEN = 37;
// pau/reg00007.H

static const uint64_t MISC_REGS_PESTB_DATA_PE10 = 0x10010b7aull;

static const uint32_t MISC_REGS_PESTB_DATA_PE10_DMA_STOPPED_STATE_PE10 = 0;
// pau/reg00007.H

static const uint64_t MISC_REGS_PESTB_DATA_PE6 = 0x10010b76ull;

static const uint32_t MISC_REGS_PESTB_DATA_PE6_DMA_STOPPED_STATE_PE6 = 0;
// pau/reg00007.H

static const uint64_t NTL1_REGS_CERR_FIRST2 = 0x10010a08ull;

static const uint32_t NTL1_REGS_CERR_FIRST2_0 = 0;
static const uint32_t NTL1_REGS_CERR_FIRST2_1 = 1;
static const uint32_t NTL1_REGS_CERR_FIRST2_2 = 2;
static const uint32_t NTL1_REGS_CERR_FIRST2_3 = 3;
static const uint32_t NTL1_REGS_CERR_FIRST2_4 = 4;
static const uint32_t NTL1_REGS_CERR_FIRST2_5 = 5;
static const uint32_t NTL1_REGS_CERR_FIRST2_6 = 6;
static const uint32_t NTL1_REGS_CERR_FIRST2_7 = 7;
static const uint32_t NTL1_REGS_CERR_FIRST2_8 = 8;
static const uint32_t NTL1_REGS_CERR_FIRST2_9 = 9;
static const uint32_t NTL1_REGS_CERR_FIRST2_10 = 10;
static const uint32_t NTL1_REGS_CERR_FIRST2_11 = 11;
static const uint32_t NTL1_REGS_CERR_FIRST2_12 = 12;
static const uint32_t NTL1_REGS_CERR_FIRST2_13 = 13;
static const uint32_t NTL1_REGS_CERR_FIRST2_14 = 14;
static const uint32_t NTL1_REGS_CERR_FIRST2_15 = 15;
static const uint32_t NTL1_REGS_CERR_FIRST2_16 = 16;
static const uint32_t NTL1_REGS_CERR_FIRST2_17 = 17;
static const uint32_t NTL1_REGS_CERR_FIRST2_18 = 18;
static const uint32_t NTL1_REGS_CERR_FIRST2_19 = 19;
static const uint32_t NTL1_REGS_CERR_FIRST2_20 = 20;
static const uint32_t NTL1_REGS_CERR_FIRST2_21 = 21;
static const uint32_t NTL1_REGS_CERR_FIRST2_22 = 22;
static const uint32_t NTL1_REGS_CERR_FIRST2_23 = 23;
static const uint32_t NTL1_REGS_CERR_FIRST2_24 = 24;
static const uint32_t NTL1_REGS_CERR_FIRST2_25 = 25;
static const uint32_t NTL1_REGS_CERR_FIRST2_26 = 26;
static const uint32_t NTL1_REGS_CERR_FIRST2_27 = 27;
static const uint32_t NTL1_REGS_CERR_FIRST2_28 = 28;
static const uint32_t NTL1_REGS_CERR_FIRST2_29 = 29;
static const uint32_t NTL1_REGS_CERR_FIRST2_30 = 30;
static const uint32_t NTL1_REGS_CERR_FIRST2_31 = 31;
static const uint32_t NTL1_REGS_CERR_FIRST2_32 = 32;
static const uint32_t NTL1_REGS_CERR_FIRST2_33 = 33;
static const uint32_t NTL1_REGS_CERR_FIRST2_34 = 34;
static const uint32_t NTL1_REGS_CERR_FIRST2_35 = 35;
static const uint32_t NTL1_REGS_CERR_FIRST2_36 = 36;
static const uint32_t NTL1_REGS_CERR_FIRST2_37 = 37;
static const uint32_t NTL1_REGS_CERR_FIRST2_38 = 38;
static const uint32_t NTL1_REGS_CERR_FIRST2_39 = 39;
static const uint32_t NTL1_REGS_CERR_FIRST2_40 = 40;
static const uint32_t NTL1_REGS_CERR_FIRST2_41 = 41;
static const uint32_t NTL1_REGS_CERR_FIRST2_42 = 42;
static const uint32_t NTL1_REGS_CERR_FIRST2_43 = 43;
static const uint32_t NTL1_REGS_CERR_FIRST2_44 = 44;
static const uint32_t NTL1_REGS_CERR_FIRST2_45 = 45;
static const uint32_t NTL1_REGS_CERR_FIRST2_46 = 46;
static const uint32_t NTL1_REGS_CERR_FIRST2_47 = 47;
static const uint32_t NTL1_REGS_CERR_FIRST2_48 = 48;
static const uint32_t NTL1_REGS_CERR_FIRST2_49 = 49;
static const uint32_t NTL1_REGS_CERR_FIRST2_50 = 50;
static const uint32_t NTL1_REGS_CERR_FIRST2_51 = 51;
static const uint32_t NTL1_REGS_CERR_FIRST2_52 = 52;
static const uint32_t NTL1_REGS_CERR_FIRST2_53 = 53;
static const uint32_t NTL1_REGS_CERR_FIRST2_54 = 54;
static const uint32_t NTL1_REGS_CERR_FIRST2_55 = 55;
static const uint32_t NTL1_REGS_CERR_FIRST2_56 = 56;
static const uint32_t NTL1_REGS_CERR_FIRST2_57 = 57;
static const uint32_t NTL1_REGS_CERR_FIRST2_58 = 58;
static const uint32_t NTL1_REGS_CERR_FIRST2_59 = 59;
static const uint32_t NTL1_REGS_CERR_FIRST2_60 = 60;
static const uint32_t NTL1_REGS_CERR_FIRST2_61 = 61;
static const uint32_t NTL1_REGS_CERR_FIRST2_62 = 62;
static const uint32_t NTL1_REGS_CERR_FIRST2_63 = 63;
// pau/reg00007.H

static const uint64_t NTL1_REGS_CERR_HOLD1 = 0x10010a02ull;

static const uint32_t NTL1_REGS_CERR_HOLD1_0 = 0;
static const uint32_t NTL1_REGS_CERR_HOLD1_1 = 1;
static const uint32_t NTL1_REGS_CERR_HOLD1_2 = 2;
static const uint32_t NTL1_REGS_CERR_HOLD1_3 = 3;
static const uint32_t NTL1_REGS_CERR_HOLD1_4 = 4;
static const uint32_t NTL1_REGS_CERR_HOLD1_5 = 5;
static const uint32_t NTL1_REGS_CERR_HOLD1_6 = 6;
static const uint32_t NTL1_REGS_CERR_HOLD1_7 = 7;
static const uint32_t NTL1_REGS_CERR_HOLD1_8 = 8;
static const uint32_t NTL1_REGS_CERR_HOLD1_9 = 9;
static const uint32_t NTL1_REGS_CERR_HOLD1_10 = 10;
static const uint32_t NTL1_REGS_CERR_HOLD1_11 = 11;
static const uint32_t NTL1_REGS_CERR_HOLD1_12 = 12;
static const uint32_t NTL1_REGS_CERR_HOLD1_13 = 13;
static const uint32_t NTL1_REGS_CERR_HOLD1_14 = 14;
static const uint32_t NTL1_REGS_CERR_HOLD1_15 = 15;
static const uint32_t NTL1_REGS_CERR_HOLD1_16 = 16;
static const uint32_t NTL1_REGS_CERR_HOLD1_17 = 17;
static const uint32_t NTL1_REGS_CERR_HOLD1_18 = 18;
static const uint32_t NTL1_REGS_CERR_HOLD1_19 = 19;
static const uint32_t NTL1_REGS_CERR_HOLD1_20 = 20;
static const uint32_t NTL1_REGS_CERR_HOLD1_21 = 21;
static const uint32_t NTL1_REGS_CERR_HOLD1_22 = 22;
static const uint32_t NTL1_REGS_CERR_HOLD1_23 = 23;
static const uint32_t NTL1_REGS_CERR_HOLD1_24 = 24;
static const uint32_t NTL1_REGS_CERR_HOLD1_25 = 25;
static const uint32_t NTL1_REGS_CERR_HOLD1_26 = 26;
static const uint32_t NTL1_REGS_CERR_HOLD1_27 = 27;
static const uint32_t NTL1_REGS_CERR_HOLD1_28 = 28;
static const uint32_t NTL1_REGS_CERR_HOLD1_29 = 29;
static const uint32_t NTL1_REGS_CERR_HOLD1_30 = 30;
static const uint32_t NTL1_REGS_CERR_HOLD1_31 = 31;
static const uint32_t NTL1_REGS_CERR_HOLD1_32 = 32;
static const uint32_t NTL1_REGS_CERR_HOLD1_33 = 33;
static const uint32_t NTL1_REGS_CERR_HOLD1_34 = 34;
static const uint32_t NTL1_REGS_CERR_HOLD1_35 = 35;
static const uint32_t NTL1_REGS_CERR_HOLD1_36 = 36;
static const uint32_t NTL1_REGS_CERR_HOLD1_37 = 37;
static const uint32_t NTL1_REGS_CERR_HOLD1_38 = 38;
static const uint32_t NTL1_REGS_CERR_HOLD1_39 = 39;
static const uint32_t NTL1_REGS_CERR_HOLD1_40 = 40;
static const uint32_t NTL1_REGS_CERR_HOLD1_41 = 41;
static const uint32_t NTL1_REGS_CERR_HOLD1_42 = 42;
static const uint32_t NTL1_REGS_CERR_HOLD1_43 = 43;
static const uint32_t NTL1_REGS_CERR_HOLD1_44 = 44;
static const uint32_t NTL1_REGS_CERR_HOLD1_45 = 45;
static const uint32_t NTL1_REGS_CERR_HOLD1_46 = 46;
static const uint32_t NTL1_REGS_CERR_HOLD1_47 = 47;
static const uint32_t NTL1_REGS_CERR_HOLD1_48 = 48;
static const uint32_t NTL1_REGS_CERR_HOLD1_49 = 49;
static const uint32_t NTL1_REGS_CERR_HOLD1_50 = 50;
static const uint32_t NTL1_REGS_CERR_HOLD1_51 = 51;
static const uint32_t NTL1_REGS_CERR_HOLD1_52 = 52;
static const uint32_t NTL1_REGS_CERR_HOLD1_53 = 53;
static const uint32_t NTL1_REGS_CERR_HOLD1_54 = 54;
static const uint32_t NTL1_REGS_CERR_HOLD1_55 = 55;
static const uint32_t NTL1_REGS_CERR_HOLD1_56 = 56;
static const uint32_t NTL1_REGS_CERR_HOLD1_57 = 57;
static const uint32_t NTL1_REGS_CERR_HOLD1_58 = 58;
static const uint32_t NTL1_REGS_CERR_HOLD1_59 = 59;
static const uint32_t NTL1_REGS_CERR_HOLD1_60 = 60;
static const uint32_t NTL1_REGS_CERR_HOLD1_61 = 61;
static const uint32_t NTL1_REGS_CERR_HOLD1_62 = 62;
static const uint32_t NTL1_REGS_CERR_HOLD1_63 = 63;
// pau/reg00007.H

static const uint64_t OTL0_MISC_OTL_REM0 = 0x10010a2dull;

static const uint32_t OTL0_MISC_OTL_REM0_VC0 = 0;
static const uint32_t OTL0_MISC_OTL_REM0_VC1 = 1;
static const uint32_t OTL0_MISC_OTL_REM0_VC2 = 2;
static const uint32_t OTL0_MISC_OTL_REM0_RSVD3 = 3;
static const uint32_t OTL0_MISC_OTL_REM0_DCP0 = 4;
static const uint32_t OTL0_MISC_OTL_REM0_DCP1 = 5;
static const uint32_t OTL0_MISC_OTL_REM0_RSVD6 = 6;
static const uint32_t OTL0_MISC_OTL_REM0_RSVD7 = 7;
// pau/reg00007.H

static const uint64_t OTL0_MISC_PMU_COUNT = 0x10010a25ull;

static const uint32_t OTL0_MISC_PMU_COUNT_0 = 0;
static const uint32_t OTL0_MISC_PMU_COUNT_0_LEN = 16;
static const uint32_t OTL0_MISC_PMU_COUNT_1 = 16;
static const uint32_t OTL0_MISC_PMU_COUNT_1_LEN = 16;
static const uint32_t OTL0_MISC_PMU_COUNT_2 = 32;
static const uint32_t OTL0_MISC_PMU_COUNT_2_LEN = 16;
static const uint32_t OTL0_MISC_PMU_COUNT_3 = 48;
static const uint32_t OTL0_MISC_PMU_COUNT_3_LEN = 16;
// pau/reg00007.H

static const uint64_t OTL1_MISC_TL_VC_CREDIT_STATUS = 0x10010a62ull;

static const uint32_t OTL1_MISC_TL_VC_CREDIT_STATUS_0_COUNT = 0;
static const uint32_t OTL1_MISC_TL_VC_CREDIT_STATUS_0_COUNT_LEN = 16;
static const uint32_t OTL1_MISC_TL_VC_CREDIT_STATUS_1_COUNT = 16;
static const uint32_t OTL1_MISC_TL_VC_CREDIT_STATUS_1_COUNT_LEN = 16;
static const uint32_t OTL1_MISC_TL_VC_CREDIT_STATUS_2_COUNT = 32;
static const uint32_t OTL1_MISC_TL_VC_CREDIT_STATUS_2_COUNT_LEN = 16;
// pau/reg00007.H

static const uint64_t XSL_MAIN_XSLOP_VLOG_RGS_DBG_WR = 0x10010a94ull;

static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_DBG_WR_TO_DIAL = 0;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_DBG_WR_TRNSO_DIAL = 1;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_DBG_WR_ERTO_DIAL = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_DBG_WR_DVS_DIAL = 8;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_DBG_WR_DVS_DIAL_LEN = 16;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_DBG_WR_ITAG_INIT_DIAL = 24;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_DBG_WR_ITAG_INIT_DIAL_LEN = 9;
// pau/reg00007.H

static const uint64_t XTS_ATSD_HYP15 = 0x10010b1full;

static const uint32_t XTS_ATSD_HYP15_MSRHV = 51;
static const uint32_t XTS_ATSD_HYP15_LPARID = 52;
static const uint32_t XTS_ATSD_HYP15_LPARID_LEN = 12;
// pau/reg00007.H

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00007.H"
#endif
#endif
