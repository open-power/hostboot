/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/omi/exp_omi_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/// @file exp_omi_utils.C
/// @brief OMI utility functions
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <generic/memory/lib/utils/find.H>
#include <lib/omi/exp_omi_utils.H>
#include <lib/shared/exp_consts.H>
#include <lib/i2c/exp_i2c_fields.H>
#include <mss_generic_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/mss_log_utils.H>
#include <lib/shared/exp_consts.H>
#include <p10_scom_omi_a.H>
#include <lib/i2c/exp_i2c.H>
#include <i2c_access.H>
#include <p10_scom_omi.H>
#include <mss_p10_attribute_getters.H>

namespace mss
{
namespace exp
{
namespace omi
{

///
/// @brief Set the OMI_DL0 configuration register for a given mode
///
/// @param[in] i_target OCMB target
/// @param[in] i_train_mode mode to use
/// @param[in] i_dl_x4_backoff_en backoff enable bit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note Algorithm from p10_omi_train.C
///
fapi2::ReturnCode setup_omi_dl0_config0(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint8_t i_train_mode,
    const uint8_t i_dl_x4_backoff_en)
{
    fapi2::buffer<uint64_t> l_config0;
    constexpr uint8_t X8_TRAINING_MODE_ONLY = 0x02;

    // Get the "reset" values so we can just overwrite with the changes
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_DLX_DL0_CONFIG0, l_config0),
             "Error reading EXPLR_DLX_DL0_CONFIG0 on %s", mss::c_str(i_target));

    // CFG_DL0_HALF_WIDTH_BACKOFF_ENABLE: dl0 x4 backoff enabled
    l_config0.writeBit<EXPLR_DLX_DL0_CONFIG0_CFG_HALF_WIDTH_BACKOFF_ENABLE>(i_dl_x4_backoff_en);

    // CFG_DL0_SUPPORTED_MODES: dl0 training configured for x8 link width
    l_config0.insertFromRight<EXPLR_DLX_DL0_CONFIG0_CFG_SUPPORTED_MODES,
                              EXPLR_DLX_DL0_CONFIG0_CFG_SUPPORTED_MODES_LEN>(X8_TRAINING_MODE_ONLY);

    // CFG_DL0_CFG_TL_CREDITS: dl0 TL credits - Maximum number of credits that can be sent to the TL
    l_config0.insertFromRight<EXPLR_DLX_DL0_CONFIG0_CFG_CFG_TL_CREDITS, EXPLR_DLX_DL0_CONFIG0_CFG_CFG_TL_CREDITS_LEN>
    (OPTIMAL_NUM_TL_CREDITS);

    // CFG_DL0_TRAIN_MODE: dl0 train mode
    l_config0.insertFromRight<EXPLR_DLX_DL0_CONFIG0_CFG_TRAIN_MODE,
                              EXPLR_DLX_DL0_CONFIG0_CFG_TRAIN_MODE_LEN>(i_train_mode);

    l_config0.writeBit<EXPLR_DLX_DL0_CONFIG0_CFG_PWRMGT_ENABLE>(0);

    FAPI_DBG("Writing 0x%016llx to EXPLR_DLX_DL0_CONFIG0 (0x%016llx) of %s",
             l_config0, EXPLR_DLX_DL0_CONFIG0, mss::c_str(i_target));

    // All other bits will be left at their default values
    FAPI_TRY( fapi2::putScom(i_target, EXPLR_DLX_DL0_CONFIG0, l_config0),
              "Error writing EXPLR_DLX_DL0_CONFIG0 on %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets up the FFE_SETTINGS command
/// @param[in] i_target target on which the code is operating
/// @param[out] o_data data for the FFE_SETTINGS command
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode ffe_setup( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                             std::vector<uint8_t>& o_data )
{
    constexpr uint32_t MAX_CURSOR_SUM = 63;

    uint32_t l_pre_cursor = 0;
    uint32_t l_post_cursor = 0;

    FAPI_TRY(mss::attr::get_omi_ffe_pre_cursor(i_target, l_pre_cursor));
    FAPI_TRY(mss::attr::get_omi_ffe_post_cursor(i_target, l_post_cursor));

    FAPI_ASSERT((l_pre_cursor + l_post_cursor) < MAX_CURSOR_SUM,
                fapi2::MSS_FFE_CURSOR_OVERFLOW().
                set_TARGET(i_target).
                set_PRE_CURSOR(l_pre_cursor).
                set_POST_CURSOR(l_post_cursor),
                "%s Sum of FFE pre-cursor %d and post-cursor %d needs to be less than 64",
                mss::c_str(i_target), l_pre_cursor, l_post_cursor);

    // Clears o_data, just in case
    o_data.clear();
    o_data.assign(mss::exp::i2c::FW_TWI_FFE_SETTINGS_BYTE_LEN, 0);

    FAPI_TRY(mss::exp::i2c::ffe_settings::set_pre_cursor( i_target, o_data, l_pre_cursor ));
    FAPI_TRY(mss::exp::i2c::ffe_settings::set_post_cursor( i_target, o_data, l_post_cursor ));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check the OMI EDPL counters for MFG screen test
/// @param[in] i_target OCMB_CHIP target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_omi_mfg_screen_edpl_counts(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_pmu_data;
    uint64_t l_edpl_count = 0;
    uint64_t l_total_edpl_count = 0;
    fapi2::ATTR_MFG_SCREEN_OMI_EDPL_ALLOWED_Type l_edpl_allowed = 0;

    FAPI_TRY(mss::attr::get_mfg_screen_omi_edpl_allowed(l_edpl_allowed));

    // Check downstream EDPL count (upstream is checked in P10 library)
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_DLX_DL0_EDPL_MAX_COUNT, l_pmu_data));

    l_pmu_data.extractToRight<EXPLR_DLX_DL0_EDPL_MAX_COUNT_L0, EXPLR_DLX_DL0_EDPL_MAX_COUNT_L0_LEN>(l_edpl_count);
    FAPI_INF("%s Downstream EDPL count from EDPL_MAX_COUNT_L0: %d", mss::c_str(i_target), l_edpl_count);
    l_total_edpl_count += l_edpl_count;

    l_pmu_data.extractToRight<EXPLR_DLX_DL0_EDPL_MAX_COUNT_L1, EXPLR_DLX_DL0_EDPL_MAX_COUNT_L1_LEN>(l_edpl_count);
    FAPI_INF("%s Downstream EDPL count from EDPL_MAX_COUNT_L1: %d", mss::c_str(i_target), l_edpl_count);
    l_total_edpl_count += l_edpl_count;

    l_pmu_data.extractToRight<EXPLR_DLX_DL0_EDPL_MAX_COUNT_L2, EXPLR_DLX_DL0_EDPL_MAX_COUNT_L2_LEN>(l_edpl_count);
    FAPI_INF("%s Downstream EDPL count from EDPL_MAX_COUNT_L2: %d", mss::c_str(i_target), l_edpl_count);
    l_total_edpl_count += l_edpl_count;

    l_pmu_data.extractToRight<EXPLR_DLX_DL0_EDPL_MAX_COUNT_L3, EXPLR_DLX_DL0_EDPL_MAX_COUNT_L3_LEN>(l_edpl_count);
    FAPI_INF("%s Downstream EDPL count from EDPL_MAX_COUNT_L3: %d", mss::c_str(i_target), l_edpl_count);
    l_total_edpl_count += l_edpl_count;

    l_pmu_data.extractToRight<EXPLR_DLX_DL0_EDPL_MAX_COUNT_L4, EXPLR_DLX_DL0_EDPL_MAX_COUNT_L4_LEN>(l_edpl_count);
    FAPI_INF("%s Downstream EDPL count from EDPL_MAX_COUNT_L4: %d", mss::c_str(i_target), l_edpl_count);
    l_total_edpl_count += l_edpl_count;

    l_pmu_data.extractToRight<EXPLR_DLX_DL0_EDPL_MAX_COUNT_L5, EXPLR_DLX_DL0_EDPL_MAX_COUNT_L5_LEN>(l_edpl_count);
    FAPI_INF("%s Downstream EDPL count from EDPL_MAX_COUNT_L5: %d", mss::c_str(i_target), l_edpl_count);
    l_total_edpl_count += l_edpl_count;

    l_pmu_data.extractToRight<EXPLR_DLX_DL0_EDPL_MAX_COUNT_L6, EXPLR_DLX_DL0_EDPL_MAX_COUNT_L6_LEN>(l_edpl_count);
    FAPI_INF("%s Downstream EDPL count from EDPL_MAX_COUNT_L6: %d", mss::c_str(i_target), l_edpl_count);
    l_total_edpl_count += l_edpl_count;

    l_pmu_data.extractToRight<EXPLR_DLX_DL0_EDPL_MAX_COUNT_L7, EXPLR_DLX_DL0_EDPL_MAX_COUNT_L7_LEN>(l_edpl_count);
    FAPI_INF("%s Downstream EDPL count from EDPL_MAX_COUNT_L7: %d", mss::c_str(i_target), l_edpl_count);
    l_total_edpl_count += l_edpl_count;

    FAPI_ASSERT_NOEXIT((l_total_edpl_count <= l_edpl_allowed),
                       fapi2::P10_MFG_OMI_SCREEN_DOWNSTREAM_EDPL()
                       .set_OCMB_TARGET(i_target)
                       .set_THRESHHOLD(l_edpl_allowed)
                       .set_EDPL_COUNT(l_total_edpl_count),
                       "%s MFG OMI screen downstream EDPL count (%d) exceeded threshhold (%d)",
                       mss::c_str(i_target),
                       l_total_edpl_count,
                       l_edpl_allowed );

    // Capture and log the error if the above assert failed
    mss::log_and_capture_error(fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE, l_rc);

    // l_rc holds any error from the ASSERT_NOEXIT above
    // it will get thrown out by the caller, but is used in the unit tests
    return l_rc;

fapi_try_exit:
    return fapi2::current_err;
}

namespace train
{

///
/// @brief Get the FW_BOOT_CONFIG from attributes
/// @param[in] i_target target on which the code is operating
/// @param[out] o_data data for the FW_BOOT_CONFIG
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode setup_fw_boot_config( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        std::vector<uint8_t>& o_data )
{
    // Variables
    uint8_t l_fw_mode = 0;
    uint8_t l_loopback_test = 0;
    uint8_t l_transport_layer = 0;
    uint8_t l_dl_layer_boot_mode = 0;
    uint8_t l_dfe_disable = 0;
    uint8_t l_lane_mode = 0;
    uint8_t l_adaptation_mode = 0;
    uint32_t l_omi_freq = 0;

    const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);

    // Read the EXP_FW_BOOT_CONFIG from the attributes
    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_adaptation_mode(i_target, l_adaptation_mode));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_fw_mode(i_target, l_fw_mode));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_opencapi_loopback_test(i_target, l_loopback_test));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_transport_layer(i_target, l_transport_layer));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_dl_layer_boot_mode(i_target, l_dl_layer_boot_mode));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_dfe_disable(i_target, l_dfe_disable));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_lane_mode(i_target, l_lane_mode));

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, l_proc, l_omi_freq) );


    // Clears o_data, just in case
    o_data.clear();
    o_data.assign(mss::exp::i2c::FW_BOOT_CONFIG_BYTE_LEN, 0);

    FAPI_TRY(mss::exp::i2c::boot_cfg::set_serdes_freq( i_target, o_data, l_omi_freq ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_lane_mode( i_target, o_data, l_lane_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_dfe_disable( i_target, o_data, l_dfe_disable ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_dl_layer_boot_mode( i_target, o_data, l_dl_layer_boot_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_transport_layer( i_target, o_data, l_transport_layer ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_loopback_test( i_target, o_data, l_loopback_test ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_fw_mode( i_target, o_data, l_fw_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_adaptation_mode( i_target, o_data, l_adaptation_mode ));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check the OMI train status on the OCMB chip
///
/// @param[in] i_target OCMB chip
/// @param[out] o_state_machine_state training state mahcine
/// @param[out] o_omi_training_status training status
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode omi_train_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   uint8_t& o_state_machine_state,
                                   fapi2::buffer<uint64_t>& o_omi_training_status)
{
    fapi2::buffer<uint64_t> l_omi_status;

    // Check OMI training status
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_DLX_DL0_STATUS, l_omi_status));

    o_omi_training_status = l_omi_status;
    o_state_machine_state = 0;
    l_omi_status.extractToRight<EXPLR_DLX_DL0_STATUS_STS_TRAINING_STATE_MACHINE,
                                EXPLR_DLX_DL0_STATUS_STS_TRAINING_STATE_MACHINE_LEN>(o_state_machine_state);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Poll for OMI training completion
///
/// @param[in] i_target OCMB target
/// @param[out] o_state_machine_state state machine state
/// @param[out] o_omi_status omi status register buffer
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode poll_for_training_completion(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint8_t& o_state_machine_state,
    fapi2::buffer<uint64_t>& o_omi_status)
{
    constexpr uint8_t MAX_LOOP_COUNT = 10;  // Retry times
    uint8_t l_tries = 0;

    do
    {
        // Delay
        fapi2::delay(500 * mss::DELAY_1MS, 10 * mss::DELAY_1MS);

        // Check OMI training status
        FAPI_TRY(mss::exp::omi::train::omi_train_status(i_target, o_state_machine_state, o_omi_status));
        l_tries++;

    }
    while (l_tries < MAX_LOOP_COUNT && o_state_machine_state != STATE_MACHINE_SUCCESS);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Abort Explorer FW polling for OMI training completion
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode poll_abort(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_INF("%s OMI training did not complete by end of polling loop. Sending TWI_POLL_ABORT command",
             mss::c_str(i_target));

    const auto& l_omi = mss::find_target<fapi2::TARGET_TYPE_OMI>(i_target);
    std::vector<uint8_t> l_cmd_data;
    std::vector<uint8_t> l_rsp_data;
    uint8_t l_status = 0;
    uint64_t l_fw_status_data = 0;
    fapi2::buffer<uint64_t> l_host_training_status;
    fapi2::buffer<uint64_t> l_host_error_hold;
    fapi2::buffer<uint64_t> l_host_edpl_max_count;
    fapi2::buffer<uint64_t> l_host_status;
    uint8_t l_is_apollo = 0;

    FAPI_TRY(mss::attr::get_is_apollo(l_is_apollo));

    // Send TWI_POLL_ABORT
    l_cmd_data.push_back(mss::exp::i2c::FW_TWI_POLL_ABORT);

    FAPI_TRY(fapi2::putI2c(i_target, l_cmd_data),
             "%s i2c failure sending POLL_ABORT command",
             mss::c_str(i_target));

    // Now poll again until BUSY state goes away
    // note the assertion parameters mean assert if we remain in the BUSY state after polling
    // and don't assert if we get a non-success status (which is ok since we're purposely aborting the command)
    FAPI_TRY(mss::exp::i2c::poll_fw_status(i_target, mss::common_timings::DELAY_1MS, 20, l_rsp_data));

    // Check that Explorer is not still in FW_BUSY state
    FAPI_TRY(mss::exp::i2c::capture_status(i_target, l_rsp_data, l_fw_status_data));
    FAPI_TRY(mss::exp::i2c::status::get_status_code(i_target, l_rsp_data, l_status));

    // Grabbing and logging host registers.
    // Note: we cannot log the explorer regs due to the explorer's status
    if (l_is_apollo == fapi2::ENUM_ATTR_MSS_IS_APOLLO_FALSE)
    {
        FAPI_TRY(fapi2::getScom(l_omi, scomt::omi::TRAINING_STATUS, l_host_training_status));
        FAPI_TRY(fapi2::getScom(l_omi, scomt::omi::ERROR_HOLD, l_host_error_hold));
        FAPI_TRY(fapi2::getScom(l_omi, scomt::omi::EDPL_MAX_COUNT, l_host_edpl_max_count));
        FAPI_TRY(fapi2::getScom(l_omi, scomt::omi::STATUS, l_host_status));
    }

    FAPI_ASSERT( (l_status != mss::exp::i2c::status_codes::FW_BUSY),
                 fapi2::MSS_EXP_POLL_ABORT_FW_STATUS_BUSY().
                 set_OCMB_TARGET(i_target).
                 set_CMD_ID(mss::exp::i2c::FW_TWI_POLL_ABORT).
                 set_COMMAND(l_cmd_data).
                 set_STATUS_DATA(l_fw_status_data).
                 set_HOST_DL0_TRAINING_STATUS(l_host_training_status).
                 set_HOST_DL0_ERROR_HOLD(l_host_error_hold).
                 set_HOST_DL0_EDPL_MAX_COUNT(l_host_edpl_max_count).
                 set_HOST_DL0_STATUS(l_host_status),
                 "Polling timeout on FW_STATUS command (still FW_BUSY) after POLL_ABORT for %s"
                 "HOST_DL0_TRAINING_STATUS:0x%016lx HOST_DL0_ERROR_HOLD:0x%016lx "
                 "HOST_DL0_EDPL_MAX_COUNT:0x%016lx HOST_DL0_STATUS:0x%016lx",
                 mss::c_str(i_target),
                 l_host_training_status,
                 l_host_error_hold,
                 l_host_edpl_max_count,
                 l_host_status );

fapi_try_exit:
    return fapi2::current_err;
}

} // ns train

} // ns omi

} // ns exp

} // ns mss
