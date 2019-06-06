/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_train_handler.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file exp_train_handler.C
/// @brief Procedure handle any training fails from the explorer
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <generic/memory/lib/utils/endian_utils.H>
#include <generic/memory/lib/mss_generic_attribute_setters.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <exp_train_handler.H>

namespace mss
{

///
/// @brief A generic bad bits setter
/// @tparam MC type memory controller type
/// @param[in] i_target the fapi2 target oon which training was conducted
/// @param[in] i_array the bad bits to set
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
template <>
fapi2::ReturnCode set_bad_dq_bitmap<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t (&i_array)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT])
{
    return mss::attr::set_bad_dq_bitmap(i_target, i_array);
}

namespace check
{

///
/// @brief Checks whether any FIRs have lit up on a target - EXPLOER/OCMB specialization
/// @param[in] i_target - the target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
// TK update this when FIR's are fully reviewed
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,

        fapi2::ReturnCode& io_rc,
        bool& o_fir_error )

{
    io_rc = fapi2::FAPI2_RC_SUCCESS;
    o_fir_error = false;
    return fapi2::FAPI2_RC_SUCCESS;
}

} // ns check

namespace exp
{

///
/// @brief Reads the training response structure
/// @param[in] i_target the target associated with the response data
/// @param[in] i_data the response data to read
/// @param[out] o_resp the processed training response class
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode read_training_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        user_response_msdg& o_resp)
{

    // True if we pass
    // We assert at the end to avoid LOTS of fapi asserts
    uint32_t l_idx = 0;

    uint32_t l_version_number = 0;
    bool l_pass = readLE(i_data, l_idx, l_version_number);
    o_resp.version_number = l_version_number;

    uint16_t l_DFIMRL_DDRCLK_trained = 0;

    // Reads in the timing portion of the training response
    l_pass &= readLE(i_data, l_idx, l_DFIMRL_DDRCLK_trained);
    l_pass &= readLEArray(i_data, TIMING_RESPONSE_2D_ARRAY_SIZE, l_idx, &o_resp.tm_resp.CDD_RR[0][0]);
    l_pass &= readLEArray(i_data, TIMING_RESPONSE_2D_ARRAY_SIZE, l_idx, &o_resp.tm_resp.CDD_WW[0][0]);
    l_pass &= readLEArray(i_data, TIMING_RESPONSE_2D_ARRAY_SIZE, l_idx, &o_resp.tm_resp.CDD_RW[0][0]);
    l_pass &= readLEArray(i_data, TIMING_RESPONSE_2D_ARRAY_SIZE, l_idx, &o_resp.tm_resp.CDD_WR[0][0]);

    // Write to user_response_msdg
    o_resp.tm_resp.DFIMRL_DDRCLK_trained = l_DFIMRL_DDRCLK_trained;

    // Error response
    l_pass &= readLEArray(i_data, 80, l_idx, o_resp.err_resp.Failure_Lane);

    uint16_t l_MR0 = 0;
    uint16_t l_MR3 = 0;
    uint16_t l_MR4 = 0;

    // MRS response
    l_pass &= readLE(i_data, l_idx, l_MR0);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RANKS, l_idx, o_resp.mrs_resp.MR1);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RANKS, l_idx, o_resp.mrs_resp.MR2);
    l_pass &= readLE(i_data, l_idx, l_MR3);
    l_pass &= readLE(i_data, l_idx, l_MR4);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RANKS, l_idx, o_resp.mrs_resp.MR5);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_MR6_SIZE, l_idx, &o_resp.mrs_resp.MR6[0][0]);

    o_resp.mrs_resp.MR0 = l_MR0;
    o_resp.mrs_resp.MR3 = l_MR3;
    o_resp.mrs_resp.MR4 = l_MR4;

    // Register Control Word (RCW) response
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RC, l_idx, o_resp.rc_resp.F0RC_D0);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RC, l_idx, o_resp.rc_resp.F1RC_D0);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RC, l_idx, o_resp.rc_resp.F0RC_D1);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RC, l_idx, o_resp.rc_resp.F1RC_D1);

    // Check if we have errors
    FAPI_ASSERT( l_pass,
                 fapi2::EXP_INBAND_LE_DATA_RANGE()
                 .set_TARGET(i_target)
                 .set_FUNCTION(mss::exp::READ_TRAINING_RESPONSE_STRUCT)
                 .set_DATA_SIZE(i_data.size())
                 .set_MAX_INDEX(sizeof(user_response_msdg)),
                 "%s Failed to convert from data to host_fw_response_struct data size %u expected size %u",
                 mss::c_str(i_target), i_data.size(), sizeof(user_response_msdg));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns exp
} // ns mss
