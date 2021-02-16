/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/p9a_omi_train_check.C $ */
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

///
/// @file p9a_omi_train_check.C
/// @brief Check the omi status
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <lib/shared/axone_defaults.H>
#include <p9a_omi_train_check.H>

#include <fapi2.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/mc/omi.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <explorer_scom_addresses.H>
#include <mss_generic_system_attribute_getters.H>

///
/// @brief Check the omi status in Axone side
/// @param[in] i_target the OMIC target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9a_omi_train_check( const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    mss::display_git_commit_info("p9a_omi_train_check");

    FAPI_INF("%s Start p9a_omi_train_check", mss::c_str(i_target));

    // Const
    constexpr uint8_t STATE_MACHINE_SUCCESS = 0b111;  // This value is from Lonny Lambrecht
    constexpr uint8_t MAX_LOOP_COUNT = 10;  // Retry times

    // Declares variables
    fapi2::buffer<uint64_t> l_omi_status;
    fapi2::buffer<uint64_t> l_omi_training_status;
    fapi2::buffer<uint64_t> l_dl0_error_hold;
    fapi2::buffer<uint64_t> l_expected_dl0_error_hold;
    fapi2::buffer<uint64_t> l_dl0_config1;
    fapi2::buffer<uint64_t> l_host_error_hold;
    fapi2::buffer<uint64_t> l_host_edpl_max_count;
    fapi2::buffer<uint64_t> l_exp_dl0_error_hold;
    fapi2::buffer<uint64_t> l_exp_dl0_edpl_max_count;
    fapi2::buffer<uint64_t> l_exp_dl0_status;
    fapi2::buffer<uint64_t> l_exp_dl0_training_status;
    uint8_t l_state_machine_state = 0;
    uint8_t l_tries = 0;
    uint32_t l_omi_freq = 0;
    uint8_t l_sim = 0;

    const auto& l_ocmbs = mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // Sanity check for no empty vector
    if (l_ocmbs.empty())
    {
        // No training could have occurred
        return fapi2::FAPI2_RC_SUCCESS;
    }

    const auto& l_ocmb = l_ocmbs[0];
    const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(l_ocmb);
    const auto& l_mc = mss::find_target<fapi2::TARGET_TYPE_MC>(i_target);

    FAPI_TRY(mss::mc::omi_train_status(i_target, l_state_machine_state, l_omi_status));

    do
    {
        // Delay
        fapi2::delay(500 * mss::DELAY_1MS, 10 * mss::DELAY_1MS);

        // Check OMI training status
        FAPI_TRY(mss::mc::omi_train_status(i_target, l_state_machine_state, l_omi_status));
        l_tries++;

    }
    while (l_tries < MAX_LOOP_COUNT && l_state_machine_state != STATE_MACHINE_SUCCESS);

    // Note: this is very useful debug information while trying to debug training during polling
    FAPI_TRY(fapi2::getScom(i_target, P9A_MC_REG2_DL0_TRAINING_STATUS, l_omi_training_status));
    FAPI_TRY(fapi2::getScom(i_target, P9A_MC_REG2_DL0_CONFIG1, l_dl0_config1));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, l_proc, l_omi_freq));
    FAPI_TRY(fapi2::getScom(i_target, P9A_MC_REG2_DL0_ERROR_HOLD, l_host_error_hold));
    FAPI_TRY(fapi2::getScom(i_target, P9A_MC_REG2_DL0_EDPL_MAX_COUNT, l_host_edpl_max_count));

    FAPI_TRY(mss::attr::get_is_simulation(l_sim));

    if (!l_sim)
    {
        FAPI_TRY(fapi2::getScom(l_ocmb, EXPLR_DLX_DL0_ERROR_HOLD, l_exp_dl0_error_hold));
        FAPI_TRY(fapi2::getScom(l_ocmb, EXPLR_DLX_DL0_EDPL_MAX_COUNT, l_exp_dl0_edpl_max_count));
        FAPI_TRY(fapi2::getScom(l_ocmb, EXPLR_DLX_DL0_STATUS, l_exp_dl0_status));
        FAPI_TRY(fapi2::getScom(l_ocmb, EXPLR_DLX_DL0_TRAINING_STATUS, l_exp_dl0_training_status));
    }

    // Check errors in ERROR_HOLD until we get a proper FIR API setup
    FAPI_TRY(mss::getScom(i_target, P9A_MC_REG2_DL0_ERROR_HOLD, l_dl0_error_hold));

    FAPI_ASSERT(l_state_machine_state == STATE_MACHINE_SUCCESS,
                fapi2::P9A_OMI_TRAIN_ERR()
                .set_MC_TARGET(l_mc)
                .set_OMI_TARGET(i_target)
                .set_OCMB_TARGET(l_ocmb)
                .set_EXPECTED_SM_STATE(STATE_MACHINE_SUCCESS)
                .set_ACTUAL_SM_STATE(l_state_machine_state)
                .set_DL0_STATUS(l_omi_status)
                .set_DL0_TRAINING_STATUS(l_omi_training_status)
                .set_DL0_CONFIG1(l_dl0_config1)
                .set_DL0_ERROR_HOLD(l_dl0_error_hold)
                .set_OMI_FREQ(l_omi_freq),
                "%s P9A OMI Training Failure, expected state:%d/actual state:%d, "
                "DL0_STATUS:0x%016llx, DL0_TRAINING_STATUS:0x%016llx, DL0_ERROR_HOLD:0x%016llx"
                "HOST_DL0_ERROR_HOLD:0x%016llx HOST_DL0_EDPL_MAX_COUNT:0x%016llx"
                "EXP_DL0_ERROR_HOLD:0x%016llx EXP_DL0_EDPL_MAX_COUNT:0x%016llx"
                "EXP_DL0_STATUS:0x%016llx EXP_DL0_TRAINING_STATUS:0x%016llx",
                mss::c_str(i_target),
                STATE_MACHINE_SUCCESS,
                l_state_machine_state,
                l_omi_status,
                l_omi_training_status,
                l_dl0_error_hold,
                l_host_error_hold,
                l_host_edpl_max_count,
                l_exp_dl0_error_hold,
                l_exp_dl0_edpl_max_count,
                l_exp_dl0_status,
                l_exp_dl0_training_status
               );

    // Training completion bit set
    l_expected_dl0_error_hold.setBit<P9A_OMI_REG0_DL0_ERROR_HOLD_CERR_39>();

    // Lost block bit set: this results in p9a only, from the
    // necessary pre-training workarounds, and is expected to be set
    // TK - We will need to the proper FIR unmasking later
    l_expected_dl0_error_hold.setBit<P9A_OMI_REG0_DL0_ERROR_HOLD_CERR_33>();

    if (l_dl0_error_hold != l_expected_dl0_error_hold)
    {
        // To get to this point, we had to have completed training, so these errors are not catastrophic
        // We don't need to assert out, but let's make sure we print them out
        FAPI_INF("%s P9A_MC_REG2_DL0_ERROR_HOLD REG 0x%016llx "
                 "did not match expected value. REG contents: 0x%016llx Expected: 0x%016llx",
                 mss::c_str(i_target),
                 P9A_MC_REG2_DL0_ERROR_HOLD,
                 l_dl0_error_hold,
                 l_expected_dl0_error_hold);
    }

    FAPI_DBG("%s End p9a_omi_train_check, expected state:%d/actual state:%d, DL0_STATUS:0x%016llx, DL0_TRAINING_STATUS:0x%016llx",
             mss::c_str(i_target),
             STATE_MACHINE_SUCCESS,
             l_state_machine_state,
             l_omi_status,
             l_omi_training_status);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // If OMI training failed or timed out, we need to check some FIRs
    return mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER, mss::check::firChecklist::OMI>(i_target, fapi2::current_err);

}// p9a_omi_train_check
