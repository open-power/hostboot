/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_scrub.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
/// @file ody_scrub.C
/// @brief Begin background scrub
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_scrub.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/dimm/ody_rank.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/mc/ody_port.H>
#include <lib/mcbist/ody_memdiags.H>


extern "C"
{

    ///
    /// @brief Begin background scrub
    /// @param[in] i_target OCMB chip
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode ody_scrub(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        FAPI_INF("Start ody scrub for %s", mss::c_str(i_target));
        // Initialize memory and set firs accordingly
        FAPI_TRY(mss::memdiags::mss_initialize_memory<mss::mc_type::ODYSSEY>(i_target));
        // Kickoff background scrub and unmask firs
        FAPI_TRY(mss::memdiags::mss_background_scrub_helper<mss::mc_type::ODYSSEY>(i_target));

    fapi_try_exit:
        FAPI_INF("End ody scrub for %s", mss::c_str(i_target));
        return fapi2::current_err;
    }

}
