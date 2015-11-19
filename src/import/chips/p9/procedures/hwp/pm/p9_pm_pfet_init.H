/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_pfet_init.H $                */
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
/// @file  p9_pm_pfet_init.H
/// @brief Initialization and reset the EC/EQ chiplet PFET controller

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS

#ifndef _P9_PFET_INIT_H_
#define _P9_PFET_INIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>

#include "p9_quad_scom_addresses.H"

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_pfet_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE);

extern "C"
{
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \param[in] i_target  Chip target
/// \param[in] i_mode    Control mode (PM_INIT, PM_RESET)

/// \retval FAPI_RC_SUCCESS if something good happens,
/// \retval RC per p9_pfet_init_errors.xml otherwise
    fapi2::ReturnCode p9_pm_pfet_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode);

} // extern "C"

#endif // _P9_PFET_INIT_H_
