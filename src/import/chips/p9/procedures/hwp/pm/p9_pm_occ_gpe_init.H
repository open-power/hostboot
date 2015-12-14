/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_occ_gpe_init.H $             */
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
/// @file p9_pm_occ_gpe_init.H
/// @brief Configure or reset the targeted GPE0 and/or GPE1
///
/// *HWP HWP Owner: Greg Still  <stillgs@us.ibm.com>
/// *HWP FW  Owner: Sunil Kumar <skumar8j@in.ibm.com>
/// *HWP Team: PM
/// *HWP Level: 1
/// *HWP Consumed by: HS
///

#ifndef _P9_PM_OCC_GPE_INIT_H
#define _P9_PM_OCC_GPE_INIT_H

#include <fapi2.H>
#include <p9_pm.H>

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Parameter structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_occ_gpe_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::P9_PM_FLOW_MODE,
    const uint32_t);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/// @brief Configure or reset the targeted GPE0 and/or GPE1
///
/// param[in] i_target   Chip target
/// param[in] i_mode     Control mode for the procedure (PM_CONFIG, PM_RESET)
/// param[in] i_engine   Targeted engine:  GPE0, GPE1, GPEALL

/// @return FAPI2_RC_SUCCESS in case of success
///         error code otherwise

    fapi2::ReturnCode
    p9_pm_occ_gpe_init(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                       const p9pm::P9_PM_FLOW_MODE i_mode, const uint32_t i_engine);
} //extern "C"
#endif // P9_PM_OCC_GPE_INIT_H
