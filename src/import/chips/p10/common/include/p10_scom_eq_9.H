/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_9.H $         */
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

#ifndef __p10_scom_eq_9_H_
#define __p10_scom_eq_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [CPLT_CTRL4]
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
//<< [CPLT_CTRL4]
// eq/reg00009.H

//>> [EPS_THERM_WSUB_DTS_RESULT1]
static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x20050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
//<< [EPS_THERM_WSUB_DTS_RESULT1]
// eq/reg00009.H

//>> [QME_DB2]
static const uint64_t QME_DB2 = 0x200e0108ull;

static const uint32_t QME_DB2_MESSAGE_NUMBER = 0;
static const uint32_t QME_DB2_MESSAGE_NUMBER_LEN = 8;
//<< [QME_DB2]
// eq/reg00009.H

//>> [QME_PSSUM]
static const uint64_t QME_PSSUM = 0x200e0134ull;

static const uint32_t QME_PSSUM_PSTATE_REQ_C0 = 0;
static const uint32_t QME_PSSUM_PSTATE_REQ_C0_LEN = 8;
static const uint32_t QME_PSSUM_PSTATE_REQ_C1 = 8;
static const uint32_t QME_PSSUM_PSTATE_REQ_C1_LEN = 8;
static const uint32_t QME_PSSUM_PSTATE_REQ_C2 = 16;
static const uint32_t QME_PSSUM_PSTATE_REQ_C2_LEN = 8;
static const uint32_t QME_PSSUM_PSTATE_REQ_C3 = 24;
static const uint32_t QME_PSSUM_PSTATE_REQ_C3_LEN = 8;
static const uint32_t QME_PSSUM_PSTATE_REQ_QUAD = 32;
static const uint32_t QME_PSSUM_PSTATE_REQ_QUAD_LEN = 8;
static const uint32_t QME_PSSUM_RECENT_CORE_NUM = 42;
static const uint32_t QME_PSSUM_RECENT_CORE_NUM_LEN = 2;
static const uint32_t QME_PSSUM_QME_QMCR_CORE_PARTIAL_GOOD = 48;
static const uint32_t QME_PSSUM_QME_QMCR_CORE_PARTIAL_GOOD_LEN = 4;
static const uint32_t QME_PSSUM_QME_QMCR_AUTO_PMCR_UPDATE = 52;
static const uint32_t QME_PSSUM_QME_QMCR_PMCR_RECENT_MODE = 53;
static const uint32_t QME_PSSUM_PMCR_PIG_PENDING = 55;
//<< [QME_PSSUM]
// eq/reg00009.H

//>> [XSTOP]
static const uint64_t XSTOP = 0x20040000ull;

static const uint32_t XSTOP_ANY_XSTOP = 0;
static const uint32_t XSTOP_SYSTEM_XSTOP = 1;
static const uint32_t XSTOP_ANY_SPATTN = 2;
static const uint32_t XSTOP_DBG_FIR_XSTOP_ON_TRIG = 3;
static const uint32_t XSTOP_PERV = 4;
static const uint32_t XSTOP_IN05 = 5;
static const uint32_t XSTOP_IN06 = 6;
static const uint32_t XSTOP_IN07 = 7;
static const uint32_t XSTOP_IN08 = 8;
static const uint32_t XSTOP_IN09 = 9;
static const uint32_t XSTOP_IN10 = 10;
static const uint32_t XSTOP_IN11 = 11;
static const uint32_t XSTOP_IN12 = 12;
static const uint32_t XSTOP_IN13 = 13;
static const uint32_t XSTOP_IN14 = 14;
static const uint32_t XSTOP_IN15 = 15;
static const uint32_t XSTOP_IN16 = 16;
static const uint32_t XSTOP_IN17 = 17;
static const uint32_t XSTOP_IN18 = 18;
static const uint32_t XSTOP_IN19 = 19;
static const uint32_t XSTOP_IN20 = 20;
static const uint32_t XSTOP_IN21 = 21;
static const uint32_t XSTOP_IN22 = 22;
static const uint32_t XSTOP_IN23 = 23;
static const uint32_t XSTOP_IN24 = 24;
static const uint32_t XSTOP_IN25 = 25;
static const uint32_t XSTOP_IN26 = 26;
static const uint32_t XSTOP_IN27 = 27;
static const uint32_t XSTOP_IN28 = 28;
static const uint32_t XSTOP_IN29 = 29;
static const uint32_t XSTOP_IN30 = 30;
static const uint32_t XSTOP_IN31 = 31;
static const uint32_t XSTOP_IN32 = 32;
static const uint32_t XSTOP_IN33 = 33;
static const uint32_t XSTOP_IN34 = 34;
static const uint32_t XSTOP_IN35 = 35;
static const uint32_t XSTOP_IN36 = 36;
static const uint32_t XSTOP_IN37 = 37;
static const uint32_t XSTOP_IN38 = 38;
static const uint32_t XSTOP_IN39 = 39;
static const uint32_t XSTOP_IN40 = 40;
static const uint32_t XSTOP_IN41 = 41;
static const uint32_t XSTOP_IN42 = 42;
static const uint32_t XSTOP_IN43 = 43;
static const uint32_t XSTOP_IN44 = 44;
static const uint32_t XSTOP_IN45 = 45;
static const uint32_t XSTOP_IN46 = 46;
static const uint32_t XSTOP_IN47 = 47;
static const uint32_t XSTOP_IN48 = 48;
static const uint32_t XSTOP_IN49 = 49;
static const uint32_t XSTOP_IN50 = 50;
static const uint32_t XSTOP_IN51 = 51;
static const uint32_t XSTOP_IN52 = 52;
static const uint32_t XSTOP_IN53 = 53;
//<< [XSTOP]
// eq/reg00009.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00009.H"
#endif
#endif
