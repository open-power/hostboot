/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_5.H $       */
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

#ifndef __p10_scom_proc_5_H_
#define __p10_scom_proc_5_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_CFG_STQ1 = 0x02010818ull;

static const uint32_t INT_CQ_CFG_STQ1_IPI_MIN_0_2 = 0;
static const uint32_t INT_CQ_CFG_STQ1_IPI_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ1_IPI_MAX_0_4 = 3;
static const uint32_t INT_CQ_CFG_STQ1_IPI_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ1_HW_MIN_0_2 = 8;
static const uint32_t INT_CQ_CFG_STQ1_HW_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ1_HW_MAX_0_4 = 11;
static const uint32_t INT_CQ_CFG_STQ1_HW_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ1_NXCQ_MIN_0_2 = 16;
static const uint32_t INT_CQ_CFG_STQ1_NXCQ_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ1_NXCQ_MAX_0_4 = 19;
static const uint32_t INT_CQ_CFG_STQ1_NXCQ_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ1_INTQ_MIN_0_2 = 24;
static const uint32_t INT_CQ_CFG_STQ1_INTQ_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ1_INTQ_MAX_0_4 = 27;
static const uint32_t INT_CQ_CFG_STQ1_INTQ_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ1_OS_MIN_0_2 = 32;
static const uint32_t INT_CQ_CFG_STQ1_OS_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ1_OS_MAX_0_4 = 35;
static const uint32_t INT_CQ_CFG_STQ1_OS_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ1_POOL_MIN_0_2 = 40;
static const uint32_t INT_CQ_CFG_STQ1_POOL_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ1_POOL_MAX_0_4 = 43;
static const uint32_t INT_CQ_CFG_STQ1_POOL_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ1_HARD_MIN_0_2 = 48;
static const uint32_t INT_CQ_CFG_STQ1_HARD_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ1_HARD_MAX_0_4 = 51;
static const uint32_t INT_CQ_CFG_STQ1_HARD_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_STQ1_THR_MIN_0_2 = 56;
static const uint32_t INT_CQ_CFG_STQ1_THR_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_STQ1_THR_MAX_0_4 = 59;
static const uint32_t INT_CQ_CFG_STQ1_THR_MAX_0_4_LEN = 5;
// proc/reg00022.H

static const uint64_t INT_CQ_WOF = 0x02010838ull;

static const uint32_t INT_CQ_WOF_INT_CQ_WOF = 0;
static const uint32_t INT_CQ_WOF_INT_CQ_WOF_LEN = 64;
// proc/reg00022.H

static const uint64_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1 = 0x02010a98ull;

static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD = 0;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE = 8;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD = 12;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD = 16;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD = 20;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN = 24;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT = 28;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT = 32;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT = 36;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU = 40;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE = 44;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY = 48;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES = 52;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE = 56;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63 = 60;
static const uint32_t INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63_LEN = 4;
// proc/reg00022.H

static const uint64_t INT_PC_NXC_REGS_WATCH3_DATA3 = 0x02010abfull;
// proc/reg00022.H

static const uint64_t INT_PC_REGS_AIB_RX_CRD_CMD = 0x02010a11ull;

static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1 = 0;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD = 2;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD_LEN = 6;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9 = 8;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD = 10;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD_LEN = 6;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17 = 16;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD = 18;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD_LEN = 6;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25 = 24;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD = 26;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD_LEN = 6;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33 = 32;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD = 34;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD_LEN = 6;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41 = 40;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD = 42;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD_LEN = 6;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49 = 48;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD = 50;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD_LEN = 6;
// proc/reg00022.H

static const uint64_t INT_PC_REGS_DBG = 0x02010a32ull;

static const uint32_t INT_PC_REGS_DBG_DBG_INT_VLD = 0;
static const uint32_t INT_PC_REGS_DBG_RESERVED_1_3 = 1;
static const uint32_t INT_PC_REGS_DBG_RESERVED_1_3_LEN = 3;
static const uint32_t INT_PC_REGS_DBG_DBG_INT_LEVEL = 4;
static const uint32_t INT_PC_REGS_DBG_DBG_INT_LEVEL_LEN = 3;
static const uint32_t INT_PC_REGS_DBG_RESERVED_7 = 7;
static const uint32_t INT_PC_REGS_DBG_DBG_INT_THRDID = 8;
static const uint32_t INT_PC_REGS_DBG_DBG_INT_THRDID_LEN = 8;
static const uint32_t INT_PC_REGS_DBG_RESERVED_16_23 = 16;
static const uint32_t INT_PC_REGS_DBG_RESERVED_16_23_LEN = 8;
// proc/reg00022.H

static const uint64_t INT_PC_REGS_ERR0_FATAL = 0x02010ac4ull;

static const uint32_t INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR = 0;
static const uint32_t INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR_LEN = 64;
// proc/reg00022.H

static const uint64_t INT_PC_REGS_ERR1_CFG1 = 0x02010ac9ull;

static const uint32_t INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0 = 0;
static const uint32_t INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0_LEN = 64;
// proc/reg00022.H

static const uint64_t INT_PC_REGS_ERR1_RECOV = 0x02010acdull;

static const uint32_t INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR = 0;
static const uint32_t INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR_LEN = 64;
// proc/reg00022.H

static const uint64_t INT_PC_REGS_TCTXT_EN0_RESET = 0x02010b03ull;
// proc/reg00022.H

static const uint64_t INT_VC_DPS_CFG = 0x02010949ull;

static const uint32_t INT_VC_DPS_CFG_IPI_LOOKUP_MODE = 0;
static const uint32_t INT_VC_DPS_CFG_HWD_LOOKUP_MODE = 1;
static const uint32_t INT_VC_DPS_CFG_NXC_LOOKUP_MODE = 2;
static const uint32_t INT_VC_DPS_CFG_INT_LOOKUP_MODE = 3;
static const uint32_t INT_VC_DPS_CFG_OS_LOOKUP_MODE = 4;
static const uint32_t INT_VC_DPS_CFG_POOL_LOOKUP_MODE = 5;
static const uint32_t INT_VC_DPS_CFG_HARD_LOOKUP_MODE = 6;
static const uint32_t INT_VC_DPS_CFG_LOC_LOOKUP_MODE = 7;
static const uint32_t INT_VC_DPS_CFG_RESERVED_8_15 = 8;
static const uint32_t INT_VC_DPS_CFG_RESERVED_8_15_LEN = 8;
static const uint32_t INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT = 16;
static const uint32_t INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT_LEN = 4;
static const uint32_t INT_VC_DPS_CFG_RESERVED_20 = 20;
static const uint32_t INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT = 21;
static const uint32_t INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT_LEN = 3;
static const uint32_t INT_VC_DPS_CFG_RESERVED_24_30 = 24;
static const uint32_t INT_VC_DPS_CFG_RESERVED_24_30_LEN = 7;
static const uint32_t INT_VC_DPS_CFG_DPS_IS_IDLE = 31;
// proc/reg00022.H

static const uint64_t INT_VC_ENDC_ADDITIONAL_PERF_2 = 0x0201099dull;

static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH = 0;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH_LEN = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP_LEN = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT = 16;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT_LEN = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD = 24;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD_LEN = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE = 32;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE_LEN = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE = 40;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE_LEN = 8;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63 = 48;
static const uint32_t INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63_LEN = 16;
// proc/reg00022.H

static const uint64_t INT_VC_ENDC_WATCH0_DATA1 = 0x020109a5ull;
// proc/reg00022.H

static const uint64_t INT_VC_ESBC_PERF_EVENT_SEL_2 = 0x02010959ull;

static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES = 0;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_LEN = 4;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY = 8;
static const uint32_t INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY_LEN = 4;
// proc/reg00022.H

static const uint64_t MCD_FIR_MASK_REG_RW = 0x03010803ull;
static const uint64_t MCD_FIR_MASK_REG_WO_AND = 0x03010804ull;
static const uint64_t MCD_FIR_MASK_REG_WO_OR = 0x03010805ull;

static const uint32_t MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK = 0;
static const uint32_t MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK = 1;
static const uint32_t MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK = 2;
static const uint32_t MCD_FIR_MASK_REG_SM_OR_CASE_MASK = 3;
static const uint32_t MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK = 4;
static const uint32_t MCD_FIR_MASK_REG_CRESP_ADDR_MASK = 5;
static const uint32_t MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK = 6;
static const uint32_t MCD_FIR_MASK_REG_TTAG_PARITY_MASK = 7;
static const uint32_t MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK = 8;
static const uint32_t MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK = 9;
static const uint32_t MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK = 10;
// proc/reg00022.H

static const uint64_t NX_CH4_ADDR_10_HASH_FUNCTION_REG = 0x0201114bull;

static const uint32_t NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION_LEN = 64;
// proc/reg00022.H

static const uint64_t NX_CH4_ADDR_7_HASH_FUNCTION_REG = 0x02011148ull;

static const uint32_t NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION_LEN = 64;
// proc/reg00022.H

static const uint64_t NX_CH4_DATATAG_3_HASH_FUNCTION_REG = 0x0201114full;

static const uint32_t NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION_LEN = 64;
// proc/reg00022.H

static const uint64_t NX_DMA_SU_ERROR_REPORT_1 = 0x02011058ull;

static const uint32_t NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1 = 0;
static const uint32_t NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1_LEN = 17;
// proc/reg00022.H

static const uint64_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR = 0x020110c0ull;

static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR = 8;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_LEN = 46;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE = 54;
static const uint32_t NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE_LEN = 3;
// proc/reg00022.H

static const uint64_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB = 0x020110cfull;

static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID = 4;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID_LEN = 12;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID = 20;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID_LEN = 20;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID = 44;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID_LEN = 16;
static const uint32_t NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE = 63;
// proc/reg00022.H

static const uint64_t PB_COM_ES3_EVENT_SEL = 0x0301139aull;

static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0 = 0;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0_LEN = 3;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1 = 3;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1_LEN = 3;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2 = 6;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2_LEN = 3;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3 = 9;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3_LEN = 3;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4 = 12;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4_LEN = 3;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5 = 15;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5_LEN = 3;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6 = 18;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6_LEN = 3;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7 = 21;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7_LEN = 3;
static const uint32_t PB_COM_ES3_EVENT_SEL_EVENT_EAST_BITWISE_ENABLE_ES3 = 24;
static const uint32_t PB_COM_ES3_EVENT_SEL_EVENT_EAST_BITWISE_ENABLE_ES3_LEN = 16;
static const uint32_t PB_COM_ES3_EVENT_SEL_EVENT_WEST_BITWISE_ENABLE_ES3 = 40;
static const uint32_t PB_COM_ES3_EVENT_SEL_EVENT_WEST_BITWISE_ENABLE_ES3_LEN = 16;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL = 56;
static const uint32_t PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2 = 57;
static const uint32_t PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK = 58;
static const uint32_t PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK = 59;
static const uint32_t PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK = 60;
static const uint32_t PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK = 61;
static const uint32_t PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK = 63;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM10_TRACE_CFG = 0x10011826ull;

static const uint32_t PB_PTLSCOM10_TRACE_CFG_0L_SEL = 0;
static const uint32_t PB_PTLSCOM10_TRACE_CFG_0L_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM10_TRACE_CFG_0R_SEL = 8;
static const uint32_t PB_PTLSCOM10_TRACE_CFG_0R_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM10_TRACE_CFG_1L_SEL = 16;
static const uint32_t PB_PTLSCOM10_TRACE_CFG_1L_SEL_LEN = 8;
static const uint32_t PB_PTLSCOM10_TRACE_CFG_1R_SEL = 24;
static const uint32_t PB_PTLSCOM10_TRACE_CFG_1R_SEL_LEN = 8;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM23_MAILBOX_00_REG = 0x11011830ull;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM23_MAILBOX_01_REG = 0x11011831ull;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM23_PTL_FIR_MASK_REG_RW = 0x11011803ull;
static const uint64_t PB_PTLSCOM23_PTL_FIR_MASK_REG_WO_AND = 0x11011804ull;
static const uint64_t PB_PTLSCOM23_PTL_FIR_MASK_REG_WO_OR = 0x11011805ull;

static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK = 0;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK = 1;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK = 2;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK = 3;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK = 4;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK = 5;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK = 6;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK = 7;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK = 8;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK = 9;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK = 10;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK = 11;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK = 12;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_CROB01_ATTN_MASK = 13;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK = 14;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK = 15;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_CROB23_ATTN_MASK = 16;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK = 17;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK = 18;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK = 19;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK = 20;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK = 21;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK = 22;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK = 23;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK = 24;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK = 25;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK = 26;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK = 27;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK = 28;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK = 29;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK = 30;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK = 31;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK = 32;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK = 33;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK = 34;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK = 35;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_PTL0_SPARE_MASK = 36;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_PTL1_SPARE_MASK = 37;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_PTL2_SPARE_MASK = 38;
static const uint32_t PB_PTLSCOM23_PTL_FIR_MASK_REG_PTL3_SPARE_MASK = 39;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM23_RCMD_RATE_CFG = 0x1101180cull;

static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE = 0;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_LEN = 8;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE = 8;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_LEN = 8;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER = 16;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN = 4;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER = 20;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN = 4;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_X_DISABLE_TURBO = 24;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_X_CMD_GAP_CFG = 25;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_X_CMD_GAP_CFG_LEN = 2;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_Y_DISABLE_TURBO = 27;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_Y_CMD_GAP_CFG = 28;
static const uint32_t PB_PTLSCOM23_RCMD_RATE_CFG_Y_CMD_GAP_CFG_LEN = 2;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM45_PMU1_TLPM_COUNTER = 0x1201181cull;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM45_PTL_FIR_ACTION0_REG = 0x12011806ull;

static const uint32_t PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 = 0;
static const uint32_t PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN = 40;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM45_PTL_FIR_ACTION1_REG = 0x12011807ull;

static const uint32_t PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 = 0;
static const uint32_t PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN = 40;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM45_PTL_FIR_WOF_REG = 0x12011808ull;

static const uint32_t PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF = 0;
static const uint32_t PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN = 40;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM45_TL_LINK_DLY_0123_REG = 0x1201180eull;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM67_MAILBOX_20_REG = 0x13011834ull;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM67_MAILBOX_21_REG = 0x13011835ull;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM67_PMU2_CNPM_COUNTER = 0x13011823ull;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM67_PSAVE23_MODE_CFG = 0x13011816ull;

static const uint32_t PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE = 0;
static const uint32_t PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE = 5;
static const uint32_t PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN = 8;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM67_PTL_FIR_REG_RW = 0x13011800ull;
static const uint64_t PB_PTLSCOM67_PTL_FIR_REG_WO_AND = 0x13011801ull;
static const uint64_t PB_PTLSCOM67_PTL_FIR_REG_WO_OR = 0x13011802ull;

static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED = 0;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED = 1;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED = 2;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED = 3;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE = 4;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE = 5;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE = 6;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR = 7;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE = 8;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE = 9;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE = 10;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR = 11;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN = 12;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN = 13;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN = 14;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN = 15;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN = 16;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN = 17;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN = 18;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN = 19;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN = 20;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN = 21;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN = 22;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN = 23;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN = 24;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN = 25;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR = 26;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR = 27;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN = 28;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN = 29;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN = 30;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN = 31;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN = 32;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN = 33;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN = 34;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN = 35;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE = 36;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE = 37;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE = 38;
static const uint32_t PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE = 39;
// proc/reg00022.H

static const uint64_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG = 0x13011811ull;

static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 = 0;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT = 1;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 = 8;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT = 9;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT = 16;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT = 24;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT = 32;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT_LEN = 5;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT = 37;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2 = 38;
static const uint32_t PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2_LEN = 2;
// proc/reg00022.H

static const uint64_t PB_BRIDGE_HCA_CONFIG_REG = 0x03011d4aull;

static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE = 0;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K = 1;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT = 2;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT_LEN = 8;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE = 10;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE_LEN = 2;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD = 24;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD_LEN = 8;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD = 32;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD_LEN = 8;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD = 40;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD_LEN = 8;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE = 49;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE = 50;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE = 51;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE_LEN = 5;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK = 56;
static const uint32_t PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK_LEN = 8;
// proc/reg00022.H

static const uint64_t PB_BRIDGE_HCA_CONTROL_REG = 0x03011d4bull;

static const uint32_t PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE = 0;
static const uint32_t PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE_LEN = 2;
static const uint32_t PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL = 4;
static const uint32_t PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL_LEN = 6;
static const uint32_t PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL = 12;
static const uint32_t PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL_LEN = 4;
static const uint32_t PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT = 63;
// proc/reg00022.H

static const uint64_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG = 0x03011cc8ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO_LEN = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT_LEN = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR = 9;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF = 10;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG = 11;
// proc/reg00022.H

static const uint64_t TP_TCN0_N0_CC_PROTECT_MODE_REG = 0x020303feull;

static const uint32_t TP_TCN0_N0_CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t TP_TCN0_N0_CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// proc/reg00022.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_DATA2 = 0x0205001bull;
// proc/reg00022.H

static const uint64_t TP_TCN0_N0_ERROR_STATUS = 0x0203000full;

static const uint32_t TP_TCN0_N0_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR = 0;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR = 1;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR = 2;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR = 3;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR = 4;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR = 5;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR = 6;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR = 7;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR = 8;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR = 9;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR = 10;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_SCAN_COLLISION_ERR = 11;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR = 12;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_OPCG_TRIGGER_ERR = 13;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR = 14;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR = 15;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR = 16;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR = 17;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR = 18;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR = 19;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR = 20;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR = 21;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_CLKCMD_REQUEST_ERR = 22;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_CBS_PROTOCOL_ERR = 23;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_VITL_ALIGN_ERR = 24;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_UNIT_SYNC_LVL_ERR = 25;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR = 26;
static const uint32_t TP_TCN0_N0_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR = 27;
// proc/reg00022.H

static const uint64_t TP_TCN0_N0_OPCG_CAPT2 = 0x02030011ull;

static const uint32_t TP_TCN0_N0_OPCG_CAPT2_13_01EVEN = 4;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_13_01EVEN_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_14_01ODD = 9;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_14_01ODD_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_15_02EVEN = 14;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_15_02EVEN_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_16_02ODD = 19;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_16_02ODD_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_17_03EVEN = 24;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_17_03EVEN_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_18_03ODD = 29;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_18_03ODD_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_19_04EVEN = 34;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_19_04EVEN_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_20_04ODD = 39;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_20_04ODD_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_21_05EVEN = 44;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_21_05EVEN_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_22_05ODD = 49;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_22_05ODD_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_23_06EVEN = 54;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_23_06EVEN_LEN = 5;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_24_06ODD = 59;
static const uint32_t TP_TCN0_N0_OPCG_CAPT2_24_06ODD_LEN = 5;
// proc/reg00022.H

static const uint64_t TP_TCN0_N0_SCAN_UPDATEDR = 0x0203a000ull;
// proc/reg00022.H

static const uint64_t TP_TCN0_N0_TRA0_TR0_CONFIG_5 = 0x02010408ull;

static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_5_D_LEN = 24;
// proc/reg00022.H

static const uint64_t TP_TCN1_N1_CLK_REGION = 0x03030006ull;

static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_CMD = 0;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_CMD_LEN = 2;
static const uint32_t TP_TCN1_N1_CLK_REGION_SLAVE_MODE = 2;
static const uint32_t TP_TCN1_N1_CLK_REGION_MASTER_MODE = 3;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_PERV = 4;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT1 = 5;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT2 = 6;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT3 = 7;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT4 = 8;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT5 = 9;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT6 = 10;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT7 = 11;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT8 = 12;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT9 = 13;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT10 = 14;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT11 = 15;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT12 = 16;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT13 = 17;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_REGION_UNIT14 = 18;
static const uint32_t TP_TCN1_N1_CLK_REGION_SEL_THOLD_SL = 48;
static const uint32_t TP_TCN1_N1_CLK_REGION_SEL_THOLD_NSL = 49;
static const uint32_t TP_TCN1_N1_CLK_REGION_SEL_THOLD_ARY = 50;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_PULSE_USE_EVEN = 52;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK = 53;
static const uint32_t TP_TCN1_N1_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK = 54;
// proc/reg00022.H

static const uint64_t TP_TCN1_N1_CPLT_CONF0_RW = 0x03000008ull;
static const uint64_t TP_TCN1_N1_CPLT_CONF0_WO_CLEAR = 0x03000028ull;
static const uint64_t TP_TCN1_N1_CPLT_CONF0_WO_OR = 0x03000018ull;

static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC = 0;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN = 6;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_6G = 6;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_7G = 7;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC = 8;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN = 6;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_14G = 14;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_15G = 15;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC = 16;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN = 6;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_22G = 22;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_23G = 23;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC = 24;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN = 6;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_30G = 30;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_31G = 31;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC = 32;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC = 33;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N = 34;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC = 35;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G = 36;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G = 37;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G = 38;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G = 39;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC = 40;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC = 41;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_42G = 42;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_43G = 43;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN = 44;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_RESERVED_45G = 45;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC = 46;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G = 47;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC = 48;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_LEN = 4;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC = 52;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G = 53;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G = 54;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G = 55;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G = 56;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G = 57;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G = 58;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G = 59;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G = 60;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G = 61;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G = 62;
static const uint32_t TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G = 63;
// proc/reg00022.H

static const uint64_t TP_TCN1_N1_CPLT_CTRL0_RW = 0x03000000ull;
static const uint64_t TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR = 0x03000020ull;
static const uint64_t TP_TCN1_N1_CPLT_CTRL0_WO_OR = 0x03000010ull;

static const uint32_t TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC = 0;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC = 1;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH = 2;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN = 3;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC = 4;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC = 8;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A = 11;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC = 13;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC = 14;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC = 15;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A = 18;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A = 19;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC = 20;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN = 8;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A = 33;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A = 34;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A = 35;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A = 38;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A = 39;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC = 40;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN = 2;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A = 42;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A = 43;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC = 46;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC = 47;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A = 48;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A = 49;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A = 50;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A = 51;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A = 52;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A = 53;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A = 54;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A = 55;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A = 56;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A = 57;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A = 58;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A = 59;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A = 60;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A = 61;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A = 62;
static const uint32_t TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A = 63;
// proc/reg00022.H

static const uint64_t TP_TCN1_N1_EPS_FIR_MODE_REG = 0x03040088ull;

static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK = 0;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV = 1;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN = 2;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP = 3;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN = 4;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05 = 5;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR = 6;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07 = 7;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08 = 8;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR = 9;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10 = 10;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11 = 11;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12 = 12;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13 = 13;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14 = 14;
static const uint32_t TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15 = 15;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_OPCG_ALIGN = 0x03030001ull;

static const uint32_t TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN = 0;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN_LEN = 4;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN = 4;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN_LEN = 4;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN = 8;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN_LEN = 4;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT = 12;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT_LEN = 8;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT = 20;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT_LEN = 12;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT = 32;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT_LEN = 8;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG = 40;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG = 41;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG = 42;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD = 43;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT = 44;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN = 2;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO = 47;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO_LEN = 5;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES = 52;
static const uint32_t TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN = 12;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_PHASE_COUNTER_RESET = 0x03030028ull;

static const uint32_t TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_SCAN64CONTSCAN = 0x0303f000ull;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_TRA0_TR1_CONFIG_4 = 0x03010447ull;

static const uint32_t TP_TCN1_N1_TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCN1_N1_TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCN1_N1_TRA0_TR1_CONFIG_4_B_LEN = 24;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_TRA1_TR0_CONFIG_2 = 0x03010485ull;

static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_2_B_LEN = 24;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_TRA2_TR0_CONFIG_5 = 0x03010508ull;

static const uint32_t TP_TCN1_N1_TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCN1_N1_TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCN1_N1_TRA2_TR0_CONFIG_5_D_LEN = 24;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_TRA3_TR1_CONFIG_3 = 0x030105c6ull;

static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_3_D_LEN = 24;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_TRA4_TR1_CONFIG_2 = 0x03010645ull;

static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_2_B_LEN = 24;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_TRA5_TR0_CONFIG_4 = 0x03010687ull;

static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_4_B_LEN = 24;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG = 0x030106c0ull;

static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG = 0x03010701ull;

static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_TRA6_TR0_CONFIG_3 = 0x03010706ull;

static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_3_D_LEN = 24;
// proc/reg00023.H

static const uint64_t TP_TCN1_N1_XSTOP_MASK_RW = 0x03040040ull;
static const uint64_t TP_TCN1_N1_XSTOP_MASK_WO_CLEAR = 0x03040060ull;
static const uint64_t TP_TCN1_N1_XSTOP_MASK_WO_OR = 0x03040050ull;

static const uint32_t TP_TCN1_N1_XSTOP_MASK_01 = 1;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_02 = 2;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_03 = 3;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_04 = 4;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_05 = 5;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_06 = 6;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_07 = 7;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_08 = 8;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_09 = 9;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_10 = 10;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_11 = 11;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_12 = 12;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_13 = 13;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_14 = 14;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_15 = 15;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_16 = 16;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_17 = 17;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_18 = 18;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_19 = 19;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_20 = 20;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_21 = 21;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_22 = 22;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_23 = 23;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_24 = 24;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_25 = 25;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_26 = 26;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_27 = 27;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_28 = 28;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_29 = 29;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_30 = 30;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_31 = 31;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_32 = 32;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_33 = 33;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_34 = 34;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_35 = 35;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_36 = 36;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_37 = 37;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_38 = 38;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_39 = 39;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_40 = 40;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_41 = 41;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_42 = 42;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_43 = 43;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_44 = 44;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_45 = 45;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_46 = 46;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_47 = 47;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_48 = 48;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_49 = 49;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_50 = 50;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_51 = 51;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_52 = 52;
static const uint32_t TP_TCN1_N1_XSTOP_MASK_53 = 53;
// proc/reg00023.H

static const uint64_t TP_TPBR_AD_TOD_DATA_RCV_REG = 0x00090029ull;

static const uint32_t TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV = 0;
static const uint32_t TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV_LEN = 64;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_BCDE_CTL_OCI = 0xc0040080ull;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_CTL_PIB = 0x00068010ull;

static const uint32_t TP_TPBR_PBA_PBAO_BCDE_CTL_OP = 0;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_CTL_ART = 1;
// proc/reg00023.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABAR0 = 0x01010cdaull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR0_ADDR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR0_ADDR_LEN = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR0_VTARGET = 48;
static const uint32_t TP_TPBR_PBA_PBAO_PBABAR0_VTARGET_LEN = 16;
// proc/reg00023.H

static const uint64_t TP_TPBR_PBA_PBAO_PBABARMSK1 = 0x01010cdfull;

static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK_LEN = 21;
// proc/reg00023.H

static const uint64_t TP_TPBR_PBA_PBAO_PBARBUFVAL0 = 0x01010cd0ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR_LEN = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT = 31;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS = 33;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS_LEN = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID = 41;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID_LEN = 3;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI = 0xc00401d0ull;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB = 0x0006803aull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START_LEN = 29;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI = 0xc00401b8ull;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB = 0x00068037ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3 = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR = 13;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE = 31;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHBR1_OCI = 0xc0040150ull;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHBR1_PIB = 0x0006802aull;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI = 0xc0040138ull;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB = 0x00068027ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3 = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR = 13;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE = 31;
// proc/reg00023.H

static const uint64_t TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG = 0x03011c18ull;
// proc/reg00023.H

static const uint64_t TP_TPBR_PSI_WRAP_RX_CH_MISC_REG = 0x03011c1bull;
// proc/reg00023.H

static const uint64_t TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG = 0x03011c08ull;

static const uint32_t TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF = 0;
static const uint32_t TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI = 2;
static const uint32_t TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE = 3;
static const uint32_t TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF = 4;
static const uint32_t TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE = 5;
static const uint32_t TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE = 6;
static const uint32_t TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION = 7;
// proc/reg00023.H

static const uint64_t TP_TPBR_PSI_WRAP_TX_TO_RT_REG = 0x03011c01ull;

static const uint32_t TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE = 0;
static const uint32_t TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE_LEN = 4;
static const uint32_t TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE = 4;
static const uint32_t TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE_LEN = 4;
// proc/reg00023.H

static const uint64_t TP_TPBR_PSIHB_NOTRUST_BAR0MASK = 0x03011f42ull;

static const uint32_t TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK = 14;
static const uint32_t TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK_LEN = 30;
// proc/reg00023.H

static const uint64_t TP_TPBR_PSIHB_NOTRUST_BAR1 = 0x03011f41ull;

static const uint32_t TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1 = 14;
static const uint32_t TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1_LEN = 30;
// proc/reg00023.H

static const uint64_t TP_TPBR_PSIHB_NOTRUST_BAR1MASK = 0x03011f43ull;

static const uint32_t TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK = 14;
static const uint32_t TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK_LEN = 30;
// proc/reg00023.H

static const uint64_t TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG = 0x03011d0aull;

static const uint32_t TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR = 8;
static const uint32_t TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_LEN = 36;
static const uint32_t TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN = 63;
// proc/reg00023.H

static const uint64_t TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG = 0x03011d0bull;

static const uint32_t TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR = 8;
static const uint32_t TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR_LEN = 36;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2 = 0x020f0002ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG = 0x020f001bull;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG = 0x030f0019ull;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG = 0x010f0020ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG = 0x010f0021ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG = 0x010f0022ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG = 0x010f0023ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG = 0x010f0024ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG = 0x010f0025ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG = 0x010f0026ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6 = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 = 6;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2 = 0x010f0002ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW = 0x010f0044ull;
static const uint64_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND = 0x010f0045ull;
static const uint64_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR = 0x010f0046ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS = 1;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS = 2;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS = 4;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS = 5;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS = 7;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS = 8;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS = 9;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS = 10;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS = 11;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS = 12;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS = 13;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS = 14;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS = 15;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC = 16;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC = 17;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC = 18;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC = 19;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC = 20;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC = 21;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC = 22;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC = 23;
// proc/reg00023.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG = 0x010f0019ull;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI = 0xc0000270ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO = 0x0006004eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN = 32;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI = 0xc0000120ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW = 0x00060024ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN = 32;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_OCI = 0xc0000098ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SCOM = 0x00060013ull;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI = 0xc0000138ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO = 0x00060027ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING = 31;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI = 0xc0000130ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO = 0x00060026ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR_LEN = 32;
// proc/reg00023.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISPRG0_OCI = 0xc0000110ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISPRG0_RW = 0x00060022ull;
// proc/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR31_OCI = 0xc0010278ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR31_RO = 0x0006204full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31_LEN = 32;
// proc/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR4_OCI = 0xc0010220ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR4_RO = 0x00062044ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4_LEN = 32;
// proc/reg00024.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCI = 0xc00200a8ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_SCOM = 0x00064015ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN = 30;
// proc/reg00024.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR0_OCI = 0xc0020200ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR0_RO = 0x00064040ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0_LEN = 32;
// proc/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_OCI = 0xc00300b0ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_RO = 0x00066016ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_ADDR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_R_NW = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_BUSY = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_RSP_INFO = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_RSP_INFO_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_RESET_PENDING = 61;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_IFETCH_PENDING = 62;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIB_DATAOP_PENDING = 63;
// proc/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR30_OCI = 0xc0030438ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR30_RO = 0x00066087ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR30_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR30_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR30_1 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR30_1_LEN = 32;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_CCSR_OCI = 0xc0060480ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_CCSR_OCI1 = 0xc0060488ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_CCSR_OCI2 = 0xc0060490ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_CCSR_RW = 0x0006c090ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR = 0x0006c091ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR = 0x0006c092ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG_LEN = 32;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_OCI = 0xc0063938ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_RW = 0x0006c727ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A__CLEAR_STICKY_BITS_1A = 1;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCI = 0xc0063940ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_RW = 0x0006c728ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A_LEN = 32;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_OCI = 0xc0061040ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_RW = 0x0006c208ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR_LEN = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK_LEN = 12;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_OCI = 0xc0061050ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_RO = 0x0006c20aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0_LEN = 5;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI = 0xc0061180ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_RW = 0x0006c230ull;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_OCI = 0xc0061108ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SCOM = 0x0006c221ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE = 31;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCI = 0xc0060530ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCI1 = 0xc0060538ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCI2 = 0xc0060540ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW = 0x0006c0a6ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR = 0x0006c0a7ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR = 0x0006c0a8ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2_LEN = 32;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q0RR_OCI = 0xc0062800ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q0RR_RO = 0x0006c500ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q0RR_OCB_OCI_OPIT0Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q0RR_OCB_OCI_OPIT0Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCI = 0xc0062840ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_RO = 0x0006c508ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q3_OCI = 0xc0062058ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q3_RO = 0x0006c40bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q3_OCB_OCI_OPIT1Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q3_OCB_OCI_OPIT1Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q0RR_OCI = 0xc0062880ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q0RR_RO = 0x0006c510ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q0RR_OCB_OCI_OPIT2Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q0RR_OCB_OCI_OPIT2Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q7_OCI = 0xc00620b8ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q7_RO = 0x0006c417ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q7_OCB_OCI_OPIT2Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q7_OCB_OCI_OPIT2Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q0RR_OCI = 0xc00628c0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q0RR_RO = 0x0006c518ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q0RR_OCB_OCI_OPIT3Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q0RR_OCB_OCI_OPIT3Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q0RR_OCI = 0xc0062900ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q0RR_RO = 0x0006c520ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q0RR_OCB_OCI_OPIT4Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q0RR_OCB_OCI_OPIT4Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q0RR_OCI = 0xc0062940ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q0RR_RO = 0x0006c528ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q0RR_OCB_OCI_OPIT5Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q0RR_OCB_OCI_OPIT5Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1_OCI = 0xc0062148ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1_RO = 0x0006c429ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0RR_OCI = 0xc0062980ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0RR_RO = 0x0006c530ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0RR_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0RR_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q5_OCI = 0xc00621a8ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q5_RO = 0x0006c435ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q5_OCB_OCI_OPIT6Q5RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q5_OCB_OCI_OPIT6Q5RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q0RR_OCI = 0xc00629c0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q0RR_RO = 0x0006c538ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q0RR_OCB_OCI_OPIT7Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q0RR_OCB_OCI_OPIT7Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C1_OCI = 0xc0062208ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C1_RO = 0x0006c441ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C1_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C1_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C1_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C1_PAYLOAD_LEN = 17;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18_OCI = 0xc0062290ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18_RO = 0x0006c452ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18_PAYLOAD_LEN = 17;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18RR_OCI = 0xc0062a90ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18RR_RO = 0x0006c552ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C18RR_PAYLOAD_LEN = 17;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30_OCI = 0xc00622f0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30_RO = 0x0006c45eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30_PAYLOAD_LEN = 17;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7RR_OCI = 0xc0062a38ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7RR_RO = 0x0006c547ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7RR_PAYLOAD_LEN = 17;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29_OCI = 0xc00623e8ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29_RO = 0x0006c47dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C29_PAYLOAD_LEN = 17;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C7RR_OCI = 0xc0062b38ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C7RR_RO = 0x0006c567ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C7RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C7RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C7RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C7RR_PAYLOAD_LEN = 17;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_OCI = 0xc0062c18ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_RO = 0x0006c583ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV3RR_7_LEN = 4;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_OCI = 0xc0062c28ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_RO = 0x0006c585ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV1RR_7_LEN = 4;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_OCI = 0xc0062438ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_RO = 0x0006c487ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV3_7_LEN = 4;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_OCI = 0xc00624a0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_RO = 0x0006c494ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFSV_7_LEN = 4;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICECC_OCI = 0xc0063c38ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICECC_RW = 0x0006c787ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICECC_INJECT_ECC_ERR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICECC_CONTINUOUS_INJECT = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICECC_INJECT_TYPE = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICECC_INJECT_DATA_OR_ECC = 3;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO = 0x0006d051ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR = 0x0006d052ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR = 0x0006d053ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1 = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_FSM_ERR = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2 = 15;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3 = 0x0006d075ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA_LEN = 64;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0 = 0x0006d014ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR_LEN = 32;
// proc/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV0_OCI = 0xc0050020ull;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV0_RW = 0x0006a004ull;

static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0 = 0;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0_LEN = 32;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG109 = 0x0000806dull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG109_REGISTER109 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG109_REGISTER109_LEN = 64;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG116 = 0x00008074ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG116_REGISTER116 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG116_REGISTER116_LEN = 64;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG121 = 0x00008079ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG121_REGISTER121 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG121_REGISTER121_LEN = 64;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG16 = 0x00008010ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG16_REGISTER16 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG16_REGISTER16_LEN = 64;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG2 = 0x00008002ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG2_REGISTER2 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG2_REGISTER2_LEN = 64;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG21 = 0x00008015ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG21_REGISTER21 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG21_REGISTER21_LEN = 64;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG40 = 0x00008028ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG40_REGISTER40 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG40_REGISTER40_LEN = 64;
// proc/reg00024.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG68 = 0x00008044ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG68_REGISTER68 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG68_REGISTER68_LEN = 64;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG77 = 0x0000804dull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG77_REGISTER77 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG77_REGISTER77_LEN = 64;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG82 = 0x00008052ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG82_REGISTER82 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG82_REGISTER82_LEN = 64;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG = 0x01010003ull;

static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT = 17;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID = 35;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN = 4;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_TPC_ITR_FMU_KVREF_DATAREG = 0x01020004ull;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_TPC_ITR_FMU_KVREF_TUNE_DATA = 0x01020005ull;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_TPC_LOCAL_XSTOP_UNMASKED = 0x01040013ull;

static const uint32_t TP_TPCHIP_TPC_LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN = 1;
static const uint32_t TP_TPCHIP_TPC_LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN_LEN = 15;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_2 = 0x01010445ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_2_B_LEN = 24;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_TPC_XSTOP2 = 0x0103000dull;

static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_MASK_B = 0;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_ALIGNED_XSTOP2 = 1;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_TRIGGER_OPCG_ON_XSTOP2 = 2;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_WAIT_ALLWAYS = 3;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_PERV = 4;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT1 = 5;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT2 = 6;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT3 = 7;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT4 = 8;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT5 = 9;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT6 = 10;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT7 = 11;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT8 = 12;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT9 = 13;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT10 = 14;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT11 = 15;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT12 = 16;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT13 = 17;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_UNIT14 = 18;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_WAIT_CYCLES = 48;
static const uint32_t TP_TPCHIP_TPC_XSTOP2_XSTOP2_WAIT_CYCLES_LEN = 12;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD2_FSI = 0x00001402ull;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD2_FSI_BYTE = 0x00001408ull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD2_FSI_SCRATCH_PAD2 = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_FSISCRPD2_FSI_SCRATCH_PAD2_LEN = 32;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_HIST_FSI = 0x00002805ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_HIST_FSI_BYTE = 0x00002814ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_HIST_SCOM = 0x00050005ull;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI = 0x00002849ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE = 0x00002924ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW = 0x00050049ull;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI = 0x00002883ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE = 0x00002a0cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RW = 0x00050083ull;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI = 0x000028c5ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE = 0x00002b14ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW = 0x000500c5ull;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_13_FSI = 0x0000290dull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_13_FSI_BYTE = 0x00002c34ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_13_RW = 0x0005010dull;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_B_FSI = 0x00002826ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_B_FSI_BYTE = 0x00002898ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_B_RO = 0x00050026ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_B_M1HC1B_MAILBOX_1_HEADER_COMMAND_B = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_B_M1HC1B_MAILBOX_1_HEADER_COMMAND_B_LEN =
    32;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_A_FSI = 0x0000282aull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_A_FSI_BYTE = 0x000028a8ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_A_RW = 0x0005002aull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_A_M2HC1A_MAILBOX_2_HEADER_COMMAND_1_A =
    0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_1_A_M2HC1A_MAILBOX_2_HEADER_COMMAND_1_A_LEN
    = 32;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_FSI = 0x00002831ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_FSI_BYTE = 0x000028c4ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_RO = 0x00050031ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1
    = 4;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1 = 5;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1 = 6;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_LBUS_SLAVE_B_RAM_PARITY_ERROR_DETECTED_1 = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_ADDRESS_OF_LBUS_PARITY_ERROR_1
    = 8;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_ADDRESS_OF_LBUS_PARITY_ERROR_1_LEN = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1 = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2
    = 20;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2 = 21;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2 = 22;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_LBUS_SLAVE_B_RAM_PARITY_ERROR_DETECTED_2 = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_ADDRESS_OF_LBUS_PARITY_ERROR_2
    = 24;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_ADDRESS_OF_LBUS_PARITY_ERROR_2_LEN = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2 = 31;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_FSI = 0x0000281aull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE = 0x00002868ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_RW = 0x0005001aull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_CHIPLET_EN_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_PCB_EP_RESET_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_RESERVED = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_4_RESERVED = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_5_RESERVED = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_6_RESERVED = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_SCIN_DC = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FLUSH_ALIGN_OVERWRITE = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_RESERVED = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_EDIS_DC = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_MPW1_DC_N = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_MPW2_DC_N = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_MPW3_DC_N = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_DELAY_LCLKR_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_RI_DC_N = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_DI1_DC_N = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_DI2_DC_N = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_22_RESERVED = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_24_RESERVED = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_RESERVED = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_TP_ARRAY_WRITE_ASSIST_EN_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_28_RESERVED = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_30_RESERVED = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE = 31;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI = 0x0000291bull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE = 0x00002c6cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW = 0x0005011bull;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI = 0x00002810ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE = 0x00002840ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_RW = 0x00050010ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_0_SPARE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TP_FENCE_VTLIO_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW1_FENCE_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW1_FENCE_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_8_SPARE = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_9_SPARE = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_10_SPARE = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_TP_IO_OCMB_RESET_B_EN = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC = 31;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI = 0x00002920ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI_BYTE = 0x00002c80ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_WO_OR = 0x00050120ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_0_SPARE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TPFSI_TP_FENCE_VTLIO_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TPFSI_TPI2C_BUS_FENCE_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TPCFSI_OPB_SW0_FENCE_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TPCFSI_OPB_SW0_FENCE_DC_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TPCFSI_OPB_SW1_FENCE_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TPCFSI_OPB_SW1_FENCE_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_8_SPARE = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_9_SPARE = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_10_SPARE = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_11_SPARE = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_12_SPARE = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_13_SPARE = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_SPARE_FENCE_CONTROL = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_VDD2VIO_LVL_FENCE_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI2PCB_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_OOB_MUX = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_PIB2PCB_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_PCB2PCB_DC = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI_CC_VSB_CBS_REQ = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI_CC_VSB_CBS_CMD = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI_CC_VSB_CBS_CMD_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_24_SPARE_CBS_CONTROL = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_25_SPARE_CBS_CONTROL = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_26_SPARE_CBS_CONTROL = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_27_SPARE_CBS_CONTROL = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_28_SPARE_RESET = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TP_IO_OCMB_RESET_B_EN = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_PCB_RESET_DC = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_SET_GLOBAL_EP_RESET_DC = 31;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_FSI = 0x00002921ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_FSI_BYTE = 0x00002c84ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_WO_OR = 0x00050121ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE0_SEL_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE0_SEL_DC_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE1_SEL_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE1_SEL_DC_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE_MESH_SEL_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE_DRV_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE_HIGHDRIVE_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_FSI_PROBE_SEL_DC = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_FSI_PROBE_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_AN_PROBE_DRVR_MCPRECOMP0_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_AN_PROBE_DRVR_MCPRECOMP1_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_AN_PROBE_DRVR_MCPRECOMP2_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_IDDQ_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_SPARE_RI_CONTROL = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_SPARE_DI_CONTROL = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_RI_DC_B = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_DI1_DC_B = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_DI2_DC_B = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_22_SPARE_TEST = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_23_SPARE_TEST = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_TEST_BURNIN_MODE_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TPFSI_ARRAY_SET_VBL_TO_VDD_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_26_SPARE = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_GLBCK_MEM_TESTCLK_SEL_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_28_SPARE_TEST_CONTROL = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_29_SPARE_TEST_CONTROL = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_30_SPARE_TEST_CONTROL = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_31_SPARE_TEST_CONTROL = 31;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_FSI = 0x00002922ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_FSI_BYTE = 0x00002c88ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_WO_OR = 0x00050122ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_0_SPARE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_3_SPARE = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_PIB_DISABLE_PARITY_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_PIB_TRACE_MODE_DATA_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_PIB_VSB_SBE_TRACE_MODE = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_TPCPERV_VSB_TRACE_STOP = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_GPIO_PIB_TIMEOUT = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_GPIO_PIB_TIMEOUT_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_SPARE_PIB_CONTROL = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TPCFSI_OPB_SW_RESET_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_13_SPARE_OPB_CONTROL = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_14_SPARE_OPB_CONTROL = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_15_SPARE_OPB_CONTROL = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_16_SPARE = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_VREGDLY_SHUTOFF_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_18_SPARE = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_19_SPARE = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_20_SPARE = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_21_FREE_USAGE = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_22_FREE_USAGE = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_23_FREE_USAGE = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_IO_VSB_OP0A_V1P8_EN = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_IO_VSB_OP0B_V1P8_EN = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_26_FREE_USAGE = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_27_FREE_USAGE = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_28_FREE_USAGE = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_ROOT_CTRL2_29_FREE_USAGE = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_IO_VSB_OP3A_V1P8_EN = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SET_TP_IO_VSB_OP3B_V1P8_EN = 31;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_FSI = 0x00002923ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_FSI_BYTE = 0x00002c8cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_WO_OR = 0x00050123ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW1_RESET_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW1_BYPASS_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW1_TEST_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_ROOT_CTRL3_3_SPARE_SS_PLL_CONTROL = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW2_RESET_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW2_BYPASS_EN_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW2_TEST_EN_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_SPARE_FILT0_PLL = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT0_PLL_RESET_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT0_PLL_BYPASS_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT0_PLL_TEST_EN_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_SPARE_FILT1_PLL = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT1_PLL_RESET_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT1_PLL_BYPASS_EN_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT1_PLL_TEST_EN_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_ROOT_CTRL3_15_SPARE_PLL = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT2_PLL_RESET_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT2_PLL_BYPASS_EN_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT2_PLL_TEST_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_ROOT_CTRL3_19_SPARE = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT3_PLL_RESET_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT3_PLL_BYPASS_EN_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_FILT3_PLL_TEST_EN_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_ROOT_CTRL3_23_SPARE_PLL_CONTROL = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PAU_DPLL_RESET_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PAU_DPLL_BYPASS_EN_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PAU_DPLL_TEST_EN_DC = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PAU_DPLL_FUNC_CLKSEL_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_NEST_DPLL_RESET_DC = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_NEST_DPLL_BYPASS_EN_DC = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_NEST_DPLL_TEST_EN_DC = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_NEST_DPLL_FUNC_CLKSEL_DC = 31;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_FSI = 0x00002924ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_FSI_BYTE = 0x00002c90ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_WO_OR = 0x00050124ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_5_SPARE = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_13_SPARE = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_TOD_LPC_MUX_SEL_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_17_SPARE = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_18_SPARE = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_19_SPARE = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_MUX1_CLKIN_SEL_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_MUX2A_CLKIN_SEL_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_MUX2B_CLKIN_SEL_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_MUX3_CLKIN_SEL_DC = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_MUX4A_CLKIN_SEL_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_26_SPARE = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TPFSI_ALTREFCLK_SEL = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_28_SPARE = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_PLL_FORCE_OUT_EN_DC = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_30_SPARE = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_31_SPARE = 31;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_FSI = 0x00002925ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_FSI_BYTE = 0x00002c94ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_WO_OR = 0x00050125ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_RESET_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_BYPASS_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_FORCE_BYPASS_CLKSEL_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_CLK_TEST_IN_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_CONTROL_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SET_CONTROL_DC_LEN = 28;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_FSI = 0x00002926ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_FSI_BYTE = 0x00002c98ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_WO_OR = 0x00050126ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_TP_PLLREFCLK_RCVR_TERM_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_TP_PLLREFCLK_RCVR_TERM_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_TP_PCIREFCLK_RCVR_TERM_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_TP_PCIREFCLK_RCVR_TERM_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_ROOT_CTRL6_4 = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_ROOT_CTRL6_5 = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_ROOT_CTRL6_6_31 = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_SET_ROOT_CTRL6_6_31_LEN = 26;
// proc/reg00025.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_FSI = 0x00002927ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_FSI_BYTE = 0x00002c9cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_WO_OR = 0x00050127ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM0_REFCLK_DRVR_EN_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM1_REFCLK_DRVR_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM2_REFCLK_DRVR_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM3_REFCLK_DRVR_EN_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM4_REFCLK_DRVR_EN_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM5_REFCLK_DRVR_EN_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM6_REFCLK_DRVR_EN_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM7_REFCLK_DRVR_EN_DC = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM8_REFCLK_DRVR_EN_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM9_REFCLK_DRVR_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMA_REFCLK_DRVR_EN_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMB_REFCLK_DRVR_EN_DC = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMC_REFCLK_DRVR_EN_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMD_REFCLK_DRVR_EN_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEME_REFCLK_DRVR_EN_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMF_REFCLK_DRVR_EN_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP0A_REFCLK_DRVR_EN_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP0B_REFCLK_DRVR_EN_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP3A_REFCLK_DRVR_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP3B_REFCLK_DRVR_EN_DC = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP4_REFCLK_DRVR_EN_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP5_REFCLK_DRVR_EN_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP6_REFCLK_DRVR_EN_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP7_REFCLK_DRVR_EN_DC = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL
    = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL
    = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL
    = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL
    = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL
    = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL
    = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL
    = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL
    = 31;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_ACK_EOT_FSI = 0x00002435ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_ACK_EOT_FSI_BYTE = 0x000024d4ull;
// proc/reg00025.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_REQ_RESET = 0x000b0033ull;
// proc/reg00025.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_SIG_EOT = 0x000b0032ull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_FSI = 0x00002401ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_FSI_BYTE = 0x00002404ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_RO = 0x000b0001ull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_REQ_RESET_FR_SP = 6;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_REQ_RESET_FR_SBE = 7;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_DEQUEUED_EOT_FLAG = 8;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_FIFO_FULL = 10;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_FIFO_EMPTY = 11;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_FIFO_ENTRY_COUNT = 12;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_FIFO_ENTRY_COUNT_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_FIFO_VALID_FLAGS = 16;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_FIFO_VALID_FLAGS_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_FIFO_EOT_FLAGS = 24;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_STATUS_FIFO_EOT_FLAGS_LEN = 8;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_CHIP_ID_FSI = 0x00000c09ull;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_CHIP_ID_FSI_BYTE = 0x00000c24ull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_STATUS_FSI = 0x00000c07ull;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_STATUS_FSI_BYTE = 0x00000c1cull;
// proc/reg00025.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_LSTAT = 0x00020002ull;
// proc/reg00025.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_RSIC = 0x00020018ull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP5_FSI0 = 0x00003064ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP5_SCOMFSI0 = 0x00000c19ull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MREFP1_FSI0 = 0x00003024ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MREFP1_RO = 0x00000c09ull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP4_FSI0 = 0x000030e0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP4_RO = 0x00000c38ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP4_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP4_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP4_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP4_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP4_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP4_2_LEN = 3;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESB0_FSI0 = 0x000035d0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESB0_WO = 0x00000d74ull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP7_FSI0 = 0x000034ecull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP7_WO = 0x00000d3bull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP7_GENERAL_RESET_7 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP7_ERROR_RESET_7 = 1;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSENP0_FSI0 = 0x00003418ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSENP0_WO_OR = 0x00000d06ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSENP0_0_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSENP0_1_ENABLE = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSENP0_2_ENABLE = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSENP0_3_ENABLE = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSENP0_4_ENABLE = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSENP0_5_ENABLE = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSENP0_6_ENABLE = 6;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSENP0_7_ENABLE = 7;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP4_FSI0 = 0x00003440ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP4_SCOMFSI0 = 0x00000d10ull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SOMR = 0x00000848ull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP1_FSI1 = 0x000030d4ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP1_WO = 0x00000c35ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP1_GENERAL_RESET_1 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP1_ERROR_RESET_1 = 1;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP2_FSI1 = 0x00003038ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP2_SCOMFSI1 = 0x00000c0eull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSSIEP0_FSI1 = 0x00003050ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSSIEP0_SCOMFSI1 = 0x00000c14ull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCI1M = 0x00000820ull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCI2CM = 0x0000082cull;
// proc/reg00025.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCRSIS0 = 0x00000860ull;
// proc/reg00026.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SI1S = 0x0000081cull;
// proc/reg00026.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SI2M = 0x00000824ull;
// proc/reg00026.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE = 0x00000800ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE_WARM_START_COMPLETED = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE_ENABLE_HW_ERROR_RECOVERY = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE_OWN_ID_THIS_FSI_SLAVE = 6;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE_OWN_ID_THIS_FSI_SLAVE_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE_ECHO_DELAY_CYCLES = 8;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE_ECHO_DELAY_CYCLES_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE_SEND_DELAY_CYCLES = 12;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE_SEND_DELAY_CYCLES_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE_LBUS_CLOCK_DIVIDER = 20;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMODE_LBUS_CLOCK_DIVIDER_LEN = 4;
// proc/reg00026.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SRSIC4 = 0x0000086cull;
// proc/reg00026.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SSMBL = 0x0000083cull;
// proc/reg00026.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_ERROR_INJECT_ = 0x00070020ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_ERROR_INJECT__ERROR_REG_Q = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_ERROR_INJECT__ERROR_REG_Q_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CONFIG1 = 0x00070042ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CONFIG1_CONFIG1_Q = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CONFIG1_CONFIG1_Q_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_MEMORY_MAPPING = 0x00070064ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_MEMORY_MAPPING_BASE = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_MEMORY_MAPPING_BASE_LEN = 16;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_MEMORY_MAPPING_MASK = 16;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_MEMORY_MAPPING_MASK_LEN = 16;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_MEMORY_MAPPING_RESERVED = 32;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_MEMORY_MAPPING_RESERVED_LEN = 32;
// proc/reg00026.H

static const uint64_t VAS_VA_EG_SCF_DBGSOUTH = 0x0201144cull;

static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_PASS_WC_INT_TRACE_DATA_LO = 0;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_PASS_WC_INT_TRACE_DATA_HI = 1;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_PASS_CQ_INT_TRACE_DATA_LO = 2;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_PASS_CQ_INT_TRACE_DATA_HI = 3;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_PASS_WC_INT_TRACE_TRIG_01 = 4;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_PASS_WC_INT_TRACE_TRIG_23 = 5;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_PASS_CQ_INT_TRACE_TRIG_01 = 6;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_PASS_CQ_INT_TRACE_TRIG_23 = 7;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_GROUP_SEL_LO = 8;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_GROUP_SEL_LO_LEN = 4;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_GROUP_SEL_HI = 12;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_GROUP_SEL_HI_LEN = 4;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_TRIGGER_SEL_01 = 16;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_TRIGGER_SEL_01_LEN = 2;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_TRIGGER_SEL_23 = 18;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_TRIGGER_SEL_23_LEN = 2;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_GROUP_SEL_LO = 20;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_GROUP_SEL_LO_LEN = 3;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_GROUP_SEL_HI = 23;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_GROUP_SEL_HI_LEN = 3;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_TRIGGER_SEL_01 = 26;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_TRIGGER_SEL_01_LEN = 3;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_TRIGGER_SEL_23 = 29;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_TRIGGER_SEL_23_LEN = 3;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_GROUP_SEL_LO = 32;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_GROUP_SEL_LO_LEN = 3;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_GROUP_SEL_HI = 35;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_GROUP_SEL_HI_LEN = 3;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_TRIGGER_SEL_01 = 38;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_TRIGGER_SEL_01_LEN = 3;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_TRIGGER_SEL_23 = 41;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_TRIGGER_SEL_23_LEN = 3;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_ENABLE_EG_TRACE = 44;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_ENABLE_WC_TRACE = 45;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_ENABLE_CQ_TRACE = 46;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_INT_DATA_LO = 47;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_INT_DATA_HI = 48;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_INT_DATA_LO = 49;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_PASS_CQ_INT_PMU_DATA_LO = 50;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_PASS_CQ_INT_PMU_DATA_HI = 51;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_ENABLE_EG_PMU_COUNTING = 52;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_INT_DATA_HI = 53;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_ENABLE_CQ_PMU_COUNTING = 54;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_INT_DATA_LO = 55;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_INT_DATA_HI = 56;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_INT_TRIG_01 = 57;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_WC_TRACE_INT_TRIG_23 = 58;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_INT_TRIG_01 = 59;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_EG_TRACE_INT_TRIG_23 = 60;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_INT_TRIG_01 = 61;
static const uint32_t VAS_VA_EG_SCF_DBGSOUTH_CQ_TRACE_INT_TRIG_23 = 62;
// proc/reg00026.H

static const uint64_t VAS_VA_EG_SCF_SOUTHCTL = 0x0201144full;

static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_DISABLE_WC_SCRUB = 0;
static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_DISABLE_WC_ECC = 1;
static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_EG_SINGLE_THREAD = 2;
static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_EG_WM_CTX_UPDATE_MODE = 3;
static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_EG_STAMP_DEBUG = 4;
static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_EN_FAST_SCRUB = 5;
static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_DIS_SIMULT_RD_WR = 6;
static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_ENA_NOTIFY_ORDER = 7;
static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_WC_IDLE_BIT = 8;
static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_CQ_IDLE_BIT = 9;
static const uint32_t VAS_VA_EG_SCF_SOUTHCTL_EG_IDLE_BIT = 10;
// proc/reg00026.H

static const uint64_t VAS_VA_RG_SCF_ERRINJNO = 0x02011432ull;

static const uint32_t VAS_VA_RG_SCF_ERRINJNO_ENA = 0;
static const uint32_t VAS_VA_RG_SCF_ERRINJNO_TYP = 1;
static const uint32_t VAS_VA_RG_SCF_ERRINJNO_FRQ = 2;
// proc/reg00026.H

static const uint64_t VAS_VA_RG_SCF_MMIOECC = 0x02011431ull;

static const uint32_t VAS_VA_RG_SCF_MMIOECC_MMIO_ECC = 0;
static const uint32_t VAS_VA_RG_SCF_MMIOECC_MMIO_ECC_LEN = 8;
// proc/reg00026.H

static const uint64_t VAS_VA_RG_SCF_RMABARM = 0x0201140full;

static const uint32_t VAS_VA_RG_SCF_RMABARM_RMA_BAR_MASK = 8;
static const uint32_t VAS_VA_RG_SCF_RMABARM_RMA_BAR_MASK_LEN = 44;
// proc/reg00026.H

static const uint64_t VAS_VA_RG_SCF_WRMON2CMP = 0x02011422ull;
// proc/reg00026.H

static const uint64_t VAS_VA_RG_SCF_WRMON3WID = 0x0201141bull;
// proc/reg00026.H

static const uint64_t VAS_VA_RG_SCF_WRMON6BAR = 0x02011416ull;
// proc/reg00026.H

}
}
#include "proc/reg00022.H"
#include "proc/reg00023.H"
#include "proc/reg00024.H"
#include "proc/reg00025.H"
#include "proc/reg00026.H"
#endif
