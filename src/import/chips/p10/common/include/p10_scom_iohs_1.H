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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_iohs_1_H_
#define __p10_scom_iohs_1_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


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

static const uint64_t AXON_EPS_FIR_ANY_LOCAL_ERR_MASK = 0x18040080ull;

static const uint32_t AXON_EPS_FIR_ANY_LOCAL_ERR_MASK_XSTOP_TO_PCB = 0;
static const uint32_t AXON_EPS_FIR_ANY_LOCAL_ERR_MASK_RECOV_TO_PCB = 1;
static const uint32_t AXON_EPS_FIR_ANY_LOCAL_ERR_MASK_SPATTN_TO_PCB = 2;
static const uint32_t AXON_EPS_FIR_ANY_LOCAL_ERR_MASK_LOCAL_XSTOP_TO_PCB = 3;
static const uint32_t AXON_EPS_FIR_ANY_LOCAL_ERR_MASK_HOSTATTN_TO_PCB = 4;
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

static const uint64_t AXON_XSTOP = 0x18040000ull;

static const uint32_t AXON_XSTOP_ANY_XSTOP = 0;
static const uint32_t AXON_XSTOP_SYSTEM_XSTOP = 1;
static const uint32_t AXON_XSTOP_XSTOP_ANY_SPATTN = 2;
static const uint32_t AXON_XSTOP_DBG_FIR_XSTOP_ON_TRIG = 3;
static const uint32_t AXON_XSTOP_XSTOP_PERV = 4;
static const uint32_t AXON_XSTOP_XSTOP_IN05 = 5;
static const uint32_t AXON_XSTOP_XSTOP_IN06 = 6;
static const uint32_t AXON_XSTOP_XSTOP_IN07 = 7;
static const uint32_t AXON_XSTOP_XSTOP_IN08 = 8;
static const uint32_t AXON_XSTOP_XSTOP_IN09 = 9;
static const uint32_t AXON_XSTOP_XSTOP_IN10 = 10;
static const uint32_t AXON_XSTOP_XSTOP_IN11 = 11;
static const uint32_t AXON_XSTOP_XSTOP_IN12 = 12;
static const uint32_t AXON_XSTOP_XSTOP_IN13 = 13;
static const uint32_t AXON_XSTOP_XSTOP_IN14 = 14;
static const uint32_t AXON_XSTOP_XSTOP_IN15 = 15;
static const uint32_t AXON_XSTOP_XSTOP_IN16 = 16;
static const uint32_t AXON_XSTOP_XSTOP_IN17 = 17;
static const uint32_t AXON_XSTOP_XSTOP_IN18 = 18;
static const uint32_t AXON_XSTOP_XSTOP_IN19 = 19;
static const uint32_t AXON_XSTOP_XSTOP_IN20 = 20;
static const uint32_t AXON_XSTOP_XSTOP_IN21 = 21;
static const uint32_t AXON_XSTOP_XSTOP_IN22 = 22;
static const uint32_t AXON_XSTOP_XSTOP_IN23 = 23;
static const uint32_t AXON_XSTOP_XSTOP_IN24 = 24;
static const uint32_t AXON_XSTOP_XSTOP_IN25 = 25;
static const uint32_t AXON_XSTOP_XSTOP_IN26 = 26;
static const uint32_t AXON_XSTOP_XSTOP_IN27 = 27;
static const uint32_t AXON_XSTOP_XSTOP_IN28 = 28;
static const uint32_t AXON_XSTOP_XSTOP_IN29 = 29;
static const uint32_t AXON_XSTOP_XSTOP_IN30 = 30;
static const uint32_t AXON_XSTOP_XSTOP_IN31 = 31;
static const uint32_t AXON_XSTOP_XSTOP_IN32 = 32;
static const uint32_t AXON_XSTOP_XSTOP_IN33 = 33;
static const uint32_t AXON_XSTOP_XSTOP_IN34 = 34;
static const uint32_t AXON_XSTOP_XSTOP_IN35 = 35;
static const uint32_t AXON_XSTOP_XSTOP_IN36 = 36;
static const uint32_t AXON_XSTOP_XSTOP_IN37 = 37;
static const uint32_t AXON_XSTOP_XSTOP_IN38 = 38;
static const uint32_t AXON_XSTOP_XSTOP_IN39 = 39;
static const uint32_t AXON_XSTOP_XSTOP_IN40 = 40;
static const uint32_t AXON_XSTOP_XSTOP_IN41 = 41;
static const uint32_t AXON_XSTOP_XSTOP_IN42 = 42;
static const uint32_t AXON_XSTOP_XSTOP_IN43 = 43;
static const uint32_t AXON_XSTOP_XSTOP_IN44 = 44;
static const uint32_t AXON_XSTOP_XSTOP_IN45 = 45;
static const uint32_t AXON_XSTOP_XSTOP_IN46 = 46;
static const uint32_t AXON_XSTOP_XSTOP_IN47 = 47;
static const uint32_t AXON_XSTOP_XSTOP_IN48 = 48;
static const uint32_t AXON_XSTOP_XSTOP_IN49 = 49;
static const uint32_t AXON_XSTOP_XSTOP_IN50 = 50;
static const uint32_t AXON_XSTOP_XSTOP_IN51 = 51;
static const uint32_t AXON_XSTOP_XSTOP_IN52 = 52;
static const uint32_t AXON_XSTOP_XSTOP_IN53 = 53;
// iohs/reg00004.H

static const uint64_t HEARTBEAT_REG = 0x180f0018ull;

static const uint32_t HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// iohs/reg00004.H

static const uint64_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL3_PL = 0x8003d80010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00004.H

static const uint64_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL1_PL = 0x8003c01010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00004.H

static const uint64_t IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_STAT1_PL = 0x8003e01010012c3full;
// iohs/reg00004.H

static const uint64_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL3_PL = 0x8003d81310012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00004.H

static const uint64_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL2_PL = 0x8003c80410012c3full;
// iohs/reg00004.H

static const uint64_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL = 0x8003d00610012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00004.H

static const uint64_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL1_PL = 0x8003c01110012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00004.H

static const uint64_t IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_STAT1_PL = 0x8003e01110012c3full;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_MODE8_PL = 0x8003580010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001200010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001700010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c00010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002880010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL18_PL = 0x8000900010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL = 0x8000300010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN = 4;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL = 0x8003680110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE4_PL = 0x8003380110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_STAT2_PL = 0x8003980110012c3full;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e80110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002380110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL3_PL = 0x8000180110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO_LEN = 3;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE3_PL = 0x8003300210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_STAT5_PL = 0x8003b00210012c3full;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001080210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001580210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a80210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a00210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTLX9_PL = 0x8000480210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTLX5_PL = 0x8003800310012c3full;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_FIR_PL = 0x8003080310012c3full;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e00310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001300310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001800310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d00310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c00310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002000310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002500310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d80410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001280410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001780410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c80410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 8;
// iohs/reg00004.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002800410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d00410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL16_PL = 0x8000800410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00005.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL = 0x8003200510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00005.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e00510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002300510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL = 0x8000500510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS = 49;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M = 50;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_SIGDET_PD = 51;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP = 52;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP = 53;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS = 54;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN = 2;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP = 58;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN = 2;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE3_PL = 0x8003300610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_STAT5_PL = 0x8003b00610012c3full;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_FIR_MASK_PL = 0x8003100610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL = 0x8003000610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d00610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002100610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002600610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL = 0x8000300610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN = 4;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a80710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f80710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001480710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001980710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b00710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL18_PL = 0x8000900710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL3_PL = 0x8000180710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL3_PL_ZERO = 51;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN = 3;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE8_PL = 0x8003580810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL = 0x8003681110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE4_PL = 0x8003381110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_STAT2_PL = 0x8003981110012c3full;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001101110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001601110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b01110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002201110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002701110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002981110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTLX9_PL = 0x8000481110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE6_PL = 0x8003481010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x8002181010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x8002681010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL = 0x8000501010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS = 49;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M = 50;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD = 51;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP = 52;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP = 53;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS = 54;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN = 2;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP = 58;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN = 2;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a00f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f00f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001400f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001900f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b80f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL16_PL = 0x8000800f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00005.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e80e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002380e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00005.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL14_PL = 0x8000700e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00005.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL = 0x8003600d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 58;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 59;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A = 60;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A = 61;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN = 62;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL = 0x8003200d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001200d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001700d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c00d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002880d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL = 0x8000400d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT_LEN = 2;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL_LEN = 2;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B = 52;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000000d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_MODE6_PL = 0x8003480c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e00c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001300c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001800c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d00c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c00c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002000c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002500c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL = 0x8000680c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN = 4;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL = 0x8000380c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_EN_DC = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_PR_POS = 49;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN = 5;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001080b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001580b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a80b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a00b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL15_PL = 0x8000780b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL2_PL = 0x8000100b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL2_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL2_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL2_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL2_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN = 4;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE8_PL = 0x8003580a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e00a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002300a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL = 0x8000080a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL = 0x8003680910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_CNTLX5_PL = 0x8003800910012c3full;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE4_PL = 0x8003380910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_STAT2_PL = 0x8003980910012c3full;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d80910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001280910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001780910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c80910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002800910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d00910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL4_PL = 0x8000200910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00006.H

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG = 0x800c6c0010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN = 9;
// iohs/reg00006.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG = 0x800ccc0010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN = 8;
// iohs/reg00006.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG = 0x800ca40010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1 = 49;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2 = 50;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3 = 51;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4 = 52;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5 = 53;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6 = 54;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7 = 55;
// iohs/reg00006.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT2_PG = 0x800d4c0010012c3full;
// iohs/reg00006.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL9_PL = 0x8004740010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN_LEN = 9;
// iohs/reg00006.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_FIR_PL = 0x8004040010012c3full;
// iohs/reg00006.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL = 0x8004b40110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00006.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL4_PL = 0x80044c0110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00006.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004140110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00006.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL = 0x8004240110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00006.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL11_PL = 0x8004840210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_24_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_24_HS_EN_LEN = 9;
// iohs/reg00006.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL = 0x8004340210012c3full;
// iohs/reg00007.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL = 0x8004d40210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00007.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL = 0x8004ac0410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00007.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL = 0x8004fc0410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN = 9;
// iohs/reg00007.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL = 0x8004440410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00007.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL = 0x8004640610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00007.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL = 0x80041c0610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN = 52;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN = 53;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00007.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL = 0x8004ac0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00007.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL = 0x8004fc0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN = 9;
// iohs/reg00007.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL = 0x80047c0810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00007.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL = 0x8004cc0810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00007.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL = 0x80051c0810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00007.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL = 0x8004441110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00007.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL = 0x8004b41010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00007.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL = 0x80049c0e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00007.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL = 0x8004ec0e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN = 9;
// iohs/reg00007.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL = 0x80045c0e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00007.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL = 0x8004bc0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00007.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL = 0x8004dc0b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00007.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL = 0x80043c0b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00007.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL = 0x8004a40910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00007.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL = 0x8004f40910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00007.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL = 0x8005240910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00007.H

static const uint64_t RECOV_INTERRUPT_REG = 0x180f001bull;
// iohs/reg00007.H

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00004.H"
#include "iohs/reg00005.H"
#include "iohs/reg00006.H"
#include "iohs/reg00007.H"
#endif
#endif
