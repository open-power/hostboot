/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_f.H $       */
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

#ifndef __p10_scom_perv_f_H_
#define __p10_scom_perv_f_H_


namespace scomt
{
namespace perv
{


static const uint64_t BIST = 0x0003000bull;

static const uint32_t BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t BIST_BIST_PERV = 4;
static const uint32_t BIST_BIST_UNIT1 = 5;
static const uint32_t BIST_BIST_UNIT2 = 6;
static const uint32_t BIST_BIST_UNIT3 = 7;
static const uint32_t BIST_BIST_UNIT4 = 8;
static const uint32_t BIST_BIST_UNIT5 = 9;
static const uint32_t BIST_BIST_UNIT6 = 10;
static const uint32_t BIST_BIST_UNIT7 = 11;
static const uint32_t BIST_BIST_UNIT8 = 12;
static const uint32_t BIST_BIST_UNIT9 = 13;
static const uint32_t BIST_BIST_UNIT10 = 14;
static const uint32_t BIST_BIST_UNIT11 = 15;
static const uint32_t BIST_BIST_UNIT12 = 16;
static const uint32_t BIST_BIST_UNIT13 = 17;
static const uint32_t BIST_BIST_UNIT14 = 18;
static const uint32_t BIST_BIST_STROBE_WINDOW_EN = 48;
// perv/reg00227.H

static const uint64_t CPLT_CTRL5_RW = 0x00000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x00000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x00000015ull;

static const uint32_t CPLT_CTRL5_0 = 0;
static const uint32_t CPLT_CTRL5_1 = 1;
static const uint32_t CPLT_CTRL5_2 = 2;
static const uint32_t CPLT_CTRL5_3 = 3;
static const uint32_t CPLT_CTRL5_4 = 4;
static const uint32_t CPLT_CTRL5_5 = 5;
static const uint32_t CPLT_CTRL5_6 = 6;
static const uint32_t CPLT_CTRL5_7 = 7;
static const uint32_t CPLT_CTRL5_8 = 8;
static const uint32_t CPLT_CTRL5_9 = 9;
static const uint32_t CPLT_CTRL5_10 = 10;
static const uint32_t CPLT_CTRL5_11 = 11;
static const uint32_t CPLT_CTRL5_12 = 12;
static const uint32_t CPLT_CTRL5_13 = 13;
static const uint32_t CPLT_CTRL5_14 = 14;
static const uint32_t CPLT_CTRL5_15 = 15;
static const uint32_t CPLT_CTRL5_16 = 16;
static const uint32_t CPLT_CTRL5_17 = 17;
static const uint32_t CPLT_CTRL5_18 = 18;
static const uint32_t CPLT_CTRL5_19 = 19;
// perv/reg00227.H

static const uint64_t DPLL_CNTL_NEST_REGS_ECHAR = 0x00000158ull;

static const uint32_t DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA = 1;
static const uint32_t DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA_LEN = 3;
static const uint32_t DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA = 5;
static const uint32_t DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA_LEN = 3;
static const uint32_t DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA = 9;
static const uint32_t DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA_LEN = 3;
static const uint32_t DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT = 61;
static const uint32_t DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT_LEN = 3;
// perv/reg00227.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x00050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
// perv/reg00227.H

static const uint64_t EPS_THERM_WSUB2_DTS_RESULT2 = 0x00050022ull;

static const uint32_t EPS_THERM_WSUB2_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// perv/reg00227.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR0_TRACE_LO_DATA_REG = 0x00018201ull;

static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00227.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR0_CONFIG_1 = 0x00018204ull;

static const uint32_t L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00227.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR0_CONFIG_9 = 0x00018289ull;

static const uint32_t L3TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00227.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR1_CONFIG_0 = 0x000182a3ull;

static const uint32_t L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00227.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR1_TRACE_HI_DATA_REG = 0x000182e0ull;

static const uint32_t L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00227.H

static const uint64_t MULTICAST_GROUP_3 = 0x000f0003ull;

static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP = 3;
static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN = 3;
// perv/reg00227.H

static const uint64_t PROTECT_MODE_REG = 0x000f03feull;

static const uint32_t PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// perv/reg00227.H

static const uint64_t TIMEOUT_REG = 0x000f0010ull;
// perv/reg00227.H

static const uint64_t TRA0_TR0_CONFIG_1 = 0x00010404ull;

static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00227.H

static const uint64_t TRA2_TR0_CONFIG_9 = 0x00010509ull;

static const uint32_t TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00227.H

static const uint64_t TRA2_TR1_CONFIG_0 = 0x00010543ull;

static const uint32_t TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00227.H

static const uint64_t TRA4_TR1_TRACE_LO_DATA_REG = 0x00010641ull;

static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00227.H

static const uint64_t TRA5_TR1_CONFIG_1 = 0x000106c4ull;

static const uint32_t TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00227.H

static const uint64_t TRA7_TR0_TRACE_HI_DATA_REG = 0x00010780ull;

static const uint32_t TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00227.H

static const uint64_t TRA7_TR0_CONFIG_0 = 0x00010783ull;

static const uint32_t TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00227.H

static const uint64_t VITAL_SCAN_OUT = 0x000f0017ull;
// perv/reg00227.H

}
}
#include "perv/reg00227.H"
#endif
