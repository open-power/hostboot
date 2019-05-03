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
// proc/reg00017.H

static const uint64_t INT_CQ_PMC_1 = 0x02010829ull;

static const uint32_t INT_CQ_PMC_1_INT_CQ_PMC_1_COUNT_0_47 = 16;
static const uint32_t INT_CQ_PMC_1_INT_CQ_PMC_1_COUNT_0_47_LEN = 48;
// proc/reg00017.H

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
// proc/reg00017.H

static const uint64_t INT_PC_NXC_REGS_SYNC_DONE = 0x02010a84ull;
// proc/reg00017.H

static const uint64_t INT_PC_NXC_REGS_WATCH0_DATA1 = 0x02010aa5ull;
// proc/reg00017.H

static const uint64_t INT_PC_NXC_REGS_WOF_ERR_DETAIL = 0x02010ad3ull;

static const uint32_t INT_PC_NXC_REGS_WOF_ERR_DETAIL_INT_PC_NXC_WOF_ERR_DETAIL_ERROR = 0;
static const uint32_t INT_PC_NXC_REGS_WOF_ERR_DETAIL_INT_PC_NXC_WOF_ERR_DETAIL_ERROR_LEN = 64;
// proc/reg00017.H

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
// proc/reg00017.H

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
// proc/reg00017.H

static const uint64_t INT_VC_ENDC_FLUSH_CTRL = 0x02010980ull;

static const uint32_t INT_VC_ENDC_FLUSH_CTRL_POLL_VALID = 0;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 = 1;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE = 2;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE = 3;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6 = 4;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6_LEN = 3;
static const uint32_t INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE = 7;
// proc/reg00017.H

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
// proc/reg00017.H

static const uint64_t INT_VC_ENDC_WATCH3_DATA3 = 0x020109bfull;
// proc/reg00017.H

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
// proc/reg00017.H

static const uint64_t INT_VC_ESBC_DBG_CACHE_EN = 0x02010955ull;

static const uint32_t INT_VC_ESBC_DBG_CACHE_EN_INT_VC_ESBC_DBG_CACHE_EN_ENABLE = 0;
static const uint32_t INT_VC_ESBC_DBG_CACHE_EN_INT_VC_ESBC_DBG_CACHE_EN_ENABLE_LEN = 16;
// proc/reg00017.H

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
// proc/reg00017.H

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
// proc/reg00017.H

static const uint64_t INT_VC_VSD_TABLE_DATA = 0x02010901ull;
// proc/reg00017.H

static const uint64_t NX_CH4_ADDR_5_HASH_FUNCTION_REG = 0x02011146ull;

static const uint32_t NX_CH4_ADDR_5_HASH_FUNCTION_REG_ADDRESS_5_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_5_HASH_FUNCTION_REG_ADDRESS_5_HASH_FUNCTION_LEN = 64;
// proc/reg00017.H

static const uint64_t NX_CH4_DATATAG_1_HASH_FUNCTION_REG = 0x0201114dull;

static const uint32_t NX_CH4_DATATAG_1_HASH_FUNCTION_REG_DATATAG_1_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_DATATAG_1_HASH_FUNCTION_REG_DATATAG_1_HASH_FUNCTION_LEN = 64;
// proc/reg00017.H

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
// proc/reg00017.H

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
// proc/reg00017.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_WOF_REG = 0x02011088ull;
// proc/reg00017.H

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
// proc/reg00017.H

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
// proc/reg00017.H

static const uint64_t PB_PTLSCOM10_PMU0_TLPM_COUNTER = 0x1001181bull;
// proc/reg00017.H

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
// proc/reg00017.H

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
// proc/reg00017.H

static const uint64_t PB_PTLSCOM23_PMU2_TLPM_COUNTER = 0x1101181dull;
// proc/reg00017.H

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
// proc/reg00017.H

static const uint64_t PB_PTLSCOM45_EN_DOB_ECC_ERR_REG = 0x12011818ull;
// proc/reg00017.H

static const uint64_t PB_PTLSCOM45_PSAVE01_MODE_CFG = 0x12011814ull;

static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_MODE = 0;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_SPARE = 5;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PTLSCOM45_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN = 8;
// proc/reg00017.H

static const uint64_t PB_PTLSCOM67_PTL_FIR_WOF_REG = 0x13011808ull;

static const uint32_t PB_PTLSCOM67_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF = 0;
static const uint32_t PB_PTLSCOM67_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN = 62;
// proc/reg00017.H

static const uint64_t PB_PTLSCOM67_TL_LINK_SYN_01_REG = 0x13011812ull;
// proc/reg00017.H

static const uint64_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG = 0x03011d4dull;

static const uint32_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG_ENABLE = 0;
static const uint32_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG_ADDRESS = 13;
static const uint32_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG_ADDRESS_LEN = 17;
static const uint32_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG_SIZE = 32;
static const uint32_t PB_BRIDGE_HCA_MONITOR_0_ADDRESS_REG_SIZE_LEN = 15;
// proc/reg00017.H

static const uint64_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT = 0x03011c86ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_PAT = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_PAT_LEN = 23;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_CRESP_PAT = 27;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_CRESP_PAT_LEN = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_MASK = 32;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_MASK_LEN = 23;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_CRESP_MASK = 59;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_FILT_CRESP_MASK_LEN = 5;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_CLOCK_STAT_ARY = 0x0203000aull;

static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t TP_TCN0_N0_CLOCK_STAT_ARY_UNIT14_ARY = 18;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_CPLT_CONF1_RW = 0x02000009ull;
static const uint64_t TP_TCN0_N0_CPLT_CONF1_WO_CLEAR = 0x02000029ull;
static const uint64_t TP_TCN0_N0_CPLT_CONF1_WO_OR = 0x02000019ull;

static const uint32_t TP_TCN0_N0_CPLT_CONF1_EN_EQ_DC_0H = 0;
static const uint32_t TP_TCN0_N0_CPLT_CONF1_EN_EQ_DC_1H = 1;
static const uint32_t TP_TCN0_N0_CPLT_CONF1_NORTH_DC_2H = 2;
static const uint32_t TP_TCN0_N0_CPLT_CONF1_NORTH_DC_3H = 3;
static const uint32_t TP_TCN0_N0_CPLT_CONF1_NORTH_DC_4H = 4;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_CPLT_CTRL1_RW = 0x02000001ull;
static const uint64_t TP_TCN0_N0_CPLT_CTRL1_WO_CLEAR = 0x02000021ull;
static const uint64_t TP_TCN0_N0_CPLT_CTRL1_WO_OR = 0x02000011ull;

static const uint32_t TP_TCN0_N0_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_VITL_FENCE_DC = 3;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION0_FENCE_DC = 4;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION1_FENCE_DC = 5;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION2_FENCE_DC = 6;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION3_FENCE_DC = 7;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION4_FENCE_DC = 8;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION5_FENCE_DC = 9;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION6_FENCE_DC = 10;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION7_FENCE_DC = 11;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION8_FENCE_DC = 12;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION9_FENCE_DC = 13;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION10_FENCE_DC = 14;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION11_FENCE_DC = 15;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION12_FENCE_DC = 16;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION13_FENCE_DC = 17;
static const uint32_t TP_TCN0_N0_CPLT_CTRL1_REGION14_FENCE_DC = 18;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0 = 0x020107cdull;

static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TP_TCN0_N0_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG = 0x02010007ull;

static const uint32_t TP_TCN0_N0_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK = 0;
static const uint32_t TP_TCN0_N0_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN = 32;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK = 0x02010002ull;

static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR = 3;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_UL_P0_ERROR = 5;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_GENERAL_TIMEOUT = 15;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t TP_TCN0_N0_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_EPS_PSC_RING_FENCE_MASK_LATCH_REG = 0x02010008ull;

static const uint32_t TP_TCN0_N0_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK = 1;
static const uint32_t TP_TCN0_N0_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN = 31;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT2 = 0x02050002ull;

static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ = 0x0205001cull;

static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_TRA0_TR0_CONFIG = 0x02010402ull;

static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_TRA0_TR1_CONFIG_3 = 0x02010446ull;

static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_3_D_LEN = 24;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_TRA1_TR0_CONFIG_5 = 0x02010488ull;

static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_5_D_LEN = 24;
// proc/reg00017.H

static const uint64_t TP_TCN0_N0_XSTOP3 = 0x0203000eull;

static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_MASK_B = 0;
static const uint32_t TP_TCN0_N0_XSTOP3_ALIGNED_XSTOP3 = 1;
static const uint32_t TP_TCN0_N0_XSTOP3_TRIGGER_OPCG_ON_XSTOP3 = 2;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_WAIT_ALLWAYS = 3;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_PERV = 4;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT1 = 5;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT2 = 6;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT3 = 7;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT4 = 8;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT5 = 9;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT6 = 10;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT7 = 11;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT8 = 12;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT9 = 13;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT10 = 14;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT11 = 15;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT12 = 16;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT13 = 17;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_UNIT14 = 18;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_WAIT_CYCLES = 48;
static const uint32_t TP_TCN0_N0_XSTOP3_XSTOP3_WAIT_CYCLES_LEN = 12;
// proc/reg00017.H

static const uint64_t TP_TCN1_N1_DBG_CBS_CC = 0x03030013ull;

static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_RESET_EP = 0;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_OPCG_IP = 1;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_VITL_CLKOFF = 2;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_TEST_ENABLE = 3;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_CBS_REQ = 4;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_CBS_CMD = 5;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_CBS_CMD_LEN = 3;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_CBS_STATE = 8;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_CBS_STATE_LEN = 5;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE = 13;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR = 14;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_PCB_IDLE = 15;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE = 16;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_LAST_OPCG_MODE = 20;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_PCB_ERROR = 24;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_PARITY_ERROR = 25;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_CC_ERROR = 26;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED = 27;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET = 28;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE = 29;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE = 30;
static const uint32_t TP_TCN1_N1_DBG_CBS_CC_TP_TPFSI_CBS_ACK = 31;
// proc/reg00017.H

static const uint64_t TP_TCN1_N1_EPS_THERM_WSUB_DTS_RESULT0 = 0x03050000ull;

static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
// proc/reg00017.H

static const uint64_t TP_TCN1_N1_EPS_THERM_WSUB_SKITTER_DATA1 = 0x0305001aull;
// proc/reg00017.H

static const uint64_t TP_TCN1_N1_OPCG_CAPT3 = 0x03030012ull;

static const uint32_t TP_TCN1_N1_OPCG_CAPT3_07EVEN = 4;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_07EVEN_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_07ODD = 9;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_07ODD_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_08EVEN = 14;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_08EVEN_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_08ODD = 19;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_08ODD_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_09EVEN = 24;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_09EVEN_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_09ODD = 29;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_09ODD_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_10EVEN = 34;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_10EVEN_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_10ODD = 39;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_10ODD_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_11EVEN = 44;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_11EVEN_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_11ODD = 49;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_11ODD_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_12EVEN = 54;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_12EVEN_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_12ODD = 59;
static const uint32_t TP_TCN1_N1_OPCG_CAPT3_12ODD_LEN = 5;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA0_TR0_CONFIG_2 = 0x03010405ull;

static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCN1_N1_TRA0_TR0_CONFIG_2_B_LEN = 24;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA1_TR1_CONFIG_4 = 0x030104c7ull;

static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCN1_N1_TRA1_TR1_CONFIG_4_B_LEN = 24;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA2_TR1_CONFIG_3 = 0x03010546ull;

static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_3_D_LEN = 24;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA3_TR0_CONFIG_5 = 0x03010588ull;

static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCN1_N1_TRA3_TR0_CONFIG_5_D_LEN = 24;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA4_TR0_CONFIG = 0x03010602ull;

static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA4_TR0_CONFIG_4 = 0x03010607ull;

static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCN1_N1_TRA4_TR0_CONFIG_4_B_LEN = 24;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG = 0x03010641ull;

static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCN1_N1_TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA5_TR1_CONFIG = 0x030106c2ull;

static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA5_TR1_CONFIG_2 = 0x030106c5ull;

static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCN1_N1_TRA5_TR1_CONFIG_2_B_LEN = 24;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA6_TR1_CONFIG_5 = 0x03010748ull;

static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCN1_N1_TRA6_TR1_CONFIG_5_D_LEN = 24;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA7_TR0_TRACE_HI_DATA_REG = 0x03010780ull;

static const uint32_t TP_TCN1_N1_TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// proc/reg00018.H

static const uint64_t TP_TCN1_N1_TRA7_TR0_CONFIG_3 = 0x03010786ull;

static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_3_D_LEN = 24;
// proc/reg00018.H

static const uint64_t TP_TPBR_AD_ADS_XSCOM_CMD_REG = 0x0009001cull;

static const uint32_t TP_TPBR_AD_ADS_XSCOM_CMD_REG_RNW = 0;
static const uint32_t TP_TPBR_AD_ADS_XSCOM_CMD_REG_SIZE = 5;
static const uint32_t TP_TPBR_AD_ADS_XSCOM_CMD_REG_SIZE_LEN = 7;
static const uint32_t TP_TPBR_AD_ADS_XSCOM_CMD_REG_ADR = 30;
static const uint32_t TP_TPBR_AD_ADS_XSCOM_CMD_REG_ADR_LEN = 34;
// proc/reg00018.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAPBTXT3 = 0x03011dd3ull;

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
// proc/reg00018.H

static const uint64_t TP_TPBR_PBA_PBAO_BCUE_OCIBAR = 0x00068019ull;

static const uint32_t TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR = 0;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR_LEN = 25;
// proc/reg00018.H

static const uint64_t TP_TPBR_PSIHB_IVT_OFFSET = 0x03011d18ull;

static const uint32_t TP_TPBR_PSIHB_IVT_OFFSET_IVT_OFFSET_PAYLOAD = 0;
static const uint32_t TP_TPBR_PSIHB_IVT_OFFSET_IVT_OFFSET_PAYLOAD_LEN = 28;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR = 0x0006d207ull;

static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_PRIORITY_MODE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_PRIORITY_ORDER = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_PRIORITY_ORDER_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_HI_BUS_MODE = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_READ_PIPELINE_CONTROL = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_READ_PIPELINE_CONTROL_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OACR_WRITE_PIPELINE_CONTROL = 7;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL = 0x00060000ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL_LEN = 4;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR0 = 0x00060040ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0_LEN = 32;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMGA = 0x00064012ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR_LEN = 32;
// proc/reg00018.H

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
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL = 0x00064027ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_R_NW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_BUSY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_RSP_INFO = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_RSP_INFO_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_IFETCH_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBL_DATAOP_PENDING = 31;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBU = 0x00064026ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR_LEN = 32;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR4 = 0x00066044ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4_LEN = 32;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR = 0x00066031ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN = 32;
// proc/reg00018.H

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
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5 = 0x0006c825ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3 = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3_LEN = 16;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RESET = 0x0006c805ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL_LEN = 2;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA = 0x0006c810ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL_LEN = 16;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_DORP0 = 0x0006c181ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP0_QUOTIENT = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP0_QUOTIENT_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP0_REMAINDER = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP0_REMAINDER_LEN = 32;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G0ISR0 = 0x0006c064ull;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G1ISR0 = 0x0006c065ull;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G2ISR0 = 0x0006c066ull;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G3ISR0 = 0x0006c067ull;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A = 0x0006c707ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A__CLEAR_STICKY_BITS_0A = 1;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20 = 0x0006c703ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0_LEN = 16;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1 = 0x0006c721ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1_LEN = 6;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SRD2A = 0x0006c749ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A_LEN = 32;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SWD0A = 0x0006c708ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A_LEN = 32;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2 = 0x0006c223ull;
// proc/reg00018.H

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
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSHI0 = 0x0006c205ull;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLI2 = 0x0006c222ull;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG5_RW = 0x0006c0bbull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG5_WO_CLEAR = 0x0006c0bcull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG5_WO_OR = 0x0006c0bdull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG5_OCB_OCI_OCCFLG5_OCC_FLAGS = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG5_OCB_OCI_OCCFLG5_OCC_FLAGS_LEN = 32;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q2 = 0x0006c402ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q2_OCB_OCI_OPIT0Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q2_OCB_OCI_OPIT0Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00018.H

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
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q6 = 0x0006c41eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q6_OCB_OCI_OPIT3Q6RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q6_OCB_OCI_OPIT3Q6RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q0 = 0x0006c420ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q0_OCB_OCI_OPIT4Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q0_OCB_OCI_OPIT4Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4 = 0x0006c43cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4_OCB_OCI_OPIT7Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q4_OCB_OCI_OPIT7Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00018.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13RR = 0x0006c54dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C13RR_PAYLOAD_LEN = 17;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C17 = 0x0006c451ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C17_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C17_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C17_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C17_PAYLOAD_LEN = 17;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20 = 0x0006c454ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C20_PAYLOAD_LEN = 17;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21RR = 0x0006c555ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21RR_PAYLOAD_LEN = 17;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0 = 0x0006c460ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0_PAYLOAD_LEN = 17;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11 = 0x0006c46bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C11_PAYLOAD_LEN = 17;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14RR = 0x0006c56eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C14RR_PAYLOAD_LEN = 17;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26 = 0x0006c47aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26_PAYLOAD_LEN = 17;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26RR = 0x0006c57aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C26RR_PAYLOAD_LEN = 17;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31RR = 0x0006c57full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31RR_PAYLOAD_LEN = 17;
// proc/reg00019.H

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
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OUISR0 = 0x0006c062ull;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICPING = 0x0006c781ull;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0 = 0x0006d010ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS_LEN = 26;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0 = 0x01010806ull;

static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0_LEN = 62;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG106 = 0x0000806aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG106_REGISTER106 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG106_REGISTER106_LEN = 64;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG119 = 0x00008077ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG119_REGISTER119 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG119_REGISTER119_LEN = 64;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG19 = 0x00008013ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG19_REGISTER19 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG19_REGISTER19_LEN = 64;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG31 = 0x0000801full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG31_REGISTER31 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG31_REGISTER31_LEN = 64;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG50 = 0x00008032ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG50_REGISTER50 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG50_REGISTER50_LEN = 64;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG67 = 0x00008043ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG67_REGISTER67 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG67_REGISTER67_LEN = 64;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG78 = 0x0000804eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG78_REGISTER78 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG78_REGISTER78_LEN = 64;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG92 = 0x0000805cull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG92_REGISTER92 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG92_REGISTER92_LEN = 64;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_TPC_CLOCK_STAT_SL = 0x01030008ull;

static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL = 4;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL = 5;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL = 6;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL = 7;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL = 8;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL = 9;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL = 10;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL = 11;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL = 12;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL = 13;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL = 14;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL = 15;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL = 16;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL = 17;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL = 18;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_TPC_CPLT_STAT0 = 0x01000100ull;

static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_EBIST_DONE_DC = 1;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_PLL_DESTOUT = 7;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_10I = 10;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_11I = 11;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_12I = 12;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_13I = 13;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_14I = 14;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_15I = 15;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_16I = 16;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_17I = 17;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_18I = 18;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_19I = 19;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_20I = 20;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_21I = 21;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_22I = 22;
static const uint32_t TP_TPCHIP_TPC_CPLT_STAT0_FREE_USAGE_23I = 23;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA0 = 0x01050019ull;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG = 0x0105000full;

static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_TPC_ITR_FMU_FORCE_OP_REG = 0x01020003ull;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_TPC_ITR_FMU_MODE_REG = 0x01020000ull;

static const uint32_t TP_TPCHIP_TPC_ITR_FMU_MODE_REG_TOD_CNTR_REF = 0;
static const uint32_t TP_TPCHIP_TPC_ITR_FMU_MODE_REG_TOD_CNTR_REF_LEN = 12;
static const uint32_t TP_TPCHIP_TPC_ITR_FMU_MODE_REG_POWER_UP_CNTR_REF = 17;
static const uint32_t TP_TPCHIP_TPC_ITR_FMU_MODE_REG_POWER_UP_CNTR_REF_LEN = 3;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_TPC_SCAN_CAPTUREDR = 0x0103c000ull;
// proc/reg00019.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_4 = 0x01010407ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_CONFIG_4_B_LEN = 24;
// proc/reg00019.H

static const uint64_t TP_TPVSB_FSI_W_I2C_EXTENDED_STATUS_A = 0x00001808ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_EXTENDED_STATUS_A_MSM_CURR_STATE_000 = 11;
static const uint32_t TP_TPVSB_FSI_W_I2C_EXTENDED_STATUS_A_MSM_CURR_STATE_000_LEN = 5;
static const uint32_t TP_TPVSB_FSI_W_I2C_EXTENDED_STATUS_A_SELF_BUSY_000 = 25;
// proc/reg00019.H

static const uint64_t TP_TPVSB_FSI_W_I2C_MODE_REGISTER_A = 0x00001802ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_MODE_REGISTER_A_BIT_RATE_DIVISOR_000 = 0;
static const uint32_t TP_TPVSB_FSI_W_I2C_MODE_REGISTER_A_BIT_RATE_DIVISOR_000_LEN = 16;
static const uint32_t TP_TPVSB_FSI_W_I2C_MODE_REGISTER_A_PORT_NUMBER_000 = 16;
static const uint32_t TP_TPVSB_FSI_W_I2C_MODE_REGISTER_A_PORT_NUMBER_000_LEN = 6;
static const uint32_t TP_TPVSB_FSI_W_I2C_MODE_REGISTER_A_FGAT_MODE_000 = 28;
static const uint32_t TP_TPVSB_FSI_W_I2C_MODE_REGISTER_A_DIAG_MODE_000 = 29;
static const uint32_t TP_TPVSB_FSI_W_I2C_MODE_REGISTER_A_PACING_ALLOW_MODE_000 = 30;
static const uint32_t TP_TPVSB_FSI_W_I2C_MODE_REGISTER_A_WRAP_MODE_000 = 31;
// proc/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI = 0x00002806ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE = 0x00002818ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_SCOM = 0x00050006ull;
// proc/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_14_RWX = 0x0000284eull;
// proc/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_6_RWX = 0x00002846ull;
// proc/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_10_RWX = 0x000028caull;
// proc/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_0_RWX = 0x00002900ull;
// proc/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR = 0x00002930ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_0_SPARE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TP_FENCE_VTLIO_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW1_FENCE_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW1_FENCE_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_8_SPARE = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_9_SPARE = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_10_SPARE = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TP_IO_OCMB_RESET_B_EN = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC = 31;
// proc/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW = 0x00002911ull;
// proc/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_WO_OR = 0x00002928ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TPFSI_SPIMST0_PORT_MUX_SEL_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TPFSI_SPIMST1_PORT_MUX_SEL_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TPFSI_SPIMST2_PORT_MUX_SEL_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TPFSI_SPIMST3_PORT_MUX_SEL_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_ROOT_CTRL8_4_15 = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_ROOT_CTRL8_4_15_LEN = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TP_FSI_FENCE_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_VITL_FENCE_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSI0_FENCE_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSI0LL_FENCE_DC = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSI0INV_FENCE_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSI1_FENCE_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSI1LL_FENCE_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSIA_FENCE_DC = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_ROOT_CTRL8_24_31 = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_SET_ROOT_CTRL8_24_31_LEN = 8;
// proc/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RWX = 0x00002839ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2 = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2_LEN = 32;
// proc/reg00019.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_ACK_EOT_WOX = 0x00002415ull;
// proc/reg00019.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_REQ_RESET = 0x000b0013ull;
// proc/reg00019.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_SIG_EOT = 0x000b0012ull;
// proc/reg00019.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_DATA_IN = 0x00002400ull;
// proc/reg00019.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_RWX = 0x00000c01ull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG = 1;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS = 2;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS_LEN = 14;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION = 16;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION_LEN = 12;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE = 28;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE_LEN = 4;
// proc/reg00019.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_RWX = 0x00000c10ull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER_LEN = 32;
// proc/reg00019.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RESET = 0x00020004ull;
// proc/reg00019.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT = 0x00020010ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ = 0;
// proc/reg00019.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CRSIM = 0x00030006ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_FSI0 = 0x000031d8ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_SCOMFSI0 = 0x00000c76ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_FSI0 = 0x000031dcull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_SCOMFSI0 = 0x00000c77ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WOX = 0x000030d8ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2 = 1;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_FSI0 = 0x00003034ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_SCOMFSI0 = 0x00000c0dull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_FSI0 = 0x00003450ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_SCOMFSI0 = 0x00000d14ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_FSI0 = 0x0000340cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_SCOMFSI0 = 0x00000d03ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_FSI0 = 0x00003470ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_SCOMFSI0 = 0x00000d1cull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO = 0x000034d4ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2_LEN = 3;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCMBR = 0x0000084cull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SMBR = 0x00000844ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SSI2M = 0x00000828ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_FSI1 = 0x00003068ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_SCOMFSI1 = 0x00000c1aull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_FSI1 = 0x00003004ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_SCOMFSI1 = 0x00000c01ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_FSI1 = 0x00003014ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_SCOMFSI1 = 0x00000c05ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO = 0x000030ecull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2_LEN = 3;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCRSIC0 = 0x00000850ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SDMA = 0x00000804ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SISC = 0x00000808ull;
// proc/reg00020.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SRSIS4 = 0x0000087cull;
// proc/reg00020.H

}
}
#include "proc/reg00017.H"
#include "proc/reg00018.H"
#include "proc/reg00019.H"
#include "proc/reg00020.H"
#endif
