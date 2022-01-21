/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_field.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/// @file spd_field.H
/// @brief SPD data fields
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_FIELD_H_
#define _MSS_SPD_FIELD_H_

#include <cstdint>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_field.H>

namespace mss
{
namespace spd
{

///
/// @class common_init_fields
/// @brief Initial fields needed to know how to parse the SPD, common to all SPD across DRAM generations
/// @note These are preliminary fields that need to be independently
/// decoded from any specific DRAM generation SPEC (e.g. SPD factory)
///
class common_init_fields
{
    private:

        enum
        {
            // Byte 1
            REVISION_START = 0,
            REVISION_LEN = 8,

            // Byte 2
            DEVICE_TYPE_START = 0,
            DEVICE_TYPE_LEN = 8,
        };

    public:

        // 1st field: Byte number
        // 2nd field: Start bit
        // 3rd field: Bit length
        static constexpr mss::field_t<mss::endian::LITTLE> REVISION{1, REVISION_START, REVISION_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DEVICE_TYPE{2, DEVICE_TYPE_START, DEVICE_TYPE_LEN};
};

///
/// @class fields
/// @brief Collection of SPD fields
/// @tparam D DRAM device type (e.g. DDR4)
/// @tparam S SPD parameter (e.g. RDIMM_MODULE, NVDIMM_MODULE)
///
template <device_type D, module_params S>
class fields;

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
    const uint16_t i_ffdc_codes);

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
    uint8_t& o_field);

}// spd
}// mss

#endif // _MSS_SPD_FIELD_H_
