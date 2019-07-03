/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_a.H $         */
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

#ifndef __p10_scom_eq_a_H_
#define __p10_scom_eq_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


static const uint64_t CC_PROTECT_MODE_REG = 0x200303feull;

static const uint32_t CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// eq/reg00010.H

static const uint64_t CLOCK_STAT_SL = 0x20030008ull;

static const uint32_t CLOCK_STAT_SL_PERV_SL = 4;
static const uint32_t CLOCK_STAT_SL_UNIT1_SL = 5;
static const uint32_t CLOCK_STAT_SL_UNIT2_SL = 6;
static const uint32_t CLOCK_STAT_SL_UNIT3_SL = 7;
static const uint32_t CLOCK_STAT_SL_UNIT4_SL = 8;
static const uint32_t CLOCK_STAT_SL_UNIT5_SL = 9;
static const uint32_t CLOCK_STAT_SL_UNIT6_SL = 10;
static const uint32_t CLOCK_STAT_SL_UNIT7_SL = 11;
static const uint32_t CLOCK_STAT_SL_UNIT8_SL = 12;
static const uint32_t CLOCK_STAT_SL_UNIT9_SL = 13;
static const uint32_t CLOCK_STAT_SL_UNIT10_SL = 14;
static const uint32_t CLOCK_STAT_SL_UNIT11_SL = 15;
static const uint32_t CLOCK_STAT_SL_UNIT12_SL = 16;
static const uint32_t CLOCK_STAT_SL_UNIT13_SL = 17;
static const uint32_t CLOCK_STAT_SL_UNIT14_SL = 18;
// eq/reg00010.H

static const uint64_t CPLT_CTRL3_RW = 0x20000003ull;
static const uint64_t CPLT_CTRL3_WO_CLEAR = 0x20000023ull;
static const uint64_t CPLT_CTRL3_WO_OR = 0x20000013ull;

static const uint32_t CPLT_CTRL3_0_PSCOM_EN = 4;
static const uint32_t CPLT_CTRL3_1_PSCOM_EN = 5;
static const uint32_t CPLT_CTRL3_2_PSCOM_EN = 6;
static const uint32_t CPLT_CTRL3_3_PSCOM_EN = 7;
static const uint32_t CPLT_CTRL3_4_PSCOM_EN = 8;
static const uint32_t CPLT_CTRL3_5_PSCOM_EN = 9;
static const uint32_t CPLT_CTRL3_6_PSCOM_EN = 10;
static const uint32_t CPLT_CTRL3_7_PSCOM_EN = 11;
static const uint32_t CPLT_CTRL3_8_PSCOM_EN = 12;
static const uint32_t CPLT_CTRL3_9_PSCOM_EN = 13;
static const uint32_t CPLT_CTRL3_10_PSCOM_EN = 14;
static const uint32_t CPLT_CTRL3_11_PSCOM_EN = 15;
static const uint32_t CPLT_CTRL3_12_PSCOM_EN = 16;
static const uint32_t CPLT_CTRL3_13_PSCOM_EN = 17;
static const uint32_t CPLT_CTRL3_14_PSCOM_EN = 18;
// eq/reg00010.H

static const uint64_t EPS_DBG_INST1_COND_REG_1 = 0x200183e1ull;

static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// eq/reg00010.H

static const uint64_t EPS_DBG_INST2_COND_REG_1 = 0x200183e4ull;

static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// eq/reg00010.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4 = 0x20040084ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SYS_XSTOP_STAGED_ERR = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_DBG_TRIG_ERR = 7;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// eq/reg00010.H

static const uint64_t L3TRA0_TR0_TRACE_HI_DATA_REG = 0x20018200ull;

static const uint32_t L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// eq/reg00010.H

static const uint64_t L3TRA1_TR1_CONFIG_1 = 0x20018264ull;

static const uint32_t L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// eq/reg00010.H

static const uint64_t L3TRA3_TR0_CONFIG_0 = 0x200182c3ull;

static const uint32_t L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// eq/reg00010.H

static const uint64_t L3TRA3_TR1_TRACE_LO_DATA_REG = 0x200182e1ull;

static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// eq/reg00010.H

static const uint64_t L3TRA3_TR1_CONFIG_9 = 0x200182e9ull;

static const uint32_t L3TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// eq/reg00010.H

static const uint64_t QME_BCEBAR0 = 0x200e0060ull;

static const uint32_t QME_BCEBAR0_BASE = 8;
static const uint32_t QME_BCEBAR0_BASE_LEN = 36;
static const uint32_t QME_BCEBAR0_SIZE = 61;
static const uint32_t QME_BCEBAR0_SIZE_LEN = 3;
// eq/reg00010.H

static const uint64_t QME_QSDR = 0x200e0078ull;

static const uint32_t QME_QSDR_QME_QSDR_SRAM_DATA = 0;
static const uint32_t QME_QSDR_QME_QSDR_SRAM_DATA_LEN = 64;
// eq/reg00010.H

static const uint64_t QME_RCTAR0 = 0x200e0190ull;

static const uint32_t QME_RCTAR0_QME_RCTAR0_DATA = 0;
static const uint32_t QME_RCTAR0_QME_RCTAR0_DATA_LEN = 64;
// eq/reg00010.H

static const uint64_t QME_SCOM_PBTXTR1 = 0x200e0041ull;

static const uint32_t QME_SCOM_PBTXTR1__VALID = 0;
static const uint32_t QME_SCOM_PBTXTR1__VALID_LEN = 8;
static const uint32_t QME_SCOM_PBTXTR1_0 = 8;
static const uint32_t QME_SCOM_PBTXTR1_0_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_1 = 12;
static const uint32_t QME_SCOM_PBTXTR1_1_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_2 = 16;
static const uint32_t QME_SCOM_PBTXTR1_2_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_3 = 20;
static const uint32_t QME_SCOM_PBTXTR1_3_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_4 = 24;
static const uint32_t QME_SCOM_PBTXTR1_4_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_5 = 28;
static const uint32_t QME_SCOM_PBTXTR1_5_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_6 = 32;
static const uint32_t QME_SCOM_PBTXTR1_6_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_7 = 36;
static const uint32_t QME_SCOM_PBTXTR1_7_LEN = 4;
// eq/reg00010.H

static const uint64_t QME_SCOM_XIVDR0 = 0x200e0280ull;

static const uint32_t QME_SCOM_XIVDR0_0 = 0;
static const uint32_t QME_SCOM_XIVDR0_0_LEN = 32;
static const uint32_t QME_SCOM_XIVDR0_1 = 32;
static const uint32_t QME_SCOM_XIVDR0_1_LEN = 32;
// eq/reg00010.H

static const uint64_t QME_TSEL = 0x200e0240ull;

static const uint32_t QME_TSEL_WATCHDOG_SEL = 0;
static const uint32_t QME_TSEL_WATCHDOG_SEL_LEN = 4;
static const uint32_t QME_TSEL_FIT_SEL = 4;
static const uint32_t QME_TSEL_FIT_SEL_LEN = 4;
// eq/reg00010.H

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00010.H"
#endif
#endif
