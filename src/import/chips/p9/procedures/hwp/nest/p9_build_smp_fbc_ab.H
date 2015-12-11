/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_build_smp_fbc_ab.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p9_build_smp_fbc_ab.H
/// @brief Fabric configuration (hotplug, AB) functions.
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
/// *HWP Consumed by: HB,FSP
///

#ifndef _P9_BUILD_SMP_FBC_AB_H_
#define _P9_BUILD_SMP_FBC_AB_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_build_smp.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
// PB Hotplug Mode register field/bit definitions
const uint32_t PB_HP_MODE_MASTER_CHIP_BIT = 0;
const uint32_t PB_HP_MODE_CHG_RATE_GP_MASTER_BIT = 2;

// TODO: RTC 147511 - Use SCOM register names from p9_misc_scom_addresses.H
// Remove the reg addresses defined below and use the ones in
// p9_misc_scom_addresses.H when available.

// HP
const uint64_t PB_HP_MODE_CURR_WEST = 0x0501180C;
const uint64_t PB_HP_MODE_CURR_CENT = 0x05011C0C;
const uint64_t PB_HP_MODE_CURR_EAST = 0x0501200C;
const uint64_t PB_HP_MODE_CURR_SHADOWS[P9_BUILD_SMP_NUM_SHADOWS] =
{
    PB_HP_MODE_CURR_WEST,
    PB_HP_MODE_CURR_CENT,
    PB_HP_MODE_CURR_EAST
};

const uint64_t PB_HP_MODE_NEXT_WEST = 0x0501180B;
const uint64_t PB_HP_MODE_NEXT_CENT = 0x05011C0B;
const uint64_t PB_HP_MODE_NEXT_EAST = 0x0501200B;
const uint32_t PB_HP_MODE_NEXT_SHADOWS[P9_BUILD_SMP_NUM_SHADOWS] =
{
    PB_HP_MODE_NEXT_WEST,
    PB_HP_MODE_NEXT_CENT,
    PB_HP_MODE_NEXT_EAST
};

// HPX
const uint64_t PB_HPX_MODE_CURR_WEST = 0x05011810;
const uint64_t PB_HPX_MODE_CURR_CENT = 0x05011C10;
const uint64_t PB_HPX_MODE_CURR_EAST = 0x05012010;
const uint32_t PB_HPX_MODE_CURR_SHADOWS[P9_BUILD_SMP_NUM_SHADOWS] =
{
    PB_HPX_MODE_CURR_WEST,
    PB_HPX_MODE_CURR_CENT,
    PB_HPX_MODE_CURR_EAST
};

const uint64_t PB_HPX_MODE_NEXT_WEST = 0x0501180F;
const uint64_t PB_HPX_MODE_NEXT_CENT = 0x05011C0F;
const uint64_t PB_HPX_MODE_NEXT_EAST = 0x0501200F;
const uint32_t PB_HPX_MODE_NEXT_SHADOWS[P9_BUILD_SMP_NUM_SHADOWS] =
{
    PB_HPX_MODE_NEXT_WEST,
    PB_HPX_MODE_NEXT_CENT,
    PB_HPX_MODE_NEXT_EAST
};

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
///
/// @brief Determine parameters of link/destination chip
///
/// @tparam T template parameter, passed in target.
/// @param[in] i_smp_chip          Structure encapsulating single chip in SMP
/// @param[in] i_source_link_id    Link identifier for FFDC
/// @param[in] i_dest_target       Destination link endpoint target
/// @param[out] o_link_is_enabled  true=link enabled, false=link disabled
/// @param[out] o_dest_target_node_id  Node ID of destination chip
/// @param[out] o_dest_target_chip_id  Chip ID of destination chip
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode p9_build_smp_query_link_state(
    const p9_build_smp_chip& i_smp_chip,
    const uint8_t i_source_link_id,
    const fapi2::Target<T>& i_dest_target,
    bool& o_link_is_enabled,
    p9_fab_smp_node_id& o_dest_target_node_id,
    p9_fab_smp_chip_id& o_dest_target_chip_id);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief Utility function to read set of PB CURR hotplug registers
///
/// @param[in] i_smp_chip    Structure encapsulating single chip in SMP
///                          topology
/// @param[in] i_hp_not_hpx  Choose HP/HPX register set (true=HP, false=HPX)
/// @param[out] o_data       Data buffer containing read data
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_get_hotplug_curr_reg(
        const p9_build_smp_chip& i_smp_chip,
        const bool i_hp_not_hpx,
        fapi2::buffer<uint64_t>& o_data);


///
/// @brief Program fabric configuration register (hotplug, A/B set)
///
/// @param[in] i_smp     Structure encapsulating SMP topology
/// @param[in] i_op      Enumerated type representing SMP build phase
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_set_fbc_ab(p9_build_smp_system& i_smp,
            const p9_build_smp_operation i_op);

} // extern "C"

#endif // _P9_BUILD_SMP_FBC_AB_H_
