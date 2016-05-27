/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_query_core_access_state.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

/// @file  p9_query_core_access_state.H
/// @brief Check the stop level for a core and set boolean scanable, scomable parameters
///
// *HWP HWP Owner: Brian Vanderpool <vanderp@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:  Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS:SBE
///
///-----------------------------------------------------------------------------

#ifndef _p9_query_core_access_state_H_
#define _p9_query_core_access_state_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_pm.H>
#include <p9_quad_scom_addresses.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_query_core_access_state_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
    bool&,
    bool&);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

/// @brief Check the stop level for a core and set boolean scanable, scomable parameters
///
/// @param[in] i_target        Core target
///
/// @param[out] o_is_scomable  Core has clocks running and is scomable
/// @param[out] o_is_scanable  Core is powered up and has valid latch state
///
/// @return FAPI2_RC_SUCCESS if success, else error code.

    fapi2::ReturnCode
    p9_query_core_access_state(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        bool& o_is_scomable,
        bool& o_is_scanable);

} // extern "C"

#endif // _p9_query_core_access_state_H_
