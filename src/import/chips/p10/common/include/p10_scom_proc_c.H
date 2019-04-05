/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_c.H $       */
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

#ifndef __p10_scom_proc_c_H_
#define __p10_scom_proc_c_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_CFG_LDQ1 = 0x0201081aull;

static const uint32_t INT_CQ_CFG_LDQ1_ESBC_MIN_0_2 = 0;
static const uint32_t INT_CQ_CFG_LDQ1_ESBC_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_LDQ1_ESBC_MAX_0_4 = 3;
static const uint32_t INT_CQ_CFG_LDQ1_ESBC_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_LDQ1_ENDC_MIN_0_2 = 8;
static const uint32_t INT_CQ_CFG_LDQ1_ENDC_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_LDQ1_ENDC_MAX_0_4 = 11;
static const uint32_t INT_CQ_CFG_LDQ1_ENDC_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_LDQ1_ESBI_MIN_0_2 = 16;
static const uint32_t INT_CQ_CFG_LDQ1_ESBI_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_LDQ1_ESBI_MAX_0_4 = 19;
static const uint32_t INT_CQ_CFG_LDQ1_ESBI_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_LDQ1_ENDI_MIN_0_2 = 24;
static const uint32_t INT_CQ_CFG_LDQ1_ENDI_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_LDQ1_ENDI_MAX_0_4 = 27;
static const uint32_t INT_CQ_CFG_LDQ1_ENDI_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_LDQ1_THRC_MIN_0_2 = 32;
static const uint32_t INT_CQ_CFG_LDQ1_THRC_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_LDQ1_THRC_MAX_0_4 = 35;
static const uint32_t INT_CQ_CFG_LDQ1_THRC_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_LDQ1_THRI_MIN_0_2 = 40;
static const uint32_t INT_CQ_CFG_LDQ1_THRI_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_LDQ1_THRI_MAX_0_4 = 43;
static const uint32_t INT_CQ_CFG_LDQ1_THRI_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_LDQ1_NXNC_MIN_0_2 = 48;
static const uint32_t INT_CQ_CFG_LDQ1_NXNC_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_LDQ1_NXNC_MAX_0_4 = 51;
static const uint32_t INT_CQ_CFG_LDQ1_NXNC_MAX_0_4_LEN = 5;
static const uint32_t INT_CQ_CFG_LDQ1_NXCO_MIN_0_2 = 56;
static const uint32_t INT_CQ_CFG_LDQ1_NXCO_MIN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_LDQ1_NXCO_MAX_0_4 = 59;
static const uint32_t INT_CQ_CFG_LDQ1_NXCO_MAX_0_4_LEN = 5;
// proc/reg00046.H

static const uint64_t INT_CQ_CFG_PB_GEN = 0x02010814ull;

static const uint32_t INT_CQ_CFG_PB_GEN_PUMP_MODE = 0;
static const uint32_t INT_CQ_CFG_PB_GEN_RESERVED_1 = 1;
static const uint32_t INT_CQ_CFG_PB_GEN_WAIT_CRESP_CIST = 2;
static const uint32_t INT_CQ_CFG_PB_GEN_WAIT_CRESP_CILD = 3;
static const uint32_t INT_CQ_CFG_PB_GEN_MST_INTRP_0_1 = 4;
static const uint32_t INT_CQ_CFG_PB_GEN_MST_INTRP_0_1_LEN = 2;
static const uint32_t INT_CQ_CFG_PB_GEN_RESERVED_6_11 = 6;
static const uint32_t INT_CQ_CFG_PB_GEN_RESERVED_6_11_LEN = 6;
static const uint32_t INT_CQ_CFG_PB_GEN_CHIP_COUNT_0_3 = 12;
static const uint32_t INT_CQ_CFG_PB_GEN_CHIP_COUNT_0_3_LEN = 4;
static const uint32_t INT_CQ_CFG_PB_GEN_PHYP_DOMAIN_VEC_0_15 = 16;
static const uint32_t INT_CQ_CFG_PB_GEN_PHYP_DOMAIN_VEC_0_15_LEN = 16;
static const uint32_t INT_CQ_CFG_PB_GEN_TOPOLOGY_ID_0_3 = 32;
static const uint32_t INT_CQ_CFG_PB_GEN_TOPOLOGY_ID_0_3_LEN = 4;
static const uint32_t INT_CQ_CFG_PB_GEN_TOPOLOGY_MODE = 36;
static const uint32_t INT_CQ_CFG_PB_GEN_UNIT_ID_0_7 = 37;
static const uint32_t INT_CQ_CFG_PB_GEN_UNIT_ID_0_7_LEN = 8;
static const uint32_t INT_CQ_CFG_PB_GEN_PB_INIT = 45;
// proc/reg00046.H

static const uint64_t INT_CQ_ERR_INFO0 = 0x0201083aull;

static const uint32_t INT_CQ_ERR_INFO0_INFO_CAPTURED = 0;
static const uint32_t INT_CQ_ERR_INFO0_RCMD0_ADDR_PERR = 1;
static const uint32_t INT_CQ_ERR_INFO0_RCMD1_ADDR_PERR = 2;
static const uint32_t INT_CQ_ERR_INFO0_RCMD2_ADDR_PERR = 3;
static const uint32_t INT_CQ_ERR_INFO0_RCMD3_ADDR_PERR = 4;
static const uint32_t INT_CQ_ERR_INFO0_RCMD0_TTAG_PERR = 5;
static const uint32_t INT_CQ_ERR_INFO0_RCMD1_TTAG_PERR = 6;
static const uint32_t INT_CQ_ERR_INFO0_RCMD2_TTAG_PERR = 7;
static const uint32_t INT_CQ_ERR_INFO0_RCMD3_TTAG_PERR = 8;
static const uint32_t INT_CQ_ERR_INFO0_CR0_TTAG_PERR = 9;
static const uint32_t INT_CQ_ERR_INFO0_CR1_TTAG_PERR = 10;
static const uint32_t INT_CQ_ERR_INFO0_CR2_TTAG_PERR = 11;
static const uint32_t INT_CQ_ERR_INFO0_CR3_TTAG_PERR = 12;
static const uint32_t INT_CQ_ERR_INFO0_CR0_ATAG_PERR = 13;
static const uint32_t INT_CQ_ERR_INFO0_CR1_ATAG_PERR = 14;
static const uint32_t INT_CQ_ERR_INFO0_CR2_ATAG_PERR = 15;
static const uint32_t INT_CQ_ERR_INFO0_CR3_ATAG_PERR = 16;
static const uint32_t INT_CQ_ERR_INFO0_RTAG_PERR = 17;
// proc/reg00046.H

static const uint64_t INT_CQ_PBC_LIMIT = 0x0201081dull;

static const uint32_t INT_CQ_PBC_LIMIT_LCL_LOWER_CMDS = 0;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_LCL_UPPER_LIMIT_0_4 = 1;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_LCL_UPPER_LIMIT_0_4_LEN = 5;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_LCL_LOWER_LIMIT_0_4 = 6;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_LCL_LOWER_LIMIT_0_4_LEN = 5;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_LCL_LOWER_DROP_0_4 = 11;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_LCL_LOWER_DROP_0_4_LEN = 5;
static const uint32_t INT_CQ_PBC_LIMIT_RMT_LOWER_CMDS = 16;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_RMT_UPPER_LIMIT_0_4 = 17;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_RMT_UPPER_LIMIT_0_4_LEN = 5;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_RMT_LOWER_LIMIT_0_4 = 22;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_RMT_LOWER_LIMIT_0_4_LEN = 5;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_RMT_LOWER_DROP_0_4 = 27;
static const uint32_t INT_CQ_PBC_LIMIT_MAX_RMT_LOWER_DROP_0_4_LEN = 5;
static const uint32_t INT_CQ_PBC_LIMIT_UPPER_RESTORE_TIMER_0_2 = 32;
static const uint32_t INT_CQ_PBC_LIMIT_UPPER_RESTORE_TIMER_0_2_LEN = 3;
static const uint32_t INT_CQ_PBC_LIMIT_LOWER_RESTORE_TIMER_0_2 = 35;
static const uint32_t INT_CQ_PBC_LIMIT_LOWER_RESTORE_TIMER_0_2_LEN = 3;
// proc/reg00046.H

static const uint64_t INT_CQ_PGM_DBG1 = 0x02010801ull;
// proc/reg00046.H

static const uint64_t INT_CQ_SWI_CMD3 = 0x02010822ull;
// proc/reg00046.H

static const uint64_t INT_PC_NXC_REGS_ERR_CFG0 = 0x02010ad0ull;

static const uint32_t INT_PC_NXC_REGS_ERR_CFG0_INT_PC_NXC_ERR_CFG0_ERROR_CONFIG = 0;
static const uint32_t INT_PC_NXC_REGS_ERR_CFG0_INT_PC_NXC_ERR_CFG0_ERROR_CONFIG_LEN = 64;
// proc/reg00046.H

static const uint64_t INT_PC_NXC_REGS_FLUSH_CTRL = 0x02010a80ull;

static const uint32_t INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID = 0;
static const uint32_t INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1 = 1;
static const uint32_t INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE = 2;
static const uint32_t INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE = 3;
static const uint32_t INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6 = 4;
static const uint32_t INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6_LEN = 3;
static const uint32_t INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE = 7;
// proc/reg00046.H

static const uint64_t INT_PC_NXC_REGS_WATCH1_DATA3 = 0x02010aafull;
// proc/reg00046.H

static const uint64_t INT_PC_REGS_AIB_RX_CRD_INIT = 0x02010a10ull;

static const uint32_t INT_PC_REGS_AIB_RX_CRD_INIT_CRD_INIT_REQUEST = 0;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_INIT_RESERVED_1_7 = 1;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_INIT_RESERVED_1_7_LEN = 7;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_INIT_CRD_INIT_TIMER = 8;
static const uint32_t INT_PC_REGS_AIB_RX_CRD_INIT_CRD_INIT_TIMER_LEN = 8;
// proc/reg00046.H

static const uint64_t INT_PC_REGS_AIB_TX_PRIO = 0x02010a15ull;

static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_TCTXT_RSP = 32;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_TCTXT_RSP_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_SYNC_DMA_WR = 34;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_SYNC_DMA_WR_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_LD_RMT_PC_CHKO = 36;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_LD_RMT_PC_CHKO_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_ST_RMT_PC_CHKI = 38;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_ST_RMT_PC_CHKI_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_LIMIT_AT_DEM_IN_PIPE = 40;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_RESERVED_41 = 41;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_LD_RMT_VC = 42;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_LD_RMT_VC_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_REGS = 44;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_REGS_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_TCTXT_WR = 46;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_TCTXT_WR_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_BLCK_UPD = 48;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_BLCK_UPD_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_LD_LCL_VC = 50;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_LD_LCL_VC_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_DMA = 52;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_DMA_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_LD_RSP_RMT = 54;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_LD_RSP_RMT_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_LD_RMT_PC_NCKO = 56;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_LD_RMT_PC_NCKO_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_ST_LCL_VC = 58;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_ST_LCL_VC_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_ST_RMT_PC_NCKI = 60;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_ST_RMT_PC_NCKI_LEN = 2;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_ST_RMT_VC = 62;
static const uint32_t INT_PC_REGS_AIB_TX_PRIO_ATX_PRIO_NXC_ST_RMT_VC_LEN = 2;
// proc/reg00046.H

static const uint64_t INT_PC_REGS_VSD_TABLE_DATA = 0x02010a01ull;
// proc/reg00046.H

static const uint64_t INT_PC_REGS_TCTXT_LSI_SET_11 = 0x02010b27ull;
// proc/reg00046.H

static const uint64_t INT_PC_REGS_TCTXT_LSI_TRIG_EOI = 0x02010b20ull;
// proc/reg00046.H

static const uint64_t INT_VC_ATX_PERF_EVENT_SEL_3 = 0x02010934ull;

static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_0 = 0;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_0_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_1R = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_1R_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_1W = 8;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_1W_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_2 = 12;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_2_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_3 = 16;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_3_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_4 = 20;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_4_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_5R = 24;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_5R_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_5W = 28;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_5W_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_6 = 32;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_6_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_7RSP = 36;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_7RSP_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_7INT = 40;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_7INT_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_7EQP = 44;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_7EQP_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_8 = 48;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_8_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_9 = 52;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_9_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_10R = 56;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_10R_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_10W = 60;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_3_10W_LEN = 4;
// proc/reg00046.H

static const uint64_t INT_VC_ENDC_CFG_LD_ENG = 0x0201098aull;

static const uint32_t INT_VC_ENDC_CFG_LD_ENG_RESERVED_0_2 = 0;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_RESERVED_0_2_LEN = 3;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_NB_LOAD_ENGINE_CORE = 3;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_NB_LOAD_ENGINE_CORE_LEN = 5;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_RESERVED_8_10 = 8;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_RESERVED_8_10_LEN = 3;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_NB_LOAD_ENGINE_CQ = 11;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_NB_LOAD_ENGINE_CQ_LEN = 5;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_RESERVED_16_18 = 16;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_RESERVED_16_18_LEN = 3;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_NB_LOAD_ENGINE_PC = 19;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_NB_LOAD_ENGINE_PC_LEN = 5;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_RESERVED_24_31 = 24;
static const uint32_t INT_VC_ENDC_CFG_LD_ENG_RESERVED_24_31_LEN = 8;
// proc/reg00046.H

static const uint64_t INT_VC_ENDC_WATCH2_DATA1 = 0x020109b5ull;
// proc/reg00046.H

static const uint64_t INT_VC_ENDC_WATCH_ASSIGN = 0x02010986ull;
// proc/reg00046.H

static const uint64_t INT_VC_FATAL_ERR_G2 = 0x020109d4ull;

static const uint32_t INT_VC_FATAL_ERR_G2_INT_VC_FATAL_ERR_G2_ERROR = 0;
static const uint32_t INT_VC_FATAL_ERR_G2_INT_VC_FATAL_ERR_G2_ERROR_LEN = 64;
// proc/reg00046.H

static const uint64_t INT_VC_INFO_ERR_G1 = 0x020109ceull;

static const uint32_t INT_VC_INFO_ERR_G1_INT_VC_INFO_ERR_G1_ERROR = 0;
static const uint32_t INT_VC_INFO_ERR_G1_INT_VC_INFO_ERR_G1_ERROR_LEN = 48;
// proc/reg00046.H

static const uint64_t MCD_BANK0_GLUON = 0x03010816ull;

static const uint32_t MCD_BANK0_GLUON_VALID = 0;
static const uint32_t MCD_BANK0_GLUON_CHIP_CONTAINED_MODE = 5;
static const uint32_t MCD_BANK0_GLUON_SMF_ENABLE = 6;
static const uint32_t MCD_BANK0_GLUON_GRP_SIZE = 11;
static const uint32_t MCD_BANK0_GLUON_GRP_SIZE_LEN = 19;
static const uint32_t MCD_BANK0_GLUON_GRP_BASE = 33;
static const uint32_t MCD_BANK0_GLUON_GRP_BASE_LEN = 31;
// proc/reg00046.H

static const uint64_t MM1_MM_FIR1_ACTION0_REG = 0x03010c46ull;

static const uint32_t MM1_MM_FIR1_ACTION0_REG_MM_FIR1_ACTION0 = 0;
static const uint32_t MM1_MM_FIR1_ACTION0_REG_MM_FIR1_ACTION0_LEN = 46;
// proc/reg00046.H

static const uint64_t MM1_MM_FIR1_ACTION1_REG = 0x03010c47ull;

static const uint32_t MM1_MM_FIR1_ACTION1_REG_MM_FIR1_ACTION1 = 0;
static const uint32_t MM1_MM_FIR1_ACTION1_REG_MM_FIR1_ACTION1_LEN = 46;
// proc/reg00046.H

static const uint64_t MM1_MM_FIR1_REG_RWX = 0x03010c40ull;
static const uint64_t MM1_MM_FIR1_REG_WOX_AND = 0x03010c41ull;
static const uint64_t MM1_MM_FIR1_REG_WOX_OR = 0x03010c42ull;

static const uint32_t MM1_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET = 0;
static const uint32_t MM1_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET = 1;
static const uint32_t MM1_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET = 2;
static const uint32_t MM1_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET = 3;
static const uint32_t MM1_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET = 4;
static const uint32_t MM1_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET = 5;
static const uint32_t MM1_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET = 6;
static const uint32_t MM1_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET = 7;
static const uint32_t MM1_MM_FIR1_REG_SLB_DIR_PERR_DET = 8;
static const uint32_t MM1_MM_FIR1_REG_SLB_CAC_PERR_DET = 9;
static const uint32_t MM1_MM_FIR1_REG_SLB_LRU_PERR_DET = 10;
static const uint32_t MM1_MM_FIR1_REG_SLB_MULTIHIT_DET = 11;
static const uint32_t MM1_MM_FIR1_REG_TLB_DIR_PERR_DET = 12;
static const uint32_t MM1_MM_FIR1_REG_TLB_CAC_PERR_DET = 13;
static const uint32_t MM1_MM_FIR1_REG_TLB_LRU_PERR_DET = 14;
static const uint32_t MM1_MM_FIR1_REG_TLB_MULTIHIT_DET = 15;
static const uint32_t MM1_MM_FIR1_REG_TW_SEG_FAULT_DET = 16;
static const uint32_t MM1_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET = 17;
static const uint32_t MM1_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET = 18;
static const uint32_t MM1_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET = 19;
static const uint32_t MM1_MM_FIR1_REG_TW_PG_FAULT_SEID_DET = 20;
static const uint32_t MM1_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET = 21;
static const uint32_t MM1_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET = 22;
static const uint32_t MM1_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET = 23;
static const uint32_t MM1_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET = 24;
static const uint32_t MM1_MM_FIR1_REG_TW_RDX_CFG_HOST_DET = 25;
static const uint32_t MM1_MM_FIR1_REG_TW_INVALID_WIMG_DET = 26;
static const uint32_t MM1_MM_FIR1_REG_TW_INV_RDX_QUAD_DET = 27;
static const uint32_t MM1_MM_FIR1_REG_TW_FOREIGN_ADDR_DET = 28;
static const uint32_t MM1_MM_FIR1_REG_TW_PREFETCH_ABT_DET = 29;
static const uint32_t MM1_MM_FIR1_REG_TW_CXT_CAC_PERR_DET = 30;
static const uint32_t MM1_MM_FIR1_REG_TW_RDX_PWC_PERR_DET = 31;
static const uint32_t MM1_MM_FIR1_REG_TW_SM_CTL_ERR_DET = 32;
static const uint32_t MM1_MM_FIR1_REG_CO_SM_CTL_ERR_DET = 33;
static const uint32_t MM1_MM_FIR1_REG_CI_SM_CTL_ERR_DET = 34;
static const uint32_t MM1_MM_FIR1_REG_INV_SM_CTL_ERR_DET = 35;
static const uint32_t MM1_MM_FIR1_REG_TW_TIMEOUT_ERR_DET = 36;
static const uint32_t MM1_MM_FIR1_REG_CO_TIMEOUT_ERR_DET = 37;
static const uint32_t MM1_MM_FIR1_REG_CI_TIMEOUT_ERR_DET = 38;
static const uint32_t MM1_MM_FIR1_REG_INV_TIMEOUT_ERR_DET = 39;
static const uint32_t MM1_MM_FIR1_REG_NX0_LXSTOP_ERR_DET = 40;
static const uint32_t MM1_MM_FIR1_REG_CP0_LXSTOP_ERR_DET = 41;
static const uint32_t MM1_MM_FIR1_REG_CP1_LXSTOP_ERR_DET = 42;
static const uint32_t MM1_MM_FIR1_REG_NPU_LXSTOP_ERR_DET = 43;
static const uint32_t MM1_MM_FIR1_REG_FBC_LXSTOP_ERR_DET = 44;
static const uint32_t MM1_MM_FIR1_REG_SPARE = 45;
// proc/reg00046.H

static const uint64_t MM1_MM_NMMU_ERR_INJ = 0x03010c58ull;

static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_DIR_EN = 2;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN = 3;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN = 4;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_DIR_MULT_SEL = 5;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_DIR_MULT_SEL_LEN = 3;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_CAC_EN = 8;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN = 9;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN = 10;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_CAC_MULT_SEL = 11;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_CAC_MULT_SEL_LEN = 3;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_LRU_EN = 14;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN = 15;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN = 16;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_LRU_MULT_SEL = 17;
static const uint32_t MM1_MM_NMMU_ERR_INJ_TLB_LRU_MULT_SEL_LEN = 3;
static const uint32_t MM1_MM_NMMU_ERR_INJ_PWC_DIR_EN = 20;
static const uint32_t MM1_MM_NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN = 21;
static const uint32_t MM1_MM_NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN = 22;
static const uint32_t MM1_MM_NMMU_ERR_INJ_PWC_DIR_MULT_SEL = 23;
static const uint32_t MM1_MM_NMMU_ERR_INJ_PWC_DIR_MULT_SEL_LEN = 3;
static const uint32_t MM1_MM_NMMU_ERR_INJ_PWC_CAC_EN = 26;
static const uint32_t MM1_MM_NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN = 27;
static const uint32_t MM1_MM_NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN = 28;
static const uint32_t MM1_MM_NMMU_ERR_INJ_PWC_CAC_MULT_SEL = 29;
static const uint32_t MM1_MM_NMMU_ERR_INJ_PWC_CAC_MULT_SEL_LEN = 3;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_DIR_EN = 34;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN = 35;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN = 36;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_DIR_MULT_SEL = 37;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_DIR_MULT_SEL_LEN = 3;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_CAC_EN = 40;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN = 41;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN = 42;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_CAC_MULT_SEL = 43;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_CAC_MULT_SEL_LEN = 3;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_LRU_EN = 46;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN = 47;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN = 48;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_LRU_MULT_SEL = 49;
static const uint32_t MM1_MM_NMMU_ERR_INJ_SLB_LRU_MULT_SEL_LEN = 3;
static const uint32_t MM1_MM_NMMU_ERR_INJ_CXT_DIR_EN = 52;
static const uint32_t MM1_MM_NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN = 53;
static const uint32_t MM1_MM_NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN = 54;
static const uint32_t MM1_MM_NMMU_ERR_INJ_CXT_DIR_MULT_SEL = 55;
static const uint32_t MM1_MM_NMMU_ERR_INJ_CXT_DIR_MULT_SEL_LEN = 3;
static const uint32_t MM1_MM_NMMU_ERR_INJ_CXT_CAC_EN = 58;
static const uint32_t MM1_MM_NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN = 59;
static const uint32_t MM1_MM_NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN = 60;
static const uint32_t MM1_MM_NMMU_ERR_INJ_CXT_CAC_MULT_SEL = 61;
static const uint32_t MM1_MM_NMMU_ERR_INJ_CXT_CAC_MULT_SEL_LEN = 3;
// proc/reg00046.H

static const uint64_t NX_CH4_ADDR_4_HASH_FUNCTION_REG = 0x02011145ull;

static const uint32_t NX_CH4_ADDR_4_HASH_FUNCTION_REG_ADDRESS_4_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_4_HASH_FUNCTION_REG_ADDRESS_4_HASH_FUNCTION_LEN = 64;
// proc/reg00046.H

static const uint64_t NX_CH4_DATATAG_0_HASH_FUNCTION_REG = 0x0201114cull;

static const uint32_t NX_CH4_DATATAG_0_HASH_FUNCTION_REG_DATATAG_0_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_DATATAG_0_HASH_FUNCTION_REG_DATATAG_0_HASH_FUNCTION_LEN = 64;
// proc/reg00046.H

static const uint64_t NX_DMA_VAS_MMIO_BAR = 0x0201105eull;

static const uint32_t NX_DMA_VAS_MMIO_BAR_VAS_MMIO_BAR = 8;
static const uint32_t NX_DMA_VAS_MMIO_BAR_VAS_MMIO_BAR_LEN = 31;
// proc/reg00046.H

static const uint64_t NX_PBI_CQ_WRAP_DEBUG_SNAPSHOT_0 = 0x020110a4ull;

static const uint32_t NX_PBI_CQ_WRAP_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 = 0;
static const uint32_t NX_PBI_CQ_WRAP_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN = 64;
// proc/reg00046.H

static const uint64_t NX_PBI_RNG_RDELAY = 0x020110e5ull;

static const uint32_t NX_PBI_RNG_RDELAY_FILL_THRESHOLD = 0;
static const uint32_t NX_PBI_RNG_RDELAY_FILL_THRESHOLD_LEN = 2;
static const uint32_t NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD = 2;
static const uint32_t NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD_LEN = 2;
static const uint32_t NX_PBI_RNG_RDELAY_LFSR_RESEED_EN = 6;
static const uint32_t NX_PBI_RNG_RDELAY_READ_RTY_RATIO = 7;
static const uint32_t NX_PBI_RNG_RDELAY_READ_RTY_RATIO_LEN = 5;
// proc/reg00046.H

static const uint64_t PB_COM_ES3_FIR_ACTION0_REG = 0x03011386ull;

static const uint32_t PB_COM_ES3_FIR_ACTION0_REG_PB_ES3_FIR_ACTION0 = 0;
static const uint32_t PB_COM_ES3_FIR_ACTION0_REG_PB_ES3_FIR_ACTION0_LEN = 16;
// proc/reg00046.H

static const uint64_t PB_COM_ES3_FIR_ACTION1_REG = 0x03011387ull;

static const uint32_t PB_COM_ES3_FIR_ACTION1_REG_PB_ES3_FIR_ACTION1 = 0;
static const uint32_t PB_COM_ES3_FIR_ACTION1_REG_PB_ES3_FIR_ACTION1_LEN = 16;
// proc/reg00046.H

static const uint64_t PB_COM_ES3_FIR_REG_RWX = 0x03011380ull;
static const uint64_t PB_COM_ES3_FIR_REG_WOX_AND = 0x00000381ull;
static const uint64_t PB_COM_ES3_FIR_REG_WOX_OR = 0x00000382ull;

static const uint32_t PB_COM_ES3_FIR_REG_PROTOCOL_ERROR = 0;
static const uint32_t PB_COM_ES3_FIR_REG_OVERFLOW_ERROR = 1;
static const uint32_t PB_COM_ES3_FIR_REG_HW_PARITY_ERROR = 2;
static const uint32_t PB_COM_ES3_FIR_REG_FIR_SPARE_3 = 3;
static const uint32_t PB_COM_ES3_FIR_REG_COHERENCY_ERROR = 4;
static const uint32_t PB_COM_ES3_FIR_REG_CRESP_ADDR_ERROR = 5;
static const uint32_t PB_COM_ES3_FIR_REG_CRESP_ERROR = 6;
static const uint32_t PB_COM_ES3_FIR_REG_HANG_RECOVERY_LIMIT_ERROR = 7;
static const uint32_t PB_COM_ES3_FIR_REG_DATA_ROUTE_ERROR = 8;
static const uint32_t PB_COM_ES3_FIR_REG_HANG_RECOVERY_GTE_LEVEL1 = 9;
static const uint32_t PB_COM_ES3_FIR_REG_FORCE_MP_IPL = 10;
static const uint32_t PB_COM_ES3_FIR_REG_SBE_IPL = 11;
static const uint32_t PB_COM_ES3_FIR_REG_FIR_SPARE_12 = 12;
static const uint32_t PB_COM_ES3_FIR_REG_FIR_SPARE_13 = 13;
static const uint32_t PB_COM_ES3_FIR_REG_FIR_SPARE_14 = 14;
static const uint32_t PB_COM_ES3_FIR_REG_FIR_SPARE_15 = 15;
// proc/reg00046.H

static const uint64_t PB_COM_ES3_MODE = 0x0301138aull;

static const uint32_t PB_COM_ES3_MODE_CFG_HOP_MODE_ES3 = 4;
static const uint32_t PB_COM_ES3_MODE_CFG_PUMP_MODE_ES3 = 5;
static const uint32_t PB_COM_ES3_MODE_CFG_REPRO_MODE_ES3 = 6;
static const uint32_t PB_COM_ES3_MODE_CFG_SL_DOMAIN_SIZE_ES3 = 7;
static const uint32_t PB_COM_ES3_MODE_CFG_HNG_CHK_DISABLE = 8;
static const uint32_t PB_COM_ES3_MODE_DBG_CLR_MAX_HANG_STAGE = 9;
static const uint32_t PB_COM_ES3_MODE_CFG_SW_AB_WAIT_ES3 = 12;
static const uint32_t PB_COM_ES3_MODE_CFG_SW_AB_WAIT_ES3_LEN = 4;
static const uint32_t PB_COM_ES3_MODE_CFG_SP_HW_MARK_ES3 = 16;
static const uint32_t PB_COM_ES3_MODE_CFG_SP_HW_MARK_ES3_LEN = 7;
static const uint32_t PB_COM_ES3_MODE_CFG_GP_HW_MARK_ES3 = 23;
static const uint32_t PB_COM_ES3_MODE_CFG_GP_HW_MARK_ES3_LEN = 7;
static const uint32_t PB_COM_ES3_MODE_CFG_NP_HW_MARK_ES3 = 30;
static const uint32_t PB_COM_ES3_MODE_CFG_NP_HW_MARK_ES3_LEN = 6;
static const uint32_t PB_COM_ES3_MODE_CFG_MCA_RATIO_OVERRIDE_ES3 = 36;
static const uint32_t PB_COM_ES3_MODE_CFG_MCA_RATIO_OVERRIDE_ES3_LEN = 3;
static const uint32_t PB_COM_ES3_MODE_CFG_MCA_RATIO_SEL_ES3 = 42;
static const uint32_t PB_COM_ES3_MODE_CFG_MCA_RATIO_SEL_ES3_LEN = 2;
static const uint32_t PB_COM_ES3_MODE_CFG_PAU_STEP_OVERRIDE_ES3 = 44;
static const uint32_t PB_COM_ES3_MODE_CFG_PAU_STEP_SEL_ES3 = 45;
static const uint32_t PB_COM_ES3_MODE_CFG_PAU_STEP_SEL_ES3_LEN = 2;
static const uint32_t PB_COM_ES3_MODE_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3 = 52;
static const uint32_t PB_COM_ES3_MODE_CFG_TMGR_SERIES_ID_DISABLE_ES3 = 53;
static const uint32_t PB_COM_ES3_MODE_CFG_TMGR_TOKEN_ID_RANGE_ES3 = 54;
static const uint32_t PB_COM_ES3_MODE_CFG_TMGR_MAX_TLBI_TOKENS_ES3 = 55;
static const uint32_t PB_COM_ES3_MODE_CFG_TMGR_MAX_TLBI_TOKENS_ES3_LEN = 4;
static const uint32_t PB_COM_ES3_MODE_CFG_TMGR_MAX_SLBI_TOKENS_ES3 = 59;
static const uint32_t PB_COM_ES3_MODE_CFG_TMGR_MAX_SLBI_TOKENS_ES3_LEN = 4;
static const uint32_t PB_COM_ES3_MODE_CFG_RESET_ERROR_CAPTURE_ES3 = 63;
// proc/reg00046.H

static const uint64_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG = 0x1001182cull;

static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_0 = 0;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_0_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_1 = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_1_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_2 = 14;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_2_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_3 = 21;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_3_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_4 = 28;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_4_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_5 = 35;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_5_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_6 = 42;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_6_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_7 = 49;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_7_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_8 = 56;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_LINK_EVENT_8_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX1_REG_ALT_EVENTS = 63;
// proc/reg00046.H

static const uint64_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG = 0x1001182dull;

static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_9 = 0;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_9_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_10 = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_10_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_11 = 14;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_11_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_12 = 21;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_12_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_13 = 28;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_13_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_14 = 35;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_14_LEN = 7;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_15 = 42;
static const uint32_t PB_PTLSCOM10_CFG_TLPM_MUX2_REG_15_LEN = 7;
// proc/reg00046.H

static const uint64_t PB_PTLSCOM10_PERFTRACE_CFG_REG = 0x1001182bull;

static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE = 0;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE = 1;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE = 2;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_TSPARE6 = 3;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE = 4;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE = 5;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE = 6;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_TSPARE7 = 7;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT = 8;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT_LEN = 2;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT = 10;
static const uint32_t PB_PTLSCOM10_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT_LEN = 2;
// proc/reg00046.H

static const uint64_t PB_PTLSCOM10_PR0123_ERR = 0x10011829ull;
// proc/reg00046.H

static const uint64_t PB_PTLSCOM45_PMU2_CNPM_COUNTER = 0x12011823ull;
// proc/reg00046.H

static const uint64_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG = 0x12011810ull;

static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 = 0;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT = 1;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 = 8;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT = 9;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT_LEN = 7;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT = 16;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT = 24;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT = 32;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT_LEN = 5;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT = 37;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2 = 38;
static const uint32_t PB_PTLSCOM45_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2_LEN = 2;
// proc/reg00046.H

static const uint64_t PB_PTLSCOM67_FM0123_ERR = 0x13011827ull;
// proc/reg00046.H

static const uint64_t PB_PTLSCOM67_FP23_CFG = 0x1301180bull;

static const uint32_t PB_PTLSCOM67_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 = 0;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_DISABLE_GATHERING = 1;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_DISABLE_CMD_COMPRESSION = 2;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_DISABLE_PRSP_COMPRESSION = 3;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_LL_CREDIT_LO_LIMIT = 4;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_LL_CREDIT_PS_LIMIT = 12;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP = 20;
static const uint32_t PB_PTLSCOM67_FP23_CFG_23_CMD_EXP_TIME = 21;
static const uint32_t PB_PTLSCOM67_FP23_CFG_23_CMD_EXP_TIME_LEN = 3;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_RUN_AFTER_FRAME_ERROR = 24;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST = 25;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_PRS_SPARE = 26;
static const uint32_t PB_PTLSCOM67_FP23_CFG_2_PRS_SPARE_LEN = 6;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 = 32;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_DISABLE_GATHERING = 33;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_DISABLE_CMD_COMPRESSION = 34;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_DISABLE_PRSP_COMPRESSION = 35;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_LL_CREDIT_LO_LIMIT = 36;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_LL_CREDIT_PS_LIMIT = 44;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP = 52;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_FMR_SPARE = 53;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_FMR_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_RUN_AFTER_FRAME_ERROR = 56;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST = 57;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_PRS_SPARE = 58;
static const uint32_t PB_PTLSCOM67_FP23_CFG_3_PRS_SPARE_LEN = 6;
// proc/reg00046.H

static const uint64_t PB_PTLSCOM67_PMU1_TLPM_COUNTER = 0x1301181cull;
// proc/reg00046.H

static const uint64_t PB_PTLSCOM67_PSAVE23_MISC_CFG = 0x13011817ull;

static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_HALF_LUC = 0;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_HALF_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_HALF_HUC = 8;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_HALF_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_HALF_LUT = 16;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_HALF_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_HALF_HUT = 21;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_HALF_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_HALF_SPARE = 26;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_HALF_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_QTR_LUC = 28;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_QTR_LUC_LEN = 8;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_QTR_HUC = 36;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_QTR_HUC_LEN = 8;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_QTR_LUT = 44;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_QTR_LUT_LEN = 5;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_QTR_HUT = 49;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_QTR_HUT_LEN = 5;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_QTR_SPARE = 54;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_QTR_SPARE_LEN = 2;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_WSIZE = 56;
static const uint32_t PB_PTLSCOM67_PSAVE23_MISC_CFG_WSIZE_LEN = 3;
// proc/reg00046.H

static const uint64_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL = 0x03011c85ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_TRIG = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_TRIG_LEN = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_MARK = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_MARK_LEN = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_DBG0_STOP = 6;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_DBG1_STOP = 7;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_RUN_STOP = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_OTHER_DBG0_STOP = 9;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_SPARE1012 = 10;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_SPARE1012_LEN = 3;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_XSTOP_STOP = 13;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_SPARE1415 = 14;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CTRL_SPARE1415_LEN = 2;
// proc/reg00046.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_0_PFIRACTION0_REG = 0x08010846ull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PFIRACTION0_REG_PFIRACTION0 = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PFIRACTION0_REG_PFIRACTION0_LEN = 6;
// proc/reg00046.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_0_PFIRACTION1_REG = 0x08010847ull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PFIRACTION1_REG_PFIRACTION1 = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_0_PFIRACTION1_REG_PFIRACTION1_LEN = 6;
// proc/reg00046.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PFIRACTION0_REG = 0x08010886ull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PFIRACTION0_REG_PFIRACTION0 = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PFIRACTION0_REG_PFIRACTION0_LEN = 6;
// proc/reg00046.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PFIRACTION1_REG = 0x08010887ull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PFIRACTION1_REG_PFIRACTION1 = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_1_PFIRACTION1_REG_PFIRACTION1_LEN = 6;
// proc/reg00046.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_1_PFIRWOF_REG = 0x08010888ull;
// proc/reg00046.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_PFIRACTION0_REG = 0x080108c6ull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PFIRACTION0_REG_PFIRACTION0 = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PFIRACTION0_REG_PFIRACTION0_LEN = 6;
// proc/reg00047.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_PFIRACTION1_REG = 0x080108c7ull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PFIRACTION1_REG_PFIRACTION1 = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PFIRACTION1_REG_PFIRACTION1_LEN = 6;
// proc/reg00047.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_ADDREXTMASK_REG = 0x02011805ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_ADDREXTMASK_REG_PE_ADDREXTMASK = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_ADDREXTMASK_REG_PE_ADDREXTMASK_LEN = 7;
// proc/reg00047.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG = 0x02011801ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPRIORITYMASK = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPRIORITYMASK_LEN = 6;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_ENABLE_CTAG_DROP_PRIORITY = 6;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_ENABLE_IO_CMD_PACING = 7;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACECOUNT = 8;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACECOUNT_LEN = 9;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACEINC = 17;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACEINC_LEN = 6;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_RTYDROPDIVIDER = 23;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_RTYDROPDIVIDER_LEN = 3;
// proc/reg00047.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_PREDV_REG = 0x02011806ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_PREDV_REG_RD_PREDV_TIMEOUT_MASK = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PREDV_REG_RD_PREDV_TIMEOUT_MASK_LEN = 8;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PREDV_REG_WR_PREDV_TIMEOUT_MASK = 8;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_PREDV_REG_WR_PREDV_TIMEOUT_MASK_LEN = 8;
// proc/reg00047.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIR_REG_RWX = 0x02011840ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIR_REG_WOX_AND = 0x02011841ull;
static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIR_REG_WOX_OR = 0x02011842ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIR_REG_NFIRNFIR = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIR_REG_NFIRNFIR_LEN = 28;
// proc/reg00047.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG = 0x0201188full;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0_LEN = 40;
// proc/reg00047.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_REG = 0x0201188eull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_REG_PE_MMIO_BAR0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR0_REG_PE_MMIO_BAR0_LEN = 40;
// proc/reg00047.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR1_REG = 0x02011890ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR1_REG_PE_MMIO_BAR1 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_MMIOBAR1_REG_PE_MMIO_BAR1_LEN = 40;
// proc/reg00047.H

static const uint64_t PE0_PHB0_ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PAST = 0x08010915ull;
// proc/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_ACT0_REG = 0x0000094eull;
// proc/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_MASK_REG_RWX = 0x0000094bull;
static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_MASK_REG_WOX_AND = 0x0000094cull;
static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_MASK_REG_WOX_OR = 0x0000094dull;
// proc/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL = 0x00000945ull;

static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE = 0;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE = 1;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE = 2;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE = 3;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE = 4;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE = 5;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE = 6;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE = 7;
static const uint32_t PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE = 8;
// proc/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_PHB5_PMON_EVENT_SEL = 0x00000998ull;
// proc/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL = 0x00000985ull;

static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE = 0;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE = 1;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE = 2;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE = 3;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE = 4;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE = 5;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE = 6;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE = 7;
static const uint32_t PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE = 8;
// proc/reg00047.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXDCR_REG = 0x0901084eull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXDCR_REG_A = 33;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXDCR_REG_A_LEN = 2;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXDCR_REG_R = 44;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PBAIBTXDCR_REG_R_LEN = 4;
// proc/reg00047.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG = 0x0901088dull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_0_CCA = 0;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_0_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_0_CCR = 10;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_0_CCR_LEN = 6;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_1_CCA = 16;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_1_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_1_CCR = 26;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_1_CCR_LEN = 6;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_2_CCA = 32;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_2_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_2_CCR = 41;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_2_CCR_LEN = 7;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_3_CCA = 48;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_3_CCA_LEN = 3;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_3_CCR = 58;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_1_PBAIBTXCCR_REG_3_CCR_LEN = 6;
// proc/reg00047.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_CACHE_INJECT_CNTL_REG = 0x030118d7ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT
    = 1;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION =
    2;
static const uint32_t
PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD = 3;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION = 4;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT =
    5;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION = 6;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_2_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD
    = 7;
// proc/reg00047.H

static const uint64_t PE1_PHB1_ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR = 0x09010953ull;
// proc/reg00047.H

static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_ACT0_REG = 0x0901098eull;
// proc/reg00047.H

static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_MASK_REG_RWX = 0x0901098bull;
static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_MASK_REG_WOX_AND = 0x0901098cull;
static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_MASK_REG_WOX_OR = 0x0901098dull;
// proc/reg00047.H

static const uint64_t PE1_PHB2_ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR = 0x09010993ull;
// proc/reg00047.H

static const uint64_t TP_LPC_SYNC_FIR_ACTION0_REG = 0x03012006ull;

static const uint32_t TP_LPC_SYNC_FIR_ACTION0_REG_INVALID_TRANSFER_SIZE_ACTION0 = 0;
static const uint32_t TP_LPC_SYNC_FIR_ACTION0_REG_INVALID_COMMAND_ACTION0 = 1;
static const uint32_t TP_LPC_SYNC_FIR_ACTION0_REG_INVALID_ADDRESS_ALIGNMENT_ACTION0 = 2;
static const uint32_t TP_LPC_SYNC_FIR_ACTION0_REG_OPB_ERROR_ACTION0 = 3;
static const uint32_t TP_LPC_SYNC_FIR_ACTION0_REG_OPB_TIMEOUT_ACTION0 = 4;
static const uint32_t TP_LPC_SYNC_FIR_ACTION0_REG_OPB_MASTER_HANG_TIMEOUT_ACTION0 = 5;
static const uint32_t TP_LPC_SYNC_FIR_ACTION0_REG_CMD_BUFFER_PAR_ERR_ACTION0 = 6;
static const uint32_t TP_LPC_SYNC_FIR_ACTION0_REG_DAT_BUFFER_PAR_ERR_ACTION0 = 7;
static const uint32_t TP_LPC_SYNC_FIR_ACTION0_REG_RETURNQ_ERR_ACTION0 = 8;
static const uint32_t TP_LPC_SYNC_FIR_ACTION0_REG_RESERVED_ACTION0 = 9;
// proc/reg00047.H

static const uint64_t TP_LPC_SYNC_FIR_ACTION1_REG = 0x03012007ull;

static const uint32_t TP_LPC_SYNC_FIR_ACTION1_REG_INVALID_TRANSFER_SIZE_ACTION1 = 0;
static const uint32_t TP_LPC_SYNC_FIR_ACTION1_REG_INVALID_COMMAND_ACTION1 = 1;
static const uint32_t TP_LPC_SYNC_FIR_ACTION1_REG_INVALID_ADDRESS_ALIGNMENT_ACTION1 = 2;
static const uint32_t TP_LPC_SYNC_FIR_ACTION1_REG_OPB_ERROR_ACTION1 = 3;
static const uint32_t TP_LPC_SYNC_FIR_ACTION1_REG_OPB_TIMEOUT_ACTION1 = 4;
static const uint32_t TP_LPC_SYNC_FIR_ACTION1_REG_OPB_MASTER_HANG_TIMEOUT_ACTION1 = 5;
static const uint32_t TP_LPC_SYNC_FIR_ACTION1_REG_CMD_BUFFER_PAR_ERR_ACTION1 = 6;
static const uint32_t TP_LPC_SYNC_FIR_ACTION1_REG_DAT_BUFFER_PAR_ERR_ACTION1 = 7;
static const uint32_t TP_LPC_SYNC_FIR_ACTION1_REG_RETURNQ_ERR_ACTION1 = 8;
static const uint32_t TP_LPC_SYNC_FIR_ACTION1_REG_RESERVED_ACTION1 = 9;
// proc/reg00047.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAFIRACT1 = 0x03011dc7ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1 = 0;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1_LEN = 44;
// proc/reg00047.H

static const uint64_t TP_TPBR_PBA_PBAO_BCUE_STAT = 0x00068017ull;

static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING = 0;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING = 1;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP_LEN = 6;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP = 14;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP_LEN = 6;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG = 20;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG_LEN = 9;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED = 29;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR = 30;
static const uint32_t TP_TPBR_PBA_PBAO_BCUE_STAT_DONE = 31;
// proc/reg00047.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAOCFG = 0x03021c8bull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_7_15 = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_7_15_LEN = 9;
// proc/reg00047.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAOCR3 = 0x0006801dull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAOCR3_PBAOCR3_COUNT = 44;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCR3_PBAOCR3_COUNT_LEN = 20;
// proc/reg00047.H

static const uint64_t TP_TPBR_PBA_PBAO_PBARBUFVAL4 = 0x03021c94ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL4_RD_SLVNUM = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL4_RD_SLVNUM_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL4_CUR_RD_ADDR = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL4_CUR_RD_ADDR_LEN = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL4_PREFETCH = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL4_ABORT = 31;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL4_BUFFER_STATUS = 33;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL4_BUFFER_STATUS_LEN = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL4_MASTERID = 41;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL4_MASTERID_LEN = 3;
// proc/reg00047.H

static const uint64_t TP_TPBR_PBA_PBAO_PBASLVCTL3 = 0x00068007ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_ENABLE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_MID_MATCH_VALUE = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_MID_MATCH_VALUE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_RESERVED_4 = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_MID_CARE_MASK = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_MID_CARE_MASK_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_WRITE_TTYPE = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_WRITE_TTYPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_RESERVED_11_14 = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_RESERVED_11_14_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_READ_TTYPE = 15;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_READ_PREFETCH_CTL = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_READ_PREFETCH_CTL_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_BUF_INVALIDATE_CTL = 18;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_BUF_ALLOC_W = 19;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_BUF_ALLOC_A = 20;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_BUF_ALLOC_B = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_BUF_ALLOC_C = 22;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_RESERVED_23 = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_DIS_WRITE_GATHER = 24;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_WR_GATHER_TIMEOUT = 25;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_WR_GATHER_TIMEOUT_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_WRITE_TSIZE = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_WRITE_TSIZE_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_EXTADDR = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_EXTADDR_LEN = 14;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL3_RESERVED_50 = 50;
// proc/reg00047.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXSHINC0 = 0x00068028ull;
// proc/reg00047.H

static const uint64_t TP_TPBR_PSIHB_PSI_FSP_MMR_REG = 0x03011d0cull;

static const uint32_t TP_TPBR_PSIHB_PSI_FSP_MMR_REG_FSP_MMR = 32;
static const uint32_t TP_TPBR_PSIHB_PSI_FSP_MMR_REG_FSP_MMR_LEN = 12;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDCACL = 0x0006002full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDCACL_ERR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDCACL_POPULATE_PENDING = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDCACL_VALID = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDCACL_VALID_LEN = 4;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDCACU = 0x0006002eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN = 27;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIEDR = 0x00060023ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIEDR_OCB_OCI_GPEXIRAMEDR_EDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIEDR_OCB_OCI_GPEXIRAMEDR_EDR_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMRA = 0x00060011ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR_LEN = 3;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR28 = 0x00060086ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR28_8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR28_8_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR28_9 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR28_9_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR0 = 0x00062040ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR0_OCB_OCI_GPEXIVDR0_GPR0_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIIAR = 0x00062025ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR_LEN = 30;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXICTR = 0x00064032ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXICTR_OCB_OCI_GPEXICTR_CTR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXICTR_OCB_OCI_GPEXICTR_CTR_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR29 = 0x0006404dull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR4 = 0x00064044ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR4_OCB_OCI_GPEXIVDR4_GPR4_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR28 = 0x0006604cull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMEDR = 0x00066014ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMEDR_IR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMEDR_EDR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMEDR_EDR_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBL = 0x00066027ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBL_R_NW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBL_BUSY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBL_RSP_INFO = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBL_RSP_INFO_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBL_IFETCH_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBL_DATAOP_PENDING = 31;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBU = 0x00066026ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_DERP2 = 0x0006c184ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP2_DEND = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP2_DEND_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP2_SOR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP2_SOR_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD2B = 0x0006c757ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD2B_CMD2B_RESERVED_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD2B__CLEAR_STICKY_BITS_2B = 1;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SRD0B = 0x0006c719ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD0B_OCB_OCI_O2SRD0B_O2S_RDATA_0B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD0B_OCB_OCI_O2SRD0B_O2S_RDATA_0B_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SWD2B = 0x0006c758ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD2B_OCB_OCI_O2SWD2B_O2S_WDATA_2B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD2B_OCB_OCI_O2SWD2B_O2S_WDATA_2B_LEN = 32;
// proc/reg00047.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSES0 = 0x0006c206ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES0_SH_READ_UNDERFLOW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES0_LL_WRITE_OVERFLOW = 1;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCICFG = 0x0006c085ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M0_PRIORITY = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M0_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M1_PRIORITY = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M1_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M2_PRIORITY = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M2_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M3_PRIORITY = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M3_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M4_PRIORITY = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M4_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M5_PRIORITY = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M5_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M6_PRIORITY = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M6_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M7_PRIORITY = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M7_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M0_PRIORITY_SEL = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M1_PRIORITY_SEL = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M2_PRIORITY_SEL = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M3_PRIORITY_SEL = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_OCICFG_RESERVED_20 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M5_PRIORITY_SEL = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_OCICFG_RESERVED_23 = 22;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_M7_PRIORITY_SEL = 23;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_PLBARB_LOCKERR = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_SPARE_24_31 = 25;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCICFG_SPARE_24_31_LEN = 7;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1C_RW = 0x0006c058ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1C_WO_CLEAR = 0x0006c059ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1C_WO_OR = 0x0006c05aull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR1C_OCB_OCI_OIRR1C_INTERRUPT_ROUTE_1_C = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR1C_OCB_OCI_OIRR1C_INTERRUPT_ROUTE_1_C_LEN = 32;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OISR0_ROX = 0x0006c000ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OISR0_WOX_CLEAR = 0x0006c001ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OISR0_WOX_OR = 0x0006c002ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_TRACE_TRIGGER = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_OCC_ERROR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_GPE2_ERROR = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_GPE3_ERROR = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_CHECK_STOP_GPE2 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_CHECK_STOP_GPE3 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_OCC_MALF_ALERT = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PVREF_ERROR = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_IPI2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_IPI3 = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_DEBUG_TRIGGER = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_SPARE = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PBAX_PGPE_ATTN = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PBAX_PGPE_PUSH0 = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PBAX_PGPE_PUSH1 = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PBA_OVERCURRENT_INDICATOR = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPE0_PENDING = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPE1_PENDING = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPE2_PENDING = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPE3_PENDING = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPE4_PENDING = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPE5_PENDING = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPE6_PENDING = 22;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPE7_PENDING = 23;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPE8_PENDING = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPE9_PENDING = 25;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPEA_PENDING = 26;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPEB_PENDING = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPEC_PENDING = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPED_PENDING = 29;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPEE_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR0_PMC_PCB_INTR_TYPEF_PENDING = 31;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3RR = 0x0006c503ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3RR_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3RR_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q3RR = 0x0006c50bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q3RR_OCB_OCI_OPIT1Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q3RR_OCB_OCI_OPIT1Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q7 = 0x0006c40full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q7_OCB_OCI_OPIT1Q7RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q7_OCB_OCI_OPIT1Q7RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q3 = 0x0006c413ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q3_OCB_OCI_OPIT2Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q3_OCB_OCI_OPIT2Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q3RR = 0x0006c513ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q3RR_OCB_OCI_OPIT2Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q3RR_OCB_OCI_OPIT2Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q3RR = 0x0006c51bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q3RR_OCB_OCI_OPIT3Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT3Q3RR_OCB_OCI_OPIT3Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q3RR = 0x0006c523ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q3RR_OCB_OCI_OPIT4Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT4Q3RR_OCB_OCI_OPIT4Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q3RR = 0x0006c52bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q3RR_OCB_OCI_OPIT5Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q3RR_OCB_OCI_OPIT5Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q5 = 0x0006c42dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q5_OCB_OCI_OPIT5Q5RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q5_OCB_OCI_OPIT5Q5RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1 = 0x0006c431ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q3RR = 0x0006c533ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q3RR_OCB_OCI_OPIT6Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q3RR_OCB_OCI_OPIT6Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q3RR = 0x0006c53bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q3RR_OCB_OCI_OPIT7Q3RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7Q3RR_OCB_OCI_OPIT7Q3RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29RR = 0x0006c55dull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C29RR_PAYLOAD_LEN = 17;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4RR = 0x0006c544ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4RR_PAYLOAD_LEN = 17;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5 = 0x0006c445ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C5_PAYLOAD_LEN = 17;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4RR = 0x0006c564ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C4RR_PAYLOAD_LEN = 17;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR = 0x0006c580ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITASV0RR_7_LEN = 4;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR = 0x0006c586ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITBSV2RR_7_LEN = 4;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITESV = 0x0006c490ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_0_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_2 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_2_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_3 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_3_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_4 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_5 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_5_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_6 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_6_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_7 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITESV_7_LEN = 4;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0 = 0x0006c840ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_FRAME_SIZE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_FRAME_SIZE_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_OUT_COUNT1 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_OUT_COUNT1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_IN_DELAY1 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_IN_DELAY1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_IN_COUNT1 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_IN_COUNT1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_OUT_COUNT2 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_OUT_COUNT2_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_IN_DELAY2 = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_IN_DELAY2_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_IN_COUNT2 = 36;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR0_IN_COUNT2_LEN = 6;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG112 = 0x00008070ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG112_REGISTER112 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG112_REGISTER112_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG12 = 0x0000800cull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG12_REGISTER12 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG12_REGISTER12_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG125 = 0x0000807dull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG125_REGISTER125 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG125_REGISTER125_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG25 = 0x00008019ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG25_REGISTER25 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG25_REGISTER25_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG44 = 0x0000802cull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG44_REGISTER44 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG44_REGISTER44_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG6 = 0x00008006ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG6_REGISTER6 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG6_REGISTER6_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG73 = 0x00008049ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG73_REGISTER73 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG73_REGISTER73_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG86 = 0x00008056ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG86_REGISTER86 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG86_REGISTER86_LEN = 64;
// proc/reg00048.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG99 = 0x00008063ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG99_REGISTER99 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG99_REGISTER99_LEN = 64;
// proc/reg00048.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_CHIPID_ROX = 0x0000100aull;
// proc/reg00048.H

static const uint64_t TP_TPVSB_FSI_W_I2C_INTERRUPTS_A = 0x00001806ull;
// proc/reg00048.H

static const uint64_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A = 0x00001807ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_INVALID_CMD_000 = 0;
static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_LBUS_PARITY_ERROR_000 = 1;
static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_BE_OV_ERROR_000 = 2;
static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_BE_ACC_ERROR_000 = 3;
static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_ARBITRATION_LOST_ERROR_000 = 4;
static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_NACK_RECEIVED_ERROR_000 = 5;
static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_DATA_REQUEST_000 = 6;
static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_STOP_ERROR_000 = 8;
static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_SELF_BUSY_000 = 23;
static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_FIFO_ENTRY_COUNT_000 = 28;
static const uint32_t TP_TPVSB_FSI_W_I2C_STATUS_REGISTER_ENGINE_A_FIFO_ENTRY_COUNT_000_LEN = 4;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_13_RWX = 0x0000288dull;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_7_RWX = 0x00002887ull;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_1_RWX = 0x000028c1ull;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_B_ROX = 0x00050027ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_B_RWX = 0x00002827ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_B_M1HC2B_MAILBOX_1_HEADER_COMMAND_2_B =
    0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_B_M1HC2B_MAILBOX_1_HEADER_COMMAND_2_B_LEN
    = 32;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_ROX = 0x00002833ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_RWX_WOR = 0x00050033ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_WOX_CLEAR = 0x00050034ull;

static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_XUP_MAILBOX_1 = 30;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_PIB_SLAVE_A_PENDING_MAILBOX_1 = 31;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_A_ROX = 0x0000282bull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_A_RWX = 0x0005002bull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_A_M2HC2A_MAILBOX_2_HEADER_COMMAND_A = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_A_M2HC2A_MAILBOX_2_HEADER_COMMAND_A_LEN =
    32;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW = 0x00002814ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_5_SPARE = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_13_SPARE = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_17_SPARE = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_NEST_CLK_ASYNC_RESET_DC = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_26_SPARE = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_FSI_CLKIN_SEL_DC = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_30_SPARE = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE = 31;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW = 0x00002916ull;
// proc/reg00048.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW = 0x00002918ull;
// proc/reg00048.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_INT_COND = 0x000b005eull;
// proc/reg00048.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_SND_BUFFER1_REGISTER_ROX = 0x00000c1eull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_SND_BUFFER1_REGISTER_DMA_PIB_SND_BUF1_REG_DATA0 = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_SND_BUFFER1_REGISTER_DMA_PIB_SND_BUF1_REG_DATA0_LEN = 32;
// proc/reg00048.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_CRSIM = 0x00020006ull;
// proc/reg00048.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RSIM = 0x00020009ull;
// proc/reg00048.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIS = 0x00020017ull;
// proc/reg00048.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RESET = 0x00030004ull;
// proc/reg00049.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIS = 0x0003000aull;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP1_FSI0 = 0x00003054ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP1_SCOMFSI0 = 0x00000c15ull;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCRSP0_FSI0 = 0x00003008ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCRSP0_SCOMFSI0 = 0x00000c02ull;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP0_RW = 0x00003010ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP0_0_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP0_1_ENABLE = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP0_2_ENABLE = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP0_3_ENABLE = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP0_4_ENABLE = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP0_5_ENABLE = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP0_6_ENABLE = 6;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP0_7_ENABLE = 7;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSSIEP0_FSI0 = 0x00003050ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSSIEP0_SCOMFSI0 = 0x00000c14ull;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP0_RO = 0x000030d0ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP0_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP0_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP0_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP0_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP0_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP0_2_LEN = 3;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP3_WOX = 0x000034dcull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP3_GENERAL_RESET_3 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP3_ERROR_RESET_3 = 1;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP0_FSI0 = 0x00003430ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP0_SCOMFSI0 = 0x00000d0cull;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_RW = 0x00003000ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_ENABLE_IPOLL_AND_DMA = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_ENABLE_PARITY_CHECK = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_CLOCK_RATE_SELECTION_0 = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_CLOCK_RATE_SELECTION_0_LEN = 10;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_CLOCK_RATE_SELECTION_1 = 14;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN = 10;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_CLOCK_DIV_4 = 25;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_TIMEOUT_SEL = 26;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_TIMEOUT_SEL_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_RECEIVER_MODE = 29;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MMODE_RECEIVER_MODE_LEN = 3;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP5_WOX = 0x000030e4ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP5_GENERAL_RESET_5 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP5_ERROR_RESET_5 = 1;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSCSB0_FSI1 = 0x000031d4ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSCSB0_SCOMFSI1 = 0x00000c75ull;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP6_FSI1 = 0x00003048ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP6_SCOMFSI1 = 0x00000c12ull;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCRSIS4 = 0x00000864ull;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SNMR = 0x0000084cull;
// proc/reg00049.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SRSIC0 = 0x00000868ull;
// proc/reg00049.H

static const uint64_t VAS_VA_EG_SCF_PBCFG1 = 0x0201144eull;

static const uint32_t VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR = 0;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR = 1;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR = 2;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR = 3;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD = 4;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD = 5;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD = 6;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD = 7;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS = 12;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_RESERVED_13 = 13;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_SKIP_G = 14;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE = 15;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_RESERVED_16 = 16;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE = 17;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ = 18;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ = 19;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK = 20;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK_LEN = 8;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK = 28;
static const uint32_t VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK_LEN = 8;
// proc/reg00049.H

static const uint64_t VAS_VA_RG_SCF_FIR_MASK_REG_RW = 0x02011403ull;
static const uint64_t VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND = 0x02011404ull;
static const uint64_t VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR = 0x02011405ull;

static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK = 0;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK = 1;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK = 2;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK = 3;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK = 4;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK = 5;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK = 6;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK = 7;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK = 8;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK = 9;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK = 10;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK = 11;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK = 12;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK = 13;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK = 14;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK = 15;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK = 16;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK = 17;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK = 18;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK = 19;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK = 20;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK = 21;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK = 22;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK = 23;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK = 24;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK = 25;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK = 26;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK = 27;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK = 28;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_LINK_ERROR_MASK = 29;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_LINK_ERROR_MASK = 30;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_LINK_ABORT_MASK = 31;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK = 32;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK = 33;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK = 34;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK = 35;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK = 36;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK = 37;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK = 38;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK = 39;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK = 40;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK = 41;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK = 42;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK = 43;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK = 44;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK = 45;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK = 46;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK = 47;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK = 48;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK = 49;
static const uint32_t VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK = 50;
// proc/reg00049.H

static const uint64_t VAS_VA_RG_SCF_INERRRPT = 0x0201142bull;

static const uint32_t VAS_VA_RG_SCF_INERRRPT_RESET = 0;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT4 = 4;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT5 = 5;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT6 = 6;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT7 = 7;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT8 = 8;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT9 = 9;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT10 = 10;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT11 = 11;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT12 = 12;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT13 = 13;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT14 = 14;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT15 = 15;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT16 = 16;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT17 = 17;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT18 = 18;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT19 = 19;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT20 = 20;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT21 = 21;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT22 = 22;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT23 = 23;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT24 = 24;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT25 = 25;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT26 = 26;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT27 = 27;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT28 = 28;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT29 = 29;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT30 = 30;
static const uint32_t VAS_VA_RG_SCF_INERRRPT_BIT31 = 31;
// proc/reg00049.H

static const uint64_t VAS_VA_RG_SCF_RESERVE = 0x02011428ull;
// proc/reg00049.H

static const uint64_t VAS_VA_RG_SCF_WRMON1BAR = 0x02011411ull;
// proc/reg00049.H

static const uint64_t VAS_VA_RG_SCF_WRMON4WID = 0x0201141cull;
// proc/reg00049.H

static const uint64_t VAS_VA_RG_SCF_WRMON5CMP = 0x02011425ull;
// proc/reg00049.H

}
}
#include "proc/reg00046.H"
#include "proc/reg00047.H"
#include "proc/reg00048.H"
#include "proc/reg00049.H"
#endif
