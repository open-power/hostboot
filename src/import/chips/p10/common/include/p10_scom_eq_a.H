/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_a.H $         */
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

#ifndef __p10_scom_eq_a_H_
#define __p10_scom_eq_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [CLOCK_STAT_SL]
static const uint64_t CLOCK_STAT_SL = 0x20030008ull;

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
// eq/reg00010.H

//>> [CPLT_CTRL3]
static const uint64_t CPLT_CTRL3_RW = 0x20000003ull;
static const uint64_t CPLT_CTRL3_WO_CLEAR = 0x20000023ull;
static const uint64_t CPLT_CTRL3_WO_OR = 0x20000013ull;

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
// eq/reg00010.H

//>> [QME_BCEBAR0]
static const uint64_t QME_BCEBAR0 = 0x200e0060ull;

static const uint32_t QME_BCEBAR0_BASE = 8;
static const uint32_t QME_BCEBAR0_BASE_LEN = 36;
static const uint32_t QME_BCEBAR0_SIZE = 61;
static const uint32_t QME_BCEBAR0_SIZE_LEN = 3;
//<< [QME_BCEBAR0]
// eq/reg00010.H

//>> [QME_QSDR]
static const uint64_t QME_QSDR = 0x200e0078ull;

static const uint32_t QME_QSDR_SRAM_DATA = 0;
static const uint32_t QME_QSDR_SRAM_DATA_LEN = 64;
//<< [QME_QSDR]
// eq/reg00010.H

//>> [QME_RCTAR0]
static const uint64_t QME_RCTAR0 = 0x200e0190ull;

static const uint32_t QME_RCTAR0_DATA = 0;
static const uint32_t QME_RCTAR0_DATA_LEN = 64;
//<< [QME_RCTAR0]
// eq/reg00010.H

//>> [QME_SCOM_PBTXTR1]
static const uint64_t QME_SCOM_PBTXTR1 = 0x200e0041ull;

static const uint32_t QME_SCOM_PBTXTR1_VALID = 0;
static const uint32_t QME_SCOM_PBTXTR1_VALID_LEN = 8;
static const uint32_t QME_SCOM_PBTXTR1_0 = 8;
static const uint32_t QME_SCOM_PBTXTR1_0_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_1 = 12;
static const uint32_t QME_SCOM_PBTXTR1_1_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_2 = 16;
static const uint32_t QME_SCOM_PBTXTR1_2_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_3 = 20;
static const uint32_t QME_SCOM_PBTXTR1_3_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_4 = 24;
static const uint32_t QME_SCOM_PBTXTR1_4_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_5 = 28;
static const uint32_t QME_SCOM_PBTXTR1_5_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_6 = 32;
static const uint32_t QME_SCOM_PBTXTR1_6_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_7 = 36;
static const uint32_t QME_SCOM_PBTXTR1_7_LEN = 4;
//<< [QME_SCOM_PBTXTR1]
// eq/reg00010.H

//>> [QME_SCOM_XIVDR0]
static const uint64_t QME_SCOM_XIVDR0 = 0x200e0280ull;

static const uint32_t QME_SCOM_XIVDR0_0 = 0;
static const uint32_t QME_SCOM_XIVDR0_0_LEN = 32;
static const uint32_t QME_SCOM_XIVDR0_1 = 32;
static const uint32_t QME_SCOM_XIVDR0_1_LEN = 32;
//<< [QME_SCOM_XIVDR0]
// eq/reg00010.H

//>> [QME_TSEL]
static const uint64_t QME_TSEL = 0x200e0240ull;

static const uint32_t QME_TSEL_WATCHDOG_SEL = 0;
static const uint32_t QME_TSEL_WATCHDOG_SEL_LEN = 4;
static const uint32_t QME_TSEL_FIT_SEL = 4;
static const uint32_t QME_TSEL_FIT_SEL_LEN = 4;
//<< [QME_TSEL]
// eq/reg00010.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00010.H"
#endif
#endif
