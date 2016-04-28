/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_init.C $                     */
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
/// @file p9_pm_init.C
/// @brief Wrapper that calls underlying HWPs to perform a Power Management
///        init function when needing to initialize the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner :
// *HWP FW Owner         : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 1
// *HWP Consumed by      : HS

///
/// High-level procedure flow:
///
/// @verbatim
/// Invoke the sub-functions to initialize the OCC (GPEs, FIRs, PPM, PPC405)
/// for the first time during boot.
/// @endverbatim
///

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_init.H>

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Global variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_INF("Entering p9_pm_init ...");

    if (i_mode == p9pm::PM_INIT)
    {
        FAPI_DBG("Initialize the OCC Complex.");
    }
    else if (i_mode == p9pm::PM_RESET)
    {
        FAPI_DBG("Reset the OCC Complex.");
    }
    else
    {
        FAPI_ASSERT(false, fapi2::PM_INIT_BAD_MODE().set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to p9_pm_init. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_INF("Exiting p9_pm_init...");
    return fapi2::current_err;
}
