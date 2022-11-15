/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_host_draminit.C $ */
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
/// @file ody_host_draminit.C
/// @brief Send chipop to Odyssey via inband FIFO
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_host_draminit.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <lib/phy/ody_draminit_utils.H>

extern "C"
{
///
/// @brief Check FIRs after draminit training and record training fails
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_host_draminit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("ody_host_draminit");

        for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
        {
            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

            // Get the bad bits from the attribute (read from Odyssey SPPE previously)
            mss::ody::phy::host_bad_bit_interface l_interface(l_dimm, l_rc);
            FAPI_TRY(l_rc);

            // Check for FIRs then record the bad bits data into our attribute and SPD if there are no FIRs set
            FAPI_TRY(mss::record_bad_bits<mss::mc_type::ODYSSEY>(i_target, l_interface));
        }

    fapi_try_exit:
        return fapi2::current_err;

    }

}// extern C
