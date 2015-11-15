/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_pss_init.C $                */
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
/// @file p9_pm_pss_init.C
/// @brief Initializes P2S and HWC logic
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS

///
/// Procedure Summary:
/// --------------------
///    One procedure to initialize both P2S and HWC SPIPSS registers to
///    second Procedure is to access APSS or DPSS through P2S Bridge
///    Third procedure is to access APSS or DPSS through HWC (hardware control)
///
///    High-level procedure flow:
///     ----------------------------------
///      o INIT PROCEDURE(frame_size,cpol,cpha)
///         - set SPIPSS_ADC_CTRL_REG0(24b)
///             hwctrl_frame_size = 16
///         - set SPIPSS_ADC_CTRL_REG1
///             hwctrl_fsm_enable = disable
///             hwctrl_device     = APSS
///             hwctrl_cpol       = 0 (set idle state = deasserted)
///             hwctrl_cpha       = 0 (set 1st edge = capture 2nd edge = change)
///             hwctrl_clock_divider = set to 10Mhz(0x1D)
///             hwctrl_nr_of_frames (4b) = 16 (for auto 2 mode)
///         - set SPIPSS_ADC_CTRL_REG2
///                      hwctrl_interframe_delay = 0x0
///              - clear SPIPSS_ADC_WDATA_REG
///         - set SPIPSS_P2S_CTRL_REG0 (24b)
///             p2s_frame_size  = 16
///         - set SPIPSS_P2S_CTRL_REG1
///             p2s_bridge_enable = disable
///             p2s_device        = DPSS
///             p2s_cpol          = 0
///             p2s_cpha          = 0
///             p2s_clock_divider = set to 10Mhz
///             p2s_nr_of_frames (1b) = 0 (means 1 frame operation)
///         - set SPIPSS_P2S_CTRL_REG2
///                      p2s_interframe_delay = 0x0
///              - clear SPIPSS_P2S_WDATA_REG
/// Procedure Prereq:
///   o System clocks are running
///


// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_pss_init.H>


// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Determines the configuration setting for the SPI bus based on
///        attributes
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_pss_config_spi_settings(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

//------------------------------------------------------------------------------
///
/// @brief Using configured attributed, performs the initialization of the PSS
///        function
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_pss_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

//------------------------------------------------------------------------------
///
/// @brief Performs the reset of the PSS function
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_pss_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_pss_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{

    FAPI_IMP("p9_pm_pss_init Enter");

    FAPI_IMP("p9_pm_pss_init Exit");
    return fapi2::current_err;

}


fapi2::ReturnCode pm_pss_config_spi_settings(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    FAPI_IMP("pm_pss_config_spi_settings Enter");
    return fapi2::current_err;

}


fapi2::ReturnCode pm_pss_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    FAPI_IMP("pm_pss_init Enter");
    return fapi2::current_err;

}


fapi2::ReturnCode pm_pss_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    FAPI_IMP("pm_pss_reset Enter");
    return fapi2::current_err;

}
