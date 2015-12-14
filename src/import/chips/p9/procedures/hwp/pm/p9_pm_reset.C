/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_reset.C $                    */
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
/// @file p9_pm_reset.C
/// @brief Wrapper that calls underlying HWPs to perform a Power Management
///        Reset function when needing to restart the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner :
// *HWP FW Owner         : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 1
// *HWP Consumed by      : HS

///
/// High-level procedure flow:
///
/// \verbatim
///
///     do {
///         - Clear the Deep Exit Masks to allow Special Wake-up to occur
///         - Put all EX chiplets in special wakeup
///         - Mask the PM FIRs
///         - Disable PMC OCC HEARTBEAT before halting and reset OCC
///         - Halt and then Reset the PPC405
///             - PMC moves to Vsafe value due to heartbeat loss
///         - Force Vsafe value into voltage controller to cover the case that
///                 the Pstate hardware didn't move correctly
///         - Reset PCBS-PM
///         - Reset PMC
///             As the PMC reset kills ALL of the configuration, the idle
///             portion must be reestablished to allow that portion to operate.
///         - Run SLW Initialiation
///             - This allows special wake-up removal before exit
///         - Reset PSS
///         - Reset GPEs
///         - Reset PBA
///         - Reset SRAM Controller
///         - Reset OCB
///         - Clear special wakeups
///     } while(0);
///
///     if error, clear special wakeups to leave this procedure clean
///
///     SLW engine reset is not done here as this will blow away all setup
///     in istep 15.  Thus, ALL manipulation of this is via calls to
///     p8_poreslw_ioit or by p8_poreslw_recovery.
///
///  \endverbatim
///

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_reset.H>
#include <p9_pm_utils.H>

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Global variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

fapi2::ReturnCode special_wakeup_all(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_action);

fapi2::ReturnCode clear_deep_exit_mask(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_mode)
{
    FAPI_IMP("Entering...");

    FAPI_IMP("Exiting...");

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Sets or clears special wake-up on all configured EX on a target
///
/// @param[in] i_target Chip target
/// @param[in] i_action true - ENABLE; false - DISABLE
///
/// @return FAPI2_RC_SUCCESS If the special wake-up is successful,
///         else error code.
///
fapi2::ReturnCode special_wakeup_all(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_action)
{
    FAPI_INF("special_wakeup_all Enter");

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Clear deep exit mask
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode clear_deep_exit_mask(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("clear_deep_exit_mask Enter");

    return fapi2::FAPI2_RC_SUCCESS;
}
