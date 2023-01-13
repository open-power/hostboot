/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_train_check.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file p10_omi_train_check.C
/// @brief Poll for omi training completion / failure
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p10_omi_train_check.H>
#include <p10_scom_omi.H>
#include <lib/omi/p10_omi_utils.H>
#include <lib/fir/p10_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <explorer_scom_addresses.H>
#include <mss_generic_system_attribute_getters.H>


enum p10_omi_train_check_consts
{
    P10_OMI_TRAINING_COMPLETE_STATE = 7,
    P10_OMI_TRAINING_CYCLES = 10000000,
    P10_OMI_TRAINING_NS = 10000,
    P10_OMI_TRAINING_LOOPS = 20,
};

fapi2::ReturnCode p10_omi_train_check_create_training_fail(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb)
{
    // Declares variables
    fapi2::buffer<uint64_t> l_omi_status;
    fapi2::buffer<uint64_t> l_omi_training_status;
    fapi2::buffer<uint64_t> l_host_error_hold;
    fapi2::buffer<uint64_t> l_host_edpl_max_count;
    fapi2::buffer<uint64_t> l_config1;
    fapi2::buffer<uint64_t> l_exp_dl0_error_hold;
    fapi2::buffer<uint64_t> l_exp_dl0_edpl_max_count;
    fapi2::buffer<uint64_t> l_exp_dl0_status;
    fapi2::buffer<uint64_t> l_exp_dl0_training_status;
    uint64_t l_state_machine_state = 0;
    uint32_t l_omi_freq = 0;

    const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_ocmb);
    const auto& l_omic = mss::find_target<fapi2::TARGET_TYPE_OMIC>(i_omi);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, l_proc, l_omi_freq));

    FAPI_TRY(scomt::omi::GET_TRAINING_STATUS(i_omi, l_omi_training_status));
    FAPI_TRY(scomt::omi::GET_CONFIG1(i_omi, l_config1));
    FAPI_TRY(scomt::omi::GET_ERROR_HOLD(i_omi, l_host_error_hold));
    FAPI_TRY(scomt::omi::GET_EDPL_MAX_COUNT(i_omi, l_host_edpl_max_count));

    FAPI_TRY(fapi2::getScom(i_ocmb, EXPLR_DLX_DL0_ERROR_HOLD, l_exp_dl0_error_hold));
    FAPI_TRY(fapi2::getScom(i_ocmb, EXPLR_DLX_DL0_EDPL_MAX_COUNT, l_exp_dl0_edpl_max_count));
    FAPI_TRY(fapi2::getScom(i_ocmb, EXPLR_DLX_DL0_STATUS, l_exp_dl0_status));
    FAPI_TRY(fapi2::getScom(i_ocmb, EXPLR_DLX_DL0_TRAINING_STATUS, l_exp_dl0_training_status));

    FAPI_ASSERT(false,
                fapi2::P10_OMI_TRAIN_ERR()
                .set_OMIC_TARGET(l_omic)
                .set_OMI_TARGET(i_omi)
                .set_OCMB_TARGET(i_ocmb)
                .set_EXPECTED_SM_STATE(mss::omi::STATE_MACHINE_SUCCESS)
                .set_ACTUAL_SM_STATE(l_state_machine_state)
                .set_STATUS(l_omi_status)
                .set_TRAINING_STATUS(l_omi_training_status)
                .set_CONFIG1(l_config1)
                .set_OMI_FREQ(l_omi_freq)
                .set_EXP_ACTIVE_LOG_SIZE(4096),
                "%s P10 OMI Training Failure, expected state:%d/actual state:%d, STATUS:0x%016llx, TRAINING_STATUS:0x%016llx"
                "HOST_DL0_ERROR_HOLD:0x%016llx HOST_DL0_EDPL_MAX_COUNT:0x%016llx"
                "EXP_DL0_ERROR_HOLD:0x%016llx EXP_DL0_EDPL_MAX_COUNT:0x%016llx"
                "EXP_DL0_STATUS:0x%016llx EXP_DL0_TRAINING_STATUS:0x%016llx",
                mss::c_str(i_omi),
                mss::omi::STATE_MACHINE_SUCCESS,
                l_state_machine_state,
                l_omi_status,
                l_omi_training_status,
                l_host_error_hold,
                l_host_edpl_max_count,
                l_exp_dl0_error_hold,
                l_exp_dl0_edpl_max_count,
                l_exp_dl0_status,
                l_exp_dl0_training_status
               );

    FAPI_INF("End p10_omi_train_check, expected state:%d/actual state:%d, STATUS:0x%016llx, TRAINING_STATUS:0x%016llx",
             mss::omi::STATE_MACHINE_SUCCESS,
             l_state_machine_state,
             l_omi_status,
             l_omi_training_status);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check training state of OMI
/// @param[in] i_target Reference to OMI endpoint target
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_train_check_common(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb)
{
    // Declares variables
    fapi2::buffer<uint64_t> l_omi_status;
    uint64_t l_state_machine_state = 0;
    uint8_t l_tries = 0;

    FAPI_TRY(scomt::omi::GET_STATUS(i_omi, l_omi_status));
    scomt::omi::GET_STATUS_TRAINING_STATE_MACHINE(l_omi_status, l_state_machine_state);

    while (l_tries < P10_OMI_TRAINING_LOOPS && l_state_machine_state != P10_OMI_TRAINING_COMPLETE_STATE)
    {
        // HW delay from P10 results
        // Sim delay from VBU testing
        fapi2::delay(P10_OMI_TRAINING_NS, P10_OMI_TRAINING_CYCLES);

        // Check OMI training status
        FAPI_TRY(scomt::omi::GET_STATUS(i_omi, l_omi_status));
        scomt::omi::GET_STATUS_TRAINING_STATE_MACHINE(l_omi_status, l_state_machine_state);
        l_tries++;
    }

    if (l_state_machine_state != P10_OMI_TRAINING_COMPLETE_STATE)
    {
        FAPI_TRY(p10_omi_train_check_create_training_fail(i_omi, i_ocmb));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // If OMI training failed or timed out, we need to check some FIRs
    return mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER, mss::check::firChecklist::OMI>(i_omi, fapi2::current_err);
}


fapi2::ReturnCode p10_omi_train_check(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi)
{
    FAPI_INF("%s Starting p10_omi_train", mss::c_str(i_omi));
    const auto& l_ocmbs = mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_omi);

    // Sanity check for no empty vector
    if (l_ocmbs.empty())
    {
        FAPI_DBG("Exiting OMI train check, no OCMB targets on %s", mss::c_str(i_omi));
        // No training could have occurred
        return fapi2::FAPI2_RC_SUCCESS;
    }

    const auto& l_ocmb = l_ocmbs[0];

    FAPI_TRY(p10_omi_train_check_common(i_omi, l_ocmb));

fapi_try_exit:
    FAPI_INF("%s End p10_omi_train", mss::c_str(i_omi));
    return fapi2::current_err;
}
