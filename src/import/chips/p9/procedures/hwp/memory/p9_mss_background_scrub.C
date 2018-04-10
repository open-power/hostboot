/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_background_scrub.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file p9_mss_background_scrub.C
/// @brief Begin background scrub
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mss_background_scrub.H>

#include <lib/dimm/rank.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mcbist/patterns.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/sim.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/fir/memdiags_fir.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

///
/// @brief Begin background scrub
/// @param[in] i_target MCBIST
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_background_scrub( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("Start mss background scrub on: %s", mss::c_str( i_target ));

    // If there are no DIMM we don't need to bother. In fact, we can't as we didn't setup
    // attributes for the PHY, etc.
    if (mss::count_dimm(i_target) == 0)
    {
        FAPI_INF("... skipping background scrub for %s - no DIMM ...", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // If we're running in the simulator, we want to only touch the addresses which training touched
    uint8_t l_sim = 0;
    FAPI_TRY( mss::is_simulation(l_sim) );

    // Kick off background scrub if we are not running in sim
    if (!(l_sim))
    {
        // Start background scrub
        FAPI_TRY ( mss::memdiags::background_scrub( i_target,
                   mss::mcbist::stop_conditions(),
                   mss::mcbist::speed::BG_SCRUB,
                   mss::mcbist::address() ) );

    }

    // Unmask firs after background scrub is started
    FAPI_TRY ( mss::unmask::after_background_scrub( i_target ) );

fapi_try_exit:
    return fapi2::current_err;
}
