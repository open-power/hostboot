/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_scrub.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_scrub.C
/// @brief Begin background scrub
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/exp_defaults.H>
#include <exp_scrub.H>
#include <lib/utils/mss_exp_conversions.H>
#include <lib/mcbist/exp_memdiags.H>

extern "C"
{

    ///
    /// @brief Begin background scrub
    /// @param[in] i_target OCMB chip
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_scrub(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        FAPI_INF("Start exp scrub for %s", mss::c_str(i_target));
        // Initialize memory and set firs accordingly
        FAPI_TRY(mss::memdiags::mss_initialize_memory(i_target));
        // Kickoff background scrub and unmask firs
        FAPI_TRY(mss::memdiags::mss_background_scrub_helper(i_target));

    fapi_try_exit:
        FAPI_INF("End exp scrub for %s", mss::c_str(i_target));
        return fapi2::current_err;
    }

}
