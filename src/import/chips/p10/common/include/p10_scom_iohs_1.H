/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_1.H $       */
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

#ifndef __p10_scom_iohs_1_H_
#define __p10_scom_iohs_1_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CPLT_CTRL5_RW = 0x18000005ull;
static const uint64_t AXON_CPLT_CTRL5_WO_CLEAR = 0x18000025ull;
static const uint64_t AXON_CPLT_CTRL5_WO_OR = 0x18000015ull;

static const uint32_t AXON_CPLT_CTRL5_0 = 0;
static const uint32_t AXON_CPLT_CTRL5_1 = 1;
static const uint32_t AXON_CPLT_CTRL5_2 = 2;
static const uint32_t AXON_CPLT_CTRL5_3 = 3;
static const uint32_t AXON_CPLT_CTRL5_4 = 4;
static const uint32_t AXON_CPLT_CTRL5_5 = 5;
static const uint32_t AXON_CPLT_CTRL5_6 = 6;
static const uint32_t AXON_CPLT_CTRL5_7 = 7;
static const uint32_t AXON_CPLT_CTRL5_8 = 8;
static const uint32_t AXON_CPLT_CTRL5_9 = 9;
static const uint32_t AXON_CPLT_CTRL5_10 = 10;
static const uint32_t AXON_CPLT_CTRL5_11 = 11;
static const uint32_t AXON_CPLT_CTRL5_12 = 12;
static const uint32_t AXON_CPLT_CTRL5_13 = 13;
static const uint32_t AXON_CPLT_CTRL5_14 = 14;
static const uint32_t AXON_CPLT_CTRL5_15 = 15;
static const uint32_t AXON_CPLT_CTRL5_16 = 16;
static const uint32_t AXON_CPLT_CTRL5_17 = 17;
static const uint32_t AXON_CPLT_CTRL5_18 = 18;
static const uint32_t AXON_CPLT_CTRL5_19 = 19;
// iohs/reg00004.H

static const uint64_t AXON_EPS_DBG_INST1_COND_REG_2 = 0x180107c2ull;

static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// iohs/reg00004.H

static const uint64_t AXON_EPS_DBG_INST2_COND_REG_2 = 0x180107c5ull;

static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// iohs/reg00004.H

static const uint64_t AXON_EPS_DBG_TRACE_REG_1 = 0x180107ceull;

static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// iohs/reg00004.H

static const uint64_t AXON_EPS_FIR_GXSTOP0_MASK_REG = 0x18040013ull;

static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP = 0;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV = 1;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN = 2;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_OOB1 = 6;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// iohs/reg00004.H

static const uint64_t AXON_EPS_THERM_WSUB_DTS_RESULT2 = 0x18050002ull;

static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// iohs/reg00004.H

static const uint64_t AXON_OPCG_REG0 = 0x18030002ull;

static const uint32_t AXON_OPCG_REG0_RUNN_MODE = 0;
static const uint32_t AXON_OPCG_REG0_OPCG_GO = 1;
static const uint32_t AXON_OPCG_REG0_RUN_SCAN0 = 2;
static const uint32_t AXON_OPCG_REG0_SCAN0_MODE = 3;
static const uint32_t AXON_OPCG_REG0_OPCG_IN_SLAVE_MODE = 4;
static const uint32_t AXON_OPCG_REG0_OPCG_IN_MASTER_MODE = 5;
static const uint32_t AXON_OPCG_REG0_KEEP_MS_MODE = 6;
static const uint32_t AXON_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL = 7;
static const uint32_t AXON_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL = 8;
static const uint32_t AXON_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR = 11;
static const uint32_t AXON_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR = 12;
static const uint32_t AXON_OPCG_REG0_STOP_RUNN_ON_XSTOP = 13;
static const uint32_t AXON_OPCG_REG0_OPCG_STARTS_BIST = 14;
static const uint32_t AXON_OPCG_REG0_LOOP_COUNT = 21;
static const uint32_t AXON_OPCG_REG0_LOOP_COUNT_LEN = 43;
// iohs/reg00004.H

static const uint64_t CONTROL = 0x1801100bull;

static const uint32_t CONTROL_0_PHY_TRAINING = 0;
static const uint32_t CONTROL_0_STARTUP = 1;
static const uint32_t CONTROL_0_HOLD_PATT_A = 2;
static const uint32_t CONTROL_0_HOLD_PATT_B = 3;
static const uint32_t CONTROL_0_RUN_LANE_DISABLE = 4;
static const uint32_t CONTROL_0_RUN_LANE_OVERRIDE = 5;
static const uint32_t CONTROL_0_IGNORE_PHY = 6;
static const uint32_t CONTROL_0_IGNORE_FENCE = 7;
static const uint32_t CONTROL_0_ERR_INJ_COMMAND = 8;
static const uint32_t CONTROL_0_ERR_INJ_COMMAND_LEN = 4;
static const uint32_t CONTROL_0_ERR_INJ_COMMAND_LANES = 12;
static const uint32_t CONTROL_0_ERR_INJ_COMMAND_LANES_LEN = 9;
static const uint32_t CONTROL_0_COMMAND = 28;
static const uint32_t CONTROL_0_COMMAND_LEN = 4;
static const uint32_t CONTROL_1_PHY_TRAINING = 32;
static const uint32_t CONTROL_1_STARTUP = 33;
static const uint32_t CONTROL_1_HOLD_PATT_A = 34;
static const uint32_t CONTROL_1_HOLD_PATT_B = 35;
static const uint32_t CONTROL_1_RUN_LANE_DISABLE = 36;
static const uint32_t CONTROL_1_RUN_LANE_OVERRIDE = 37;
static const uint32_t CONTROL_1_IGNORE_PHY = 38;
static const uint32_t CONTROL_1_IGNORE_FENCE = 39;
static const uint32_t CONTROL_1_ERR_INJ_COMMAND = 40;
static const uint32_t CONTROL_1_ERR_INJ_COMMAND_LEN = 4;
static const uint32_t CONTROL_1_ERR_INJ_COMMAND_LANES = 44;
static const uint32_t CONTROL_1_ERR_INJ_COMMAND_LANES_LEN = 9;
static const uint32_t CONTROL_1_COMMAND = 60;
static const uint32_t CONTROL_1_COMMAND_LEN = 4;
// iohs/reg00004.H

static const uint64_t HEARTBEAT_REG = 0x180f0018ull;

static const uint32_t HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL3_PL = 0x8003d8200000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL1_PL = 0x8003c0300000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_STAT1_PL = 0x8003e0300000003full;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL3_PL = 0x8003d8330000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL2_PL = 0x8003c8240000003full;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL = 0x8003d0260000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL1_PL = 0x8003c0310000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_STAT1_PL = 0x8003e0310000003full;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_MODE8_PL = 0x800358200000003full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x800120200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x800170200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c0200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x800288200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL18_PL = 0x800090200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL = 0x800030200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL = 0x800368210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE4_PL = 0x800338210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_STAT2_PL = 0x800398210000003full;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e8210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x800238210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL3_PL = 0x800018210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE3_PL = 0x800330220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_STAT5_PL = 0x8003b0220000003full;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x800108220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x800158220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a8220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a0220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTLX9_PL = 0x800048220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTLX5_PL = 0x800380230000003full;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_FIR_PL = 0x800308230000003full;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e0230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x800130230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x800180230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d0230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c0230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x800200230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x800250230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d8240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x800128240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x800178240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c8240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x800280240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d0240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL16_PL = 0x800080240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL = 0x800320250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e0250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x800230250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE3_PL = 0x800330260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_STAT5_PL = 0x8003b0260000003full;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_FIR_MASK_PL = 0x800310260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL = 0x800300260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d0260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x800210260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x800260260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL = 0x800030260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a8270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f8270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x800148270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x800198270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b0270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL18_PL = 0x800090270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL3_PL = 0x800018270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE8_PL = 0x800358280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b8280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f8280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x800248280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c0280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL = 0x800368310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE4_PL = 0x800338310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_STAT2_PL = 0x800398310000003full;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x800110310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x800160310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b0310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x800220310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x800270310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x800298310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTLX9_PL = 0x800048310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE6_PL = 0x800348300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x800218300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x800268300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a02f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f02f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001402f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001902f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b82f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL16_PL = 0x8000802f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e82e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002382e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL14_PL = 0x8000702e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL = 0x8003602d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL = 0x8003202d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// iohs/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001202d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001702d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c02d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002882d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL = 0x8000402d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000002d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_MODE6_PL = 0x8003482c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e02c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001302c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001802c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d02c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c02c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002002c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002502c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL = 0x8000682c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL = 0x8000382c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_A_BIST_EN = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_B_BIST_EN = 49;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN = 50;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN = 2;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ = 52;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN = 4;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN = 4;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001082b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001582b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a82b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a02b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL15_PL = 0x8000782b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE8_PL = 0x8003582a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e02a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002302a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL = 0x8000082a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL = 0x800368290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTLX5_PL = 0x800380290000003full;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE4_PL = 0x800338290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_STAT2_PL = 0x800398290000003full;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d8290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x800128290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x800178290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c8290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x800280290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d0290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL4_PL = 0x800020290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG = 0x800c6c200000003full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN = 9;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG = 0x800ccc200000003full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN = 8;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG = 0x800ca4200000003full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1 = 49;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2 = 50;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3 = 51;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4 = 52;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5 = 53;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6 = 54;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7 = 55;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT2_PG = 0x800d4c200000003full;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL9_PL = 0x800474200000003full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_FIR_PL = 0x800404200000003full;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL = 0x8004b4210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL27_PL = 0x800504210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL4_PL = 0x80044c210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800414210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL = 0x800424210000003full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL11_PL = 0x800484220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL = 0x800434220000003full;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL = 0x8004d4220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL = 0x8004ac240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL = 0x8004fc240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL = 0x800444240000003full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL = 0x800464260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL = 0x80041c260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL = 0x8004ac270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL = 0x8004fc270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL = 0x80047c280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL = 0x8004cc280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL = 0x80051c280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL = 0x800444310000003full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL = 0x8004b4300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL27_PL = 0x800504300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL = 0x80049c2e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL = 0x8004ec2e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL = 0x80045c2e0000003full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL = 0x8004bc2c0000003full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL28_PL = 0x80050c2c0000003full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL12_PL = 0x80048c2b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL = 0x8004dc2b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL = 0x80043c2b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL = 0x8004a4290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL = 0x8004f4290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL = 0x800524290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00007.H

static const uint64_t LINK0_QUALITY = 0x18011026ull;

static const uint32_t LINK0_QUALITY_TX_BW = 1;
static const uint32_t LINK0_QUALITY_TX_BW_LEN = 11;
static const uint32_t LINK0_QUALITY_RX_BW = 13;
static const uint32_t LINK0_QUALITY_RX_BW_LEN = 11;
static const uint32_t LINK0_QUALITY_ERROR_RATE = 25;
static const uint32_t LINK0_QUALITY_ERROR_RATE_LEN = 23;
static const uint32_t LINK0_QUALITY_SPARE_COUNTER_1 = 49;
static const uint32_t LINK0_QUALITY_SPARE_COUNTER_1_LEN = 7;
static const uint32_t LINK0_QUALITY_SPARE_COUNTER_2 = 57;
static const uint32_t LINK0_QUALITY_SPARE_COUNTER_2_LEN = 7;
// iohs/reg00007.H

static const uint64_t LINK1_TX_LANE_CONTROL = 0x18011011ull;

static const uint32_t LINK1_TX_LANE_CONTROL_00_CONTROL = 0;
static const uint32_t LINK1_TX_LANE_CONTROL_00_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_01_CONTROL = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_01_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_02_CONTROL = 8;
static const uint32_t LINK1_TX_LANE_CONTROL_02_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_03_CONTROL = 12;
static const uint32_t LINK1_TX_LANE_CONTROL_03_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_04_CONTROL = 16;
static const uint32_t LINK1_TX_LANE_CONTROL_04_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_05_CONTROL = 20;
static const uint32_t LINK1_TX_LANE_CONTROL_05_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_06_CONTROL = 24;
static const uint32_t LINK1_TX_LANE_CONTROL_06_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_07_CONTROL = 28;
static const uint32_t LINK1_TX_LANE_CONTROL_07_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_08_CONTROL = 32;
static const uint32_t LINK1_TX_LANE_CONTROL_08_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL__FAILED = 48;
static const uint32_t LINK1_TX_LANE_CONTROL__FAILED_LEN = 9;
// iohs/reg00007.H

static const uint64_t RECOV_INTERRUPT_REG = 0x180f001bull;
// iohs/reg00007.H

}
}
#include "iohs/reg00004.H"
#include "iohs/reg00005.H"
#include "iohs/reg00006.H"
#include "iohs/reg00007.H"
#endif
