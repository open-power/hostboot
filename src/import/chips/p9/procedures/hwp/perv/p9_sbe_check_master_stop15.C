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
// *HWP Level       : 1
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

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

// See .H for documentation
fapi2::ReturnCode p9_sbe_check_master_stop15(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    FAPI_IMP("> p9_sbe_check_master_stop15");

    FAPI_INF("< p9_sbe_check_master_stop15");

    return fapi2::current_err;
} // END p9_sbe_check_master_stop15

