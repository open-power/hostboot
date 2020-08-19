/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_core_special_wakeup.H $ */
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
/// @file   p10_core_special_wakeup.H
/// @brief  Asserts or de-asserts special wakeup request on a given core.
///
// *HWP HW Owner:       Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:           PM
// *HWP Level:          2
// *HWP Consumed by:    HB,FSP

#ifndef _P10_CORE_SPECIAL_WAKEUP_H_
#define _P10_CORE_SPECIAL_WAKEUP_H_

#include <fapi2.H>
#include <p10_scom_c_0.H>
#include <p10_scom_c_4.H>

namespace p10specialWakeup
{

static const uint32_t  MAX_SPWKUP_ENTITY        =   4;
static const uint32_t  SPECIAL_WKUP_REQ_BIT     =   0;
static const uint32_t  SPWKUP_REQ_REG_OTR       =   scomt::c::QME_SPWU_OTR;
static const uint32_t  SPWKUP_REQ_REG_FSP       =   scomt::c::QME_SPWU_FSP;
static const uint32_t  SPWKUP_REQ_REG_OCC       =   scomt::c::QME_SPWU_OCC;
static const uint32_t  SPWKUP_REQ_REG_HYP       =   scomt::c::QME_SPWU_HYP;
static const uint32_t  SPWKUP_REQ_DONE_BIT      =   4;
static const uint32_t  QME_FLAG_STOP_READY      =   16;
static const uint32_t  SPECIAL_WAKE_UP_POLL_INTERVAL_NS  =  1000000;   //1ms
static const uint32_t  SPECIAL_WAKEUP_TIMEOUT_NS         =  (100 * SPECIAL_WAKE_UP_POLL_INTERVAL_NS);     //100 ms

/**
 * @brief enumerates all platforms which request special wakeup.
 */
enum PROC_SPCWKUP_ENTITY
{
    OTR     = 0,
    FSP     = 1,
    OCC     = 2,
    HYP     = 3,
    HOST    = HYP,
    SPW_ALL
};

/**
 * @brief enumerates all operations associated with special wakeup.
 */
enum PROC_SPCWKUP_OPS
{
    SPCWKUP_ENABLE  = 0,
    SPCWKUP_DISABLE = 1,
    MAX_OPERATION   = 2,
};

/**
 * @brief Special wakeup operation message.
 */
static char SplWkupMsg[MAX_OPERATION][10] __attribute__((unused)) =
{
    "ASSERT",
    "DE-ASSERT"
};

/**
 * @brief SCOM address for special wakeup for various entities.
 */
static const uint64_t SpecialWakeupAddr[MAX_SPWKUP_ENTITY]  =
{
    SPWKUP_REQ_REG_OTR,
    SPWKUP_REQ_REG_FSP,
    SPWKUP_REQ_REG_OCC,
    SPWKUP_REQ_REG_HYP,
};

/**
 * @brief Recursion modes supported by Spl Wkup HWP.
 */
enum RecursionOp
{
    UNBLOCK     =   0,
    BLOCK       =   1,
};

} //namespace p10specialWakeup ends

extern "C"
{
    typedef fapi2::ReturnCode (*p10_core_special_wakeup_FP_t)
    ( const fapi2::Target < fapi2::TARGET_TYPE_CORE  | fapi2::TARGET_TYPE_MULTICAST > &,
      const p10specialWakeup::PROC_SPCWKUP_OPS,
      const p10specialWakeup::PROC_SPCWKUP_ENTITY);

    fapi2::ReturnCode p10_core_special_wakeup(
        const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST > & i_target,
        const p10specialWakeup::PROC_SPCWKUP_OPS i_operation,
        const p10specialWakeup::PROC_SPCWKUP_ENTITY i_entity );

} //extern "C"

#endif // _P10_CORE_SPECIAL_WAKEUP_H_
