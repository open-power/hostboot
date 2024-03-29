/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_exit_cache_contained.H $ */
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
///
/// @file p10_exit_cache_contained.H
/// @brief Trigger SBE assist to exit HB cache containment

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

#ifndef _P10_EXIT_CACHE_CONTAINED_H_
#define _P10_EXIT_CACHE_CONTAINED_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_sbe_exit_cache_contained.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_exit_cache_contained_FP_t)(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets,
    const p10_sbe_exit_cache_contained_step_t&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{

///
/// @brief Trigger SBE assist to exit HB cache containment
///
/// @param[in] i_targets   Collection of processor chip targets in drawer scope
/// @param[in] i_step      Enum defining steps of HWP sequence which should
///                        be run
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_exit_cache_contained(
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets,
        const p10_sbe_exit_cache_contained_step_t& i_step);

} // extern "C"

#endif // _P10_EXIT_CACHE_CONTAINED_H_
