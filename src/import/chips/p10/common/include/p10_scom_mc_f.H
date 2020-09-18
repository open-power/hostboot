/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_f.H $         */
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

#ifndef __p10_scom_mc_f_H_
#define __p10_scom_mc_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
{
#endif


//>> [BIST]
static const uint64_t BIST = 0x0c03000bull;

static const uint32_t BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t BIST_REGION_PERV = 4;
static const uint32_t BIST_REGION_UNIT1 = 5;
static const uint32_t BIST_REGION_UNIT2 = 6;
static const uint32_t BIST_REGION_UNIT3 = 7;
static const uint32_t BIST_REGION_UNIT4 = 8;
static const uint32_t BIST_REGION_UNIT5 = 9;
static const uint32_t BIST_REGION_UNIT6 = 10;
static const uint32_t BIST_REGION_UNIT7 = 11;
static const uint32_t BIST_REGION_UNIT8 = 12;
static const uint32_t BIST_REGION_UNIT9 = 13;
static const uint32_t BIST_REGION_UNIT10 = 14;
static const uint32_t BIST_REGION_UNIT11 = 15;
static const uint32_t BIST_REGION_UNIT12 = 16;
static const uint32_t BIST_REGION_UNIT13 = 17;
static const uint32_t BIST_REGION_UNIT14 = 18;
static const uint32_t BIST_STROBE_WINDOW_EN = 48;
//<< [BIST]
// mc/reg00015.H

//>> [CPLT_CTRL5]
static const uint64_t CPLT_CTRL5_RW = 0x0c000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x0c000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x0c000015ull;

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
//<< [CPLT_CTRL5]
// mc/reg00015.H

//>> [EPS_THERM_WSUB_DTS_RESULT0]
static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x0c050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
//<< [EPS_THERM_WSUB_DTS_RESULT0]
// mc/reg00015.H

//>> [SCOMFIR_MCFGPM0A]
static const uint64_t SCOMFIR_MCFGPM0A = 0x0c010c21ull;

static const uint32_t SCOMFIR_MCFGPM0A_HOLE_VALID = 0;
static const uint32_t SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t SCOMFIR_MCFGPM0A_RESERVED_16_21 = 16;
static const uint32_t SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN = 6;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_VALID = 22;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN = 19;
//<< [SCOMFIR_MCFGPM0A]
// mc/reg00015.H

//>> [TIMEOUT_REG]
static const uint64_t TIMEOUT_REG = 0x0c0f0010ull;

static const uint32_t TIMEOUT_REG_INT_TIMEOUT = 0;
static const uint32_t TIMEOUT_REG_INT_TIMEOUT_LEN = 2;
//<< [TIMEOUT_REG]
// mc/reg00015.H

//>> [SCOMFIR_MCFGP1E]
static const uint64_t SCOMFIR_MCFGP1E = 0x0c010c17ull;

static const uint32_t SCOMFIR_MCFGP1E_VALID = 0;
static const uint32_t SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t SCOMFIR_MCFGP1E_LOWER_ADDRESS = 2;
static const uint32_t SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t SCOMFIR_MCFGP1E_UPPER_ADDRESS = 21;
static const uint32_t SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN = 19;
//<< [SCOMFIR_MCFGP1E]
// mc/reg00015.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mc/reg00015.H"
#endif
#endif
