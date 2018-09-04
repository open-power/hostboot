/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/freq/gen_mss_freq.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file gen_mss_freq.H
/// @brief Contains frequency traits information
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef _GEN_MSS_FREQ_H_
#define _GEN_MSS_FREQ_H_

#include <generic/memory/lib/utils/freq/gen_mss_freq_traits.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/spd/spd_utils.H>
#include <generic/memory/lib/utils/freq/cas_latency.H>
#include <generic/memory/lib/utils/freq/mss_freq_scoreboard.H>
#include <generic/memory/lib/data_engine/pre_data_init.H>
#include <vpd_access.H>

namespace mss
{
///
/// @brief      Sets DRAM CAS latency attributes
/// @tparam P mss::proc_type on which to operate
/// @tparam T fapi2::TargetType on which to set the frequency
/// @param[in]  i_target the controller target the cas_latency value
/// @param[in]  i_cas_latency cas latency to update
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, fapi2::TargetType T>
fapi2::ReturnCode set_CL_attr(const fapi2::Target<T>& i_target,
                              const uint64_t i_cas_latency);

///
/// @brief      Sets the frequency value
/// @tparam P mss::proc_type on which to operate
/// @tparam T fapi2::TargetType on which to set the frequency
/// @param[in]  i_target the target on which to set the frequency values
/// @param[in]  i_freq frequency value to set
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, fapi2::TargetType T>
fapi2::ReturnCode set_freq(const fapi2::Target<T>& i_target,
                           const uint64_t i_freq);

///
/// @brief      Gets the number of master ranks per DIMM
/// @tparam P mss::proc_type on which to operate
/// @tparam T fapi2::TargetType on which to set the frequency
/// @param[in]  i_target the target on which to set the frequency values
/// @param[out]  o_master_ranks number of master ranks per DIMM
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, fapi2::TargetType T>
fapi2::ReturnCode get_master_rank_per_dimm(const fapi2::Target<T>& i_target,
        uint8_t* o_master_ranks);

///
/// @brief      Sets frequency attributes
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in]  i_target the controller target
/// @param[in]  i_dimm_freq vector of freqs selected dimm freq in MT/s
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
inline fapi2::ReturnCode set_freq_attrs(const fapi2::Target<TT::FREQ_TARGET_TYPE>& i_target,
                                        const std::vector<uint64_t>& i_dimm_freq)
{
    // Find the minimum (but non-0) freq in the vector. If we see all 0's we'll write a 0. However,
    // we shouldn't as the caller should have been dealing with no DIMM before we got here.
    uint64_t l_final_freq = UINT64_MAX;

    for (const auto l_freq : i_dimm_freq)
    {
        if (l_freq != 0)
        {
            l_final_freq = std::min(l_final_freq, l_freq);
        }
    }

    // If we saw all 0's, write a 0.
    l_final_freq = (l_final_freq == UINT64_MAX) ? 0 : l_final_freq;

    {
        // Declaring temporary variables to avoid linker errors associated with FAPI_ASSERT
        const auto FREQ0 = TT::SUPPORTED_FREQ0;
        const auto FREQ1 = TT::SUPPORTED_FREQ1;
        const auto FREQ2 = TT::SUPPORTED_FREQ2;
        const auto FREQ3 = TT::SUPPORTED_FREQ3;

        // If we don't find a valid frequency OR don't get a 0 (nothing configured on this clock domain), then error out
        FAPI_ASSERT( std::binary_search(TT::SUPPORTED_FREQS.begin(), TT::SUPPORTED_FREQS.end(), l_final_freq) ||
                     l_final_freq == 0,
                     fapi2::MSS_BAD_FREQ_CALCULATED()
                     .set_MSS_FREQ(l_final_freq)
                     .set_TARGET(i_target)
                     .set_PROC_TYPE(P)
                     .set_SUPPORTED_FREQ_0(FREQ0)
                     .set_SUPPORTED_FREQ_1(FREQ1)
                     .set_SUPPORTED_FREQ_2(FREQ2)
                     .set_SUPPORTED_FREQ_3(FREQ3),
                     "%s: Calculated FREQ (%d) isn't supported",
                     mss::c_str(i_target),
                     l_final_freq);
    }

    FAPI_INF( "Final Chosen Frequency: %d (%s)", l_final_freq, mss::c_str(i_target) );

    FAPI_TRY(set_freq<P>(i_target, l_final_freq), "%s Failed to set mss freq attribute", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves max frequency each port supports due to DIMM SPD
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to operate
/// @param[out] o_supported_freqs reference to vector of max SPD supported freq for each port
/// @return FAPI2_RC_SUCCESS iff okay
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
inline fapi2::ReturnCode spd_supported_freq(const fapi2::Target<TT::FREQ_TARGET_TYPE>& i_target,
        std::vector<uint32_t>& o_supported_freqs)
{
    uint64_t l_largest_tck = 0;

    // Start with a really high value so we can use std::min to reduce it below
    o_supported_freqs = std::vector<uint32_t>(TT::PORTS_PER_FREQ_DOMAIN, ~(0));

    // Get cached decoder
    std::vector< mss::spd::facade > l_spd_facades;
    FAPI_TRY( get_spd_decoder_list(i_target, l_spd_facades), "%s get decoder - spd", mss::c_str(i_target) );

    // Looking for the biggest application period on an MC.
    // This will further reduce supported frequencies the system can run on.
    for ( const auto& l_cache : l_spd_facades )
    {
        const auto l_dimm = l_cache.get_dimm_target();
        const auto l_port = mss::find_target<TT::PORT_TARGET_TYPE>(l_dimm);
        const auto l_port_pos = mss::relative_pos<TT::FREQ_TARGET_TYPE>(l_port);
        uint64_t l_tckmax_in_ps = 0;
        uint64_t l_tck_min_in_ps = 0;
        uint32_t l_dimm_freq = 0;

        FAPI_TRY( spd::get_tckmax(l_cache, l_tckmax_in_ps),
                  "%s. Failed to get tCKmax", mss::c_str(l_dimm) );
        FAPI_TRY( spd::get_tckmin(l_cache, l_tck_min_in_ps),
                  "%s. Failed to get tCKmin", mss::c_str(l_dimm) );

        // Determine a proposed tCK value that is greater than or equal tCKmin
        // But less than tCKmax
        l_largest_tck = std::max(l_largest_tck, l_tck_min_in_ps);
        l_largest_tck = std::min(l_largest_tck, l_tckmax_in_ps);

        FAPI_TRY( mss::ps_to_freq(l_largest_tck, l_dimm_freq), "%s ps to freq %lu", mss::c_str(i_target), l_largest_tck );
        FAPI_INF("Biggest freq supported from SPD %d MT/s for %s",
                 l_dimm_freq, mss::c_str(l_dimm));

        o_supported_freqs[l_port_pos] = std::min(l_dimm_freq, o_supported_freqs[l_port_pos]);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Create a vector of support freq based on VPD config
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to operate
/// @param[in] i_target target on which to operate for which to get the DIMM configs
/// @param[out] o_vpd_supported_freqs reference to a 2 dimensional vector of supported VPD frequencies for each MCA
/// @return FAPI2_RC_SUCCESS iff ok
///
// Pass in the syncronous target
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode vpd_supported_freqs( const fapi2::Target<TT::FREQ_TARGET_TYPE>& i_target,
                                       std::vector<std::vector<uint32_t>>& o_vpd_supported_freqs)
{
    uint8_t l_rank_count_dimm[TT::MAX_DIMM_PER_PORT] = {};
    uint8_t l_vpd_blob[TT::VPD_KEYWORD_MAX] = {};

    // This bitmap will keep track of the ports we visit.
    // Any we don't are not configured, so will support all frequencies in the scoreboard
    fapi2::buffer<uint8_t> configured_ports;

    // Clearing output Just.In.Case
    o_vpd_supported_freqs.clear();

    for ( size_t l_index = 0; l_index < TT::PORTS_PER_FREQ_DOMAIN; ++l_index )
    {
        o_vpd_supported_freqs.push_back(std::vector<uint32_t>());
    }

    fapi2::VPDInfo<TT::VPD_TARGET_TYPE> l_vpd_info(TT::VPD_BLOB);

    // Just go to find target for the port level
    for( const auto& p : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target) )
    {
        const auto& l_vpd_target = mss::find_target<TT::VPD_TARGET_TYPE>(p);
        const auto l_port_pos = mss::relative_pos<TT::FREQ_TARGET_TYPE>(p);
        FAPI_TRY( configured_ports.setBit(l_port_pos) );

        if( mss::count_dimm(p) == 0 )
        {
            // Cronus lets you have a port w/no DIMMs. In this case, we say the port supports all frequencies
            // TK should this be the processor type OR the MC type?? - SPG
            for( const auto& freq : TT::SUPPORTED_FREQS )
            {
                o_vpd_supported_freqs[l_port_pos].push_back(freq);
            }

            continue;
        }

        // ATTR to update
        // Note: this flat out assumes that we have two DIMM per port max. This goes against the directive to have arrays be dynamic in length and derived from ATTR's
        FAPI_TRY( get_master_rank_per_dimm<P>(p, &(l_rank_count_dimm[0])) );

        l_vpd_info.iv_rank_count_dimm_0 = l_rank_count_dimm[0];
        l_vpd_info.iv_rank_count_dimm_1 = l_rank_count_dimm[1];
        l_vpd_info.iv_is_config_ffdc_enabled = false;

        // Iterate through all supported memory freqs
        for( const auto& freq : TT::SUPPORTED_FREQS )
        {
            l_vpd_info.iv_freq_mhz = freq;

            FAPI_INF("%s. VPD info - frequency: %d MT/s, rank count for dimm_0: %d, dimm_1: %d",
                     mss::c_str(p), l_vpd_info.iv_freq_mhz, l_vpd_info.iv_rank_count_dimm_0, l_vpd_info.iv_rank_count_dimm_1);

            // In order to retrieve the VPD contents we first need the keyword size.
            // If we are unable to retrieve the keyword size then this speed isn't
            // supported in the VPD in Cronus (but not FW) and we skip to the next
            // possible speed bin.

            // So, we'll use VPD access for the IBM specific product data (assuming the vendor of the OCMB's side as well)
            if( fapi2::getVPD(l_vpd_target, l_vpd_info, nullptr) != fapi2::FAPI2_RC_SUCCESS )
            {
                FAPI_INF("Couldn't retrieve MR size from VPD for this config %s -- skipping freq %d MT/s", mss::c_str(p), freq );

                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                continue;
            }

            // Need temporary variables to avoid issues with FAPI_ASSERT and templated variables
            {
                const auto VPD_KW_MAX = TT::VPD_KEYWORD_MAX;
                const auto VPD_BLOB = TT::VPD_BLOB;
                FAPI_ASSERT( l_vpd_info.iv_size <= TT::VPD_KEYWORD_MAX,
                             fapi2::MSS_INVALID_VPD_KEYWORD_MAX().
                             set_MAX(VPD_KW_MAX).
                             set_ACTUAL(l_vpd_info.iv_size).
                             set_KEYWORD(VPD_BLOB).
                             set_MCS_TARGET(i_target),
                             "VPD MR keyword size retrieved: %d, is larger than max: %d for %s",
                             l_vpd_info.iv_size, TT::VPD_KEYWORD_MAX, mss::c_str(i_target));
            }

            // Firmware doesn't do the VPD lookup in the size check so repeat the logic here
            if(  fapi2::getVPD(l_vpd_target, l_vpd_info, &(l_vpd_blob[0])) != fapi2::FAPI2_RC_SUCCESS )
            {
                FAPI_INF("Couldn't retrieve %s data from VPD for this config %s -- skipping freq %d MT/s", TT::VPD_BLOB_NAME,
                         mss::c_str(p), freq );

                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                continue;
            }

            // Add supported freqs to our output
            FAPI_INF("VPD supported freq added: %d for %s", freq, mss::c_str(p) );
            o_vpd_supported_freqs[l_port_pos].push_back(freq);
        }// freqs
    }// mca

    // Mark any ports we didn't visit as supporting all frequencies
    for ( uint64_t l_port_pos = 0; l_port_pos <  TT::PORTS_PER_FREQ_DOMAIN; ++l_port_pos )
    {
        if ( !configured_ports.getBit(l_port_pos) )
        {
            for ( const auto l_freq : TT::SUPPORTED_FREQS )
            {
                o_vpd_supported_freqs[l_port_pos].push_back(l_freq);
            }
        }
    }

    for ( auto& l_freqs : o_vpd_supported_freqs )
    {
        std::sort( l_freqs.begin(), l_freqs.end() );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Finds the minimum dimm frequencies
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to operate
/// @param[in] i_supported_freqs reference to vector of supported frequencies for each port
/// @param[out] o_supported_freqs reference to vector of supported frequencies for each port
/// @return FAPI2_RC_SUCCESS iff okay
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
inline fapi2::ReturnCode find_min_dimm_freq(const fapi2::Target<TT::FREQ_TARGET_TYPE>& i_target,
        const std::vector<uint32_t>& i_supported_freqs,
        std::vector<uint64_t>& o_min_dimm_freq)
{
    for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target) )
    {
        fapi2::ReturnCode l_rc;
        uint64_t l_desired_cl = 0;

        // Get cached decoder
        std::vector< mss::spd::facade > l_spd_facades;
        FAPI_TRY( get_spd_decoder_list(l_port, l_spd_facades) );

        // Instantiation of class that calculates CL algorithm
        mss::cas_latency<TT::MC> l_cas_latency( l_port, l_spd_facades, i_supported_freqs, l_rc );

        FAPI_TRY( l_rc, "%s. Failed to initialize cas_latency ctor", mss::c_str(l_port) );

        if(l_cas_latency.iv_dimm_list_empty)
        {
            // Cannot fail out for an empty DIMM configuration, so default values are set
            FAPI_INF("%s. DIMM list is empty! Setting default values for CAS latency and DIMM speed.",
                     mss::c_str(l_port) );
            l_desired_cl = 0;
        }

        else
        {
            // We set this to a non-0 so we avoid divide-by-zero errors in the conversions which
            // go from clocks to time (and vice versa.) We have other bugs if there was really
            // no MT/s determined and there really is a DIMM installed, so this is ok.
            // We pick the maximum frequency supported by the system as the default.

            uint64_t l_desired_freq = TT::SUPPORTED_FREQS.back();
            uint64_t l_tCKmin = 0;

            // Find CAS latency using JEDEC algorithm
            FAPI_TRY( l_cas_latency.find_cl(l_desired_cl, l_tCKmin), "%s failed to find a cas latency", mss::c_str(i_target) );

            FAPI_INF("%s. Result from CL algorithm, CL (nck): %d, tCK (ps): %d",
                     mss::c_str(l_port), l_desired_cl, l_tCKmin);

            // Find dimm transfer speed from selected tCK
            FAPI_TRY( mss::ps_to_freq(l_tCKmin, l_desired_freq),
                      "%s. Failed ps_to_freq()", mss::c_str(l_port) );

            FAPI_INF("DIMM speed %d from selected tCK (ps): %d for %s",
                     l_desired_freq,
                     l_tCKmin,
                     mss::c_str(l_port));

            o_min_dimm_freq.push_back(l_desired_freq);

        }// end else

        FAPI_TRY(set_CL_attr<P>(l_port, l_desired_cl), "%s. Failed set_CL_attr()", mss::c_str(l_port) );
    } // mca

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Find a list of all supported frequencies
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to operate
/// @param[out] o_supported_freqs reference to vector of supported frequencies for each port
/// @return FAPI2_RC_SUCCESS iff okay
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
inline fapi2::ReturnCode supported_freqs(const fapi2::Target<TT::FREQ_TARGET_TYPE>& i_target,
        std::vector<uint32_t>& o_freqs)
{
    o_freqs.clear();

    freq_scoreboard l_scoreboard(TT::PORTS_PER_FREQ_DOMAIN, TT::SUPPORTED_FREQS);
    std::vector<uint32_t> l_max_freqs(NUM_MAX_FREQS, 0);
    std::vector<std::vector<uint32_t>> l_vpd_supported_freqs;
    std::vector<uint32_t> l_spd_supported_freq;
    std::vector<uint8_t> l_deconfigured = {0};

    // Retrieve system MRW, SPD, and VPD constraints
    FAPI_TRY( max_allowed_dimm_freq<P>(l_max_freqs.data()), "%s max_allowed_dimm_freq", mss::c_str(i_target) );
    FAPI_TRY( spd_supported_freq<P>(i_target, l_spd_supported_freq),
              "%s spd supported freqs", mss::c_str(i_target) );
    FAPI_TRY( vpd_supported_freqs<P>(i_target, l_vpd_supported_freqs),
              "%s vpd supported freqs", mss::c_str(i_target) );

    // Limits the frequency by the Nimbus processor constraints (sync mode)
    FAPI_TRY( limit_freq_by_processor<P>(i_target, l_scoreboard) );

    // Limit frequency scoreboard according to MRW constraints
    FAPI_TRY( limit_freq_by_mrw<P>(i_target, l_max_freqs, l_scoreboard) );

    // Limit frequency scoreboard according to VPD constraints
    FAPI_TRY( limit_freq_by_vpd<P>(i_target, l_vpd_supported_freqs, l_scoreboard) );

    // Limit frequency scoreboard according to SPD (DIMM) constraints
    FAPI_TRY( limit_freq_by_spd<P>(i_target, l_spd_supported_freq, l_scoreboard) );

    // Callout the fewest number of ports to achieve a common shared freq
    FAPI_TRY( l_scoreboard.template resolve<P>(i_target,
              l_vpd_supported_freqs,
              l_deconfigured,
              o_freqs) );

    FAPI_INF("%s supported freqs:", mss::c_str(i_target));

    for (const auto l_freq : o_freqs)
    {
        FAPI_INF("%s            %d", mss::c_str(i_target), l_freq);
    }

fapi_try_exit:
    return fapi2::current_err;
}

namespace check
{

///
/// @brief Checks the final frequency for the system type
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCESS iff okay
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode final_freq(const fapi2::Target<TT::FREQ_TARGET_TYPE>& i_target);

} // check nameespace

///
/// @brief Generates the memory frequency for one frequency domain
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCESS iff okay
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode generate_freq(const fapi2::Target<TT::FREQ_TARGET_TYPE>& i_target)
{
    std::vector<uint64_t> l_min_dimm_freq;
    std::vector<uint32_t> l_supported_freqs;

    // We will first set pre-eff_config attributes
    FAPI_TRY( mss::set_pre_init_attrs<P>(i_target));

    // Get supported freqs for this MCBIST
    FAPI_TRY( mss::supported_freqs<P>(i_target, l_supported_freqs), "%s failed to get supported frequencies",
              mss::c_str(i_target) );

    // Finds the minimum supported DIMM frequencies for this MCBIST
    FAPI_TRY(mss::find_min_dimm_freq<P>(i_target, l_supported_freqs, l_min_dimm_freq),
             "%s. Failed find_min_dimm_freq()", mss::c_str(i_target) );

    FAPI_TRY(mss::set_freq_attrs<P>(i_target, l_min_dimm_freq),
             "%s. Failed set_freq_attrs()", mss::c_str(i_target) );

    // Check MEM/NEST frequency ratio
    FAPI_TRY(mss::check::final_freq<P>(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

}// mss namespace

#endif
