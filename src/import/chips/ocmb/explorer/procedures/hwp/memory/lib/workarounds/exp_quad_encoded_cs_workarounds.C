/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_quad_encoded_cs_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file exp_quad_encoded_cs_workarounds.C
/// @brief Workarounds for Explorer quad encoded CS
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <lib/workarounds/exp_quad_encoded_cs_workarounds.H>

namespace mss
{
namespace exp
{
namespace workarounds
{

///
/// @brief Fixes the mirroring bitmap based upon the quad encoded CS configuration
/// @param[in] i_is_quad_encoded_cs true if quad encoded CS is used
/// @param[in,out] io_mirroring the mirroring bitmap to fix up
/// @note Only swaps the bits in the mirroring bitmap associated with the ranks affected by the quad encoded CS bug
/// Associated with JIRA355
///
void fix_mirroring_bitmap_for_quad_encoded_cs(const bool i_is_quad_encoded_cs, uint8_t& io_mirroring)
{
    // Ranks 1/2 are swapped between the IBM and DFI perspectives
    // If this part uses quad encoded CS, then we need to swap ranks 1/2
    // The rank values are taken from the SPD description for explorer
    // Rank3 - bit4
    // Rank2 - bit5
    // Rank1 - bit6
    // Rank0 - bit7
    constexpr uint64_t RANK1 = 6;
    constexpr uint64_t RANK2 = 5;

    if(i_is_quad_encoded_cs)
    {
        fapi2::buffer<uint8_t> l_input(io_mirroring);
        fapi2::buffer<uint8_t> l_output(io_mirroring);
        l_output.writeBit<RANK1>(l_input.getBit<RANK2>())
        .writeBit<RANK2>(l_input.getBit<RANK1>());
        io_mirroring = l_output;
    }
}

} // workarounds
} // exp
} // mss
