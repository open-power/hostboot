/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/timing.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file timing.H
/// @brief Determine effective config for mss settings
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_TIMING_H_
#define _MSS_TIMING_H_

#include <cstdint>
#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/utils/conversions.H>

namespace mss
{

///
/// @brief Enums for ffdc error callout so we know which function had the error
///
enum functions
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
};

enum guard_band : uint16_t
{
    // Used for caclulating spd timing values - from JEDEC rounding algorithm
    // Correction factor is 1% (for DDR3) or 2.5% (for DDR4)
    // when doing integer math, we add-in the inverse correction factor
    // Formula used for derivation:
    // Guardband = 1000 * (1000* correction_factor) - 1
    INVERSE_DDR3_CORRECTION_FACTOR = 989,
    INVERSE_DDR4_CORRECTION_FACTOR = 974,
};

enum class refresh_rate : uint8_t
{
    REF1X = 1,
    REF2X = 2,
    REF4X = 4,
};

namespace spd
{

///
/// @brief Calculates timing value
/// @param[in] i_timing_mtb timing value in MTB units
/// @param[in] i_mtb_multiplier SPD medium timebase
/// @param[in] i_timing_ftb fine offset of timing value
/// @param[in] i_ftb_multiplier SPD fine timebase
/// @return the timing value in picoseconds
///
inline int64_t calc_timing_from_timebase(const int64_t i_timing_mtb,
        const int64_t i_mtb_multiplier,
        const int64_t i_timing_ftb,
        const int64_t i_ftb_multiplier)
{
    // JEDEC algorithm
    const int64_t l_timing_val = i_timing_mtb * i_mtb_multiplier;
    const int64_t l_fine_offset = i_timing_ftb * i_ftb_multiplier;

    return l_timing_val + l_fine_offset;
}

///
/// @brief Helper to compute JEDEC's SPD rounding algorithm
/// to convert ps to nCK
/// @tparam T input type
/// @tparam OT output type
/// @param[in] i_timing_in_ps timing parameter in ps
/// @param[in] i_tck_in_ps  clock period in ps
/// @param[in] i_inverse_corr_factor inverse correction factor (defined by JEDEC)
/// @param[out] o_value_nck the end calculation in nck
/// @return true if overflow didn't occur, false otherwise
/// @note DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<typename T, typename OT>
static inline bool jedec_spd_rounding_alg(const T& i_timing_in_ps,
        const T& i_tck_in_ps,
        const guard_band i_inverse_corr_factor,
        OT& o_val_nck)
{
    // Preliminary nCK calculation, scaled by 1000 per JDEC algorithm
    T l_temp_nck = (i_timing_in_ps * CONVERT_PS_IN_A_NS) / (i_tck_in_ps == 0 ? 1 : i_tck_in_ps);
    l_temp_nck += i_inverse_corr_factor;
    l_temp_nck = l_temp_nck / CONVERT_PS_IN_A_NS;

    // Check for overflow
    // static_cast needed for HB compiler that complains about
    // comparision of two different integral types
    o_val_nck = l_temp_nck;

    FAPI_DBG("Input timing (ps) %d, tCK (ps) %d, temp output %d, output (nCK) %d",
             i_timing_in_ps, i_tck_in_ps, l_temp_nck, o_val_nck);

    return (static_cast<T>(o_val_nck) == l_temp_nck);
}

///
/// @brief Returns clock cycles based on input application period
/// @tparam T input type
/// @tparam OT output type
/// @param[in] i_timing_in_ps timing parameter in ps
/// @param[in] i_tck_in_ps  clock period in ps
/// @param[in] i_inverse_corr_factor inverse correction factor  (defined by JEDEC)
/// @param[out] o_value_nck the end calculation in nck
/// @return FAPI2_RC_SUCCESS iff okay
/// @note DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<typename T, typename OT>
inline fapi2::ReturnCode calc_nck(const T& i_timing_in_ps,
                                  const T& i_tck_in_ps,
                                  const guard_band i_inverse_corr_factor,
                                  OT& o_val_nck)
{
    FAPI_ASSERT( jedec_spd_rounding_alg(i_timing_in_ps,
                                        i_tck_in_ps,
                                        i_inverse_corr_factor,
                                        o_val_nck),
                 fapi2::MSS_INVALID_CAST_CALC_NCK().
                 set_TIMING_PS(i_timing_in_ps).
                 set_NCK_NS(i_tck_in_ps).
                 set_CORRECTION_FACTOR(i_inverse_corr_factor),
                 "Overflow occured. Returned data is %d", o_val_nck);

    // If we don't assert, we don't know what's in current_err ...
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Returns clock cycles form picoseconds based on speed bin
/// Uses SPD rounding algorithm for DDR4
/// @tparam T the target type from which to get the mt/s
/// @tparam OT the output type, derrived from the parameters
/// @param[in] i_target target for the frequency attribute
/// @param[in] timing_in_ps timing parameter in ps
/// @return the clock cycles of timing parameter (provided in ps)
/// @note Uses DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<fapi2::TargetType T, typename OT>
inline OT ps_to_nck( const fapi2::Target<T>& i_target, const OT& i_timing_in_ps)
{
    uint64_t l_freq = 0;
    OT l_tck_in_ps = 0;
    OT l_temp_nck = 0;

    FAPI_TRY( mss::freq( find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq) );

    // No time if MT/s is 0 (well, infinite really but shut up)
    if (l_freq == 0)
    {
        return 0;
    }

    FAPI_TRY( freq_to_ps(l_freq, l_tck_in_ps),
              "Failed freq() accessor" );
    FAPI_TRY( calc_nck(i_timing_in_ps, l_tck_in_ps, INVERSE_DDR4_CORRECTION_FACTOR, l_temp_nck),
              "Failed calc_nck()" );

    return l_temp_nck;

fapi_try_exit:
    // We simply can't work if we can't get the frequency or
    // if we get an unsupported value that can't be converted to a valid tCK (clock period)
    // ...so this should be ok
    FAPI_ERR("Can't get MSS_FREQ, obtained an invalid MSS_FREQ (%d), or overflow occurred - stopping", l_freq);
    fapi2::Assert(false);

    // Keeps compiler happy
    return 0;
}

///
/// @brief Returns clock cycles from nanoseconds
/// Uses SPD rounding algorithm for DDR4
/// @tparam T the target type from which to get the mt/s
/// @tparam OT the output type, derrived from the parameters
/// @param[in] timing_in_ps timing parameter in ps
/// @param[out] o_value_nck the end calculation in nck
/// @return the clock cycles of timing parameter (provided in ps)
/// @note Uses DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<fapi2::TargetType T, typename OT>
inline OT ns_to_nck( const fapi2::Target<T>& i_target, const OT& i_timing_in_ns)
{
    return ps_to_nck(i_target, i_timing_in_ns * CONVERT_PS_IN_A_NS);
}

}// spd

///
/// @brief Returns application clock period (tCK) based on dimm transfer rate
/// @tparam T the fapi2 target
/// @tparam OT output type
/// @param[in] i_target FAPI2 target
/// @param[out] o_tCK_in_ps application period in ps
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
template<fapi2::TargetType T, typename OT>
inline fapi2::ReturnCode clock_period(const fapi2::Target<T>& i_target,
                                      OT& o_tCK_in_ps)
{
    uint64_t l_dimm_transfer_rate = 0;
    FAPI_TRY( freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_dimm_transfer_rate) );

    FAPI_TRY( freq_to_ps(l_dimm_transfer_rate, o_tCK_in_ps) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates refresh interval time
/// @param[in] i_mode fine refresh rate mode
/// @param[in] i_temp_refresh_range temperature refresh range
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode calc_trefi( const refresh_rate i_mode,
                              const uint8_t i_temp_refresh_range,
                              uint64_t& o_timing );

///
/// @brief Calculates Minimum Refresh Recovery Delay Time (different logical rank)
/// @param[in] i_target a target for attributes
/// @param[in] i_mode fine refresh rate mode
/// @param[in] i_density SDRAM density
/// @param[out] o_trfc_in_ps timing val in ps
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode calc_trfc_dlr( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint8_t i_refresh_mode,
                                 const uint8_t i_density,
                                 uint64_t& o_trfc_in_ps );

///
/// @brief DLL locking time *in clocks*
/// @tparam T the fapi2::TargetType of i_target
/// @tparam OT the type of the output location
/// @param[in] i_target a target for attributes
/// @param[out] o_value reference to space into which to store the output
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
template< fapi2::TargetType T, typename OT = uint64_t >
inline fapi2::ReturnCode tdllk( const fapi2::Target<T>& i_target, OT& o_value )
{
    uint64_t l_freq = 0;

    // Calculate tDLLK from our MT/s. Magic numbers (in clocks) from the DDR4 spec
    FAPI_TRY( mss::freq(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq) );
    o_value = (l_freq < fapi2::ENUM_ATTR_MSS_FREQ_MT2133) ? 597 : 768;
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Mode Register Set Command Cycle Time
/// @return constexpr value of 8 clocks
///
constexpr uint64_t tmrd()
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return 8;
}

///
/// @brief Control word to control word delay
/// @return constexpr value of 16 clocks
///
constexpr uint64_t tmrd_l()
{
    // Per DDR4RCD02 Spec Rev 0.85
    return 16;
}

///
/// @brief Stabilization time
/// @return constexpr value of 5 us
///
constexpr uint64_t tstab()
{
    // Per DDR4RCD02 Spec Rev 0.85 CK_t stable
    return 5;
}

///
/// @brief Power-up and RESET calibration time
/// @return constexpr value of 1024 clocks
///
constexpr uint64_t tzqinit()
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return 1024;
}

///
/// @brief Normal operation Full calibration time
/// @return constexpr value of 512 clocks
///
constexpr uint64_t tzqoper()
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return 512;
}

///
/// @brief Normal operation Short calibration time
/// @return constexpr value of 128 clocks
///
constexpr uint64_t tzqcs()
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return 128;
}

///
/// @brief DQS_t/DQS_n delay after write leveling mode is programmed
/// @return constexpr value of 25 clocks
///
constexpr uint64_t twldqsen()
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return 25;
}

///
/// @brief First DQS_t/DQS_n rising edge after write leveling mode is programmed
/// @return constexpr value of 40 clocks
///
constexpr uint64_t twlmrd()
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return 40;
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
/// @brief Mode Register Set command update delay
/// @tparam T fapi2::TargetType of the target used to calculate cycles from ns
/// @param[in] i_target the target used to get clocks
/// @return max(24nCK,15ns) in clocks
///
template< fapi2::TargetType T >
inline uint64_t tmod( const fapi2::Target<T>& i_target )
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return mss::max_ck_ns( i_target, 24, 15 );
}

///
/// @brief Calculate TWLO_TWLOE
/// @tparam T fapi2::TargetType of the target used to calculate cycles from ns
/// @param[in] i_target the target used to get DIMM clocks
/// @return uint64_t, TWLO_TWLOE in cycles
///
template< fapi2::TargetType T >
inline uint64_t twlo_twloe(const fapi2::Target<T>& i_target)
{
    // From mthe PHY databook:
    // 12 + std::max((twldqsen - tmod), (twlo - twlow))
    //    + longest DQS delay in clocks (rounded up) + longest DQ delay in clocks (rounded up)
    // Magic numbers taken from talking with Anuwat (twloe) and reviewing the Centaur code (ldq/ldqs)
    constexpr uint64_t l_dq_ck = 1;
    constexpr uint64_t l_dqs_ck = 1;
    uint8_t l_wlo_ck = 0;
    uint64_t l_wloe_ck = mss::ns_to_cycles(i_target, 2);
    uint64_t l_twlo_twloe = 0;

    FAPI_TRY( mss::vpd_mr_dphy_wlo(i_target, l_wlo_ck) );

    // TODO RTC:160356 This changes if wlo is signed, which it's not but I wonder if it should
    // be ... (the PHY register is.) It changes because we need to round up to 0 if needed.
    l_twlo_twloe = 12 + std::max( (twldqsen() + tmod(i_target)), (l_wlo_ck + l_wloe_ck) ) + l_dq_ck + l_dqs_ck;
    FAPI_INF("twlo_twloe %d for %s", l_twlo_twloe, mss::c_str(i_target));
    return l_twlo_twloe;

fapi_try_exit:
    // We're in deep horseradish if we can't get wlo
    FAPI_ERR("failed to calculate twlo_twloe for %s", mss::c_str(i_target));
    fapi2::Assert(false);
    return 0;
}

///
/// @brief Direct ODT turn on Latency
/// @param[in] i_target the DIMM target used to get attributes
/// @param[out] o_dodt *in clocks*
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode dodt_on( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t& o_dodt )
{
    // CWL + AL + PL - 2.0 per DDR4 Full spec update(79-4B)

    uint8_t l_ca_parity_latency = 0;
    uint8_t l_al = 0;
    uint8_t l_cwl = 0;

    FAPI_TRY( mss::eff_ca_parity_latency(i_target, l_ca_parity_latency) );
    FAPI_TRY( mss::eff_dram_al(i_target, l_al) );
    FAPI_TRY( mss::eff_dram_cwl(i_target, l_cwl) );

    o_dodt = l_cwl + l_al + l_ca_parity_latency - 2;
    FAPI_INF( "dodt_on %s %d", mss::c_str(i_target), o_dodt );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Direct ODT turn off Latency
/// @param[in] i_target the DIMM target used to get attributes
/// @param[out] o_dodt *in clocks*
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode dodt_off( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t& o_dodt )
{
    // Same for all frequencies of DDR4; DDR4 Full spec update(79-4B)
    return dodt_on(i_target, o_dodt);
}

///
/// @brief Direct ODT turn on Latency - max value on port
/// @param[in] i_target the MCA target
/// @param[out] o_dodt *in clocks*
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode max_dodt_on( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, uint8_t& o_dodt )
{
    for (const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        uint8_t l_odt = 0;
        FAPI_TRY( mss::dodt_on(d, l_odt) );

        o_dodt = std::max(o_dodt, l_odt);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Direct ODT turn off Latency - max value on port
/// @param[in] i_target the MCA
/// @param[out] o_dodt *in clocks*
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode max_dodt_off( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, uint8_t& o_dodt )
{
    // Same for all frequencies of DDR4; DDR4 Full spec update(79-4B)
    return max_dodt_on(i_target, o_dodt);
}

// TK RODTon - The use would be for the ODT in the PHY, but the max RODT is equal to or less than
// the max DODTon/off so it would really never be used anyway there anyway. We can implement it if
// we find another need for it.

///
/// @brief Number of memory clock cycles to wait between the write and
/// read command pairs during Write Centering.
/// @return constexpr value of 0 clocks
///
constexpr uint64_t fw_wr_rd()
{
    // Per PHY spec, defaults to 0. Would need an attribute to drive differently
    return 0;
}

///
/// @brief This value sets the delay between a read and write command in memory clock cycles.
/// This delay value is used in two places in the write centering algorithm.
/// @param[in] i_target the MCA
/// @param[out] o_fw_rd_wr *in clocks*
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode fw_rd_wr( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, uint8_t& o_fw_rd_wr )
{
    // From the PHY spec. Also confirmed with S. Wyatt as this is different than the calculation used in Centaur.
    // This field must be set to the larger of the two values in number of memory clock cycles.
    // FW_RD_WR = max(tWTR + 11, AL + tRTP + 3)
    // Note from J. Bialas: The difference between tWTR_S and tWTR_L is that _S is write to read
    // time to different bank groups, while _L is to the same. The algorithm should be switching
    // bank groups so tWTR_S can be used
    uint8_t l_trtp = 0;
    uint8_t l_twtr_s = 0;
    uint8_t l_al = 0;
    FAPI_TRY( mss::eff_dram_trtp(i_target, l_trtp) );
    FAPI_TRY( mss::eff_dram_twtr_s(i_target, l_twtr_s) );
    FAPI_TRY( mss::eff_dram_al(i_target, l_al) );

    o_fw_rd_wr = std::max(l_twtr_s + 11, l_al + l_trtp + 3);
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("Error calculating the delay between a read and write command in memory clock cycles (fw_rd_wr");
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
/// @return value in picoseconds
///
inline uint64_t tras(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    uint64_t l_freq = 0;
    uint64_t l_tras = 0;

    // Frequency is used to determine tRAS
    FAPI_TRY( freq(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq) );

    switch(l_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            l_tras = 34000;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            l_tras = 33000;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            l_tras = 32000;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(l_freq)
                         .set_FUNCTION(TRAS)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         l_freq);
    }

    return l_tras;

fapi_try_exit:

    // We simply can't work if we can't get the frequency or
    // if we get an unsupported value that can't be converted to a valid tCK (clock period)
    // ...so this should be ok
    FAPI_ERR("Can't get MSS_FREQ or obtained an invalid MSS_FREQ (%d) - stopping", l_freq);
    fapi2::Assert(false);

    // Keeps compiler happy
    return 0;
}

///
/// @brief Helper function to find tFAW based speed (MT/s) for 1/2 KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode tfaw_half_kb_page_helper(const fapi2::Target<T>& i_target,
        uint64_t& o_output)
{
    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    uint64_t l_freq = 0;
    FAPI_TRY( freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq),
              "Failed to invoke freq accessor" );

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability.
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(l_freq)
    {
        // static_cast is needed for template deduction of std::max API
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            o_output = std::max( 16, spd::ns_to_nck(i_target, 17) );
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            o_output = std::max( 16, spd::ns_to_nck(i_target, 15) );
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            o_output = std::max( 16, spd::ns_to_nck(i_target, 13) );
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_output = std::max( 16, spd::ns_to_nck(i_target, 12) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(l_freq)
                         .set_FUNCTION(TFAW_HALF_KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         l_freq);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to find tFAW based speed (MT/s) for 1KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode tfaw_1kb_page_helper(const fapi2::Target<T>& i_target,
        uint64_t& o_output)
{
    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    uint64_t l_freq = 0;
    FAPI_TRY( freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq),
              "Failed to invoke freq accessor" );

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability (and ease of debug?).
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(l_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            o_output = std::max( 20, spd::ns_to_nck(i_target, 23) );
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_output = std::max( 20, spd::ns_to_nck(i_target, 21) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(l_freq)
                         .set_FUNCTION(TFAW_ONE_KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         l_freq);
            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to find tFAW based speed (MT/s) for 2KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode tfaw_2kb_page_helper(const fapi2::Target<T>& i_target,
        uint64_t& o_output)
{

    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability.
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    uint64_t l_freq = 0;
    FAPI_TRY( freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq),
              "Failed to invoke freq accessor" );

    switch(l_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_output = std::max( 28, spd::ns_to_nck(i_target, 30) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(l_freq)
                         .set_FUNCTION(TFAW_TW_KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         l_freq);
            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return the minimum allowable tFAW in nck
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[in] i_dram_width the page size
/// @param[out] o_tFAW timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
//
template< fapi2::TargetType T >
fapi2::ReturnCode tfaw( const fapi2::Target<T>& i_target,
                        const uint8_t i_dram_width,
                        uint64_t& o_tFAW )
{
    switch(i_dram_width)
    {
        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4:
            FAPI_TRY( tfaw_half_kb_page_helper(i_target, o_tFAW) );
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8:
            FAPI_TRY( tfaw_1kb_page_helper(i_target, o_tFAW) );
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X16:
            FAPI_TRY( tfaw_2kb_page_helper(i_target, o_tFAW) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_DRAM_WIDTH()
                         .set_DRAM_WIDTH(i_dram_width)
                         .set_DIMM_TARGET(i_target),
                         "Invalid DRAM width with %d for target %s",
                         i_dram_width,
                         mss::c_str(i_target));
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
/// @brief Helper function to find tRRD_L based speed (MT/s) for 1KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode trrd_l_half_and_1kb_page_helper(const fapi2::Target<T>& i_target,
        uint64_t& o_output)
{
    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    uint64_t l_freq = 0;
    FAPI_TRY( freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq),
              "Failed to invoke freq accessor" );

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability (and ease of debug?).
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(l_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            // From the spec: Max(4nCK,5.3ns)
            o_output = std::max( 4, spd::ps_to_nck(i_target, 5300) );
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            // Max(4nCK,4.9ns)
            o_output = std::max( 4, spd::ps_to_nck(i_target, 4900) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(l_freq)
                         .set_FUNCTION(TRRD_L_HALF_AND_1KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         l_freq);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to find tRRD_L based speed (MT/s) for 2KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode trrd_l_2kb_page_helper(const fapi2::Target<T>& i_target,
        uint64_t& o_output)
{

    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    uint64_t l_freq = 0;
    FAPI_TRY( freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq),
              "Failed to invoke freq accessor" );

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability (and ease of debug?).
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(l_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_output = std::max( 4, spd::ps_to_nck(i_target, 6400) );
            break;

        default:
            FAPI_TRY(fapi2::FAPI2_RC_INVALID_PARAMETER, "%s Invalid frequency %lu", mss::c_str(i_target), l_freq);
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
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
fapi2::ReturnCode trrd_l( const fapi2::Target<T>& i_target,
                          const uint8_t i_dram_width,
                          uint64_t& o_tRRD_L )
{
    switch(i_dram_width)
    {
        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4:
        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8:
            FAPI_TRY( trrd_l_half_and_1kb_page_helper(i_target, o_tRRD_L), "Error calculating trrd l for half and 1kb page" );
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X16:
            FAPI_TRY( trrd_l_2kb_page_helper(i_target, o_tRRD_L) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_PAGE_SIZE()
                         .set_DRAM_WIDTH(i_dram_width)
                         .set_DIMM_TARGET(i_target),
                         "%s Recieved an invalid page size: %lu",
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
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode trrd_s_half_and_1kb_page_helper(const fapi2::Target<T>& i_target,
        uint64_t& o_output)
{
    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    uint64_t l_freq = 0;
    FAPI_TRY( freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq),
              "Failed to invoke freq accessor" );

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability (and ease of debug?).
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(l_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            o_output = std::max( 4, spd::ps_to_nck(i_target, 4200) );
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            o_output = std::max( 4, spd::ps_to_nck(i_target, 3700) );
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            o_output = std::max( 4, spd::ps_to_nck(i_target, 3300) );
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_output = std::max( 4, spd::ps_to_nck(i_target, 3000) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(l_freq)
                         .set_FUNCTION(TRRD_S_HALF_AND_1KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         l_freq);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to find tRRD_S based speed (MT/s) for 2KB page
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target the fapi2 target
/// @param[out] o_output timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
static fapi2::ReturnCode trrd_s_2kb_page_helper(const fapi2::Target<T>& i_target,
        uint64_t& o_output)
{
    // Values derived from DDR4 Spec (79-4A)
    // 13.3 Timing Parameters by Speed Grade
    // Table 132. Pg 240
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    uint64_t l_freq = 0;
    FAPI_TRY( freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq),
              "Failed to invoke freq accessor" );

    // It could have been more "efficient" to hand-calculate the answer and
    // use compile time constants to return the answer. To avoid magic
    // numbers and to align (more closely) with the DDR4 JEDEC spec,
    // we let the std library do the work for us for maintainability (and ease of debug?).
    // Could have used compile-time constants to denote the numbers below
    // but they are "random" and vary.
    switch(l_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_output = std::max( 4, spd::ps_to_nck(i_target, 5300) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(l_freq)
                         .set_FUNCTION(TRRD_S_2KB_PAGE_HELPER)
                         .set_DIMM_TARGET(i_target),
                         "%s Invalid frequency %lu",
                         mss::c_str(i_target),
                         l_freq);
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
/// @param[out] o_tRRD_S timing in clocks (nck)
/// @return FAPI2_RC_SUCCESS iff okay
/// @note this is only for non-3DS DIMM
///
template< fapi2::TargetType T >
fapi2::ReturnCode trrd_s( const fapi2::Target<T>& i_target,
                          const uint8_t i_dram_width,
                          uint64_t& o_tRRD_S )
{
    switch(i_dram_width)
    {
        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4:
        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8:
            FAPI_TRY( trrd_s_half_and_1kb_page_helper(i_target, o_tRRD_S), "Error calculating trrd_s for half and 1kb page" );
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X16:
            FAPI_TRY( trrd_s_2kb_page_helper(i_target, o_tRRD_S) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_PAGE_SIZE()
                         .set_DRAM_WIDTH(i_dram_width)
                         .set_DIMM_TARGET(i_target),
                         "%s Recieved an invalid page size: %lu",
                         mss::c_str(i_target),
                         i_dram_width);
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief VREF DQ Enter time *in clocks*
/// @tparam T the fapi2::TargetType of i_target
/// @param[in] i_target a target for attributes
/// @return VREF DQ Enter time *in clocks*
///
template< fapi2::TargetType T >
inline uint64_t tvrefdqe( const fapi2::Target<T>& i_target )
{
    // JEDEC tVREFDQE in ns
    constexpr uint64_t tVREFDQE = 150;
    return ns_to_cycles(i_target, tVREFDQE);
}

///
/// @brief VREF DQ Exit time *in clocks*
/// @tparam T the fapi2::TargetType of i_target
/// @param[in] i_target a target for attributes
/// @return VREF DQ Exit time *in clocks*
///
template< fapi2::TargetType T >
inline uint64_t tvrefdqx( const fapi2::Target<T>& i_target )
{
    // JEDEC tVREFDQX in ns
    constexpr uint64_t tVREFDQX = 150;
    return ns_to_cycles(i_target, tVREFDQX);
}

///
/// @brief CAS_n to CAS_n command delay for different bank group
/// @return constexpr value of 4 clocks
///
constexpr uint64_t tccd_s()
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return 4;
}

} // mss
#endif
