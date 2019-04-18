/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_0.H $       */
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

#ifndef __p10_scom_proc_0_H_
#define __p10_scom_proc_0_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_ACTION0 = 0x02010836ull;

static const uint32_t INT_CQ_ACTION0_INT_CQ_ACTION0 = 0;
static const uint32_t INT_CQ_ACTION0_INT_CQ_ACTION0_LEN = 64;
// proc/reg00244.H

static const uint64_t INT_CQ_ERR_INFO2 = 0x0201083cull;

static const uint32_t INT_CQ_ERR_INFO2_INFO_CAPTURED = 0;
static const uint32_t INT_CQ_ERR_INFO2_RESERVED_1_4 = 1;
static const uint32_t INT_CQ_ERR_INFO2_RESERVED_1_4_LEN = 4;
static const uint32_t INT_CQ_ERR_INFO2_HI = 5;
static const uint32_t INT_CQ_ERR_INFO2_LO = 6;
static const uint32_t INT_CQ_ERR_INFO2_RD_ADDR_0_8 = 7;
static const uint32_t INT_CQ_ERR_INFO2_RD_ADDR_0_8_LEN = 9;
static const uint32_t INT_CQ_ERR_INFO2_SYN_HI_0_7 = 16;
static const uint32_t INT_CQ_ERR_INFO2_SYN_HI_0_7_LEN = 8;
static const uint32_t INT_CQ_ERR_INFO2_SYN_LO_0_7 = 24;
static const uint32_t INT_CQ_ERR_INFO2_SYN_LO_0_7_LEN = 8;
// proc/reg00244.H

static const uint64_t INT_CQ_SWI_CMD1 = 0x02010820ull;
// proc/reg00244.H

static const uint64_t INT_PC_NXC_REGS_WATCH1_DATA1 = 0x02010aadull;
// proc/reg00244.H

static const uint64_t INT_PC_REGS_ERR0_CFG1 = 0x02010ac1ull;

static const uint32_t INT_PC_REGS_ERR0_CFG1_INT_PC_ERR0_CFG1_ERROR_CONFIG0 = 0;
static const uint32_t INT_PC_REGS_ERR0_CFG1_INT_PC_ERR0_CFG1_ERROR_CONFIG0_LEN = 64;
// proc/reg00244.H

static const uint64_t INT_PC_REGS_ERR0_WOF = 0x02010ac2ull;

static const uint32_t INT_PC_REGS_ERR0_WOF_ARX_CREDIT_ERROR = 0;
static const uint32_t INT_PC_REGS_ERR0_WOF_ARX_CMD_ERROR = 1;
static const uint32_t INT_PC_REGS_ERR0_WOF_ARX_DAT_ERROR = 2;
static const uint32_t INT_PC_REGS_ERR0_WOF_ARX_ROUTE_ERROR = 3;
static const uint32_t INT_PC_REGS_ERR0_WOF_ARX_PARITY_ERROR = 4;
static const uint32_t INT_PC_REGS_ERR0_WOF_ARX_AIB_ECC_CE = 5;
static const uint32_t INT_PC_REGS_ERR0_WOF_ARX_AIB_ECC_UE = 6;
static const uint32_t INT_PC_REGS_ERR0_WOF_ARX_TAG_ECC_CE = 7;
static const uint32_t INT_PC_REGS_ERR0_WOF_ARX_TAG_ECC_UE = 8;
static const uint32_t INT_PC_REGS_ERR0_WOF_ARX_TIMEOUT_ERROR = 9;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_10_14 = 10;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_10_14_LEN = 5;
static const uint32_t INT_PC_REGS_ERR0_WOF_AVX_ATX_DAT_ERROR = 15;
static const uint32_t INT_PC_REGS_ERR0_WOF_AVX_ATX_PARITY_ERROR = 16;
static const uint32_t INT_PC_REGS_ERR0_WOF_AVX_ATX_ECC_CE = 17;
static const uint32_t INT_PC_REGS_ERR0_WOF_AVX_ATX_ECC_UE = 18;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_19 = 19;
static const uint32_t INT_PC_REGS_ERR0_WOF_AVX_ATX_ADDR_ERROR = 20;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_21 = 21;
static const uint32_t INT_PC_REGS_ERR0_WOF_MMIO_LDST_PRIO_ERROR = 22;
static const uint32_t INT_PC_REGS_ERR0_WOF_MMIO_LDST_USR_ERROR = 23;
static const uint32_t INT_PC_REGS_ERR0_WOF_MMIO_LDST_OS_ERROR = 24;
static const uint32_t INT_PC_REGS_ERR0_WOF_MMIO_LDST_HYP_ERROR = 25;
static const uint32_t INT_PC_REGS_ERR0_WOF_MMIO_LDST_ULT_ERROR = 26;
static const uint32_t INT_PC_REGS_ERR0_WOF_PROC_MMIO_INVALID_ERROR = 27;
static const uint32_t INT_PC_REGS_ERR0_WOF_PROC_MMIO_USR_ERROR = 28;
static const uint32_t INT_PC_REGS_ERR0_WOF_PROC_MMIO_OS_ERROR = 29;
static const uint32_t INT_PC_REGS_ERR0_WOF_PROC_MMIO_HYP_ERROR = 30;
static const uint32_t INT_PC_REGS_ERR0_WOF_PROC_MMIO_ULT_ERROR = 31;
static const uint32_t INT_PC_REGS_ERR0_WOF_ATX_TCTXT_FIFO_ERROR = 32;
static const uint32_t INT_PC_REGS_ERR0_WOF_ATX_NXC_FIFO_ERROR = 33;
static const uint32_t INT_PC_REGS_ERR0_WOF_ATX_SLOT_OVERFLOW_ERROR = 34;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_35_37 = 35;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_35_37_LEN = 3;
static const uint32_t INT_PC_REGS_ERR0_WOF_ATX_TAG_RELEASE_ERROR = 38;
static const uint32_t INT_PC_REGS_ERR0_WOF_ATX_CREDIT_UNDERFLOW_ERROR = 39;
static const uint32_t INT_PC_REGS_ERR0_WOF_ATX_CREDIT_OVERFLOW_ERROR = 40;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_41 = 41;
static const uint32_t INT_PC_REGS_ERR0_WOF_ATX_PARITY_ERROR = 42;
static const uint32_t INT_PC_REGS_ERR0_WOF_ATX_ECC_CE = 43;
static const uint32_t INT_PC_REGS_ERR0_WOF_ATX_TCTXT_ECC_UE = 44;
static const uint32_t INT_PC_REGS_ERR0_WOF_ATX_NXC_ECC_UE = 45;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_46 = 46;
static const uint32_t INT_PC_REGS_ERR0_WOF_COM_ATX_CMD_STATE_ERROR = 47;
static const uint32_t INT_PC_REGS_ERR0_WOF_COM_ATX_LKP_STATE_ERROR = 48;
static const uint32_t INT_PC_REGS_ERR0_WOF_COM_ATX_ATC_STATE_ERROR = 49;
static const uint32_t INT_PC_REGS_ERR0_WOF_COM_ATX_ATC_CAM_STATE_ERROR = 50;
static const uint32_t INT_PC_REGS_ERR0_WOF_COM_ATX_VSD_TYPE_ERROR = 51;
static const uint32_t INT_PC_REGS_ERR0_WOF_COM_ATX_VSD_IND_ERROR = 52;
static const uint32_t INT_PC_REGS_ERR0_WOF_COM_ATX_VSD_OFF_ERROR = 53;
static const uint32_t INT_PC_REGS_ERR0_WOF_COM_ATX_PARITY_ERROR = 54;
static const uint32_t INT_PC_REGS_ERR0_WOF_COM_ATX_ECC_CE = 55;
static const uint32_t INT_PC_REGS_ERR0_WOF_COM_ATX_ECC_UE = 56;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_57_60 = 57;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_57_60_LEN = 4;
static const uint32_t INT_PC_REGS_ERR0_WOF_REGS_PARITY_ERROR = 61;
static const uint32_t INT_PC_REGS_ERR0_WOF_SCOM_ERROR = 62;
static const uint32_t INT_PC_REGS_ERR0_WOF_RESERVED_63 = 63;
// proc/reg00244.H

static const uint64_t INT_PC_REGS_ERR1_WOF = 0x02010acaull;

static const uint32_t INT_PC_REGS_ERR1_WOF_CMD_ARB_CONFIG_ERROR = 0;
static const uint32_t INT_PC_REGS_ERR1_WOF_CMD_ARB_PARITY_ERROR = 1;
static const uint32_t INT_PC_REGS_ERR1_WOF_CMD_ARB_NXC_RSP_ERROR = 2;
static const uint32_t INT_PC_REGS_ERR1_WOF_RESERVED_3 = 3;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_BLK_GRP_ERROR = 4;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_CAM_ALLOC_ERROR = 5;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_CAM_STATE_ERROR = 6;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_CAM_RCMD_MULTIHIT_ERROR = 7;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_CAM_RCMD_ASSIGN_ERROR = 8;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_CAM_SEQ_ERROR = 9;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_CAM_REQ_ACK_ERROR = 10;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_PARITY_ERROR = 11;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_ECC_CE = 12;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_ECC_UE = 13;
static const uint32_t INT_PC_REGS_ERR1_WOF_CMD_PIPE_PARITY_ERROR = 14;
static const uint32_t INT_PC_REGS_ERR1_WOF_TCTXT_PARITY_ERROR = 15;
static const uint32_t INT_PC_REGS_ERR1_WOF_TCTXT_CONTROL_ERROR = 16;
static const uint32_t INT_PC_REGS_ERR1_WOF_BLK_CNT_OVERFLOW_ERROR = 17;
static const uint32_t INT_PC_REGS_ERR1_WOF_BLK_CNT_UNDERFLOW_ERROR = 18;
static const uint32_t INT_PC_REGS_ERR1_WOF_BLK_PARITY_ERROR = 19;
static const uint32_t INT_PC_REGS_ERR1_WOF_RESERVED_20 = 20;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_RCMD_THRD_MULTIHIT_ERROR = 21;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_RCMD_THRD_ASSIGN_ERROR = 22;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_RCMD_PRESP_MULTIHIT_ERROR = 23;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_RCMD_CRESP_SET_ERROR = 24;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_CRESP_HIT_ERROR = 25;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_LSI_HIT_ERROR = 26;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_MMIO_DATA_CNFLT_ERROR = 27;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_MMIO_DATA_RSP_ERROR = 28;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_NRQ_CMD_ERROR = 29;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_NRQ_REQ_ERROR = 30;
static const uint32_t INT_PC_REGS_ERR1_WOF_PROC_PARITY_ERROR = 31;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_LDST_STATE_VLD_ERROR = 32;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_LDST_STATE_PEND_ERROR = 33;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_LDST_STATE_WAIT_ERROR = 34;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_LDST_STATE_TMOT_ERROR = 35;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_LDST_LD_OVERFLOW_ERROR = 36;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_LDST_ST_OVERFLOW_ERROR = 37;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_LDST_PARITY_ERROR = 38;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_LDST_ECC_CE = 39;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_LDST_ECC_UE = 40;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_PEND_CTRL_ERROR = 41;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_PEND_PARITY_ERROR = 42;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_PCMD_CFG_ERROR = 43;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_PCMD_FIFO_ERROR = 44;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_PCMD_PARITY_ERROR = 45;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_RSP_DATA_ERROR = 46;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_RSP_LVL_ERROR = 47;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_RSP_NXC_ERROR = 48;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_RSP_PARITY_ERROR = 49;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_RSP_ECC_CE = 50;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_RSP_ECC_UE = 51;
static const uint32_t INT_PC_REGS_ERR1_WOF_MMIO_PEND_CFG_ERROR = 52;
static const uint32_t INT_PC_REGS_ERR1_WOF_RESERVED_53 = 53;
static const uint32_t INT_PC_REGS_ERR1_WOF_NRQ_CFG_QSIZE_ERROR = 54;
static const uint32_t INT_PC_REGS_ERR1_WOF_RESERVED_55_56 = 55;
static const uint32_t INT_PC_REGS_ERR1_WOF_RESERVED_55_56_LEN = 2;
static const uint32_t INT_PC_REGS_ERR1_WOF_NRQ_CFG_NXC_CRED_ERROR = 57;
static const uint32_t INT_PC_REGS_ERR1_WOF_NRQ_CTRL_ERROR = 58;
static const uint32_t INT_PC_REGS_ERR1_WOF_NRQ_PARITY_ERROR = 59;
static const uint32_t INT_PC_REGS_ERR1_WOF_NRQ_OVERFLOW_ERROR = 60;
static const uint32_t INT_PC_REGS_ERR1_WOF_NRQ_UNDERFLOW_ERROR = 61;
static const uint32_t INT_PC_REGS_ERR1_WOF_NRQ_ECC_CE = 62;
static const uint32_t INT_PC_REGS_ERR1_WOF_NRQ_ECC_UE = 63;
// proc/reg00244.H

static const uint64_t INT_VC_ATX_PERF_EVENT_SEL_1 = 0x02010932ull;

static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_11 = 0;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_11_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_1R = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_1R_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_1W = 8;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_1W_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_2 = 12;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_2_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_3 = 16;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_3_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_4 = 20;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_4_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_5R = 24;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_5R_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_5W = 28;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_5W_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_6 = 32;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_6_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_7RSP = 36;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_7RSP_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_7INT = 40;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_7INT_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_7EQP = 44;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_7EQP_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_8 = 48;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_8_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_9 = 52;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_9_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_10R = 56;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_10R_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_10W = 60;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_1_10W_LEN = 4;
// proc/reg00244.H

static const uint64_t INT_VC_EASC_FLUSH_CTRL = 0x02010960ull;

static const uint32_t INT_VC_EASC_FLUSH_CTRL_POLL_VALID = 0;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_RESERVED_1 = 1;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE = 2;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7 = 3;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7_LEN = 5;
// proc/reg00244.H

static const uint64_t INT_VC_ENDC_WATCH2_DATA3 = 0x020109b7ull;
// proc/reg00244.H

static const uint64_t INT_VC_ERR_CFG_G1R1 = 0x020109c9ull;

static const uint32_t INT_VC_ERR_CFG_G1R1_INT_VC_ERR_CFG_G1R1_ERROR_CONFIG = 0;
static const uint32_t INT_VC_ERR_CFG_G1R1_INT_VC_ERR_CFG_G1R1_ERROR_CONFIG_LEN = 48;
// proc/reg00244.H

static const uint64_t INT_VC_ESBC_ADDITIONAL_PERF = 0x0201095bull;

static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_P0_IS_IDLE = 0;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_P1_IS_IDLE = 1;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_RESERVED_2_7 = 2;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_RESERVED_2_7_LEN = 6;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_MAX_PTAG_IN_USE = 8;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_MAX_PTAG_IN_USE_LEN = 8;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_MAX_OUTSTANDING_SOFT_EOI = 16;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_MAX_OUTSTANDING_SOFT_EOI_LEN = 8;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_MAX_UNLOCK_IN_FIFO = 24;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_MAX_UNLOCK_IN_FIFO_LEN = 8;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_HIGHIEST_SELECTED_WAY = 32;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_HIGHIEST_SELECTED_WAY_LEN = 8;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_RESERVED_40_47 = 40;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_RESERVED_40_47_LEN = 8;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_MAX_OUTSTANDING_ESB_FETCH = 48;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_MAX_OUTSTANDING_ESB_FETCH_LEN = 8;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_MAX_OUTSTANDING_ESB_WRITE = 56;
static const uint32_t INT_VC_ESBC_ADDITIONAL_PERF_MAX_OUTSTANDING_ESB_WRITE_LEN = 8;
// proc/reg00244.H

static const uint64_t INT_VC_ESBC_CFG = 0x02010948ull;

static const uint32_t INT_VC_ESBC_CFG_RESERVED_16_18 = 16;
static const uint32_t INT_VC_ESBC_CFG_RESERVED_16_18_LEN = 3;
static const uint32_t INT_VC_ESBC_CFG_NB_LOAD_ENGINE_CORE = 19;
static const uint32_t INT_VC_ESBC_CFG_NB_LOAD_ENGINE_CORE_LEN = 5;
static const uint32_t INT_VC_ESBC_CFG_RESERVED_24_26 = 24;
static const uint32_t INT_VC_ESBC_CFG_RESERVED_24_26_LEN = 3;
static const uint32_t INT_VC_ESBC_CFG_NB_LOAD_ENGINE_CQ = 27;
static const uint32_t INT_VC_ESBC_CFG_NB_LOAD_ENGINE_CQ_LEN = 5;
static const uint32_t INT_VC_ESBC_CFG_RESERVED_32_34 = 32;
static const uint32_t INT_VC_ESBC_CFG_RESERVED_32_34_LEN = 3;
static const uint32_t INT_VC_ESBC_CFG_NB_LOAD_ENGINE_PC = 35;
static const uint32_t INT_VC_ESBC_CFG_NB_LOAD_ENGINE_PC_LEN = 5;
static const uint32_t INT_VC_ESBC_CFG_HASH_ARRAY_ENABLE = 40;
static const uint32_t INT_VC_ESBC_CFG_HASH_STORE_MODE = 41;
static const uint32_t INT_VC_ESBC_CFG_HASH_STORE_MODE_LEN = 2;
static const uint32_t INT_VC_ESBC_CFG_RESERVED_43_45 = 43;
static const uint32_t INT_VC_ESBC_CFG_RESERVED_43_45_LEN = 3;
static const uint32_t INT_VC_ESBC_CFG_MAX_PTAG_IN_USE = 46;
static const uint32_t INT_VC_ESBC_CFG_MAX_PTAG_IN_USE_LEN = 6;
static const uint32_t INT_VC_ESBC_CFG_BG_SCAN_RATE = 52;
static const uint32_t INT_VC_ESBC_CFG_BG_SCAN_RATE_LEN = 4;
static const uint32_t INT_VC_ESBC_CFG_SPLIT_MODE = 56;
static const uint32_t INT_VC_ESBC_CFG_RESERVED_57_58 = 57;
static const uint32_t INT_VC_ESBC_CFG_RESERVED_57_58_LEN = 2;
static const uint32_t INT_VC_ESBC_CFG_MAX_ENTRIES_IN_MODIFIED = 59;
static const uint32_t INT_VC_ESBC_CFG_MAX_ENTRIES_IN_MODIFIED_LEN = 5;
// proc/reg00244.H

static const uint64_t INT_VC_ESBC_SOFTWR_DATA = 0x02010952ull;

static const uint32_t INT_VC_ESBC_SOFTWR_DATA_INT_VC_ESBC_SOFTWR_DATA_PQ_STATE = 0;
static const uint32_t INT_VC_ESBC_SOFTWR_DATA_INT_VC_ESBC_SOFTWR_DATA_PQ_STATE_LEN = 64;
// proc/reg00244.H

static const uint64_t INT_VC_FATAL_ERR_G0 = 0x020109c4ull;

static const uint32_t INT_VC_FATAL_ERR_G0_INT_VC_FATAL_ERR_G0_ERROR = 0;
static const uint32_t INT_VC_FATAL_ERR_G0_INT_VC_FATAL_ERR_G0_ERROR_LEN = 64;
// proc/reg00244.H

static const uint64_t INT_VC_IQS_CFG = 0x02010920ull;

static const uint32_t INT_VC_IQS_CFG_FORCE_IN_ORDER = 0;
static const uint32_t INT_VC_IQS_CFG_FORCE_IN_ORDER_LEN = 8;
static const uint32_t INT_VC_IQS_CFG_QUEUE_DISABLE = 8;
static const uint32_t INT_VC_IQS_CFG_QUEUE_DISABLE_LEN = 8;
static const uint32_t INT_VC_IQS_CFG_RESERVED_16_23 = 16;
static const uint32_t INT_VC_IQS_CFG_RESERVED_16_23_LEN = 8;
static const uint32_t INT_VC_IQS_CFG_MATRIX_IDLE = 24;
static const uint32_t INT_VC_IQS_CFG_MATRIX_IDLE_LEN = 8;
// proc/reg00244.H

static const uint64_t INT_VC_WOF_ERR_G1 = 0x020109caull;

static const uint32_t INT_VC_WOF_ERR_G1_ESBC_WB_CRD_ERROR = 0;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_RESP_ERROR = 1;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_PTAG_ASSIGN_ERROR = 2;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_PTAG_RELEASE_ERROR = 3;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_REPLAY_ERROR = 4;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_PARITY_ERROR = 5;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_TAG_SRAM_ECC_UE = 6;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_STATE_SRAM_ECC_UE = 7;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_DATA_SRAM_ECC_UE = 8;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_CTRL_SRAM_ECC_UE = 9;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_UNLOCK_FIFO_OVERFLOW = 10;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_LOAD_OVERFLOW = 11;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_LOAD_TAG_ERROR = 12;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_HASH_SRAM_ECC_UE = 13;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_14 = 14;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_15 = 15;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_16 = 16;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_AIB_RESP_ERROR = 17;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_PTAG_ASSIGN_ERROR = 18;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_PTAG_RELEASE_ERROR = 19;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_REPLAY_ERROR = 20;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_PARITY_ERROR = 21;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_TAG_SRAM_ECC_UE = 22;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_STATE_SRAM_ECC_UE = 23;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_DATA_SRAM_ECC_UE = 24;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_CTRL_SRAM_ECC_UE = 25;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_UNLOCK_FIFO_OVERFLOW = 26;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_27 = 27;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_28 = 28;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_29 = 29;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_30 = 30;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_31 = 31;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_TAG_SRAM_ECC_CE = 32;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_STATE_SRAM_ECC_CE = 33;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_DATA_SRAM_ECC_CE = 34;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_CTRL_SRAM_ECC_CE = 35;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_TAG_SRAM_ECC_CE = 36;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_STATE_SRAM_ECC_CE = 37;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_DATA_SRAM_ECC_CE = 38;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_CTRL_SRAM_ECC_CE = 39;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_HASH_SRAM_ECC_CE = 40;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_41 = 41;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_42 = 42;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_43 = 43;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_LOAD_BLK_NOT_OWNED = 44;
static const uint32_t INT_VC_WOF_ERR_G1_ESBC_SOFT_WR_BLK_NOT_OWNED = 45;
static const uint32_t INT_VC_WOF_ERR_G1_EASC_INVALID_EAS = 46;
static const uint32_t INT_VC_WOF_ERR_G1_RESERVED_47 = 47;
// proc/reg00244.H

static const uint64_t INT_VC_WOF_ERR_G2_DETAIL = 0x020109d3ull;

static const uint32_t INT_VC_WOF_ERR_G2_DETAIL_INT_VC_WOF_ERR_G2_DETAIL_ERROR = 0;
static const uint32_t INT_VC_WOF_ERR_G2_DETAIL_INT_VC_WOF_ERR_G2_DETAIL_ERROR_LEN = 64;
// proc/reg00244.H

static const uint64_t MCD_BANK0_BOSON = 0x03010817ull;

static const uint32_t MCD_BANK0_BOSON_VALID = 0;
static const uint32_t MCD_BANK0_BOSON_CHIP_CONTAINED_MODE = 5;
static const uint32_t MCD_BANK0_BOSON_SMF_ENABLE = 6;
static const uint32_t MCD_BANK0_BOSON_GRP_SIZE = 11;
static const uint32_t MCD_BANK0_BOSON_GRP_SIZE_LEN = 19;
static const uint32_t MCD_BANK0_BOSON_GRP_BASE = 33;
static const uint32_t MCD_BANK0_BOSON_GRP_BASE_LEN = 31;
// proc/reg00244.H

static const uint64_t MCD_BANK0_VGC = 0x03010811ull;

static const uint32_t MCD_BANK0_VGC_P10_AVAIL_GROUPS = 0;
static const uint32_t MCD_BANK0_VGC_P10_AVAIL_GROUPS_LEN = 8;
static const uint32_t MCD_BANK0_VGC_RSVD_AVAIL_GROUPS = 8;
static const uint32_t MCD_BANK0_VGC_RSVD_AVAIL_GROUPS_LEN = 8;
static const uint32_t MCD_BANK0_VGC_FAILED_GROUPS = 16;
static const uint32_t MCD_BANK0_VGC_FAILED_GROUPS_LEN = 8;
static const uint32_t MCD_BANK0_VGC_FORCE_RTY_MCD_RATE = 24;
static const uint32_t MCD_BANK0_VGC_FORCE_RTY_MCD_RATE_LEN = 2;
static const uint32_t MCD_BANK0_VGC_4X4_MODE = 32;
static const uint32_t MCD_BANK0_VGC_HANG_POLL_ENABLE = 33;
static const uint32_t MCD_BANK0_VGC_RND_BACKOFF_ENABLE = 34;
static const uint32_t MCD_BANK0_VGC_DROP_PRIORITY_MODE = 35;
static const uint32_t MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE = 36;
static const uint32_t MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE = 37;
static const uint32_t MCD_BANK0_VGC_P8MODE_ENABLE = 38;
static const uint32_t MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE = 39;
static const uint32_t MCD_BANK0_VGC_EXT_ADDR_FAC_MASK = 40;
static const uint32_t MCD_BANK0_VGC_EXT_ADDR_FAC_MASK_LEN = 7;
static const uint32_t MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE = 47;
static const uint32_t MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE_LEN = 2;
static const uint32_t MCD_BANK0_VGC_CS_HW400693_DISABLE = 49;
static const uint32_t MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG = 50;
static const uint32_t MCD_BANK0_VGC_CS_HW403560_DISABLE = 51;
static const uint32_t MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE = 52;
static const uint32_t MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE = 53;
static const uint32_t MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE = 54;
static const uint32_t MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE = 55;
static const uint32_t MCD_BANK0_VGC_1MB_GRANULE_MODE = 57;
static const uint32_t MCD_BANK0_VGC_SPARE = 59;
static const uint32_t MCD_BANK0_VGC_SPARE_LEN = 5;
// proc/reg00244.H

static const uint64_t MCD_FIR_WOF_REG = 0x03010808ull;
// proc/reg00244.H

static const uint64_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG = 0x02010c10ull;

static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL = 0;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL_LEN = 8;
// proc/reg00244.H

static const uint64_t MM0_MM_NMMU_DBG_MODE = 0x02010c59ull;

static const uint32_t MM0_MM_NMMU_DBG_MODE_EN = 0;
static const uint32_t MM0_MM_NMMU_DBG_MODE_PRV_BUS0_STG2_SEL = 1;
static const uint32_t MM0_MM_NMMU_DBG_MODE_PRV_BUS1_STG2_SEL = 2;
static const uint32_t MM0_MM_NMMU_DBG_MODE_FBC_BUS0_STG2_SEL = 3;
static const uint32_t MM0_MM_NMMU_DBG_MODE_FBC_BUS1_STG2_SEL = 4;
static const uint32_t MM0_MM_NMMU_DBG_MODE_MSC_BUS0_STG2_SEL = 5;
static const uint32_t MM0_MM_NMMU_DBG_MODE_MSC_BUS1_STG2_SEL = 6;
static const uint32_t MM0_MM_NMMU_DBG_MODE_SLB_BUS0_STG2_SEL = 7;
static const uint32_t MM0_MM_NMMU_DBG_MODE_SLB_BUS1_STG2_SEL = 8;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TW_BUS0_STG2_SEL = 9;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TW_BUS1_STG2_SEL = 10;
static const uint32_t MM0_MM_NMMU_DBG_MODE_RDX_BUS0_STG2_SEL = 11;
static const uint32_t MM0_MM_NMMU_DBG_MODE_RDX_BUS1_STG2_SEL = 12;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TLB_BUS0_STG2_SEL = 13;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TLB_BUS1_STG2_SEL = 14;
static const uint32_t MM0_MM_NMMU_DBG_MODE_FBC_BUS0_STG1_SEL = 15;
static const uint32_t MM0_MM_NMMU_DBG_MODE_FBC_BUS1_STG1_SEL = 16;
static const uint32_t MM0_MM_NMMU_DBG_MODE_MSC_BUS0_STG1_SEL = 17;
static const uint32_t MM0_MM_NMMU_DBG_MODE_MSC_BUS1_STG1_SEL = 18;
static const uint32_t MM0_MM_NMMU_DBG_MODE_SLB_BUS0_STG1_SEL = 19;
static const uint32_t MM0_MM_NMMU_DBG_MODE_SLB_BUS1_STG1_SEL = 20;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TW_BUS0_STG1_SEL = 21;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TW_BUS1_STG1_SEL = 22;
static const uint32_t MM0_MM_NMMU_DBG_MODE_RDX_BUS0_STG1_SEL = 23;
static const uint32_t MM0_MM_NMMU_DBG_MODE_RDX_BUS1_STG1_SEL = 24;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TLB_BUS0_STG1_SEL = 25;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TLB_BUS1_STG1_SEL = 26;
static const uint32_t MM0_MM_NMMU_DBG_MODE_FBC_BUS0_STG0_SEL = 32;
static const uint32_t MM0_MM_NMMU_DBG_MODE_FBC_BUS0_STG0_SEL_LEN = 4;
static const uint32_t MM0_MM_NMMU_DBG_MODE_FBC_BUS1_STG0_SEL = 36;
static const uint32_t MM0_MM_NMMU_DBG_MODE_FBC_BUS1_STG0_SEL_LEN = 4;
static const uint32_t MM0_MM_NMMU_DBG_MODE_MSC_BUS0_STG0_SEL = 40;
static const uint32_t MM0_MM_NMMU_DBG_MODE_MSC_BUS0_STG0_SEL_LEN = 4;
static const uint32_t MM0_MM_NMMU_DBG_MODE_MSC_BUS1_STG0_SEL = 44;
static const uint32_t MM0_MM_NMMU_DBG_MODE_MSC_BUS1_STG0_SEL_LEN = 4;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TW_BUS0_STG0_SEL = 48;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TW_BUS0_STG0_SEL_LEN = 6;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TW_BUS1_STG0_SEL = 54;
static const uint32_t MM0_MM_NMMU_DBG_MODE_TW_BUS1_STG0_SEL_LEN = 6;
static const uint32_t MM0_MM_NMMU_DBG_MODE_RDX_BUS0_STG0_SEL = 60;
static const uint32_t MM0_MM_NMMU_DBG_MODE_RDX_BUS0_STG0_SEL_LEN = 2;
static const uint32_t MM0_MM_NMMU_DBG_MODE_RDX_BUS1_STG0_SEL = 62;
static const uint32_t MM0_MM_NMMU_DBG_MODE_RDX_BUS1_STG0_SEL_LEN = 2;
// proc/reg00244.H

static const uint64_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG = 0x03010c28ull;

static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE = 4;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE_LEN = 4;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE = 8;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE_LEN = 4;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE = 12;
static const uint32_t MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE_LEN = 4;
// proc/reg00244.H

static const uint64_t NX_DBG_DMA_ENG_FIR_ACTION0 = 0x02011106ull;

static const uint32_t NX_DBG_DMA_ENG_FIR_ACTION0_NX_DMA_ENG_FIR_ACTION0_BITS = 0;
static const uint32_t NX_DBG_DMA_ENG_FIR_ACTION0_NX_DMA_ENG_FIR_ACTION0_BITS_LEN = 48;
// proc/reg00244.H

static const uint64_t NX_DMA_SU_CH0_ABORT_CSB = 0x02011043ull;
// proc/reg00244.H

static const uint64_t NX_DMA_SU_CH1_ABORT_CSB = 0x02011045ull;
// proc/reg00244.H

static const uint64_t NX_DMA_SU_STATUS = 0x02011040ull;

static const uint32_t NX_DMA_SU_STATUS_HMI_ACTIVE = 54;
static const uint32_t NX_DMA_SU_STATUS_PBI_IDLE = 55;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH0_IDLE = 56;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH1_IDLE = 57;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH2_IDLE = 58;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH3_IDLE = 59;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH4_IDLE = 60;
// proc/reg00244.H

static const uint64_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_CNTL = 0x020110ceull;

static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET = 4;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN = 8;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_CNTL_QUEUED = 15;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN = 9;
// proc/reg00244.H

static const uint64_t NX_PBI_UMAC_SEND_WC_BASE_ADDR = 0x020110d2ull;

static const uint32_t NX_PBI_UMAC_SEND_WC_BASE_ADDR_SEND_WC_BAR = 8;
static const uint32_t NX_PBI_UMAC_SEND_WC_BASE_ADDR_SEND_WC_BAR_LEN = 33;
// proc/reg00244.H

static const uint64_t PB_PTLSCOM10_PMU1_CNPM_COUNTER = 0x10011822ull;
// proc/reg00244.H

static const uint64_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG = 0x10011810ull;

static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 = 0;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT = 1;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 = 8;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT = 9;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT = 16;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT = 24;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT = 32;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT_LEN = 5;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT = 37;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2 = 38;
static const uint32_t PB_PTLSCOM10_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2_LEN = 2;
// proc/reg00244.H

static const uint64_t PB_PTLSCOM23_MAILBOX_10_REG = 0x11011832ull;
// proc/reg00244.H

static const uint64_t PB_PTLSCOM23_MAILBOX_11_REG = 0x11011833ull;
// proc/reg00244.H

static const uint64_t PB_PTLSCOM23_PMU3_CNPM_COUNTER = 0x11011824ull;
// proc/reg00244.H

static const uint64_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG = 0x11011811ull;

static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 = 0;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT = 1;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 = 8;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT = 9;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT = 16;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT = 24;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT = 32;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT_LEN = 5;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT = 37;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2 = 38;
static const uint32_t PB_PTLSCOM23_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2_LEN = 2;
// proc/reg00244.H

static const uint64_t PB_PTLSCOM67_CFG_CNPM_REG = 0x1301181full;

static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_EN = 0;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_RESET_MODE = 1;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_COUNTER_MODE = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_GLOBAL_PMISC_DIS = 3;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_GLOBAL_PMISC_MODE = 4;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_EXTERNAL_FREEZE = 5;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_0_1_OP = 6;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_0_1_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_2_3_OP = 8;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_2_3_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_4_5_OP = 10;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_4_5_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_6_7_OP = 12;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_6_7_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_8_9_OP = 14;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_8_9_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_10_11_OP = 16;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_10_11_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_12_13_OP = 18;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_12_13_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_14_15_OP = 20;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_14_15_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_16_17_OP = 22;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_16_17_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_18_19_OP = 24;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_18_19_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_20_21_OP = 26;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_20_21_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_22_23_OP = 28;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_22_23_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_24_25_OP = 30;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_24_25_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_26_27_OP = 32;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_26_27_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_28_29_OP = 34;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_28_29_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_30_31_OP = 36;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_30_31_OP_LEN = 2;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_CASCADE_PMU0 = 38;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_CASCADE_PMU0_LEN = 3;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_CASCADE_PMU1 = 41;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_CASCADE_PMU1_LEN = 3;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_CASCADE_PMU2 = 44;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_CASCADE_PMU2_LEN = 3;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_CASCADE_PMU3 = 47;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_CASCADE_PMU3_LEN = 3;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_SPARE = 50;
static const uint32_t PB_PTLSCOM67_CFG_CNPM_REG_SPARE_LEN = 6;
// proc/reg00244.H

static const uint64_t PB_PTLSCOM67_MAILBOX_30_REG = 0x13011836ull;
// proc/reg00244.H

static const uint64_t PB_PTLSCOM67_MAILBOX_31_REG = 0x13011837ull;
// proc/reg00244.H

static const uint64_t PB_PTLSCOM67_PSAVE01_MISC_CFG = 0x13011815ull;

static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_HALF_LUC = 0;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_HALF_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_HALF_HUC = 8;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_HALF_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_HALF_LUT = 16;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_HALF_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_HALF_HUT = 21;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_HALF_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_HALF_SPARE = 26;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_HALF_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_QTR_LUC = 28;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_QTR_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_QTR_HUC = 36;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_QTR_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_QTR_LUT = 44;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_QTR_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_QTR_HUT = 49;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_QTR_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_QTR_SPARE = 54;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_QTR_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_WSIZE = 56;
static const uint32_t PB_PTLSCOM67_PSAVE01_MISC_CFG_WSIZE_LEN = 3;
// proc/reg00244.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_PHBRESET_REG = 0x080108caull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PHBRESET_REG_PE_ETU_RESET = 0;
// proc/reg00244.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_SPARSE_PAGE_CNTL_REG = 0x02011856ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_SPARSE_PAGE_CNTL_REG_FV = 3;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_SPARSE_PAGE_CNTL_REG_T3 = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_SPARSE_PAGE_CNTL_REG_T4 = 5;
// proc/reg00244.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRMASK_REG_RW = 0x020118c3ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRMASK_REG_WO_AND = 0x020118c4ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRMASK_REG_WO_OR = 0x020118c5ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRMASK_REG_NFIRMASK = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_NFIRMASK_REG_NFIRMASK_LEN = 28;
// proc/reg00244.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_SPARSE_PAGE_CNTL_REG = 0x020118d6ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_SPARSE_PAGE_CNTL_REG_FV = 3;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_SPARSE_PAGE_CNTL_REG_T3 = 4;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_SPARSE_PAGE_CNTL_REG_T4 = 5;
// proc/reg00244.H

static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_PHB5_PMON_CONFIG = 0x08010917ull;
// proc/reg00244.H

static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK = 0x08010907ull;

static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE = 12;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN = 40;
// proc/reg00244.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK = 0x00000947ull;

static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE = 12;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN = 40;
// proc/reg00244.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP = 0x00000986ull;

static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE = 0;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE = 12;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN = 40;
// proc/reg00244.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_0_PHBRESET_REG = 0x0901084aull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PHBRESET_REG_PE_ETU_RESET = 0;
// proc/reg00244.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG = 0x03011807ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_EN = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_INBOUND_OVERRIDE_EN = 1;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_OUTBOUND_OVERRIDE_EN = 2;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_CHECKOUT_BASE_RTAG = 3;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_CHECKOUT_BASE_RTAG_LEN = 17;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_RESPONSE_BASE_RTAG = 23;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_RESPONSE_BASE_RTAG_LEN = 17;
// proc/reg00244.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_BARE_REG = 0x03011854ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_BARE_REG_MMIO_BAR0_EN = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_BARE_REG_MMIO_BAR1_EN = 1;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_BARE_REG_PHB_BAR_EN = 2;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_BARE_REG_INT_BAR_EN = 3;
// proc/reg00245.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_CQSTAT_REG = 0x0301184cull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_CQSTAT_REG_INBOUND_ACTIVE = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_CQSTAT_REG_OUTBOUND_ACTIVE = 1;
// proc/reg00245.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PBCQMODE_REG = 0x0301184dull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PBCQMODE_REG_PEER2PEER_MODDE = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PBCQMODE_REG_ENHANCED_PEER2PEER_MODDE = 1;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PBCQMODE_REG_PB_CQ_REGS_CS_ENABLE_SMF = 2;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PBCQMODE_REG_ATOMIC_LITTLE_ENDIAN = 3;
// proc/reg00245.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_SPARSE_PAGE_CNTL_REG = 0x03011856ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_SPARSE_PAGE_CNTL_REG_FV = 3;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_SPARSE_PAGE_CNTL_REG_T3 = 4;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_SPARSE_PAGE_CNTL_REG_T4 = 5;
// proc/reg00245.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PHBBAR_REG = 0x03011852ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PHBBAR_REG_PE_PHB_BAR = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PHBBAR_REG_PE_PHB_BAR_LEN = 42;
// proc/reg00245.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_SPARSE_PAGE_CNTL_REG = 0x030118d6ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_SPARSE_PAGE_CNTL_REG_FV = 3;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_SPARSE_PAGE_CNTL_REG_T3 = 4;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_SPARSE_PAGE_CNTL_REG_T4 = 5;
// proc/reg00245.H

static const uint64_t TP_TPBR_AD_TOD_CMD_REG = 0x03001c2aull;

static const uint32_t TP_TPBR_AD_TOD_CMD_REG_TOD_CMD_REG_ADR = 30;
static const uint32_t TP_TPBR_AD_TOD_CMD_REG_TOD_CMD_REG_ADR_LEN = 31;
// proc/reg00245.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAERRRPT1 = 0x03021c8dull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_RESERVED_0_5 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_RESERVED_0_5_LEN = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCDE_SETUP_ERR = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCDE_SETUP_ERR_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_SETUP_ERR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_SETUP_ERR_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_OCI_DATAERR = 10;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_OCI_DATAERR_LEN = 2;
// proc/reg00245.H

static const uint64_t TP_TPBR_PSI_WRAP_TX_DF_FSM_REG = 0x03011c06ull;
// proc/reg00245.H

static const uint64_t TP_TPBR_PSIHB_DEBUG_REG = 0x03011d11ull;

static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2FSP_INJ_ERR_BITS = 0;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2FSP_INJ_ERR_BITS_LEN = 2;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2FSP_INJ_ONCE = 2;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2FSP_INJ_CONST = 3;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2PB_INJ_ERR_BITS = 8;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2PB_INJ_ERR_BITS_LEN = 2;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2PB_INJ_ONCE = 10;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2PB_INJ_CONST = 11;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_TRACE_SEL = 16;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_TRACE_SEL_LEN = 4;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR29 = 0x0006004dull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR9 = 0x00060049ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR9_OCB_OCI_GPEXIVDR8_GPR9 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR9_OCB_OCI_GPEXIVDR8_GPR9_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXILR = 0x00060031ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM = 0x00060017ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_ADDR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_R_NW = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_BUSY = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_BYTE_ENABLE = 35;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_BYTE_ENABLE_LEN = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_LINE_MODE = 43;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_ERROR = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_ERROR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_IFETCH_PENDING = 62;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEM_DATAOP_PENDING = 63;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR8 = 0x00060084ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR8_8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR8_8_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR8_9 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR8_9_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGINF = 0x0006201full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGINF_SRR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGINF_SRR0_LEN = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGINF_LR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGINF_LR_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR2 = 0x00062042ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR2_OCB_OCI_GPEXIVDR2_GPR2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR2_OCB_OCI_GPEXIVDR2_GPR2_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR28 = 0x0006204cull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDRX = 0x00062085ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDRX_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDRX_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDRX_3 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDRX_3_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL = 0x0006402full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_ERR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_POPULATE_PENDING = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_VALID = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_VALID_LEN = 4;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU = 0x0006402eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN = 27;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR6 = 0x00064046ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR6_OCB_OCI_GPEXIVDR6_GPR6 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR6_OCB_OCI_GPEXIVDR6_GPR6_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMRA = 0x00064011ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR_LEN = 3;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR28 = 0x00064086ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR28_8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR28_8_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR28_9 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR28_9_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL = 0x00066000ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_WATCHDOG_SEL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_WATCHDOG_SEL_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_FIT_SEL = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_FIT_SEL_LEN = 4;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_DERP0 = 0x0006c180ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP0_DEND = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP0_DEND_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP0_SOR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP0_SOR_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1 = 0x0006c720ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_FRAME_SIZE_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_FRAME_SIZE_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_OUT_COUNT1_1 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_OUT_COUNT1_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_DELAY1_1 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_DELAY1_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_COUNT1_1 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_COUNT1_1_LEN = 6;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSES2 = 0x0006c226ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES2_SH_READ_UNDERFLOW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES2_LL_WRITE_OVERFLOW = 1;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCISR1 = 0x0006c071ull;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ODISR1 = 0x0006c073ull;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_RW = 0x0006c02cull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_WO_CLEAR = 0x0006c02dull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_WO_OR = 0x0006c02eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_OCB_OCI_OIEPR1_INTERRUPT_EDGE_POL_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_OCB_OCI_OIEPR1_INTERRUPT_EDGE_POL_1_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_RW = 0x0006c024ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_WO_CLEAR = 0x0006c025ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_WO_OR = 0x0006c026ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_OCB_OCI_OIMR1_INTERRUPT_MASK_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_OCB_OCI_OIMR1_INTERRUPT_MASK_1_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OINKR1 = 0x0006c030ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OINKR1_OCB_OCI_OINKR1_INTERRUPT_INPUT_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OINKR1_OCB_OCI_OINKR1_INTERRUPT_INPUT_1_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_RW = 0x0006c050ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_WO_CLEAR = 0x0006c051ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_WO_OR = 0x0006c052ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_OCB_OCI_OIRR1A_INTERRUPT_ROUTE_1_A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_OCB_OCI_OIRR1A_INTERRUPT_ROUTE_1_A_LEN = 32;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q7RR = 0x0006c507ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q7RR_OCB_OCI_OPIT0Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q7RR_OCB_OCI_OPIT0Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q5 = 0x0006c40dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q5_OCB_OCI_OPIT1Q5RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q5_OCB_OCI_OPIT1Q5RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q7RR = 0x0006c50full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q7RR_OCB_OCI_OPIT1Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q7RR_OCB_OCI_OPIT1Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1 = 0x0006c411ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q7RR = 0x0006c517ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q7RR_OCB_OCI_OPIT2Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q7RR_OCB_OCI_OPIT2Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7RR = 0x0006c51full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7RR_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7RR_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q7RR = 0x0006c527ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q7RR_OCB_OCI_OPIT4Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q7RR_OCB_OCI_OPIT4Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7 = 0x0006c42full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7_OCB_OCI_OPIT5Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7_OCB_OCI_OPIT5Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7RR = 0x0006c52full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7RR_OCB_OCI_OPIT5Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7RR_OCB_OCI_OPIT5Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q3 = 0x0006c433ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q3_OCB_OCI_OPIT6Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q3_OCB_OCI_OPIT6Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7RR = 0x0006c537ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7RR_OCB_OCI_OPIT6Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7RR_OCB_OCI_OPIT6Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q7RR = 0x0006c53full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q7RR_OCB_OCI_OPIT7Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q7RR_OCB_OCI_OPIT7Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0RR = 0x0006c540ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0RR_PAYLOAD_LEN = 17;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29 = 0x0006c45dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29_PAYLOAD_LEN = 17;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7 = 0x0006c447ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7_PAYLOAD_LEN = 17;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0RR = 0x0006c560ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0RR_PAYLOAD_LEN = 17;
// proc/reg00245.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18 = 0x0006c472ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18_PAYLOAD_LEN = 17;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18RR = 0x0006c572ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18RR_PAYLOAD_LEN = 17;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30 = 0x0006c47eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30_PAYLOAD_LEN = 17;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9 = 0x0006c469ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9_PAYLOAD_LEN = 17;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_ROX = 0x0006c694ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_WOX_CLEAR = 0x0006c695ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_7 = 7;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2SCR2 = 0x0006c842ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR2_OCB_OCI_P2SCR2_P2S_INTER_FRAME_DELAY = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR2_OCB_OCI_P2SCR2_P2S_INTER_FRAME_DELAY_LEN = 17;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICDCM1 = 0x0006c785ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICDCM1_OCB_OCI_WOFICDCM1_DCM_MESSAGE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICDCM1_OCB_OCI_WOFICDCM1_DCM_MESSAGE_LEN = 64;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG10 = 0x0000800aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG10_REGISTER10 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG10_REGISTER10_LEN = 64;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG110 = 0x0000806eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG110_REGISTER110 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG110_REGISTER110_LEN = 64;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG127 = 0x0000807full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG127_REGISTER127 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG127_REGISTER127_LEN = 64;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG27 = 0x0000801bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG27_REGISTER27 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG27_REGISTER27_LEN = 64;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG38 = 0x00008026ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG38_REGISTER38 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG38_REGISTER38_LEN = 64;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG4 = 0x00008004ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG4_REGISTER4 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG4_REGISTER4_LEN = 64;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG46 = 0x0000802eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG46_REGISTER46 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG46_REGISTER46_LEN = 64;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG59 = 0x0000803bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG59_REGISTER59 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG59_REGISTER59_LEN = 64;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG71 = 0x00008047ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG71_REGISTER71 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG71_REGISTER71_LEN = 64;
// proc/reg00246.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG84 = 0x00008054ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG84_REGISTER84 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG84_REGISTER84_LEN = 64;
// proc/reg00246.H

static const uint64_t VAS_VA_RG_SCF_CAMDATA0 = 0x02011434ull;

static const uint32_t VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0 = 0;
static const uint32_t VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0_LEN = 64;
// proc/reg00246.H

static const uint64_t VAS_VA_RG_SCF_CAMDISPCNTL = 0x02011433ull;
// proc/reg00246.H

static const uint64_t VAS_VA_RG_SCF_MMIOCTL = 0x02011429ull;

static const uint32_t VAS_VA_RG_SCF_MMIOCTL_INIT = 0;
static const uint32_t VAS_VA_RG_SCF_MMIOCTL_COMP = 1;
static const uint32_t VAS_VA_RG_SCF_MMIOCTL_OPTYPE = 2;
static const uint32_t VAS_VA_RG_SCF_MMIOCTL_ACTYPE = 3;
static const uint32_t VAS_VA_RG_SCF_MMIOCTL_OP_ERR = 4;
static const uint32_t VAS_VA_RG_SCF_MMIOCTL_OFFSET = 36;
static const uint32_t VAS_VA_RG_SCF_MMIOCTL_OFFSET_LEN = 12;
static const uint32_t VAS_VA_RG_SCF_MMIOCTL_WINID = 48;
static const uint32_t VAS_VA_RG_SCF_MMIOCTL_WINID_LEN = 16;
// proc/reg00246.H

static const uint64_t VAS_VA_RG_SCF_WRMON2WID = 0x0201141aull;
// proc/reg00246.H

static const uint64_t VAS_VA_RG_SCF_WRMON3CMP = 0x02011423ull;
// proc/reg00246.H

static const uint64_t VAS_VA_RG_SCF_WRMON7BAR = 0x02011417ull;
// proc/reg00246.H

}
}
#include "proc/reg00244.H"
#include "proc/reg00245.H"
#include "proc/reg00246.H"
#endif
