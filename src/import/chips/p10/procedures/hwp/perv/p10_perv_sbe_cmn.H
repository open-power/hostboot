/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_perv_sbe_cmn.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file  p10_perv_sbe_cmn.H
///
/// @brief Modules for scan 0 and array init
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------

#ifndef _P10_PERV_SBE_CMN_H_
#define _P10_PERV_SBE_CMN_H_


#include <fapi2.H>
#include <multicast_defs.H>
#include "p10_ring_id.H"

enum mux_type : int
{
    FSI2PCB = 16,
    PIB2PCB = 18,
    PCB2PCB = 19,
};

/// @brief Describes ring table for putring call in initf procedures
const uint8_t IGNORE_PG = 0xFF;

enum target_type : uint8_t
{
    TARGET_CHIP,
    TARGET_CHIPLET,
};

struct ring_setup_t
{
    RingID ring_id;       ///< Abstract ring ID that will be represented by this
    uint8_t pg_bit;       ///< pg bit for the ring
    target_type targ;     ///< the ring can be of type TARGET_CHIP/TARGET_CHIPLET
    uint8_t min_cplt_id;  ///< Min chiplet id of the chiplet
    uint8_t max_cplt_id;  ///< Max chiplet id of the chiplet
    uint8_t last;         ///< Set to 1 for the last entry in an array of this struct
};

struct mc_ring_setup_t
{
    RingID ring_id;       ///< Abstract ring ID that will be represented by this
    uint8_t last;         ///< Set to 1 for the last entry in an array of this struct
};

/// @brief Describes a hang pulse configuration
struct hang_pulse_t
{
    uint16_t id            : 4; ///< Hang pulse number to program
    uint16_t value         : 8; ///< Frequency value for this hang pulse
    uint16_t stop_on_xstop : 1; ///< Hang pulse should stop when a checkstop comes in
    uint16_t               : 2;
    uint16_t last          : 1; ///< Set to 1 for the last entry in an array of this struct
};

enum mc_hw_group_t : uint8_t
{
    MC_GROUP_0 = 0x0,
    MC_GROUP_1 = 0x1,
    MC_GROUP_2 = 0x2,
    MC_GROUP_3 = 0x3,
    MC_GROUP_4 = 0x4,
    MC_GROUP_5 = 0x5,
    MC_GROUP_6 = 0x6,
};

enum mc_pgood_type : uint8_t
{
    IGNORE_PGOOD           = 0,
    HONOR_PGOOD,
    HONOR_PGOOD_FORCE_EQ,
    HONOR_CORE_PGOOD_ATTR,
    HONOR_CORE_PGOOD_REG,
    NUM_PGOOD_CHOICES
};

/// @brief Describes the setup for a single multicast group
struct mc_setup_t
{
    fapi2::MulticastGroup group;       ///< Abstract group ID that will be represented by this
    mc_hw_group_t         hw_group;    ///< Hardware group value to associate with this group
    mc_pgood_type         pgood_type;  ///< How to handle partial-goodness of chiplets
    uint8_t               last;        ///< Set to 1 for the last entry in an array of this struct
    uint64_t              members;     ///< A vector of chiplets to make members of this group
};

fapi2::ReturnCode p10_perv_sbe_cmn_array_init_module(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_mcast_target,
        const fapi2::buffer<uint16_t> i_regions,
        const fapi2::buffer<uint64_t> i_loop_counter,
        const fapi2::buffer<uint64_t> i_start_abist_match_value,
        bool i_drop_fences = true);

fapi2::ReturnCode p10_perv_sbe_cmn_scan0_module(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_mcast_target,
        const fapi2::buffer<uint16_t> i_regions,
        const fapi2::buffer<uint16_t> i_scan_types);

fapi2::ReturnCode p10_perv_sbe_cmn_clock_start_stop(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_OR > & i_mcast_target,
        const fapi2::buffer<uint8_t> i_clock_cmd,
        const bool i_startslave,
        const bool i_startmaster,
        const fapi2::buffer<uint64_t> i_regions,
        const fapi2::buffer<uint8_t> i_clock_types);

fapi2::ReturnCode p10_perv_sbe_cmn_check_status(
    const fapi2::buffer<uint64_t> i_regions,
    const fapi2::buffer<uint64_t> i_clock_status,
    const bool i_reg,
    const fapi2::buffer<uint8_t> i_clock_cmd,
    fapi2::buffer<uint64_t>& o_exp_clock_status);

fapi2::ReturnCode p10_perv_sbe_cmn_setup_hangpulse_counters(
    const fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST > & i_target_chiplet,
    const bool i_target_parent_chip,
    const uint32_t i_base_address,
    const uint8_t i_pre_divider,
    const hang_pulse_t* i_hang_pulse_table);

fapi2::ReturnCode p10_perv_sbe_cmn_setup_multicast_groups(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const mc_setup_t* i_setup_table);

fapi2::ReturnCode p10_perv_sbe_cmn_cplt_status(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    fapi2::TargetState i_target_state,
    fapi2::buffer<uint64_t>& o_cplt_status_mask);

fapi2::ReturnCode p10_perv_sbe_cmn_eqs_with_good_cores(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    bool i_use_reg_not_attr,
    fapi2::buffer<uint64_t>& o_cplt_status_mask);

fapi2::ReturnCode p10_perv_sbe_cmn_align_chiplets(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_COMPARE > & i_mcast_target);

fapi2::ReturnCode p10_perv_sbe_cmn_setup_putring(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const ring_setup_t* i_ring_table,
    bool i_tp_chiplet = false);

fapi2::ReturnCode p10_perv_sbe_cmn_setup_putring_multicast(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const fapi2::MulticastGroup i_group,
    const mc_ring_setup_t* i_ring_table);

fapi2::ReturnCode p10_perv_sbe_cmn_is_simulation_check(bool& is_simulation);

fapi2::ReturnCode p10_perv_sbe_cmn_switch_mux_scom(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip, mux_type i_mux_setup);

/**
 * @brief Poll for lock of one or more PLLs
 *
 * Will poll for all requested lock indicators to turn on within 5ms, returning early
 * as soon as all PLLs are locked. If after the timeout not all requested PLLs are locked,
 * will return FAPI2_RC_FALSE, otherwise FAPI2_RC_SUCCESS (or something else on a SCOM error).
 *
 * @param[in]  i_target        Target chiplet(s) to check
 * @param[in]  i_bits_to_check Bits of the PLL_LOCK register that must be 1
 * @param[out] o_read_value    Last value read from the PLL_LOCK register for FFDC
 *
 * @return FAPI2_RC_SUCCESS if all PLLs locked in time
 *         FAPI2_RC_FALSE   if not all PLLs locked before the timeout
 *         others           if the SCOM read failed
 */
fapi2::ReturnCode p10_perv_sbe_cmn_poll_pll_lock(
    const fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST,
    fapi2::MULTICAST_AND > & i_target,
    const fapi2::buffer<uint64_t> i_bits_to_check,
    fapi2::buffer<uint64_t>& o_read_value);

fapi2::ReturnCode p10_perv_sbe_cmn_switch_mux_cfam(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip, mux_type i_mux_setup);

#endif
