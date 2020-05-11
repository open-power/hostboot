/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_f.H $         */
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

#ifndef __p10_scom_eq_f_H_
#define __p10_scom_eq_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [BIST]
static const uint64_t BIST = 0x2003000bull;

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
// eq/reg00015.H

//>> [CPLT_CTRL5]
static const uint64_t CPLT_CTRL5_RW = 0x20000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x20000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x20000015ull;

static const uint32_t CPLT_CTRL5_VITL_DFT_FENCE_DC = 3;
static const uint32_t CPLT_CTRL5_REGION0_DFT_FENCE_DC = 4;
static const uint32_t CPLT_CTRL5_REGION1_DFT_FENCE_DC = 5;
static const uint32_t CPLT_CTRL5_REGION2_DFT_FENCE_DC = 6;
static const uint32_t CPLT_CTRL5_REGION3_DFT_FENCE_DC = 7;
static const uint32_t CPLT_CTRL5_REGION4_DFT_FENCE_DC = 8;
static const uint32_t CPLT_CTRL5_REGION5_DFT_FENCE_DC = 9;
static const uint32_t CPLT_CTRL5_REGION6_DFT_FENCE_DC = 10;
static const uint32_t CPLT_CTRL5_REGION7_DFT_FENCE_DC = 11;
static const uint32_t CPLT_CTRL5_REGION8_DFT_FENCE_DC = 12;
static const uint32_t CPLT_CTRL5_REGION9_DFT_FENCE_DC = 13;
static const uint32_t CPLT_CTRL5_REGION10_DFT_FENCE_DC = 14;
static const uint32_t CPLT_CTRL5_REGION11_DFT_FENCE_DC = 15;
static const uint32_t CPLT_CTRL5_REGION12_DFT_FENCE_DC = 16;
static const uint32_t CPLT_CTRL5_REGION13_DFT_FENCE_DC = 17;
static const uint32_t CPLT_CTRL5_REGION14_DFT_FENCE_DC = 18;
//<< [CPLT_CTRL5]
// eq/reg00015.H

//>> [EPS_THERM_WSUB_DTS_RESULT0]
static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x20050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
//<< [EPS_THERM_WSUB_DTS_RESULT0]
// eq/reg00015.H

//>> [QME_QSAR]
static const uint64_t QME_QSAR = 0x200e0074ull;

static const uint32_t QME_QSAR_SRAM_ADDRESS = 16;
static const uint32_t QME_QSAR_SRAM_ADDRESS_LEN = 13;
static const uint32_t QME_QSAR_AUTO_INCR_MODE = 63;
//<< [QME_QSAR]
// eq/reg00015.H

//>> [QME_SCOM_XIVDR6]
static const uint64_t QME_SCOM_XIVDR6 = 0x200e028cull;

static const uint32_t QME_SCOM_XIVDR6_6 = 0;
static const uint32_t QME_SCOM_XIVDR6_6_LEN = 32;
static const uint32_t QME_SCOM_XIVDR6_7 = 32;
static const uint32_t QME_SCOM_XIVDR6_7_LEN = 32;
//<< [QME_SCOM_XIVDR6]
// eq/reg00015.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00015.H"
#endif
#endif
