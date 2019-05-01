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
// proc/reg00058.H

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
// proc/reg00058.H

static const uint64_t INT_CQ_SWI_CMD4 = 0x02010823ull;
// proc/reg00058.H

static const uint64_t INT_CQ_TAR = 0x0201080eull;

static const uint32_t INT_CQ_TAR_AUTO_INC = 0;
static const uint32_t INT_CQ_TAR_TABLE_SEL_0_3 = 12;
static const uint32_t INT_CQ_TAR_TABLE_SEL_0_3_LEN = 4;
static const uint32_t INT_CQ_TAR_ENTRY_SEL_0_3 = 28;
static const uint32_t INT_CQ_TAR_ENTRY_SEL_0_3_LEN = 4;
// proc/reg00058.H

static const uint64_t INT_CQ_TM_BAR = 0x02010809ull;

static const uint32_t INT_CQ_TM_BAR_VALID = 0;
static const uint32_t INT_CQ_TM_BAR_PAGE_SIZE_64K = 1;
static const uint32_t INT_CQ_TM_BAR_ADDR_8_49 = 8;
static const uint32_t INT_CQ_TM_BAR_ADDR_8_49_LEN = 42;
// proc/reg00058.H

static const uint64_t INT_PC_NXC_REGS_FATAL_ERR = 0x02010ad4ull;

static const uint32_t INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR = 0;
static const uint32_t INT_PC_NXC_REGS_FATAL_ERR_INT_PC_NXC_FATAL_ERR_ERROR_LEN = 64;
// proc/reg00058.H

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
// proc/reg00058.H

static const uint64_t INT_PC_NXC_REGS_WATCH3_DATA0 = 0x02010abcull;
// proc/reg00058.H

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
// proc/reg00058.H

static const uint64_t INT_VC_EASC_FLUSH_POLL = 0x02010961ull;

static const uint32_t INT_VC_EASC_FLUSH_POLL_BLOCKID = 0;
static const uint32_t INT_VC_EASC_FLUSH_POLL_BLOCKID_LEN = 4;
static const uint32_t INT_VC_EASC_FLUSH_POLL_OFFSET = 4;
static const uint32_t INT_VC_EASC_FLUSH_POLL_OFFSET_LEN = 28;
static const uint32_t INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK = 32;
static const uint32_t INT_VC_EASC_FLUSH_POLL_BLOCKID_MASK_LEN = 4;
static const uint32_t INT_VC_EASC_FLUSH_POLL_OFFSET_MASK = 36;
static const uint32_t INT_VC_EASC_FLUSH_POLL_OFFSET_MASK_LEN = 28;
// proc/reg00058.H

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
// proc/reg00058.H

static const uint64_t INT_VC_ENDC_WATCH0_DATA2 = 0x020109a6ull;
// proc/reg00058.H

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
// proc/reg00058.H

static const uint64_t INT_VC_END_BLOCK_MODE = 0x0201090aull;

static const uint32_t INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE = 0;
static const uint32_t INT_VC_END_BLOCK_MODE_INT_VC_END_BLOCK_MODE_LEN = 32;
// proc/reg00058.H

static const uint64_t INT_VC_ERR_CFG_G2R0 = 0x020109d0ull;

static const uint32_t INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG = 0;
static const uint32_t INT_VC_ERR_CFG_G2R0_INT_VC_ERR_CFG_G2R0_ERROR_CONFIG_LEN = 64;
// proc/reg00058.H

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
// proc/reg00058.H

static const uint64_t MM0_MM_CFG_NMMU_XLAT_CTL_REG2 = 0x02010c4cull;

static const uint32_t MM0_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR = 0;
static const uint32_t MM0_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR_LEN = 64;
// proc/reg00058.H

static const uint64_t MM0_MM_NMMU_ERR_INJ = 0x02010c58ull;

static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_DIR_EN = 2;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN = 3;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN = 4;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_DIR_MULT_SEL = 5;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_DIR_MULT_SEL_LEN = 3;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_CAC_EN = 8;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN = 9;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN = 10;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_CAC_MULT_SEL = 11;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_CAC_MULT_SEL_LEN = 3;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_LRU_EN = 14;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN = 15;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN = 16;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_LRU_MULT_SEL = 17;
static const uint32_t MM0_MM_NMMU_ERR_INJ_TLB_LRU_MULT_SEL_LEN = 3;
static const uint32_t MM0_MM_NMMU_ERR_INJ_PWC_DIR_EN = 20;
static const uint32_t MM0_MM_NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN = 21;
static const uint32_t MM0_MM_NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN = 22;
static const uint32_t MM0_MM_NMMU_ERR_INJ_PWC_DIR_MULT_SEL = 23;
static const uint32_t MM0_MM_NMMU_ERR_INJ_PWC_DIR_MULT_SEL_LEN = 3;
static const uint32_t MM0_MM_NMMU_ERR_INJ_PWC_CAC_EN = 26;
static const uint32_t MM0_MM_NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN = 27;
static const uint32_t MM0_MM_NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN = 28;
static const uint32_t MM0_MM_NMMU_ERR_INJ_PWC_CAC_MULT_SEL = 29;
static const uint32_t MM0_MM_NMMU_ERR_INJ_PWC_CAC_MULT_SEL_LEN = 3;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_DIR_EN = 34;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN = 35;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN = 36;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_DIR_MULT_SEL = 37;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_DIR_MULT_SEL_LEN = 3;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_CAC_EN = 40;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN = 41;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN = 42;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_CAC_MULT_SEL = 43;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_CAC_MULT_SEL_LEN = 3;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_LRU_EN = 46;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN = 47;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN = 48;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_LRU_MULT_SEL = 49;
static const uint32_t MM0_MM_NMMU_ERR_INJ_SLB_LRU_MULT_SEL_LEN = 3;
static const uint32_t MM0_MM_NMMU_ERR_INJ_CXT_DIR_EN = 52;
static const uint32_t MM0_MM_NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN = 53;
static const uint32_t MM0_MM_NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN = 54;
static const uint32_t MM0_MM_NMMU_ERR_INJ_CXT_DIR_MULT_SEL = 55;
static const uint32_t MM0_MM_NMMU_ERR_INJ_CXT_DIR_MULT_SEL_LEN = 3;
static const uint32_t MM0_MM_NMMU_ERR_INJ_CXT_CAC_EN = 58;
static const uint32_t MM0_MM_NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN = 59;
static const uint32_t MM0_MM_NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN = 60;
static const uint32_t MM0_MM_NMMU_ERR_INJ_CXT_CAC_MULT_SEL = 61;
static const uint32_t MM0_MM_NMMU_ERR_INJ_CXT_CAC_MULT_SEL_LEN = 3;
// proc/reg00058.H

static const uint64_t MM1_MM_CFG_NMMU_CTL_SM = 0x03010c52ull;

static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS = 0;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS_LEN = 12;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS = 12;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS_LEN = 8;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN = 20;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS = 21;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN = 24;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN = 26;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS = 31;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH = 32;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH_LEN = 8;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS = 40;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS = 41;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS = 42;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS = 43;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN = 44;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC = 45;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF = 46;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN = 51;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS = 52;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS = 53;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS = 54;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN = 55;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH = 56;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN = 58;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN = 59;
// proc/reg00058.H

static const uint64_t NX_CH4_ADDR_2_HASH_FUNCTION_REG = 0x02011143ull;

static const uint32_t NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_2_HASH_FUNCTION_REG_ADDRESS_2_HASH_FUNCTION_LEN = 64;
// proc/reg00058.H

static const uint64_t NX_CH4_GZIP_CONTROL_REG = 0x02011140ull;

static const uint32_t NX_CH4_GZIP_CONTROL_REG_DISABLE_NEAR_HISTORY = 0;
static const uint32_t NX_CH4_GZIP_CONTROL_REG_DISABLE_FAR_HISTORY = 1;
static const uint32_t NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_HASH_ACCESSES = 2;
static const uint32_t NX_CH4_GZIP_CONTROL_REG_DISABLE_EXTRA_FIFO_ACCESSES = 3;
static const uint32_t NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK = 8;
static const uint32_t NX_CH4_GZIP_CONTROL_REG_HASH_SIZE_MASK_LEN = 8;
// proc/reg00058.H

static const uint64_t NX_DMA_EFT_MAX_BYTE_CNT = 0x02011059ull;

static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT = 0;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT_LEN = 5;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT = 5;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_SRC_DDE_CNT_LEN = 8;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT = 13;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT_LEN = 8;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT = 21;
static const uint32_t NX_DMA_EFT_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT_LEN = 5;
// proc/reg00058.H

static const uint64_t NX_PBI_RNG_RESET = 0x020110e6ull;

static const uint32_t NX_PBI_RNG_RESET_RNG_RESET = 0;
// proc/reg00058.H

static const uint64_t PB_COM_ES3_HP_MODE1_NEXT = 0x0000038bull;

static const uint32_t PB_COM_ES3_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES3 = 0;
static const uint32_t PB_COM_ES3_HP_MODE1_NEXT_TM_MASTER_NEXT_ES3 = 1;
static const uint32_t PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES3 = 2;
static const uint32_t PB_COM_ES3_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES3 = 3;
static const uint32_t PB_COM_ES3_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES3 = 16;
static const uint32_t PB_COM_ES3_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES3 = 17;
static const uint32_t PB_COM_ES3_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES3 = 18;
static const uint32_t PB_COM_ES3_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES3 = 32;
static const uint32_t PB_COM_ES3_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES3 = 33;
static const uint32_t PB_COM_ES3_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES3 = 34;
// proc/reg00058.H

static const uint64_t PB_COM_ES3_SP_CMD_RATE = 0x000003abull;

static const uint32_t PB_COM_ES3_SP_CMD_RATE_0_ES3 = 0;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_0_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_1_ES3 = 8;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_1_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_2_ES3 = 16;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_2_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_3_ES3 = 24;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_3_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_4_ES3 = 32;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_4_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_5_ES3 = 40;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_5_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_6_ES3 = 48;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_6_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_7_ES3 = 56;
static const uint32_t PB_COM_ES3_SP_CMD_RATE_7_ES3_LEN = 8;
// proc/reg00058.H

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
// proc/reg00058.H

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
// proc/reg00058.H

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
// proc/reg00058.H

static const uint64_t PB_PTLSCOM10_PMU3_TLPM_COUNTER = 0x1001181eull;
// proc/reg00058.H

static const uint64_t PB_PTLSCOM10_PTL_FIR_WOF_REG = 0x10011808ull;

static const uint32_t PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF = 0;
static const uint32_t PB_PTLSCOM10_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN = 62;
// proc/reg00058.H

static const uint64_t PB_PTLSCOM23_PMU1_TLPM_COUNTER = 0x1101181cull;
// proc/reg00058.H

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
// proc/reg00058.H

static const uint64_t PB_PTLSCOM67_TL_LINK_SYN_23_REG = 0x13011813ull;
// proc/reg00058.H

static const uint64_t PB_PTLSCOM67_TRACE_CFG = 0x13011826ull;

static const uint32_t PB_PTLSCOM67_TRACE_CFG_0L_SEL = 0;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_0L_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_0R_SEL = 8;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_0R_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_1L_SEL = 16;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_1L_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_1R_SEL = 24;
static const uint32_t PB_PTLSCOM67_TRACE_CFG_1R_SEL_LEN = 8;
// proc/reg00058.H

static const uint64_t PB_BRIDGE_HCA_DECAY_0_CONTROL_REG = 0x03012411ull;

static const uint32_t PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_ENABLE = 0;
static const uint32_t PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY = 1;
static const uint32_t PB_BRIDGE_HCA_DECAY_0_CONTROL_REG_DELAY_LEN = 6;
// proc/reg00058.H

static const uint64_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG = 0x030120c4ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_START = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP = 1;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_PAUSE = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_STOP_ALT = 3;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_RESET = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_VALID = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE = 6;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TRIG_MARK_TYPE_LEN = 10;
// proc/reg00058.H

static const uint64_t PE0_PB_PBAIB_REGS_PRDSTKOVR_REG = 0x08010802ull;

static const uint32_t PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0 = 0;
static const uint32_t PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK0_LEN = 32;
static const uint32_t PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1 = 32;
static const uint32_t PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_STK1_LEN = 16;
static const uint32_t PE0_PB_PBAIB_REGS_PRDSTKOVR_REG_ENABLE = 48;
// proc/reg00058.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG = 0x0801084bull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0 = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN = 21;
// proc/reg00058.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_RW = 0x08010883ull;
static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_AND = 0x08010884ull;
static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_WO_OR = 0x08010885ull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PFIRMASK_REG_PFIRMASK_LEN = 6;
// proc/reg00058.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG = 0x02011800ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE_LEN = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE_LEN = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE = 8;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE_LEN = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT = 12;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE = 13;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE = 14;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK = 15;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE = 16;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING = 17;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING = 18;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE = 19;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION = 20;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS = 21;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE = 22;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START = 23;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START_LEN = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE = 27;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE_LEN = 2;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD = 30;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE = 32;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN = 33;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE = 34;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE_LEN = 2;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_NEW_FLOW_CACHE_INJECT = 36;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND = 37;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW = 38;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW = 39;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG = 41;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP = 42;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG = 43;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP = 44;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE = 45;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE = 46;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE_LEN = 3;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL = 50;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP = 51;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN = 52;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP = 53;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG = 54;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL = 55;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP = 56;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN = 57;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP = 58;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG = 59;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION = 60;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION = 61;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH = 62;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT = 63;
// proc/reg00058.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG = 0x02011894ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR0_EN = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_MMIO_BAR1_EN = 1;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_PHB_BAR_EN = 2;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_BARE_REG_INT_BAR_EN = 3;
// proc/reg00058.H

static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_ACT0_REG = 0x0801090eull;
// proc/reg00058.H

static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_RWX = 0x0801090bull;
static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_AND = 0x0801090cull;
static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_MASK_REG_WOX_OR = 0x0801090dull;
// proc/reg00058.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG = 0x090108cdull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA = 0;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR = 10;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR_LEN = 6;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA = 16;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR = 26;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR_LEN = 6;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA = 32;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR = 41;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR_LEN = 7;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA = 48;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR = 58;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR_LEN = 6;
// proc/reg00058.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3 = 0x0301180full;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3_LEN = 40;
// proc/reg00058.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG = 0x0301188full;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0_LEN = 40;
// proc/reg00058.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG = 0x03011897ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT
    = 1;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION =
    2;
static const uint32_t
PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD = 3;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION = 4;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT =
    5;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION = 6;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD
    = 7;
// proc/reg00058.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK = 0x00000907ull;

static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE = 12;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN = 40;
// proc/reg00058.H

static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK = 0x09010947ull;

static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE = 12;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN = 40;
// proc/reg00058.H

static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL = 0x09010998ull;
// proc/reg00058.H

static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP = 0x09010986ull;

static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE = 0;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE = 12;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN = 40;
// proc/reg00059.H

static const uint64_t TP_LPC_SYNC_FIR_MASK_REG_RW = 0x000201c3ull;
static const uint64_t TP_LPC_SYNC_FIR_MASK_REG_WO_AND = 0x000201c4ull;
static const uint64_t TP_LPC_SYNC_FIR_MASK_REG_WO_OR = 0x000201c5ull;

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
// proc/reg00059.H

static const uint64_t TP_TPBR_AD_PIB_CMD_REG = 0x03001c31ull;

static const uint32_t TP_TPBR_AD_PIB_CMD_REG_RNW = 0;
static const uint32_t TP_TPBR_AD_PIB_CMD_REG_ADR = 30;
static const uint32_t TP_TPBR_AD_PIB_CMD_REG_ADR_LEN = 31;
// proc/reg00059.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAFIRMASK_RW = 0x03021cc3ull;
static const uint64_t TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND = 0x03021cc4ull;
static const uint64_t TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR = 0x03021cc5ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_OCI_APAR_ERR_MASK = 0;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK = 1;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK = 2;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK = 3;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK = 5;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_OCI_SLAVE_INIT_MASK = 6;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_OCI_WRPAR_ERR_MASK = 7;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_8 = 8;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK = 9;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK = 10;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK = 11;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK = 12;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK = 13;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK = 14;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK = 15;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_SETUP_ERR_MASK = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK = 17;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK = 18;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_OCI_DATERR_MASK = 19;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SETUP_ERR_MASK = 20;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK = 21;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK = 22;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK = 23;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK = 24;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK = 25;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK = 26;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_OCI_DATERR_MASK = 27;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK = 28;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK = 29;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK = 30;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXPUSH_WRERR_MASK = 31;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK = 32;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK = 33;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK = 34;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK = 35;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK = 36;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK = 37;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK = 38;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVERR_MASK = 39;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK = 40;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_41_43 = 41;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_41_43_LEN = 3;
// proc/reg00059.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABAR3 = 0x03021c9dull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3 = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_ADDR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_ADDR_LEN = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_VTARGET = 48;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR3_VTARGET_LEN = 16;
// proc/reg00059.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABARMSK2 = 0x03021ca0ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK_LEN = 21;
// proc/reg00059.H

static const uint64_t TP_TPBR_PBA_PBAO_PBARBUFVAL3 = 0x03021c93ull;

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
// proc/reg00059.H

static const uint64_t TP_TPBR_PBA_PBAO_PBASLVRST = 0x00068001ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_SET = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_SET_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR_LEN = 2;
// proc/reg00059.H

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
// proc/reg00059.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT = 0x00068034ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_IN_PROGRESS = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_ERROR = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_WRITE_IN_PROGRESS = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_RESERVATION_SET = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_CAPTURE = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXIRCVSTAT_CAPTURE_LEN = 16;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXICTR = 0x00060032ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXICTR_OCB_OCI_GPEXICTR_CTR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXICTR_OCB_OCI_GPEXICTR_CTR_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR = 0x00060014ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL = 0x0006002bull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING = 3;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU = 0x0006002aull;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR30 = 0x00060087ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR30_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR30_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR30_1 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR30_1_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC = 0x0006201aull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_TAG_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_TAG_ADDR_LEN = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_ERR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_POPULATE_PENDING = 35;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_VALID = 36;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCAC_VALID_LEN = 4;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR7 = 0x00062047ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR7_OCB_OCI_GPEXIVDR6_GPR7 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR7_OCB_OCI_GPEXIVDR6_GPR7_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR6 = 0x00062083ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR6_6 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR6_6_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR6_7 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR6_7_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIEDR = 0x00064023ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIEDR_OCB_OCI_GPEXIRAMEDR_EDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIEDR_OCB_OCI_GPEXIRAMEDR_EDR_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR3 = 0x00064043ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR3_OCB_OCI_GPEXIVDR2_GPR3 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR3_OCB_OCI_GPEXIVDR2_GPR3_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR31 = 0x0006404full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR2 = 0x00064081ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR2_2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR2_2_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR2_3 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR2_3_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR30 = 0x0006604eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8 = 0x00066048ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR = 0x00066025ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR_LEN = 30;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISPRG0 = 0x00066022ull;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B = 0x0006c737ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B = 1;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SWD1B = 0x0006c738ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3 = 0x0006c238ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR_LEN = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK_LEN = 12;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3 = 0x0006c23aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0_LEN = 5;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0 = 0x0006c200ull;
// proc/reg00059.H

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
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW = 0x0006c0a3ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR = 0x0006c0a4ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR = 0x0006c0a5ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR1_RW = 0x0006c028ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR = 0x0006c029ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR = 0x0006c02aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_ROX = 0x0006c600ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WOX_CLEAR = 0x0006c601ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7 = 7;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0 = 0x0006c408ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4 = 0x0006c414ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2 = 0x0006c42aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6 = 0x0006c436ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR = 0x0006c550ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD_LEN = 17;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C2 = 0x0006c442ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD_LEN = 17;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR = 0x0006c558ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD_LEN = 17;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR = 0x0006c549ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD_LEN = 17;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR = 0x0006c56bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD_LEN = 17;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR = 0x0006c577ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD_LEN = 17;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR = 0x0006c569ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD_LEN = 17;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_ROX = 0x0006c660ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WOX_CLEAR = 0x0006c661ull;

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
// proc/reg00059.H

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
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITIR = 0x0006c5c0ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD_LEN = 23;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA = 0x0006c860ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA_LEN = 32;
// proc/reg00059.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA = 0x0006c850ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA_LEN = 32;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG = 0x0006c803ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_HWCTRL_ONGOING = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_RESERVED_1_3 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_RESERVED_1_3_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_HWCTRL_INVALID_NUMBER_OF_FRAMES = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_SPIPSS_ADC_STATUS_REG_HWCTRL_FSM_ERR = 7;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SCOM = 0x0006d031ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SCOM1 = 0x0006d032ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SCOM2 = 0x0006d033ull;

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
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0 = 0x0006d015ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA_LEN = 64;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3 = 0x0006d074ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR_LEN = 32;
// proc/reg00060.H

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
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OCC_SRAM_CTL_SRBV3 = 0x0006a007ull;

static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3 = 0;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3_LEN = 32;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1 = 0x00008001ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1_LEN = 64;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115 = 0x00008073ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115_LEN = 64;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122 = 0x0000807aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122_LEN = 64;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15 = 0x0000800full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15_LEN = 64;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22 = 0x00008016ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22_LEN = 64;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43 = 0x0000802bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43_LEN = 64;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74 = 0x0000804aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74_LEN = 64;
// proc/reg00060.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81 = 0x00008051ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81_LEN = 64;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD1_RW = 0x00001401ull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD1_FSI_SCRATCH_PAD1 = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD1_FSI_SCRATCH_PAD1_LEN = 32;
// proc/reg00060.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_0_RWX = 0x00002880ull;
// proc/reg00060.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_14_RWX = 0x0000288eull;
// proc/reg00060.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_6_RWX = 0x000028c6ull;
// proc/reg00060.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_10_RWX = 0x0000290aull;
// proc/reg00060.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_A_ROX = 0x00002822ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_A_RWX = 0x00050022ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A_LEN =
    32;
// proc/reg00060.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_B_ROX = 0x0005002eull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_B_RWX = 0x0000282eull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B =
    0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B_LEN
    = 32;
// proc/reg00060.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_RW = 0x00002813ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_ROOT_CTRL3_3_SPARE_SS_PLL_CONTROL = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_FILT0_PLL = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT0_PLL_RESET_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT0_PLL_BYPASS_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT0_PLL_TEST_EN_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_FILT1_PLL = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT1_PLL_RESET_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT1_PLL_BYPASS_EN_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT1_PLL_TEST_EN_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_ROOT_CTRL3_15_SPARE_PLL = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT2_PLL_RESET_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT2_PLL_BYPASS_EN_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT2_PLL_TEST_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_ROOT_CTRL3_19_SPARE = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT3_PLL_RESET_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT3_PLL_BYPASS_EN_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_FILT3_PLL_TEST_EN_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_ROOT_CTRL3_23_SPARE_PLL_CONTROL = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC = 31;
// proc/reg00060.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_COPY_RW = 0x00002913ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_WOX = 0x00002414ull;
// proc/reg00060.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INPUT = 0x000b0050ull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INPUT_0 = 0;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INPUT_1 = 1;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INPUT_2 = 2;
// proc/reg00060.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_CRSIS = 0x00020007ull;
// proc/reg00060.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RSIS = 0x0002000aull;
// proc/reg00060.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIM = 0x00020016ull;
// proc/reg00060.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIM = 0x00030009ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP6_FSI0 = 0x00003068ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP6_SCOMFSI0 = 0x00000c1aull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_RO = 0x000030ecull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP7_2_LEN = 3;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP4_WOX = 0x000034e0ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP4_GENERAL_RESET_4 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP4_ERROR_RESET_4 = 1;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP7_FSI0 = 0x0000344cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP7_SCOMFSI0 = 0x00000d13ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSSIEP0_FSI0 = 0x00003450ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSSIEP0_SCOMFSI0 = 0x00000d14ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCRSIM0 = 0x00000858ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SLBUS = 0x00000830ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SRSIC0 = 0x00000868ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MATRB0_FSI1 = 0x000031d8ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MATRB0_SCOMFSI1 = 0x00000c76ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDTRB0_FSI1 = 0x000031dcull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDTRB0_SCOMFSI1 = 0x00000c77ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX = 0x000030d8ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2 = 1;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1 = 0x00003034ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1 = 0x00000c0dull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SNML = 0x00000840ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SSISM = 0x00000810ull;
// proc/reg00060.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SSTAT = 0x00000814ull;
// proc/reg00060.H

static const uint64_t VAS_VA_EG_SCF_WCBSBAR = 0x02011440ull;

static const uint32_t VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR = 8;
static const uint32_t VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR_LEN = 33;
// proc/reg00060.H

static const uint64_t VAS_VA_RG_SCF_FIR_REG_RWX = 0x02011400ull;
static const uint64_t VAS_VA_RG_SCF_FIR_REG_WOX_AND = 0x02011401ull;
static const uint64_t VAS_VA_RG_SCF_FIR_REG_WOX_OR = 0x02011402ull;

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
// proc/reg00060.H

}
}
#include "proc/reg00058.H"
#include "proc/reg00059.H"
#include "proc/reg00060.H"
#endif
