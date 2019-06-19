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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_proc_0_H_
#define __p10_scom_proc_0_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_ACTION0 = 0x02010836ull;

static const uint32_t INT_CQ_ACTION0_INT_CQ_ACTION0 = 0;
static const uint32_t INT_CQ_ACTION0_INT_CQ_ACTION0_LEN = 64;
// proc/reg00000.H

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
// proc/reg00000.H

static const uint64_t INT_CQ_SWI_CMD1 = 0x02010820ull;
// proc/reg00000.H

static const uint64_t INT_PC_NXC_REGS_WATCH1_DATA1 = 0x02010aadull;
// proc/reg00000.H

static const uint64_t INT_PC_REGS_ERR0_CFG1 = 0x02010ac1ull;

static const uint32_t INT_PC_REGS_ERR0_CFG1_INT_PC_ERR0_CFG1_ERROR_CONFIG0 = 0;
static const uint32_t INT_PC_REGS_ERR0_CFG1_INT_PC_ERR0_CFG1_ERROR_CONFIG0_LEN = 64;
// proc/reg00000.H

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
// proc/reg00000.H

static const uint64_t INT_PC_REGS_ERR1_WOF = 0x02010acaull;

static const uint32_t INT_PC_REGS_ERR1_WOF_CMD_ARB_CONFIG_ERROR = 0;
static const uint32_t INT_PC_REGS_ERR1_WOF_CMD_ARB_PARITY_ERROR = 1;
static const uint32_t INT_PC_REGS_ERR1_WOF_CMD_ARB_NXC_RSP_ERROR = 2;
static const uint32_t INT_PC_REGS_ERR1_WOF_CRESP_PB_INV_PRIO = 3;
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
// proc/reg00000.H

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
// proc/reg00000.H

static const uint64_t INT_VC_EASC_FLUSH_CTRL = 0x02010960ull;

static const uint32_t INT_VC_EASC_FLUSH_CTRL_POLL_VALID = 0;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_RESERVED_1 = 1;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE = 2;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7 = 3;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7_LEN = 5;
// proc/reg00000.H

static const uint64_t INT_VC_ENDC_WATCH2_DATA3 = 0x020109b7ull;
// proc/reg00000.H

static const uint64_t INT_VC_ERR_CFG_G1R1 = 0x020109c9ull;

static const uint32_t INT_VC_ERR_CFG_G1R1_INT_VC_ERR_CFG_G1R1_ERROR_CONFIG = 0;
static const uint32_t INT_VC_ERR_CFG_G1R1_INT_VC_ERR_CFG_G1R1_ERROR_CONFIG_LEN = 48;
// proc/reg00000.H

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
// proc/reg00000.H

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
// proc/reg00000.H

static const uint64_t INT_VC_ESBC_SOFTWR_DATA = 0x02010952ull;

static const uint32_t INT_VC_ESBC_SOFTWR_DATA_INT_VC_ESBC_SOFTWR_DATA_PQ_STATE = 0;
static const uint32_t INT_VC_ESBC_SOFTWR_DATA_INT_VC_ESBC_SOFTWR_DATA_PQ_STATE_LEN = 64;
// proc/reg00000.H

static const uint64_t INT_VC_FATAL_ERR_G0 = 0x020109c4ull;

static const uint32_t INT_VC_FATAL_ERR_G0_INT_VC_FATAL_ERR_G0_ERROR = 0;
static const uint32_t INT_VC_FATAL_ERR_G0_INT_VC_FATAL_ERR_G0_ERROR_LEN = 64;
// proc/reg00000.H

static const uint64_t INT_VC_IQS_CFG = 0x02010920ull;

static const uint32_t INT_VC_IQS_CFG_FORCE_IN_ORDER = 0;
static const uint32_t INT_VC_IQS_CFG_FORCE_IN_ORDER_LEN = 8;
static const uint32_t INT_VC_IQS_CFG_QUEUE_DISABLE = 8;
static const uint32_t INT_VC_IQS_CFG_QUEUE_DISABLE_LEN = 8;
static const uint32_t INT_VC_IQS_CFG_RESERVED_16_23 = 16;
static const uint32_t INT_VC_IQS_CFG_RESERVED_16_23_LEN = 8;
static const uint32_t INT_VC_IQS_CFG_MATRIX_IDLE = 24;
static const uint32_t INT_VC_IQS_CFG_MATRIX_IDLE_LEN = 8;
// proc/reg00000.H

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
// proc/reg00000.H

static const uint64_t INT_VC_WOF_ERR_G2_DETAIL = 0x020109d3ull;

static const uint32_t INT_VC_WOF_ERR_G2_DETAIL_INT_VC_WOF_ERR_G2_DETAIL_ERROR = 0;
static const uint32_t INT_VC_WOF_ERR_G2_DETAIL_INT_VC_WOF_ERR_G2_DETAIL_ERROR_LEN = 64;
// proc/reg00000.H

static const uint64_t MCD_BANK0_BOSON = 0x03010817ull;

static const uint32_t MCD_BANK0_BOSON_VALID = 0;
static const uint32_t MCD_BANK0_BOSON_CHIP_CONTAINED_MODE = 5;
static const uint32_t MCD_BANK0_BOSON_SMF_ENABLE = 6;
static const uint32_t MCD_BANK0_BOSON_GRP_SIZE = 11;
static const uint32_t MCD_BANK0_BOSON_GRP_SIZE_LEN = 19;
static const uint32_t MCD_BANK0_BOSON_GRP_BASE = 33;
static const uint32_t MCD_BANK0_BOSON_GRP_BASE_LEN = 31;
// proc/reg00000.H

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
// proc/reg00000.H

static const uint64_t MCD_FIR_WOF_REG = 0x03010808ull;
// proc/reg00000.H

static const uint64_t NX_DBG_DMA_ENG_FIR_ACTION0 = 0x02011106ull;

static const uint32_t NX_DBG_DMA_ENG_FIR_ACTION0_NX_DMA_ENG_FIR_ACTION0_BITS = 0;
static const uint32_t NX_DBG_DMA_ENG_FIR_ACTION0_NX_DMA_ENG_FIR_ACTION0_BITS_LEN = 48;
// proc/reg00000.H

static const uint64_t NX_DMA_SU_CH0_ABORT_CSB = 0x02011043ull;
// proc/reg00000.H

static const uint64_t NX_DMA_SU_CH1_ABORT_CSB = 0x02011045ull;
// proc/reg00000.H

static const uint64_t NX_DMA_SU_STATUS = 0x02011040ull;

static const uint32_t NX_DMA_SU_STATUS_HMI_ACTIVE = 54;
static const uint32_t NX_DMA_SU_STATUS_PBI_IDLE = 55;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH0_IDLE = 56;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH1_IDLE = 57;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH2_IDLE = 58;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH3_IDLE = 59;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH4_IDLE = 60;
// proc/reg00000.H

static const uint64_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_CNTL = 0x020110ceull;

static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET = 4;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN = 8;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_CNTL_QUEUED = 15;
static const uint32_t NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN = 9;
// proc/reg00000.H

static const uint64_t NX_PBI_UMAC_SEND_WC_BASE_ADDR = 0x020110d2ull;

static const uint32_t NX_PBI_UMAC_SEND_WC_BASE_ADDR_SEND_WC_BAR = 8;
static const uint32_t NX_PBI_UMAC_SEND_WC_BASE_ADDR_SEND_WC_BAR_LEN = 33;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB = 0x0301121cull;

static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TTYPE_EN1 = 0;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TTYPE_EN1_LEN = 7;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TTYPE_MASK_EN1 = 7;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TTYPE_MASK_EN1_LEN = 7;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TSIZE_EN1 = 14;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TSIZE_EN1_LEN = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TSIZE_MASK_EN1 = 22;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TSIZE_MASK_EN1_LEN = 8;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TTAG_EN1 = 30;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TTAG_EN1_LEN = 10;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TTAG_MASK_EN1 = 40;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_TTAG_MASK_EN1_LEN = 10;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_CRESP_EN1 = 50;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_CRESP_EN1_LEN = 5;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_CRESP_MASK_EN1 = 55;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_CRESP_MASK_EN1_LEN = 5;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_CRESP_POLARITY_EN1 = 60;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_SCOPE_EN1 = 61;
static const uint32_t PB_COM_SCOM_EN1_STATION_EVENT_COMPB_SCOPE_EN1_LEN = 3;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EN3_STATION_FIR_ACTION0_REG = 0x03011286ull;

static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0 = 0;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0_LEN = 22;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EN3_STATION_FIR_ACTION1_REG = 0x03011287ull;

static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1 = 0;
static const uint32_t PB_COM_SCOM_EN3_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1_LEN = 22;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE = 0x030112aaull;

static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_0_EN3 = 0;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_0_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_1_EN3 = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_1_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_2_EN3 = 16;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_2_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_3_EN3 = 24;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_3_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_4_EN3 = 32;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_4_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_5_EN3 = 40;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_5_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_6_EN3 = 48;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_6_EN3_LEN = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_7_EN3 = 56;
static const uint32_t PB_COM_SCOM_EN3_STATION_GP_CMD_RATE_7_EN3_LEN = 8;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT = 0x0301128dull;

static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_0_EN_NEXT_EN3 = 0;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_1_EN_NEXT_EN3 = 1;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_2_EN_NEXT_EN3 = 2;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_3_EN_NEXT_EN3 = 3;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_4_EN_NEXT_EN3 = 4;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_5_EN_NEXT_EN3 = 5;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_6_EN_NEXT_EN3 = 6;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_7_EN_NEXT_EN3 = 7;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_0_ADDR_DIS_NEXT_EN3 = 8;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_1_ADDR_DIS_NEXT_EN3 = 9;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_2_ADDR_DIS_NEXT_EN3 = 10;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_3_ADDR_DIS_NEXT_EN3 = 11;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_4_ADDR_DIS_NEXT_EN3 = 12;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_5_ADDR_DIS_NEXT_EN3 = 13;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_6_ADDR_DIS_NEXT_EN3 = 14;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_7_ADDR_DIS_NEXT_EN3 = 15;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_0_MODE_NEXT_EN3 = 16;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_0_ID_NEXT_EN3 = 17;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_0_ID_NEXT_EN3_LEN = 3;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_1_MODE_NEXT_EN3 = 20;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_1_ID_NEXT_EN3 = 21;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_1_ID_NEXT_EN3_LEN = 3;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_2_MODE_NEXT_EN3 = 24;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_2_ID_NEXT_EN3 = 25;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_2_ID_NEXT_EN3_LEN = 3;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_3_MODE_NEXT_EN3 = 28;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_3_ID_NEXT_EN3 = 29;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_3_ID_NEXT_EN3_LEN = 3;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_4_MODE_NEXT_EN3 = 32;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_4_ID_NEXT_EN3 = 33;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_4_ID_NEXT_EN3_LEN = 3;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_5_MODE_NEXT_EN3 = 36;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_5_ID_NEXT_EN3 = 37;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_5_ID_NEXT_EN3_LEN = 3;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_6_MODE_NEXT_EN3 = 40;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_6_ID_NEXT_EN3 = 41;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_6_ID_NEXT_EN3_LEN = 3;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_7_MODE_NEXT_EN3 = 44;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_7_ID_NEXT_EN3 = 45;
static const uint32_t PB_COM_SCOM_EN3_STATION_HP_MODE2_NEXT_7_ID_NEXT_EN3_LEN = 3;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EQ0_STATION_FIR_REG_RW = 0x03011000ull;
static const uint64_t PB_COM_SCOM_EQ0_STATION_FIR_REG_WO_AND = 0x03011001ull;
static const uint64_t PB_COM_SCOM_EQ0_STATION_FIR_REG_WO_OR = 0x03011002ull;

static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_PROTOCOL_ERROR = 0;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_OVERFLOW_ERROR = 1;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_HW_PARITY_ERROR = 2;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_FIR_SPARE_3 = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_COHERENCY_ERROR = 4;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_CRESP_ADDR_ERROR = 5;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_CRESP_ERROR = 6;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_HANG_RECOVERY_LIMIT_ERROR = 7;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_FIR_SPARE_8 = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_HANG_RECOVERY_GTE_LEVEL1 = 9;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_FORCE_MP_IPL = 10;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_PB_CMD_SNOOPER_ERROR = 11;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_DATA_OVERFLOW_ERROR = 12;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_DATA_PROTOCOL_ERROR = 13;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_DATA_ROUTE_ERROR = 14;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_FIR_SPARE_15 = 15;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK0_PROTOCOL_ERROR = 16;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK0_OVERFLOW_ERROR = 17;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK0_HW_PARITY_ERROR = 18;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK1_PROTOCOL_ERROR = 19;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK1_OVERFLOW_ERROR = 20;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK1_HW_PARITY_ERROR = 21;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE = 0x0301102bull;

static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0 = 0;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0 = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0 = 16;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0 = 24;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0 = 32;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0 = 40;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0 = 48;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0 = 56;
static const uint32_t PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0_LEN = 8;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EQ1_STATION_FIR_ACTION0_REG = 0x03011046ull;

static const uint32_t PB_COM_SCOM_EQ1_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0 = 0;
static const uint32_t PB_COM_SCOM_EQ1_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0_LEN = 22;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EQ1_STATION_FIR_ACTION1_REG = 0x03011047ull;

static const uint32_t PB_COM_SCOM_EQ1_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1 = 0;
static const uint32_t PB_COM_SCOM_EQ1_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1_LEN = 22;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT = 0x0301108bull;

static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_EQ2 = 0;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_EQ2 = 1;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_EQ2 = 2;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_EQ2 = 3;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_EQ2 = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_EQ2 = 16;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_EQ2 = 17;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_EQ2 = 18;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_EQ2 = 24;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_EQ2_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_EQ2 = 32;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_EQ2 = 33;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_EQ2 = 34;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_EQ2 = 40;
static const uint32_t PB_COM_SCOM_EQ2_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_EQ2_LEN = 8;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT = 0x0301118dull;

static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_0_EN_NEXT_EQ6 = 0;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_1_EN_NEXT_EQ6 = 1;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_2_EN_NEXT_EQ6 = 2;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_3_EN_NEXT_EQ6 = 3;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_4_EN_NEXT_EQ6 = 4;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_5_EN_NEXT_EQ6 = 5;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_6_EN_NEXT_EQ6 = 6;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_7_EN_NEXT_EQ6 = 7;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_0_ADDR_DIS_NEXT_EQ6 = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_1_ADDR_DIS_NEXT_EQ6 = 9;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_2_ADDR_DIS_NEXT_EQ6 = 10;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_3_ADDR_DIS_NEXT_EQ6 = 11;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_4_ADDR_DIS_NEXT_EQ6 = 12;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_5_ADDR_DIS_NEXT_EQ6 = 13;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_6_ADDR_DIS_NEXT_EQ6 = 14;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_7_ADDR_DIS_NEXT_EQ6 = 15;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_0_MODE_NEXT_EQ6 = 16;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_0_ID_NEXT_EQ6 = 17;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_0_ID_NEXT_EQ6_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_1_MODE_NEXT_EQ6 = 20;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_1_ID_NEXT_EQ6 = 21;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_1_ID_NEXT_EQ6_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_2_MODE_NEXT_EQ6 = 24;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_2_ID_NEXT_EQ6 = 25;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_2_ID_NEXT_EQ6_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_3_MODE_NEXT_EQ6 = 28;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_3_ID_NEXT_EQ6 = 29;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_3_ID_NEXT_EQ6_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_4_MODE_NEXT_EQ6 = 32;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_4_ID_NEXT_EQ6 = 33;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_4_ID_NEXT_EQ6_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_5_MODE_NEXT_EQ6 = 36;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_5_ID_NEXT_EQ6 = 37;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_5_ID_NEXT_EQ6_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_6_MODE_NEXT_EQ6 = 40;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_6_ID_NEXT_EQ6 = 41;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_6_ID_NEXT_EQ6_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_7_MODE_NEXT_EQ6 = 44;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_7_ID_NEXT_EQ6 = 45;
static const uint32_t PB_COM_SCOM_EQ6_STATION_HP_MODE2_NEXT_7_ID_NEXT_EQ6_LEN = 3;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE = 0x030111abull;

static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_0_EQ6 = 0;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_0_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_1_EQ6 = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_1_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_2_EQ6 = 16;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_2_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_3_EQ6 = 24;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_3_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_4_EQ6 = 32;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_4_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_5_EQ6 = 40;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_5_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_6_EQ6 = 48;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_6_EQ6_LEN = 8;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_7_EQ6 = 56;
static const uint32_t PB_COM_SCOM_EQ6_STATION_SP_CMD_RATE_7_EQ6_LEN = 8;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_RW = 0x030111c3ull;
static const uint64_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_WO_AND = 0x030111c4ull;
static const uint64_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_WO_OR = 0x030111c5ull;

static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK = 0;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK = 1;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK = 2;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK = 3;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK = 4;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK = 5;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_CRESP_ERROR_MASK = 6;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK = 7;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK = 8;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK = 9;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK = 10;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK = 11;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK = 12;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK = 13;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK = 14;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_FIR_SPARE_15_MASK = 15;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK = 16;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK = 17;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK = 18;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK = 19;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK = 20;
static const uint32_t PB_COM_SCOM_EQ7_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK = 21;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_ES2_EXTFIR_ACTION0_REG = 0x03011374ull;

static const uint32_t PB_COM_SCOM_ES2_EXTFIR_ACTION0_REG_EXTFIR_ACTION0 = 0;
static const uint32_t PB_COM_SCOM_ES2_EXTFIR_ACTION0_REG_EXTFIR_ACTION0_LEN = 8;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_ES2_EXTFIR_ACTION1_REG = 0x03011375ull;

static const uint32_t PB_COM_SCOM_ES2_EXTFIR_ACTION1_REG_EXTFIR_ACTION1 = 0;
static const uint32_t PB_COM_SCOM_ES2_EXTFIR_ACTION1_REG_EXTFIR_ACTION1_LEN = 8;
// proc/reg00000.H

static const uint64_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR = 0x0301134cull;

static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_MASTER_CHIP_CURR_ES2 = 0;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_TM_MASTER_CURR_ES2 = 1;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES2 = 2;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES2 = 3;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_NP_CMD_RATE_CURR_ES2 = 8;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_NP_CMD_RATE_CURR_ES2_LEN = 8;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_G_AGGREGATE_CURR_ES2 = 16;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES2 = 17;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES2 = 18;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_MIN_G_CMD_RATE_CURR_ES2 = 24;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_MIN_G_CMD_RATE_CURR_ES2_LEN = 8;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_R_AGGREGATE_CURR_ES2 = 32;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES2 = 33;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES2 = 34;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_MIN_R_CMD_RATE_CURR_ES2 = 40;
static const uint32_t PB_COM_SCOM_ES2_STATION_HP_MODE1_CURR_MIN_R_CMD_RATE_CURR_ES2_LEN = 8;
// proc/reg00000.H

static const uint64_t PB_PTLSCOM10_PMU1_CNPM_COUNTER = 0x10011822ull;
// proc/reg00000.H

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
// proc/reg00000.H

static const uint64_t PB_PTLSCOM23_MAILBOX_10_REG = 0x11011832ull;
// proc/reg00000.H

static const uint64_t PB_PTLSCOM23_MAILBOX_11_REG = 0x11011833ull;
// proc/reg00000.H

static const uint64_t PB_PTLSCOM23_PMU3_CNPM_COUNTER = 0x11011824ull;
// proc/reg00000.H

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
// proc/reg00000.H

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
// proc/reg00000.H

static const uint64_t PB_PTLSCOM67_MAILBOX_30_REG = 0x13011836ull;
// proc/reg00001.H

static const uint64_t PB_PTLSCOM67_MAILBOX_31_REG = 0x13011837ull;
// proc/reg00001.H

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
// proc/reg00001.H

static const uint64_t TP_TCN0_N0_CPLT_STAT0 = 0x02000100ull;

static const uint32_t TP_TCN0_N0_CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_10I = 10;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_11I = 11;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_12I = 12;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_13I = 13;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_14I = 14;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_15I = 15;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_16I = 16;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_17I = 17;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_18I = 18;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_19I = 19;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_20I = 20;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_21I = 21;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_22I = 22;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_23I = 23;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_24I = 24;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_25I = 25;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_26I = 26;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_27I = 27;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_28I = 28;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_29I = 29;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_30I = 30;
static const uint32_t TP_TCN0_N0_CPLT_STAT0_FREE_USAGE_31I = 31;
// proc/reg00001.H

static const uint64_t TP_TCN0_N0_EPS_DBG_MODE_REG = 0x020107c0ull;

static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION = 11;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 12;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TP_TCN0_N0_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// proc/reg00001.H

static const uint64_t TP_TCN0_N0_EPS_DBG_DEBUG_TRACE_CONTROL = 0x020107d0ull;
// proc/reg00001.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_CONTROL_REG = 0x02050012ull;
// proc/reg00001.H

static const uint64_t TP_TCN0_N0_OPCG_REG2 = 0x02030004ull;

static const uint32_t TP_TCN0_N0_OPCG_REG2_OPCG_GO2 = 0;
static const uint32_t TP_TCN0_N0_OPCG_REG2_PRPG_WEIGHTING = 1;
static const uint32_t TP_TCN0_N0_OPCG_REG2_PRPG_WEIGHTING_LEN = 3;
static const uint32_t TP_TCN0_N0_OPCG_REG2_PRPG_VALUE = 4;
static const uint32_t TP_TCN0_N0_OPCG_REG2_PRPG_VALUE_LEN = 12;
static const uint32_t TP_TCN0_N0_OPCG_REG2_PRPG_A_VAL = 16;
static const uint32_t TP_TCN0_N0_OPCG_REG2_PRPG_A_VAL_LEN = 12;
static const uint32_t TP_TCN0_N0_OPCG_REG2_PRPG_B_VAL = 28;
static const uint32_t TP_TCN0_N0_OPCG_REG2_PRPG_B_VAL_LEN = 12;
static const uint32_t TP_TCN0_N0_OPCG_REG2_PRPG_MODE = 40;
static const uint32_t TP_TCN0_N0_OPCG_REG2_SM_LBIST_CNTRL = 48;
static const uint32_t TP_TCN0_N0_OPCG_REG2_SM_LBIST_CNTRL_LEN = 16;
// proc/reg00001.H

static const uint64_t TP_TCN0_N0_SCAN_CAPTUREDR = 0x0203c000ull;
// proc/reg00001.H

static const uint64_t TP_TCN0_N0_TRA0_TR0_CONFIG_3 = 0x02010406ull;

static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_3_D_LEN = 24;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x03050014ull;

static const uint32_t TP_TCN1_N1_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_ERROR_STATUS = 0x0303000full;

static const uint32_t TP_TCN1_N1_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR = 0;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR = 1;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR = 2;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR = 3;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR = 4;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR = 5;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR = 6;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR = 7;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR = 8;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR = 9;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR = 10;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_SCAN_COLLISION_ERR = 11;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR = 12;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_OPCG_TRIGGER_ERR = 13;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR = 14;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR = 15;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR = 16;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR = 17;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR = 18;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR = 19;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR = 20;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR = 21;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_CLKCMD_REQUEST_ERR = 22;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_CBS_PROTOCOL_ERR = 23;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_VITL_ALIGN_ERR = 24;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_UNIT_SYNC_LVL_ERR = 25;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR = 26;
static const uint32_t TP_TCN1_N1_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR = 27;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_SCAN_LONG_ROTATE = 0x03039000ull;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_SPATTN = 0x03040002ull;

static const uint32_t TP_TCN1_N1_SPATTN_ANY_SPATTN = 0;
static const uint32_t TP_TCN1_N1_SPATTN_RESERVED1S = 1;
static const uint32_t TP_TCN1_N1_SPATTN_RESERVED2S = 2;
static const uint32_t TP_TCN1_N1_SPATTN_RESERVED3S = 3;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_PERV = 4;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN05 = 5;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN06 = 6;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN07 = 7;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN08 = 8;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN09 = 9;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN10 = 10;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN11 = 11;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN12 = 12;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN13 = 13;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN14 = 14;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN15 = 15;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN16 = 16;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN17 = 17;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN18 = 18;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN19 = 19;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN20 = 20;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN21 = 21;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN22 = 22;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN23 = 23;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN24 = 24;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN25 = 25;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN26 = 26;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN27 = 27;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN28 = 28;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN29 = 29;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN30 = 30;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN31 = 31;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN32 = 32;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN33 = 33;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN34 = 34;
static const uint32_t TP_TCN1_N1_SPATTN_SPATTN_IN35 = 35;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_TRA0_TR1_CONFIG_2 = 0x03010445ull;

static const uint32_t TP_TCN1_N1_TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCN1_N1_TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCN1_N1_TRA0_TR1_CONFIG_2_B_LEN = 24;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_TRA1_TR0_CONFIG_4 = 0x03010487ull;

static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCN1_N1_TRA1_TR0_CONFIG_4_B_LEN = 24;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_TRA2_TR0_CONFIG_3 = 0x03010506ull;

static const uint32_t TP_TCN1_N1_TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCN1_N1_TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCN1_N1_TRA2_TR0_CONFIG_3_D_LEN = 24;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_TRA3_TR1_CONFIG_5 = 0x030105c8ull;

static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCN1_N1_TRA3_TR1_CONFIG_5_D_LEN = 24;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_TRA4_TR1_CONFIG_4 = 0x03010647ull;

static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_4_B_LEN = 24;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_TRA5_TR0_CONFIG_2 = 0x03010685ull;

static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_2_B_LEN = 24;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG = 0x030106c1ull;

static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCN1_N1_TRA5_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_TRA6_TR0_TRACE_HI_DATA_REG = 0x03010700ull;

static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// proc/reg00001.H

static const uint64_t TP_TCN1_N1_TRA6_TR0_CONFIG_5 = 0x03010708ull;

static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCN1_N1_TRA6_TR0_CONFIG_5_D_LEN = 24;
// proc/reg00001.H

static const uint64_t TP_TPBR_AD_TOD_CMD_REG = 0x0009002aull;

static const uint32_t TP_TPBR_AD_TOD_CMD_REG_TOD_CMD_REG_ADR = 30;
static const uint32_t TP_TPBR_AD_TOD_CMD_REG_TOD_CMD_REG_ADR_LEN = 31;
// proc/reg00001.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAERRRPT1 = 0x01010ccdull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_RESERVED_0_5 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_RESERVED_0_5_LEN = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCDE_SETUP_ERR = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCDE_SETUP_ERR_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_SETUP_ERR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_SETUP_ERR_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_OCI_DATAERR = 10;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_OCI_DATAERR_LEN = 2;
// proc/reg00001.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAOCR1 = 0x0006801bull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAOCR1_PBAOCR1_COUNT = 44;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCR1_PBAOCR1_COUNT_LEN = 20;
// proc/reg00001.H

static const uint64_t TP_TPBR_PBA_PBAO_PBASLVCTL1 = 0x00068005ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_ENABLE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_MID_MATCH_VALUE = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_MID_MATCH_VALUE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_RESERVED_4 = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_MID_CARE_MASK = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_MID_CARE_MASK_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WRITE_TTYPE = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WRITE_TTYPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_RESERVED_11_14 = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_RESERVED_11_14_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_READ_TTYPE = 15;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_READ_PREFETCH_CTL = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_READ_PREFETCH_CTL_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_INVALIDATE_CTL = 18;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_W = 19;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_A = 20;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_B = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_C = 22;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_RESERVED_23 = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_DIS_WRITE_GATHER = 24;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WR_GATHER_TIMEOUT = 25;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WR_GATHER_TIMEOUT_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WRITE_TSIZE = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WRITE_TSIZE_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_EXTADDR = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_EXTADDR_LEN = 14;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_RESERVED_50 = 50;
// proc/reg00001.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXISHINC0 = 0x00068038ull;
// proc/reg00001.H

static const uint64_t TP_TPBR_PSI_WRAP_TX_DF_FSM_REG = 0x03011c06ull;
// proc/reg00001.H

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
// proc/reg00001.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_4 = 0x020f0004ull;

static const uint32_t TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_HEARTBEAT_REG = 0x010f0018ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_4 = 0x010f0004ull;

static const uint32_t TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR29 = 0x0006004dull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29_LEN = 32;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR9 = 0x00060049ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR9_OCB_OCI_GPEXIVDR8_GPR9 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR9_OCB_OCI_GPEXIVDR8_GPR9_LEN = 32;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXILR = 0x00060031ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN = 32;
// proc/reg00001.H

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
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR8 = 0x00060084ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR8_8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR8_8_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR8_9 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR8_9_LEN = 32;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGINF = 0x0006201full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGINF_SRR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGINF_SRR0_LEN = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGINF_LR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGINF_LR_LEN = 32;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR2 = 0x00062042ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR2_OCB_OCI_GPEXIVDR2_GPR2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR2_OCB_OCI_GPEXIVDR2_GPR2_LEN = 32;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR28 = 0x0006204cull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28_LEN = 32;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDRX = 0x00062085ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDRX_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDRX_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDRX_3 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDRX_3_LEN = 32;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL = 0x0006402full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_ERR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_POPULATE_PENDING = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_VALID = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_VALID_LEN = 4;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU = 0x0006402eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN = 27;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR6 = 0x00064046ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR6_OCB_OCI_GPEXIVDR6_GPR6 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR6_OCB_OCI_GPEXIVDR6_GPR6_LEN = 32;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMRA = 0x00064011ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR_LEN = 3;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR28 = 0x00064086ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR28_8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR28_8_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR28_9 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR28_9_LEN = 32;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL = 0x00066000ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_WATCHDOG_SEL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_WATCHDOG_SEL_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_FIT_SEL = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_FIT_SEL_LEN = 4;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_DERP0 = 0x0006c180ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP0_DEND = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP0_DEND_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP0_SOR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP0_SOR_LEN = 32;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1 = 0x0006c720ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_FRAME_SIZE_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_FRAME_SIZE_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_OUT_COUNT1_1 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_OUT_COUNT1_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_DELAY1_1 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_DELAY1_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_COUNT1_1 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_COUNT1_1_LEN = 6;
// proc/reg00001.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSES2 = 0x0006c226ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES2_SH_READ_UNDERFLOW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES2_LL_WRITE_OVERFLOW = 1;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCISR1 = 0x0006c071ull;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ODISR1 = 0x0006c073ull;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_RW = 0x0006c02cull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_WO_CLEAR = 0x0006c02dull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_WO_OR = 0x0006c02eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_OCB_OCI_OIEPR1_INTERRUPT_EDGE_POL_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_OCB_OCI_OIEPR1_INTERRUPT_EDGE_POL_1_LEN = 32;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_RW = 0x0006c024ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_WO_CLEAR = 0x0006c025ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_WO_OR = 0x0006c026ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_OCB_OCI_OIMR1_INTERRUPT_MASK_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_OCB_OCI_OIMR1_INTERRUPT_MASK_1_LEN = 32;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OINKR1 = 0x0006c030ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OINKR1_OCB_OCI_OINKR1_INTERRUPT_INPUT_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OINKR1_OCB_OCI_OINKR1_INTERRUPT_INPUT_1_LEN = 32;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_RW = 0x0006c050ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_WO_CLEAR = 0x0006c051ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_WO_OR = 0x0006c052ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_OCB_OCI_OIRR1A_INTERRUPT_ROUTE_1_A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_OCB_OCI_OIRR1A_INTERRUPT_ROUTE_1_A_LEN = 32;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q7RR = 0x0006c507ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q7RR_OCB_OCI_OPIT0Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q7RR_OCB_OCI_OPIT0Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q5 = 0x0006c40dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q5_OCB_OCI_OPIT1Q5RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q5_OCB_OCI_OPIT1Q5RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q7RR = 0x0006c50full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q7RR_OCB_OCI_OPIT1Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q7RR_OCB_OCI_OPIT1Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1 = 0x0006c411ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q7RR = 0x0006c517ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q7RR_OCB_OCI_OPIT2Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q7RR_OCB_OCI_OPIT2Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7RR = 0x0006c51full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7RR_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7RR_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q7RR = 0x0006c527ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q7RR_OCB_OCI_OPIT4Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q7RR_OCB_OCI_OPIT4Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7 = 0x0006c42full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7_OCB_OCI_OPIT5Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7_OCB_OCI_OPIT5Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7RR = 0x0006c52full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7RR_OCB_OCI_OPIT5Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q7RR_OCB_OCI_OPIT5Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q3 = 0x0006c433ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q3_OCB_OCI_OPIT6Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q3_OCB_OCI_OPIT6Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7RR = 0x0006c537ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7RR_OCB_OCI_OPIT6Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q7RR_OCB_OCI_OPIT6Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q7RR = 0x0006c53full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q7RR_OCB_OCI_OPIT7Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q7RR_OCB_OCI_OPIT7Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0RR = 0x0006c540ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C0RR_PAYLOAD_LEN = 17;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29 = 0x0006c45dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29_PAYLOAD_LEN = 17;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7 = 0x0006c447ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C7_PAYLOAD_LEN = 17;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0RR = 0x0006c560ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C0RR_PAYLOAD_LEN = 17;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18 = 0x0006c472ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18_PAYLOAD_LEN = 17;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18RR = 0x0006c572ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C18RR_PAYLOAD_LEN = 17;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30 = 0x0006c47eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C30_PAYLOAD_LEN = 17;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9 = 0x0006c469ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C9_PAYLOAD_LEN = 17;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_RO = 0x0006c694ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_WO_CLEAR = 0x0006c695ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITFPRD_7 = 7;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1 = 0x0006c841ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1__BRIDGE_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1__DEVICE = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1__CPOL = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1__CPHA = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1__CLOCK_DIVIDER = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1__CLOCK_DIVIDER_LEN = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_CR1_RESERVED_2 = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_CR1_RESERVED_2_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1__NR_OF_FRAMES = 17;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT = 0x0006c843ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_P2S_ONGOING = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_RESERVED_1_4 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_RESERVED_1_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_P2S_WRITE_WHILE_BRIDGE_BUSY_ERR = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_P2S_FSM_ERR = 7;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICDCM1 = 0x0006c785ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICDCM1_OCB_OCI_WOFICDCM1_DCM_MESSAGE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICDCM1_OCB_OCI_WOFICDCM1_DCM_MESSAGE_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG10 = 0x0000800aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG10_REGISTER10 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG10_REGISTER10_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG110 = 0x0000806eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG110_REGISTER110 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG110_REGISTER110_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG127 = 0x0000807full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG127_REGISTER127 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG127_REGISTER127_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG27 = 0x0000801bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG27_REGISTER27 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG27_REGISTER27_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG38 = 0x00008026ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG38_REGISTER38 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG38_REGISTER38_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG4 = 0x00008004ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG4_REGISTER4 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG4_REGISTER4_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG46 = 0x0000802eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG46_REGISTER46 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG46_REGISTER46_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG59 = 0x0000803bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG59_REGISTER59 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG59_REGISTER59_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG71 = 0x00008047ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG71_REGISTER71 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG71_REGISTER71_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG84 = 0x00008054ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG84_REGISTER84 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG84_REGISTER84_LEN = 64;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_TPC_CLOCK_STAT_ARY = 0x0103000aull;

static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t TP_TPCHIP_TPC_CLOCK_STAT_ARY_UNIT14_ARY = 18;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_TPC_CPLT_CONF1_RW = 0x01000009ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CONF1_WO_CLEAR = 0x01000029ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CONF1_WO_OR = 0x01000019ull;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL1_RW = 0x01000001ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR = 0x01000021ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR = 0x01000011ull;

static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_VITL_FENCE_DC = 3;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION0_FENCE_DC = 4;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION1_FENCE_DC = 5;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION2_FENCE_DC = 6;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION3_FENCE_DC = 7;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION4_FENCE_DC = 8;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION5_FENCE_DC = 9;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION6_FENCE_DC = 10;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION7_FENCE_DC = 11;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION8_FENCE_DC = 12;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION9_FENCE_DC = 13;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION10_FENCE_DC = 14;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION11_FENCE_DC = 15;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION12_FENCE_DC = 16;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION13_FENCE_DC = 17;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_REGION14_FENCE_DC = 18;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2 = 0x01040109ull;

static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_00 = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_01 = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_02 = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_03 = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_04 = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_05 = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_06 = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_07 = 7;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_08 = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_09 = 9;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_10 = 10;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_11 = 11;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_12 = 12;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_13 = 13;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_14 = 14;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_15 = 15;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_16 = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_17 = 17;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_18 = 18;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_19 = 19;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_20 = 20;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_21 = 21;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_22 = 22;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_23 = 23;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_24 = 24;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_25 = 25;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_26 = 26;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_27 = 27;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_28 = 28;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_29 = 29;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_30 = 30;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_31 = 31;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_32 = 32;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_33 = 33;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_34 = 34;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_35 = 35;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_36 = 36;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_37 = 37;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_38 = 38;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_39 = 39;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_40 = 40;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_41 = 41;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_42 = 42;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_43 = 43;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_44 = 44;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_45 = 45;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_46 = 46;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_47 = 47;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_48 = 48;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_49 = 49;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_50 = 50;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_51 = 51;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_52 = 52;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_53 = 53;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_54 = 54;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_55 = 55;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_56 = 56;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_57 = 57;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_58 = 58;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_59 = 59;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_60 = 60;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_61 = 61;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_62 = 62;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION2_63 = 63;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_TPC_EPS_THERM_WSUB_INJECT_REG = 0x01050011ull;

static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_INJECT_REG_TRIP = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_INJECT_REG_TRIP_LEN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_INJECT_REG_MODE = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_THERM_WSUB_INJECT_REG_MODE_LEN = 2;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_TPC_PCB_OPCG_GO = 0x01030020ull;

static const uint32_t TP_TPCHIP_TPC_PCB_OPCG_GO_PCB_OPCGGO = 0;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_4 = 0x01010447ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR1_CONFIG_4_B_LEN = 24;
// proc/reg00002.H

static const uint64_t TP_TPCHIP_TPC_XSTOP4 = 0x01030014ull;

static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_MASK_B = 0;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_ALIGNED_XSTOP4 = 1;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_TRIGGER_OPCG_ON_XSTOP4 = 2;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_WAIT_ALLWAYS = 3;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_PERV = 4;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT1 = 5;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT2 = 6;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT3 = 7;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT4 = 8;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT5 = 9;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT6 = 10;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT7 = 11;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT8 = 12;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT9 = 13;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT10 = 14;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT11 = 15;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT12 = 16;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT13 = 17;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_UNIT14 = 18;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_WAIT_CYCLES = 48;
static const uint32_t TP_TPCHIP_TPC_XSTOP4_XSTOP4_WAIT_CYCLES_LEN = 12;
// proc/reg00002.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_1_FSI = 0x00001001ull;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_1_FSI_BYTE = 0x00001004ull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_1_DATA_REG_1 = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_1_DATA_REG_1_LEN = 32;
// proc/reg00002.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS = 0x00050001ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI = 0x00002801ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE = 0x00002804ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN = 16;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI = 0x00002804ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE = 0x00002810ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO = 0x00050004ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_TEST_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CARD_TEST_BSC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_VDN_GPOOD = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_IN_ENA = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CHIP_MASTER = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_SMD = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_JTAG_TMS = 6;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_FSI = 0x00002802ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_FSI_BYTE = 0x00002808ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_RO = 0x00050002ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_SIGNATURE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_SIGNATURE_LEN = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TRANS_DELAY = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TRANS_DELAY_LEN = 10;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_11_FSI = 0x0000288bull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_11_FSI_BYTE = 0x00002a2cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_11_RW = 0x0005008bull;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_5_FSI = 0x00002885ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_5_FSI_BYTE = 0x00002a14ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_5_RW = 0x00050085ull;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_3_FSI = 0x000028c3ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_3_FSI_BYTE = 0x00002b0cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_3_RW = 0x000500c3ull;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_15_FSI = 0x0000290full;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_15_FSI_BYTE = 0x00002c3cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_15_RW = 0x0005010full;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_9_FSI = 0x00002909ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_9_FSI_BYTE = 0x00002c24ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_9_RW = 0x00050109ull;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI = 0x0000291aull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE = 0x00002c68ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW = 0x0005011aull;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL2_FSI = 0x00002942ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL2_FSI_BYTE = 0x00002d08ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL2_RO = 0x00050142ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL2_RCS_EVENTLOG_2 = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL2_RCS_EVENTLOG_2_LEN = 32;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_FSI = 0x00002931ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_FSI_BYTE = 0x00002cc4ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_WO_CLEAR = 0x00050131ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE0_SEL_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE0_SEL_DC_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE1_SEL_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE1_SEL_DC_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE_MESH_SEL_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE_DRV_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE_HIGHDRIVE_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_FSI_PROBE_SEL_DC = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_FSI_PROBE_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_AN_PROBE_DRVR_MCPRECOMP0_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_AN_PROBE_DRVR_MCPRECOMP1_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_AN_PROBE_DRVR_MCPRECOMP2_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_IDDQ_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_SPARE_RI_CONTROL = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_SPARE_DI_CONTROL = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_RI_DC_B = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_DI1_DC_B = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_DI2_DC_B = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_22_SPARE_TEST = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_23_SPARE_TEST = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_TEST_BURNIN_MODE_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TPFSI_ARRAY_SET_VBL_TO_VDD_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_26_SPARE = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_GLBCK_MEM_TESTCLK_SEL_DC = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_28_SPARE_TEST_CONTROL = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_29_SPARE_TEST_CONTROL = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_30_SPARE_TEST_CONTROL = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_31_SPARE_TEST_CONTROL = 31;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI = 0x00002816ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE = 0x00002858ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW = 0x00050016ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_PLLREFCLK_RCVR_TERM_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_PLLREFCLK_RCVR_TERM_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_PCIREFCLK_RCVR_TERM_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_PCIREFCLK_RCVR_TERM_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_4 = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_5 = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_6_31 = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_6_31_LEN = 26;
// proc/reg00003.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS2LTH_FSI = 0x0000281eull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS2LTH_FSI_BYTE = 0x00002878ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS2LTH_RO = 0x0005001eull;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_REQ_RESET_FSI = 0x00002423ull;
static const uint32_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_REQ_RESET_FSI_BYTE = 0x0000248cull;
// proc/reg00003.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_RESET = 0x000b0004ull;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI = 0x00000c1full;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE = 0x00000c7cull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0 = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0_LEN = 32;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP3_FSI0 = 0x0000305cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP3_SCOMFSI0 = 0x00000c17ull;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP0_FSI0 = 0x00003018ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP0_RO = 0x00000c06ull;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP2_FSI0 = 0x000030d8ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP2_RO = 0x00000c36ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP2_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP2_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP2_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP2_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP2_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP2_2_LEN = 3;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP1_FSI0 = 0x000034d4ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP1_WO = 0x00000d35ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP1_GENERAL_RESET_1 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP1_ERROR_RESET_1 = 1;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP2_FSI0 = 0x00003438ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP2_SCOMFSI0 = 0x00000d0eull;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCRSIS0 = 0x00000860ull;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SDATA = 0x00000830ull;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_LLMOD = 0x00000900ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_LLMOD_FSI_B_ASYNC_MODE = 31;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESB0_FSI1 = 0x000031d0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESB0_WO = 0x00000c74ull;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP7_FSI1 = 0x000030ecull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP7_WO = 0x00000c3bull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP7_GENERAL_RESET_7 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP7_ERROR_RESET_7 = 1;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSENP0_FSI1 = 0x00003018ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSENP0_WO_OR = 0x00000c06ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSENP0_0_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSENP0_1_ENABLE = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSENP0_2_ENABLE = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSENP0_3_ENABLE = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSENP0_4_ENABLE = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSENP0_5_ENABLE = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSENP0_6_ENABLE = 6;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSENP0_7_ENABLE = 7;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP4_FSI1 = 0x00003040ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP4_SCOMFSI1 = 0x00000c10ull;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCISM = 0x00000814ull;
// proc/reg00003.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SISS = 0x00000810ull;
// proc/reg00003.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG = 0x00070005ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN = 64;
// proc/reg00003.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1 = 0x00070022ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_CONFIG1_Q = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_CONFIG1_Q_LEN = 64;
// proc/reg00003.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG = 0x00070026ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q_LEN = 64;
// proc/reg00003.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG = 0x00070043ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN = 64;
// proc/reg00003.H

static const uint64_t VAS_VA_RG_SCF_CAMDATA0 = 0x02011434ull;

static const uint32_t VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0 = 0;
static const uint32_t VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0_LEN = 64;
// proc/reg00003.H

static const uint64_t VAS_VA_RG_SCF_CAMDISPCNTL = 0x02011433ull;
// proc/reg00003.H

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
// proc/reg00003.H

static const uint64_t VAS_VA_RG_SCF_WRMON2WID = 0x0201141aull;
// proc/reg00003.H

static const uint64_t VAS_VA_RG_SCF_WRMON3CMP = 0x02011423ull;
// proc/reg00003.H

static const uint64_t VAS_VA_RG_SCF_WRMON7BAR = 0x02011417ull;
// proc/reg00003.H

}
}
#ifndef __PPE_HCODE__
    #include "proc/reg00000.H"
    #include "proc/reg00001.H"
    #include "proc/reg00002.H"
    #include "proc/reg00003.H"
#endif
#endif
