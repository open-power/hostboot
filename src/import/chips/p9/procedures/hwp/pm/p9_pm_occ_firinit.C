/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_occ_firinit.C $             */
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
/// @file p9_pm_occ_firinit.C
/// @brief Configures the OCC LFIR Mask and Action
///
// *HWP HWP Owner: Jim Yacynych <jimyac@us.ibm.com>
// *HWP FW  Owner: Sunil Kumar  <skumar8j@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: HS
//

/// \todo
/// High-level procedure flow:
/// \verbatim
///
/// Procedure Prereq:
///   o System clocks are running
/// \endverbatim
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "p9_pm_occ_firinit.H"

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Macro definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p9_pm_occ_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::P9_PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p9_pm_occ_firinit Enter");

    FAPI_IMP("p9_pm_occ_firinit Exit");
    return fapi2::FAPI2_RC_SUCCESS;
} // end p9_pm_occ_firinit
