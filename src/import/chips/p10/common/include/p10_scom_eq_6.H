/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_6.H $         */
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

#ifndef __p10_scom_eq_6_H_
#define __p10_scom_eq_6_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [CPLT_CONF1]
static const uint64_t CPLT_CONF1_RW = 0x20000009ull;
static const uint64_t CPLT_CONF1_WO_CLEAR = 0x20000029ull;
static const uint64_t CPLT_CONF1_WO_OR = 0x20000019ull;

static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_DC = 0;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_DC_LEN = 3;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC = 3;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC_LEN = 4;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC = 7;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC_LEN = 3;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC = 10;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC_LEN = 2;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC = 12;
static const uint32_t CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC = 13;
static const uint32_t CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC = 14;
static const uint32_t CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC = 15;
//<< [CPLT_CONF1]
// eq/reg00006.H

//>> [CPLT_CTRL1]
static const uint64_t CPLT_CTRL1_RW = 0x20000001ull;
static const uint64_t CPLT_CTRL1_WO_CLEAR = 0x20000021ull;
static const uint64_t CPLT_CTRL1_WO_OR = 0x20000011ull;

static const uint32_t CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t CPLT_CTRL1_REGION0_FENCE_DC = 4;
static const uint32_t CPLT_CTRL1_REGION1_FENCE_DC = 5;
static const uint32_t CPLT_CTRL1_REGION2_FENCE_DC = 6;
static const uint32_t CPLT_CTRL1_REGION3_FENCE_DC = 7;
static const uint32_t CPLT_CTRL1_REGION4_FENCE_DC = 8;
static const uint32_t CPLT_CTRL1_REGION5_FENCE_DC = 9;
static const uint32_t CPLT_CTRL1_REGION6_FENCE_DC = 10;
static const uint32_t CPLT_CTRL1_REGION7_FENCE_DC = 11;
static const uint32_t CPLT_CTRL1_REGION8_FENCE_DC = 12;
static const uint32_t CPLT_CTRL1_REGION9_FENCE_DC = 13;
static const uint32_t CPLT_CTRL1_REGION10_FENCE_DC = 14;
static const uint32_t CPLT_CTRL1_REGION11_FENCE_DC = 15;
static const uint32_t CPLT_CTRL1_REGION12_FENCE_DC = 16;
static const uint32_t CPLT_CTRL1_REGION13_FENCE_DC = 17;
static const uint32_t CPLT_CTRL1_REGION14_FENCE_DC = 18;
static const uint32_t CPLT_CTRL1_STG_ACT_EN_DC = 22;
//<< [CPLT_CTRL1]
// eq/reg00006.H

//>> [LOCAL_XSTOP_MASK]
static const uint64_t LOCAL_XSTOP_MASK_RW = 0x20040043ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_CLEAR = 0x20040063ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_OR = 0x20040053ull;

static const uint32_t LOCAL_XSTOP_MASK_01 = 1;
static const uint32_t LOCAL_XSTOP_MASK_02 = 2;
static const uint32_t LOCAL_XSTOP_MASK_03 = 3;
static const uint32_t LOCAL_XSTOP_MASK_04 = 4;
static const uint32_t LOCAL_XSTOP_MASK_05 = 5;
static const uint32_t LOCAL_XSTOP_MASK_06 = 6;
static const uint32_t LOCAL_XSTOP_MASK_07 = 7;
static const uint32_t LOCAL_XSTOP_MASK_08 = 8;
static const uint32_t LOCAL_XSTOP_MASK_09 = 9;
static const uint32_t LOCAL_XSTOP_MASK_10 = 10;
static const uint32_t LOCAL_XSTOP_MASK_11 = 11;
static const uint32_t LOCAL_XSTOP_MASK_12 = 12;
static const uint32_t LOCAL_XSTOP_MASK_13 = 13;
static const uint32_t LOCAL_XSTOP_MASK_14 = 14;
static const uint32_t LOCAL_XSTOP_MASK_15 = 15;
//<< [LOCAL_XSTOP_MASK]
// eq/reg00006.H

//>> [QME_PPEBAR]
static const uint64_t QME_PPEBAR = 0x200e0050ull;

static const uint32_t QME_PPEBAR_BASE = 8;
static const uint32_t QME_PPEBAR_BASE_LEN = 36;
static const uint32_t QME_PPEBAR_SIZE = 61;
static const uint32_t QME_PPEBAR_SIZE_LEN = 3;
//<< [QME_PPEBAR]
// eq/reg00006.H

//>> [QME_QHTMEM]
static const uint64_t QME_QHTMEM = 0x200e01a4ull;

static const uint32_t QME_QHTMEM_ALLOC = 0;
static const uint32_t QME_QHTMEM_SCOPE = 1;
static const uint32_t QME_QHTMEM_SCOPE_LEN = 3;
static const uint32_t QME_QHTMEM_PRIORITY = 4;
static const uint32_t QME_QHTMEM_SIZE_SMALL = 5; // p10:20,
static const uint32_t QME_QHTMEM_BASE = 8;
static const uint32_t QME_QHTMEM_BASE_LEN = 32;
static const uint32_t QME_QHTMEM_SIZE = 40;
static const uint32_t QME_QHTMEM_SIZE_LEN = 9;
//<< [QME_QHTMEM]
// eq/reg00006.H

//>> [QME_RCTAR2]
static const uint64_t QME_RCTAR2 = 0x200e0198ull;

static const uint32_t QME_RCTAR2_DATA = 0;
static const uint32_t QME_RCTAR2_DATA_LEN = 64;
//<< [QME_RCTAR2]
// eq/reg00006.H

//>> [QME_SCOM_PBTXTR3]
static const uint64_t QME_SCOM_PBTXTR3 = 0x200e0043ull;

static const uint32_t QME_SCOM_PBTXTR3_VALID = 0;
static const uint32_t QME_SCOM_PBTXTR3_VALID_LEN = 8;
static const uint32_t QME_SCOM_PBTXTR3_0 = 8;
static const uint32_t QME_SCOM_PBTXTR3_0_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_1 = 12;
static const uint32_t QME_SCOM_PBTXTR3_1_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_2 = 16;
static const uint32_t QME_SCOM_PBTXTR3_2_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_3 = 20;
static const uint32_t QME_SCOM_PBTXTR3_3_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_4 = 24;
static const uint32_t QME_SCOM_PBTXTR3_4_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_5 = 28;
static const uint32_t QME_SCOM_PBTXTR3_5_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_6 = 32;
static const uint32_t QME_SCOM_PBTXTR3_6_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_7 = 36;
static const uint32_t QME_SCOM_PBTXTR3_7_LEN = 4;
//<< [QME_SCOM_PBTXTR3]
// eq/reg00006.H

//>> [QME_SCOM_XIRAMEDR]
static const uint64_t QME_SCOM_XIRAMEDR = 0x200e0210ull;

static const uint32_t QME_SCOM_XIRAMEDR_IR = 0;
static const uint32_t QME_SCOM_XIRAMEDR_IR_LEN = 32;
static const uint32_t QME_SCOM_XIRAMEDR_EDR = 32;
static const uint32_t QME_SCOM_XIRAMEDR_EDR_LEN = 32;
//<< [QME_SCOM_XIRAMEDR]
// eq/reg00006.H

//>> [QME_SCOM_XIVDR2]
static const uint64_t QME_SCOM_XIVDR2 = 0x200e0284ull;

static const uint32_t QME_SCOM_XIVDR2_2 = 0;
static const uint32_t QME_SCOM_XIVDR2_2_LEN = 32;
static const uint32_t QME_SCOM_XIVDR2_3 = 32;
static const uint32_t QME_SCOM_XIVDR2_3_LEN = 32;
//<< [QME_SCOM_XIVDR2]
// eq/reg00006.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00006.H"
#endif
#endif
