/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training_helper.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
enum errors : uint64_t
{
    CLEAN_BITMAP = 0,
};

///
/// @brief Appends a buffer's error callouts per-nibble onto the nibble bitmap
/// @param[in] i_nibble0 flag for nibble 0 - true is fail
/// @param[in] i_nibble1 flag for nibble 1 - true is fail
/// @param[in,out] io_bitmap bitmap to update
/// @note Bit flags are used for the nibbles to simplify the error callouts
/// We can callout one bitmap or 18 bits
///
inline void append_nibble_flags(const bool i_nibble0, const bool i_nibble1, uint32_t& io_bitmap)
{


    // Update the bitmap -
    // bit logic shifts the bits to the right then OR's in the given nibble
    // This forces nibble 0 to be the leftmost bit in the flag, while nibble 17 is the right most bit in the flag
    io_bitmap <<= 1;
    io_bitmap |= i_nibble0 ? 1 : 0;
    io_bitmap <<= 1;
    io_bitmap |= i_nibble1 ? 1 : 0;
}

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

// Namespace for any helper functions for calling out errors
namespace callout
{

///
/// @brief Calls out if invalid data is seen during this calibration step
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_per_nibble_flags flags for which nibbles are failing
/// @param[in] i_invalid_data_count count for the number of times fails were seen
/// @param[in] i_calibration_step calibration step number
/// @param[in] i_name string of the calibration steps name
/// @return FAPI2_RC_SUCCESS if okay
/// @note Invalid data is defined as not having all zeros or all ones
/// To only be used during per-nibble training steps (MREP, DWL, MRD coarse, MWD coarse)
///
inline fapi2::ReturnCode invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const uint8_t i_rank,
                                       const uint32_t i_per_nibble_flags,
                                       const uint64_t i_invalid_data_count,
                                       const uint64_t i_calibration_step,
                                       const char* i_name)
{
    // Per nibble invalid data - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    FAPI_ASSERT(i_per_nibble_flags == CLEAN_BITMAP,
                fapi2::MSS_LRDIMM_CAL_INVALID_DATA()
                .set_TARGET(i_target)
                .set_RANK(i_rank)
                .set_CALIBRATION_STEP(i_calibration_step)
                .set_NIBBLE_FLAGS(i_per_nibble_flags)
                .set_INVALID_DATA_COUNT(i_invalid_data_count),
                "%s rank%u has counted %u invalid data on nibbles 0x%x in %s",
                mss::c_str(i_target), i_rank, i_invalid_data_count, i_per_nibble_flags, i_name);


    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered
    // We "recover" by setting a default value and continuing with calibration
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}

///
/// @brief Calls out if a rank does not see a 0->1 transition
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_per_nibble_flags flags for which nibbles are failing
/// @param[in] i_calibration_step calibration step number
/// @param[in] i_name string of the calibration steps name
/// @return FAPI2_RC_SUCCESS if okay
///
inline fapi2::ReturnCode no_transition( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint8_t i_rank,
                                        const uint32_t i_per_nibble_flags,
                                        const uint64_t i_calibration_step,
                                        const char* i_name)
{
    // Per nibble invalid data - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    FAPI_ASSERT(i_per_nibble_flags == CLEAN_BITMAP,
                fapi2::MSS_LRDIMM_CAL_NO_TRANSITION()
                .set_TARGET(i_target)
                .set_RANK(i_rank)
                .set_CALIBRATION_STEP(i_calibration_step)
                .set_NIBBLE_FLAGS(i_per_nibble_flags),
                "%s rank%u has found no transitions on nibbles 0x%x in %s",
                mss::c_str(i_target), i_rank, i_per_nibble_flags, i_name);


    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered
    // We "recover" by setting a default value and continuing with calibration
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}

} // ns callout

} // ns training

} // ns lrdimm

} // ns mss

#endif
