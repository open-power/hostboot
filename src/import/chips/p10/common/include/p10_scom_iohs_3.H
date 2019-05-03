/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_3.H $       */
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

#ifndef __p10_scom_iohs_3_H_
#define __p10_scom_iohs_3_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_BIST = 0x1803000bull;

static const uint32_t AXON_BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t AXON_BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t AXON_BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t AXON_BIST_BIST_PERV = 4;
static const uint32_t AXON_BIST_BIST_UNIT1 = 5;
static const uint32_t AXON_BIST_BIST_UNIT2 = 6;
static const uint32_t AXON_BIST_BIST_UNIT3 = 7;
static const uint32_t AXON_BIST_BIST_UNIT4 = 8;
static const uint32_t AXON_BIST_BIST_UNIT5 = 9;
static const uint32_t AXON_BIST_BIST_UNIT6 = 10;
static const uint32_t AXON_BIST_BIST_UNIT7 = 11;
static const uint32_t AXON_BIST_BIST_UNIT8 = 12;
static const uint32_t AXON_BIST_BIST_UNIT9 = 13;
static const uint32_t AXON_BIST_BIST_UNIT10 = 14;
static const uint32_t AXON_BIST_BIST_UNIT11 = 15;
static const uint32_t AXON_BIST_BIST_UNIT12 = 16;
static const uint32_t AXON_BIST_BIST_UNIT13 = 17;
static const uint32_t AXON_BIST_BIST_UNIT14 = 18;
static const uint32_t AXON_BIST_BIST_STROBE_WINDOW_EN = 48;
// iohs/reg00012.H

static const uint64_t AXON_CLOCK_STAT_ARY = 0x1803000aull;

static const uint32_t AXON_CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT14_ARY = 18;
// iohs/reg00012.H

static const uint64_t AXON_CLOCK_STAT_SL = 0x18030008ull;

static const uint32_t AXON_CLOCK_STAT_SL_PERV_SL = 4;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT1_SL = 5;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT2_SL = 6;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT3_SL = 7;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT4_SL = 8;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT5_SL = 9;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT6_SL = 10;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT7_SL = 11;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT8_SL = 12;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT9_SL = 13;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT10_SL = 14;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT11_SL = 15;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT12_SL = 16;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT13_SL = 17;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT14_SL = 18;
// iohs/reg00012.H

static const uint64_t AXON_EPS_FIR_MODE_REG = 0x18040008ull;

static const uint32_t AXON_EPS_FIR_MODE_REG_00 = 0;
static const uint32_t AXON_EPS_FIR_MODE_REG_01 = 1;
static const uint32_t AXON_EPS_FIR_MODE_REG_02 = 2;
static const uint32_t AXON_EPS_FIR_MODE_REG_03 = 3;
static const uint32_t AXON_EPS_FIR_MODE_REG_04 = 4;
static const uint32_t AXON_EPS_FIR_MODE_REG_05 = 5;
static const uint32_t AXON_EPS_FIR_MODE_REG_06 = 6;
static const uint32_t AXON_EPS_FIR_MODE_REG_07 = 7;
static const uint32_t AXON_EPS_FIR_MODE_REG_08 = 8;
static const uint32_t AXON_EPS_FIR_MODE_REG_09 = 9;
static const uint32_t AXON_EPS_FIR_MODE_REG_10 = 10;
static const uint32_t AXON_EPS_FIR_MODE_REG_11 = 11;
static const uint32_t AXON_EPS_FIR_MODE_REG_12 = 12;
static const uint32_t AXON_EPS_FIR_MODE_REG_13 = 13;
static const uint32_t AXON_EPS_FIR_MODE_REG_14 = 14;
static const uint32_t AXON_EPS_FIR_MODE_REG_15 = 15;
// iohs/reg00012.H

static const uint64_t AXON_EPS_PSC_PSCOM_MODE_REG = 0x18010000ull;

static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE = 4;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT = 5;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN = 2;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS = 7;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT = 9;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN = 3;
// iohs/reg00012.H

static const uint64_t AXON_OPCG_CAPT1 = 0x18030010ull;

static const uint32_t AXON_OPCG_CAPT1_COUNT = 0;
static const uint32_t AXON_OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t AXON_OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t AXON_OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t AXON_OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t AXON_OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t AXON_OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t AXON_OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t AXON_OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t AXON_OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t AXON_OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t AXON_OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t AXON_OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t AXON_OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t AXON_OPCG_CAPT1_SEQ_12_LEN = 5;
// iohs/reg00012.H

static const uint64_t AXON_TRA0_TR0_TRACE_HI_DATA_REG = 0x18010400ull;

static const uint32_t AXON_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t AXON_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// iohs/reg00012.H

static const uint64_t AXON_TRA0_TR0_CONFIG_4 = 0x18010407ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_4_B_LEN = 24;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG = 0x800848200000003full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2 = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2 = 52;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3 = 56;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3 = 60;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3_LEN = 4;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG = 0x800a10200000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4_LEN = 6;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5 = 54;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5_LEN = 6;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG = 0x800a60200000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23_LEN = 8;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL1_PL = 0x8003c02e0000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_STAT1_PL = 0x8003e02e0000003full;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL3_PL = 0x8003d8220000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL = 0x8003d0240000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL2_PL = 0x8003c8260000003full;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x800108200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x800158200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a8200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a0200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL = 0x800018200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL = 0x800320210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e0210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x800130210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x800180210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d0210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c0210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x800200210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x800250210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL = 0x800030210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL = 0x800360220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE6_PL = 0x800348220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x800120220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x800170220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c0220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x800288220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e8230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x800238230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE8_PL = 0x800358240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b0240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x800100240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x800150240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a0240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a8240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL = 0x800068240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL = 0x800368250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE4_PL = 0x800338250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_STAT2_PL = 0x800398250000003full;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x800098250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e8250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x800138250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x800188250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c8250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x800208250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x800258250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL15_PL = 0x800078250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE6_PL = 0x800348260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b8260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f8260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x800248260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c0260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL3_PL = 0x800018260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x800110270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x800160270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b0270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x800220270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x800270270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x800298270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL = 0x800030270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d0280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x800210280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x800260280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL = 0x800320310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a8310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f8310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x800148310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x800198310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b0310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE3_PL = 0x800330300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_STAT5_PL = 0x8003b0300000003full;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f0300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x800240300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c8300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL15_PL = 0x800078300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8003182f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL = 0x8003002f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001182f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001682f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b82f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d82f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002282f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002782f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002902f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL = 0x8000682f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL = 0x8003802e0000003full;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE8_PL = 0x8003582e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e02e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001302e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001802e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d02e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c02e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002002e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002502e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL = 0x8000402e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL = 0x8003682d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE4_PL = 0x8003382d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_STAT2_PL = 0x8003982d0000003full;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_PL = 0x8003082d0000003full;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001082d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001582d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a82d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a02d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL17_PL = 0x8000882d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_MODE3_PL = 0x8003302c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_STAT5_PL = 0x8003b02c0000003full;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e82c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002382c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL16_PL = 0x8000802c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001202b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001702b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c02b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002882b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL = 0x8000382b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_A_BIST_EN = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_B_BIST_EN = 49;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN = 50;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN = 2;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ = 52;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN = 4;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL = 0x8003602a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000982a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e82a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001382a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001882a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c82a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002082a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002582a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL4_PL = 0x8000202a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTLX9_PL = 0x8000482a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL = 0x800320290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800318290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b0290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x800100290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x800150290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a0290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a8290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL = 0x800008290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG = 0x800c2c200000003full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63 = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63_LEN = 16;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG = 0x800c54200000003full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL_LEN = 3;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL = 51;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL_LEN = 4;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL = 55;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL_LEN = 6;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG = 0x800cf4200000003full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN = 16;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_PG = 0x800c84200000003full;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL18_PL = 0x8004bc200000003full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL28_PL = 0x80050c200000003full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL12_PL = 0x80048c210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL22_PL = 0x8004dc210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_STAT1_PL = 0x800524210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL = 0x80049c220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL24_PL = 0x8004ec220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL5_PL = 0x800454220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL = 0x80042c220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL8_PL = 0x80046c230000003full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800414230000003full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL13_PL = 0x800494240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL23_PL = 0x8004e4240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL6_PL = 0x80045c240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL19_PL = 0x8004c4250000003full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL29_PL = 0x800514250000003full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL = 0x8004c4260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL29_PL = 0x800514260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL2_PL = 0x80043c260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_FIR_PL = 0x800404260000003full;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL13_PL = 0x800494270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL23_PL = 0x8004e4270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL = 0x8004a4280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL25_PL = 0x8004f4280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL = 0x80045c310000003full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL12_PL = 0x80048c300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL22_PL = 0x8004dc300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL8_PL = 0x80046c300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL18_PL = 0x8004bc2f0000003full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL28_PL = 0x80050c2f0000003full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL5_PL = 0x8004542f0000003full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL = 0x80042c2f0000003full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL11_PL = 0x8004842e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL1G_PL = 0x8004342e0000003full;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL21_PL = 0x8004d42e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL = 0x8004442e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL = 0x8004b42b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL27_PL = 0x8005042b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL7_PL = 0x8004642b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL = 0x80041c2b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL9_PL = 0x8004742a0000003full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL10_PL = 0x80047c290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL20_PL = 0x8004cc290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL30_PL = 0x80051c290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL4_PL = 0x80044c290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL = 0x800424290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00015.H

static const uint64_t LINK1_RX_LANE_CONTROL = 0x18011013ull;

static const uint32_t LINK1_RX_LANE_CONTROL_DISABLED = 0;
static const uint32_t LINK1_RX_LANE_CONTROL_DISABLED_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_BRINGUP = 12;
static const uint32_t LINK1_RX_LANE_CONTROL_BRINGUP_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_SPARED = 24;
static const uint32_t LINK1_RX_LANE_CONTROL_SPARED_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_LOCKED = 36;
static const uint32_t LINK1_RX_LANE_CONTROL_LOCKED_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_FAILED = 48;
static const uint32_t LINK1_RX_LANE_CONTROL_FAILED_LEN = 9;
// iohs/reg00015.H

static const uint64_t LXSTOP_INTERRUPT_REG = 0x180f002aull;
// iohs/reg00015.H

static const uint64_t MULTICAST_GROUP_1 = 0x180f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// iohs/reg00015.H

static const uint64_t NET_CTRL0_RWX = 0x180f0040ull;
static const uint64_t NET_CTRL0_RWX_WAND = 0x180f0041ull;
static const uint64_t NET_CTRL0_RWX_WOR = 0x180f0042ull;

static const uint32_t NET_CTRL0_CHIPLET_ENABLE = 0;
static const uint32_t NET_CTRL0_PCB_EP_RESET = 1;
static const uint32_t NET_CTRL0_CLK_ASYNC_RESET = 2;
static const uint32_t NET_CTRL0_PLL_TEST_EN = 3;
static const uint32_t NET_CTRL0_PLL_RESET = 4;
static const uint32_t NET_CTRL0_PLL_BYPASS = 5;
static const uint32_t NET_CTRL0_VITAL_SCAN = 6;
static const uint32_t NET_CTRL0_VITAL_SCAN_IN = 7;
static const uint32_t NET_CTRL0_VITAL_PHASE = 8;
static const uint32_t NET_CTRL0_FLUSH_ALIGN_OVR = 9;
static const uint32_t NET_CTRL0_VITAL_AL = 10;
static const uint32_t NET_CTRL0_ACT_DIS = 11;
static const uint32_t NET_CTRL0_MPW1 = 12;
static const uint32_t NET_CTRL0_MPW2 = 13;
static const uint32_t NET_CTRL0_MPW3 = 14;
static const uint32_t NET_CTRL0_DELAY_LCLKR = 15;
static const uint32_t NET_CTRL0_VITAL_THOLD = 16;
static const uint32_t NET_CTRL0_FLUSH_SCAN_N = 17;
static const uint32_t NET_CTRL0_FENCE_EN = 18;
static const uint32_t NET_CTRL0_CPLT_RCTRL = 19;
static const uint32_t NET_CTRL0_CPLT_DCTRL = 20;
static const uint32_t NET_CTRL0_ADJ_FUNC_CLKSEL = 22;
static const uint32_t NET_CTRL0_TP_SRAM_ENABLE = 23;
static const uint32_t NET_CTRL0_TP_FENCE_PCB = 25;
static const uint32_t NET_CTRL0_LVLTRANS_FENCE = 26;
static const uint32_t NET_CTRL0_ARRAY_WRITE_ASSIST_EN = 27;
static const uint32_t NET_CTRL0_HTB_INTEST = 28;
static const uint32_t NET_CTRL0_HTB_EXTEST = 29;
static const uint32_t NET_CTRL0_PLLFORCE_OUT_EN = 31;
// iohs/reg00015.H

static const uint64_t PLL_LOCK_REG = 0x180f0019ull;
// iohs/reg00015.H

static const uint64_t REGS_PRX0_DLR_APSR = 0x18011039ull;
// iohs/reg00015.H

}
}
#include "iohs/reg00012.H"
#include "iohs/reg00013.H"
#include "iohs/reg00014.H"
#include "iohs/reg00015.H"
#endif
