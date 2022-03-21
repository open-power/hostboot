/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/dimm/mss_ddr4_timing.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file mss_ddr4_timing.H
/// @brief Determine DDR4 timings
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_DDR4_TIMING_H_
#define _MSS_DDR4_TIMING_H_

#include <cstdint>
#include <fapi2.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/spd/spd_utils_ddr4.H>

namespace mss
{

///
/// @brief Enums for ffdc error callout so we know which function had the error
///
enum timing_ffdc_codes
{
    TRAS = 0,
    TFAW_HALF_KB_PAGE_HELPER = 1,
    TFAW_ONE_KB_PAGE_HELPER = 2,
    TFAW_TW_KB_PAGE_HELPER = 3,
    TFAW_SLR_X4_HELPER = 4,
    TFAW_SLR_X8_HELPER = 5,
    TRRD_S_SLR = 6,
    TRRD_L_SLR = 7,
    TRRD_L_HALF_AND_1KB_PAGE_HELPER = 8,
    TRRD_S_HALF_AND_1KB_PAGE_HELPER = 9,
    TRRD_S_2KB_PAGE_HELPER = 10,
    TRRD_L_2KB_PAGE_HELPER = 11,
    TRRD_S = 12,
    TRRD_L = 13,
    TFAW = 14,
    TDLLK = 15,
};

enum refresh_rate : uint8_t
{
    REF1X = 1, ///< Refresh rate 1X
    REF2X = 2, ///< Refresh rate 2X
    REF4X = 4, ///< Refresh rate 4X
};

namespace spd
{
namespace ddr4
{

///
/// @brief Returns clock cycles form picoseconds based on speed bin
/// Uses SPD rounding algorithm for DDR4
/// @tparam OT the output type, derrived from the parameters
/// @param[in] i_freq frequency of the DIMM
/// @param[in] timing_in_ps timing parameter in ps
/// @param[out] o_nck the number of clock cycles
/// @return fapi2::ReturnCode
/// @note Uses DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<typename OT>
inline fapi2::ReturnCode ps_to_nck( const uint64_t i_freq, const OT& i_timing_in_ps, OT& o_nck)
{
    OT l_tck_in_ps = 0;
    o_nck = 0;

    // No time if MT/s is 0 (well, infinite really but shut up)
    if (i_freq == 0)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( freq_to_ps(i_freq, l_tck_in_ps),
              "Failed freq() accessor" );
    FAPI_TRY( calc_nck(mss::generic_ffdc_codes::PS_TO_NS_CUSTOM_TIME, i_timing_in_ps, l_tck_in_ps,
                       spd::INVERSE_DDR4_CORRECTION_FACTOR, o_nck),
              "Failed calc_nck()" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Returns clock cycles form nanoseconds based on speed bin
/// Uses SPD rounding algorithm for DDR4
/// @tparam OT the output type, derrived from the parameters
/// @param[in] i_freq frequency of the DIMM
/// @param[in] i_timing_in_ns timing parameter in ns
/// @param[out] o_nck the number of clock cycles
/// @param[out] o_rc a return code used to handle an error
/// @return fapi2::ReturnCode
/// @note Uses DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<typename OT>
inline fapi2::ReturnCode ns_to_nck( const uint64_t i_freq, const OT& i_timing_in_ns, OT& o_nck, fapi2::ReturnCode& o_rc)
{
    return ps_to_nck(i_freq, i_timing_in_ns * CONVERT_PS_IN_A_NS, o_nck, o_rc);
}

///
/// @brief Returns clock cycles form picoseconds based on speed bin
/// Uses SPD rounding algorithm for DDR4
/// @tparam OT the output type, derrived from the parameters
/// @param[in] i_freq frequency of the DIMM
/// @param[in] timing_in_ps timing parameter in ps
/// @param[out] o_rc a return code used to handle an error
/// @return the clock cycles of timing parameter (provided in ps)
/// @note Uses DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<typename OT>
inline OT ps_to_nck( const uint64_t i_freq, const OT& i_timing_in_ps, fapi2::ReturnCode& o_rc)
{
    OT l_tck_in_ps = 0;
    OT l_temp_nck = 0;

    // No time if MT/s is 0 (well, infinite really but shut up)
    if (i_freq == 0)
    {
        return 0;
    }

    FAPI_TRY( freq_to_ps(i_freq, l_tck_in_ps),
              "Failed to convert memory frequency to a valid clock period (%d) - stopping", i_freq);
    FAPI_TRY( ddr4::calc_nck(mss::generic_ffdc_codes::PS_TO_NS_ONE_CLOCK, i_timing_in_ps, l_tck_in_ps,
                             spd::INVERSE_DDR4_CORRECTION_FACTOR, l_temp_nck),
              "Failed to clock period to nck (%d) - stopping", i_freq);

    return l_temp_nck;

fapi_try_exit:
    o_rc = fapi2::current_err;

    // Keeps compiler happy
    return 0;
}

///
/// @brief Returns clock cycles from nanoseconds
/// Uses SPD rounding algorithm for DDR4
/// @tparam OT the output type, derrived from the parameters
/// @param[in] i_freq frequency of the DIMM
/// @param[out] o_value_nck the end calculation in nck
/// @param[out] o_rc a return code used to handle an error
/// @return the clock cycles of timing parameter (provided in ps)
/// @note Uses DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<typename OT>
inline OT ns_to_nck( const uint64_t i_freq, const OT& i_timing_in_ns, fapi2::ReturnCode& o_rc)
{
    return ps_to_nck(i_freq, i_timing_in_ns * CONVERT_PS_IN_A_NS, o_rc);
}

}// ddr4

}// spd

namespace ddr4
{

///
/// @brief VREF DQ Enter time *in clocks*
/// @tparam MC mc_type
/// @return VREF DQ Enter time *in clocks*
///
template< mss::mc_type MC, fapi2::TargetType T>
class tvrefdqe
{
    public:
        static uint64_t get(const fapi2::Target<T>& i_target);
};

///
/// @brief Calculates refresh interval time
/// @param[in] i_mode fine refresh rate mode
/// @param[in] i_refresh_request_rate refresh rate
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
inline fapi2::ReturnCode calc_trefi( const refresh_rate i_mode,
                                     const uint8_t i_refresh_request_rate,
                                     uint64_t& o_timing )
{
    // Proposed DDR4 Full spec update(79-4B)
    // Item No. 1716.78C
    // pg.46
    // Table 24 - tREFI and tRFC parameters (in ps)
    constexpr uint64_t TREFI_BASE = 7800000;

    uint64_t l_refresh_request = 0;
    constexpr double TEN_PERCENT_FASTER = 0.90;

    switch(i_refresh_request_rate)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_SINGLE:
            l_refresh_request = TREFI_BASE;
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_DOUBLE:
            // We are truncating but there is no remainder with TREFI_BASE, so we are okay
            l_refresh_request = TREFI_BASE / 2;
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_SINGLE_10_PERCENT_FASTER:
            // We are truncating but there is no remainder with TREFI_BASE, so we are okay
            // 10% faster so 100% - 10% = 90%
            l_refresh_request = TREFI_BASE * TEN_PERCENT_FASTER;
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_DOUBLE_10_PERCENT_FASTER:
            // We are truncating but there is no remainder with TREFI_BASE, so we are okay
            // 10% faster so 100% - 10% = 90%
            l_refresh_request = (TREFI_BASE / 2) * TEN_PERCENT_FASTER;
            break;

        default:
            // Will catch incorrect MRW value set
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_REFRESH_RATE_REQUEST().set_REFRESH_RATE_REQUEST(i_refresh_request_rate),
                        "Incorrect refresh request rate received: %d ", i_refresh_request_rate);
            break;
    }

    o_timing =  (l_refresh_request / i_mode);

    FAPI_INF( "tREFI (ps): %d, refresh request (ps): %d, tREFI_base (ps): %d, REF%dX",
              o_timing, l_refresh_request, TREFI_BASE, i_mode );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Calculates Minimum Refresh Recovery Delay Time (different logical rank)
/// @param[in] i_target the target on which to operate
/// @param[in] i_mode fine refresh rate mode
/// @param[in] i_density SDRAM density
/// @param[out] o_trfc_in_ps timing val in ps
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode calc_trfc_dlr(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const uint8_t i_refresh_mode,
                                       const uint8_t i_density,
                                       uint64_t& o_trfc_in_ps)
{
    // Proposed DDR4 3DS Addendum
    // Item No. 1727.58A
    // pg. 69 - 71
    // Table 42 - Refresh parameters by logical rank density
    const std::vector<std::pair<uint8_t, uint64_t> > TRFC_DLR1 =
    {
        // { density in GBs, tRFC4(min) in picoseconds }
        {4, 90000},
        {8, 120000},
        {16, 185000},
    };

    // Proposed DDR4 3DS Addendum
    // Item No. 1727.58A
    // pg. 69 - 71
    // Table 42 - Refresh parameters by logical rank density
    const std::vector<std::pair<uint8_t, uint64_t> > TRFC_DLR2 =
    {
        // { density in GBs, tRFC4(min) in picoseconds }
        {4, 55000},
        {8, 90000},
        {16, 120000},
    };

    // Proposed DDR4 3DS Addendum
    // Item No. 1727.58A
    // pg. 69 - 71
    // Table 42 - Refresh parameters by logical rank density
    const std::vector<std::pair<uint8_t, uint64_t> > TRFC_DLR4 =
    {
        // { density in GBs, tRFC4(min) in picoseconds }
        {4, 40000},
        {8, 55000},
        {16, 90000},
    };

    bool l_is_val_found = 0;

    // Selects appropriate tRFC based on fine refresh mode
    switch(i_refresh_mode)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL:
            l_is_val_found = find_value_from_key(TRFC_DLR1, i_density, o_trfc_in_ps);
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_2X:
            l_is_val_found = find_value_from_key(TRFC_DLR2, i_density, o_trfc_in_ps);
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_4X:
            l_is_val_found = find_value_from_key(TRFC_DLR4, i_density, o_trfc_in_ps);
            break;

        default:
            // Fine Refresh Mode will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if openpower messes this up we can at least catch it
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FINE_REFRESH_MODE()
                         .set_FINE_REF_MODE(i_refresh_mode),
                         "Incorrect Fine Refresh Mode received: %d ",
                         i_refresh_mode);
            break;
    }// switch

    FAPI_ASSERT( l_is_val_found,
                 fapi2::MSS_FAILED_TO_FIND_TRFC()
                 .set_SDRAM_DENSITY(i_density)
                 .set_REFRESH_MODE(i_refresh_mode)
                 .set_DIMM_TARGET(i_target),
                 "%s: Unable to find tRFC (ps) from map with SDRAM density key %d with %d refresh mode",
                 mss::c_str(i_target),
                 i_density,
                 i_refresh_mode);

    // Again, FAPI_ASSERT doesn't set current_err to good, only to bad
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief tRTP *in ps*
/// @return constexpr value of RTP = 7500 ps
///
constexpr uint64_t trtp()
{
    // Per JEDEC spec, defaults to 7500 ps for all frequencies.
    // (technically max of 7.5 ns or 4 nclk, which is always 7.5ns for DDR4)
    return 7500;
}

///
/// @brief Return the minimum allowable tRAS in picoseconds
/// @param[in] i_target the fapi2 target
/// @param[in] i_freq freq for the DIMM
/// @return value in picoseconds
///
inline uint64_t tras(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                     const uint64_t i_freq)
{
    uint64_t l_tras = 0;

    switch(i_freq)
    {
        case 1866:
            l_tras = 34000;
            break;

        case 2133:
            l_tras = 33000;
            break;

        case 2400:
        case 2666:
        case 2933:
        case 3200:
            l_tras = 32000;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(i_freq)
                         .set_FUNCTION(TRAS)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu in TRAS",
                         mss::c_str(i_target),
                         i_freq);
    }

    return l_tras;

fapi_try_exit:

    // We simply can't work if we can't get the frequency or
    // if we get an unsupported value that can't be converted to a valid tCK (clock period)
    // ...so this should be ok
    FAPI_ERR("Obtained an invalid MSS_FREQ (%d) - stopping", i_freq);
    fapi2::Assert(false);

    // Keeps compiler happy
    return 0;
}

///
/// @brief Helper function to find tFAW based speed (MT/s) for 1/2 KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[in] i_freq the DRAM frequency
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode tfaw_half_kb_page_helper(const fapi2::Target<T>& i_target,
        const uint64_t i_freq, uint64_t& o_output)
{
    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability.
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(i_freq)
    {
        // static_cast is needed for template deduction of std::max API
        case 1866:
            o_output = std::max( 16, mss::spd::ddr4::ps_to_nck(i_freq, 17000, l_rc) );
            break;

        case 2133:
            o_output = std::max( 16, mss::spd::ddr4::ps_to_nck(i_freq, 15000, l_rc) );
            break;

        case 2400:
            o_output = std::max( 16, mss::spd::ddr4::ps_to_nck(i_freq, 13000, l_rc) );
            break;

        case 2666:
            o_output = std::max( 16, mss::spd::ddr4::ps_to_nck(i_freq, 12000, l_rc) );
            break;

        case 2933:
            o_output = std::max( 16, mss::spd::ddr4::ps_to_nck(i_freq, 10875, l_rc) );
            break;

        case 3200:
            o_output = std::max( 16, mss::spd::ddr4::ps_to_nck(i_freq, 10000, l_rc) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(i_freq)
                         .set_FUNCTION(TFAW_HALF_KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         i_freq);
    }

    FAPI_TRY(l_rc, "%s ps_to_nck failed", mss::c_str(i_target));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to find tFAW based speed (MT/s) for 1KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[in] i_freq the DRAM frequency
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode tfaw_1kb_page_helper(const fapi2::Target<T>& i_target,
        const uint64_t i_freq,
        uint64_t& o_output)
{
    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability (and ease of debug?).
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(i_freq)
    {
        case 1866:
            o_output = std::max( 20, mss::spd::ddr4::ns_to_nck(i_freq, 23, l_rc) );
            break;

        case 2133:
        case 2400:
        case 2666:
        case 2933:
        case 3200:
            o_output = std::max( 20, mss::spd::ddr4::ns_to_nck(i_freq, 21, l_rc) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(i_freq)
                         .set_FUNCTION(TFAW_ONE_KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         i_freq);
            break;
    }

    FAPI_TRY(l_rc, "%s ns_to_nck failed", mss::c_str(i_target));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to find tFAW based speed (MT/s) for 2KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[in] i_freq the DRAM frequency
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode tfaw_2kb_page_helper(const fapi2::Target<T>& i_target,
        const uint64_t i_freq,
        uint64_t& o_output)
{

    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability.
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(i_freq)
    {
        case 1866:
        case 2133:
        case 2400:
        case 2666:
        case 2933:
        case 3200:
            o_output = std::max( 28, mss::spd::ddr4::ns_to_nck(i_freq, 30, l_rc) );
            FAPI_TRY(l_rc, "%s ns_to_nck failed", mss::c_str(i_target));
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(i_freq)
                         .set_FUNCTION(TFAW_TW_KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         i_freq);
            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief tFAW_dlr *in nck*
/// @return 16nck
/// @note From DDR4 3DS Spec
/// 12.2 Timing Parameters by Speed Grade
///
constexpr uint64_t tfaw_dlr()
{
    return 16;
}

///
/// @brief tRRD_dlr *in nck*
/// @return 4nck
/// @note From DDR4 3DS Spec
/// 12.2 Timing Parameters by Speed Grade
///
constexpr uint64_t trrd_dlr()
{
    return 4;
}

///
/// @brief Buffer command word to BCW or DRAM cmd delay
/// @return constexpr value of 16 clocks
///
constexpr uint64_t tmrc()
{
    // DDR4DB01 Spec Rev 1.0 - input timing requirements
    return 16;
}

///
/// @brief Helper function to find tRRD_L based speed (MT/s) for 1KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[in] i_freq the DRAM frequency
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode trrd_l_half_and_1kb_page_helper(const fapi2::Target<T>& i_target,
        const uint64_t i_freq,
        uint64_t& o_output)
{
    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    o_output = 0;
    uint64_t l_ps = 0;
    uint64_t l_nck = 0;

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability (and ease of debug?).
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(i_freq)
    {
        case 1866:
        case 2133:
            // From the spec: Max(4nCK,5.3ns)
            l_ps = 5300;
            break;

        case 2400:
        case 2666:
        case 2933:
        case 3200:
            // Max(4nCK,4.9ns)
            l_ps = 4900;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(i_freq)
                         .set_FUNCTION(TRRD_L_HALF_AND_1KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         i_freq);
    }

    FAPI_TRY(mss::spd::ddr4::ps_to_nck(i_freq, l_ps, l_nck));
    o_output = std::max( uint64_t(4), l_nck );

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to find tRRD_L based speed (MT/s) for 2KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[in] i_freq the DRAM frequency
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode trrd_l_2kb_page_helper(const fapi2::Target<T>& i_target,
        const uint64_t i_freq,
        uint64_t& o_output)
{

    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability (and ease of debug?).
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(i_freq)
    {
        case 1866:
        case 2133:
        case 2400:
        case 2666:
        case 2933:
        case 3200:
            {
                uint64_t l_nck = 0;
                FAPI_TRY(mss::spd::ddr4::ps_to_nck(i_freq, uint64_t(6400), l_nck));
                o_output = std::max( uint64_t(4), l_nck );
            }
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(i_freq)
                         .set_FUNCTION(TRRD_L_2KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         i_freq);
            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return the minimum allowable tRRD_L in nck
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[in] i_dram_width the page size
/// @param[in] i_freq the DRAM frequency
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
fapi2::ReturnCode trrd_l( const fapi2::Target<T>& i_target,
                          const uint8_t i_dram_width,
                          const uint64_t i_freq,
                          uint64_t& o_tRRD_L )
{
    switch(i_dram_width)
    {
        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4:
        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8:
            FAPI_TRY( trrd_l_half_and_1kb_page_helper(i_target, i_freq, o_tRRD_L),
                      "Error calculating trrd l for half and 1kb page" );
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X16:
            FAPI_TRY( trrd_l_2kb_page_helper(i_target, i_freq, o_tRRD_L) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_PAGE_SIZE()
                         .set_DRAM_WIDTH(i_dram_width)
                         .set_DIMM_TARGET(i_target)
                         .set_FUNCTION(TRRD_L),
                         "%s Recieved an invalid page size: %lu in function SET_TRRD_L",
                         mss::c_str(i_target),
                         i_dram_width);
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to find tRRD_S based speed (MT/s) for 1KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[in] i_freq the DRAM frequency
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode trrd_s_half_and_1kb_page_helper(const fapi2::Target<T>& i_target,
        const uint64_t i_freq,
        uint64_t& o_output)
{
    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    o_output = 0;
    uint64_t l_ps = 0;
    uint64_t l_nck = 0;

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability (and ease of debug?).
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(i_freq)
    {
        case 1866:
            l_ps = 4200;
            break;

        case 2133:
            l_ps = 3700;
            break;

        case 2400:
            l_ps = 3300;
            break;

        case 2666:
            l_ps = 3000;
            break;

        case 2933:
            l_ps = 2700;
            break;

        case 3200:
            l_ps = 2500;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(i_freq)
                         .set_FUNCTION(TRRD_S_HALF_AND_1KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu in TRRD_S_HALF_AND_1KB_PAGE_HELPER",
                         mss::c_str(i_target),
                         i_freq);
    }

    FAPI_TRY(mss::spd::ddr4::ps_to_nck(i_freq, l_ps, l_nck));
    o_output = std::max( uint64_t(4), l_nck );

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to find tRRD_S based speed (MT/s) for 2KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[in] i_freq the DRAM frequency
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode trrd_s_2kb_page_helper(const fapi2::Target<T>& i_target,
        const uint64_t i_freq,
        uint64_t& o_output)
{
    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability (and ease of debug?).
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(i_freq)
    {
        case 1866:
        case 2133:
        case 2400:
        case 2666:
        case 2933:
        case 3200:
            {

                uint64_t l_nck = 0;
                FAPI_TRY(mss::spd::ddr4::ps_to_nck(i_freq, uint64_t(5300), l_nck));
                o_output = std::max( uint64_t(4), l_nck );
            }
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(i_freq)
                         .set_FUNCTION(TRRD_S_2KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu in function TRRD_S_2KB_PAGE_HELPER",
                         mss::c_str(i_target),
                         i_freq);
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return the minimum allowable tRRD_S in nck
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[in] i_dram_width the page size
/// @param[in] i_freq the DRAM frequency
/// @param[out] o_tRRD_S timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
fapi2::ReturnCode trrd_s( const fapi2::Target<T>& i_target,
                          const uint8_t i_dram_width,
                          const uint64_t i_freq,
                          uint64_t& o_tRRD_S )
{
    switch(i_dram_width)
    {
        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4:
        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8:
            FAPI_TRY( trrd_s_half_and_1kb_page_helper(i_target, i_freq, o_tRRD_S),
                      "Error calculating trrd_s for half and 1kb page" );
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X16:
            FAPI_TRY( trrd_s_2kb_page_helper(i_target, i_freq, o_tRRD_S) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_PAGE_SIZE()
                         .set_DRAM_WIDTH(i_dram_width)
                         .set_DIMM_TARGET(i_target)
                         .set_FUNCTION(TRRD_S),
                         "%s Recieved an invalid page size: %lu in tRRD_s",
                         mss::c_str(i_target),
                         i_dram_width);
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // ddr4

} // mss
#endif
