/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_sbe_check_master_stop15.C $ */
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
///
/// @file  p9_sbe_check_master_stop15.H
/// @brief Check if the targeted core (master) is fully in STOP15
///
// *HWP HWP Owner   : Greg Still <stillgsg@us.ibm.com>
// *HWP FW Owner    : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team        : PM
// *HWP Level       : 2
// *HWP Consumed by : SBE
///
/// High-level procedure flow:
/// @verbatim
///    - Read the STOP History Register from the target core
///    - Return SUCCESS if::
///        - STOP_GATED is set (indicating it is not running)
///        - STOP_TRANSITION is COMPLETE (indicating it is stable)
///        - ACT_STOP_LEVEL is at the appropriate value (either 11 (0xB) or
///          15 (0xF)
///    - Return PENDING if
///        - STOP_GATED is RUNNING
///         or
///        - STOP_GATED is GATED  (indicating it is not running)
///        - STOP_TRANSITION is not COMPLETE (indicating transtion is progress)
///    - Return ERROR if
///        - STOP_GATED is set, STOP_TRANSITION is COMPLETE and ACT_STOP_LEVEL
///          is not appropriate
///        - Hardware access errors
/// @endverbatim

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <p9_sbe_check_master_stop15.H>
#include <p9_pm_stop_history.H>
#include <p9_quad_scom_addresses.H>

#ifdef DD2
    #include <p9_collect_deadman_ffdc.H>
#endif

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

// See .H for documentation
fapi2::ReturnCode p9_sbe_check_master_stop15(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    FAPI_IMP("> p9_sbe_check_master_stop15");

    fapi2::buffer<uint64_t> l_data64;
    uint32_t l_stop_gated = 0;
    uint32_t l_stop_transition = p9ssh::SSH_UNDEFINED;
    uint32_t l_stop_requested_level = 0; // Running Level
    uint32_t l_stop_actual_level = 0;    // Running Level

    // Read the "Other" STOP History Register
    FAPI_TRY(fapi2::getScom(i_target, C_PPM_SSHOTR, l_data64));

    // Extract the field values
    l_data64.extractToRight<p9ssh::STOP_GATED_START,
                            p9ssh::STOP_GATED_LEN>(l_stop_gated);

    l_data64.extractToRight<p9ssh::STOP_TRANSITION_START,
                            p9ssh::STOP_TRANSITION_LEN>(l_stop_transition);

    // Testing showed the above operation was sign extending into
    // the l_stop_transition variable.
    l_stop_transition &= 0x3;

    l_data64.extractToRight<p9ssh::STOP_REQUESTED_LEVEL_START,
                            p9ssh::STOP_REQUESTED_LEVEL_LEN>(l_stop_requested_level);

    l_data64.extractToRight<p9ssh::STOP_ACTUAL_LEVEL_START,
                            p9ssh::STOP_ACTUAL_LEVEL_LEN>(l_stop_actual_level);

#ifndef __PPE__
    FAPI_DBG("GATED = %d; TRANSITION = %d (0x%X); REQUESTED_LEVEL = %d; ACTUAL_LEVEL = %d",
             l_stop_gated,
             l_stop_transition, l_stop_transition,
             l_stop_requested_level,
             l_stop_actual_level);

    FAPI_DBG("SSH_RUNNING = %d; SSH_GATED = %d; SSH_COMPLETE = %d",
             p9ssh::SSH_RUNNING,
             p9ssh::SSH_GATED,
             p9ssh::SSH_COMPLETE);
#endif

    if (l_stop_gated == p9ssh::SSH_RUNNING ||
        (l_stop_gated ==  p9ssh::SSH_GATED &&
         l_stop_transition != p9ssh::SSH_COMPLETE))
    {
        FAPI_ASSERT(false,
                    fapi2::CHECK_MASTER_STOP15_PENDING(),
                    "STOP 15 is still pending")
    }

    if (l_stop_gated == p9ssh::SSH_GATED &&
        l_stop_transition == p9ssh::SSH_COMPLETE &&
        (l_stop_requested_level == 11 || l_stop_requested_level == 15))
    {
        FAPI_INF("SUCCESS!!  Valid STOP entry state has been achieved.");
    }
    else
    {
#ifdef DD2
        FAPI_TRY ( p9_collect_deadman_ffdc (
                       i_target,
                       CHECK_MASTER_STOP15_INVALID_STATE ));
#else
        // DD1 has a memory crunch on SBE
        FAPI_ASSERT ( false,
                      fapi2::CHECK_MASTER_STOP15_INVALID_STATE()
                      .set_STOP_HISTORY(l_data64),
                      "STOP 15 error" );
#endif
    }

// @todo RTC 162331 These should work but don't..... follow-up later
//     // Check for valid pending condition (which includes running)
//     FAPI_ASSERT((l_stop_gated == p9ssh::SSH_RUNNING ||
//                   (l_stop_gated ==  p9ssh::SSH_GATED &&
//                    l_stop_transition != p9ssh::SSH_COMPLETE)),
//                 fapi2::CHECK_MASTER_STOP15_PENDING(),
//                 "STOP 15 is still pending");

//     // Assert gated, completion and the proper STOP actual level.  If not, something is off.
//     FAPI_ASSERT((l_stop_gated == p9ssh::SSH_GATED &&
//                  l_stop_transition == p9ssh::SSH_COMPLETE &&
//                  (l_stop_actual_level == 11 || l_stop_actual_level == 15)),
//                 fapi2::CHECK_MASTER_STOP15_INVALID_STATE()
//                 .set_STOP_HISTORY(l_data64),
//     }            "STOP 15 error");



fapi_try_exit:
    FAPI_INF("< p9_sbe_check_master_stop15");

    return fapi2::current_err;
} // END p9_sbe_check_master_stop15
