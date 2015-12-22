/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_fab_iovalid.H $               */
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
/// @file p9_fab_iovalid.H
/// @brief Manage fabric link iovalid controls (FAPI2)
///
/// Manage fabric X/A link iovalid controls, which control the
/// flow of fabric transactions
///
/// The iovalid controls are intended to be raised in the IPL flow
/// after the underlying PHY/DLL/TL layers are running, to start the
/// broadcast of fabric transactions
///
/// The iovalid controls are intended to be lowered prior to stopping
/// the clocks in the dump process (to provide a clean dump state with
/// the fabric quiesced)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB,FSP
//

#ifndef _P9_FAB_IOVALID_H_
#define _P9_FAB_IOVALID_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_fab_iovalid_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        const bool);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Raise/lower iovalids for all logically enabled links on a single chip
///
/// @param[in] i_target Reference to processor chip target
/// @param[in] i_set_not_clear Define iovalid operation (true=set, false=clear)
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_fab_iovalid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                     const bool i_set_not_clear);

} // extern "C"

#endif // _P9_FAB_IOVALID_H_
