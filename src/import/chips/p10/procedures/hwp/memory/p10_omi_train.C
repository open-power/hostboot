/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_train.C $  */
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
/// @file p10_omi_train.C
/// @brief Train the OMI link after p10_omi_setup
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p10_omi_train.H>
#include <lib/omi/p10_omi_utils.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/mss_git_data_helper.H>
#include <p10_io_lib.H>
#include <mss_generic_system_attribute_getters.H>
#include <exp_omi_train.H>
#include <p10_scom_omi.H>
#include <explorer_scom_addresses.H>


enum p10_omi_train_consts
{
    P10_OMI_TRAIN_TSM_PATTERN_B = 2,
    P10_OMI_TRAIN_TSM4 = 4,
    P10_OMI_TRAIN_TSM8 = 8,
    P10_OMI_TRAIN_DELAY_1MS = 1000000, // in nS
    P10_OMI_TRAIN_DELAY_3M_CYCLES = 3000000,
    P10_OMI_TRAIN_MAX_LOOPS = 400,
};



///
/// @brief Start DL link training on the selected OMIC
/// @param[in] i_target Reference to OMIC endpoint target
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_train_explorer(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    uint8_t l_sim = 0;
    FAPI_INF("%s Start p10_omi_train", mss::c_str(i_target));
    mss::display_git_commit_info("p10_omi_train");
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_TRY(mss::attr::get_is_simulation(l_sim));

    if (l_sim)
    {
        FAPI_TRY(mss::omi::p10_omi_train_sim(i_target));
        FAPI_INF("Sim, exiting p10_omi_train %s", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Two OMIs per OMIC
    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        // Poll that P10 is done with its PHY training
        // NOTE: need to do this here to not break parallelization of p10_omi_setup
        fapi2::current_err = p10_io_omi_poll_init_done(l_omi);

        if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
        {
            if (l_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE);
            }

            l_rc = fapi2::current_err;
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }
        else
        {
            // One OCMB per OMI
            // We only need to set up host side registers if there is an OCMB on the other side,
            // otherwise, there's no need to train the link. So with no OCMB, we just skip
            // the below step
            for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
            {

                // Helper to perform upstream PRBS sequence if needed
                FAPI_TRY(mss::omi::p10_omi_train_prbs_helper1(l_omi, l_ocmb));

                FAPI_TRY(exp_omi_train_internal(l_ocmb));

                // kick off ENABLE_AUTO_TRAINING
                FAPI_TRY(mss::omi::p10_omi_train_prbs_helper2(l_omi, l_ocmb));
            }
        }
    }

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        return l_rc;
    }

fapi_try_exit:
    return fapi2::current_err;
}


fapi2::ReturnCode p10_omi_train_create_fail(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
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


fapi2::ReturnCode p10_omi_train_odyssey_init(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi)
{
    fapi2::buffer<uint64_t> l_config0;
    FAPI_TRY(scomt::omi::GET_CONFIG0(i_omi, l_config0));
    scomt::omi::SET_CONFIG0_ENABLE(1, l_config0);
    scomt::omi::SET_CONFIG0_CFG_SPARE(0, l_config0);
    scomt::omi::SET_CONFIG0_CFG_TL_CREDITS(18, l_config0);
    scomt::omi::SET_CONFIG0_TL_EVENT_ACTIONS(0, l_config0);
    scomt::omi::SET_CONFIG0_TL_ERROR_ACTIONS(0, l_config0);
    scomt::omi::SET_CONFIG0_FWD_PROGRESS_TIMER(4, l_config0);
    scomt::omi::SET_CONFIG0_REPLAY_RSVD_ENTRIES(0, l_config0);
    scomt::omi::SET_CONFIG0_DEBUG_SELECT(0, l_config0);
    scomt::omi::SET_CONFIG0_DEBUG_ENABLE(0, l_config0);
    scomt::omi::SET_CONFIG0_DL2TL_DATA_PARITY_INJECT(0, l_config0);
    scomt::omi::SET_CONFIG0_DL2TL_CONTROL_PARITY_INJECT(0, l_config0);
    scomt::omi::SET_CONFIG0_ECC_UE_INJECTION(0, l_config0);
    scomt::omi::SET_CONFIG0_ECC_CE_INJECTION(0, l_config0);
    scomt::omi::SET_CONFIG0_FP_DISABLE(0, l_config0);
    scomt::omi::SET_CONFIG0_TX_LN_REV_ENA(1, l_config0);
    scomt::omi::SET_CONFIG0_128_130_ENCODING_ENABLED(0, l_config0);
    scomt::omi::SET_CONFIG0_PHY_CNTR_LIMIT(15, l_config0);
    scomt::omi::SET_CONFIG0_RUNLANE_OVRD_ENABLE(0, l_config0);
    scomt::omi::SET_CONFIG0_PWRMGT_ENABLE(0, l_config0);
    scomt::omi::SET_CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE(0, l_config0);
    scomt::omi::SET_CONFIG0_HALF_WIDTH_BACKOFF_ENABLE(1, l_config0);
    scomt::omi::SET_CONFIG0_SUPPORTED_MODES(3, l_config0);
    scomt::omi::SET_CONFIG0_TRAIN_MODE(1, l_config0); // Tx Pattern A
    scomt::omi::SET_CONFIG0_VERSION(9, l_config0);
    scomt::omi::SET_CONFIG0_RETRAIN(0, l_config0);
    scomt::omi::SET_CONFIG0_RESET(0, l_config0);
    FAPI_TRY(scomt::omi::PUT_CONFIG0(i_omi, l_config0));

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode p10_omi_train_odyssey_set_training_state(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
        const uint32_t& i_training_state)
{
    fapi2::buffer<uint64_t> l_config0;
    FAPI_TRY(scomt::omi::GET_CONFIG0(i_omi, l_config0));
    FAPI_DBG("%s Set Training State Machine = %d", mss::c_str(i_omi), i_training_state);
    scomt::omi::SET_CONFIG0_TRAIN_MODE(i_training_state, l_config0);
    FAPI_TRY(scomt::omi::PUT_CONFIG0(i_omi, l_config0));
fapi_try_exit:
    return fapi2::current_err;
}


fapi2::ReturnCode p10_omi_train_odyssey_poll_pattern(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
        const uint32_t& i_start_bit,
        const uint32_t& i_length)
{
    fapi2::buffer<uint64_t> l_status;
    uint64_t l_pattern = 0;
    int i = 0;

    // Tx Pattern A, Rx Pattern B
    // Typically takes ~5M Cycles
    for (i = 0; i < P10_OMI_TRAIN_MAX_LOOPS; i++)
    {
        FAPI_DBG("%s Loop[%d] Checking for Pattern...", mss::c_str(i_omi), i);
        FAPI_TRY(scomt::omi::GET_TRAINING_STATUS(i_omi, l_status));
        l_status.extractToRight(l_pattern, i_start_bit, i_length);

        if (l_pattern > 0)
        {
            break;
        }

        FAPI_TRY(fapi2::delay(P10_OMI_TRAIN_DELAY_1MS, P10_OMI_TRAIN_DELAY_3M_CYCLES));
    }

    // Check for Errors
    if (l_pattern)
    {
        FAPI_DBG("%s Found Pattern(0x%08X%08X) after %dms...", mss::c_str(i_omi), l_status >> 32, l_status, i);
    }
    else
    {
        FAPI_ERR("%s ERROR: Pattern(0x%08X%08X) Not Found", mss::c_str(i_omi), l_status >> 32, l_status);
        FAPI_TRY(p10_omi_train_create_fail(i_omi, i_ocmb));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Start DL link training on the selected OMIC
/// @param[in] i_target Reference to OMIC endpoint target
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_train_odyssey(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic)
{
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_ocmb;

    // Initialize Config0 & Drive Pattern A
    for (const auto& l_omi : i_omic.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        const auto& l_ocmbs = l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(fapi2::TARGET_STATE_FUNCTIONAL);

        if (!l_ocmbs.empty())
        {
            FAPI_TRY(p10_omi_train_odyssey_init(l_omi));
        }
    }

    // Poll Pattern B & Drive Pattern B
    for (const auto& l_omi : i_omic.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        const auto& l_ocmbs = l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(fapi2::TARGET_STATE_FUNCTIONAL);

        if (!l_ocmbs.empty())
        {
            l_ocmb = l_ocmbs[0];
            FAPI_DBG("%s Poll for Pattern B", mss::c_str(l_omi));
            FAPI_TRY(p10_omi_train_odyssey_poll_pattern(l_omi, l_ocmb, scomt::omi::TRAINING_STATUS_RX_PATTERN_B,
                     scomt::omi::TRAINING_STATUS_RX_PATTERN_B_LEN));
            FAPI_TRY(p10_omi_train_odyssey_set_training_state(l_omi, P10_OMI_TRAIN_TSM_PATTERN_B))
        }
    }

    // Poll Pattern Sync & Drive Pattern TSM4
    for (const auto& l_omi : i_omic.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        const auto& l_ocmbs = l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(fapi2::TARGET_STATE_FUNCTIONAL);

        if (!l_ocmbs.empty())
        {
            l_ocmb = l_ocmbs[0];
            FAPI_DBG("%s Poll for Sync Pattern", mss::c_str(l_omi));
            FAPI_TRY(p10_omi_train_odyssey_poll_pattern(l_omi, l_ocmb, scomt::omi::TRAINING_STATUS_SYNC_PATTERN,
                     scomt::omi::TRAINING_STATUS_SYNC_PATTERN_LEN));
            FAPI_TRY(p10_omi_train_odyssey_set_training_state(l_omi, P10_OMI_TRAIN_TSM4))
        }
    }

    // Poll Pattern TS2 & Drive Pattern TSM8 (Auto Train)
    for (const auto& l_omi : i_omic.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        const auto& l_ocmbs = l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(fapi2::TARGET_STATE_FUNCTIONAL);

        if (!l_ocmbs.empty())
        {
            l_ocmb = l_ocmbs[0];
            FAPI_DBG("%s Poll for TS2 Pattern", mss::c_str(l_omi));
            FAPI_TRY(p10_omi_train_odyssey_poll_pattern(l_omi, l_ocmb, scomt::omi::TRAINING_STATUS_RX_TS2,
                     scomt::omi::TRAINING_STATUS_RX_TS2_LEN));
            FAPI_TRY(p10_omi_train_odyssey_set_training_state(l_omi, P10_OMI_TRAIN_TSM8))
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}


fapi2::ReturnCode p10_omi_train(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic)
{

    FAPI_INF("Starting p10_omi_train");
    uint8_t l_ocmb_type = fapi2::ENUM_ATTR_NAME_NONE;
    bool l_any_odyssey = false;

    for (const auto& l_omi : i_omic.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        const auto& l_ocmbs = l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(fapi2::TARGET_STATE_FUNCTIONAL);

        if (!l_ocmbs.empty())
        {
            const auto& l_ocmb = l_ocmbs[0];
            FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, l_ocmb, l_ocmb_type));
            FAPI_DBG("OCMB Type: %d", l_ocmb_type)

            if (l_ocmb_type == fapi2::ENUM_ATTR_NAME_ODYSSEY)
            {
                l_any_odyssey = true;
                break;
            }
        }
    }

    if (l_any_odyssey)
    {
        FAPI_TRY(p10_omi_train_odyssey(i_omic));
    }
    else // Explorer, Gemini
    {
        FAPI_TRY(p10_omi_train_explorer(i_omic));
    }


fapi_try_exit:
    FAPI_INF("End p10_omi_train");
    return fapi2::current_err;
}
