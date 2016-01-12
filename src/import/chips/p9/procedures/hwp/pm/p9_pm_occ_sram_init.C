/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_occ_sram_init.C $            */
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
/// @file  p9_pm_occ_sram_init.C
/// @brief Initialize the SRAM in the OCC
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS
//

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_occ_sram_init.H>

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_occ_sram_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_INF("Entering p9_pm_occ_sram_init...");

    // Initialization:  perform order or dynamic operations to initialize
    // the OCC SRAM using necessary Platform or Feature attributes.
    if (i_mode == p9pm::PM_INIT)
    {
        FAPI_INF("OCC SRAM initialization...");
    }
    // Reset:  perform reset of OCC SRAM so that it can reconfigured and
    // reinitialized
    else if (i_mode == p9pm::PM_RESET)
    {
        FAPI_INF("OCC SRAM reset...");
    }
    // Unsupported Mode
    else
    {
        FAPI_ASSERT(false, fapi2::PM_OCCSRAM_BAD_MODE().set_MODE(i_mode),
                    "ERROR; Unknown mode passed to p9_pm_occ_sram_init. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    return fapi2::current_err;
}
