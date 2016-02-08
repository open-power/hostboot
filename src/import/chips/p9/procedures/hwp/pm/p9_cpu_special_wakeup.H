/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
///
///  @file          :     p9_cpu_special_wakeup.H
///  @brief         :     HWP to perform special wakeup of core, EQ or EX.

// *HWP HW Owner    :    Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :    Prem S Jha <premjha2@in.ibm.com>
// *HWP Team        :    PM
// *HWP Level       :    2
// *HWP Consumed by :    OCC:FSP:HOST

#ifndef __P9_CPU_SPECIAL_WAKEUP_H_
#define __P9_CPU_SPECIAL_WAKEUP_H_


// ---------------------------------------------------------------------
// Includes
// ---------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

namespace p9specialWakeup
{

/**
 * @brief enumerates all platforms which request special wakeup.
 */
enum PROC_SPCWKUP_ENTITY
{
    OTR = 0,
    FSP = 1,
    OCC = 2,
    HYP = 3,
    HOST = HYP,
    SPW_ALL
};

/**
 * @brief enumerates all operations associated with special wakeup.
 */
enum PROC_SPCWKUP_OPS
{
    SPCWKUP_ENABLE = 0,
    SPCWKUP_DISABLE = 1
};

/**
 * @brief enumerates types of special wakeup.
 */
enum PROC_SPCWKUP_TYPE
{
    SPW_CORE    = 0,
    SPW_EQ      = 1,
    SPW_EX      = 2
};
// Used by checking infrastructure checking code
static const uint32_t END_OP = SPCWKUP_DISABLE;

/**
 * Id of the string associated with special wakeup.
 */
enum SpecialWakeUpMsg
{
    SPWK_MSG_ASSERT             = 0,
    SPWK_MSG_DEASSERT           = 1,
    SPWK_MSG_CLEAN_UP_DEASSERT  = 2,
};

} //p9specialWakeup ends

typedef fapi2::ReturnCode (*p9_cpu_special_wakeup_FP_t)
( const fapi2::Target < fapi2::TARGET_TYPE_CORE >&,
  const p9specialWakeup::PROC_SPCWKUP_OPS,
  const p9specialWakeup::PROC_SPCWKUP_ENTITY);

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_cpu_special_wakeup_core_FP_t)
( const fapi2::Target < fapi2::TARGET_TYPE_CORE >&,
  const p9specialWakeup::PROC_SPCWKUP_OPS,
  const p9specialWakeup::PROC_SPCWKUP_ENTITY);

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_cpu_special_wakeup_eq_FP_t)
( const fapi2::Target < fapi2::TARGET_TYPE_EQ >&,
  const p9specialWakeup::PROC_SPCWKUP_OPS,
  const p9specialWakeup::PROC_SPCWKUP_ENTITY);

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_cpu_special_wakeup_ex_FP_t)
( const fapi2::Target < fapi2::TARGET_TYPE_EX >&,
  const p9specialWakeup::PROC_SPCWKUP_OPS,
  const p9specialWakeup::PROC_SPCWKUP_ENTITY);



extern "C"
{

/// @brief  Asserts/Deasserts core, ex or eq chiplets into special wakeup state.
/// @verbatim
/// - General function
///     Based on "entity" parameter (OCC, FSP, HYP, OTHER), write the
///     appropriate Special Wakeup bit (different address)
///
///     Poll for SPECIAL WAKEUP DONE
///
///     Note: the caller has to decide what needs to be target based on the
///     fused operational mode and the address that is needed to be accessed.
///     This procedure does NOT know the address(es) to be accessed.
///
/// - General flow
///         if TARGET_TYPE_CORE, same as normal core mode
///         if TARGET_TYPE_EQ, same a normal core mode
///         if TARGET_TYPE_EX, sets special wakeup to both cores in the EX
///             The act of waking up an EX will wakeup the shared portion of the EQ
///             (including the CMEs and all L3) as well as the L2 domain associated
///             with the functional core in the targeted EX. The two cores will be
///             restored (including SCOM and SPR restoration.
///
/// - Polling Timeouts
///     Timeouts need to account for the following:
///         1) All the chiplets are not in a Deep Idle state and will awaken in
///         < 1us
///
///         2) All the chiplets in a STOP 4 or less can be awakened in < 1ms
///
///         3) Multiple chiplets in STOP 11/15 will cause a serialization of
///         at least two exits so awakening of < 5ms
///
///  Procedure Prereq:
///     - Caller must follow these rules:
///       - if system checkstop is present, set ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG
///           to not produce errors if special wake-up done times out
///       - On a successful assertion of special wake-up, deassert afterwards!
///       - On an unsuccessful assertion of special wake-up, do NOT deassert
///         afterwards!
/// @endverbatim
///
/// @param[in]   i_chipletTarget fapi2 target associated with core, ex and eq.
/// @param[in]   i_operation     special wakeup operations to be used.
///                 SPCWKUP_ENABLE - asserts the special wake-up bit associated
///                     with i_entity, increment entity specific counter
///                     (attribute), and poll for valid special wakeup completion.
///                 SPCWKUP_DISABLE - decrement entity specific counter (attribute)
///                     associated with i_entity and deasserts the special wake-up
///                     bit only if the count is zero.
///                 SPCWKUP_INIT - write all entity counters(attributes) to zero.
///                 SPCWKUP_FORCE_DEASSERT - deassert the i_entity bit without
///                     checking or updating the counter attributes.
/// @param[in]   i_entity  entity to perform special wake-up upon.  Effectively
///                 chooses the special wake-up to use.
/// @return      FAPI2_RC_SUCCESS on success, errorcode otherwise.
///
/// @note   needs support of following attributes:
///         ATTR_PM_SPWUP_CORE[NUM_ENTITIES] (CORE target) - counter attributes
///             for Cores
///         ATTR_PM_SPWUP_EQ[NUM_ENTITIES] (EQ target) - counter attributes for
///             EQs
///         ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG (PROC target) - bypass Done timeout
///             Done checking to return SUCCESS if a checkstop condition is
///             present.  Must be set by the caller to suppress timeout errors
///             from being reported.
///
    fapi2::ReturnCode p9_cpu_special_wakeup(
        const fapi2::Target <fapi2::TARGET_TYPE_CORE>& i_target,
        const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
        const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity );

    fapi2::ReturnCode p9_cpu_special_wakeup_core(
        const fapi2::Target <fapi2::TARGET_TYPE_CORE>& i_target,
        const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
        const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity );

    fapi2::ReturnCode p9_cpu_special_wakeup_eq(
        const fapi2::Target <fapi2::TARGET_TYPE_EQ>& i_target,
        const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
        const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity );

    fapi2::ReturnCode p9_cpu_special_wakeup_ex(
        const fapi2::Target <fapi2::TARGET_TYPE_EX>& i_target,
        const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
        const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity );

}// extern "C" ends

#endif //__P9_CPU_SPECIAL_WAKEUP_H_
