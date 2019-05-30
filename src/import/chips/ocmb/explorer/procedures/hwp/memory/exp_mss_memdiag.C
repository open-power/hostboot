/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_mss_memdiag.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file exp_mss_memdiag.C
/// @brief HW Procedure pattern testing
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <exp_mss_memdiag.H>
#include <lib/shared/exp_defaults.H>
#include <lib/dimm/exp_rank.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.H>

using fapi2::TARGET_TYPE_OCMB_CHIP;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::TARGET_TYPE_MEM_PORT;
using fapi2::FAPI2_RC_SUCCESS;

extern "C"
{
    ///
    /// @brief Begin background scrub and run pattern tests
    /// @param[in] i_target OCMB Chip
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_mss_memdiag( const fapi2::Target<TARGET_TYPE_OCMB_CHIP>& i_target )
    {
        FAPI_INF("Start mss memdiags on: %s", mss::c_str( i_target ));

        // TODO: Actually implement this.

        FAPI_INF("End memdiag");
        return fapi2::current_err;
    }
}
