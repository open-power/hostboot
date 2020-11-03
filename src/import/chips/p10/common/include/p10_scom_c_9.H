/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_9.H $          */
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

#ifndef __p10_scom_c_9_H_
#define __p10_scom_c_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_DDSR]
static const uint64_t CPMS_DDSR = 0x200e0e50ull;

static const uint32_t CPMS_DDSR_DDS_DATA = 3;
static const uint32_t CPMS_DDSR_DDS_DATA_LEN = 5;
static const uint32_t CPMS_DDSR_DDS_MIN = 11;
static const uint32_t CPMS_DDSR_DDS_MIN_LEN = 5;
static const uint32_t CPMS_DDSR_DDS_MAX = 19;
static const uint32_t CPMS_DDSR_DDS_MAX_LEN = 5;
static const uint32_t CPMS_DDSR_DPLL_ENCODED_DATA = 33;
static const uint32_t CPMS_DDSR_DPLL_ENCODED_DATA_LEN = 3;
static const uint32_t CPMS_DDSR_DPLL_ENCODED_MIN = 37;
static const uint32_t CPMS_DDSR_DPLL_ENCODED_MIN_LEN = 3;
static const uint32_t CPMS_DDSR_DPLL_ENCODED_MAX = 41;
static const uint32_t CPMS_DDSR_DPLL_ENCODED_MAX_LEN = 3;
static const uint32_t CPMS_DDSR_STOP_STATE_ACTIVE = 60;
static const uint32_t CPMS_DDSR_CORE_SAMPLE_DISABLED = 61;
static const uint32_t CPMS_DDSR_STOP_STATE_OCCURRED = 62;
static const uint32_t CPMS_DDSR_SAMPLE_DISABLE_OCCURRED = 63;
//<< [CPMS_DDSR]
// c/reg00009.H

//>> [CPMS_FDIR]
static const uint64_t CPMS_FDIR = 0x200e0e44ull;
static const uint64_t CPMS_FDIR_WO_CLEAR = 0x200e0e47ull;
static const uint64_t CPMS_FDIR_WO_OR = 0x200e0e46ull;

static const uint32_t CPMS_FDIR_INJECT_ENABLE = 0;
static const uint32_t CPMS_FDIR_UARCH_HALT_INJECT = 1;
static const uint32_t CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT = 2;
static const uint32_t CPMS_FDIR_FETCH_THROTTLE10_INJECT = 3;
static const uint32_t CPMS_FDIR_FETCH_THROTTLE01_INJECT = 4;
static const uint32_t CPMS_FDIR_ISSUE_NTC_INJECT = 5;
static const uint32_t CPMS_FDIR_PREFETCH_THROTTLE_INJECT = 6;
static const uint32_t CPMS_FDIR_PREFETCH_THROTTLE_INJECT_LEN = 2;
static const uint32_t CPMS_FDIR_SLOW_FETCH_INJECT = 8;
static const uint32_t CPMS_FDIR_VECTOR_LIMIT_INJECT = 9;
static const uint32_t CPMS_FDIR_VECTOR_LIMIT_INJECT_LEN = 3;
static const uint32_t CPMS_FDIR_SLOW_COMPLETION_INJECT = 12;
static const uint32_t CPMS_FDIR_MMA_UARCH_ENABLE_INJECT = 13;
static const uint32_t CPMS_FDIR_MMA_LIMIT = 14;
static const uint32_t CPMS_FDIR_MMA_LIMIT_LEN = 2;
static const uint32_t CPMS_FDIR_TOGGLE_HALT_AMOUNT = 16;
static const uint32_t CPMS_FDIR_TOGGLE_HALT_AMOUNT_LEN = 4;
static const uint32_t CPMS_FDIR_IRRITATE_INJECT_RESPONSE = 20;
static const uint32_t CPMS_FDIR_IRRITATE_INJECT_RESPONSE_LEN = 2;
static const uint32_t CPMS_FDIR_IRRITATE_LFSR_SELECT = 22;
static const uint32_t CPMS_FDIR_IRRITATE_LFSR_SELECT_LEN = 2;
static const uint32_t CPMS_FDIR_IRRITATE_SMALL_SELECT = 24;
static const uint32_t CPMS_FDIR_IRRITATE_SMALL_SELECT_LEN = 2;
static const uint32_t CPMS_FDIR_IRRITATE_LARGE_SELECT = 26;
static const uint32_t CPMS_FDIR_IRRITATE_LARGE_SELECT_LEN = 2;
static const uint32_t CPMS_FDIR_EXCLUDE_LSU_HALT = 28;
static const uint32_t CPMS_FDIR_IRRITATE_WEIGHT_SELECT = 29;
static const uint32_t CPMS_FDIR_IRRITATE_WEIGHT_SELECT_LEN = 2;
static const uint32_t CPMS_FDIR_INJECT_DPT_SUSPEND = 31;
//<< [CPMS_FDIR]
// c/reg00009.H

//>> [EC_PC_TFX_SM]
static const uint64_t EC_PC_TFX_SM = 0x2002049bull;

static const uint32_t EC_PC_TFX_SM_INACTIVE = 0;
static const uint32_t EC_PC_TFX_SM_ACTIVE = 1;
static const uint32_t EC_PC_TFX_SM_LOAD = 2;
static const uint32_t EC_PC_TFX_SM_SEND = 3;
static const uint32_t EC_PC_TFX_SM_RECEIVE = 4;
//<< [EC_PC_TFX_SM]
// c/reg00009.H

//>> [L3_MISC_L3CERRS_BACKING_CTL_REG]
static const uint64_t L3_MISC_L3CERRS_BACKING_CTL_REG = 0x2001060full;

static const uint32_t L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG = 1;
static const uint32_t L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG_LEN = 3;
//<< [L3_MISC_L3CERRS_BACKING_CTL_REG]
// c/reg00009.H

//>> [NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS]
static const uint64_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS = 0x2001068aull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM_LEN = 7;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT = 12;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT_LEN = 4;
//<< [NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS]
// c/reg00009.H

//>> [QME_CDBB]
static const uint64_t QME_CDBB = 0x200e0804ull;

static const uint32_t QME_CDBB_MESSAGE_NUMBER = 0;
static const uint32_t QME_CDBB_MESSAGE_NUMBER_LEN = 8;
//<< [QME_CDBB]
// c/reg00009.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00009.H"
#endif
#endif
