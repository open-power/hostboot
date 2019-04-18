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
// iohs/reg00043.H

static const uint64_t ATTN_INTERRUPT_REG = 0x180f001aull;
// iohs/reg00043.H

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
// iohs/reg00043.H

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
// iohs/reg00043.H

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
// iohs/reg00043.H

static const uint64_t AXON_EPS_PSC_WRITE_PROTECT_RINGS_REG = 0x18010006ull;

static const uint32_t AXON_EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS = 0;
static const uint32_t AXON_EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN = 32;
// iohs/reg00043.H

static const uint64_t AXON_EPS_THERM_WSUB_DTS_RESULT1 = 0x18050001ull;

static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// iohs/reg00043.H

static const uint64_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT = 0x18050003ull;

static const uint32_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE = 0;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN = 44;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT_DTS_1_RESULT = 48;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_TRC_RESULT_DTS_1_RESULT_LEN = 16;
// iohs/reg00043.H

static const uint64_t AXON_EPS_THERM_WSUB_ERR_STATUS_REG = 0x18050013ull;
// iohs/reg00043.H

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
// iohs/reg00043.H

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
// iohs/reg00043.H

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
// iohs/reg00043.H

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
// iohs/reg00043.H

}
}
#include "iohs/reg00043.H"
#endif
