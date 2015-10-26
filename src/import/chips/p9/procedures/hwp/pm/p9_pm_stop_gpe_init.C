/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_ocb_indir_access.C $        */
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
/// @file p9_pm_stop_gpe_init.C
/// @brief Initialize the Stop GPE and related functions

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS

///
/// High-level procedure flow:
/// @verbatim
///   if PM_RESET
///   - Halt the SGPE
///   if PM_INIT
///Å  - Sets the IAR to the SGPE bootloader in HOMER.
///Å    - HOMER base (PBABAR0 + 1MB) + 16B
///Å  - Starts the SGPE and polls OCC Flag bit for HCode init completion
///Å    - Starting the SGPE will cause a "reboot" of functional CMEs
///Å  - SGPE will cause Block Copy Engine to pull CPMR code, common rings
///     and Core Pstate Parameter Block into CME SRAM
///Å  - SGPE checks that CME STOP functions have started as part of the
///     HCode init complete
/// @endverbatim

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------

#include "p9_pm_stop_gpe_init.H"


// This will be uncommented upon the formal availabilty
//#include "p9_cpu_special_wakeup.H"
//#include "p9_pm_pfet_init.H"


// -----------------------------------------------------------------------------
//  Function prototypes
// -----------------------------------------------------------------------------

fapi2::ReturnCode stop_gpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode stop_gpe_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode stop_corecache_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

/// @brief Initialize the Stop GPE and related functions
///
/// @param [in] i_target Chip target
/// @param [in] i_mode   Control mode for the procedure
///                      PM_INIT, PM_RESET
///
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml

fapi2::ReturnCode p9_pm_stop_gpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p9_pm_stop_gpe_init start");
#if 0

    const char*         PM_MODE_NAME_VAR; /// Defines storage for PM_MODE_NAME

    FAPI_INF("Executing p9_stop_gpe_init in mode %s", PM_MODE_NAME(i_mode));


    // -------------------------------
    // Initialization:  perform order or dynamic operations to initialize
    // the SLW using necessary Platform or Feature attributes.
    if (i_mode == PM_INIT)
    {
        rc = stop_gpe_init(i_target, i_mode);
    }

    //-------------------------------
    // Reset:  perform reset of SLW engine so that it can reconfigured and
    // reinitialized
    else if (i_mode == PM_RESET)
    {
        rc = stop_gpe_reset(i_target);
    }

    // -------------------------------
    // Unsupported Mode
    else
    {

        FAPI_ERR("Unknown mode passed to p9_stop_gpe_init. Mode %x ....", i_mode);
        uint32_t& IMODE = i_mode;
        FAPI_SET_HWP_ERROR(rc, RC_PROCPM_STOP_GPE_CODE_BAD_MODE);

    }

#endif
    FAPI_INF("p9_pm_stop_gpe_init end");
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//  STOP GPE Initialization Function
// -----------------------------------------------------------------------------

/// @brief Initializes the STOP GPE and related STOP functions on a chip
///
/// @param [in] i_target Chip target
///
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml

fapi2::ReturnCode stop_gpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_mode)
{

    FAPI_INF("STOP initialization...");


    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//  Stop GPE Function
// -----------------------------------------------------------------------------

/// @brief Stops the Stop GPE
///
/// @param [in] i_target Chip target
///
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml

fapi2::ReturnCode stop_gpe_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    FAPI_INF("STOP reset...");

    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
// EX Stop Setup Function
//  Note:   PMGP0 and OCC Special Wakeup actions could be done with multicast in
//          the future.
// -----------------------------------------------------------------------------

// @brief Resets the STOP function for each Core and Cache chiplet
//
// @param [in] i_target Chip target
//
// @retval FAPI_RC_SUCCESS
// @retval ERROR defined in xml

fapi2::ReturnCode stop_corecache_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    FAPI_INF("Executing stop_corecache_setup...");

    return fapi2::current_err;
}
