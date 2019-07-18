/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_freq.C $     */
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
/// @file p9_mss_freq.C
/// @brief Calculate and save off DIMM frequencies
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <p9_mss_freq.H>

// std lib
#include <map>
#include <utility>
// fapi2
#include <fapi2.H>

// mss lib
#include <lib/freq/nimbus_freq_traits.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq.H>
#include <lib/eff_config/pre_data_init.H>

using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::FAPI2_RC_SUCCESS;

extern "C"
{
    // TK:LRDIMM Update frequency for LRDIMM - I don't think this will change at all, but better safe than sorry SPG
    ///
    /// @brief Calculate and save off DIMM frequencies
    /// @param[in] i_target, the controller (e.g., MCS)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_freq( const fapi2::Target<TARGET_TYPE_MCS>& i_target )
    {
        // TODO RTC:161701 p9_mss_freq needs to be re-worked to work per-MC as it's hard
        // (if not impossible) to know the appropriate freq if we don't have information
        // for both MCS. Setting one to max freq doesn't work in the case of 0 DIMM as
        // there is no check for other freq's and we end up setting the chosen freq to
        // the default.
        // So for now, iterate over all the MCBIST. This isn't great as we do this work
        // twice for every MC. However, attribute access is cheap so this will suffice for
        // the time being.
        const auto l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

        // If there are no DIMM, we can just get out.
        if (mss::count_dimm(l_mcbist) == 0)
        {
            FAPI_INF("Seeing no DIMM on %s, no freq to set", mss::c_str(l_mcbist));
            return FAPI2_RC_SUCCESS;
        }

        // We will first set pre-eff_config attributes
        FAPI_TRY(mss::set_pre_init_attrs<mss::proc_type::NIMBUS>(l_mcbist));

        FAPI_TRY(mss::generate_freq<mss::proc_type::NIMBUS>(l_mcbist));

    fapi_try_exit:
        return fapi2::current_err;

    }// p9_mss_freq
}// extern C
