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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_proc_9_H_
#define __p10_scom_proc_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


static const uint64_t INT_CQ_FIR_RW = 0x02010830ull;
static const uint64_t INT_CQ_FIR_WO_AND = 0x02010831ull;
static const uint64_t INT_CQ_FIR_WO_OR = 0x02010832ull;

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
// proc/reg00043.H

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
// proc/reg00043.H

static const uint64_t INT_CQ_SWI_CMD5 = 0x02010824ull;
// proc/reg00043.H

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
// proc/reg00043.H

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
// proc/reg00043.H

static const uint64_t INT_PC_NXC_REGS_WATCH3_DATA1 = 0x02010abdull;
// proc/reg00043.H

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
// proc/reg00043.H

static const uint64_t INT_VC_DBG_ATX_ORDER_1 = 0x02010938ull;
// proc/reg00043.H

static const uint64_t INT_VC_EASC_CFG = 0x02010968ull;

static const uint32_t INT_VC_EASC_CFG_RESERVED_16_25 = 16;
static const uint32_t INT_VC_EASC_CFG_RESERVED_16_25_LEN = 10;
static const uint32_t INT_VC_EASC_CFG_MAX_PTAG_IN_USE = 26;
static const uint32_t INT_VC_EASC_CFG_MAX_PTAG_IN_USE_LEN = 6;
// proc/reg00043.H

static const uint64_t INT_VC_EASC_FLUSH_INJECT = 0x02010962ull;

static const uint32_t INT_VC_EASC_FLUSH_INJECT_BLOCKID = 0;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_BLOCKID_LEN = 4;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_OFFSET = 4;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_OFFSET_LEN = 28;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK = 32;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK_LEN = 4;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK = 36;
static const uint32_t INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK_LEN = 28;
// proc/reg00043.H

static const uint64_t INT_VC_EAS_BLOCK_MODE = 0x02010909ull;

static const uint32_t INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE = 0;
static const uint32_t INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE_LEN = 32;
// proc/reg00043.H

static const uint64_t INT_VC_ENDC_WATCH0_DATA3 = 0x020109a7ull;
// proc/reg00043.H

static const uint64_t INT_VC_ERR_CFG_G2R1 = 0x020109d1ull;

static const uint32_t INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG = 0;
static const uint32_t INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG_LEN = 64;
// proc/reg00043.H

static const uint64_t MCD_BANK0_TAU = 0x03010815ull;

static const uint32_t MCD_BANK0_TAU_VALID = 0;
static const uint32_t MCD_BANK0_TAU_CHIP_CONTAINED_MODE = 5;
static const uint32_t MCD_BANK0_TAU_SMF_ENABLE = 6;
static const uint32_t MCD_BANK0_TAU_GRP_SIZE = 11;
static const uint32_t MCD_BANK0_TAU_GRP_SIZE_LEN = 19;
static const uint32_t MCD_BANK0_TAU_GRP_BASE = 33;
static const uint32_t MCD_BANK0_TAU_GRP_BASE_LEN = 31;
// proc/reg00043.H

static const uint64_t NX_DBG_DMA_ENG_FIR_MASK_RW = 0x02011103ull;
static const uint64_t NX_DBG_DMA_ENG_FIR_MASK_WO_AND = 0x02011104ull;
static const uint64_t NX_DBG_DMA_ENG_FIR_MASK_WO_OR = 0x02011105ull;

static const uint32_t NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS = 0;
static const uint32_t NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS_LEN = 48;
// proc/reg00043.H

static const uint64_t NX_PBI_UMAC_SU_ERAT_ERROR_RPT = 0x020110d7ull;

static const uint32_t NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT = 0;
static const uint32_t NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT_LEN = 51;
// proc/reg00043.H

static const uint64_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB = 0x020110c7ull;

static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID = 4;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN = 12;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID = 20;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID_LEN = 20;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID = 44;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID_LEN = 16;
static const uint32_t NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE = 63;
// proc/reg00043.H

static const uint64_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR = 0x020110caull;

static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR = 8;
static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_LEN = 46;
static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE = 54;
static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN = 3;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EN1_EXTFIR_REG_RW = 0x0301122eull;
static const uint64_t PB_COM_SCOM_EN1_EXTFIR_REG_WO_AND = 0x0301122full;
static const uint64_t PB_COM_SCOM_EN1_EXTFIR_REG_WO_OR = 0x03011230ull;

static const uint32_t PB_COM_SCOM_EN1_EXTFIR_REG_0_FIR_ERR = 0;
static const uint32_t PB_COM_SCOM_EN1_EXTFIR_REG_1_FIR_ERR = 1;
static const uint32_t PB_COM_SCOM_EN1_EXTFIR_REG_2_FIR_ERR = 2;
static const uint32_t PB_COM_SCOM_EN1_EXTFIR_REG_3_FIR_ERR = 3;
static const uint32_t PB_COM_SCOM_EN1_EXTFIR_REG_4_FIR_ERR = 4;
static const uint32_t PB_COM_SCOM_EN1_EXTFIR_REG_5_FIR_ERR = 5;
static const uint32_t PB_COM_SCOM_EN1_EXTFIR_REG_6_FIR_ERR = 6;
static const uint32_t PB_COM_SCOM_EN1_EXTFIR_REG_7_FIR_ERR = 7;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EN2_EXTFIR_REG_RW = 0x0301126eull;
static const uint64_t PB_COM_SCOM_EN2_EXTFIR_REG_WO_AND = 0x0301126full;
static const uint64_t PB_COM_SCOM_EN2_EXTFIR_REG_WO_OR = 0x03011270ull;

static const uint32_t PB_COM_SCOM_EN2_EXTFIR_REG_0_FIR_ERR = 0;
static const uint32_t PB_COM_SCOM_EN2_EXTFIR_REG_1_FIR_ERR = 1;
static const uint32_t PB_COM_SCOM_EN2_EXTFIR_REG_2_FIR_ERR = 2;
static const uint32_t PB_COM_SCOM_EN2_EXTFIR_REG_3_FIR_ERR = 3;
static const uint32_t PB_COM_SCOM_EN2_EXTFIR_REG_4_FIR_ERR = 4;
static const uint32_t PB_COM_SCOM_EN2_EXTFIR_REG_5_FIR_ERR = 5;
static const uint32_t PB_COM_SCOM_EN2_EXTFIR_REG_6_FIR_ERR = 6;
static const uint32_t PB_COM_SCOM_EN2_EXTFIR_REG_7_FIR_ERR = 7;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT = 0x0301124bull;

static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_EN2 = 0;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_EN2 = 1;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_EN2 = 2;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_EN2 = 3;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_EN2 = 8;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_EN2_LEN = 8;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_EN2 = 16;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_EN2 = 17;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_EN2 = 18;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_EN2 = 24;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_EN2_LEN = 8;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_EN2 = 32;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_EN2 = 33;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_EN2 = 34;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_EN2 = 40;
static const uint32_t PB_COM_SCOM_EN2_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_EN2_LEN = 8;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EN2_STATION_MODE = 0x0301124aull;

static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_HOP_MODE_EN2 = 4;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_PUMP_MODE_EN2 = 5;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_REPRO_MODE_EN2 = 6;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_SL_DOMAIN_SIZE_EN2 = 7;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_REQ_GATHER_ENABLE_EN2 = 10;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_NHTM_EVENT_COMP_EN_EN2 = 11;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_SWITCH_OPTION_AB_EN2 = 12;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_SW_AB_WAIT_EN2 = 13;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_SW_AB_WAIT_EN2_LEN = 3;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_SP_HW_MARK_EN2 = 16;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_SP_HW_MARK_EN2_LEN = 7;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_GP_HW_MARK_EN2 = 23;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_GP_HW_MARK_EN2_LEN = 7;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_NP_HW_MARK_EN2 = 30;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_NP_HW_MARK_EN2_LEN = 6;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_MCA_RATIO_OVERRIDE_EN2 = 36;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_MCA_RATIO_OVERRIDE_EN2_LEN = 3;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_MCA_RATIO_SEL_EN2 = 42;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_MCA_RATIO_SEL_EN2_LEN = 2;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_PAU_STEP_OVERRIDE_EN2 = 44;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_PAU_STEP_SEL_EN2 = 45;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_PAU_STEP_SEL_EN2_LEN = 2;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_SWITCH_CD_GATE_ENABLE_EN2 = 47;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_TMGR_OP2_OVERLAP_DISABLE_EN2 = 52;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_TMGR_SERIES_ID_DISABLE_EN2 = 53;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_TMGR_TOKEN_ID_RANGE_EN2 = 54;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_TMGR_MAX_TLBI_TOKENS_EN2 = 55;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_TMGR_MAX_TLBI_TOKENS_EN2_LEN = 4;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_TMGR_MAX_SLBI_TOKENS_EN2 = 59;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_TMGR_MAX_SLBI_TOKENS_EN2_LEN = 4;
static const uint32_t PB_COM_SCOM_EN2_STATION_MODE_RESET_ERROR_CAPTURE_EN2 = 63;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EN3_EXTFIR_ACTION0_REG = 0x030112b4ull;

static const uint32_t PB_COM_SCOM_EN3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0 = 0;
static const uint32_t PB_COM_SCOM_EN3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0_LEN = 8;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EN3_EXTFIR_ACTION1_REG = 0x030112b5ull;

static const uint32_t PB_COM_SCOM_EN3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1 = 0;
static const uint32_t PB_COM_SCOM_EN3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1_LEN = 8;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_RW = 0x03011283ull;
static const uint64_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_WO_AND = 0x03011284ull;
static const uint64_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_WO_OR = 0x03011285ull;

static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK = 0;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK = 1;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK = 2;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK = 3;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK = 4;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK = 5;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK = 6;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK = 7;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK = 9;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK = 10;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK = 11;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK = 12;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK = 13;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK = 14;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_FIR_SPARE_15_MASK = 15;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK = 16;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK = 17;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK = 18;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK = 19;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK = 20;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK = 21;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE = 0x030112abull;

static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_0_EN3 = 0;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_0_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_1_EN3 = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_1_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_2_EN3 = 16;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_2_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_3_EN3 = 24;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_3_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_4_EN3 = 32;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_4_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_5_EN3 = 40;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_5_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_6_EN3 = 48;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_6_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_7_EN3 = 56;
static const uint32_t PB_COM_SCOM_EN3_STATION_SP_CMD_RATE_7_EN3_LEN = 8;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EN4_EXTFIR_REG_RW = 0x030112eeull;
static const uint64_t PB_COM_SCOM_EN4_EXTFIR_REG_WO_AND = 0x030112efull;
static const uint64_t PB_COM_SCOM_EN4_EXTFIR_REG_WO_OR = 0x030112f0ull;

static const uint32_t PB_COM_SCOM_EN4_EXTFIR_REG_0_FIR_ERR = 0;
static const uint32_t PB_COM_SCOM_EN4_EXTFIR_REG_1_FIR_ERR = 1;
static const uint32_t PB_COM_SCOM_EN4_EXTFIR_REG_2_FIR_ERR = 2;
static const uint32_t PB_COM_SCOM_EN4_EXTFIR_REG_3_FIR_ERR = 3;
static const uint32_t PB_COM_SCOM_EN4_EXTFIR_REG_4_FIR_ERR = 4;
static const uint32_t PB_COM_SCOM_EN4_EXTFIR_REG_5_FIR_ERR = 5;
static const uint32_t PB_COM_SCOM_EN4_EXTFIR_REG_6_FIR_ERR = 6;
static const uint32_t PB_COM_SCOM_EN4_EXTFIR_REG_7_FIR_ERR = 7;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ0_EXTFIR_REG_RW = 0x0301102eull;
static const uint64_t PB_COM_SCOM_EQ0_EXTFIR_REG_WO_AND = 0x0301102full;
static const uint64_t PB_COM_SCOM_EQ0_EXTFIR_REG_WO_OR = 0x03011030ull;

static const uint32_t PB_COM_SCOM_EQ0_EXTFIR_REG_0_FIR_ERR = 0;
static const uint32_t PB_COM_SCOM_EQ0_EXTFIR_REG_1_FIR_ERR = 1;
static const uint32_t PB_COM_SCOM_EQ0_EXTFIR_REG_2_FIR_ERR = 2;
static const uint32_t PB_COM_SCOM_EQ0_EXTFIR_REG_3_FIR_ERR = 3;
static const uint32_t PB_COM_SCOM_EQ0_EXTFIR_REG_4_FIR_ERR = 4;
static const uint32_t PB_COM_SCOM_EQ0_EXTFIR_REG_5_FIR_ERR = 5;
static const uint32_t PB_COM_SCOM_EQ0_EXTFIR_REG_6_FIR_ERR = 6;
static const uint32_t PB_COM_SCOM_EQ0_EXTFIR_REG_7_FIR_ERR = 7;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE = 0x0301102aull;

static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_0_EQ0 = 0;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_0_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_1_EQ0 = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_1_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_2_EQ0 = 16;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_2_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_3_EQ0 = 24;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_3_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_4_EQ0 = 32;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_4_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_5_EQ0 = 40;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_5_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_6_EQ0 = 48;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_6_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_7_EQ0 = 56;
static const uint32_t PB_COM_SCOM_EQ0_STATION_GP_CMD_RATE_7_EQ0_LEN = 8;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ2_STATION_CR_ERROR = 0x030110acull;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB = 0x0301109cull;

static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TTYPE_EQ2 = 0;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TTYPE_EQ2_LEN = 7;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TTYPE_MASK_EQ2 = 7;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TTYPE_MASK_EQ2_LEN = 7;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TSIZE_EQ2 = 14;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TSIZE_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TSIZE_MASK_EQ2 = 22;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TSIZE_MASK_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TTAG_EQ2 = 30;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TTAG_EQ2_LEN = 10;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TTAG_MASK_EQ2 = 40;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_TTAG_MASK_EQ2_LEN = 10;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_CRESP_EQ2 = 50;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_CRESP_EQ2_LEN = 5;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_CRESP_MASK_EQ2 = 55;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_CRESP_MASK_EQ2_LEN = 5;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_CRESP_POLARITY_EQ2 = 60;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_SCOPE_EQ2 = 61;
static const uint32_t PB_COM_SCOM_EQ2_STATION_EVENT_COMPB_SCOPE_EQ2_LEN = 3;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ2_STATION_MODE = 0x0301108aull;

static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_HOP_MODE_EQ2 = 4;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_PUMP_MODE_EQ2 = 5;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_REPRO_MODE_EQ2 = 6;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_SL_DOMAIN_SIZE_EQ2 = 7;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_REQ_GATHER_ENABLE_EQ2 = 10;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_NHTM_EVENT_COMP_EN_EQ2 = 11;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_SWITCH_OPTION_AB_EQ2 = 12;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_SW_AB_WAIT_EQ2 = 13;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_SW_AB_WAIT_EQ2_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_SP_HW_MARK_EQ2 = 16;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_SP_HW_MARK_EQ2_LEN = 7;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_GP_HW_MARK_EQ2 = 23;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_GP_HW_MARK_EQ2_LEN = 7;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_NP_HW_MARK_EQ2 = 30;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_NP_HW_MARK_EQ2_LEN = 6;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_MCA_RATIO_OVERRIDE_EQ2 = 36;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_MCA_RATIO_OVERRIDE_EQ2_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_MCA_RATIO_SEL_EQ2 = 42;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_MCA_RATIO_SEL_EQ2_LEN = 2;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_PAU_STEP_OVERRIDE_EQ2 = 44;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_PAU_STEP_SEL_EQ2 = 45;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_PAU_STEP_SEL_EQ2_LEN = 2;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_SWITCH_CD_GATE_ENABLE_EQ2 = 47;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_TMGR_OP2_OVERLAP_DISABLE_EQ2 = 52;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_TMGR_SERIES_ID_DISABLE_EQ2 = 53;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_TMGR_TOKEN_ID_RANGE_EQ2 = 54;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_TMGR_MAX_TLBI_TOKENS_EQ2 = 55;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_TMGR_MAX_TLBI_TOKENS_EQ2_LEN = 4;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_TMGR_MAX_SLBI_TOKENS_EQ2 = 59;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_TMGR_MAX_SLBI_TOKENS_EQ2_LEN = 4;
static const uint32_t PB_COM_SCOM_EQ2_STATION_MODE_RESET_ERROR_CAPTURE_EQ2 = 63;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ3_EXTFIR_REG_RW = 0x030110eeull;
static const uint64_t PB_COM_SCOM_EQ3_EXTFIR_REG_WO_AND = 0x030110efull;
static const uint64_t PB_COM_SCOM_EQ3_EXTFIR_REG_WO_OR = 0x030110f0ull;

static const uint32_t PB_COM_SCOM_EQ3_EXTFIR_REG_0_FIR_ERR = 0;
static const uint32_t PB_COM_SCOM_EQ3_EXTFIR_REG_1_FIR_ERR = 1;
static const uint32_t PB_COM_SCOM_EQ3_EXTFIR_REG_2_FIR_ERR = 2;
static const uint32_t PB_COM_SCOM_EQ3_EXTFIR_REG_3_FIR_ERR = 3;
static const uint32_t PB_COM_SCOM_EQ3_EXTFIR_REG_4_FIR_ERR = 4;
static const uint32_t PB_COM_SCOM_EQ3_EXTFIR_REG_5_FIR_ERR = 5;
static const uint32_t PB_COM_SCOM_EQ3_EXTFIR_REG_6_FIR_ERR = 6;
static const uint32_t PB_COM_SCOM_EQ3_EXTFIR_REG_7_FIR_ERR = 7;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT = 0x030110cdull;

static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_0_EN_NEXT_EQ3 = 0;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_1_EN_NEXT_EQ3 = 1;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_2_EN_NEXT_EQ3 = 2;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_3_EN_NEXT_EQ3 = 3;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_4_EN_NEXT_EQ3 = 4;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_5_EN_NEXT_EQ3 = 5;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_6_EN_NEXT_EQ3 = 6;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_7_EN_NEXT_EQ3 = 7;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_0_ADDR_DIS_NEXT_EQ3 = 8;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_1_ADDR_DIS_NEXT_EQ3 = 9;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_2_ADDR_DIS_NEXT_EQ3 = 10;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_3_ADDR_DIS_NEXT_EQ3 = 11;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_4_ADDR_DIS_NEXT_EQ3 = 12;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_5_ADDR_DIS_NEXT_EQ3 = 13;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_6_ADDR_DIS_NEXT_EQ3 = 14;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_7_ADDR_DIS_NEXT_EQ3 = 15;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_0_MODE_NEXT_EQ3 = 16;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_0_ID_NEXT_EQ3 = 17;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_0_ID_NEXT_EQ3_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_1_MODE_NEXT_EQ3 = 20;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_1_ID_NEXT_EQ3 = 21;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_1_ID_NEXT_EQ3_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_2_MODE_NEXT_EQ3 = 24;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_2_ID_NEXT_EQ3 = 25;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_2_ID_NEXT_EQ3_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_3_MODE_NEXT_EQ3 = 28;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_3_ID_NEXT_EQ3 = 29;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_3_ID_NEXT_EQ3_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_4_MODE_NEXT_EQ3 = 32;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_4_ID_NEXT_EQ3 = 33;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_4_ID_NEXT_EQ3_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_5_MODE_NEXT_EQ3 = 36;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_5_ID_NEXT_EQ3 = 37;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_5_ID_NEXT_EQ3_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_6_MODE_NEXT_EQ3 = 40;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_6_ID_NEXT_EQ3 = 41;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_6_ID_NEXT_EQ3_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_7_MODE_NEXT_EQ3 = 44;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_7_ID_NEXT_EQ3 = 45;
static const uint32_t PB_COM_SCOM_EQ3_STATION_HP_MODE2_NEXT_7_ID_NEXT_EQ3_LEN = 3;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB = 0x0301111cull;

static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TTYPE_EQ4 = 0;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TTYPE_EQ4_LEN = 7;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TTYPE_MASK_EQ4 = 7;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TTYPE_MASK_EQ4_LEN = 7;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TSIZE_EQ4 = 14;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TSIZE_EQ4_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TSIZE_MASK_EQ4 = 22;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TSIZE_MASK_EQ4_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TTAG_EQ4 = 30;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TTAG_EQ4_LEN = 10;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TTAG_MASK_EQ4 = 40;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_TTAG_MASK_EQ4_LEN = 10;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_CRESP_EQ4 = 50;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_CRESP_EQ4_LEN = 5;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_CRESP_MASK_EQ4 = 55;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_CRESP_MASK_EQ4_LEN = 5;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_CRESP_POLARITY_EQ4 = 60;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_SCOPE_EQ4 = 61;
static const uint32_t PB_COM_SCOM_EQ4_STATION_EVENT_COMPB_SCOPE_EQ4_LEN = 3;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ4_STATION_FIR_ACTION0_REG = 0x03011106ull;

static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0 = 0;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0_LEN = 22;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ4_STATION_FIR_ACTION1_REG = 0x03011107ull;

static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1 = 0;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1_LEN = 22;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ4_STATION_FIR_REG_RW = 0x03011100ull;
static const uint64_t PB_COM_SCOM_EQ4_STATION_FIR_REG_WO_AND = 0x03011101ull;
static const uint64_t PB_COM_SCOM_EQ4_STATION_FIR_REG_WO_OR = 0x03011102ull;

static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_PROTOCOL_ERROR = 0;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_OVERFLOW_ERROR = 1;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_HW_PARITY_ERROR = 2;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_FIR_SPARE_3 = 3;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_COHERENCY_ERROR = 4;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_CRESP_ADDR_ERROR = 5;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_CRESP_ERROR = 6;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_HANG_RECOVERY_LIMIT_ERROR = 7;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_FIR_SPARE_8 = 8;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_HANG_RECOVERY_GTE_LEVEL1 = 9;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_FORCE_MP_IPL = 10;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_PB_CMD_SNOOPER_ERROR = 11;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_DATA_OVERFLOW_ERROR = 12;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_DATA_PROTOCOL_ERROR = 13;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_DATA_ROUTE_ERROR = 14;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_FIR_SPARE_15 = 15;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_LINK0_PROTOCOL_ERROR = 16;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_LINK0_OVERFLOW_ERROR = 17;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_LINK0_HW_PARITY_ERROR = 18;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_LINK1_PROTOCOL_ERROR = 19;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_LINK1_OVERFLOW_ERROR = 20;
static const uint32_t PB_COM_SCOM_EQ4_STATION_FIR_REG_LINK1_HW_PARITY_ERROR = 21;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ5_EXTFIR_REG_RW = 0x0301116eull;
static const uint64_t PB_COM_SCOM_EQ5_EXTFIR_REG_WO_AND = 0x0301116full;
static const uint64_t PB_COM_SCOM_EQ5_EXTFIR_REG_WO_OR = 0x03011170ull;

static const uint32_t PB_COM_SCOM_EQ5_EXTFIR_REG_0_FIR_ERR = 0;
static const uint32_t PB_COM_SCOM_EQ5_EXTFIR_REG_1_FIR_ERR = 1;
static const uint32_t PB_COM_SCOM_EQ5_EXTFIR_REG_2_FIR_ERR = 2;
static const uint32_t PB_COM_SCOM_EQ5_EXTFIR_REG_3_FIR_ERR = 3;
static const uint32_t PB_COM_SCOM_EQ5_EXTFIR_REG_4_FIR_ERR = 4;
static const uint32_t PB_COM_SCOM_EQ5_EXTFIR_REG_5_FIR_ERR = 5;
static const uint32_t PB_COM_SCOM_EQ5_EXTFIR_REG_6_FIR_ERR = 6;
static const uint32_t PB_COM_SCOM_EQ5_EXTFIR_REG_7_FIR_ERR = 7;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ6_EXTFIR_REG_RW = 0x030111aeull;
static const uint64_t PB_COM_SCOM_EQ6_EXTFIR_REG_WO_AND = 0x030111afull;
static const uint64_t PB_COM_SCOM_EQ6_EXTFIR_REG_WO_OR = 0x030111b0ull;

static const uint32_t PB_COM_SCOM_EQ6_EXTFIR_REG_0_FIR_ERR = 0;
static const uint32_t PB_COM_SCOM_EQ6_EXTFIR_REG_1_FIR_ERR = 1;
static const uint32_t PB_COM_SCOM_EQ6_EXTFIR_REG_2_FIR_ERR = 2;
static const uint32_t PB_COM_SCOM_EQ6_EXTFIR_REG_3_FIR_ERR = 3;
static const uint32_t PB_COM_SCOM_EQ6_EXTFIR_REG_4_FIR_ERR = 4;
static const uint32_t PB_COM_SCOM_EQ6_EXTFIR_REG_5_FIR_ERR = 5;
static const uint32_t PB_COM_SCOM_EQ6_EXTFIR_REG_6_FIR_ERR = 6;
static const uint32_t PB_COM_SCOM_EQ6_EXTFIR_REG_7_FIR_ERR = 7;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE = 0x030111aaull;

static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_0_EQ6 = 0;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_0_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_1_EQ6 = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_1_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_2_EQ6 = 16;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_2_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_3_EQ6 = 24;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_3_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_4_EQ6 = 32;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_4_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_5_EQ6 = 40;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_5_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_6_EQ6 = 48;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_6_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_7_EQ6 = 56;
static const uint32_t PB_COM_SCOM_EQ6_STATION_GP_CMD_RATE_7_EQ6_LEN = 8;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_RW = 0x030111f1ull;
static const uint64_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_WO_AND = 0x030111f2ull;
static const uint64_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_WO_OR = 0x030111f3ull;

static const uint32_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_0_FIR_ERR_MASK = 0;
static const uint32_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_1_FIR_ERR_MASK = 1;
static const uint32_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_2_FIR_ERR_MASK = 2;
static const uint32_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_3_FIR_ERR_MASK = 3;
static const uint32_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_4_FIR_ERR_MASK = 4;
static const uint32_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_5_FIR_ERR_MASK = 5;
static const uint32_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_6_FIR_ERR_MASK = 6;
static const uint32_t PB_COM_SCOM_EQ7_EXTFIR_MASK_REG_7_FIR_ERR_MASK = 7;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT = 0x030111cbull;

static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_EQ7 = 0;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_EQ7 = 1;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_EQ7 = 2;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_EQ7 = 3;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_EQ7 = 8;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_EQ7_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_EQ7 = 16;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_EQ7 = 17;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_EQ7 = 18;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_EQ7 = 24;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_EQ7_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_EQ7 = 32;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_EQ7 = 33;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_EQ7 = 34;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_EQ7 = 40;
static const uint32_t PB_COM_SCOM_EQ7_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_EQ7_LEN = 8;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_RW = 0x03011303ull;
static const uint64_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_WO_AND = 0x03011304ull;
static const uint64_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_WO_OR = 0x03011305ull;

static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK = 0;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK = 1;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK = 2;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK = 3;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK = 4;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK = 5;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_CRESP_ERROR_MASK = 6;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK = 7;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK = 8;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK = 9;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK = 10;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK = 11;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK = 12;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK = 13;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK = 14;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_FIR_SPARE_15_MASK = 15;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK = 16;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK = 17;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK = 18;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK = 19;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK = 20;
static const uint32_t PB_COM_SCOM_ES1_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK = 21;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_ES2_STATION_CR_ERROR = 0x0301136cull;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA = 0x0301139bull;

static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TTYPE_ES3 = 0;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TTYPE_ES3_LEN = 7;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TTYPE_MASK_ES3 = 7;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TTYPE_MASK_ES3_LEN = 7;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TSIZE_ES3 = 14;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TSIZE_ES3_LEN = 8;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TSIZE_MASK_ES3 = 22;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TSIZE_MASK_ES3_LEN = 8;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TTAG_ES3 = 30;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TTAG_ES3_LEN = 10;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TTAG_MASK_ES3 = 40;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_TTAG_MASK_ES3_LEN = 10;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_CRESP_ES3 = 50;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_CRESP_ES3_LEN = 5;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_CRESP_MASK_ES3 = 55;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_CRESP_MASK_ES3_LEN = 5;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_CRESP_POLARITY_ES3 = 60;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_SCOPE_ES3 = 61;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPA_SCOPE_ES3_LEN = 3;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX = 0x0301139dull;

static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_A_SCOPE_MASK_ES3 = 0;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_A_SCOPE_MASK_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_A_PRESP_ES3 = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_A_PRESP_ES3_LEN = 14;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_A_PRESP_MASK_ES3 = 17;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_A_PRESP_MASK_ES3_LEN = 14;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_B_SCOPE_MASK_ES3 = 32;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_B_SCOPE_MASK_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_B_PRESP_ES3 = 35;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_B_PRESP_ES3_LEN = 14;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_B_PRESP_MASK_ES3 = 49;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_B_PRESP_MASK_ES3_LEN = 14;
static const uint32_t PB_COM_SCOM_ES3_STATION_EVENT_COMPX_AB_LPC_D_MODE_ES3 = 63;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR = 0x0301138eull;

static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_0_EN_CURR_ES3 = 0;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_1_EN_CURR_ES3 = 1;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_2_EN_CURR_ES3 = 2;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_3_EN_CURR_ES3 = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_4_EN_CURR_ES3 = 4;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_5_EN_CURR_ES3 = 5;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_6_EN_CURR_ES3 = 6;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_7_EN_CURR_ES3 = 7;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_0_ADDR_DIS_CURR_ES3 = 8;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_1_ADDR_DIS_CURR_ES3 = 9;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_2_ADDR_DIS_CURR_ES3 = 10;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_3_ADDR_DIS_CURR_ES3 = 11;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_4_ADDR_DIS_CURR_ES3 = 12;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_5_ADDR_DIS_CURR_ES3 = 13;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_6_ADDR_DIS_CURR_ES3 = 14;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_7_ADDR_DIS_CURR_ES3 = 15;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_0_MODE_CURR_ES3 = 16;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_0_ID_CURR_ES3 = 17;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_0_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_1_MODE_CURR_ES3 = 20;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_1_ID_CURR_ES3 = 21;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_1_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_2_MODE_CURR_ES3 = 24;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_2_ID_CURR_ES3 = 25;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_2_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_3_MODE_CURR_ES3 = 28;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_3_ID_CURR_ES3 = 29;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_3_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_4_MODE_CURR_ES3 = 32;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_4_ID_CURR_ES3 = 33;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_4_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_5_MODE_CURR_ES3 = 36;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_5_ID_CURR_ES3 = 37;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_5_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_6_MODE_CURR_ES3 = 40;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_6_ID_CURR_ES3 = 41;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_6_ID_CURR_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_7_MODE_CURR_ES3 = 44;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_7_ID_CURR_ES3 = 45;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_7_ID_CURR_ES3_LEN = 3;
// proc/reg00043.H

static const uint64_t PB_COM_SCOM_ES3_STATION_MODE = 0x0301138aull;

static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_ES3_PBIXXX_INIT = 0;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_ES3_DBG_MAX_HANG_STAGE_REACHED = 1;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_ES3_DBG_MAX_HANG_STAGE_REACHED_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_HOP_MODE_ES3 = 4;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_PUMP_MODE_ES3 = 5;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_REPRO_MODE_ES3 = 6;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_SL_DOMAIN_SIZE_ES3 = 7;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_HNG_CHK_DISABLE = 8;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_DBG_CLR_MAX_HANG_STAGE = 9;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_REQ_GATHER_ENABLE_ES3 = 10;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_NHTM_EVENT_COMP_EN_ES3 = 11;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_SWITCH_OPTION_AB_ES3 = 12;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_SW_AB_WAIT_ES3 = 13;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_SW_AB_WAIT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_SP_HW_MARK_ES3 = 16;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_SP_HW_MARK_ES3_LEN = 7;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_GP_HW_MARK_ES3 = 23;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_GP_HW_MARK_ES3_LEN = 7;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_NP_HW_MARK_ES3 = 30;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_NP_HW_MARK_ES3_LEN = 6;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_MCA_RATIO_OVERRIDE_ES3 = 36;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_MCA_RATIO_OVERRIDE_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_MCA_RATIO_SEL_ES3 = 42;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_MCA_RATIO_SEL_ES3_LEN = 2;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_PAU_STEP_OVERRIDE_ES3 = 44;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_PAU_STEP_SEL_ES3 = 45;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_PAU_STEP_SEL_ES3_LEN = 2;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_SWITCH_CD_GATE_ENABLE_ES3 = 47;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3 = 52;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_TMGR_SERIES_ID_DISABLE_ES3 = 53;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_TMGR_TOKEN_ID_RANGE_ES3 = 54;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_TMGR_MAX_TLBI_TOKENS_ES3 = 55;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_TMGR_MAX_TLBI_TOKENS_ES3_LEN = 4;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_TMGR_MAX_SLBI_TOKENS_ES3 = 59;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_TMGR_MAX_SLBI_TOKENS_ES3_LEN = 4;
static const uint32_t PB_COM_SCOM_ES3_STATION_MODE_CFG_RESET_ERROR_CAPTURE_ES3 = 63;
// proc/reg00043.H

static const uint64_t PB_PTLSCOM10_PMU2_TLPM_COUNTER = 0x1001181dull;
// proc/reg00043.H

static const uint64_t PB_PTLSCOM10_TL_LINK_DLY_0123_REG = 0x1001180eull;
// proc/reg00044.H

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
// proc/reg00044.H

static const uint64_t PB_PTLSCOM23_PMU0_TLPM_COUNTER = 0x1101181bull;
// proc/reg00044.H

static const uint64_t PB_PTLSCOM45_TL_LINK_SYN_23_REG = 0x12011813ull;
// proc/reg00044.H

static const uint64_t PB_PTLSCOM67_PSAVE01_MODE_CFG = 0x13011814ull;

static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE = 0;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE = 5;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN = 8;
// proc/reg00044.H

static const uint64_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL = 0x03011cc5ull;

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
// proc/reg00044.H

static const uint64_t PSI_MAC_SCOM_REGS_TX_CNTL = 0x03012c30ull;

static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_DRV_PATTERN_EN = 1;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_PATTERN_SEL = 2;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_PATTERN_SEL_LEN = 2;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_CLK_QUIESCE_P = 4;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_CLK_QUIESCE_P_LEN = 2;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_CLK_QUIESCE_N = 6;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_CLK_QUIESCE_N_LEN = 2;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_LANE_QUIESCE = 8;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_LANE_QUIESCE_LEN = 2;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_CLK_INVERT = 10;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_LANE_INVERT = 11;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_PDWN = 12;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_BIST_EN = 13;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_CNTL_SPARE = 24;
static const uint32_t PSI_MAC_SCOM_REGS_TX_CNTL_CNTL_SPARE_LEN = 8;
// proc/reg00044.H

static const uint64_t TP_TCN0_N0_BIST = 0x0203000bull;

static const uint32_t TP_TCN0_N0_BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t TP_TCN0_N0_BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t TP_TCN0_N0_BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t TP_TCN0_N0_BIST_BIST_PERV = 4;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT1 = 5;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT2 = 6;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT3 = 7;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT4 = 8;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT5 = 9;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT6 = 10;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT7 = 11;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT8 = 12;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT9 = 13;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT10 = 14;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT11 = 15;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT12 = 16;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT13 = 17;
static const uint32_t TP_TCN0_N0_BIST_BIST_UNIT14 = 18;
static const uint32_t TP_TCN0_N0_BIST_BIST_STROBE_WINDOW_EN = 48;
// proc/reg00044.H

static const uint64_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4 = 0x02040084ull;

static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_XSTOP_ERR = 0;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_RECOV_ERR = 1;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SPATTN_ERR = 2;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_LXSTOP_ERR = 3;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_HOSTATTN_ERR = 4;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SYS_XSTOP_ERR = 5;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SYS_XSTOP_STAGED_ERR = 6;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_DBG_TRIG_ERR = 7;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// proc/reg00044.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_DTS_TRC_RESULT = 0x02050003ull;

static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE = 0;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN = 44;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_DTS_TRC_RESULT_DTS_1_RESULT = 48;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_DTS_TRC_RESULT_DTS_1_RESULT_LEN = 16;
// proc/reg00044.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_ERR_STATUS_REG = 0x02050013ull;
// proc/reg00044.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA0 = 0x02050019ull;
// proc/reg00044.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x02050014ull;

static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// proc/reg00044.H

static const uint64_t TP_TCN0_N0_SPATTN_UNMASKED = 0x02040012ull;

static const uint32_t TP_TCN0_N0_SPATTN_UNMASKED_SPATTN_UNMASKED_IN = 1;
static const uint32_t TP_TCN0_N0_SPATTN_UNMASKED_SPATTN_UNMASKED_IN_LEN = 35;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_CPLT_CTRL2_RW = 0x03000002ull;
static const uint64_t TP_TCN1_N1_CPLT_CTRL2_WO_CLEAR = 0x03000022ull;
static const uint64_t TP_TCN1_N1_CPLT_CTRL2_WO_OR = 0x03000012ull;

static const uint32_t TP_TCN1_N1_CPLT_CTRL2_0_PGOOD = 4;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_1_PGOOD = 5;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_2_PGOOD = 6;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_3_PGOOD = 7;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_4_PGOOD = 8;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_5_PGOOD = 9;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_6_PGOOD = 10;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_7_PGOOD = 11;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_8_PGOOD = 12;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_9_PGOOD = 13;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_10_PGOOD = 14;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_11_PGOOD = 15;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_12_PGOOD = 16;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_13_PGOOD = 17;
static const uint32_t TP_TCN1_N1_CPLT_CTRL2_14_PGOOD = 18;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_CPLT_MASK0 = 0x03000101ull;

static const uint32_t TP_TCN1_N1_CPLT_MASK0_ITR_MASK = 0;
static const uint32_t TP_TCN1_N1_CPLT_MASK0_ITR_MASK_LEN = 32;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_EPS_PSC_WRITE_PROTECT_RINGS_REG = 0x03010006ull;

static const uint32_t TP_TCN1_N1_EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS = 0;
static const uint32_t TP_TCN1_N1_EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN = 32;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_HOSTATTN_UNMASKED = 0x03040014ull;

static const uint32_t TP_TCN1_N1_HOSTATTN_UNMASKED_HOSTATTN_UNMASKED_IN = 1;
static const uint32_t TP_TCN1_N1_HOSTATTN_UNMASKED_HOSTATTN_UNMASKED_IN_LEN = 53;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_LOCAL_FIR_RW = 0x03040100ull;
static const uint64_t TP_TCN1_N1_LOCAL_FIR_WO_AND = 0x03040101ull;
static const uint64_t TP_TCN1_N1_LOCAL_FIR_WO_OR = 0x03040102ull;

static const uint32_t TP_TCN1_N1_LOCAL_FIR_CFIR = 0;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL = 1;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_CC_PCB = 2;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_CC_OTHERS = 3;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN04 = 4;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN05 = 5;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN06 = 6;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN07 = 7;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN08 = 8;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN09 = 9;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN10 = 10;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN11 = 11;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN12 = 12;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN13 = 13;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN14 = 14;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN15 = 15;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN16 = 16;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN17 = 17;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN18 = 18;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN19 = 19;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN20 = 20;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN21 = 21;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN22 = 22;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN23 = 23;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN24 = 24;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN25 = 25;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN26 = 26;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN27 = 27;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN28 = 28;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN29 = 29;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN30 = 30;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN31 = 31;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN32 = 32;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN33 = 33;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN34 = 34;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN35 = 35;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN36 = 36;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN37 = 37;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN38 = 38;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN39 = 39;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN40 = 40;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN41 = 41;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN42 = 42;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN43 = 43;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN44 = 44;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN45 = 45;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN46 = 46;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN47 = 47;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN48 = 48;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN49 = 49;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN50 = 50;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN51 = 51;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN52 = 52;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN53 = 53;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN54 = 54;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN55 = 55;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN56 = 56;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN57 = 57;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN58 = 58;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN59 = 59;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN60 = 60;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN61 = 61;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_IN62 = 62;
static const uint32_t TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP = 63;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_SCAN_CAPTUREDR = 0x0303c000ull;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA1_TR0_CONFIG_0 = 0x03010483ull;

static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA1_TR1_CONFIG_9 = 0x030104c9ull;

static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA3_TR1_CONFIG_1 = 0x030105c4ull;

static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA4_TR0_TRACE_HI_DATA_REG = 0x03010600ull;

static const uint32_t TP_TCN1_N1_TRA4_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA4_TR0_CONFIG_9 = 0x03010609ull;

static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA4_TR1_CONFIG_0 = 0x03010643ull;

static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA6_TR0_CONFIG = 0x03010702ull;

static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA6_TR0_CONFIG_1 = 0x03010704ull;

static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_XSTOP4 = 0x03030014ull;

static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_MASK_B = 0;
static const uint32_t TP_TCN1_N1_XSTOP4_ALIGNED_XSTOP4 = 1;
static const uint32_t TP_TCN1_N1_XSTOP4_TRIGGER_OPCG_ON_XSTOP4 = 2;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_WAIT_ALLWAYS = 3;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_PERV = 4;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT1 = 5;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT2 = 6;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT3 = 7;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT4 = 8;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT5 = 9;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT6 = 10;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT7 = 11;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT8 = 12;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT9 = 13;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT10 = 14;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT11 = 15;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT12 = 16;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT13 = 17;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_UNIT14 = 18;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_WAIT_CYCLES = 48;
static const uint32_t TP_TCN1_N1_XSTOP4_XSTOP4_WAIT_CYCLES_LEN = 12;
// proc/reg00044.H

static const uint64_t TP_TPBR_AD_LPC_BASE_REG = 0x00090040ull;

static const uint32_t TP_TPBR_AD_LPC_BASE_REG_BASE = 8;
static const uint32_t TP_TPBR_AD_LPC_BASE_REG_BASE_LEN = 24;
static const uint32_t TP_TPBR_AD_LPC_BASE_REG_DISABLE = 63;
// proc/reg00044.H

static const uint64_t TP_TPBR_AD_RCV_ERRLOG0_REG = 0x00090022ull;
// proc/reg00044.H

static const uint64_t TP_TPBR_AD_XSCOM_MODE_REG = 0x00090011ull;

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
// proc/reg00044.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABAR2 = 0x01010cdcull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3 = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_ADDR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_ADDR_LEN = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_VTARGET = 48;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR2_VTARGET_LEN = 16;
// proc/reg00044.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABARMSK3 = 0x01010ce1ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK_LEN = 21;
// proc/reg00044.H

static const uint64_t TP_TPBR_PBA_PBAO_PBARBUFVAL2 = 0x01010cd2ull;

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
// proc/reg00044.H

static const uint64_t TP_TPBR_PSIHB_STATUS_CTL_REG = 0x03011d0eull;
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
// proc/reg00044.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_CTRL0_RW = 0x020f0040ull;
static const uint64_t TP_TPCHIP_NET_PCBSLN0_CTRL0_RW_WAND = 0x020f0041ull;
static const uint64_t TP_TPCHIP_NET_PCBSLN0_CTRL0_RW_WOR = 0x020f0042ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_CHIPLET_ENABLE = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_PCB_EP_RESET = 1;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_CLK_ASYNC_RESET = 2;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_PLL_TEST_EN = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_PLL_RESET = 4;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_PLL_BYPASS = 5;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_VITAL_SCAN = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_VITAL_SCAN_IN = 7;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_VITAL_PHASE = 8;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_FLUSH_ALIGN_OVR = 9;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_VITAL_AL = 10;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_ACT_DIS = 11;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_TOADMODE_EN = 12;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_SYNC_PULSE = 13;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_MPW3 = 14;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_DELAY_LCLKR = 15;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_VITAL_THOLD = 16;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_FLUSH_SCAN_N = 17;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_FENCE_EN = 18;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_CPLT_RCTRL = 19;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_CPLT_DCTRL = 20;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_CPLT_RCTRL2 = 21;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_ADJ_FUNC_CLKSEL = 22;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_FUNC_LCB_EDIS = 24;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_TP_FENCE_PCB = 25;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_LVLTRANS_FENCE = 26;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_ARRAY_WRITE_ASSIST_EN = 27;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_HTB_INTEST = 28;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_HTB_EXTEST = 29;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_CTRL0_PLLFORCE_OUT_EN = 31;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_PRIMARY_ADDRESS_REG = 0x020f0000ull;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_CTRL0_RW = 0x030f0040ull;
static const uint64_t TP_TPCHIP_NET_PCBSLN1_CTRL0_RW_WAND = 0x030f0041ull;
static const uint64_t TP_TPCHIP_NET_PCBSLN1_CTRL0_RW_WOR = 0x030f0042ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_CHIPLET_ENABLE = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_PCB_EP_RESET = 1;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_CLK_ASYNC_RESET = 2;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_PLL_TEST_EN = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_PLL_RESET = 4;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_PLL_BYPASS = 5;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_VITAL_SCAN = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_VITAL_SCAN_IN = 7;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_VITAL_PHASE = 8;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_FLUSH_ALIGN_OVR = 9;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_VITAL_AL = 10;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_ACT_DIS = 11;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_TOADMODE_EN = 12;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_SYNC_PULSE = 13;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_MPW3 = 14;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_DELAY_LCLKR = 15;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_VITAL_THOLD = 16;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_FLUSH_SCAN_N = 17;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_FENCE_EN = 18;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_CPLT_RCTRL = 19;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_CPLT_DCTRL = 20;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_CPLT_RCTRL2 = 21;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_ADJ_FUNC_CLKSEL = 22;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_FUNC_LCB_EDIS = 24;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_TP_FENCE_PCB = 25;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_LVLTRANS_FENCE = 26;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_ARRAY_WRITE_ASSIST_EN = 27;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_HTB_INTEST = 28;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_HTB_EXTEST = 29;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_CTRL0_PLLFORCE_OUT_EN = 31;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_LXSTOP_INTERRUPT_REG = 0x010f002aull;
// proc/reg00044.H

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
// proc/reg00044.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPESWPR0 = 0x00060005ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPESWPR0_BAR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPESWPR0_BAR_LEN = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPESWPR0_SIZE = 44;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPESWPR0_SIZE_LEN = 15;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGB = 0x00060018ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING = 35;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR = 0x00060021ull;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR = 0x00062001ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN = 23;
// proc/reg00044.H

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
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE = 12;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR6 = 0x00062046ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR6_OCB_OCI_GPEXIVDR6_GPR6 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR6_OCB_OCI_GPEXIVDR6_GPR6_LEN = 32;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR30 = 0x00062087ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR30_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR30_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR30_1 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR30_1_LEN = 32;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR = 0x00062010ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR_LEN = 32;
// proc/reg00044.H

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
// proc/reg00044.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR2 = 0x00064042ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR2_OCB_OCI_GPEXIVDR2_GPR2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR2_OCB_OCI_GPEXIVDR2_GPR2_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR30 = 0x0006404eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISPRG0 = 0x00064022ull;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDRX = 0x00064085ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDRX_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDRX_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDRX_3 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDRX_3_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR31 = 0x0006604full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR9 = 0x00066049ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR9_OCB_OCI_GPEXIVDR8_GPR9 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR9_OCB_OCI_GPEXIVDR8_GPR9_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR8 = 0x00066084ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR8_8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR8_8_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR8_9 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR8_9_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_CMD = 0x0006c804ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING = 0;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B = 0x0006c716ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B__ONGOING_0B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B__WRITE_WHILE_BRIDGE_BUSY_ERR_0B = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST0B__FSM_ERR_0B = 7;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2 = 0x0006c228ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR_LEN = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK_LEN = 12;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2 = 0x0006c22aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0_LEN = 5;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1 = 0x0006c210ull;
// proc/reg00045.H

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
// proc/reg00045.H

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
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW = 0x0006c0a0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR = 0x0006c0a1ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR = 0x0006c0a2ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR0_RW = 0x0006c008ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR = 0x0006c009ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR = 0x0006c00aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q4RR = 0x0006c504ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q4RR_OCB_OCI_OPIT0Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q4RR_OCB_OCI_OPIT0Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1 = 0x0006c409ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q4RR = 0x0006c50cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q4RR_OCB_OCI_OPIT1Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q4RR_OCB_OCI_OPIT1Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4RR = 0x0006c514ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4RR_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4RR_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q5 = 0x0006c415ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q5_OCB_OCI_OPIT2Q5RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q5_OCB_OCI_OPIT2Q5RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q4RR = 0x0006c51cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q4RR_OCB_OCI_OPIT3Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q4RR_OCB_OCI_OPIT3Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4RR = 0x0006c524ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4RR_OCB_OCI_OPIT4Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4RR_OCB_OCI_OPIT4Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q3 = 0x0006c42bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q3_OCB_OCI_OPIT5Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q3_OCB_OCI_OPIT5Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4RR = 0x0006c52cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4RR_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4RR_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q4RR = 0x0006c534ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q4RR_OCB_OCI_OPIT6Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q4RR_OCB_OCI_OPIT6Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7 = 0x0006c437ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7_OCB_OCI_OPIT6Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7_OCB_OCI_OPIT6Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4RR = 0x0006c53cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4RR_OCB_OCI_OPIT7Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4RR_OCB_OCI_OPIT7Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3 = 0x0006c443ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3_PAYLOAD_LEN = 17;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3RR = 0x0006c543ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C3RR_PAYLOAD_LEN = 17;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29RR = 0x0006c57dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29RR_PAYLOAD_LEN = 17;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C3RR = 0x0006c563ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C3RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C3RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C3RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C3RR_PAYLOAD_LEN = 17;
// proc/reg00045.H

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
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO = 0x0006d011ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR = 0x0006d012ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR = 0x0006d013ull;

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
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1 = 0x0006d035ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2 = 0x0006d054ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW = 0x01010800ull;
static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND = 0x01010801ull;
static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR = 0x01010802ull;

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
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR = 22;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR = 23;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP = 26;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET = 29;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK = 31;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR = 35;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_36_41 = 36;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_36_41_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR = 42;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR = 43;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE = 44;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE = 45;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK = 46;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR = 47;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50 = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50_LEN = 2;
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
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_SRAM_CTL_SRBV2 = 0x0006a006ull;

static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2 = 0;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG0 = 0x00008000ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG0_REGISTER0 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG0_REGISTER0_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG114 = 0x00008072ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG114_REGISTER114 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG114_REGISTER114_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG123 = 0x0000807bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG123_REGISTER123 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG123_REGISTER123_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG14 = 0x0000800eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG14_REGISTER14 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG14_REGISTER14_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG23 = 0x00008017ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG23_REGISTER23 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG23_REGISTER23_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG42 = 0x0000802aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG42_REGISTER42 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG42_REGISTER42_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG75 = 0x0000804bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG75_REGISTER75 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG75_REGISTER75_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG80 = 0x00008050ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG80_REGISTER80 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG80_REGISTER80_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL5_RW = 0x01000005ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL5_WO_CLEAR = 0x01000025ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL5_WO_OR = 0x01000015ull;

static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_0 = 0;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_1 = 1;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_2 = 2;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_3 = 3;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_4 = 4;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_5 = 5;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_6 = 6;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_7 = 7;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_8 = 8;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_9 = 9;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_10 = 10;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_11 = 11;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_12 = 12;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_13 = 13;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_14 = 14;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_15 = 15;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_16 = 16;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_17 = 17;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_18 = 18;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_19 = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT = 0x01060055ull;

static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT = 1;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT = 12;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE = 60;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE = 61;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE = 62;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK = 63;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK = 0x01010002ull;

static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_UL_P0_ERROR = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_GENERAL_TIMEOUT = 15;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_EPS_THERM_WSUB_CONTROL_REG = 0x01050012ull;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_ITR_FMU_OSC_CNTR1_REG = 0x01020001ull;

static const uint32_t TP_TPCHIP_TPC_ITR_FMU_OSC_CNTR1_REG_RESULT_AVAILABLE = 3;
static const uint32_t TP_TPCHIP_TPC_ITR_FMU_OSC_CNTR1_REG_OSC_PULSE1_CNTR = 4;
static const uint32_t TP_TPCHIP_TPC_ITR_FMU_OSC_CNTR1_REG_OSC_PULSE1_CNTR_LEN = 24;
// proc/reg00046.H

static const uint64_t TP_TPCHIP_TPC_ITR_FMU_OSC_CNTR2_REG = 0x01020002ull;

static const uint32_t TP_TPCHIP_TPC_ITR_FMU_OSC_CNTR2_REG_RESULT_AVAILABLE = 3;
static const uint32_t TP_TPCHIP_TPC_ITR_FMU_OSC_CNTR2_REG_OSC_PULSE2_CNTR = 4;
static const uint32_t TP_TPCHIP_TPC_ITR_FMU_OSC_CNTR2_REG_OSC_PULSE2_CNTR_LEN = 24;
// proc/reg00046.H

static const uint64_t TP_TPCHIP_TPC_SCAN_UPDATEDR = 0x0103a000ull;
// proc/reg00046.H

static const uint64_t TP_TPCHIP_TPC_SPATTN = 0x01040002ull;

static const uint32_t TP_TPCHIP_TPC_SPATTN_ANY_SPATTN = 0;
static const uint32_t TP_TPCHIP_TPC_SPATTN_RESERVED1S = 1;
static const uint32_t TP_TPCHIP_TPC_SPATTN_RESERVED2S = 2;
static const uint32_t TP_TPCHIP_TPC_SPATTN_RESERVED3S = 3;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_PERV = 4;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN05 = 5;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN06 = 6;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN07 = 7;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN08 = 8;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN09 = 9;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN10 = 10;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN11 = 11;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN12 = 12;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN13 = 13;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN14 = 14;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN15 = 15;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN16 = 16;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN17 = 17;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN18 = 18;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN19 = 19;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN20 = 20;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN21 = 21;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN22 = 22;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN23 = 23;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN24 = 24;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN25 = 25;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN26 = 26;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN27 = 27;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN28 = 28;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN29 = 29;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN30 = 30;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN31 = 31;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN32 = 32;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN33 = 33;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN34 = 34;
static const uint32_t TP_TPCHIP_TPC_SPATTN_SPATTN_IN35 = 35;
// proc/reg00046.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG = 0x01010402ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// proc/reg00046.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9 = 0x01010409ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00046.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_0 = 0x01010443ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMMAND_REGISTER_FSI = 0x00001002ull;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMMAND_REGISTER_FSI_BYTE = 0x00001008ull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMMAND_REGISTER_CMD_REG = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMMAND_REGISTER_CMD_REG_LEN = 32;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_A_WO = 0x00001804ull;
static const uint64_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_A_WO_AND = 0x00001806ull;
static const uint64_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_A_WO_OR = 0x00001805ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_A_INT_MASK_000 = 16;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_A_INT_MASK_000_LEN = 16;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_I2C_RESIDUAL_FRONT_END_BACK_LENGTH_A = 0x00001809ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_RESIDUAL_FRONT_END_BACK_LENGTH_A_RESID_FE_LEN_000 = 0;
static const uint32_t TP_TPVSB_FSI_W_I2C_RESIDUAL_FRONT_END_BACK_LENGTH_A_RESID_FE_LEN_000_LEN = 16;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_1_FSI = 0x00002881ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_1_FSI_BYTE = 0x00002a04ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_1_RW = 0x00050081ull;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_15_FSI = 0x0000288full;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_15_FSI_BYTE = 0x00002a3cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_15_RW = 0x0005008full;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_7_FSI = 0x000028c7ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_7_FSI_BYTE = 0x00002b1cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_7_RW = 0x000500c7ull;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_11_FSI = 0x0000290bull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_11_FSI_BYTE = 0x00002c2cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_11_RW = 0x0005010bull;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI = 0x0000293bull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE = 0x00002cecull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR = 0x0005013bull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_RESERVED = 3;
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
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_25_RESERVED = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_26_27_RESERVED = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_26_27_RESERVED_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_28_RESERVED = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_29_RESERVED = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_30_RESERVED = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_PCB_PM_MUX_SEL_DC = 31;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI = 0x00002812ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE = 0x00002848ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW = 0x00050012ull;

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
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE = 31;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI = 0x00002933ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE = 0x00002cccull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR = 0x00050133ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLCLKSW1 = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLCLKSW2 = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC = 31;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI = 0x00002917ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE = 0x00002c5cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW = 0x00050117ull;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_ENABLE = 0x000b005dull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_ENABLE_0 = 0;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_ENABLE_1 = 1;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_ENABLE_2 = 2;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CMD_WRDAT = 0x00030000ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CMD_WRDAT_WRITE_NOT_READ = 0;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP7_FSI0 = 0x0000306cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP7_SCOMFSI0 = 0x00000c1bull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_FSI0 = 0x00003020ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_WO_CLEAR = 0x00000c08ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_0_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_1_ENABLE = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_2_ENABLE = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_3_ENABLE = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_4_ENABLE = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_5_ENABLE = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_6_ENABLE = 6;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCENP0_7_ENABLE = 7;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_FSI0 = 0x000030e8ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_RO = 0x00000c3aull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP6_2_LEN = 3;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP5_FSI0 = 0x000034e4ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP5_WO = 0x00000d39ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP5_GENERAL_RESET_5 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP5_ERROR_RESET_5 = 1;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSCSB0_FSI0 = 0x000035d4ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSCSB0_SCOMFSI0 = 0x00000d75ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP6_FSI0 = 0x00003448ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP6_SCOMFSI0 = 0x00000d12ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCRSIS4 = 0x00000864ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP3_FSI1 = 0x000030dcull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP3_WO = 0x00000c37ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP3_GENERAL_RESET_3 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP3_ERROR_RESET_3 = 1;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1 = 0x00003030ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1 = 0x00000c0cull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCMBR = 0x0000084cull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMBL = 0x00000838ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SSI2M = 0x00000828ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8 = 0x000004a8ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE = 8;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE = 12;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE = 16;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE = 20;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE = 24;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE = 28;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SPIMC_FSI2SPI_SET_PIB_RESET_FSI = 0x00001c07ull;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_FSI2SPI_SET_PIB_RESET_FSI_BYTE = 0x00001c1cull;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW = 0x00070009ull;
static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND = 0x0007000aull;
static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR = 0x0007000bull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_MISO = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_MISO_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_MOSI = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_MOSI_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_DIRECTMODE = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_EN_C4 = 9;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_SCS_B = 10;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_SCK = 11;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_IO_CONTROL = 12;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_IO_CONTROL_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_INVERT_PORTS = 20;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_INVERT_PORTS_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_SLAVE_RESET = 24;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_SPI_SLAVE_RESET_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_LOOPBACK = 28;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG = 0x00070007ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN = 64;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER = 0x00070061ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1 = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2 = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A = 16;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT = 24;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT = 32;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL = 40;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL = 48;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL = 52;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B = 56;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B_LEN = 8;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG = 0x00070065ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN = 64;
// proc/reg00046.H

static const uint64_t VAS_VA_RG_SCF_WRMON0BAR = 0x02011410ull;
// proc/reg00046.H

static const uint64_t VAS_VA_RG_SCF_WRMON4CMP = 0x02011424ull;
// proc/reg00046.H

static const uint64_t VAS_VA_RG_SCF_WRMON5WID = 0x0201141dull;
// proc/reg00046.H

#ifndef __PPE_HCODE__
}
}
#include "proc/reg00043.H"
#include "proc/reg00044.H"
#include "proc/reg00045.H"
#include "proc/reg00046.H"
#endif
#endif
