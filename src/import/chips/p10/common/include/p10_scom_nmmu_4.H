/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_4.H $       */
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

#ifndef __p10_scom_nmmu_4_H_
#define __p10_scom_nmmu_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


static const uint64_t CFG_NMMU_CTL_SM = 0x02010c52ull;

static const uint32_t CFG_NMMU_CTL_SM_SM_TWSM_DIS = 0;
static const uint32_t CFG_NMMU_CTL_SM_SM_TWSM_DIS_LEN = 12;
static const uint32_t CFG_NMMU_CTL_SM_SM_CKINSM_DIS = 12;
static const uint32_t CFG_NMMU_CTL_SM_SM_CKINSM_DIS_LEN = 8;
static const uint32_t CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN = 20;
static const uint32_t CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS = 21;
static const uint32_t CFG_NMMU_CTL_SM_SM_ISS487_EN = 24;
static const uint32_t CFG_NMMU_CTL_SM_SM_ISS526_EN = 26;
static const uint32_t CFG_NMMU_CTL_SM_TW_MPSS_DIS = 31;
static const uint32_t CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH = 32;
static const uint32_t CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH_LEN = 8;
static const uint32_t CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS = 40;
static const uint32_t CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS = 41;
static const uint32_t CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS = 42;
static const uint32_t CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS = 43;
static const uint32_t CFG_NMMU_CTL_SM_TW_LCO_RDX_EN = 44;
static const uint32_t CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC = 45;
static const uint32_t CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF = 46;
static const uint32_t CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN = 51;
static const uint32_t CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS = 52;
static const uint32_t CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS = 53;
static const uint32_t CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS = 54;
static const uint32_t CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN = 55;
static const uint32_t CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH = 56;
static const uint32_t CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_OVERLAP_EN = 57;
static const uint32_t CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN = 58;
static const uint32_t CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN = 59;
// nmmu/reg00004.H

static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG = 0x02010c16ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG_LEN = 32;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN = 32;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN_LEN = 6;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK = 38;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK_LEN = 3;
// nmmu/reg00004.H

#ifndef __PPE_HCODE__
}
}
#include "nmmu/reg00004.H"
#endif
#endif
