/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_occ_gpe_init.H $             */
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
/// @file p9_pm_occ_gpe_init.H
/// @brief Initialize or reset the targeted GPE0 and/or GPE1
///
/// *HWP HWP Owner: Greg Still  <stillgs@us.ibm.com>
/// *HWP FW  Owner: Sangeetha T S <sangeet2@in.ibm.com>
/// *HWP Team: PM
/// *HWP Level: 2
/// *HWP Consumed by: HS
///

#ifndef _P9_PM_OCC_GPE_INIT_H
#define _P9_PM_OCC_GPE_INIT_H

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>
#include <p9_misc_scom_addresses.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
namespace p9occgpe
{
enum GPE_ENGINES
{
    GPE0        = 0x0,
    GPE1        = 0x1,
    GPEALL      = 0XF
};
}

//------------------------------------------------------------------------------
// Parameter structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_occ_gpe_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE,
    const p9occgpe::GPE_ENGINES);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/// @brief Configure or reset the targeted GPE0 and/or GPE1
///
/// param[in] i_target   Chip target
/// param[in] i_mode     Control mode for the procedure (PM_INIT, PM_RESET)
/// param[in] i_engine   Targeted engine:  GPE0, GPE1, GPEALL

/// @return FAPI2_RC_SUCCESS in case of success
///         error code otherwise

    fapi2::ReturnCode
    p9_pm_occ_gpe_init(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                       const p9pm::PM_FLOW_MODE i_mode,
                       const p9occgpe::GPE_ENGINES i_engine);
} //extern "C"
#endif // P9_PM_OCC_GPE_INIT_H
