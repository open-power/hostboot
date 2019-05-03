/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_4.H $       */
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

#ifndef __p10_scom_iohs_4_H_
#define __p10_scom_iohs_4_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CLOCK_STAT_NSL = 0x18030009ull;

static const uint32_t AXON_CLOCK_STAT_NSL_PERV_NSL = 4;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT1_NSL = 5;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT2_NSL = 6;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT3_NSL = 7;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT4_NSL = 8;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT5_NSL = 9;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT6_NSL = 10;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT7_NSL = 11;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT8_NSL = 12;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT9_NSL = 13;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT10_NSL = 14;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT11_NSL = 15;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT12_NSL = 16;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT13_NSL = 17;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT14_NSL = 18;
// iohs/reg00016.H

static const uint64_t AXON_CPLT_CTRL3_RW = 0x18000003ull;
static const uint64_t AXON_CPLT_CTRL3_WO_CLEAR = 0x18000023ull;
static const uint64_t AXON_CPLT_CTRL3_WO_OR = 0x18000013ull;

static const uint32_t AXON_CPLT_CTRL3_0_PSCOM_EN = 4;
static const uint32_t AXON_CPLT_CTRL3_1_PSCOM_EN = 5;
static const uint32_t AXON_CPLT_CTRL3_2_PSCOM_EN = 6;
static const uint32_t AXON_CPLT_CTRL3_3_PSCOM_EN = 7;
static const uint32_t AXON_CPLT_CTRL3_4_PSCOM_EN = 8;
static const uint32_t AXON_CPLT_CTRL3_5_PSCOM_EN = 9;
static const uint32_t AXON_CPLT_CTRL3_6_PSCOM_EN = 10;
static const uint32_t AXON_CPLT_CTRL3_7_PSCOM_EN = 11;
static const uint32_t AXON_CPLT_CTRL3_8_PSCOM_EN = 12;
static const uint32_t AXON_CPLT_CTRL3_9_PSCOM_EN = 13;
static const uint32_t AXON_CPLT_CTRL3_10_PSCOM_EN = 14;
static const uint32_t AXON_CPLT_CTRL3_11_PSCOM_EN = 15;
static const uint32_t AXON_CPLT_CTRL3_12_PSCOM_EN = 16;
static const uint32_t AXON_CPLT_CTRL3_13_PSCOM_EN = 17;
static const uint32_t AXON_CPLT_CTRL3_14_PSCOM_EN = 18;
// iohs/reg00016.H

static const uint64_t AXON_EPS_THERM_WSUB_SKITTER_DATA0 = 0x18050019ull;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL2_PL = 0x8003c8200000003full;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL1_PL = 0x8003c02c0000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_STAT1_PL = 0x8003e02c0000003full;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL2_PL = 0x8003c8330000003full;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_MODE1_PL = 0x8003d0220000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL1_PL = 0x8003c0360000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_STAT1_PL = 0x8003e0360000003full;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL3_PL = 0x8003d8240000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d8200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x800128200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x800178200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c8200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x800280200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d0200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL7_PL = 0x800038200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL7_PL_A_BIST_EN = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL7_PL_B_BIST_EN = 49;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN = 50;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN = 2;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ = 52;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN = 4;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN = 4;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL = 0x800370210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE5_PL = 0x800340210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_STAT3_PL = 0x8003a0210000003full;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e0210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x800230210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTLX9_PL = 0x800048210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL4_PL = 0x800378220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX5_PL = 0x800380220000003full;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE2_PL = 0x800328220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_STAT4_PL = 0x8003a8220000003full;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800318220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b0220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x800100220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x800150220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a0220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a8220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x800098230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e8230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x800138230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x800188230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c8230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x800208230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x800258230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL18_PL = 0x800090230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL8_PL = 0x800040230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x800000230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_FIR_MASK_PL = 0x800310240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x800120240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x800170240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c0240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x800288240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL17_PL = 0x800088240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00016.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL6_PL = 0x800388250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_STAT6_PL = 0x8003b8250000003full;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e8250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x800238250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL4_PL = 0x800378260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE2_PL = 0x800328260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_STAT4_PL = 0x8003a8260000003full;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x800218260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x800268260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL7_PL = 0x800038260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL7_PL_A_BIST_EN = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL7_PL_B_BIST_EN = 49;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN = 50;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN = 2;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN = 4;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN = 4;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTLX9_PL = 0x800048260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL = 0x800300270000003full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a0270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f0270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x800140270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x800190270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b8270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f0280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x800240280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c8280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL18_PL = 0x800090280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL = 0x800370310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE5_PL = 0x800340310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_STAT3_PL = 0x8003a0310000003full;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_FIR_PL = 0x800308310000003full;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x800118310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x800168310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b8310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d8310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x800228310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x800278310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x800290310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL8_PL = 0x800040310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE7_PL = 0x800350300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_STAT1_PL = 0x800390300000003full;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d0300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x800210300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x800260300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a82f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f82f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001482f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001982f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b02f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL = 0x8000882f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000002f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL = 0x8003602e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e02e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002302e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL = 0x8000782e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL = 0x8003882d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// iohs/reg00017.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL = 0x8003b82d0000003full;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d82d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001282d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001782d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c82d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002802d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d02d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL = 0x8000682d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL = 0x8003502c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL = 0x8003902c0000003full;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000982c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e82c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001382c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001882c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c82c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002082c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002582c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL = 0x8000302c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b02b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001002b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001502b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a02b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a82b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL = 0x8000702b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL = 0x8000182b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL = 0x8003802a0000003full;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e82a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002382a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL = 0x800370290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL = 0x800340290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL = 0x8003a0290000003full;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x800120290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x800170290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c0290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x800288290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG = 0x800c74200000003full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN = 16;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG = 0x800c0c200000003full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN_LEN = 3;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN = 51;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE = 52;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL = 53;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 = 54;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN = 55;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN = 56;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN = 57;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG = 0x800cd4200000003full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN = 16;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG = 0x800d54200000003full;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL = 0x80046c200000003full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL = 0x8004ac210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL26_PL = 0x8004fc210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL5_PL = 0x800454210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE3_PL = 0x80042c210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL10_PL = 0x80047c220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL20_PL = 0x8004cc220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL30_PL = 0x80051c220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_STAT1_PL = 0x800524220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL17_PL = 0x8004b4240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL27_PL = 0x800504240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00018.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL2_PL = 0x80043c240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800414250000003full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL6_PL = 0x80045c260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL17_PL = 0x8004b4270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL27_PL = 0x800504270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_FIR_PL = 0x800404270000003full;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL11_PL = 0x800484280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL1G_PL = 0x800434280000003full;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL21_PL = 0x8004d4280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL2_PL = 0x80043c310000003full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL16_PL = 0x8004ac300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL26_PL = 0x8004fc300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_STAT1_PL = 0x8005242f0000003full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL15_PL = 0x8004a42e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL25_PL = 0x8004f42e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL7_PL = 0x8004642e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL = 0x80041c2e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL19_PL = 0x8004c42c0000003full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL29_PL = 0x8005142c0000003full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL13_PL = 0x8004942b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL23_PL = 0x8004e42b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL3_PL = 0x8004442b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL14_PL = 0x80049c290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00019.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL24_PL = 0x8004ec290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00019.H

static const uint64_t PERF_COUNT_LSB_1 = 0x18011021ull;
// iohs/reg00019.H

}
}
#include "iohs/reg00016.H"
#include "iohs/reg00017.H"
#include "iohs/reg00018.H"
#include "iohs/reg00019.H"
#endif
