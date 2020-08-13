/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_4.H $         */
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

#ifndef __p10_scom_mc_4_H_
#define __p10_scom_mc_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
{
#endif


//>> [CLOCK_STAT_ARY]
static const uint64_t CLOCK_STAT_ARY = 0x0c03000aull;

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
// mc/reg00004.H

//>> [OPCG_REG2]
static const uint64_t OPCG_REG2 = 0x0c030004ull;

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
// mc/reg00004.H

//>> [TRA0_TR0_TRACE_LO_DATA_REG]
static const uint64_t TRA0_TR0_TRACE_LO_DATA_REG = 0x0c010401ull;

static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
//<< [TRA0_TR0_TRACE_LO_DATA_REG]
// mc/reg00004.H

//>> [XSTOP1]
static const uint64_t XSTOP1 = 0x0c03000cull;

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
// mc/reg00004.H

//>> [EPS_FIR_LOCAL_ACTION2]
static const uint64_t EPS_FIR_LOCAL_ACTION2 = 0x0c040109ull;

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
// mc/reg00004.H

//>> [MBA_SCOMFIR_MISCFIRACT2]
static const uint64_t MBA_SCOMFIR_MISCFIRACT2 = 0x0c010f09ull;

static const uint32_t MBA_SCOMFIR_MISCFIRACT2_MISCFIRACT2_FIR_ACTION2 = 0;
static const uint32_t MBA_SCOMFIR_MISCFIRACT2_MISCFIRACT2_FIR_ACTION2_LEN = 12;
//<< [MBA_SCOMFIR_MISCFIRACT2]
// mc/reg00004.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mc/reg00004.H"
#endif
#endif
