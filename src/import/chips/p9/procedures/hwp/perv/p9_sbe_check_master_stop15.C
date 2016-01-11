/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_sbe_check_master_stop15.C $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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
///        - STOP_GATED is set (indicating it is stopped)
///        - STOP_TRANSITION is clear (indicating it is stable)
///        - ACT_STOP_LEVEL is at the appropriate value (either 11 (0xB) or 15 (0x15)
///    - Return PENDING if
///        - STOP_TRANSITION is set (indicating transtion is progress)
///    - Return ERROR if
///        - STOP_GATED is set, STOP_TRANSITION is clear and ACT_STOP_LEVEL is not
///          appropriate
///        - STOP_TRANSITION is clear but STOP_GATED is clear
///        - Hardware access errors
/// @endverbatim

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <p9_sbe_check_master_stop15.H>
#include <p9_pm_stop_history.H>
#include <p9_quad_scom_addresses.H>

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
#endif

    // Check for valide reguest level
    FAPI_ASSERT((l_stop_requested_level == 11 || l_stop_requested_level == 15),
                fapi2::CHECK_MASTER_STOP15_INVALID_REQUEST_LEVEL()
                .set_REQUESTED_LEVEL(l_stop_requested_level),
                "Invalid requested STOP Level");

    // Check for valid pending condition
    FAPI_ASSERT(!(l_stop_transition == p9ssh::SSH_CORE_COMPLETE ||
                  l_stop_transition == p9ssh::SSH_ENTERING        ),
                fapi2::CHECK_MASTER_STOP15_PENDING(),
                "STOP 15 is still pending");

    // Assert completion and the core gated condition.  If not, something is off.
    FAPI_ASSERT((l_stop_transition == p9ssh::SSH_COMPLETE &&
                 l_stop_gated == p9ssh::SSH_GATED         ),
                fapi2::CHECK_MASTER_STOP15_INVALID_STATE()
                .set_STOP_HISTORY(l_data64),
                "STOP 15 error");

    // Check for valid actual level
    FAPI_ASSERT((l_stop_actual_level == 11 || l_stop_actual_level == 15),
                fapi2::CHECK_MASTER_STOP15_INVALID_ACTUAL_LEVEL()
                .set_ACTUAL_LEVEL(l_stop_actual_level),
                "Invalid actual STOP Level");

    FAPI_INF("SUCCESS!!  Valid STOP entry state has been achieved.")

fapi_try_exit:
    FAPI_INF("< p9_sbe_check_master_stop15");

    return fapi2::current_err;
} // END p9_sbe_check_master_stop15

