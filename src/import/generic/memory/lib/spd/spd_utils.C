/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_utils.C $               */
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
/// @file spd_utls.C
/// @brief SPD utility function implimentations
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP


#include <generic/memory/lib/spd/spd_utils.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/spd/spd_fields_ddr4.H>

namespace mss
{
namespace spd
{

///
/// @brief Helper function to retrieves medium and fine timebase values
/// @param[in] i_ocmb OCMB target
/// @param[in] i_spd the SPD binary
/// @param[out] o_mtb the medium timebase (MTB) from SPD
/// @param[out] o_ftb the fine timebase (FTB) from SPD
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_timebases(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
    const std::vector<uint8_t>& i_spd,
    uint8_t& o_mtb,
    uint8_t& o_ftb )
{
    using F = mss::spd::fields<DDR4, BASE_CNFG>;

    // =========================================================
    // Byte 17 maps
    // Item JC-45-2220.01x
    // Page 29
    // DDR4 SPD Document Release 3
    // Byte 17 (0x011): Timebases
    // =========================================================
    // Created a maps of a single value in case mapping expands to more values
    static const std::vector<std::pair<uint8_t, uint8_t> > FINE_TIMEBASE_MAP =
    {
        // {key byte, fine timebase (in picoseconds)
        {0, 1}
        // All others reserved
    };

    // =========================================================
    // Byte 17 maps
    // Item JC-45-2220.01x
    // Page 29
    // DDR4 SPD Document Release 3
    // Byte 17 (0x011): Timebases
    // =========================================================
    // Created a maps of a single value in case mapping expands to more values
    static const std::vector<std::pair<uint8_t, uint8_t> > MEDIUM_TIMEBASE_MAP =
    {
        // {key byte, medium timebase (in picoseconds)
        {0, 125}
        // All others reserved
    };

    // Retrieve timing parameters
    uint8_t l_spd_ftb = 0;
    uint8_t l_spd_mtb = 0;

    FAPI_TRY(get_field_spd(i_ocmb, F::MEDIUM_TIMEBASE, i_spd, GET_TIMEBASES_MTB, l_spd_mtb));

    FAPI_ASSERT( mss::find_value_from_key(MEDIUM_TIMEBASE_MAP, l_spd_mtb, o_mtb),
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(l_spd_mtb)
                 .set_DATA(o_mtb)
                 .set_FUNCTION(GET_TIMEBASES_MTB)
                 .set_TARGET(i_ocmb),
                 "Could not find a mapped value that matched the key (%d) for %s",
                 l_spd_mtb, spd::c_str(i_ocmb) );

    FAPI_TRY(get_field_spd(i_ocmb, F::FINE_TIMEBASE, i_spd, GET_TIMEBASES_FTB, l_spd_ftb));

    FAPI_ASSERT( mss::find_value_from_key(FINE_TIMEBASE_MAP, l_spd_ftb, o_ftb),
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(l_spd_ftb)
                 .set_DATA(o_ftb)
                 .set_FUNCTION(GET_TIMEBASES_FTB)
                 .set_TARGET(i_ocmb),
                 "Could not find a mapped value that matched the key (%d) for %s",
                 l_spd_ftb, spd::c_str(i_ocmb) );

    FAPI_DBG("MTB: %d, FTB: %d for %s", o_mtb, o_ftb, spd::c_str(i_ocmb));

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
    using F = mss::spd::fields<mss::spd::device_type::DDR4, mss::spd::module_params::BASE_CNFG>;
    uint8_t l_timing_ftb_unsigned = 0;
    int8_t l_timing_ftb = 0;
    uint8_t l_timing_mtb = 0;
    uint8_t l_medium_timebase = 0;
    uint8_t l_fine_timebase = 0;
    int64_t l_temp = 0;

    // Retrieve timing parameters
    const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);

    FAPI_TRY( get_timebases(l_ocmb, i_spd, l_medium_timebase, l_fine_timebase),
              "%s. Failed get_timebases", spd::c_str(i_dimm) );

    FAPI_TRY(get_field_spd(l_ocmb, F::TCK_MIN, i_spd, GET_TCKMIN, l_timing_mtb));
    FAPI_TRY(get_field_spd(l_ocmb, F::OFFSET_TCK_MIN, i_spd, GET_TCKMIN, l_timing_ftb_unsigned));

    l_timing_ftb = static_cast<int8_t>(l_timing_ftb_unsigned);

    // Calculate timing value
    l_temp = spd::calc_timing_from_timebase(l_timing_mtb,
                                            l_medium_timebase,
                                            l_timing_ftb,
                                            l_fine_timebase);

    // Sanity check
    FAPI_ASSERT(l_temp > 0,
                fapi2::MSS_INVALID_TIMING_VALUE().
                set_VALUE(l_temp).
                set_FUNCTION(GET_TCKMIN).
                set_DIMM_TARGET(i_dimm),
                "%s. tCKmin invalid (<= 0) : %d",
                spd::c_str(i_dimm),
                l_temp);

    o_value = l_temp;

    FAPI_DBG("%s. tCKmin (ps): %d",
             spd::c_str(i_dimm),
             o_value );

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
    using F = mss::spd::fields<mss::spd::device_type::DDR4, mss::spd::module_params::BASE_CNFG>;
    uint8_t l_timing_ftb_unsigned = 0;
    int8_t l_timing_ftb = 0;
    uint8_t l_timing_mtb = 0;
    uint8_t l_medium_timebase = 0;
    uint8_t l_fine_timebase = 0;
    int64_t l_temp = 0;

    // Retrieve timing parameters
    const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);

    FAPI_TRY( get_timebases(l_ocmb, i_spd, l_medium_timebase, l_fine_timebase),
              "%s. Failed get_timebases", spd::c_str(i_dimm) );

    FAPI_TRY(get_field_spd(l_ocmb, F::TCK_MAX, i_spd, GET_TCKMAX, l_timing_mtb));
    FAPI_TRY(get_field_spd(l_ocmb, F::OFFSET_TCK_MAX, i_spd, GET_TCKMAX, l_timing_ftb_unsigned));

    l_timing_ftb = static_cast<int8_t>(l_timing_ftb_unsigned);

    // Calculate timing value
    l_temp = spd::calc_timing_from_timebase(l_timing_mtb,
                                            l_medium_timebase,
                                            l_timing_ftb,
                                            l_fine_timebase);

    // Sanity check
    FAPI_ASSERT(l_temp > 0,
                fapi2::MSS_INVALID_TIMING_VALUE().
                set_VALUE(l_temp).
                set_FUNCTION(GET_TCKMAX).
                set_DIMM_TARGET(i_dimm),
                "%s. tCKmax invalid (<= 0) : %d",
                spd::c_str(i_dimm),
                l_temp);

    o_value = l_temp;

    FAPI_DBG( "%s. tCKmax (ps): %d",
              spd::c_str(i_dimm),
              o_value);

fapi_try_exit:
    return fapi2::current_err;
}

}// spd
}// mss
