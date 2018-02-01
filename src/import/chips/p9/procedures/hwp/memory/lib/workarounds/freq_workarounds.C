/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/freq_workarounds.C $ */
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
/// @file workarounds/freq_workarounds.C
/// @brief Frequency related workarounds
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/workarounds/freq_workarounds.H>
#include <lib/utils/assert_noexit.H>

namespace mss
{

namespace workarounds
{

///
/// @brief Ensures the ratio between DIMM and NEST frequencies is within allowable limit
/// @param[in] i_target - the MCBIST target to check
/// @param[in] i_dimm_speed - dimm speed in MT/s
/// @param[in] i_nest_freq - nest freq in MHz
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode check_dimm_nest_freq_ratio( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const uint64_t i_dimm_speed,
        const uint32_t i_nest_freq )
{
    constexpr double MAX_MEM_NEST_FREQ_RATIO = 1.5;
    double l_ratio = 0;

    FAPI_INF("%s Checking the MEM to NEST frequency ratio versus the allowed limit", mss::c_str(i_target));

    // Protect against nest_freq == 0 (divide by zero)
    // This should never happen, so do a code callout
    FAPI_ASSERT((i_nest_freq != 0) && (i_dimm_speed != 0),
                fapi2::MSS_FREQ_OR_NEST_FREQ_IS_ZERO()
                .set_MSS_FREQ(i_dimm_speed)
                .set_NEST_FREQ(i_nest_freq),
                "%s saw a zero memory or nest frequency when checking mem to nest freq ratio: mss: %d, nest: %d",
                mss::c_str(i_target),
                i_dimm_speed,
                i_nest_freq);

    // Check limit
    l_ratio = static_cast<double>(i_dimm_speed) / static_cast<double>(i_nest_freq);
    FAPI_INF("l_ratio = %f, max_ratio = %f", l_ratio, MAX_MEM_NEST_FREQ_RATIO);

    if (l_ratio > MAX_MEM_NEST_FREQ_RATIO)
    {
        // Deconfigure MCSes
        for ( const auto& l_mcs : mss::find_targets<fapi2::TARGET_TYPE_MCS>(i_target) )
        {
            MSS_ASSERT_NOEXIT(false,
                              fapi2::MSS_FREQ_TO_NEST_FREQ_RATIO_TOO_LARGE()
                              .set_MSS_FREQ(i_dimm_speed)
                              .set_NEST_FREQ(i_nest_freq)
                              .set_MCS_TARGET(l_mcs),
                              "Deconfiguring %s due to the memory to nest frequency ratio being too large: mss: %d, nest: %d, ratio: %f",
                              mss::c_str(l_mcs),
                              i_dimm_speed,
                              i_nest_freq,
                              l_ratio);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace workarounds

} // namespace mss
