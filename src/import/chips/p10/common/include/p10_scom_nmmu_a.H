/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_a.H $       */
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

#ifndef __p10_scom_nmmu_a_H_
#define __p10_scom_nmmu_a_H_


namespace scomt
{
namespace nmmu
{


static const uint64_t FIR1_REG_RW = 0x02010c40ull;
static const uint64_t FIR1_REG_WO_AND = 0x02010c41ull;
static const uint64_t FIR1_REG_WO_OR = 0x02010c42ull;

static const uint32_t FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET = 0;
static const uint32_t FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET = 1;
static const uint32_t FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET = 2;
static const uint32_t FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET = 3;
static const uint32_t FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET = 4;
static const uint32_t FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET = 5;
static const uint32_t FIR1_REG_FBC_XLAT_PROT_ERR_DET = 6;
static const uint32_t FIR1_REG_FBC_XLAT_TIMEOUT_DET = 7;
static const uint32_t FIR1_REG_SLB_DIR_PERR_DET = 8;
static const uint32_t FIR1_REG_SLB_CAC_PERR_DET = 9;
static const uint32_t FIR1_REG_SLB_LRU_PERR_DET = 10;
static const uint32_t FIR1_REG_SLB_MULTIHIT_DET = 11;
static const uint32_t FIR1_REG_TLB_DIR_PERR_DET = 12;
static const uint32_t FIR1_REG_TLB_CAC_PERR_DET = 13;
static const uint32_t FIR1_REG_TLB_LRU_PERR_DET = 14;
static const uint32_t FIR1_REG_TLB_MULTIHIT_DET = 15;
static const uint32_t FIR1_REG_TW_SEG_FAULT_DET = 16;
static const uint32_t FIR1_REG_TW_PG_FAULT_NOPTE_DET = 17;
static const uint32_t FIR1_REG_TW_PG_FAULT_BPCHK_DET = 18;
static const uint32_t FIR1_REG_TW_PG_FAULT_VPCHK_DET = 19;
static const uint32_t FIR1_REG_TW_PG_FAULT_SEID_DET = 20;
static const uint32_t FIR1_REG_TW_ADD_ERR_CR_RD_DET = 21;
static const uint32_t FIR1_REG_TW_PTE_UPD_FAIL_DET = 22;
static const uint32_t FIR1_REG_TW_ADD_ERR_CR_WR_DET = 23;
static const uint32_t FIR1_REG_TW_RDX_CFG_GUEST_DET = 24;
static const uint32_t FIR1_REG_TW_RDX_CFG_HOST_DET = 25;
static const uint32_t FIR1_REG_TW_INVALID_WIMG_DET = 26;
static const uint32_t FIR1_REG_TW_INV_RDX_QUAD_DET = 27;
static const uint32_t FIR1_REG_TW_FOREIGN_ADDR_DET = 28;
static const uint32_t FIR1_REG_TW_PREFETCH_ABT_DET = 29;
static const uint32_t FIR1_REG_TW_CXT_CAC_PERR_DET = 30;
static const uint32_t FIR1_REG_TW_RDX_PWC_PERR_DET = 31;
static const uint32_t FIR1_REG_TW_SM_CTL_ERR_DET = 32;
static const uint32_t FIR1_REG_CO_SM_CTL_ERR_DET = 33;
static const uint32_t FIR1_REG_CI_SM_CTL_ERR_DET = 34;
static const uint32_t FIR1_REG_INV_SM_CTL_ERR_DET = 35;
static const uint32_t FIR1_REG_TW_TIMEOUT_ERR_DET = 36;
static const uint32_t FIR1_REG_CO_TIMEOUT_ERR_DET = 37;
static const uint32_t FIR1_REG_CI_TIMEOUT_ERR_DET = 38;
static const uint32_t FIR1_REG_INV_TIMEOUT_ERR_DET = 39;
static const uint32_t FIR1_REG_NX0_LXSTOP_ERR_DET = 40;
static const uint32_t FIR1_REG_CP0_LXSTOP_ERR_DET = 41;
static const uint32_t FIR1_REG_CP1_LXSTOP_ERR_DET = 42;
static const uint32_t FIR1_REG_NPU_LXSTOP_ERR_DET = 43;
static const uint32_t FIR1_REG_FBC_LXSTOP_ERR_DET = 44;
static const uint32_t FIR1_REG_SPARE = 45;
// nmmu/reg00010.H

static const uint64_t NMMU_ERR_LOG = 0x02010c57ull;

static const uint32_t NMMU_ERR_LOG_EN = 2;
static const uint32_t NMMU_ERR_LOG_SNGL_SHOT_EN = 3;
static const uint32_t NMMU_ERR_LOG_OVERLAP_EN = 4;
static const uint32_t NMMU_ERR_LOG_MULT_SEL = 5;
static const uint32_t NMMU_ERR_LOG_MULT_SEL_LEN = 3;
// nmmu/reg00010.H

}
}
#ifndef __PPE_HCODE__
    #include "nmmu/reg00010.H"
#endif
#endif
