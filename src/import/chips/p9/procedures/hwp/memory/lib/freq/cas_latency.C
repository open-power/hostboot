/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/freq/cas_latency.C $ */
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
/// @file cas_latency.C
/// @brief CAS latency class implementation
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

// std lib
#include <limits.h>
#include <algorithm>

// fapi2
#include <fapi2.H>

// mss lib
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <lib/freq/cas_latency.H>
#include <lib/freq/sync.H>
#include <lib/utils/conversions.H>
#include <lib/eff_config/timing.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/utils/checker.H>

using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;

namespace mss
{

///
/// @brief encoding for MSS_INVALID_TIMING so we can look up functions based on encoding
///
enum invalid_timing_function_encoding
{
    TAAMIN = 10,
    TCKMIN = 11,
    TCKMAX = 12,
};

/////////////////////////
// Member method implementation
/////////////////////////

///
/// @brief      Class constructor that retrieves required SPD data held by internal state
/// @param[in]  i_target the controller target
/// @param[in]  i_caches decoder caches
/// @param[out] o_rc returns FAPI2_RC_SUCCESS if constructor initialzed successfully
///
cas_latency::cas_latency(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                         const std::vector< std::shared_ptr<spd::decoder> >& i_caches,
                         fapi2::ReturnCode& o_rc ):
    iv_dimm_list_empty(false),
    iv_target(i_target),
    iv_largest_taamin(0),
    iv_proposed_tck(0),
    iv_common_cl(UINT64_MAX) // Masks out supported CLs
{
    o_rc = fapi2::FAPI2_RC_SUCCESS;

    if( i_caches.empty() )
    {
        FAPI_INF("cas latency ctor seeing no SPD caches for %s", mss::c_str(i_target) );
        iv_dimm_list_empty = true;
        return;
    }

    for ( const auto& l_cache : i_caches )
    {
        // Retrieve timing values from the SPD
        uint64_t l_taa_min_in_ps = 0;
        uint64_t l_tckmax_in_ps = 0;
        uint64_t l_tck_min_in_ps = 0;

        FAPI_TRY( get_taamin(l_cache, l_taa_min_in_ps),
                  "%s. Failed to get tAAmin", mss::c_str(iv_target) );
        FAPI_TRY( get_tckmax(l_cache, l_tckmax_in_ps),
                  "%s. Failed to get tCKmax", mss::c_str(iv_target) );
        FAPI_TRY( get_tckmin(l_cache, l_tck_min_in_ps),
                  "%s. Failed to get tCKmin", mss::c_str(iv_target) );

        // Determine largest tAAmin value
        iv_largest_taamin = std::max(iv_largest_taamin, l_taa_min_in_ps);

        // Determine a proposed tCK value that is greater than or equal tCKmin
        // But less than tCKmax
        iv_proposed_tck = std::max(iv_proposed_tck, l_tck_min_in_ps);
        iv_proposed_tck = std::min(iv_proposed_tck, l_tckmax_in_ps);

        // Collecting stack type
        // If I have at least one 3DS DIMM connected I have
        // to use 3DS tAAmax of 21.5 ps versus 18 ps for non-3DS DDR4
        if( iv_is_3ds != loading::IS_3DS)
        {
            uint8_t l_stack_type = 0;
            FAPI_TRY( l_cache->prim_sdram_signal_loading(l_stack_type) );

            // Is there a more algorithmic efficient approach? - AAM
            iv_is_3ds = (l_stack_type == fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_3DS) ?
                        loading::IS_3DS : loading::NOT_3DS;
        }

        {
            // Retrieve dimm supported cas latencies from SPD
            uint64_t l_dimm_supported_cl = 0;
            FAPI_TRY( l_cache->supported_cas_latencies(l_dimm_supported_cl),
                      "%s. Failed to get supported CAS latency", mss::c_str(iv_target) );

            // Bitwise ANDING the bitmap from all modules creates a bitmap w/a common CL
            iv_common_cl &= l_dimm_supported_cl;
        }
    }// caches

    // Limit tCK from the max supported dimm speed in the system
    // So that this is taken into account when calculating CL
    {
        // Defaulting to non-zero speed
        uint64_t l_freq_override = fapi2::ENUM_ATTR_MSS_FREQ_MT2666;
        uint64_t l_tck_override_in_ps = 0;

        FAPI_TRY( select_supported_freq(iv_target, l_freq_override),
                  "%s. Failed select_supported_freq()", mss::c_str(iv_target) );
        FAPI_TRY( freq_to_ps(l_freq_override, l_tck_override_in_ps),
                  "%s. Failed freq_to_ps()", mss::c_str(iv_target) );

        FAPI_INF("%s. Selected supported dimm speed %d MT/s (Clock period %d in ps)",
                 mss::c_str(iv_target), l_freq_override, l_tck_override_in_ps);

        iv_proposed_tck = std::max( l_tck_override_in_ps, iv_proposed_tck );
        FAPI_INF("%s. Initial proposed tCK in ps: %d", mss::c_str(iv_target), iv_proposed_tck);


        // Sanity check
        FAPI_ASSERT(iv_proposed_tck > 0,
                    fapi2::MSS_INVALID_CALCULATED_TCK().
                    set_TAAMIN(iv_largest_taamin).
                    set_PROPOSED_TCK(iv_proposed_tck).
                    set_IS_3DS(iv_is_3ds).
                    set_FREQUENCY(l_freq_override).
                    set_MCA_TARGET(iv_target),
                    "%s. Invalid calculated clock period(<= 0) : %d",
                    mss::c_str(iv_target),
                    iv_proposed_tck);
    }

    // Why didn't I encapsulate common CL operations and checking in a function
    // like the timing params? Well, I want to check the "final" common CL and
    // the creation of common CLs (bitwise ANDING) is at the dimm level operation
    FAPI_ASSERT(iv_common_cl != 0,
                fapi2::MSS_NO_COMMON_SUPPORTED_CL().
                set_CL_SUPPORTED(iv_common_cl).
                set_MCA_TARGET(iv_target),
                "%s. No common CAS latencies (CL bitmap = 0)",
                mss::c_str(iv_target) );

    FAPI_INF("%s. Supported CL bitmap 0x%llX", mss::c_str(iv_target), iv_common_cl);

fapi_try_exit:
    o_rc = fapi2::current_err;
    return;
}// ctor


///
/// @brief      Constructor that allows the user to set desired data in lieu of SPD
/// @param[in]  i_target the controller target
/// @param[in]  i_taa_min largest tAAmin we want to set in picoseconds
/// @param[in]  i_tck_min proposed tCKmin in picoseconds
/// @param[in]  i_common_cl_mask common CAS latency mask we want to force (bitmap)
/// @param[in]  i_is_3ds loading::IS_3DS if this is for 3DS, loading::NOT_3DS otherwise
///
cas_latency::cas_latency(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                         const uint64_t i_taa_min,
                         const uint64_t i_tck_min,
                         const uint64_t i_common_cl_mask,
                         const loading i_is_3ds):
    iv_dimm_list_empty(false),
    iv_target(i_target),
    iv_largest_taamin(i_taa_min),
    iv_proposed_tck(i_tck_min),
    iv_common_cl(i_common_cl_mask),
    iv_is_3ds(i_is_3ds)
{
    const auto l_dimm_list = find_targets<TARGET_TYPE_DIMM>(iv_target);

    if(l_dimm_list.empty())
    {
        FAPI_INF("cas latency ctor seeing no DIMM on %s", mss::c_str(iv_target));
        iv_dimm_list_empty = true;
    }
}

///
/// @brief      Calculates CAS latency and checks if it is supported and within JEDEC spec.
/// @param[out] o_cas_latency selected CAS latency
/// @param[out] o_tck cycle time corresponding to selected CAS latency
/// @return     fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode cas_latency::find_cl(uint64_t& o_cas_latency,
                                       uint64_t& o_tck)
{
    uint64_t l_desired_cas_latency = 0;

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    if(!iv_dimm_list_empty)
    {
        // Create a vector filled with common CLs from buffer
        std::vector<uint64_t> l_supported_cls = integral_bitmap_to_vector(iv_common_cl);

        // Make sure we have at least one entry. We should since iv_common_cl is checked in ctor
        FAPI_ASSERT( !l_supported_cls.empty(),
                     fapi2::MSS_NO_COMMON_SUPPORTED_CL().
                     set_CL_SUPPORTED(iv_common_cl).
                     set_MCA_TARGET(iv_target),
                     "%s. Error making support cas latency vector. No common CAS latencies",
                     mss::c_str(iv_target) );

        // For a proposed tCK value between tCKmin(all) and tCKmax, determine the desired CAS Latency.
        FAPI_TRY( calc_cas_latency(iv_largest_taamin, iv_proposed_tck, l_desired_cas_latency),
                  "%s. Failed to calculate CAS latency", mss::c_str(iv_target) );

        // Chose an actual CAS Latency (CLactual) that is greater than or equal to CLdesired
        // and is supported by all modules on the memory channel
        FAPI_TRY( is_cl_supported_in_common(l_supported_cls, l_desired_cas_latency),
                  "%s. Failed to find a common CAS latency supported among all modules", mss::c_str(iv_target) );

        // Once the calculation of CLactual is completed
        // verify that this CAS Latency value does not exceed tAAmax.
        FAPI_TRY( is_cl_exceeding_taa_max (l_desired_cas_latency, iv_proposed_tck),
                  "%s. Failed to find a CL value that doesn't exceed tAAmax", mss::c_str(iv_target) );
    }

    // Update output values after all criteria is met
    // If the MCA has no dimm configured than both
    // l_desired_latency & iv_proposed_tck is 0 by initialization
    o_cas_latency = l_desired_cas_latency;
    o_tck = iv_proposed_tck;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Retrieves SDRAM Minimum CAS Latency Time (tAAmin) from SPD
/// @param[in]  i_pDecoder the SPD decoder
/// @param[out] o_value tCKmin value in ps
/// @return     FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode cas_latency::get_taamin( const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
        uint64_t& o_value )
{
    int64_t l_timing_ftb = 0;
    int64_t l_timing_mtb = 0;
    int64_t l_medium_timebase = 0;
    int64_t l_fine_timebase = 0;
    int64_t l_temp = 0;
    // Retrieve timing parameters
    FAPI_TRY( i_pDecoder->medium_timebase(l_medium_timebase),
              "%s. Failed medium_timebase()", mss::c_str(iv_target) );
    FAPI_TRY( i_pDecoder->fine_timebase(l_fine_timebase),
              "%s. Failed fine_timebase()", mss::c_str(iv_target) );
    FAPI_TRY( i_pDecoder->min_taa(l_timing_mtb),
              "%s. Failed min_taa()", mss::c_str(iv_target) );
    FAPI_TRY( i_pDecoder->fine_offset_min_taa(l_timing_ftb),
              "%s. Failed fine_offset_min_taa()", mss::c_str(iv_target) );

    // Calculate timing value
    l_temp = spd::calc_timing_from_timebase(l_timing_mtb,
                                            l_medium_timebase,
                                            l_timing_ftb,
                                            l_fine_timebase);

    // Sanity check
    FAPI_ASSERT(l_temp > 0,
                fapi2::MSS_INVALID_TIMING_VALUE().
                set_VALUE(o_value).
                set_FUNCTION(TAAMIN).
                set_DIMM_TARGET(iv_target),
                "%s. tAAmin invalid (<= 0) : %d",
                mss::c_str(iv_target),
                l_temp);

    o_value = l_temp;
    FAPI_INF( "%s. tAAmin (ps): %d",
              mss::c_str(iv_target),
              o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Retrieves SDRAM Minimum Cycle Time (tCKmin) from SPD
/// @param[in]  i_pDecoder the SPD decoder
/// @param[out] o_value tCKmin value in ps
/// @return     FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode cas_latency::get_tckmin( const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
        uint64_t& o_value )
{
    int64_t l_timing_ftb = 0;
    int64_t l_timing_mtb = 0;
    int64_t l_medium_timebase = 0;
    int64_t l_fine_timebase = 0;
    int64_t l_temp = 0;

    // Retrieve timing parameters
    FAPI_TRY( i_pDecoder->medium_timebase(l_medium_timebase),
              "%s. Failed medium_timebase()", mss::c_str(iv_target) );
    FAPI_TRY( i_pDecoder->fine_timebase(l_fine_timebase),
              "%s. Failed fine_timebase()", mss::c_str(iv_target) );
    FAPI_TRY( i_pDecoder->min_tck(l_timing_mtb),
              "%s. Failed min_tck()", mss::c_str(iv_target) );
    FAPI_TRY( i_pDecoder->fine_offset_min_tck(l_timing_ftb),
              "%s. Failed fine_offset_min_tck()", mss::c_str(iv_target) );

    // Calculate timing value
    l_temp = spd::calc_timing_from_timebase(l_timing_mtb,
                                            l_medium_timebase,
                                            l_timing_ftb,
                                            l_fine_timebase);

    // Sanity check
    FAPI_ASSERT(l_temp > 0,
                fapi2::MSS_INVALID_TIMING_VALUE().
                set_VALUE(l_temp).
                set_FUNCTION(TCKMIN).
                set_DIMM_TARGET(iv_target),
                "%s. tCKmin invalid (<= 0) : %d",
                mss::c_str(iv_target),
                l_temp);

    o_value = l_temp;

    FAPI_INF("%s. tCKmin (ps): %d",
             mss::c_str(iv_target),
             o_value );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Retrieves SDRAM Maximum Cycle Time (tCKmax) from SPD
/// @param[in]  i_pDecoder SPD decoder
/// @param[out] o_value tCKmax value in ps
/// @return     FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode cas_latency::get_tckmax( const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
        uint64_t& o_value )
{
    int64_t l_timing_ftb = 0;
    int64_t l_timing_mtb = 0;
    int64_t l_medium_timebase = 0;
    int64_t l_fine_timebase = 0;
    int64_t l_temp = 0;
    // Retrieve timing parameters
    FAPI_TRY( i_pDecoder->medium_timebase(l_medium_timebase),
              "%s. Failed medium_timebase()", mss::c_str(iv_target) );
    FAPI_TRY( i_pDecoder->fine_timebase(l_fine_timebase),
              "%s. Failed fine_timebase()", mss::c_str(iv_target) );
    FAPI_TRY( i_pDecoder->max_tck(l_timing_mtb),
              "%s. Failed max_tck()", mss::c_str(iv_target) );
    FAPI_TRY( i_pDecoder->fine_offset_max_tck(l_timing_ftb),
              "%s. Failed fine_offset_max_tck()", mss::c_str(iv_target) );

    // Calculate timing value
    l_temp = spd::calc_timing_from_timebase(l_timing_mtb,
                                            l_medium_timebase,
                                            l_timing_ftb,
                                            l_fine_timebase);

    // Sanity check
    FAPI_ASSERT(l_temp > 0,
                fapi2::MSS_INVALID_TIMING_VALUE().
                set_VALUE(l_temp).
                set_FUNCTION(TCKMAX).
                set_DIMM_TARGET(iv_target),
                "%s. tCKmax invalid (<= 0) : %d",
                mss::c_str(iv_target),
                l_temp);

    o_value = l_temp;

    FAPI_INF( "%s. tCKmax (ps): %d",
              mss::c_str(iv_target),
              o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Gets max CAS latency (CL) for the appropriate High/Low Range
/// @param[in]  i_supported_cl
/// @return     the maximum supported CL
/// @note       Depends on bit 7 of byte 23 from the DDR4 SPD
///
inline uint64_t cas_latency::get_max_cl(const fapi2::buffer<uint64_t> i_supported_cl) const
{
    // If the last of Byte 23 of the SPD is 1, this selects CL values
    // in the High CL range (23 to 52)

    // If the last bit of Byte 23 of the SPD is 0, this selects CL values
    // in the Low CL range (7 to 36)
    //Assuming bitmap is right aligned
    return i_supported_cl.getBit<CAS_LAT_RANGE_BIT>() ? HIGH_RANGE_MAX_CL_DDR4 : LOW_RANGE_MAX_CL_DDR4;
}

///
/// @brief      Gets min CAS latency (CL) for the appropriate High/Low Range
/// @param[in]  i_supported_cl
/// @return     the minimum supported CL
/// @note       Depends on bit 7 of byte 23 from the DDR4 SPD
///
inline uint64_t cas_latency::get_min_cl(const fapi2::buffer<uint64_t>& i_supported_cl) const
{
    // If the last of Byte 23 of the SPD is 1, this selects CL values
    // in the High CL range (23 to 52)

    // If the last bit of Byte 23 of the SPD is 0, this selects CL values
    // in the Low CL range (7 to 36)
    return  i_supported_cl.getBit<CAS_LAT_RANGE_BIT>() ? HIGH_RANGE_MIN_CL_DDR4 : LOW_RANGE_MIN_CL_DDR4;

}

///
/// @brief Calculates CAS latency time from tCK and tAA
/// @param[in]  i_taa cas latency time
/// @param[in]  i_tck min cycle time
/// @param[out] o_cas_latency calculated CAS latency
/// @return     FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode cas_latency::calc_cas_latency(const uint64_t i_taa,
        const uint64_t i_tck,
        uint64_t& o_cas_latency) const
{
    FAPI_TRY( spd::calc_nck(i_taa, i_tck, INVERSE_DDR4_CORRECTION_FACTOR, o_cas_latency) );

    FAPI_INF("%s. tAA (ps): %d, tCK (ps): %d, CL (nck): %d",
             mss::c_str(iv_target),
             i_taa,
             i_tck,
             o_cas_latency);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Helper function to create a vector of supported CAS latencies from a bitmap
/// @param[in]  i_common_cl common CAS latency bitmap
/// @return     vector of supported CAS latencies
///
std::vector<uint64_t> cas_latency::integral_bitmap_to_vector(const uint64_t i_common_cl) const
{
    std::vector<uint64_t> l_vector;
    fapi2::buffer<uint64_t> l_cl_mask(i_common_cl);

    uint64_t min_cl = get_min_cl(l_cl_mask);
    uint64_t max_cl = get_max_cl(l_cl_mask);

    FAPI_INF("%s. min CL %lu", mss::c_str(iv_target), min_cl);
    FAPI_INF("%s. max CL %lu", mss::c_str(iv_target), max_cl);

    for(uint64_t l_cas_latency = min_cl; l_cas_latency <= max_cl; ++l_cas_latency)
    {
        // 64 bit is buffer length - indexed at 0 - 63
        constexpr uint64_t l_buffer_length = 64 - 1;
        uint64_t l_bit_pos = l_buffer_length - (l_cas_latency - min_cl);

        // Traversing through buffer one bit at a time
        // 0 means unsupported CAS latency
        // 1 means supported  CAS latency
        // We are pushing supported CAS latencies into a vector for direct use
        if( l_cl_mask.getBit(l_bit_pos) )
        {
            // I want don't this to print all the time, DBG is fine
            FAPI_DBG( "%s. Supported CL (%d) from common CL mask",
                      mss::c_str(iv_target), l_cas_latency );

            l_vector.push_back(l_cas_latency);
        }
    }

    return l_vector;
}

///
/// @brief      Determines if a requested CAS latency (CL) is supported in the bin of common CLs
/// @param[in]  i_common_cls vector of common CAS latencies
/// @param[in]  i_cas_latency CAS latency we are comparing against
/// @return     FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode cas_latency::is_cl_supported_in_common(const std::vector<uint64_t>& i_common_cls,
        const uint64_t i_cas_latency) const
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Grabbing freq info for ffdc
    std::vector<uint32_t> l_mrw_freqs(NUM_MRW_FREQS, 0);
    std::vector<uint32_t> l_max_freqs(NUM_MAX_FREQS, 0);

    FAPI_TRY( mss::mrw_supported_freq(l_mrw_freqs.data()) );
    FAPI_TRY( mss::max_allowed_dimm_freq(l_max_freqs.data()) );

    // If the cas_latency wasn't found, we return an error
    // Passing in timing values which were used to calculated i_cas_latency for extra info
    // iv_common_cl contains all of the valid cas latencies that populate the input vector
    FAPI_ASSERT( std::binary_search(i_common_cls.begin(), i_common_cls.end(), i_cas_latency),
                 fapi2::MSS_FAILED_TO_FIND_SUPPORTED_CL()
                 .set_DESIRED_CAS_LATENCY(i_cas_latency)
                 .set_TAA(iv_largest_taamin)
                 .set_TCK(iv_proposed_tck)
                 .set_COMMON_CLS(iv_common_cl)
                 .set_MSS_MRW_FREQ_0(l_mrw_freqs[0])
                 .set_MSS_MRW_FREQ_1(l_mrw_freqs[1])
                 .set_MSS_MRW_FREQ_2(l_mrw_freqs[2])
                 .set_MSS_MRW_FREQ_3(l_mrw_freqs[3])
                 .set_MSS_MAX_FREQ_0(l_max_freqs[0])
                 .set_MSS_MAX_FREQ_1(l_max_freqs[1])
                 .set_MSS_MAX_FREQ_2(l_max_freqs[2])
                 .set_MSS_MAX_FREQ_3(l_max_freqs[3])
                 .set_MSS_MAX_FREQ_4(l_max_freqs[4])
                 .set_MCA_TARGET(iv_target),
                 "%s. Failed to find a common CAS latency supported among all modules"
                 "Desired %d, common CL's %016lx",
                 mss::c_str(iv_target),
                 i_cas_latency,
                 iv_common_cl);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Checks that CAS latency doesn't exceed largest CAS latency time
/// @param[in]  i_cas_latency cas latency
/// @param[in]  i_tck cycle time
/// @return     FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode cas_latency::is_cl_exceeding_taa_max(const uint64_t i_cas_latency,
        const uint64_t i_tck) const
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    // JEDEC SPD spec requirement
    const size_t l_taa_max = (iv_is_3ds == loading::NOT_3DS) ? TAA_MAX_DDR4 : TAA_MAX_DDR4_3DS;

    FAPI_INF("%s. CL (%d) * tCK (%d) = %d > %d",
             mss::c_str(iv_target),
             i_cas_latency,
             i_tck,
             i_cas_latency * i_tck,
             l_taa_max);

    FAPI_ASSERT( ((i_cas_latency * i_tck) <= l_taa_max),
                 fapi2::MSS_CL_EXCEEDS_TAA_MAX()
                 .set_CAS_LATENCY(i_cas_latency)
                 .set_TCK(i_tck)
                 .set_COMPARE(i_cas_latency * i_tck)
                 .set_TAA_MAX(l_taa_max)
                 .set_IS_3DS(iv_is_3ds),
                 "%s: Calculated Cas Latency (i_cas_latency %d * i_tck %d) exceeds JEDEC value of TAA MAX %d",
                 mss::c_str(iv_target),
                 i_cas_latency,
                 i_tck,
                 l_taa_max);
fapi_try_exit:
    return fapi2::current_err;
}

}// mss
