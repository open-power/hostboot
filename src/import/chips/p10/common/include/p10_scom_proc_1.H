/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_1.H $       */
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

#ifndef __p10_scom_proc_1_H_
#define __p10_scom_proc_1_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_ERR_RPT_HOLD = 0x02010839ull;

static const uint32_t INT_CQ_ERR_RPT_HOLD_INT_CQ_ERR_RPT_HOLD_0_42 = 0;
static const uint32_t INT_CQ_ERR_RPT_HOLD_INT_CQ_ERR_RPT_HOLD_0_42_LEN = 43;
// proc/reg00004.H

static const uint64_t INT_CQ_ESB_BAR = 0x0201080aull;

static const uint32_t INT_CQ_ESB_BAR_VALID = 0;
static const uint32_t INT_CQ_ESB_BAR_PAGE_SIZE_64K = 1;
static const uint32_t INT_CQ_ESB_BAR_ADDR_8_39 = 8;
static const uint32_t INT_CQ_ESB_BAR_ADDR_8_39_LEN = 32;
static const uint32_t INT_CQ_ESB_BAR_SET_DIV_SEL_0_2 = 56;
static const uint32_t INT_CQ_ESB_BAR_SET_DIV_SEL_0_2_LEN = 3;
static const uint32_t INT_CQ_ESB_BAR_RANGE_0_4 = 59;
static const uint32_t INT_CQ_ESB_BAR_RANGE_0_4_LEN = 5;
// proc/reg00004.H

static const uint64_t INT_CQ_PMC_7 = 0x0201082full;

static const uint32_t INT_CQ_PMC_7_INT_CQ_PMC_7_COUNT_0_47 = 16;
static const uint32_t INT_CQ_PMC_7_INT_CQ_PMC_7_COUNT_0_47_LEN = 48;
// proc/reg00004.H

static const uint64_t INT_PC_NXC_REGS_PROC_CONFIG = 0x02010a8aull;

static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_CACHE_WATCH_ASSIGN = 0;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_CACHE_WATCH_ASSIGN_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_RESERVED_4_7 = 4;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_RESERVED_4_7_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_ESC_REENABLE_PRIO_DIS = 8;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_ESC_REENABLE_PRIO_DIS_LEN = 8;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_PULL_FIRST_GRPSCAN_ENA = 16;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_LSMFB_SCAN_ALL_PRIO_ENA = 17;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_RESERVED_18_20 = 18;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_RESERVED_18_20_LEN = 3;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_TARGET_VC_QUEUE_REDIST = 21;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_TARGET_VC_QUEUE_REDIST_LEN = 3;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_RESERVED_24 = 24;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_TARGET_VC_QUEUE_ESC = 25;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_TARGET_VC_QUEUE_ESC_LEN = 3;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_LOW_POWER_INTR_MODE = 28;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_RESERVED_29_31 = 29;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_RESERVED_29_31_LEN = 3;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_CFG_NVG_TABLE_COMPRESS = 32;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_CFG_NVG_TABLE_COMPRESS_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_CFG_NVC_TABLE_COMPRESS = 36;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_CFG_NVC_TABLE_COMPRESS_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_RESERVED_40_47 = 40;
static const uint32_t INT_PC_NXC_REGS_PROC_CONFIG_RESERVED_40_47_LEN = 8;
// proc/reg00004.H

static const uint64_t INT_PC_NXC_REGS_WATCH2_DATA3 = 0x02010ab7ull;
// proc/reg00004.H

static const uint64_t INT_PC_REGS_DBG_TRACE = 0x02010a33ull;

static const uint32_t INT_PC_REGS_DBG_TRACE_0 = 0;
static const uint32_t INT_PC_REGS_DBG_TRACE_1 = 1;
// proc/reg00004.H

static const uint64_t INT_PC_REGS_ERR0_RECOV = 0x02010ac5ull;

static const uint32_t INT_PC_REGS_ERR0_RECOV_INT_PC_ERR0_RECOV_ERROR = 0;
static const uint32_t INT_PC_REGS_ERR0_RECOV_INT_PC_ERR0_RECOV_ERROR_LEN = 64;
// proc/reg00004.H

static const uint64_t INT_PC_REGS_ERR1_FATAL = 0x02010accull;

static const uint32_t INT_PC_REGS_ERR1_FATAL_INT_PC_ERR1_FATAL_ERROR = 0;
static const uint32_t INT_PC_REGS_ERR1_FATAL_INT_PC_ERR1_FATAL_ERROR_LEN = 64;
// proc/reg00004.H

static const uint64_t INT_PC_REGS_NRQ_NXC_CRD = 0x02010a1eull;

static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_NCKO_LD_RSVD = 0;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_NCKO_LD_RSVD_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_NCKO_LD_LMIT = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_NCKO_LD_LMIT_LEN = 6;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_CHKO_LD_RSVD = 9;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_CHKO_LD_RSVD_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_CHKO_LD_LMIT = 12;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_CHKO_LD_LMIT_LEN = 6;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_NCKI_ST_RSVD = 18;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_NCKI_ST_RSVD_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_NCKI_ST_LMIT = 21;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_NCKI_ST_LMIT_LEN = 6;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_CHKI_ST_RSVD = 27;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_CHKI_ST_RSVD_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_CHKI_ST_LMIT = 30;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_LCL_CHKI_ST_LMIT_LEN = 6;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_RMT_NCKI_ST_RSVD = 36;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_RMT_NCKI_ST_RSVD_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_RMT_NCKI_ST_LMIT = 39;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_RMT_NCKI_ST_LMIT_LEN = 6;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_RMT_CHKI_ST_RSVD = 45;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_RMT_CHKI_ST_RSVD_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_RMT_CHKI_ST_LMIT = 48;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_RMT_CHKI_ST_LMIT_LEN = 6;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_RESERVED_54_57 = 54;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_RESERVED_54_57_LEN = 4;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_MAX = 58;
static const uint32_t INT_PC_REGS_NRQ_NXC_CRD_CFG_NRQ_NXC_CRD_MAX_LEN = 6;
// proc/reg00004.H

static const uint64_t INT_PC_REGS_TCTXT_EN0 = 0x02010b00ull;

static const uint32_t INT_PC_REGS_TCTXT_EN0_0_EN = 0;
static const uint32_t INT_PC_REGS_TCTXT_EN0_0_EN_LEN = 8;
static const uint32_t INT_PC_REGS_TCTXT_EN0_1_EN = 8;
static const uint32_t INT_PC_REGS_TCTXT_EN0_1_EN_LEN = 8;
static const uint32_t INT_PC_REGS_TCTXT_EN0_2_EN = 16;
static const uint32_t INT_PC_REGS_TCTXT_EN0_2_EN_LEN = 8;
static const uint32_t INT_PC_REGS_TCTXT_EN0_3_EN = 24;
static const uint32_t INT_PC_REGS_TCTXT_EN0_3_EN_LEN = 8;
static const uint32_t INT_PC_REGS_TCTXT_EN0_4_EN = 32;
static const uint32_t INT_PC_REGS_TCTXT_EN0_4_EN_LEN = 8;
static const uint32_t INT_PC_REGS_TCTXT_EN0_5_EN = 40;
static const uint32_t INT_PC_REGS_TCTXT_EN0_5_EN_LEN = 8;
static const uint32_t INT_PC_REGS_TCTXT_EN0_6_EN = 48;
static const uint32_t INT_PC_REGS_TCTXT_EN0_6_EN_LEN = 8;
static const uint32_t INT_PC_REGS_TCTXT_EN0_7_EN = 56;
static const uint32_t INT_PC_REGS_TCTXT_EN0_7_EN_LEN = 8;
// proc/reg00004.H

static const uint64_t INT_PC_REGS_TCTXT_EN1_RESET = 0x02010b07ull;
// proc/reg00004.H

static const uint64_t INT_VC_AIB_TX_ORDERING_TAG = 0x02010916ull;

static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ERQ_ORDERING_TAG = 16;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ERQ_ORDERING_TAG_LEN = 2;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_18 = 18;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_EASC_ORDERING_TAG = 19;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_EASC_ORDERING_TAG_LEN = 5;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ESBC_DMA_ORDERING_TAG = 24;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_25_26 = 25;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_25_26_LEN = 2;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ESBC_EOI_ORDERING_TAG = 27;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ESBC_EOI_ORDERING_TAG_LEN = 5;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_32_34 = 32;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_32_34_LEN = 3;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RELAXED_TRIG_FWD = 35;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_NO_ORDERING_DMA = 36;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_DISABLE_IDX_IN_AIBTAG = 37;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ENDC_EOI_INT_EQP_ORDERING_TAG = 38;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ENDC_DMA_ORDERING_TAG = 39;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_40_41 = 40;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_40_41_LEN = 2;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ENDC_EOI_ESE_ORDERING_TAG = 42;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ENDC_EOI_ESE_ORDERING_TAG_LEN = 6;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_48_52 = 48;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_48_52_LEN = 5;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ENDC_CISTORE_ORDERING_TAG = 53;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ENDC_CISTORE_ORDERING_TAG_LEN = 3;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_56_58 = 56;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_RESERVED_56_58_LEN = 3;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ENDC_CILOAD_ORDERING_TAG = 59;
static const uint32_t INT_VC_AIB_TX_ORDERING_TAG_ENDC_CILOAD_ORDERING_TAG_LEN = 5;
// proc/reg00004.H

static const uint64_t INT_VC_ATX_INIT_CREDIT_COUNT = 0x02010914ull;

static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_CRD_INIT_REQUEST = 24;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RESERVED_25 = 25;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_DMA_READ = 26;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_DMA_READ_LEN = 2;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_AT_MACRO = 28;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_AT_MACRO_LEN = 2;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_ENDC_DOING_CI_LOAD = 30;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_ENDC_DOING_CI_LOAD_LEN = 2;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RESERVED_32_33 = 32;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RESERVED_32_33_LEN = 2;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_READ_CRD_POOL = 34;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_READ_CRD_POOL_LEN = 6;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RESERVED_40_43 = 40;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RESERVED_40_43_LEN = 4;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_DMA_WRITE = 44;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_DMA_WRITE_LEN = 2;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_EQ_POST = 46;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_EQ_POST_LEN = 2;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_TRIG_FWD_TO_INT = 48;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_TRIG_FWD_TO_INT_LEN = 2;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_ENDC_SYNC = 50;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RSD_CRD_ENDC_SYNC_LEN = 2;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RESERVED_52_57 = 52;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_RESERVED_52_57_LEN = 6;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_WRITE_CRD_POOL = 58;
static const uint32_t INT_VC_ATX_INIT_CREDIT_COUNT_WRITE_CRD_POOL_LEN = 6;
// proc/reg00004.H

static const uint64_t INT_VC_ENDC_DBG_CACHE_EN = 0x02010995ull;

static const uint32_t INT_VC_ENDC_DBG_CACHE_EN_INT_VC_ENDC_DBG_CACHE_EN_ENABLE = 0;
static const uint32_t INT_VC_ENDC_DBG_CACHE_EN_INT_VC_ENDC_DBG_CACHE_EN_ENABLE_LEN = 16;
// proc/reg00004.H

static const uint64_t INT_VC_ENDC_WATCH1_DATA1 = 0x020109adull;
// proc/reg00004.H

static const uint64_t INT_VC_ENDC_WATCH2_SPEC = 0x020109b0ull;

static const uint32_t INT_VC_ENDC_WATCH2_SPEC_CONFLICT = 0;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_RESERVED_1_7 = 1;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_RESERVED_1_7_LEN = 7;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_FULL = 8;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_RESERVED_9_27 = 9;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_RESERVED_9_27_LEN = 19;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_BLOCKID = 28;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_BLOCKID_LEN = 4;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_RESERVED_32_39 = 32;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_RESERVED_32_39_LEN = 8;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_OFFSET = 40;
static const uint32_t INT_VC_ENDC_WATCH2_SPEC_OFFSET_LEN = 24;
// proc/reg00004.H

static const uint64_t INT_VC_ERR_CFG_G0R0 = 0x020109c0ull;

static const uint32_t INT_VC_ERR_CFG_G0R0_INT_VC_ERR_CFG_G0R0_ERROR_CONFIG = 0;
static const uint32_t INT_VC_ERR_CFG_G0R0_INT_VC_ERR_CFG_G0R0_ERROR_CONFIG_LEN = 64;
// proc/reg00004.H

static const uint64_t INT_VC_ESBC_DBG = 0x02010954ull;

static const uint32_t INT_VC_ESBC_DBG_RESERVED_16_17 = 16;
static const uint32_t INT_VC_ESBC_DBG_RESERVED_16_17_LEN = 2;
static const uint32_t INT_VC_ESBC_DBG_MAX_OUTSTANDING_DMA_READ = 18;
static const uint32_t INT_VC_ESBC_DBG_MAX_OUTSTANDING_DMA_READ_LEN = 6;
static const uint32_t INT_VC_ESBC_DBG_RESERVED_24_25 = 24;
static const uint32_t INT_VC_ESBC_DBG_RESERVED_24_25_LEN = 2;
static const uint32_t INT_VC_ESBC_DBG_MAX_OUTSTANDING_DMA_WRITE = 26;
static const uint32_t INT_VC_ESBC_DBG_MAX_OUTSTANDING_DMA_WRITE_LEN = 6;
static const uint32_t INT_VC_ESBC_DBG_WAY_DISABLE = 32;
static const uint32_t INT_VC_ESBC_DBG_WAY_DISABLE_LEN = 6;
static const uint32_t INT_VC_ESBC_DBG_DIS_TAG_ECC_CORRECTION = 38;
static const uint32_t INT_VC_ESBC_DBG_DIS_TAG_ECC_CORRECTION_LEN = 6;
static const uint32_t INT_VC_ESBC_DBG_DIS_STATE_ECC_CORRECTION = 44;
static const uint32_t INT_VC_ESBC_DBG_DIS_DATA_ECC_CORRECTION = 45;
static const uint32_t INT_VC_ESBC_DBG_DIS_DATA_ECC_CORRECTION_LEN = 3;
static const uint32_t INT_VC_ESBC_DBG_DIS_CTRLBUF_ECC_CORRECTION = 48;
static const uint32_t INT_VC_ESBC_DBG_FORCE_SINGLE_BIT_ECC_ERR = 49;
static const uint32_t INT_VC_ESBC_DBG_FORCE_DOUBLE_BIT_ECC_ERR = 50;
static const uint32_t INT_VC_ESBC_DBG_ECC_ERR_INJ_ARRAY_SEL = 51;
static const uint32_t INT_VC_ESBC_DBG_ECC_ERR_INJ_ARRAY_SEL_LEN = 6;
static const uint32_t INT_VC_ESBC_DBG_TRACE_ENABLE = 57;
static const uint32_t INT_VC_ESBC_DBG_RESERVED_58_63 = 58;
static const uint32_t INT_VC_ESBC_DBG_RESERVED_58_63_LEN = 6;
// proc/reg00004.H

static const uint64_t INT_VC_ESBC_FLUSH_POLL = 0x02010941ull;

static const uint32_t INT_VC_ESBC_FLUSH_POLL_RESERVED_0_3 = 0;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_RESERVED_0_3_LEN = 4;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_BLOCKID = 4;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_BLOCKID_LEN = 4;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_RESERVED_8 = 8;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_OFFSET = 9;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_OFFSET_LEN = 23;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_RESERVED_32_35 = 32;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_RESERVED_32_35_LEN = 4;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_BLOCKID_MASK = 36;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_BLOCKID_MASK_LEN = 4;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_RESERVED_40 = 40;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_OFFSET_MASK = 41;
static const uint32_t INT_VC_ESBC_FLUSH_POLL_OFFSET_MASK_LEN = 23;
// proc/reg00004.H

static const uint64_t INT_VC_MAIN_DBG = 0x02010924ull;

static const uint32_t INT_VC_MAIN_DBG_DIS_AIB_IN_ECC_CORRECTION = 0;
static const uint32_t INT_VC_MAIN_DBG_DIS_TAG_SRAM_ECC_CORRECTION = 1;
static const uint32_t INT_VC_MAIN_DBG_DIS_IRQ_ECC_CORRECTION = 2;
static const uint32_t INT_VC_MAIN_DBG_DIS_ERQ_ECC_CORRECTION = 3;
static const uint32_t INT_VC_MAIN_DBG_DIS_IQS_ECC_CORRECTION = 4;
static const uint32_t INT_VC_MAIN_DBG_DIS_AT_SRAM_ECC_CORRECTION = 5;
static const uint32_t INT_VC_MAIN_DBG_DIS_VSD_SRAM_ECC_CORRECTION = 6;
static const uint32_t INT_VC_MAIN_DBG_DIS_CTAG_SRAM_ECC_CORRECTION = 7;
static const uint32_t INT_VC_MAIN_DBG_FORCE_SINGLE_BIT_ECC_ERR = 8;
static const uint32_t INT_VC_MAIN_DBG_FORCE_DOUBLE_BIT_ECC_ERR = 9;
static const uint32_t INT_VC_MAIN_DBG_ECC_ERR_INJ_SELECTION = 10;
static const uint32_t INT_VC_MAIN_DBG_ECC_ERR_INJ_SELECTION_LEN = 6;
static const uint32_t INT_VC_MAIN_DBG_RESERVED_16_21 = 16;
static const uint32_t INT_VC_MAIN_DBG_RESERVED_16_21_LEN = 6;
static const uint32_t INT_VC_MAIN_DBG_IRQ_TRACE_ENABLE = 22;
static const uint32_t INT_VC_MAIN_DBG_EQA_TRACE_ENABLE = 23;
static const uint32_t INT_VC_MAIN_DBG_ATX_CACHE_SLOTS_IDLE = 24;
static const uint32_t INT_VC_MAIN_DBG_ATX_IS_IDLE = 25;
// proc/reg00004.H

static const uint64_t INT_VC_QUEUES_CFG_REM_0 = 0x02010917ull;

static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_DISABLE = 0;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_DROP_EQ_INJECT_FROM_CORE = 1;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_PREFETCH_DISTANCE = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_PREFETCH_DISTANCE_LEN = 6;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_8_10 = 8;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_8_10_LEN = 3;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_MAX_CRD_TO_CQ = 11;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_MAX_CRD_TO_CQ_LEN = 5;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_16_18 = 16;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_16_18_LEN = 3;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_MAX_CRD_TO_PC = 19;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_MAX_CRD_TO_PC_LEN = 5;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_MAX_NB_OUTSTANDING_DEM = 24;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_MAX_NB_OUTSTANDING_DEM_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_MIN_NB_OUTSTANDING_DEM = 28;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_MIN_NB_OUTSTANDING_DEM_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_32_33 = 32;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_32_33_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_FULL = 34;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_IRQ_IDLE = 35;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_36_37 = 36;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_36_37_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_ERQ_ENABLE_MEMORY_BACKING = 38;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_ERQ_FULL_WRITEBACK_ENABLE = 39;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_40_41 = 40;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_40_41_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_ERQ_MEM_SIZE = 42;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_ERQ_MEM_SIZE_LEN = 6;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_48_49 = 48;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_RESERVED_48_49_LEN = 2;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_ERQ_FULL = 50;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_ERQ_IDLE = 51;
static const uint32_t INT_VC_QUEUES_CFG_REM_0_ERQ_CFG_UPD_PND = 52;
// proc/reg00004.H

static const uint64_t INT_VC_QUEUES_PERF_EVENT_SEL_3 = 0x02010929ull;

static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_FROM_AIB = 0;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_FROM_AIB_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_IRQ_TO_IQA = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_IRQ_TO_IQA_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_IQA_TO_DPS = 8;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_IQA_TO_DPS_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_IQA_TO_IQS = 12;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_IQA_TO_IQS_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_IQS_TO_EQA = 16;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_IQS_TO_EQA_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_EQA_TO_ERQ = 20;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_EQA_TO_ERQ_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_EQA_TO_ATX = 24;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_EQA_TO_ATX_LEN = 4;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_EQA_TO_ENDC = 28;
static const uint32_t INT_VC_QUEUES_PERF_EVENT_SEL_3_EQA_TO_ENDC_LEN = 4;
// proc/reg00004.H

static const uint64_t INT_VC_RECOV_ERR_G0 = 0x020109c5ull;

static const uint32_t INT_VC_RECOV_ERR_G0_INT_VC_RECOV_ERR_G0_ERROR = 0;
static const uint32_t INT_VC_RECOV_ERR_G0_INT_VC_RECOV_ERR_G0_ERROR_LEN = 64;
// proc/reg00004.H

static const uint64_t MCD_MCC_FIR_REG_RWX = 0x03010800ull;
static const uint64_t MCD_MCC_FIR_REG_WOX_AND = 0x03010801ull;
static const uint64_t MCD_MCC_FIR_REG_WOX_OR = 0x03010802ull;

static const uint32_t MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR = 0;
static const uint32_t MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR = 1;
static const uint32_t MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR = 2;
static const uint32_t MCD_MCC_FIR_REG_SM_OR_CASE_ERR = 3;
static const uint32_t MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR = 4;
static const uint32_t MCD_MCC_FIR_REG_CRESP_ADDR_ERR = 5;
static const uint32_t MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR = 6;
static const uint32_t MCD_MCC_FIR_REG_TTAG_PARITY_ERR = 7;
static const uint32_t MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR = 8;
static const uint32_t MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR = 9;
static const uint32_t MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR = 10;
// proc/reg00004.H

static const uint64_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG = 0x03010c06ull;

static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 = 0;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN = 20;
// proc/reg00004.H

static const uint64_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG = 0x03010c07ull;

static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 = 0;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN = 20;
// proc/reg00004.H

static const uint64_t MM1_MM_NMMU_DBG_MODE = 0x03010c59ull;

static const uint32_t MM1_MM_NMMU_DBG_MODE_EN = 0;
static const uint32_t MM1_MM_NMMU_DBG_MODE_PRV_BUS0_STG2_SEL = 1;
static const uint32_t MM1_MM_NMMU_DBG_MODE_PRV_BUS1_STG2_SEL = 2;
static const uint32_t MM1_MM_NMMU_DBG_MODE_FBC_BUS0_STG2_SEL = 3;
static const uint32_t MM1_MM_NMMU_DBG_MODE_FBC_BUS1_STG2_SEL = 4;
static const uint32_t MM1_MM_NMMU_DBG_MODE_MSC_BUS0_STG2_SEL = 5;
static const uint32_t MM1_MM_NMMU_DBG_MODE_MSC_BUS1_STG2_SEL = 6;
static const uint32_t MM1_MM_NMMU_DBG_MODE_SLB_BUS0_STG2_SEL = 7;
static const uint32_t MM1_MM_NMMU_DBG_MODE_SLB_BUS1_STG2_SEL = 8;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TW_BUS0_STG2_SEL = 9;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TW_BUS1_STG2_SEL = 10;
static const uint32_t MM1_MM_NMMU_DBG_MODE_RDX_BUS0_STG2_SEL = 11;
static const uint32_t MM1_MM_NMMU_DBG_MODE_RDX_BUS1_STG2_SEL = 12;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TLB_BUS0_STG2_SEL = 13;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TLB_BUS1_STG2_SEL = 14;
static const uint32_t MM1_MM_NMMU_DBG_MODE_FBC_BUS0_STG1_SEL = 15;
static const uint32_t MM1_MM_NMMU_DBG_MODE_FBC_BUS1_STG1_SEL = 16;
static const uint32_t MM1_MM_NMMU_DBG_MODE_MSC_BUS0_STG1_SEL = 17;
static const uint32_t MM1_MM_NMMU_DBG_MODE_MSC_BUS1_STG1_SEL = 18;
static const uint32_t MM1_MM_NMMU_DBG_MODE_SLB_BUS0_STG1_SEL = 19;
static const uint32_t MM1_MM_NMMU_DBG_MODE_SLB_BUS1_STG1_SEL = 20;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TW_BUS0_STG1_SEL = 21;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TW_BUS1_STG1_SEL = 22;
static const uint32_t MM1_MM_NMMU_DBG_MODE_RDX_BUS0_STG1_SEL = 23;
static const uint32_t MM1_MM_NMMU_DBG_MODE_RDX_BUS1_STG1_SEL = 24;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TLB_BUS0_STG1_SEL = 25;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TLB_BUS1_STG1_SEL = 26;
static const uint32_t MM1_MM_NMMU_DBG_MODE_FBC_BUS0_STG0_SEL = 32;
static const uint32_t MM1_MM_NMMU_DBG_MODE_FBC_BUS0_STG0_SEL_LEN = 4;
static const uint32_t MM1_MM_NMMU_DBG_MODE_FBC_BUS1_STG0_SEL = 36;
static const uint32_t MM1_MM_NMMU_DBG_MODE_FBC_BUS1_STG0_SEL_LEN = 4;
static const uint32_t MM1_MM_NMMU_DBG_MODE_MSC_BUS0_STG0_SEL = 40;
static const uint32_t MM1_MM_NMMU_DBG_MODE_MSC_BUS0_STG0_SEL_LEN = 4;
static const uint32_t MM1_MM_NMMU_DBG_MODE_MSC_BUS1_STG0_SEL = 44;
static const uint32_t MM1_MM_NMMU_DBG_MODE_MSC_BUS1_STG0_SEL_LEN = 4;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TW_BUS0_STG0_SEL = 48;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TW_BUS0_STG0_SEL_LEN = 6;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TW_BUS1_STG0_SEL = 54;
static const uint32_t MM1_MM_NMMU_DBG_MODE_TW_BUS1_STG0_SEL_LEN = 6;
static const uint32_t MM1_MM_NMMU_DBG_MODE_RDX_BUS0_STG0_SEL = 60;
static const uint32_t MM1_MM_NMMU_DBG_MODE_RDX_BUS0_STG0_SEL_LEN = 2;
static const uint32_t MM1_MM_NMMU_DBG_MODE_RDX_BUS1_STG0_SEL = 62;
static const uint32_t MM1_MM_NMMU_DBG_MODE_RDX_BUS1_STG0_SEL_LEN = 2;
// proc/reg00004.H

static const uint64_t NX_DMA_SU_CH2_ABORT_CSB = 0x02011047ull;
// proc/reg00004.H

static const uint64_t NX_DMA_SU_CH3_ABORT_CSB = 0x02011049ull;
// proc/reg00004.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_MASK_REG_RW = 0x02011083ull;
static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_MASK_REG_WO_AND = 0x02011084ull;
static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_MASK_REG_WO_OR = 0x02011085ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_MASK_REG_NX_CQ_FIR_MASK = 0;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_MASK_REG_NX_CQ_FIR_MASK_LEN = 42;
// proc/reg00004.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG = 0x02011091ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_ECC_INJECT_MODE = 0;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_ECC_INJECT_MODE_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_ECC_INJECT_TYPE = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_ECC_INJECT_TYPE_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_PBCQ_INJECT_ENABLE = 4;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_PBCQ_ARRAY = 5;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_PBCQ_ARRAY_LEN = 4;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_RNG_INJECT_ENABLE = 16;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_RNG_INJECT_ACTION = 17;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_ERAT_ARRAY_ENABLE = 24;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_ERAT_ARRAY_TYPE = 25;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_ERAT_ARRAY_ACTION = 26;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_ERAT_ARRAY_SELECT = 27;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_ECC_REG_ERAT_ARRAY_SELECT_LEN = 4;
// proc/reg00004.H

static const uint64_t NX_PBI_RNG_ST1 = 0x020110e2ull;

static const uint32_t NX_PBI_RNG_ST1_SOFT_FAIL_TH = 0;
static const uint32_t NX_PBI_RNG_ST1_SOFT_FAIL_TH_LEN = 7;
static const uint32_t NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN = 7;
static const uint32_t NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN_LEN = 16;
static const uint32_t NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX = 23;
static const uint32_t NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX_LEN = 16;
// proc/reg00004.H

static const uint64_t NX_PBI_SHIM_ERAT_STATUS_CONTROL = 0x020110d6ull;

static const uint32_t NX_PBI_SHIM_ERAT_STATUS_CONTROL_PBI_SHIM_FORCE_ERAT_BYPASS = 0;
static const uint32_t NX_PBI_SHIM_ERAT_STATUS_CONTROL_PBI_SHIM_ERAT_IDLE = 1;
static const uint32_t NX_PBI_SHIM_ERAT_STATUS_CONTROL_PBI_SHIM_ERAT_VALID_ENTRY = 2;
static const uint32_t NX_PBI_SHIM_ERAT_STATUS_CONTROL_PBI_SHIM_DISABLE_ERAT_HIT_UNDER_BARRIER = 3;
static const uint32_t NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE = 6;
static const uint32_t NX_PBI_SHIM_ERAT_STATUS_CONTROL_PBI_SHIM_DISABLE_CHECKIN_HANG_TIMER = 7;
static const uint32_t NX_PBI_SHIM_ERAT_STATUS_CONTROL_PBI_SHIM_DISABLE_CHECKOUT_HANG_TIMER = 8;
static const uint32_t NX_PBI_SHIM_ERAT_STATUS_CONTROL_PBI_SHIM_SPECULATIVE_CHECKIN_COUNT = 9;
static const uint32_t NX_PBI_SHIM_ERAT_STATUS_CONTROL_PBI_SHIM_SPECULATIVE_CHECKIN_COUNT_LEN = 3;
// proc/reg00004.H

static const uint64_t NX_PBI_UMAC_RNG_FAILED_INT = 0x020110e7ull;

static const uint32_t NX_PBI_UMAC_RNG_FAILED_INT_ENABLE = 0;
static const uint32_t NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS = 8;
static const uint32_t NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS_LEN = 44;
// proc/reg00004.H

static const uint64_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_CNTL = 0x020110cdull;

static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET = 4;
static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN = 8;
static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_CNTL_QUEUED = 15;
static const uint32_t NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN = 9;
// proc/reg00004.H

static const uint64_t PB_COM_ES3_HP_MODE2_NEXT = 0x0000038dull;

static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_0_EN_NEXT_ES3 = 0;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_1_EN_NEXT_ES3 = 1;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_2_EN_NEXT_ES3 = 2;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_3_EN_NEXT_ES3 = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_4_EN_NEXT_ES3 = 4;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_5_EN_NEXT_ES3 = 5;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_6_EN_NEXT_ES3 = 6;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_7_EN_NEXT_ES3 = 7;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_0_ADDR_DIS_NEXT_ES3 = 8;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_1_ADDR_DIS_NEXT_ES3 = 9;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_2_ADDR_DIS_NEXT_ES3 = 10;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_3_ADDR_DIS_NEXT_ES3 = 11;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_4_ADDR_DIS_NEXT_ES3 = 12;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_5_ADDR_DIS_NEXT_ES3 = 13;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_6_ADDR_DIS_NEXT_ES3 = 14;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_7_ADDR_DIS_NEXT_ES3 = 15;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_0_MODE_NEXT_ES3 = 16;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_0_ID_NEXT_ES3 = 17;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_0_ID_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_1_MODE_NEXT_ES3 = 20;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_1_ID_NEXT_ES3 = 21;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_1_ID_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_2_MODE_NEXT_ES3 = 24;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_2_ID_NEXT_ES3 = 25;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_2_ID_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_3_MODE_NEXT_ES3 = 28;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_3_ID_NEXT_ES3 = 29;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_3_ID_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_4_MODE_NEXT_ES3 = 32;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_4_ID_NEXT_ES3 = 33;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_4_ID_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_5_MODE_NEXT_ES3 = 36;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_5_ID_NEXT_ES3 = 37;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_5_ID_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_6_MODE_NEXT_ES3 = 40;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_6_ID_NEXT_ES3 = 41;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_6_ID_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_7_MODE_NEXT_ES3 = 44;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_7_ID_NEXT_ES3 = 45;
static const uint32_t PB_COM_ES3_HP_MODE2_NEXT_7_ID_NEXT_ES3_LEN = 3;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM10_PSAVE01_MODE_CFG = 0x10011814ull;

static const uint32_t PB_PTLSCOM10_PSAVE01_MODE_CFG_MODE = 0;
static const uint32_t PB_PTLSCOM10_PSAVE01_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PTLSCOM10_PSAVE01_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PTLSCOM10_PSAVE01_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PTLSCOM10_PSAVE01_MODE_CFG_SPARE = 5;
static const uint32_t PB_PTLSCOM10_PSAVE01_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM10_PSAVE01_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PTLSCOM10_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN = 8;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG = 0x1101182cull;

static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_0 = 0;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_0_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_1 = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_1_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_2 = 14;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_2_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_3 = 21;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_3_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_4 = 28;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_4_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_5 = 35;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_5_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_6 = 42;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_6_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_7 = 49;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_7_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_8 = 56;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_LINK_EVENT_8_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX1_REG_ALT_EVENTS = 63;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG = 0x1101182dull;

static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_9 = 0;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_9_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_10 = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_10_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_11 = 14;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_11_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_12 = 21;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_12_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_13 = 28;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_13_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_14 = 35;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_14_LEN = 7;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_15 = 42;
static const uint32_t PB_PTLSCOM23_CFG_TLPM_MUX2_REG_15_LEN = 7;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM23_FP23_CFG = 0x1101180bull;

static const uint32_t PB_PTLSCOM23_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 = 0;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_DISABLE_GATHERING = 1;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_DISABLE_CMD_COMPRESSION = 2;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_DISABLE_PRSP_COMPRESSION = 3;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_LL_CREDIT_LO_LIMIT = 4;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_LL_CREDIT_PS_LIMIT = 12;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP = 20;
static const uint32_t PB_PTLSCOM23_FP23_CFG_23_CMD_EXP_TIME = 21;
static const uint32_t PB_PTLSCOM23_FP23_CFG_23_CMD_EXP_TIME_LEN = 3;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_RUN_AFTER_FRAME_ERROR = 24;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST = 25;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_PRS_SPARE = 26;
static const uint32_t PB_PTLSCOM23_FP23_CFG_2_PRS_SPARE_LEN = 6;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 = 32;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_DISABLE_GATHERING = 33;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_DISABLE_CMD_COMPRESSION = 34;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_DISABLE_PRSP_COMPRESSION = 35;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_LL_CREDIT_LO_LIMIT = 36;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_LL_CREDIT_PS_LIMIT = 44;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP = 52;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_FMR_SPARE = 53;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_FMR_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_RUN_AFTER_FRAME_ERROR = 56;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST = 57;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_PRS_SPARE = 58;
static const uint32_t PB_PTLSCOM23_FP23_CFG_3_PRS_SPARE_LEN = 6;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM23_PERFTRACE_CFG_REG = 0x1101182bull;

static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE = 0;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE = 1;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE = 2;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_TSPARE6 = 3;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE = 4;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE = 5;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE = 6;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_TSPARE7 = 7;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT = 8;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT_LEN = 2;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT = 10;
static const uint32_t PB_PTLSCOM23_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT_LEN = 2;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM45_DOB23_DIB23_INT_ERR_REG = 0x1201182aull;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM45_FP01_CFG = 0x1201180aull;

static const uint32_t PB_PTLSCOM45_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 = 0;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_DISABLE_GATHERING = 1;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_DISABLE_CMD_COMPRESSION = 2;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_DISABLE_PRSP_COMPRESSION = 3;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_LL_CREDIT_LO_LIMIT = 4;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_LL_CREDIT_PS_LIMIT = 12;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP = 20;
static const uint32_t PB_PTLSCOM45_FP01_CFG_01_CMD_EXP_TIME = 21;
static const uint32_t PB_PTLSCOM45_FP01_CFG_01_CMD_EXP_TIME_LEN = 3;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_RUN_AFTER_FRAME_ERROR = 24;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST = 25;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_PRS_SPARE = 26;
static const uint32_t PB_PTLSCOM45_FP01_CFG_0_PRS_SPARE_LEN = 6;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 = 32;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_DISABLE_GATHERING = 33;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_DISABLE_CMD_COMPRESSION = 34;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_DISABLE_PRSP_COMPRESSION = 35;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_LL_CREDIT_LO_LIMIT = 36;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_LL_CREDIT_PS_LIMIT = 44;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP = 52;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_FMR_SPARE = 53;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_FMR_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_RUN_AFTER_FRAME_ERROR = 56;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST = 57;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_PRS_SPARE = 58;
static const uint32_t PB_PTLSCOM45_FP01_CFG_1_PRS_SPARE_LEN = 6;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM45_MISC_CFG = 0x12011825ull;

static const uint32_t PB_PTLSCOM45_MISC_CFG_SCOM_PTLX0_ENABLE = 0;
static const uint32_t PB_PTLSCOM45_MISC_CFG_SCOM_PTLX1_ENABLE = 1;
static const uint32_t PB_PTLSCOM45_MISC_CFG_SCOM_PTLY0_ENABLE = 2;
static const uint32_t PB_PTLSCOM45_MISC_CFG_SCOM_PTLY1_ENABLE = 3;
static const uint32_t PB_PTLSCOM45_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR = 4;
static const uint32_t PB_PTLSCOM45_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR = 5;
static const uint32_t PB_PTLSCOM45_MISC_CFG_SCOM_PTLX_RESET_KEEPER = 6;
static const uint32_t PB_PTLSCOM45_MISC_CFG_SCOM_PTLY_RESET_KEEPER = 7;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_0_ENABLE = 8;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_1_ENABLE = 9;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_2_ENABLE = 10;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_3_ENABLE = 11;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 = 12;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN = 13;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 = 14;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN = 15;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 = 16;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN = 17;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 = 18;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN = 19;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 = 20;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 = 21;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 = 22;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 = 23;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 = 24;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 = 25;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 = 26;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 = 27;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 = 28;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 = 29;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 = 30;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 = 31;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 = 32;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 = 33;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 = 34;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 = 35;
static const uint32_t PB_PTLSCOM45_MISC_CFG_SCOM_PTLX_EMULATION_MODE = 36;
static const uint32_t PB_PTLSCOM45_MISC_CFG_SCOM_PTLY_EMULATION_MODE = 37;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TOD_EVN_IB_MUX_CTL = 38;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TOD_EVN_IB_MUX_CTL_LEN = 2;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TOD_ODD_IB_MUX_CTL = 40;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TOD_ODD_IB_MUX_CTL_LEN = 2;
static const uint32_t PB_PTLSCOM45_MISC_CFG_TRANSPORT_PRI_BUS_CTL = 42;
static const uint32_t PB_PTLSCOM45_MISC_CFG_MISC_SPARE = 43;
static const uint32_t PB_PTLSCOM45_MISC_CFG_MISC_SPARE_LEN = 9;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM45_PMU0_CNPM_COUNTER = 0x12011821ull;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM45_PR0123_ERR = 0x12011829ull;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM45_PSAVE23_MISC_CFG = 0x12011817ull;

static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_HALF_LUC = 0;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_HALF_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_HALF_HUC = 8;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_HALF_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_HALF_LUT = 16;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_HALF_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_HALF_HUT = 21;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_HALF_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_HALF_SPARE = 26;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_HALF_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_QTR_LUC = 28;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_QTR_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_QTR_HUC = 36;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_QTR_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_QTR_LUT = 44;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_QTR_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_QTR_HUT = 49;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_QTR_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_QTR_SPARE = 54;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_QTR_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_WSIZE = 56;
static const uint32_t PB_PTLSCOM45_PSAVE23_MISC_CFG_WSIZE_LEN = 3;
// proc/reg00004.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint64_t PB_PTLSCOM45_PTL_FIR_REG_RWX = 0x12011800ull;
static const uint64_t PB_PTLSCOM45_PTL_FIR_REG_WOX_AND = 0x00000001ull;
static const uint64_t PB_PTLSCOM45_PTL_FIR_REG_WOX_OR = 0x00000002ull;

static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED = 0;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED = 1;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED = 2;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED = 3;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE = 8;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE = 9;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE = 10;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE = 11;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE = 12;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE = 13;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN = 20;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN = 21;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN = 22;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN = 23;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN = 28;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN = 29;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN = 30;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN = 31;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN = 36;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN = 37;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN = 38;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN = 39;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN = 40;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN = 41;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN = 42;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN = 43;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR = 52;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR = 53;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR = 56;
static const uint32_t PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR = 57;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM67_PMU3_TLPM_COUNTER = 0x1301181eull;
// proc/reg00004.H

static const uint64_t PB_PTLSCOM67_RCMD_RATE_CFG = 0x1301180cull;

static const uint32_t PB_PTLSCOM67_RCMD_RATE_CFG_X_RCMD_RATE = 0;
static const uint32_t PB_PTLSCOM67_RCMD_RATE_CFG_X_RCMD_RATE_LEN = 8;
static const uint32_t PB_PTLSCOM67_RCMD_RATE_CFG_Y_RCMD_RATE = 8;
static const uint32_t PB_PTLSCOM67_RCMD_RATE_CFG_Y_RCMD_RATE_LEN = 8;
static const uint32_t PB_PTLSCOM67_RCMD_RATE_CFG_X_RCMD_RATE_ADDER = 16;
static const uint32_t PB_PTLSCOM67_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN = 4;
static const uint32_t PB_PTLSCOM67_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER = 20;
static const uint32_t PB_PTLSCOM67_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN = 4;
// proc/reg00004.H

static const uint64_t PB_BRIDGE_HCA_FIR_MASK_SCOM = 0x03012403ull;
static const uint64_t PB_BRIDGE_HCA_FIR_MASK_SCOM1 = 0x03012404ull;
static const uint64_t PB_BRIDGE_HCA_FIR_MASK_SCOM2 = 0x03012405ull;

static const uint32_t PB_BRIDGE_HCA_FIR_MASK_FIR_MASK_BITS = 0;
static const uint32_t PB_BRIDGE_HCA_FIR_MASK_FIR_MASK_BITS_LEN = 28;
// proc/reg00005.H

static const uint64_t PB_BRIDGE_HCA_MONITOR_1_ADDRESS_REG = 0x0301240eull;

static const uint32_t PB_BRIDGE_HCA_MONITOR_1_ADDRESS_REG_ENABLE = 0;
static const uint32_t PB_BRIDGE_HCA_MONITOR_1_ADDRESS_REG_ADDRESS = 13;
static const uint32_t PB_BRIDGE_HCA_MONITOR_1_ADDRESS_REG_ADDRESS_LEN = 17;
static const uint32_t PB_BRIDGE_HCA_MONITOR_1_ADDRESS_REG_SIZE = 32;
static const uint32_t PB_BRIDGE_HCA_MONITOR_1_ADDRESS_REG_SIZE_LEN = 15;
// proc/reg00005.H

static const uint64_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_FILT = 0x030120c6ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_FILT_PAT = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_FILT_PAT_LEN = 23;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_FILT_CRESP_PAT = 27;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_FILT_CRESP_PAT_LEN = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_FILT_MASK = 32;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_FILT_MASK_LEN = 23;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_FILT_CRESP_MASK = 59;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_FILT_CRESP_MASK_LEN = 5;
// proc/reg00005.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_0_PHBRESET_REG = 0x0801084aull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PHBRESET_REG_PE_ETU_RESET = 0;
// proc/reg00005.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_CERR_RPT_REG = 0x0801088bull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_CERR_RPT_REG_PBAIB_CERR_RPT0 = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN = 21;
// proc/reg00005.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG = 0x02011807ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_EN = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_INBOUND_OVERRIDE_EN = 1;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_OUTBOUND_OVERRIDE_EN = 2;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_CHECKOUT_BASE_RTAG = 3;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_CHECKOUT_BASE_RTAG_LEN = 17;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_RESPONSE_BASE_RTAG = 23;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_RESPONSE_BASE_RTAG_LEN = 17;
// proc/reg00005.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2 = 0x0201180eull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2_LEN = 40;
// proc/reg00005.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRMASK_REG_RW = 0x02011843ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRMASK_REG_WO_AND = 0x02011844ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRMASK_REG_WO_OR = 0x02011845ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRMASK_REG_NFIRMASK = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRMASK_REG_NFIRMASK_LEN = 28;
// proc/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_ACTION1_REG = 0x0000098full;
// proc/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_PHB5_PMON_CONFIG = 0x00000997ull;
// proc/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_WOF_REG = 0x00000990ull;
// proc/reg00005.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXDCR_REG = 0x090108ceull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXDCR_REG_A = 33;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXDCR_REG_A_LEN = 2;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXDCR_REG_R = 44;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PBAIBTXDCR_REG_R_LEN = 4;
// proc/reg00005.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_2_PHBRESET_REG = 0x090108caull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_2_PHBRESET_REG_PE_ETU_RESET = 0;
// proc/reg00005.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_NRDSTKOVR_REG = 0x03011808ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_NRDSTKOVR_REG_STK0 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NRDSTKOVR_REG_STK0_LEN = 32;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NRDSTKOVR_REG_STK1 = 32;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NRDSTKOVR_REG_STK1_LEN = 16;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NRDSTKOVR_REG_ENABLE = 48;
// proc/reg00005.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_PREDV_REG = 0x03011806ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_PREDV_REG_RD_PREDV_TIMEOUT_MASK = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PREDV_REG_RD_PREDV_TIMEOUT_MASK_LEN = 8;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PREDV_REG_WR_PREDV_TIMEOUT_MASK = 8;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PREDV_REG_WR_PREDV_TIMEOUT_MASK_LEN = 8;
// proc/reg00005.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT0_REG = 0x0301188aull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT0_REG_CERR_RPT0 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT0_REG_CERR_RPT0_LEN = 64;
// proc/reg00005.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT1_REG = 0x0301188bull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT1_REG_CERR_RPT1 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_CERR_RPT1_REG_CERR_RPT1_LEN = 41;
// proc/reg00005.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR1_MASK_REG = 0x03011891ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN = 40;
// proc/reg00005.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_BARE_REG = 0x030118d4ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_BARE_REG_MMIO_BAR0_EN = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_BARE_REG_MMIO_BAR1_EN = 1;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_BARE_REG_PHB_BAR_EN = 2;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_BARE_REG_INT_BAR_EN = 3;
// proc/reg00005.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRWOF_REG = 0x030118c8ull;
// proc/reg00005.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PBCQMODE_REG = 0x030118cdull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PBCQMODE_REG_PEER2PEER_MODDE = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PBCQMODE_REG_ENHANCED_PEER2PEER_MODDE = 1;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PBCQMODE_REG_PB_CQ_REGS_CS_ENABLE_SMF = 2;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PBCQMODE_REG_ATOMIC_LITTLE_ENDIAN = 3;
// proc/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE1_PHB0_ETUX16_RSB_REGS_PHB5_PMON_EVENT_SEL = 0x00000918ull;
// proc/reg00005.H

static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL = 0x09010944ull;

static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_ENABLE = 0;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE = 12;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN = 8;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE = 44;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN = 8;
// proc/reg00005.H

static const uint64_t TP_TPBR_AD_ADU_HANG_DIV_REG = 0x03001c50ull;

static const uint32_t TP_TPBR_AD_ADU_HANG_DIV_REG_DATA_HANG_DIV = 0;
static const uint32_t TP_TPBR_AD_ADU_HANG_DIV_REG_DATA_HANG_DIV_LEN = 5;
static const uint32_t TP_TPBR_AD_ADU_HANG_DIV_REG_OPER_HANG_DIV = 5;
static const uint32_t TP_TPBR_AD_ADU_HANG_DIV_REG_OPER_HANG_DIV_LEN = 5;
// proc/reg00005.H

static const uint64_t TP_TPBR_AD_ALTD_DATA_REG = 0x03001c04ull;

static const uint32_t TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA = 0;
static const uint32_t TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA_LEN = 64;
// proc/reg00005.H

static const uint64_t TP_TPBR_AD_FORCE_ECC_REG = 0x03001c0dull;

static const uint32_t TP_TPBR_AD_FORCE_ECC_REG_ITAG = 0;
static const uint32_t TP_TPBR_AD_FORCE_ECC_REG_TX_ECC = 1;
static const uint32_t TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_LEN = 16;
static const uint32_t TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE = 17;
// proc/reg00005.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAERRRPT1 = 0x03021ccdull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT1_BADCRESP = 0;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT1_BADCRESP_LEN = 12;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT1_OPERTO = 12;
static const uint32_t TP_TPBR_PBA_PBAF_PBAERRRPT1_OPERTO_LEN = 12;
// proc/reg00005.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAPBOCR1 = 0x03021cd5ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR1_EVENT = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR1_EVENT_LEN = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR1_ACCUM = 44;
static const uint32_t TP_TPBR_PBA_PBAF_PBAPBOCR1_ACCUM_LEN = 20;
// proc/reg00005.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAWBUFVAL0 = 0x03021c98ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAWBUFVAL0_WR_SLVNUM = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAWBUFVAL0_WR_SLVNUM_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAWBUFVAL0_START_WR_ADDR = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAWBUFVAL0_START_WR_ADDR_LEN = 30;
static const uint32_t TP_TPBR_PBA_PBAO_PBAWBUFVAL0_WR_BUFFER_STATUS = 35;
static const uint32_t TP_TPBR_PBA_PBAO_PBAWBUFVAL0_WR_BUFFER_STATUS_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAWBUFVAL0_WR_BYTE_COUNT = 41;
static const uint32_t TP_TPBR_PBA_PBAO_PBAWBUFVAL0_WR_BYTE_COUNT_LEN = 7;
// proc/reg00005.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXISNDTX = 0x00068030ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_SCOPE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_SCOPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_QID = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_TYPE = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_RESERVATION = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_RESERVED_6_7 = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_RESERVED_6_7_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_GROUPID = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_GROUPID_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_CHIPID = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_CHIPID_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_RESERVED_15 = 15;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_VG_TARGE = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_VG_TARGE_LEN = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_STOP = 59;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_CNT = 60;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXISNDTX_SND_CNT_LEN = 4;
// proc/reg00005.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXSNDTX = 0x00068020ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_SCOPE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_SCOPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_QID = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_TYPE = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_RESERVATION = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_RESERVED_6_7 = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_RESERVED_6_7_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_GROUPID = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_GROUPID_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_CHIPID = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_CHIPID_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_RESERVED_15 = 15;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_VG_TARGE = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_VG_TARGE_LEN = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_STOP = 59;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_CNT = 60;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDTX_SND_CNT_LEN = 4;
// proc/reg00005.H

static const uint64_t TP_TPBR_PSI_WRAP_EECNT_REG = 0x03011c09ull;
// proc/reg00005.H

static const uint64_t TP_TPBR_PSI_WRAP_RX_DBFF_REG0 = 0x03011c19ull;
// proc/reg00005.H

static const uint64_t TP_TPBR_PSI_WRAP_RX_ERR_MODE = 0x03011c0full;
// proc/reg00005.H

static const uint64_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG = 0x03011c00ull;

static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_ENABLE_SCWR_TO_TXRF = 0;
static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_DISABLE_ECC_COR_GXC_PSI = 1;
static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_DISABLE_ECC_COR_TXRF_PSI = 2;
static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_TX_CRC_MODE = 3;
static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_TX_CHIP_PERSONALISATION = 4;
static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_TX_ENABLE_STREAMING_MODE = 5;
static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_TX_CHIP_INTERFACEMODE = 6;
static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_DISABLE_TIMEOUT_AND_RETRY = 7;
static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_FENCE_IO_INTERFACE = 8;
static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_FENCE_GX_INTERFACE = 9;
static const uint32_t TP_TPBR_PSI_WRAP_TX_CTRL_STAT_REG_GX_ENABLE_OVERWRITE = 10;
// proc/reg00005.H

static const uint64_t TP_TPBR_PSI_WRAP_TX_DBFF_REG0 = 0x03011c11ull;
// proc/reg00005.H

static const uint64_t TP_TPBR_PSIHB_ESB_NOTIFY = 0x03011d17ull;

static const uint32_t TP_TPBR_PSIHB_ESB_NOTIFY_ADDR = 8;
static const uint32_t TP_TPBR_PSIHB_ESB_NOTIFY_ADDR_LEN = 53;
static const uint32_t TP_TPBR_PSIHB_ESB_NOTIFY_VALID = 63;
// proc/reg00005.H

static const uint64_t TP_TPBR_PSIHB_INTERRUPT_CONTROL = 0x03011d15ull;

static const uint32_t TP_TPBR_PSIHB_INTERRUPT_CONTROL_ESB_OR_LSI_INTERRUPTS = 0;
static const uint32_t TP_TPBR_PSIHB_INTERRUPT_CONTROL_INTERRUPT_SM_RESET = 1;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR6 = 0x00060046ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR6_OCB_OCI_GPEXIVDR6_GPR6 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR6_OCB_OCI_GPEXIVDR6_GPR6_LEN = 32;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR10 = 0x0006204aull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR10_OCB_OCI_GPEXIVDRX_GPR10 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR10_OCB_OCI_GPEXIVDRX_GPR10_LEN = 32;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM = 0x00062017ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_ADDR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_R_NW = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_BUSY = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_BYTE_ENABLE = 35;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_BYTE_ENABLE_LEN = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_LINE_MODE = 43;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_ERROR = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_ERROR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_IFETCH_PENDING = 62;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEM_DATAOP_PENDING = 63;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMEDR = 0x00062014ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMEDR_IR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMEDR_EDR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMEDR_EDR_LEN = 32;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR13 = 0x0006404bull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR13_OCB_OCI_GPEXIVDRX_GPR13 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR13_OCB_OCI_GPEXIVDRX_GPR13_LEN = 32;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR9 = 0x00064049ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR9_OCB_OCI_GPEXIVDR8_GPR9 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR9_OCB_OCI_GPEXIVDR8_GPR9_LEN = 32;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIICACL = 0x0006402dull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIICACL_SIB_PIB_IFETCH_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIICACL_MEM_IFETCH_PENDING = 3;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIICACU = 0x0006402cull;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR8 = 0x00064084ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR8_8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR8_8_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR8_9 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR8_9_LEN = 32;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR2 = 0x00066042ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR2_OCB_OCI_GPEXIVDR2_GPR2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR2_OCB_OCI_GPEXIVDR2_GPR2_LEN = 32;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIR = 0x00066024ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN = 32;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDRX = 0x00066085ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDRX_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDRX_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDRX_3 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDRX_3_LEN = 32;
// proc/reg00005.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA3 = 0x0006c823ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA3_2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA3_2_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA3_3 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA3_3_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA3_4 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA3_4_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA3_5 = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA3_5_LEN = 16;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11 = 0x0006c722ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_O2S_BRIDGE_ENABLE_1_A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_O2S_BRIDGE_ENABLE_1_B = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_RESERVED_2_3 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_RESERVED_2_3_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_O2S_CLOCK_DIVIDER_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_O2S_CLOCK_DIVIDER_1_LEN = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_O2SCTRL11_RESERVED_14_16 = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_O2SCTRL11_RESERVED_14_16_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_O2S_NR_OF_FRAMES_1 = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_RESERVED_18_19 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_RESERVED_18_19_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_SLAVE_DATA_SAMPLE_DELAY = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRL11_SLAVE_DATA_SAMPLE_DELAY_LEN = 7;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SST2A = 0x0006c746ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2A__ONGOING_2A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2A_ST2A_RESERVED_1_4 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2A_ST2A_RESERVED_1_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2A__WRITE_WHILE_BRIDGE_BUSY_ERR_2A = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2A_ST2A_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SST2A__FSM_ERR_2A = 7;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR2 = 0x0006c22cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR2_REGION = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR2_REGION_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR2_BASE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR2_BASE_LEN = 7;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_RW = 0x0006c0b5ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_CLEAR = 0x0006c0b6ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_OR = 0x0006c0b7ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_OCB_OCI_OCCFLG3_OCC_FLAGS = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_OCB_OCI_OCCFLG3_OCC_FLAGS_LEN = 32;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0A_RW = 0x0006c040ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0A_WO_CLEAR = 0x0006c041ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR0A_WO_OR = 0x0006c042ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR0A_OCB_OCI_OIRR0A_INTERRUPT_ROUTE_0_A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR0A_OCB_OCI_OIRR0A_INTERRUPT_ROUTE_0_A_LEN = 32;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ONISR1 = 0x0006c070ull;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q4 = 0x0006c404ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q4_OCB_OCI_OPIT0Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q4_OCB_OCI_OPIT0Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3PRA_ROX = 0x0006c618ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3PRA_WOX_CLEAR = 0x0006c619ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3PRA_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3PRA_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3PRA_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3PRA_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3PRA_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3PRA_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3PRA_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3PRA_7 = 7;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q0 = 0x0006c418ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q0_OCB_OCI_OPIT3Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q0_OCB_OCI_OPIT3Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q6 = 0x0006c426ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q6_OCB_OCI_OPIT4Q6RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q6_OCB_OCI_OPIT4Q6RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q2 = 0x0006c43aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q2_OCB_OCI_OPIT7Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q2_OCB_OCI_OPIT7Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11 = 0x0006c44bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C14RR = 0x0006c54eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C14RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C14RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C14RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C14RR_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C26 = 0x0006c45aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C26_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C26_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C26_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C26_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C26RR = 0x0006c55aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C26RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C26RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C26RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C26RR_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C31RR = 0x0006c55full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C31RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C31RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C31RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C31RR_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C8 = 0x0006c448ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C8_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C8_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C8_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C8_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C13RR = 0x0006c56dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C13RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C13RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C13RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C13RR_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17 = 0x0006c471ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C17_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C20 = 0x0006c474ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C20_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C20_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C20_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C20_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C21RR = 0x0006c575ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C21RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C21RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C21RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C21RR_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C6 = 0x0006c466ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C6_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C6_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C6_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C6_PAYLOAD_LEN = 17;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0 = 0x0006c480ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7_LEN = 4;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITCPRC_ROX = 0x0006c688ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITCPRC_ROX_CLRPART = 0x0006c689ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCPRC_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCPRC_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCPRC_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCPRC_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCPRC_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCPRC_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCPRC_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITCPRC_7 = 7;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG = 0x0006d003ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_MST_DIS_ABUSPAREN = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_MST_DIS_BEPAREN = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_MST_DIS_WRDBUSPAREN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_MST_DIS_RDDBUSPAR = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_MST_SPARE = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_SLV_DIS_SACK = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_SLV_DIS_ABUSPAR = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_SLV_DIS_BEPAR = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_SLV_DIS_BE = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_SLV_DIS_WRDBUSPAR = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_SLV_DIS_RDDBUSPAREN = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_SLV_SPARE = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_SPARE = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCDBG_SPARE_LEN = 4;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM = 0x0006d008ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM1 = 0x0006d009ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2 = 0x0006d00aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR_LEN = 4;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOEAR = 0x0006d200ull;

static const uint32_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOEAR_OCB_PIB_OSTOEAR_OCC_SPCL_TIMEOUT_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOEAR_OCB_PIB_OSTOEAR_OCC_SPCL_TIMEOUT_ADDR_LEN = 32;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW = 0x01010803ull;
static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND = 0x01010804ull;
static const uint64_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR = 0x01010805ull;

static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_2_MASK = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_3_MASK = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_MALF_MASK = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_READ_ERROR_MASK = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_WRITE_ERROR_MASK = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_DATAOUT_PERR_MASK = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OCI_WRITE_DATA_PARITY_MASK = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OCI_BE_PARITY_ERR_MASK = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OCI_ADDR_PARITY_ERR_MASK = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK = 22;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK = 23;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK = 25;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK = 26;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK = 29;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK = 31;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_OCI_TIMEOUT_MASK = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_OCI_READ_DATA_PARITY_MASK = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_OCI_SLAVE_ERROR_MASK = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK = 35;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_PIB_DATA_PARITY_ERR_MASK = 36;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC0_ERROR_MASK = 37;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC1_ERROR_MASK = 38;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC2_ERROR_MASK = 39;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC3_ERROR_MASK = 40;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_FSM_ERR_MASK = 41;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK = 42;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK = 43;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK = 44;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK = 45;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK = 46;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR0_MASK = 47;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR1_MASK = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR2_MASK = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR3_MASK = 50;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK = 51;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK = 52;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK = 53;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK = 54;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK = 55;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK = 56;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK = 57;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK = 58;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK = 59;
static const uint32_t TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK_LEN = 3;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG100 = 0x00008064ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG100_REGISTER100 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG100_REGISTER100_LEN = 64;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG28 = 0x0000801cull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG28_REGISTER28 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG28_REGISTER28_LEN = 64;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG37 = 0x00008025ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG37_REGISTER37 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG37_REGISTER37_LEN = 64;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG49 = 0x00008031ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG49_REGISTER49 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG49_REGISTER49_LEN = 64;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG56 = 0x00008038ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG56_REGISTER56 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG56_REGISTER56_LEN = 64;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG61 = 0x0000803dull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG61_REGISTER61 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG61_REGISTER61_LEN = 64;
// proc/reg00006.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG94 = 0x0000805eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG94_REGISTER94 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG94_REGISTER94_LEN = 64;
// proc/reg00006.H

static const uint64_t TP_TPVSB_FSI_W_I2C_BUSY_REGISTER_A = 0x0000180aull;
// proc/reg00006.H

static const uint64_t TP_TPVSB_FSI_W_I2C_IMM_RESET_S_SDA_A = 0x0000180dull;
// proc/reg00006.H

static const uint64_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_READ_A = 0x00001804ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_READ_A_INT_MASK_000 = 16;
static const uint32_t TP_TPVSB_FSI_W_I2C_INTERRUPT_MASK_REGISTER_READ_A_INT_MASK_000_LEN = 16;
// proc/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_FSI = 0x0000282cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_FSI_BYTE = 0x000028b0ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_SCOM = 0x00050028ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_PERMISSION_TO_SEND_DOORBELL_2 =
    0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_ABORT_DOORBELL_2 = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_LBUS_SLAVE_2B_PENDING = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_PIB_SLAVE_2A_PENDING = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_XDN_DOORBELL_2 = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_XUP_DOORBELL_2 = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_HEADER_COUNT_2A = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_HEADER_COUNT_2A_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_DATA_COUNT_2A = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_DATA_COUNT_2A_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_HEADER_COUNT_2B = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_HEADER_COUNT_2B_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_DATA_COUNT_2B = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_DATA_COUNT_2B_LEN = 8;
// proc/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_0_RWX = 0x00002840ull;
// proc/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_12_RWX = 0x0000284cull;
// proc/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_6_RWX = 0x00002906ull;
// proc/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW = 0x00002910ull;
// proc/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG_FSI = 0x00002809ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE = 0x00002824ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG_SCOM = 0x00050009ull;
// proc/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RWX = 0x0000283bull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4 = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4_LEN = 32;
// proc/reg00006.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_DNFIFO_DATA_OUT_ROX = 0x00002410ull;
// proc/reg00006.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_REQ_RESET_WOX = 0x00002403ull;
// proc/reg00006.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_OUTPUT_EN = 0x000b0054ull;

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_OUTPUT_EN_0 = 0;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_OUTPUT_EN_1 = 1;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_OUTPUT_EN_2 = 2;
// proc/reg00006.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_REM_SIZE_REGISTER_ROX = 0x00000c1cull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_REM_SIZE_REGISTER_DMA_REM_SIZE_REMAINING_WORDS = 8;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_REM_SIZE_REGISTER_DMA_REM_SIZE_REMAINING_WORDS_LEN = 24;
// proc/reg00006.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_EXTENDED_STATUS_ROX = 0x00000c08ull;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_TRUE_MASK_RWX = 0x00000c0dull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_TRUE_MASK_TRUE_MASK_REG = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_TRUE_MASK_TRUE_MASK_REG_LEN = 32;
// proc/reg00007.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_CMD_WRDAT = 0x00020000ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_CMD_WRDAT_WRITE_NOT_READ = 0;
// proc/reg00007.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_RSIS = 0x0002001aull;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP4_WOX = 0x000030e0ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP4_GENERAL_RESET_4 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP4_ERROR_RESET_4 = 1;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP7_FSI0 = 0x0000304cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP7_SCOMFSI0 = 0x00000c13ull;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP6_FSI0 = 0x00003468ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP6_SCOMFSI0 = 0x00000d1aull;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP7_RO = 0x000034ecull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP7_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP7_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP7_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP7_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP7_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP7_2_LEN = 3;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCRSIC0 = 0x00000850ull;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SNML = 0x00000840ull;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SRSIM0 = 0x00000870ull;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_LLSTAT = 0x00000904ull;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP0_FSI1 = 0x00003050ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP0_SCOMFSI1 = 0x00000c14ull;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCRSP1_FSI1 = 0x0000300cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCRSP1_SCOMFSI1 = 0x00000c03ull;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP1_RO = 0x000030d4ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP1_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP1_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP1_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP1_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP1_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP1_2_LEN = 3;
// proc/reg00007.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4B4 = 0x000004b4ull;
// proc/reg00007.H

static const uint64_t VAS_VA_EG_SCF_PGMIG6 = 0x02011446ull;
// proc/reg00007.H

static const uint64_t VAS_VA_RG_SCF_FIR_WOF_REG = 0x02011408ull;

static const uint32_t VAS_VA_RG_SCF_FIR_WOF_REG_VAS_FIR_WOF = 0;
static const uint32_t VAS_VA_RG_SCF_FIR_WOF_REG_VAS_FIR_WOF_LEN = 52;
// proc/reg00007.H

static const uint64_t VAS_VA_RG_SCF_PMCNTL = 0x02011430ull;

static const uint32_t VAS_VA_RG_SCF_PMCNTL_PU_BIT_ENABLES = 0;
static const uint32_t VAS_VA_RG_SCF_PMCNTL_PU_BIT_ENABLES_LEN = 32;
// proc/reg00007.H

static const uint64_t VAS_VA_RG_SCF_UWMBAR = 0x0201140bull;

static const uint32_t VAS_VA_RG_SCF_UWMBAR_UWMBAR_BASE_ADDR = 8;
static const uint32_t VAS_VA_RG_SCF_UWMBAR_UWMBAR_BASE_ADDR_LEN = 28;
// proc/reg00007.H

}
}
#include "proc/reg00004.H"
#include "proc/reg00005.H"
#include "proc/reg00006.H"
#include "proc/reg00007.H"
#endif
