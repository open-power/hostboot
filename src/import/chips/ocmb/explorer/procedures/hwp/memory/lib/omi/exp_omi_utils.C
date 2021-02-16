/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/omi/exp_omi_utils.C $ */
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
/// @file exp_omi_utils.C
/// @brief OMI utility functions
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <generic/memory/lib/utils/find.H>
#include <lib/omi/exp_omi_utils.H>
#include <lib/shared/exp_consts.H>
#include <lib/i2c/exp_i2c_fields.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <lib/shared/exp_consts.H>
#include <lib/i2c/exp_i2c.H>
#include <i2c_access.H>

// P9 cross-includes
#include <p9_io_scom.H>
#include <p9_io_regs.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>

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
/// @note Algorithm from p9a_omi_train.C
///
fapi2::ReturnCode setup_omi_dl0_config0(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint8_t i_train_mode,
    const uint8_t i_dl_x4_backoff_en)
{
    fapi2::buffer<uint64_t> l_config0;

    // Get the "reset" values so we can just overwrite with the changes
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_DLX_DL0_CONFIG0, l_config0),
             "Error reading EXPLR_DLX_DL0_CONFIG0 on %s", mss::c_str(i_target));

    // CFG_DL0_HALF_WIDTH_BACKOFF_ENABLE: dl0 x4 backoff enabled
    l_config0.writeBit<EXPLR_DLX_DL0_CONFIG0_CFG_HALF_WIDTH_BACKOFF_ENABLE>(i_dl_x4_backoff_en);

    // CFG_DL0_CFG_TL_CREDITS: dl0 TL credits - Maximum number of credits that can be sent to the TL
    l_config0.insertFromRight<EXPLR_DLX_DL0_CONFIG0_CFG_CFG_TL_CREDITS, EXPLR_DLX_DL0_CONFIG0_CFG_CFG_TL_CREDITS_LEN>
    (OPTIMAL_NUM_TL_CREDITS);


    // CFG_DL0_TRAIN_MODE: dl0 train mode
    l_config0.insertFromRight<EXPLR_DLX_DL0_CONFIG0_CFG_TRAIN_MODE,
                              EXPLR_DLX_DL0_CONFIG0_CFG_TRAIN_MODE_LEN>(i_train_mode);

    l_config0.writeBit<EXPLR_DLX_DL0_CONFIG0_CFG_PWRMGT_ENABLE>(0);

    FAPI_DBG("Writing 0x%16llx to EXPLR_DLX_DL0_CONFIG0 (0x%16llx) of %s",
             l_config0, EXPLR_DLX_DL0_CONFIG0, mss::c_str(i_target));

    // All other bits will be left at their default values
    FAPI_TRY( fapi2::putScom(i_target, EXPLR_DLX_DL0_CONFIG0, l_config0),
              "Error writing EXPLR_DLX_DL0_CONFIG0 on %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set up the OMI object handles for intrp_req commands
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode setup_obj_handles(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ATTR_MSS_OCMB_CHECKSTOP_OBJ_HANDLE_Type l_checkstop_obj_handle = 0;
    fapi2::ATTR_MSS_OCMB_RECOV_OBJ_HANDLE_Type l_recov_obj_handle = 0;
    fapi2::ATTR_MSS_OCMB_SPECATTN_OBJ_HANDLE_Type l_specattn_obj_handle = 0;
    fapi2::ATTR_MSS_OCMB_APPINTR_OBJ_HANDLE_Type l_appintr_obj_handle = 0;

    FAPI_TRY(mss::attr::get_ocmb_checkstop_obj_handle(l_checkstop_obj_handle));
    FAPI_TRY(mss::attr::get_ocmb_recov_obj_handle(l_recov_obj_handle));
    FAPI_TRY(mss::attr::get_ocmb_specattn_obj_handle(l_specattn_obj_handle));
    FAPI_TRY(mss::attr::get_ocmb_appintr_obj_handle(l_appintr_obj_handle));

    FAPI_DBG("%s Setting up OMI object handles in EXPLR_TLXT_TLXTINTHLD", mss::c_str(i_target));

    FAPI_TRY( fapi2::putScom(i_target, EXPLR_TLXT_TLXTINTHLD0, l_checkstop_obj_handle),
              "Error writing EXPLR_TLXT_TLXTINTHLD0 on %s", mss::c_str(i_target) );
    FAPI_TRY( fapi2::putScom(i_target, EXPLR_TLXT_TLXTINTHLD1, l_recov_obj_handle),
              "Error writing EXPLR_TLXT_TLXTINTHLD1 on %s", mss::c_str(i_target) );
    FAPI_TRY( fapi2::putScom(i_target, EXPLR_TLXT_TLXTINTHLD2, l_specattn_obj_handle),
              "Error writing EXPLR_TLXT_TLXTINTHLD2 on %s", mss::c_str(i_target) );
    FAPI_TRY( fapi2::putScom(i_target, EXPLR_TLXT_TLXTINTHLD3, l_appintr_obj_handle),
              "Error writing EXPLR_TLXT_TLXTINTHLD3 on %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set up the OMI interrupt command flags
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode setup_int_cmd_flags(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    constexpr uint8_t CHECKSTOP_COMMAND_FLAG = 0;
    constexpr uint8_t RECOV_COMMAND_FLAG = 1;
    constexpr uint8_t SPECATTN_COMMAND_FLAG = 2;
    constexpr uint8_t APPINTR_COMMAND_FLAG = 3;

    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("%s Setting up OMI interrupt command flags in EXPLR_TLXT_TLXCFG1", mss::c_str(i_target));

    FAPI_TRY( fapi2::getScom(i_target, EXPLR_TLXT_TLXCFG1, l_data),
              "Error reading EXPLR_TLXT_TLXCFG1 on %s", mss::c_str(i_target));
    l_data.insertFromRight<EXPLR_TLXT_TLXCFG1_TLXT_INTRP_CMDFLAG_0,
                           EXPLR_TLXT_TLXCFG1_TLXT_INTRP_CMDFLAG_0_LEN>(CHECKSTOP_COMMAND_FLAG);
    l_data.insertFromRight<EXPLR_TLXT_TLXCFG1_TLXT_INTRP_CMDFLAG_1,
                           EXPLR_TLXT_TLXCFG1_TLXT_INTRP_CMDFLAG_1_LEN>(RECOV_COMMAND_FLAG);
    l_data.insertFromRight<EXPLR_TLXT_TLXCFG1_TLXT_INTRP_CMDFLAG_2,
                           EXPLR_TLXT_TLXCFG1_TLXT_INTRP_CMDFLAG_2_LEN>(SPECATTN_COMMAND_FLAG);
    l_data.insertFromRight<EXPLR_TLXT_TLXCFG1_TLXT_INTRP_CMDFLAG_3,
                           EXPLR_TLXT_TLXCFG1_TLXT_INTRP_CMDFLAG_3_LEN>(APPINTR_COMMAND_FLAG);
    FAPI_TRY( fapi2::putScom(i_target, EXPLR_TLXT_TLXCFG1, l_data),
              "Error writing EXPLR_TLXT_TLXCFG1 on %s", mss::c_str(i_target));

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
/// @brief Helper function to perform BUMP_SL workaround
///
/// @param[in] i_omi OMI target
/// @param[in] i_lane OMI lane
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode bump_sl_workaround(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi, uint8_t i_lane)
{
    FAPI_INF("Performing BUMP_SL workaround on %s", mss::c_str(i_omi));

    const auto& l_omic = mss::find_target<fapi2::TARGET_TYPE_OMIC>(i_omi);

    fapi2::buffer<uint64_t> l_omi_status;
    uint8_t l_state_machine_state_omi = 0;
    constexpr uint8_t MAX_LANE = 7;

    // Check valid lane input
    FAPI_ASSERT((i_lane <= MAX_LANE),
                fapi2::EXP_OMI_BUMP_SL_WORKAROUND_ERROR()
                .set_MAX_LANE(MAX_LANE)
                .set_LANE_INPUT(i_lane),
                "Invalid lane input of %d", i_lane);

    // Check OMI training status
    FAPI_TRY(mss::getScom(i_omi, P9A_MC_REG2_DL0_STATUS, l_omi_status));
    l_omi_status.extractToRight<P9A_MC_REG2_DL0_STATUS_STS_TRAINING_STATE_MACHINE,
                                P9A_MC_REG2_DL0_STATUS_STS_TRAINING_STATE_MACHINE_LEN>(l_state_machine_state_omi);

    if (l_state_machine_state_omi == mss::omi::train_mode::TX_TRAINING_STATE1)
    {
        // Perform the real workaround
        uint8_t l_group_pos = 0;
        uint32_t l_lane = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_DL_GROUP_POS, i_omi, l_group_pos));

        l_lane = (l_group_pos * mss::conversions::BITS_PER_BYTE) + i_lane; // tk 8 = bits_per_byte
        FAPI_INF("Bumping PHY by one UI for lane %d", i_lane);
        // Set
        FAPI_TRY(io::rmw(OPT_RX_PR_BUMP_SL_1UI, // reg, fld, len
                         l_omic, // target
                         0,      // group
                         l_lane, // lane
                         1));    // data

        // Reset
        FAPI_TRY(io::rmw(OPT_RX_PR_BUMP_SL_1UI, // reg, fld, len
                         l_omic, // target
                         0,      // group
                         l_lane, // lane
                         0));    // data
    }

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
    FAPI_TRY(mss::exp::i2c::poll_fw_status(i_target, mss::common_timings::DELAY_1MS, 100, l_rsp_data));

    // Check that Explorer is not still in FW_BUSY state
    FAPI_TRY(mss::exp::i2c::capture_status(i_target, l_rsp_data, l_fw_status_data));
    FAPI_TRY(mss::exp::i2c::status::get_status_code(i_target, l_rsp_data, l_status));

    // Grabbing and logging host registers.
    // Note: we cannot log the explorer regs due to the explorer's status
    if (l_is_apollo == fapi2::ENUM_ATTR_MSS_IS_APOLLO_FALSE)
    {
        FAPI_TRY(fapi2::getScom(l_omi, P9A_MC_REG2_DL0_TRAINING_STATUS, l_host_training_status));
        FAPI_TRY(fapi2::getScom(l_omi, P9A_MC_REG2_DL0_ERROR_HOLD, l_host_error_hold));
        FAPI_TRY(fapi2::getScom(l_omi, P9A_MC_REG2_DL0_EDPL_MAX_COUNT, l_host_edpl_max_count));
        FAPI_TRY(fapi2::getScom(l_omi, P9A_MC_REG2_DL0_STATUS, l_host_status));
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
