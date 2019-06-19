/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_d.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __p10_scom_nmmu_d_H_
#define __p10_scom_nmmu_d_H_


namespace scomt
{
namespace nmmu
{


static const uint64_t CFG_NMMU_XLAT_CTL_REG1 = 0x02010c4bull;

static const uint32_t CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR = 0;
static const uint32_t CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR_LEN = 64;
// nmmu/reg00013.H

static const uint64_t FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1 = 0x02010c25ull;

static const uint32_t FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87 = 0;
static const uint32_t FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87_LEN = 24;
// nmmu/reg00013.H

static const uint64_t FIR1_ACTION0_REG = 0x02010c46ull;

static const uint32_t FIR1_ACTION0_REG_MM_FIR1_ACTION0 = 0;
static const uint32_t FIR1_ACTION0_REG_MM_FIR1_ACTION0_LEN = 46;
// nmmu/reg00013.H

static const uint64_t FIR1_ACTION1_REG = 0x02010c47ull;

static const uint32_t FIR1_ACTION1_REG_MM_FIR1_ACTION1 = 0;
static const uint32_t FIR1_ACTION1_REG_MM_FIR1_ACTION1_LEN = 46;
// nmmu/reg00013.H

static const uint64_t NMMU_ERR_INJ = 0x02010c58ull;

static const uint32_t NMMU_ERR_INJ_TLB_DIR_EN = 2;
static const uint32_t NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN = 3;
static const uint32_t NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN = 4;
static const uint32_t NMMU_ERR_INJ_TLB_DIR_MULT_SEL = 5;
static const uint32_t NMMU_ERR_INJ_TLB_DIR_MULT_SEL_LEN = 3;
static const uint32_t NMMU_ERR_INJ_TLB_CAC_EN = 8;
static const uint32_t NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN = 9;
static const uint32_t NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN = 10;
static const uint32_t NMMU_ERR_INJ_TLB_CAC_MULT_SEL = 11;
static const uint32_t NMMU_ERR_INJ_TLB_CAC_MULT_SEL_LEN = 3;
static const uint32_t NMMU_ERR_INJ_TLB_LRU_EN = 14;
static const uint32_t NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN = 15;
static const uint32_t NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN = 16;
static const uint32_t NMMU_ERR_INJ_TLB_LRU_MULT_SEL = 17;
static const uint32_t NMMU_ERR_INJ_TLB_LRU_MULT_SEL_LEN = 3;
static const uint32_t NMMU_ERR_INJ_PWC_DIR_EN = 20;
static const uint32_t NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN = 21;
static const uint32_t NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN = 22;
static const uint32_t NMMU_ERR_INJ_PWC_DIR_MULT_SEL = 23;
static const uint32_t NMMU_ERR_INJ_PWC_DIR_MULT_SEL_LEN = 3;
static const uint32_t NMMU_ERR_INJ_PWC_CAC_EN = 26;
static const uint32_t NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN = 27;
static const uint32_t NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN = 28;
static const uint32_t NMMU_ERR_INJ_PWC_CAC_MULT_SEL = 29;
static const uint32_t NMMU_ERR_INJ_PWC_CAC_MULT_SEL_LEN = 3;
static const uint32_t NMMU_ERR_INJ_SLB_DIR_EN = 34;
static const uint32_t NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN = 35;
static const uint32_t NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN = 36;
static const uint32_t NMMU_ERR_INJ_SLB_DIR_MULT_SEL = 37;
static const uint32_t NMMU_ERR_INJ_SLB_DIR_MULT_SEL_LEN = 3;
static const uint32_t NMMU_ERR_INJ_SLB_CAC_EN = 40;
static const uint32_t NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN = 41;
static const uint32_t NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN = 42;
static const uint32_t NMMU_ERR_INJ_SLB_CAC_MULT_SEL = 43;
static const uint32_t NMMU_ERR_INJ_SLB_CAC_MULT_SEL_LEN = 3;
static const uint32_t NMMU_ERR_INJ_SLB_LRU_EN = 46;
static const uint32_t NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN = 47;
static const uint32_t NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN = 48;
static const uint32_t NMMU_ERR_INJ_SLB_LRU_MULT_SEL = 49;
static const uint32_t NMMU_ERR_INJ_SLB_LRU_MULT_SEL_LEN = 3;
static const uint32_t NMMU_ERR_INJ_CXT_DIR_EN = 52;
static const uint32_t NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN = 53;
static const uint32_t NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN = 54;
static const uint32_t NMMU_ERR_INJ_CXT_DIR_MULT_SEL = 55;
static const uint32_t NMMU_ERR_INJ_CXT_DIR_MULT_SEL_LEN = 3;
static const uint32_t NMMU_ERR_INJ_CXT_CAC_EN = 58;
static const uint32_t NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN = 59;
static const uint32_t NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN = 60;
static const uint32_t NMMU_ERR_INJ_CXT_CAC_MULT_SEL = 61;
static const uint32_t NMMU_ERR_INJ_CXT_CAC_MULT_SEL_LEN = 3;
// nmmu/reg00013.H

static const uint64_t NMMU_PMU0_CTL_REG = 0x02010c4dull;

static const uint32_t NMMU_PMU0_CTL_REG_MM_PMU0_CTL = 0;
static const uint32_t NMMU_PMU0_CTL_REG_MM_PMU0_CTL_LEN = 64;
// nmmu/reg00013.H

}
}
#ifndef __PPE_HCODE__
    #include "nmmu/reg00013.H"
#endif
#endif
