/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mcbist/ody_maint_cmds.C $ */
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
// EKB-Mirror-To: hostboot
///
/// @file ody_maint_cmds.C
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
#include <lib/mcbist/ody_maint_cmds.H>
#include <ody_scom_ody_odc.H>


namespace mss
{

namespace steer
{
///
/// @brief Table matching spare index to last symbol
/// @note the vector index matches the spare index and holds the symbol value
///       the vector index also matches the Spare values for Steer mux registers
///

const std::vector<uint8_t> genSteerTraits< mss::mc_type::ODYSSEY>::spare_to_symbol(
{
    68,    36,    64,    32,    60,
    28,    56,    24,    52,    20,
    48,    16,    44,    12,    40,
    8,     4,     0
});

///
/// @brief Used to determine spare info for Spare0 WriteMux
/// @note Regs at indices 0-1 are port 0 and at indices 2-3 are port 1
///
const std::vector< uint32_t > steerTraits< mss::mc_type::ODYSSEY, mux_type::WRITE_MUX >::muxregs_left =
{
    scomt::ody::ODC_WDF_REGS_WSPAR_R0_LEFT,
    scomt::ody::ODC_WDF_REGS_WSPAR_R1_LEFT,
    scomt::ody::ODC_WDF_REGS_WSPAR_R2_LEFT,
    scomt::ody::ODC_WDF_REGS_WSPAR_R3_LEFT,
};

///
/// @brief Used to determine spare info for Spare1 WriteMux
/// @note Regs at indices 0-1 are port 0 and at indices 2-3 are port 1
///
const std::vector< uint32_t > steerTraits< mss::mc_type::ODYSSEY, mux_type::WRITE_MUX >::muxregs_right =
{
    scomt::ody::ODC_WDF_REGS_WSPAR_R0_RIGHT,
    scomt::ody::ODC_WDF_REGS_WSPAR_R1_RIGHT,
    scomt::ody::ODC_WDF_REGS_WSPAR_R2_RIGHT,
    scomt::ody::ODC_WDF_REGS_WSPAR_R3_RIGHT,
};

///
/// @brief Used to determine spare info for Spare0 ReadMux
/// @note Regs at indices 0-1 are port 0 and at indices 2-3 are port 1
///
const std::vector< uint32_t > steerTraits< mss::mc_type::ODYSSEY, mux_type::READ_MUX >::muxregs_left =
{
    scomt::ody::ODC_RDF0_SCOM_RSPAR_R0_LEFT,
    scomt::ody::ODC_RDF0_SCOM_RSPAR_R1_LEFT,
    scomt::ody::ODC_RDF1_SCOM_RSPAR_R0_LEFT,
    scomt::ody::ODC_RDF1_SCOM_RSPAR_R1_LEFT,
};

///
/// @brief Used to determine spare info for Spare1 ReadMux
/// @note Regs at indices 0-1 are port 0 and at indices 2-3 are port 1
///
const std::vector< uint32_t > steerTraits< mss::mc_type::ODYSSEY, mux_type::READ_MUX >::muxregs_right =
{
    scomt::ody::ODC_RDF0_SCOM_RSPAR_R0_RIGHT,
    scomt::ody::ODC_RDF0_SCOM_RSPAR_R1_RIGHT,
    scomt::ody::ODC_RDF1_SCOM_RSPAR_R0_RIGHT,
    scomt::ody::ODC_RDF1_SCOM_RSPAR_R1_RIGHT,
};

///
/// @brief Updates steer mux index with respect to OCMB ODYSSEY specialization
/// @param[in] i_target Mem Port target
/// @param[in, out] io_steer_mux_index steer mux index we want to read/write steer mux for.
///
template<>
void update_steer_mux_instance<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    uint8_t& io_steer_mux_index)
{
    constexpr uint8_t PORT_1 = 1;
    constexpr uint8_t RANK_OFFSET = 2;
    const uint8_t l_port_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // If were looking at port 1/side 1 (ODYSSEY) check muxregs[2] and muxregs[3]
    if(l_port_pos == PORT_1)
    {
        io_steer_mux_index = io_steer_mux_index + RANK_OFFSET;
    }
}

} // ns steer

} // ns mss
