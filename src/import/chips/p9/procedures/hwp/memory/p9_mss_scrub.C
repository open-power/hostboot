/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_scrub.C $               */
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
/// @file p9_mss_scrub.C
/// @brief Begin background scrub
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mss_scrub.H>

#include <lib/dimm/rank.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mcbist/patterns.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/sim.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

///
/// @brief Begin background scrub
/// @param[in] i_target MCBIST
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_scrub( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("Start mss scrub");

    // If we're running in the simulator, we want to only touch the addresses which training touched
    uint8_t is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    if (is_sim)
    {
        // Use some sort of pattern in sim in case the verification folks need to look for something
        // TK. Need a verification pattern. This is a not-good pattern for verification ... We don't really
        // have a good pattern for verification defined.
        FAPI_INF("running mss sim init in place of scrub");
        return mss::mcbist::sim::sf_init(i_target, mss::mcbist::PATTERN_2);
    }

    // TK do we want these to be arguments to the wrapper?
    return memdiags::background_scrub(i_target, mss::mcbist::stop_conditions::NO_STOP_ON_ERROR, mss::mcbist::thresholds(),
                                      mss::mcbist::speed::LUDICROUS, mss::mcbist::address());

fapi_try_exit:
    return fapi2::current_err;
}
