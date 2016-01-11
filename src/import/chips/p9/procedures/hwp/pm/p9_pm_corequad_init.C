/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_corequad_init.C $            */
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
/// @file  p9_pm_corequad_init.C
/// @brief Establish safe settings for Core and Quad.
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: HS

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_corequad_init.H>

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

// Reset function
///
/// @brief Stop the CMEs and clear the CME FIRs, PPM Errors and their masks
///        for all functional and enabled EX chiplets
///
/// @param[in] i_target Proc Chip target
///
/// @return FAPI2_RC_SUCCESS on success or error return code
///
fapi2::ReturnCode pm_corequad_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// Init function
///
/// @brief Setup the CME and PPM Core & Quad for all functional and enabled
///        EX chiplets
///
/// @param[in] i_target Proc Chip target
///
/// @return FAPI2_RC_SUCCESS on success or error return code
///
fapi2::ReturnCode pm_corequad_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p9_pm_corequad_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("Entering p9_pm_corequad_init...");

    FAPI_IMP("Exiting p9_pm_corequad_init...");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_corequad_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("Entering pm_corequad_init...");

    return fapi2::current_err;
}

fapi2::ReturnCode pm_corequad_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("Entering pm_corequad_reset...");

    return fapi2::current_err;
}

