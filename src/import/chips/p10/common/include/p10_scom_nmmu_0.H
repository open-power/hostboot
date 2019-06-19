/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_0.H $       */
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

#ifndef __p10_scom_nmmu_0_H_
#define __p10_scom_nmmu_0_H_


namespace scomt
{
namespace nmmu
{


static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG = 0x02010c15ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP = 1;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN = 3;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN = 4;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP = 5;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS = 6;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN = 7;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG = 30;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES = 31;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE = 33;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G = 34;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED = 35;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE = 37;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL = 38;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE = 39;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK = 40;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK_LEN = 8;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK = 48;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK_LEN = 8;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK = 56;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK_LEN = 7;
// nmmu/reg00000.H

static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG = 0x02010c28ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE = 4;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE_LEN = 4;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE = 8;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE_LEN = 4;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE = 12;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE_LEN = 4;
// nmmu/reg00000.H

static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG = 0x02010c11ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE = 4;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY = 5;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY_LEN = 4;
// nmmu/reg00000.H

static const uint64_t NMMU_PMU1_CNT_REG = 0x02010c50ull;

static const uint32_t NMMU_PMU1_CNT_REG_MM_PMU1_CNT = 0;
static const uint32_t NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN = 64;
// nmmu/reg00000.H

}
}
#ifndef __PPE_HCODE__
    #include "nmmu/reg00000.H"
#endif
#endif
