/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_2.H $       */
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

#ifndef __p10_scom_proc_2_H_
#define __p10_scom_proc_2_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_PMC_0 = 0x02010828ull;

static const uint32_t INT_CQ_PMC_0_INT_CQ_PMC_0_COUNT_47 = 16;
static const uint32_t INT_CQ_PMC_0_INT_CQ_PMC_0_COUNT_47_LEN = 48;
// proc/reg00008.H

static const uint64_t INT_CQ_TTT_0 = 0x02010804ull;

static const uint32_t INT_CQ_TTT_0_VALID_0_7 = 0;
static const uint32_t INT_CQ_TTT_0_VALID_0_7_LEN = 8;
static const uint32_t INT_CQ_TTT_0_ENTRY_0_3 = 8;
static const uint32_t INT_CQ_TTT_0_ENTRY_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_0_ENTRY_1_0_3 = 12;
static const uint32_t INT_CQ_TTT_0_ENTRY_1_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_0_ENTRY_2_0_3 = 16;
static const uint32_t INT_CQ_TTT_0_ENTRY_2_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_0_ENTRY_3_0 = 20;
static const uint32_t INT_CQ_TTT_0_ENTRY_3_0_LEN = 4;
static const uint32_t INT_CQ_TTT_0_ENTRY_4_0_3 = 24;
static const uint32_t INT_CQ_TTT_0_ENTRY_4_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_0_ENTRY_5_0_3 = 28;
static const uint32_t INT_CQ_TTT_0_ENTRY_5_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_0_ENTRY_6_0_3 = 32;
static const uint32_t INT_CQ_TTT_0_ENTRY_6_0_3_LEN = 4;
static const uint32_t INT_CQ_TTT_0_ENTRY_7_0_3 = 36;
static const uint32_t INT_CQ_TTT_0_ENTRY_7_0_3_LEN = 4;
// proc/reg00008.H

static const uint64_t INT_PC_NXC_REGS_WATCH0_DATA0 = 0x02010aa4ull;
// proc/reg00008.H

static const uint64_t INT_PC_REGS_NRQ_CFG = 0x02010a1cull;

static const uint32_t INT_PC_REGS_NRQ_CFG_CFG_NRQ_CORE_PUSH_EN = 0;
static const uint32_t INT_PC_REGS_NRQ_CFG_RESERVED_1_2 = 1;
static const uint32_t INT_PC_REGS_NRQ_CFG_RESERVED_1_2_LEN = 2;
static const uint32_t INT_PC_REGS_NRQ_CFG_CFG_NRQ_LCL_QUEUE_SIZE_NCKO_LD = 3;
static const uint32_t INT_PC_REGS_NRQ_CFG_CFG_NRQ_LCL_QUEUE_SIZE_NCKO_LD_LEN = 5;
static const uint32_t INT_PC_REGS_NRQ_CFG_RESERVED_8_10 = 8;
static const uint32_t INT_PC_REGS_NRQ_CFG_RESERVED_8_10_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_CFG_CFG_NRQ_LCL_QUEUE_SIZE_CHKO_LD = 11;
static const uint32_t INT_PC_REGS_NRQ_CFG_CFG_NRQ_LCL_QUEUE_SIZE_CHKO_LD_LEN = 5;
static const uint32_t INT_PC_REGS_NRQ_CFG_RESERVED_16_18 = 16;
static const uint32_t INT_PC_REGS_NRQ_CFG_RESERVED_16_18_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_CFG_CFG_NRQ_LCL_QUEUE_SIZE_NCKI_ST = 19;
static const uint32_t INT_PC_REGS_NRQ_CFG_CFG_NRQ_LCL_QUEUE_SIZE_NCKI_ST_LEN = 5;
static const uint32_t INT_PC_REGS_NRQ_CFG_RESERVED_24_28 = 24;
static const uint32_t INT_PC_REGS_NRQ_CFG_RESERVED_24_28_LEN = 5;
static const uint32_t INT_PC_REGS_NRQ_CFG_CFG_NRQ_RMT_QUEUE_SIZE_NCKI_ST = 29;
static const uint32_t INT_PC_REGS_NRQ_CFG_CFG_NRQ_RMT_QUEUE_SIZE_NCKI_ST_LEN = 3;
// proc/reg00008.H

static const uint64_t INT_PC_REGS_NVC_BLOCK_MODE = 0x02010a0eull;

static const uint32_t INT_PC_REGS_NVC_BLOCK_MODE_INT_PC_NVC_BLOCK_MODE = 0;
static const uint32_t INT_PC_REGS_NVC_BLOCK_MODE_INT_PC_NVC_BLOCK_MODE_LEN = 32;
// proc/reg00008.H

static const uint64_t INT_PC_REGS_TCTXT_EN0_SET = 0x02010b02ull;
// proc/reg00008.H

static const uint64_t INT_PC_REGS_TCTXT_EN1_SET = 0x02010b06ull;
// proc/reg00008.H

static const uint64_t INT_PC_REGS_TCTXT_TRACK = 0x02010b29ull;

static const uint32_t INT_PC_REGS_TCTXT_TRACK_CFG_BLOCK_TRACK_EN = 0;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_CFG_BLOCK_TRACK_RESET = 1;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_RESERVED_2_3 = 2;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_RESERVED_2_3_LEN = 2;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_CFG_BLOCK_FILTER_EN = 4;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_CFG_BLOCK_FILTER_REGS_EN = 5;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_RESERVED_6_9 = 6;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_RESERVED_6_9_LEN = 4;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_CFG_BLOCK_RESET_DELAY = 10;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_CFG_BLOCK_RESET_DELAY_LEN = 6;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_CFG_BLOCK_EN_VEC = 48;
static const uint32_t INT_PC_REGS_TCTXT_TRACK_CFG_BLOCK_EN_VEC_LEN = 16;
// proc/reg00008.H

static const uint64_t INT_VC_EASC_ADDITIONAL_PERF = 0x0201097bull;

static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_P0_IS_IDLE = 0;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_P1_IS_IDLE = 1;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_RESERVED_2_7 = 2;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_RESERVED_2_7_LEN = 6;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_MAX_PTAG_IN_USE = 8;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_MAX_PTAG_IN_USE_LEN = 8;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_RESERVED_16_23 = 16;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_RESERVED_16_23_LEN = 8;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_MAX_UNLOCK_IN_FIFO = 24;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_MAX_UNLOCK_IN_FIFO_LEN = 8;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_HIGHIEST_SELECTED_WAY = 32;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_HIGHIEST_SELECTED_WAY_LEN = 8;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_RESERVED_40_47 = 40;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_RESERVED_40_47_LEN = 8;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_MAX_OUTSTANDING_EAS_FETCH = 48;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_MAX_OUTSTANDING_EAS_FETCH_LEN = 8;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_RESERVED_56_63 = 56;
static const uint32_t INT_VC_EASC_ADDITIONAL_PERF_RESERVED_56_63_LEN = 8;
// proc/reg00008.H

static const uint64_t INT_VC_EASC_HASH_1 = 0x02010969ull;

static const uint32_t INT_VC_EASC_HASH_1_0 = 0;
static const uint32_t INT_VC_EASC_HASH_1_0_LEN = 8;
static const uint32_t INT_VC_EASC_HASH_1_1 = 8;
static const uint32_t INT_VC_EASC_HASH_1_1_LEN = 8;
static const uint32_t INT_VC_EASC_HASH_1_2 = 16;
static const uint32_t INT_VC_EASC_HASH_1_2_LEN = 8;
static const uint32_t INT_VC_EASC_HASH_1_3 = 24;
static const uint32_t INT_VC_EASC_HASH_1_3_LEN = 8;
static const uint32_t INT_VC_EASC_HASH_1_4 = 32;
static const uint32_t INT_VC_EASC_HASH_1_4_LEN = 8;
static const uint32_t INT_VC_EASC_HASH_1_5 = 40;
static const uint32_t INT_VC_EASC_HASH_1_5_LEN = 8;
static const uint32_t INT_VC_EASC_HASH_1_6 = 48;
static const uint32_t INT_VC_EASC_HASH_1_6_LEN = 8;
static const uint32_t INT_VC_EASC_HASH_1_7 = 56;
static const uint32_t INT_VC_EASC_HASH_1_7_LEN = 8;
// proc/reg00008.H

static const uint64_t INT_VC_ENDC_DBG = 0x02010994ull;

static const uint32_t INT_VC_ENDC_DBG_RESERVED_0_17 = 0;
static const uint32_t INT_VC_ENDC_DBG_RESERVED_0_17_LEN = 18;
static const uint32_t INT_VC_ENDC_DBG_WAY_DISABLE = 18;
static const uint32_t INT_VC_ENDC_DBG_WAY_DISABLE_LEN = 6;
static const uint32_t INT_VC_ENDC_DBG_RESERVED_24_25 = 24;
static const uint32_t INT_VC_ENDC_DBG_RESERVED_24_25_LEN = 2;
static const uint32_t INT_VC_ENDC_DBG_DIS_WATCH_ECC_CORRECTION = 26;
static const uint32_t INT_VC_ENDC_DBG_DIS_ARX_ECC_CORRECTION = 27;
static const uint32_t INT_VC_ENDC_DBG_DIS_TAG_ECC_CORRECTION = 28;
static const uint32_t INT_VC_ENDC_DBG_DIS_TAG_ECC_CORRECTION_LEN = 12;
static const uint32_t INT_VC_ENDC_DBG_DIS_STATE_ECC_CORRECTION = 40;
static const uint32_t INT_VC_ENDC_DBG_DIS_STATE_ECC_CORRECTION_LEN = 2;
static const uint32_t INT_VC_ENDC_DBG_DIS_CTRLBUF_ECC_CORRECTION = 42;
static const uint32_t INT_VC_ENDC_DBG_DIS_DATA_ECC_CORRECTION = 43;
static const uint32_t INT_VC_ENDC_DBG_DIS_DATA_ECC_CORRECTION_LEN = 6;
static const uint32_t INT_VC_ENDC_DBG_FORCE_SINGLE_BIT_ECC_ERR = 49;
static const uint32_t INT_VC_ENDC_DBG_FORCE_DOUBLE_BIT_ECC_ERR = 50;
static const uint32_t INT_VC_ENDC_DBG_ECC_ERR_INJ_ARRAY_SEL = 51;
static const uint32_t INT_VC_ENDC_DBG_ECC_ERR_INJ_ARRAY_SEL_LEN = 6;
static const uint32_t INT_VC_ENDC_DBG_TRACE_ENABLE = 57;
static const uint32_t INT_VC_ENDC_DBG_RESERVED_58_63 = 58;
static const uint32_t INT_VC_ENDC_DBG_RESERVED_58_63_LEN = 6;
// proc/reg00008.H

static const uint64_t INT_VC_ENDC_WATCH3_DATA2 = 0x020109beull;
// proc/reg00008.H

static const uint64_t INT_VC_ERQ_CFG_CMD_LIMIT = 0x02010922ull;

static const uint32_t INT_VC_ERQ_CFG_CMD_LIMIT_RESERVED_0_17 = 0;
static const uint32_t INT_VC_ERQ_CFG_CMD_LIMIT_RESERVED_0_17_LEN = 18;
static const uint32_t INT_VC_ERQ_CFG_CMD_LIMIT_MAX_ERQ_DMA_READ = 18;
static const uint32_t INT_VC_ERQ_CFG_CMD_LIMIT_MAX_ERQ_DMA_READ_LEN = 6;
static const uint32_t INT_VC_ERQ_CFG_CMD_LIMIT_RESERVED_24_25 = 24;
static const uint32_t INT_VC_ERQ_CFG_CMD_LIMIT_RESERVED_24_25_LEN = 2;
static const uint32_t INT_VC_ERQ_CFG_CMD_LIMIT_MAX_ERQ_DMA_WRITE = 26;
static const uint32_t INT_VC_ERQ_CFG_CMD_LIMIT_MAX_ERQ_DMA_WRITE_LEN = 6;
// proc/reg00008.H

static const uint64_t INT_VC_IQA_CFG = 0x0201091full;

static const uint32_t INT_VC_IQA_CFG_RESERVED_0 = 0;
static const uint32_t INT_VC_IQA_CFG_IPI_QUEUE_PRIORITY = 1;
static const uint32_t INT_VC_IQA_CFG_IPI_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_IQA_CFG_RESERVED_4 = 4;
static const uint32_t INT_VC_IQA_CFG_HWD_QUEUE_PRIORITY = 5;
static const uint32_t INT_VC_IQA_CFG_HWD_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_IQA_CFG_RESERVED_8 = 8;
static const uint32_t INT_VC_IQA_CFG_NXC_QUEUE_PRIORITY = 9;
static const uint32_t INT_VC_IQA_CFG_NXC_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_IQA_CFG_RESERVED_12 = 12;
static const uint32_t INT_VC_IQA_CFG_INT_QUEUE_PRIORITY = 13;
static const uint32_t INT_VC_IQA_CFG_INT_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_IQA_CFG_RESERVED_16 = 16;
static const uint32_t INT_VC_IQA_CFG_OS_QUEUE_PRIORITY = 17;
static const uint32_t INT_VC_IQA_CFG_OS_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_IQA_CFG_RESERVED_20 = 20;
static const uint32_t INT_VC_IQA_CFG_POOL_QUEUE_PRIORITY = 21;
static const uint32_t INT_VC_IQA_CFG_POOL_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_IQA_CFG_RESERVED_24 = 24;
static const uint32_t INT_VC_IQA_CFG_HARD_QUEUE_PRIORITY = 25;
static const uint32_t INT_VC_IQA_CFG_HARD_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_IQA_CFG_RESERVED_28 = 28;
static const uint32_t INT_VC_IQA_CFG_LOCAL_QUEUE_PRIORITY = 29;
static const uint32_t INT_VC_IQA_CFG_LOCAL_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_IQA_CFG_RESERVED_32_33 = 32;
static const uint32_t INT_VC_IQA_CFG_RESERVED_32_33_LEN = 2;
static const uint32_t INT_VC_IQA_CFG_MAX_OUTSTANDING_ESBC_DEM = 34;
static const uint32_t INT_VC_IQA_CFG_MAX_OUTSTANDING_ESBC_DEM_LEN = 6;
static const uint32_t INT_VC_IQA_CFG_RESERVED_40_41 = 40;
static const uint32_t INT_VC_IQA_CFG_RESERVED_40_41_LEN = 2;
static const uint32_t INT_VC_IQA_CFG_MAX_OUTSTANDING_EASC_DEM = 42;
static const uint32_t INT_VC_IQA_CFG_MAX_OUTSTANDING_EASC_DEM_LEN = 6;
static const uint32_t INT_VC_IQA_CFG_RESERVED_48_55 = 48;
static const uint32_t INT_VC_IQA_CFG_RESERVED_48_55_LEN = 8;
// proc/reg00008.H

static const uint64_t INT_VC_QUEUES_PERF_EVENT_SEL_4 = 0x0201092aull;

static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_FROM_AIB = 0;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_FROM_AIB_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_IRQ_TO_IQA = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_IRQ_TO_IQA_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_IQA_TO_DPS = 8;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_IQA_TO_DPS_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_IQA_TO_IQS = 12;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_IQA_TO_IQS_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_IQS_TO_EQA = 16;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_IQS_TO_EQA_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_EQA_TO_ERQ = 20;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_EQA_TO_ERQ_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_EQA_TO_ATX = 24;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_EQA_TO_ATX_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_EQA_TO_ENDC = 28;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_4_EQA_TO_ENDC_LEN = 4;
// proc/reg00008.H

static const uint64_t INT_VC_VSD_TABLE_ADDR = 0x02010900ull;

static const uint32_t INT_VC_VSD_TABLE_ADDR_AUTO_INCREMENT = 0;
static const uint32_t INT_VC_VSD_TABLE_ADDR_TABLE_SELECT = 12;
static const uint32_t INT_VC_VSD_TABLE_ADDR_TABLE_SELECT_LEN = 4;
static const uint32_t INT_VC_VSD_TABLE_ADDR_RESERVED_16_27 = 16;
static const uint32_t INT_VC_VSD_TABLE_ADDR_RESERVED_16_27_LEN = 12;
static const uint32_t INT_VC_VSD_TABLE_ADDR_TABLE_ADDRESS = 28;
static const uint32_t INT_VC_VSD_TABLE_ADDR_TABLE_ADDRESS_LEN = 4;
// proc/reg00008.H

static const uint64_t MCD_BANK0_CMD = 0x0301080eull;

static const uint32_t MCD_BANK0_CMD_CHECK_CMDS = 0;
static const uint32_t MCD_BANK0_CMD_CHECK_CMDS_LEN = 19;
static const uint32_t MCD_BANK0_CMD_CHECK_CMDS_EN = 31;
static const uint32_t MCD_BANK0_CMD_SET_CMDS = 32;
static const uint32_t MCD_BANK0_CMD_SET_CMDS_LEN = 19;
static const uint32_t MCD_BANK0_CMD_SET_CMDS_EN = 63;
// proc/reg00008.H

static const uint64_t MM0_MM_FIR1_ACTION0_REG = 0x02010c46ull;

static const uint32_t MM0_MM_FIR1_ACTION0_REG_MM_FIR1_ACTION0 = 0;
static const uint32_t MM0_MM_FIR1_ACTION0_REG_MM_FIR1_ACTION0_LEN = 46;
// proc/reg00008.H

static const uint64_t MM0_MM_FIR1_ACTION1_REG = 0x02010c47ull;

static const uint32_t MM0_MM_FIR1_ACTION1_REG_MM_FIR1_ACTION1 = 0;
static const uint32_t MM0_MM_FIR1_ACTION1_REG_MM_FIR1_ACTION1_LEN = 46;
// proc/reg00008.H

static const uint64_t MM1_MM_CFG_NMMU_XLAT_CTL_REG0 = 0x03010c4aull;

static const uint32_t MM1_MM_CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR = 0;
static const uint32_t MM1_MM_CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR_LEN = 64;
// proc/reg00008.H

static const uint64_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG = 0x03010c11ull;

static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE = 0;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE_LEN = 2;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE = 2;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE_LEN = 2;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE = 4;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY = 5;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY_LEN = 4;
// proc/reg00008.H

static const uint64_t NX_DBG_DMA_ENG_FIR_RWX = 0x02011100ull;
static const uint64_t NX_DBG_DMA_ENG_FIR_WOX_AND = 0x02011101ull;
static const uint64_t NX_DBG_DMA_ENG_FIR_WOX_OR = 0x02011102ull;

static const uint32_t NX_DBG_DMA_ENG_FIR_DMA_HANG_TIMER_FIR = 0;
static const uint32_t NX_DBG_DMA_ENG_FIR_SHM_INVALID_STATE_FIR = 1;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_02_FIR = 2;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_03_FIR = 3;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH0_842_ECC_CE_FIR = 4;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH0_842_ECC_UE_FIR = 5;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH1_842_ECC_CE_FIR = 6;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH1_842_ECC_UE_FIR = 7;
static const uint32_t NX_DBG_DMA_ENG_FIR_DMA_NONZERO_CSB_CC_FIR = 8;
static const uint32_t NX_DBG_DMA_ENG_FIR_DMA_ECC_CE_FIR = 9;
static const uint32_t NX_DBG_DMA_ENG_FIR_DMA_OUTWR_INRD_ECC_CE_FIR = 10;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH4_GZIP_ECC_CE_FIR = 11;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH4_GZIP_ECC_UE_FIR = 12;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH4_GZIP_PE_FIR = 13;
static const uint32_t NX_DBG_DMA_ENG_FIR_OTHER_SCOM_SAT_FIR = 14;
static const uint32_t NX_DBG_DMA_ENG_FIR_DMA_INVALID_STATE_UNRECOV_FIR = 15;
static const uint32_t NX_DBG_DMA_ENG_FIR_DMA_INVALID_STATE_RECOV_FIR = 16;
static const uint32_t NX_DBG_DMA_ENG_FIR_DMA_ECC_UE_FIR = 17;
static const uint32_t NX_DBG_DMA_ENG_FIR_DMA_OUTWR_INRD_ECC_UE_FIR = 18;
static const uint32_t NX_DBG_DMA_ENG_FIR_DMA_INRD_DONE_ERR_FIR = 19;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH0_842_INVALID_STATE_FIR = 20;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH1_842_INVALID_STATE_FIR = 21;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH2_SYM_INVALID_STATE_FIR = 22;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH3_SYM_INVALID_STATE_FIR = 23;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH4_GZIP_INVALID_STATE_FIR = 24;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_25_FIR = 25;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_26_FIR = 26;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_27_FIR = 27;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_28_FIR = 28;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_29_FIR = 29;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_30_FIR = 30;
static const uint32_t NX_DBG_DMA_ENG_FIR_CRB_ECC_UE_FIR = 31;
static const uint32_t NX_DBG_DMA_ENG_FIR_CRB_ECC_SUE_FIR = 32;
static const uint32_t NX_DBG_DMA_ENG_FIR_DMA_OUTWR_INRD_ECC_SUE_FIR = 33;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH0_842_WATCHDOG_FIR = 34;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH1_842_WATCHDOG_FIR = 35;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH2_SYM_WATCHDOG_FIR = 36;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH3_SYM_WATCHDOG_FIR = 37;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_38_FIR = 38;
static const uint32_t NX_DBG_DMA_ENG_FIR_CH4_GZIP_WATCHDOG_FIR = 39;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_40_FIR = 40;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_41_FIR = 41;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_42_FIR = 42;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_43_FIR = 43;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_44_FIR = 44;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_45_FIR = 45;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_46_FIR = 46;
static const uint32_t NX_DBG_DMA_ENG_FIR_RESERVED_47_FIR = 47;
// proc/reg00008.H

static const uint64_t NX_DMA_SU_CH4_ABORT_CSB = 0x0201104bull;
// proc/reg00008.H

static const uint64_t NX_DMA_SU_ENGINE_ENABLE = 0x02011041ull;

static const uint32_t NX_DMA_SU_ENGINE_ENABLE_ALLOW_CRYPTO = 0;
static const uint32_t NX_DMA_SU_ENGINE_ENABLE_CH3_SYM_ENABLE = 57;
static const uint32_t NX_DMA_SU_ENGINE_ENABLE_CH2_SYM_ENABLE = 58;
static const uint32_t NX_DMA_SU_ENGINE_ENABLE_CH4_GZIP_ENABLE = 61;
static const uint32_t NX_DMA_SU_ENGINE_ENABLE_CH1_EFT_ENABLE = 62;
static const uint32_t NX_DMA_SU_ENGINE_ENABLE_CH0_EFT_ENABLE = 63;
// proc/reg00008.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG = 0x020110a6ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_ENABLE = 0;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_FREEZE = 1;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_RESET = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_DIS_GLOB_SCOM = 3;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_PRESCALAR_SEL0 = 4;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_PRESCALAR_SEL0_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_PRESCALAR_SEL1 = 6;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_PRESCALAR_SEL1_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_PRESCALAR_SEL2 = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_PRESCALAR_SEL2_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_PRESCALAR_SEL3 = 10;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_PRESCALAR_SEL3_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT0_PAIR_OP = 12;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT0_PAIR_OP_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT1_PAIR_OP = 14;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT1_PAIR_OP_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT2_PAIR_OP = 16;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT2_PAIR_OP_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT3_PAIR_OP = 18;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT3_PAIR_OP_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT0_MUX_SEL = 20;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT0_MUX_SEL_LEN = 3;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT1_MUX_SEL = 23;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT1_MUX_SEL_LEN = 3;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT2_MUX_SEL = 26;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT2_MUX_SEL_LEN = 3;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT3_MUX_SEL = 29;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CNT3_MUX_SEL_LEN = 3;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_FREEZE_ON_OVERFLOW = 32;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CASCADE = 33;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_CONTROL_REG_CASCADE_LEN = 3;
// proc/reg00008.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_COUNTER_REG = 0x020110a7ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_COUNTER_REG_0 = 0;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_COUNTER_REG_0_LEN = 16;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_COUNTER_REG_1 = 16;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_COUNTER_REG_1_LEN = 16;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_COUNTER_REG_2 = 32;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_COUNTER_REG_2_LEN = 16;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_COUNTER_REG_3 = 48;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PMU0_COUNTER_REG_3_LEN = 16;
// proc/reg00008.H

static const uint64_t NX_PBI_UMAC_SU_ERROR_RPT = 0x020110d3ull;

static const uint32_t NX_PBI_UMAC_SU_ERROR_RPT_0 = 0;
static const uint32_t NX_PBI_UMAC_SU_ERROR_RPT_0_LEN = 19;
static const uint32_t NX_PBI_UMAC_SU_ERROR_RPT_1 = 33;
static const uint32_t NX_PBI_UMAC_SU_ERROR_RPT_1_LEN = 23;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM10_PMU1_TLPM_COUNTER = 0x1001181cull;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM23_CFG_TLPM_REG = 0x1101181aull;

static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_EN = 0;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_RESET_MODE = 1;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_COUNTER_MODE = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_GLOBAL_PMISC_DIS = 3;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_GLOBAL_PMISC_MODE = 4;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_EXTERNAL_FREEZE = 5;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_0_1_OP = 6;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_0_1_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_2_3_OP = 8;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_2_3_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_4_5_OP = 10;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_4_5_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_6_7_OP = 12;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_6_7_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_8_9_OP = 14;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_8_9_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_10_11_OP = 16;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_10_11_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_12_13_OP = 18;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_12_13_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_14_15_OP = 20;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_14_15_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_16_17_OP = 22;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_16_17_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_18_19_OP = 24;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_18_19_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_20_21_OP = 26;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_20_21_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_22_23_OP = 28;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_22_23_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_24_25_OP = 30;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_24_25_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_26_27_OP = 32;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_26_27_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_28_29_OP = 34;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_28_29_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_30_31_OP = 36;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_30_31_OP_LEN = 2;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_CASCADE_PMU0 = 38;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_CASCADE_PMU0_LEN = 3;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_CASCADE_PMU1 = 41;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_CASCADE_PMU1_LEN = 3;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_CASCADE_PMU2 = 44;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_CASCADE_PMU2_LEN = 3;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_CASCADE_PMU3 = 47;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_CASCADE_PMU3_LEN = 3;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_SPARE = 50;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_REG_SPARE_LEN = 6;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM23_CNPM_PMU_PRESCALER = 0x11011820ull;

static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0 = 0;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1 = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2 = 4;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3 = 6;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0 = 8;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1 = 10;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2 = 12;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3 = 14;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0 = 16;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1 = 18;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2 = 20;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3 = 22;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0 = 24;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1 = 26;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2 = 28;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3 = 30;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0 = 32;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1 = 34;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2 = 36;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3 = 38;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0 = 40;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1 = 42;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2 = 44;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3 = 46;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0 = 48;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1 = 50;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2 = 52;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3 = 54;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0 = 56;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1 = 58;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2 = 60;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2_LEN = 2;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3 = 62;
static const uint32_t PB_PTLSCOM23_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3_LEN = 2;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM23_PMU3_TLPM_COUNTER = 0x1101181eull;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM23_PSAVE01_MODE_CFG = 0x11011814ull;

static const uint32_t PB_PTLSCOM23_PSAVE01_MODE_CFG_MODE = 0;
static const uint32_t PB_PTLSCOM23_PSAVE01_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PTLSCOM23_PSAVE01_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PTLSCOM23_PSAVE01_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PTLSCOM23_PSAVE01_MODE_CFG_SPARE = 5;
static const uint32_t PB_PTLSCOM23_PSAVE01_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM23_PSAVE01_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PTLSCOM23_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN = 8;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM23_TL_LINK_DLY_0123_REG = 0x1101180eull;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM23_TL_LINK_RT_DELAY_CTL_REG = 0x11011819ull;

static const uint32_t PB_PTLSCOM23_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET = 0;
static const uint32_t PB_PTLSCOM23_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_PTLSCOM23_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET = 2;
static const uint32_t PB_PTLSCOM23_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_PTLSCOM23_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT = 4;
static const uint32_t PB_PTLSCOM23_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN = 2;
static const uint32_t PB_PTLSCOM23_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT = 6;
static const uint32_t PB_PTLSCOM23_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN = 2;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM45_TL_LINK_SYN_01_REG = 0x12011812ull;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG = 0x1301182cull;

static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_0 = 0;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_0_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_1 = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_1_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_2 = 14;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_2_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_3 = 21;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_3_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_4 = 28;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_4_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_5 = 35;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_5_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_6 = 42;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_6_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_7 = 49;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_7_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_8 = 56;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_LINK_EVENT_8_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX1_REG_ALT_EVENTS = 63;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG = 0x1301182dull;

static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_9 = 0;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_9_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_10 = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_10_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_11 = 14;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_11_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_12 = 21;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_12_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_13 = 28;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_13_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_14 = 35;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_14_LEN = 7;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_15 = 42;
static const uint32_t PB_PTLSCOM67_CFG_TLPM_MUX2_REG_15_LEN = 7;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM67_EN_DOB_ECC_ERR_REG = 0x13011818ull;
// proc/reg00008.H

static const uint64_t PB_PTLSCOM67_PERFTRACE_CFG_REG = 0x1301182bull;

static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE = 0;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE = 1;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE = 2;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_TSPARE6 = 3;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE = 4;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE = 5;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE = 6;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_TSPARE7 = 7;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT = 8;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT_LEN = 2;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT = 10;
static const uint32_t PB_PTLSCOM67_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT_LEN = 2;
// proc/reg00008.H

static const uint64_t PB_BRIDGE_HCA_FIR_DATA_RWX = 0x03012400ull;
static const uint64_t PB_BRIDGE_HCA_FIR_DATA_WOX_AND = 0x03012401ull;
static const uint64_t PB_BRIDGE_HCA_FIR_DATA_WOX_OR = 0x03012402ull;

static const uint32_t PB_BRIDGE_HCA_FIR_DATA_FIR_DATA_BITS = 0;
static const uint32_t PB_BRIDGE_HCA_FIR_DATA_FIR_DATA_BITS_LEN = 28;
// proc/reg00008.H

static const uint64_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM = 0x030120c1ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_ALLOC = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_SCOPE = 1;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_SCOPE_LEN = 3;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_PRIORITY = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_SIZE_SMALL = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_SPARE67 = 6;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_SPARE67_LEN = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_BASE = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_BASE_LEN = 32;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_SIZE = 40;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_MEM_SIZE_LEN = 9;
// proc/reg00008.H

static const uint64_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT = 0x030120c2ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_SPARE = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_SPARE_LEN = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_CRESP_OV = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_REPAIR = 3;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_BUF_WAIT = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_STATUS_TRIG_DROPPED_Q = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_ADDR_ERROR = 6;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_STATUS_REC_DROPPED_Q = 7;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_INIT = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_PREREQ = 9;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_READY = 10;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_TRACING = 11;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_PAUSED = 12;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_FLUSH = 13;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_COMPLETE = 14;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_ENABLE = 15;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_HTMCO_STATUS_STAMP = 16;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_STATUS_SCOM_ERROR = 17;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_STATUS_PARITY_ERROR = 18;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_STAT_STATUS_INVALID_CRESP = 19;
// proc/reg00008.H

static const uint64_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG = 0x08010800ull;

static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_DATASTART_MODE = 16;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_DATASTART_MODE_LEN = 3;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_TX_RESP_HWM = 20;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_TX_RESP_HWM_LEN = 4;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_TX_RESP_LWM = 24;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_TX_RESP_LWM_LEN = 4;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_EARLYEMPTY_MODE = 28;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_EARLYEMPTY_MODE_LEN = 2;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_PCIE_CLK_TRACE_EN = 30;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_SELECT_ETU_TRACE = 31;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_PCI_CLK_TRACE_SEL = 32;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_PCI_CLK_TRACE_SEL_LEN = 4;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_ISMB_ERROR_INJECT = 36;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_ISMB_ERROR_INJECT_LEN = 3;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_HOL_BLK_CNT = 40;
static const uint32_t PE0_PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_HOL_BLK_CNT_LEN = 3;
// proc/reg00008.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_CERR_RPT_REG = 0x080108cbull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_CERR_RPT_REG_PBAIB_CERR_RPT0 = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN = 21;
// proc/reg00008.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRACTION0_REG = 0x02011846ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRACTION0_REG_NFIRACTION0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRACTION0_REG_NFIRACTION0_LEN = 28;
// proc/reg00008.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRACTION1_REG = 0x02011847ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRACTION1_REG_NFIRACTION1 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRACTION1_REG_NFIRACTION1_LEN = 28;
// proc/reg00008.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PBCQMODE_REG = 0x0201184dull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PBCQMODE_REG_PEER2PEER_MODDE = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PBCQMODE_REG_ENHANCED_PEER2PEER_MODDE = 1;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PBCQMODE_REG_PB_CQ_REGS_CS_ENABLE_SMF = 2;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PBCQMODE_REG_ATOMIC_LITTLE_ENDIAN = 3;
// proc/reg00008.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR1_MASK_REG = 0x02011891ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN = 40;
// proc/reg00008.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRACTION0_REG = 0x02011886ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRACTION0_REG_NFIRACTION0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRACTION0_REG_NFIRACTION0_LEN = 28;
// proc/reg00008.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRACTION1_REG = 0x02011887ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRACTION1_REG_NFIRACTION1 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRACTION1_REG_NFIRACTION1_LEN = 28;
// proc/reg00008.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRACTION0_REG = 0x020118c6ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRACTION0_REG_NFIRACTION0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRACTION0_REG_NFIRACTION0_LEN = 28;
// proc/reg00009.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRACTION1_REG = 0x020118c7ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRACTION1_REG_NFIRACTION1 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRACTION1_REG_NFIRACTION1_LEN = 28;
// proc/reg00009.H

static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_PHB5_PMON_EVENT_SEL = 0x08010918ull;
// proc/reg00009.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL = 0x00000984ull;

static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_ENABLE = 0;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE = 12;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN = 8;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE = 44;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN = 8;
// proc/reg00009.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG = 0x0901084dull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA = 0;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR = 10;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR_LEN = 6;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA = 16;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR = 26;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR_LEN = 6;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA = 32;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR = 41;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR_LEN = 7;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA = 48;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR = 58;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR_LEN = 6;
// proc/reg00009.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG = 0x0901088eull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A = 33;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A_LEN = 2;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R = 44;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R_LEN = 4;
// proc/reg00009.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_1_PFIR_REG_RWX = 0x09010880ull;
static const uint64_t PE1_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_AND = 0x09010881ull;
static const uint64_t PE1_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_OR = 0x09010882ull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR = 0;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR_LEN = 6;
// proc/reg00009.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRWOF_REG = 0x03011848ull;
// proc/reg00009.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRMASK_REG_RW = 0x030118c3ull;
static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRMASK_REG_WO_AND = 0x030118c4ull;
static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRMASK_REG_WO_OR = 0x030118c5ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRMASK_REG_NFIRMASK = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRMASK_REG_NFIRMASK_LEN = 28;
// proc/reg00009.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL = 0x00000904ull;

static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_ENABLE = 0;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE = 12;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN = 8;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE = 44;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN = 8;
// proc/reg00009.H

static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RWX = 0x09010988ull;
static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_WOX_AND = 0x09010989ull;
static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_WOX_OR = 0x0901098aull;

static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID = 0;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID = 1;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR = 2;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR = 3;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR = 4;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR = 6;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED = 7;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR = 8;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR = 9;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR = 10;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR = 11;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE = 12;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT = 13;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR = 14;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR = 15;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR = 16;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR = 17;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR = 18;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR = 19;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR = 20;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR = 21;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR = 22;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR = 23;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR = 24;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR = 25;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR = 26;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR = 27;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR = 28;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR = 29;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_SCOM_INF_ERROR = 30;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS = 31;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR = 32;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR = 33;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR = 34;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_TVT_ERROR = 35;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG = 36;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG = 37;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG = 38;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR = 39;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR = 40;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR = 41;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR = 42;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR = 43;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR = 44;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR = 45;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED = 46;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR = 47;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR = 48;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR = 49;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR = 50;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR = 51;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR = 52;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_MRG_MRT_ERROR = 53;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR = 56;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR = 57;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR = 58;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR = 59;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR = 60;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR = 61;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR = 63;
// proc/reg00009.H

static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_PHB5_PMON_COUNTERS = 0x09010999ull;
// proc/reg00009.H

static const uint64_t TP_TPBR_AD_LPC_CMD_REG = 0x00090041ull;

static const uint32_t TP_TPBR_AD_LPC_CMD_REG_RNW = 0;
static const uint32_t TP_TPBR_AD_LPC_CMD_REG_SIZE = 5;
static const uint32_t TP_TPBR_AD_LPC_CMD_REG_SIZE_LEN = 7;
static const uint32_t TP_TPBR_AD_LPC_CMD_REG_ADR = 32;
static const uint32_t TP_TPBR_AD_LPC_CMD_REG_ADR_LEN = 32;
// proc/reg00009.H

static const uint64_t TP_TPBR_AD_SND_MODE_REG = 0x03001c21ull;

static const uint32_t TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0 = 0;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1 = 1;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE = 2;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD = 3;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY = 4;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY_LEN = 4;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD = 8;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD = 9;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD = 10;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD = 11;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD = 12;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD = 13;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD = 14;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD = 15;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD = 16;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD = 17;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD = 18;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP = 19;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP = 20;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP = 21;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_PB_STOP = 22;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD = 25;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER = 26;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER_LEN = 2;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD = 28;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE = 29;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB = 30;
static const uint32_t TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD = 31;
// proc/reg00009.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAPBTXT2 = 0x03021cd2ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2__VALID = 0;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2__VALID_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_0 = 8;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_0_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_1 = 12;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_1_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_2 = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_2_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_3 = 20;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_3_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_4 = 24;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_4_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_5 = 28;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_5_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_6 = 32;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_6_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_7 = 36;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBTXT2_7_LEN = 4;
// proc/reg00009.H

static const uint64_t TP_TPBR_PBA_PBAO_BCUE_PBADR = 0x00068018ull;

static const uint32_t TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET_LEN = 23;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26 = 25;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR = 27;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR_LEN = 14;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42 = 41;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42_LEN = 2;
// proc/reg00009.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXRCVSTAT = 0x00068024ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXRCVSTAT_IN_PROGRESS = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXRCVSTAT_ERROR = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXRCVSTAT_WRITE_IN_PROGRESS = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXRCVSTAT_RESERVATION_SET = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXRCVSTAT_CAPTURE = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXRCVSTAT_CAPTURE_LEN = 16;
// proc/reg00009.H

static const uint64_t TP_TPBR_PSI_WRAP_TX_ERR_MODE = 0x03011c07ull;
// proc/reg00009.H

static const uint64_t TP_TPBR_PSIHB_EMPTY_10 = 0x03011d10ull;
// proc/reg00009.H

static const uint64_t TP_TPBR_PSIHB_EMPTY_1B = 0x03011d1bull;
// proc/reg00009.H

static const uint64_t TP_TPBR_PSIHB_FIR_ACTION0_REG = 0x03011d06ull;

static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_PB_ECC_ERR_CE_ACTION0 = 0;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_PB_ECC_ERR_UE_ACTION0 = 1;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_PB_ECC_ERR_SUE_ACTION0 = 2;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INTERRUPT_FROM_ERROR_ACTION0 = 3;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INTERRUPT_FROM_FSP_ACTION0 = 4;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_FSP_ECC_ERR_CE_ACTION0 = 5;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_FSP_ECC_ERR_UE_ACTION0 = 6;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_ERROR_STATE_ACTION0 = 7;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INVALID_TTYPE_ACTION0 = 8;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INVALID_CRESP_ACTION0 = 9;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_PB_DATA_TIME_OUT_ACTION0 = 10;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_PB_PARITY_ERROR_ACTION0 = 11;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION0 = 12;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_UNEXPECTED_PB_ACTION0 = 13;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION0 = 14;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INTERRUPT0_ADDRESS_ERROR_ACTION0 = 15;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INTERRUPT1_ADDRESS_ERROR_ACTION0 = 16;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INTERRUPT2_ADDRESS_ERROR_ACTION0 = 17;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INTERRUPT3_ADDRESS_ERROR_ACTION0 = 18;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INTERRUPT4_ADDRESS_ERROR_ACTION0 = 19;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_INTERRUPT5_ADDRESS_ERROR_ACTION0 = 20;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION0 = 21;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION0 = 22;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_UPSTREAM_FIR_ACTION0 = 23;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_SPARE_FIR_ACTION0 = 24;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_SPARE_FIR_ACTION0_LEN = 3;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION0_REG_FIR_PARITY_ERROR_ACTION0 = 27;
// proc/reg00009.H

static const uint64_t TP_TPBR_PSIHB_FIR_ACTION1_REG = 0x03011d07ull;

static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1 = 0;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1 = 1;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1 = 2;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1 = 3;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1 = 4;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1 = 5;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1 = 6;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1 = 7;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1 = 8;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1 = 9;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1 = 10;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1 = 11;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1 = 12;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1 = 13;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1 = 14;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1 = 15;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1 = 16;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1 = 17;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1 = 18;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1 = 19;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1 = 20;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1 = 21;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1 = 22;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1 = 23;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1 = 24;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1_LEN = 3;
static const uint32_t TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1 = 27;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV = 0x0006d202ull;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1 = 0x00060041ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN = 32;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML = 0x00060029ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_BUSY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_BYTE_ENABLE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_BYTE_ENABLE_LEN = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_LINE_MODE = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_ERROR = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_ERROR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_IFETCH_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_DATAOP_PENDING = 31;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU = 0x00060028ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN = 32;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0 = 0x00060030ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN = 30;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0 = 0x00060080ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1_LEN = 32;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR = 0x00062020ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN = 3;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC = 0x00062019ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_MEM_IFETCH_PENDING = 35;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR = 0x00064024ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN = 32;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR = 0x00064014ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR_LEN = 32;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5 = 0x00066045ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN = 32;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM = 0x00066017ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE = 35;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE_LEN = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE = 43;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING = 62;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING = 63;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA = 0x00066012ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR_LEN = 32;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4 = 0x00066082ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5_LEN = 32;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADCCR0 = 0x0006c800ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR0_FRAME_SIZE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR0_FRAME_SIZE_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR0_OUT_COUNT = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR0_OUT_COUNT_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR0_IN_DELAY = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR0_IN_DELAY_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR0_IN_COUNT = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADCCR0_IN_COUNT_LEN = 6;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4 = 0x0006c824ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9 = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9_LEN = 16;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_DORP1 = 0x0006c183ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER_LEN = 32;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G0ISR1 = 0x0006c074ull;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G1ISR1 = 0x0006c075ull;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G2ISR1 = 0x0006c076ull;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_G3ISR1 = 0x0006c077ull;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21 = 0x0006c723ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1_LEN = 16;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0 = 0x0006c701ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0_LEN = 6;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SST1A = 0x0006c726ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST1A__ONGOING_1A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST1A__WRITE_WHILE_BRIDGE_BUSY_ERR_1A = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST1A__FSM_ERR_1A = 7;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3 = 0x0006c233ull;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2 = 0x0006c224ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE = 31;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSHI1 = 0x0006c215ull;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLI3 = 0x0006c232ull;
// proc/reg00009.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW = 0x0006c0b8ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR = 0x0006c0b9ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR = 0x0006c0baull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS_LEN = 32;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SCOM = 0x0006c080ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SCOM1 = 0x0006c081ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SCOM2 = 0x0006c082ull;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR = 0x0006c501ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3 = 0x0006c403ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR = 0x0006c509ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR = 0x0006c511ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR = 0x0006c519ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7 = 0x0006c41full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1 = 0x0006c421ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR = 0x0006c521ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR = 0x0006c529ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR = 0x0006c531ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR = 0x0006c539ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5 = 0x0006c43dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16 = 0x0006c450ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD_LEN = 17;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR = 0x0006c553ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD_LEN = 17;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21 = 0x0006c455ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD_LEN = 17;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR = 0x0006c546ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD_LEN = 17;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C1 = 0x0006c461ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD_LEN = 17;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C10 = 0x0006c46aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD_LEN = 17;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C27 = 0x0006c47bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD_LEN = 17;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR = 0x0006c566ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD_LEN = 17;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR = 0x0006c582ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7_LEN = 4;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR = 0x0006c584ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7_LEN = 4;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OUISR1 = 0x0006c072ull;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1 = 0x0006d030ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS_LEN = 26;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR = 0x0006d201ull;

static const uint32_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7_LEN = 2;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1 = 0x01010807ull;

static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1_LEN = 62;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OCC_SRAM_CTL_SREAR = 0x0006a003ull;

static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS = 0;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS_LEN = 17;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107 = 0x0000806bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107_LEN = 64;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118 = 0x00008076ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118_LEN = 64;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18 = 0x00008012ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18_LEN = 64;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30 = 0x0000801eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30_LEN = 64;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51 = 0x00008033ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51_LEN = 64;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66 = 0x00008042ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66_LEN = 64;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79 = 0x0000804full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79_LEN = 64;
// proc/reg00010.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93 = 0x0000805dull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93_LEN = 64;
// proc/reg00010.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_SCPSIZE = 0x00001400ull;
// proc/reg00010.H

static const uint64_t TP_TPVSB_FSI_W_I2C_FIFO1_REGISTER_READ_A = 0x00001800ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_FIFO1_REGISTER_READ_A_FIFO_BITS_READ0_000 = 0;
static const uint32_t TP_TPVSB_FSI_W_I2C_FIFO1_REGISTER_READ_A_FIFO_BITS_READ0_000_LEN = 8;
// proc/reg00010.H

static const uint64_t TP_TPVSB_FSI_W_I2C_IMM_SET_S_SDA_A = 0x0000180cull;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_FSI = 0x00002824ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_FSI_BYTE = 0x00002890ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_SCOM = 0x00050020ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_PERMISSION_TO_SEND_DOORBELL_1 =
    0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_ABORT_DOORBELL_1 = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_LBUS_SLAVE_1B_PENDING = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_PIB_SLAVE_1A_PENDING = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_XDN_DOORBELL_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_XUP_DOORBELL_1 = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_HEADER_COUNT_1A = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_HEADER_COUNT_1A_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_DATA_COUNT_1A = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_DATA_COUNT_1A_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_HEADER_COUNT_1B = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_HEADER_COUNT_1B_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_DATA_COUNT_1B = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_1A_DATA_COUNT_1B_LEN = 8;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_GPWRP_RWX = 0x0000281full;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_GPWRP_MAGIC_COOKIE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_GPWRP_MAGIC_COOKIE_LEN = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_GPWRP_EN_OR_DIS_WRITE_PROTECTION = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_GPWRP_EN_OR_DIS_WRITE_PROTECTION_LEN = 16;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RWX = 0x0000284full;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_7_RWX = 0x00002847ull;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RWX = 0x000028cbull;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_1_RWX = 0x00002901ull;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_B_ROX = 0x00050025ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_B_RWX = 0x00002825ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_B_M1HC0B_MAILBOX_1_HEADER_COMMAND_0_B =
    0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_B_M1HC0B_MAILBOX_1_HEADER_COMMAND_0_B_LEN
    = 32;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_A_ROX = 0x00002829ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_A_RWX = 0x00050029ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_A_M2HC0A_MAILBOX_2_HEADER_COMMAND_0_A =
    0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_A_M2HC0A_MAILBOX_2_HEADER_COMMAND_0_A_LEN
    = 32;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_INTERRUPT_ROX = 0x00002835ull;

static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_INTERRUPT_LBUS_SLAVE_B_DOORBELL_ERROR_MAILBOX_2 = 26;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_INTERRUPT_LBUS_SLAVE_B_DOORBELL_ERROR_MAILBOX_1 = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_INTERRUPT_XDN_MAILBOX_2 = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_INTERRUPT_XDN_MAILBOX_1 = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_INTERRUPT_LBUS_SLAVE_B_PENDING_MAILBOX_2 =
    30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_INTERRUPT_LBUS_SLAVE_B_PENDING_MAILBOX_1 =
    31;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_COPY_RW = 0x00002915ull;
// proc/reg00010.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RWX = 0x0000283aull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3 = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3_LEN = 32;
// proc/reg00011.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_POLARITY = 0x000b005cull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_POLARITY_0 = 0;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_POLARITY_1 = 1;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_POLARITY_2 = 2;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_SND_BUFFER0_REGISTER_ROX = 0x00000c1dull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_SND_BUFFER0_REGISTER_DMA_PIB_SND_BUF0_REG_DATA0 = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_SND_BUFFER0_REGISTER_DMA_PIB_SND_BUF0_REG_DATA0_LEN = 32;
// proc/reg00011.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_RSIM = 0x00020019ull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_LLSTAT = 0x00000904ull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW = 0x00003000ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0 = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0_LEN = 10;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1 = 14;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN = 10;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4 = 25;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL = 26;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE = 29;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE_LEN = 3;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WOX = 0x000030dcull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3 = 1;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_FSI0 = 0x00003030ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_SCOMFSI0 = 0x00000c0cull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_FSI0 = 0x00003074ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_SCOMFSI0 = 0x00000c1dull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_FSI0 = 0x00003454ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_SCOMFSI0 = 0x00000d15ull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_FSI0 = 0x00003408ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_SCOMFSI0 = 0x00000d02ull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO = 0x000034d0ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2_LEN = 3;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SNMR = 0x0000084cull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SSISM = 0x00000810ull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SSTAT = 0x00000814ull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_FSI1 = 0x0000306cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_SCOMFSI1 = 0x00000c1bull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR = 0x00003020ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE = 6;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE = 7;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW = 0x00003010ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE = 6;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE = 7;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO = 0x000030e8ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2_LEN = 3;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_FSI1 = 0x00003074ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_SCOMFSI1 = 0x00000c1dull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SLBUS = 0x00000830ull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SRSIM0 = 0x00000870ull;
// proc/reg00011.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A4 = 0x000004a4ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR = 8;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE = 12;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE = 16;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE = 20;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE = 24;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE = 28;
// proc/reg00011.H

static const uint64_t VAS_VA_EG_SCF_ERRINJSO = 0x0201144bull;

static const uint32_t VAS_VA_EG_SCF_ERRINJSO_WC_ENA = 0;
static const uint32_t VAS_VA_EG_SCF_ERRINJSO_WC_TYP = 1;
static const uint32_t VAS_VA_EG_SCF_ERRINJSO_WC_FRQ = 2;
static const uint32_t VAS_VA_EG_SCF_ERRINJSO_WC_SEL = 3;
static const uint32_t VAS_VA_EG_SCF_ERRINJSO_WC_SEL_LEN = 2;
static const uint32_t VAS_VA_EG_SCF_ERRINJSO_EG_ENA = 5;
static const uint32_t VAS_VA_EG_SCF_ERRINJSO_EG_TYP = 6;
static const uint32_t VAS_VA_EG_SCF_ERRINJSO_EG_FRQ = 7;
static const uint32_t VAS_VA_EG_SCF_ERRINJSO_EG_SEL = 8;
// proc/reg00011.H

static const uint64_t VAS_VA_EG_SCF_PGMIG1 = 0x02011441ull;
// proc/reg00011.H

static const uint64_t VAS_VA_RG_SCF_RGERRRPT = 0x0201142cull;

static const uint32_t VAS_VA_RG_SCF_RGERRRPT_RESET = 0;
static const uint32_t VAS_VA_RG_SCF_RGERRRPT_BIT4 = 4;
static const uint32_t VAS_VA_RG_SCF_RGERRRPT_BIT5 = 5;
static const uint32_t VAS_VA_RG_SCF_RGERRRPT_BIT6 = 6;
static const uint32_t VAS_VA_RG_SCF_RGERRRPT_BIT7 = 7;
static const uint32_t VAS_VA_RG_SCF_RGERRRPT_BIT8 = 8;
static const uint32_t VAS_VA_RG_SCF_RGERRRPT_BIT9 = 9;
static const uint32_t VAS_VA_RG_SCF_RGERRRPT_BIT10 = 10;
static const uint32_t VAS_VA_RG_SCF_RGERRRPT_BIT11 = 11;
static const uint32_t VAS_VA_RG_SCF_RGERRRPT_BIT12 = 12;
static const uint32_t VAS_VA_RG_SCF_RGERRRPT_BIT13 = 13;
// proc/reg00011.H

static const uint64_t VAS_VA_RG_SCF_RMABAR = 0x0201140eull;

static const uint32_t VAS_VA_RG_SCF_RMABAR_RMA_BAR = 8;
static const uint32_t VAS_VA_RG_SCF_RMABAR_RMA_BAR_LEN = 44;
// proc/reg00011.H

static const uint64_t VAS_VA_RG_SCF_WRMON2BAR = 0x02011412ull;
// proc/reg00011.H

static const uint64_t VAS_VA_RG_SCF_WRMON6CMP = 0x02011426ull;
// proc/reg00011.H

static const uint64_t VAS_VA_RG_SCF_WRMON7WID = 0x0201141full;
// proc/reg00011.H

}
}
#include "proc/reg00008.H"
#include "proc/reg00009.H"
#include "proc/reg00010.H"
#include "proc/reg00011.H"
#endif
