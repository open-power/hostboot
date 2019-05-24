/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_f.H $       */
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

#ifndef __p10_scom_proc_f_H_
#define __p10_scom_proc_f_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_AIB_CTL = 0x02010817ull;

static const uint32_t INT_CQ_AIB_CTL_DIS_ECCCHK_AIB_IN = 0;
static const uint32_t INT_CQ_AIB_CTL_RESERVED_1_25 = 1;
static const uint32_t INT_CQ_AIB_CTL_RESERVED_1_25_LEN = 25;
static const uint32_t INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5 = 26;
static const uint32_t INT_CQ_AIB_CTL_CH7_DAT_CREDITS_0_5_LEN = 6;
static const uint32_t INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5 = 32;
static const uint32_t INT_CQ_AIB_CTL_CH0_CMD_CREDITS_0_5_LEN = 6;
static const uint32_t INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5 = 38;
static const uint32_t INT_CQ_AIB_CTL_CH1_CMD_CREDITS_0_5_LEN = 6;
static const uint32_t INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5 = 44;
static const uint32_t INT_CQ_AIB_CTL_CH6_DAT_CREDITS_0_5_LEN = 6;
static const uint32_t INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5 = 50;
static const uint32_t INT_CQ_AIB_CTL_CH4_CMD_CREDITS_PC_0_5_LEN = 6;
static const uint32_t INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5 = 56;
static const uint32_t INT_CQ_AIB_CTL_CH4_CMD_CREDITS_VC_0_5_LEN = 6;
static const uint32_t INT_CQ_AIB_CTL_RESERVED_62 = 62;
static const uint32_t INT_CQ_AIB_CTL_REINIT_CREDITS = 63;
// proc/reg00071.H

static const uint64_t INT_CQ_CFG_STQ2 = 0x02010819ull;

static const uint32_t INT_CQ_CFG_STQ2_NXNC_MIN_0_2 = 0;
static const uint32_t INT_CQ_CFG_STQ2_NXNC_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ2_NXNC_MAX_0_4 = 3;
static const uint32_t INT_CQ_CFG_STQ2_NXNC_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ2_NXCI_MIN_0_2 = 8;
static const uint32_t INT_CQ_CFG_STQ2_NXCI_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ2_NXCI_MAX_0_4 = 11;
static const uint32_t INT_CQ_CFG_STQ2_NXCI_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ2_NXLS_MIN_0_2 = 16;
static const uint32_t INT_CQ_CFG_STQ2_NXLS_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ2_NXLS_MAX_0_4 = 19;
static const uint32_t INT_CQ_CFG_STQ2_NXLS_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ2_REG_MIN_0_2 = 24;
static const uint32_t INT_CQ_CFG_STQ2_REG_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ2_REG_MAX_0_4 = 27;
static const uint32_t INT_CQ_CFG_STQ2_REG_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ2_KILL_MIN_0_2 = 32;
static const uint32_t INT_CQ_CFG_STQ2_KILL_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ2_KILL_MAX_0_4 = 35;
static const uint32_t INT_CQ_CFG_STQ2_KILL_MAX_0_4_LEN = 5;
// proc/reg00071.H

static const uint64_t INT_CQ_SWI_CMD4 = 0x02010823ull;
// proc/reg00071.H

static const uint64_t INT_CQ_TAR = 0x0201080eull;

static const uint32_t INT_CQ_TAR_AUTO_INC = 0;
static const uint32_t INT_CQ_TAR_TABLE_SEL_0_3 = 12;
static const uint32_t INT_CQ_TAR_TABLE_SEL_0_3_LEN = 4;
static const uint32_t INT_CQ_TAR_ENTRY_SEL_0_3 = 28;
static const uint32_t INT_CQ_TAR_ENTRY_SEL_0_3_LEN = 4;
// proc/reg00071.H

static const uint64_t INT_CQ_TM_BAR = 0x02010809ull;

static const uint32_t INT_CQ_TM_BAR_VALID = 0;
static const uint32_t INT_CQ_TM_BAR_PAGE_SIZE_64K = 1;
static const uint32_t INT_CQ_TM_BAR_ADDR_8_49 = 8;
static const uint32_t INT_CQ_TM_BAR_ADDR_8_49_LEN = 42;
// proc/reg00071.H

static const uint64_t INT_PC_NXC_REGS_FATAL_ERR = 0x02010ad4ull;

static const uint32_t INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR = 0;
static const uint32_t INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR_LEN = 64;
// proc/reg00071.H

static const uint64_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2 = 0x02010a99ull;

static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB = 0;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_WB_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_NXC_FETCH_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT = 8;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_TCTXT_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC = 12;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_LCL_VC_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC = 16;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_PC_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC = 20;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_RMT_VC_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD = 24;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RSP_SW_LD_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP = 28;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STVP_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP = 32;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_1STGRP_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP = 36;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_VP_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP = 40;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_SCAN_GRP_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO = 44;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_PULL_CHKO_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST = 48;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_LCL_ST_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI = 52;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_PC_NCKI_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC = 56;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_ST_VC_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI = 60;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_2_RMT_CHKI_LEN = 4;
// proc/reg00071.H

static const uint64_t INT_PC_NXC_REGS_WATCH3_DATA0 = 0x02010abcull;
// proc/reg00071.H

static const uint64_t INT_PC_REGS_DBG_PMC_ATX0 = 0x02010a35ull;

static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_0 = 0;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_0_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_1 = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_1_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_2 = 8;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_2_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_3 = 12;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_3_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_15 = 16;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_15_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_4R = 20;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_4R_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_4W = 24;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_4W_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_5 = 28;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_5_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_6 = 32;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_6_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_7 = 36;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_7_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_8 = 40;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_8_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_9 = 44;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_9_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_10 = 48;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_10_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_11 = 52;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_11_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_12 = 56;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_12_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_13 = 60;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX0_13_LEN = 4;
// proc/reg00071.H

static const uint64_t INT_VC_EASC_FLUSH_POLL = 0x02010961ull;

static const uint32_t INT_VC_EASC_FLUSH_POLL_BLOCKID = 0;
static const uint32_t INT_VC_EASC_FLUSH_POLL_BLOCKID_LEN = 4;
static const uint32_t INT_VC_EASC_FLUSH_POLL_OFFSET = 4;
static const uint32_t INT_VC_EASC_FLUSH_POLL_OFFSET_LEN = 28;
static const uint32_t INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK = 32;
static const uint32_t INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK_LEN = 4;
static const uint32_t INT_VC_EASC_FLUSH_POLL_OFFSET_MASK = 36;
static const uint32_t INT_VC_EASC_FLUSH_POLL_OFFSET_MASK_LEN = 28;
// proc/reg00071.H

static const uint64_t INT_VC_ENDC_ADDITIONAL_PERF_1 = 0x0201099cull;

static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_P0_IS_IDLE = 0;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_P1_IS_IDLE = 1;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7 = 2;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_2_7_LEN = 6;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE_LEN = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS = 16;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_OUTSTANDING_LOADS_LEN = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO = 24;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO_LEN = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY = 32;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_HIGHIEST_SELECTED_WAY_LEN = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63 = 40;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_1_RESERVED_40_63_LEN = 24;
// proc/reg00071.H

static const uint64_t INT_VC_ENDC_WATCH0_DATA2 = 0x020109a6ull;
// proc/reg00071.H

static const uint64_t INT_VC_ENDC_WATCH1_SPEC = 0x020109a8ull;

static const uint32_t INT_VC_ENDC_WATCH1_SPEC_CONFLICT = 0;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7 = 1;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_RESERVED_1_7_LEN = 7;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_FULL = 8;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27 = 9;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_RESERVED_9_27_LEN = 19;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_BLOCKID = 28;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_BLOCKID_LEN = 4;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39 = 32;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_RESERVED_32_39_LEN = 8;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_OFFSET = 40;
static const uint32_t INT_VC_ENDC_WATCH1_SPEC_OFFSET_LEN = 24;
// proc/reg00071.H

static const uint64_t INT_VC_END_BLOCK_MODE = 0x0201090aull;

static const uint32_t INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE = 0;
static const uint32_t INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE_LEN = 32;
// proc/reg00071.H

static const uint64_t INT_VC_ERR_CFG_G2R0 = 0x020109d0ull;

static const uint32_t INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG = 0;
static const uint32_t INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG_LEN = 64;
// proc/reg00071.H

static const uint64_t INT_VC_ESBC_PERF_EVENT_SEL_1 = 0x02010958ull;

static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF = 0;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_EVENT_TRIG_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI = 8;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_STEOI_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ = 12;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_SETPQ_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED = 16;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_OWNED_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED = 20;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_LOAD_NOT_OWNED_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES = 24;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_TOO_MANY_ENTRIES_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU = 28;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_VICTIM_IS_LRU_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY = 32;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_RETRY_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT = 36;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_PRF_HIT_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT = 40;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_1_DPS_DEM_OR_LOAD_HIT_LEN = 4;
// proc/reg00071.H

static const uint64_t NX_CH4_ADDR_2_HASH_FUNCTION_REG = 0x02011143ull;

static const uint32_t NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION_LEN = 64;
// proc/reg00071.H

static const uint64_t NX_CH4_GZIP_CONTROL_REG = 0x02011140ull;

static const uint32_t NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY = 0;
static const uint32_t NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY = 1;
static const uint32_t NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES = 2;
static const uint32_t NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES = 3;
static const uint32_t NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK = 8;
static const uint32_t NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK_LEN = 8;
// proc/reg00071.H

static const uint64_t NX_DMA_EFT_MAX_BYTE_CNT = 0x02011059ull;

static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT = 0;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT_LEN = 5;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT = 5;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT_LEN = 8;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT = 13;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT_LEN = 8;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT = 21;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT_LEN = 5;
// proc/reg00071.H

static const uint64_t NX_PBI_RNG_RESET = 0x020110e6ull;

static const uint32_t NX_PBI_RNG_RESET_RNG_RESET = 0;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE = 0x0301122aull;

static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_0_EN1 = 0;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_0_EN1_LEN = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_1_EN1 = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_1_EN1_LEN = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_2_EN1 = 16;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_2_EN1_LEN = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_3_EN1 = 24;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_3_EN1_LEN = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_4_EN1 = 32;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_4_EN1_LEN = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_5_EN1 = 40;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_5_EN1_LEN = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_6_EN1 = 48;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_6_EN1_LEN = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_7_EN1 = 56;
static const uint32_t PB_COM_SCOM_EN1_STATION_GP_CMD_RATE_7_EN1_LEN = 8;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT = 0x0301120dull;

static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_0_EN_NEXT_EN1 = 0;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_1_EN_NEXT_EN1 = 1;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_2_EN_NEXT_EN1 = 2;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_3_EN_NEXT_EN1 = 3;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_4_EN_NEXT_EN1 = 4;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_5_EN_NEXT_EN1 = 5;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_6_EN_NEXT_EN1 = 6;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_7_EN_NEXT_EN1 = 7;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_0_ADDR_DIS_NEXT_EN1 = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_1_ADDR_DIS_NEXT_EN1 = 9;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_2_ADDR_DIS_NEXT_EN1 = 10;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_3_ADDR_DIS_NEXT_EN1 = 11;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_4_ADDR_DIS_NEXT_EN1 = 12;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_5_ADDR_DIS_NEXT_EN1 = 13;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_6_ADDR_DIS_NEXT_EN1 = 14;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_7_ADDR_DIS_NEXT_EN1 = 15;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_0_MODE_NEXT_EN1 = 16;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_0_ID_NEXT_EN1 = 17;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_0_ID_NEXT_EN1_LEN = 3;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_1_MODE_NEXT_EN1 = 20;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_1_ID_NEXT_EN1 = 21;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_1_ID_NEXT_EN1_LEN = 3;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_2_MODE_NEXT_EN1 = 24;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_2_ID_NEXT_EN1 = 25;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_2_ID_NEXT_EN1_LEN = 3;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_3_MODE_NEXT_EN1 = 28;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_3_ID_NEXT_EN1 = 29;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_3_ID_NEXT_EN1_LEN = 3;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_4_MODE_NEXT_EN1 = 32;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_4_ID_NEXT_EN1 = 33;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_4_ID_NEXT_EN1_LEN = 3;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_5_MODE_NEXT_EN1 = 36;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_5_ID_NEXT_EN1 = 37;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_5_ID_NEXT_EN1_LEN = 3;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_6_MODE_NEXT_EN1 = 40;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_6_ID_NEXT_EN1 = 41;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_6_ID_NEXT_EN1_LEN = 3;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_7_MODE_NEXT_EN1 = 44;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_7_ID_NEXT_EN1 = 45;
static const uint32_t PB_COM_SCOM_EN1_STATION_HP_MODE2_NEXT_7_ID_NEXT_EN1_LEN = 3;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EN2_EXTFIR_ACTION0_REG = 0x03011274ull;

static const uint32_t PB_COM_SCOM_EN2_EXTFIR_ACTION0_REG_EXTFIR_ACTION0 = 0;
static const uint32_t PB_COM_SCOM_EN2_EXTFIR_ACTION0_REG_EXTFIR_ACTION0_LEN = 8;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EN2_EXTFIR_ACTION1_REG = 0x03011275ull;

static const uint32_t PB_COM_SCOM_EN2_EXTFIR_ACTION1_REG_EXTFIR_ACTION1 = 0;
static const uint32_t PB_COM_SCOM_EN2_EXTFIR_ACTION1_REG_EXTFIR_ACTION1_LEN = 8;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB = 0x0301129cull;

static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TTYPE_EN3 = 0;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TTYPE_EN3_LEN = 7;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TTYPE_MASK_EN3 = 7;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TTYPE_MASK_EN3_LEN = 7;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TSIZE_EN3 = 14;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TSIZE_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TSIZE_MASK_EN3 = 22;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TSIZE_MASK_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TTAG_EN3 = 30;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TTAG_EN3_LEN = 10;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TTAG_MASK_EN3 = 40;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_TTAG_MASK_EN3_LEN = 10;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_CRESP_EN3 = 50;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_CRESP_EN3_LEN = 5;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_CRESP_MASK_EN3 = 55;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_CRESP_MASK_EN3_LEN = 5;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_CRESP_POLARITY_EN3 = 60;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_SCOPE_EN3 = 61;
static const uint32_t PB_COM_SCOM_EN3_STATION_EVENT_COMPB_SCOPE_EN3_LEN = 3;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT = 0x0301100bull;

static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_EQ0 = 0;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_EQ0 = 1;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_EQ0 = 2;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_EQ0 = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_EQ0 = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_EQ0 = 16;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_EQ0 = 17;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_EQ0 = 18;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_EQ0 = 24;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_EQ0 = 32;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_EQ0 = 33;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_EQ0 = 34;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_EQ0 = 40;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_EQ0_LEN = 8;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE = 0x030110abull;

static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_0_EQ2 = 0;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_0_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_1_EQ2 = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_1_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_2_EQ2 = 16;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_2_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_3_EQ2 = 24;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_3_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_4_EQ2 = 32;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_4_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_5_EQ2 = 40;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_5_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_6_EQ2 = 48;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_6_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_7_EQ2 = 56;
static const uint32_t PB_COM_SCOM_EQ2_STATION_SP_CMD_RATE_7_EQ2_LEN = 8;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EQ4_STATION_CR_ERROR = 0x0301112cull;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT = 0x0301110dull;

static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_0_EN_NEXT_EQ4 = 0;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_1_EN_NEXT_EQ4 = 1;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_2_EN_NEXT_EQ4 = 2;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_3_EN_NEXT_EQ4 = 3;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_4_EN_NEXT_EQ4 = 4;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_5_EN_NEXT_EQ4 = 5;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_6_EN_NEXT_EQ4 = 6;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_7_EN_NEXT_EQ4 = 7;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_0_ADDR_DIS_NEXT_EQ4 = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_1_ADDR_DIS_NEXT_EQ4 = 9;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_2_ADDR_DIS_NEXT_EQ4 = 10;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_3_ADDR_DIS_NEXT_EQ4 = 11;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_4_ADDR_DIS_NEXT_EQ4 = 12;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_5_ADDR_DIS_NEXT_EQ4 = 13;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_6_ADDR_DIS_NEXT_EQ4 = 14;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_7_ADDR_DIS_NEXT_EQ4 = 15;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_0_MODE_NEXT_EQ4 = 16;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_0_ID_NEXT_EQ4 = 17;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_0_ID_NEXT_EQ4_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_1_MODE_NEXT_EQ4 = 20;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_1_ID_NEXT_EQ4 = 21;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_1_ID_NEXT_EQ4_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_2_MODE_NEXT_EQ4 = 24;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_2_ID_NEXT_EQ4 = 25;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_2_ID_NEXT_EQ4_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_3_MODE_NEXT_EQ4 = 28;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_3_ID_NEXT_EQ4 = 29;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_3_ID_NEXT_EQ4_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_4_MODE_NEXT_EQ4 = 32;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_4_ID_NEXT_EQ4 = 33;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_4_ID_NEXT_EQ4_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_5_MODE_NEXT_EQ4 = 36;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_5_ID_NEXT_EQ4 = 37;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_5_ID_NEXT_EQ4_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_6_MODE_NEXT_EQ4 = 40;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_6_ID_NEXT_EQ4 = 41;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_6_ID_NEXT_EQ4_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_7_MODE_NEXT_EQ4 = 44;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_7_ID_NEXT_EQ4 = 45;
static const uint32_t PB_COM_SCOM_EQ4_STATION_HP_MODE2_NEXT_7_ID_NEXT_EQ4_LEN = 3;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE = 0x0301112bull;

static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_0_EQ4 = 0;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_0_EQ4_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_1_EQ4 = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_1_EQ4_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_2_EQ4 = 16;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_2_EQ4_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_3_EQ4 = 24;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_3_EQ4_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_4_EQ4 = 32;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_4_EQ4_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_5_EQ4 = 40;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_5_EQ4_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_6_EQ4 = 48;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_6_EQ4_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_7_EQ4 = 56;
static const uint32_t PB_COM_SCOM_EQ4_STATION_SP_CMD_RATE_7_EQ4_LEN = 8;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_EQ5_STATION_FIR_REG_RW = 0x03011140ull;
static const uint64_t PB_COM_SCOM_EQ5_STATION_FIR_REG_WO_AND = 0x03011141ull;
static const uint64_t PB_COM_SCOM_EQ5_STATION_FIR_REG_WO_OR = 0x03011142ull;

static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_PROTOCOL_ERROR = 0;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_OVERFLOW_ERROR = 1;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_HW_PARITY_ERROR = 2;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_FIR_SPARE_3 = 3;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_COHERENCY_ERROR = 4;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_CRESP_ADDR_ERROR = 5;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_CRESP_ERROR = 6;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_HANG_RECOVERY_LIMIT_ERROR = 7;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_FIR_SPARE_8 = 8;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_HANG_RECOVERY_GTE_LEVEL1 = 9;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_FORCE_MP_IPL = 10;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_PB_CMD_SNOOPER_ERROR = 11;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_DATA_OVERFLOW_ERROR = 12;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_DATA_PROTOCOL_ERROR = 13;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_DATA_ROUTE_ERROR = 14;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_FIR_SPARE_15 = 15;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_LINK0_PROTOCOL_ERROR = 16;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_LINK0_OVERFLOW_ERROR = 17;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_LINK0_HW_PARITY_ERROR = 18;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_LINK1_PROTOCOL_ERROR = 19;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_LINK1_OVERFLOW_ERROR = 20;
static const uint32_t PB_COM_SCOM_EQ5_STATION_FIR_REG_LINK1_HW_PARITY_ERROR = 21;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_ES2_STATION_FIR_ACTION0_REG = 0x03011346ull;

static const uint32_t PB_COM_SCOM_ES2_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0 = 0;
static const uint32_t PB_COM_SCOM_ES2_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0_LEN = 22;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_ES2_STATION_FIR_ACTION1_REG = 0x03011347ull;

static const uint32_t PB_COM_SCOM_ES2_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1 = 0;
static const uint32_t PB_COM_SCOM_ES2_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1_LEN = 22;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_ES4_STATION_CR_ERROR = 0x030113ecull;
// proc/reg00071.H

static const uint64_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR = 0x030113ceull;

static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_0_EN_CURR_ES4 = 0;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_1_EN_CURR_ES4 = 1;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_2_EN_CURR_ES4 = 2;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_3_EN_CURR_ES4 = 3;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_4_EN_CURR_ES4 = 4;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_5_EN_CURR_ES4 = 5;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_6_EN_CURR_ES4 = 6;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_7_EN_CURR_ES4 = 7;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_0_ADDR_DIS_CURR_ES4 = 8;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_1_ADDR_DIS_CURR_ES4 = 9;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_2_ADDR_DIS_CURR_ES4 = 10;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_3_ADDR_DIS_CURR_ES4 = 11;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_4_ADDR_DIS_CURR_ES4 = 12;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_5_ADDR_DIS_CURR_ES4 = 13;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_6_ADDR_DIS_CURR_ES4 = 14;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_7_ADDR_DIS_CURR_ES4 = 15;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_0_MODE_CURR_ES4 = 16;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_0_ID_CURR_ES4 = 17;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_0_ID_CURR_ES4_LEN = 3;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_1_MODE_CURR_ES4 = 20;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_1_ID_CURR_ES4 = 21;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_1_ID_CURR_ES4_LEN = 3;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_2_MODE_CURR_ES4 = 24;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_2_ID_CURR_ES4 = 25;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_2_ID_CURR_ES4_LEN = 3;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_3_MODE_CURR_ES4 = 28;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_3_ID_CURR_ES4 = 29;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_3_ID_CURR_ES4_LEN = 3;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_4_MODE_CURR_ES4 = 32;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_4_ID_CURR_ES4 = 33;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_4_ID_CURR_ES4_LEN = 3;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_5_MODE_CURR_ES4 = 36;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_5_ID_CURR_ES4 = 37;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_5_ID_CURR_ES4_LEN = 3;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_6_MODE_CURR_ES4 = 40;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_6_ID_CURR_ES4 = 41;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_6_ID_CURR_ES4_LEN = 3;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_7_MODE_CURR_ES4 = 44;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_7_ID_CURR_ES4 = 45;
static const uint32_t PB_COM_SCOM_ES4_STATION_HP_MODE2_CURR_7_ID_CURR_ES4_LEN = 3;
// proc/reg00071.H

static const uint64_t PB_PTLSCOM10_CFG_CNPM_REG = 0x1001181full;

static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_EN = 0;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_RESET_MODE = 1;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_COUNTER_MODE = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_DIS = 3;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_GLOBAL_PMISC_MODE = 4;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_EXTERNAL_FREEZE = 5;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP = 6;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_0_1_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP = 8;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_2_3_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP = 10;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_4_5_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP = 12;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_6_7_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP = 14;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_8_9_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP = 16;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_10_11_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP = 18;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_12_13_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP = 20;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_14_15_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP = 22;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_16_17_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP = 24;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_18_19_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP = 26;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_20_21_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP = 28;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_22_23_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP = 30;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_24_25_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP = 32;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_26_27_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP = 34;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_28_29_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP = 36;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_30_31_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0 = 38;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU0_LEN = 3;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1 = 41;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU1_LEN = 3;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2 = 44;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU2_LEN = 3;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3 = 47;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_CASCADE_PMU3_LEN = 3;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_SPARE = 50;
static const uint32_t PB_PTLSCOM10_CFG_CNPM_REG_SPARE_LEN = 6;
// proc/reg00071.H

static const uint64_t PB_PTLSCOM10_FP01_CFG = 0x1001180aull;

static const uint32_t PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 = 0;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING = 1;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION = 2;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION = 3;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT = 4;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT = 12;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP = 20;
static const uint32_t PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME = 21;
static const uint32_t PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME_LEN = 3;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR = 24;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST = 25;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE = 26;
static const uint32_t PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE_LEN = 6;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 = 32;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING = 33;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION = 34;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION = 35;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT = 36;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT = 44;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP = 52;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE = 53;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR = 56;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST = 57;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE = 58;
static const uint32_t PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE_LEN = 6;
// proc/reg00071.H

static const uint64_t PB_PTLSCOM10_MISC_CFG = 0x10011825ull;

static const uint32_t PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE = 0;
static const uint32_t PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE = 1;
static const uint32_t PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE = 2;
static const uint32_t PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE = 3;
static const uint32_t PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR = 4;
static const uint32_t PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR = 5;
static const uint32_t PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER = 6;
static const uint32_t PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER = 7;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE = 8;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE = 9;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE = 10;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE = 11;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 = 12;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN = 13;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 = 14;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN = 15;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 = 16;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN = 17;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 = 18;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN = 19;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 = 20;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 = 21;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 = 22;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 = 23;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 = 24;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 = 25;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 = 26;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 = 27;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 = 28;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 = 29;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 = 30;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 = 31;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 = 32;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 = 33;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 = 34;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 = 35;
static const uint32_t PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE = 36;
static const uint32_t PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE = 37;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL = 38;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TOD_EVN_IB_MUX_CTL_LEN = 2;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL = 40;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TOD_ODD_IB_MUX_CTL_LEN = 2;
static const uint32_t PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL = 42;
static const uint32_t PB_PTLSCOM10_MISC_CFG_MISC_SPARE = 43;
static const uint32_t PB_PTLSCOM10_MISC_CFG_MISC_SPARE_LEN = 9;
// proc/reg00071.H

static const uint64_t PB_PTLSCOM10_PMU3_TLPM_COUNTER = 0x1001181eull;
// proc/reg00071.H

static const uint64_t PB_PTLSCOM10_PTL_FIR_WOF_REG = 0x10011808ull;

static const uint32_t PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF = 0;
static const uint32_t PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN = 40;
// proc/reg00071.H

static const uint64_t PB_PTLSCOM23_PMU1_TLPM_COUNTER = 0x1101181cull;
// proc/reg00071.H

static const uint64_t PB_PTLSCOM45_CFG_TLPM_REG = 0x1201181aull;

static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_EN = 0;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_RESET_MODE = 1;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_COUNTER_MODE = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_DIS = 3;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_GLOBAL_PMISC_MODE = 4;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_EXTERNAL_FREEZE = 5;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP = 6;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_0_1_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP = 8;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_2_3_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP = 10;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_4_5_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP = 12;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_6_7_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP = 14;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_8_9_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP = 16;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_10_11_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP = 18;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_12_13_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP = 20;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_14_15_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP = 22;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_16_17_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP = 24;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_18_19_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP = 26;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_20_21_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP = 28;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_22_23_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP = 30;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_24_25_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP = 32;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_26_27_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP = 34;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_28_29_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP = 36;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_30_31_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0 = 38;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU0_LEN = 3;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1 = 41;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU1_LEN = 3;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2 = 44;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU2_LEN = 3;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3 = 47;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_CASCADE_PMU3_LEN = 3;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_SPARE = 50;
static const uint32_t PB_PTLSCOM45_CFG_TLPM_REG_SPARE_LEN = 6;
// proc/reg00071.H

static const uint64_t PB_PTLSCOM67_TL_LINK_SYN_23_REG = 0x13011813ull;
// proc/reg00071.H

static const uint64_t PB_PTLSCOM67_TRACE_CFG = 0x13011826ull;

static const uint32_t PB_PTLSCOM67_TRACE_CFG_0L_SEL = 0;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_0L_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_0R_SEL = 8;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_0R_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_1L_SEL = 16;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_1L_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_1R_SEL = 24;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_1R_SEL_LEN = 8;
// proc/reg00071.H

static const uint64_t PB_BRIDGE_HCA_DECAY_0_CONTROL_REG = 0x03011d51ull;

static const uint32_t PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE = 0;
static const uint32_t PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY = 1;
static const uint32_t PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY_LEN = 6;
// proc/reg00071.H

static const uint64_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG = 0x03011cc4ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP = 1;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT = 3;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE = 6;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE_LEN = 10;
// proc/reg00071.H

static const uint64_t TP_LPC_SYNC_FIR_MASK_REG_RW = 0x030121c3ull;
static const uint64_t TP_LPC_SYNC_FIR_MASK_REG_WO_AND = 0x030121c4ull;
static const uint64_t TP_LPC_SYNC_FIR_MASK_REG_WO_OR = 0x030121c5ull;

static const uint32_t TP_LPC_SYNC_FIR_MASK_REG_INVALID_TRANSFER_SIZE_MASK = 0;
static const uint32_t TP_LPC_SYNC_FIR_MASK_REG_INVALID_COMMAND_MASK = 1;
static const uint32_t TP_LPC_SYNC_FIR_MASK_REG_INVALID_ADDRESS_ALIGNMENT_MASK = 2;
static const uint32_t TP_LPC_SYNC_FIR_MASK_REG_OPB_ERROR_MASK = 3;
static const uint32_t TP_LPC_SYNC_FIR_MASK_REG_OPB_TIMEOUT_MASK = 4;
static const uint32_t TP_LPC_SYNC_FIR_MASK_REG_OPB_MASTER_HANG_TIMEOUT_MASK = 5;
static const uint32_t TP_LPC_SYNC_FIR_MASK_REG_CMD_BUFFER_PAR_ERR_MASK = 6;
static const uint32_t TP_LPC_SYNC_FIR_MASK_REG_DAT_BUFFER_PAR_ERR_MASK = 7;
static const uint32_t TP_LPC_SYNC_FIR_MASK_REG_RETURNQ_ERR_MASK = 8;
static const uint32_t TP_LPC_SYNC_FIR_MASK_REG_RESERVED_MASK = 9;
// proc/reg00071.H

static const uint64_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5 = 0x02040085ull;

static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR = 0;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR = 1;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR = 2;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR = 3;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR = 4;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR = 5;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1_ERR = 6;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR = 7;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// proc/reg00071.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA1 = 0x0205001aull;
// proc/reg00071.H

static const uint64_t TP_TCN0_N0_LOCAL_FIR_RW = 0x02040100ull;
static const uint64_t TP_TCN0_N0_LOCAL_FIR_WO_AND = 0x02040101ull;
static const uint64_t TP_TCN0_N0_LOCAL_FIR_WO_OR = 0x02040102ull;

static const uint32_t TP_TCN0_N0_LOCAL_FIR_CFIR = 0;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_CPLT_CTRL = 1;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_CC_PCB = 2;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_CC_OTHERS = 3;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN04 = 4;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN05 = 5;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN06 = 6;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN07 = 7;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN08 = 8;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN09 = 9;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN10 = 10;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN11 = 11;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN12 = 12;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN13 = 13;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN14 = 14;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN15 = 15;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN16 = 16;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN17 = 17;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN18 = 18;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN19 = 19;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN20 = 20;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN21 = 21;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN22 = 22;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN23 = 23;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN24 = 24;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN25 = 25;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN26 = 26;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN27 = 27;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN28 = 28;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN29 = 29;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN30 = 30;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN31 = 31;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN32 = 32;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN33 = 33;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN34 = 34;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN35 = 35;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN36 = 36;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN37 = 37;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN38 = 38;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN39 = 39;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN40 = 40;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN41 = 41;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN42 = 42;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN43 = 43;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN44 = 44;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN45 = 45;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN46 = 46;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN47 = 47;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN48 = 48;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN49 = 49;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN50 = 50;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN51 = 51;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN52 = 52;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN53 = 53;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN54 = 54;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN55 = 55;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN56 = 56;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN57 = 57;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN58 = 58;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN59 = 59;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN60 = 60;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN61 = 61;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_IN62 = 62;
static const uint32_t TP_TCN0_N0_LOCAL_FIR_EXT_LOCAL_XSTOP = 63;
// proc/reg00071.H

static const uint64_t TP_TCN0_N0_OPCG_CAPT1 = 0x02030010ull;

static const uint32_t TP_TCN0_N0_OPCG_CAPT1_COUNT = 0;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t TP_TCN0_N0_OPCG_CAPT1_SEQ_12_LEN = 5;
// proc/reg00072.H

static const uint64_t TP_TCN0_N0_PCB_OPCG_GO = 0x02030020ull;

static const uint32_t TP_TCN0_N0_PCB_OPCG_GO_PCB_OPCGGO = 0;
// proc/reg00072.H

static const uint64_t TP_TCN0_N0_RECOV_MASK_RW = 0x02040041ull;
static const uint64_t TP_TCN0_N0_RECOV_MASK_WO_CLEAR = 0x02040061ull;
static const uint64_t TP_TCN0_N0_RECOV_MASK_WO_OR = 0x02040051ull;

static const uint32_t TP_TCN0_N0_RECOV_MASK_1 = 1;
static const uint32_t TP_TCN0_N0_RECOV_MASK_2 = 2;
static const uint32_t TP_TCN0_N0_RECOV_MASK_3 = 3;
static const uint32_t TP_TCN0_N0_RECOV_MASK_4 = 4;
static const uint32_t TP_TCN0_N0_RECOV_MASK_5 = 5;
static const uint32_t TP_TCN0_N0_RECOV_MASK_6 = 6;
static const uint32_t TP_TCN0_N0_RECOV_MASK_7 = 7;
static const uint32_t TP_TCN0_N0_RECOV_MASK_8 = 8;
static const uint32_t TP_TCN0_N0_RECOV_MASK_9 = 9;
static const uint32_t TP_TCN0_N0_RECOV_MASK_10 = 10;
static const uint32_t TP_TCN0_N0_RECOV_MASK_11 = 11;
static const uint32_t TP_TCN0_N0_RECOV_MASK_12 = 12;
static const uint32_t TP_TCN0_N0_RECOV_MASK_13 = 13;
static const uint32_t TP_TCN0_N0_RECOV_MASK_14 = 14;
static const uint32_t TP_TCN0_N0_RECOV_MASK_15 = 15;
static const uint32_t TP_TCN0_N0_RECOV_MASK_16 = 16;
static const uint32_t TP_TCN0_N0_RECOV_MASK_17 = 17;
static const uint32_t TP_TCN0_N0_RECOV_MASK_18 = 18;
static const uint32_t TP_TCN0_N0_RECOV_MASK_19 = 19;
static const uint32_t TP_TCN0_N0_RECOV_MASK_20 = 20;
static const uint32_t TP_TCN0_N0_RECOV_MASK_21 = 21;
static const uint32_t TP_TCN0_N0_RECOV_MASK_22 = 22;
static const uint32_t TP_TCN0_N0_RECOV_MASK_23 = 23;
static const uint32_t TP_TCN0_N0_RECOV_MASK_24 = 24;
static const uint32_t TP_TCN0_N0_RECOV_MASK_25 = 25;
static const uint32_t TP_TCN0_N0_RECOV_MASK_26 = 26;
static const uint32_t TP_TCN0_N0_RECOV_MASK_27 = 27;
static const uint32_t TP_TCN0_N0_RECOV_MASK_28 = 28;
static const uint32_t TP_TCN0_N0_RECOV_MASK_29 = 29;
static const uint32_t TP_TCN0_N0_RECOV_MASK_30 = 30;
static const uint32_t TP_TCN0_N0_RECOV_MASK_31 = 31;
static const uint32_t TP_TCN0_N0_RECOV_MASK_32 = 32;
static const uint32_t TP_TCN0_N0_RECOV_MASK_33 = 33;
static const uint32_t TP_TCN0_N0_RECOV_MASK_34 = 34;
static const uint32_t TP_TCN0_N0_RECOV_MASK_35 = 35;
static const uint32_t TP_TCN0_N0_RECOV_MASK_36 = 36;
static const uint32_t TP_TCN0_N0_RECOV_MASK_37 = 37;
static const uint32_t TP_TCN0_N0_RECOV_MASK_38 = 38;
static const uint32_t TP_TCN0_N0_RECOV_MASK_39 = 39;
static const uint32_t TP_TCN0_N0_RECOV_MASK_40 = 40;
static const uint32_t TP_TCN0_N0_RECOV_MASK_41 = 41;
static const uint32_t TP_TCN0_N0_RECOV_MASK_42 = 42;
static const uint32_t TP_TCN0_N0_RECOV_MASK_43 = 43;
static const uint32_t TP_TCN0_N0_RECOV_MASK_44 = 44;
static const uint32_t TP_TCN0_N0_RECOV_MASK_45 = 45;
static const uint32_t TP_TCN0_N0_RECOV_MASK_46 = 46;
static const uint32_t TP_TCN0_N0_RECOV_MASK_47 = 47;
static const uint32_t TP_TCN0_N0_RECOV_MASK_48 = 48;
static const uint32_t TP_TCN0_N0_RECOV_MASK_49 = 49;
static const uint32_t TP_TCN0_N0_RECOV_MASK_50 = 50;
static const uint32_t TP_TCN0_N0_RECOV_MASK_51 = 51;
static const uint32_t TP_TCN0_N0_RECOV_MASK_52 = 52;
static const uint32_t TP_TCN0_N0_RECOV_MASK_53 = 53;
// proc/reg00072.H

static const uint64_t TP_TCN0_N0_SCAN_LONG_ROTATE = 0x02039000ull;
// proc/reg00072.H

static const uint64_t TP_TCN0_N0_TRA1_TR0_CONFIG_9 = 0x02010489ull;

static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00072.H

static const uint64_t TP_TCN0_N0_XSTOP_UNMASKED = 0x02040010ull;

static const uint32_t TP_TCN0_N0_XSTOP_UNMASKED_XSTOP_UNMASKED_IN = 1;
static const uint32_t TP_TCN0_N0_XSTOP_UNMASKED_XSTOP_UNMASKED_IN_LEN = 53;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_BIST = 0x0303000bull;

static const uint32_t TP_TCN1_N1_BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t TP_TCN1_N1_BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t TP_TCN1_N1_BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t TP_TCN1_N1_BIST_BIST_PERV = 4;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT1 = 5;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT2 = 6;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT3 = 7;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT4 = 8;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT5 = 9;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT6 = 10;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT7 = 11;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT8 = 12;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT9 = 13;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT10 = 14;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT11 = 15;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT12 = 16;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT13 = 17;
static const uint32_t TP_TCN1_N1_BIST_BIST_UNIT14 = 18;
static const uint32_t TP_TCN1_N1_BIST_BIST_STROBE_WINDOW_EN = 48;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_CPLT_CTRL3_RW = 0x03000003ull;
static const uint64_t TP_TCN1_N1_CPLT_CTRL3_WO_CLEAR = 0x03000023ull;
static const uint64_t TP_TCN1_N1_CPLT_CTRL3_WO_OR = 0x03000013ull;

static const uint32_t TP_TCN1_N1_CPLT_CTRL3_0_PSCOM_EN = 4;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_1_PSCOM_EN = 5;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_2_PSCOM_EN = 6;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_3_PSCOM_EN = 7;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_4_PSCOM_EN = 8;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_5_PSCOM_EN = 9;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_6_PSCOM_EN = 10;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_7_PSCOM_EN = 11;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_8_PSCOM_EN = 12;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_9_PSCOM_EN = 13;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_10_PSCOM_EN = 14;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_11_PSCOM_EN = 15;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_12_PSCOM_EN = 16;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_13_PSCOM_EN = 17;
static const uint32_t TP_TCN1_N1_CPLT_CTRL3_14_PSCOM_EN = 18;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_CTRL_ATOMIC_LOCK_REG = 0x030003ffull;

static const uint32_t TP_TCN1_N1_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t TP_TCN1_N1_CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t TP_TCN1_N1_CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t TP_TCN1_N1_CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t TP_TCN1_N1_CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_EPS_DBG_XTRA_TRACE_MODE = 0x030107d1ull;

static const uint32_t TP_TCN1_N1_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t TP_TCN1_N1_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK = 0x03010002ull;

static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR = 3;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_UL_P0_ERROR = 5;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_GENERAL_TIMEOUT = 15;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG = 0x03010401ull;

static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_TRA0_TR0_CONFIG = 0x03010402ull;

static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_TRA1_TR0_CONFIG_1 = 0x03010484ull;

static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_TRA1_TR1_CONFIG = 0x030104c2ull;

static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_TRA3_TR0_CONFIG_9 = 0x03010589ull;

static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_TRA3_TR1_TRACE_HI_DATA_REG = 0x030105c0ull;

static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_TRA3_TR1_CONFIG_0 = 0x030105c3ull;

static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_TRA4_TR1_CONFIG_1 = 0x03010644ull;

static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_TRA6_TR0_CONFIG_0 = 0x03010703ull;

static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_TRA6_TR1_CONFIG_9 = 0x03010749ull;

static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00072.H

static const uint64_t TP_TCN1_N1_XSTOP5 = 0x03030015ull;

static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_MASK_B = 0;
static const uint32_t TP_TCN1_N1_XSTOP5_ALIGNED_XSTOP5 = 1;
static const uint32_t TP_TCN1_N1_XSTOP5_TRIGGER_OPCG_ON_XSTOP5 = 2;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_WAIT_ALLWAYS = 3;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_PERV = 4;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT1 = 5;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT2 = 6;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT3 = 7;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT4 = 8;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT5 = 9;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT6 = 10;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT7 = 11;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT8 = 12;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT9 = 13;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT10 = 14;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT11 = 15;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT12 = 16;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT13 = 17;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_UNIT14 = 18;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_WAIT_CYCLES = 48;
static const uint32_t TP_TCN1_N1_XSTOP5_XSTOP5_WAIT_CYCLES_LEN = 12;
// proc/reg00072.H

static const uint64_t TP_TPBR_AD_PIB_CMD_REG = 0x00090031ull;

static const uint32_t TP_TPBR_AD_PIB_CMD_REG_RNW = 0;
static const uint32_t TP_TPBR_AD_PIB_CMD_REG_ADR = 30;
static const uint32_t TP_TPBR_AD_PIB_CMD_REG_ADR_LEN = 31;
// proc/reg00072.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAFIRMASK_RW = 0x03011dc3ull;
static const uint64_t TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND = 0x03011dc4ull;
static const uint64_t TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR = 0x03011dc5ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK = 0;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK = 1;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK = 2;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK = 3;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK = 5;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK = 6;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK = 7;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK = 8;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK = 9;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK = 10;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK = 11;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK = 12;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK = 13;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK = 14;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK = 15;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK = 17;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK = 18;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK = 19;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK = 20;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK = 21;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK = 22;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK = 23;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK = 24;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK = 25;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK = 26;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK = 27;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK = 28;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK = 29;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK = 30;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK = 31;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK = 32;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK = 33;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK = 34;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK = 35;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK = 36;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39 = 37;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39_LEN = 3;
// proc/reg00072.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABAR3 = 0x01010cddull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3 = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_ADDR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_ADDR_LEN = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_VTARGET = 48;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_VTARGET_LEN = 16;
// proc/reg00072.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABARMSK2 = 0x01010ce0ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK_LEN = 21;
// proc/reg00072.H

static const uint64_t TP_TPBR_PBA_PBAO_PBARBUFVAL3 = 0x01010cd3ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR_LEN = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT = 31;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS = 33;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS_LEN = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID = 41;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID_LEN = 3;
// proc/reg00072.H

static const uint64_t TP_TPBR_PBA_PBAO_PBASLVRST = 0x00068001ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_SET = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_SET_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR_LEN = 2;
// proc/reg00072.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXICFG = 0x00068031ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_PBAX_EN = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RESERVATION_EN = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_SND_RESET = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RCV_RESET = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RCV_GROUPID = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RCV_GROUPID_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RCV_CHIPID = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RCV_CHIPID_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RESERVED_11 = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RCV_BRDCST_GROUP = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RCV_BRDCST_GROUP_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RCV_DATATO_DIV = 20;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RCV_DATATO_DIV_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RESERVED_25_26 = 25;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_RESERVED_25_26_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_SND_RETRY_COUNT_OVERCOM = 27;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_SND_RETRY_THRESH = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_SND_RETRY_THRESH_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_SND_RSVTO_DIV = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXICFG_SND_RSVTO_DIV_LEN = 5;
// proc/reg00072.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT = 0x00068034ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_IN_PROGRESS = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_ERROR = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_WRITE_IN_PROGRESS = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_RESERVATION_SET = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_CAPTURE = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_CAPTURE_LEN = 16;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1 = 0x020f0001ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_CTRL1_RW = 0x020f0044ull;
static const uint64_t TP_TPCHIP_NET_PCBSLN0_CTRL1_RW_WAND = 0x020f0045ull;
static const uint64_t TP_TPCHIP_NET_PCBSLN0_CTRL1_RW_WOR = 0x020f0046ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE0_CLK_DCC_BYPASS = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE1_CLK_DCC_BYPASS = 1;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE2_CLK_DCC_BYPASS = 2;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE3_CLK_DCC_BYPASS = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE0_CLK_DCC_BYPASS = 4;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE1_CLK_DCC_BYPASS = 5;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE2_CLK_DCC_BYPASS = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE3_CLK_DCC_BYPASS = 7;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE0_CLK_PDLY_BYPASS = 8;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE1_CLK_PDLY_BYPASS = 9;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE2_CLK_PDLY_BYPASS = 10;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE3_CLK_PDLY_BYPASS = 11;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE0_CLK_PDLY_BYPASS = 12;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE1_CLK_PDLY_BYPASS = 13;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE2_CLK_PDLY_BYPASS = 14;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE3_CLK_PDLY_BYPASS = 15;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC = 16;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC = 17;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC = 18;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC = 19;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE0_CLK_DCADJUST_RESET_DC = 20;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE1_CLK_DCADJUST_RESET_DC = 21;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE2_CLK_DCADJUST_RESET_DC = 22;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL1_ORE3_CLK_DCADJUST_RESET_DC = 23;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_PRE_COUNTER_REG = 0x020f0028ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN0_PRE_COUNTER_REG_PRE_COUNTER = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_PRE_COUNTER_REG_PRE_COUNTER_LEN = 8;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_HEARTBEAT_REG = 0x030f0018ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN1_HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_CTRL1_RW = 0x030f0044ull;
static const uint64_t TP_TPCHIP_NET_PCBSLN1_CTRL1_RW_WAND = 0x030f0045ull;
static const uint64_t TP_TPCHIP_NET_PCBSLN1_CTRL1_RW_WOR = 0x030f0046ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE0_CLK_DCC_BYPASS = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE1_CLK_DCC_BYPASS = 1;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE2_CLK_DCC_BYPASS = 2;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE3_CLK_DCC_BYPASS = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE0_CLK_DCC_BYPASS = 4;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE1_CLK_DCC_BYPASS = 5;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE2_CLK_DCC_BYPASS = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE3_CLK_DCC_BYPASS = 7;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE0_CLK_PDLY_BYPASS = 8;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE1_CLK_PDLY_BYPASS = 9;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE2_CLK_PDLY_BYPASS = 10;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE3_CLK_PDLY_BYPASS = 11;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE0_CLK_PDLY_BYPASS = 12;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE1_CLK_PDLY_BYPASS = 13;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE2_CLK_PDLY_BYPASS = 14;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE3_CLK_PDLY_BYPASS = 15;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC = 16;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC = 17;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC = 18;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC = 19;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE0_CLK_DCADJUST_RESET_DC = 20;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE1_CLK_DCADJUST_RESET_DC = 21;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE2_CLK_DCADJUST_RESET_DC = 22;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL1_ORE3_CLK_DCADJUST_RESET_DC = 23;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_1 = 0x010f0001ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPESWPR1 = 0x00060006ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPESWPR1_BAR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPESWPR1_BAR_LEN = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPESWPR1_SIZE = 44;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPESWPR1_SIZE_LEN = 15;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXICTR = 0x00060032ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXICTR_OCB_OCI_GPEXICTR_CTR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXICTR_OCB_OCI_GPEXICTR_CTR_LEN = 32;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR = 0x00060014ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR_LEN = 32;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL = 0x0006002bull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING = 3;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU = 0x0006002aull;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR30 = 0x00060087ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR30_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR30_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR30_1 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR30_1_LEN = 32;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC = 0x0006201aull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_TAG_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_TAG_ADDR_LEN = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_ERR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_POPULATE_PENDING = 35;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_VALID = 36;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_VALID_LEN = 4;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR7 = 0x00062047ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR7_OCB_OCI_GPEXIVDR6_GPR7 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR7_OCB_OCI_GPEXIVDR6_GPR7_LEN = 32;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR6 = 0x00062083ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR6_6 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR6_6_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR6_7 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR6_7_LEN = 32;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIEDR = 0x00064023ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIEDR_OCB_OCI_GPEXIRAMEDR_EDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIEDR_OCB_OCI_GPEXIRAMEDR_EDR_LEN = 32;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR3 = 0x00064043ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR3_OCB_OCI_GPEXIVDR2_GPR3 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR3_OCB_OCI_GPEXIVDR2_GPR3_LEN = 32;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR31 = 0x0006404full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31_LEN = 32;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR2 = 0x00064081ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR2_2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR2_2_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR2_3 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR2_3_LEN = 32;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR30 = 0x0006604eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN = 32;
// proc/reg00072.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8 = 0x00066048ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8_LEN = 32;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR = 0x00066025ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR_LEN = 30;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISPRG0 = 0x00066022ull;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B = 0x0006c737ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B = 1;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SWD1B = 0x0006c738ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B_LEN = 32;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3 = 0x0006c238ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR_LEN = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK_LEN = 12;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3 = 0x0006c23aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0_LEN = 5;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0 = 0x0006c200ull;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1 = 0x0006c211ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE = 31;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW = 0x0006c0a3ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR = 0x0006c0a4ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR = 0x0006c0a5ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1_LEN = 32;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR1_RW = 0x0006c028ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR = 0x0006c029ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR = 0x0006c02aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1_LEN = 32;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO = 0x0006c600ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR = 0x0006c601ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7 = 7;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0 = 0x0006c408ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4 = 0x0006c414ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2 = 0x0006c42aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6 = 0x0006c436ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR = 0x0006c550ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD_LEN = 17;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C2 = 0x0006c442ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD_LEN = 17;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR = 0x0006c558ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD_LEN = 17;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR = 0x0006c549ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD_LEN = 17;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR = 0x0006c56bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD_LEN = 17;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR = 0x0006c577ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD_LEN = 17;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR = 0x0006c569ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD_LEN = 17;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO = 0x0006c660ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR = 0x0006c661ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7 = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9 = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10 = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11 = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13 = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14 = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15 = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17 = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19 = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21 = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22 = 22;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23 = 23;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25 = 25;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26 = 26;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27 = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29 = 29;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30 = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31 = 31;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0 = 0x0006c484ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7_LEN = 4;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITIR = 0x0006c5c0ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD_LEN = 23;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA = 0x0006c860ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA_LEN = 32;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA = 0x0006c850ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA_LEN = 32;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG = 0x0006c803ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_HWCTRL_ONGOING = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_RESERVED_1_3 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_RESERVED_1_3_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_HWCTRL_INVALID_NUMBER_OF_FRAMES = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_HWCTRL_FSM_ERR = 7;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO = 0x0006d031ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR = 0x0006d032ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR = 0x0006d033ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 = 15;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0 = 0x0006d015ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA_LEN = 64;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3 = 0x0006d074ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR_LEN = 32;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO = 0x0006d00dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B = 37;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT = 38;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG = 40;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR = 41;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR = 42;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR = 43;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR = 44;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR = 45;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR = 46;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR = 50;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET = 51;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID = 52;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR = 60;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR_LEN = 4;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OCC_SRAM_CTL_SRBV3 = 0x0006a007ull;

static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3 = 0;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3_LEN = 32;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1 = 0x00008001ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1_LEN = 64;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115 = 0x00008073ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115_LEN = 64;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122 = 0x0000807aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122_LEN = 64;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15 = 0x0000800full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15_LEN = 64;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22 = 0x00008016ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22_LEN = 64;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43 = 0x0000802bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43_LEN = 64;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74 = 0x0000804aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74_LEN = 64;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81 = 0x00008051ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81_LEN = 64;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL4_RW = 0x01000004ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR = 0x01000024ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR = 0x01000014ull;

static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH = 4;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH = 5;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH = 6;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH = 7;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH = 8;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH = 9;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH = 10;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH = 11;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH = 12;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH = 13;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH = 14;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH = 15;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH = 16;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH = 17;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH = 18;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG = 0x010003feull;

static const uint32_t TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG = 0x010107c0ull;

static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION = 11;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 12;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW = 0x01040103ull;
static const uint64_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND = 0x01040104ull;
static const uint64_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR = 0x01040105ull;

static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00 = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01 = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02 = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03 = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04 = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05 = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06 = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07 = 7;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08 = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09 = 9;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10 = 10;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11 = 11;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12 = 12;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13 = 13;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14 = 14;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15 = 15;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16 = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17 = 17;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18 = 18;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19 = 19;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20 = 20;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21 = 21;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22 = 22;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23 = 23;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24 = 24;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25 = 25;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26 = 26;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27 = 27;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28 = 28;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29 = 29;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30 = 30;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31 = 31;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32 = 32;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33 = 33;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34 = 34;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35 = 35;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36 = 36;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37 = 37;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38 = 38;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39 = 39;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40 = 40;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41 = 41;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42 = 42;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43 = 43;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44 = 44;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45 = 45;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46 = 46;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47 = 47;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48 = 48;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49 = 49;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50 = 50;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51 = 51;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52 = 52;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53 = 53;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54 = 54;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55 = 55;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56 = 56;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57 = 57;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58 = 58;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59 = 59;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60 = 60;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61 = 61;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62 = 62;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63 = 63;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG = 0x01010000ull;

static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS = 7;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT = 9;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN = 3;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG = 0x01020001ull;

static const uint32_t TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA = 0;
static const uint32_t TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF = 2;
static const uint32_t TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF_LEN = 10;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG = 0x01020007ull;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_TPC_SCAN_LONG_ROTATE = 0x01039000ull;
// proc/reg00073.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_HI_DATA_REG = 0x01010400ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// proc/reg00074.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_1 = 0x01010444ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00074.H

static const uint64_t TP_TPCHIP_TPC_XSTOP1 = 0x0103000cull;

static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_MASK_B = 0;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_ALIGNED_XSTOP1 = 1;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_TRIGGER_OPCG_ON_XSTOP1 = 2;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_WAIT_ALLWAYS = 3;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_PERV = 4;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT1 = 5;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT2 = 6;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT3 = 7;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT4 = 8;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT5 = 9;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT6 = 10;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT7 = 11;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT8 = 12;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT9 = 13;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT10 = 14;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT11 = 15;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT12 = 16;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT13 = 17;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_UNIT14 = 18;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_WAIT_CYCLES = 48;
static const uint32_t TP_TPCHIP_TPC_XSTOP1_XSTOP1_WAIT_CYCLES_LEN = 12;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD1_FSI = 0x00001401ull;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD1_FSI_BYTE = 0x00001404ull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD1_FSI_SCRATCH_PAD1 = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD1_FSI_SCRATCH_PAD1_LEN = 32;
// proc/reg00074.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_0_FSI = 0x00002880ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_0_FSI_BYTE = 0x00002a00ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_0_RW = 0x00050080ull;
// proc/reg00074.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_14_FSI = 0x0000288eull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_14_FSI_BYTE = 0x00002a38ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_14_RW = 0x0005008eull;
// proc/reg00074.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_6_FSI = 0x000028c6ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_6_FSI_BYTE = 0x00002b18ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_6_RW = 0x000500c6ull;
// proc/reg00074.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_10_FSI = 0x0000290aull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_10_FSI_BYTE = 0x00002c28ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_10_RW = 0x0005010aull;
// proc/reg00074.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_A_FSI = 0x00002822ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_A_FSI_BYTE = 0x00002888ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_A_RW = 0x00050022ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A_LEN =
    32;
// proc/reg00074.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_B_FSI = 0x0000282eull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_B_FSI_BYTE = 0x000028b8ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_B_RO = 0x0005002eull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B =
    0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B_LEN
    = 32;
// proc/reg00074.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_FSI = 0x00002813ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE = 0x0000284cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_RW = 0x00050013ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLCLKSW1 = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLCLKSW2 = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC = 31;
// proc/reg00074.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_COPY_FSI = 0x00002913ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_COPY_FSI_BYTE = 0x00002c4cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_COPY_RW = 0x00050113ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI = 0x00002414ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI_BYTE = 0x00002450ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_RESET_FSI = 0x00002434ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_RESET_FSI_BYTE = 0x000024d0ull;
// proc/reg00074.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INPUT = 0x000b0050ull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INPUT_0 = 0;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INPUT_1 = 1;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INPUT_2 = 2;
// proc/reg00074.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_CRSIS = 0x00020007ull;
// proc/reg00074.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RSIS = 0x0002000aull;
// proc/reg00074.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIM = 0x00020016ull;
// proc/reg00074.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIM = 0x00030009ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP6_FSI0 = 0x00003068ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP6_SCOMFSI0 = 0x00000c1aull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_FSI0 = 0x000030ecull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_RO = 0x00000c3bull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_2_LEN = 3;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP4_FSI0 = 0x000034e0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP4_WO = 0x00000d38ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP4_GENERAL_RESET_4 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP4_ERROR_RESET_4 = 1;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP7_FSI0 = 0x0000344cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP7_SCOMFSI0 = 0x00000d13ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSSIEP0_FSI0 = 0x00003450ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSSIEP0_SCOMFSI0 = 0x00000d14ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCRSIM0 = 0x00000858ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SLBUS = 0x00000830ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SRSIC0 = 0x00000868ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MATRB0_FSI1 = 0x000031d8ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MATRB0_SCOMFSI1 = 0x00000c76ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDTRB0_FSI1 = 0x000031dcull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDTRB0_SCOMFSI1 = 0x00000c77ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_FSI1 = 0x000030d8ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WO = 0x00000c36ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2 = 1;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1 = 0x00003034ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1 = 0x00000c0dull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SNML = 0x00000840ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SSISM = 0x00000810ull;
// proc/reg00074.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SSTAT = 0x00000814ull;
// proc/reg00074.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER = 0x00070021ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1 = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2 = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A = 16;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT = 24;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_INTERNALCOUNT = 32;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_INTERNALCOUNT_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL = 40;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL = 48;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL = 52;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B = 56;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B_LEN = 8;
// proc/reg00074.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_RW = 0x00070029ull;
static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_RW_WAND = 0x0007002aull;
static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_RW_WOR = 0x0007002bull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_MISO = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_MISO_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_MOSI = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_MOSI_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_DIRECTMODE = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_EN_C4 = 9;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_SCS_B = 10;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_SCK = 11;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_IO_CONTROL = 12;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_IO_CONTROL_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_INVERT_PORTS = 20;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_INVERT_PORTS_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_SLAVE_RESET = 24;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_SPI_SLAVE_RESET_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_LOOPBACK = 28;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_PORT_CONTROL_MMSPISM_ENABLE = 29;
// proc/reg00074.H

static const uint64_t VAS_VA_EG_SCF_WCBSBAR = 0x02011440ull;

static const uint32_t VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR = 8;
static const uint32_t VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR_LEN = 33;
// proc/reg00074.H

static const uint64_t VAS_VA_RG_SCF_FIR_REG_RW = 0x02011400ull;
static const uint64_t VAS_VA_RG_SCF_FIR_REG_WO_AND = 0x02011401ull;
static const uint64_t VAS_VA_RG_SCF_FIR_REG_WO_OR = 0x02011402ull;

static const uint32_t VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR = 0;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR = 1;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR = 2;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR = 3;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR = 4;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR = 5;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR = 6;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR = 7;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR = 8;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR = 9;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR = 10;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR = 11;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR = 12;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR = 13;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR = 14;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG = 15;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR = 16;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR = 17;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR = 18;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR = 19;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR = 20;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR = 21;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR = 22;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR = 23;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR = 24;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR = 25;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR = 26;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR = 27;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR = 28;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR = 29;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR = 30;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT = 31;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR = 32;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR = 33;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR = 34;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR = 35;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR = 36;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR = 37;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR = 38;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR = 39;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR = 40;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR = 41;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR = 42;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR = 43;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD = 44;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED = 45;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR = 46;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR = 47;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP = 48;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR = 49;
static const uint32_t VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR = 50;
// proc/reg00074.H

}
}
#include "proc/reg00071.H"
#include "proc/reg00072.H"
#include "proc/reg00073.H"
#include "proc/reg00074.H"
#endif
