/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_4.H $          */
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

#ifndef __p10_scom_c_4_H_
#define __p10_scom_c_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_RVCSR]
static const uint64_t CPMS_RVCSR = 0x200e0e04ull;
static const uint64_t CPMS_RVCSR_WO_CLEAR = 0x200e0e07ull;
static const uint64_t CPMS_RVCSR_WO_OR = 0x200e0e06ull;

static const uint32_t CPMS_RVCSR_RVID_ENABLE = 0;
static const uint32_t CPMS_RVCSR_RVID_OVERRIDE = 1;
static const uint32_t CPMS_RVCSR_ACS_CALIBRATE = 2;
static const uint32_t CPMS_RVCSR_RVRM_TUNE = 6;
static const uint32_t CPMS_RVCSR_RVRM_TUNE_LEN = 6;
static const uint32_t CPMS_RVCSR_RVID_ACTIVE = 32;
static const uint32_t CPMS_RVCSR_BYPASS_ACTIVE = 33;
static const uint32_t CPMS_RVCSR_RVID_ENABLED = 34;
//<< [CPMS_RVCSR]
// c/reg00004.H

//>> [EC_PC_IMA_EVENT_MASK]
static const uint64_t EC_PC_IMA_EVENT_MASK = 0x20020400ull;

static const uint32_t EC_PC_IMA_EVENT_MASK_IC_TAP = 30;
static const uint32_t EC_PC_IMA_EVENT_MASK_IC_TAP_LEN = 3;
static const uint32_t EC_PC_IMA_EVENT_MASK_DIS_WRAP = 33;
static const uint32_t EC_PC_IMA_EVENT_MASK_FREEZE = 34;
static const uint32_t EC_PC_IMA_EVENT_MASK_EN_D_PRE = 36;
static const uint32_t EC_PC_IMA_EVENT_MASK_EN_I_PRE = 37;
static const uint32_t EC_PC_IMA_EVENT_MASK_ONE_EVENT = 38;
static const uint32_t EC_PC_IMA_EVENT_MASK_EVENT_VTID = 39;
static const uint32_t EC_PC_IMA_EVENT_MASK_EVENT_VTID_LEN = 2;
static const uint32_t EC_PC_IMA_EVENT_MASK_EVENT_SELECT = 41;
static const uint32_t EC_PC_IMA_EVENT_MASK_EVENT_SELECT_LEN = 5;
//<< [EC_PC_IMA_EVENT_MASK]
// c/reg00004.H

//>> [L2_L2MISC_L2CERRS_TOPOTABLE2]
static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE2 = 0x20020016ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_16 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_16_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_17 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_17_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_18 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_18_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_19 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_19_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_20 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_20_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_21 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_21_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_22 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_22_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_23 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_23_LEN = 4;
//<< [L2_L2MISC_L2CERRS_TOPOTABLE2]
// c/reg00004.H

//>> [L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD]
static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD = 0x20010627ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_LEN = 4;
//<< [L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD]
// c/reg00004.H

//>> [QME_SPWU_FSP]
static const uint64_t QME_SPWU_FSP = 0x200e0834ull;

static const uint32_t QME_SPWU_FSP_REQ = 0;
static const uint32_t QME_SPWU_FSP_DONE = 4;
//<< [QME_SPWU_FSP]
// c/reg00004.H

//>> [QME_SPWU_HYP]
static const uint64_t QME_SPWU_HYP = 0x200e083cull;

static const uint32_t QME_SPWU_HYP_REQ = 0;
static const uint32_t QME_SPWU_HYP_DONE = 4;
//<< [QME_SPWU_HYP]
// c/reg00004.H

//>> [QME_SPWU_OCC]
static const uint64_t QME_SPWU_OCC = 0x200e0838ull;

static const uint32_t QME_SPWU_OCC_REQ = 0;
static const uint32_t QME_SPWU_OCC_DONE = 4;
//<< [QME_SPWU_OCC]
// c/reg00004.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00004.H"
#endif
#endif
