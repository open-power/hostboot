/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_query_cache_access_state.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file  p9_query_cache_access_state.H
/// @brief Check the stop level for the EX caches and sets boolean scomable parameters
///
// *HWP HWP Owner: Christina Graves <clgraves@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:  Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS:SBE
///
///-----------------------------------------------------------------------------

#ifndef _p9_query_cache_access_state_H_
#define _p9_query_cache_access_state_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_pm.H>
#include <p9_quad_scom_addresses.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
#define MAX_L2_PER_QUAD 2 //shared by the core/ex
#define MAX_L3_PER_QUAD 2 //shared by the core/ex
// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_query_cache_access_state_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>&,
    bool*,
    bool*,
    bool*,
    bool*);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

/// @brief Check the stop level for the EX caches and sets boolean scomable parameters
///
/// @param[in] i_target        EX target
///
/// @param[out] o_l2_is_scomable[MAX_L2_PER_QUAD]
//                           L2 cache has clocks running and is scomable
/// @param[out[ o_l2_is_scannable[MAX_L2_PER_QUAD]
//                           L2 cache is powered up and has valid latch state
/// @param[out] o_l3_is_scomable  L3 cache has clocks running and is scomable
/// @param[out[ o_l2_is_scannable L3 cache is powered up and has valid latch state
///
/// @return FAPI2_RC_SUCCESS if success, else error code.

    fapi2::ReturnCode
    p9_query_cache_access_state(
        const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
        bool  o_l2_is_scomable[MAX_L2_PER_QUAD],
        bool  o_l2_is_scannable[MAX_L2_PER_QUAD],
        bool  o_l3_is_scomable[MAX_L3_PER_QUAD],
        bool  o_l3_is_scannable[MAX_L3_PER_QUAD]);

/// @brief Check the stop level for the EX caches and sets boolean scomable parameters
///
/// @param[in] i_target        EX target
///
/// @param[out] o_l2_is_scomable[MAX_L2_PER_QUAD]
//                           L2 cache has clocks running and is scomable
/// @param[out] o_l3_is_scomable  L3 cache has clocks running and is scomable
///
/// @return FAPI2_RC_SUCCESS if success, else error code.

    fapi2::ReturnCode
    p9_query_cache_clock_state(
        const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
        bool  o_l2_is_scomable[MAX_L2_PER_QUAD],
        bool  o_l3_is_scomable[MAX_L3_PER_QUAD]);

} // extern "C"

#endif // _p9_query_cache_access_state_H_
