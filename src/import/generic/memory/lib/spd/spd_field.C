/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_field.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file spd_field.C
/// @brief SPD data fields
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <generic/memory/lib/spd/spd_field.H>

namespace mss
{
namespace spd
{

// If a constexpr static data member (since C++11) is odr-used,
// a definition at namespace scope is still required, but it cannot have an initializer.
constexpr mss::field_t<mss::endian::LITTLE> init_fields::REVISION;
constexpr mss::field_t<mss::endian::LITTLE> init_fields::DEVICE_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> init_fields::BASE_MODULE;
constexpr mss::field_t<mss::endian::LITTLE> init_fields::HYBRID;
constexpr mss::field_t<mss::endian::LITTLE> init_fields::HYBRID_MEDIA;
constexpr mss::field_t<mss::endian::LITTLE> init_fields::REF_RAW_CARD;

///
/// @brief Determine if the provided index is within the SPD bounds
///
/// @param[in] i_target OCMB target for traces
/// @param[in] i_index index
/// @param[in] i_size size of binary
/// @param[in] i_ffdc_codes FFDC code
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode index_within_bounds_spd(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const size_t i_index,
    const size_t i_size,
    const uint16_t i_ffdc_codes)
{
    FAPI_ASSERT( i_index < i_size,
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(i_index)
                 .set_LIST_SIZE(i_size)
                 .set_FUNCTION(i_ffdc_codes)
                 .set_TARGET(i_target),
                 "Out of bounds indexing (with %d) on a list of size %d for " TARGTIDFORMAT,
                 i_index, i_size, TARGTID );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;

} // invalid_type_conversion

///
/// @brief Get the provided field from the passed in binary
///
/// @param[in] i_target Target for error traces
/// @param[in] i_field field parameter including byte, start, len
/// @param[in] i_binary binary (SPD/EFD)
/// @param[in] i_ffdc_code FFDC code for error traces
/// @param[out] o_field resulting field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_field_spd(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const mss::field_t<mss::endian::LITTLE>& i_field,
    const std::vector<uint8_t>& i_binary,
    const uint16_t i_ffdc_code,
    uint8_t& o_field)
{
    const size_t BYTE = i_field.get_byte(i_binary);

    // clear out stale state
    o_field = 0;

    // Passes target for better FFDC
    FAPI_TRY(mss::spd::index_within_bounds_spd(i_target, BYTE, i_binary.size(), i_ffdc_code));

    {
        // Extracting desired bits
        // API enforces uint8_t vector data, so no conversion check needed to uint8_t buffer
        fapi2::buffer<uint8_t> l_byte(i_binary[BYTE]);
        FAPI_TRY(l_byte.extractToRight(o_field, i_field.get_start(), i_field.get_length()));
    }

fapi_try_exit:
    return fapi2::current_err;
}


}// spd
}// mss
