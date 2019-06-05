/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_scrub.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p9_mss_scrub.C
/// @brief Begin background scrub
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/nimbus_defaults.H>
#include <fapi2.H>
#include <p9_mss_scrub.H>

#include <lib/dimm/rank.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.H>
#include <lib/mcbist/memdiags.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/fir/unmask.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

extern "C"
{

    ///
    /// @brief Begin background scrub
    /// @param[in] i_target MCBIST
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_scrub( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
    {
        FAPI_INF("Start mss scrub for %s", mss::c_str(i_target));
        // Initialize memory and set firs accordingly
        FAPI_TRY(mss::memdiags::mss_initialize_memory(i_target));
        // Kickoff background scrub and unmask firs
        FAPI_TRY(mss::memdiags::mss_background_scrub_helper(i_target));

    fapi_try_exit:
        return fapi2::current_err;
    }

}
