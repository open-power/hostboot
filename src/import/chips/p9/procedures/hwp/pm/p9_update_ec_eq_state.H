/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_update_ec_eq_state.H $         */
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
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: SBE
///

#ifndef _p9_update_ec_eq_state_H_
#define _p9_update_ec_eq_state_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_misc_scom_addresses.H>


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_update_ec_eq_state_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

extern "C" {

// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------

/// @brief Select the Hostboot core from the available cores on the chip
///
/// @param [in] i_target    Chip target
///

    fapi2::ReturnCode p9_update_ec_eq_state(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif // _p9_update_ec_eq_state_H_
