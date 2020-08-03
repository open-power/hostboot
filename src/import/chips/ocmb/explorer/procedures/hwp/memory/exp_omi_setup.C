/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_omi_setup.C $ */
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
/// @file exp_omi_setup.C
/// @brief Contains the explorer OMI setup
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <lib/shared/exp_defaults.H>
#include <exp_omi_setup.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/omi/exp_omi_utils.H>
#include <lib/workarounds/exp_omi_workarounds.H>
#include <lib/i2c/exp_i2c.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <mss_generic_system_attribute_getters.H>

extern "C"
{

    ///
    /// @brief Setup the OCMB for enterprise and half-DIMM modes as desired
    /// @param[in] i_target the OCMB target to operate on
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_omi_setup( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("exp_omi_setup");
        fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);
        uint8_t l_gem_menterp_workaround = 0;
        uint8_t l_enable_ffe_settings = 0;

        // Declares variables
        std::vector<uint8_t> l_boot_config_data;
        std::vector<uint8_t> l_ffe_setup_data;

        // BOOT CONFIG 0
        uint8_t l_dl_layer_boot_mode = fapi2::ENUM_ATTR_MSS_OCMB_EXP_BOOT_CONFIG_DL_LAYER_BOOT_MODE_NON_DL_TRAINING;

        uint8_t l_sim = 0;
        FAPI_TRY(mss::attr::get_is_simulation(l_sim));

        // Skip the rest if we are in sim
        if (l_sim)
        {
            FAPI_INF("Sim, exiting exp_omi_setup %s", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // FFE Setup
        FAPI_TRY(mss::attr::get_omi_ffe_settings_command(i_target, l_enable_ffe_settings));

        if (l_enable_ffe_settings == fapi2::ENUM_ATTR_OMI_FFE_SETTINGS_COMMAND_ENABLE)
        {
            FAPI_TRY(mss::exp::omi::ffe_setup(i_target, l_ffe_setup_data));
            FAPI_TRY(mss::exp::i2c::send_ffe_settings(i_target, l_ffe_setup_data));
            FAPI_TRY(mss::exp::i2c::fw_status(i_target, mss::DELAY_1MS, 100));
        }

        // Gets the data setup
        FAPI_TRY(mss::exp::omi::train::setup_fw_boot_config(i_target, l_boot_config_data));

        // Sanity check: set dl_layer_boot_mode to NON DL TRAINING (0b00 == default)
        FAPI_TRY(mss::exp::i2c::boot_cfg::set_dl_layer_boot_mode( i_target, l_boot_config_data, l_dl_layer_boot_mode ));

        // Issues the command and checks for completion
        // Note: This does not kick off OMI training
        FAPI_TRY(mss::exp::i2c::boot_config(i_target, l_boot_config_data));

        // Check FW status for success
        // Note: Extended polling count from 100 to 1000 to account for longer Boot_config_0 sequence
        // in Explorer FW CL-384401.
        l_rc = mss::exp::i2c::fw_status(i_target, mss::DELAY_1MS, 1000);

        // Note: It's still under discussion whether FIRs will be lit if BOOT_CONFIG_0 fails, and if
        // the registers will be clocked so we can read them. Disabling FIR checking until this
        // gets resolved.
#ifdef FIRS_AVAIL_AFTER_BOOT_CONFIG_0_FAIL
        // If BOOT_CONFIG_0 failed or timed out, we need to check some FIRs
        FAPI_TRY( (mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER, mss::check::firChecklist::OMI>(i_target, l_rc)) );
#else
        FAPI_TRY(l_rc, "%s BOOT_CONFIG_0 either failed or timed out", mss::c_str(i_target));
#endif

        FAPI_TRY(mss::exp::workarounds::omi::gem_menterp(i_target, l_gem_menterp_workaround));

        // If no workaround (explorer), we can perform menterp reads/writes
        // If workaround (gemini). we need to bypass menterp. Can also bypass dlx_config1 too since it's a noop
        if (l_gem_menterp_workaround)
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Set up DLX_CONFIG1
        {
            fapi2::buffer<uint64_t> l_data;
            fapi2::buffer<uint64_t> l_dlx_config1_data;

            uint8_t l_edpl_disable = 0;
            uint8_t l_enterprise_attr = 0;
            bool l_is_half_dimm = false;
            bool l_is_enterprise = false;

            // Gets the configuration information from attributes
            FAPI_TRY(mss::attr::get_ocmb_enterprise_mode(i_target, l_enterprise_attr));
            l_is_enterprise = (l_enterprise_attr == fapi2::ENUM_ATTR_MSS_OCMB_ENTERPRISE_MODE_ENTERPRISE);

            FAPI_TRY(mss::half_dimm_mode(i_target, l_is_enterprise, l_is_half_dimm));
            FAPI_TRY(mss::attr::get_mss_omi_edpl_disable(l_edpl_disable));

            // Prints out the data
            FAPI_INF("%s is %s enterprise mode, and %s-DIMM mode", mss::c_str(i_target), l_is_enterprise ? "" : "non",
                     l_is_half_dimm ? "half" : "full");

            // Sets up the register
            mss::exp::omi::set_enterprise_set_bit(l_data, l_is_enterprise);
            mss::exp::omi::set_half_dimm_mode(l_data, l_is_half_dimm);

            // Writes the data to the register
            FAPI_TRY(mss::exp::omi::write_enterprise_config(i_target, l_data));

            // Checks that the chip is configured correctly
            FAPI_TRY(mss::exp::omi::read_enterprise_config(i_target, l_data));
            FAPI_TRY(mss::exp::omi::check_enterprise_mode(i_target, l_is_enterprise, l_data));

            // Set the EDPL according the attribute
            FAPI_TRY(mss::exp::omi::read_dlx_config1(i_target, l_dlx_config1_data));
            mss::exp::omi::set_edpl_enable_bit(l_dlx_config1_data, !l_edpl_disable);
            FAPI_TRY(mss::exp::omi::write_dlx_config1(i_target, l_dlx_config1_data));
            FAPI_INF("%s EDPL enable: %s", mss::c_str(i_target), l_edpl_disable ? "false" : "true");
        }

        // Update explorer CDR BW value to 0x2F based on Chris Steffen's testing
        FAPI_TRY(mss::exp::workarounds::omi::cdr_bw_override(i_target));

        // Perform p10 workaround
        // Train mode 6 (state 3)
        FAPI_TRY(mss::exp::workarounds::omi::pre_training_prbs(i_target));

        // Unmask FIRs
        FAPI_TRY(mss::unmask::after_mc_omi_setup<mss::mc_type::EXPLORER>(i_target));

    fapi_try_exit:
        return fapi2::current_err;
    }
}
