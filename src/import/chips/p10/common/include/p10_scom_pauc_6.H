/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_6.H $       */
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

#ifndef __p10_scom_pauc_6_H_
#define __p10_scom_pauc_6_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


//>> [CPLT_CONF1]
static const uint64_t CPLT_CONF1_RW = 0x10000009ull;
static const uint64_t CPLT_CONF1_WO_CLEAR = 0x10000029ull;
static const uint64_t CPLT_CONF1_WO_OR = 0x10000019ull;

static const uint32_t CPLT_CONF1_0_IOVALID_DC = 0;
static const uint32_t CPLT_CONF1_1_IOVALID_DC = 1;
static const uint32_t CPLT_CONF1_2_IOVALID_DC = 2;
static const uint32_t CPLT_CONF1_3_IOVALID_DC = 3;
//<< [CPLT_CONF1]
// pauc/reg00006.H

//>> [CPLT_CTRL1]
static const uint64_t CPLT_CTRL1_RW = 0x10000001ull;
static const uint64_t CPLT_CTRL1_WO_CLEAR = 0x10000021ull;
static const uint64_t CPLT_CTRL1_WO_OR = 0x10000011ull;

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
// pauc/reg00006.H

//>> [LOCAL_XSTOP_MASK]
static const uint64_t LOCAL_XSTOP_MASK_RW = 0x10040043ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_CLEAR = 0x10040063ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_OR = 0x10040053ull;

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
// pauc/reg00006.H

//>> [PHY_PPE_WRAP_ARB_CSAR]
static const uint64_t PHY_PPE_WRAP_ARB_CSAR = 0x10012c0dull;

static const uint32_t PHY_PPE_WRAP_ARB_CSAR_CSAR_SRAM_ADDRESS = 15;
static const uint32_t PHY_PPE_WRAP_ARB_CSAR_CSAR_SRAM_ADDRESS_LEN = 14;
// ERROR Duplicate Dial         static const uint32_t PHY_PPE_WRAP_ARB_CSAR_CSAR_SRAM_ADDRESS = 16; // p10:20,
// ERROR Duplicate Dial         static const uint32_t PHY_PPE_WRAP_ARB_CSAR_CSAR_SRAM_ADDRESS_LEN = 13;
//<< [PHY_PPE_WRAP_ARB_CSAR]
// pauc/reg00006.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00006.H"
#endif
#endif
