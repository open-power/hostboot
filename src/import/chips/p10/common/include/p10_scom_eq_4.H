/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_4.H $         */
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

#ifndef __p10_scom_eq_4_H_
#define __p10_scom_eq_4_H_


namespace scomt
{
namespace eq
{


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
// eq/reg00004.H

static const uint64_t EPS_THERM_WSUB_INJECT_REG = 0x20050011ull;

static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP = 0;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP_LEN = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE_LEN = 2;
// eq/reg00004.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG = 0x20050036ull;

static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// eq/reg00004.H

static const uint64_t L3TRA0_TR1_CONFIG_4 = 0x20018227ull;

static const uint32_t L3TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t L3TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t L3TRA0_TR1_CONFIG_4_B_LEN = 24;
// eq/reg00004.H

static const uint64_t L3TRA1_TR0_CONFIG_2 = 0x20018245ull;

static const uint32_t L3TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t L3TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t L3TRA1_TR0_CONFIG_2_B_LEN = 24;
// eq/reg00004.H

static const uint64_t L3TRA2_TR0_CONFIG_5 = 0x20018288ull;

static const uint32_t L3TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t L3TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t L3TRA2_TR0_CONFIG_5_D_LEN = 24;
// eq/reg00004.H

static const uint64_t L3TRA3_TR1_CONFIG_3 = 0x200182e6ull;

static const uint32_t L3TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t L3TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t L3TRA3_TR1_CONFIG_3_D_LEN = 24;
// eq/reg00004.H

static const uint64_t OPCG_REG2 = 0x20030004ull;

static const uint32_t OPCG_REG2_OPCG_GO2 = 0;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING = 1;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING_LEN = 3;
static const uint32_t OPCG_REG2_PRPG_VALUE = 4;
static const uint32_t OPCG_REG2_PRPG_VALUE_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_A_VAL = 16;
static const uint32_t OPCG_REG2_PRPG_A_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_B_VAL = 28;
static const uint32_t OPCG_REG2_PRPG_B_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_MODE = 40;
static const uint32_t OPCG_REG2_SM_LBIST_CNTRL = 48;
static const uint32_t OPCG_REG2_SM_LBIST_CNTRL_LEN = 16;
// eq/reg00004.H

static const uint64_t PCB_OPCG_GO = 0x20030020ull;

static const uint32_t PCB_OPCG_GO_PCB_OPCGGO = 0;
// eq/reg00004.H

static const uint64_t QME_EISTR = 0x200e0270ull;
// eq/reg00004.H

static const uint64_t QME_LFIRACT0 = 0x200e0008ull;

static const uint32_t QME_LFIRACT0_QME_LFIRACT0_FIR_ACTION1 = 0;
static const uint32_t QME_LFIRACT0_QME_LFIRACT0_FIR_ACTION1_LEN = 27;
// eq/reg00004.H

static const uint64_t QME_PLSR = 0x200e0148ull;
// eq/reg00004.H

static const uint64_t QME_QHB = 0x200e0080ull;

static const uint32_t QME_QHB_COUNT = 0;
static const uint32_t QME_QHB_COUNT_LEN = 16;
static const uint32_t QME_QHB_ENABLE = 16;
static const uint32_t QME_QHB_LOSS_THROTTLE_ENABLE = 17;
// eq/reg00004.H

static const uint64_t QME_RCSCR_SCOM = 0x200e0184ull;
static const uint64_t QME_RCSCR_SCOM1 = 0x200e0187ull;
static const uint64_t QME_RCSCR_SCOM2 = 0x200e0186ull;

static const uint32_t QME_RCSCR__OFF_REQ = 0;
static const uint32_t QME_RCSCR__OFF_REQ_LEN = 4;
static const uint32_t QME_RCSCR__CHANGE_DONE = 4;
static const uint32_t QME_RCSCR__CHANGE_DONE_LEN = 4;
static const uint32_t QME_RCSCR__CHANGE_ACTIVE = 8;
static const uint32_t QME_RCSCR__CHANGE_ACTIVE_LEN = 4;
static const uint32_t QME_RCSCR__PARTIAL_GOOD = 12;
static const uint32_t QME_RCSCR__PARTIAL_GOOD_LEN = 4;
static const uint32_t QME_RCSCR__CHANGE_ERROR = 16;
static const uint32_t QME_RCSCR__CHANGE_ERROR_LEN = 4;
static const uint32_t QME_RCSCR_0_TARGET_INDEX = 35;
static const uint32_t QME_RCSCR_0_TARGET_INDEX_LEN = 5;
static const uint32_t QME_RCSCR_1_TARGET_INDEX = 43;
static const uint32_t QME_RCSCR_1_TARGET_INDEX_LEN = 5;
static const uint32_t QME_RCSCR_2_TARGET_INDEX = 51;
static const uint32_t QME_RCSCR_2_TARGET_INDEX_LEN = 5;
static const uint32_t QME_RCSCR_3_TARGET_INDEX = 59;
static const uint32_t QME_RCSCR_3_TARGET_INDEX_LEN = 5;
// eq/reg00004.H

static const uint64_t QME_RS4BAR = 0x200e0160ull;

static const uint32_t QME_RS4BAR_QME_RS4BAR_BASE = 0;
static const uint32_t QME_RS4BAR_QME_RS4BAR_BASE_LEN = 32;
// eq/reg00004.H

static const uint64_t QME_RS4DBGD = 0x200e0158ull;

static const uint32_t QME_RS4DBGD_QME_RS4DBGD_SCAN_DATA_IN = 0;
static const uint32_t QME_RS4DBGD_QME_RS4DBGD_SCAN_DATA_IN_LEN = 64;
// eq/reg00004.H

static const uint64_t XSTOP1 = 0x2003000cull;

static const uint32_t XSTOP1_XSTOP1_MASK_B = 0;
static const uint32_t XSTOP1_ALIGNED_XSTOP1 = 1;
static const uint32_t XSTOP1_TRIGGER_OPCG_ON_XSTOP1 = 2;
static const uint32_t XSTOP1_XSTOP1_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP1_XSTOP1_PERV = 4;
static const uint32_t XSTOP1_XSTOP1_UNIT1 = 5;
static const uint32_t XSTOP1_XSTOP1_UNIT2 = 6;
static const uint32_t XSTOP1_XSTOP1_UNIT3 = 7;
static const uint32_t XSTOP1_XSTOP1_UNIT4 = 8;
static const uint32_t XSTOP1_XSTOP1_UNIT5 = 9;
static const uint32_t XSTOP1_XSTOP1_UNIT6 = 10;
static const uint32_t XSTOP1_XSTOP1_UNIT7 = 11;
static const uint32_t XSTOP1_XSTOP1_UNIT8 = 12;
static const uint32_t XSTOP1_XSTOP1_UNIT9 = 13;
static const uint32_t XSTOP1_XSTOP1_UNIT10 = 14;
static const uint32_t XSTOP1_XSTOP1_UNIT11 = 15;
static const uint32_t XSTOP1_XSTOP1_UNIT12 = 16;
static const uint32_t XSTOP1_XSTOP1_UNIT13 = 17;
static const uint32_t XSTOP1_XSTOP1_UNIT14 = 18;
static const uint32_t XSTOP1_XSTOP1_WAIT_CYCLES = 48;
static const uint32_t XSTOP1_XSTOP1_WAIT_CYCLES_LEN = 12;
// eq/reg00004.H

}
}
#include "eq/reg00004.H"
#endif
