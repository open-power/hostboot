/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/timing.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_TIMING_H_
#define _MSS_TIMING_H_

#include <cstdint>
#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/utils/nimbus_find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/dimm/mss_timing.H>
#include <lib/utils/mss_nimbus_conversions.H>

namespace mss
{

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
    o_value = 854;

    // Calculate tDLLK from our MT/s. Magic numbers (in clocks) from the DDR4 spec
    FAPI_TRY( mss::freq(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq) );

    switch(l_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            o_value = 597;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            o_value = 768;
            break;


        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_value = 854;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_FREQ_PASSED_IN()
                         .set_FREQ(l_freq)
                         .set_FUNCTION(TDLLK)
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
/// @brief Time it takes to do a buffer control word write
/// @return constexpr value of 16 clocks
///
constexpr uint64_t tbcw()
{
    // Per DDR4 buffer JEDEC spec - timing requirements
    return 16;
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
/// @brief Command Pass Disable Delay Time
/// @return constexpr value of 4 clocks
///
constexpr uint64_t tcpded()
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return 4;
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
/// @brief Control word to control word delay for L2 (using F0RC0D or F0RC0F)
/// @return constexpr value of 32 clocks
///
constexpr uint64_t tmrd_l2()
{
    // Per DDR4RCD02 Spec Rev 0.85
    return 32;
}

///
/// @brief Control word F0RC06 with or without geardown mode
/// @note using the geardown mode which is longer for saftey
/// @return constexpr value of 32 clocks
///
constexpr uint64_t tmrc1()
{
    // Per DDR4RCD02 Spec Rev 0.85
    return 32;
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
    return mss::max_ck_ns<T>( i_target, 24, 15 );
}

///
/// @brief RTT change skew
/// @return constexpr value of 1 clock
///
constexpr uint8_t tadc()
{
    // Per DDR4 spec, this value is between 0.3 and 0.7, so round up to 1 clk
    return 1;
}

///
/// @brief Self Refresh Entry delay
/// @tparam T fapi2::TargetType of the target used to calculate cycles from ns
/// @param[in] i_target the target used to get clocks
/// @return max(5nCK,10ns) in clocks
///
template< fapi2::TargetType T >
inline uint64_t tcksre( const fapi2::Target<T>& i_target )
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return mss::max_ck_ns<T>( i_target, 5, 10 );
}

///
/// @brief Self Refresh Exit delay
/// @tparam T fapi2::TargetType of the target used to calculate cycles from ns
/// @param[in] i_target the target used to get clocks
/// @return max(5nCK,10ns) in clocks
///
template< fapi2::TargetType T >
inline uint64_t tcksrx( const fapi2::Target<T>& i_target )
{
    // Per DDR4 Full spec update (79-4A) - timing requirements
    return mss::max_ck_ns<T>( i_target, 5, 10 );
}

///
/// @brief DQS_t/DQS_n delay after write leveling mode is programmed
/// @tparam T fapi2::TargetType of the target used to calculate cycles from ns
/// @param[in] i_target the target used to get tMOD clocks
/// @param[out] o_twldqsen *in clocks*
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode twldqsen( const fapi2::Target<T>& i_target, uint8_t& o_twldqsen )
{
    const uint8_t l_tadc = tadc();
    const auto l_tmod = tmod(i_target);
    uint8_t l_ca_parity_latency = 0;
    uint8_t l_al = 0;
    uint8_t l_cwl = 0;

    FAPI_TRY( mss::eff_ca_parity_latency(i_target, l_ca_parity_latency) );
    FAPI_TRY( mss::eff_dram_al(i_target, l_al) );
    FAPI_TRY( mss::eff_dram_cwl(i_target, l_cwl) );

    // tWLDQSEN >= tMOD + WL + tADC
    // WL = CWL + AL + PL
    o_twldqsen = l_tmod + l_cwl + l_al + l_ca_parity_latency + l_tadc;
    FAPI_INF("twldqsen %d for %s", o_twldqsen, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
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
    // From the PHY databook:
    // 12 + std::max((twldqsen - tmod), (twlo - twlow))
    //    + longest DQS delay in clocks (rounded up) + longest DQ delay in clocks (rounded up)
    // Magic numbers taken from talking with Anuwat (twloe) and reviewing the Centaur code (ldq/ldqs)
    constexpr uint64_t l_dq_ck = 1;
    constexpr uint64_t l_dqs_ck = 1;
    uint8_t l_wlo_ck = 0;
    uint64_t l_wloe_ck = mss::ns_to_cycles<T>(i_target, 2);
    uint64_t l_twlo_twloe = 0;
    uint8_t l_twldqsen = 0;

    FAPI_TRY( mss::eff_dphy_wlo(i_target, l_wlo_ck) );
    FAPI_TRY( mss::twldqsen(i_target, l_twldqsen) );

    // TODO RTC:160356 This changes if wlo is signed, which it's not but I wonder if it should
    // be ... (the PHY register is.) It changes because we need to round up to 0 if needed.
    l_twlo_twloe = 12 + std::max( (l_twldqsen + tmod(i_target)), (l_wlo_ck + l_wloe_ck) ) + l_dq_ck + l_dqs_ck;
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
/// @brief VREF DQ Enter time *in clocks*
/// @tparam T TargetType
/// @return VREF DQ Enter time *in clocks*
/// @note Nimbus specialization
///
template<fapi2::TargetType T>
class tvrefdqe<mss::mc_type::NIMBUS, T>
{
    public:
        static uint64_t get(const fapi2::Target<T>& i_target)
        {
            // JEDEC tVREFDQE in ns
            constexpr uint64_t tVREFDQE = 150;
            return ns_to_cycles<T>(i_target, tVREFDQE);
        }
};

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
    return ns_to_cycles<T>(i_target, tVREFDQX);
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
