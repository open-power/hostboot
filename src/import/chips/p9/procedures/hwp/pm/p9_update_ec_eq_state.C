/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_update_ec_eq_state.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_update_ec_eq_state.H
/// @brief Update the "permanent" multicast groups  reflect any additional
///          deconfigured by Hostboot
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: SBE
///
///
///
/// High-level procedure flow:
/// @verbatim
///  Å Update the "permanent" multicast groups  reflect any additional
///        deconfiguration by Hostboot
///  Å Use the functional state to find all good cores
///  Å Write the good core and quad mask into OCC CCSR and QCSR respectively
///         These become the "master record " of the enabled cores/quad in
///         the system for runtime
/// @endverbatim

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include "p9_update_ec_eq_state.H"

// -----------------------------------------------------------------------------
//  Function prototypes
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------


// See .H for documentation
fapi2::ReturnCode p9_update_ec_eq_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("p9_update_ec_eq_state start");

    FAPI_INF("p9_update_ec_eq_state end");

    return fapi2::current_err;
} // END p9_update_ec_eq_state
