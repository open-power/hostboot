/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/freq/sync.C $              */
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
/// @file sync.C
/// @brief Synchronous function implementations
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP
#include  <vector>
#include <map>

#include <fapi2.H>
#include <mss.H>
#include <freq/sync.H>
#include <lib/utils/find.H>

using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_SYSTEM;

namespace mss
{

///
/// @brief Retrieves a mapping of MSS frequency values per mcbist target
/// @param[in] i_targets vector of controller targets
/// @param[out] o_freq_map dimm speed map <key, value> = (mcbist target, frequency)
/// @param[out] o_is_speed_equal true if all map dimm speeds are the same
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dimm_speed_map(const std::vector< fapi2::Target<TARGET_TYPE_MCBIST> >& i_targets,
                                 std::map< fapi2::Target<TARGET_TYPE_MCBIST>, uint64_t >& o_freq_map,
                                 speed_equality& o_is_speed_equal)
{
    FAPI_INF("---- In dimm_speed_pairs ----");

    if(i_targets.empty())
    {
        FAPI_ERR("Empty target vector found when constructing dimm speed mapping!");
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    // Getting a sample freq value from an arbitrary target (first one)
    // to compare against all other target freq values
    uint64_t l_comparator = 0;
    FAPI_TRY( mss::freq(i_targets[0], l_comparator), "Failed accessor to mss_freq" );

    o_is_speed_equal = speed_equality::EQUAL_DIMM_SPEEDS;

    // Loop through all MCSBISTs and store dimm speeds
    for (const auto& l_mcbist : i_targets)
    {
        uint64_t l_dimm_speed = 0;
        FAPI_TRY( mss::freq(l_mcbist, l_dimm_speed), "Failed accessor to mss_freq" );

        if(l_comparator != l_dimm_speed)
        {
            o_is_speed_equal = speed_equality::NOT_EQUAL_DIMM_SPEEDS;
        }

        FAPI_INF("%s: Dimm speed %d MT/s", c_str(l_mcbist), l_dimm_speed);
        o_freq_map.emplace( std::make_pair(l_mcbist, l_dimm_speed) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deconfigures MCS targets connected to MCBIST
/// @param[in] i_target the controller target
/// @param[in] i_dimm_speed dimm speed in MT/s
/// @param[in] i_nest_freq nest freq in MHz
/// @return true if hardware was deconfigured
///
bool deconfigure(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                 const uint64_t i_dimm_speed,
                 const uint32_t i_nest_freq)
{
    FAPI_INF("---- In deconfigure ----");
    bool l_is_hw_deconfigured = false;

    // TODO - RTC 155347 fix dimm speed & nest comparison if needed
    if(i_dimm_speed != i_nest_freq)
    {
        // Deconfigure MCSes
        for( const auto& l_mcs : mss::find_targets<TARGET_TYPE_MCS>(i_target) )
        {
            l_is_hw_deconfigured = true;

            PLAT_FAPI_ASSERT_NOEXIT(false,
                                    fapi2::MSS_FREQ_NOT_EQUAL_NEST_FREQ()
                                    .set_MSS_FREQ(i_dimm_speed)
                                    .set_NEST_FREQ(i_nest_freq)
                                    .set_MCS_TARGET(l_mcs),
                                    "Deconfiguring %s",
                                    mss::c_str(l_mcs) );
        }// end for
    }// end if

    return l_is_hw_deconfigured;
}

///
/// @brief Selects synchronous mode and performs requirements enforced by ATTR_REQUIRED_SYNCH_MODE
/// @param[in] i_freq_map dimm speed mapping
/// @param[in] i_equal_dimm_speed tracks whether map has equal dimm speeds
/// @param[in] i_nest_freq nest frequency
/// @param[in] i_required_sync_mode system policy to enforce synchronous mode
/// @param[out] o_selected_sync_mode final synchronous mode
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode select_sync_mode(const std::map< fapi2::Target<TARGET_TYPE_MCBIST>, uint64_t >& i_freq_map,
                                   const speed_equality i_equal_dimm_speed,
                                   const uint32_t i_nest_freq,
                                   const uint8_t i_required_sync_mode,
                                   sync_mode& o_selected_sync_mode)
{
    FAPI_INF("---- In select_sync_mode ----");

    // Implementing frequency handling discussion:
    // https://w3-connections.ibm.com/forums/html/topic?id=1222318f-5992-4342-a858-b75594df1be3&ps=
    // Summary: We will always use async mode if we don't see a perfect match of dimm frequencies that match the nest
    switch(i_equal_dimm_speed)
    {
        case speed_equality::EQUAL_DIMM_SPEEDS:

            // Do not run synchronously, even if the frequencies match
            if (i_required_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_NEVER)
            {
                o_selected_sync_mode = sync_mode::MC_NOT_IN_SYNC;
                break;
            }

            // Run synchronously if the dimm and nest freq matches
            // Implicitly covers case when ATTR_REQUIRED_SYNCH_MODE is
            // ALWAYS and UNDETERMINED
            if( i_freq_map.begin()->second  == i_nest_freq)
            {
                o_selected_sync_mode = sync_mode::MC_IN_SYNC;
            }
            else
            {
                o_selected_sync_mode =  sync_mode::MC_NOT_IN_SYNC;
            }

            break;

        case speed_equality::NOT_EQUAL_DIMM_SPEEDS:

            // Require matching frequencies and deconfigure memory that does not match the nest
            if( i_required_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS )
            {
                for(const auto& l_it : i_freq_map)
                {
                    // This can be refactored to return info people might
                    // need.  Until then this returns true if hw was deconfigured
                    // FFDC prints out location
                    deconfigure(l_it.first, l_it.second, i_nest_freq);

                }// end for
            }// end if

            // Implicitly covers case when ATTR_REQUIRED_SYNCH_MODE is
            // NEVER, ALWAYS, and UNDETERMINED
            o_selected_sync_mode = sync_mode::MC_NOT_IN_SYNC;

            break;

        default:
            FAPI_ERR("Invalid speed_equality parameter!");
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
            break;
    }// end switch

    return fapi2::FAPI2_RC_SUCCESS;
}

}// mss
