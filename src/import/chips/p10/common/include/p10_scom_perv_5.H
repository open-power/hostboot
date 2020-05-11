/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_5.H $       */
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

#ifndef __p10_scom_perv_5_H_
#define __p10_scom_perv_5_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [EPS_THERM_WSUB2_DTS_RESULT1]
static const uint64_t EPS_THERM_WSUB2_DTS_RESULT1 = 0x00050021ull;

static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT_LEN = 16;
//<< [EPS_THERM_WSUB2_DTS_RESULT1]
// perv/reg00010.H

//>> [NET_CTRL1]
static const uint64_t NET_CTRL1_RW = 0x000f0044ull;
static const uint64_t NET_CTRL1_RW_WAND = 0x000f0045ull;
static const uint64_t NET_CTRL1_RW_WOR = 0x000f0046ull;

static const uint32_t NET_CTRL1_CACHE0_CLK_DCC_BYPASS = 0;
static const uint32_t NET_CTRL1_CACHE1_CLK_DCC_BYPASS = 1;
static const uint32_t NET_CTRL1_CACHE2_CLK_DCC_BYPASS = 2;
static const uint32_t NET_CTRL1_CACHE3_CLK_DCC_BYPASS = 3;
static const uint32_t NET_CTRL1_CORE0_CLK_DCC_BYPASS = 4;
static const uint32_t NET_CTRL1_CORE1_CLK_DCC_BYPASS = 5;
static const uint32_t NET_CTRL1_CORE2_CLK_DCC_BYPASS = 6;
static const uint32_t NET_CTRL1_CORE3_CLK_DCC_BYPASS = 7;
static const uint32_t NET_CTRL1_CACHE0_CLK_PDLY_BYPASS = 8;
static const uint32_t NET_CTRL1_CACHE1_CLK_PDLY_BYPASS = 9;
static const uint32_t NET_CTRL1_CACHE2_CLK_PDLY_BYPASS = 10;
static const uint32_t NET_CTRL1_CACHE3_CLK_PDLY_BYPASS = 11;
static const uint32_t NET_CTRL1_CORE0_CLK_PDLY_BYPASS = 12;
static const uint32_t NET_CTRL1_CORE1_CLK_PDLY_BYPASS = 13;
static const uint32_t NET_CTRL1_CORE2_CLK_PDLY_BYPASS = 14;
static const uint32_t NET_CTRL1_CORE3_CLK_PDLY_BYPASS = 15;
static const uint32_t NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC = 16;
static const uint32_t NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC = 17;
static const uint32_t NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC = 18;
static const uint32_t NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC = 19;
static const uint32_t NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC = 20;
static const uint32_t NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC = 21;
static const uint32_t NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC = 22;
static const uint32_t NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC = 23;
static const uint32_t NET_CTRL1_PCB_ACCESS = 24;
static const uint32_t NET_CTRL1_PCB_ACCESS_LEN = 8;
//<< [NET_CTRL1]
// perv/reg00010.H

//>> [SCAN_LONG_ROTATE]
static const uint64_t SCAN_LONG_ROTATE = 0x00039000ull;
//<< [SCAN_LONG_ROTATE]
// perv/reg00010.H

//>> [TOD_START_REG]
static const uint64_t TOD_START_REG = 0x00040022ull;

static const uint32_t TOD_START_REG_FSM_START_TOD_TRIGGER = 0;
static const uint32_t TOD_START_REG_REG_0X22_SPARE_01 = 1;
static const uint32_t TOD_START_REG_FSM_START_TOD_DATA02 = 2;
static const uint32_t TOD_START_REG_REG_0X22_SPARE_03_07 = 3;
static const uint32_t TOD_START_REG_REG_0X22_SPARE_03_07_LEN = 5;
//<< [TOD_START_REG]
// perv/reg00010.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL7_COPY]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI = 0x00002917ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE = 0x00002c5cull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW = 0x00050117ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG_LEN = 32;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL7_COPY]
// perv/reg00010.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00010.H"
#include "perv/reg00011.H"
#endif
#endif
