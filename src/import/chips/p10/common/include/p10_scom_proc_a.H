/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_a.H $       */
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

#ifndef __p10_scom_proc_a_H_
#define __p10_scom_proc_a_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_CNPM_SEL = 0x02010826ull;

static const uint32_t INT_CQ_CNPM_SEL_PMON_MUX_BYTE0_0_2 = 0;
static const uint32_t INT_CQ_CNPM_SEL_PMON_MUX_BYTE0_0_2_LEN = 3;
static const uint32_t INT_CQ_CNPM_SEL_PMON_MUX_BYTE1_0_2 = 3;
static const uint32_t INT_CQ_CNPM_SEL_PMON_MUX_BYTE1_0_2_LEN = 3;
static const uint32_t INT_CQ_CNPM_SEL_PMON_MUX_BYTE2_0_2 = 6;
static const uint32_t INT_CQ_CNPM_SEL_PMON_MUX_BYTE2_0_2_LEN = 3;
static const uint32_t INT_CQ_CNPM_SEL_PMON_MUX_BYTE3_0_2 = 9;
static const uint32_t INT_CQ_CNPM_SEL_PMON_MUX_BYTE3_0_2_LEN = 3;
static const uint32_t INT_CQ_CNPM_SEL_RESERVED_12_23 = 12;
static const uint32_t INT_CQ_CNPM_SEL_RESERVED_12_23_LEN = 12;
static const uint32_t INT_CQ_CNPM_SEL_EBUS_ENABLE_0_15 = 24;
static const uint32_t INT_CQ_CNPM_SEL_EBUS_ENABLE_0_15_LEN = 16;
// proc/reg00043.H

static const uint64_t INT_CQ_ERR_INFO1 = 0x0201083bull;

static const uint32_t INT_CQ_ERR_INFO1_INFO_CAPTURED = 0;
static const uint32_t INT_CQ_ERR_INFO1_CI_WRITE = 1;
static const uint32_t INT_CQ_ERR_INFO1_CI_READ = 2;
static const uint32_t INT_CQ_ERR_INFO1_DMA_WRITE = 3;
static const uint32_t INT_CQ_ERR_INFO1_TSIZE_4_6 = 4;
static const uint32_t INT_CQ_ERR_INFO1_TSIZE_4_6_LEN = 3;
static const uint32_t INT_CQ_ERR_INFO1_BAR_VEC_0_5 = 7;
static const uint32_t INT_CQ_ERR_INFO1_BAR_VEC_0_5_LEN = 6;
static const uint32_t INT_CQ_ERR_INFO1_TTAG_0_14 = 13;
static const uint32_t INT_CQ_ERR_INFO1_TTAG_0_14_LEN = 15;
static const uint32_t INT_CQ_ERR_INFO1_ADDRESS_28_63 = 28;
static const uint32_t INT_CQ_ERR_INFO1_ADDRESS_28_63_LEN = 36;
// proc/reg00043.H

static const uint64_t INT_CQ_PGM_DBG0 = 0x02010800ull;
// proc/reg00043.H

static const uint64_t INT_CQ_SWI_CMD2 = 0x02010821ull;
// proc/reg00043.H

static const uint64_t INT_CQ_TDR = 0x0201080full;
// proc/reg00043.H

static const uint64_t INT_PC_NXC_REGS_ERR_CFG1 = 0x02010ad1ull;

static const uint32_t INT_PC_NXC_REGS_ERR_CFG1_INT_PC_NXC_ERR_CFG1_ERROR_CONFIG = 0;
static const uint32_t INT_PC_NXC_REGS_ERR_CFG1_INT_PC_NXC_ERR_CFG1_ERROR_CONFIG_LEN = 64;
// proc/reg00043.H

static const uint64_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD = 0x02010a89ull;

static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_0_1 = 0;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_0_1_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CHKOUT_LOAD = 2;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CHKOUT_LOAD_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_8_9 = 8;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_8_9_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CI_LOAD_LCL_VC = 10;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CI_LOAD_LCL_VC_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_16_17 = 16;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_16_17_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CI_LOAD_RMT_VC = 18;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CI_LOAD_RMT_VC_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_24_25 = 24;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_24_25_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CI_STORE_RMT_PC = 26;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CI_STORE_RMT_PC_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_32_33 = 32;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_32_33_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CI_STORE_RMT_VC = 34;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CI_STORE_RMT_VC_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_40_41 = 40;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_40_41_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CI_LOAD_RMT_PC = 42;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_CI_LOAD_RMT_PC_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_48_49 = 48;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_48_49_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_NVX_DMA_READ = 50;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_NVX_DMA_READ_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_56_57 = 56;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_RESERVED_56_57_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_NVX_DMA_WRITE = 58;
static const uint32_t INT_PC_NXC_REGS_MAX_OUTSTANDING_OUTB_CMD_NVX_DMA_WRITE_LEN = 6;
// proc/reg00043.H

static const uint64_t INT_PC_NXC_REGS_WATCH1_DATA2 = 0x02010aaeull;
// proc/reg00043.H

static const uint64_t INT_PC_REGS_NRQ_NXC_ARB = 0x02010a1full;

static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_RESERVED_0 = 0;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_RSVD = 1;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_RSVD_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_STALL_LCL_NCKO_LD = 4;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_LCL_NCKO_LD = 5;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_LCL_NCKO_LD_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_STALL_LCL_CHKO_LD = 8;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_LCL_CHKO_LD = 9;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_LCL_CHKO_LD_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_STALL_LCL_NCKI_ST = 12;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_LCL_NCKI_ST = 13;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_LCL_NCKI_ST_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_STALL_LCL_CHKI_ST = 16;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_LCL_CHKI_ST = 17;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_LCL_CHKI_ST_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_STALL_RMT_NCKI_ST = 20;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_RMT_NCKI_ST = 21;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_RMT_NCKI_ST_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_STALL_RMT_CHKI_ST = 24;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_RMT_CHKI_ST = 25;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_CFG_NRQ_NXC_ARB_PRIO_RMT_CHKI_ST_LEN = 3;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_RESERVED_28_31 = 28;
static const uint32_t INT_PC_REGS_NRQ_NXC_ARB_RESERVED_28_31_LEN = 4;
// proc/reg00043.H

static const uint64_t INT_PC_REGS_VSD_TABLE_ADDR = 0x02010a00ull;

static const uint32_t INT_PC_REGS_VSD_TABLE_ADDR_AUTO_INCREMENT = 0;
static const uint32_t INT_PC_REGS_VSD_TABLE_ADDR_RESERVED_1_3 = 1;
static const uint32_t INT_PC_REGS_VSD_TABLE_ADDR_RESERVED_1_3_LEN = 3;
static const uint32_t INT_PC_REGS_VSD_TABLE_ADDR_TABLE_SELECT = 12;
static const uint32_t INT_PC_REGS_VSD_TABLE_ADDR_TABLE_SELECT_LEN = 4;
static const uint32_t INT_PC_REGS_VSD_TABLE_ADDR_RESERVED_24_27 = 24;
static const uint32_t INT_PC_REGS_VSD_TABLE_ADDR_RESERVED_24_27_LEN = 4;
static const uint32_t INT_PC_REGS_VSD_TABLE_ADDR_TABLE_ADDRESS = 28;
static const uint32_t INT_PC_REGS_VSD_TABLE_ADDR_TABLE_ADDRESS_LEN = 4;
// proc/reg00043.H

static const uint64_t INT_PC_REGS_TCTXT_LSI_SET_10 = 0x02010b26ull;
// proc/reg00043.H

static const uint64_t INT_VC_ATX_PERF_EVENT_SEL_2 = 0x02010933ull;

static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_0 = 0;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_0_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_1R = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_1R_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_1W = 8;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_1W_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_2 = 12;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_2_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_3 = 16;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_3_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_4 = 20;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_4_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_5R = 24;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_5R_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_5W = 28;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_5W_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_6 = 32;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_6_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_7RSP = 36;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_7RSP_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_7INT = 40;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_7INT_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_7EQP = 44;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_7EQP_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_8 = 48;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_8_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_9 = 52;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_9_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_10R = 56;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_10R_LEN = 4;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_10W = 60;
static const uint32_t INT_VC_ATX_PERF_EVENT_SEL_2_10W_LEN = 4;
// proc/reg00043.H

static const uint64_t INT_VC_AT_MACRO_KILL = 0x02010902ull;

static const uint32_t INT_VC_AT_MACRO_KILL_VALID = 0;
static const uint32_t INT_VC_AT_MACRO_KILL_VSD_TYPE = 12;
static const uint32_t INT_VC_AT_MACRO_KILL_VSD_TYPE_LEN = 4;
static const uint32_t INT_VC_AT_MACRO_KILL_BLOCKID = 28;
static const uint32_t INT_VC_AT_MACRO_KILL_BLOCKID_LEN = 4;
static const uint32_t INT_VC_AT_MACRO_KILL_OFFSET = 48;
static const uint32_t INT_VC_AT_MACRO_KILL_OFFSET_LEN = 13;
// proc/reg00043.H

static const uint64_t INT_VC_AT_MACRO_KILL_MASK = 0x02010903ull;

static const uint32_t INT_VC_AT_MACRO_KILL_MASK_VSD_TYPE = 12;
static const uint32_t INT_VC_AT_MACRO_KILL_MASK_VSD_TYPE_LEN = 4;
static const uint32_t INT_VC_AT_MACRO_KILL_MASK_BLOCKID = 28;
static const uint32_t INT_VC_AT_MACRO_KILL_MASK_BLOCKID_LEN = 4;
static const uint32_t INT_VC_AT_MACRO_KILL_MASK_OFFSET = 48;
static const uint32_t INT_VC_AT_MACRO_KILL_MASK_OFFSET_LEN = 13;
// proc/reg00043.H

static const uint64_t INT_VC_ENDC_SYNC_DONE = 0x02010984ull;
// proc/reg00043.H

static const uint64_t INT_VC_ENDC_WATCH0_SPEC = 0x020109a0ull;

static const uint32_t INT_VC_ENDC_WATCH0_SPEC_CONFLICT = 0;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_RESERVED_1_7 = 1;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_RESERVED_1_7_LEN = 7;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_FULL = 8;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_RESERVED_9_27 = 9;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_RESERVED_9_27_LEN = 19;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_BLOCKID = 28;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_BLOCKID_LEN = 4;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_RESERVED_32_39 = 32;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_RESERVED_32_39_LEN = 8;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_OFFSET = 40;
static const uint32_t INT_VC_ENDC_WATCH0_SPEC_OFFSET_LEN = 24;
// proc/reg00043.H

static const uint64_t INT_VC_ENDC_WATCH2_DATA0 = 0x020109b4ull;
// proc/reg00043.H

static const uint64_t INT_VC_INFO_ERR_G0 = 0x020109c6ull;

static const uint32_t INT_VC_INFO_ERR_G0_INT_VC_INFO_ERR_G0_ERROR = 0;
static const uint32_t INT_VC_INFO_ERR_G0_INT_VC_INFO_ERR_G0_ERROR_LEN = 64;
// proc/reg00043.H

static const uint64_t INT_VC_NVC_BLOCK_MODE = 0x0201090eull;

static const uint32_t INT_VC_NVC_BLOCK_MODE_INT_VC_NVC_BLOCK_MODE = 0;
static const uint32_t INT_VC_NVC_BLOCK_MODE_INT_VC_NVC_BLOCK_MODE_LEN = 32;
// proc/reg00043.H

static const uint64_t INT_VC_WOF_ERR_G2 = 0x020109d2ull;

static const uint32_t INT_VC_WOF_ERR_G2_ENDC_EQA_SLOT_OVERFLOW = 0;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_CRD_OR_RESP_ERROR = 1;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PTAG_ASSIGN_ERROR = 2;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PTAG_RELEASE_ERROR = 3;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_REPLAY_ERROR = 4;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PARITY_ERROR = 5;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_TAG_SRAM_ECC_UE = 6;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_STATE_SRAM_ECC_UE = 7;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_WATCH_SRAM_ECC_UE = 8;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_DATA_SRAM_ECC_UE = 9;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_CTRL_SRAM_ECC_UE = 10;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_REM_RSP_SRAM_ECC_UE = 11;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_REM_LOC_SRAM_ECC_UE = 12;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_ARX_DATA_ECC_UE = 13;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_UNLOCK_FIFO_OVERFLOW = 14;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_LOAD_OVERFLOW = 15;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_LOAD_TAG_ERROR = 16;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_RSD_CI_STR_CRD_ERROR = 17;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_RESPONSE_FIFO_OVERFLOW = 18;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_19 = 19;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_TAG_SRAM_ECC_CE = 20;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_STATE_SRAM_ECC_CE = 21;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_WATCH_SRAM_ECC_CE = 22;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_DATA_SRAM_ECC_CE = 23;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_CTRL_SRAM_ECC_CE = 24;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_REM_RSP_SRAM_ECC_CE = 25;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_REM_LOC_SRAM_ECC_CE = 26;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_ARX_DATA_ECC_CE = 27;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_28 = 28;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_29 = 29;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_30 = 30;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_31 = 31;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_WATCH_ERROR = 32;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_33 = 33;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_34 = 34;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_35 = 35;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_36 = 36;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_MULTISYNC = 37;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_38 = 38;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_0 = 39;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_1 = 40;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_2 = 41;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_3 = 42;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_4 = 43;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_5 = 44;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_6 = 45;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_7 = 46;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_8 = 47;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_9 = 48;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_10 = 49;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_11 = 50;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_12 = 51;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_13 = 52;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_14 = 53;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_15 = 54;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_16 = 55;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_17 = 56;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_18 = 57;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_19 = 58;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_20 = 59;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_21 = 60;
static const uint32_t INT_VC_WOF_ERR_G2_ENDC_PROC_ERROR_22 = 61;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_62 = 62;
static const uint32_t INT_VC_WOF_ERR_G2_RESERVED_63 = 63;
// proc/reg00043.H

static const uint64_t MCD_BANK0_RW = 0x0301080full;

static const uint32_t MCD_BANK0_RW_ACCESS_EN = 0;
static const uint32_t MCD_BANK0_RW_WR_ENABLE = 1;
static const uint32_t MCD_BANK0_RW_REQ_PEND = 3;
static const uint32_t MCD_BANK0_RW_READ_STATUS = 4;
static const uint32_t MCD_BANK0_RW_WRITE_MODE = 5;
static const uint32_t MCD_BANK0_RW_WRITE_STATUS = 6;
static const uint32_t MCD_BANK0_RW_ADDR = 8;
static const uint32_t MCD_BANK0_RW_ADDR_LEN = 15;
static const uint32_t MCD_BANK0_RW_RDWR_DATA = 28;
static const uint32_t MCD_BANK0_RW_RDWR_DATA_LEN = 36;
// proc/reg00043.H

static const uint64_t MCD_ECAP = 0x03010812ull;

static const uint32_t MCD_ECAP_ECAP_ECC_CLEAR = 0;
static const uint32_t MCD_ECAP_ECAP_ECC_UE = 2;
static const uint32_t MCD_ECAP_ECAP_ECC_CE = 3;
static const uint32_t MCD_ECAP_ECAP_ECC_ERROR_COUNT = 4;
static const uint32_t MCD_ECAP_ECAP_ECC_ERROR_COUNT_LEN = 4;
static const uint32_t MCD_ECAP_ECAP_ECC_ERROR_ADDR = 10;
static const uint32_t MCD_ECAP_ECAP_ECC_ERROR_ADDR_LEN = 14;
static const uint32_t MCD_ECAP_ECAP_ECC_SYNDROME = 24;
static const uint32_t MCD_ECAP_ECAP_ECC_SYNDROME_LEN = 8;
static const uint32_t MCD_ECAP_ECAP_SLICE0_CFG_ECC_UE_ERR = 33;
static const uint32_t MCD_ECAP_ECAP_SLICE0_CFG_ECC_CE_ERR = 34;
static const uint32_t MCD_ECAP_ECAP_SLICE1_CFG_ECC_UE_ERR = 35;
static const uint32_t MCD_ECAP_ECAP_SLICE1_CFG_ECC_CE_ERR = 36;
static const uint32_t MCD_ECAP_ECAP_SLICE2_CFG_ECC_UE_ERR = 37;
static const uint32_t MCD_ECAP_ECAP_SLICE2_CFG_ECC_CE_ERR = 38;
static const uint32_t MCD_ECAP_ECAP_SLICE3_CFG_ECC_UE_ERR = 39;
static const uint32_t MCD_ECAP_ECAP_SLICE3_CFG_ECC_CE_ERR = 40;
static const uint32_t MCD_ECAP_ECAP_PRESP_RTY_OTHER = 41;
static const uint32_t MCD_ECAP_ECAP_REC_SM_ERROR_ERR = 42;
static const uint32_t MCD_ECAP_ECAP_REC_PB_SM_ERROR_ERR = 43;
static const uint32_t MCD_ECAP_ECAP_ADDR_ERROR_PULSE = 44;
static const uint32_t MCD_ECAP_ECAP_RCMD0_ADDR_PARITY_ERROR = 45;
static const uint32_t MCD_ECAP_ECAP_RCMD1_ADDR_PARITY_ERROR = 46;
static const uint32_t MCD_ECAP_ECAP_RCMD2_ADDR_PARITY_ERROR = 47;
static const uint32_t MCD_ECAP_ECAP_RCMD3_ADDR_PARITY_ERROR = 48;
static const uint32_t MCD_ECAP_ECAP_WARB_INVALID_CASE_ERROR = 49;
static const uint32_t MCD_ECAP_ECAP_INVALID_CRESP_ERROR = 50;
static const uint32_t MCD_ECAP_ECAP_TTAG_PARITY_ERROR = 51;
static const uint32_t MCD_ECAP_ECAP_RDADDR_ARB_BAD_HAND = 52;
static const uint32_t MCD_ECAP_RDWR_UPDATE_ERROR = 53;
static const uint32_t MCD_ECAP_REC_UPDATE_ERROR = 54;
static const uint32_t MCD_ECAP_REC_ACK_DEAD_ERROR = 55;
// proc/reg00043.H

static const uint64_t NX_DMA_SU_INBOUND_WRITE_CONTROL = 0x02011042ull;

static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_GZIPCOMP_MAX_INRD = 8;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_GZIPCOMP_MAX_INRD_LEN = 4;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_GZIPDECOMP_MAX_INRD = 12;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_GZIPDECOMP_MAX_INRD_LEN = 4;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_GZIP_COMP_PREFETCH_ENABLE = 16;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_GZIP_DECOMP_PREFETCH_ENABLE = 17;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_EFT_COMP_PREFETCH_ENABLE = 23;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_EFT_DECOMP_PREFETCH_ENABLE = 24;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_SYM_MAX_INRD = 25;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_SYM_MAX_INRD_LEN = 4;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_EFTCOMP_MAX_INRD = 33;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_EFTCOMP_MAX_INRD_LEN = 4;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_EFTDECOMP_MAX_INRD = 37;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_EFTDECOMP_MAX_INRD_LEN = 4;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_SYM_CPB_CHECK_DISABLE = 48;
static const uint32_t NX_DMA_SU_INBOUND_WRITE_CONTROL_EFT_SPBC_WRITE_ENABLE = 56;
// proc/reg00043.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG = 0x02011095ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_WR_DISABLE_LN = 0;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_WR_DISABLE_GROUP = 1;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_WR_DISABLE_NN_RN = 3;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_RD_DISABLE_LN = 4;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_RD_DISABLE_GROUP = 5;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS = 6;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_RD_DISABLE_NN_RN = 7;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_UMAC_WR_DISABLE_LN = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_UMAC_WR_DISABLE_GROUP = 9;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_UMAC_WR_DISABLE_VG_NOT_SYS = 10;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_UMAC_WR_DISABLE_NN_RN = 11;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_UMAC_RD_DISABLE_LN = 12;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_UMAC_RD_DISABLE_GROUP = 13;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_UMAC_RD_DISABLE_VG_NOT_SYS = 14;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_UMAC_RD_DISABLE_NN_RN = 15;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_NX_FREEZE_MODES = 16;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_NX_FREEZE_MODES_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_RESERVED_18_19 = 18;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_RESERVED_18_19_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_WR_NOT_INJECT = 20;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_PARTIAL_WRT_NOT_INJECT = 21;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_RD_GO_M_QOS = 22;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_RESERVED_23 = 23;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_SKIP_G = 24;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DATA_ARB_LFSR_CONFIG = 25;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DATA_ARB_LFSR_CONFIG_LEN = 2;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE = 27;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_RESERVED_28 = 28;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_CFG_PUMP_MODE = 29;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DISABLE_FLOW_SCOPE = 30;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DISABLE_PMU_SNOOPING = 31;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_ENABLE_PMU_CNT_RESET = 32;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DISABLE_WRP = 33;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_SMF_DISABLE = 34;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_RESERVED_35_39 = 35;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_RESERVED_35_39_LEN = 5;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK = 40;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK_LEN = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK = 48;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK_LEN = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_RESERVED_56_62 = 56;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_MODE_REG_RESERVED_56_62_LEN = 7;
// proc/reg00043.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MISC_CONTROL_REG = 0x020110a8ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MISC_CONTROL_REG_HANG_POLL_SCALE = 4;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MISC_CONTROL_REG_HANG_POLL_SCALE_LEN = 4;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MISC_CONTROL_REG_HANG_DATA_SCALE = 8;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MISC_CONTROL_REG_HANG_DATA_SCALE_LEN = 4;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MISC_CONTROL_REG_HANG_SHM_SCALE = 12;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MISC_CONTROL_REG_HANG_SHM_SCALE_LEN = 4;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MISC_CONTROL_REG_ERAT_DATA_POLL_SCALE = 16;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_MISC_CONTROL_REG_ERAT_DATA_POLL_SCALE_LEN = 4;
// proc/reg00043.H

static const uint64_t NX_PBI_CQ_WRAP_DEBUG_SNAPSHOT_1 = 0x020110a5ull;

static const uint32_t NX_PBI_CQ_WRAP_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87 = 0;
static const uint32_t NX_PBI_CQ_WRAP_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87_LEN = 24;
// proc/reg00043.H

static const uint64_t PB_COM_ES3_CR_ERROR = 0x030113acull;
// proc/reg00043.H

static const uint64_t PB_PTLSCOM23_FP01_CFG = 0x1101180aull;

static const uint32_t PB_PTLSCOM23_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 = 0;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_DISABLE_GATHERING = 1;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_DISABLE_CMD_COMPRESSION = 2;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_DISABLE_PRSP_COMPRESSION = 3;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_LL_CREDIT_LO_LIMIT = 4;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_LL_CREDIT_PS_LIMIT = 12;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP = 20;
static const uint32_t PB_PTLSCOM23_FP01_CFG_01_CMD_EXP_TIME = 21;
static const uint32_t PB_PTLSCOM23_FP01_CFG_01_CMD_EXP_TIME_LEN = 3;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_RUN_AFTER_FRAME_ERROR = 24;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST = 25;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_PRS_SPARE = 26;
static const uint32_t PB_PTLSCOM23_FP01_CFG_0_PRS_SPARE_LEN = 6;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 = 32;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_DISABLE_GATHERING = 33;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_DISABLE_CMD_COMPRESSION = 34;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_DISABLE_PRSP_COMPRESSION = 35;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_LL_CREDIT_LO_LIMIT = 36;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_LL_CREDIT_PS_LIMIT = 44;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP = 52;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_FMR_SPARE = 53;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_FMR_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_RUN_AFTER_FRAME_ERROR = 56;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST = 57;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_PRS_SPARE = 58;
static const uint32_t PB_PTLSCOM23_FP01_CFG_1_PRS_SPARE_LEN = 6;
// proc/reg00043.H

static const uint64_t PB_PTLSCOM23_MISC_CFG = 0x11011825ull;

static const uint32_t PB_PTLSCOM23_MISC_CFG_SCOM_PTLX0_ENABLE = 0;
static const uint32_t PB_PTLSCOM23_MISC_CFG_SCOM_PTLX1_ENABLE = 1;
static const uint32_t PB_PTLSCOM23_MISC_CFG_SCOM_PTLY0_ENABLE = 2;
static const uint32_t PB_PTLSCOM23_MISC_CFG_SCOM_PTLY1_ENABLE = 3;
static const uint32_t PB_PTLSCOM23_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR = 4;
static const uint32_t PB_PTLSCOM23_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR = 5;
static const uint32_t PB_PTLSCOM23_MISC_CFG_SCOM_PTLX_RESET_KEEPER = 6;
static const uint32_t PB_PTLSCOM23_MISC_CFG_SCOM_PTLY_RESET_KEEPER = 7;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_0_ENABLE = 8;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_1_ENABLE = 9;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_2_ENABLE = 10;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_3_ENABLE = 11;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 = 12;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN = 13;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 = 14;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN = 15;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 = 16;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN = 17;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 = 18;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN = 19;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 = 20;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 = 21;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 = 22;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 = 23;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 = 24;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 = 25;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 = 26;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 = 27;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 = 28;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 = 29;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 = 30;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 = 31;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 = 32;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 = 33;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 = 34;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 = 35;
static const uint32_t PB_PTLSCOM23_MISC_CFG_SCOM_PTLX_EMULATION_MODE = 36;
static const uint32_t PB_PTLSCOM23_MISC_CFG_SCOM_PTLY_EMULATION_MODE = 37;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TOD_EVN_IB_MUX_CTL = 38;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TOD_EVN_IB_MUX_CTL_LEN = 2;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TOD_ODD_IB_MUX_CTL = 40;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TOD_ODD_IB_MUX_CTL_LEN = 2;
static const uint32_t PB_PTLSCOM23_MISC_CFG_TRANSPORT_PRI_BUS_CTL = 42;
static const uint32_t PB_PTLSCOM23_MISC_CFG_MISC_SPARE = 43;
static const uint32_t PB_PTLSCOM23_MISC_CFG_MISC_SPARE_LEN = 9;
// proc/reg00043.H

static const uint64_t PB_PTLSCOM45_DOB01_DIB01_INT_ERR_REG = 0x12011828ull;
// proc/reg00043.H

static const uint64_t PB_PTLSCOM45_FP23_CFG = 0x1201180bull;

static const uint32_t PB_PTLSCOM45_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 = 0;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_DISABLE_GATHERING = 1;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_DISABLE_CMD_COMPRESSION = 2;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_DISABLE_PRSP_COMPRESSION = 3;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_LL_CREDIT_LO_LIMIT = 4;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_LL_CREDIT_PS_LIMIT = 12;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP = 20;
static const uint32_t PB_PTLSCOM45_FP23_CFG_23_CMD_EXP_TIME = 21;
static const uint32_t PB_PTLSCOM45_FP23_CFG_23_CMD_EXP_TIME_LEN = 3;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_RUN_AFTER_FRAME_ERROR = 24;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST = 25;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_PRS_SPARE = 26;
static const uint32_t PB_PTLSCOM45_FP23_CFG_2_PRS_SPARE_LEN = 6;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 = 32;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_DISABLE_GATHERING = 33;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_DISABLE_CMD_COMPRESSION = 34;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_DISABLE_PRSP_COMPRESSION = 35;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_LL_CREDIT_LO_LIMIT = 36;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_LL_CREDIT_PS_LIMIT = 44;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP = 52;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_FMR_SPARE = 53;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_FMR_SPARE_LEN = 3;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_RUN_AFTER_FRAME_ERROR = 56;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST = 57;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_PRS_SPARE = 58;
static const uint32_t PB_PTLSCOM45_FP23_CFG_3_PRS_SPARE_LEN = 6;
// proc/reg00043.H

static const uint64_t PB_PTLSCOM45_PMU3_CNPM_COUNTER = 0x12011824ull;
// proc/reg00043.H

static const uint64_t PB_PTLSCOM67_PMU0_TLPM_COUNTER = 0x1301181bull;
// proc/reg00043.H

static const uint64_t PB_BRIDGE_HCA_DECAY_1_CONTROL_REG = 0x03011d53ull;

static const uint32_t PB_BRIDGE_HCA_DECAY_1_CONTROL_REG_ENABLE = 0;
static const uint32_t PB_BRIDGE_HCA_DECAY_1_CONTROL_REG_DELAY = 1;
static const uint32_t PB_BRIDGE_HCA_DECAY_1_CONTROL_REG_DELAY_LEN = 6;
// proc/reg00043.H

static const uint64_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CFG = 0x03011c88ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CFG_OPER_HANG_DIV_RATIO = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CFG_OPER_HANG_DIV_RATIO_LEN = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CFG_RTY_DRP_COUNT = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CFG_RTY_DRP_COUNT_LEN = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR = 9;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CFG_DIS_RETRY_BACKOFF = 10;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_CFG_DIS_OPER_HANG = 11;
// proc/reg00043.H

static const uint64_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TRIG = 0x03011c84ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TRIG_START = 0;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TRIG_STOP = 1;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TRIG_PAUSE = 2;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TRIG_STOP_ALT = 3;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TRIG_RESET = 4;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TRIG_MARK_VALID = 5;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TRIG_MARK_TYPE = 6;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_TRIG_MARK_TYPE_LEN = 10;
// proc/reg00043.H

static const uint64_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT = 0x03011cc7ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT_TTYPEFILT_PAT = 1;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT_TTYPEFILT_PAT_LEN = 7;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT_TSIZEFILT_PAT = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT_TSIZEFILT_PAT_LEN = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT_TTYPEFILT_MASK = 17;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT_TTYPEFILT_MASK_LEN = 7;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT_TSIZEFILT_MASK = 24;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT_TSIZEFILT_MASK_LEN = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT = 32;
static const uint32_t PB_BRIDGE_NHTM_NHTM1_SC_HTM_TTYPEFILT_CRESPFILT_INVERT = 33;
// proc/reg00043.H

static const uint64_t PSI_MAC_SCOM_REGS_RX_CNTL = 0x03012c20ull;

static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_PATTERN_CHECK_EN = 1;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_PATTERN_SEL = 2;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_PATTERN_SEL_LEN = 2;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_CLK_INVERT = 4;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_LANE_INVERT = 5;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_PDWN = 6;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_CLK_DLY = 7;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_CLK_DLY_LEN = 7;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_DATA_DLY = 14;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_DATA_DLY_LEN = 7;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_DEGLITCH_CLK_DLY = 21;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_DEGLITCH_CLK_DLY_LEN = 5;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_DEGLITCH_DATA_DLY = 26;
static const uint32_t PSI_MAC_SCOM_REGS_RX_CNTL_DEGLITCH_DATA_DLY_LEN = 5;
// proc/reg00043.H

static const uint64_t TP_LPC_SYNC_FIR_WOF_REG = 0x030121c8ull;

static const uint32_t TP_LPC_SYNC_FIR_WOF_REG_SYNC_FIR_WOF = 0;
static const uint32_t TP_LPC_SYNC_FIR_WOF_REG_SYNC_FIR_WOF_LEN = 6;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_EPS_DBG_INST1_COND_REG_3 = 0x020107c3ull;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_EPS_DBG_INST2_COND_REG_3 = 0x020107c6ull;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3 = 0x02040083ull;

static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_XSTOP_ERR = 0;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_RECOV_ERR = 1;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_SPATTN_ERR = 2;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_LXSTOP_ERR = 3;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_ANY_HOSTATTN_ERR = 4;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYSTEM_XSTOP = 5;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_OOB1 = 6;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 = 21;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 = 22;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 = 23;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 = 24;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 = 25;
static const uint32_t TP_TCN0_N0_EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 = 26;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_EPS_FIR_MODE_REG = 0x02040088ull;

static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_XSTOP_LOCK = 0;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV = 1;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN = 2;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP = 3;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN = 4;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_MODE_REG05 = 5;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR = 6;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_MODE_REG07 = 7;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_MODE_REG08 = 8;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR = 9;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_MODE_REG10 = 10;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_MODE_REG11 = 11;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_MODE_REG12 = 12;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_MODE_REG13 = 13;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_MODE_REG14 = 14;
static const uint32_t TP_TCN0_N0_EPS_FIR_MODE_REG_MODE_REG15 = 15;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG = 0x02050010ull;

static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE = 0;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG_DISABLE_SKITTER_STICKINESS = 1;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL = 4;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL = 6;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS = 8;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE_WITH_TRIGGER = 44;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_DATA_V_LT = 45;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG = 0x0205000full;

static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_LOCAL_XSTOP_UNMASKED = 0x02040013ull;

static const uint32_t TP_TCN0_N0_LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN = 1;
static const uint32_t TP_TCN0_N0_LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN_LEN = 15;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_OPCG_REG1 = 0x02030003ull;

static const uint32_t TP_TCN0_N0_OPCG_REG1_SCAN_COUNT = 0;
static const uint32_t TP_TCN0_N0_OPCG_REG1_SCAN_COUNT_LEN = 12;
static const uint32_t TP_TCN0_N0_OPCG_REG1_MISR_A_VAL = 12;
static const uint32_t TP_TCN0_N0_OPCG_REG1_MISR_A_VAL_LEN = 12;
static const uint32_t TP_TCN0_N0_OPCG_REG1_MISR_B_VAL = 24;
static const uint32_t TP_TCN0_N0_OPCG_REG1_MISR_B_VAL_LEN = 12;
static const uint32_t TP_TCN0_N0_OPCG_REG1_MISR_INIT_WAIT = 36;
static const uint32_t TP_TCN0_N0_OPCG_REG1_MISR_INIT_WAIT_LEN = 12;
static const uint32_t TP_TCN0_N0_OPCG_REG1_SCAN_CLK_USE_EVEN = 49;
static const uint32_t TP_TCN0_N0_OPCG_REG1_RTIM_THOLD_FORCE = 52;
static const uint32_t TP_TCN0_N0_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL = 53;
static const uint32_t TP_TCN0_N0_OPCG_REG1_SG_HIGH_DURING_FILL = 54;
static const uint32_t TP_TCN0_N0_OPCG_REG1_LBIST_SKITTER_CTL = 55;
static const uint32_t TP_TCN0_N0_OPCG_REG1_LBIST_SKITTER_CTL_LEN = 2;
static const uint32_t TP_TCN0_N0_OPCG_REG1_MISR_MODE = 57;
static const uint32_t TP_TCN0_N0_OPCG_REG1_INFINITE_MODE = 58;
static const uint32_t TP_TCN0_N0_OPCG_REG1_NSL_FILL_COUNT = 59;
static const uint32_t TP_TCN0_N0_OPCG_REG1_NSL_FILL_COUNT_LEN = 5;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_TRA0_TR0_CONFIG_0 = 0x02010403ull;

static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN0_N0_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_TRA0_TR1_CONFIG = 0x02010442ull;

static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_TRA0_TR1_CONFIG_9 = 0x02010449ull;

static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN0_N0_TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00043.H

static const uint64_t TP_TCN0_N0_TRA1_TR0_CONFIG = 0x02010482ull;

static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCN0_N0_TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_CLOCK_STAT_NSL = 0x03030009ull;

static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_PERV_NSL = 4;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT1_NSL = 5;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT2_NSL = 6;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT3_NSL = 7;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT4_NSL = 8;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT5_NSL = 9;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT6_NSL = 10;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT7_NSL = 11;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT8_NSL = 12;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT9_NSL = 13;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT10_NSL = 14;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT11_NSL = 15;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT12_NSL = 16;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT13_NSL = 17;
static const uint32_t TP_TCN1_N1_CLOCK_STAT_NSL_UNIT14_NSL = 18;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_CPLT_CTRL5_RW = 0x03000005ull;
static const uint64_t TP_TCN1_N1_CPLT_CTRL5_WO_CLEAR = 0x03000025ull;
static const uint64_t TP_TCN1_N1_CPLT_CTRL5_WO_OR = 0x03000015ull;

static const uint32_t TP_TCN1_N1_CPLT_CTRL5_0 = 0;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_1 = 1;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_2 = 2;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_3 = 3;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_4 = 4;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_5 = 5;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_6 = 6;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_7 = 7;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_8 = 8;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_9 = 9;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_10 = 10;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_11 = 11;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_12 = 12;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_13 = 13;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_14 = 14;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_15 = 15;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_16 = 16;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_17 = 17;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_18 = 18;
static const uint32_t TP_TCN1_N1_CPLT_CTRL5_19 = 19;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG = 0x03010000ull;

static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE = 4;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT = 5;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN = 2;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS = 7;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT = 9;
static const uint32_t TP_TCN1_N1_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN = 3;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_OPCG_REG0 = 0x03030002ull;

static const uint32_t TP_TCN1_N1_OPCG_REG0_RUNN_MODE = 0;
static const uint32_t TP_TCN1_N1_OPCG_REG0_OPCG_GO = 1;
static const uint32_t TP_TCN1_N1_OPCG_REG0_RUN_SCAN0 = 2;
static const uint32_t TP_TCN1_N1_OPCG_REG0_SCAN0_MODE = 3;
static const uint32_t TP_TCN1_N1_OPCG_REG0_OPCG_IN_SLAVE_MODE = 4;
static const uint32_t TP_TCN1_N1_OPCG_REG0_OPCG_IN_MASTER_MODE = 5;
static const uint32_t TP_TCN1_N1_OPCG_REG0_KEEP_MS_MODE = 6;
static const uint32_t TP_TCN1_N1_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL = 7;
static const uint32_t TP_TCN1_N1_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL = 8;
static const uint32_t TP_TCN1_N1_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR = 11;
static const uint32_t TP_TCN1_N1_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR = 12;
static const uint32_t TP_TCN1_N1_OPCG_REG0_STOP_RUNN_ON_XSTOP = 13;
static const uint32_t TP_TCN1_N1_OPCG_REG0_OPCG_STARTS_BIST = 14;
static const uint32_t TP_TCN1_N1_OPCG_REG0_LOOP_COUNT = 21;
static const uint32_t TP_TCN1_N1_OPCG_REG0_LOOP_COUNT_LEN = 43;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA0_TR0_TRACE_HI_DATA_REG = 0x03010400ull;

static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA0_TR1_CONFIG_1 = 0x03010444ull;

static const uint32_t TP_TCN1_N1_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN1_N1_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA2_TR0_CONFIG_0 = 0x03010503ull;

static const uint32_t TP_TCN1_N1_TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCN1_N1_TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA2_TR1_CONFIG_9 = 0x03010549ull;

static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN1_N1_TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG = 0x030105c1ull;

static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCN1_N1_TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA4_TR1_CONFIG = 0x03010642ull;

static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCN1_N1_TRA4_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA5_TR0_CONFIG = 0x03010682ull;

static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA5_TR0_CONFIG_1 = 0x03010684ull;

static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCN1_N1_TRA5_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_TRA7_TR0_CONFIG_9 = 0x03010789ull;

static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCN1_N1_TRA7_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// proc/reg00044.H

static const uint64_t TP_TCN1_N1_XSTOP3 = 0x0303000eull;

static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_MASK_B = 0;
static const uint32_t TP_TCN1_N1_XSTOP3_ALIGNED_XSTOP3 = 1;
static const uint32_t TP_TCN1_N1_XSTOP3_TRIGGER_OPCG_ON_XSTOP3 = 2;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_WAIT_ALLWAYS = 3;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_PERV = 4;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT1 = 5;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT2 = 6;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT3 = 7;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT4 = 8;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT5 = 9;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT6 = 10;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT7 = 11;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT8 = 12;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT9 = 13;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT10 = 14;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT11 = 15;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT12 = 16;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT13 = 17;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_UNIT14 = 18;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_WAIT_CYCLES = 48;
static const uint32_t TP_TCN1_N1_XSTOP3_XSTOP3_WAIT_CYCLES_LEN = 12;
// proc/reg00044.H

static const uint64_t TP_TPBR_AD_LPC_STATUS_REG = 0x00090043ull;

static const uint32_t TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS = 0;
static const uint32_t TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS = 10;
static const uint32_t TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS = 11;
// proc/reg00044.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAFIRACT0 = 0x03011dc6ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0 = 0;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0_LEN = 40;
// proc/reg00044.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAERRRPT2 = 0x01010cceull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT2_SLV_INTERNAL_ERR = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT2_SLV_INTERNAL_ERR_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT2_BCDE_INTERNAL_ERR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT2_BCDE_INTERNAL_ERR_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT2_BCUE_INTERNAL_ERR = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT2_BCUE_INTERNAL_ERR_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT2_AXFLOW_ERR = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT2_AXFLOW_ERR_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT2_AXPUSH_WRERR = 19;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT2_AXPUSH_WRERR_LEN = 2;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_PBAOCR2_OCI = 0xc00400e0ull;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCR2_PIB = 0x0006801cull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAOCR2_PBAOCR2_COUNT = 44;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCR2_PBAOCR2_COUNT_LEN = 20;
// proc/reg00044.H

static const uint64_t TP_TPBR_PBA_PBAO_PBARBUFVAL5 = 0x01010cd5ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR_LEN = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT = 31;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS = 33;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS_LEN = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID = 41;
static const uint32_t TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID_LEN = 3;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_OCI = 0xc0040030ull;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_PIB = 0x00068006ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4 = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14 = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE = 15;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL = 18;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W = 19;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A = 20;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C = 22;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23 = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER = 24;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT = 25;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR_LEN = 14;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50 = 50;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_OCI = 0xc0040108ull;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_PIB = 0x00068021ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11 = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV = 20;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV_LEN = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26 = 25;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM = 27;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV_LEN = 5;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHINC1_OCI = 0xc0040160ull;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSHINC1_PIB = 0x0006802cull;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDSTAT_OCI = 0xc0040110ull;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDSTAT_PIB = 0x00068022ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDSTAT_IN_PROGRESS = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDSTAT_ERROR = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDSTAT_PHASE_STATUS = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDSTAT_PHASE_STATUS_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDSTAT_CNT_STATUS = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDSTAT_CNT_STATUS_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDSTAT_RETRY_COUNT = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAXSNDSTAT_RETRY_COUNT_LEN = 8;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_ATTN_INTERRUPT_REG = 0x020f001aull;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_HOSTATTN_INTERRUPT_REG = 0x020f002bull;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG = 0x020f001eull;

static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN = 1;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP = 2;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK = 3;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT = 4;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO = 5;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE = 6;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE = 7;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS = 8;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS = 9;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS = 10;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS = 11;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS = 12;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN = 8;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS = 20;
static const uint32_t TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME = 21;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG = 0x030f03feull;

static const uint32_t TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_NET_PCBSLPERV_PRIMARY_ADDRESS_REG = 0x010f0000ull;
// proc/reg00044.H

static const uint64_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR = 0x0006d206ull;

static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR_LEN = 32;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_OCI = 0xc0000010ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RW = 0x00060002ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL_LEN = 4;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCI = 0xc0000008ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_RW = 0x00060001ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN = 23;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_OCI = 0xc0000020ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_RW = 0x00060004ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE = 12;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCI = 0xc0000100ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_WO = 0x00060020ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN = 3;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_OCI = 0xc00000c8ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_RO = 0x00060019ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING = 35;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_OCI = 0xc0010178ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_RO = 0x0006202full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID_LEN = 4;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCI = 0xc0010170ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_RO = 0x0006202eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN = 27;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCI = 0xc0010208ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_RO = 0x00062041ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN = 32;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_OCI = 0xc0010148ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_SCOM = 0x00062029ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE_LEN = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING = 31;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCI = 0xc0010140ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_RO = 0x00062028ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN = 32;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCI = 0xc0010088ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_WO = 0x00062011ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR_LEN = 3;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCI = 0xc0010180ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_RO = 0x00062030ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN = 30;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_OCI = 0xc0010400ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_RO = 0x00062080ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1_LEN = 32;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_OCI = 0xc0010430ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_RO = 0x00062086ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9_LEN = 32;
// proc/reg00044.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_OCI = 0xc0020028ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_RW = 0x00064005ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR_LEN = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE = 44;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE_LEN = 15;
// proc/reg00044.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCI = 0xc0020260ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_RO = 0x0006404cull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28_LEN = 32;
// proc/reg00044.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCI = 0xc0020228ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_RO = 0x00064045ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN = 32;
// proc/reg00044.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCI = 0xc00200c0ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_RO = 0x00064018ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING = 35;
// proc/reg00044.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_OCI = 0xc0020410ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_RO = 0x00064082ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5_LEN = 32;
// proc/reg00044.H

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_OCI = 0xc0020108ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RO = 0x00064021ull;
// proc/reg00044.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCI = 0xc0030268ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_RO = 0x0006604dull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29_LEN = 32;
// proc/reg00045.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OCI = 0xc0030080ull;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_SCOM = 0x00066010ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_DERP3_OCI = 0xc0060c30ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_DERP3_RW = 0x0006c186ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OCI = 0xc0063a00ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_RW = 0x0006c740ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2_LEN = 6;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSES1_OCI = 0xc00610b0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSES1_RW = 0x0006c216ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW = 1;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCI = 0xc00602a0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCI1 = 0xc00602a8ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCI2 = 0xc00602b0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW = 0x0006c054ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR = 0x0006c055ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR = 0x0006c056ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCI = 0xc0060100ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCI1 = 0xc0060108ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCI2 = 0xc0060110ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OISR1_RO = 0x0006c020ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR = 0x0006c021ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR = 0x0006c022ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH = 22;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL = 23;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL = 25;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH = 26;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY = 29;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY = 31;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_OCI = 0xc0063040ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_OCI1 = 0xc0063048ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO = 0x0006c608ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR = 0x0006c609ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 = 7;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCI = 0xc0062070ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_RO = 0x0006c40eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCI = 0xc0062090ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_RO = 0x0006c412ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCI = 0xc0062160ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_RO = 0x0006c42cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCI = 0xc0062180ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_RO = 0x0006c430ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_OCI = 0xc0062a58ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_RO = 0x0006c54bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD_LEN = 17;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_OCI = 0xc0062ab8ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_RO = 0x0006c557ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD_LEN = 17;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_OCI = 0xc0062220ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_RO = 0x0006c444ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD_LEN = 17;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_OCI = 0xc0063200ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_OCI1 = 0xc0063208ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO = 0x0006c640ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR = 0x0006c641ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7 = 7;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8 = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9 = 9;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10 = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11 = 11;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13 = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14 = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15 = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17 = 17;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19 = 19;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20 = 20;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21 = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22 = 22;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23 = 23;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24 = 24;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25 = 25;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26 = 26;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27 = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28 = 28;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29 = 29;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30 = 30;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31 = 31;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_OCI = 0xc0062b80ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_RO = 0x0006c570ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD_LEN = 17;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_OCI = 0xc0062bc0ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_RO = 0x0006c578ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD_LEN = 17;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_OCI = 0xc0063400ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_OCI1 = 0xc0063408ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO = 0x0006c680ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART = 0x0006c681ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7 = 7;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1_OCI = 0xc0064208ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1_RW = 0x0006c841ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1__BRIDGE_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1__DEVICE = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1__CPOL = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1__CPHA = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1__CLOCK_DIVIDER = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1__CLOCK_DIVIDER_LEN = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1_CR1_RESERVED_2 = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1_CR1_RESERVED_2_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2SCR1__NR_OF_FRAMES = 17;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PMC_SPIPSS_P2S_STATUS_REG_OCI = 0xc0064218ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PMC_SPIPSS_P2S_STATUS_REG_RO = 0x0006c843ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PMC_SPIPSS_P2S_STATUS_REG_P2S_ONGOING = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PMC_SPIPSS_P2S_STATUS_REG_RESERVED_1_4 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PMC_SPIPSS_P2S_STATUS_REG_RESERVED_1_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PMC_SPIPSS_P2S_STATUS_REG_P2S_WRITE_WHILE_BRIDGE_BUSY_ERR = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PMC_SPIPSS_P2S_STATUS_REG_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PMC_SPIPSS_P2S_STATUS_REG_P2S_FSM_ERR = 7;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCI = 0xc0063c30ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_RW = 0x0006c786ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW = 0x0006d004ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR = 0x0006d005ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR = 0x0006d006ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT = 6;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI = 0x0006d00cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113 = 0x00008071ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG124 = 0x0000807cull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG124_REGISTER124 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG124_REGISTER124_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG13 = 0x0000800dull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG13_REGISTER13 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG13_REGISTER13_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG24 = 0x00008018ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG24_REGISTER24 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG24_REGISTER24_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG45 = 0x0000802dull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG45_REGISTER45 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG45_REGISTER45_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG7 = 0x00008007ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG7_REGISTER7 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG7_REGISTER7_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG72 = 0x00008048ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG72_REGISTER72 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG72_REGISTER72_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG87 = 0x00008057ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG87_REGISTER87 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG87_REGISTER87_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG98 = 0x00008062ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG98_REGISTER98 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG98_REGISTER98_LEN = 64;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL2_RW = 0x01000002ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL2_WO_CLEAR = 0x01000022ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL2_WO_OR = 0x01000012ull;

static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_0_PGOOD = 4;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_1_PGOOD = 5;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_2_PGOOD = 6;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_3_PGOOD = 7;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_4_PGOOD = 8;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_5_PGOOD = 9;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_6_PGOOD = 10;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_7_PGOOD = 11;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_8_PGOOD = 12;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_9_PGOOD = 13;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_10_PGOOD = 14;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_11_PGOOD = 15;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_12_PGOOD = 16;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_13_PGOOD = 17;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL2_14_PGOOD = 18;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_CPLT_MASK0 = 0x01000101ull;

static const uint32_t TP_TPCHIP_TPC_CPLT_MASK0_ITR_MASK = 0;
static const uint32_t TP_TPCHIP_TPC_CPLT_MASK0_ITR_MASK_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR = 0x01000157ull;

static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_AVG = 1;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_AVG_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_AVG = 12;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_AVG_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_MAX = 21;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_MAX_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_MAX = 32;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_MAX_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_MIN = 41;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_MIN_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_MIN = 52;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_MIN_LEN = 5;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR = 0x01000156ull;

static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX = 1;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX = 12;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG = 21;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG = 32;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN = 41;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN = 52;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN_LEN = 5;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT = 0x01000155ull;

static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT = 1;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT = 12;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT_LEN = 5;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE = 60;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE = 61;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE = 62;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK = 63;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2 = 0x010107cfull;

static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t TP_TPCHIP_TPC_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1 = 0x01040107ull;

static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_00 = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_01 = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_02 = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_03 = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_04 = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_05 = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_06 = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_07 = 7;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_08 = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_09 = 9;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_10 = 10;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_11 = 11;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_12 = 12;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_13 = 13;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_14 = 14;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_15 = 15;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_16 = 16;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_17 = 17;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_18 = 18;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_19 = 19;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_20 = 20;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_21 = 21;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_22 = 22;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_23 = 23;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_24 = 24;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_25 = 25;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_26 = 26;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_27 = 27;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_28 = 28;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_29 = 29;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_30 = 30;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_31 = 31;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_32 = 32;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_33 = 33;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_34 = 34;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_35 = 35;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_36 = 36;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_37 = 37;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_38 = 38;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_39 = 39;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_40 = 40;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_41 = 41;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_42 = 42;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_43 = 43;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_44 = 44;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_45 = 45;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_46 = 46;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_47 = 47;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_48 = 48;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_49 = 49;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_50 = 50;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_51 = 51;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_52 = 52;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_53 = 53;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_54 = 54;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_55 = 55;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_56 = 56;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_57 = 57;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_58 = 58;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_59 = 59;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_60 = 60;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_61 = 61;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_62 = 62;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_LOCAL_ACTION1_63 = 63;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG = 0x01040088ull;

static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_XSTOP_LOCK = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV = 1;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN = 2;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP = 3;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN = 4;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_MODE_REG05 = 5;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR = 6;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_MODE_REG07 = 7;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_MODE_REG08 = 8;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR = 9;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_MODE_REG10 = 10;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_MODE_REG11 = 11;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_MODE_REG12 = 12;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_MODE_REG13 = 13;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_MODE_REG14 = 14;
static const uint32_t TP_TPCHIP_TPC_EPS_FIR_MODE_REG_MODE_REG15 = 15;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_EPS_PSC_WRITE_PROTECT_ENABLE_REG = 0x01010005ull;

static const uint32_t TP_TPCHIP_TPC_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_EPS_PSC_WRITE_PROTECT_RINGS_REG = 0x01010006ull;

static const uint32_t TP_TPCHIP_TPC_EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS = 0;
static const uint32_t TP_TPCHIP_TPC_EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_ITR_FMU_VMEAS_MIN_RESULT = 0x01020009ull;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_PHASE_COUNTER_RESET = 0x01030028ull;

static const uint32_t TP_TPCHIP_TPC_PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_SCAN32 = 0x01038000ull;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_SCAN64 = 0x0103e000ull;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG = 0x01010401ull;

static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TPCHIP_TPC_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// proc/reg00045.H

static const uint64_t TP_TPCHIP_TPC_XSTOP = 0x01040000ull;

static const uint32_t TP_TPCHIP_TPC_XSTOP_ANY_XSTOP = 0;
static const uint32_t TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP = 1;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN = 2;
static const uint32_t TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG = 3;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_PERV = 4;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN05 = 5;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN06 = 6;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN07 = 7;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN08 = 8;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN09 = 9;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN10 = 10;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN11 = 11;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN12 = 12;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN13 = 13;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN14 = 14;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN15 = 15;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN16 = 16;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN17 = 17;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN18 = 18;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN19 = 19;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN20 = 20;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN21 = 21;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN22 = 22;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN23 = 23;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN24 = 24;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN25 = 25;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN26 = 26;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN27 = 27;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN28 = 28;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN29 = 29;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN30 = 30;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN31 = 31;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN32 = 32;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN33 = 33;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN34 = 34;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN35 = 35;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN36 = 36;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN37 = 37;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN38 = 38;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN39 = 39;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN40 = 40;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN41 = 41;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN42 = 42;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN43 = 43;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN44 = 44;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN45 = 45;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN46 = 46;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN47 = 47;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN48 = 48;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN49 = 49;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN50 = 50;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN51 = 51;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN52 = 52;
static const uint32_t TP_TPCHIP_TPC_XSTOP_XSTOP_IN53 = 53;
// proc/reg00045.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMPLEMENT_MASK_FSI = 0x0000100cull;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMPLEMENT_MASK_FSI_BYTE = 0x00001030ull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMPLEMENT_MASK_COMPLEMENT_MASK_REG = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_COMPLEMENT_MASK_COMPLEMENT_MASK_REG_LEN = 32;
// proc/reg00045.H

static const uint64_t TP_TPVSB_FSI_W_I2C_WATER_MARK_REGISTER_A = 0x00001803ull;

static const uint32_t TP_TPVSB_FSI_W_I2C_WATER_MARK_REGISTER_A_WATERMARK_REG_000 = 16;
static const uint32_t TP_TPVSB_FSI_W_I2C_WATER_MARK_REGISTER_A_WATERMARK_REG_000_LEN = 16;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI = 0x0000288cull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE = 0x00002a30ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RW = 0x0005008cull;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_6_FSI = 0x00002886ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_6_FSI_BYTE = 0x00002a18ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_6_RW = 0x00050086ull;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_0_FSI = 0x000028c0ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_0_FSI_BYTE = 0x00002b00ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_0_RW = 0x000500c0ull;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL1_FSI = 0x00002941ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL1_FSI_BYTE = 0x00002d04ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL1_RO = 0x00050141ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL1_RCS_EVENTLOG_1 = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL1_RCS_EVENTLOG_1_LEN = 32;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI = 0x00002912ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE = 0x00002c48ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW = 0x00050112ull;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI = 0x00002815ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE = 0x00002854ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW = 0x00050015ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RESET_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BYPASS_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_BYPASS_CLKSEL_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLK_TEST_IN_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CONTROL_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CONTROL_DC_LEN = 28;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI = 0x00002937ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE = 0x00002cdcull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR = 0x00050137ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC = 23;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL = 24;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL = 25;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL = 26;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL = 27;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL = 28;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL = 29;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL = 30;
static const uint32_t
TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL = 31;
// proc/reg00046.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI = 0x0000283full;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE = 0x000028fcull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW = 0x0005003full;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8 = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8_LEN = 32;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_DATA_OUT = 0x000b0000ull;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_SBE_FIFO_GPIO_MODE = 0x000b0059ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI = 0x00000c22ull;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE = 0x00000c88ull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG_LEN = 32;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP0_FSI0 = 0x00003050ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP0_SCOMFSI0 = 0x00000c14ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCRSP1_FSI0 = 0x0000300cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MCRSP1_SCOMFSI0 = 0x00000c03ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDLYR_FSI0 = 0x00003004ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDLYR_SCOMFSI0 = 0x00000c01ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP1_FSI0 = 0x00003014ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MENP1_SCOMFSI0 = 0x00000c05ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP1_FSI0 = 0x000030d4ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP1_RO = 0x00000c35ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP1_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP1_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP1_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP1_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP1_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP1_2_LEN = 3;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MATRB0_FSI0 = 0x000035d8ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MATRB0_SCOMFSI0 = 0x00000d76ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDTRB0_FSI0 = 0x000035dcull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDTRB0_SCOMFSI0 = 0x00000d77ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP2_FSI0 = 0x000034d8ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP2_WO = 0x00000d36ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP2_GENERAL_RESET_2 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP2_ERROR_RESET_2 = 1;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP1_FSI0 = 0x00003434ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP1_SCOMFSI0 = 0x00000d0dull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCISC = 0x00000808ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SDMA = 0x00000804ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SISC = 0x00000808ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP4_FSI1 = 0x000030e0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP4_WO = 0x00000c38ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP4_GENERAL_RESET_4 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP4_ERROR_RESET_4 = 1;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP7_FSI1 = 0x0000304cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP7_SCOMFSI1 = 0x00000c13ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCMBL = 0x00000840ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCMDT = 0x0000082cull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SCRSIM0 = 0x00000858ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SMBR = 0x00000844ull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SSI1M = 0x0000081cull;
// proc/reg00046.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_PEEK4B8 = 0x000004b8ull;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER = 0x00070041ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_COUNT_N1 = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_COUNT_N1_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_COUNT_N2 = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_COUNT_N2_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_COUNT_RESERVED_A = 16;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_COUNT_RESERVED_A_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_LOOPCOUNT = 24;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_LOOPCOUNT_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_INTERNALCOUNT = 32;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_INTERNALCOUNT_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_SHIFTER_FSM_CONTROL = 40;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_SHIFTER_FSM_CONTROL_LEN = 8;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_N1_CONTROL = 48;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_N1_CONTROL_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_N2_CONTROL = 52;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_N2_CONTROL_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_COUNT_RESERVED_B = 56;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_COUNTER_COUNT_RESERVED_B_LEN = 8;
// proc/reg00046.H

static const uint64_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_SEQUENCER_OP_REG = 0x00070047ull;

static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_SEQUENCER_OP_REG_SEQUENCER_OP_Q = 0;
static const uint32_t TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN = 64;
// proc/reg00046.H

static const uint64_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL0_REG = 0x02011450ull;

static const uint32_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07 = 8;
static const uint32_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07_LEN = 32;
// proc/reg00046.H

static const uint64_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL1_REG = 0x02011451ull;

static const uint32_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15 = 8;
static const uint32_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15_LEN = 32;
// proc/reg00046.H

static const uint64_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL2_REG = 0x02011452ull;

static const uint32_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23 = 8;
static const uint32_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23_LEN = 32;
// proc/reg00046.H

static const uint64_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL3_REG = 0x02011453ull;

static const uint32_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31 = 8;
static const uint32_t VAS_VA_EG_SCF_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31_LEN = 32;
// proc/reg00046.H

static const uint64_t VAS_VA_EG_SCF_PBCFG0 = 0x0201144dull;

static const uint32_t VAS_VA_EG_SCF_PBCFG0_RESERVED_0_6 = 0;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_RESERVED_0_6_LEN = 7;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_HANG_POLL_MAX_CNT = 7;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_HANG_POLL_MAX_CNT_LEN = 4;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_SMF_CONFIG = 11;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_HANG_NX_MAX_CNT = 15;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_HANG_NX_MAX_CNT_LEN = 4;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_DISABLE_WR_RD_PUSH = 19;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_INJ_CE = 20;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_INJ_UE = 21;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_INJ_SUE = 22;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_INJ_ARRAY_SEL = 23;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_INJ_FREQ = 24;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_QUEUE_TO_TRACE = 25;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_QUEUE_TO_TRACE_LEN = 4;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_QUEUE_DISABLES = 29;
static const uint32_t VAS_VA_EG_SCF_PBCFG0_PBCFG_0_QUEUE_DISABLES_LEN = 3;
// proc/reg00046.H

static const uint64_t VAS_VA_RG_SCF_DBGTRIG = 0x0201142full;

static const uint32_t VAS_VA_RG_SCF_DBGTRIG_BITS_64_87 = 0;
static const uint32_t VAS_VA_RG_SCF_DBGTRIG_BITS_64_87_LEN = 24;
static const uint32_t VAS_VA_RG_SCF_DBGTRIG_TRIGGER_BITS = 24;
static const uint32_t VAS_VA_RG_SCF_DBGTRIG_TRIGGER_BITS_LEN = 4;
// proc/reg00046.H

static const uint64_t VAS_VA_RG_SCF_FIR_ACTION0_REG = 0x02011406ull;

static const uint32_t VAS_VA_RG_SCF_FIR_ACTION0_REG_VAS_FIR_ACTION0 = 0;
static const uint32_t VAS_VA_RG_SCF_FIR_ACTION0_REG_VAS_FIR_ACTION0_LEN = 52;
// proc/reg00046.H

static const uint64_t VAS_VA_RG_SCF_FIR_ACTION1_REG = 0x02011407ull;

static const uint32_t VAS_VA_RG_SCF_FIR_ACTION1_REG_VAS_FIR_ACTION1 = 0;
static const uint32_t VAS_VA_RG_SCF_FIR_ACTION1_REG_VAS_FIR_ACTION1_LEN = 52;
// proc/reg00046.H

}
}
#include "proc/reg00043.H"
#include "proc/reg00044.H"
#include "proc/reg00045.H"
#include "proc/reg00046.H"
#endif
