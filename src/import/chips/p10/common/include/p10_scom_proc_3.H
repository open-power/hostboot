/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_3.H $       */
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

#ifndef __p10_scom_proc_3_H_
#define __p10_scom_proc_3_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_EQP_SPACE = 0x0201081cull;

static const uint32_t INT_CQ_EQP_SPACE_DISABLE_L3_LOCAL = 0;
static const uint32_t INT_CQ_EQP_SPACE_DISABLE_L3_GROUP = 1;
static const uint32_t INT_CQ_EQP_SPACE_DISABLE_L3_VG = 2;
static const uint32_t INT_CQ_EQP_SPACE_DISABLE_MEM_LOCAL = 3;
static const uint32_t INT_CQ_EQP_SPACE_DISABLE_MEM_GROUP = 4;
static const uint32_t INT_CQ_EQP_SPACE_DISABLE_MEM_VG = 5;
static const uint32_t INT_CQ_EQP_SPACE_INC_BY_TWO_0_3 = 6;
static const uint32_t INT_CQ_EQP_SPACE_INC_BY_TWO_0_3_LEN = 4;
static const uint32_t INT_CQ_EQP_SPACE_INC_BY_ONE_0_3 = 10;
static const uint32_t INT_CQ_EQP_SPACE_INC_BY_ONE_0_3_LEN = 4;
static const uint32_t INT_CQ_EQP_SPACE_DEC_BY_ONE_0_3 = 14;
static const uint32_t INT_CQ_EQP_SPACE_DEC_BY_ONE_0_3_LEN = 4;
// proc/reg00012.H

static const uint64_t INT_CQ_NVPG_BAR = 0x0201080cull;

static const uint32_t INT_CQ_NVPG_BAR_VALID = 0;
static const uint32_t INT_CQ_NVPG_BAR_PAGE_SIZE_64K = 1;
static const uint32_t INT_CQ_NVPG_BAR_ADDR_8_39 = 8;
static const uint32_t INT_CQ_NVPG_BAR_ADDR_8_39_LEN = 32;
static const uint32_t INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2 = 56;
static const uint32_t INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2_LEN = 3;
static const uint32_t INT_CQ_NVPG_BAR_RANGE_0_4 = 59;
static const uint32_t INT_CQ_NVPG_BAR_RANGE_0_4_LEN = 5;
// proc/reg00012.H

static const uint64_t INT_CQ_RST_CTL = 0x02010812ull;

static const uint32_t INT_CQ_RST_CTL_SYNC_RESET = 0;
static const uint32_t INT_CQ_RST_CTL_QUIESCE_PB = 1;
static const uint32_t INT_CQ_RST_CTL_MASTER_IDLE = 2;
static const uint32_t INT_CQ_RST_CTL_SLAVE_IDLE = 3;
static const uint32_t INT_CQ_RST_CTL_PB_BAR_RESET = 4;
static const uint32_t INT_CQ_RST_CTL_RESERVED_5_7 = 5;
static const uint32_t INT_CQ_RST_CTL_RESERVED_5_7_LEN = 3;
// proc/reg00012.H

static const uint64_t INT_PC_NXC_REGS_FLUSH_POLL = 0x02010a81ull;

static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_RESERVED_0_1 = 0;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_RESERVED_0_1_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_NXC_TYPE = 2;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_NXC_TYPE_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_BLOCKID = 4;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_BLOCKID_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_OFFSET = 8;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_OFFSET_LEN = 24;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_RESERVED_32_33 = 32;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_RESERVED_32_33_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_NXC_TYPE_MASK = 34;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_NXC_TYPE_MASK_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_BLOCKID_MASK = 36;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_BLOCKID_MASK_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_OFFSET_MASK = 40;
static const uint32_t INT_PC_NXC_REGS_FLUSH_POLL_OFFSET_MASK_LEN = 24;
// proc/reg00012.H

static const uint64_t INT_PC_NXC_REGS_WATCH3_DATA2 = 0x02010abeull;
// proc/reg00012.H

static const uint64_t INT_PC_NXC_REGS_WATCH3_SPEC = 0x02010ab8ull;
// proc/reg00012.H

static const uint64_t INT_PC_REGS_DBG_PMC_ATX2 = 0x02010a37ull;

static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_0 = 0;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_0_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_1 = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_1_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_2 = 8;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_2_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_3 = 12;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_3_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_15 = 16;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_15_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_4R = 20;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_4R_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_4W = 24;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_4W_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_5 = 28;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_5_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_6 = 32;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_6_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_7 = 36;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_7_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_8 = 40;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_8_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_9 = 44;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_9_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_10 = 48;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_10_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_11 = 52;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_11_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_12 = 56;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_12_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_13 = 60;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX2_13_LEN = 4;
// proc/reg00012.H

static const uint64_t INT_PC_REGS_ERR1_CFG0 = 0x02010ac8ull;

static const uint32_t INT_PC_REGS_ERR1_CFG0_INT_PC_ERR1_CFG0_ERROR_CONFIG0 = 0;
static const uint32_t INT_PC_REGS_ERR1_CFG0_INT_PC_ERR1_CFG0_ERROR_CONFIG0_LEN = 64;
// proc/reg00012.H

static const uint64_t INT_PC_REGS_ERR1_INFO = 0x02010aceull;

static const uint32_t INT_PC_REGS_ERR1_INFO_INT_PC_ERR1_INFO_ERROR = 0;
static const uint32_t INT_PC_REGS_ERR1_INFO_INT_PC_ERR1_INFO_ERROR_LEN = 64;
// proc/reg00012.H

static const uint64_t INT_PC_REGS_ESB_BLOCK_MODE = 0x02010a08ull;

static const uint32_t INT_PC_REGS_ESB_BLOCK_MODE_INT_PC_ESB_BLOCK_MODE = 0;
static const uint32_t INT_PC_REGS_ESB_BLOCK_MODE_INT_PC_ESB_BLOCK_MODE_LEN = 32;
// proc/reg00012.H

static const uint64_t INT_PC_REGS_MMIO_ARB = 0x02010a1aull;

static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_LDST_ARB_PRIO_SET_LD = 0;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_LDST_ARB_PRIO_SET_LD_LEN = 2;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_LDST_ARB_PRIO_RSP_LD = 2;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_LDST_ARB_PRIO_RSP_LD_LEN = 2;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_4_5 = 4;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_4_5_LEN = 2;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_PARSE_PULL_ST_RR_SEL = 6;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_PARSE_PULL_ST_RR_SEL_LEN = 2;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_PARSE_IACK_RR_SEL = 8;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_PARSE_IACK_RR_SEL_LEN = 2;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_PULL_ST_PRIO_HYP = 10;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_PULL_ST_PRIO_HYP_LEN = 2;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_IACK_PRIO_HYP = 12;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_IACK_PRIO_HYP_LEN = 2;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_14 = 14;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_PARSE_PULL_LD_RR_SEL = 15;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_16 = 16;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_PCMD_ARB_PRIO_LDST_SET = 17;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_PCMD_ARB_PRIO_LDST_SET_LEN = 3;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_20 = 20;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_PCMD_ARB_PRIO_LDST_RSP = 21;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_PCMD_ARB_PRIO_LDST_RSP_LEN = 3;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_24 = 24;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_PCMD_ARB_PRIO_DONE = 25;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_PCMD_ARB_PRIO_DONE_LEN = 3;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_28 = 28;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_PCMD_ARB_PRIO_RR = 29;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_PCMD_ARB_PRIO_RR_LEN = 3;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_32 = 32;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_PRIO_IACK = 33;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_PRIO_IACK_LEN = 3;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_36 = 36;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_PRIO_PULL_ST = 37;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_PRIO_PULL_ST_LEN = 3;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_40 = 40;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_PRIO_PULL_LD = 41;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_PRIO_PULL_LD_LEN = 3;
static const uint32_t INT_PC_REGS_MMIO_ARB_RESERVED_44 = 44;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_PRIO_RR = 45;
static const uint32_t INT_PC_REGS_MMIO_ARB_CFG_MMIO_DONE_ARB_PRIO_RR_LEN = 3;
// proc/reg00012.H

static const uint64_t INT_PC_REGS_PCMD_ARB = 0x02010a18ull;

static const uint32_t INT_PC_REGS_PCMD_ARB_RESERVED_0 = 0;
static const uint32_t INT_PC_REGS_PCMD_ARB_CFG_PCMD_ARB_PRIO_LSI = 1;
static const uint32_t INT_PC_REGS_PCMD_ARB_CFG_PCMD_ARB_PRIO_LSI_LEN = 3;
static const uint32_t INT_PC_REGS_PCMD_ARB_RESERVED_4 = 4;
static const uint32_t INT_PC_REGS_PCMD_ARB_CFG_PCMD_ARB_PRIO_MMIO = 5;
static const uint32_t INT_PC_REGS_PCMD_ARB_CFG_PCMD_ARB_PRIO_MMIO_LEN = 3;
static const uint32_t INT_PC_REGS_PCMD_ARB_RESERVED_8 = 8;
static const uint32_t INT_PC_REGS_PCMD_ARB_CFG_PCMD_ARB_PRIO_NRQ_REQ = 9;
static const uint32_t INT_PC_REGS_PCMD_ARB_CFG_PCMD_ARB_PRIO_NRQ_REQ_LEN = 3;
static const uint32_t INT_PC_REGS_PCMD_ARB_RESERVED_12 = 12;
static const uint32_t INT_PC_REGS_PCMD_ARB_CFG_PCMD_ARB_PRIO_NRQ_RSP = 13;
static const uint32_t INT_PC_REGS_PCMD_ARB_CFG_PCMD_ARB_PRIO_NRQ_RSP_LEN = 3;
static const uint32_t INT_PC_REGS_PCMD_ARB_RESERVED_16 = 16;
static const uint32_t INT_PC_REGS_PCMD_ARB_CFG_PCMD_ARB_PRIO_RR = 17;
static const uint32_t INT_PC_REGS_PCMD_ARB_CFG_PCMD_ARB_PRIO_RR_LEN = 3;
// proc/reg00012.H

static const uint64_t INT_VC_ENDC_CFG = 0x02010988ull;

static const uint32_t INT_VC_ENDC_CFG_RESERVED_0_2 = 0;
static const uint32_t INT_VC_ENDC_CFG_RESERVED_0_2_LEN = 3;
static const uint32_t INT_VC_ENDC_CFG_MAX_NOSYS_CNT = 3;
static const uint32_t INT_VC_ENDC_CFG_MAX_NOSYS_CNT_LEN = 5;
static const uint32_t INT_VC_ENDC_CFG_RESERVED_8 = 8;
static const uint32_t INT_VC_ENDC_CFG_CLEAR_EQVGPREDICT_ON_VH_DROP = 9;
static const uint32_t INT_VC_ENDC_CFG_CLEAR_EQVGPREDICT_ON_VH_SET = 10;
static const uint32_t INT_VC_ENDC_CFG_CLEAR_EQVGPREDICT_ON_VT_DROP = 11;
static const uint32_t INT_VC_ENDC_CFG_RESERVED_12 = 12;
static const uint32_t INT_VC_ENDC_CFG_CLEAR_EQVGPREDICT_AFTER_EQP = 13;
static const uint32_t INT_VC_ENDC_CFG_CLEAR_EQVGPREDICT_AFTER_EQP_LEN = 3;
static const uint32_t INT_VC_ENDC_CFG_CORE_LOADS_ORDERING_RULE = 16;
static const uint32_t INT_VC_ENDC_CFG_CORE_LOADS_ORDERING_RULE_LEN = 2;
static const uint32_t INT_VC_ENDC_CFG_TRIG_FWD_TARGET_QUEUE = 18;
static const uint32_t INT_VC_ENDC_CFG_TRIG_FWD_TARGET_QUEUE_LEN = 8;
static const uint32_t INT_VC_ENDC_CFG_ESC_TARGET_QUEUE = 26;
static const uint32_t INT_VC_ENDC_CFG_ESC_TARGET_QUEUE_LEN = 6;
static const uint32_t INT_VC_ENDC_CFG_CACHE_WATCH_ASSIGN = 32;
static const uint32_t INT_VC_ENDC_CFG_CACHE_WATCH_ASSIGN_LEN = 4;
static const uint32_t INT_VC_ENDC_CFG_RESERVED_36_42 = 36;
static const uint32_t INT_VC_ENDC_CFG_RESERVED_36_42_LEN = 7;
static const uint32_t INT_VC_ENDC_CFG_SKIP_ESCALATE = 43;
static const uint32_t INT_VC_ENDC_CFG_RESERVED_44_45 = 44;
static const uint32_t INT_VC_ENDC_CFG_RESERVED_44_45_LEN = 2;
static const uint32_t INT_VC_ENDC_CFG_MAX_PTAG_IN_USE = 46;
static const uint32_t INT_VC_ENDC_CFG_MAX_PTAG_IN_USE_LEN = 6;
static const uint32_t INT_VC_ENDC_CFG_BG_SCAN_RATE = 52;
static const uint32_t INT_VC_ENDC_CFG_BG_SCAN_RATE_LEN = 4;
static const uint32_t INT_VC_ENDC_CFG_RESERVED_56 = 56;
static const uint32_t INT_VC_ENDC_CFG_FORCE_INVALIDATE = 57;
static const uint32_t INT_VC_ENDC_CFG_MAX_ENTRIES_IN_MODIFIED = 58;
static const uint32_t INT_VC_ENDC_CFG_MAX_ENTRIES_IN_MODIFIED_LEN = 6;
// proc/reg00012.H

static const uint64_t INT_VC_ENDC_WATCH0_DATA0 = 0x020109a4ull;
// proc/reg00012.H

static const uint64_t INT_VC_EQA_TO_ENDC_CREDITS = 0x02010925ull;

static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_0_2 = 0;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_0_2_LEN = 3;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_IPI_RSD_CREDITS = 3;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_IPI_RSD_CREDITS_LEN = 5;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_8_10 = 8;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_8_10_LEN = 3;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_HWD_RSD_CREDITS = 11;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_HWD_RSD_CREDITS_LEN = 5;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_16_18 = 16;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_16_18_LEN = 3;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_NXC_RSD_CREDITS = 19;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_NXC_RSD_CREDITS_LEN = 5;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_24_26 = 24;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_24_26_LEN = 3;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_INT_RSD_CREDITS = 27;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_INT_RSD_CREDITS_LEN = 5;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_32_34 = 32;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_32_34_LEN = 3;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_OS_RSD_CREDITS = 35;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_OS_RSD_CREDITS_LEN = 5;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_40_42 = 40;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_40_42_LEN = 3;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_POOL_RSD_CREDITS = 43;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_POOL_RSD_CREDITS_LEN = 5;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_48_50 = 48;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_48_50_LEN = 3;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_HARD_RSD_CREDITS = 51;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_HARD_RSD_CREDITS_LEN = 5;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_56_57 = 56;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_RESERVED_56_57_LEN = 2;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_POOL_CREDITS = 58;
static const uint32_t INT_VC_EQA_TO_ENDC_CREDITS_POOL_CREDITS_LEN = 6;
// proc/reg00012.H

static const uint64_t INT_VC_ESBC_FLUSH_INJECT = 0x02010942ull;

static const uint32_t INT_VC_ESBC_FLUSH_INJECT_RESERVED_0_3 = 0;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_RESERVED_0_3_LEN = 4;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_BLOCKID = 4;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_BLOCKID_LEN = 4;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_RESERVED_8 = 8;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_OFFSET = 9;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_OFFSET_LEN = 23;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_RESERVED_32_35 = 32;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_RESERVED_32_35_LEN = 4;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_BLOCKID_MASK = 36;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_BLOCKID_MASK_LEN = 4;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_RESERVED_40 = 40;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_OFFSET_MASK = 41;
static const uint32_t INT_VC_ESBC_FLUSH_INJECT_OFFSET_MASK_LEN = 23;
// proc/reg00012.H

static const uint64_t INT_VC_ESBC_PERF_EVENT_SEL_3 = 0x0201095aull;

static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_PROC_UPDATE = 0;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_PROC_UPDATE_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_CNT_ESB_FETCH = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_CNT_ESB_FETCH_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_CNT_ESB_WRITE = 8;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_CNT_ESB_WRITE_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_CNT_ESB_FETCH_REPLAY = 12;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_CNT_ESB_FETCH_REPLAY_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_CNT_TRIGGER_FILTERED = 16;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_CNT_TRIGGER_FILTERED_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_CNT_STEOI_FILTERED = 20;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_3_CNT_STEOI_FILTERED_LEN = 4;
// proc/reg00012.H

static const uint64_t INT_VC_ESBC_SOFTWR_MASK = 0x02010951ull;

static const uint32_t INT_VC_ESBC_SOFTWR_MASK_INT_VC_ESBC_SOFTWR_MASK_MSK = 0;
static const uint32_t INT_VC_ESBC_SOFTWR_MASK_INT_VC_ESBC_SOFTWR_MASK_MSK_LEN = 32;
// proc/reg00012.H

static const uint64_t INT_VC_WOF_ERR_G1_DETAIL = 0x020109cbull;

static const uint32_t INT_VC_WOF_ERR_G1_DETAIL_INT_VC_WOF_ERR_G1_DETAIL_ERROR = 0;
static const uint32_t INT_VC_WOF_ERR_G1_DETAIL_INT_VC_WOF_ERR_G1_DETAIL_ERROR_LEN = 64;
// proc/reg00012.H

static const uint64_t MCD_BANK0_BOT = 0x0301080cull;

static const uint32_t MCD_BANK0_BOT_VALID = 0;
static const uint32_t MCD_BANK0_BOT_CPG = 1;
static const uint32_t MCD_BANK0_BOT_GRP_MBR_ID = 2;
static const uint32_t MCD_BANK0_BOT_ALWAYS_RTY = 3;
static const uint32_t MCD_BANK0_BOT_SMF_ENABLE = 6;
static const uint32_t MCD_BANK0_BOT_GRP_SIZE = 11;
static const uint32_t MCD_BANK0_BOT_GRP_SIZE_LEN = 19;
static const uint32_t MCD_BANK0_BOT_GRP_BASE = 33;
static const uint32_t MCD_BANK0_BOT_GRP_BASE_LEN = 31;
// proc/reg00012.H

static const uint64_t MCD_BANK0_TOPID = 0x03010818ull;

static const uint32_t MCD_BANK0_TOPID_ACTIVE0_ENABLE = 0;
static const uint32_t MCD_BANK0_TOPID_ACTIVE0_TOPO_ID = 1;
static const uint32_t MCD_BANK0_TOPID_ACTIVE0_TOPO_ID_LEN = 5;
static const uint32_t MCD_BANK0_TOPID_ACTIVE1_ENABLE = 8;
static const uint32_t MCD_BANK0_TOPID_ACTIVE1_TOPO_ID = 9;
static const uint32_t MCD_BANK0_TOPID_ACTIVE1_TOPO_ID_LEN = 5;
static const uint32_t MCD_BANK0_TOPID_ACTIVE2_ENABLE = 16;
static const uint32_t MCD_BANK0_TOPID_ACTIVE2_TOPO_ID = 17;
static const uint32_t MCD_BANK0_TOPID_ACTIVE2_TOPO_ID_LEN = 5;
static const uint32_t MCD_BANK0_TOPID_ACTIVE3_ENABLE = 24;
static const uint32_t MCD_BANK0_TOPID_ACTIVE3_TOPO_ID = 25;
static const uint32_t MCD_BANK0_TOPID_ACTIVE3_TOPO_ID_LEN = 5;
static const uint32_t MCD_BANK0_TOPID_PASSIVE_TOPO_ID = 32;
static const uint32_t MCD_BANK0_TOPID_PASSIVE_TOPO_ID_LEN = 32;
// proc/reg00012.H

static const uint64_t MM0_MM_CFG_NMMU_XLAT_CTL_REG0 = 0x02010c4aull;

static const uint32_t MM0_MM_CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR = 0;
static const uint32_t MM0_MM_CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR_LEN = 64;
// proc/reg00012.H

static const uint64_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RWX = 0x02010c00ull;
static const uint64_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WOX_AND = 0x02010c01ull;
static const uint64_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WOX_OR = 0x02010c02ull;

static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR = 0;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR = 1;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR = 2;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR = 3;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR = 4;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR = 5;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR = 6;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR = 7;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR = 8;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR = 9;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR = 10;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR = 11;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR = 12;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR = 13;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR = 14;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR = 15;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR = 16;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR = 17;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR = 18;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR = 19;
// proc/reg00012.H

static const uint64_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG = 0x02010c28ull;

static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE = 4;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE_LEN = 4;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE = 8;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE_LEN = 4;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE = 12;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE_LEN = 4;
// proc/reg00012.H

static const uint64_t MM1_MM_CFG_NMMU_CTL_TLB = 0x03010c55ull;

static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_MBR_DIS = 0;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_MBR_DIS_LEN = 16;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN = 16;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS = 17;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN = 18;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_MPSS_DIS = 19;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS = 20;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS = 21;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS = 22;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS = 23;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS = 24;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS = 25;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS = 26;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS = 27;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS = 28;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS = 29;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS = 30;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS = 31;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL = 32;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL_LEN = 4;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL = 36;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL_LEN = 4;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS = 40;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS = 41;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS = 42;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS = 43;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ = 44;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ_LEN = 4;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ = 48;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ_LEN = 4;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS = 52;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN = 53;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS = 54;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS = 55;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA = 56;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA = 57;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA = 58;
static const uint32_t MM1_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA = 59;
// proc/reg00012.H

static const uint64_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG = 0x03010c15ull;

static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN = 0;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP = 1;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS = 2;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN = 3;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN = 4;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP = 5;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS = 6;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN = 7;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG = 30;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES = 31;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES_LEN = 2;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE = 33;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G = 34;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED = 35;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED_LEN = 2;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE = 37;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL = 38;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE = 39;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK = 40;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK_LEN = 8;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK = 48;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK_LEN = 8;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK = 56;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK_LEN = 7;
// proc/reg00012.H

static const uint64_t NX_CH4_ADDR_9_HASH_FUNCTION_REG = 0x0201114aull;

static const uint32_t NX_CH4_ADDR_9_HASH_FUNCTION_REG_ADDRESS_9_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_9_HASH_FUNCTION_REG_ADDRESS_9_HASH_FUNCTION_LEN = 64;
// proc/reg00012.H

static const uint64_t NX_DMA_SU_ERROR_REPORT_0 = 0x02011057ull;

static const uint32_t NX_DMA_SU_ERROR_REPORT_0_DMA_ERROR_REPORT_0 = 0;
static const uint32_t NX_DMA_SU_ERROR_REPORT_0_DMA_ERROR_REPORT_0_LEN = 64;
// proc/reg00012.H

static const uint64_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_BAR = 0x020110c2ull;

static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_BAR_GZIP_HI_PRIORITY_RCV_FIFO_BAR = 8;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_BAR_GZIP_HI_PRIORITY_RCV_FIFO_BAR_LEN = 46;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_BAR_GZIP_HI_PRIORITY_RCV_FIFO_BAR_SIZE = 54;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_BAR_GZIP_HI_PRIORITY_RCV_FIFO_BAR_SIZE_LEN = 3;
// proc/reg00012.H

static const uint64_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_ASB = 0x020110d1ull;

static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_ASB_LPID = 4;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_ASB_LPID_LEN = 12;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_ASB_PID = 20;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_ASB_PID_LEN = 20;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_ASB_TID = 44;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_ASB_TID_LEN = 16;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_ASB_ENABLE = 63;
// proc/reg00012.H

static const uint64_t NX_PBI_UMAC_SU_ERROR_RPT1 = 0x020110d8ull;

static const uint32_t NX_PBI_UMAC_SU_ERROR_RPT1_RNG_ERROR_RPT = 0;
static const uint32_t NX_PBI_UMAC_SU_ERROR_RPT1_RNG_ERROR_RPT_LEN = 6;
// proc/reg00012.H

static const uint64_t PB_COM_ES3_EVENT_COMPA = 0x0000039bull;

static const uint32_t PB_COM_ES3_EVENT_COMPA_TTYPE_ES3 = 0;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TTYPE_ES3_LEN = 7;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TTYPE_MASK_ES3 = 7;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TTYPE_MASK_ES3_LEN = 7;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TSIZE_ES3 = 14;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TSIZE_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TSIZE_MASK_ES3 = 22;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TSIZE_MASK_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TTAG_ES3 = 30;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TTAG_ES3_LEN = 10;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TTAG_MASK_ES3 = 40;
static const uint32_t PB_COM_ES3_EVENT_COMPA_TTAG_MASK_ES3_LEN = 10;
static const uint32_t PB_COM_ES3_EVENT_COMPA_CRESP_ES3 = 50;
static const uint32_t PB_COM_ES3_EVENT_COMPA_CRESP_ES3_LEN = 5;
static const uint32_t PB_COM_ES3_EVENT_COMPA_CRESP_MASK_ES3 = 55;
static const uint32_t PB_COM_ES3_EVENT_COMPA_CRESP_MASK_ES3_LEN = 5;
static const uint32_t PB_COM_ES3_EVENT_COMPA_CRESP_POLARITY_ES3 = 60;
static const uint32_t PB_COM_ES3_EVENT_COMPA_SCOPE_ES3 = 61;
static const uint32_t PB_COM_ES3_EVENT_COMPA_SCOPE_ES3_LEN = 3;
// proc/reg00012.H

static const uint64_t PB_COM_ES3_EVENT_COMPX = 0x0000039dull;

static const uint32_t PB_COM_ES3_EVENT_COMPX_A_SCOPE_MASK_ES3 = 0;
static const uint32_t PB_COM_ES3_EVENT_COMPX_A_SCOPE_MASK_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_EVENT_COMPX_A_PRESP_ES3 = 3;
static const uint32_t PB_COM_ES3_EVENT_COMPX_A_PRESP_ES3_LEN = 14;
static const uint32_t PB_COM_ES3_EVENT_COMPX_A_PRESP_MASK_ES3 = 17;
static const uint32_t PB_COM_ES3_EVENT_COMPX_A_PRESP_MASK_ES3_LEN = 14;
static const uint32_t PB_COM_ES3_EVENT_COMPX_B_SCOPE_MASK_ES3 = 32;
static const uint32_t PB_COM_ES3_EVENT_COMPX_B_SCOPE_MASK_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_EVENT_COMPX_B_PRESP_ES3 = 35;
static const uint32_t PB_COM_ES3_EVENT_COMPX_B_PRESP_ES3_LEN = 14;
static const uint32_t PB_COM_ES3_EVENT_COMPX_B_PRESP_MASK_ES3 = 49;
static const uint32_t PB_COM_ES3_EVENT_COMPX_B_PRESP_MASK_ES3_LEN = 14;
static const uint32_t PB_COM_ES3_EVENT_COMPX_AB_LPC_D_MODE_ES3 = 63;
// proc/reg00012.H

static const uint64_t PB_COM_ES3_FIR_MASK_REG_RWX = 0x03011383ull;
static const uint64_t PB_COM_ES3_FIR_MASK_REG_WOX_AND = 0x00000384ull;
static const uint64_t PB_COM_ES3_FIR_MASK_REG_WOX_OR = 0x00000385ull;

static const uint32_t PB_COM_ES3_FIR_MASK_REG_PROTOCOL_ERROR_MASK = 0;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_OVERFLOW_ERROR_MASK = 1;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_HW_PARITY_ERROR_MASK = 2;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_FIR_SPARE_3_MASK = 3;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_COHERENCY_ERROR_MASK = 4;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK = 5;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_CRESP_ERROR_MASK = 6;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK = 7;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK = 8;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK = 9;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_FORCE_MP_IPL_MASK = 10;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_SBE_IPL_MASK = 11;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_FIR_SPARE_12_MASK = 12;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_FIR_SPARE_13_MASK = 13;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_FIR_SPARE_14_MASK = 14;
static const uint32_t PB_COM_ES3_FIR_MASK_REG_FIR_SPARE_15_MASK = 15;
// proc/reg00012.H

static const uint64_t PB_COM_ES3_HP_MODE2_CURR = 0x0000038eull;

static const uint32_t PB_COM_ES3_HP_MODE2_CURR_0_EN_CURR_ES3 = 0;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_1_EN_CURR_ES3 = 1;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_2_EN_CURR_ES3 = 2;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_3_EN_CURR_ES3 = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_4_EN_CURR_ES3 = 4;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_5_EN_CURR_ES3 = 5;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_6_EN_CURR_ES3 = 6;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_7_EN_CURR_ES3 = 7;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_0_ADDR_DIS_CURR_ES3 = 8;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_1_ADDR_DIS_CURR_ES3 = 9;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_2_ADDR_DIS_CURR_ES3 = 10;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_3_ADDR_DIS_CURR_ES3 = 11;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_4_ADDR_DIS_CURR_ES3 = 12;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_5_ADDR_DIS_CURR_ES3 = 13;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_6_ADDR_DIS_CURR_ES3 = 14;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_7_ADDR_DIS_CURR_ES3 = 15;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_0_MODE_CURR_ES3 = 16;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_0_ID_CURR_ES3 = 17;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_0_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_1_MODE_CURR_ES3 = 20;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_1_ID_CURR_ES3 = 21;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_1_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_2_MODE_CURR_ES3 = 24;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_2_ID_CURR_ES3 = 25;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_2_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_3_MODE_CURR_ES3 = 28;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_3_ID_CURR_ES3 = 29;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_3_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_4_MODE_CURR_ES3 = 32;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_4_ID_CURR_ES3 = 33;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_4_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_5_MODE_CURR_ES3 = 36;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_5_ID_CURR_ES3 = 37;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_5_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_6_MODE_CURR_ES3 = 40;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_6_ID_CURR_ES3 = 41;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_6_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_7_MODE_CURR_ES3 = 44;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_7_ID_CURR_ES3 = 45;
static const uint32_t PB_COM_ES3_HP_MODE2_CURR_7_ID_CURR_ES3_LEN = 3;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM10_FM0123_ERR = 0x10011827ull;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM10_MAILBOX_10_REG = 0x10011832ull;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM10_MAILBOX_11_REG = 0x10011833ull;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM23_PTL_FIR_ACTION0_REG = 0x11011806ull;

static const uint32_t PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 = 0;
static const uint32_t PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN = 62;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM23_PTL_FIR_ACTION1_REG = 0x11011807ull;

static const uint32_t PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 = 0;
static const uint32_t PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN = 62;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM23_TL_LINK_SYN_23_REG = 0x11011813ull;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM45_MAILBOX_00_REG = 0x12011830ull;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM45_MAILBOX_01_REG = 0x12011831ull;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM45_PMU0_TLPM_COUNTER = 0x1201181bull;
// proc/reg00012.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint64_t PB_PTLSCOM45_PTL_FIR_MASK_REG_RWX = 0x12011803ull;
static const uint64_t PB_PTLSCOM45_PTL_FIR_MASK_REG_WOX_AND = 0x00000004ull;
static const uint64_t PB_PTLSCOM45_PTL_FIR_MASK_REG_WOX_OR = 0x00000005ull;

static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK = 0;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK = 1;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK = 2;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK = 3;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK = 8;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK = 9;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK = 10;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK = 11;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK = 12;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK = 13;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK = 20;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK = 21;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK = 22;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK = 23;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK = 28;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK = 29;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK = 30;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK = 31;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK = 36;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK = 37;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK = 38;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK = 39;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK = 40;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK = 41;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK = 42;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK = 43;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK = 52;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK = 53;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK = 56;
static const uint32_t PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK = 57;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM45_TRACE_CFG = 0x12011826ull;

static const uint32_t PB_PTLSCOM45_TRACE_CFG_0L_SEL = 0;
static const uint32_t PB_PTLSCOM45_TRACE_CFG_0L_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM45_TRACE_CFG_0R_SEL = 8;
static const uint32_t PB_PTLSCOM45_TRACE_CFG_0R_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM45_TRACE_CFG_1L_SEL = 16;
static const uint32_t PB_PTLSCOM45_TRACE_CFG_1L_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM45_TRACE_CFG_1R_SEL = 24;
static const uint32_t PB_PTLSCOM45_TRACE_CFG_1R_SEL_LEN = 8;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM45_RCMD_RATE_CFG = 0x1201180cull;

static const uint32_t PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE = 0;
static const uint32_t PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_LEN = 8;
static const uint32_t PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE = 8;
static const uint32_t PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_LEN = 8;
static const uint32_t PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER = 16;
static const uint32_t PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN = 4;
static const uint32_t PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER = 20;
static const uint32_t PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN = 4;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM67_DOB23_DIB23_INT_ERR_REG = 0x1301182aull;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM67_MAILBOX_DATA_REG = 0x1301182full;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM67_PMU3_CNPM_COUNTER = 0x13011824ull;
// proc/reg00012.H

static const uint64_t PB_PTLSCOM67_PR0123_ERR = 0x13011829ull;
// proc/reg00013.H

static const uint64_t PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG = 0x13011819ull;

static const uint32_t PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET = 0;
static const uint32_t PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET = 2;
static const uint32_t PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT = 4;
static const uint32_t PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN = 2;
static const uint32_t PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT = 6;
static const uint32_t PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN = 2;
// proc/reg00013.H

static const uint64_t PB_BRIDGE_HCA_FIR_WOF = 0x03012408ull;

static const uint32_t PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS = 0;
static const uint32_t PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS_LEN = 28;
// proc/reg00013.H

static const uint64_t PB_BRIDGE_HCA_CHSW_CTRL_REG = 0x03012417ull;

static const uint32_t PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK = 0;
static const uint32_t PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK_LEN = 12;
// proc/reg00013.H

static const uint64_t PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG = 0x03012412ull;

static const uint32_t PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS = 24;
static const uint32_t PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS_LEN = 33;
// proc/reg00013.H

static const uint64_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST = 0x030120c3ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS_LEN = 49;
// proc/reg00013.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_RESERVED1_REG = 0x0801088cull;
// proc/reg00013.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG = 0x02011809ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0_LEN = 16;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1 = 16;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1_LEN = 8;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE = 24;
// proc/reg00013.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PBCQMODE_REG = 0x020118cdull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PBCQMODE_REG_PEER2PEER_MODDE = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PBCQMODE_REG_ENHANCED_PEER2PEER_MODDE = 1;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PBCQMODE_REG_PB_CQ_REGS_CS_ENABLE_SMF = 2;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PBCQMODE_REG_ATOMIC_LITTLE_ENDIAN = 3;
// proc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR = 0x00000953ull;
// proc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR = 0x00000993ull;
// proc/reg00013.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG1 = 0x0301180dull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG1_PE_TOPOLOGY_ID_REG1 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG1_PE_TOPOLOGY_ID_REG1_LEN = 40;
// proc/reg00013.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRMASK_REG_RW = 0x03011843ull;
static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRMASK_REG_WO_AND = 0x03011844ull;
static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRMASK_REG_WO_OR = 0x03011845ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRMASK_REG_NFIRMASK = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRMASK_REG_NFIRMASK_LEN = 28;
// proc/reg00013.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_CQSTAT_REG = 0x0301188cull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_CQSTAT_REG_INBOUND_ACTIVE = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_CQSTAT_REG_OUTBOUND_ACTIVE = 1;
// proc/reg00013.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRWOF_REG = 0x03011888ull;
// proc/reg00013.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIR_REG_RWX = 0x03011880ull;
static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIR_REG_WOX_AND = 0x03011881ull;
static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIR_REG_WOX_OR = 0x03011882ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIR_REG_NFIRNFIR = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIR_REG_NFIRNFIR_LEN = 28;
// proc/reg00013.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PHBBAR_REG = 0x03011892ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PHBBAR_REG_PE_PHB_BAR = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PHBBAR_REG_PE_PHB_BAR_LEN = 42;
// proc/reg00013.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_INTBAR_REG = 0x030118d3ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_INTBAR_REG_PE_INT_BAR = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_INTBAR_REG_PE_INT_BAR_LEN = 28;
// proc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE1_PHB0_ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PAST = 0x00000915ull;
// proc/reg00013.H

static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL = 0x09010945ull;

static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE = 0;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE = 1;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE = 2;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE = 3;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE = 4;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE = 5;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE = 6;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE = 7;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE = 8;
// proc/reg00013.H

static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_ACTION1_REG = 0x0901098full;
// proc/reg00013.H

static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL = 0x09010985ull;

static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE = 0;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE = 1;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE = 2;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE = 3;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE = 4;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE = 5;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE = 6;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE = 7;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE = 8;
// proc/reg00013.H

static const uint64_t TP_TPBR_AD_ALTD_STATUS_REG = 0x03001c03ull;

static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT = 1;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE = 2;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE = 3;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP = 4;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR = 5;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR = 6;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR = 7;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR = 8;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR = 9;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR = 10;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR = 11;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR = 12;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT = 16;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE = 17;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR = 33;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR_LEN = 5;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE = 48;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE = 49;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE = 50;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE = 59;
static const uint32_t TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE_LEN = 5;
// proc/reg00013.H

static const uint64_t TP_TPBR_AD_XSCOM_LOG_REG = 0x03001c12ull;

static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG = 0;
static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS = 1;
static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS_LEN = 3;
static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD = 4;
static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG = 5;
static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG_LEN = 20;
static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_THR_ID = 27;
static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_THR_ID_LEN = 3;
static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY = 31;
static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR = 33;
static const uint32_t TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR_LEN = 31;
// proc/reg00013.H

static const uint64_t TP_TPBR_PBA_PBAO_BCDE_SET = 0x00068011ull;

static const uint32_t TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH_LEN = 6;
// proc/reg00013.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABAR1 = 0x03021c9bull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR1_ADDR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR1_ADDR_LEN = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR1_VTARGET = 48;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR1_VTARGET_LEN = 16;
// proc/reg00013.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABARMSK0 = 0x03021c9eull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK_LEN = 21;
// proc/reg00013.H

static const uint64_t TP_TPBR_PBA_PBAO_PBARBUFVAL1 = 0x03021c91ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR_LEN = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT = 31;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS = 33;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS_LEN = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID = 41;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID_LEN = 3;
// proc/reg00013.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXISHBR0 = 0x00068036ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START_LEN = 29;
// proc/reg00013.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXISHCS1 = 0x0006803bull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3 = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR = 13;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE = 31;
// proc/reg00013.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXSHBR0 = 0x00068026ull;
// proc/reg00013.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXSHCS1 = 0x0006802bull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3 = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR = 13;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE = 31;
// proc/reg00013.H

static const uint64_t TP_TPBR_PSI_WRAP_TX_CH_MISC_REG = 0x03011c13ull;
// proc/reg00013.H

static const uint64_t TP_TPBR_PSIHB_NOTRUST_BAR0 = 0x03011f40ull;

static const uint32_t TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0 = 14;
static const uint32_t TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0_LEN = 30;
// proc/reg00013.H

static const uint64_t TP_TPBR_PSIHB_FIR_MASK_REG_RW = 0x03011d03ull;
static const uint64_t TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND = 0x03011d04ull;
static const uint64_t TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR = 0x03011d05ull;

static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK = 0;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK = 1;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK = 2;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK = 3;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK = 4;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK = 5;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK = 6;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK = 7;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK = 8;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK = 9;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK = 10;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK = 11;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK = 12;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK = 13;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK = 14;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK = 15;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK = 16;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK = 17;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK = 18;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK = 19;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK = 20;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK = 21;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK = 22;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK = 23;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK = 24;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK_LEN = 3;
static const uint32_t TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK = 27;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31 = 0x0006004full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31_LEN = 32;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30 = 0x0006204eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN = 32;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5 = 0x00062045ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN = 32;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR = 0x00062031ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN = 32;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0 = 0x00062022ull;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4 = 0x00062082ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5_LEN = 32;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL = 0x00064000ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL_LEN = 4;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF = 0x0006401full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0_LEN = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR_LEN = 32;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1 = 0x00064041ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN = 32;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM = 0x00064017ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE = 35;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE_LEN = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE = 43;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING = 62;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING = 63;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML = 0x00064029ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_BUSY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_BYTE_ENABLE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_BYTE_ENABLE_LEN = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_LINE_MODE = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_ERROR = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_ERROR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_IFETCH_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_DATAOP_PENDING = 31;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU = 0x00064028ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN = 32;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0 = 0x00064030ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN = 30;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0 = 0x00064080ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1_LEN = 32;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30 = 0x00064087ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1_LEN = 32;
// proc/reg00013.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR = 0x00066020ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN = 3;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICAC = 0x00066019ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIICAC_MEM_IFETCH_PENDING = 35;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SST0A = 0x0006c706ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0A__ONGOING_0A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0A__WRITE_WHILE_BRIDGE_BUSY_ERR_0A = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0A__FSM_ERR_0A = 7;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1 = 0x0006c218ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR_LEN = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK_LEN = 12;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1 = 0x0006c21aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0_LEN = 5;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2 = 0x0006c220ull;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3 = 0x0006c231ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE = 31;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW = 0x0006c0a9ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR = 0x0006c0aaull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR = 0x0006c0abull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3_LEN = 32;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q2 = 0x0006c40aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q2_OCB_OCI_OPIT1Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q2_OCB_OCI_OPIT1Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q6 = 0x0006c416ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q6_OCB_OCI_OPIT2Q6RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q6_OCB_OCI_OPIT2Q6RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q0 = 0x0006c428ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q0_OCB_OCI_OPIT5Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q0_OCB_OCI_OPIT5Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6PRA_ROX = 0x0006c630ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6PRA_WOX_CLEAR = 0x0006c631ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6PRA_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6PRA_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6PRA_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6PRA_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6PRA_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6PRA_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6PRA_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6PRA_7 = 7;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q4 = 0x0006c434ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q4_OCB_OCI_OPIT6Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q4_OCB_OCI_OPIT6Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0 = 0x0006c440ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0_PAYLOAD_LEN = 17;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12RR = 0x0006c54cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12RR_PAYLOAD_LEN = 17;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C19 = 0x0006c453ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C19_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C19_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C19_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C19_PAYLOAD_LEN = 17;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20RR = 0x0006c554ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20RR_PAYLOAD_LEN = 17;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C31 = 0x0006c45full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C31_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C31_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C31_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C31_PAYLOAD_LEN = 17;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15RR = 0x0006c56full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15RR_PAYLOAD_LEN = 17;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C27RR = 0x0006c57bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C27RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C27RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C27RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C27RR_PAYLOAD_LEN = 17;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C28 = 0x0006c47cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C28_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C28_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C28_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C28_PAYLOAD_LEN = 17;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30RR = 0x0006c57eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30RR_PAYLOAD_LEN = 17;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2 = 0x0006c486ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2_7_LEN = 4;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR = 0x0006c588ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCSVRR_7_LEN = 4;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR = 0x0006c58cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSVRR_7_LEN = 4;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR = 0x0006c590ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESVRR_7_LEN = 4;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR = 0x0006c594ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSVRR_7_LEN = 4;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL = 0x0006c780ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_LINK_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_LINK_RESET = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_CPOL = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_CPHA = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_CLOCK_DIVIDER = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_CLOCK_DIVIDER_LEN = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_RESERVED_14 = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_WRAP_ENABLE = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_INTERFACE_ENABLE_NORTH = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_INTERFACE_ENABLE_SOUTH = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_SYNC_EN = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_RESERVED_19 = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_ECC_GEN_EN = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_ECC_CHECK_EN = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_RX_FSM_FREEZE_ON_UE = 22;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL_INTERCHIP_RESET_ECC_ERR = 23;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICRD = 0x0006c783ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICRD_OCB_OCI_WOFICRD_WOFCNTL_RDDATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICRD_OCB_OCI_WOFICRD_WOFCNTL_RDDATA_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SCOM = 0x0006d071ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SCOM1 = 0x0006d072ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SCOM2 = 0x0006d073ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1 = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_FSM_ERR = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2 = 15;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2 = 0x0006d055ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1 = 0x0006d034ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR_LEN = 32;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OCC_SRAM_CTL_SRBV1 = 0x0006a005ull;

static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1 = 0;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1_LEN = 32;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG108 = 0x0000806cull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG108_REGISTER108 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG108_REGISTER108_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG117 = 0x00008075ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG117_REGISTER117 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG117_REGISTER117_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG120 = 0x00008078ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG120_REGISTER120 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG120_REGISTER120_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG17 = 0x00008011ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG17_REGISTER17 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG17_REGISTER17_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG20 = 0x00008014ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG20_REGISTER20 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG20_REGISTER20_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG3 = 0x00008003ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG3_REGISTER3 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG3_REGISTER3_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG41 = 0x00008029ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG41_REGISTER41 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG41_REGISTER41_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG69 = 0x00008045ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG69_REGISTER69 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG69_REGISTER69_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG76 = 0x0000804cull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG76_REGISTER76 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG76_REGISTER76_LEN = 64;
// proc/reg00014.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG83 = 0x00008053ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG83_REGISTER83 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG83_REGISTER83_LEN = 64;
// proc/reg00014.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD3_RW = 0x00001403ull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD3_FSI_SCRATCH_PAD3 = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD3_FSI_SCRATCH_PAD3_LEN = 32;
// proc/reg00014.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_TRUE_MASK_RWX = 0x0000100dull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_TRUE_MASK_TRUE_MASK_REG = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_TRUE_MASK_TRUE_MASK_REG_LEN = 32;
// proc/reg00014.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_FSI = 0x00002803ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_FSI_BYTE = 0x0000280cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_SCOM = 0x00050003ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_ENVSTAT_CHANGE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_ENVSTAT_CHANGE_LEN = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_PGOOD_DROP_DURING_CBS = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_PGOOD_DROP_AFTER_CBS = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_CTRL_WRITE_DURING_CBS = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_INVALID_STATE = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_PGOOD_LOW_WHILE_UNFENCED = 24;
// proc/reg00014.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_8_RWX = 0x00002848ull;
// proc/reg00014.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_2_RWX = 0x00002882ull;
// proc/reg00014.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_4_RWX = 0x000028c4ull;
// proc/reg00014.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_12_RWX = 0x0000290cull;
// proc/reg00014.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_RW = 0x0000281bull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_PLL_BNDY_BYPASS_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_4_RESERVED = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_5_RESERVED = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_6_RESERVED = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_7_RESERVED = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_8_RESERVED = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_9_RESERVED = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_10_RESERVED = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_11_RESERVED = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_12_RESERVED = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_13_RESERVED = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_14_RESERVED = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_15_RESERVED = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_RESERVED = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_21_RESERVED = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_22_RESERVED = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_23_RESERVED = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_24_RESERVED = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CLK_PULSE_ENABLE_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CLK_PULSE_MODE_DC = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CLK_PULSE_MODE_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_28_RESERVED = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_29_RESERVED = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_30_RESERVED = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_TP_PCB_PM_MUX_SEL_DC = 31;
// proc/reg00015.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_RW = 0x00002811ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_HIGHDRIVE_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_22_SPARE_TEST = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_26_SPARE = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_GLBCK_MEM_TESTCLK_SEL_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL = 31;
// proc/reg00015.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR = 0x00002935ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_RESET_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BYPASS_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_BYPASS_CLKSEL_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_TEST_IN_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CONTROL_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CONTROL_DC_LEN = 28;
// proc/reg00015.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR = 0x00002938ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15 = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15_LEN = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31 = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31_LEN = 8;
// proc/reg00015.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_OUTPUT_RW = 0x000b0051ull;
static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_OUTPUT_WO_CLEAR = 0x000b0053ull;
static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_OUTPUT_WO_OR = 0x000b0052ull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_OUTPUT_0 = 0;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_OUTPUT_1 = 1;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_OUTPUT_2 = 2;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_ERROR_PTR_REGISTER_ROX = 0x00000c21ull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_ERROR_PTR_REGISTER_DMA_ERROR_PTR_REG = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_ERROR_PTR_REGISTER_DMA_ERROR_PTR_REG_LEN = 32;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_RESET_ERRORS_WOX_1P = 0x00000c07ull;
// proc/reg00015.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CRSIC = 0x00030005ull;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAEB_RO = 0x00003070ull;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP4_FSI0 = 0x00003060ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP4_SCOMFSI0 = 0x00000c18ull;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MREFP0_ROX = 0x00003020ull;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP5_RO = 0x000030e4ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP5_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP5_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP5_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP5_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP5_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP5_2_LEN = 3;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MESRB0_ROX = 0x000035d0ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MESRB0_FIRST_ERROR = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MESRB0_FIRST_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MESRB0_FAILING_OPB_MASTER_FRST = 17;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MESRB0_FAILING_OPB_MASTER_FRST_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MESRB0_ACTUAL_ERROR = 20;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MESRB0_ACTUAL_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MESRB0_FAILING_OPB_MASTER_ACT = 29;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MESRB0_FAILING_OPB_MASTER_ACT_LEN = 3;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP6_WOX = 0x000034e8ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP6_GENERAL_RESET_6 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP6_ERROR_RESET_6 = 1;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP5_FSI0 = 0x00003444ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP5_SCOMFSI0 = 0x00000d11ull;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAEB_RO = 0x00003070ull;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP0_WOX = 0x000030d0ull;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP3_FSI1 = 0x0000303cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP3_SCOMFSI1 = 0x00000c0full;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCRSIM4 = 0x0000085cull;
// proc/reg00015.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SISM = 0x0000080cull;
// proc/reg00015.H

static const uint64_t VAS_VA_RG_SCF_BUFCTL = 0x0201140cull;

static const uint32_t VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT = 49;
static const uint32_t VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT_LEN = 7;
static const uint32_t VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT = 57;
static const uint32_t VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT_LEN = 7;
// proc/reg00015.H

}
}
#include "proc/reg00012.H"
#include "proc/reg00013.H"
#include "proc/reg00014.H"
#include "proc/reg00015.H"
#endif
