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
// proc/reg00050.H

static const uint64_t INT_CQ_PMC_5 = 0x0201082dull;

static const uint32_t INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47 = 16;
static const uint32_t INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47_LEN = 48;
// proc/reg00050.H

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
// proc/reg00050.H

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
// proc/reg00050.H

static const uint64_t INT_PC_NXC_REGS_WATCH0_SPEC = 0x02010aa0ull;
// proc/reg00050.H

static const uint64_t INT_PC_NXC_REGS_WATCH2_DATA1 = 0x02010ab5ull;
// proc/reg00050.H

static const uint64_t INT_PC_NXC_REGS_WATCH_ASSIGN = 0x02010a86ull;
// proc/reg00050.H

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
// proc/reg00050.H

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
// proc/reg00050.H

static const uint64_t INT_PC_REGS_NVG_BLOCK_MODE = 0x02010a0dull;

static const uint32_t INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE = 0;
static const uint32_t INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE_LEN = 32;
// proc/reg00050.H

static const uint64_t INT_PC_REGS_TCTXT_LSI_SET_01 = 0x02010b25ull;
// proc/reg00050.H

static const uint64_t INT_VC_ENDC_WATCH1_DATA3 = 0x020109afull;
// proc/reg00050.H

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
// proc/reg00050.H

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
// proc/reg00050.H

static const uint64_t INT_VC_RECOV_ERR_G2 = 0x020109d5ull;

static const uint32_t INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR = 0;
static const uint32_t INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR_LEN = 64;
// proc/reg00050.H

static const uint64_t INT_VC_WOF_ERR_G0_DETAIL = 0x020109c3ull;

static const uint32_t INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR = 0;
static const uint32_t INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR_LEN = 64;
// proc/reg00050.H

static const uint64_t MM0_MM_CFG_NMMU_CTL_TLB = 0x02010c55ull;

static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS = 0;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS_LEN = 16;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN = 16;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS = 17;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN = 18;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS = 19;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS = 20;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS = 21;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS = 22;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS = 23;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS = 24;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS = 25;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS = 26;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS = 27;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS = 28;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS = 29;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS = 30;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS = 31;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL = 32;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL_LEN = 4;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL = 36;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL_LEN = 4;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS = 40;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS = 41;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS = 42;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS = 43;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ = 44;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ_LEN = 4;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ = 48;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ_LEN = 4;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS = 52;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN = 53;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS = 54;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS = 55;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA = 56;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA = 57;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA = 58;
static const uint32_t MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA = 59;
// proc/reg00050.H

static const uint64_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE = 0x02010c1dull;

static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL = 0;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN = 12;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL = 12;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN = 4;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL = 16;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN = 12;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL = 28;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN = 4;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE = 32;
// proc/reg00050.H

static const uint64_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG = 0x02010c06ull;

static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 = 0;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN = 20;
// proc/reg00050.H

static const uint64_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG = 0x02010c07ull;

static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 = 0;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN = 20;
// proc/reg00050.H

static const uint64_t MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0 = 0x02010c24ull;

static const uint32_t MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 = 0;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN = 64;
// proc/reg00050.H

static const uint64_t NX_CH4_ADDR_6_HASH_FUNCTION_REG = 0x02011147ull;

static const uint32_t NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION_LEN = 64;
// proc/reg00050.H

static const uint64_t NX_CH4_DATATAG_2_HASH_FUNCTION_REG = 0x0201114eull;

static const uint32_t NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION_LEN = 64;
// proc/reg00050.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR = 0x0201108dull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_LEN = 44;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE = 52;
// proc/reg00050.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG = 0x02011090ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL = 0;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL_LEN = 8;
// proc/reg00050.H

static const uint64_t NX_PBI_RNG_ST3 = 0x020110e8ull;

static const uint32_t NX_PBI_RNG_ST3_RRN_ENABLE = 0;
static const uint32_t NX_PBI_RNG_ST3_WINDOW_SIZE = 1;
static const uint32_t NX_PBI_RNG_ST3_WINDOW_SIZE_LEN = 3;
static const uint32_t NX_PBI_RNG_ST3_MATCH_TH_MIN = 4;
static const uint32_t NX_PBI_RNG_ST3_MATCH_TH_MIN_LEN = 16;
static const uint32_t NX_PBI_RNG_ST3_MATCH_TH_MAX = 20;
static const uint32_t NX_PBI_RNG_ST3_MATCH_TH_MAX_LEN = 16;
// proc/reg00050.H

static const uint64_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL = 0x020110ccull;

static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET = 4;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN = 8;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED = 15;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN = 9;
// proc/reg00050.H

static const uint64_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB = 0x020110c8ull;

static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID = 4;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN = 12;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID = 20;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID_LEN = 20;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID = 44;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID_LEN = 16;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE = 63;
// proc/reg00050.H

static const uint64_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR = 0x020110cbull;

static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR = 8;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_LEN = 46;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE = 54;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN = 3;
// proc/reg00050.H

static const uint64_t PB_COM_ES3_HP_MODE1_CURR = 0x0000038cull;

static const uint32_t PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3 = 0;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3 = 1;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3 = 2;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3 = 3;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3 = 16;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3 = 17;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3 = 18;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3 = 32;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3 = 33;
static const uint32_t PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3 = 34;
// proc/reg00050.H

static const uint64_t PB_PTLSCOM10_DOB23_DIB23_INT_ERR_REG = 0x1001182aull;
// proc/reg00050.H

static const uint64_t PB_PTLSCOM10_MAILBOX_20_REG = 0x10011834ull;
// proc/reg00050.H

static const uint64_t PB_PTLSCOM10_MAILBOX_21_REG = 0x10011835ull;
// proc/reg00050.H

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
// proc/reg00050.H

static const uint64_t PB_PTLSCOM10_PMU3_CNPM_COUNTER = 0x10011824ull;
// proc/reg00050.H

static const uint64_t PB_PTLSCOM10_PSAVE23_MODE_CFG = 0x10011816ull;

static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE = 0;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE = 5;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN = 8;
// proc/reg00050.H

static const uint64_t PB_PTLSCOM10_TL_LINK_SYN_01_REG = 0x10011812ull;
// proc/reg00050.H

static const uint64_t PB_PTLSCOM23_DOB01_DIB01_INT_ERR_REG = 0x11011828ull;
// proc/reg00050.H

static const uint64_t PB_PTLSCOM23_PMU1_CNPM_COUNTER = 0x11011822ull;
// proc/reg00050.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint64_t PB_PTLSCOM23_PTL_FIR_REG_RWX = 0x11011800ull;
static const uint64_t PB_PTLSCOM23_PTL_FIR_REG_WOX_AND = 0x00000001ull;
static const uint64_t PB_PTLSCOM23_PTL_FIR_REG_WOX_OR = 0x00000002ull;

static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED = 0;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED = 1;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED = 2;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED = 3;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE = 8;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE = 9;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE = 10;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE = 11;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE = 12;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE = 13;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN = 20;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN = 21;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN = 22;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN = 23;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN = 28;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN = 29;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN = 30;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN = 31;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN = 36;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN = 37;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN = 38;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN = 39;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN = 40;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN = 41;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN = 42;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN = 43;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR = 52;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR = 53;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR = 56;
static const uint32_t PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR = 57;
// proc/reg00050.H

static const uint64_t PB_PTLSCOM45_MAILBOX_30_REG = 0x12011836ull;
// proc/reg00050.H

static const uint64_t PB_PTLSCOM45_MAILBOX_31_REG = 0x12011837ull;
// proc/reg00050.H

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
// proc/reg00050.H

static const uint64_t PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG = 0x03012410ull;

static const uint32_t PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER = 13;
static const uint32_t PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER_LEN = 30;
// proc/reg00050.H

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
// proc/reg00050.H

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
// proc/reg00050.H

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
// proc/reg00050.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_0_PFIRWOF_REG = 0x08010848ull;
// proc/reg00050.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_RWX = 0x08010880ull;
static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_AND = 0x08010881ull;
static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_OR = 0x08010882ull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR_LEN = 6;
// proc/reg00050.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG = 0x02011803ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE = 16;
// proc/reg00050.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG0 = 0x0201180cull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG0_PE_TOPOLOGY_ID_REG0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG0_PE_TOPOLOGY_ID_REG0_LEN = 40;
// proc/reg00051.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT0_REG = 0x0201188aull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT0_REG_CERR_RPT0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT0_REG_CERR_RPT0_LEN = 64;
// proc/reg00051.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT1_REG = 0x0201188bull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT1_REG_CERR_RPT1 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT1_REG_CERR_RPT1_LEN = 41;
// proc/reg00051.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_CQSTAT_REG = 0x0201188cull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_CQSTAT_REG_INBOUND_ACTIVE = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_CQSTAT_REG_OUTBOUND_ACTIVE = 1;
// proc/reg00051.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PHBBAR_REG = 0x02011892ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PHBBAR_REG_PE_PHB_BAR = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PHBBAR_REG_PE_PHB_BAR_LEN = 42;
// proc/reg00051.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_INTBAR_REG = 0x020118d3ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_INTBAR_REG_PE_INT_BAR = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_INTBAR_REG_PE_INT_BAR_LEN = 28;
// proc/reg00051.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIR_REG_RWX = 0x020118c0ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIR_REG_WOX_AND = 0x020118c1ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIR_REG_WOX_OR = 0x020118c2ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIR_REG_NFIRNFIR = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIR_REG_NFIRNFIR_LEN = 28;
// proc/reg00051.H

static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_WOF_REG = 0x08010910ull;
// proc/reg00051.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_WOF_REG = 0x00000950ull;
// proc/reg00051.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_1_RESERVED1_REG = 0x0901088cull;
// proc/reg00051.H

static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_PHB5_PMON_CONFIG = 0x09010957ull;
// proc/reg00051.H

static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL = 0x09010958ull;
// proc/reg00051.H

static const uint64_t TP_TPBR_AD_TOD_DATA_SND_REG = 0x03001c28ull;

static const uint32_t TP_TPBR_AD_TOD_DATA_SND_REG_PCB_TOD_DATA_SND = 0;
static const uint32_t TP_TPBR_AD_TOD_DATA_SND_REG_PCB_TOD_DATA_SND_LEN = 64;
// proc/reg00051.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAFCFG = 0x03021ccbull;

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
// proc/reg00051.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAPBOCR3 = 0x03021cd7ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR3_EVENT = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR3_EVENT_LEN = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR3_ACCUM = 44;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR3_ACCUM_LEN = 20;
// proc/reg00051.H

static const uint64_t TP_TPBR_PBA_PBAO_BCUE_SET = 0x00068016ull;

static const uint32_t TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH_LEN = 6;
// proc/reg00051.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAFIR_RWX = 0x03021c80ull;
static const uint64_t TP_TPBR_PBA_PBAO_PBAFIR_WOX_AND = 0x03021c81ull;
static const uint64_t TP_TPBR_PBA_PBAO_PBAFIR_WOX_OR = 0x03021c82ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_RDADRERR_FW = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_RDDATATO_FW = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_SUE_FW = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_UE_FW = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_CE_FW = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_8 = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_UNEXPCRESP = 9;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_UNEXPDATA = 10;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_PARITY_ERR = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_WRADRERR_FW = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_BADCRESP = 13;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_ACKDEAD_FW_RD = 14;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_OPERTO = 15;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCUE_PB_ACK_DEAD = 17;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCUE_PB_ADRERR = 18;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR = 19;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR = 20;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCDE_PB_ACK_DEAD = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCDE_PB_ADRERR = 22;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCDE_RDDATATO_ERR = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SUE_ERR = 24;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCDE_UE_ERR = 25;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCDE_CE = 26;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR = 27;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_ILLEGAL_CACHE_OP = 29;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR = 30;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR = 31;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXRCV_DLO_ERR = 32;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXRCV_DLO_TO = 33;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXRCV_RSVDATA_TO = 34;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR = 35;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXSND_DHI_RTYTO = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXSND_DLO_RTYTO = 37;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVTO = 38;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR = 39;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_PB_ACKDEAD_FW_WR = 40;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_41 = 41;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_42 = 42;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_43 = 43;
// proc/reg00051.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAFIRACT1 = 0x03021c87ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1_LEN = 44;
// proc/reg00051.H

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
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_DIS_CHGRATE_COUNT = 50;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_PBREQ_EVENT_MUX = 51;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_PBREQ_EVENT_MUX_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_53_63 = 53;
static const uint32_t TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_53_63_LEN = 11;
// proc/reg00051.H

static const uint64_t TP_TPBR_PSI_WRAP_RX_DF_FSM_REG = 0x03011c0eull;
// proc/reg00051.H

static const uint64_t TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG = 0x03011c10ull;
// proc/reg00051.H

static const uint64_t TP_TPBR_PSIHB_FIR_REG_RWX = 0x03011d00ull;
static const uint64_t TP_TPBR_PSIHB_FIR_REG_WOX_AND = 0x03011d01ull;
static const uint64_t TP_TPBR_PSIHB_FIR_REG_WOX_OR = 0x03011d02ull;

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
// proc/reg00051.H

static const uint64_t TP_TPBR_PSIHB_INTERRUPT_STATUS = 0x03011d1aull;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR13 = 0x0006004bull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR13_OCB_OCI_GPEXIVDRX_GPR13 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR13_OCB_OCI_GPEXIVDRX_GPR13_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR4 = 0x00060044ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIAR = 0x00060025ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR_LEN = 30;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL = 0x0006002dull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_SIB_PIB_IFETCH_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_MEM_IFETCH_PENDING = 3;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU = 0x0006002cull;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIEDR = 0x00062023ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIEDR_OCB_OCI_GPEXIRAMEDR_EDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIEDR_OCB_OCI_GPEXIRAMEDR_EDR_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL = 0x00062027ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_R_NW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_BUSY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_RSP_INFO = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_RSP_INFO_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_IFETCH_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBL_DATAOP_PENDING = 31;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBU = 0x00062026ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR = 0x00064001ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN = 23;
// proc/reg00051.H

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
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXICTR = 0x00066032ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXICTR_OCB_OCI_GPEXICTR_CTR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXICTR_OCB_OCI_GPEXICTR_CTR_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGINF = 0x0006601full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGINF_SRR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGINF_SRR0_LEN = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGINF_LR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGINF_LR_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR0 = 0x00066040ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR10 = 0x0006604aull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR10_OCB_OCI_GPEXIVDRX_GPR10 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR10_OCB_OCI_GPEXIVDRX_GPR10_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1 = 0x0006c821ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7 = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7_LEN = 16;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SRD1B = 0x0006c739ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0 = 0x0006c20cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE_LEN = 7;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW = 0x0006c0afull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR = 0x0006c0b0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR = 0x0006c0b1ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW = 0x0006c048ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR = 0x0006c049ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR = 0x0006c04aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C_LEN = 32;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q6 = 0x0006c406ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q6_OCB_OCI_OPIT0Q6RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q6_OCB_OCI_OPIT0Q6RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q2 = 0x0006c41aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q2_OCB_OCI_OPIT3Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q2_OCB_OCI_OPIT3Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4 = 0x0006c424ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4_OCB_OCI_OPIT4Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q4_OCB_OCI_OPIT4Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_ROX = 0x0006c628ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_WOX_CLEAR = 0x0006c629ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5PRA_7 = 7;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q0 = 0x0006c438ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q0_OCB_OCI_OPIT7Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q0_OCB_OCI_OPIT7Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C10RR = 0x0006c54aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C10RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C10RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C10RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C10RR_PAYLOAD_LEN = 17;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13 = 0x0006c44dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13_PAYLOAD_LEN = 17;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C22RR = 0x0006c556ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C22RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C22RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C22RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C22RR_PAYLOAD_LEN = 17;
// proc/reg00051.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24 = 0x0006c458ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C24_PAYLOAD_LEN = 17;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15 = 0x0006c46full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C15_PAYLOAD_LEN = 17;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17RR = 0x0006c571ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17RR_PAYLOAD_LEN = 17;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C22 = 0x0006c476ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C22_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C22_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C22_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C22_PAYLOAD_LEN = 17;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C25RR = 0x0006c579ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C25RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C25RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C25RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C25RR_PAYLOAD_LEN = 17;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4 = 0x0006c464ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4_PAYLOAD_LEN = 17;
// proc/reg00052.H

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
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OTR0 = 0x0006c100ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0_LEN = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0_LEN = 16;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_100NS = 0x0006c828ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS_LEN = 32;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_CMD = 0x0006c844ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND = 0;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR = 0x0006d110ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_TRACE_BUS_EN = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_OCB_TRACE_MUX_SEL = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_OCC_TRACE_MUX_SEL = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_OCC_TRACE_MUX_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_OCI_TRACE_MUX_SEL = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OTDCR_OCI_TRACE_MUX_SEL_LEN = 4;
// proc/reg00052.H

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
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG102 = 0x00008066ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG102_REGISTER102 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG102_REGISTER102_LEN = 64;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG35 = 0x00008023ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG35_REGISTER35 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG35_REGISTER35_LEN = 64;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG54 = 0x00008036ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG54_REGISTER54 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG54_REGISTER54_LEN = 64;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG63 = 0x0000803full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG63_REGISTER63 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG63_REGISTER63_LEN = 64;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG89 = 0x00008059ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG89_REGISTER89 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG89_REGISTER89_LEN = 64;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG9 = 0x00008009ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG9_REGISTER9 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG9_REGISTER9_LEN = 64;
// proc/reg00052.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG96 = 0x00008060ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG96_REGISTER96 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG96_REGISTER96_LEN = 64;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_SET_PIB_RESET_WOX_1P = 0x00001007ull;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_STATUS_ROX = 0x00001007ull;

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
// proc/reg00052.H

static const uint64_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A = 0x00001805ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_INVALID_CMD_000 = 16;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_LBUS_PARITY_ERROR_000 = 17;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_BE_OV_ERROR_000 = 18;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_BE_ACC_ERROR_000 = 19;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_ARBITRATION_LOST_ERROR_000 = 20;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_NACK_RECEIVED_ERROR_000 = 21;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_DATA_REQUEST_000 = 22;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_COND_A_STOP_ERROR_000 = 24;
// proc/reg00052.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_10_RWX = 0x0000284aull;
// proc/reg00052.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RWX = 0x00002842ull;
// proc/reg00052.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RWX = 0x00002888ull;
// proc/reg00052.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_14_RWX = 0x000028ceull;
// proc/reg00052.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RWX = 0x00002904ull;
// proc/reg00052.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_WO_CLEAR = 0x0000293aull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_CHIPLET_EN_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_PCB_EP_RESET_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_CLK_ASYNC_RESET_DC = 2;
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
// proc/reg00052.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR = 0x0000292aull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_CHIPLET_EN_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_PCB_EP_RESET_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_CLK_ASYNC_RESET_DC = 2;
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
// proc/reg00052.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_SET_WO_OR = 0x0000292bull;

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
// proc/reg00052.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_WO_CLEAR = 0x00002932ull;

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
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TPFSI_TC_HSSPORWREN_ALLOW = 20;
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
// proc/reg00052.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_RWX = 0x0000283dull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_SR_SCRATCH_REGISTER_6 = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_SR_SCRATCH_REGISTER_6_LEN = 32;
// proc/reg00052.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_DATA_IN = 0x000b0010ull;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_MTC_RWX = 0x00002416ull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_MTC_DNFIFO_MCT = 0;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_MTC_DNFIFO_MCT_LEN = 32;
// proc/reg00052.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_ACK_EOT = 0x000b0005ull;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_SIG_EOT_WOX = 0x00002402ull;
// proc/reg00052.H

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
// proc/reg00052.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_LSTAT = 0x00030002ull;
// proc/reg00052.H

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
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_LLMOD = 0x00000900ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_LLMOD_FSI_A_ASYNC_MODE = 31;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_ROX = 0x000031d0ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FIRST_ERROR = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FIRST_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST = 17;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_ACTUAL_ERROR = 20;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_ACTUAL_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT = 29;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN = 3;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP6_WOX = 0x000030e8ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP6_GENERAL_RESET_6 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP6_ERROR_RESET_6 = 1;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP5_FSI0 = 0x00003044ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP5_SCOMFSI0 = 0x00000c11ull;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP4_FSI0 = 0x00003460ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP4_SCOMFSI0 = 0x00000d18ull;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MREFP0_ROX = 0x00003420ull;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_RO = 0x000034e4ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP5_2_LEN = 3;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCISM = 0x00000814ull;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SISM = 0x0000080cull;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP2_FSI1 = 0x00003058ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP2_SCOMFSI1 = 0x00000c16ull;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MECTRL_FSI1 = 0x000032e0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MECTRL_SCOMFSI1 = 0x00000cb8ull;
// proc/reg00052.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MLEVP1_ROX = 0x0000301cull;
// proc/reg00053.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_RO = 0x000030dcull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP3_2_LEN = 3;
// proc/reg00053.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCRSIC4 = 0x00000854ull;
// proc/reg00053.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SDATA = 0x00000830ull;
// proc/reg00053.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SRSIS0 = 0x00000878ull;
// proc/reg00053.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4AC = 0x000004acull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4AC_6_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4AC_7_ENABLE = 4;
// proc/reg00053.H

static const uint64_t VAS_VA_EG_SCF_PGMIG4 = 0x02011444ull;
// proc/reg00053.H

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
// proc/reg00053.H

}
}
#include "proc/reg00050.H"
#include "proc/reg00051.H"
#include "proc/reg00052.H"
#include "proc/reg00053.H"
#endif
