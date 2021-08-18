/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_omi_train.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file exp_omi_train.C
/// @brief Contains the explorer OMI train
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/omi/exp_omi_utils.H>
#include <lib/i2c/exp_i2c.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/workarounds/exp_omi_workarounds.H>
#include <exp_omi_train.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <mss_generic_system_attribute_getters.H>
#include <i2c/exp_i2c_fields.H>

extern "C"
{

    ///
    /// @brief Trains the OCMB link
    /// @param[in] i_target the OCMB target to operate on
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_omi_train_internal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("exp_omi_train");

        fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);
        uint8_t l_sim = 0;
        FAPI_TRY(mss::attr::get_is_simulation(l_sim));

        if (!l_sim)
        {
            // Train mode 1 (PATTERN_A)
            FAPI_TRY(mss::exp::workarounds::omi::training_prbs(i_target));
        }

        // BOOT CONFIG 1
        {
            bool l_ocmb_is_explorer = false;

            std::vector<uint8_t> l_cmd_data;
            std::vector<uint8_t> l_rsp_data;
            uint8_t l_dl_layer_boot_mode = fapi2::ENUM_ATTR_MSS_OCMB_EXP_BOOT_CONFIG_DL_LAYER_BOOT_MODE_ONLY_DL_TRAINING;

            // Gets the data setup
            FAPI_TRY(mss::exp::omi::train::setup_fw_boot_config(i_target, l_cmd_data));

            // Sets DL_TRAIN field
            FAPI_TRY(mss::exp::i2c::boot_cfg::set_dl_layer_boot_mode( i_target, l_cmd_data, l_dl_layer_boot_mode ));

            // Issues the command and checks for completion
            FAPI_TRY(mss::exp::i2c::boot_config(i_target, l_cmd_data));

            // Return success code for Gemini
            if (!l_sim)
            {
                FAPI_TRY(mss::exp::workarounds::omi::ocmb_is_explorer(i_target, l_ocmb_is_explorer));
            }

            if (!l_ocmb_is_explorer)
            {
                // Gemini should return success code
                FAPI_TRY(mss::exp::i2c::poll_fw_status(i_target, mss::DELAY_1MS, 100, l_rsp_data));
                FAPI_TRY(mss::exp::i2c::check::boot_config(i_target, l_cmd_data, l_rsp_data));
            }

        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Trains the OCMB link
    /// @param[in] i_target the OCMB target to operate on
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_omi_train(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        // Check if we running on Apollo
        uint8_t l_is_apollo;
        mss::attr::get_is_apollo(l_is_apollo);

        if (l_is_apollo)
        {
            FAPI_TRY(exp_omi_train_internal(i_target));
        }
        else
        {
            FAPI_DBG("Called exp_omi_train::Skipping...");
        }

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }
}
