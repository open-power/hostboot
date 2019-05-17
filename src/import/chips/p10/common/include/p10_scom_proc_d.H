/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_d.H $       */
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

#ifndef __p10_scom_proc_d_H_
#define __p10_scom_proc_d_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_FIRMASK_RW = 0x02010833ull;
static const uint64_t INT_CQ_FIRMASK_WO_AND = 0x02010834ull;
static const uint64_t INT_CQ_FIRMASK_WO_OR = 0x02010835ull;

static const uint32_t INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK = 0;
static const uint32_t INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK_LEN = 64;
// proc/reg00055.H

static const uint64_t INT_CQ_PMC_5 = 0x0201082dull;

static const uint32_t INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47 = 16;
static const uint32_t INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47_LEN = 48;
// proc/reg00055.H

static const uint64_t INT_CQ_SWI_RSP = 0x02010825ull;

static const uint32_t INT_CQ_SWI_RSP_HIST_DONE = 0;
static const uint32_t INT_CQ_SWI_RSP_POLL_DONE = 1;
static const uint32_t INT_CQ_SWI_RSP_BCAST_DONE = 2;
static const uint32_t INT_CQ_SWI_RSP_ASSIGN_DONE = 3;
static const uint32_t INT_CQ_SWI_RSP_BLK_UPDT_DONE = 4;
static const uint32_t INT_CQ_SWI_RSP_Z = 5;
static const uint32_t INT_CQ_SWI_RSP_O = 6;
static const uint32_t INT_CQ_SWI_RSP_M = 7;
static const uint32_t INT_CQ_SWI_RSP_CRESP_0_4 = 8;
static const uint32_t INT_CQ_SWI_RSP_CRESP_0_4_LEN = 5;
static const uint32_t INT_CQ_SWI_RSP_CRESP_RAMP = 13;
static const uint32_t INT_CQ_SWI_RSP_COLLISON = 14;
static const uint32_t INT_CQ_SWI_RSP_PRECLUDE = 15;
static const uint32_t INT_CQ_SWI_RSP_ATAG_0_15 = 16;
static const uint32_t INT_CQ_SWI_RSP_ATAG_0_15_LEN = 16;
// proc/reg00055.H

static const uint64_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1 = 0x02010a9bull;

static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE = 0;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE = 1;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9 = 2;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9_LEN = 8;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE = 10;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27 = 16;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27_LEN = 12;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO = 28;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33 = 32;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB = 34;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41 = 40;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER = 42;
static const uint32_t INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER_LEN = 6;
// proc/reg00055.H

static const uint64_t INT_PC_NXC_REGS_WATCH0_SPEC = 0x02010aa0ull;
// proc/reg00055.H

static const uint64_t INT_PC_NXC_REGS_WATCH2_DATA1 = 0x02010ab5ull;
// proc/reg00055.H

static const uint64_t INT_PC_NXC_REGS_WATCH_ASSIGN = 0x02010a86ull;
// proc/reg00055.H

static const uint64_t INT_PC_REGS_AIB_TX_CRD = 0x02010a14ull;

static const uint32_t INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST = 24;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RESERVED_25 = 25;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ = 26;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO = 28;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO = 30;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO = 32;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL = 34;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL_LEN = 6;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC = 40;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45 = 42;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45_LEN = 4;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE = 46;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE = 48;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI = 50;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE = 52;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI = 54;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC = 56;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL = 58;
static const uint32_t INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL_LEN = 6;
// proc/reg00055.H

static const uint64_t INT_PC_REGS_DBG_ATX_ORDER_2 = 0x02010a39ull;
// proc/reg00055.H

static const uint64_t INT_PC_REGS_NRQ_PEND_ARB = 0x02010a1dull;

static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1 = 0;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1_LEN = 2;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL = 2;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL_LEN = 2;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL = 4;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL_LEN = 2;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7 = 6;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7_LEN = 2;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD = 8;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD_LEN = 2;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD = 10;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD_LEN = 2;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST = 12;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST_LEN = 2;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST = 14;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST_LEN = 2;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23 = 16;
static const uint32_t INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23_LEN = 8;
// proc/reg00055.H

static const uint64_t INT_PC_REGS_NVG_BLOCK_MODE = 0x02010a0dull;

static const uint32_t INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE = 0;
static const uint32_t INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE_LEN = 32;
// proc/reg00055.H

static const uint64_t INT_PC_REGS_TCTXT_LSI_SET_01 = 0x02010b25ull;
// proc/reg00055.H

static const uint64_t INT_VC_ENDC_WATCH1_DATA3 = 0x020109afull;
// proc/reg00055.H

static const uint64_t INT_VC_QUEUES_CFG_REM_2 = 0x02010919ull;

static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE = 0;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE = 1;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE_LEN = 6;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10 = 8;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10_LEN = 3;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ = 11;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ_LEN = 5;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18 = 16;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18_LEN = 3;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC = 19;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC_LEN = 5;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM = 24;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM = 28;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33 = 32;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_FULL = 34;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE = 35;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37 = 36;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING = 38;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE = 39;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41 = 40;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE = 42;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE_LEN = 6;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49 = 48;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_ERQ_FULL = 50;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE = 51;
static const uint32_t INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND = 52;
// proc/reg00055.H

static const uint64_t INT_VC_QUEUES_PERF_EVENT_SEL_1 = 0x02010927ull;

static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB = 0;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS = 8;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS = 12;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA = 16;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ = 20;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX = 24;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC = 28;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC_LEN = 4;
// proc/reg00055.H

static const uint64_t INT_VC_RECOV_ERR_G2 = 0x020109d5ull;

static const uint32_t INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR = 0;
static const uint32_t INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR_LEN = 64;
// proc/reg00055.H

static const uint64_t INT_VC_WOF_ERR_G0_DETAIL = 0x020109c3ull;

static const uint32_t INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR = 0;
static const uint32_t INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR_LEN = 64;
// proc/reg00055.H

static const uint64_t NX_CH4_ADDR_6_HASH_FUNCTION_REG = 0x02011147ull;

static const uint32_t NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION_LEN = 64;
// proc/reg00055.H

static const uint64_t NX_CH4_DATATAG_2_HASH_FUNCTION_REG = 0x0201114eull;

static const uint32_t NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION_LEN = 64;
// proc/reg00055.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR = 0x0201108dull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_LEN = 44;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE = 52;
// proc/reg00055.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG = 0x02011090ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL = 0;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL_LEN = 8;
// proc/reg00055.H

static const uint64_t NX_PBI_RNG_ST3 = 0x020110e8ull;

static const uint32_t NX_PBI_RNG_ST3_RRN_ENABLE = 0;
static const uint32_t NX_PBI_RNG_ST3_WINDOW_SIZE = 1;
static const uint32_t NX_PBI_RNG_ST3_WINDOW_SIZE_LEN = 3;
static const uint32_t NX_PBI_RNG_ST3_MATCH_TH_MIN = 4;
static const uint32_t NX_PBI_RNG_ST3_MATCH_TH_MIN_LEN = 16;
static const uint32_t NX_PBI_RNG_ST3_MATCH_TH_MAX = 20;
static const uint32_t NX_PBI_RNG_ST3_MATCH_TH_MAX_LEN = 16;
// proc/reg00055.H

static const uint64_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL = 0x020110ccull;

static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET = 4;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN = 8;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED = 15;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN = 9;
// proc/reg00055.H

static const uint64_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB = 0x020110c8ull;

static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID = 4;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN = 12;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID = 20;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID_LEN = 20;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID = 44;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID_LEN = 16;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE = 63;
// proc/reg00055.H

static const uint64_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR = 0x020110cbull;

static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR = 8;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_LEN = 46;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE = 54;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN = 3;
// proc/reg00055.H

static const uint64_t PB_COM_ES3_HP_MODE1_CURR = 0x0301138cull;

static const uint32_t PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3 = 0;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3 = 1;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3 = 2;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3 = 3;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_NP_CMD_RATE_CURR_ES3 = 8;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_NP_CMD_RATE_CURR_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3 = 16;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3 = 17;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3 = 18;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_MIN_G_CMD_RATE_CURR_ES3 = 24;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_MIN_G_CMD_RATE_CURR_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3 = 32;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3 = 33;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3 = 34;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_MIN_R_CMD_RATE_CURR_ES3 = 40;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_MIN_R_CMD_RATE_CURR_ES3_LEN = 8;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM10_DOB23_DIB23_INT_ERR_REG = 0x1001182aull;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM10_MAILBOX_20_REG = 0x10011834ull;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM10_MAILBOX_21_REG = 0x10011835ull;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM10_MAILBOX_CTL_REG = 0x1001182eull;

static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID = 0;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD = 1;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR = 2;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN = 3;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT = 4;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT = 5;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE = 6;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET = 7;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID = 8;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID = 9;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID_LEN = 3;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE = 12;
static const uint32_t PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE_LEN = 4;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM10_PMU3_CNPM_COUNTER = 0x10011824ull;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM10_PSAVE23_MODE_CFG = 0x10011816ull;

static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE = 0;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE = 5;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN = 8;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM10_TL_LINK_SYN_01_REG = 0x10011812ull;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM23_DOB01_DIB01_INT_ERR_REG = 0x11011828ull;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM23_PMU1_CNPM_COUNTER = 0x11011822ull;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM23_PTL_FIR_REG_RW = 0x11011800ull;
static const uint64_t PB_PTLSCOM23_PTL_FIR_REG_WO_AND = 0x11011801ull;
static const uint64_t PB_PTLSCOM23_PTL_FIR_REG_WO_OR = 0x11011802ull;

static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED = 0;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED = 1;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED = 2;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED = 3;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE = 4;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE = 5;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE = 6;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR = 7;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE = 8;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE = 9;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE = 10;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR = 11;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN = 12;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN = 13;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN = 14;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN = 15;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN = 16;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN = 17;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN = 18;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN = 19;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN = 20;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN = 21;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN = 22;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN = 23;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN = 24;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN = 25;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR = 26;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR = 27;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN = 28;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN = 29;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN = 30;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN = 31;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN = 32;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN = 33;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN = 34;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN = 35;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE = 36;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE = 37;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE = 38;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE = 39;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM45_MAILBOX_30_REG = 0x12011836ull;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM45_MAILBOX_31_REG = 0x12011837ull;
// proc/reg00055.H

static const uint64_t PB_PTLSCOM45_PSAVE01_MISC_CFG = 0x12011815ull;

static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC = 0;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC = 8;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT = 16;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT = 21;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE = 26;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC = 28;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC = 36;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT = 44;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT = 49;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE = 54;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE = 56;
static const uint32_t PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE_LEN = 3;
// proc/reg00055.H

static const uint64_t PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG = 0x03011d50ull;

static const uint32_t PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER = 13;
static const uint32_t PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER_LEN = 30;
// proc/reg00055.H

static const uint64_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX = 0x03011c89ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0 = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0_LEN = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1 = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1_LEN = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2 = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2_LEN = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3 = 12;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3_LEN = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4 = 16;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4_LEN = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5 = 20;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5_LEN = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0 = 24;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0_LEN = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1 = 28;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1_LEN = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2 = 32;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2_LEN = 4;
// proc/reg00055.H

static const uint64_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM = 0x03011c81ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE = 1;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE_LEN = 3;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67 = 6;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67_LEN = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE_LEN = 32;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE = 40;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_LEN = 9;
// proc/reg00055.H

static const uint64_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE = 0x03011c80ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL = 1;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL_LEN = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3 = 3;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE_LEN = 9;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP = 13;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP = 14;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP = 15;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16 = 16;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY = 17;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE = 18;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE = 19;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE_LEN = 3;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO = 22;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23 = 23;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET = 24;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET_LEN = 16;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043 = 40;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043_LEN = 4;
// proc/reg00055.H

static const uint64_t PSI_MAC_SCOM_FIR_WOF_REG = 0x03012c08ull;
// proc/reg00055.H

static const uint64_t TP_TCN0_N0_CPLT_CTRL5_RW = 0x02000005ull;
static const uint64_t TP_TCN0_N0_CPLT_CTRL5_WO_CLEAR = 0x02000025ull;
static const uint64_t TP_TCN0_N0_CPLT_CTRL5_WO_OR = 0x02000015ull;

static const uint32_t TP_TCN0_N0_CPLT_CTRL5_0 = 0;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_1 = 1;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_2 = 2;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_3 = 3;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_4 = 4;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_5 = 5;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_6 = 6;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_7 = 7;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_8 = 8;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_9 = 9;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_10 = 10;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_11 = 11;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_12 = 12;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_13 = 13;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_14 = 14;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_15 = 15;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_16 = 16;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_17 = 17;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_18 = 18;
static const uint32_t TP_TCN0_N0_CPLT_CTRL5_19 = 19;
// proc/reg00055.H

static const uint64_t TP_TCN0_N0_HOSTATTN = 0x02040004ull;

static const uint32_t TP_TCN0_N0_HOSTATTN_ANY_HOSTATTN = 0;
static const uint32_t TP_TCN0_N0_HOSTATTN_RESERVED1H = 1;
static const uint32_t TP_TCN0_N0_HOSTATTN_RESERVED2H = 2;
static const uint32_t TP_TCN0_N0_HOSTATTN_RESERVED3H = 3;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_PERV = 4;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN05 = 5;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN06 = 6;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN07 = 7;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN08 = 8;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN09 = 9;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN10 = 10;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN11 = 11;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN12 = 12;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN13 = 13;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN14 = 14;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN15 = 15;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN16 = 16;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN17 = 17;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN18 = 18;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN19 = 19;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN20 = 20;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN21 = 21;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN22 = 22;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN23 = 23;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN24 = 24;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN25 = 25;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN26 = 26;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN27 = 27;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN28 = 28;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN29 = 29;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN30 = 30;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN31 = 31;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN32 = 32;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN33 = 33;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN34 = 34;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN35 = 35;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN36 = 36;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN37 = 37;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN38 = 38;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN39 = 39;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN40 = 40;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN41 = 41;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN42 = 42;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN43 = 43;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN44 = 44;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN45 = 45;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN46 = 46;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN47 = 47;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN48 = 48;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN49 = 49;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN50 = 50;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN51 = 51;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN52 = 52;
static const uint32_t TP_TCN0_N0_HOSTATTN_HOSTATTN_IN53 = 53;
// proc/reg00055.H

static const uint64_t TP_TCN0_N0_SCAN32 = 0x02038000ull;
// proc/reg00055.H

static const uint64_t TP_TCN0_N0_SCAN64 = 0x0203e000ull;
// proc/reg00055.H

static const uint64_t TP_TCN0_N0_TRA1_TR0_CONFIG_1 = 0x02010484ull;

static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00055.H

static const uint64_t TP_TCN1_N1_CLOCK_STAT_ARY = 0x0303000aull;

static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_ARY_UNIT14_ARY = 18;
// proc/reg00055.H

static const uint64_t TP_TCN1_N1_CTRL_PROTECT_MODE_REG = 0x030003feull;

static const uint32_t TP_TCN1_N1_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t TP_TCN1_N1_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1 = 0x030107c1ull;

static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1 = 0x030107c4ull;

static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCN1_N1_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5 = 0x03040085ull;

static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR = 0;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR = 1;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR = 2;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR = 3;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR = 4;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP = 5;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1 = 6;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t TP_TCN1_N1_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG = 0x03010001ull;

static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0_ERROR = 3;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0_ERROR = 5;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT = 15;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY_ERROR = 18;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY_ERROR = 19;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY_ERROR = 20;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0_ERROR = 21;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY_ERROR = 22;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0_ERROR = 23;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_INTERFACE_MACHINE = 24;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_P2S_MACHINE = 25;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 26;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 27;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 28;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_WRITE_NVLD = 29;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_READ_NVLD = 30;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_ADDR_INVALID = 31;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY_ERROR = 32;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT = 33;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 34;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 35;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG = 0x0305000full;

static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_SCAN_REGION_TYPE = 0x03030005ull;

static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SYSTEM_FAST_INIT = 0;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_PARALLEL_SCAN = 1;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR = 2;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_VITL = 3;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_PERV = 4;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT1 = 5;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT2 = 6;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT3 = 7;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT4 = 8;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT5 = 9;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT6 = 10;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT7 = 11;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT8 = 12;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT9 = 13;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT10 = 14;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT11 = 15;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT12 = 16;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT13 = 17;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_REGION_UNIT14 = 18;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_FUNC = 48;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_CFG = 49;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR = 50;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_REGF = 51;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_LBIST = 52;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_ABIST = 53;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_REPR = 54;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_TIME = 55;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_BNDY = 56;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_FARR = 57;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_CMSK = 58;
static const uint32_t TP_TCN1_N1_SCAN_REGION_TYPE_SCAN_TYPE_INEX = 59;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_TRA1_TR0_CONFIG_9 = 0x03010489ull;

static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_TRA1_TR1_CONFIG_0 = 0x030104c3ull;

static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_TRA3_TR0_CONFIG_1 = 0x03010584ull;

static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_TRA4_TR0_CONFIG_0 = 0x03010603ull;

static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_TRA4_TR1_CONFIG_9 = 0x03010649ull;

static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_TRA5_TR0_TRACE_HI_DATA_REG = 0x03010680ull;

static const uint32_t TP_TCN1_N1_TRA5_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA5_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG = 0x03010741ull;

static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCN1_N1_TRA6_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// proc/reg00056.H

static const uint64_t TP_TCN1_N1_TRA6_TR1_CONFIG_1 = 0x03010744ull;

static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00056.H

static const uint64_t TP_TPBR_AD_TOD_DATA_SND_REG = 0x00090028ull;

static const uint32_t TP_TPBR_AD_TOD_DATA_SND_REG_PCB_TOD_DATA_SND = 0;
static const uint32_t TP_TPBR_AD_TOD_DATA_SND_REG_PCB_TOD_DATA_SND_LEN = 64;
// proc/reg00056.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAFCFG = 0x03011dcbull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY = 0;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG = 1;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY = 2;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX = 3;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV = 9;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK = 14;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK_LEN = 6;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV = 20;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG = 24;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG = 25;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK = 26;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF = 27;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP = 28;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29 = 29;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE = 30;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK = 31;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK = 32;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE = 33;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ = 34;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ = 35;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX = 36;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT = 38;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT = 39;
// proc/reg00056.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAPBOCR3 = 0x03011dd3ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR3_EVENT = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR3_EVENT_LEN = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR3_ACCUM = 44;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR3_ACCUM_LEN = 20;
// proc/reg00056.H

static const uint64_t TP_TPBR_PBA_PBAO_BCUE_SET = 0x00068016ull;

static const uint32_t TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH_LEN = 6;
// proc/reg00056.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAFIR_RW = 0x01010cc0ull;
static const uint64_t TP_TPBR_PBA_PBAO_PBAFIR_WO_AND = 0x01010cc1ull;
static const uint64_t TP_TPBR_PBA_PBAO_PBAFIR_WO_OR = 0x01010cc2ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3 = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR = 9;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR = 10;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR = 13;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR = 14;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR = 15;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_16 = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_17 = 17;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18 = 18;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19 = 19;
// proc/reg00056.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAFIRACT1 = 0x01010cc7ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1_LEN = 20;
// proc/reg00056.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAMODE = 0x00068000ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9 = 9;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF = 10;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_INJECT_TYPE = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_INJECT_TYPE_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_INJECT_MODE = 14;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_INJECT_MODE_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE = 18;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE = 25;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE = 26;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS = 27;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29 = 29;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX = 30;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS = 32;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI = 33;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE = 34;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39 = 39;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK = 40;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV = 45;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63 = 50;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63_LEN = 14;
// proc/reg00056.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAPBTXT1 = 0x01010ce3ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1__VALID = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1__VALID_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_0 = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_0_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_1 = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_1_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_2 = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_2_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_3 = 20;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_3_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_4 = 24;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_4_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_5 = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_5_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_6 = 32;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_6_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_7 = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBAPBTXT1_7_LEN = 4;
// proc/reg00056.H

static const uint64_t TP_TPBR_PSI_WRAP_RX_DF_FSM_REG = 0x03011c0eull;
// proc/reg00056.H

static const uint64_t TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG = 0x03011c10ull;
// proc/reg00056.H

static const uint64_t TP_TPBR_PSIHB_FIR_REG_RW = 0x03011d00ull;
static const uint64_t TP_TPBR_PSIHB_FIR_REG_WO_AND = 0x03011d01ull;
static const uint64_t TP_TPBR_PSIHB_FIR_REG_WO_OR = 0x03011d02ull;

static const uint32_t TP_TPBR_PSIHB_FIR_REG_PB_ECC_ERR_CE = 0;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_PB_ECC_ERR_UE = 1;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_PB_ECC_ERR_SUE = 2;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INTERRUPT_FROM_ERROR = 3;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INTERRUPT_FROM_FSP = 4;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_FSP_ECC_ERR_CE = 5;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_FSP_ECC_ERR_UE = 6;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_ERROR_STATE = 7;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INVALID_TTYPE = 8;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INVALID_CRESP = 9;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_PB_DATA_TIME_OUT = 10;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_PB_PARITY_ERROR = 11;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_FSP_ACCESS_TRUSTED_SPACE = 12;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_UNEXPECTED_PB = 13;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE = 14;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INTERRUPT0_ADDRESS_ERROR = 15;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INTERRUPT1_ADDRESS_ERROR = 16;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INTERRUPT2_ADDRESS_ERROR = 17;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INTERRUPT3_ADDRESS_ERROR = 18;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INTERRUPT4_ADDRESS_ERROR = 19;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_INTERRUPT5_ADDRESS_ERROR = 20;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_TCBR_TP_PSI_GLB_ERR_0 = 21;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_TCBR_TP_PSI_GLB_ERR_1 = 22;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_UPSTREAM_FIR = 23;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_SPARE_FIR = 24;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_SPARE_FIR_LEN = 3;
static const uint32_t TP_TPBR_PSIHB_FIR_REG_FIR_PARITY_ERROR = 27;
// proc/reg00056.H

static const uint64_t TP_TPBR_PSIHB_INTERRUPT_STATUS = 0x03011d1aull;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_LXSTOP_INTERRUPT_REG = 0x020f002aull;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_HOSTATTN_INTERRUPT_REG = 0x030f002bull;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_LXSTOP_INTERRUPT_REG = 0x030f002aull;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_2 = 0x030f0002ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_PROTECT_MODE_REG = 0x010f03feull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR13 = 0x0006004bull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR13_OCB_OCI_GPEXIVDRX_GPR13 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR13_OCB_OCI_GPEXIVDRX_GPR13_LEN = 32;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR4 = 0x00060044ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4_LEN = 32;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIAR = 0x00060025ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR_LEN = 30;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL = 0x0006002dull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_SIB_PIB_IFETCH_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_MEM_IFETCH_PENDING = 3;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU = 0x0006002cull;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIEDR = 0x00062023ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIEDR_OCB_OCI_GPEXIRAMEDR_EDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIEDR_OCB_OCI_GPEXIRAMEDR_EDR_LEN = 32;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL = 0x00062027ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_R_NW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_BUSY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_RSP_INFO = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_RSP_INFO_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_IFETCH_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_DATAOP_PENDING = 31;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBU = 0x00062026ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR_LEN = 32;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR = 0x00064001ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN = 23;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR = 0x00064004ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE = 12;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR1 = 0x00066006ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR1_BAR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR1_BAR_LEN = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR1_SIZE = 44;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPESWPR1_SIZE_LEN = 15;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXICTR = 0x00066032ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXICTR_OCB_OCI_GPEXICTR_CTR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXICTR_OCB_OCI_GPEXICTR_CTR_LEN = 32;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGINF = 0x0006601full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGINF_SRR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGINF_SRR0_LEN = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGINF_LR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGINF_LR_LEN = 32;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR0 = 0x00066040ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0_LEN = 32;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR10 = 0x0006604aull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR10_OCB_OCI_GPEXIVDRX_GPR10 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR10_OCB_OCI_GPEXIVDRX_GPR10_LEN = 32;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1 = 0x0006c821ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7 = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7_LEN = 16;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SRD1B = 0x0006c739ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B_LEN = 32;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0 = 0x0006c20cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE_LEN = 7;
// proc/reg00056.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW = 0x0006c0afull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR = 0x0006c0b0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR = 0x0006c0b1ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS_LEN = 32;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW = 0x0006c048ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR = 0x0006c049ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR = 0x0006c04aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C_LEN = 32;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q6 = 0x0006c406ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q6_OCB_OCI_OPIT0Q6RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q6_OCB_OCI_OPIT0Q6RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q2 = 0x0006c41aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q2_OCB_OCI_OPIT3Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q2_OCB_OCI_OPIT3Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4 = 0x0006c424ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4_OCB_OCI_OPIT4Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4_OCB_OCI_OPIT4Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_RO = 0x0006c628ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_WO_CLEAR = 0x0006c629ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_7 = 7;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q0 = 0x0006c438ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q0_OCB_OCI_OPIT7Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q0_OCB_OCI_OPIT7Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C10RR = 0x0006c54aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C10RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C10RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C10RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C10RR_PAYLOAD_LEN = 17;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13 = 0x0006c44dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13_PAYLOAD_LEN = 17;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C22RR = 0x0006c556ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C22RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C22RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C22RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C22RR_PAYLOAD_LEN = 17;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24 = 0x0006c458ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24_PAYLOAD_LEN = 17;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15 = 0x0006c46full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15_PAYLOAD_LEN = 17;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17RR = 0x0006c571ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17RR_PAYLOAD_LEN = 17;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C22 = 0x0006c476ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C22_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C22_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C22_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C22_PAYLOAD_LEN = 17;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C25RR = 0x0006c579ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C25RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C25RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C25RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C25RR_PAYLOAD_LEN = 17;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4 = 0x0006c464ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4_PAYLOAD_LEN = 17;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2 = 0x0006c482ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7_LEN = 4;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OTR0 = 0x0006c100ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0_LEN = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0_LEN = 16;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_100NS = 0x0006c828ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS_LEN = 32;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_CMD = 0x0006c844ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND = 0;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR = 0x0006d110ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_TRACE_BUS_EN = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_OCB_TRACE_MUX_SEL = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_OCC_TRACE_MUX_SEL = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_OCC_TRACE_MUX_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_OCI_TRACE_MUX_SEL = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_OCI_TRACE_MUX_SEL_LEN = 4;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2 = 0x0101080bull;

static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRAM_SPARE_DIRECT_ERROR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRAM_SPARE_DIRECT_ERROR1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRAM_SPARE_DIRECT_ERROR2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRAM_SPARE_DIRECT_ERROR3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_OCB_IDC0_ERROR = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_OCB_IDC1_ERROR = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_OCB_IDC2_ERROR = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_OCB_IDC3_ERROR = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_OCB_DB_OCI_TIMEOUT = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_OCB_DB_OCI_READ_DATA_PARITY = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_OCB_DB_OCI_SLAVE_ERROR = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_OCB_DB_PIB_DATA_PARITY_ERR = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRT_READ_ERROR = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRT_WRITE_ERROR = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRT_DATAOUT_PERR = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRT_OCI_WRITE_DATA_PARITY = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRT_OCI_BE_PARITY_ERR = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRT_OCI_ADDR_PARITY_ERR = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCERRRPT2_SRT_FSM_ERR = 18;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OCC_SRAM_CTL_SRMR = 0x0006a001ull;

static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMR_RAM_ENABLE_REMAP = 0;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMR_RAM_ARB_EN_SEND_ALL_WRITES = 1;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMR_RAM_DISABLE_LFSR = 2;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMR_RAM_LFSR_FAIRNESS_MASK = 3;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMR_RAM_LFSR_FAIRNESS_MASK_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMR_RAM_ERROR_INJECT_ENABLE = 8;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMR_RAM_CTL_TRACE_EN = 9;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMR_RAM_CTL_TRACE_SEL = 10;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMR_PARE = 11;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMR_PARE_LEN = 5;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG102 = 0x00008066ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG102_REGISTER102 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG102_REGISTER102_LEN = 64;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG35 = 0x00008023ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG35_REGISTER35 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG35_REGISTER35_LEN = 64;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG54 = 0x00008036ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG54_REGISTER54 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG54_REGISTER54_LEN = 64;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG63 = 0x0000803full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG63_REGISTER63 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG63_REGISTER63_LEN = 64;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG89 = 0x00008059ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG89_REGISTER89 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG89_REGISTER89_LEN = 64;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG9 = 0x00008009ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG9_REGISTER9 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG9_REGISTER9_LEN = 64;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG96 = 0x00008060ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG96_REGISTER96 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG96_REGISTER96_LEN = 64;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_ECHAR = 0x01000058ull;

static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_ECHAR_DYNAMIC_ENCODED_DATA = 1;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_ECHAR_DYNAMIC_ENCODED_DATA_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_ECHAR_MIN_ENCODED_DATA = 5;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_ECHAR_MIN_ENCODED_DATA_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_ECHAR_MAX_ENCODED_DATA = 9;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_ECHAR_MAX_ENCODED_DATA_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT = 61;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT_LEN = 3;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ = 0x01000051ull;

static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX = 1;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX = 12;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FF_MAX_MULT_FRAC7 = 16;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT = 17;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT = 28;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_MULT_FRAC7 = 32;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN = 33;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN = 44;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FF_MIN_MULT_FRAC7 = 48;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1 = 0x010107ceull;

static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_TPC_EPS_FIR_ANY_LOCAL_ERR_MASK = 0x01040080ull;

static const uint32_t TP_TPCHIP_TPC_EPS_FIR_ANY_LOCAL_ERR_MASK_XSTOP_TO_PCB = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_ANY_LOCAL_ERR_MASK_RECOV_TO_PCB = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_ANY_LOCAL_ERR_MASK_SPATTN_TO_PCB = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_ANY_LOCAL_ERR_MASK_LOCAL_XSTOP_TO_PCB = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_ANY_LOCAL_ERR_MASK_HOSTATTN_TO_PCB = 4;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3 = 0x01040083ull;

static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_XSTOP_ERR = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_RECOV_ERR = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_SPATTN_ERR = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_LXSTOP_ERR = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_HOSTATTN_ERR = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYSTEM_XSTOP = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_OOB1 = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 = 21;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 = 22;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 = 23;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 = 24;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 = 25;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 = 26;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_TPC_EPS_THERM_WSUB_DTS_RESULT2 = 0x01050002ull;

static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_TPC_ITR_FMU_VMEAS_RESULT_REG = 0x01020006ull;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_TPC_OPCG_REG1 = 0x01030003ull;

static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_SCAN_COUNT = 0;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_SCAN_COUNT_LEN = 12;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_MISR_A_VAL = 12;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_MISR_A_VAL_LEN = 12;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_MISR_B_VAL = 24;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_MISR_B_VAL_LEN = 12;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_MISR_INIT_WAIT = 36;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_MISR_INIT_WAIT_LEN = 12;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_SCAN_CLK_USE_EVEN = 49;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_RTIM_THOLD_FORCE = 52;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL = 53;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_SG_HIGH_DURING_FILL = 54;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_LBIST_SKITTER_CTL = 55;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_LBIST_SKITTER_CTL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_MISR_MODE = 57;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_INFINITE_MODE = 58;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_NSL_FILL_COUNT = 59;
static const uint32_t TP_TPCHIP_TPC_OPCG_REG1_NSL_FILL_COUNT_LEN = 5;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_0 = 0x01010403ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00057.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9 = 0x01010449ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00057.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_SET_PIB_RESET_FSI = 0x00001007ull;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_SET_PIB_RESET_FSI_BYTE = 0x0000101cull;
// proc/reg00057.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI = 0x00001007ull;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE = 0x0000101cull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP = 1;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION = 2;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR = 3;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST = 4;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK = 5;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT = 6;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK = 7;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8 = 8;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9 = 9;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION = 10;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT = 11;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE = 16;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE = 17;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC = 23;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC = 26;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING = 28;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED = 29;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION = 30;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31 = 31;
// proc/reg00057.H

static const uint64_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A = 0x00001805ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_INVALID_CMD_000 = 16;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_LBUS_PARITY_ERROR_000 = 17;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_BE_OV_ERROR_000 = 18;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_BE_ACC_ERROR_000 = 19;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_ARBITRATION_LOST_ERROR_000 = 20;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_NACK_RECEIVED_ERROR_000 = 21;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_DATA_REQUEST_000 = 22;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_STOP_ERROR_000 = 24;
// proc/reg00057.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_10_FSI = 0x0000284aull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_10_FSI_BYTE = 0x00002928ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_10_RW = 0x0005004aull;
// proc/reg00057.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI = 0x00002842ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE = 0x00002908ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW = 0x00050042ull;
// proc/reg00057.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI = 0x00002888ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE = 0x00002a20ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RW = 0x00050088ull;
// proc/reg00057.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_14_FSI = 0x000028ceull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_14_FSI_BYTE = 0x00002b38ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_14_RW = 0x000500ceull;
// proc/reg00057.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI = 0x00002904ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE = 0x00002c10ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RW = 0x00050104ull;
// proc/reg00057.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_FSI = 0x0000293aull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_FSI_BYTE = 0x00002ce8ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_WO_CLEAR = 0x0005013aull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_CHIPLET_EN_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_PCB_EP_RESET_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_3_RESERVED = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_4_RESERVED = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_5_RESERVED = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_6_RESERVED = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_SCIN_DC = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_8_RESERVED = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_FLUSH_ALIGN_OVERWRITE = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_10_RESERVED = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_EDIS_DC = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_MPW1_DC_N = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_MPW2_DC_N = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_MPW3_DC_N = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_DELAY_LCLKR_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_CLKOFF_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_17_RESERVED = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_FENCE_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_RI_DC_N = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_DI1_DC_N = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_DI2_DC_N = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_22_RESERVED = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_OTP_SCOM_FUSED_CORE_MODE = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_24_RESERVED = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_FENCE_PCB_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_26_RESERVED = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_ARRAY_WRITE_ASSIST_EN_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_28_RESERVED = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_29_RESERVED = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_30_RESERVED = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_31_SPARE = 31;
// proc/reg00057.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI = 0x0000292aull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE = 0x00002ca8ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR = 0x0005012aull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_CHIPLET_EN_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_PCB_EP_RESET_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_RESERVED = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_4_RESERVED = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_5_RESERVED = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_6_RESERVED = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_SCIN_DC = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FLUSH_ALIGN_OVERWRITE = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_RESERVED = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_EDIS_DC = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_MPW1_DC_N = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_MPW2_DC_N = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_MPW3_DC_N = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_DELAY_LCLKR_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_RI_DC_N = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_DI1_DC_N = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_DI2_DC_N = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_22_RESERVED = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_24_RESERVED = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_RESERVED = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_ARRAY_WRITE_ASSIST_EN_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_28_RESERVED = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_30_RESERVED = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE = 31;
// proc/reg00057.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_FSI = 0x0000292bull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_FSI_BYTE = 0x00002cacull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_WO_OR = 0x0005012bull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_0_RESERVED = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_TP_CHIPLET_PLL_BNDY_BYPASS_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_4_RESERVED = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_5_RESERVED = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_6_RESERVED = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_7_RESERVED = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_8_RESERVED = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_9_RESERVED = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_10_RESERVED = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_11_RESERVED = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_12_RESERVED = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_13_RESERVED = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_14_RESERVED = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_15_RESERVED = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_TP_SEC_BUF_DRV_STRENGTH_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_TP_SEC_BUF_DRV_STRENGTH_DC_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_20_RESERVED = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_21_RESERVED = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_22_RESERVED = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_23_RESERVED = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_24_RESERVED = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_TP_CLK_PULSE_ENABLE_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_TP_CLK_PULSE_MODE_DC = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_TP_CLK_PULSE_MODE_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_28_RESERVED = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_29_RESERVED = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_PERV_CTRL1_30_RESERVED = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_TP_PCB_PM_MUX_SEL_DC = 31;
// proc/reg00058.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_FSI = 0x00002932ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_FSI_BYTE = 0x00002cc8ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_WO_CLEAR = 0x00050132ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_0_SPARE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_3_SPARE = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_PIB_DISABLE_PARITY_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_PIB_TRACE_MODE_DATA_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_PIB_VSB_SBE_TRACE_MODE = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_TPCPERV_VSB_TRACE_STOP = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_GPIO_PIB_TIMEOUT = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_GPIO_PIB_TIMEOUT_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_SPARE_PIB_CONTROL = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TPCFSI_OPB_SW_RESET_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_13_SPARE_OPB_CONTROL = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_14_SPARE_OPB_CONTROL = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_15_SPARE_OPB_CONTROL = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_16_SPARE = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_VREGDLY_SHUTOFF_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_18_SPARE = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_19_SPARE = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_20_SPARE = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_21_FREE_USAGE = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_22_FREE_USAGE = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_23_FREE_USAGE = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP0A_V1P8_EN = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP0B_V1P8_EN = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_26_FREE_USAGE = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_27_FREE_USAGE = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_28_FREE_USAGE = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_29_FREE_USAGE = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP3A_V1P8_EN = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP3B_V1P8_EN = 31;
// proc/reg00058.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_FSI = 0x0000283dull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_FSI_BYTE = 0x000028f4ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_RW = 0x0005003dull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_SR_SCRATCH_REGISTER_6 = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_SR_SCRATCH_REGISTER_6_LEN = 32;
// proc/reg00058.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_DATA_IN = 0x000b0010ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_MTC_FSI = 0x00002416ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_MTC_FSI_BYTE = 0x00002458ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_MTC_RW = 0x000b0016ull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_MTC_DNFIFO_MCT = 0;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_MTC_DNFIFO_MCT_LEN = 32;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDNFIFO_DATA_OUT_FSI = 0x00002430ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDNFIFO_DATA_OUT_FSI_BYTE = 0x000024c0ull;
// proc/reg00058.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_ACK_EOT = 0x000b0025ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_SIG_EOT_FSI = 0x00002422ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_SIG_EOT_FSI_BYTE = 0x00002488ull;
// proc/reg00058.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_ACK_EOT = 0x000b0005ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_SIG_EOT_FSI = 0x00002402ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_SIG_EOT_FSI_BYTE = 0x00002408ull;
// proc/reg00058.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES = 0x00020001ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_CMD_PARITY_ERROR = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_WR_DATA_PARITY_ERROR =
    2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_RD_DATA_PARITY_ERROR =
    3;
static const uint32_t
TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_LCK_STATUS_PARITY_ERROR = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_FSM_PARITY_ERROR = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_OPB_PARITY_ERROR = 8;
// proc/reg00058.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_LSTAT = 0x00030002ull;
// proc/reg00058.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES = 0x00030001ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_CMD_PARITY_ERROR = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_WR_DATA_PARITY_ERROR =
    2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_RD_DATA_PARITY_ERROR =
    3;
static const uint32_t
TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_LCK_STATUS_PARITY_ERROR = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_FSM_PARITY_ERROR = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_STAT_RDDAT_ERRES_OPB_PARITY_ERROR = 8;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_LLMOD = 0x00000900ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_LLMOD_FSI_A_ASYNC_MODE = 31;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FSI0 = 0x000031d0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_RO = 0x00000c74ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FIRST_ERROR = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FIRST_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST = 17;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_ACTUAL_ERROR = 20;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_ACTUAL_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT = 29;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN = 3;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP6_FSI0 = 0x000030e8ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP6_WO = 0x00000c3aull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP6_GENERAL_RESET_6 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP6_ERROR_RESET_6 = 1;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP5_FSI0 = 0x00003044ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP5_SCOMFSI0 = 0x00000c11ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP4_FSI0 = 0x00003460ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP4_SCOMFSI0 = 0x00000d18ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MREFP0_FSI0 = 0x00003420ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MREFP0_RO = 0x00000d08ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_FSI0 = 0x000034e4ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_RO = 0x00000d39ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_2_LEN = 3;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCISM = 0x00000814ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SISM = 0x0000080cull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP2_FSI1 = 0x00003058ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP2_SCOMFSI1 = 0x00000c16ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MECTRL_FSI1 = 0x000032e0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MECTRL_SCOMFSI1 = 0x00000cb8ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MLEVP1_FSI1 = 0x0000301cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MLEVP1_RO = 0x00000c07ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_FSI1 = 0x000030dcull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_RO = 0x00000c37ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_2_LEN = 3;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCRSIC4 = 0x00000854ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SDATA = 0x00000830ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SRSIS0 = 0x00000878ull;
// proc/reg00058.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4AC = 0x000004acull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4AC_6_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4AC_7_ENABLE = 4;
// proc/reg00058.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_CLOCK_CONFIG = 0x00070003ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN = 64;
// proc/reg00058.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_ERROR_INJECT_ = 0x00070000ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_ERROR_INJECT__ERROR_REG_Q = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_ERROR_INJECT__ERROR_REG_Q_LEN = 64;
// proc/reg00058.H

static const uint64_t VAS_VA_EG_SCF_PGMIG4 = 0x02011444ull;
// proc/reg00058.H

static const uint64_t VAS_VA_RG_SCF_MISCCTL = 0x0201140dull;

static const uint32_t VAS_VA_RG_SCF_MISCCTL_4VS64 = 0;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE = 1;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON = 2;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT = 3;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST = 4;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE = 5;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE = 6;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE = 7;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE = 8;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC = 47;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL = 48;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION = 49;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION_LEN = 7;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE = 56;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE = 58;
static const uint32_t VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE = 59;
// proc/reg00058.H

}
}
#include "proc/reg00055.H"
#include "proc/reg00056.H"
#include "proc/reg00057.H"
#include "proc/reg00058.H"
#endif
