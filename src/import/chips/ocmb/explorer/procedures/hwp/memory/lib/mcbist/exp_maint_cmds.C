/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_maint_cmds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file exp_maint_cmds.C
/// @brief Utility functions for accessing steer muxes.
///
/// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:CI
///

//------------------------------------------------------------------------------
//    Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <lib/mc/exp_port_traits.H>
#include <lib/mcbist/exp_maint_cmds.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <lib/dimm/exp_rank.H>
#include <lib/mc/exp_port_traits.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

namespace steer
{

///
/// @brief Table matching spare index to last symbol
/// @note the vector index matches the spare index and holds the symbol value
///       the vector index also matches the Spare values for Steer mux registers
///
const std::vector<uint8_t> genSteerTraits< mss::mc_type::EXPLORER>::spare_to_symbol(
{
    68,    36,    64,    32,    60,
    28,    56,    24,    52,    20,
    48,    16,    44,    12,    40,
    8,     4,     0
});

///
/// @brief Used to determine spare info for Spare0 WriteMux
///
const std::vector< uint32_t > steerTraits< mss::mc_type::EXPLORER, mux_type::WRITE_MUX >::muxregs_left =
{
    EXPLR_WDF_WSPAR_CFG_STEERING_R0_LEFT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R1_LEFT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R2_LEFT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R3_LEFT,
};

///
/// @brief Used to determine spare info for Spare1 WriteMux
///
const std::vector< uint32_t > steerTraits< mss::mc_type::EXPLORER, mux_type::WRITE_MUX >::muxregs_right =
{
    EXPLR_WDF_WSPAR_CFG_STEERING_R0_RIGHT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R1_RIGHT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R2_RIGHT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R3_RIGHT,
};

///
/// @brief Used to determine spare info for Spare0 ReadMux
///
const std::vector< uint32_t > steerTraits< mss::mc_type::EXPLORER, mux_type::READ_MUX >::muxregs_left =
{
    EXPLR_RDF_RSPAR_CFG_STEERING_R0_LEFT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R1_LEFT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R2_LEFT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R3_LEFT,
};

///
/// @brief Used to determine spare info for Spare1 ReadMux
///
const std::vector< uint32_t > steerTraits< mss::mc_type::EXPLORER, mux_type::READ_MUX >::muxregs_right =
{
    EXPLR_RDF_RSPAR_CFG_STEERING_R0_RIGHT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R1_RIGHT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R2_RIGHT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R3_RIGHT,
};

///
/// @brief Updates steer mux index with respect to OCMB EXPLORER specialization does nothing
/// @param[in] i_target Mem Port target
/// @param[in, out] io_steer_mux_index mux index we want to read/write steer mux for.
///
template<>
void update_steer_mux_instance<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    uint8_t& io_steer_mux_index)
{}

} // ns steer

} // ns mss
