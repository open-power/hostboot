/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_init.H $                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pm_init.H
/// @brief Wrapper that calls underlying HWPs to perform a Power Management
///        Init function when needing to initialize the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner :
// *HWP FW Owner         : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 1
// *HWP Consumed by      : HS

#ifndef _P9_PM_INIT_H
#define _P9_PM_INIT_H

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm.H>
#include <fapi2.H>

// Function pointer defintion
typedef fapi2::ReturnCode (*p9_pm_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE);

extern "C"
{
//------------------------------------------------------------------------------
///
/// @brief Call underlying unit procedures to perform readiness for
///             initialization of PM complex.
///
/// @param[in] i_target Primary Chip target which will be passed
///                     to all the procedures
/// @param[in] i_mode   (PM_INIT / PM_RESET)
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
///
    fapi2::ReturnCode p9_pm_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode);
}

#endif // _P9_PM_INIT_H
