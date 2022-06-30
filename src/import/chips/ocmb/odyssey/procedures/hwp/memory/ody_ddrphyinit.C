/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_ddrphyinit.C $ */
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
/// @file ody_ddrphyinit.C
/// @brief Configure settings for Synopsys DDR PHYs
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <generic/memory/lib/utils/find.H>

#ifndef __PPE__
    #include <generic/memory/lib/utils/c_str.H>
    #include <generic/memory/lib/utils/mss_generic_check.H>
#endif

#include <ody_ddrphyinit.H>

#include <lib/phy/ody_ddrphy_phyinit_config.H>
#include <lib/phy/ody_phy_reset.H>

extern "C"
{
///
/// @brief Configure settings for Synopsys DDR PHYs
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_ddrphyinit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {

        for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
        {
            // Perform PHY reset for Odyssey
            FAPI_TRY(mss::ody::phy::reset(l_port));

            // Runs all steps of PHY init
            FAPI_TRY(run_phy_init(l_port), TARGTIDFORMAT "failed init_phy_config", TARGTID);
        }

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }

}// extern C
