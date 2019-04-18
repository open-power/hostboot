/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_a.H $       */
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

#ifndef __p10_scom_perv_a_H_
#define __p10_scom_perv_a_H_


namespace scomt
{
namespace perv
{


static const uint64_t CC_PROTECT_MODE_REG = 0x000303feull;

static const uint32_t CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// perv/reg00222.H

static const uint64_t CLOCK_STAT_SL = 0x00030008ull;

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
// perv/reg00222.H

static const uint64_t CPLT_CTRL3_RW = 0x00000003ull;
static const uint64_t CPLT_CTRL3_WO_CLEAR = 0x00000023ull;
static const uint64_t CPLT_CTRL3_WO_OR = 0x00000013ull;

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
// perv/reg00222.H

static const uint64_t DPLL_CNTL_PAU_REGS_ECHAR = 0x00000058ull;

static const uint32_t DPLL_CNTL_PAU_REGS_ECHAR_DYNAMIC_ENCODED_DATA = 1;
static const uint32_t DPLL_CNTL_PAU_REGS_ECHAR_DYNAMIC_ENCODED_DATA_LEN = 3;
static const uint32_t DPLL_CNTL_PAU_REGS_ECHAR_MIN_ENCODED_DATA = 5;
static const uint32_t DPLL_CNTL_PAU_REGS_ECHAR_MIN_ENCODED_DATA_LEN = 3;
static const uint32_t DPLL_CNTL_PAU_REGS_ECHAR_MAX_ENCODED_DATA = 9;
static const uint32_t DPLL_CNTL_PAU_REGS_ECHAR_MAX_ENCODED_DATA_LEN = 3;
static const uint32_t DPLL_CNTL_PAU_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT = 61;
static const uint32_t DPLL_CNTL_PAU_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT_LEN = 3;
// perv/reg00222.H

static const uint64_t DPLL_CNTL_PAU_REGS_TESTSEL = 0x00000059ull;

static const uint32_t DPLL_CNTL_PAU_REGS_TESTSEL_DPLL_TESTSEL_TEST_SEL = 0;
static const uint32_t DPLL_CNTL_PAU_REGS_TESTSEL_DPLL_TESTSEL_TEST_SEL_LEN = 8;
// perv/reg00222.H

static const uint64_t EPS_DBG_INST1_COND_REG_1 = 0x000107c1ull;

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
// perv/reg00222.H

static const uint64_t EPS_DBG_INST2_COND_REG_1 = 0x000107c4ull;

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
// perv/reg00222.H

static const uint64_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG = 0x00010007ull;

static const uint32_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK = 0;
static const uint32_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN = 32;
// perv/reg00222.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR0_TRACE_HI_DATA_REG = 0x00018200ull;

static const uint32_t L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00222.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR1_CONFIG_1 = 0x00018264ull;

static const uint32_t L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00222.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR0_CONFIG_0 = 0x000182c3ull;

static const uint32_t L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00222.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR1_TRACE_LO_DATA_REG = 0x000182e1ull;

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
// perv/reg00222.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR1_CONFIG_9 = 0x000182e9ull;

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
// perv/reg00222.H

static const uint64_t TRA1_TR1_CONFIG_1 = 0x000104c4ull;

static const uint32_t TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00222.H

static const uint64_t TRA3_TR0_CONFIG_0 = 0x00010583ull;

static const uint32_t TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00222.H

static const uint64_t TRA3_TR1_CONFIG_9 = 0x000105c9ull;

static const uint32_t TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00222.H

static const uint64_t TRA4_TR0_CONFIG_1 = 0x00010604ull;

static const uint32_t TRA4_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA4_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00222.H

static const uint64_t TRA4_TR1_TRACE_HI_DATA_REG = 0x00010640ull;

static const uint32_t TRA4_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA4_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00222.H

static const uint64_t TRA6_TR0_CONFIG_9 = 0x00010709ull;

static const uint32_t TRA6_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA6_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA6_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA6_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA6_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA6_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA6_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA6_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA6_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA6_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA6_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA6_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA6_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA6_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA6_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA6_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00222.H

static const uint64_t TRA6_TR1_CONFIG_0 = 0x00010743ull;

static const uint32_t TRA6_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA6_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00222.H

static const uint64_t TRA7_TR0_TRACE_LO_DATA_REG = 0x00010781ull;

static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA7_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00222.H

}
}
#include "perv/reg00222.H"
#endif
