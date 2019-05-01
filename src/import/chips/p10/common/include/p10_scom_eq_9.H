/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_9.H $         */
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

#ifndef __p10_scom_eq_9_H_
#define __p10_scom_eq_9_H_


namespace scomt
{
namespace eq
{


static const uint64_t CPLT_CTRL4_RW = 0x20000004ull;
static const uint64_t CPLT_CTRL4_WO_CLEAR = 0x20000024ull;
static const uint64_t CPLT_CTRL4_WO_OR = 0x20000014ull;

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
// eq/reg00009.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x20050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// eq/reg00009.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA2 = 0x2005001bull;
// eq/reg00009.H

static const uint64_t EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x20050014ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// eq/reg00009.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_FORCE_REG = 0x20050034ull;

static const uint32_t EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// eq/reg00009.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR0_CONFIG_0 = 0x20018203ull;

static const uint32_t L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// eq/reg00009.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR1_CONFIG_9 = 0x20018229ull;

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
// eq/reg00009.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR1_CONFIG_1 = 0x200182a4ull;

static const uint32_t L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// eq/reg00009.H

static const uint64_t MULTICAST_GROUP_2 = 0x200f0002ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// eq/reg00009.H

static const uint64_t QME_DB2 = 0x200e0108ull;

static const uint32_t QME_DB2_QME_DB2_MESSAGE_NUMBER = 0;
static const uint32_t QME_DB2_QME_DB2_MESSAGE_NUMBER_LEN = 8;
// eq/reg00009.H

static const uint64_t QME_PSSUM = 0x200e0134ull;

static const uint32_t QME_PSSUM_CORE_PARTIAL_GOOD = 48;
static const uint32_t QME_PSSUM_CORE_PARTIAL_GOOD_LEN = 4;
static const uint32_t QME_PSSUM_AUTO_PMCR_UPDATE = 52;
static const uint32_t QME_PSSUM_PMCR_RECENT_MODE = 53;
// eq/reg00009.H

}
}
#include "eq/reg00009.H"
#endif
