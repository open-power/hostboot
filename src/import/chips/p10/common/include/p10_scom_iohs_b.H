/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_b.H $       */
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

#ifndef __p10_scom_iohs_b_H_
#define __p10_scom_iohs_b_H_


namespace scomt
{
namespace iohs
{


static const uint64_t ATOMIC_LOCK_REG = 0x180f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// iohs/reg00046.H

static const uint64_t ATTN_INTERRUPT_REG = 0x180f001aull;
// iohs/reg00046.H

static const uint64_t AXON_EPS_DBG_INST1_COND_REG_1 = 0x180107c1ull;

static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// iohs/reg00046.H

static const uint64_t AXON_EPS_DBG_INST2_COND_REG_1 = 0x180107c4ull;

static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// iohs/reg00046.H

static const uint64_t AXON_EPS_FIR_GXSTOP4_MASK_REG = 0x1804001bull;

static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP = 0;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV = 1;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN = 2;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_OOB1 = 6;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t AXON_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// iohs/reg00046.H

static const uint64_t AXON_EPS_PSC_WRITE_PROTECT_RINGS_REG = 0x18010006ull;

static const uint32_t AXON_EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS = 0;
static const uint32_t AXON_EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN = 32;
// iohs/reg00046.H

static const uint64_t AXON_EPS_THERM_WSUB_DTS_RESULT1 = 0x18050001ull;

static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// iohs/reg00046.H

static const uint64_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT = 0x18050003ull;

static const uint32_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE = 0;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN = 44;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT_DTS_1_RESULT = 48;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT_DTS_1_RESULT_LEN = 16;
// iohs/reg00046.H

static const uint64_t AXON_EPS_THERM_WSUB_ERR_STATUS_REG = 0x18050013ull;
// iohs/reg00046.H

static const uint64_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG = 0x18050010ull;

static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE = 0;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG_DISABLE_SKITTER_STICKINESS = 1;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL = 4;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL = 6;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS = 8;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS_LEN = 2;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE_WITH_TRIGGER = 44;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_DATA_V_LT = 45;
// iohs/reg00046.H

static const uint64_t AXON_FIR_MASK = 0x18040002ull;

static const uint32_t AXON_FIR_MASK_01 = 1;
static const uint32_t AXON_FIR_MASK_02 = 2;
static const uint32_t AXON_FIR_MASK_03 = 3;
static const uint32_t AXON_FIR_MASK_04 = 4;
static const uint32_t AXON_FIR_MASK_05 = 5;
static const uint32_t AXON_FIR_MASK_06 = 6;
static const uint32_t AXON_FIR_MASK_07 = 7;
static const uint32_t AXON_FIR_MASK_08 = 8;
static const uint32_t AXON_FIR_MASK_09 = 9;
static const uint32_t AXON_FIR_MASK_10 = 10;
static const uint32_t AXON_FIR_MASK_11 = 11;
static const uint32_t AXON_FIR_MASK_12 = 12;
static const uint32_t AXON_FIR_MASK_13 = 13;
static const uint32_t AXON_FIR_MASK_14 = 14;
static const uint32_t AXON_FIR_MASK_15 = 15;
static const uint32_t AXON_FIR_MASK_16 = 16;
static const uint32_t AXON_FIR_MASK_17 = 17;
static const uint32_t AXON_FIR_MASK_18 = 18;
static const uint32_t AXON_FIR_MASK_19 = 19;
static const uint32_t AXON_FIR_MASK_20 = 20;
static const uint32_t AXON_FIR_MASK_21 = 21;
static const uint32_t AXON_FIR_MASK_22 = 22;
static const uint32_t AXON_FIR_MASK_23 = 23;
static const uint32_t AXON_FIR_MASK_24 = 24;
static const uint32_t AXON_FIR_MASK_25 = 25;
static const uint32_t AXON_FIR_MASK_26 = 26;
static const uint32_t AXON_FIR_MASK_27 = 27;
static const uint32_t AXON_FIR_MASK_28 = 28;
static const uint32_t AXON_FIR_MASK_29 = 29;
static const uint32_t AXON_FIR_MASK_30 = 30;
static const uint32_t AXON_FIR_MASK_31 = 31;
static const uint32_t AXON_FIR_MASK_32 = 32;
static const uint32_t AXON_FIR_MASK_33 = 33;
static const uint32_t AXON_FIR_MASK_34 = 34;
static const uint32_t AXON_FIR_MASK_35 = 35;
static const uint32_t AXON_FIR_MASK_36 = 36;
static const uint32_t AXON_FIR_MASK_37 = 37;
static const uint32_t AXON_FIR_MASK_38 = 38;
static const uint32_t AXON_FIR_MASK_39 = 39;
static const uint32_t AXON_FIR_MASK_40 = 40;
static const uint32_t AXON_FIR_MASK_41 = 41;
static const uint32_t AXON_FIR_MASK_42 = 42;
static const uint32_t AXON_FIR_MASK_43 = 43;
static const uint32_t AXON_FIR_MASK_44 = 44;
static const uint32_t AXON_FIR_MASK_45 = 45;
static const uint32_t AXON_FIR_MASK_46 = 46;
static const uint32_t AXON_FIR_MASK_47 = 47;
static const uint32_t AXON_FIR_MASK_48 = 48;
static const uint32_t AXON_FIR_MASK_49 = 49;
static const uint32_t AXON_FIR_MASK_50 = 50;
static const uint32_t AXON_FIR_MASK_51 = 51;
static const uint32_t AXON_FIR_MASK_52 = 52;
static const uint32_t AXON_FIR_MASK_53 = 53;
// iohs/reg00046.H

static const uint64_t AXON_SCAN_REGION_TYPE = 0x18030005ull;

static const uint32_t AXON_SCAN_REGION_TYPE_SYSTEM_FAST_INIT = 0;
static const uint32_t AXON_SCAN_REGION_TYPE_PARALLEL_SCAN = 1;
static const uint32_t AXON_SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR = 2;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_VITL = 3;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_PERV = 4;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT1 = 5;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT2 = 6;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT3 = 7;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT4 = 8;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT5 = 9;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT6 = 10;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT7 = 11;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT8 = 12;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT9 = 13;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT10 = 14;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT11 = 15;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT12 = 16;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT13 = 17;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_REGION_UNIT14 = 18;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_FUNC = 48;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_CFG = 49;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR = 50;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_REGF = 51;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_LBIST = 52;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_ABIST = 53;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_REPR = 54;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_TIME = 55;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_BNDY = 56;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_FARR = 57;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_CMSK = 58;
static const uint32_t AXON_SCAN_REGION_TYPE_SCAN_TYPE_INEX = 59;
// iohs/reg00046.H

static const uint64_t AXON_XFIR = 0x18040000ull;

static const uint32_t AXON_XFIR_ANY_XSTOP = 0;
static const uint32_t AXON_XFIR_SYSTEM_XSTOP = 1;
static const uint32_t AXON_XFIR_XSTOP_ANY_SPATTN = 2;
static const uint32_t AXON_XFIR_DBG_FIR_XSTOP_ON_TRIG = 3;
static const uint32_t AXON_XFIR_XSTOP_PERV = 4;
static const uint32_t AXON_XFIR_XSTOP_IN05 = 5;
static const uint32_t AXON_XFIR_XSTOP_IN06 = 6;
static const uint32_t AXON_XFIR_XSTOP_IN07 = 7;
static const uint32_t AXON_XFIR_XSTOP_IN08 = 8;
static const uint32_t AXON_XFIR_XSTOP_IN09 = 9;
static const uint32_t AXON_XFIR_XSTOP_IN10 = 10;
static const uint32_t AXON_XFIR_XSTOP_IN11 = 11;
static const uint32_t AXON_XFIR_XSTOP_IN12 = 12;
static const uint32_t AXON_XFIR_XSTOP_IN13 = 13;
static const uint32_t AXON_XFIR_XSTOP_IN14 = 14;
static const uint32_t AXON_XFIR_XSTOP_IN15 = 15;
static const uint32_t AXON_XFIR_XSTOP_IN16 = 16;
static const uint32_t AXON_XFIR_XSTOP_IN17 = 17;
static const uint32_t AXON_XFIR_XSTOP_IN18 = 18;
static const uint32_t AXON_XFIR_XSTOP_IN19 = 19;
static const uint32_t AXON_XFIR_XSTOP_IN20 = 20;
static const uint32_t AXON_XFIR_XSTOP_IN21 = 21;
static const uint32_t AXON_XFIR_XSTOP_IN22 = 22;
static const uint32_t AXON_XFIR_XSTOP_IN23 = 23;
static const uint32_t AXON_XFIR_XSTOP_IN24 = 24;
static const uint32_t AXON_XFIR_XSTOP_IN25 = 25;
static const uint32_t AXON_XFIR_XSTOP_IN26 = 26;
static const uint32_t AXON_XFIR_XSTOP_IN27 = 27;
static const uint32_t AXON_XFIR_XSTOP_IN28 = 28;
static const uint32_t AXON_XFIR_XSTOP_IN29 = 29;
static const uint32_t AXON_XFIR_XSTOP_IN30 = 30;
static const uint32_t AXON_XFIR_XSTOP_IN31 = 31;
static const uint32_t AXON_XFIR_XSTOP_IN32 = 32;
static const uint32_t AXON_XFIR_XSTOP_IN33 = 33;
static const uint32_t AXON_XFIR_XSTOP_IN34 = 34;
static const uint32_t AXON_XFIR_XSTOP_IN35 = 35;
static const uint32_t AXON_XFIR_XSTOP_IN36 = 36;
static const uint32_t AXON_XFIR_XSTOP_IN37 = 37;
static const uint32_t AXON_XFIR_XSTOP_IN38 = 38;
static const uint32_t AXON_XFIR_XSTOP_IN39 = 39;
static const uint32_t AXON_XFIR_XSTOP_IN40 = 40;
static const uint32_t AXON_XFIR_XSTOP_IN41 = 41;
static const uint32_t AXON_XFIR_XSTOP_IN42 = 42;
static const uint32_t AXON_XFIR_XSTOP_IN43 = 43;
static const uint32_t AXON_XFIR_XSTOP_IN44 = 44;
static const uint32_t AXON_XFIR_XSTOP_IN45 = 45;
static const uint32_t AXON_XFIR_XSTOP_IN46 = 46;
static const uint32_t AXON_XFIR_XSTOP_IN47 = 47;
static const uint32_t AXON_XFIR_XSTOP_IN48 = 48;
static const uint32_t AXON_XFIR_XSTOP_IN49 = 49;
static const uint32_t AXON_XFIR_XSTOP_IN50 = 50;
static const uint32_t AXON_XFIR_XSTOP_IN51 = 51;
static const uint32_t AXON_XFIR_XSTOP_IN52 = 52;
static const uint32_t AXON_XFIR_XSTOP_IN53 = 53;
// iohs/reg00046.H

static const uint64_t DLX_CONFIG = 0x18011031ull;

static const uint32_t DLX_CONFIG_CFG_DLX1 = 0;
static const uint32_t DLX_CONFIG_CFG_DLX1_LEN = 32;
// iohs/reg00046.H

static const uint64_t FIR_REG_SCOM = 0x18011000ull;
static const uint64_t FIR_REG_SCOM1 = 0x18011001ull;
static const uint64_t FIR_REG_SCOM2 = 0x18011002ull;

static const uint32_t FIR_REG_LINK0_TRAINED = 0;
static const uint32_t FIR_REG_LINK1_TRAINED = 1;
static const uint32_t FIR_REG_LINK0_OP_IRQ = 2;
static const uint32_t FIR_REG_LINK1_OP_IRQ = 3;
static const uint32_t FIR_REG_LINK0_REPLAY_THRESHOLD = 4;
static const uint32_t FIR_REG_LINK1_REPLAY_THRESHOLD = 5;
static const uint32_t FIR_REG_LINK0_CRC_ERROR = 6;
static const uint32_t FIR_REG_LINK1_CRC_ERROR = 7;
static const uint32_t FIR_REG_LINK0_NAK_RECEIVED = 8;
static const uint32_t FIR_REG_LINK1_NAK_RECEIVED = 9;
static const uint32_t FIR_REG_LINK0_REPLAY_BUFFER_FULL = 10;
static const uint32_t FIR_REG_LINK1_REPLAY_BUFFER_FULL = 11;
static const uint32_t FIR_REG_LINK0_SL_ECC_THRESHOLD = 12;
static const uint32_t FIR_REG_LINK1_SL_ECC_THRESHOLD = 13;
static const uint32_t FIR_REG_LINK0_SL_ECC_CORRECTABLE = 14;
static const uint32_t FIR_REG_LINK1_SL_ECC_CORRECTABLE = 15;
static const uint32_t FIR_REG_LINK0_SL_ECC_UE = 16;
static const uint32_t FIR_REG_LINK1_SL_ECC_UE = 17;
static const uint32_t FIR_REG_LINK0_RETRAIN_THRESHOLD = 18;
static const uint32_t FIR_REG_LINK1_RETRAIN_THRESHOLD = 19;
static const uint32_t FIR_REG_LINK0_LOSS_BLOCK_ALIGN = 20;
static const uint32_t FIR_REG_LINK1_LOSS_BLOCK_ALIGN = 21;
static const uint32_t FIR_REG_LINK0_INVALID_BLOCK = 22;
static const uint32_t FIR_REG_LINK1_INVALID_BLOCK = 23;
static const uint32_t FIR_REG_LINK0_DESKEW_ERROR = 24;
static const uint32_t FIR_REG_LINK1_DESKEW_ERROR = 25;
static const uint32_t FIR_REG_LINK0_DESKEW_OVERFLOW = 26;
static const uint32_t FIR_REG_LINK1_DESKEW_OVERFLOW = 27;
static const uint32_t FIR_REG_LINK0_SW_RETRAIN = 28;
static const uint32_t FIR_REG_LINK1_SW_RETRAIN = 29;
static const uint32_t FIR_REG_LINK0_ACK_QUEUE_OVERFLOW = 30;
static const uint32_t FIR_REG_LINK1_ACK_QUEUE_OVERFLOW = 31;
static const uint32_t FIR_REG_LINK0_ACK_QUEUE_UNDERFLOW = 32;
static const uint32_t FIR_REG_LINK1_ACK_QUEUE_UNDERFLOW = 33;
static const uint32_t FIR_REG_LINK0_NUM_REPLAY = 34;
static const uint32_t FIR_REG_LINK1_NUM_REPLAY = 35;
static const uint32_t FIR_REG_LINK0_TRAINING_SET_RECEIVED = 36;
static const uint32_t FIR_REG_LINK1_TRAINING_SET_RECEIVED = 37;
static const uint32_t FIR_REG_LINK0_PRBS_SELECT_ERROR = 38;
static const uint32_t FIR_REG_LINK1_PRBS_SELECT_ERROR = 39;
static const uint32_t FIR_REG_LINK0_TCOMPLETE_BAD = 40;
static const uint32_t FIR_REG_LINK1_TCOMPLETE_BAD = 41;
static const uint32_t FIR_REG_LINK0_NO_SPARE = 42;
static const uint32_t FIR_REG_LINK1_NO_SPARE = 43;
static const uint32_t FIR_REG_LINK0_SPARE_DONE = 44;
static const uint32_t FIR_REG_LINK1_SPARE_DONE = 45;
static const uint32_t FIR_REG_LINK0_TOO_MANY_CRC_ERRORS = 46;
static const uint32_t FIR_REG_LINK1_TOO_MANY_CRC_ERRORS = 47;
static const uint32_t FIR_REG_LINK0_NPU_DLX_ERROR = 48;
static const uint32_t FIR_REG_LINK1_NPU_DLX_ERROR = 49;
static const uint32_t FIR_REG_OSC_SWITCH = 51;
static const uint32_t FIR_REG_LINK0_CORRECTABLE_ARRAY_ERROR = 52;
static const uint32_t FIR_REG_LINK1_CORRECTABLE_ARRAY_ERROR = 53;
static const uint32_t FIR_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR = 54;
static const uint32_t FIR_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR = 55;
static const uint32_t FIR_REG_LINK0_TRAINING_FAILED = 56;
static const uint32_t FIR_REG_LINK1_TRAINING_FAILED = 57;
static const uint32_t FIR_REG_LINK0_UNRECOVERABLE_ERROR = 58;
static const uint32_t FIR_REG_LINK1_UNRECOVERABLE_ERROR = 59;
static const uint32_t FIR_REG_LINK0_INTERNAL_ERROR = 60;
static const uint32_t FIR_REG_LINK1_INTERNAL_ERROR = 61;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG = 0x800910200000003full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS = 62;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET = 63;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG = 0x800880200000003full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1 = 51;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 = 56;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2 = 59;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2_LEN = 5;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE5_PG = 0x800828200000003full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1 = 51;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 = 56;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2 = 59;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2_LEN = 5;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG = 0x800930200000003full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN = 12;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG = 0x8009f0200000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL = 53;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL = 58;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL_LEN = 5;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT24_PG = 0x800a40200000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN = 8;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG = 0x8009b8200000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN = 16;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT12_PG = 0x800ae8200000003full;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT22_PG = 0x800b38200000003full;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT7_PG = 0x800ac0200000003full;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL = 0x8003c0210000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_1_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_1_PLREGS_RX_STAT1_PL = 0x8003e0210000003full;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL = 0x8003d82f0000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_15_PLREGS_RX_CNTL2_PL = 0x8003c82b0000003full;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL = 0x8003d0290000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL = 0x8003c0320000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_18_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_18_PLREGS_RX_STAT1_PL = 0x8003e0320000003full;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL = 0x8003d0350000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_23_PLREGS_RX_CNTL2_PL = 0x8003c8370000003full;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL = 0x8003d8280000003full;

static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_MODE1_PL = 0x800320200000003full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b8200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f8200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x800248200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c0200000003full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x800110210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x800160210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b0210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x800220210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x800270210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x800298210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL17_PL = 0x800088210000003full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d0220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x800210220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x800260220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00046.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL16_PL = 0x800080220000003full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE6_PL = 0x800348230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a8230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f8230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x800148230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x800198230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b0230000003full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL2_PL = 0x800368240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE4_PL = 0x800338240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_STAT2_PL = 0x800398240000003full;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f0240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x800240240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c8240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL3_PL = 0x800018240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTLX9_PL = 0x800048240000003full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE8_PL = 0x800358250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x800118250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x800168250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b8250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d8250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x800228250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x800278250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x800290250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL6_PL = 0x800030250000003full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x800108260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x800158260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a8260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a0260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL17_PL = 0x800088260000003full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL = 0x800360270000003full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_MODE6_PL = 0x800348270000003full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e0270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x800130270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x800180270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d0270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c0270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x800200270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x800250270000003full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE1_PL = 0x800320280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800318280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x800120280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x800170280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c0280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x800288280000003full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_FIR_MASK_PL = 0x800310310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e8310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x800238310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL16_PL = 0x800080310000003full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b0300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x800100300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00047.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x800150300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a0300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a8300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL3_PL = 0x800018300000003full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX5_PL = 0x8003802f0000003full;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE3_PL = 0x8003302f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT5_PL = 0x8003b02f0000003full;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000982f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e82f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001382f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001882f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c82f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002082f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002582f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL6_PL = 0x8000302f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTLX9_PL = 0x8000482f0000003full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL2_PL = 0x8003682e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE4_PL = 0x8003382e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_STAT2_PL = 0x8003982e0000003full;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_SPARE_MODE_PL = 0x8003002e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001102e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001602e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b02e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002202e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002702e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002982e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL4_PL = 0x8000202e0000003full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE8_PL = 0x8003582d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b82d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f82d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002482d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c02d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL1_PL = 0x8000082d0000003full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8003182c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a82c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f82c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001482c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001982c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b02c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000002c0000003full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE3_PL = 0x8003302b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT5_PL = 0x8003b02b0000003full;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_FIR_PL = 0x8003082b0000003full;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d02b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002102b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002602b0000003full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE1_PL = 0x8003202a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001182a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001682a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b82a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00048.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d82a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002282a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002782a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002902a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL13_PL = 0x8000682a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL8_PL = 0x8000402a0000003full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f0290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x800240290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c8290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL15_PL = 0x800078290000003full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG = 0x800d2c200000003full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1_LEN = 8;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL14_PL = 0x80049c200000003full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL24_PL = 0x8004ec200000003full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL18_PL = 0x8004bc220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL28_PL = 0x80050c220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL9_PL = 0x800474220000003full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL12_PL = 0x80048c230000003full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL22_PL = 0x8004dc230000003full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL4_PL = 0x80044c230000003full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_FIR_MASK_PL = 0x80040c230000003full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE2_PL = 0x800424230000003full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL15_PL = 0x8004a4250000003full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL25_PL = 0x8004f4250000003full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL7_PL = 0x800464250000003full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL = 0x80041c250000003full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL15_PL = 0x8004a4260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL25_PL = 0x8004f4260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_FIR_MASK_PL = 0x80040c260000003full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL3_PL = 0x800444270000003full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL19_PL = 0x8004c4280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL29_PL = 0x800514280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL7_PL = 0x800464280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL = 0x80041c280000003full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL13_PL = 0x800494310000003full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL23_PL = 0x8004e4310000003full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_FIR_PL = 0x800404310000003full;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL4_PL = 0x80044c300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE2_PL = 0x800424300000003full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL14_PL = 0x80049c2f0000003full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL24_PL = 0x8004ec2f0000003full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL9_PL = 0x8004742f0000003full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL17_PL = 0x8004b42d0000003full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL27_PL = 0x8005042d0000003full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL2_PL = 0x80043c2d0000003full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL11_PL = 0x8004842c0000003full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL1G_PL = 0x8004342c0000003full;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL21_PL = 0x8004d42c0000003full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL6_PL = 0x80045c2c0000003full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004142b0000003full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL = 0x8004ac2a0000003full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00049.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL = 0x8004fc2a0000003full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00050.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL = 0x8004542a0000003full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00050.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL = 0x80040c2a0000003full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00050.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL = 0x8004042a0000003full;
// iohs/reg00050.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL = 0x80042c2a0000003full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// iohs/reg00050.H

//ERRCODE: // Some of the name targets not found in address targets: iohs

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL = 0x80046c290000003full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00050.H

static const uint64_t LAT_MEASURE = 0x1801100eull;

static const uint32_t LAT_MEASURE_LINK0_ROUND_TRIP_VALID = 0;
static const uint32_t LAT_MEASURE_LINK0_ROUND_TRIP = 2;
static const uint32_t LAT_MEASURE_LINK0_ROUND_TRIP_LEN = 10;
static const uint32_t LAT_MEASURE_LINK1_ROUND_TRIP_VALID = 12;
static const uint32_t LAT_MEASURE_LINK1_ROUND_TRIP = 14;
static const uint32_t LAT_MEASURE_LINK1_ROUND_TRIP_LEN = 10;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID = 24;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK = 25;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE = 29;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN = 7;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID = 36;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK = 37;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE = 41;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN = 7;
static const uint32_t LAT_MEASURE_LINK0_TOD_LATENCY = 49;
static const uint32_t LAT_MEASURE_LINK0_TOD_LATENCY_LEN = 7;
static const uint32_t LAT_MEASURE_LINK1_TOD_LATENCY = 57;
static const uint32_t LAT_MEASURE_LINK1_TOD_LATENCY_LEN = 7;
// iohs/reg00050.H

static const uint64_t PERF_COUNTERS_1 = 0x1801101full;

static const uint32_t PERF_COUNTERS_1_4 = 0;
static const uint32_t PERF_COUNTERS_1_4_LEN = 16;
static const uint32_t PERF_COUNTERS_1_5 = 16;
static const uint32_t PERF_COUNTERS_1_5_LEN = 16;
static const uint32_t PERF_COUNTERS_1_6 = 32;
static const uint32_t PERF_COUNTERS_1_6_LEN = 16;
static const uint32_t PERF_COUNTERS_1_7 = 48;
static const uint32_t PERF_COUNTERS_1_7_LEN = 16;
// iohs/reg00050.H

static const uint64_t PHY_CONFIG = 0x1801100cull;

static const uint32_t PHY_CONFIG_PHY_TRAIN_A_ADJ = 0;
static const uint32_t PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN = 2;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_ADJ = 2;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN = 2;
static const uint32_t PHY_CONFIG_PHY_TRAIN_TIME = 4;
static const uint32_t PHY_CONFIG_PHY_TRAIN_TIME_LEN = 4;
static const uint32_t PHY_CONFIG_PHY_TRAIN_A_HYST = 8;
static const uint32_t PHY_CONFIG_PHY_TRAIN_A_HYST_LEN = 4;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_HYST = 12;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_HYST_LEN = 4;
static const uint32_t PHY_CONFIG_PRBS_PHASE_SELECT = 16;
static const uint32_t PHY_CONFIG_PRBS_PHASE_SELECT_LEN = 24;
static const uint32_t PHY_CONFIG_PRBS_CONFIG = 40;
static const uint32_t PHY_CONFIG_PRBS_CONFIG_LEN = 10;
static const uint32_t PHY_CONFIG_PRBS_INVERT = 50;
static const uint32_t PHY_CONFIG_LINK0_SELECT = 56;
static const uint32_t PHY_CONFIG_LINK1_SELECT = 57;
static const uint32_t PHY_CONFIG_PRECODER_ENABLE = 60;
static const uint32_t PHY_CONFIG_50G_MODE = 61;
static const uint32_t PHY_CONFIG_DL_SELECT = 62;
static const uint32_t PHY_CONFIG_DL_SELECT_LEN = 2;
// iohs/reg00050.H

}
}
#include "iohs/reg00046.H"
#include "iohs/reg00047.H"
#include "iohs/reg00048.H"
#include "iohs/reg00049.H"
#include "iohs/reg00050.H"
#endif
