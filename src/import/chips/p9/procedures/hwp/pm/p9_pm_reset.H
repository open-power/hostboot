/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_reset.H $                    */
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
/// @file p9_pm_reset.H
/// @brief Wrapper that calls underlying HWPs to perform a Power Management
///        Reset function when needing to restart the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner :
// *HWP FW Owner         : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 2
// *HWP Consumed by      : HS

#ifndef _P9_PM_RESET_H
#define _P9_PM_RESET_H

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>
#include <p9_pm_utils.H>
#include <p9_misc_scom_addresses.H>
#include <p9_pm_firinit.H>
#include <p9_pm_occ_control.H>
#include <p9_cpu_special_wakeup.H>
#include <p9_pm_stop_gpe_init.H>
#include <p9_pm_occ_gpe_init.H>
#include <p9_pm_corequad_init.H>
#include <p9_pm_pba_init.H>
#include <p9_pm_occ_sram_init.H>
#include <p9_pm_ocb_init.H>
#include <p9_pm_pss_init.H>

typedef fapi2::ReturnCode (*p9_pm_reset_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

// -----------------------------------------------------------------------------
// Function Prototype
// -----------------------------------------------------------------------------
extern "C"
{
//------------------------------------------------------------------------------
///
/// @brief Call underlying unit procedures to reset PM complex
///
/// @param[in] i_target Proc Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
///
    fapi2::ReturnCode p9_pm_reset(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
}

#endif // _P9_PM_RESET_H
