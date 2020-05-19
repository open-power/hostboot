/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_f.H $        */
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

#ifndef __p10_scom_pec_f_H_
#define __p10_scom_pec_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> [BIST]
static const uint64_t BIST = 0x0803000bull;

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
// pec/reg00015.H

//>> [CPLT_CTRL5]
static const uint64_t CPLT_CTRL5_RW = 0x08000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x08000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x08000015ull;

static const uint32_t CPLT_CTRL5_TC_CCFG_PMA0_MUX_SEL_DC = 0;
static const uint32_t CPLT_CTRL5_TC_CCFG_PMA1_MUX_SEL_DC = 1;
static const uint32_t CPLT_CTRL5_TC_CCFG_PMA2_MUX_SEL_DC = 2;
static const uint32_t CPLT_CTRL5_TC_CCFG_PMA3_MUX_SEL_DC = 3;
static const uint32_t CPLT_CTRL5_TC_CCFG_PCS01_MUX_SEL_DC = 4;
static const uint32_t CPLT_CTRL5_TC_CCFG_PCS23_MUX_SEL_DC = 5;
static const uint32_t CPLT_CTRL5_TC_CCFG_PIPE_LANEX_EXT_PLL_MODE_DC = 6;
static const uint32_t CPLT_CTRL5_TC_CCFG_PHYX_CR_PARA_SEL_DC = 7;
static const uint32_t CPLT_CTRL5_TC_CCFG_PHY_EXT_CTRL_SEL_DC = 8;
static const uint32_t CPLT_CTRL5_09 = 9;
static const uint32_t CPLT_CTRL5_010 = 10;
static const uint32_t CPLT_CTRL5_011 = 11;
static const uint32_t CPLT_CTRL5_012 = 12;
static const uint32_t CPLT_CTRL5_013 = 13;
static const uint32_t CPLT_CTRL5_014 = 14;
static const uint32_t CPLT_CTRL5_015 = 15;
static const uint32_t CPLT_CTRL5_016 = 16;
static const uint32_t CPLT_CTRL5_017 = 17;
static const uint32_t CPLT_CTRL5_018 = 18;
static const uint32_t CPLT_CTRL5_019 = 19;
//<< [CPLT_CTRL5]
// pec/reg00015.H

//>> [EPS_THERM_WSUB_DTS_RESULT0]
static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x08050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
//<< [EPS_THERM_WSUB_DTS_RESULT0]
// pec/reg00015.H

//>> [TIMEOUT_REG]
static const uint64_t TIMEOUT_REG = 0x080f0010ull;

static const uint32_t TIMEOUT_REG_INT_TIMEOUT = 0;
static const uint32_t TIMEOUT_REG_INT_TIMEOUT_LEN = 2;
//<< [TIMEOUT_REG]
// pec/reg00015.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00015.H"
#endif
#endif
