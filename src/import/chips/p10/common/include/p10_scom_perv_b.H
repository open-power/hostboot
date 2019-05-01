/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_b.H $       */
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

#ifndef __p10_scom_perv_b_H_
#define __p10_scom_perv_b_H_


namespace scomt
{
namespace perv
{


static const uint64_t ATOMIC_LOCK_REG = 0x000f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// perv/reg00011.H

static const uint64_t ATTN_INTERRUPT_REG = 0x000f001aull;
// perv/reg00011.H

static const uint64_t DPLL_CNTL_PAU_REGS_ICHAR = 0x00000057ull;

static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_FREQIN_AVG = 1;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_FREQIN_AVG_LEN = 11;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_HIRES_FREQIN_AVG = 12;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_HIRES_FREQIN_AVG_LEN = 5;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_FREQIN_MAX = 21;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_FREQIN_MAX_LEN = 11;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_HIRES_FREQIN_MAX = 32;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_HIRES_FREQIN_MAX_LEN = 5;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_FREQIN_MIN = 41;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_FREQIN_MIN_LEN = 11;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_HIRES_FREQIN_MIN = 52;
static const uint32_t DPLL_CNTL_PAU_REGS_ICHAR_HIRES_FREQIN_MIN_LEN = 5;
// perv/reg00011.H

static const uint64_t DPLL_CNTL_PAU_REGS_OCHAR = 0x00000056ull;

static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_FREQOUT_MAX = 1;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_FREQOUT_MAX_LEN = 11;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_HIRES_FREQOUT_MAX = 12;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_HIRES_FREQOUT_MAX_LEN = 5;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_FREQOUT_AVG = 21;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_FREQOUT_AVG_LEN = 11;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_HIRES_FREQOUT_AVG = 32;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_HIRES_FREQOUT_AVG_LEN = 5;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_FREQOUT_MIN = 41;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_FREQOUT_MIN_LEN = 11;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_HIRES_FREQOUT_MIN = 52;
static const uint32_t DPLL_CNTL_PAU_REGS_OCHAR_HIRES_FREQOUT_MIN_LEN = 5;
// perv/reg00011.H

static const uint64_t EPS_DBG_TRACE_MODE_REG_2 = 0x000107cfull;

static const uint32_t EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// perv/reg00011.H

static const uint64_t EPS_FIR_GXSTOP2_MASK_REG = 0x00040015ull;

static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SUM_XSTOP = 0;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SUM_RECOV = 1;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SUM_SPATTN = 2;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_OOB1 = 6;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// perv/reg00011.H

static const uint64_t EPS_FIR_LOCAL_MASK_RW = 0x0004000dull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_AND = 0x0004000eull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_OR = 0x0004000full;

static const uint32_t EPS_FIR_LOCAL_MASK_00 = 0;
static const uint32_t EPS_FIR_LOCAL_MASK_01 = 1;
static const uint32_t EPS_FIR_LOCAL_MASK_02 = 2;
static const uint32_t EPS_FIR_LOCAL_MASK_03 = 3;
static const uint32_t EPS_FIR_LOCAL_MASK_04 = 4;
static const uint32_t EPS_FIR_LOCAL_MASK_05 = 5;
static const uint32_t EPS_FIR_LOCAL_MASK_06 = 6;
static const uint32_t EPS_FIR_LOCAL_MASK_07 = 7;
static const uint32_t EPS_FIR_LOCAL_MASK_08 = 8;
static const uint32_t EPS_FIR_LOCAL_MASK_09 = 9;
static const uint32_t EPS_FIR_LOCAL_MASK_10 = 10;
static const uint32_t EPS_FIR_LOCAL_MASK_11 = 11;
static const uint32_t EPS_FIR_LOCAL_MASK_12 = 12;
static const uint32_t EPS_FIR_LOCAL_MASK_13 = 13;
static const uint32_t EPS_FIR_LOCAL_MASK_14 = 14;
static const uint32_t EPS_FIR_LOCAL_MASK_15 = 15;
static const uint32_t EPS_FIR_LOCAL_MASK_16 = 16;
static const uint32_t EPS_FIR_LOCAL_MASK_17 = 17;
static const uint32_t EPS_FIR_LOCAL_MASK_18 = 18;
static const uint32_t EPS_FIR_LOCAL_MASK_19 = 19;
static const uint32_t EPS_FIR_LOCAL_MASK_20 = 20;
static const uint32_t EPS_FIR_LOCAL_MASK_21 = 21;
static const uint32_t EPS_FIR_LOCAL_MASK_22 = 22;
static const uint32_t EPS_FIR_LOCAL_MASK_23 = 23;
static const uint32_t EPS_FIR_LOCAL_MASK_24 = 24;
static const uint32_t EPS_FIR_LOCAL_MASK_25 = 25;
static const uint32_t EPS_FIR_LOCAL_MASK_26 = 26;
static const uint32_t EPS_FIR_LOCAL_MASK_27 = 27;
static const uint32_t EPS_FIR_LOCAL_MASK_28 = 28;
static const uint32_t EPS_FIR_LOCAL_MASK_29 = 29;
static const uint32_t EPS_FIR_LOCAL_MASK_30 = 30;
static const uint32_t EPS_FIR_LOCAL_MASK_31 = 31;
static const uint32_t EPS_FIR_LOCAL_MASK_32 = 32;
static const uint32_t EPS_FIR_LOCAL_MASK_33 = 33;
static const uint32_t EPS_FIR_LOCAL_MASK_34 = 34;
static const uint32_t EPS_FIR_LOCAL_MASK_35 = 35;
static const uint32_t EPS_FIR_LOCAL_MASK_36 = 36;
static const uint32_t EPS_FIR_LOCAL_MASK_37 = 37;
static const uint32_t EPS_FIR_LOCAL_MASK_38 = 38;
static const uint32_t EPS_FIR_LOCAL_MASK_39 = 39;
static const uint32_t EPS_FIR_LOCAL_MASK_40 = 40;
static const uint32_t EPS_FIR_LOCAL_MASK_41 = 41;
static const uint32_t EPS_FIR_LOCAL_MASK_42 = 42;
static const uint32_t EPS_FIR_LOCAL_MASK_43 = 43;
static const uint32_t EPS_FIR_LOCAL_MASK_44 = 44;
static const uint32_t EPS_FIR_LOCAL_MASK_45 = 45;
static const uint32_t EPS_FIR_LOCAL_MASK_46 = 46;
static const uint32_t EPS_FIR_LOCAL_MASK_47 = 47;
static const uint32_t EPS_FIR_LOCAL_MASK_48 = 48;
// perv/reg00011.H

static const uint64_t EPS_THERM_WSUB2_CONTROL_REG = 0x00050032ull;
// perv/reg00011.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA2 = 0x0005003bull;
// perv/reg00011.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR1_CONFIG_1 = 0x00018224ull;

static const uint32_t L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00011.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR0_TRACE_LO_DATA_REG = 0x00018241ull;

static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00011.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR0_CONFIG_0 = 0x00018283ull;

static const uint32_t L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00011.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR1_TRACE_HI_DATA_REG = 0x000182a0ull;

static const uint32_t L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00011.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR1_CONFIG_9 = 0x000182a9ull;

static const uint32_t L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00011.H

static const uint64_t LOCAL_FIR_RWX = 0x0004000aull;
static const uint64_t LOCAL_FIR_WOX_AND = 0x0004000bull;
static const uint64_t LOCAL_FIR_WOX_OR = 0x0004000cull;

static const uint32_t LOCAL_FIR_00 = 0;
static const uint32_t LOCAL_FIR_01 = 1;
static const uint32_t LOCAL_FIR_02 = 2;
static const uint32_t LOCAL_FIR_03 = 3;
static const uint32_t LOCAL_FIR_04 = 4;
static const uint32_t LOCAL_FIR_05 = 5;
static const uint32_t LOCAL_FIR_06 = 6;
static const uint32_t LOCAL_FIR_07 = 7;
static const uint32_t LOCAL_FIR_08 = 8;
static const uint32_t LOCAL_FIR_09 = 9;
static const uint32_t LOCAL_FIR_10 = 10;
static const uint32_t LOCAL_FIR_11 = 11;
static const uint32_t LOCAL_FIR_12 = 12;
static const uint32_t LOCAL_FIR_13 = 13;
static const uint32_t LOCAL_FIR_14 = 14;
static const uint32_t LOCAL_FIR_15 = 15;
static const uint32_t LOCAL_FIR_16 = 16;
static const uint32_t LOCAL_FIR_17 = 17;
static const uint32_t LOCAL_FIR_18 = 18;
static const uint32_t LOCAL_FIR_19 = 19;
static const uint32_t LOCAL_FIR_20 = 20;
static const uint32_t LOCAL_FIR_21 = 21;
static const uint32_t LOCAL_FIR_22 = 22;
static const uint32_t LOCAL_FIR_23 = 23;
static const uint32_t LOCAL_FIR_24 = 24;
static const uint32_t LOCAL_FIR_25 = 25;
static const uint32_t LOCAL_FIR_26 = 26;
static const uint32_t LOCAL_FIR_27 = 27;
static const uint32_t LOCAL_FIR_28 = 28;
static const uint32_t LOCAL_FIR_29 = 29;
static const uint32_t LOCAL_FIR_30 = 30;
static const uint32_t LOCAL_FIR_31 = 31;
static const uint32_t LOCAL_FIR_32 = 32;
static const uint32_t LOCAL_FIR_33 = 33;
static const uint32_t LOCAL_FIR_34 = 34;
static const uint32_t LOCAL_FIR_35 = 35;
static const uint32_t LOCAL_FIR_36 = 36;
static const uint32_t LOCAL_FIR_37 = 37;
static const uint32_t LOCAL_FIR_38 = 38;
static const uint32_t LOCAL_FIR_39 = 39;
static const uint32_t LOCAL_FIR_40 = 40;
static const uint32_t LOCAL_FIR_41 = 41;
static const uint32_t LOCAL_FIR_42 = 42;
static const uint32_t LOCAL_FIR_43 = 43;
static const uint32_t LOCAL_FIR_44 = 44;
static const uint32_t LOCAL_FIR_45 = 45;
static const uint32_t LOCAL_FIR_46 = 46;
static const uint32_t LOCAL_FIR_47 = 47;
static const uint32_t LOCAL_FIR_48 = 48;
// perv/reg00011.H

static const uint64_t TRA0_TR1_CONFIG_1 = 0x00010444ull;

static const uint32_t TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00011.H

static const uint64_t TRA2_TR0_CONFIG_0 = 0x00010503ull;

static const uint32_t TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00011.H

static const uint64_t TRA2_TR1_CONFIG = 0x00010542ull;

static const uint32_t TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00011.H

static const uint64_t TRA2_TR1_CONFIG_9 = 0x00010549ull;

static const uint32_t TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00011.H

static const uint64_t TRA3_TR0_CONFIG = 0x00010582ull;

static const uint32_t TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00011.H

static const uint64_t TRA5_TR0_CONFIG_1 = 0x00010684ull;

static const uint32_t TRA5_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA5_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00011.H

static const uint64_t TRA5_TR1_TRACE_LO_DATA_REG = 0x000106c1ull;

static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00011.H

static const uint64_t TRA6_TR0_TRACE_HI_DATA_REG = 0x00010700ull;

static const uint32_t TRA6_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA6_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00011.H

static const uint64_t TRA7_TR0_CONFIG_9 = 0x00010789ull;

static const uint32_t TRA7_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA7_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA7_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA7_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA7_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA7_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA7_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00011.H

}
}
#include "perv/reg00011.H"
#endif
