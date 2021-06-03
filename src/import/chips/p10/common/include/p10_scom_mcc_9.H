/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_9.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_mcc_9_H_
#define __p10_scom_mcc_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [DSTL_DSTLFIRMASK]
static const uint64_t DSTL_DSTLFIRMASK_RW = 0x0c010d03ull;
static const uint64_t DSTL_DSTLFIRMASK_WO_AND = 0x0c010d04ull;
static const uint64_t DSTL_DSTLFIRMASK_WO_OR = 0x0c010d05ull;

static const uint32_t DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 39;
static const uint32_t P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0; // p10:20,
static const uint32_t P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 41;
//<< [DSTL_DSTLFIRMASK]
// mcc/reg00009.H

//>> [WRITE_WRTCFG]
static const uint64_t WRITE_WRTCFG = 0x0c010f48ull;

static const uint32_t WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS = 0;
static const uint32_t WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS = 1;
static const uint32_t WRITE_WRTCFG_RESERVED_2_8 = 2;
static const uint32_t WRITE_WRTCFG_RESERVED_2_8_LEN = 7;
static const uint32_t WRITE_WRTCFG_NEW_WRITE_64B_MODE = 9;
static const uint32_t WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE = 10;
static const uint32_t WRITE_WRTCFG_RESERVED_11 = 11;
static const uint32_t WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ = 12;
static const uint32_t WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ = 14;
static const uint32_t WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ = 16;
static const uint32_t WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ = 18;
static const uint32_t WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ = 20;
static const uint32_t WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ = 21;
static const uint32_t WRITE_WRTCFG_RESERVED_22_31 = 22;
static const uint32_t WRITE_WRTCFG_RESERVED_22_31_LEN = 10;
//<< [WRITE_WRTCFG]
// mcc/reg00009.H

//>> [ATCL_CL_CLSCOM_MCAMOC]
static const uint64_t ATCL_CL_CLSCOM_MCAMOC = 0x0c010c25ull;

static const uint32_t ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN = 0;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0 = 1;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1 = 2;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC = 3;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES = 4;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_LEN = 25;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT = 29;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO = 32;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47 = 33;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47_LEN = 15;
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCAMOC_SUBCH_FAIR_COUNT_P10D20 = 33; // p10:20,
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCAMOC_SUBCH_FAIR_COUNT_P10D20_LEN = 5;
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCAMOC_CMDLIST_DEBUG_SEL_P10D20 = 38; // p10:20,
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCAMOC_CMDLIST_DEBUG_SEL_P10D20_LEN = 10;
//<< [ATCL_CL_CLSCOM_MCAMOC]
// mcc/reg00009.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00009.H"
#endif
#endif
