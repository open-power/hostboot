/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_host_draminit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_host_draminit.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/phy/ody_phy_access.H>

extern "C"
{
///
/// @brief Perform Host side cleanup after Odyssey draminit (currently just a placeholder)
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_host_draminit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("ody_host_draminit");

        // Initialize address range in PHY imem that's used for DQS drift recal logs
        for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
        {
            FAPI_TRY(mss::ody::phy::configure_phy_scom_access(l_port, mss::states::ON_N));

            // Log area
            for (uint64_t l_log_idx = 0; l_log_idx < mss::ddr5::ATTR_ODY_DQS_TRACKING_LOG_ENTRIES; l_log_idx++)
            {
                fapi2::buffer<uint64_t> l_buf;

                for (uint8_t l_hword = 0; l_hword < mss::ddr5::ATTR_ODY_DQS_TRACKING_LOG_HWORDS_PER_ENTRY; l_hword++)
                {
                    const uint64_t l_syn_addr = mss::ddr5::ODY_DQS_TRACKING_LOG_START_ADDRESS +
                                                l_log_idx * mss::ddr5::ATTR_ODY_DQS_TRACKING_LOG_HWORDS_PER_ENTRY + l_hword;
                    const uint64_t l_address = mss::ody::phy::convert_synopsys_to_ibm_reg_addr(l_syn_addr);

                    FAPI_TRY(fapi2::putScom(l_port, l_address, l_buf));
                }
            }

            // And the recal count
            {
                const uint64_t l_address = mss::ody::phy::convert_synopsys_to_ibm_reg_addr(
                                               static_cast<uint64_t>(mss::ddr5::ODY_DQS_TRACKING_COUNT_START_ADDRESS));
                const uint64_t l_address_odd = mss::ody::phy::convert_synopsys_to_ibm_reg_addr(
                                                   static_cast<uint64_t>(mss::ddr5::ODY_DQS_TRACKING_COUNT_START_ADDRESS + 1));

                FAPI_TRY(fapi2::putScom(l_port, l_address, 0));
                // Required to write even+odd addresses on PHY imem
                FAPI_TRY(fapi2::putScom(l_port, l_address_odd, 0));
            }

            FAPI_TRY(mss::ody::phy::configure_phy_scom_access(l_port, mss::states::OFF_N));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
}// extern C
