/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/data_engine_utils.C $ */
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

///
/// @file data_engine_utils.C
/// @brief Data engine to set memory driven data
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: CI
// EKB-Mirror-To: hostboot

#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_field.H>

namespace mss
{

///
/// @brief Algorithm to calculate SPD timings in nCK
///
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd SPD binary
/// @param[in] i_timing_mtb MTB
/// @param[in] i_timing_ftb FTB
/// @param[in] i_function the calling function to log for FFDC
/// @param[in] i_timing_name Name for ffdc traces
/// @param[out] o_timing_in_nck nCK calculated timing
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode calc_spd_time_in_nck(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    const uint32_t i_timing_mtb,
    const int32_t i_timing_ftb,
    const uint16_t i_function,
    const char* i_timing_name,
    int32_t& o_timing_in_nck)
{
    uint32_t l_tck_in_ps = 0;
    uint64_t l_freq = 0;
    FAPI_TRY( attr::get_freq(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_dimm), l_freq) );
    FAPI_TRY( freq_to_ps(l_freq, l_tck_in_ps),
              "Failed to calculate clock period (tCK) for %s", spd::c_str(i_dimm) );

    {
        // Calculate the desired timing in ps
        uint32_t l_timing_in_ps = 0;

        const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);
        uint8_t l_mtb = 0;
        uint8_t l_ftb = 0;

        FAPI_TRY( spd::get_timebases(l_ocmb, i_spd, l_mtb, l_ftb) );

        FAPI_DBG("%s medium timebase (ps): %ld, fine timebase (ps): %ld, (MTB): %ld, (FTB): %ld",
                 spd::c_str(l_ocmb), l_mtb, l_ftb, i_timing_mtb, i_timing_ftb );

        l_timing_in_ps = spd::calc_timing_from_timebase(i_timing_mtb, l_mtb, i_timing_ftb, l_ftb);

        // Calculate nck
        FAPI_TRY( spd::calc_nck(i_function, l_timing_in_ps, l_tck_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, o_timing_in_nck),
                  "Error in calculating %s (nCK) for target %s, with value of %d",
                  i_timing_name, spd::c_str(l_ocmb), l_timing_in_ps );

        FAPI_INF("tCK (ps): %d, %s (ps): %d, %s (nck): %d",
                 l_tck_in_ps, i_timing_name, l_timing_in_ps, i_timing_name, o_timing_in_nck);
    }

fapi_try_exit:
    return fapi2::current_err;
}

namespace gen
{

///
/// @brief Get the supported cas latencies as calculated from SPD fields and dimm type
///
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd spd binary
/// @param[in] i_rev spd revision
/// @param[out] o_field supported CL field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_supported_cas_latencies(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    const mss::spd::rev i_rev,
    uint32_t& o_field)
{
    using F = mss::spd::fields<mss::spd::device_type::DDR4, mss::spd::module_params::BASE_CNFG>;

    o_field = 0;

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);
    uint8_t l_first_raw_byte = 0;
    uint8_t l_sec_raw_byte = 0;
    uint8_t l_third_raw_byte = 0;
    uint8_t l_fourth_raw_byte = 0;
    uint8_t l_dimm_type = 0;
    uint32_t l_field = 0;

    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_FIRST_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_first_raw_byte));
    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_SECOND_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_sec_raw_byte));
    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_THIRD_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_third_raw_byte));
    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_FOURTH_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_fourth_raw_byte));

    FAPI_TRY(mss::attr::get_dimm_type(i_dimm, l_dimm_type));

    {
        // Buffers used for bit manipulation
        // Combine Bytes to create bitmap - right aligned
        fapi2::buffer<uint64_t> l_buffer;
        right_aligned_insert(l_buffer, l_fourth_raw_byte, l_third_raw_byte, l_sec_raw_byte, l_first_raw_byte);

        // According to the JEDEC spec:
        // Byte 22 (Bits 7~0) and Byte 23 are reserved in the base revision SPD general section
        // Only bit 6 (right-aligned) for Byte 23 is reserved for subsequent SPD revisions
        // Check for a valid value, and that reserved bit is not set
        // We return Byte 23 arbitrarily as the failed byte, but any byte (20 - 23) would work
        // This rev 1.0 does not apply to DDIMM 1.0 - so make sure we are not a ddimm
        const size_t MAX_VALID_VAL = mss::gen::get_max_valid_cl_val(i_rev, l_dimm_type);

        constexpr uint64_t DATA_START_OFFSET  = 32;
        constexpr uint64_t RESERVED_BIT = DATA_START_OFFSET + 1;
        // Bit 6 of byte 23 must be 0 (reserved for future use)
        const bool RESERVED_BIT_VALUE = l_buffer.getBit<RESERVED_BIT>();

        FAPI_TRY( mss::check::invalid_value(i_dimm,
                                            l_buffer <= MAX_VALID_VAL && !RESERVED_BIT_VALUE,
                                            23,
                                            l_buffer,
                                            mss::BAD_SPD_DATA,
                                            "Failed check on CAS latencies supported") );

        // Update output value only if range check passes
        l_field = uint32_t(l_buffer);

        FAPI_INF("%s. CAS latencies supported (bitmap): 0x%llX",
                 spd::c_str(i_dimm),
                 l_field);
        o_field = l_field;
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns gen

namespace spd
{

///
/// @brief Retrieve SPD data
/// @param[in] i_target the DIMM target
/// @param[out] o_spd reference to std::vector
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode get_raw_data(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    std::vector<uint8_t>& o_spd)
{
    // Get SPD blob size
    size_t l_size = 0;
    FAPI_TRY( fapi2::getSPD(i_target, nullptr, l_size),
              "%s. Failed to retrieve SPD blob size", spd::c_str(i_target) );

    FAPI_DBG( "SPD size %d for %s", l_size, spd::c_str(i_target) );

    // Reassign container size with the retrieved size
    // Arbitrarily set the data to zero since it will be overwritten
    o_spd.assign(l_size, 0);

    // Retrieve SPD data content
    FAPI_TRY( fapi2::getSPD(i_target, o_spd.data(), l_size),
              "%s. Failed to retrieve SPD data", spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

} // ns spd

namespace pmic
{

///
/// @brief Convert PMIC rail voltage offset from SPD to signed offset for attributes
///
/// @param[in] i_offset - unsigned offset value
/// @param[in] i_direction - direction (0 = positive, 1 = negative)
/// @return int8_t signed equivalent
/// @note Should be used with SPD data where the offset is 7 bits such that overflow could not be possible
///
int8_t convert_to_signed_offset(const uint8_t i_offset, const uint8_t i_direction)
{
    // Offset voltage from spd (+/-)
    static constexpr uint8_t OFFSET_MINUS = 1;

    // Since offset value must be 7 bits (from SPD), we can directly cast it to an int8_t
    int8_t l_signed_offset = static_cast<int8_t>(i_offset);

    if (i_direction == OFFSET_MINUS)
    {
        // Can't overflow since signed_offset was only 7 bits
        l_signed_offset = 0 - l_signed_offset;
    }

    return l_signed_offset;
}

} // ns pmic
} // ns mss
