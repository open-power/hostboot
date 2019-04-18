/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_3.H $       */
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

#ifndef __p10_scom_omic_3_H_
#define __p10_scom_omic_3_H_


namespace scomt
{
namespace omic
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_MODE1_PG = 0x800808600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN = 48;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN_LEN = 3;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 = 51;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT19_PG = 0x800a18600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6_LEN = 6;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT29_PG = 0x800a68600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16_LEN = 16;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_STAT16_PG = 0x800b08600c00003full;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_STAT26_PG = 0x800b58600c00003full;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL = 0x8003d0610c00003full;

static const uint32_t RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL = 0x8003c86c0c00003full;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL = 0x8003d06a0c00003full;

static const uint32_t RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL = 0x8003d8680c00003full;

static const uint32_t RX0_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t RX0_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL = 0x8003d8770c00003full;

static const uint32_t RX0_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t RX0_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_3_PLREGS_RX_CNTL2_PL = 0x8003c8630c00003full;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL3_PL = 0x8003d86f0c00003full;

static const uint32_t RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTL6_PL = 0x800388600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_BIT_REGS_STAT6_PL = 0x8003b8600c00003full;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e0600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x800230600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL = 0x800090600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d8610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x800128610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x800178610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c8610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x800280610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d0610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x800098620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e8620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x800138620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x800188620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c8620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x800208620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x800258620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL = 0x800048620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL = 0x800350630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_BIT_REGS_STAT1_PL = 0x800390630c00003full;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b0630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x800100630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x800150630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a0630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a8630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL = 0x800370640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL = 0x800340640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_STAT3_PL = 0x8003a0640c00003full;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e8640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x800238640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL = 0x800080640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL = 0x800300650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x800120650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x800170650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c0650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x800288650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001186e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// omic/reg00124.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001686e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b86e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d86e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002286e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002786e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002906e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_CNTL16_PL = 0x8000806e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL = 0x8000306e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_BIT_REGS_CNTL4_PL = 0x8003786f0c00003full;

static const uint32_t RX0_1_RD_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t RX0_1_RD_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t RX0_1_RD_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t RX0_1_RD_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_BIT_REGS_MODE2_PL = 0x8003286f0c00003full;

static const uint32_t RX0_1_RD_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t RX0_1_RD_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t RX0_1_RD_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t RX0_1_RD_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t RX0_1_RD_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t RX0_1_RD_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t RX0_1_RD_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_BIT_REGS_STAT4_PL = 0x8003a86f0c00003full;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_BIT_REGS_FIR_PL = 0x8003086f0c00003full;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f06f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x8002406f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c86f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_CNTL3_PL = 0x8000186f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t RX0_1_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t RX0_1_RD_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t RX0_1_RD_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000006f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL = 0x800370670c00003full;

static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL = 0x800380670c00003full;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_BIT_REGS_MODE5_PL = 0x800340670c00003full;

static const uint32_t RX0_1_RD_2_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_BIT_REGS_STAT3_PL = 0x8003a0670c00003full;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a0670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f0670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x800140670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x800190670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b8670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x800218660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x800268660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_CNTL17_PL = 0x800088660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e86d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002386d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL4_PL = 0x8000206d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL = 0x8003486c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001206c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001706c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c06c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002886c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL1_PL = 0x8000086c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE1_PL = 0x8003206b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_BIT_REGS_SPARE_MODE_PL = 0x8003006b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_2_DEFAULT_RD_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e06b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001306b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001806b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d06b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c06b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002006b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002506b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001086a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001586a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a86a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// omic/reg00125.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a06a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e0690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x800230690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL14_PL = 0x800070690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL8_PL = 0x800040690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x800000690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL = 0x800330680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_STAT5_PL = 0x8003b0680c00003full;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d8680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x800128680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x800178680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c8680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x800280680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d0680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG = 0x800c9c600c00003full;

static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ = 48;
static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ_LEN = 4;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL19_PL = 0x8004c4600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL29_PL = 0x800514600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL7_PL = 0x800464600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL = 0x80041c600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL13_PL = 0x800494610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL23_PL = 0x8004e4610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL15_PL = 0x8004a4620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL25_PL = 0x8004f4620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_FIR_PL = 0x800404620c00003full;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL3_PL = 0x800444630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL12_PL = 0x80048c640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL22_PL = 0x8004dc640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL18_PL = 0x8004bc650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL28_PL = 0x80050c650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL = 0x80049c6e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL = 0x8004ec6e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL2_PL = 0x80043c6f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL = 0x8004bc670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL28_PL = 0x80050c670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL = 0x80045c670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_CNTL12_PL = 0x80048c660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL = 0x8004dc660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL12_PL = 0x80048c6d0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL22_PL = 0x8004dc6d0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL4_PL = 0x80044c6d0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_MODE2_PL = 0x8004246d0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL = 0x8004bc6c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL = 0x80050c6c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL9_PL = 0x8004746c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL = 0x80040c6c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL = 0x80049c6a0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL = 0x8004ec6a0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL = 0x8004c4690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL = 0x800514690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL = 0x800494680c00003full;

static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// omic/reg00126.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL = 0x8004e4680c00003full;

static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00127.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL3_PL = 0x800444680c00003full;

static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// omic/reg00127.H

}
}
#include "omic/reg00124.H"
#include "omic/reg00125.H"
#include "omic/reg00126.H"
#include "omic/reg00127.H"
#endif
