/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/freq/cas_latency.C $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file cas_latency.C
/// @brief CAS latency class implementation
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include <limits.h>
#include <algorithm>

#include <fapi2.H>
#include <mss.H>
#include <freq/cas_latency.H>
#include <freq/cycle_time.H>
#include <lib/utils/conversions.H>
#include <lib/utils/fake_spd.H>
#include <lib/eff_config/timing.H>

using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;

namespace mss
{

/////////////////////////
// Member method implementation
/////////////////////////

///
/// @brief      Class constructor that retrieves required SPD data held by internal state
/// @param[in]  i_target the controller target
/// @param[in]  i_caches decoder caches
///
cas_latency::cas_latency(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                         const std::map<uint32_t, std::shared_ptr<spd::decoder> >& i_caches)
{
    iv_common_CL = UINT64_MAX; // Masks out supported CLs
    iv_largest_taamin = 0;
    iv_proposed_tck = 0;

    for (const auto& l_port : i_target.getChildren<TARGET_TYPE_MCA>())
    {
        for (const auto& l_dimm : l_port.getChildren<TARGET_TYPE_DIMM>())
        {
            const auto& l_dimm_pos = pos(l_dimm);

            // Find decoder factory for this dimm position
            auto l_it = i_caches.find(l_dimm_pos);
            FAPI_TRY( check::spd::invalid_cache(l_dimm,
                                                l_it != i_caches.end(),
                                                l_dimm_pos),
                      "Failed to get valid cache");

            {
                // Retrive timing values from the SPD
                uint64_t l_tAAmin_in_ps = 0;
                uint64_t l_tCKmax_in_ps = 0;
                uint64_t l_tCKmin_in_ps = 0;

                FAPI_TRY( get_taamin(l_dimm, l_it->second, l_tAAmin_in_ps),
                          "Failed to get tAAmin");
                FAPI_TRY( get_tckmax(l_dimm, l_it->second, l_tCKmax_in_ps),
                          "Failed to get tCKmax" );
                FAPI_TRY( get_tckmin(l_dimm, l_it->second, l_tCKmin_in_ps),
                          "Failed to get tCKmin");

                // Determine largest tAAmin value
                iv_largest_taamin = std::max(iv_largest_taamin, l_tAAmin_in_ps);

                // Determine a proposed tCK value that is greater than or equal tCKmin
                // But less than tCKmax
                iv_proposed_tck = std::max(iv_proposed_tck, l_tCKmin_in_ps);
                iv_proposed_tck = std::min(iv_proposed_tck, l_tCKmax_in_ps);
            }

            {
                // Retrieve dimm supported cas latencies from SPD
                uint64_t l_dimm_supported_CL = 0;
                FAPI_TRY( l_it->second->supported_cas_latencies(l_dimm,
                          l_it->second->iv_spd_data.get(),
                          l_dimm_supported_CL),
                          "Failed to get supported CAS latency");

                // ANDing bitmap from all modules creates a bitmap w/a common CL
                iv_common_CL &= l_dimm_supported_CL;
            }
        }// dimm
    }// port

    // Why didn't I encapsulate common CL operations and checking in a function
    // like the timing params? Well, I want to check the "final" common CL and
    // the creation of common CLs (ANDing bits) is dimm level operation
    FAPI_ASSERT(iv_common_CL != 0,
                fapi2::MSS_NO_COMMON_SUPPORTED_CL().
                set_CL_SUPPORTED(iv_common_CL).
                set_MCS_TARGET(i_target),
                "No common CAS latencies (CL bitmap = 0)");

    FAPI_DBG("Supported CL bitmap 0x%llX", iv_common_CL);

    // If we reach here al instance vars should have successfully initialized
    return;

    // If we reach here something failed above.
fapi_try_exit:
    FAPI_ERR("Something went wrong retreiving dimm info");

}// ctor


///
/// @brief      Calculates CAS latency and checks if it is supported and within JEDEC spec.
/// @param[in]  i_target the controller target
/// @param[out] o_cas_latency selected CAS latency
/// @param[out] o_tCK cycle time corresponding to seleted CAS latency
/// @return     fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode cas_latency::find_CL(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                       uint64_t& o_cas_latency,
                                       uint64_t& o_tCK)
{
    // Create a vector filled with common CLs from buffer
    std::vector<uint64_t> l_supported_CLs = create_common_cl_vector(iv_common_CL);

    //For a proposed tCK value between tCKmin(all) and tCKmax, determine the desired CAS Latency.
    uint64_t l_desired_cas_latency = calc_cas_latency(iv_largest_taamin, iv_proposed_tck);

    //Chose an actual CAS Latency (CLactual) that is greater than or equal to CLdesired
    //and is supported by all modules on the memory channel
    FAPI_TRY( choose_actual_CL(l_supported_CLs, iv_largest_taamin, iv_proposed_tck, l_desired_cas_latency) );

    // Once the calculation of CLactual is completed, the BIOS must also
    // verify that this CAS Latency value does not exceed tAAmax.
    //If not, choose a lower CL value and repeat until a solution is found.
    FAPI_TRY( validate_valid_CL(l_supported_CLs, iv_largest_taamin, iv_proposed_tck, l_desired_cas_latency) );

    // Update output values after all criteria is met
    o_cas_latency = l_desired_cas_latency;
    o_tCK = iv_proposed_tck;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Retrieves SDRAM Minimum CAS Latency Time (tAAmin) from SPD
/// @param[in]  i_target the dimm target
/// @param[in]  i_pDecoder the SPD decoder
/// @param[out] o_value tCKmin value in ps
/// @return     FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode cas_latency::get_taamin(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
        uint64_t& o_value)
{
    int64_t l_timing_ftb = 0;
    int64_t l_timing_mtb = 0;
    int64_t l_medium_timebase = 0;
    int64_t l_fine_timebase = 0;

    // Retrieve timing parameters
    FAPI_TRY( i_pDecoder->medium_timebase(i_target, i_pDecoder->iv_spd_data.get(), l_medium_timebase) );
    FAPI_TRY( i_pDecoder->fine_timebase(i_target, i_pDecoder->iv_spd_data.get(), l_fine_timebase) );
    FAPI_TRY( i_pDecoder->min_cas_latency_time(i_target, i_pDecoder->iv_spd_data.get(), l_timing_mtb) );
    FAPI_TRY( i_pDecoder->fine_offset_min_taa(i_target, i_pDecoder->iv_spd_data.get(), l_timing_ftb) );

    // Calculate timing value
    o_value = uint64_t(calc_timing_from_timebase(l_timing_mtb,
                       l_medium_timebase,
                       l_timing_ftb,
                       l_fine_timebase));

    // Sanity check
    FAPI_ASSERT(o_value > 0,
                fapi2::MSS_INVALID_TIMING_VALUE().
                set_VALUE(o_value).
                set_DIMM_TARGET(i_target),
                "tAAmin invalid (<= 0) : %d",
                o_value);

    FAPI_DBG( "%s. tAAmin (ps): %d",
              c_str(i_target),
              o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Retrieves SDRAM Minimum Cycle Time (tCKmin) from SPD
/// @param[in]  i_target the dimm target
/// @param[in]  i_pDecoder the SPD decoder
/// @param[out] o_value tCKmin value in ps
/// @return     FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode cas_latency::get_tckmin(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
        uint64_t& o_value)
{
    int64_t l_timing_ftb = 0;
    int64_t l_timing_mtb = 0;
    int64_t l_medium_timebase = 0;
    int64_t l_fine_timebase = 0;

    // Retrieve timing parameters
    FAPI_TRY( i_pDecoder->medium_timebase(i_target, i_pDecoder->iv_spd_data.get(), l_medium_timebase) );
    FAPI_TRY( i_pDecoder->fine_timebase(i_target, i_pDecoder->iv_spd_data.get(), l_fine_timebase) );
    FAPI_TRY( i_pDecoder->min_cycle_time(i_target, i_pDecoder->iv_spd_data.get(), l_timing_mtb) );
    FAPI_TRY( i_pDecoder->fine_offset_min_tck(i_target, i_pDecoder->iv_spd_data.get(), l_timing_ftb) );

    // Calculate timing value
    o_value = uint64_t( calc_timing_from_timebase(l_timing_mtb,
                        l_medium_timebase,
                        l_timing_ftb,
                        l_fine_timebase) );

    // Sanity check
    FAPI_ASSERT(o_value > 0,
                fapi2::MSS_INVALID_TIMING_VALUE().
                set_VALUE(o_value).
                set_DIMM_TARGET(i_target),
                "tCKmin invalid (<= 0) : %d",
                o_value);

    FAPI_DBG("%s. tCKmin (ps): %d",
             c_str(i_target),
             o_value );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Retrieves SDRAM Maximum Cycle Time (tCKmax) from SPD
/// @param[in]  i_target the dimm target
/// @param[in]  i_pDecoder SPD decoder
/// @param[out] o_value tCKmax value in ps
/// @return     FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode cas_latency::get_tckmax(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
        uint64_t& o_value)
{
    int64_t l_timing_ftb = 0;
    int64_t l_timing_mtb = 0;
    int64_t l_medium_timebase = 0;
    int64_t l_fine_timebase = 0;

    // Retrieve timing parameters
    FAPI_TRY( i_pDecoder->medium_timebase(i_target, i_pDecoder->iv_spd_data.get(), l_medium_timebase) );
    FAPI_TRY( i_pDecoder->fine_timebase(i_target, i_pDecoder->iv_spd_data.get(), l_fine_timebase) );
    FAPI_TRY( i_pDecoder->max_cycle_time(i_target, i_pDecoder->iv_spd_data.get(), l_timing_mtb) );
    FAPI_TRY( i_pDecoder->fine_offset_max_tck(i_target, i_pDecoder->iv_spd_data.get(), l_timing_ftb) );

    // Calculate timing value
    o_value = uint64_t(calc_timing_from_timebase(l_timing_mtb,
                       l_medium_timebase,
                       l_timing_ftb,
                       l_fine_timebase) );

    // Sanity check
    FAPI_ASSERT(o_value > 0,
                fapi2::MSS_INVALID_TIMING_VALUE().
                set_VALUE(o_value).
                set_DIMM_TARGET(i_target),
                "tCKmax invalid (<= 0) : %d",
                o_value);

    FAPI_DBG( "%s. tCKmax (ps): %d",
              c_str(i_target),
              o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Gets max CAS latency (CL) for the appropriate High/Low Range
/// @param[in]  i_supported_CL
/// @return     the maximum supported CL
/// @note       Depends on bit 7 of byte 23 from the DDR4 SPD
///
inline uint64_t cas_latency::get_max_CL(const fapi2::buffer<uint64_t> i_supported_CL) const
{
    constexpr uint64_t CAS_LAT_RANGE_BIT = 31;

    // If the last of Byte 23 of the SPD is 1, this selects CL values
    // in the High CL range (23 to 52)

    // If the last bit of Byte 23 of the SPD is 0, this selects CL values
    // in the Low CL range (7 to 36)
    //Assuming bitmap is right aligned
    return i_supported_CL.getBit<CAS_LAT_RANGE_BIT>() ? HIGH_RANGE_MAX_CL_DDR4 : LOW_RANGE_MAX_CL_DDR4;
}

///
/// @brief      Gets min CAS latency (CL) for the appropriate High/Low Range
/// @param[in]  i_supported_CL
/// @return     the minimum supported CL
/// @note       Depends on bit 7 of byte 23 from the DDR4 SPD
///
inline uint64_t cas_latency::get_min_CL(const fapi2::buffer<uint64_t>& i_supported_CL) const
{
    // If the last of Byte 23 of the SPD is 1, this selects CL values
    // in the High CL range (23 to 52)

    // If the last bit of Byte 23 of the SPD is 0, this selects CL values
    // in the Low CL range (7 to 36)
    constexpr uint64_t CAS_LAT_RANGE_BIT = 31;

    return  i_supported_CL.getBit<CAS_LAT_RANGE_BIT>() ? HIGH_RANGE_MIN_CL_DDR4 : LOW_RANGE_MIN_CL_DDR4;

}

///
/// @brief Calculates CAS latency time from tCK and tAA
/// @param[in]  i_tAA cas latency time
/// @param[in]  i_tCK min cycle time
/// @return     o_cas_latency calculated CAS latency
///
inline uint64_t cas_latency::calc_cas_latency(const uint64_t i_tAA, const uint64_t i_tCK) const
{
    uint64_t l_quotient = i_tAA / i_tCK;
    uint64_t l_remainder = i_tAA % i_tCK;
    uint64_t o_cas_latency = l_quotient + (l_remainder == 0 ? 0 : 1);

    FAPI_DBG("Calculated CL = tAA / tCK : %d / %d = %d",
             i_tAA,
             i_tCK,
             o_cas_latency);

    return o_cas_latency;
}

///
/// @brief      Helper function to create a vector of supported CAS latencies from a bitmap
/// @param[in]  i_common_CL common CAS latency bitmap
/// @return     vector of supported CAS latencies
///
std::vector<uint64_t> cas_latency::create_common_cl_vector(const uint64_t i_common_CL) const
{
    std::vector<uint64_t> l_vector;
    fapi2::buffer<uint64_t> l_CL_mask(i_common_CL);

    uint64_t min_CL = get_min_CL(l_CL_mask);
    uint64_t max_CL = get_max_CL(l_CL_mask);

    FAPI_DBG("min CL %lu", min_CL);
    FAPI_DBG("max CL %lu", max_CL);

    for(uint64_t cas_latency = min_CL; cas_latency <= max_CL; ++cas_latency)
    {
        // 64 bit is buffer length - indexed at 0 - 63
        constexpr uint64_t l_buffer_length = 64 - 1;
        uint64_t l_bit_pos = l_buffer_length - (cas_latency - min_CL);

        // Traversing through buffer one bit at a time
        // 0 means unsupported CAS latency
        // 1 means supported  CAS latency
        // We are pushing supported CAS latencies into a vector for direct use
        if( l_CL_mask.getBit(l_bit_pos) )
        {
            l_vector.push_back(cas_latency);
        }
    }

    return l_vector;
}


///
/// @brief      Determines if a requested CAS latency (CL) is supported in the bin of common CLs
/// @param[in]  i_common_CLs vector of common CAS latencies
/// @param[in]  i_cas_latency CAS latency we are comparing against
/// @return     true if CAS latency is supported
///
inline bool cas_latency::is_CL_supported_in_common(const std::vector<uint64_t>& i_common_CLs,
        const uint64_t i_cas_latency) const
{
    return std::binary_search(i_common_CLs.begin(), i_common_CLs.end(), i_cas_latency);
}

///
/// @brief      Checks that CAS latency doesn't exceed largest CAS latency time
/// @param[in]  i_cas_latency cas latency
/// @param[in]  i_tCK cycle time
/// @return     bool true if CAS latency exceeds the largest CAS latency time
///             false otherwise
///
inline bool cas_latency::is_CL_exceeding_tAAmax(const uint64_t i_cas_latency,
        const uint64_t i_tCK) const
{
    // JEDEC spec requirement
    return (i_cas_latency * i_tCK > TAA_MAX_DDR4);
}


///
/// @brief         Helper function to determines next lowest CAS latency (CL)
/// @param[in]     i_common_CLs vector of common CAS latencies
/// @param[in,out] io_desired_cas_latency current CAS latency
/// @return        the next lowest CL
///
inline uint64_t cas_latency::next_lowest_CL(const std::vector<uint64_t>& i_common_CLs,
        uint64_t& io_desired_cas_latency)
{
    auto iterator = std::lower_bound(i_common_CLs.begin(),
                                     i_common_CLs.end(),
                                     io_desired_cas_latency);

    io_desired_cas_latency = *(--iterator);

    return  io_desired_cas_latency;
}

///
/// @brief          Checks that CAS latency (CL) is supported among all dimms
///                 and if it isn't we try to find a CL that is.
/// @param[in]      i_common_CLs vector of common CAS latencies
/// @param[in]      i_tAA CAS latency time
/// @param[in,out]  io_tCK cycle time that corresponds to cas latency
/// @param[in,out]  io_desired_cas_lat cas latency supported for all dimms
/// @return         fapi2::FAPI2_RC_SUCCESS if we find a valid CL also common among all dimms
///
fapi2::ReturnCode cas_latency::choose_actual_CL (const std::vector<uint64_t>& i_common_CLs,
        const uint64_t i_tAA,
        uint64_t& io_tCK,
        uint64_t& io_desired_cas_lat)
{
    if( i_common_CLs.empty() )
    {
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    //check if the desired CL is supported in the common CAS latency bin
    bool l_is_CL_supported = is_CL_supported_in_common(i_common_CLs, io_desired_cas_lat);

    while( !l_is_CL_supported )
    {
        // If CL is not supported...
        // Choose a higher tCKproposed value and recalculate CL
        // Check recalculated CL is supported in common CL
        // Repeat until a solution is found
        FAPI_TRY( select_higher_tck(io_tCK), "Failed select_higher_tck()");
        FAPI_DBG("Next higher tCK: %d", io_tCK);

        io_desired_cas_lat = calc_cas_latency(i_tAA, io_tCK);
        l_is_CL_supported = is_CL_supported_in_common(i_common_CLs, io_desired_cas_lat);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief          Checks that CAS latency (CL) doesn't exceed max CAS latency time (tAAmax)
///                 and if it does it tries to find a valid CL that doesn't exceed tAAmax.
/// @param[in]      i_common_CLs vector of common CAS latencies
/// @param[in]      i_tAA CAS latency time
/// @param[in,out]  io_tCK cycle time that corresponds to cas latency
/// @param[in,out]  io_desired_cas_lat cas latency supported for all dimms
/// @return         fapi2::FAPI2_RC_SUCCESS if CL doesn't exceed tAAmax
///
fapi2::ReturnCode cas_latency::validate_valid_CL (const std::vector<uint64_t>& i_common_CLs,
        const uint64_t i_tAA,
        uint64_t& io_tCK,
        uint64_t& io_desired_cas_lat)
{
    if( i_common_CLs.empty() )
    {
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    // Check that selected CL is less than tAAmax
    bool l_is_CL_violating_spec = is_CL_exceeding_tAAmax (io_desired_cas_lat, io_tCK);

    while(l_is_CL_violating_spec)
    {
        // If it is not....
        // Decrement CL to next lowest supported CL
        // And try again
        io_desired_cas_lat = next_lowest_CL(i_common_CLs, io_desired_cas_lat);
        FAPI_DBG("Next lowest supported CL: %d", io_desired_cas_lat);

        FAPI_TRY( choose_actual_CL(i_common_CLs, i_tAA, io_tCK, io_desired_cas_lat),
                  "Failed choose_actual_CL()");
        l_is_CL_violating_spec = is_CL_exceeding_tAAmax (io_desired_cas_lat, io_tCK);
    }

    //If we reach this point that we are not violationg tAAmax spec anymore
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Since a fail here could mean a fail due to choose_actual_cl and
    // due to violation of taamax specification, this error will help
    // distinguish error reason
    FAPI_ASSERT(false,
                fapi2::MSS_EXCEED_TAA_MAX_NO_CL().
                set_CL(io_desired_cas_lat),
                "Exceeded tAAmax");

    return fapi2::current_err;
}

}// mss
