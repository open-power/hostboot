/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_2.H $       */
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

#ifndef __p10_scom_nmmu_2_H_
#define __p10_scom_nmmu_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


//>> [CFG_NMMU_CTL_TLB]
static const uint64_t CFG_NMMU_CTL_TLB = 0x02010c55ull;

static const uint32_t CFG_NMMU_CTL_TLB_MBR_DIS = 0;
static const uint32_t CFG_NMMU_CTL_TLB_MBR_DIS_LEN = 16;
static const uint32_t CFG_NMMU_CTL_TLB_SNGL_THD_EN = 16;
static const uint32_t CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS = 17;
static const uint32_t CFG_NMMU_CTL_TLB_DMAP_MODE_EN = 18;
static const uint32_t CFG_NMMU_CTL_TLB_MPSS_DIS = 19;
static const uint32_t CFG_NMMU_CTL_TLB_HASH_LPID_DIS = 20;
static const uint32_t CFG_NMMU_CTL_TLB_HASH_PID_DIS = 21;
static const uint32_t CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS = 22;
static const uint32_t CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS = 23;
static const uint32_t CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS = 24;
static const uint32_t CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS = 25;
static const uint32_t CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS = 26;
static const uint32_t CFG_NMMU_CTL_TLB_ISS426_FIX_DIS = 27;
static const uint32_t CFG_NMMU_CTL_TLB_ISS486_FIX_DIS = 28;
static const uint32_t CFG_NMMU_CTL_TLB_ISS505_FIX_DIS = 29;
static const uint32_t CFG_NMMU_CTL_TLB_ISS510_FIX_DIS = 30;
static const uint32_t CFG_NMMU_CTL_TLB_ISS512_FIX_DIS = 31;
static const uint32_t CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL = 32;
static const uint32_t CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL_LEN = 4;
static const uint32_t CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL = 36;
static const uint32_t CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL_LEN = 4;
static const uint32_t CFG_NMMU_CTL_TLB_ISS534_FIX_DIS = 40;
static const uint32_t CFG_NMMU_CTL_TLB_ISS537_FIX_DIS = 41;
static const uint32_t CFG_NMMU_CTL_TLB_ISS540_FIX_DIS = 42;
static const uint32_t CFG_NMMU_CTL_TLB_ISS543_FIX_DIS = 43;
static const uint32_t CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ = 44;
static const uint32_t CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ_LEN = 4;
static const uint32_t CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ = 48;
static const uint32_t CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ_LEN = 4;
static const uint32_t CFG_NMMU_CTL_TLB_ISS542_FIX_DIS = 52;
static const uint32_t CFG_NMMU_CTL_TLB_ISS543B_FIX_EN = 53;
static const uint32_t CFG_NMMU_CTL_TLB_ISS567_FIX_DIS = 54;
static const uint32_t CFG_NMMU_CTL_TLB_ISS586_FIX_DIS = 55;
static const uint32_t CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA = 56;
static const uint32_t CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA = 57;
static const uint32_t CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA = 58;
static const uint32_t CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA = 59;
//<< [CFG_NMMU_CTL_TLB]
// nmmu/reg00002.H

//>> [FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG]
static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG = 0x02010c10ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL_LEN = 8;
//<< [FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG]
// nmmu/reg00002.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "nmmu/reg00002.H"
#endif
#endif
