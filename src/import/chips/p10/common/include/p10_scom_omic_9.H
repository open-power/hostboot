/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_9.H $       */
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

#ifndef __p10_scom_omic_9_H_
#define __p10_scom_omic_9_H_


namespace scomt
{
namespace omic
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_MODE12_PG = 0x800860600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC = 50;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC_LEN = 3;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS = 53;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B = 54;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG = 0x8008b0600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH = 48;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH_LEN = 5;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT = 53;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT_LEN = 4;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR = 57;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG = 58;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG_LEN = 3;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4 = 61;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4_LEN = 2;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH = 63;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_MODE8_PG = 0x800840600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME = 48;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME_LEN = 5;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG = 0x800938600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ = 48;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN = 11;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT10_PG = 0x8009d0600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0_LEN = 8;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT20_PG = 0x800a20600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME_LEN = 6;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME = 54;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME_LEN = 6;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE = 61;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE = 62;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS = 63;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT30_PG = 0x800a70600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23_LEN = 8;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNTL3_PG = 0x800998600c00003full;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL1_PL = 0x8003c0690c00003full;

static const uint32_t RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_14_PLREGS_RX_STAT1_PL = 0x8003e0690c00003full;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL2_PL = 0x8003c8730c00003full;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL1_PL = 0x8003c0760c00003full;

static const uint32_t RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_22_PLREGS_RX_STAT1_PL = 0x8003e0760c00003full;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL1_PL = 0x8003c06e0c00003full;

static const uint32_t RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_6_PLREGS_RX_STAT1_PL = 0x8003e06e0c00003full;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_9_PLREGS_RX_MODE1_PL = 0x8003d0660c00003full;

static const uint32_t RX0_RXCTL_DATASM_9_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RX0_RXCTL_DATASM_9_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RX0_RXCTL_DATASM_9_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RX0_RXCTL_DATASM_9_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RX0_RXCTL_DATASM_9_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX5_PL = 0x800380600c00003full;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800318600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x800118600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x800168600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b8600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d8600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x800228600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x800278600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x800290600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL = 0x800370610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL = 0x800340610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_STAT3_PL = 0x8003a0610c00003full;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f0610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x800240610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c8610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL17_PL = 0x800088610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL = 0x800378620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL = 0x800328620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_STAT4_PL = 0x8003a8620c00003full;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a0620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f0620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x800140620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x800190620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b8620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL16_PL = 0x800080620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL6_PL = 0x800030620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x800218630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x800268630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL3_PL = 0x800018630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL = 0x800360640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x800110640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x800160640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b0640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x800220640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// omic/reg00148.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x800270640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x800298640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL = 0x800048640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL = 0x800388650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_STAT6_PL = 0x8003b8650c00003full;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_FIR_PL = 0x800308650c00003full;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b8650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f8650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x800248650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c0650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_MODE7_PL = 0x8003506e0c00003full;

static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_STAT1_PL = 0x8003906e0c00003full;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e06e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002306e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_CNTLX9_PL = 0x8000486e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d86f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001286f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001786f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c86f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002806f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d06f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x800098670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e8670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x800138670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x800188670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c8670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x800208670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x800258670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_CNTL18_PL = 0x800090670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x800000670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_CNTL6_PL = 0x800388660c00003full;

static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_STAT6_PL = 0x8003b8660c00003full;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b0660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x800100660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x800150660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a0660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a8660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE3_PL = 0x8003306d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_STAT5_PL = 0x8003b06d0c00003full;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001106d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001606d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b06d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002206d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002706d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002986d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL13_PL = 0x8000686d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_BIT_REGS_FIR_PL = 0x8003086c0c00003full;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b86c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f86c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002486c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// omic/reg00149.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c06c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL15_PL = 0x8000786c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL8_PL = 0x8000406c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE8_PL = 0x8003586b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a86b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f86b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001486b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001986b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b06b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL14_PL = 0x8000706b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL = 0x8000386b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_A_BIST_EN = 48;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_B_BIST_EN = 49;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN = 50;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ = 52;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ = 56;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN = 4;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL2_PL = 0x8003686a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL = 0x8003606a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE4_PL = 0x8003386a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT2_PL = 0x8003986a0c00003full;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d06a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002106a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002606a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE6_PL = 0x800348690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800318690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_FIR_MASK_PL = 0x800310690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x800118690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x800168690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b8690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d8690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x800228690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x800278690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x800290690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL1_PL = 0x800008690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f0680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x800240680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c8680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL = 0x800020680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_CTL_REGS_TX_CNTL2_PG = 0x800c4c600c00003full;

static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL = 48;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL_LEN = 3;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL = 51;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL_LEN = 4;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL = 55;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL_LEN = 6;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE = 61;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE = 62;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG = 0x800c04600c00003full;

static const uint32_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0 = 48;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1 = 49;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2 = 50;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3 = 51;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4 = 52;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5 = 53;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6 = 54;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7 = 55;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9 = 56;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9_LEN = 2;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG = 0x800cec600c00003full;

static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0 = 48;
static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0_LEN = 8;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG = 0x800d6c600c00003full;

static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL = 48;
static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL = 49;
static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL = 50;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL = 0x80047c600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL20_PL = 0x8004cc600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL30_PL = 0x80051c600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_FIR_MASK_PL = 0x80040c600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL = 0x800444610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800414610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL7_PL = 0x800464620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL = 0x80041c620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL = 0x8004ac630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL = 0x8004fc630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL4_PL = 0x80044c640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL = 0x800424640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL = 0x800484650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00150.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL1G_PL = 0x800434650c00003full;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL = 0x8004d4650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL9_PL = 0x800474650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_CNTL6_PL = 0x80045c6e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_FIR_PL = 0x8004046e0c00003full;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL17_PL = 0x8004b46f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL27_PL = 0x8005046f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL11_PL = 0x800484670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL1G_PL = 0x800434670c00003full;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL21_PL = 0x8004d4670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_CNTL2_PL = 0x80043c660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004146d0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL = 0x8004846c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL = 0x8004346c0c00003full;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL = 0x8004d46c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_FIR_PL = 0x8004046c0c00003full;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL17_PL = 0x8004b46b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL27_PL = 0x8005046b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL4_PL = 0x80044c6b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE2_PL = 0x8004246b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL = 0x8004746a0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL = 0x80047c690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL = 0x8004cc690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL = 0x80051c690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL = 0x800464690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// omic/reg00151.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL = 0x80041c690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// omic/reg00151.H

}
}
#include "omic/reg00148.H"
#include "omic/reg00149.H"
#include "omic/reg00150.H"
#include "omic/reg00151.H"
#endif
