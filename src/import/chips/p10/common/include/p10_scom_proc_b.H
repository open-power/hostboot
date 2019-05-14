/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_b.H $       */
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

#ifndef __p10_scom_proc_b_H_
#define __p10_scom_proc_b_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_IC_BAR = 0x02010808ull;

static const uint32_t INT_CQ_IC_BAR_VALID = 0;
static const uint32_t INT_CQ_IC_BAR_PAGE_SIZE_64K = 1;
static const uint32_t INT_CQ_IC_BAR_ADDR_8_42 = 8;
static const uint32_t INT_CQ_IC_BAR_ADDR_8_42_LEN = 35;
// proc/reg00047.H

static const uint64_t INT_CQ_PMC_4 = 0x0201082cull;

static const uint32_t INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47 = 16;
static const uint32_t INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47_LEN = 48;
// proc/reg00047.H

static const uint64_t INT_PC_NXC_REGS_RECOV_ERR = 0x02010ad5ull;

static const uint32_t INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR = 0;
static const uint32_t INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR_LEN = 64;
// proc/reg00047.H

static const uint64_t INT_PC_NXC_REGS_WATCH2_DATA0 = 0x02010ab4ull;
// proc/reg00047.H

static const uint64_t INT_PC_NXC_REGS_WOF_ERR = 0x02010ad2ull;

static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_0 = 0;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR = 1;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR = 2;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR = 3;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR = 4;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR = 5;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE = 6;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE = 7;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9 = 8;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR = 10;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR = 11;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13 = 12;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE = 14;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_15 = 15;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_16 = 16;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR = 17;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19 = 18;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR = 20;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR = 21;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_22 = 22;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH = 23;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE = 24;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE = 25;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR = 26;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P1_OS_NVP_PRIO_ERROR = 27;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR = 28;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE = 29;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR = 30;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR = 31;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW = 32;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW = 33;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE = 34;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE = 35;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR = 36;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52 = 37;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52_LEN = 16;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR = 53;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR = 54;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR = 55;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR = 56;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR = 57;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR = 58;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60 = 59;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR = 61;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE = 62;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE = 63;
// proc/reg00047.H

static const uint64_t INT_PC_REGS_AT_KILL = 0x02010a02ull;

static const uint32_t INT_PC_REGS_AT_KILL_VALID = 0;
static const uint32_t INT_PC_REGS_AT_KILL_VSD_TYPE = 24;
static const uint32_t INT_PC_REGS_AT_KILL_VSD_TYPE_LEN = 4;
static const uint32_t INT_PC_REGS_AT_KILL_BLOCKID = 28;
static const uint32_t INT_PC_REGS_AT_KILL_BLOCKID_LEN = 4;
static const uint32_t INT_PC_REGS_AT_KILL_OFFSET = 48;
static const uint32_t INT_PC_REGS_AT_KILL_OFFSET_LEN = 13;
static const uint32_t INT_PC_REGS_AT_KILL_RESERVED_61_63 = 61;
static const uint32_t INT_PC_REGS_AT_KILL_RESERVED_61_63_LEN = 3;
// proc/reg00047.H

static const uint64_t INT_PC_REGS_AT_KILL_MASK = 0x02010a03ull;

static const uint32_t INT_PC_REGS_AT_KILL_MASK_VSD_TYPE = 24;
static const uint32_t INT_PC_REGS_AT_KILL_MASK_VSD_TYPE_LEN = 4;
static const uint32_t INT_PC_REGS_AT_KILL_MASK_BLOCKID = 28;
static const uint32_t INT_PC_REGS_AT_KILL_MASK_BLOCKID_LEN = 4;
static const uint32_t INT_PC_REGS_AT_KILL_MASK_OFFSET = 48;
static const uint32_t INT_PC_REGS_AT_KILL_MASK_OFFSET_LEN = 13;
static const uint32_t INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63 = 61;
static const uint32_t INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63_LEN = 3;
// proc/reg00047.H

static const uint64_t INT_PC_REGS_DBG_ECC = 0x02010a31ull;

static const uint32_t INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR = 0;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR = 1;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR_LEN = 2;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR = 3;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR = 4;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR = 5;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR = 6;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR = 7;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR = 8;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR = 9;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR = 10;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR = 11;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR = 12;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR = 13;
static const uint32_t INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR = 14;
static const uint32_t INT_PC_REGS_DBG_ECC_RESERVED_15 = 15;
static const uint32_t INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR = 16;
static const uint32_t INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR = 17;
static const uint32_t INT_PC_REGS_DBG_ECC_RESERVED_18_19 = 18;
static const uint32_t INT_PC_REGS_DBG_ECC_RESERVED_18_19_LEN = 2;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM = 20;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM = 21;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM = 22;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM = 23;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA = 24;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA_LEN = 2;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA = 26;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA_LEN = 2;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM = 28;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA = 29;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB = 30;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB_LEN = 2;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM = 32;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA = 33;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA_LEN = 2;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM = 35;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA = 36;
static const uint32_t INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA_LEN = 2;
static const uint32_t INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE = 38;
static const uint32_t INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE = 39;
// proc/reg00047.H

static const uint64_t INT_PC_REGS_DBG_TMOT = 0x02010a30ull;

static const uint32_t INT_PC_REGS_DBG_TMOT_RESERVED_0_1 = 0;
static const uint32_t INT_PC_REGS_DBG_TMOT_RESERVED_0_1_LEN = 2;
static const uint32_t INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT = 2;
static const uint32_t INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT_LEN = 6;
static const uint32_t INT_PC_REGS_DBG_TMOT_RESERVED_8_9 = 8;
static const uint32_t INT_PC_REGS_DBG_TMOT_RESERVED_8_9_LEN = 2;
static const uint32_t INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT = 10;
static const uint32_t INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT_LEN = 6;
// proc/reg00047.H

static const uint64_t INT_PC_REGS_TCTXT_LSI_SET_00 = 0x02010b24ull;
// proc/reg00047.H

static const uint64_t INT_VC_AIB_TX_CMD_PRIORITY = 0x02010915ull;

static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43 = 32;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43_LEN = 12;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS = 44;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS_LEN = 2;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ = 46;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ_LEN = 2;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS = 48;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS_LEN = 2;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE = 50;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE_LEN = 2;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP = 52;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP_LEN = 2;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA = 54;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA_LEN = 2;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE = 56;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE_LEN = 2;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP = 58;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP_LEN = 2;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD = 60;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD_LEN = 2;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA = 62;
static const uint32_t INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA_LEN = 2;
// proc/reg00047.H

static const uint64_t INT_VC_ENDC_CFG_CMD_LIMIT = 0x02010989ull;

static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1 = 0;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1_LEN = 2;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE = 2;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE_LEN = 6;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS = 8;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS_LEN = 2;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS = 10;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS_LEN = 6;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL = 16;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL_LEN = 2;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL = 18;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL_LEN = 6;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD = 24;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD_LEN = 2;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD = 26;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD_LEN = 6;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33 = 32;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33_LEN = 2;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST = 34;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST_LEN = 6;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST = 40;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST_LEN = 6;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD = 46;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD_LEN = 6;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ = 52;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ_LEN = 6;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE = 58;
static const uint32_t INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE_LEN = 6;
// proc/reg00047.H

static const uint64_t INT_VC_ENDC_FLUSH_POLL = 0x02010981ull;

static const uint32_t INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3 = 0;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3_LEN = 4;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_BLOCKID = 4;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_BLOCKID_LEN = 4;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_OFFSET = 8;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_OFFSET_LEN = 24;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35 = 32;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35_LEN = 4;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK = 36;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK_LEN = 4;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK = 40;
static const uint32_t INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK_LEN = 24;
// proc/reg00047.H

static const uint64_t INT_VC_ENDC_PERF_EVENT_SEL_4 = 0x0201099bull;

static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND = 0;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD = 8;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00 = 12;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00 = 16;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC = 20;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY = 24;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY = 28;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY = 32;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY = 36;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY = 40;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY = 44;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY = 48;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY = 52;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY = 56;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE = 60;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE_LEN = 4;
// proc/reg00047.H

static const uint64_t INT_VC_ENDC_WATCH1_DATA2 = 0x020109aeull;
// proc/reg00047.H

static const uint64_t INT_VC_ESB_BLOCK_MODE = 0x02010908ull;

static const uint32_t INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE = 0;
static const uint32_t INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE_LEN = 32;
// proc/reg00047.H

static const uint64_t INT_VC_NVPG_BLOCK_MODE = 0x0201090cull;

static const uint32_t INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE = 0;
static const uint32_t INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE_LEN = 32;
// proc/reg00047.H

static const uint64_t INT_VC_QUEUES_CFG_REM_3 = 0x0201091aull;

static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE = 0;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE = 1;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE_LEN = 6;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10 = 8;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10_LEN = 3;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ = 11;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ_LEN = 5;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18 = 16;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18_LEN = 3;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC = 19;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC_LEN = 5;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM = 24;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM = 28;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33 = 32;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_FULL = 34;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE = 35;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37 = 36;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING = 38;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE = 39;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41 = 40;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE = 42;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE_LEN = 6;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49 = 48;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_ERQ_FULL = 50;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE = 51;
static const uint32_t INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND = 52;
// proc/reg00047.H

static const uint64_t INT_VC_QUEUES_PERF_EVENT_SEL_0 = 0x02010926ull;

static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB = 0;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS = 8;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS = 12;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA = 16;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ = 20;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX = 24;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC = 28;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC_LEN = 4;
// proc/reg00047.H

static const uint64_t MCD_BANK0_STR = 0x0301080bull;

static const uint32_t MCD_BANK0_STR_VALID = 0;
static const uint32_t MCD_BANK0_STR_CPG = 1;
static const uint32_t MCD_BANK0_STR_GRP_MBR_ID = 2;
static const uint32_t MCD_BANK0_STR_ALWAYS_RTY = 3;
static const uint32_t MCD_BANK0_STR_SMF_ENABLE = 6;
static const uint32_t MCD_BANK0_STR_GRP_SIZE = 11;
static const uint32_t MCD_BANK0_STR_GRP_SIZE_LEN = 19;
static const uint32_t MCD_BANK0_STR_GRP_BASE = 33;
static const uint32_t MCD_BANK0_STR_GRP_BASE_LEN = 31;
// proc/reg00047.H

static const uint64_t NX_CH4_ADDR_8_HASH_FUNCTION_REG = 0x02011149ull;

static const uint32_t NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION_LEN = 64;
// proc/reg00047.H

static const uint64_t NX_DBG_TRIGGER_CTRL = 0x0201110bull;

static const uint32_t NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS = 50;
static const uint32_t NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS_LEN = 12;
// proc/reg00047.H

static const uint64_t NX_DMA_GZIP_MAX_BYTE_CNT = 0x0201105bull;

static const uint32_t NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW = 0;
static const uint32_t NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW_LEN = 5;
static const uint32_t NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH = 5;
static const uint32_t NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH_LEN = 5;
static const uint32_t NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD = 10;
static const uint32_t NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT = 11;
static const uint32_t NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT_LEN = 8;
static const uint32_t NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT = 19;
static const uint32_t NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT_LEN = 8;
// proc/reg00047.H

static const uint64_t NX_DMA_SYM_MAX_BYTE_CNT = 0x0201105aull;

static const uint32_t NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT = 0;
static const uint32_t NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT_LEN = 5;
static const uint32_t NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT = 5;
static const uint32_t NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT_LEN = 8;
static const uint32_t NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT = 13;
static const uint32_t NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT_LEN = 8;
static const uint32_t NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT = 21;
static const uint32_t NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT_LEN = 5;
// proc/reg00047.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG = 0x020110b0ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07 = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07_LEN = 32;
// proc/reg00047.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG = 0x020110b1ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15 = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15_LEN = 32;
// proc/reg00047.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG = 0x020110b2ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23 = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23_LEN = 32;
// proc/reg00047.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG = 0x020110b3ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31 = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31_LEN = 32;
// proc/reg00047.H

static const uint64_t NX_PBI_RNG_CFG = 0x020110e0ull;

static const uint32_t NX_PBI_RNG_CFG_FAIL_REG = 0;
static const uint32_t NX_PBI_RNG_CFG_FAIL_REG_LEN = 10;
static const uint32_t NX_PBI_RNG_CFG_RNG0_FAIL = 10;
static const uint32_t NX_PBI_RNG_CFG_RNG1_FAIL = 11;
static const uint32_t NX_PBI_RNG_CFG_INTERRUPT_SENT = 12;
static const uint32_t NX_PBI_RNG_CFG_BIST_ENABLE = 16;
static const uint32_t NX_PBI_RNG_CFG_BIST_COMPLETE = 17;
static const uint32_t NX_PBI_RNG_CFG_RNG0_BIST_FAIL = 18;
static const uint32_t NX_PBI_RNG_CFG_RNG1_BIST_FAIL = 19;
static const uint32_t NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH = 20;
static const uint32_t NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH_LEN = 3;
static const uint32_t NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR = 23;
static const uint32_t NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR = 24;
static const uint32_t NX_PBI_RNG_CFG_ST2_RESET_PERIOD = 30;
static const uint32_t NX_PBI_RNG_CFG_ST2_RESET_PERIOD_LEN = 8;
static const uint32_t NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE = 38;
static const uint32_t NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE = 39;
static const uint32_t NX_PBI_RNG_CFG_SAMPTEST_ENABLE = 40;
static const uint32_t NX_PBI_RNG_CFG_REPTEST_ENABLE = 41;
static const uint32_t NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE = 42;
static const uint32_t NX_PBI_RNG_CFG_ADAPTEST_ENABLE = 43;
static const uint32_t NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL = 44;
static const uint32_t NX_PBI_RNG_CFG_PACE_RATE = 46;
static const uint32_t NX_PBI_RNG_CFG_PACE_RATE_LEN = 16;
static const uint32_t NX_PBI_RNG_CFG_RNG_ENABLE = 63;
// proc/reg00047.H

static const uint64_t NX_PBI_RNG_ST2 = 0x020110e3ull;

static const uint32_t NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0 = 0;
static const uint32_t NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0_LEN = 8;
static const uint32_t NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1 = 8;
static const uint32_t NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1_LEN = 8;
static const uint32_t NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0 = 16;
static const uint32_t NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0_LEN = 8;
static const uint32_t NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1 = 24;
static const uint32_t NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1_LEN = 8;
static const uint32_t NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0 = 32;
static const uint32_t NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0_LEN = 6;
static const uint32_t NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1 = 38;
static const uint32_t NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1_LEN = 6;
// proc/reg00047.H

static const uint64_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB = 0x020110c6ull;

static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID = 4;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN = 12;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID = 20;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID_LEN = 20;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID = 44;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID_LEN = 16;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE = 63;
// proc/reg00047.H

static const uint64_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL = 0x020110c3ull;

static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET = 4;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN = 8;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED = 15;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN = 9;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX = 27;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX_LEN = 9;
// proc/reg00047.H

static const uint64_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR = 0x020110c9ull;

static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR = 8;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_LEN = 46;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE = 54;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN = 3;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM10_EN_DOB_ECC_ERR_REG = 0x10011818ull;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM10_MAILBOX_DATA_REG = 0x1001182full;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM10_PMU2_CNPM_COUNTER = 0x10011823ull;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM10_PTL_FIR_REG_RW = 0x10011800ull;
static const uint64_t PB_PTLSCOM10_PTL_FIR_REG_WO_AND = 0x10011801ull;
static const uint64_t PB_PTLSCOM10_PTL_FIR_REG_WO_OR = 0x10011802ull;

static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED = 0;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED = 1;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED = 2;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED = 3;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE = 4;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE = 5;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE = 6;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR = 7;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE = 8;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE = 9;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE = 10;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR = 11;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN = 12;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN = 13;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN = 14;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN = 15;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN = 16;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN = 17;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN = 18;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN = 19;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN = 20;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN = 21;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN = 22;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN = 23;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN = 24;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN = 25;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR = 26;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR = 27;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN = 28;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN = 29;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN = 30;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN = 31;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN = 32;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN = 33;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN = 34;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN = 35;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE = 36;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE = 37;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE = 38;
static const uint32_t PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE = 39;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG = 0x10011811ull;

static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 = 0;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT = 1;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 = 8;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT = 9;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT = 16;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT = 24;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT = 32;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT_LEN = 5;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT = 37;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2 = 38;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2_LEN = 2;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM23_MAILBOX_30_REG = 0x11011836ull;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM23_MAILBOX_31_REG = 0x11011837ull;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM23_PMU0_CNPM_COUNTER = 0x11011821ull;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM23_PSAVE01_MISC_CFG = 0x11011815ull;

static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC = 0;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC = 8;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT = 16;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT = 21;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE = 26;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC = 28;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC = 36;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT = 44;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT = 49;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE = 54;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE = 56;
static const uint32_t PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE_LEN = 3;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG = 0x11011810ull;

static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 = 0;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT = 1;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 = 8;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT = 9;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT = 16;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT = 24;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT = 32;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT_LEN = 5;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT = 37;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2 = 38;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2_LEN = 2;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG = 0x1201182cull;

static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0 = 0;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1 = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2 = 14;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3 = 21;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4 = 28;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5 = 35;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6 = 42;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7 = 49;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8 = 56;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS = 63;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG = 0x1201182dull;

static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9 = 0;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10 = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11 = 14;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12 = 21;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13 = 28;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14 = 35;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14_LEN = 7;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15 = 42;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15_LEN = 7;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM45_PERFTRACE_CFG_REG = 0x1201182bull;

static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE = 0;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE = 1;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE = 2;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6 = 3;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE = 4;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE = 5;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE = 6;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7 = 7;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT = 8;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT_LEN = 2;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT = 10;
static const uint32_t PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT_LEN = 2;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG = 0x12011819ull;

static const uint32_t PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET = 0;
static const uint32_t PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET = 2;
static const uint32_t PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT = 4;
static const uint32_t PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN = 2;
static const uint32_t PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT = 6;
static const uint32_t PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN = 2;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM67_CFG_TLPM_REG = 0x1301181aull;

static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_EN = 0;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE = 1;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS = 3;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE = 4;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE = 5;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP = 6;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP = 8;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP = 10;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP = 12;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP = 14;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP = 16;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP = 18;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP = 20;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP = 22;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP = 24;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP = 26;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP = 28;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP = 30;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP = 32;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP = 34;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP = 36;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0 = 38;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0_LEN = 3;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1 = 41;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1_LEN = 3;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2 = 44;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2_LEN = 3;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3 = 47;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3_LEN = 3;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_SPARE = 50;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_REG_SPARE_LEN = 6;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM67_MAILBOX_10_REG = 0x13011832ull;
// proc/reg00047.H

static const uint64_t PB_PTLSCOM67_MAILBOX_11_REG = 0x13011833ull;
// proc/reg00047.H

static const uint64_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT = 0x03011c87ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT_TTYPEFILT_PAT = 1;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT_TTYPEFILT_PAT_LEN = 7;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT_TSIZEFILT_PAT = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT_TSIZEFILT_PAT_LEN = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT_TTYPEFILT_MASK = 17;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT_TTYPEFILT_MASK_LEN = 7;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT_TSIZEFILT_MASK = 24;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT_TSIZEFILT_MASK_LEN = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT = 32;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TTYPEFILT_CRESPFILT_INVERT = 33;
// proc/reg00048.H

static const uint64_t PSI_MAC_SCOM_FIR_REG_RW = 0x03012c00ull;
static const uint64_t PSI_MAC_SCOM_FIR_REG_WO_AND = 0x03012c01ull;
static const uint64_t PSI_MAC_SCOM_FIR_REG_WO_OR = 0x03012c02ull;

static const uint32_t PSI_MAC_SCOM_FIR_REG_PSI_FIR_RESERVED0 = 0;
static const uint32_t PSI_MAC_SCOM_FIR_REG_PSI_FIR_RESERVED1 = 1;
static const uint32_t PSI_MAC_SCOM_FIR_REG_PSI_FIR_RESERVED2 = 2;
static const uint32_t PSI_MAC_SCOM_FIR_REG_PSI_FIR_RESERVED3 = 3;
static const uint32_t PSI_MAC_SCOM_FIR_REG_PSI_FIR_RESERVED4 = 4;
static const uint32_t PSI_MAC_SCOM_FIR_REG_INTERNAL_SCOM_ERROR = 5;
static const uint32_t PSI_MAC_SCOM_FIR_REG_INTERNAL_SCOM_ERROR_CLONE = 6;
// proc/reg00048.H

static const uint64_t PSI_MAC_SCOM_REGS_RX_MODE = 0x03012c21ull;

static const uint32_t PSI_MAC_SCOM_REGS_RX_MODE_VREF = 0;
static const uint32_t PSI_MAC_SCOM_REGS_RX_MODE_VREF_LEN = 8;
static const uint32_t PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE = 12;
static const uint32_t PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC = 15;
static const uint32_t PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC_LEN = 5;
static const uint32_t PSI_MAC_SCOM_REGS_RX_MODE_PEAK = 20;
static const uint32_t PSI_MAC_SCOM_REGS_RX_MODE_PEAK_LEN = 3;
static const uint32_t PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE = 24;
static const uint32_t PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE_LEN = 8;
// proc/reg00048.H

static const uint64_t PSI_MAC_SCOM_REGS_RX_STATUS = 0x03012c22ull;

static const uint32_t PSI_MAC_SCOM_REGS_RX_STATUS_LD_UNLD_DLY = 4;
static const uint32_t PSI_MAC_SCOM_REGS_RX_STATUS_LD_UNLD_DLY_LEN = 4;
static const uint32_t PSI_MAC_SCOM_REGS_RX_STATUS_OVER_OR_UNDERRUN_ERR = 8;
static const uint32_t PSI_MAC_SCOM_REGS_RX_STATUS_STATUS_CLEAR = 9;
static const uint32_t PSI_MAC_SCOM_REGS_RX_STATUS_STATUS_SPARE = 10;
static const uint32_t PSI_MAC_SCOM_REGS_RX_STATUS_STATUS_SPARE_LEN = 6;
// proc/reg00048.H

static const uint64_t TP_TCN0_N0_CPLT_CTRL4_RW = 0x02000004ull;
static const uint64_t TP_TCN0_N0_CPLT_CTRL4_WO_CLEAR = 0x02000024ull;
static const uint64_t TP_TCN0_N0_CPLT_CTRL4_WO_OR = 0x02000014ull;

static const uint32_t TP_TCN0_N0_CPLT_CTRL4_0_FLUSHMODE_INH = 4;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_1_FLUSHMODE_INH = 5;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_2_FLUSHMODE_INH = 6;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_3_FLUSHMODE_INH = 7;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_4_FLUSHMODE_INH = 8;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_5_FLUSHMODE_INH = 9;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_6_FLUSHMODE_INH = 10;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_7_FLUSHMODE_INH = 11;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_8_FLUSHMODE_INH = 12;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_9_FLUSHMODE_INH = 13;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_10_FLUSHMODE_INH = 14;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_11_FLUSHMODE_INH = 15;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_12_FLUSHMODE_INH = 16;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_13_FLUSHMODE_INH = 17;
static const uint32_t TP_TCN0_N0_CPLT_CTRL4_14_FLUSHMODE_INH = 18;
// proc/reg00048.H

static const uint64_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG = 0x02010441ull;

static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCN0_N0_TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// proc/reg00048.H

static const uint64_t TP_TCN0_N0_TRA1_TR0_CONFIG_0 = 0x02010483ull;

static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4 = 0x03040084ull;

static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_ANY_XSTOP_ERR = 0;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_ANY_RECOV_ERR = 1;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_ANY_SPATTN_ERR = 2;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_ANY_LXSTOP_ERR = 3;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_ANY_HOSTATTN_ERR = 4;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SYSTEM_XSTOP = 5;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_OOB1 = 6;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_EPS_PSC_WRITE_PROTECT_ENABLE_REG = 0x03010005ull;

static const uint32_t TP_TCN1_N1_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t TP_TCN1_N1_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_EPS_THERM_WSUB_INJECT_REG = 0x03050011ull;

static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_INJECT_REG_TRIP = 0;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_INJECT_REG_TRIP_LEN = 2;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_INJECT_REG_MODE = 2;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_INJECT_REG_MODE_LEN = 2;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_HOSTATTN_MASK_RW = 0x03040044ull;
static const uint64_t TP_TCN1_N1_HOSTATTN_MASK_WO_CLEAR = 0x03040064ull;
static const uint64_t TP_TCN1_N1_HOSTATTN_MASK_WO_OR = 0x03040054ull;

static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_01 = 1;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_02 = 2;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_03 = 3;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_04 = 4;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_05 = 5;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_06 = 6;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_07 = 7;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_08 = 8;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_09 = 9;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_10 = 10;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_11 = 11;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_12 = 12;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_13 = 13;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_14 = 14;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_15 = 15;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_16 = 16;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_17 = 17;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_18 = 18;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_19 = 19;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_20 = 20;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_21 = 21;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_22 = 22;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_23 = 23;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_24 = 24;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_25 = 25;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_26 = 26;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_27 = 27;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_28 = 28;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_29 = 29;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_30 = 30;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_31 = 31;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_32 = 32;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_33 = 33;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_34 = 34;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_35 = 35;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_36 = 36;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_37 = 37;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_38 = 38;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_39 = 39;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_40 = 40;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_41 = 41;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_42 = 42;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_43 = 43;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_44 = 44;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_45 = 45;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_46 = 46;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_47 = 47;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_48 = 48;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_49 = 49;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_50 = 50;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_51 = 51;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_52 = 52;
static const uint32_t TP_TCN1_N1_HOSTATTN_MASK_53 = 53;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_PCB_OPCG_GO = 0x03030020ull;

static const uint32_t TP_TCN1_N1_PCB_OPCG_GO_PCB_OPCGGO = 0;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG = 0x03010481ull;

static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCN1_N1_TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_TRA1_TR1_CONFIG_1 = 0x030104c4ull;

static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_TRA2_TR1_TRACE_HI_DATA_REG = 0x03010540ull;

static const uint32_t TP_TCN1_N1_TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_TRA3_TR0_CONFIG_0 = 0x03010583ull;

static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_TRA3_TR1_CONFIG_9 = 0x030105c9ull;

static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_TRA4_TR0_CONFIG_1 = 0x03010604ull;

static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_TRA6_TR0_CONFIG_9 = 0x03010709ull;

static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00048.H

static const uint64_t TP_TCN1_N1_TRA6_TR1_CONFIG_0 = 0x03010743ull;

static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPBR_AD_ALTD_ADDR_REG = 0x00090000ull;

static const uint32_t TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS = 8;
static const uint32_t TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS_LEN = 56;
static const uint32_t TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS = 8;
static const uint32_t TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS_LEN = 56;
// proc/reg00048.H

static const uint64_t TP_TPBR_AD_PIB_DATA_REG = 0x00090032ull;

static const uint32_t TP_TPBR_AD_PIB_DATA_REG_PIB_DATA = 0;
static const uint32_t TP_TPBR_AD_PIB_DATA_REG_PIB_DATA_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPBR_AD_PIB_RESET_REG = 0x00090033ull;

static const uint32_t TP_TPBR_AD_PIB_RESET_REG_PIB_RESET = 0;
static const uint32_t TP_TPBR_AD_PIB_RESET_REG_PIB_RESET_STATE = 1;
static const uint32_t TP_TPBR_AD_PIB_RESET_REG_PIB_RESET_ABORTED_CMD = 2;
// proc/reg00048.H

static const uint64_t TP_TPBR_AD_XSCOM_BASE_REG = 0x00090010ull;

static const uint32_t TP_TPBR_AD_XSCOM_BASE_REG_BASE = 8;
static const uint32_t TP_TPBR_AD_XSCOM_BASE_REG_BASE_LEN = 22;
static const uint32_t TP_TPBR_AD_XSCOM_BASE_REG_RESET = 61;
static const uint32_t TP_TPBR_AD_XSCOM_BASE_REG_DISABLE = 62;
static const uint32_t TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT = 63;
// proc/reg00048.H

static const uint64_t TP_TPBR_AD_XSCOM_DAT0_REG = 0x0009001eull;

static const uint32_t TP_TPBR_AD_XSCOM_DAT0_REG_XSCOM_DAT0 = 0;
static const uint32_t TP_TPBR_AD_XSCOM_DAT0_REG_XSCOM_DAT0_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPBR_AD_XSCOM_DAT1_REG = 0x0009001full;

static const uint32_t TP_TPBR_AD_XSCOM_DAT1_REG_XSCOM_DAT1 = 0;
static const uint32_t TP_TPBR_AD_XSCOM_DAT1_REG_XSCOM_DAT1_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAERRRPT2 = 0x03011dceull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_BAR_PARITY_ERR = 0;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_SCOMTB_ERR = 1;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_SPARE = 2;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_SPARE_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_PBDOUT_PARITY_ERR = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_PB_PARITY_ERR = 5;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_PB_PARITY_ERR_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_AXFLOW_ERR = 8;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_AXFLOW_ERR_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_AXIFLOW_ERR = 10;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT2_AXIFLOW_ERR_LEN = 2;
// proc/reg00048.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAPBOCR2 = 0x03011dd2ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR2_EVENT = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR2_EVENT_LEN = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR2_ACCUM = 44;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR2_ACCUM_LEN = 20;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_BCUE_CTL_OCI = 0xc00400a8ull;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_CTL_PIB = 0x00068015ull;

static const uint32_t TP_TPBR_PBA_PBAO_BCUE_CTL_OP = 0;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_CTL_ART = 1;
// proc/reg00048.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAFIRACT0 = 0x01010cc6ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0_LEN = 20;
// proc/reg00048.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAOCCACT = 0x01010ccaull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAOCCACT_PBAOCCACT_OCC_ACTION_SET = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCCACT_PBAOCCACT_OCC_ACTION_SET_LEN = 20;
// proc/reg00048.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAPBTXT0 = 0x01010ce2ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0__VALID = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0__VALID_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_0 = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_0_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_1 = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_1_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_2 = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_2_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_3 = 20;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_3_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_4 = 24;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_4_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_5 = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_5_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_6 = 32;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_6_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_7 = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT0_7_LEN = 4;
// proc/reg00048.H

static const uint64_t TP_TPBR_PSI_WRAP_TX_CH_FSM_REG = 0x03011c05ull;
// proc/reg00048.H

static const uint64_t TP_TPBR_PSIHB_DMA_UP_ADDR = 0x03011d14ull;

static const uint32_t TP_TPBR_PSIHB_DMA_UP_ADDR_BASE_UPPER_BITS = 0;
static const uint32_t TP_TPBR_PSIHB_DMA_UP_ADDR_BASE_UPPER_BITS_LEN = 8;
static const uint32_t TP_TPBR_PSIHB_DMA_UP_ADDR_ESCAPE_ADDRESS = 16;
static const uint32_t TP_TPBR_PSIHB_DMA_UP_ADDR_ESCAPE_ADDRESS_LEN = 48;
// proc/reg00048.H

static const uint64_t TP_TPBR_PSIHB_INTERRUPT_LEVEL = 0x03011d19ull;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_PROTECT_MODE_REG = 0x020f03feull;

static const uint32_t TP_TPCHIP_NET_PCBSLN0_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_ATOMIC_LOCK_REG = 0x030f03ffull;

static const uint32_t TP_TPCHIP_NET_PCBSLN1_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_3 = 0x030f0003ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_3_MULTICAST3_GROUP = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN = 3;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_RECOV_INTERRUPT_REG = 0x030f001bull;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG = 0x030f001eull;

static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN = 1;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP = 2;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT = 4;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO = 5;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_PM_DISABLE = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_PM_MUX_DISABLE = 7;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS = 8;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS = 9;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS = 10;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS = 11;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_MASK_PLL_ERRS = 12;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN = 8;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_QME_PAR_DIS = 20;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_SLAVE_CONFIG_REG_FORCE_0_QME = 21;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_XSTOP_INTERRUPT_REG = 0x010f001cull;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR5_OCI = 0xc0000228ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR5_RO = 0x00060045ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN = 32;
// proc/reg00048.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR4_OCI = 0xc0000410ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR4_RO = 0x00060082ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR4_4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR4_4_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR4_5 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR4_5_LEN = 32;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_OCI = 0xc0010010ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_RW = 0x00062002ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_EN_DBG = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_HALT_ON_XSTOP = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_HALT_ON_TRIG = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_EN_COVERAGE_MODE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_EN_INTR_ADDR = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_EN_TRACE_EXTRA = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_EN_TRACE_STALL = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_EN_WAIT_CYCLES = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_EN_FULL_SPEED = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_DIS_FLOW_CHANGE = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_TRACE_MODE_SEL = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_TRACE_MODE_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_RESERVED12_15 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_RESERVED12_15_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_FIR_TRIGGER = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_SPARE = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_SPARE_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_TRACE_DATA_SEL = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEDBG_TRACE_DATA_SEL_LEN = 4;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR13_OCI = 0xc0010258ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR13_RO = 0x0006204bull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR13_OCB_OCI_GPEXIVDRX_GPR13 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR13_OCB_OCI_GPEXIVDRX_GPR13_LEN = 32;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICACL_OCI = 0xc0010168ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICACL_RO = 0x0006202dull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICACL_SIB_PIB_IFETCH_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICACL_MEM_IFETCH_PENDING = 3;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICACU_OCI = 0xc0010160ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICACU_RO = 0x0006202cull;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMDBG_OCI = 0xc0010098ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMDBG_SCOM = 0x00062013ull;
// proc/reg00048.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEOXIXCR_OCI = 0xc0020100ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEOXIXCR_WO = 0x00064020ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN = 3;
// proc/reg00048.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR10_OCI = 0xc0020250ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR10_RO = 0x0006404aull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR10_OCB_OCI_GPEXIVDRX_GPR10 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR10_OCB_OCI_GPEXIVDRX_GPR10_LEN = 32;
// proc/reg00048.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIICAC_OCI = 0xc00200c8ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIICAC_RO = 0x00064019ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIICAC_MEM_IFETCH_PENDING = 35;
// proc/reg00049.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR_OCI = 0xc0020080ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR_SCOM = 0x00064010ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR_OXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR_OXIXCR_XCR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR_XICTR_CTR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR_XICTR_CTR_LEN = 32;
// proc/reg00049.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR0_OCI = 0xc0030028ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR0_RW = 0x00066005ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR0_BAR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR0_BAR_LEN = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR0_SIZE = 44;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR0_SIZE_LEN = 15;
// proc/reg00049.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGPRO_OCI = 0xc00300a8ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGPRO_SCOM = 0x00066015ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN = 30;
// proc/reg00049.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR1_OCI = 0xc0030208ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR1_RO = 0x00066041ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN = 32;
// proc/reg00049.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_OCI = 0xc0030148ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_SCOM = 0x00066029ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_BUSY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_BYTE_ENABLE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_BYTE_ENABLE_LEN = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_LINE_MODE = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_ERROR = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_ERROR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_IFETCH_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEML_DATAOP_PENDING = 31;
// proc/reg00049.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEMU_OCI = 0xc0030140ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEMU_RO = 0x00066028ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN = 32;
// proc/reg00049.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGB_OCI = 0xc00300c0ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGB_RO = 0x00066018ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING = 35;
// proc/reg00049.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISRR0_OCI = 0xc0030180ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISRR0_RO = 0x00066030ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN = 30;
// proc/reg00049.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR0_OCI = 0xc0030400ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR0_RO = 0x00066080ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR0_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR0_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR0_1 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR0_1_LEN = 32;
// proc/reg00049.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXSR_OCI = 0xc0030108ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXSR_RO = 0x00066021ull;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA0_OCI = 0xc0064100ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA0_RO = 0x0006c820ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA0_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA0_0_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA0_1 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA0_1_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA0_2 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA0_2_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA0_3 = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA0_3_LEN = 16;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_OCI = 0xc0063a10ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_RW = 0x0006c742ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_O2S_BRIDGE_ENABLE_2_A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_O2S_BRIDGE_ENABLE_2_B = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_RESERVED_2_3 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_RESERVED_2_3_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_O2S_CLOCK_DIVIDER_2 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_O2S_CLOCK_DIVIDER_2_LEN = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_O2SCTRL12_RESERVED_14_16 = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_O2SCTRL12_RESERVED_14_16_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_O2S_NR_OF_FRAMES_2 = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_RESERVED_18_19 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_RESERVED_18_19_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_SLAVE_DATA_SAMPLE_DELAY = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL12_SLAVE_DATA_SAMPLE_DELAY_LEN = 7;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SST2B_OCI = 0xc0063ab0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SST2B_RO = 0x0006c756ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2B__ONGOING_2B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2B_ST2B_RESERVED_1_4 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2B_ST2B_RESERVED_1_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2B__WRITE_WHILE_BRIDGE_BUSY_ERR_2B = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2B_ST2B_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2B__FSM_ERR_2B = 7;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR1_OCI = 0xc00610e0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR1_RW = 0x0006c21cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR1_REGION = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR1_REGION_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR1_BASE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR1_BASE_LEN = 7;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG0_OCI = 0xc0060560ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG0_OCI1 = 0xc0060568ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG0_OCI2 = 0xc0060570ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG0_RW = 0x0006c0acull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG0_WO_CLEAR = 0x0006c0adull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG0_WO_OR = 0x0006c0aeull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG0_OCB_OCI_OCCFLG0_OCC_FLAGS = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG0_OCB_OCI_OCCFLG0_OCC_FLAGS_LEN = 32;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_OCI = 0xc0060418ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_SCOM = 0x0006c083ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_HTM_SRC_SEL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_HTM_SRC_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_HTM_STOP = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_HTM_MARKER_SLAVE_ADRS = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_HTM_MARKER_SLAVE_ADRS_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_EVENT2HALT_MODE = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_EVENT2HALT_MODE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_EVENT2HALT_EN = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_EVENT2HALT_EN_LEN = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_HTM_GPE_SRC_SEL = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_HTM_GPE_SRC_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_EVENT2HALT_OCC = 23;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_EVENT2HALT_GPE0 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_EVENT2HALT_GPE1 = 25;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_EVENT2HALT_GPE2 = 26;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_EVENT2HALT_GPE3 = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OHTMCR_EVENT2HALT_HALT_STATE = 31;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0B_OCI = 0xc0060220ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0B_OCI1 = 0xc0060228ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0B_OCI2 = 0xc0060230ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0B_RW = 0x0006c044ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0B_WO_CLEAR = 0x0006c045ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0B_WO_OR = 0x0006c046ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR0B_OCB_OCI_OIRR0B_INTERRUPT_ROUTE_0_B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR0B_OCB_OCI_OIRR0B_INTERRUPT_ROUTE_0_B_LEN = 32;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q2RR_OCI = 0xc0062810ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q2RR_RO = 0x0006c502ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q2RR_OCB_OCI_OPIT0Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q2RR_OCB_OCI_OPIT0Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q7_OCI = 0xc0062038ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q7_RO = 0x0006c407ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q7_OCB_OCI_OPIT0Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q7_OCB_OCI_OPIT0Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q2RR_OCI = 0xc0062850ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q2RR_RO = 0x0006c50aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q2RR_OCB_OCI_OPIT1Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q2RR_OCB_OCI_OPIT1Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2RR_OCI = 0xc0062890ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2RR_RO = 0x0006c512ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2RR_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2RR_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q2RR_OCI = 0xc00628d0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q2RR_RO = 0x0006c51aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q2RR_OCB_OCI_OPIT3Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q2RR_OCB_OCI_OPIT3Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q3_OCI = 0xc00620d8ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q3_RO = 0x0006c41bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q3_OCB_OCI_OPIT3Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q3_OCB_OCI_OPIT3Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2RR_OCI = 0xc0062910ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2RR_RO = 0x0006c522ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2RR_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2RR_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q5_OCI = 0xc0062128ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q5_RO = 0x0006c425ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q5_OCB_OCI_OPIT4Q5RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q5_OCB_OCI_OPIT4Q5RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2RR_OCI = 0xc0062950ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2RR_RO = 0x0006c52aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2RR_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2RR_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q2RR_OCI = 0xc0062990ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q2RR_RO = 0x0006c532ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q2RR_OCB_OCI_OPIT6Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q2RR_OCB_OCI_OPIT6Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1_OCI = 0xc00621c8ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1_RO = 0x0006c439ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q2RR_OCI = 0xc00629d0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q2RR_RO = 0x0006c53aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q2RR_OCB_OCI_OPIT7Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q2RR_OCB_OCI_OPIT7Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12_OCI = 0xc0062260ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12_RO = 0x0006c44cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C12_PAYLOAD_LEN = 17;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C25_OCI = 0xc00622c8ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C25_RO = 0x0006c459ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C25_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C25_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C25_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C25_PAYLOAD_LEN = 17;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28RR_OCI = 0xc0062ae0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28RR_RO = 0x0006c55cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28RR_PAYLOAD_LEN = 17;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5RR_OCI = 0xc0062a28ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5RR_RO = 0x0006c545ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5RR_PAYLOAD_LEN = 17;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14_OCI = 0xc0062370ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14_RO = 0x0006c46eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14_PAYLOAD_LEN = 17;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23_OCI = 0xc00623b8ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23_RO = 0x0006c477ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23_PAYLOAD_LEN = 17;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5_OCI = 0xc0062328ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5_RO = 0x0006c465ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5_PAYLOAD_LEN = 17;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5RR_OCI = 0xc0062b28ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5RR_RO = 0x0006c565ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C5RR_PAYLOAD_LEN = 17;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_OCI = 0xc0062c08ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_RO = 0x0006c581ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV1RR_7_LEN = 4;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_OCI = 0xc0062418ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_RO = 0x0006c483ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7_LEN = 4;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_OCI = 0xc0062c38ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_RO = 0x0006c587ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3RR_7_LEN = 4;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_OCI = 0xc0062460ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_RO = 0x0006c48cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITDSV_7_LEN = 4;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OTR1_OCI = 0xc0060808ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OTR1_SCOM = 0x0006c101ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1_LEN = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1_LEN = 16;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO = 0x0006d000ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR = 0x0006d001ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR = 0x0006d002ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE_LEN = 5;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJFRST = 0x0006d007ull;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG103 = 0x00008067ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG103_REGISTER103 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG103_REGISTER103_LEN = 64;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG34 = 0x00008022ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG34_REGISTER34 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG34_REGISTER34_LEN = 64;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG55 = 0x00008037ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG55_REGISTER55 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG55_REGISTER55_LEN = 64;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG62 = 0x0000803eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG62_REGISTER62 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG62_REGISTER62_LEN = 64;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG8 = 0x00008008ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG8_REGISTER8 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG8_REGISTER8_LEN = 64;
// proc/reg00049.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG88 = 0x00008058ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG88_REGISTER88 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG88_REGISTER88_LEN = 64;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG97 = 0x00008061ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG97_REGISTER97 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG97_REGISTER97_LEN = 64;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR = 0x01000158ull;

static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA = 1;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA = 5;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA = 9;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT = 61;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT_LEN = 3;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1 = 0x010107c1ull;

static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1 = 0x010107c4ull;

static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0 = 0x010107cdull;

static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2 = 0x01040082ull;

static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_ANY_XSTOP_ERR = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_ANY_RECOV_ERR = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_ANY_SPATTN_ERR = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_ANY_LXSTOP_ERR = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_ANY_HOSTATTN_ERR = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYSTEM_XSTOP = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1 = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010 = 21;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011 = 22;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012 = 23;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013 = 24;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014 = 25;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015 = 26;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_TPC_OPCG_CAPT1 = 0x01030010ull;

static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_COUNT = 0;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t TP_TPCHIP_TPC_OPCG_CAPT1_SEQ_12_LEN = 5;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_TPC_OPCG_REG0 = 0x01030002ull;

static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_RUNN_MODE = 0;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_OPCG_GO = 1;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_RUN_SCAN0 = 2;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_SCAN0_MODE = 3;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_OPCG_IN_SLAVE_MODE = 4;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_OPCG_IN_MASTER_MODE = 5;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_KEEP_MS_MODE = 6;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL = 7;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL = 8;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR = 11;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR = 12;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_STOP_RUNN_ON_XSTOP = 13;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_OPCG_STARTS_BIST = 14;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_LOOP_COUNT = 21;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG0_LOOP_COUNT_LEN = 43;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_TPC_RECOV_MASK_RW = 0x01040041ull;
static const uint64_t TP_TPCHIP_TPC_RECOV_MASK_WO_CLEAR = 0x01040061ull;
static const uint64_t TP_TPCHIP_TPC_RECOV_MASK_WO_OR = 0x01040051ull;

static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_1 = 1;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_2 = 2;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_3 = 3;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_4 = 4;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_5 = 5;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_6 = 6;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_7 = 7;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_8 = 8;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_9 = 9;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_10 = 10;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_11 = 11;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_12 = 12;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_13 = 13;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_14 = 14;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_15 = 15;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_16 = 16;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_17 = 17;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_18 = 18;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_19 = 19;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_20 = 20;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_21 = 21;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_22 = 22;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_23 = 23;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_24 = 24;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_25 = 25;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_26 = 26;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_27 = 27;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_28 = 28;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_29 = 29;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_30 = 30;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_31 = 31;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_32 = 32;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_33 = 33;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_34 = 34;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_35 = 35;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_36 = 36;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_37 = 37;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_38 = 38;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_39 = 39;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_40 = 40;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_41 = 41;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_42 = 42;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_43 = 43;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_44 = 44;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_45 = 45;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_46 = 46;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_47 = 47;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_48 = 48;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_49 = 49;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_50 = 50;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_51 = 51;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_52 = 52;
static const uint32_t TP_TPCHIP_TPC_RECOV_MASK_53 = 53;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_1 = 0x01010404ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00050.H

static const uint64_t TP_TPCHIP_TPC_XSTOP_UNMASKED = 0x01040010ull;

static const uint32_t TP_TPCHIP_TPC_XSTOP_UNMASKED_XSTOP_UNMASKED_IN = 1;
static const uint32_t TP_TPCHIP_TPC_XSTOP_UNMASKED_XSTOP_UNMASKED_IN_LEN = 53;
// proc/reg00050.H

static const uint64_t TP_TPVSB_FSI_W_I2C_IMM_RESET_A = 0x00001807ull;
// proc/reg00050.H

static const uint64_t TP_TPVSB_FSI_W_I2C_IMM_RESET_S_SCL_A = 0x0000180bull;
// proc/reg00050.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_11_FSI = 0x0000284bull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_11_FSI_BYTE = 0x0000292cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_11_RW = 0x0005004bull;
// proc/reg00050.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_3_FSI = 0x00002843ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_3_FSI_BYTE = 0x0000290cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_3_RW = 0x00050043ull;
// proc/reg00050.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_9_FSI = 0x00002889ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_9_FSI_BYTE = 0x00002a24ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_9_RW = 0x00050089ull;
// proc/reg00050.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_15_FSI = 0x000028cfull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_15_FSI_BYTE = 0x00002b3cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_15_RW = 0x000500cfull;
// proc/reg00050.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_5_FSI = 0x00002905ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_5_FSI_BYTE = 0x00002c14ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_5_RW = 0x00050105ull;
// proc/reg00050.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI = 0x0000283eull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE = 0x000028f8ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW = 0x0005003eull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7 = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7_LEN = 32;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI = 0x00002411ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE = 0x00002444ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO = 0x000b0011ull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE = 6;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP = 7;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG = 8;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL = 10;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY = 11;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT = 12;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS = 16;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS = 24;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS_LEN = 8;
// proc/reg00050.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_RESET = 0x000b0024ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_RESET_FSI = 0x00000c06ull;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_RESET_FSI_BYTE = 0x00000c18ull;
// proc/reg00050.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_CRSIC = 0x00020005ull;
// proc/reg00050.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RSIC = 0x00020008ull;
// proc/reg00050.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_STAT_RDDAT_ERRES = 0x00020011ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_STAT_RDDAT_ERRES_CMD_PARITY_ERROR = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_STAT_RDDAT_ERRES_WR_DATA_PARITY_ERROR =
    2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_STAT_RDDAT_ERRES_RD_DATA_PARITY_ERROR =
    3;
static const uint32_t
TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_STAT_RDDAT_ERRES_LCK_STATUS_PARITY_ERROR = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_STAT_RDDAT_ERRES_FSM_PARITY_ERROR = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_STAT_RDDAT_ERRES_OPB_PARITY_ERROR = 8;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESB0_FSI0 = 0x000031d0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESB0_WO = 0x00000c74ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP7_FSI0 = 0x000030ecull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP7_WO = 0x00000c3bull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP7_GENERAL_RESET_7 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP7_ERROR_RESET_7 = 1;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSENP0_FSI0 = 0x00003018ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSENP0_WO_OR = 0x00000c06ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSENP0_0_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSENP0_1_ENABLE = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSENP0_2_ENABLE = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSENP0_3_ENABLE = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSENP0_4_ENABLE = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSENP0_5_ENABLE = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSENP0_6_ENABLE = 6;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSENP0_7_ENABLE = 7;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP4_FSI0 = 0x00003040ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP4_SCOMFSI0 = 0x00000c10ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP5_FSI0 = 0x00003464ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP5_SCOMFSI0 = 0x00000d19ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MREFP1_FSI0 = 0x00003424ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MREFP1_RO = 0x00000d09ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP4_FSI0 = 0x000034e0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP4_RO = 0x00000d38ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP4_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP4_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP4_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP4_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP4_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP4_2_LEN = 3;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SI1S = 0x0000081cull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SI2M = 0x00000824ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SSMBR = 0x00000848ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP3_FSI1 = 0x0000305cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP3_SCOMFSI1 = 0x00000c17ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MLEVP0_FSI1 = 0x00003018ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MLEVP0_RO = 0x00000c06ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP2_FSI1 = 0x000030d8ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP2_RO = 0x00000c36ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP2_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP2_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP2_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP2_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP2_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP2_2_LEN = 3;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SOMR = 0x00000848ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SRSIM4 = 0x00000874ull;
// proc/reg00050.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A0 = 0x000004a0ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A0_ACTUAL_ERROR = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A0_ACTUAL_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A0_PORT_0_ENABLE = 8;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A0_PORT_1_ENABLE = 12;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A0_PORT_2_ENABLE = 16;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A0_PORT_3_ENABLE = 20;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A0_PORT_4_ENABLE = 24;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A0_PORT_5_ENABLE = 28;
// proc/reg00050.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CLOCK_CONFIG = 0x00070023ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN = 64;
// proc/reg00050.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_SEQUENCER_OP_REG = 0x00070067ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_SEQUENCER_OP_REG_SEQUENCER_OP_Q = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN = 64;
// proc/reg00050.H

static const uint64_t VAS_VA_EG_SCF_EGERRRPT = 0x0201144aull;

static const uint32_t VAS_VA_EG_SCF_EGERRRPT_RESET = 0;
static const uint32_t VAS_VA_EG_SCF_EGERRRPT_BIT4 = 4;
static const uint32_t VAS_VA_EG_SCF_EGERRRPT_BIT5 = 5;
static const uint32_t VAS_VA_EG_SCF_EGERRRPT_BIT6 = 6;
static const uint32_t VAS_VA_EG_SCF_EGERRRPT_BIT7 = 7;
static const uint32_t VAS_VA_EG_SCF_EGERRRPT_BIT8 = 8;
static const uint32_t VAS_VA_EG_SCF_EGERRRPT_BIT9 = 9;
static const uint32_t VAS_VA_EG_SCF_EGERRRPT_BIT10 = 10;
static const uint32_t VAS_VA_EG_SCF_EGERRRPT_BIT11 = 11;
// proc/reg00050.H

static const uint64_t VAS_VA_EG_SCF_PGMIG5 = 0x02011445ull;
// proc/reg00050.H

static const uint64_t VAS_VA_RG_SCF_WRMON0WID = 0x02011418ull;
// proc/reg00050.H

static const uint64_t VAS_VA_RG_SCF_WRMON1CMP = 0x02011421ull;
// proc/reg00050.H

static const uint64_t VAS_VA_RG_SCF_WRMON5BAR = 0x02011415ull;
// proc/reg00050.H

}
}
#include "proc/reg00047.H"
#include "proc/reg00048.H"
#include "proc/reg00049.H"
#include "proc/reg00050.H"
#endif
