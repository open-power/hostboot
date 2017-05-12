/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_pss_init.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// @file p9_pm_pss_init.H
/// @brief Initializes P2S and HWC logic
///
// *HWP HW Owner        :   Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    :   Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   3
// *HWP Consumed by     :   HS

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

#ifndef _P9_PM_PSS_INIT_H_
#define _P9_PM_PSS_INIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>
#include <p9_misc_scom_addresses.H>

typedef fapi2::ReturnCode (*p9_pm_pss_init_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const p9pm::PM_FLOW_MODE);

extern "C"
{
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
///
/// @brief Calls the underlying routine based on mode parameter to initialize
///        the PSS macro or reset it or configure the required attributes
///
/// @param[in] i_target Chip target
/// @param[in] i_mode   Control mode for the procedure:
///                     PM_INIT, PM_RESET
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode p9_pm_pss_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode);
}
#endif // _P9_PM_PSS_INIT_H_
