/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_pfet_control.C $  */
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
///
/// @file p9_pm_pfet_control.C
/// @brief Enable PFET devices to power on/off all enabled Core and Cache
/// chiplets in target passed.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 3
// *HWP Consumed by     : OCC:CME:FSP
//----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
// PFET Control
// Power-on via Hardare FSM:
// ------------------------
// VDD first, VCS second
// Read PFETCNTLSTAT_REG and check for bits 0:3 being 0b0000.
// Write PFETCNTLSTAT_REG with values defined below
// -vdd_pfet_force_state = 11 (Force Von)
// -vdd_pfet_val_override = 0 (Override disabled)
// -vdd_pfet_sel_override = 0 (Override disabled)
// -vdd_pfet_enable_regulation_finger = 0 (Regulation finger controlled by FSM)
// Poll for PFETCNTLSTAT_REG[VDD_PG_STATE] for 0b1000 (FSM idle)-Timeout value = 1ms
// (Optional) Check PFETCNTLSTAT_REG[VDD_PG_SEL]being 0x8 (Off encode point)
// Write PFETCNTLSTAT_REG_WCLEAR
// -vdd_pfet_force_state = 00 (No Operation);all fields set to 1 for WAND
// Write PFETCNTLSTAT_REG_OR with values defined below
// -vcs_pfet_force_state = 11 (Force Von)
// Write to PFETCNTLSTAT_REG_CLR
// -vcs_pfet_val_override = 0 (Override disabled)
// -vcs_pfet_sel_override = 0 (Override disabled)
// Note there is no vcs_pfet_enable_regulation_finger
// Poll for PFETCNTLSTAT_REG[VCS_PG_STATE] for 0b1000 (FSM idle)-Timeout value = 1ms
// (Optional) Check PFETCNTLSTAT_REG[VCS_PG_SEL] being 0x8 (Off encode point)
// Write PFETCNTLSTAT_REG_WCLEAR
// -vcs_pfet_force_state = 00 (No Operation);all fields set to 1 for WAND
//
// Power-off via Hardare FSM:
// -------------------------
// VCS first, VDD second
// Read PFETCNTLSTAT_REG and check for bits 0:3 being 0b0000.
// Write PFETCNTLSTAT_REG with values defined below
// -vcs_pfet_force_state = 01 (Force Voff)
// -vcs_pfet_val_override = 0 (Override disabled)
// -vcs_pfet_sel_override = 0 (Override disabled)
// Note there is no vcs_pfet_enable_regulation_finger
// Poll for PFETCNTLSTAT_REG[VCS_PG_STATE] for 0b1000 (FSM idle)-Timeout value = 1ms
// (Optional) Check PFETCNTLSTAT_REG[VCS_PG_SEL]being 0x8 (Off encode point)
// Write PFETCNTLSTAT_REG_WCLEAR
// -vcs_pfet_force_state = 00 (No Operation);all fields set to 1 for WAND
// Write PFETCNTLSTAT_REG_OR with values defined below
// -vdd_pfet_force_state = 01 (Force Voff)
// Write to PFETCNTLSTAT_REG_CLR
// -vdd_pfet_val_override = 0 (Override disabled)
// -vdd_pfet_sel_override = 0 (Override disabled)
// -vdd_pfet_enable_regulation_finger = 0 (Regulation finger controlled by FSM)
// Poll for PFETCNTLSTAT_REG[VDD_PG_STATE] for 0b1000 (FSM idle)-Timeout value = 1ms
// (Optional) Check PFETCNTLSTAT_REG[VDD_PG_SEL] being 0x8 (Off encode point)
// Write PFETCNTLSTAT_REG_WCLEAR
// -vdd_pfet_force_state = 00 (No Operation);all fields set to 1 for WAND
//
// NOTE:
// For EQ supports: VDD,VCS,BOTH
// For EC & EX supports: VDD only. VCS returns an error. BOTH reports a warning that only VDD was controlled.
// EX target only powers OFF the two cores associated with that 'half' of the quad.
//
// Procedure Prereq:
//    - System clocks are running
//
// @endverbatim
//------------------------------------------------------------------------------

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_common_poweronoff.H>
#include <p9_pm_pfet_control.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variables
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Enable power on/off for core and cache chiplets
///
/// @param [in]  i_target          Target type Core/EQ/Ex chiplet
/// @param [in]  i_rail            Valid rail options:BOTH/VDD/VCS
/// @param [in]  i_op              Valid options:OFF/ON
///
/// @return FAPI2_RC_SUCCESS on success, error otherwise.
///
template <fapi2::TargetType K >
static fapi2::ReturnCode pfet_ctrl(
    const fapi2::Target< K >&  i_target,
    const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
    const PM_PFET_TYPE_C::pfet_force_t i_op);


// Procedure pfet control-EQ entry point, comments in header
fapi2::ReturnCode p9_pm_pfet_control_eq(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
    const PM_PFET_TYPE_C::pfet_force_t i_op)
{
    fapi2::current_err     = fapi2::FAPI2_RC_SUCCESS;
    bool core_target_found = false;

    FAPI_INF("p9_pm_pfet_control_eq: Entering...");

    // Print chiplet position
    FAPI_INF("pfet control for EQ chiplet %d", i_target.getChipletNumber());

    // When i_op == OFF all functional cores first followed by EQ
    // When i_op == ON EQ first followed by all functional cores
    if(i_op == PM_PFET_TYPE_C::ON)
    {
        FAPI_TRY(pfet_ctrl<fapi2::TargetType::TARGET_TYPE_EQ>(i_target,
                 i_rail, i_op), "Error: pfet_ctrl for eq!!");
    }

    // Check for all core chiplets in EQ and power on/off targets accordingly
    for (auto& l_core_target : i_target.getChildren<fapi2::TARGET_TYPE_CORE>
         (fapi2::TARGET_STATE_FUNCTIONAL))
    {
        FAPI_INF("Core chiplet %d in EQ", l_core_target.getChipletNumber());
        FAPI_TRY(pfet_ctrl<fapi2::TargetType::TARGET_TYPE_CORE>(l_core_target,
                 i_rail, i_op), "Error: pfet_ctrl for core!!");
        core_target_found = true;
    }

    // Power on/off EQ target
    if( (i_op == PM_PFET_TYPE_C::OFF) && (core_target_found) )
    {
        FAPI_TRY(pfet_ctrl<fapi2::TargetType::TARGET_TYPE_EQ>(i_target,
                 i_rail, i_op), "Error: pfet_ctrl for eq!!");
    }
    else if( ((i_op == PM_PFET_TYPE_C::ON) && !(core_target_found)) ||
             ((i_op == PM_PFET_TYPE_C::OFF) && !(core_target_found)) )
    {
        FAPI_INF("EQ chiplet no. %d; No core target found in functional state in this EQ\n", i_target.getChipletNumber());
    }

    FAPI_INF("p9_pm_pfet_control_eq: ...Exiting");

fapi_try_exit:
    return fapi2::current_err;
} //p9_pm_pfet_control_eq


// Procedure pfet control-EX entry point, comments in header
fapi2::ReturnCode p9_pm_pfet_control_ex(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
    const PM_PFET_TYPE_C::pfet_force_t i_op)
{
    fapi2::current_err     = fapi2::FAPI2_RC_SUCCESS;
    bool core_target_found = false;

    FAPI_INF("p9_pm_pfet_control_ex: Entering...");

    // Get chiplet position
    FAPI_INF("pfet control for EX chiplet %d", i_target.getChipletNumber());

    // Check for all core chiplets in EX and power on/off targets accordingly
    for (auto& l_core_target : i_target.getChildren<fapi2::TARGET_TYPE_CORE>
         (fapi2::TARGET_STATE_FUNCTIONAL))
    {
        FAPI_INF("Core chiplet %d in EX", l_core_target.getChipletNumber());
        FAPI_TRY(pfet_ctrl<fapi2::TargetType::TARGET_TYPE_CORE>(l_core_target,
                 i_rail, i_op), "Error: pfet_ctrl for core!!");
        core_target_found = true;
    }

    // When no functional chiplet target found
    if(!core_target_found)
    {
        FAPI_INF("EX chiplet no. %d; No core target found in functional state"
                 " in this EX", i_target.getChipletNumber());
    }

    FAPI_INF("p9_pm_pfet_control_ex: ...Exiting");

fapi_try_exit:
    return fapi2::current_err;
} //p9_pm_pfet_control_ex


// Procedure pfet control-Core entry point, comments in header
fapi2::ReturnCode p9_pm_pfet_control_ec(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
    const PM_PFET_TYPE_C::pfet_force_t i_op)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF("p9_pm_pfet_control_core: Entering...");

    FAPI_TRY(pfet_ctrl<fapi2::TargetType::TARGET_TYPE_CORE>(i_target,
             i_rail, i_op), "Error: pfet_ctrl for core!!");

    FAPI_INF("p9_pm_pfet_control_core: ...Exiting");

fapi_try_exit:
    return fapi2::current_err;
} //p9_pm_pfet_control_ec


//------------------------------------------------------------------------------
// pfet_ctrl:
//  Function to power on/off core and cache chiplets
//------------------------------------------------------------------------------
template <fapi2::TargetType K >
fapi2::ReturnCode pfet_ctrl(
    const fapi2::Target< K >&  i_target,
    const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
    const PM_PFET_TYPE_C::pfet_force_t i_op)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF("pfet_ctrl: Entering...");

    // Check for target passed
    if(i_target.getType() & fapi2::TARGET_TYPE_CORE)
    {
        FAPI_INF("pfet control for Core chiplet %d",
                 i_target.getChipletNumber());
    }
    else if(i_target.getType() & fapi2::TARGET_TYPE_EQ)
    {
        FAPI_INF("pfet control for EQ chiplet %d", i_target.getChipletNumber());
    }
    else
    {
        // Invalid chiplet selected
        FAPI_ASSERT(false,
                    fapi2::PFET_CTRL_INVALID_CHIPLET_ERROR()
                    .set_TARGET(i_target),
                    "ERROR: Invalid chiplet selected");
    }

    switch(i_op)
    {
        case PM_PFET_TYPE_C::OFF:
            switch(i_rail)
            {
                case PM_PFET_TYPE_C::BOTH:
                    if(i_target.getType() & fapi2::TARGET_TYPE_EQ)
                    {
                        FAPI_TRY(p9_common_poweronoff(i_target, p9power::POWER_OFF));
                    }
                    else
                    {
                        FAPI_IMP("WARNING:Only VDD (not BOTH/VCS) is controlled for target Core & EX");
                        FAPI_TRY(p9_common_poweronoff(i_target, p9power::POWER_OFF_VDD));
                    }

                    break;

                case PM_PFET_TYPE_C::VDD:
                    FAPI_TRY(p9_common_poweronoff(i_target, p9power::POWER_OFF_VDD));
                    break;

                case PM_PFET_TYPE_C::VCS:
                    FAPI_IMP("WARNING:Only VDD or both VDD/VCS controlled for target Core/EX & Cache respectively");
                    break;
            }

            break;

        case PM_PFET_TYPE_C::ON:
            switch(i_rail)
            {
                case PM_PFET_TYPE_C::BOTH:
                    if(i_target.getType() & fapi2::TARGET_TYPE_EQ)
                    {
                        FAPI_TRY(p9_common_poweronoff(i_target, p9power::POWER_ON));
                    }
                    else
                    {
                        FAPI_IMP("WARNING:Only VDD (not BOTH/VCS) is controlled for target Core & EX");
                        FAPI_TRY(p9_common_poweronoff(i_target, p9power::POWER_ON_VDD));
                    }

                    break;

                case PM_PFET_TYPE_C::VDD:
                    FAPI_TRY(p9_common_poweronoff(i_target, p9power::POWER_ON_VDD));
                    break;

                case PM_PFET_TYPE_C::VCS:
                    FAPI_IMP("WARNING:Only VDD or both VDD/VCS controlled for target Core/EX & Cache respectively");
                    break;
            }

            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}


