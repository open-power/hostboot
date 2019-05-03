/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_7.H $       */
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

#include "proc_scomt.H"

#ifndef __p10_scom_nmmu_7_H_
#define __p10_scom_nmmu_7_H_


namespace scomt
{
namespace nmmu
{


static const uint64_t CFG_NMMU_CTL_SLB = 0x02010c54ull;

static const uint32_t CFG_NMMU_CTL_SLB_MBR_DIS = 0;
static const uint32_t CFG_NMMU_CTL_SLB_MBR_DIS_LEN = 16;
static const uint32_t CFG_NMMU_CTL_SLB_SNGL_THD_EN = 16;
static const uint32_t CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS = 17;
static const uint32_t CFG_NMMU_CTL_SLB_DMAP_MODE_EN = 18;
static const uint32_t CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS = 19;
static const uint32_t CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS = 20;
static const uint32_t CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS = 21;
static const uint32_t CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS = 22;
static const uint32_t CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS = 23;
static const uint32_t CFG_NMMU_CTL_SLB_ISS505_FIX_DIS = 24;
static const uint32_t CFG_NMMU_CTL_SLB_ISS510_FIX_DIS = 25;
static const uint32_t CFG_NMMU_CTL_SLB_ISS511_FIX_DIS = 26;
static const uint32_t CFG_NMMU_CTL_SLB_ISS544_FIX_DIS = 27;
static const uint32_t CFG_NMMU_CTL_SLB_ISS554_FIX_DIS = 28;
static const uint32_t CFG_NMMU_CTL_SLB_ISS560_FIX_DIS = 29;
static const uint32_t CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS = 30;
static const uint32_t CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL = 32;
static const uint32_t CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL_LEN = 4;
static const uint32_t CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL = 36;
static const uint32_t CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL_LEN = 4;
static const uint32_t CFG_NMMU_CTL_SLB_ISS542_FIX_DIS = 52;
static const uint32_t CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA = 57;
static const uint32_t CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA = 58;
static const uint32_t CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA = 59;
// nmmu/reg00007.H

static const uint64_t CFG_NMMU_XLAT_CTL_REG2 = 0x02010c4cull;

static const uint32_t CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR = 0;
static const uint32_t CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR_LEN = 64;
// nmmu/reg00007.H

static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG = 0x02010c06ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN = 20;
// nmmu/reg00007.H

static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG = 0x02010c07ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN = 20;
// nmmu/reg00007.H

}
}
#include "nmmu/reg00007.H"
#endif
