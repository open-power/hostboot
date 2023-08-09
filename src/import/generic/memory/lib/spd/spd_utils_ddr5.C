/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_utils_ddr5.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file spd_utils_ddr5.C
/// @brief DDR5 SPD utility functions definitions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/spd/spd_utils_ddr5.H>
#include <generic/memory/lib/spd/spd_utils.H>
#include <generic/memory/lib/spd/spd_fields_ddr5.H>
#include <generic/memory/lib/spd/spd_field.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_generic_attribute_getters.H>

namespace mss
{
namespace spd
{

///
/// @brief Retrieves SDRAM Maximum Cycle Time (tCKmax) from SPD - specialization for ODYSSEY
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd SPD binary
/// @param[out] o_value tCKmax value in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode get_tckmax_helper<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    uint64_t& o_value)
{
    FAPI_TRY( ddr5::get_tckmax(i_dimm, i_spd, o_value) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves SDRAM Minimum Cycle Time (tCKmin) from SPD - specialization for ODYSSEY
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd SPD binary
/// @param[out] o_value tCKmin value in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode get_tckmin_helper<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    uint64_t& o_value)
{
    FAPI_TRY( ddr5::get_tckmin(i_dimm, i_spd, o_value) );

fapi_try_exit:
    return fapi2::current_err;
}

namespace ddr5
{

///
/// @brief Helper function to calculate a DDR5 SPD timing in ps from the SPD
/// @param[in] i_target DIMM target
/// @param[in] i_spd the SPD binary
/// @param[in] i_start_byte the starting byte for this timing
/// @param[in] i_ffdc_codes the FFDC for this timing
/// @param[out] o_time_in_ps the amount of time in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_timing(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const std::vector<uint8_t>& i_spd,
    const uint16_t i_start_byte,
    const uint16_t i_ffdc_codes,
    uint64_t& o_time_in_ps )
{
    o_time_in_ps = 0;
    // In DDR5, two bytes are used for each timing in ps
    // The two bytes are adjacent
    // We use the maximum byte for the boundaries checking
    const auto l_last_byte = i_start_byte + 1;

    // Conducts boundary checking
    FAPI_TRY(mss::spd::index_within_bounds_spd(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target),
             l_last_byte,
             i_spd.size(),
             i_ffdc_codes));

    {
        fapi2::buffer<uint16_t> l_buffer;
        const uint8_t l_lsb = i_spd[i_start_byte];
        const uint8_t l_msb = i_spd[l_last_byte];

        // Inserts the data for this timing into the buffer
        mss::right_aligned_insert(l_buffer, l_msb, l_lsb);

        // SPD notes that a timing of 0 is reserved
        FAPI_ASSERT(l_buffer != 0,
                    fapi2::MSS_INVALID_TIMING_VALUE().
                    set_VALUE(l_buffer).
                    set_FUNCTION(i_ffdc_codes).
                    set_DIMM_TARGET(i_target),
                    "%s. timing is 0 in the SPD for byte %u, which is invalid",
                    spd::c_str(i_target), i_start_byte);
        o_time_in_ps = l_buffer;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to calculate a DDR5 SPD timing in ps from the SPD
/// @param[in] i_target DIMM target
/// @param[in] i_spd the SPD binary
/// @param[in] i_start_byte the starting byte for this timing
/// @param[in] i_ffdc_codes the FFDC for this timing
/// @param[out] o_time_in_ps the amount of time in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
/// Note : PPE compatible version of function
fapi2::ReturnCode get_timing(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint8_t (&i_spd)[mss::spd::DDR5_SPD_SIZE],
    const uint16_t i_start_byte,
    const uint16_t i_ffdc_codes,
    uint64_t& o_time_in_ps )
{
    o_time_in_ps = 0;
    // In DDR5, two bytes are used for each timing in ps
    // The two bytes are adjacent
    // We use the maximum byte for the boundaries checking
    const auto l_last_byte = i_start_byte + 1;

    // Conducts boundary checking
    FAPI_TRY(mss::spd::index_within_bounds_spd(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target),
             l_last_byte,
             mss::spd::DDR5_SPD_SIZE,
             i_ffdc_codes));

    {
        fapi2::buffer<uint16_t> l_buffer;
        const uint8_t l_lsb = i_spd[i_start_byte];
        const uint8_t l_msb = i_spd[l_last_byte];

        // Inserts the data for this timing into the buffer
        mss::right_aligned_insert(l_buffer, l_msb, l_lsb);

        // SPD notes that a timing of 0 is reserved
        FAPI_ASSERT(l_buffer != 0,
                    fapi2::MSS_INVALID_TIMING_VALUE().
                    set_VALUE(l_buffer).
                    set_FUNCTION(i_ffdc_codes).
                    set_DIMM_TARGET(i_target),
                    TARGTIDFORMAT " timing is 0 in the SPD for byte %u, which is invalid",
                    TARGTID, i_start_byte);
        o_time_in_ps = l_buffer;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves SDRAM Minimum Cycle Time (tCKmin) from SPD
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd SPD binary
/// @param[out] o_value tCKmin value in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_tckmin(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    uint64_t& o_value)
{
    using F = mss::spd::fields<mss::spd::device_type::DDR5, mss::spd::module_params::BASE_CNFG>;

    const auto BYTE = F::TCK_MIN_LSB.get_byte(i_spd);
    FAPI_TRY(get_timing(i_dimm, i_spd, BYTE, GET_TCKMIN, o_value), "%s failed to get TCK_MIN", mss::spd::c_str(i_dimm));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves SDRAM Maximum Cycle Time (tCKmax) from SPD
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd SPD binary
/// @param[out] o_value tCKmax value in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_tckmax(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    uint64_t& o_value)
{
    using F = mss::spd::fields<mss::spd::device_type::DDR5, mss::spd::module_params::BASE_CNFG>;

    const auto BYTE = F::TCK_MAX_LSB.get_byte(i_spd);
    FAPI_TRY(get_timing(i_dimm, i_spd, BYTE, GET_TCKMAX, o_value), "%s failed to get TCK_MAX", mss::spd::c_str(i_dimm));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves an nCK value from the SPD with byte checking
/// @param[in] i_target DIMM target
/// @param[in] i_spd the SPD binary
/// @param[in] i_start_byte the starting byte for this timing
/// @param[in] i_ffdc_codes the FFDC for this timing
/// @param[out] o_time_in_nck the amount of time in nck
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Should be used for 3 byte timing values, specifcally timings from bytes 70-84
///
fapi2::ReturnCode get_nck_for_timing_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const std::vector<uint8_t>& i_spd,
    const uint16_t i_start_byte,
    const uint16_t i_ffdc_codes,
    uint8_t& o_time_in_nck )
{
    o_time_in_nck = 0;
    // In DDR5, for certain timings:
    //    two bytes are used for each timing in ps
    //    one byte is used for each timing as a lower clock limit in nCK
    // The three bytes are adjacent
    // The third byte contains the nCK lower clock limit
    const auto l_timing_byte = i_start_byte + 2;

    // Conducts boundary checking
    FAPI_TRY(mss::spd::index_within_bounds_spd(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target),
             l_timing_byte,
             i_spd.size(),
             i_ffdc_codes));

    {
        o_time_in_nck = i_spd[l_timing_byte];

        // SPD notes that a timing of 0 is reserved
        FAPI_ASSERT(o_time_in_nck != 0,
                    fapi2::MSS_INVALID_TIMING_VALUE().
                    set_VALUE(l_timing_byte).
                    set_FUNCTION(i_ffdc_codes).
                    set_DIMM_TARGET(i_target),
                    "%s. timing is 0 in the SPD for byte:%u, which is invalid",
                    spd::c_str(i_target), l_timing_byte);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves an nCK value from the SPD with byte checking
/// @param[in] i_target DIMM target
/// @param[in] i_spd the SPD binary
/// @param[in] i_start_byte the starting byte for this timing
/// @param[in] i_ffdc_codes the FFDC for this timing
/// @param[out] o_time_in_nck the amount of time in nck
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Should be used for 3 byte timing values, specifcally timings from bytes 70-84
///
/// Note : PPE compatible version of function
fapi2::ReturnCode get_nck_for_timing_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint8_t (&i_spd)[mss::spd::DDR5_SPD_SIZE],
    const uint16_t i_start_byte,
    const uint16_t i_ffdc_codes,
    uint8_t& o_time_in_nck )
{
    o_time_in_nck = 0;
    // In DDR5, for certain timings:
    //    two bytes are used for each timing in ps
    //    one byte is used for each timing as a lower clock limit in nCK
    // The three bytes are adjacent
    // The third byte contains the nCK lower clock limit
    const auto l_timing_byte = i_start_byte + 2;

    // Conducts boundary checking
    FAPI_TRY(mss::spd::index_within_bounds_spd(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target),
             l_timing_byte,
             mss::spd::DDR5_SPD_SIZE,
             i_ffdc_codes));

    {
        o_time_in_nck = i_spd[l_timing_byte];

        // SPD notes that a timing of 0 is reserved
        FAPI_ASSERT(o_time_in_nck != 0,
                    fapi2::MSS_INVALID_TIMING_VALUE().
                    set_VALUE(l_timing_byte).
                    set_FUNCTION(i_ffdc_codes).
                    set_DIMM_TARGET(i_target),
                    TARGTIDFORMAT " timing is 0 in the SPD for byte:%u, which is invalid",
                    TARGTID, l_timing_byte);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves an nCK value from the SPD for a timing with a lower clock limit
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd the SPD binary
/// @param[in] i_start_byte the starting byte for this timing
/// @param[in] i_ffdc_codes the FFDC for this timing
/// @param[in] i_tck_in_ps the number of ps to a single clock cycle
/// @param[out] o_time_in_ps the amount of time in nck
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Should be used for 3 byte timing values, specifcally timings from bytes 70-84
///
fapi2::ReturnCode get_nck_with_lower_clock_limit(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    const uint16_t i_start_byte,
    const uint16_t i_ffdc_codes,
    const uint64_t i_tck_in_ps,
    uint8_t& o_time_in_nck )
{
    uint64_t l_time_in_ps = 0;
    uint8_t l_calculated_nck = 0;
    uint8_t l_spd_nck = 0;

    o_time_in_nck = 0;

    // Calculate the timing in nCK from the minimum timing provided by the SPD
    FAPI_TRY(get_timing(i_dimm, i_spd, i_start_byte, i_ffdc_codes, l_time_in_ps ));
    FAPI_TRY(calc_nck(i_ffdc_codes, l_time_in_ps, i_tck_in_ps, l_calculated_nck));

    // Get the lower clock limit timing: the minimum number of allowed cycles provided by the SPD
    FAPI_TRY(get_nck_for_timing_helper(i_dimm, i_spd, i_start_byte, i_ffdc_codes, l_spd_nck ));

    // The timing is the worst case between the calculated timing in nCK and the lower clock limit value provided in the SPD
    o_time_in_nck = std::max(l_calculated_nck, l_spd_nck);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves an nCK value from the SPD for a timing with a lower clock limit
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd the SPD binary
/// @param[in] i_start_byte the starting byte for this timing
/// @param[in] i_ffdc_codes the FFDC for this timing
/// @param[in] i_tck_in_ps the number of ps to a single clock cycle
/// @param[out] o_time_in_ps the amount of time in nck
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Should be used for 3 byte timing values, specifcally timings from bytes 70-84
///
/// Note : PPE compatible version of function
fapi2::ReturnCode get_nck_with_lower_clock_limit(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const uint8_t (&i_spd)[mss::spd::DDR5_SPD_SIZE],
    const uint16_t i_start_byte,
    const uint16_t i_ffdc_codes,
    const uint64_t i_tck_in_ps,
    uint8_t& o_time_in_nck )
{
    uint64_t l_time_in_ps = 0;
    uint8_t l_calculated_nck = 0;
    uint8_t l_spd_nck = 0;

    o_time_in_nck = 0;

    // Calculate the timing in nCK from the minimum timing provided by the SPD
    FAPI_TRY(get_timing(i_dimm, i_spd, i_start_byte, i_ffdc_codes, l_time_in_ps ));
    FAPI_TRY(calc_nck(i_ffdc_codes, l_time_in_ps, i_tck_in_ps, l_calculated_nck));

    // Get the lower clock limit timing: the minimum number of allowed cycles provided by the SPD
    FAPI_TRY(get_nck_for_timing_helper(i_dimm, i_spd, i_start_byte, i_ffdc_codes, l_spd_nck ));

    // The timing is the worst case between the calculated timing in nCK and the lower clock limit value provided in the SPD
    o_time_in_nck = std::max(l_calculated_nck, l_spd_nck);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief A helper to process TRFC values, which depend upon the refresh mode
///
/// @param[in] i_port port target
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd SPD binary
/// @param[in] i_start_byte the starting SPD byte to process for this two byte field
/// @param[in] i_ffdc the ffdc code for this byte
/// @param[in] i_refresh_mode the refresh mode for this system
/// @param[out] o_timing_ck the computed timing value in clock cycles
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note This is largely for unit testing. the refresh mode is an MRW which cannot be changed
///
fapi2::ReturnCode process_trfc_nck( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
                                    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                                    const std::vector<uint8_t>& i_spd,
                                    const uint64_t i_start_byte,
                                    const generic_ffdc_codes i_ffdc,
                                    const uint8_t i_refresh_mode,
                                    uint16_t& o_timing_ck)
{
    // The refresh modes are offset by 2 bytes for the fine refresh mode
    constexpr uint64_t REFRESH_MODE_BYTE_OFFSET = 2;
    const auto START_BYTE = i_refresh_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL ? i_start_byte :
                            i_start_byte + REFRESH_MODE_BYTE_OFFSET;

    o_timing_ck = 0;
    uint64_t l_timing_in_ns = 0;
    uint64_t l_timing_in_ps = 0;

    // First up, grab the value of tCK in picoseconds for this frequency
    uint64_t l_freq = 0;
    uint64_t l_tck_in_ps = 0;
    FAPI_TRY(mss::attr::get_freq(i_port, l_freq));
    FAPI_TRY(mss::freq_to_ps(l_freq, l_tck_in_ps));

    // Now grab the timing value in NANOseconds -> this is why we can't use the helper function
    FAPI_TRY(mss::spd::ddr5::get_timing(i_dimm, i_spd, START_BYTE, i_ffdc, l_timing_in_ns));
    l_timing_in_ps = l_timing_in_ns * CONVERT_PS_IN_A_NS;

    // Finally, convert the timing from picoseconds to clock cycles
    FAPI_TRY(mss::spd::ddr5::calc_nck(i_ffdc, l_timing_in_ps, l_tck_in_ps, o_timing_ck));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief A helper to process TRFC values, which depend upon the refresh mode
///
/// @param[in] i_port port target
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd SPD binary
/// @param[in] i_start_byte the starting SPD byte to process for this two byte field
/// @param[in] i_ffdc the ffdc code for this byte
/// @param[in] i_refresh_mode the refresh mode for this system
/// @param[out] o_timing_ck the computed timing value in clock cycles
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note This is largely for unit testing. the refresh mode is an MRW which cannot be changed
///
/// Note : PPE compatible version of function
fapi2::ReturnCode process_trfc_nck( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
                                    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                                    const uint8_t (&i_spd)[mss::spd::DDR5_SPD_SIZE],
                                    const uint64_t i_start_byte,
                                    const generic_ffdc_codes i_ffdc,
                                    const uint8_t i_refresh_mode,
                                    uint16_t& o_timing_ck)
{
    // The refresh modes are offset by 2 bytes for the fine refresh mode
    constexpr uint64_t REFRESH_MODE_BYTE_OFFSET = 2;
    const auto START_BYTE = i_refresh_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL ? i_start_byte :
                            i_start_byte + REFRESH_MODE_BYTE_OFFSET;

    o_timing_ck = 0;
    uint64_t l_timing_in_ns = 0;
    uint64_t l_timing_in_ps = 0;

    // First up, grab the value of tCK in picoseconds for this frequency
    uint64_t l_freq = 0;
    uint64_t l_tck_in_ps = 0;
    FAPI_TRY(mss::attr::get_freq(i_port, l_freq));
    FAPI_TRY(mss::freq_to_ps(l_freq, l_tck_in_ps));

    // Now grab the timing value in NANOseconds -> this is why we can't use the helper function
    FAPI_TRY(mss::spd::ddr5::get_timing(i_dimm, i_spd, START_BYTE, i_ffdc, l_timing_in_ns));
    l_timing_in_ps = l_timing_in_ns * CONVERT_PS_IN_A_NS;

    // Finally, convert the timing from picoseconds to clock cycles
    FAPI_TRY(mss::spd::ddr5::calc_nck(i_ffdc, l_timing_in_ps, l_tck_in_ps, o_timing_ck));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief A helper to process TREFI values, which depend upon the refresh mode
///
/// @param[in] i_port port target
/// @param[in] i_refresh_mode the refresh mode for this system
/// @param[in] i_refresh_request_rate the refresh request_rate for this system
/// @param[out] o_timing_ck the computed timing value in clock cycles
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note This is largely for unit testing. the refresh mode is an MRW which cannot be changed
///
fapi2::ReturnCode process_trefi_nck( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
                                     const uint8_t i_refresh_mode,
                                     const uint8_t i_refresh_request_rate,
                                     uint16_t& o_timing_ck)
{
    // Grab the appropriate TREFI based upon the refresh mode - taken from 4.13.5 in JEDEC spec rev 1.7.1
    constexpr uint64_t TREFI1_PS = 3900000;
    constexpr uint64_t TREFI2_PS = 1950000;
    constexpr uint64_t TREFI4_PS = 975000;
    uint64_t TREFI_PS = 0;
    //Since SBE might not Support Double / Float Pre-Calculate the Values
    constexpr uint64_t TEN_PERCENT_FASTER_TREFI1 = TREFI1_PS - (TREFI1_PS / 10);
    constexpr uint64_t TEN_PERCENT_FASTER_TREFI2 = TREFI2_PS - (TREFI2_PS / 10);
    constexpr uint64_t TEN_PERCENT_FASTER_TREFI4 = TREFI4_PS - (TREFI4_PS / 10);

    switch(i_refresh_request_rate)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_SINGLE:
            TREFI_PS = (i_refresh_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL) ? TREFI1_PS : TREFI2_PS;
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_DOUBLE:
            TREFI_PS = (i_refresh_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL) ? TREFI2_PS : TREFI4_PS;
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_SINGLE_10_PERCENT_FASTER:
            TREFI_PS = (i_refresh_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL) ?
                       TEN_PERCENT_FASTER_TREFI1 : TEN_PERCENT_FASTER_TREFI2;
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_DOUBLE_10_PERCENT_FASTER:
            TREFI_PS = (i_refresh_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL) ?
                       TEN_PERCENT_FASTER_TREFI2 : TEN_PERCENT_FASTER_TREFI4;
            break;

        default:
            TREFI_PS = (i_refresh_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL) ? TREFI1_PS : TREFI2_PS;
            break;
    }

    // Grab the value of tCK in picoseconds for this frequency
    uint64_t l_freq = 0;
    uint64_t l_tck_in_ps = 0;
    FAPI_TRY(mss::attr::get_freq(i_port, l_freq));
    FAPI_TRY(freq_to_ps(l_freq, l_tck_in_ps));

    // Compute the value
    FAPI_TRY(mss::spd::ddr5::calc_nck(generic_ffdc_codes::SET_DRAM_TREFI, TREFI_PS, l_tck_in_ps, o_timing_ck));

fapi_try_exit:
    return fapi2::current_err;
}

}// ddr5

}// spd

}// mss
