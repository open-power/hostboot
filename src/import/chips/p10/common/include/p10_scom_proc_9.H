/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_9.H $       */
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

#ifndef __p10_scom_proc_9_H_
#define __p10_scom_proc_9_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_FIR_RWX = 0x02010830ull;
static const uint64_t INT_CQ_FIR_WOX_AND = 0x02010831ull;
static const uint64_t INT_CQ_FIR_WOX_OR = 0x02010832ull;

static const uint32_t INT_CQ_FIR_PI_ECC_CE = 0;
static const uint32_t INT_CQ_FIR_PI_ECC_UE = 1;
static const uint32_t INT_CQ_FIR_PI_ECC_SUE = 2;
static const uint32_t INT_CQ_FIR_PBDI_ECC_CE = 3;
static const uint32_t INT_CQ_FIR_PBDI_ECC_UE = 4;
static const uint32_t INT_CQ_FIR_PBDO_ECC_CE = 5;
static const uint32_t INT_CQ_FIR_PBDO_ECC_UE = 6;
static const uint32_t INT_CQ_FIR_AI_ECC_CE = 7;
static const uint32_t INT_CQ_FIR_AI_ECC_UE = 8;
static const uint32_t INT_CQ_FIR_UNSOLICITED_CRESP = 9;
static const uint32_t INT_CQ_FIR_UNSOLICITED_PBDATA = 10;
static const uint32_t INT_CQ_FIR_PC_CRD_PERR = 11;
static const uint32_t INT_CQ_FIR_PC_CRD_AVAIL_PERR = 12;
static const uint32_t INT_CQ_FIR_VC_CRD_PERR = 13;
static const uint32_t INT_CQ_FIR_VC_CRD_AVAIL_PERR = 14;
static const uint32_t INT_CQ_FIR_AIB_IN_CMD_CTL_PERR = 15;
static const uint32_t INT_CQ_FIR_AIB_IN_CMD_PERR = 16;
static const uint32_t INT_CQ_FIR_AIB_IN_DAT_CTL_PERR = 17;
static const uint32_t INT_CQ_FIR_PB_PARITY_ERROR = 18;
static const uint32_t INT_CQ_FIR_PB_RCMDX_CI_ERR1 = 19;
static const uint32_t INT_CQ_FIR_PB_RCMDX_CI_ERR2 = 20;
static const uint32_t INT_CQ_FIR_PB_RCMDX_CI_ERR3 = 21;
static const uint32_t INT_CQ_FIR_PB_RCMDX_CI_ERR4 = 22;
static const uint32_t INT_CQ_FIR_MRT_ERR_NOT_VALID = 23;
static const uint32_t INT_CQ_FIR_MRT_ERR_PSIZE = 24;
static const uint32_t INT_CQ_FIR_SCOM_S_ERR = 25;
static const uint32_t INT_CQ_FIR_TTT_INVALID = 26;
static const uint32_t INT_CQ_FIR_WRQ_OP_HANG = 27;
static const uint32_t INT_CQ_FIR_RDQ_OP_HANG = 28;
static const uint32_t INT_CQ_FIR_INTQ_OP_HANG = 29;
static const uint32_t INT_CQ_FIR_RDQ_DATA_HANG = 30;
static const uint32_t INT_CQ_FIR_STQ_DATA_HANG = 31;
static const uint32_t INT_CQ_FIR_LDQ_DATA_HANG = 32;
static const uint32_t INT_CQ_FIR_WRQ_BAD_CRESP = 33;
static const uint32_t INT_CQ_FIR_RDQ_BAD_CRESP = 34;
static const uint32_t INT_CQ_FIR_INTQ_BAD_CRESP = 35;
static const uint32_t INT_CQ_FIR_RDQ_ABORT_TRM = 36;
static const uint32_t INT_CQ_FIR_INTR_PROTOCOL = 37;
static const uint32_t INT_CQ_FIR_OP_TARGETED_SECURE_MEM = 38;
static const uint32_t INT_CQ_FIR_AIB_FENCE = 39;
static const uint32_t INT_CQ_FIR_CFG_REG_PERR = 40;
static const uint32_t INT_CQ_FIR_RESERVED_41 = 41;
static const uint32_t INT_CQ_FIR_CMD_QX_SEVERE_ERR = 42;
static const uint32_t INT_CQ_FIR_PC_FATAL_ERROR_0_3 = 43;
static const uint32_t INT_CQ_FIR_PC_FATAL_ERROR_0_3_LEN = 4;
static const uint32_t INT_CQ_FIR_PC_RECOV_ERROR_0_3 = 47;
static const uint32_t INT_CQ_FIR_PC_RECOV_ERROR_0_3_LEN = 4;
static const uint32_t INT_CQ_FIR_PC_INFO_ERROR_0_3 = 51;
static const uint32_t INT_CQ_FIR_PC_INFO_ERROR_0_3_LEN = 4;
static const uint32_t INT_CQ_FIR_VC_FATAL_ERROR_0_2 = 55;
static const uint32_t INT_CQ_FIR_VC_FATAL_ERROR_0_2_LEN = 3;
static const uint32_t INT_CQ_FIR_VC_RECOV_ERROR_0_2 = 58;
static const uint32_t INT_CQ_FIR_VC_RECOV_ERROR_0_2_LEN = 3;
static const uint32_t INT_CQ_FIR_VC_INFO_ERROR_0_2 = 61;
static const uint32_t INT_CQ_FIR_VC_INFO_ERROR_0_2_LEN = 3;
// proc/reg00035.H

static const uint64_t INT_CQ_PM_CTL = 0x02010827ull;

static const uint32_t INT_CQ_PM_CTL_ENABLE_0_7 = 0;
static const uint32_t INT_CQ_PM_CTL_ENABLE_0_7_LEN = 8;
static const uint32_t INT_CQ_PM_CTL_RESET_0_7 = 8;
static const uint32_t INT_CQ_PM_CTL_RESET_0_7_LEN = 8;
static const uint32_t INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1 = 16;
static const uint32_t INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1_LEN = 2;
static const uint32_t INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4 = 18;
static const uint32_t INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4_LEN = 5;
static const uint32_t INT_CQ_PM_CTL_RESERVED_23 = 23;
static const uint32_t INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7 = 24;
static const uint32_t INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7_LEN = 8;
// proc/reg00035.H

static const uint64_t INT_CQ_SWI_CMD5 = 0x02010824ull;
// proc/reg00035.H

static const uint64_t INT_PC_NXC_REGS_CONFIG = 0x02010a88ull;

static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_0_8 = 0;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_0_8_LEN = 9;
static const uint32_t INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD = 9;
static const uint32_t INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD_LEN = 3;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_12 = 12;
static const uint32_t INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD = 13;
static const uint32_t INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD_LEN = 3;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_16_17 = 16;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_16_17_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA = 18;
static const uint32_t INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_24_25 = 24;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_24_25_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE = 26;
static const uint32_t INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_32_33 = 32;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_32_33_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT = 34;
static const uint32_t INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_40 = 40;
static const uint32_t INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA = 41;
static const uint32_t INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA_LEN = 3;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_44_49 = 44;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_44_49_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH = 50;
static const uint32_t INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE = 52;
static const uint32_t INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_CONFIG_RESERVED_56 = 56;
static const uint32_t INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE = 57;
static const uint32_t INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED = 58;
static const uint32_t INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED_LEN = 6;
// proc/reg00035.H

static const uint64_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3 = 0x02010a9aull;

static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY = 0;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY = 8;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY = 12;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY = 16;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY = 20;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY = 24;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY = 28;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY = 32;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY = 36;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY = 40;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY = 44;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY = 48;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE = 52;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC = 56;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC = 60;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_LEN = 4;
// proc/reg00035.H

static const uint64_t INT_PC_NXC_REGS_WATCH3_DATA1 = 0x02010abdull;
// proc/reg00035.H

static const uint64_t INT_PC_REGS_DBG_PMC_ATX1 = 0x02010a36ull;

static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_0 = 0;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_0_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_1 = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_1_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_2 = 8;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_2_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_3 = 12;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_3_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_15 = 16;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_15_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_4R = 20;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_4R_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_4W = 24;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_4W_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_5 = 28;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_5_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_6 = 32;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_6_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_7 = 36;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_7_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_8 = 40;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_8_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_9 = 44;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_9_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_10 = 48;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_10_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_11 = 52;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_11_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_12 = 56;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_12_LEN = 4;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_13 = 60;
static const uint32_t INT_PC_REGS_DBG_PMC_ATX1_13_LEN = 4;
// proc/reg00035.H

static const uint64_t INT_VC_EASC_CFG = 0x02010968ull;

static const uint32_t INT_VC_EASC_CFG_RESERVED_16_25 = 16;
static const uint32_t INT_VC_EASC_CFG_RESERVED_16_25_LEN = 10;
static const uint32_t INT_VC_EASC_CFG_MAX_PTAG_IN_USE = 26;
static const uint32_t INT_VC_EASC_CFG_MAX_PTAG_IN_USE_LEN = 6;
// proc/reg00035.H

static const uint64_t INT_VC_EASC_FLUSH_INJECT = 0x02010962ull;

static const uint32_t INT_VC_EASC_FLUSH_INJECT_BLOCKID = 0;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_BLOCKID_LEN = 4;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_OFFSET = 4;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_OFFSET_LEN = 28;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK = 32;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK_LEN = 4;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK = 36;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK_LEN = 28;
// proc/reg00035.H

static const uint64_t INT_VC_EAS_BLOCK_MODE = 0x02010909ull;

static const uint32_t INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE = 0;
static const uint32_t INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE_LEN = 32;
// proc/reg00035.H

static const uint64_t INT_VC_ENDC_WATCH0_DATA3 = 0x020109a7ull;
// proc/reg00035.H

static const uint64_t INT_VC_ERR_CFG_G2R1 = 0x020109d1ull;

static const uint32_t INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG = 0;
static const uint32_t INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG_LEN = 64;
// proc/reg00035.H

static const uint64_t MCD_BANK0_TAU = 0x03010815ull;

static const uint32_t MCD_BANK0_TAU_VALID = 0;
static const uint32_t MCD_BANK0_TAU_CHIP_CONTAINED_MODE = 5;
static const uint32_t MCD_BANK0_TAU_SMF_ENABLE = 6;
static const uint32_t MCD_BANK0_TAU_GRP_SIZE = 11;
static const uint32_t MCD_BANK0_TAU_GRP_SIZE_LEN = 19;
static const uint32_t MCD_BANK0_TAU_GRP_BASE = 33;
static const uint32_t MCD_BANK0_TAU_GRP_BASE_LEN = 31;
// proc/reg00035.H

static const uint64_t MM0_MM_CFG_NMMU_CTL_SM = 0x02010c52ull;

static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS = 0;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS_LEN = 12;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS = 12;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS_LEN = 8;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN = 20;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS = 21;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN = 24;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN = 26;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS = 31;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH = 32;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH_LEN = 8;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS = 40;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS = 41;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS = 42;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS = 43;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN = 44;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC = 45;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF = 46;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN = 51;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS = 52;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS = 53;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS = 54;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN = 55;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH = 56;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN = 58;
static const uint32_t MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN = 59;
// proc/reg00035.H

static const uint64_t MM0_MM_FIR1_REG_RWX = 0x02010c40ull;
static const uint64_t MM0_MM_FIR1_REG_WOX_AND = 0x02010c41ull;
static const uint64_t MM0_MM_FIR1_REG_WOX_OR = 0x02010c42ull;

static const uint32_t MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET = 0;
static const uint32_t MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET = 1;
static const uint32_t MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET = 2;
static const uint32_t MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET = 3;
static const uint32_t MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET = 4;
static const uint32_t MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET = 5;
static const uint32_t MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET = 6;
static const uint32_t MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET = 7;
static const uint32_t MM0_MM_FIR1_REG_SLB_DIR_PERR_DET = 8;
static const uint32_t MM0_MM_FIR1_REG_SLB_CAC_PERR_DET = 9;
static const uint32_t MM0_MM_FIR1_REG_SLB_LRU_PERR_DET = 10;
static const uint32_t MM0_MM_FIR1_REG_SLB_MULTIHIT_DET = 11;
static const uint32_t MM0_MM_FIR1_REG_TLB_DIR_PERR_DET = 12;
static const uint32_t MM0_MM_FIR1_REG_TLB_CAC_PERR_DET = 13;
static const uint32_t MM0_MM_FIR1_REG_TLB_LRU_PERR_DET = 14;
static const uint32_t MM0_MM_FIR1_REG_TLB_MULTIHIT_DET = 15;
static const uint32_t MM0_MM_FIR1_REG_TW_SEG_FAULT_DET = 16;
static const uint32_t MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET = 17;
static const uint32_t MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET = 18;
static const uint32_t MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET = 19;
static const uint32_t MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET = 20;
static const uint32_t MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET = 21;
static const uint32_t MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET = 22;
static const uint32_t MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET = 23;
static const uint32_t MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET = 24;
static const uint32_t MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET = 25;
static const uint32_t MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET = 26;
static const uint32_t MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET = 27;
static const uint32_t MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET = 28;
static const uint32_t MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET = 29;
static const uint32_t MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET = 30;
static const uint32_t MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET = 31;
static const uint32_t MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET = 32;
static const uint32_t MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET = 33;
static const uint32_t MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET = 34;
static const uint32_t MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET = 35;
static const uint32_t MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET = 36;
static const uint32_t MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET = 37;
static const uint32_t MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET = 38;
static const uint32_t MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET = 39;
static const uint32_t MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET = 40;
static const uint32_t MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET = 41;
static const uint32_t MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET = 42;
static const uint32_t MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET = 43;
static const uint32_t MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET = 44;
static const uint32_t MM0_MM_FIR1_REG_SPARE = 45;
// proc/reg00035.H

static const uint64_t MM0_MM_FIR1_WOF_REG = 0x02010c48ull;
// proc/reg00035.H

static const uint64_t MM0_MM_NMMU_PMU1_CNT_REG = 0x02010c50ull;

static const uint32_t MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT = 0;
static const uint32_t MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN = 64;
// proc/reg00035.H

static const uint64_t MM1_MM_NMMU_PMU1_CNT_REG = 0x03010c50ull;

static const uint32_t MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT = 0;
static const uint32_t MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN = 64;
// proc/reg00035.H

static const uint64_t NX_DBG_DMA_ENG_FIR_MASK_SCOM = 0x02011103ull;
static const uint64_t NX_DBG_DMA_ENG_FIR_MASK_SCOM1 = 0x02011104ull;
static const uint64_t NX_DBG_DMA_ENG_FIR_MASK_SCOM2 = 0x02011105ull;

static const uint32_t NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS = 0;
static const uint32_t NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS_LEN = 48;
// proc/reg00035.H

static const uint64_t NX_PBI_UMAC_SU_ERAT_ERROR_RPT = 0x020110d7ull;

static const uint32_t NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT = 0;
static const uint32_t NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT_LEN = 51;
// proc/reg00035.H

static const uint64_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB = 0x020110c7ull;

static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID = 4;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN = 12;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID = 20;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID_LEN = 20;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID = 44;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID_LEN = 16;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE = 63;
// proc/reg00035.H

static const uint64_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR = 0x020110caull;

static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR = 8;
static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_LEN = 46;
static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE = 54;
static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN = 3;
// proc/reg00035.H

static const uint64_t PB_COM_ES3_EVENT_COMPB = 0x0000039cull;

static const uint32_t PB_COM_ES3_EVENT_COMPB_TTYPE_ES3 = 0;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TTYPE_ES3_LEN = 7;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3 = 7;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3_LEN = 7;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TSIZE_ES3 = 14;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TSIZE_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3 = 22;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TTAG_ES3 = 30;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TTAG_ES3_LEN = 10;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3 = 40;
static const uint32_t PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3_LEN = 10;
static const uint32_t PB_COM_ES3_EVENT_COMPB_CRESP_ES3 = 50;
static const uint32_t PB_COM_ES3_EVENT_COMPB_CRESP_ES3_LEN = 5;
static const uint32_t PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3 = 55;
static const uint32_t PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3_LEN = 5;
static const uint32_t PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3 = 60;
static const uint32_t PB_COM_ES3_EVENT_COMPB_SCOPE_ES3 = 61;
static const uint32_t PB_COM_ES3_EVENT_COMPB_SCOPE_ES3_LEN = 3;
// proc/reg00035.H

static const uint64_t PB_PTLSCOM10_PMU2_TLPM_COUNTER = 0x1001181dull;
// proc/reg00035.H

static const uint64_t PB_PTLSCOM10_TL_LINK_DLY_0123_REG = 0x1001180eull;
// proc/reg00035.H

static const uint64_t PB_PTLSCOM23_CFG_CNPM_REG = 0x1101181full;

static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_EN = 0;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE = 1;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS = 3;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE = 4;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE = 5;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP = 6;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP = 8;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP = 10;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP = 12;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP = 14;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP = 16;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP = 18;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP = 20;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP = 22;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP = 24;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP = 26;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP = 28;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP = 30;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP = 32;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP = 34;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP = 36;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0 = 38;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0_LEN = 3;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1 = 41;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1_LEN = 3;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2 = 44;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2_LEN = 3;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3 = 47;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3_LEN = 3;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_SPARE = 50;
static const uint32_t PB_PTLSCOM23_CFG_CNPM_REG_SPARE_LEN = 6;
// proc/reg00035.H

static const uint64_t PB_PTLSCOM23_PMU0_TLPM_COUNTER = 0x1101181bull;
// proc/reg00035.H

static const uint64_t PB_PTLSCOM45_TL_LINK_SYN_23_REG = 0x12011813ull;
// proc/reg00035.H

static const uint64_t PB_PTLSCOM67_PSAVE01_MODE_CFG = 0x13011814ull;

static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE = 0;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE = 5;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN = 8;
// proc/reg00035.H

static const uint64_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL = 0x030120c5ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG_LEN = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK_LEN = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP = 6;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP = 7;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP = 9;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012 = 10;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012_LEN = 3;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP = 13;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415 = 14;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415_LEN = 2;
// proc/reg00035.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG = 0x0801084dull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA_LEN = 3;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR = 10;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR_LEN = 6;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA = 16;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA_LEN = 3;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR = 26;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR_LEN = 6;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA = 32;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA_LEN = 3;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR = 41;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR_LEN = 7;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA = 48;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA_LEN = 3;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR = 58;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR_LEN = 6;
// proc/reg00035.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG = 0x0801088eull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A = 33;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A_LEN = 2;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R = 44;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R_LEN = 4;
// proc/reg00035.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG = 0x0801088aull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET = 0;
// proc/reg00035.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_RESERVED1_REG = 0x080108ccull;
// proc/reg00035.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG = 0x02011811ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE_LEN = 2;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE = 2;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES_LEN = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES = 8;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES_LEN = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES = 12;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES_LEN = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES = 16;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES_LEN = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES = 20;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES_LEN = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK = 24;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK_LEN = 4;
// proc/reg00035.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRWOF_REG = 0x02011848ull;
// proc/reg00035.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG = 0x02011857ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT
    = 1;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION =
    2;
static const uint32_t
PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD = 3;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT =
    5;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION = 6;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD
    = 7;
// proc/reg00035.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG = 0x02011893ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR_LEN = 28;
// proc/reg00035.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_RW = 0x02011883ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_AND = 0x02011884ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_OR = 0x02011885ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK_LEN = 28;
// proc/reg00035.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG = 0x020118ccull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE = 1;
// proc/reg00035.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG = 0x020118d2ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR_LEN = 42;
// proc/reg00035.H

static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP = 0x08010906ull;

static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE = 0;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE = 12;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN = 40;
// proc/reg00035.H

static const uint64_t PE0_PHB0_ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR = 0x08010913ull;
// proc/reg00035.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP = 0x00000946ull;

static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE = 0;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE = 12;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN = 40;
// proc/reg00035.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK = 0x00000987ull;

static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE = 12;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN = 40;
// proc/reg00035.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR = 0x00000982ull;

static const uint32_t PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD = 0;
static const uint32_t PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B = 1;
static const uint32_t PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC = 2;
static const uint32_t PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE = 51;
static const uint32_t PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN = 11;
// proc/reg00035.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG = 0x090108c8ull;
// proc/reg00035.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG = 0x03011809ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0_LEN = 16;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1 = 16;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1_LEN = 8;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE = 24;
// proc/reg00035.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2 = 0x0301180eull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2_LEN = 40;
// proc/reg00035.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG = 0x03011855ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN = 28;
// proc/reg00035.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_MMIOBAR1_MASK_REG = 0x030118d1ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN = 40;
// proc/reg00036.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE1_PHB0_ETUX16_RSB_REGS_ACTION1_REG = 0x0000090full;
// proc/reg00036.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL = 0x00000905ull;

static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE = 0;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE = 1;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE = 2;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE = 3;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE = 4;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE = 5;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE = 6;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE = 7;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE = 8;
// proc/reg00036.H

static const uint64_t PE1_PHB1_ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PAST = 0x09010955ull;
// proc/reg00036.H

static const uint64_t PE1_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR = 0x09010980ull;

static const uint32_t PE1_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD = 0;
static const uint32_t PE1_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B = 1;
static const uint32_t PE1_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC = 2;
static const uint32_t PE1_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE = 51;
static const uint32_t PE1_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE_LEN = 11;
// proc/reg00036.H

static const uint64_t PE1_PHB2_ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PAST = 0x09010995ull;
// proc/reg00036.H

static const uint64_t TP_TPBR_AD_LPC_BASE_REG = 0x03001c40ull;

static const uint32_t TP_TPBR_AD_LPC_BASE_REG_BASE = 8;
static const uint32_t TP_TPBR_AD_LPC_BASE_REG_BASE_LEN = 24;
static const uint32_t TP_TPBR_AD_LPC_BASE_REG_DISABLE = 63;
// proc/reg00036.H

static const uint64_t TP_TPBR_AD_RCV_ERRLOG0_REG = 0x03001c22ull;

static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_0 = 0;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_0_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_1 = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_1_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_2 = 16;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_2_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_3 = 24;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_3_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_4 = 32;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_4_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_5 = 40;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_5_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_6 = 48;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_6_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_7 = 56;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG0_REG_7_LEN = 8;
// proc/reg00036.H

static const uint64_t TP_TPBR_AD_RCV_ERRLOG1_REG = 0x03001c23ull;

static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_8 = 0;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_8_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_9 = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_9_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_10 = 16;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_10_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_11 = 24;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_11_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_12 = 32;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_12_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_13 = 40;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_13_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_14 = 48;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_14_LEN = 8;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_15 = 56;
static const uint32_t TP_TPBR_AD_RCV_ERRLOG1_REG_15_LEN = 8;
// proc/reg00036.H

static const uint64_t TP_TPBR_AD_XSCOM_MODE_REG = 0x03001c11ull;

static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_SPARE = 0;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_SPARE_LEN = 4;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_BAR_PIB_ON_ERROR1 = 4;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_BAR_PIB_ON_ERROR2 = 5;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_BAR_PIB_ON_ERROR3 = 6;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_BAR_PIB_ON_ERROR4 = 7;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_BAR_PIB_ON_ERROR5 = 8;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_BAR_PIB_ON_ERROR6 = 9;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_BAR_PIB_ON_ERROR7 = 10;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_HANG_PIB_RESET = 11;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_HANG_RESET = 12;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_RESET_ON_PARITY = 13;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_FREEZE_LOG_ON_ERROR1 = 14;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_FREEZE_LOG_ON_ERROR2 = 15;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_FREEZE_LOG_ON_ERROR3 = 16;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_FREEZE_LOG_ON_ERROR4 = 17;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_FREEZE_LOG_ON_ERROR5 = 18;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_FREEZE_LOG_ON_ERROR6 = 19;
static const uint32_t TP_TPBR_AD_XSCOM_MODE_REG_FREEZE_LOG_ON_ERROR7 = 20;
// proc/reg00036.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABAR2 = 0x03021c9cull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3 = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_ADDR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_ADDR_LEN = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_VTARGET = 48;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_VTARGET_LEN = 16;
// proc/reg00036.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABARMSK3 = 0x03021ca1ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK_LEN = 21;
// proc/reg00036.H

static const uint64_t TP_TPBR_PBA_PBAO_PBARBUFVAL2 = 0x03021c92ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR_LEN = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT = 31;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS = 33;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS_LEN = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID = 41;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID_LEN = 3;
// proc/reg00036.H

static const uint64_t TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM = 0x03011d0eull;
static const uint64_t TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1 = 0x03011d12ull;
static const uint64_t TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM2 = 0x03011d13ull;

static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE = 0;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE = 1;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE = 2;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE = 3;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE = 4;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE = 5;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET = 6;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET = 7;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK = 8;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK_LEN = 4;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE = 12;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT = 16;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT = 17;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE = 18;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE = 19;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE = 20;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING = 21;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING = 22;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY = 23;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR = 32;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS = 33;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT = 34;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT = 35;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR = 36;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR = 37;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR = 38;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE = 39;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR = 40;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1 = 41;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2 = 42;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR = 43;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR = 48;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR = 49;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT = 50;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP = 51;
static const uint32_t TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ = 52;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR = 0x0006d204ull;

static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_0_TIMEOUT_ERROR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_0_RW_STATUS = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_0_OESR_FLCK = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_0_OEAR_LOCK = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_1_TIMEOUT_ERROR = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_1_RW_STATUS = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_1_OESR_FLCK = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_1_OEAR_LOCK = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_2_TIMEOUT_ERROR = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_2_RW_STATUS = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_2_OESR_FLCK = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_2_OEAR_LOCK = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_3_TIMEOUT_ERROR = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_3_RW_STATUS = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_3_OESR_FLCK = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_3_OEAR_LOCK = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_4_TIMEOUT_ERROR = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_4_RW_STATUS = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_4_OESR_FLCK = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_4_OEAR_LOCK = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_5_TIMEOUT_ERROR = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_5_RW_STATUS = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_5_OESR_FLCK = 22;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_5_OEAR_LOCK = 23;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_6_TIMEOUT_ERROR = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_6_RW_STATUS = 25;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_6_OESR_FLCK = 26;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_6_OEAR_LOCK = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_7_TIMEOUT_ERROR = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_7_RW_STATUS = 29;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_7_OESR_FLCK = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OESR_7_OEAR_LOCK = 31;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGB = 0x00060018ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING = 35;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR = 0x00060021ull;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR = 0x00062001ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN = 23;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR = 0x00062004ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN = 2;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR6 = 0x00062046ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR6_OCB_OCI_GPEXIVDR6_GPR6 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR6_OCB_OCI_GPEXIVDR6_GPR6_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR30 = 0x00062087ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR30_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR30_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR30_1 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR30_1_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR = 0x00062010ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG = 0x00064002ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED12_15 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED12_15_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL_LEN = 4;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR2 = 0x00064042ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR2_OCB_OCI_GPEXIVDR2_GPR2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR2_OCB_OCI_GPEXIVDR2_GPR2_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR30 = 0x0006404eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISPRG0 = 0x00064022ull;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDRX = 0x00064085ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDRX_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDRX_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDRX_3 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDRX_3_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR31 = 0x0006604full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR9 = 0x00066049ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR9_OCB_OCI_GPEXIVDR8_GPR9 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR9_OCB_OCI_GPEXIVDR8_GPR9_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR8 = 0x00066084ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR8_8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR8_8_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR8_9 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR8_9_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_CMD = 0x0006c804ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING = 0;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B = 0x0006c716ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B__ONGOING_0B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B__WRITE_WHILE_BRIDGE_BUSY_ERR_0B = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B__FSM_ERR_0B = 7;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2 = 0x0006c228ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR_LEN = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK_LEN = 12;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2 = 0x0006c22aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0_LEN = 5;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1 = 0x0006c210ull;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0 = 0x0006c201ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE = 31;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT = 0x0006c086ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_ADCFSM_ONGOING = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_SPARE_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_PMC_O2S_0A_ONGOING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_PMC_O2S_0B_ONGOING = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_PMC_O2S_1A_ONGOING = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_PMC_O2S_1B_ONGOING = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_PMC_O2S_2A_ONGOING = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_PMC_O2S_2B_ONGOING = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_AVS_SLAVE0 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_AVS_SLAVE1 = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_AVS_SLAVE2 = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_SPARE_11 = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_DERP0_ONGOING = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_DERP1_ONGOING = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_DERP2_ONGOING = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSTAT_DERP3_ONGOING = 15;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW = 0x0006c0a0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR = 0x0006c0a1ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR = 0x0006c0a2ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR0_RW = 0x0006c008ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR = 0x0006c009ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR = 0x0006c00aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0_LEN = 32;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q4RR = 0x0006c504ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q4RR_OCB_OCI_OPIT0Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q4RR_OCB_OCI_OPIT0Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1 = 0x0006c409ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q4RR = 0x0006c50cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q4RR_OCB_OCI_OPIT1Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q4RR_OCB_OCI_OPIT1Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4RR = 0x0006c514ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4RR_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4RR_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q5 = 0x0006c415ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q5_OCB_OCI_OPIT2Q5RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q5_OCB_OCI_OPIT2Q5RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q4RR = 0x0006c51cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q4RR_OCB_OCI_OPIT3Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q4RR_OCB_OCI_OPIT3Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4RR = 0x0006c524ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4RR_OCB_OCI_OPIT4Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4RR_OCB_OCI_OPIT4Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q3 = 0x0006c42bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q3_OCB_OCI_OPIT5Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q3_OCB_OCI_OPIT5Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4RR = 0x0006c52cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4RR_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4RR_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q4RR = 0x0006c534ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q4RR_OCB_OCI_OPIT6Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q4RR_OCB_OCI_OPIT6Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7 = 0x0006c437ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7_OCB_OCI_OPIT6Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7_OCB_OCI_OPIT6Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00036.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4RR = 0x0006c53cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4RR_OCB_OCI_OPIT7Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4RR_OCB_OCI_OPIT7Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3 = 0x0006c443ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3_PAYLOAD_LEN = 17;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3RR = 0x0006c543ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3RR_PAYLOAD_LEN = 17;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29RR = 0x0006c57dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29RR_PAYLOAD_LEN = 17;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C3RR = 0x0006c563ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C3RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C3RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C3RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C3RR_PAYLOAD_LEN = 17;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1 = 0x0006c485ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1_7_LEN = 4;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SCOM = 0x0006d011ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SCOM1 = 0x0006d012ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SCOM2 = 0x0006d013ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1 = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_FSM_ERR = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2 = 15;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1 = 0x0006d035ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA_LEN = 64;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2 = 0x0006d054ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR_LEN = 32;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SCOM = 0x01010800ull;
static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SCOM1 = 0x01010801ull;
static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SCOM2 = 0x01010802ull;

static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_READ_ERROR = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_WRITE_ERROR = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_DATAOUT_PERR = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OCI_WRITE_DATA_PARITY = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OCI_BE_PARITY_ERR = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OCI_ADDR_PARITY_ERR = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED = 22;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED = 23;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED = 25;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP = 26;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET = 29;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK = 31;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_OCI_TIMEOUT = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_OCI_READ_DATA_PARITY = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_OCI_SLAVE_ERROR = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR = 35;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_PIB_DATA_PARITY_ERR = 36;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC0_ERROR = 37;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC1_ERROR = 38;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC2_ERROR = 39;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC3_ERROR = 40;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_FSM_ERR = 41;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR = 42;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR = 43;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE = 44;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE = 45;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK = 46;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR0 = 47;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR1 = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR2 = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR3 = 50;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR = 51;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR = 52;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR = 53;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR = 54;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT = 55;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT = 56;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT = 57;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY = 58;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61 = 59;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61_LEN = 3;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OCC_SRAM_CTL_SRBV2 = 0x0006a006ull;

static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2 = 0;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2_LEN = 32;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG0 = 0x00008000ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG0_REGISTER0 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG0_REGISTER0_LEN = 64;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG114 = 0x00008072ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG114_REGISTER114 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG114_REGISTER114_LEN = 64;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG123 = 0x0000807bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG123_REGISTER123 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG123_REGISTER123_LEN = 64;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG14 = 0x0000800eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG14_REGISTER14 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG14_REGISTER14_LEN = 64;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG23 = 0x00008017ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG23_REGISTER23 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG23_REGISTER23_LEN = 64;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG42 = 0x0000802aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG42_REGISTER42 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG42_REGISTER42_LEN = 64;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG75 = 0x0000804bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG75_REGISTER75 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG75_REGISTER75_LEN = 64;
// proc/reg00037.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG80 = 0x00008050ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG80_REGISTER80 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG80_REGISTER80_LEN = 64;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMMAND_REGISTER_RWX = 0x00001002ull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMMAND_REGISTER_CMD_REG = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMMAND_REGISTER_CMD_REG_LEN = 32;
// proc/reg00037.H

static const uint64_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_A_WOX = 0x00001804ull;
static const uint64_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_A_WOX_AND = 0x00001806ull;
static const uint64_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_A_WOX_OR = 0x00001805ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_A_INT_MASK_000 = 16;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_A_INT_MASK_000_LEN = 16;
// proc/reg00037.H

static const uint64_t TP_TPVSB_FSI_W_I2C_RESIDUAL_FRONT_END_BACK_LENGTH_A = 0x00001809ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_RESIDUAL_FRONT_END_BACK_LENGTH_A_RESID_FE_LEN_000 = 0;
static const uint32_t TP_TPVSB_FSI_W_I2C_RESIDUAL_FRONT_END_BACK_LENGTH_A_RESID_FE_LEN_000_LEN = 16;
// proc/reg00037.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_1_RWX = 0x00002881ull;
// proc/reg00037.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_15_RWX = 0x0000288full;
// proc/reg00037.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_7_RWX = 0x000028c7ull;
// proc/reg00037.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_11_RWX = 0x0000290bull;
// proc/reg00037.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR = 0x0000293bull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_PLL_BNDY_BYPASS_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_4_RESERVED = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_5_RESERVED = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_6_RESERVED = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_7_RESERVED = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_8_RESERVED = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_9_RESERVED = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_10_RESERVED = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_11_RESERVED = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_12_RESERVED = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_13_RESERVED = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_14_RESERVED = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_15_RESERVED = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_RESERVED = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_21_RESERVED = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_22_RESERVED = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_23_RESERVED = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_24_RESERVED = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CLK_PULSE_ENABLE_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CLK_PULSE_MODE_DC = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CLK_PULSE_MODE_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_28_RESERVED = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_29_RESERVED = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_30_RESERVED = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_PCB_PM_MUX_SEL_DC = 31;
// proc/reg00037.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW = 0x00002812ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_VREGDLY_SHUTOFF_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TC_HSSPORWREN_ALLOW = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_IO_VSB_OP0A_V1P8_EN = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_IO_VSB_OP0B_V1P8_EN = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_IO_VSB_OP3A_V1P8_EN = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_IO_VSB_OP3B_V1P8_EN = 31;
// proc/reg00037.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR = 0x00002933ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_ROOT_CTRL3_3_SPARE_SS_PLL_CONTROL = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_FILT0_PLL = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT0_PLL_RESET_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT0_PLL_BYPASS_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT0_PLL_TEST_EN_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_FILT1_PLL = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT1_PLL_RESET_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT1_PLL_BYPASS_EN_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT1_PLL_TEST_EN_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_ROOT_CTRL3_15_SPARE_PLL = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT2_PLL_RESET_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT2_PLL_BYPASS_EN_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT2_PLL_TEST_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_ROOT_CTRL3_19_SPARE = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT3_PLL_RESET_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT3_PLL_BYPASS_EN_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_FILT3_PLL_TEST_EN_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_ROOT_CTRL3_23_SPARE_PLL_CONTROL = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC = 31;
// proc/reg00037.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW = 0x00002917ull;
// proc/reg00037.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_ENABLE = 0x000b005dull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_ENABLE_0 = 0;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_ENABLE_1 = 1;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_ENABLE_2 = 2;
// proc/reg00037.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CMD_WRDAT = 0x00030000ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CMD_WRDAT_WRITE_NOT_READ = 0;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP7_FSI0 = 0x0000306cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP7_SCOMFSI0 = 0x00000c1bull;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_WO_CLEAR = 0x00003020ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_0_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_1_ENABLE = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_2_ENABLE = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_3_ENABLE = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_4_ENABLE = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_5_ENABLE = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_6_ENABLE = 6;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_7_ENABLE = 7;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_RO = 0x000030e8ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_2_LEN = 3;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP5_WOX = 0x000034e4ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP5_GENERAL_RESET_5 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP5_ERROR_RESET_5 = 1;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSCSB0_FSI0 = 0x000035d4ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSCSB0_SCOMFSI0 = 0x00000d75ull;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP6_FSI0 = 0x00003448ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP6_SCOMFSI0 = 0x00000d12ull;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCRSIS4 = 0x00000864ull;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP3_WOX = 0x000030dcull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP3_GENERAL_RESET_3 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP3_ERROR_RESET_3 = 1;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1 = 0x00003030ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1 = 0x00000c0cull;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCMBR = 0x0000084cull;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMBL = 0x00000838ull;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SSI2M = 0x00000828ull;
// proc/reg00037.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8 = 0x000004a8ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE = 8;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE = 12;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE = 16;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE = 20;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE = 24;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE = 28;
// proc/reg00037.H

static const uint64_t VAS_VA_RG_SCF_WRMON0BAR = 0x02011410ull;
// proc/reg00037.H

static const uint64_t VAS_VA_RG_SCF_WRMON4CMP = 0x02011424ull;
// proc/reg00037.H

static const uint64_t VAS_VA_RG_SCF_WRMON5WID = 0x0201141dull;
// proc/reg00037.H

}
}
#include "proc/reg00035.H"
#include "proc/reg00036.H"
#include "proc/reg00037.H"
#endif
