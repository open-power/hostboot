/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training_helper.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file lib/phy/mss_lrdimm_training_helper.H
/// @brief Common helper functions for LRDIMM training
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef MSS_LRDIMM_TRAINING_HELPER_H
#define MSS_LRDIMM_TRAINING_HELPER_H

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/ccs/ccs.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>
#include <lib/dimm/ddr4/data_buffer_ddr4.H>
#include <lib/phy/seq.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <lib/mcbist/mcbist.H>
#include <lib/dimm/ddr4/pba.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/rosetta_map/rosetta_map.H>

namespace mss
{

namespace training
{

namespace lrdimm
{

///
/// @brief Enums for per-nibble or per-bit level for LRDIMM training
/// @note Values taken from the buffer spec
///
enum training_level : uint64_t
{
    NIBBLE = 0,
    BIT = 1,
};

///
/// @brief Sets the comparison on a per-nibble or per-bit level
/// @param[in] i_target the DIMM target
/// @param[in] i_training_level the buffer's training level
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up buffer control word F6BC4x to do compares on a per-bit level
///
fapi2::ReturnCode set_training_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint64_t i_training_level);

///
/// @brief Creates the control words to set the expected MPR pattern into the buffer
/// @param[in] i_pattern the pattern to program into the buffer
/// @return cw_info vector containing the control words used to setup the MPR pattern into the buffer
/// @note Sets up the expected data pattern in buffer control words (F5BC0x,F5BC1x,F5BC2x,F5BC3x, F6BC0x,F6BC1x,F6BC2x,F6BC3x)
///
std::vector<cw_info> set_expected_mpr_pattern(const fapi2::buffer<uint8_t>& i_pattern );

///
/// @brief Sets expected mpr pattern into the buffer
/// @param[in] i_target the DIMM target
/// @param[in] i_pattern the pattern to program into the buffer
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up the expected data pattern in buffer control words (F5BC0x,F5BC1x,F5BC2x,F5BC3x, F6BC0x,F6BC1x,F6BC2x,F6BC3x)
///
fapi2::ReturnCode set_expected_mpr_pattern(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const fapi2::buffer<uint8_t>& i_pattern );

} // ns training

} // ns lrdimm

} // ns mss

#endif
