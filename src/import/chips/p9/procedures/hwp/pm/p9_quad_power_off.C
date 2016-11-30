/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_quad_power_off.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file p9_quad_power_off.C
/// @brief Power off the EQ including the functional cores associatated with it.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : OCC:CME:FSP
//----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
//     - For each good EC associated with the targeted EQ, power it off.
//     - Power off the EQ.
// @endverbatim
//
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_quad_power_off.H>

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// Procedure p9_quad_power_off entry point, comments in header
fapi2::ReturnCode p9_quad_power_off(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target)
{
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF("p9_quad_power_off: Entering...");

    // Print chiplet position
    FAPI_INF("Quad power off chiplet no.%d", i_target.getChipletNumber());

    // Call the procedure
    FAPI_EXEC_HWP(rc, p9_pm_pfet_control_eq, i_target,
                  PM_PFET_TYPE_C::BOTH, PM_PFET_TYPE_C::OFF);
    FAPI_TRY(rc);

fapi_try_exit:
    FAPI_INF("p9_quad_power_off: ...Exiting");
    return fapi2::current_err;
}
