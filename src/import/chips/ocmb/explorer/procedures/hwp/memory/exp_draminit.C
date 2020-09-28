/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_draminit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file exp_draminit.C
/// @brief Procedure definition to initialize DRAM
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <lib/shared/exp_defaults.H>
#include <lib/shared/exp_consts.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <lib/dimm/exp_mrs_traits.H>
#include <lib/inband/exp_inband.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <lib/exp_draminit_utils.H>
#include <lib/phy/exp_phy_reset.H>
#include <lib/phy/exp_train_display.H>
#include <lib/phy/exp_train_handler.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <lib/workarounds/exp_mr_workarounds.H>
#include <mss_generic_system_attribute_getters.H>

extern "C"
{

    ///
    /// @brief Initializes DRAM
    /// @param[in] i_target the controller
    /// @return FAPI2_RC_SUCCESS if ok
    ///
    fapi2::ReturnCode exp_draminit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("exp_draminit");

        uint8_t l_phy_init_mode = 0;

        // Get phy init mode attribute
        FAPI_TRY(mss::attr::get_exp_phy_init_mode(i_target, l_phy_init_mode));

        // Make sure we're in range
        FAPI_ASSERT((l_phy_init_mode <= fapi2::ENUM_ATTR_MSS_OCMB_PHY_INIT_MODE_WITH_EYE_CAPTURE),
                    fapi2::MSS_EXP_UNKNOWN_PHY_INIT_MODE()
                    .set_TARGET(i_target)
                    .set_VALUE(l_phy_init_mode),
                    "%s Value for phy init mode for exp_draminit is unknown: %u expected 0 (NORMAL), 1 (WITH_EYE_CAPTURE)",
                    mss::c_str(i_target), l_phy_init_mode);

        FAPI_TRY(mss::exp::host_fw_phy_init(i_target, l_phy_init_mode));

        // Loops through the ports and issues the MRS based workarounds over CCS
        for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
        {
            FAPI_TRY(mss::exp::workarounds::updates_mode_registers(l_port));
        }

        // Unmask registers after draminit training
        FAPI_TRY(mss::unmask::after_draminit_training(i_target), "%s Failed after_draminit_training", mss::c_str(i_target));

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        FAPI_INF("Draminit training - %s %s",
                 (fapi2::current_err == fapi2::FAPI2_RC_SUCCESS ? "success" : "errors reported - trying to blame FIR's"),
                 mss::c_str(i_target));

        // Due to the RAS/PRD requirements, we need to check for FIR's
        // If any FIR's have lit up, this draminit fail could have been caused by the FIR, rather than bad hardware
        // So, let PRD retrigger this step to see if we can resolve the issue
        return mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER,
               mss::check::firChecklist::DRAMINIT>(i_target, fapi2::current_err);
    }

} // extern C
