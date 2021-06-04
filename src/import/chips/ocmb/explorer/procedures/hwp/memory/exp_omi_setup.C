/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_omi_setup.C $ */
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
/// @file exp_omi_setup.C
/// @brief Contains the explorer OMI setup
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
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
#include <mss_explorer_attribute_setters.H>
#include <lib/i2c/exp_i2c_fields.H>
#include <p10_io_omi_prbs.H>

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

        fapi2::ReturnCode l_rc_bootconfig0(fapi2::FAPI2_RC_SUCCESS);
        fapi2::ReturnCode l_rc_bootconfig0_copy(fapi2::FAPI2_RC_SUCCESS);
        fapi2::ReturnCode l_rc_unmask(fapi2::FAPI2_RC_SUCCESS);
        fapi2::ReturnCode l_rc_firchk(fapi2::FAPI2_RC_SUCCESS);
        uint8_t l_gem_menterp_workaround = 0;
        uint8_t l_enable_ffe_settings = 0;
        uint32_t l_omi_freq = 0;
        uint8_t l_is_apollo = 0;
        bool l_mnfg_screen_test = false;
        fapi2::ATTR_MSS_EXP_OMI_CDR_BW_OVERRIDE_Type l_cdr_bw_override = 0;
        fapi2::ATTR_MSS_EXP_OMI_CDR_OFFSET_Type l_cdr_offset = 0;
        fapi2::ATTR_MSS_EXP_OMI_CDR_OFFSET_LANE_MASK_Type l_cdr_offset_lane_mask = 0;

        // Declares variables
        std::vector<uint8_t> l_boot_config_data;
        std::vector<uint8_t> l_ffe_setup_data;
        std::vector<uint8_t> l_fw_status_data;

        const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);

        uint8_t l_sim = 0;
        FAPI_TRY(mss::attr::get_is_simulation(l_sim));

        // Skip the rest if we are in sim
        if (l_sim)
        {
            FAPI_INF("Sim, exiting exp_omi_setup %s", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY(mss::attr::get_is_apollo(l_is_apollo));
        FAPI_TRY(mss::exp::check_omi_mfg_screen_edpl_setting(l_mnfg_screen_test));

        // Send downstream PRBS pattern from host
        if (l_is_apollo == fapi2::ENUM_ATTR_MSS_IS_APOLLO_FALSE)
        {
            FAPI_TRY(p10_io_omi_prbs(mss::find_target<fapi2::TARGET_TYPE_OMI>(i_target), true));
        }

        // FFE Setup
        FAPI_TRY(mss::attr::get_omi_ffe_settings_command(i_target, l_enable_ffe_settings));

        if (l_enable_ffe_settings == fapi2::ENUM_ATTR_OMI_FFE_SETTINGS_COMMAND_ENABLE)
        {
            FAPI_TRY(mss::exp::omi::ffe_setup(i_target, l_ffe_setup_data));
            FAPI_TRY(mss::exp::i2c::send_ffe_settings(i_target, l_ffe_setup_data));
            FAPI_TRY(mss::exp::i2c::poll_fw_status(i_target, mss::DELAY_1MS, 100, l_fw_status_data));
            FAPI_TRY(mss::exp::i2c::check::command_result(i_target, mss::exp::i2c::FW_TWI_FFE_SETTINGS, l_ffe_setup_data,
                     l_fw_status_data));
        }

        // Apply override for CDR bandwidth
        FAPI_TRY(mss::attr::get_exp_omi_cdr_bw_override(i_target, l_cdr_bw_override));
        FAPI_TRY(mss::exp::workarounds::omi::override_cdr_bw_i2c(i_target, l_cdr_bw_override));

        // Gets the data setup
        FAPI_TRY(mss::exp::omi::train::setup_fw_boot_config(i_target, l_boot_config_data));

        // Set up dl_layer_boot_mode according to FW and HW support
        // Need to run original sequence (0b00) on Apollo and on legacy FW
        FAPI_TRY(mss::exp::workarounds::omi::select_dl_layer_boot_mode(i_target, l_is_apollo, l_boot_config_data));

        // Issues the command and checks for completion
        // Note: This does not kick off OMI training
        FAPI_TRY(mss::exp::i2c::boot_config(i_target, l_boot_config_data));

        // Check FW status for success
        FAPI_TRY(mss::exp::i2c::poll_fw_status(i_target, 2 * mss::DELAY_1MS, 100000, l_fw_status_data));
        l_rc_bootconfig0 = mss::exp::i2c::check::boot_config(i_target, l_boot_config_data, l_fw_status_data);
        l_rc_bootconfig0_copy = l_rc_bootconfig0;

        // Unmask FIRs before checking the BOOT_CONFIG0 RC in case we need to blame FIRs
        l_rc_unmask = mss::unmask::after_mc_omi_setup<mss::mc_type::EXPLORER>(i_target);

        // The error paths below are complicated due to the fact that certain BOOT_CONFIG0 fails will
        // cause us not to be able to access FIRs. This is the plan:
        // 1. Assume we can unmask FIRs, and attempt to do so
        //    a. if we get a scom fail and BOOT_CONFIG failed, commit the scom fail as recovered and return the BOOT_CONFIG fail
        //    b. if we get a scom fail and BOOT_CONFIG passed, return the scom fail
        // 2. If BOOT_CONFIG0 failed, check the FIRs to see if any are unmasked and lit
        //    a. if we get a scom fail and BOOT_CONFIG failed, commit the scom fail as recovered and return the BOOT_CONFIG fail
        //    b. if we see FIRs lit, commit the FIR RC (fir_or_pll_fail does this), return the BOOT_CONFIG fail in Cronus, but SUCCESS in hostboot
        //    c. if we don't see any FIRs lit, return the BOOT_CONFIG fail
        {
            // Check for unmask scom fail
            if(l_rc_unmask != fapi2::FAPI2_RC_SUCCESS)
            {
                // 1a: Commit scom and return BOOT_CONFIG fail
                if(l_rc_bootconfig0 != fapi2::FAPI2_RC_SUCCESS)
                {
                    fapi2::log_related_error(i_target, l_rc_unmask, fapi2::FAPI2_ERRL_SEV_RECOVERED);
                    FAPI_TRY(l_rc_bootconfig0, "%s BOOT_CONFIG_0 either failed or timed out", mss::c_str(i_target));
                }
                // 1b: Return the scom fail
                else
                {
                    FAPI_TRY(l_rc_unmask, "%s Unmask after exp_omi_setup failed", mss::c_str(i_target));
                }
            }

            // Check FIRs if BOOT_CONFIG_0 failed or timed out
            // Use a copy of l_rc_bootconfig0 so we don't overwrite it with SUCCESS if we find a FIR lit
            l_rc_firchk = mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER, mss::check::firChecklist::OMI>(i_target,
                          l_rc_bootconfig0_copy);

            // Check for scom fail and return correct log
            // l_rc_firchk will either be a duplicate of l_rc_bootconfig0_copy or a scom fail RC
            if(l_rc_firchk != l_rc_bootconfig0_copy)
            {
                // 2a: Commit scom fail and return l_rc_bootconfig0_copy
                fapi2::log_related_error(i_target, l_rc_firchk, fapi2::FAPI2_ERRL_SEV_RECOVERED);
                return l_rc_bootconfig0_copy;
            }

            // 2b/c: Finally, return l_rc_firchk (SUCCESS if we found FIRs set, failing RC otherwise) if BOOT_CONFIG0 failed
            if (l_rc_bootconfig0 != fapi2::FAPI2_RC_SUCCESS)
            {
                FAPI_ERR("%s BOOT_CONFIG_0 either failed or timed out", mss::c_str(i_target));
                return l_rc_firchk;
            }
        }

        // Save our new communication state
        FAPI_TRY(mss::attr::set_exp_comm_state(i_target, fapi2::ENUM_ATTR_MSS_EXP_COMM_STATE_I2C_WITH_SCOM));

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
            mss::exp::omi::setup_edpl_time_window(l_dlx_config1_data, !l_edpl_disable, l_mnfg_screen_test);
            FAPI_TRY(mss::exp::omi::write_dlx_config1(i_target, l_dlx_config1_data));
            FAPI_INF("%s EDPL enable: %s", mss::c_str(i_target), l_edpl_disable ? "false" : "true");
        }

        // TODO Zen-1002: See if we can remove this
        // Update explorer CDR BW value to 0x2F based on Chris Steffen's testing
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, l_proc, l_omi_freq) );
        FAPI_TRY(mss::exp::workarounds::omi::cdr_bw_override(i_target, l_omi_freq));

        // Apply override for CDR offset
        FAPI_TRY(mss::attr::get_exp_omi_cdr_offset(i_target, l_cdr_offset));
        FAPI_TRY(mss::attr::get_exp_omi_cdr_offset_lane_mask(i_target, l_cdr_offset_lane_mask));
        FAPI_TRY(mss::exp::workarounds::omi::override_cdr_offset(i_target, l_cdr_offset, l_cdr_offset_lane_mask));

        // Start P10 PHY training by sending upstream PRBS pattern
        // Train mode 6 (state 3)
        FAPI_TRY(mss::exp::workarounds::omi::pre_training_prbs(i_target));

    fapi_try_exit:
        return fapi2::current_err;
    }
}
