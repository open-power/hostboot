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
/// @brief Bad bit getter - Explorer specialization
/// @param[in] i_target the fapi2 target oon which training was conducted
/// @param[out] o_array the bad bits
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
template <>
fapi2::ReturnCode get_bad_dq_bitmap<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t (&o_array)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT])
{
    return mss::attr::get_bad_dq_bitmap(i_target, o_array);
}

///
/// @brief Bad bit setter - Explorer specialization
/// @param[in] i_target the fapi2 target oon which training was conducted
/// @param[in] i_array the bad bits to append
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
template <>
fapi2::ReturnCode set_bad_dq_bitmap<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t (&i_array)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT])
{
    uint8_t l_current_data[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT] = {};

    // Get existing bad bits data
    FAPI_TRY(mss::attr::get_bad_dq_bitmap(i_target, l_current_data));

    // Now, or the new bits and any existing bits together
    mss::combine_bad_bits(l_current_data, i_array);

    FAPI_TRY(mss::attr::set_bad_dq_bitmap(i_target, i_array));

fapi_try_exit:
    return fapi2::current_err;
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
fapi2::ReturnCode read_normal_training_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        user_response_msdg& o_resp)
{
    // We assert at the end to avoid LOTS of fapi asserts
    uint32_t l_idx = 0;
    uint32_t l_version_number = 0;
    bool l_pass = readLE(i_data, l_idx, l_version_number);
    o_resp.version_number = l_version_number;

    FAPI_TRY(read_tm_err_mrs_rc_response<user_response_msdg>(i_target, i_data, l_idx, l_pass, o_resp));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns exp
} // ns mss
