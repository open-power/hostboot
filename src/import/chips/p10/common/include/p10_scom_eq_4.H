/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_4.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __p10_scom_eq_4_H_
#define __p10_scom_eq_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [CLOCK_STAT_ARY]
static const uint64_t CLOCK_STAT_ARY = 0x2003000aull;

static const uint32_t CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t CLOCK_STAT_ARY_UNIT14_ARY = 18;
//<< [CLOCK_STAT_ARY]
// eq/reg00004.H

//>> [OPCG_REG2]
static const uint64_t OPCG_REG2 = 0x20030004ull;

static const uint32_t OPCG_REG2_OPCG_GO2 = 0;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING = 1;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING_LEN = 3;
static const uint32_t OPCG_REG2_PRPG_SEED = 4;
static const uint32_t OPCG_REG2_PRPG_SEED_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_A_VAL = 16;
static const uint32_t OPCG_REG2_PRPG_A_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_B_VAL = 28;
static const uint32_t OPCG_REG2_PRPG_B_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_MODE = 40;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM = 48;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM_LEN = 4;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK = 52;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK_LEN = 4;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT = 56;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE = 57;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE = 58;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE = 59;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT = 60;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT_LEN = 4;
//<< [OPCG_REG2]
// eq/reg00004.H

//>> [QME_QHB]
static const uint64_t QME_QHB = 0x200e0080ull;

static const uint32_t QME_QHB_HEARTBEAT_COUNT = 0;
static const uint32_t QME_QHB_HEARTBEAT_COUNT_LEN = 16;
static const uint32_t QME_QHB_HEARTBEAT_ENABLE = 16;
static const uint32_t QME_QHB_SPARE = 17;
//<< [QME_QHB]
// eq/reg00004.H

//>> [QME_EISTR]
static const uint64_t QME_EISTR = 0x200e0270ull;

static const uint32_t QME_EISTR_INTERRUPT_STATUS = 0;
static const uint32_t QME_EISTR_INTERRUPT_STATUS_LEN = 64;
//<< [QME_EISTR]
// eq/reg00004.H

//>> [QME_LFIRACT0]
static const uint64_t QME_LFIRACT0 = 0x200e0008ull;

static const uint32_t QME_LFIRACT0_FIR_ACTION0 = 0;
static const uint32_t QME_LFIRACT0_FIR_ACTION0_LEN = 36;
//<< [QME_LFIRACT0]
// eq/reg00004.H

//>> [QME_FTXR]
static const uint64_t QME_FTXR = 0x200e0178ull;

static const uint32_t QME_FTXR_C0_DTC_INDEX = 2;
static const uint32_t QME_FTXR_C0_DTC_INDEX_LEN = 6;
static const uint32_t QME_FTXR_C1_DTC_INDEX = 10;
static const uint32_t QME_FTXR_C1_DTC_INDEX_LEN = 6;
static const uint32_t QME_FTXR_C2_DTC_INDEX = 18;
static const uint32_t QME_FTXR_C2_DTC_INDEX_LEN = 6;
static const uint32_t QME_FTXR_C3_DTC_INDEX = 26;
static const uint32_t QME_FTXR_C3_DTC_INDEX_LEN = 6;
static const uint32_t QME_FTXR_FTX_UPDATE_PENDING = 32;
static const uint32_t QME_FTXR_FTX_UPDATE_PENDING_LEN = 4;
static const uint32_t QME_FTXR_QOS_UPDATE_PENDING = 36;
static const uint32_t QME_FTXR_QOS_UPDATE_PENDING_LEN = 4;
//<< [QME_FTXR]
// eq/reg00004.H

//>> [QME_PLSR]
static const uint64_t QME_PLSR = 0x200e0148ull;

static const uint32_t QME_PLSR_0_T0 = 0;
static const uint32_t QME_PLSR_0_T0_LEN = 4;
static const uint32_t QME_PLSR_0_T1 = 4;
static const uint32_t QME_PLSR_0_T1_LEN = 4;
static const uint32_t QME_PLSR_0_T2 = 8;
static const uint32_t QME_PLSR_0_T2_LEN = 4;
static const uint32_t QME_PLSR_0_T3 = 12;
static const uint32_t QME_PLSR_0_T3_LEN = 4;
static const uint32_t QME_PLSR_1_T0 = 16;
static const uint32_t QME_PLSR_1_T0_LEN = 4;
static const uint32_t QME_PLSR_1_T1 = 20;
static const uint32_t QME_PLSR_1_T1_LEN = 4;
static const uint32_t QME_PLSR_1_T2 = 24;
static const uint32_t QME_PLSR_1_T2_LEN = 4;
static const uint32_t QME_PLSR_1_T3 = 28;
static const uint32_t QME_PLSR_1_T3_LEN = 4;
static const uint32_t QME_PLSR_2_T0 = 32;
static const uint32_t QME_PLSR_2_T0_LEN = 4;
static const uint32_t QME_PLSR_2_T1 = 36;
static const uint32_t QME_PLSR_2_T1_LEN = 4;
static const uint32_t QME_PLSR_2_T2 = 40;
static const uint32_t QME_PLSR_2_T2_LEN = 4;
static const uint32_t QME_PLSR_2_T3 = 44;
static const uint32_t QME_PLSR_2_T3_LEN = 4;
static const uint32_t QME_PLSR_3_T0 = 48;
static const uint32_t QME_PLSR_3_T0_LEN = 4;
static const uint32_t QME_PLSR_3_T1 = 52;
static const uint32_t QME_PLSR_3_T1_LEN = 4;
static const uint32_t QME_PLSR_3_T2 = 56;
static const uint32_t QME_PLSR_3_T2_LEN = 4;
static const uint32_t QME_PLSR_3_T3 = 60;
static const uint32_t QME_PLSR_3_T3_LEN = 4;
//<< [QME_PLSR]
// eq/reg00004.H

//>> [QME_RCSCR]
static const uint64_t QME_RCSCR = 0x200e0184ull;
static const uint64_t QME_RCSCR_WO_CLEAR = 0x200e0187ull;
static const uint64_t QME_RCSCR_WO_OR = 0x200e0186ull;

static const uint32_t QME_RCSCR_OFF_REQ = 0;
static const uint32_t QME_RCSCR_OFF_REQ_LEN = 4;
static const uint32_t QME_RCSCR_CHANGE_DONE = 4;
static const uint32_t QME_RCSCR_CHANGE_DONE_LEN = 4;
static const uint32_t QME_RCSCR_CHANGE_ACTIVE = 8;
static const uint32_t QME_RCSCR_CHANGE_ACTIVE_LEN = 4;
static const uint32_t QME_RCSCR_PARTIAL_GOOD = 12;
static const uint32_t QME_RCSCR_PARTIAL_GOOD_LEN = 4;
static const uint32_t QME_RCSCR_CHANGE_ERROR = 16;
static const uint32_t QME_RCSCR_CHANGE_ERROR_LEN = 4;
static const uint32_t QME_RCSCR_0_TARGET_INDEX = 35;
static const uint32_t QME_RCSCR_0_TARGET_INDEX_LEN = 5;
static const uint32_t QME_RCSCR_1_TARGET_INDEX = 43;
static const uint32_t QME_RCSCR_1_TARGET_INDEX_LEN = 5;
static const uint32_t QME_RCSCR_2_TARGET_INDEX = 51;
static const uint32_t QME_RCSCR_2_TARGET_INDEX_LEN = 5;
static const uint32_t QME_RCSCR_3_TARGET_INDEX = 59;
static const uint32_t QME_RCSCR_3_TARGET_INDEX_LEN = 5;
//<< [QME_RCSCR]
// eq/reg00004.H

//>> [XSTOP1]
static const uint64_t XSTOP1 = 0x2003000cull;

static const uint32_t XSTOP1_ENABLE = 0;
static const uint32_t XSTOP1_WAIT_SNOPA = 1;
static const uint32_t XSTOP1_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP1_WAIT_ALWAYS = 3;
static const uint32_t XSTOP1_REGION_PERV = 4;
static const uint32_t XSTOP1_REGION_UNIT1 = 5;
static const uint32_t XSTOP1_REGION_UNIT2 = 6;
static const uint32_t XSTOP1_REGION_UNIT3 = 7;
static const uint32_t XSTOP1_REGION_UNIT4 = 8;
static const uint32_t XSTOP1_REGION_UNIT5 = 9;
static const uint32_t XSTOP1_REGION_UNIT6 = 10;
static const uint32_t XSTOP1_REGION_UNIT7 = 11;
static const uint32_t XSTOP1_REGION_UNIT8 = 12;
static const uint32_t XSTOP1_REGION_UNIT9 = 13;
static const uint32_t XSTOP1_REGION_UNIT10 = 14;
static const uint32_t XSTOP1_REGION_UNIT11 = 15;
static const uint32_t XSTOP1_REGION_UNIT12 = 16;
static const uint32_t XSTOP1_REGION_UNIT13 = 17;
static const uint32_t XSTOP1_REGION_UNIT14 = 18;
static const uint32_t XSTOP1_WAIT_CYCLES = 48;
static const uint32_t XSTOP1_WAIT_CYCLES_LEN = 12;
//<< [XSTOP1]
// eq/reg00004.H

//>> [EPS_FIR_LOCAL_ACTION2]
static const uint64_t EPS_FIR_LOCAL_ACTION2 = 0x20040109ull;

static const uint32_t EPS_FIR_LOCAL_ACTION2_00 = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION2_01 = 1;
static const uint32_t EPS_FIR_LOCAL_ACTION2_02 = 2;
static const uint32_t EPS_FIR_LOCAL_ACTION2_03 = 3;
static const uint32_t EPS_FIR_LOCAL_ACTION2_04 = 4;
static const uint32_t EPS_FIR_LOCAL_ACTION2_05 = 5;
static const uint32_t EPS_FIR_LOCAL_ACTION2_06 = 6;
static const uint32_t EPS_FIR_LOCAL_ACTION2_07 = 7;
static const uint32_t EPS_FIR_LOCAL_ACTION2_08 = 8;
static const uint32_t EPS_FIR_LOCAL_ACTION2_09 = 9;
static const uint32_t EPS_FIR_LOCAL_ACTION2_10 = 10;
static const uint32_t EPS_FIR_LOCAL_ACTION2_11 = 11;
static const uint32_t EPS_FIR_LOCAL_ACTION2_12 = 12;
static const uint32_t EPS_FIR_LOCAL_ACTION2_13 = 13;
static const uint32_t EPS_FIR_LOCAL_ACTION2_14 = 14;
static const uint32_t EPS_FIR_LOCAL_ACTION2_15 = 15;
static const uint32_t EPS_FIR_LOCAL_ACTION2_16 = 16;
static const uint32_t EPS_FIR_LOCAL_ACTION2_17 = 17;
static const uint32_t EPS_FIR_LOCAL_ACTION2_18 = 18;
static const uint32_t EPS_FIR_LOCAL_ACTION2_19 = 19;
static const uint32_t EPS_FIR_LOCAL_ACTION2_20 = 20;
static const uint32_t EPS_FIR_LOCAL_ACTION2_21 = 21;
static const uint32_t EPS_FIR_LOCAL_ACTION2_22 = 22;
static const uint32_t EPS_FIR_LOCAL_ACTION2_23 = 23;
static const uint32_t EPS_FIR_LOCAL_ACTION2_24 = 24;
static const uint32_t EPS_FIR_LOCAL_ACTION2_25 = 25;
static const uint32_t EPS_FIR_LOCAL_ACTION2_26 = 26;
static const uint32_t EPS_FIR_LOCAL_ACTION2_27 = 27;
static const uint32_t EPS_FIR_LOCAL_ACTION2_28 = 28;
static const uint32_t EPS_FIR_LOCAL_ACTION2_29 = 29;
static const uint32_t EPS_FIR_LOCAL_ACTION2_30 = 30;
static const uint32_t EPS_FIR_LOCAL_ACTION2_31 = 31;
static const uint32_t EPS_FIR_LOCAL_ACTION2_32 = 32;
static const uint32_t EPS_FIR_LOCAL_ACTION2_33 = 33;
static const uint32_t EPS_FIR_LOCAL_ACTION2_34 = 34;
static const uint32_t EPS_FIR_LOCAL_ACTION2_35 = 35;
static const uint32_t EPS_FIR_LOCAL_ACTION2_36 = 36;
static const uint32_t EPS_FIR_LOCAL_ACTION2_37 = 37;
static const uint32_t EPS_FIR_LOCAL_ACTION2_38 = 38;
static const uint32_t EPS_FIR_LOCAL_ACTION2_39 = 39;
static const uint32_t EPS_FIR_LOCAL_ACTION2_40 = 40;
static const uint32_t EPS_FIR_LOCAL_ACTION2_41 = 41;
static const uint32_t EPS_FIR_LOCAL_ACTION2_42 = 42;
static const uint32_t EPS_FIR_LOCAL_ACTION2_43 = 43;
static const uint32_t EPS_FIR_LOCAL_ACTION2_44 = 44;
static const uint32_t EPS_FIR_LOCAL_ACTION2_45 = 45;
static const uint32_t EPS_FIR_LOCAL_ACTION2_46 = 46;
static const uint32_t EPS_FIR_LOCAL_ACTION2_47 = 47;
static const uint32_t EPS_FIR_LOCAL_ACTION2_48 = 48;
static const uint32_t EPS_FIR_LOCAL_ACTION2_49 = 49;
static const uint32_t EPS_FIR_LOCAL_ACTION2_50 = 50;
static const uint32_t EPS_FIR_LOCAL_ACTION2_51 = 51;
static const uint32_t EPS_FIR_LOCAL_ACTION2_52 = 52;
static const uint32_t EPS_FIR_LOCAL_ACTION2_53 = 53;
static const uint32_t EPS_FIR_LOCAL_ACTION2_54 = 54;
static const uint32_t EPS_FIR_LOCAL_ACTION2_55 = 55;
static const uint32_t EPS_FIR_LOCAL_ACTION2_56 = 56;
static const uint32_t EPS_FIR_LOCAL_ACTION2_57 = 57;
static const uint32_t EPS_FIR_LOCAL_ACTION2_58 = 58;
static const uint32_t EPS_FIR_LOCAL_ACTION2_59 = 59;
static const uint32_t EPS_FIR_LOCAL_ACTION2_60 = 60;
static const uint32_t EPS_FIR_LOCAL_ACTION2_61 = 61;
static const uint32_t EPS_FIR_LOCAL_ACTION2_62 = 62;
static const uint32_t EPS_FIR_LOCAL_ACTION2_63 = 63;
//<< [EPS_FIR_LOCAL_ACTION2]
// eq/reg00004.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00004.H"
#endif
#endif
