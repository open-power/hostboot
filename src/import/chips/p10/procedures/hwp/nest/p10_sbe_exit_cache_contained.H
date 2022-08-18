/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_sbe_exit_cache_contained.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file p10_sbe_exit_cache_contained.H
/// @brief Execute sequence of HWP calls on SBE to exit HB cache
///        containment
///        - Stop instruction on active cores
///        - Revert MC setup in place to support HB execution in cache
///          contained footprint
///        - Configures MC/MCD BAR resources on all sockets, via XSCOM
///        - Purges active/backing caches and resets contained mode
///          configuration
///        - Restarts instructions on master core to relaunch HB from
///          main memory

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
// *HWP Consumed by  : SBE
//

#ifndef _P10_SBE_EXIT_CACHE_CONTAINED_H_
#define _P10_SBE_EXIT_CACHE_CONTAINED_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// permit step based execution of flow
enum class p10_sbe_exit_cache_contained_step_t : uint8_t
{
    STOP_HB            = 0x01,
    REVERT_MCS_SETUP   = 0x02,
    SETUP_MEMORY_BARS  = 0x04,
    PURGE_HB           = 0x08,
    RESUME_HB          = 0x10,
    RUN_ALL            = 0x1F,
    SKIP_ALL           = 0x00
};


constexpr enum p10_sbe_exit_cache_contained_step_t operator | (p10_sbe_exit_cache_contained_step_t a,
        p10_sbe_exit_cache_contained_step_t b)
{
    return (enum p10_sbe_exit_cache_contained_step_t)(uint8_t(a) | uint8_t(b));
}

constexpr enum p10_sbe_exit_cache_contained_step_t operator & (p10_sbe_exit_cache_contained_step_t a,
        p10_sbe_exit_cache_contained_step_t b)
{
    return (enum p10_sbe_exit_cache_contained_step_t)(uint8_t(a) & uint8_t(b));
}

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_sbe_exit_cache_contained_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const size_t,
    const void*,
    const p10_sbe_exit_cache_contained_step_t);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{

// @brief Executes sequence of HWP calls to exit HB cache containment
//
// @param[in] i_target          Reference to processor chip target
// @param[in] i_xscomPairSize   Number of XSCOM register address-data pair to
//                              be initialized.
// @param[in] i_pxscomInit      Pointer to the data set of address-data pair
//
// @param[in] i_steps           Enum defining steps of HWP sequence which should
//                              be run
//
// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
//
    fapi2::ReturnCode p10_sbe_exit_cache_contained(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const size_t i_xscomPairSize,
        const void* i_pxscomInit,
        const p10_sbe_exit_cache_contained_step_t i_steps);

///
/// @brief Process input target and associated attributes to generate set of
///        core targets needed for HWP calls
///
/// @param[in]  i_target                Reference to processor chip target
/// @param[out] o_active_core_targets   Set of targets to process which are
///                                     associated with active cores
///                                     (running HB code)
/// @param[out] o_backing_cache_targets Set of targets to process which are
///                                     associated with backing caches
/// @param[out] o_master_core_target    Designated HB master core target,
///                                     should lie in set of active core targets
/// @param[out] o_master_core_pair_target    Designated HB master core pair
///                                     target, should lie in set of active core
///                                     targets
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode
    p10_sbe_exit_cache_contained_validate_core_inputs(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>& o_active_core_targets,
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>& o_backing_cache_targets,
        fapi2::Target<fapi2::TARGET_TYPE_CORE>& o_master_core_target,
        fapi2::Target<fapi2::TARGET_TYPE_CORE>& o_master_core_pair_target);

} // extern "C"

#endif // _P10_SBE_EXIT_CACHE_CONTAINED_H_
