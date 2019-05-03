/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_7.H $       */
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

#ifndef __p10_scom_iohs_7_H_
#define __p10_scom_iohs_7_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CC_PROTECT_MODE_REG = 0x180303feull;

static const uint32_t AXON_CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t AXON_CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// iohs/reg00029.H

static const uint64_t AXON_CPLT_CTRL4_RW = 0x18000004ull;
static const uint64_t AXON_CPLT_CTRL4_WO_CLEAR = 0x18000024ull;
static const uint64_t AXON_CPLT_CTRL4_WO_OR = 0x18000014ull;

static const uint32_t AXON_CPLT_CTRL4_0_FLUSHMODE_INH = 4;
static const uint32_t AXON_CPLT_CTRL4_1_FLUSHMODE_INH = 5;
static const uint32_t AXON_CPLT_CTRL4_2_FLUSHMODE_INH = 6;
static const uint32_t AXON_CPLT_CTRL4_3_FLUSHMODE_INH = 7;
static const uint32_t AXON_CPLT_CTRL4_4_FLUSHMODE_INH = 8;
static const uint32_t AXON_CPLT_CTRL4_5_FLUSHMODE_INH = 9;
static const uint32_t AXON_CPLT_CTRL4_6_FLUSHMODE_INH = 10;
static const uint32_t AXON_CPLT_CTRL4_7_FLUSHMODE_INH = 11;
static const uint32_t AXON_CPLT_CTRL4_8_FLUSHMODE_INH = 12;
static const uint32_t AXON_CPLT_CTRL4_9_FLUSHMODE_INH = 13;
static const uint32_t AXON_CPLT_CTRL4_10_FLUSHMODE_INH = 14;
static const uint32_t AXON_CPLT_CTRL4_11_FLUSHMODE_INH = 15;
static const uint32_t AXON_CPLT_CTRL4_12_FLUSHMODE_INH = 16;
static const uint32_t AXON_CPLT_CTRL4_13_FLUSHMODE_INH = 17;
static const uint32_t AXON_CPLT_CTRL4_14_FLUSHMODE_INH = 18;
// iohs/reg00029.H

static const uint64_t AXON_EPS_DBG_INST1_COND_REG_3 = 0x180107c3ull;
// iohs/reg00029.H

static const uint64_t AXON_EPS_DBG_INST2_COND_REG_3 = 0x180107c6ull;
// iohs/reg00029.H

static const uint64_t AXON_EPS_DBG_TRACE_REG_0 = 0x180107cdull;

static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// iohs/reg00029.H

static const uint64_t AXON_EPS_THERM_WSUB_SKITTER_CLKSRC_REG = 0x18050016ull;

static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// iohs/reg00029.H

static const uint64_t AXON_OPCG_REG1 = 0x18030003ull;

static const uint32_t AXON_OPCG_REG1_SCAN_COUNT = 0;
static const uint32_t AXON_OPCG_REG1_SCAN_COUNT_LEN = 12;
static const uint32_t AXON_OPCG_REG1_MISR_A_VAL = 12;
static const uint32_t AXON_OPCG_REG1_MISR_A_VAL_LEN = 12;
static const uint32_t AXON_OPCG_REG1_MISR_B_VAL = 24;
static const uint32_t AXON_OPCG_REG1_MISR_B_VAL_LEN = 12;
static const uint32_t AXON_OPCG_REG1_MISR_INIT_WAIT = 36;
static const uint32_t AXON_OPCG_REG1_MISR_INIT_WAIT_LEN = 12;
static const uint32_t AXON_OPCG_REG1_SCAN_CLK_USE_EVEN = 49;
static const uint32_t AXON_OPCG_REG1_RTIM_THOLD_FORCE = 52;
static const uint32_t AXON_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL = 53;
static const uint32_t AXON_OPCG_REG1_SG_HIGH_DURING_FILL = 54;
static const uint32_t AXON_OPCG_REG1_LBIST_SKITTER_CTL = 55;
static const uint32_t AXON_OPCG_REG1_LBIST_SKITTER_CTL_LEN = 2;
static const uint32_t AXON_OPCG_REG1_MISR_MODE = 57;
static const uint32_t AXON_OPCG_REG1_INFINITE_MODE = 58;
static const uint32_t AXON_OPCG_REG1_NSL_FILL_COUNT = 59;
static const uint32_t AXON_OPCG_REG1_NSL_FILL_COUNT_LEN = 5;
// iohs/reg00029.H

static const uint64_t AXON_SCAN_CAPTUREDR = 0x1803c000ull;
// iohs/reg00029.H

static const uint64_t HANG_PULSE_0_REG = 0x180f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
// iohs/reg00029.H

static const uint64_t HANG_PULSE_1_REG = 0x180f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
// iohs/reg00029.H

static const uint64_t HANG_PULSE_2_REG = 0x180f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
// iohs/reg00029.H

static const uint64_t HANG_PULSE_3_REG = 0x180f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
// iohs/reg00029.H

static const uint64_t HANG_PULSE_4_REG = 0x180f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
// iohs/reg00029.H

static const uint64_t HANG_PULSE_5_REG = 0x180f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
// iohs/reg00029.H

static const uint64_t HANG_PULSE_6_REG = 0x180f0026ull;

static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6 = 0;
static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN = 6;
static const uint32_t HANG_PULSE_6_REG_SUPPRESS_HANG_6 = 6;
// iohs/reg00029.H

static const uint64_t HOSTATTN_INTERRUPT_REG = 0x180f002bull;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG = 0x800920200000003full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK = 49;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE10_PG = 0x800850200000003full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4 = 52;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG = 57;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC = 60;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH = 61;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE20_PG = 0x8008a0200000003full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START = 53;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START_LEN = 5;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE3_PG = 0x800818200000003full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4 = 52;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG = 57;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC = 60;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT = 61;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH = 62;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG = 0x8009e0200000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23_LEN = 8;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG = 0x800a30200000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN = 52;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN = 53;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN = 54;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN = 55;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN = 56;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN = 57;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN = 58;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN = 59;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN = 60;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN = 61;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN = 62;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG = 0x800a80200000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN = 16;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL1_PG = 0x800988200000003full;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT14_PG = 0x800af8200000003full;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT1_PG = 0x800a90200000003full;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT24_PG = 0x800b48200000003full;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL = 0x8003d0210000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_1_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL1_PL = 0x8003c0290000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_STAT1_PL = 0x8003e0290000003full;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_18_PLREGS_RX_MODE1_PL = 0x8003d0320000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_18_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_18_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_18_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_18_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_18_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL1_PL = 0x8003c0350000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_STAT1_PL = 0x8003e0350000003full;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_3_PLREGS_RX_CNTL2_PL = 0x8003c8230000003full;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL3_PL = 0x8003d8270000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_MODE7_PL = 0x800350200000003full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_STAT1_PL = 0x800390200000003full;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_SPARE_MODE_PL = 0x800300200000003full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x800098200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e8200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x800138200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x800188200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c8200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x800208200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x800258200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL17_PL = 0x800088200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800318210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b0210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x800100210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x800150210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00029.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a0210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a8210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e0220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x800230220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL3_PL = 0x800018220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL6_PL = 0x800388230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT6_PL = 0x8003b8230000003full;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d8230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x800128230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x800178230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c8230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x800280230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d0230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL16_PL = 0x800080230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL6_PL = 0x800030230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL4_PL = 0x800378240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE2_PL = 0x800328240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_STAT4_PL = 0x8003a8240000003full;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e0240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x800130240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x800180240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d0240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c0240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x800200240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x800250240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x800108250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x800158250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a8250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a0250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTLX9_PL = 0x800048250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x800118260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x800168260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b8260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d8260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x800228260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x800278260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x800290260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_CNTL6_PL = 0x800388270000003full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_STAT6_PL = 0x8003b8270000003full;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_FIR_MASK_PL = 0x800310270000003full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f0270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x800240270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c8270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL17_PL = 0x800088270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE7_PL = 0x800350280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_STAT1_PL = 0x800390280000003full;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a0280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f0280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x800140280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x800190280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b8280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL16_PL = 0x800080280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL3_PL = 0x800018280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTLX5_PL = 0x800380310000003full;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x800218310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x800268310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL6_PL = 0x800030310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x800110300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x800160300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b0300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x800220300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x800270300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x800298300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTLX9_PL = 0x800048300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL = 0x8003702f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE5_PL = 0x8003402f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT3_PL = 0x8003a02f0000003full;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b82f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f82f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002482f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c02f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL4_PL = 0x8003782e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE2_PL = 0x8003282e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_STAT4_PL = 0x8003a82e0000003full;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_FIR_PL = 0x8003082e0000003full;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b02e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001002e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001502e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a02e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a82e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000002e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000982d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e82d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001382d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001882d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c82d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002082d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002582d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL7_PL = 0x8000382d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL7_PL_A_BIST_EN = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL7_PL_B_BIST_EN = 49;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN = 2;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN = 4;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d82c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001282c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001782c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c82c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002802c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d02c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL8_PL = 0x8000402c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL = 0x8003702b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE5_PL = 0x8003402b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT3_PL = 0x8003a02b0000003full;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e02b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00031.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002302b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE7_PL = 0x8003502a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_STAT1_PL = 0x8003902a0000003full;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001082a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001582a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a82a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a02a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL15_PL = 0x8000782a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e0290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x800130290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x800180290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d0290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c0290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x800200290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x800250290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL13_PL = 0x800068290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL9_PG = 0x800c24200000003full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47 = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47_LEN = 16;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG = 0x800d1c200000003full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6_LEN = 6;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM = 54;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME = 55;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME_LEN = 6;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE = 61;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL12_PL = 0x80048c200000003full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL22_PL = 0x8004dc200000003full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL6_PL = 0x80045c200000003full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL18_PL = 0x8004bc210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL28_PL = 0x80050c210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL14_PL = 0x80049c230000003full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL24_PL = 0x8004ec230000003full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL2_PL = 0x80043c230000003full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL19_PL = 0x8004c4240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL29_PL = 0x800514240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL13_PL = 0x800494250000003full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL23_PL = 0x8004e4250000003full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_STAT1_PL = 0x800524250000003full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL13_PL = 0x800494260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL23_PL = 0x8004e4260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL8_PL = 0x80046c260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL19_PL = 0x8004c4270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL29_PL = 0x800514270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL5_PL = 0x800454270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_MODE3_PL = 0x80042c270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_STAT1_PL = 0x800524280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL15_PL = 0x8004a4310000003full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL25_PL = 0x8004f4310000003full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800414310000003full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL18_PL = 0x8004bc300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL28_PL = 0x80050c300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL2_PL = 0x80043c300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL12_PL = 0x80048c2f0000003full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL22_PL = 0x8004dc2f0000003full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL9_PL = 0x8004742e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL11_PL = 0x8004842d0000003full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL1G_PL = 0x8004342d0000003full;
// iohs/reg00032.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL = 0x8004d42d0000003full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00033.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL = 0x80044c2d0000003full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00033.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL = 0x8004242d0000003full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00033.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL = 0x8004b42c0000003full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00033.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL = 0x8005042c0000003full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00033.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL = 0x80047c2a0000003full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00033.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL = 0x8004cc2a0000003full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00033.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL = 0x80051c2a0000003full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00033.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL = 0x8004442a0000003full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00033.H

static const uint64_t PERF_SEL_CONFIG = 0x1801101dull;

static const uint32_t PERF_SEL_CONFIG_0 = 0;
static const uint32_t PERF_SEL_CONFIG_0_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_1 = 8;
static const uint32_t PERF_SEL_CONFIG_1_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_2 = 16;
static const uint32_t PERF_SEL_CONFIG_2_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_3 = 24;
static const uint32_t PERF_SEL_CONFIG_3_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_4 = 32;
static const uint32_t PERF_SEL_CONFIG_4_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_5 = 40;
static const uint32_t PERF_SEL_CONFIG_5_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_6 = 48;
static const uint32_t PERF_SEL_CONFIG_6_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_7 = 56;
static const uint32_t PERF_SEL_CONFIG_7_LEN = 8;
// iohs/reg00033.H

}
}
#include "iohs/reg00029.H"
#include "iohs/reg00030.H"
#include "iohs/reg00031.H"
#include "iohs/reg00032.H"
#include "iohs/reg00033.H"
#endif
