/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/freq/gen_mss_freq.H $     */
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
/// @file gen_mss_freq.H
/// @brief Contains frequency traits information
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef _GEN_MSS_FREQ_H_
#define _GEN_MSS_FREQ_H_

#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq_traits.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/spd/spd_utils.H>
#include <generic/memory/lib/utils/freq/cas_latency.H>
#include <generic/memory/lib/utils/freq/mss_freq_scoreboard.H>
#include <generic/memory/lib/utils/count_dimm.H>
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
/// @param[in]  i_target the target on which to get the number of master ranks per DIMM
/// @param[out] o_master_ranks number of master ranks per DIMM
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>, fapi2::TargetType T>
fapi2::ReturnCode get_master_rank_per_dimm(const fapi2::Target<T>& i_target,
        uint8_t* o_master_ranks);

///
/// @brief      Gets the number of master ranks per DIMM
/// @tparam P mss::proc_type on which to operate
/// @tparam T fapi2::TargetType on which to get the DIMM types
/// @param[in]  i_target the target on which to get the DIMM types
/// @param[out] o_dimm_type DIMM types
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>, fapi2::TargetType T>
fapi2::ReturnCode get_dimm_type(const fapi2::Target<T>& i_target,
                                uint8_t* o_dimm_type);

///
/// @brief Calls out the code if we calculated a bad frequency for the domain
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target target on which to operate
/// @param[in] i_final_freq frequency calculated for domain
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode callout_bad_freq_calculated(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
        const uint64_t i_final_freq);

///
/// @brief Configures the number of ranks in the VPD accessor dependent upon DIMM type
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to set the frequency values
/// @param[in,out] io_vpd_info VPD information that needs to be configured
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode configure_vpd_ranks(const fapi2::Target<TT::PORT_TARGET_TYPE>& i_target,
                                      fapi2::VPDInfo<TT::VPD_TARGET_TYPE>& io_vpd_info);

///
/// @brief Checks to see if a specific VPD configuration is valid
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to operate
/// @param[in] i_proposed_freq frequency to check for support
/// @param[in,out] io_vpd_info VPDInfo instance to use
/// @param[out] o_supported true if VPD supports the proposed frequency
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode is_vpd_config_supported( const fapi2::Target<TT::VPD_TARGET_TYPE>& i_target,
        const uint64_t i_proposed_freq,
        fapi2::VPDInfo<TT::VPD_TARGET_TYPE>& io_vpd_info,
        bool& o_supported)
{
    uint8_t l_vpd_blob[TT::VPD_KEYWORD_MAX] = {};

    // We are unsupported by default
    o_supported = false;

    // In order to retrieve the VPD contents we first need the keyword size.
    // If we are unable to retrieve the keyword size then this speed isn't
    // supported in the VPD in Cronus (but not FW) and we skip to the next
    // possible speed bin.

    // So, we'll use VPD access for the IBM specific product data (assuming the vendor of the OCMB's side as well)
    if( fapi2::getVPD(i_target, io_vpd_info, nullptr) != fapi2::FAPI2_RC_SUCCESS )
    {
        FAPI_INF("Couldn't retrieve MR size from VPD for this config %s -- skipping freq %d MT/s",
                 mss::c_str(i_target), i_proposed_freq );

        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Need temporary variables to avoid issues with FAPI_ASSERT and templated variables
    {
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        const auto VPD_KW_MAX = TT::VPD_KEYWORD_MAX;
        const auto VPD_BLOB = TT::VPD_BLOB;
        FAPI_ASSERT( io_vpd_info.iv_size <= TT::VPD_KEYWORD_MAX,
                     fapi2::MSS_INVALID_VPD_KEYWORD_MAX().
                     set_MAX(VPD_KW_MAX).
                     set_ACTUAL(io_vpd_info.iv_size).
                     set_KEYWORD(VPD_BLOB).
                     set_VPD_TARGET(i_target),
                     "VPD MR keyword size retrieved: %d, is larger than max: %d for %s",
                     io_vpd_info.iv_size, TT::VPD_KEYWORD_MAX, mss::c_str(i_target));
    }

    // Firmware doesn't do the VPD lookup in the size check so repeat the logic here
    if(  fapi2::getVPD(i_target, io_vpd_info, &(l_vpd_blob[0])) != fapi2::FAPI2_RC_SUCCESS )
    {
        FAPI_INF("Couldn't retrieve %s data from VPD for this config %s -- skipping freq %d MT/s", TT::VPD_BLOB_NAME,
                 mss::c_str(i_target), i_proposed_freq );

        return fapi2::FAPI2_RC_SUCCESS;
    }

    // If we made it here, it means the frequency was supported for this config
    o_supported = true;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check VPD config for support of a given freq
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to operate
/// @param[in] i_proposed_freq frequency to check for support
/// @param[out] o_supported true if VPD supports the proposed frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode check_freq_support_vpd( const fapi2::Target<TT::PORT_TARGET_TYPE>& i_target,
        const uint64_t i_proposed_freq,
        bool& o_supported);

///
/// @brief      Sets frequency attributes
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in]  i_target the controller target
/// @param[in]  i_dimm_freq vector of freqs selected dimm freq in MT/s
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
inline fapi2::ReturnCode set_freq_attrs(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
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

    FAPI_TRY(callout_bad_freq_calculated<P>(i_target, l_final_freq));

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
inline fapi2::ReturnCode spd_supported_freq(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
        std::vector<uint32_t>& o_supported_freqs)
{
    uint64_t l_largest_tck = 0;

    // Start with a really high value so we can use std::min to reduce it below
    o_supported_freqs = std::vector<uint32_t>(TT::PORTS_PER_FREQ_DOMAIN, ~(0));

    // Looking for the biggest application period on an MC.
    // This will further reduce supported frequencies the system can run on.
    for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target))
    {
        for ( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port) )
        {
            std::vector<uint8_t> l_spd;

            const auto l_port_pos = mss::relative_pos<TT::FREQ_DOMAIN_TARGET_TYPE>(l_port);
            uint64_t l_tckmax_in_ps = 0;
            uint64_t l_tck_min_in_ps = 0;
            uint32_t l_dimm_freq = 0;

            FAPI_TRY(mss::spd::get_raw_data(l_dimm, l_spd));
            FAPI_TRY( spd::get_tckmax(l_dimm, l_spd, l_tckmax_in_ps),
                      "%s. Failed to get tCKmax", mss::c_str(l_dimm) );
            FAPI_TRY( spd::get_tckmin(l_dimm, l_spd, l_tck_min_in_ps),
                      "%s. Failed to get tCKmin", mss::c_str(l_dimm) );

            // Determine a proposed tCK value that is greater than or equal tCKmin
            // But less than tCKmax
            l_largest_tck = std::max(l_largest_tck, l_tck_min_in_ps);
            l_largest_tck = std::min(l_largest_tck, l_tckmax_in_ps);

            FAPI_TRY( mss::ps_to_freq(l_largest_tck, l_dimm_freq), "%s ps to freq %lu", mss::c_str(i_target), l_largest_tck );
            FAPI_DBG("Biggest freq supported from SPD %d MT/s for %s",
                     l_dimm_freq, mss::c_str(l_dimm));

            o_supported_freqs[l_port_pos] = std::min(l_dimm_freq, o_supported_freqs[l_port_pos]);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Create a vector of support freq based on VPD config
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to operate
/// @param[out] o_vpd_supported_freqs reference to a 2 dimensional vector of supported VPD frequencies for each MCA
/// @return FAPI2_RC_SUCCESS iff ok
///
// Pass in the syncronous target
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode vpd_supported_freqs( const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
                                       std::vector<std::vector<uint32_t>>& o_vpd_supported_freqs)
{
    // This bitmap will keep track of the ports we visit.
    // Any we don't are not configured, so will support all frequencies in the scoreboard
    fapi2::buffer<uint64_t> configured_ports;

    // Clearing output Just.In.Case
    o_vpd_supported_freqs.clear();

    for ( size_t l_index = 0; l_index < TT::PORTS_PER_FREQ_DOMAIN; ++l_index )
    {
        o_vpd_supported_freqs.push_back(std::vector<uint32_t>());
    }

    // Just go to find target for the port level
    for( const auto& p : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target) )
    {
        const auto l_port_pos = mss::relative_pos<TT::FREQ_DOMAIN_TARGET_TYPE>(p);

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

        // Iterate through all supported memory freqs
        for( const auto& freq : TT::SUPPORTED_FREQS )
        {
            bool l_supported = false;

            FAPI_TRY(check_freq_support_vpd<P>(p, freq, l_supported));

            // Add supported freqs to our output
            if (l_supported)
            {
                FAPI_DBG("VPD supported freq added: %d for %s", freq, mss::c_str(p) );
                o_vpd_supported_freqs[l_port_pos].push_back(freq);
            }
        }
    }

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
inline fapi2::ReturnCode find_min_dimm_freq(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
        const std::vector<uint32_t>& i_supported_freqs,
        std::vector<uint64_t>& o_min_dimm_freq)
{
    for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target) )
    {
        fapi2::ReturnCode l_rc;
        uint64_t l_desired_cl = 0;

        // Instantiation of class that calculates CL algorithm
        mss::cas_latency<TT::MC> l_cas_latency( l_port, i_supported_freqs, l_rc );

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

            FAPI_DBG("%s. Result from CL algorithm, CL (nck): %d, tCK (ps): %d",
                     mss::c_str(l_port), l_desired_cl, l_tCKmin);

            // Find dimm transfer speed from selected tCK
            FAPI_TRY( mss::ps_to_freq(l_tCKmin, l_desired_freq),
                      "%s. Failed ps_to_freq()", mss::c_str(l_port) );

            FAPI_DBG("DIMM speed %d from selected tCK (ps): %d for %s",
                     l_desired_freq,
                     l_tCKmin,
                     mss::c_str(l_port));

            o_min_dimm_freq.push_back(l_desired_freq);

        }// end else

        FAPI_TRY(set_CL_attr<P>(l_port, l_desired_cl), "%s. Failed set_CL_attr()", mss::c_str(l_port) );
    } // port

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
inline fapi2::ReturnCode supported_freqs(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
        std::vector<uint32_t>& o_freqs)
{
    o_freqs.clear();

    freq_scoreboard l_scoreboard(TT::PORTS_PER_FREQ_DOMAIN, TT::SUPPORTED_FREQS);
    std::vector<uint32_t> l_max_mrw_freqs(NUM_MAX_FREQS, 0);
    std::vector<std::vector<uint32_t>> l_vpd_supported_freqs;
    std::vector<uint32_t> l_spd_supported_freq;
    std::vector<uint8_t> l_deconfigured = {0};
    std::vector<fapi2::Target<TT::PORT_TARGET_TYPE>> l_deconfigured_targets;

    // Retrieve system MRW, SPD, and VPD constraints
    FAPI_TRY( max_allowed_dimm_freq<P>(l_max_mrw_freqs.data()), "%s max_allowed_dimm_freq", mss::c_str(i_target) );

    FAPI_TRY( spd_supported_freq<P>(i_target, l_spd_supported_freq),
              "%s spd supported freqs", mss::c_str(i_target) );

    FAPI_TRY( vpd_supported_freqs<P>(i_target, l_vpd_supported_freqs),
              "%s vpd supported freqs", mss::c_str(i_target) );

    // Limits the frequency by the processor constraints (sync mode)
    FAPI_TRY( limit_freq_by_processor<P>(i_target, l_scoreboard) );

    // Limit frequency scoreboard according to MRW constraints
    FAPI_TRY( limit_freq_by_mrw<P>(i_target, l_max_mrw_freqs, l_scoreboard) );

    // Limit frequency scoreboard according to VPD constraints
    FAPI_TRY( limit_freq_by_vpd<P>(i_target, l_vpd_supported_freqs, l_scoreboard) );

    // Limit frequency scoreboard according to SPD (DIMM) constraints
    FAPI_TRY( limit_freq_by_spd<P>(i_target, l_spd_supported_freq, l_scoreboard) );

    // Callout the fewest number of ports to achieve a common shared freq
    FAPI_TRY( l_scoreboard.template resolve<P>(i_target,
              l_vpd_supported_freqs,
              l_deconfigured,
              l_deconfigured_targets,
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
fapi2::ReturnCode final_freq(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target);

} // check nameespace

///
/// @brief Generates the memory frequency for one frequency domain
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCESS iff okay
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode generate_freq(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target)
{
    std::vector<uint64_t> l_min_dimm_freq;
    std::vector<uint32_t> l_supported_freqs;

    // Get supported freqs for this domain
    FAPI_TRY( mss::supported_freqs<P>(i_target, l_supported_freqs), "%s failed to get supported frequencies",
              mss::c_str(i_target) );

    // Finds the minimum supported DIMM frequencies for this domain
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
