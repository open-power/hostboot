/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_load_pie.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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
#include <lib/phy/ody_draminit_utils.H>

#include <lib/mc/ody_port.H>
#include <lib/mc/ody_port_traits.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>

extern "C"
{
///
/// @brief Load the PHY Initialization Engine (PIE) to initialize the PHY to mainline mode
/// @param[in] i_target, the MC of the ports
/// @param[in] i_code_data0 - hwp_data_istream for the PIE image data for port0
/// @param[in] i_code_data1 - hwp_data_istream for the PIE image data for port1
/// @param[in] i_code_sections0 - hwp_data_istream for the PIE code sections for port0
/// @param[in] i_code_sections1 - hwp_data_istream for the PIE code sections for port1
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_load_pie( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    fapi2::hwp_data_istream& i_code_data0,
                                    fapi2::hwp_data_istream& i_code_data1,
                                    fapi2::hwp_data_istream& i_code_sections0,
                                    fapi2::hwp_data_istream& i_code_sections1 )
    {
        mss::display_git_commit_info("ody_load_pie");

        uint8_t l_draminit_step_enable = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DRAMINIT_STEP_ENABLE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_draminit_step_enable));

        if (mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_PIE, l_draminit_step_enable))
        {
            FAPI_INF_NO_SBE(TARGTIDFORMAT " ATTR_ODY_DRAMINIT_STEP_ENABLE set to skip ody_load_pie. Exiting...", TARGTID);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
        {
            uint8_t l_pos = 0;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, l_port, l_pos));

            FAPI_TRY(dwc_ddrphy_phyinit_I_loadPIEImage(l_port,
                     (l_pos == 0) ? i_code_data0 : i_code_data1,
                     (l_pos == 0) ? i_code_sections0 : i_code_sections1));

            // Throws the DRAM into self-time refresh mode
            FAPI_TRY(mss::change_force_str<mss::mc_type::ODYSSEY>( i_target, mss::states::ON ));
        }

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }
}
