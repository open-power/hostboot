/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_throttle_sync.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_throttle_sync.C
/// @brief p10_throttle_sync HWP
/// @note The purpose of this procedure is to triggers sync command from a 'master'
/// MC to other MCs that have attached memory in a processor.
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB
///

#include <fapi2.H>
#include <p10_throttle_sync.H>
#include <lib/power_thermal/p10_throttle_sync_utils.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/count_dimm.H>

extern "C"
{
    ///
    /// @brief p10_throttle_sync procedure
    ///
    /// @param[in] i_target TARGET_TYPE_PROC_CHIP target
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode p10_throttle_sync(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Executing p10_throttle_sync on %s", mss::c_str(i_target));
        const auto l_mi_list = mss::find_targets<fapi2::TARGET_TYPE_MI>(i_target);

        if (l_mi_list.size() == 0)
        {
            FAPI_INF("No MIs found under %s -- skipping", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        bool l_primary_mi = true;

        // Loop through and configure all MI and associated OCMB appropriately
        for (const auto& mi : l_mi_list)
        {
            if (mss::count_dimm(mi) == 0)
            {
                FAPI_INF("No DIMMs on %s -- skipping", mss::c_str(mi));
                continue;
            }

            // Enable sync operations for all MIs
            FAPI_TRY(mss::setup_sync(mi, l_primary_mi),
                     "setup_sync failed on %s", mss::c_str(mi));

            // Enable the OCMB's to be in sync mode
            FAPI_TRY(mss::configure_ocmb_sync_operations(mi, mss::states::ON),
                     "configure_ocmb_sync_operations failed on %s", mss::c_str(mi));

            if(l_primary_mi)
            {
                FAPI_DBG("Setup MI %s as primary MI target", mss::c_str(mi));
            }

            // Mark the first seen
            l_primary_mi = false;
        }

        // Now, issue the sync command from the primary MI
        for (const auto& mi : l_mi_list)
        {
            if (mss::count_dimm(mi) == 0)
            {
                FAPI_INF("No DIMMs on %s -- skipping", mss::c_str(mi));
                continue;
            }

            FAPI_TRY(mss::issue_sync(mi), "issue_sync failed on %s", mss::c_str(mi));

            // Only issue the sync command on the primary MI
            break;
        }// MIs

        // Finally loop through and disable the OCMB's sync operations
        for (const auto& mi : l_mi_list)
        {
            if (mss::count_dimm(mi) == 0)
            {
                FAPI_INF("No DIMMs on %s -- skipping", mss::c_str(mi));
                continue;
            }

            FAPI_TRY(mss::configure_ocmb_sync_operations(mi, mss::states::OFF),
                     "configure_ocmb_sync_operations failed on %s", mss::c_str(mi));
        }// MIs

    fapi_try_exit:
        FAPI_DBG("Exiting p10_throttle_sync on %s", mss::c_str(i_target));
        return fapi2::current_err;
    }

} // extern "C"
