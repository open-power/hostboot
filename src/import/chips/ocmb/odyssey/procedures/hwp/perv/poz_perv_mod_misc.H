/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_perv_mod_misc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
//------------------------------------------------------------------------------
/// @file  poz_perv_mod_misc.H
/// @brief Miscellaneous module definitions
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Sreekanth Reddy (skadapal@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#pragma once

#include <fapi2.H>
#include <poz_perv_common_params.H>

using namespace mux;

/// @brief CBS start module
/// -- Prepare for CBS start
/// -- Start CBS and check CBS_CS INTERNAL_STATE_VECTOR for IDLE state.
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_ANY_POZ_CHIP
/// @param[in]   i_start_sbe               Option to prevent SBE start
/// @param[in]   i_scan0_clockstart        Option to skip scan0 and clockstart command
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_cbs_start(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    bool i_start_sbe = true,
    bool i_scan0_clockstart = true);

/// @brief Switch pcbmux module
/// -- enable the new path first and disable the old path.
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_ANY_POZ_CHIP
/// @param[in]   i_path                    Path to be enabled FSI2PCB/PIB2PCB/PCB2PCB/I2C2PCB
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_switch_pcbmux(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    mux_type i_path);

/// @brief Switch pcbmux module using cfams
/// -- enable the new path first and disable the old path.
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_ANY_POZ_CHIP
/// @param[in]   i_path                    Path to be enabled FSI2PCB/PIB2PCB/PCB2PCB/I2C2PCB
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_switch_pcbmux_cfam(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    mux_type i_path);

/// @brief Multicast setup module
/// -- Determine required/current group members and update group memebership where needed.
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_ANY_POZ_CHIP
/// @param[in]   i_group_id                Multicast group number
/// @param[in]   i_chiplets                64bit address having corresponding bit location set for required chiplets
/// @param[in]   i_pgood_policy            Partial good policy TARGET_STATE_[FUNCTIONAL/PRESENT/others]
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_multicast_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    uint8_t i_group_id,
    uint64_t i_chiplets,
    fapi2::TargetState i_pgood_policy);

/// @brief Get chiplet by chiplet number module
/// -- Given a chiplet number, plug the corresponding chiplet target into the output argument.
///
/// @param[in]   i_target                  Reference to the target containing the desired chiplet
/// @param[in]   i_chiplet_number          Number of the desired chiplet
/// @param[out]  o_target                  Pervasive object for accessing our desired chiplet
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_get_chiplet_by_number(
    const fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_ANY_POZ_CHIP > & i_target,
    uint8_t i_chiplet_number,
    fapi2::Target < fapi2::TARGET_TYPE_PERV >& o_target);

/// @brief Hangpulse setup module
/// -- write hang pulse table values into corresponding HANG_PULSE_* registers
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_PERV or TARGET_TYPE_MULTICAST
/// @param[in]   i_pre_divider             Divider for hang counter clock
/// @param[in]   i_hangpulse_table         Hang pulse table having id, frequency and stop_on_xstop values
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_hangpulse_setup(
    const fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST > & i_target,
    uint8_t i_pre_divider,
    const hang_pulse_t* i_hangpulse_table);

/// @brief Constant hangpulse setup module
/// -- write constant hang pulse table values into corresponding HANG_PULSE_* & PRE_COUNTER registers
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_ANY_POZ_CHIP
/// @param[in]   i_base_address            Base address (HANG_PULSE_CONFIG_REG address of the chiplet)
/// @param[in]   i_hangpulses[4]           4 Hang pulse arrays having predivider, frequency & stop_on_xstop values
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_constant_hangpulse_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    uint32_t i_base_address,
    const constant_hang_pulse_t i_hangpulses[4]);

// Own namespace to hide the helper functions
namespace _mod_pipe_setup
{
/// @brief Helper function for mod_pipe_setup: Calculate access control for a pipe pair
///
/// @param[in] i_a      A side PIB controller ID - writes even pipe, reads odd pipe
/// @param[in] i_a_int  Enable interrupts for A side
/// @param[in] i_b      B side PIB controller ID - write odd pipe, reads even pipe
/// @param[in] i_b_int  Enable interrupts for B side
/// @return Access control register bits for a pair of pipes
constexpr uint64_t acc_ctrl(pib::pib_controller i_a, bool i_a_int, pib::pib_controller i_b, bool i_b_int)
{
    return (i_a == pib::PC_NONE && i_b == pib::PC_NONE) ? 0 :   // If both ends are NONE, pipe pair is closed
           ( 0x8888                                // All pipe ends are open
             | (i_a == pib::PC_NONE ? 0 : 0x4004)  // Side A writes into even pipe, reads from odd pipe
             | (i_b == pib::PC_NONE ? 0 : 0x0440)  // Side B reads from even pipe, writes into odd pipe
             | (i_a_int ? 0x0002 : 0)              // Side A reads from odd pipe i.e. gets ints from there
             | (i_b_int ? 0x0200 : 0));            // Side B reads from even pipe i.e. gets ints from there
}

/// @brief Helper function for mod_pipe_setup: Calculate controller ID register for a pipe pair
///
/// @param[in] i_a      A side PIB controller ID - writes even pipe, reads odd pipe
/// @param[in] i_b      B side PIB controller ID - write odd pipe, reads even pipe
/// @return Controller ID register bits for a pair of pipes
constexpr uint64_t ctrl_id(pib::pib_controller i_a, pib::pib_controller i_b)
{
    return (uint64_t(i_a) << 12) | (uint64_t(i_b) << 8) | (uint64_t(i_b) << 4) | uint64_t(i_a);
}
}

/// @brief Set up the multipipe unit on a chip according to fixed parameters
///
/// The eight pipes are grouped into four pairs. Each pair has an "A side" and "B side"
/// PIB controller. The A side writes into the even pipe of the pair and reads from the
/// odd pipe, the B side writes into the odd pipe and reads from the even one.
/// Interrupts can be enabled on a per-side basis.
///
/// @param[in] i_target Chip target to set up
/// @param[in] i_p0a      Pair 0: Side A PIB controller ID - writes even pipe, reads odd pipe
/// @param[in] i_p0a_int  Pair 0: Enable receive interrupts for side A
/// @param[in] i_p0b      Pair 0: Side B PIB controller ID - write odd pipe, reads even pipe
/// @param[in] i_p0b_int  Pair 0: Enable receive interrupts for side B
/// @param[in] i_pN...    The same for pair N
///
/// @return Standard FAPI2 return codes
//
// This function is static inline so that the register values can be fully calculated
// at compile time and the code optimizes down to two putScoms with constant values.
//
static inline fapi2::ReturnCode mod_pipe_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    pib::pib_controller i_p0a, bool i_p0a_int, pib::pib_controller i_p0b, bool i_p0b_int,
    pib::pib_controller i_p1a, bool i_p1a_int, pib::pib_controller i_p1b, bool i_p1b_int,
    pib::pib_controller i_p2a, bool i_p2a_int, pib::pib_controller i_p2b, bool i_p2b_int,
    pib::pib_controller i_p3a, bool i_p3a_int, pib::pib_controller i_p3b, bool i_p3b_int)
{
    const uint64_t l_acc_ctrl = 0
                                | _mod_pipe_setup::acc_ctrl(i_p0a, i_p0a_int, i_p0b, i_p0b_int) << 48
                                | _mod_pipe_setup::acc_ctrl(i_p1a, i_p1a_int, i_p1b, i_p1b_int) << 32
                                | _mod_pipe_setup::acc_ctrl(i_p2a, i_p2a_int, i_p2b, i_p2b_int) << 16
                                | _mod_pipe_setup::acc_ctrl(i_p3a, i_p3a_int, i_p3b, i_p3b_int);
    const uint64_t l_ctrl_id = 0
                               | _mod_pipe_setup::ctrl_id(i_p0a, i_p0b) << 48
                               | _mod_pipe_setup::ctrl_id(i_p1a, i_p1b) << 32
                               | _mod_pipe_setup::ctrl_id(i_p2a, i_p2b) << 16
                               | _mod_pipe_setup::ctrl_id(i_p3a, i_p3b);

    // Using magic constants for the register addresses here because we don't
    // want to include the register headers in .H files.
    FAPI_TRY(fapi2::putScom(i_target, 0xB0120, l_acc_ctrl));
    FAPI_TRY(fapi2::putScom(i_target, 0xB0123, l_ctrl_id));

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Miscellaneous TP setup
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_ANY_POZ_CHIP
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_poz_tp_init_common(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target);

/// @brief Unmask chiplet FIRs on all good non-TP chiplets
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_ANY_POZ_CHIP
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_unmask_firs(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target);

/// @brief Setup clockstop on checkstop module
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_ANY_POZ_CHIP
/// @param[in]   i_chiplet_delays[64]      Array of per-chiplet delays
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_setup_clockstop_on_xstop(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    const uint8_t i_chiplet_delays[64]);
