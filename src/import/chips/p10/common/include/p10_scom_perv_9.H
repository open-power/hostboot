/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_9.H $       */
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

#ifndef __p10_scom_perv_9_H_
#define __p10_scom_perv_9_H_


namespace scomt
{
namespace perv
{


static const uint64_t CPLT_CTRL4_RW = 0x00000004ull;
static const uint64_t CPLT_CTRL4_WO_CLEAR = 0x00000024ull;
static const uint64_t CPLT_CTRL4_WO_OR = 0x00000014ull;

static const uint32_t CPLT_CTRL4_0_FLUSHMODE_INH = 4;
static const uint32_t CPLT_CTRL4_1_FLUSHMODE_INH = 5;
static const uint32_t CPLT_CTRL4_2_FLUSHMODE_INH = 6;
static const uint32_t CPLT_CTRL4_3_FLUSHMODE_INH = 7;
static const uint32_t CPLT_CTRL4_4_FLUSHMODE_INH = 8;
static const uint32_t CPLT_CTRL4_5_FLUSHMODE_INH = 9;
static const uint32_t CPLT_CTRL4_6_FLUSHMODE_INH = 10;
static const uint32_t CPLT_CTRL4_7_FLUSHMODE_INH = 11;
static const uint32_t CPLT_CTRL4_8_FLUSHMODE_INH = 12;
static const uint32_t CPLT_CTRL4_9_FLUSHMODE_INH = 13;
static const uint32_t CPLT_CTRL4_10_FLUSHMODE_INH = 14;
static const uint32_t CPLT_CTRL4_11_FLUSHMODE_INH = 15;
static const uint32_t CPLT_CTRL4_12_FLUSHMODE_INH = 16;
static const uint32_t CPLT_CTRL4_13_FLUSHMODE_INH = 17;
static const uint32_t CPLT_CTRL4_14_FLUSHMODE_INH = 18;
// perv/reg00221.H

static const uint64_t DPLL_CNTL_NEST_REGS_FREQ = 0x00000151ull;

static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_FMAX = 1;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_FMAX_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX = 12;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX_LEN = 4;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_FF_MAX_MULT_FRAC7 = 16;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_FMULT = 17;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_FMULT_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT = 28;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT_LEN = 4;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_MULT_FRAC7 = 32;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_FMIN = 33;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_FMIN_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN = 44;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN_LEN = 4;
static const uint32_t DPLL_CNTL_NEST_REGS_FREQ_FF_MIN_MULT_FRAC7 = 48;
// perv/reg00221.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x00050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// perv/reg00221.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA2 = 0x0005001bull;
// perv/reg00221.H

static const uint64_t EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x00050014ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// perv/reg00221.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_FORCE_REG = 0x00050034ull;

static const uint32_t EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// perv/reg00221.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR0_CONFIG_0 = 0x00018203ull;

static const uint32_t L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00221.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR1_CONFIG_9 = 0x00018229ull;

static const uint32_t L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00221.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR1_CONFIG_1 = 0x000182a4ull;

static const uint32_t L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00221.H

static const uint64_t MULTICAST_GROUP_2 = 0x000f0002ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// perv/reg00221.H

static const uint64_t TRA0_TR0_CONFIG_0 = 0x00010403ull;

static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00221.H

static const uint64_t TRA0_TR1_TRACE_HI_DATA_REG = 0x00010440ull;

static const uint32_t TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00221.H

static const uint64_t TRA0_TR1_CONFIG_9 = 0x00010449ull;

static const uint32_t TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00221.H

static const uint64_t TRA2_TR1_CONFIG_1 = 0x00010544ull;

static const uint32_t TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00221.H

static const uint64_t TRA3_TR0_TRACE_LO_DATA_REG = 0x00010581ull;

static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00221.H

static const uint64_t TRA5_TR0_CONFIG_9 = 0x00010689ull;

static const uint32_t TRA5_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA5_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA5_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA5_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA5_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA5_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00221.H

static const uint64_t TRA5_TR1_CONFIG_0 = 0x000106c3ull;

static const uint32_t TRA5_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA5_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00221.H

static const uint64_t TRA7_TR0_CONFIG_1 = 0x00010784ull;

static const uint32_t TRA7_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA7_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00221.H

}
}
#include "perv/reg00221.H"
#endif
