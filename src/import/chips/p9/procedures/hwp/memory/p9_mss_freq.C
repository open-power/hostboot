/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_freq.C $                */
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
/// @file p9_mss_freq.C
/// @brief Calculate and save off DIMM frequencies
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <cstring>
#include <cstdint>

#include <fapi2.H>
#include <mss.H>
#include <p9_mss_freq.H>
#include <lib/spd/spd_decoder.H>
#include <lib/freq/cas_latency.H>
#include <lib/utils/c_str.H>
#include <lib/freq/cycle_time.H>
#include <lib/utils/find.H>

using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;

extern "C"
{

    ///
    /// @brief Calculate and save off DIMM frequencies
    /// @param[in] i_target, the controller (e.g., MCS)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_freq( const fapi2::Target<TARGET_TYPE_MCS>& i_target )
    {
        // Get cached decoder
        std::map<uint32_t, std::shared_ptr<mss::spd::decoder> > l_factory_caches;
        FAPI_TRY( mss::spd::populate_decoder_caches(i_target, l_factory_caches),
                  "Failed to populate decoder cache");

        {
            // instantiation of class that calculates CL algorithm
            mss::cas_latency l_cas_latency(i_target, l_factory_caches);

#if 0   // TK - encapsulated functionality left over from p8, how do we tackle this for p9?? -AAM
            // left for reference

            // TK - Need to add functionality for determining system setting based
            // on system drop (e.g. single & dual drop) and configuration.
            // How will we determine a system is single or dual drop?
            // What will we do if there is dimm mixing?
            // How does this affect tck timing ? - AAM

            // TK - Need to incorporate code path for overrides
            FAPI_TRY(mss::check_for_freq_override(l_target_mcbist,
                                                  l_tCKmin),
                     "Failed check for freq_override()");

#endif
            uint64_t l_min_dimm_freq = 0;
            uint64_t l_desired_cas_latency = 0;

            if(!l_cas_latency.iv_dimm_list_empty)
            {
                uint64_t l_tCKmin = 0;

                // Find CAS latency using JEDEC algorithm
                l_cas_latency.find_CL(i_target,
                                      l_desired_cas_latency,
                                      l_tCKmin);

                // Find dimm transfer speed from selected tCK
                l_min_dimm_freq = mss::ps_to_freq(l_tCKmin);

                FAPI_TRY(mss::select_supported_freq(l_min_dimm_freq),
                         "Failed select_supported_freq()");

                // TK - RIT PROTECT - NEED TO CHANGE
                l_min_dimm_freq = 2400;

                // Set attributes
                FAPI_TRY(mss::set_freq_attrs(i_target, l_min_dimm_freq),
                         "Failed set_freq_attrs()");

                FAPI_TRY(mss::set_CL_attr(i_target, l_desired_cas_latency ),
                         "Failed set_CL_attr()");
            }// end if

            FAPI_DBG( "Final Chosen Frequency: %d",  l_min_dimm_freq);
            FAPI_DBG( "Final Chosen CL: %d",  l_desired_cas_latency);

        }

    fapi_try_exit:
        return fapi2::current_err;

    }// p9_mss_freq

}// extern C
