/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_pfet_init.C $                */
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
/* IBM_PROLOG_END_TAG                                                                                                         */
///
/// @file p9_pfet_init.C
/// @brief  Initialization and reset the EC/EQ chiplet PFET controller
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS
///
/// High-level procedure flow:
/// \verbatim
///
///     Check for valid parameters
///     if PM_INIT {
///         Get the delay setting held in platform attributes
///         Convert these to hardware values
///         for each EX chiplet {
///             Store the VDD delay and VOFF value
///             Store the VCS delay and VOFF values
///         }
///     } else if PM_RESET {
///         for each EX chiplet {
///             Reset the VDD delay and VOFF values to 0
///             Reore the VCS delay and VOFF values to 0
///     }
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "p9_pm_pfet_init.H"

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

/// \param[in] i_target  Chip target
/// \param[in] i_mode    Control mode (PM_INIT, PM_RESET)
///
/// \retval FAPI_RC_SUCCESS if something good happens,
/// \retval RC per p9_pfet_init_errors.xml otherwise
///
/// \attr  ATTR_PM_PFET_POWERUP_DELAY_NS -
///     Time (in nanoseconds) between PFET controller steps (7 of them)
///     when turning the PFES ON. Applies to both VDD and VCS rails
///
/// \attr  ATTR_PM_PFET_POWERDOWN_DELAY_NS -
///     Time (in nanoseconds) between PFET controller steps (7 of them)
///     when turning the PFES OFF.  Applies to both VDD and VCS rails
///
/// \attr  ATTR_PM_PFET_VDD_VOFF_SEL -
///     Value of the stage withing the PFET controller representing OFF
///     for the VDD rail.  Enum: 0 through 8 inclusive
///
/// \attr  ATTR_PM_PFET_VCS_VOFF_SEL -
///     Value of the stage withing the PFET controller representing OFF
///     for the VCS rail.  Enum: 0 through 8 inclusive

fapi2::ReturnCode p9_pm_pfet_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p9_pm_pfet_init start");

    // Loop over configured cache chiplets

    // Establish the VDD and VCS VOff Select Setting

    // Write the Power Up and Down Delays

    // Loop over configured core chiplets

    // Establish the VDD and VCS VOff Select Setting

    // Write the Power Up and Down Delays


    FAPI_INF("p9_pm_pfet_init end");
    return fapi2::FAPI2_RC_SUCCESS;
}


