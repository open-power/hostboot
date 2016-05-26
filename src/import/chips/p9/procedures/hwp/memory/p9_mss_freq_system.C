/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_freq_system.C $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file p9_freq_system.C
/// @brief Sets synchronous mode an
///
// *HWP HWP Owner: Andre A. Marin  <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
#include <vector>
#include <map>

#include <fapi2.H>
#include <mss.H>

#include <p9_mss_freq_system.H>
#include <lib/utils/find.H>
#include <lib/freq/sync.H>

using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::TARGET_TYPE_PROC_CHIP;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCS;

extern "C"
{
    ///
    /// @brief Set synchronous mode
    /// @param[in] i_targets vector of controllers (e.g., MCS)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_freq_system( const std::vector< fapi2::Target<TARGET_TYPE_MCBIST> >& i_targets )
    {
        FAPI_INF("----- In p9_mss_freq_system ----");

        std::map< fapi2::Target<TARGET_TYPE_MCBIST>, uint64_t > l_freq_map;
        uint32_t l_nest_freq = 0;
        uint8_t l_required_sync_mode = 0;
        mss::sync_mode l_mc_in_sync;
        mss::speed_equality l_equal_dimm_speed;

        // Populate dimm speed map
        FAPI_TRY( mss::dimm_speed_map(i_targets, l_freq_map, l_equal_dimm_speed),
                  "Failed to get dimm speed mapping" );

        FAPI_INF("Dimm speed for all MCBISTs are the same : %s",
                 uint8_t(l_equal_dimm_speed) ? "true" : "false");

        // Get nest freq && F/W attr that tells me if sync mode is required
        // or if I have to figure that out
        FAPI_TRY( mss::required_synch_mode(l_required_sync_mode) );
        FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_FREQ_PB_MHZ, fapi2::Target<TARGET_TYPE_SYSTEM>(), l_nest_freq) );

        FAPI_INF("Retrieved req'd sync mode: %d and nest freq %d", l_required_sync_mode, l_nest_freq);

        // Select SYNCH mode
        FAPI_TRY( mss::select_sync_mode(l_freq_map,
                                        l_equal_dimm_speed,
                                        l_nest_freq,
                                        l_required_sync_mode,
                                        l_mc_in_sync) );

        FAPI_INF("Selected SYNC mode : %s", uint8_t(l_mc_in_sync) ? "MC in sync" : "MC NOT in sync");

        // Set attribute
        for(const auto& l_mcbist : i_targets)
        {
            const auto& l_proc_chip = mss::find_target<TARGET_TYPE_PROC_CHIP>(l_mcbist);

            // Cast converts enum class to uint8_t& expected for ATTR_SET
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MC_SYNC_MODE, l_proc_chip, reinterpret_cast<uint8_t(&)>(l_mc_in_sync) ),
                      "Failed to set ATTR_MC_SYNC_MODE");
        }

    fapi_try_exit:
        return fapi2::current_err;

    } // p9_freq_system

} //extern "C"
