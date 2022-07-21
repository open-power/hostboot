/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_maint_cmds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
/// @file exp_maint_cmds.H
/// @brief Utility functions for accessing steer muxes.
///
/// *HWP HWP Owner: Geetha Pisapati Geetha.Pisapati@ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:CI
///

#ifndef _EXP_MAINT_CMDS_H
#define _EXP_MAINT_CMDS_H

//------------------------------------------------------------------------------
//    Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_rank.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_maint_cmds.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>

namespace mss
{

namespace steer
{

///
/// @class genSteerTraits
/// @brief Generic Steer Traits
///
template<>
class genSteerTraits< mss::mc_type::EXPLORER>
{
    public:
        static constexpr uint8_t INVALID_SYMBOL = 0xff;
        static constexpr uint8_t SPARE_INDICES = 18;
        static constexpr uint8_t SPARE_UNUSED = 31;
        static const std::vector<uint8_t> spare_to_symbol;

};

///
/// @class steerTraits
/// @brief Exp Steer Traits
///
template<>
class steerTraits< mss::mc_type::EXPLORER, mss::steer::mux_type::READ_MUX >
{
    public:

        static const std::vector<uint32_t> muxregs_left;
        static const std::vector<uint32_t> muxregs_right;

        ///
        /// @brief Gets the correct target for the read mux registers off of a MEM_PORT target
        /// @return Returns the MEM_PORT target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> get_target(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
        {
            return i_target;
        }

        // Mux Register and Spare value definitions
        enum mux_registers : size_t
        {
            // Function spaces
            MUX_REGISTER = EXPLR_RDF_RSPAR,
            SPARE_MUX_LEN = EXPLR_RDF_RSPAR_CFG_STEERING_R0_LEFT_LEN,
        };

};

///
/// @class steerTraits
/// @brief Exp Steer Traits
///
template<>
class steerTraits< mss::mc_type::EXPLORER, mss::steer::mux_type::WRITE_MUX >
{
    public:

        static const std::vector<uint32_t> muxregs_left;
        static const std::vector<uint32_t> muxregs_right;

        ///
        /// @brief Gets the correct target for the write mux registers off of a MEM_PORT target
        /// @return Returns the MEM_PORT target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> get_target(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
        {
            return i_target;
        }

        // Mux Register and Spare value definitions
        enum mux_registers : size_t
        {
            // Function spaces
            MUX_REGISTER = EXPLR_WDF_WSPAR,
            SPARE_MUX_LEN = EXPLR_WDF_WSPAR_CFG_STEERING_R0_LEFT_LEN,
        };

};

} // ns steer

} // ns mss

#endif
