/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_firinit.H $                  */
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
/// @file p9_pm_firinit.H
/// @brief  common .H file for all FIRINITS
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS

#ifndef _P9_PM_FIRINIT_H_
#define _P9_PM_FIRINIT_H_
//------------------------------------------------------------------------------
//
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_firinit_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE);

extern "C"
{
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Calls each PM unit firinit procedures based on the input mode,
///        to configure the FIRs of the chip to  predefined types.
///        The procdures invoked are:
///        p9_pm_pmc_firinit
///        p9_pm_pba_firinit
///        p9_pm_ppm_firinit
///        p9_pm_occ_firinit
///
/// @param[in] i_target   Chip target which will be passed to all the procedures
/// @param[in] i_mode     Control mode for the procedure:
///                       PM_INIT, PM_RESET, PM_RESET_SOFT
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_pm_firinit(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode);

} // extern "C"

#endif //_P9_PM_FIRINIT_H_
