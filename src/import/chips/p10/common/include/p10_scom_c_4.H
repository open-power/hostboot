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


//>> [CPMS_CCCR]
static const uint64_t CPMS_CCCR = 0x200e0e70ull;

static const uint32_t CPMS_CCCR_COUNT_MODE = 0;
static const uint32_t CPMS_CCCR_COUNT_MODE_LEN = 2;
static const uint32_t CPMS_CCCR_COUNT_TYPE = 2;
static const uint32_t CPMS_CCCR_COUNT_TYPE_LEN = 2;
static const uint32_t CPMS_CCCR_COUNT_ENABLE_SEL = 4;
static const uint32_t CPMS_CCCR_COUNT_ENABLE_SEL_LEN = 2;
static const uint32_t CPMS_CCCR_INVERT_COUNT_ENABLE = 6;
static const uint32_t CPMS_CCCR_COUNT_ALWAYS_SAMPLED = 7;
static const uint32_t CPMS_CCCR_HI_THRESHOLD = 8;
static const uint32_t CPMS_CCCR_HI_THRESHOLD_LEN = 8;
static const uint32_t CPMS_CCCR_LO_THRESHOLD = 16;
static const uint32_t CPMS_CCCR_LO_THRESHOLD_LEN = 8;
static const uint32_t CPMS_CCCR_SPARE = 24;
static const uint32_t CPMS_CCCR_SPARE_LEN = 2;
//<< [CPMS_CCCR]
// c/reg00004.H

//>> [CPMS_DPCR]
static const uint64_t CPMS_DPCR = 0x200e0ea4ull;

static const uint32_t CPMS_DPCR_PROXY_SCALE_FACTOR = 0;
static const uint32_t CPMS_DPCR_PROXY_SCALE_FACTOR_LEN = 12;
static const uint32_t CPMS_DPCR_PROXY_LEAKAGE_CONSTANT = 12;
static const uint32_t CPMS_DPCR_PROXY_LEAKAGE_CONSTANT_LEN = 8;
static const uint32_t CPMS_DPCR_DDP_RECHARGE_VALUE = 20;
static const uint32_t CPMS_DPCR_DDP_RECHARGE_VALUE_LEN = 7;
//<< [CPMS_DPCR]
// c/reg00004.H

//>> [CPMS_PSSR]
static const uint64_t CPMS_PSSR = 0x200e0e9cull;

static const uint32_t CPMS_PSSR_ACCUM_ERROR = 0;
static const uint32_t CPMS_PSSR_ACCUM_ERROR_LEN = 20;
static const uint32_t CPMS_PSSR_AVG_FTX_PHASE0 = 20;
static const uint32_t CPMS_PSSR_AVG_FTX_PHASE0_LEN = 8;
static const uint32_t CPMS_PSSR_AVG_FTX_PHASE1 = 28;
static const uint32_t CPMS_PSSR_AVG_FTX_PHASE1_LEN = 8;
static const uint32_t CPMS_PSSR_AVG_FTX_TOTAL = 36;
static const uint32_t CPMS_PSSR_AVG_FTX_TOTAL_LEN = 8;
static const uint32_t CPMS_PSSR_PITCH_PERIOD_NUMBER = 44;
static const uint32_t CPMS_PSSR_PITCH_PERIOD_NUMBER_LEN = 4;
static const uint32_t CPMS_PSSR_PITCH_SUB_PERIOD = 48;
static const uint32_t CPMS_PSSR_PITCH_SUB_PERIOD_LEN = 2;
static const uint32_t CPMS_PSSR_PITCH_PERIOD_TIMER = 50;
static const uint32_t CPMS_PSSR_PITCH_PERIOD_TIMER_LEN = 13;
static const uint32_t CPMS_PSSR_PITCH_ACTIVE = 63;
//<< [CPMS_PSSR]
// c/reg00004.H

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
static const uint32_t P10_20_CPMS_RVCSR_BYPASS_RAW = 35; // p10:20,
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

//>> [QME_SSH_FSP]
static const uint64_t QME_SSH_FSP = 0x200e0824ull;

static const uint32_t QME_SSH_FSP_STOP_GATED = 0;
static const uint32_t QME_SSH_FSP_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_FSP_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_FSP_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_FSP_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_FSP_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_FSP_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_FSP_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
//<< [QME_SSH_FSP]
// c/reg00004.H

//>> [QME_SSH_HYP]
static const uint64_t QME_SSH_HYP = 0x200e082cull;

static const uint32_t QME_SSH_HYP_STOP_GATED = 0;
static const uint32_t QME_SSH_HYP_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_HYP_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_HYP_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_HYP_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_HYP_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_HYP_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_HYP_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
//<< [QME_SSH_HYP]
// c/reg00004.H

//>> [QME_SSH_OCC]
static const uint64_t QME_SSH_OCC = 0x200e0828ull;

static const uint32_t QME_SSH_OCC_STOP_GATED = 0;
static const uint32_t QME_SSH_OCC_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_OCC_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_OCC_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_OCC_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_OCC_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OCC_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_OCC_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
//<< [QME_SSH_OCC]
// c/reg00004.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00004.H"
#endif
#endif
