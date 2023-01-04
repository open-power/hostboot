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

/// @brief Miscellaneous TP setup
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_ANY_POZ_CHIP
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode mod_poz_tp_init_common(
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
