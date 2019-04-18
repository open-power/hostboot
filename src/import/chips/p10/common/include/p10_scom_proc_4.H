/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_4.H $       */
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

#ifndef __p10_scom_proc_4_H_
#define __p10_scom_proc_4_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_END_BAR = 0x0201080bull;

static const uint32_t INT_CQ_END_BAR_VALID = 0;
static const uint32_t INT_CQ_END_BAR_PAGE_SIZE_64K = 1;
static const uint32_t INT_CQ_END_BAR_ADDR_8_39 = 8;
static const uint32_t INT_CQ_END_BAR_ADDR_8_39_LEN = 32;
static const uint32_t INT_CQ_END_BAR_SET_DIV_SEL_0_2 = 56;
static const uint32_t INT_CQ_END_BAR_SET_DIV_SEL_0_2_LEN = 3;
static const uint32_t INT_CQ_END_BAR_RANGE_0_4 = 59;
static const uint32_t INT_CQ_END_BAR_RANGE_0_4_LEN = 5;
// proc/reg00256.H

static const uint64_t INT_CQ_PMC_1 = 0x02010829ull;

static const uint32_t INT_CQ_PMC_1_INT_CQ_PMC_1_COUNT_0_47 = 16;
static const uint32_t INT_CQ_PMC_1_INT_CQ_PMC_1_COUNT_0_47_LEN = 48;
// proc/reg00256.H

static const uint64_t INT_CQ_TTT_1 = 0x02010805ull;

static const uint32_t INT_CQ_TTT_1_VALID_0_7 = 0;
static const uint32_t INT_CQ_TTT_1_VALID_0_7_LEN = 8;
static const uint32_t INT_CQ_TTT_1_ENTRY_0_3 = 8;
static const uint32_t INT_CQ_TTT_1_ENTRY_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_1_ENTRY_1_0_3 = 12;
static const uint32_t INT_CQ_TTT_1_ENTRY_1_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_1_ENTRY_2_0_3 = 16;
static const uint32_t INT_CQ_TTT_1_ENTRY_2_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_1_ENTRY_3_0 = 20;
static const uint32_t INT_CQ_TTT_1_ENTRY_3_0_LEN = 4;
static const uint32_t INT_CQ_TTT_1_ENTRY_4_0_3 = 24;
static const uint32_t INT_CQ_TTT_1_ENTRY_4_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_1_ENTRY_5_0_3 = 28;
static const uint32_t INT_CQ_TTT_1_ENTRY_5_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_1_ENTRY_6_0_3 = 32;
static const uint32_t INT_CQ_TTT_1_ENTRY_6_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_1_ENTRY_7_0_3 = 36;
static const uint32_t INT_CQ_TTT_1_ENTRY_7_0_3_LEN = 4;
// proc/reg00256.H

static const uint64_t INT_PC_NXC_REGS_SYNC_DONE = 0x02010a84ull;
// proc/reg00256.H

static const uint64_t INT_PC_NXC_REGS_WATCH0_DATA1 = 0x02010aa5ull;
// proc/reg00256.H

static const uint64_t INT_PC_NXC_REGS_WOF_ERR_DETAIL = 0x02010ad3ull;

static const uint32_t INT_PC_NXC_REGS_WOF_ERR_DETAIL_INT_PC_NXC_WOF_ERR_DETAIL_ERROR = 0;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_DETAIL_INT_PC_NXC_WOF_ERR_DETAIL_ERROR_LEN = 64;
// proc/reg00256.H

static const uint64_t INT_PC_REGS_TCTXT_CFG = 0x02010b28ull;

static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_0 = 0;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_TARGET_EN = 1;
static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_2_3 = 2;
static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_2_3_LEN = 2;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN = 4;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_LINUX_MODE = 5;
static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_6_11 = 6;
static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_6_11_LEN = 6;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS = 12;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS = 13;
static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_14_16 = 14;
static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_14_16_LEN = 3;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS = 17;
static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_18_19 = 18;
static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_18_19_LEN = 2;
static const uint32_t INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE = 20;
static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_21_24 = 21;
static const uint32_t INT_PC_REGS_TCTXT_CFG_RESERVED_21_24_LEN = 4;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS = 25;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS_LEN = 3;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO = 28;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO_LEN = 2;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE = 30;
static const uint32_t INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE_LEN = 2;
// proc/reg00256.H

static const uint64_t INT_VC_EASC_PERF_EVENT_SEL_1 = 0x02010978ull;

static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_IPI_DOES_PRF = 0;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_IPI_DOES_PRF_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_HWD_DOES_PRF = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_HWD_DOES_PRF_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_NXC_DOES_PRF = 8;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_NXC_DOES_PRF_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_INT_DOES_PRF = 12;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_INT_DOES_PRF_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_OS_DOES_PRF = 16;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_OS_DOES_PRF_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_POOL_DOES_PRF = 20;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_POOL_DOES_PRF_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_HARD_DOES_PRF = 24;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_HARD_DOES_PRF_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_LOC_DOES_PRF = 28;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_LOC_DOES_PRF_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_IPI_DOES_DEM = 32;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_IPI_DOES_DEM_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_HWD_DOES_DEM = 36;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_HWD_DOES_DEM_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_NXC_DOES_DEM = 40;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_NXC_DOES_DEM_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_INT_DOES_DEM = 44;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_INT_DOES_DEM_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_OS_DOES_DEM = 48;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_OS_DOES_DEM_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_POOL_DOES_DEM = 52;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_POOL_DOES_DEM_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_HARD_DOES_DEM = 56;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_HARD_DOES_DEM_LEN = 4;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_LOC_DOES_DEM = 60;
static const uint32_t INT_VC_EASC_PERF_EVENT_SEL_1_LOC_DOES_DEM_LEN = 4;
// proc/reg00256.H

static const uint64_t INT_VC_ENDC_FLUSH_CTRL = 0x02010980ull;

static const uint32_t INT_VC_ENDC_FLUSH_CTRL_POLL_VALID = 0;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 = 1;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE = 2;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE = 3;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6 = 4;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6_LEN = 3;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE = 7;
// proc/reg00256.H

static const uint64_t INT_VC_ENDC_PERF_EVENT_SEL_1 = 0x02010998ull;

static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_EQ_TRIGGER = 0;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_EQ_TRIGGER_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_EVT_TRIG_ESN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_EVT_TRIG_ESN_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_EVT_TRIG_RDI = 8;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_EVT_TRIG_RDI_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_EVT_TRIG_ESE = 12;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_EVT_TRIG_ESE_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_STR_EOI_ESN = 16;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_STR_EOI_ESN_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_STR_EOI_ESE = 20;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_STR_EOI_ESE_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_EQ_INJECT = 24;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_EQ_INJECT_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_SETPQ_ESN = 28;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_SETPQ_ESN_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_SETPQ_ESE = 32;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_SETPQ_ESE_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_IPI = 36;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_IPI_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_HWD = 40;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_HWD_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_NXC = 44;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_NXC_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_INT = 48;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_INT_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_OS = 52;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_OS_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_POOL = 56;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_POOL_LEN = 4;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_HARD = 60;
static const uint32_t INT_VC_ENDC_PERF_EVENT_SEL_1_CMD_FROM_HARD_LEN = 4;
// proc/reg00256.H

static const uint64_t INT_VC_ENDC_WATCH3_DATA3 = 0x020109bfull;
// proc/reg00256.H

static const uint64_t INT_VC_ENDC_WATCH3_SPEC = 0x020109b8ull;

static const uint32_t INT_VC_ENDC_WATCH3_SPEC_CONFLICT = 0;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_RESERVED_1_7 = 1;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_RESERVED_1_7_LEN = 7;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_FULL = 8;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_RESERVED_9_27 = 9;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_RESERVED_9_27_LEN = 19;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_BLOCKID = 28;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_BLOCKID_LEN = 4;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_RESERVED_32_39 = 32;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_RESERVED_32_39_LEN = 8;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_OFFSET = 40;
static const uint32_t INT_VC_ENDC_WATCH3_SPEC_OFFSET_LEN = 24;
// proc/reg00256.H

static const uint64_t INT_VC_ESBC_DBG_CACHE_EN = 0x02010955ull;

static const uint32_t INT_VC_ESBC_DBG_CACHE_EN_INT_VC_ESBC_DBG_CACHE_EN_ENABLE = 0;
static const uint32_t INT_VC_ESBC_DBG_CACHE_EN_INT_VC_ESBC_DBG_CACHE_EN_ENABLE_LEN = 16;
// proc/reg00256.H

static const uint64_t INT_VC_QUEUES_CFG_REM_6 = 0x0201091dull;

static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_DISABLE = 0;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_DROP_EQ_INJECT_FROM_CORE = 1;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_PREFETCH_DISTANCE = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_PREFETCH_DISTANCE_LEN = 6;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_8_10 = 8;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_8_10_LEN = 3;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_MAX_CRD_TO_CQ = 11;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_MAX_CRD_TO_CQ_LEN = 5;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_16_18 = 16;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_16_18_LEN = 3;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_MAX_CRD_TO_PC = 19;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_MAX_CRD_TO_PC_LEN = 5;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_MAX_NB_OUTSTANDING_DEM = 24;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_MAX_NB_OUTSTANDING_DEM_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_MIN_NB_OUTSTANDING_DEM = 28;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_MIN_NB_OUTSTANDING_DEM_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_32_33 = 32;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_32_33_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_FULL = 34;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_IRQ_IDLE = 35;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_36_37 = 36;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_36_37_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_ERQ_ENABLE_MEMORY_BACKING = 38;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_ERQ_FULL_WRITEBACK_ENABLE = 39;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_40_41 = 40;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_40_41_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_ERQ_MEM_SIZE = 42;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_ERQ_MEM_SIZE_LEN = 6;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_48_49 = 48;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_RESERVED_48_49_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_ERQ_FULL = 50;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_ERQ_IDLE = 51;
static const uint32_t INT_VC_QUEUES_CFG_REM_6_ERQ_CFG_UPD_PND = 52;
// proc/reg00256.H

static const uint64_t INT_VC_QUEUES_PERF_EVENT_SEL_5 = 0x0201092bull;

static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_FROM_AIB = 0;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_FROM_AIB_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_IRQ_TO_IQA = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_IRQ_TO_IQA_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_IQA_TO_DPS = 8;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_IQA_TO_DPS_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_IQA_TO_IQS = 12;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_IQA_TO_IQS_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_IQS_TO_EQA = 16;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_IQS_TO_EQA_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_EQA_TO_ERQ = 20;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_EQA_TO_ERQ_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_EQA_TO_ATX = 24;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_EQA_TO_ATX_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_EQA_TO_ENDC = 28;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_5_EQA_TO_ENDC_LEN = 4;
// proc/reg00256.H

static const uint64_t INT_VC_VSD_TABLE_DATA = 0x02010901ull;
// proc/reg00256.H

static const uint64_t MM0_MM_NMMU_PMU0_CTL_REG = 0x02010c4dull;

static const uint32_t MM0_MM_NMMU_PMU0_CTL_REG_MM_PMU0_CTL = 0;
static const uint32_t MM0_MM_NMMU_PMU0_CTL_REG_MM_PMU0_CTL_LEN = 64;
// proc/reg00256.H

static const uint64_t MM1_MM_CFG_NMMU_XLAT_CTL_REG1 = 0x03010c4bull;

static const uint32_t MM1_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR = 0;
static const uint32_t MM1_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR_LEN = 64;
// proc/reg00256.H

static const uint64_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG = 0x03010c16ull;

static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG = 0;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG_LEN = 32;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN = 32;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN_LEN = 6;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK = 38;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK_LEN = 3;
// proc/reg00256.H

static const uint64_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RWX = 0x03010c00ull;
static const uint64_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WOX_AND = 0x03010c01ull;
static const uint64_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WOX_OR = 0x03010c02ull;

static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR = 0;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR = 1;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR = 2;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR = 3;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR = 4;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR = 5;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR = 6;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR = 7;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR = 8;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR = 9;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR = 10;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR = 11;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR = 12;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR = 13;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR = 14;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR = 15;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR = 16;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR = 17;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR = 18;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR = 19;
// proc/reg00256.H

static const uint64_t MM1_MM_NMMU_PMU0_CTL_REG = 0x03010c4dull;

static const uint32_t MM1_MM_NMMU_PMU0_CTL_REG_MM_PMU0_CTL = 0;
static const uint32_t MM1_MM_NMMU_PMU0_CTL_REG_MM_PMU0_CTL_LEN = 64;
// proc/reg00256.H

static const uint64_t NX_CH4_ADDR_5_HASH_FUNCTION_REG = 0x02011146ull;

static const uint32_t NX_CH4_ADDR_5_HASH_FUNCTION_REG_ADDRESS_5_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_5_HASH_FUNCTION_REG_ADDRESS_5_HASH_FUNCTION_LEN = 64;
// proc/reg00256.H

static const uint64_t NX_CH4_DATATAG_1_HASH_FUNCTION_REG = 0x0201114dull;

static const uint32_t NX_CH4_DATATAG_1_HASH_FUNCTION_REG_DATATAG_1_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_DATATAG_1_HASH_FUNCTION_REG_DATATAG_1_HASH_FUNCTION_LEN = 64;
// proc/reg00256.H

static const uint64_t NX_DBG_ERRORINJ_CTRL = 0x0201110cull;

static const uint32_t NX_DBG_ERRORINJ_CTRL_CH0EFT_ERRORINJ_ENA = 2;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH0EFT_ERRORINJ_TYPE = 3;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH0EFT_ERRORINJ_ACTION = 4;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH0EFT_ERRORINJ_SELECT = 5;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH0EFT_ERRORINJ_SELECT_LEN = 4;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH1EFT_ERRORINJ_ENA = 9;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH1EFT_ERRORINJ_TYPE = 10;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH1EFT_ERRORINJ_ACTION = 11;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH1EFT_ERRORINJ_SELECT = 12;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH1EFT_ERRORINJ_SELECT_LEN = 4;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_INWR_ERRORINJ_ENA = 23;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_INWR_ERRORINJ_TYPE = 24;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_INWR_ERRORINJ_ACTION = 25;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_OUTWR_ERRORINJ_ENA = 26;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_OUTWR_ERRORINJ_TYPE = 27;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_OUTWR_ERRORINJ_ACTION = 28;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_INGARRAY_ERRORINJ_ENA = 29;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_INGARRAY_ERRORINJ_TYPE = 30;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_INGARRAY_ERRORINJ_ACTION = 31;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_INGARRAY_ERRORINJ_SELECT = 32;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_INGARRAY_ERRORINJ_SELECT_LEN = 4;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_EGRARRAY_ERRORINJ_ENA = 36;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_EGRARRAY_ERRORINJ_TYPE = 37;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_EGRARRAY_ERRORINJ_ACTION = 38;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_EGRARRAY_ERRORINJ_SELECT = 39;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_EGRARRAY_ERRORINJ_SELECT_LEN = 4;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_CRBARRAY_ERRORINJ_ENA = 43;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_CRBARRAY_ERRORINJ_TYPE = 44;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_CRBARRAY_ERRORINJ_ACTION = 45;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_CRBARRAY_ERRORINJ_SELECT = 46;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH4GZIP_ERRORINJ_ENA = 48;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH4GZIP_ERRORINJ_TYPE = 49;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH4GZIP_ERRORINJ_ACTION = 50;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH4GZIP_ERRORINJ_SELECT = 51;
static const uint32_t NX_DBG_ERRORINJ_CTRL_CH4GZIP_ERRORINJ_SELECT_LEN = 8;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_OUTWR_QW0_UEINJ_ENA = 59;
static const uint32_t NX_DBG_ERRORINJ_CTRL_DMA_OUTWR_QW4_UEINJ_ENA = 60;
// proc/reg00256.H

static const uint64_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL = 0x0201105cull;

static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH0_WATCHDOG_TIMER_ENBL = 0;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH0_WATCHDOG_REF_DIV = 1;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH0_WATCHDOG_REF_DIV_LEN = 4;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH1_WATCHDOG_TIMER_ENBL = 5;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH1_WATCHDOG_REF_DIV = 6;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH1_WATCHDOG_REF_DIV_LEN = 4;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH2_WATCHDOG_TIMER_ENBL = 10;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH2_WATCHDOG_REF_DIV = 11;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH2_WATCHDOG_REF_DIV_LEN = 4;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH3_WATCHDOG_TIMER_ENBL = 15;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH3_WATCHDOG_REF_DIV = 16;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH3_WATCHDOG_REF_DIV_LEN = 4;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH4_WATCHDOG_TIMER_ENBL = 20;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH4_WATCHDOG_REF_DIV = 21;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_CH4_WATCHDOG_REF_DIV_LEN = 4;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_DMA_HANG_TIMER_ENBL = 25;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_DMA_HANG_TIMER_REF_DIV = 26;
static const uint32_t NX_DMA_WATCHDOG_HANG_TIMERS_CNTL_DMA_HANG_TIMER_REF_DIV_LEN = 4;
// proc/reg00256.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_WOF_REG = 0x02011088ull;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM10_CFG_TLPM_REG = 0x1001181aull;

static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_EN = 0;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_RESET_MODE = 1;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_COUNTER_MODE = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_GLOBAL_PMISC_DIS = 3;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_GLOBAL_PMISC_MODE = 4;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_EXTERNAL_FREEZE = 5;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_0_1_OP = 6;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_0_1_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_2_3_OP = 8;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_2_3_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_4_5_OP = 10;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_4_5_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_6_7_OP = 12;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_6_7_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_8_9_OP = 14;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_8_9_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_10_11_OP = 16;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_10_11_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_12_13_OP = 18;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_12_13_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_14_15_OP = 20;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_14_15_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_16_17_OP = 22;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_16_17_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_18_19_OP = 24;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_18_19_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_20_21_OP = 26;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_20_21_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_22_23_OP = 28;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_22_23_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_24_25_OP = 30;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_24_25_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_26_27_OP = 32;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_26_27_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_28_29_OP = 34;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_28_29_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_30_31_OP = 36;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_30_31_OP_LEN = 2;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_CASCADE_PMU0 = 38;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_CASCADE_PMU0_LEN = 3;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_CASCADE_PMU1 = 41;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_CASCADE_PMU1_LEN = 3;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_CASCADE_PMU2 = 44;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_CASCADE_PMU2_LEN = 3;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_CASCADE_PMU3 = 47;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_CASCADE_PMU3_LEN = 3;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_SPARE = 50;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_REG_SPARE_LEN = 6;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM10_FP23_CFG = 0x1001180bull;

static const uint32_t PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 = 0;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING = 1;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION = 2;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION = 3;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_LO_LIMIT = 4;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_PS_LIMIT = 12;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP = 20;
static const uint32_t PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME = 21;
static const uint32_t PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME_LEN = 3;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR = 24;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST = 25;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE = 26;
static const uint32_t PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE_LEN = 6;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 = 32;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING = 33;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION = 34;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION = 35;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_LO_LIMIT = 36;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_PS_LIMIT = 44;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP = 52;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE = 53;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR = 56;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST = 57;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE = 58;
static const uint32_t PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE_LEN = 6;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM10_PMU0_TLPM_COUNTER = 0x1001181bull;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM10_PSAVE23_MISC_CFG = 0x10011817ull;

static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_HALF_LUC = 0;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_HALF_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_HALF_HUC = 8;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_HALF_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_HALF_LUT = 16;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_HALF_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_HALF_HUT = 21;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_HALF_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_HALF_SPARE = 26;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_HALF_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_QTR_LUC = 28;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_QTR_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_QTR_HUC = 36;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_QTR_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_QTR_LUT = 44;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_QTR_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_QTR_HUT = 49;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_QTR_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_QTR_SPARE = 54;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_QTR_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_WSIZE = 56;
static const uint32_t PB_PTLSCOM10_PSAVE23_MISC_CFG_WSIZE_LEN = 3;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM23_MAILBOX_CTL_REG = 0x1101182eull;

static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_VALID = 0;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_WR_NOT_RD = 1;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_BAD_ADDR = 2;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_LINK_DOWN = 3;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_CORRUPT = 4;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_SENT = 5;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_BAD_WRITE = 6;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_RESET = 7;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_AILBOX_ID = 8;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_LINK_ID = 9;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_LINK_ID_LEN = 3;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_SPARE = 12;
static const uint32_t PB_PTLSCOM23_MAILBOX_CTL_REG_B_SPARE_LEN = 4;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM23_PMU2_TLPM_COUNTER = 0x1101181dull;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM45_CFG_CNPM_REG = 0x1201181full;

static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_EN = 0;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_RESET_MODE = 1;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_COUNTER_MODE = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_GLOBAL_PMISC_DIS = 3;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_GLOBAL_PMISC_MODE = 4;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_EXTERNAL_FREEZE = 5;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_0_1_OP = 6;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_0_1_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_2_3_OP = 8;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_2_3_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_4_5_OP = 10;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_4_5_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_6_7_OP = 12;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_6_7_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_8_9_OP = 14;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_8_9_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_10_11_OP = 16;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_10_11_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_12_13_OP = 18;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_12_13_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_14_15_OP = 20;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_14_15_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_16_17_OP = 22;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_16_17_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_18_19_OP = 24;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_18_19_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_20_21_OP = 26;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_20_21_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_22_23_OP = 28;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_22_23_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_24_25_OP = 30;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_24_25_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_26_27_OP = 32;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_26_27_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_28_29_OP = 34;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_28_29_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_30_31_OP = 36;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_30_31_OP_LEN = 2;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_CASCADE_PMU0 = 38;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_CASCADE_PMU0_LEN = 3;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_CASCADE_PMU1 = 41;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_CASCADE_PMU1_LEN = 3;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_CASCADE_PMU2 = 44;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_CASCADE_PMU2_LEN = 3;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_CASCADE_PMU3 = 47;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_CASCADE_PMU3_LEN = 3;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_SPARE = 50;
static const uint32_t PB_PTLSCOM45_CFG_CNPM_REG_SPARE_LEN = 6;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM45_EN_DOB_ECC_ERR_REG = 0x12011818ull;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM45_PSAVE01_MODE_CFG = 0x12011814ull;

static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_MODE = 0;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_SPARE = 5;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN = 8;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM67_PTL_FIR_WOF_REG = 0x13011808ull;

static const uint32_t PB_PTLSCOM67_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF = 0;
static const uint32_t PB_PTLSCOM67_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN = 62;
// proc/reg00256.H

static const uint64_t PB_PTLSCOM67_TL_LINK_SYN_01_REG = 0x13011812ull;
// proc/reg00256.H

static const uint64_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG = 0x0301240dull;

static const uint32_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG_ENABLE = 0;
static const uint32_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG_ADDRESS = 13;
static const uint32_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG_ADDRESS_LEN = 17;
static const uint32_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG_SIZE = 32;
static const uint32_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG_SIZE_LEN = 15;
// proc/reg00256.H

static const uint64_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT = 0x03011c86ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_PAT = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_PAT_LEN = 23;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_CRESP_PAT = 27;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_CRESP_PAT_LEN = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_MASK = 32;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_MASK_LEN = 23;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_CRESP_MASK = 59;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_CRESP_MASK_LEN = 5;
// proc/reg00256.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG = 0x080108cdull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCA_LEN = 3;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR = 10;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_0_CCR_LEN = 6;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA = 16;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCA_LEN = 3;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR = 26;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_1_CCR_LEN = 6;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA = 32;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCA_LEN = 3;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR = 41;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_2_CCR_LEN = 7;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA = 48;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCA_LEN = 3;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR = 58;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PBAIBTXCCR_REG_3_CCR_LEN = 6;
// proc/reg00256.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_PFIR_REG_RWX = 0x080108c0ull;
static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_PFIR_REG_WOX_AND = 0x080108c1ull;
static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_PFIR_REG_WOX_OR = 0x080108c2ull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PFIR_REG_PFIRPFIR = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PFIR_REG_PFIRPFIR_LEN = 6;
// proc/reg00256.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR0_REG = 0x0201184eull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR0_REG_PE_MMIO_BAR0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR0_REG_PE_MMIO_BAR0_LEN = 40;
// proc/reg00256.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_REG = 0x02011850ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_REG_PE_MMIO_BAR1 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_REG_PE_MMIO_BAR1_LEN = 40;
// proc/reg00256.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIR_REG_RWX = 0x02011880ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIR_REG_WOX_AND = 0x02011881ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIR_REG_WOX_OR = 0x02011882ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIR_REG_NFIRNFIR = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIR_REG_NFIRNFIR_LEN = 28;
// proc/reg00256.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_DFREEZE_REG = 0x02011895ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_DFREEZE_REG_PE_DFREEZE = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN = 28;
// proc/reg00256.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_MMIOBAR0_MASK_REG = 0x020118cfull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0_LEN = 40;
// proc/reg00256.H

static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_PHB5_PMON_COUNTERS = 0x08010919ull;
// proc/reg00256.H

static const uint64_t PE0_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_HVIAR = 0x08010900ull;

static const uint32_t PE0_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD = 0;
static const uint32_t PE0_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B = 1;
static const uint32_t PE0_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC = 2;
static const uint32_t PE0_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE = 51;
static const uint32_t PE0_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE_LEN = 11;
// proc/reg00256.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_ACTION1_REG = 0x0000094full;
// proc/reg00256.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_ACT0_REG = 0x0000098eull;
// proc/reg00256.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RWX = 0x00000988ull;
static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_WOX_AND = 0x00000989ull;
static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_WOX_OR = 0x0000098aull;

static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID = 0;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID = 1;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR = 2;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR = 3;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR = 4;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR = 6;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED = 7;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR = 8;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR = 9;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR = 10;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR = 11;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE = 12;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT = 13;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR = 14;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR = 15;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR = 16;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR = 17;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR = 18;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR = 19;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR = 20;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR = 21;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR = 22;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR = 23;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR = 24;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR = 25;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR = 26;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR = 27;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR = 28;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR = 29;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_SCOM_INF_ERROR = 30;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS = 31;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR = 32;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR = 33;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR = 34;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_TVT_ERROR = 35;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG = 36;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG = 37;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG = 38;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR = 39;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR = 40;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR = 41;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR = 42;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR = 43;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR = 44;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR = 45;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED = 46;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR = 47;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR = 48;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR = 49;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR = 50;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR = 51;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR = 52;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_MRT_ERROR = 53;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR = 56;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR = 57;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR = 58;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR = 59;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR = 60;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR = 61;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR = 63;
// proc/reg00257.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_MASK_REG_RWX = 0x0000098bull;
static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_MASK_REG_WOX_AND = 0x0000098cull;
static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_MASK_REG_WOX_OR = 0x0000098dull;
// proc/reg00257.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_1_CERR_RPT_REG = 0x0901088bull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_CERR_RPT_REG_PBAIB_CERR_RPT0 = 0;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN = 21;
// proc/reg00257.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_INTBAR_REG = 0x03011853ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_INTBAR_REG_PE_INT_BAR = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_INTBAR_REG_PE_INT_BAR_LEN = 28;
// proc/reg00257.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_DFREEZE_REG = 0x030118d5ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_DFREEZE_REG_PE_DFREEZE = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN = 28;
// proc/reg00257.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE1_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_UVIAR = 0x00000902ull;

static const uint32_t PE1_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD = 0;
static const uint32_t PE1_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B = 1;
static const uint32_t PE1_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC = 2;
static const uint32_t PE1_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE = 51;
static const uint32_t PE1_PHB0_ETUX16_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN = 11;
// proc/reg00257.H

static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_ACT0_REG = 0x0901094eull;
// proc/reg00257.H

static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_MASK_REG_RWX = 0x0901094bull;
static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_MASK_REG_WOX_AND = 0x0901094cull;
static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_MASK_REG_WOX_OR = 0x0901094dull;
// proc/reg00257.H

static const uint64_t TP_TPBR_AD_ADS_XSCOM_CMD_REG = 0x03001c1cull;

static const uint32_t TP_TPBR_AD_ADS_XSCOM_CMD_REG_RNW = 0;
static const uint32_t TP_TPBR_AD_ADS_XSCOM_CMD_REG_SIZE = 5;
static const uint32_t TP_TPBR_AD_ADS_XSCOM_CMD_REG_SIZE_LEN = 7;
static const uint32_t TP_TPBR_AD_ADS_XSCOM_CMD_REG_ADR = 30;
static const uint32_t TP_TPBR_AD_ADS_XSCOM_CMD_REG_ADR_LEN = 34;
// proc/reg00257.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAPBTXT3 = 0x03021cd3ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3__VALID = 0;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3__VALID_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_0 = 8;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_0_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_1 = 12;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_1_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_2 = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_2_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_3 = 20;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_3_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_4 = 24;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_4_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_5 = 28;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_5_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_6 = 32;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_6_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_7 = 36;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT3_7_LEN = 4;
// proc/reg00257.H

static const uint64_t TP_TPBR_PSIHB_IVT_OFFSET = 0x03011d18ull;

static const uint32_t TP_TPBR_PSIHB_IVT_OFFSET_IVT_OFFSET_PAYLOAD = 0;
static const uint32_t TP_TPBR_PSIHB_IVT_OFFSET_IVT_OFFSET_PAYLOAD_LEN = 28;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR = 0x0006d207ull;

static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_PRIORITY_MODE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_PRIORITY_ORDER = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_PRIORITY_ORDER_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_HI_BUS_MODE = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_READ_PIPELINE_CONTROL = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_READ_PIPELINE_CONTROL_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_WRITE_PIPELINE_CONTROL = 7;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL = 0x00060000ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL_LEN = 4;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR0 = 0x00060040ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0_LEN = 32;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMGA = 0x00064012ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR_LEN = 32;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB = 0x00064016ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB_ADDR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB_R_NW = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB_BUSY = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB_RSP_INFO = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB_RSP_INFO_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB_RESET_PENDING = 61;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB_IFETCH_PENDING = 62;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIB_DATAOP_PENDING = 63;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL = 0x00064027ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_R_NW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_BUSY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_RSP_INFO = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_RSP_INFO_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_IFETCH_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_DATAOP_PENDING = 31;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBU = 0x00064026ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR_LEN = 32;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR4 = 0x00066044ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4_LEN = 32;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR = 0x00066031ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN = 32;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1 = 0x0006c801ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_HWCTRL_FSM_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_HWCTRL_DEVICE = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_HWCTRL_CPOL = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_HWCTRL_CPHA = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_HWCTRL_CLOCK_DIVIDER = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_HWCTRL_CLOCK_DIVIDER_LEN = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_HWCTRL_NR_OF_FRAMES = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_HWCTRL_NR_OF_FRAMES_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_BUSY_RESPONSE_CODE = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR1_BUSY_RESPONSE_CODE_LEN = 3;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5 = 0x0006c825ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3 = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3_LEN = 16;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RESET = 0x0006c805ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL_LEN = 2;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA = 0x0006c810ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL_LEN = 16;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_DORP0 = 0x0006c181ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP0_QUOTIENT = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP0_QUOTIENT_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP0_REMAINDER = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP0_REMAINDER_LEN = 32;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G0ISR0 = 0x0006c064ull;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G1ISR0 = 0x0006c065ull;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G2ISR0 = 0x0006c066ull;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G3ISR0 = 0x0006c067ull;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A = 0x0006c707ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A__CLEAR_STICKY_BITS_0A = 1;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20 = 0x0006c703ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0_LEN = 16;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1 = 0x0006c721ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1_LEN = 6;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SRD2A = 0x0006c749ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A_LEN = 32;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SWD0A = 0x0006c708ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A_LEN = 32;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2 = 0x0006c223ull;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3 = 0x0006c234ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE = 31;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSHI0 = 0x0006c205ull;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLI2 = 0x0006c222ull;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG5_RW = 0x0006c0bbull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG5_WO_CLEAR = 0x0006c0bcull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG5_WO_OR = 0x0006c0bdull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG5_OCB_OCI_OCCFLG5_OCC_FLAGS = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG5_OCB_OCI_OCCFLG5_OCC_FLAGS_LEN = 32;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q2 = 0x0006c402ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q2_OCB_OCI_OPIT0Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q2_OCB_OCI_OPIT0Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2PRA_ROX = 0x0006c610ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2PRA_WOX_CLEAR = 0x0006c611ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2PRA_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2PRA_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2PRA_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2PRA_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2PRA_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2PRA_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2PRA_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2PRA_7 = 7;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q6 = 0x0006c41eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q6_OCB_OCI_OPIT3Q6RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q6_OCB_OCI_OPIT3Q6RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q0 = 0x0006c420ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q0_OCB_OCI_OPIT4Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q0_OCB_OCI_OPIT4Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4 = 0x0006c43cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4_OCB_OCI_OPIT7Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4_OCB_OCI_OPIT7Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13RR = 0x0006c54dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13RR_PAYLOAD_LEN = 17;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C17 = 0x0006c451ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C17_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C17_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C17_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C17_PAYLOAD_LEN = 17;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20 = 0x0006c454ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20_PAYLOAD_LEN = 17;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21RR = 0x0006c555ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21RR_PAYLOAD_LEN = 17;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0 = 0x0006c460ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0_PAYLOAD_LEN = 17;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11 = 0x0006c46bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11_PAYLOAD_LEN = 17;
// proc/reg00257.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14RR = 0x0006c56eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14RR_PAYLOAD_LEN = 17;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26 = 0x0006c47aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26_PAYLOAD_LEN = 17;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26RR = 0x0006c57aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26RR_PAYLOAD_LEN = 17;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31RR = 0x0006c57full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31RR_PAYLOAD_LEN = 17;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBPRC_ROX = 0x0006c684ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBPRC_ROX_CLRPART = 0x0006c685ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBPRC_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBPRC_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBPRC_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBPRC_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBPRC_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBPRC_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBPRC_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBPRC_7 = 7;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OUISR0 = 0x0006c062ull;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICPING = 0x0006c781ull;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0 = 0x0006d010ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS_LEN = 26;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0 = 0x01010806ull;

static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0_LEN = 62;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG106 = 0x0000806aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG106_REGISTER106 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG106_REGISTER106_LEN = 64;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG119 = 0x00008077ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG119_REGISTER119 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG119_REGISTER119_LEN = 64;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG19 = 0x00008013ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG19_REGISTER19 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG19_REGISTER19_LEN = 64;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG31 = 0x0000801full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG31_REGISTER31 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG31_REGISTER31_LEN = 64;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG50 = 0x00008032ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG50_REGISTER50 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG50_REGISTER50_LEN = 64;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG67 = 0x00008043ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG67_REGISTER67 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG67_REGISTER67_LEN = 64;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG78 = 0x0000804eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG78_REGISTER78 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG78_REGISTER78_LEN = 64;
// proc/reg00258.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG92 = 0x0000805cull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG92_REGISTER92 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG92_REGISTER92_LEN = 64;
// proc/reg00258.H

}
}
#include "proc/reg00256.H"
#include "proc/reg00257.H"
#include "proc/reg00258.H"
#endif
