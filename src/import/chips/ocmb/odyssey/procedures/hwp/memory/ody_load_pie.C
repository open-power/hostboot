/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_load_pie.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
/* [+] International Business Machines Corp.                              */
/* [+] Synopsys, Inc.                                                     */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_load_pie.C
/// @brief Loads the binaries for the PHY Initialization Engine (PIE) to initialize the PHY to mainline mode
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_load_pie.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/count_dimm.H>

#include <generic/memory/mss_git_data_helper.H>
#include <lib/phy/dwc_ddrphy_phyinit_I_loadPIEImage.H>

extern "C"
{
///
/// @brief Load the PHY Initialization Engine (PIE) to initialize the PHY to mainline mode
/// @param[in] i_target, the MC of the ports
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_load_pie( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
    {
        mss::display_git_commit_info("ody_load_pie");

        for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
        {
            FAPI_TRY(dwc_ddrphy_phyinit_I_loadPIEImage(l_port));
        }

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }
}
