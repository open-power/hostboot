/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_omi_train_check.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

/// @file exp_omi_train_check.C
/// @brief Check that omi training was successful from explorer side
///
/// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include <fapi2.H>
#include <exp_omi_train_check.H>
#include <lib/omi/exp_omi_utils.H>
#include <generic/memory/mss_git_data_helper.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/i2c/exp_i2c.H>
#include <lib/omi/exp_omi_utils.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/mss_generic_check.H>

///
/// @brief Check that the OCMB's omi state machine is in its expected state after OMI training
/// @param[in] i_target the OCMB target to check
/// @return FAPI2_RC_SUCCESS iff ok
/// @note the functionality of this procedure was made to match that of p10_omi_train_check
///
fapi2::ReturnCode exp_omi_train_check(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    mss::display_git_commit_info("exp_omi_train_check");

    FAPI_INF("%s Start exp_omi_train_check", mss::c_str(i_target));

    const auto& l_omi = mss::find_target<fapi2::TARGET_TYPE_OMI>(i_target);
    const auto& l_omic = mss::find_target<fapi2::TARGET_TYPE_OMIC>(l_omi);
    const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);

    // Declares variables
    fapi2::ReturnCode l_poll_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_omi_status;
    fapi2::buffer<uint64_t> l_omi_training_status;
    fapi2::buffer<uint64_t> l_dl0_error_hold;
    fapi2::buffer<uint64_t> l_expected_dl0_error_hold;
    fapi2::buffer<uint64_t> l_dl0_config1;
    uint8_t l_state_machine_state = 0;
    uint32_t l_omi_freq = 0;
    uint8_t l_lane = 0;
    constexpr uint8_t NUM_LANES = 8;
    bool l_fw_status_busy = true;
    std::vector<uint8_t> l_fw_status_data;

    uint8_t l_sim = 0;
    uint8_t l_simics = 0;
    FAPI_TRY(mss::attr::get_is_simulation(l_sim));
    FAPI_TRY(mss::attr::get_is_simics(l_simics));

    // Skip this in sim, check via I2C is not supported
    if (l_sim)
    {
        FAPI_INF("Sim, exiting exp_omi_train_check %s", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Simics does not support fw_status here, will return BUSY as done in exp_omi_setup
    if (l_simics == fapi2::ENUM_ATTR_IS_SIMICS_REALHW)
    {
        // First poll FW_STATUS to ensure we can do scoms to Explorer
        // There is a window during OMI training where Explorer FW will not respond to anything
        // except FW_STATUS and TWI_POLL_ABORT commands (which precludes i2c scom reads)
        // note the assert param is to suppress assert/callout if polling ends with BUSY state
        // note the polling count was updated from 100 to 10,000 to give time for training to
        // complete. This value may need to be optimized once the training procedure is finalized
        FAPI_TRY( mss::exp::i2c::fw_status(i_target, mss::common_timings::DELAY_1MS, 10000,
                                           mss::exp::i2c::NO_ASSERT_IF_BUSY_FW_STATUS) );

        FAPI_TRY( mss::exp::i2c::get_fw_status(i_target, l_fw_status_data) );
        FAPI_TRY( mss::exp::i2c::check::status_code(i_target, mss::exp::i2c::FW_STATUS, l_fw_status_data, l_fw_status_busy) );

        // If we're still in the BUSY state, abort Explorer FW polling loop
        if (l_fw_status_busy)
        {
            FAPI_TRY( mss::exp::omi::train::poll_abort(i_target) );
        }
    }

    // Read DL0_STATUS
    FAPI_TRY(mss::exp::omi::train::omi_train_status(i_target, l_state_machine_state, l_omi_status));

    while ((l_state_machine_state == mss::omi::train_mode::TX_TRAINING_STATE2
            || l_state_machine_state == mss::omi::train_mode::TX_TRAINING_STATE1) && l_lane < NUM_LANES)
    {
        // Now poll once more
        FAPI_TRY(mss::exp::omi::train::poll_for_training_completion(i_target, l_state_machine_state, l_omi_status));
        l_lane++;
    }

    // Note: this is very useful debug information while trying to debug training during polling
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_DLX_DL0_TRAINING_STATUS, l_omi_training_status));
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_DLX_DL0_CONFIG1, l_dl0_config1));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, l_proc, l_omi_freq));

    // Check for errors in ERROR_HOLD until we get a proper FIR API setup
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_DLX_DL0_ERROR_HOLD, l_dl0_error_hold));

    FAPI_ASSERT(l_state_machine_state == STATE_MACHINE_SUCCESS,
                fapi2::EXP_OMI_TRAIN_ERR()
                .set_OCMB_TARGET(i_target)
                .set_OMI_TARGET(l_omi)
                .set_OMIC_TARGET(l_omic)
                .set_EXPECTED_SM_STATE(STATE_MACHINE_SUCCESS)
                .set_ACTUAL_SM_STATE(l_state_machine_state)
                .set_DL0_STATUS(l_omi_status)
                .set_DL0_TRAINING_STATUS(l_omi_training_status)
                .set_DL0_CONFIG1(l_dl0_config1)
                .set_DL0_ERROR_HOLD(l_dl0_error_hold)
                .set_OMI_FREQ(l_omi_freq)
                .set_EXP_ACTIVE_LOG_SIZE(4096),
                "%s EXP OMI Training Failure, expected state:%d/actual state:%d, "
                "DL0_STATUS:0x%016llx, DL0_TRAINING_STATUS:0x%016llx, DL0_ERROR_HOLD:0x%016llx",
                mss::c_str(i_target),
                STATE_MACHINE_SUCCESS,
                l_state_machine_state,
                l_omi_status,
                l_omi_training_status,
                l_dl0_error_hold
               );

    // Finally, make sure fw_status is good
    FAPI_TRY(mss::exp::i2c::fw_status(i_target, mss::common_timings::DELAY_1MS, 100));

    // Training done bit
    l_expected_dl0_error_hold.setBit<EXPLR_DLX_DL0_ERROR_HOLD_CERR_39>();

    if (l_dl0_error_hold != l_expected_dl0_error_hold)
    {
        // To get to this point, we had to have completed training, so these errors are not catastrophic
        // We don't need to assert out, but let's make sure we print them out
        FAPI_INF("%s EXPLR_DLX_DL0_ERROR_HOLD REG 0x%016llx "
                 "did not match expected value. REG contents: 0x%016llx Expected: 0x%016llx",
                 mss::c_str(i_target),
                 EXPLR_DLX_DL0_ERROR_HOLD,
                 l_dl0_error_hold,
                 l_expected_dl0_error_hold);
    }

    FAPI_DBG("%s End exp_omi_train_check, expected state:%d/actual state:%d, DL0_STATUS:0x%016llx, DL0_TRAINING_STATUS:0x%016llx",
             mss::c_str(i_target),
             STATE_MACHINE_SUCCESS,
             l_state_machine_state,
             l_omi_status,
             l_omi_training_status);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // If OMI training failed or timed out, we need to check some FIRs
    return mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER, mss::check::firChecklist::OMI>(i_target, fapi2::current_err);

}// exp_omi_train_check
