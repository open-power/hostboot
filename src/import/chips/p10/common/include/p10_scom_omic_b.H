/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_b.H $       */
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

#ifndef __p10_scom_omic_b_H_
#define __p10_scom_omic_b_H_


namespace scomt
{
namespace omic
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_MODE17_PG = 0x800888600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 = 48;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN = 3;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3 = 51;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3_LEN = 5;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 = 56;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN = 3;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4 = 59;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4_LEN = 5;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT15_PG = 0x8009f8600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL_LEN = 5;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT25_PG = 0x800a48600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15_LEN = 16;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG = 0x8009b0600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN = 8;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_STAT6_PG = 0x800ab8600c00003full;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_16_PLREGS_RX_CNTL1_PL = 0x8003c0700c00003full;

static const uint32_t RX0_RXCTL_DATASM_16_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RX0_RXCTL_DATASM_16_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_16_PLREGS_RX_STAT1_PL = 0x8003e0700c00003full;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_19_PLREGS_RX_MODE1_PL = 0x8003d0730c00003full;

static const uint32_t RX0_RXCTL_DATASM_19_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RX0_RXCTL_DATASM_19_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RX0_RXCTL_DATASM_19_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RX0_RXCTL_DATASM_19_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RX0_RXCTL_DATASM_19_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_20_PLREGS_RX_CNTL1_PL = 0x8003c0740c00003full;

static const uint32_t RX0_RXCTL_DATASM_20_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RX0_RXCTL_DATASM_20_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_20_PLREGS_RX_STAT1_PL = 0x8003e0740c00003full;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL = 0x8003c0640c00003full;

static const uint32_t RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL = 0x8003e0640c00003full;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL = 0x8003c8660c00003full;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a0600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f0600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x800140600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x800190600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b8600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL14_PL = 0x800070600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL = 0x800388610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL = 0x800360610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL = 0x8003b8610c00003full;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x800218610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x800268610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL = 0x800350620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL = 0x800390620c00003full;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x800118620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x800168620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b8620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d8620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x800228620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x800278620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x800290620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL13_PL = 0x800068620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL3_PL = 0x800018620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f0630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x800240630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c8630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL15_PL = 0x800078630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL = 0x800030630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a8640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f8640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x800148640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x800198640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b0640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL = 0x800370650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTLX5_PL = 0x800380650c00003full;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL = 0x800340650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL = 0x8003a0650c00003full;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d0650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// omic/reg00156.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x800210650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x800260650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_CNTL4_PL = 0x8003786e0c00003full;

static const uint32_t RX0_1_RD_0_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_MODE2_PL = 0x8003286e0c00003full;

static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_STAT4_PL = 0x8003a86e0c00003full;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000986e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e86e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001386e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001886e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c86e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002086e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002586e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b06f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001006f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001506f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a06f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a86f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL = 0x800300670c00003full;

static const uint32_t RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e0670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x800230670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL = 0x800370660c00003full;

static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_MODE5_PL = 0x800340660c00003full;

static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_STAT3_PL = 0x8003a0660c00003full;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_FIR_PL = 0x800308660c00003full;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d8660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x800128660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x800178660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c8660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x800280660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d0660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE6_PL = 0x8003486d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a86d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f86d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001486d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001986d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b06d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL16_PL = 0x8000806d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL8_PL = 0x8000406d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000006d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d06c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002106c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002606c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_BIT_REGS_CNTLX5_PL = 0x8003806b0c00003full;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001106b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001606b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b06b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002206b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002706b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002986b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE1_PL = 0x8003206a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// omic/reg00157.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL = 0x8003106a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b86a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f86a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002486a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c06a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL17_PL = 0x8000886a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL = 0x8000386a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_A_BIST_EN = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_B_BIST_EN = 49;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN = 50;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ = 52;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ = 56;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN = 4;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE3_PL = 0x800330690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT5_PL = 0x8003b0690c00003full;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a0690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f0690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x800140690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x800190690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b8690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL18_PL = 0x800090690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL4_PL = 0x800020690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x800218680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x800268680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL = 0x800008680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_CTL_REGS_TX_CNTL7_PG = 0x800c74600c00003full;

static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 = 48;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN = 16;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_CTL_REGS_TX_MODE1_PG = 0x800c0c600c00003full;

static const uint32_t TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN = 48;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN_LEN = 3;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN = 51;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE = 52;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL = 53;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 = 54;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN = 55;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN = 56;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN = 57;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG = 0x800cd4600c00003full;

static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 = 48;
static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN = 16;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG = 0x800d54600c00003full;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL15_PL = 0x8004a4600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL25_PL = 0x8004f4600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL6_PL = 0x80045c610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_PL = 0x800404610c00003full;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL19_PL = 0x8004c4620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL29_PL = 0x800514620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL2_PL = 0x80043c620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_FIR_MASK_PL = 0x80040c620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL13_PL = 0x800494630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL23_PL = 0x8004e4630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800414630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_STAT1_PL = 0x800524640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL14_PL = 0x80049c650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL24_PL = 0x8004ec650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_CNTL18_PL = 0x8004bc6e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_CNTL28_PL = 0x80050c6e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_CNTL3_PL = 0x8004446e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL12_PL = 0x80048c6f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL22_PL = 0x8004dc6f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL14_PL = 0x80049c670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL24_PL = 0x8004ec670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_CNTL7_PL = 0x800464660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL = 0x80041c660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL8_PL = 0x80046c6d0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL14_PL = 0x80049c6c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL24_PL = 0x8004ec6c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL5_PL = 0x8004546c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// omic/reg00158.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL = 0x80042c6c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// omic/reg00159.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL = 0x80048c6b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// omic/reg00159.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL = 0x8004dc6b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// omic/reg00159.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004146b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// omic/reg00159.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_STAT1_PL = 0x8005246b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// omic/reg00159.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL18_PL = 0x8004bc6a0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// omic/reg00159.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL28_PL = 0x80050c6a0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// omic/reg00159.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL15_PL = 0x8004a4690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// omic/reg00159.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL25_PL = 0x8004f4690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00159.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL2_PL = 0x80043c690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// omic/reg00159.H

}
}
#include "omic/reg00156.H"
#include "omic/reg00157.H"
#include "omic/reg00158.H"
#include "omic/reg00159.H"
#endif
