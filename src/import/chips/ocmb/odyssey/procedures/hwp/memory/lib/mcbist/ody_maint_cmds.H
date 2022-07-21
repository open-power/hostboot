/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mcbist/ody_maint_cmds.H $ */
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
// EKB-Mirror-To: hostboot
///
/// @file ody_maint_cmds.H
/// @brief Utility functions for accessing steer muxes.
///
/// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:CI
///

#ifndef _ODY_MAINT_CMDS_H_
#define _ODY_MAINT_CMDS_H_

//------------------------------------------------------------------------------
//    Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <ody_scom_ody_odc.H>
#include <lib/shared/ody_consts.H>
#include <lib/dimm/ody_rank.H>
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
/// @brief Ody Generic Steer Traits
///
template<>
class genSteerTraits< mss::mc_type::ODYSSEY>
{
    public:
        static constexpr uint8_t INVALID_SYMBOL = 0xff;
        static constexpr uint8_t SPARE_INDICES = 18;
        static constexpr uint8_t SPARE_UNUSED = 31;
        static const std::vector<uint8_t> spare_to_symbol;

};

///
/// @class steerTraits
/// @brief Ody Steer Traits
///
template<>
class steerTraits< mss::mc_type::ODYSSEY, mux_type::READ_MUX >
{
    public:
        static const std::vector<uint32_t> muxregs_left;
        static const std::vector<uint32_t> muxregs_right;

        ///
        /// @brief Gets the correct target for the read mux registers off of a MEM_PORT target
        /// @return Returns the OCMB_CHIP target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> get_target(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
        {
            return i_target;
        }

        // Mux Register and Spare value definitions
        enum mux_registers : size_t
        {
            // Function spaces
            MUX_REGISTER = scomt::ody::ODC_RDF0_SCOM_RSPAR,
            SPARE_MUX_LEN = scomt::ody::ODC_RDF0_SCOM_RSPAR_0_LEFT_LEN,
        };

};


///
/// @class steerTraits
/// @brief Ody Steer Traits
///
template<>
class steerTraits< mss::mc_type::ODYSSEY, mux_type::WRITE_MUX >
{
    public:
        static const std::vector<uint32_t> muxregs_left;
        static const std::vector<uint32_t> muxregs_right;

        ///
        /// @brief Gets the correct target for the write mux registers off of a MEM_PORT target
        /// @return Returns the OCMB_CHIP target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> get_target(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
                i_target)
        {
            return mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
        }

        // Mux Register and Spare value definitions
        enum mux_registers : size_t
        {
            // Function spaces
            MUX_REGISTER = scomt::ody::ODC_WDF_REGS_WSPAR,
            SPARE_MUX_LEN = scomt::ody::ODC_WDF_REGS_WSPAR_0_LEFT_LEN,
        };

};


} // ns steer

} // ns mss

#endif
