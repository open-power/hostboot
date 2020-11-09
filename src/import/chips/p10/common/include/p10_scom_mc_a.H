/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_a.H $         */
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

#ifndef __p10_scom_mc_a_H_
#define __p10_scom_mc_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
{
#endif


//>> [CLOCK_STAT_SL]
static const uint64_t CLOCK_STAT_SL = 0x0c030008ull;

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
//<< [CLOCK_STAT_SL]
// mc/reg00010.H

//>> [CPLT_CTRL3]
static const uint64_t CPLT_CTRL3_RW = 0x0c000003ull;
static const uint64_t CPLT_CTRL3_WO_CLEAR = 0x0c000023ull;
static const uint64_t CPLT_CTRL3_WO_OR = 0x0c000013ull;

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
//<< [CPLT_CTRL3]
// mc/reg00010.H

//>> [SCOMFIR_MCFIR]
static const uint64_t SCOMFIR_MCFIR_RW = 0x0c010c00ull;
static const uint64_t SCOMFIR_MCFIR_WO_AND = 0x0c010c01ull;
static const uint64_t SCOMFIR_MCFIR_WO_OR = 0x0c010c02ull;

static const uint32_t SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR = 0;
static const uint32_t SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR = 1;
static const uint32_t SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR = 2;
static const uint32_t SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE = 3;
static const uint32_t SCOMFIR_MCFIR_MULTIPLE_BAR_HIT = 4;
static const uint32_t SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 = 5;
static const uint32_t P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG = 5; // p10:20,
static const uint32_t SCOMFIR_MCFIR_RESERVED_6 = 6;
static const uint32_t SCOMFIR_MCFIR_RESERVED_7 = 7;
static const uint32_t SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT = 8;
static const uint32_t SCOMFIR_MCFIR_RESERVED_9 = 9;
static const uint32_t SCOMFIR_MCFIR_RESERVED_10 = 10;
static const uint32_t SCOMFIR_MCFIR_MCS_WAT0 = 11;
static const uint32_t SCOMFIR_MCFIR_MCS_WAT1 = 12;
static const uint32_t SCOMFIR_MCFIR_MCS_WAT2 = 13;
static const uint32_t SCOMFIR_MCFIR_MCS_WAT3 = 14;
static const uint32_t SCOMFIR_MCFIR_POP_RCMD_NOHIT = 15;
static const uint32_t SCOMFIR_MCFIR_POP_RCMD_BADHIT = 16;
static const uint32_t SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR = 17;
static const uint32_t SCOMFIR_MCFIR_RESERVED_18 = 18;
static const uint32_t P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT = 18; // p10:20,
static const uint32_t SCOMFIR_MCFIR_RESERVED_19 = 19;
static const uint32_t P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT = 19; // p10:20,
static const uint32_t SCOMFIR_MCFIR_MULTIPLE_TID_ERROR = 20;
static const uint32_t SCOMFIR_MCFIR_RESERVED_21 = 21;
static const uint32_t SCOMFIR_MCFIR_INVALID_SMF_ACCESS = 22;
static const uint32_t SCOMFIR_MCFIR_SYNC_ERROR = 23;
//<< [SCOMFIR_MCFIR]
// mc/reg00010.H

//>> [SCOMFIR_MCFIRACT1]
static const uint64_t SCOMFIR_MCFIRACT1 = 0x0c010c07ull;

static const uint32_t SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1 = 0;
static const uint32_t SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1_LEN = 24;
//<< [SCOMFIR_MCFIRACT1]
// mc/reg00010.H

//>> [SCOMFIR_MCMODE1]
static const uint64_t SCOMFIR_MCMODE1 = 0x0c010c12ull;

static const uint32_t SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY = 0;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN = 8;
static const uint32_t SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT = 8;
static const uint32_t SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT = 9;
static const uint32_t SCOMFIR_MCMODE1_RESERVED_10 = 10;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS = 11;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN = 6;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS = 17;
static const uint32_t SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY = 18;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE = 19;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN = 9;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH = 28;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN = 4;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS = 32;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_SPEC_OP = 33;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN = 19;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_CI = 52;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_CI_LEN = 2;
static const uint32_t P10_20_SCOMFIR_MCMODE1_RESERVED_52_53 = 52; // p10:20,
static const uint32_t P10_20_SCOMFIR_MCMODE1_RESERVED_52_53_LEN = 2;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS = 54;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN = 6;
static const uint32_t SCOMFIR_MCMODE1_RESERVED_60 = 60;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS = 61;
static const uint32_t SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW = 62;
static const uint32_t SCOMFIR_MCMODE1_RESERVED_63 = 63;
//<< [SCOMFIR_MCMODE1]
// mc/reg00010.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mc/reg00010.H"
#endif
#endif
