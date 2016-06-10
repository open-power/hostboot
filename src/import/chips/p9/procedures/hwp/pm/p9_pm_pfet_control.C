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
// *HWP Level           : 2
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
// @TODO:RTC:157109
// @endverbatim
//------------------------------------------------------------------------------

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm_pfet_control.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variables
//------------------------------------------------------------------------------

enum pfetRegField
{
    PFET_NOP           = 0,
    PFET_FORCE_VOFF    = 1,
    PFET_NOP_RESERVERD = 2,
    PFET_FORCE_VON     = 3
};

enum PFCS_Bits
{
    VDD_PFET_FORCE_STATE_BIT             = 0,
    VCS_PFET_FORCE_STATE_BIT             = 2,
    VDD_PFET_VAL_OVERRIDE_BIT            = 4,
    VDD_PFET_SEL_OVERRIDE_BIT            = 5,
    VCS_PFET_VAL_OVERRIDE_BIT            = 6,
    VCS_PFET_SEL_OVERRIDE_BIT            = 7,
    VDD_PFET_REGULATION_FINGER_EN_BIT    = 8,
    VDD_PFET_REGULATION_FINGER_VALUE_BIT = 9,
    RESERVED1_BIT                        = 10,
    VDD_PFET_ENABLE_VALUE_BIT            = 12,
    VDD_PFET_SEL_VALUE_BIT               = 20,
    VCS_PFET_ENABLE_VALUE_BIT            = 24,
    VCS_PFET_SEL_VALUE_BIT               = 32,
    RESERVED2_BIT                        = 36,
    VDD_PG_STATE_BIT                     = 42,
    VDD_PG_SEL_BIT                       = 46,
    VCS_PG_STATE_BIT                     = 50,
    VCS_PG_SEL_BIT                       = 54,
    RESERVED3_BIT                        = 58
};


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

///
/// @brief Enable power on/off for core and cache chiplets-VDD
///
/// @param [in]  i_target          Target type Core/EQ/Ex chiplet
/// @param [in]  i_op              Valid options:OFF/ON
/// @param [in]  i_PPM_PFCS_RW     Register offset for target type Core/EQ/EX
/// @param [in]  i_PPM_PFCS_CLR    Register offset for target type Core/EQ/EX
/// @param [in]  i_PPM_PFCS_OR     Register offset for target type Core/EQ/EX
///
/// @return FAPI2_RC_SUCCESS on success, error otherwise.
///
template <fapi2::TargetType K >
fapi2::ReturnCode pfet_ctrl_vdd(
    const fapi2::Target< K >&  i_target,
    const PM_PFET_TYPE_C::pfet_force_t  i_op,
    const uint64_t i_PPM_PFCS_RW,
    const uint64_t i_PPM_PFCS_CLR,
    const uint64_t i_PPM_PFCS_OR);

///
/// @brief Enable power on/off for core and cache chiplets-VCS
///
/// @param [in]  i_target          Target type Core/EQ/Ex chiplet
/// @param [in]  i_op              Valid options:OFF/ON
/// @param [in]  i_PPM_PFCS_RW     Register offset for target type Core/EQ/EX
/// @param [in]  i_PPM_PFCS_CLR    Register offset for target type Core/EQ/EX
/// @param [in]  i_PPM_PFCS_OR     Register offset for target type Core/EQ/EX
///
/// @return FAPI2_RC_SUCCESS on success, error otherwise.
///
template <fapi2::TargetType K >
fapi2::ReturnCode pfet_ctrl_vcs(
    const fapi2::Target< K >&  i_target,
    const PM_PFET_TYPE_C::pfet_force_t  i_op,
    const uint64_t i_PPM_PFCS_RW,
    const uint64_t i_PPM_PFCS_CLR,
    const uint64_t i_PPM_PFCS_OR);


// Procedure pfet control-EQ entry point, comments in header
fapi2::ReturnCode p9_pm_pfet_control_eq(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
    const PM_PFET_TYPE_C::pfet_force_t i_op)
{
    fapi2::current_err     = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_unit_pos     = 0;
    bool core_target_found = false;

    FAPI_INF("p9_pm_pfet_control_eq: Entering...");

    // Get chiplet position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_unit_pos));
    FAPI_INF("pfet control for EQ chiplet %d", l_unit_pos);

    // When i_op == OFF all functional cores first followed by EQ
    // When i_op ==  ON EQ first followed by all functional cores
    if(i_op == PM_PFET_TYPE_C::ON)
    {
        FAPI_TRY(pfet_ctrl<fapi2::TargetType::TARGET_TYPE_EQ>(i_target,
                 i_rail, i_op), "Error: pfet_ctrl for eq!!");
    }

    // Check for all core chiplets in EQ and power on/off targets accordingly
    for (auto l_core_target : i_target.getChildren<fapi2::TARGET_TYPE_CORE>
         (fapi2::TARGET_STATE_FUNCTIONAL))
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core_target, l_unit_pos));
        FAPI_INF("Core chiplet %d in EQ", l_unit_pos);
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
        FAPI_INF("EQ chiplet no. %d; No core target found in functional state in this EQ\n", l_unit_pos);
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
    uint8_t l_unit_pos     = 0;
    bool core_target_found = false;

    FAPI_INF("p9_pm_pfet_control_ex: Entering...");

    // Get chiplet position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_unit_pos));
    FAPI_INF("pfet control for EX chiplet %d", l_unit_pos);

    // Check for all core chiplets in EX and power on/off targets accordingly
    for (auto l_core_target : i_target.getChildren<fapi2::TARGET_TYPE_CORE>
         (fapi2::TARGET_STATE_FUNCTIONAL))
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core_target, l_unit_pos));
        FAPI_INF("Core chiplet %d in EX", l_unit_pos);
        FAPI_TRY(pfet_ctrl<fapi2::TargetType::TARGET_TYPE_CORE>(l_core_target,
                 i_rail, i_op), "Error: pfet_ctrl for core!!");
        core_target_found = true;
    }

    // When no functional chiplet target found
    if(!core_target_found)
    {
        FAPI_INF("EX chiplet no. %d; No core target found in functional state in this EX\n", l_unit_pos);
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
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_temp64;

    uint8_t l_unit_pos     = 0;
    uint8_t VDD_VCS_PFET_FORCE_STATE_BITS_0_3 = VDD_PFET_FORCE_STATE_BIT;

    // Registers used to perform power on/off to core & cache chiplets
    // PPM PFETCNTLSTAT REG
    uint64_t PPM_PFCS_RW = 0;
    uint64_t PPM_PFCS_CLR = 0;
    uint64_t PPM_PFCS_OR = 0;

    FAPI_INF("pfet_ctrl: Entering...");

    // Get chiplet position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_unit_pos));

    // Check for target passed
    if(i_target.getType() & fapi2::TARGET_TYPE_CORE)
    {
        FAPI_INF("pfet control for Core chiplet %d", l_unit_pos);
        PPM_PFCS_RW = C_PPM_PFCS_SCOM;    //PPM_PFCS_RW
        PPM_PFCS_CLR = C_PPM_PFCS_SCOM1;  //PPM_PFCS_CLR
        PPM_PFCS_OR = C_PPM_PFCS_SCOM2;   //PPM_PFCS_OR
    }
    else if(i_target.getType() & fapi2::TARGET_TYPE_EQ)
    {
        FAPI_INF("pfet control for EQ chiplet %d", l_unit_pos);
        PPM_PFCS_RW = EQ_PPM_PFCS_SCOM;
        PPM_PFCS_CLR = EQ_PPM_PFCS_SCOM1;
        PPM_PFCS_OR = EQ_PPM_PFCS_SCOM2;
    }
    else if(i_target.getType() & fapi2::TARGET_TYPE_EX)
    {
        FAPI_INF("pfet control for EX chiplet %d", l_unit_pos);
        PPM_PFCS_RW = EX_PPM_PFCS_SCOM;
        PPM_PFCS_CLR = EX_PPM_PFCS_SCOM1;
        PPM_PFCS_OR = EX_PPM_PFCS_SCOM2;
    }
    else
    {
        // Invalid chiplet selected
        FAPI_ASSERT(false,
                    fapi2::PFET_CTRL_INVALID_CHIPLET_ERROR()
                    .set_TARGET(i_target),
                    "ERROR: Invalid chiplet selected. Target:%x", i_target);
    }

    // Check for PFET hardware FSM
    // Read PFETCNTLSTAT_REG and check for bits [0:3]=0b0000
    FAPI_DBG("Make sure that we are not forcing PFET for VCS or VDD off");
    FAPI_TRY(fapi2::getScom(i_target, PPM_PFCS_RW, l_data64),
             "Failed to read PPM_PFCS_RW");

    l_data64.extractToRight(l_temp64, VDD_VCS_PFET_FORCE_STATE_BITS_0_3, 4);

    FAPI_ASSERT(l_temp64 == 0,
                fapi2::PFET_FORCE_STATE_NOT_ZERO_ERROR()
                .set_VALUE(l_temp64).set_TARGET(i_target),
                "ERROR: PFET force state not zero");

    switch(i_op)
    {
        case PM_PFET_TYPE_C::OFF:
            switch(i_rail)
            {
                case PM_PFET_TYPE_C::BOTH:
                case PM_PFET_TYPE_C::VCS:
                    if(( (i_rail == PM_PFET_TYPE_C::BOTH) && (i_target.getType() & fapi2::TARGET_TYPE_EQ) ) ||
                       ( (i_rail == PM_PFET_TYPE_C::VCS)  && (i_target.getType() & fapi2::TARGET_TYPE_EQ) ))
                    {
                        // VCS first, VDD second for BOTH rails power off
                        pfet_ctrl_vcs(i_target,
                                      i_op,
                                      PPM_PFCS_RW,
                                      PPM_PFCS_CLR,
                                      PPM_PFCS_OR);

                        if(i_rail == PM_PFET_TYPE_C::BOTH)
                        {
                            pfet_ctrl_vdd(i_target,
                                          i_op,
                                          PPM_PFCS_RW,
                                          PPM_PFCS_CLR,
                                          PPM_PFCS_OR);
                        }

                        break;
                    }
                    else
                    {
                        FAPI_IMP("WARNING:Only VDD (not BOTH/VCS) is controlled for target Core & EX");

                        if(i_rail == PM_PFET_TYPE_C::VCS)
                        {
                            break;
                        }
                    }

                case PM_PFET_TYPE_C::VDD:
                    pfet_ctrl_vdd(i_target,
                                  i_op,
                                  PPM_PFCS_RW,
                                  PPM_PFCS_CLR,
                                  PPM_PFCS_OR);

                    break;
            }

            break;

        case PM_PFET_TYPE_C::ON:
            if(i_target.getType() & fapi2::TARGET_TYPE_EX)
            {
                FAPI_IMP("WARNING:Target EX only power off the two cores associated with that 'half' of the quad");
                break;
            }

            switch(i_rail)
            {
                case PM_PFET_TYPE_C::BOTH:
                case PM_PFET_TYPE_C::VDD:
                    // VDD first, VCS second for BOTH rails power on
                    pfet_ctrl_vdd(i_target,
                                  i_op,
                                  PPM_PFCS_RW,
                                  PPM_PFCS_CLR,
                                  PPM_PFCS_OR);

                    if( (i_rail == PM_PFET_TYPE_C::BOTH) && (i_target.getType() & fapi2::TARGET_TYPE_EQ) )
                    {
                        pfet_ctrl_vcs(i_target,
                                      i_op,
                                      PPM_PFCS_RW,
                                      PPM_PFCS_CLR,
                                      PPM_PFCS_OR);
                    }

                    if(( (i_rail == PM_PFET_TYPE_C::BOTH) && (i_target.getType() & fapi2::TARGET_TYPE_CORE) ) ||
                       ( (i_rail == PM_PFET_TYPE_C::BOTH) && (i_target.getType() & fapi2::TARGET_TYPE_EX) ))
                    {
                        FAPI_IMP("WARNING:Only VDD (not BOTH/VCS) is controlled for target Core & EX");
                    }

                    break;

                case PM_PFET_TYPE_C::VCS:
                    if(i_target.getType() & fapi2::TARGET_TYPE_EQ)
                    {
                        pfet_ctrl_vcs(i_target,
                                      i_op,
                                      PPM_PFCS_RW,
                                      PPM_PFCS_CLR,
                                      PPM_PFCS_OR);
                    }
                    else
                    {
                        FAPI_IMP("WARNING:Only VDD (not BOTH/VCS) is controlled for target Core & EX");
                    }

                    break;
            }

            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// pfet_ctrl_vdd:
//  Function to power on/off core and cache chiplets
//------------------------------------------------------------------------------
template <fapi2::TargetType K >
fapi2::ReturnCode pfet_ctrl_vdd(
    const fapi2::Target< K >&  i_target,
    const PM_PFET_TYPE_C::pfet_force_t i_op,
    const uint64_t i_PPM_PFCS_RW,
    const uint64_t i_PPM_PFCS_CLR,
    const uint64_t i_PPM_PFCS_OR)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_temp64;

    uint16_t                 l_delayCnt = 10000;

    FAPI_INF("pfet_ctrl_vdd: Entering...");

    if(i_op == PM_PFET_TYPE_C::OFF)
    {
        // Clear VDD PFET stage select and value override bits
        FAPI_DBG("Clear VDD PFET stage select and value override bits");
        l_data64.flush<0>().
        setBit<VDD_PFET_FORCE_STATE_BIT, 2>().
        setBit<VDD_PFET_VAL_OVERRIDE_BIT>().
        setBit<VDD_PFET_SEL_OVERRIDE_BIT>().
        setBit<VDD_PFET_REGULATION_FINGER_EN_BIT>();

        FAPI_TRY(fapi2::putScom(i_target, i_PPM_PFCS_CLR, l_data64),
                 "putScom failed for address PPM_PFCS_CLR");

        FAPI_DBG("Force VDD off");
        l_data64.flush<0>().insertFromRight(PFET_FORCE_VOFF, VDD_PFET_FORCE_STATE_BIT, 2);
        FAPI_TRY(fapi2::putScom(i_target, i_PPM_PFCS_OR, l_data64),
                 "putScom failed for address PPM_PFCS_OR");
    }
    else
    {
        // Clear VDD PFET stage select and value override bits
        FAPI_DBG("Clear VDD PFET stage select and value override bits");
        l_data64.flush<0>().
        setBit<VDD_PFET_VAL_OVERRIDE_BIT>().
        setBit<VDD_PFET_SEL_OVERRIDE_BIT>().
        setBit<VDD_PFET_REGULATION_FINGER_EN_BIT>();

        FAPI_TRY(fapi2::putScom(i_target, i_PPM_PFCS_CLR, l_data64),
                 "putScom failed for address PPM_PFCS_CLR");

        FAPI_DBG("Force VDD on");
        l_data64.flush<0>().insertFromRight(PFET_FORCE_VON, VDD_PFET_FORCE_STATE_BIT, 2);
        FAPI_TRY(fapi2::putScom(i_target, i_PPM_PFCS_OR, l_data64),
                 "putScom failed for address PPM_PFCS_OR");
    }

    // Check for valid power on completion
    // Poll for PFETCNTLSTAT_REG[VDD_PG_STATE] for 0b1000 (FSM idle)
    // Timeout value = 1ms
    // Polling the register in the interval of 100us (max 100us*10=1ms)
    FAPI_DBG("Polling register in interval of 100us (max 100us*10=1ms) \
             for power gate sequencer state: FSM idle else timeout");

    do
    {
        fapi2::delay(PFET_DELAY, PFET_SIM_CYCLES_DELAY);

        FAPI_TRY(fapi2::getScom(i_target, i_PPM_PFCS_RW, l_data64),
                 "getScom failed for address PPM_PFCS_RW");
        l_data64.extractToRight(l_temp64, VDD_PG_STATE_BIT, 4);

        if(l_temp64 == 0x8)
        {
            break;
        }

        l_delayCnt--;
    }
    while(l_delayCnt > 0);

    FAPI_INF("Delay count: %d", l_delayCnt);

    FAPI_ASSERT(l_temp64 == 0x8,
                fapi2::PFET_CTRL_VDD_PG_STATE_TIMEOUT_ERROR()
                .set_VALUE(l_temp64).set_TARGET(i_target),
                "ERROR: VDD FSM idle timeout");

    // Optional check VDD_PG_SEL
    FAPI_DBG("Optionally checking for VDD_PG_SEL value");
    l_data64.extractToRight(l_temp64, VDD_PG_SEL_BIT, 4);
    FAPI_DBG("Value of VDD_PG_SEL: %0x", l_temp64);

    // Write PFETCNTLSTAT_REG_WCLEAR vdd_pfet_force_state = 00 (No Operation)
    FAPI_DBG("vdd_pfet_force_state = 00, or Idle");
    l_data64.flush<0>().setBit<VDD_PFET_FORCE_STATE_BIT, 2>();
    FAPI_TRY(fapi2::putScom(i_target, i_PPM_PFCS_CLR, l_data64),
             "putScom failed for address PPM_PFCS_CLR");

fapi_try_exit:
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// pfet_ctrl_vcs:
//  Function to power on/off core and cache chiplets
//------------------------------------------------------------------------------
template <fapi2::TargetType K >
fapi2::ReturnCode pfet_ctrl_vcs(
    const fapi2::Target< K >&  i_target,
    const PM_PFET_TYPE_C::pfet_force_t i_op,
    const uint64_t i_PPM_PFCS_RW,
    const uint64_t i_PPM_PFCS_CLR,
    const uint64_t i_PPM_PFCS_OR)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_temp64;

    uint16_t                 l_delayCnt = 10000;

    FAPI_INF("pfet_ctrl_vcs: Entering...");

    if(i_op == PM_PFET_TYPE_C::OFF)
    {
        // Clear VCS PFET stage select and value override bits
        FAPI_DBG("Clear VCS PFET stage select and value override bits");
        l_data64.flush<0>().
        setBit<VCS_PFET_FORCE_STATE_BIT, 2>().
        setBit<VCS_PFET_VAL_OVERRIDE_BIT>().
        setBit<VCS_PFET_SEL_OVERRIDE_BIT>();

        FAPI_TRY(fapi2::putScom(i_target, i_PPM_PFCS_CLR, l_data64),
                 "putScom failed for address PPM_PFCS_CLR");

        FAPI_DBG("Force VCS off");
        l_data64.flush<0>().insertFromRight(PFET_FORCE_VOFF, VCS_PFET_FORCE_STATE_BIT, 2);
        FAPI_TRY(fapi2::putScom(i_target, i_PPM_PFCS_OR, l_data64),
                 "putScom failed for address PPM_PFCS_OR");
    }
    else
    {
        // Clear VCS PFET stage select and value override bits
        FAPI_DBG("Clear VCS PFET stage select and value override bits");
        l_data64.flush<0>().
        setBit<VCS_PFET_VAL_OVERRIDE_BIT>().
        setBit<VCS_PFET_SEL_OVERRIDE_BIT>();

        FAPI_TRY(fapi2::putScom(i_target, i_PPM_PFCS_CLR, l_data64),
                 "putScom failed for address PPM_PFCS_CLR");

        FAPI_DBG("Force VCS on");
        l_data64.flush<0>().insertFromRight(PFET_FORCE_VON, VCS_PFET_FORCE_STATE_BIT, 2);
        FAPI_TRY(fapi2::putScom(i_target, i_PPM_PFCS_OR, l_data64),
                 "putScom failed for address PPM_PFCS_OR");
    }

    // Check for valid power on completion
    // Poll for PFETCNTLSTAT_REG[VCS_PG_STATE] for 0b1000 (FSM idle)
    // Timeout value = 1ms
    // Polling the register in the interval of 100us (max 100us*10=1ms)
    FAPI_DBG("Polling register in interval of 100us (max 100us*10=1ms) \
             for power gate sequencer state: FSM idle else timeout");

    do
    {
        fapi2::delay(PFET_DELAY, PFET_SIM_CYCLES_DELAY);

        FAPI_TRY(fapi2::getScom(i_target, i_PPM_PFCS_RW, l_data64),
                 "getScom failed for address PPM_PFCS_RW");
        l_data64.extractToRight(l_temp64, VCS_PG_STATE_BIT, 4);

        if(l_temp64 == 0x8)
        {
            break;
        }

        l_delayCnt--;
    }
    while(l_delayCnt > 0);

    FAPI_INF("Delay count: %d", l_delayCnt);

    FAPI_ASSERT(l_temp64 == 0x8,
                fapi2::PFET_CTRL_VCS_PG_STATE_TIMEOUT_ERROR()
                .set_VALUE(l_temp64).set_TARGET(i_target),
                "ERROR: VCS FSM idle timeout");

    // Optional check VCS_PG_SEL
    FAPI_DBG("Optionally checking for VCS_PG_SEL value");
    l_data64.extractToRight(l_temp64, VCS_PG_SEL_BIT, 4);
    FAPI_DBG("Value of VCS_PG_SEL: %0x", l_temp64);

    // Write PFETCNTLSTAT_REG_WCLEAR vcs_pfet_force_state = 00 (No Operation)
    FAPI_DBG("vcs_pfet_force_state = 00, or Idle");
    l_data64.flush<0>().setBit<VCS_PFET_FORCE_STATE_BIT, 2>();
    FAPI_TRY(fapi2::putScom(i_target, i_PPM_PFCS_CLR, l_data64),
             "putScom failed for address PPM_PFCS_CLR");

fapi_try_exit:
    return fapi2::current_err;
}

