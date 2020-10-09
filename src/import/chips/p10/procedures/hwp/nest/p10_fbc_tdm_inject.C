/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_tdm_inject.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file p10_fbc_tdm_inject.C
/// @brief Force TDM entry on IOHS link (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fbc_tdm_inject.H>
#include <p10_fbc_tdm_utils.H>
#include <p10_io_power.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// tdm transition delay/polling constants
const uint32_t P10_FBC_TDM_INJECT_TDM_TRANSITION_HW_NS_DELAY     = 10000000;
const uint32_t P10_FBC_TDM_INJECT_TDM_TRANSITION_SIM_CYCLE_DELAY = 10000000;
const uint32_t P10_FBC_TDM_INJECT_TDM_TRANSITION_MAX_WAIT_POLLS  = 100;

// recal stop polling constants
const uint32_t P10_FBC_TDM_INJECT_RECAL_STOP_MAX_ATTEMPTS = 10;

// typedef for function pointers
typedef fapi2::ReturnCode (*p10_fbc_tdm_inject_func_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, const bool);

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Trigger TDM entry, the specified half-link will be quiesced
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to quiesce (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_tdm_enter(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc_target;
    fapi2::ATTR_CHIP_EC_FEATURE_HW532820_Type l_hw532820;
    l_proc_target = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW532820, l_proc_target, l_hw532820));

    // Note that RESET is either a soft reset (when link is up)
    // or hard reset (when link is down) and would also deassert
    // link_up, whereas ENTER_TDM would leave link_up asserted.
    // RESET would be the ideal command here, except HW532820
    // prevents us from using it.
    if (l_hw532820)
    {
        // input parameter specifies link half we want to become
        // non-functional; command is sent to partner link which we
        // want to remain functional in this case
        FAPI_TRY(p10_fbc_tdm_utils_dl_send_command(
                     i_target,
                     !i_even_not_odd,
                     p10_fbc_tdm_utils_dl_cmd_t::ENTER_TDM),
                 "Error from p10_fbc_tdm_utils_dl_send_command (ENTER_TDM)");
    }
    else
    {
        FAPI_TRY(p10_fbc_tdm_utils_dl_send_command(
                     i_target,
                     i_even_not_odd,
                     p10_fbc_tdm_utils_dl_cmd_t::RESET),
                 "Error from p10_fbc_tdm_utils_dl_send_command (RESET)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Confirm that partner link is currently running and assert
///        if not. This should give flexiblity to call the inject
///        procedure at full width mode, or on a half link which
///        has been quiesced by HW.
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to quiesce (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_tdm_confirm_partner(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");

    bool l_selected_link_down = false;
    bool l_partner_link_down = false;

    FAPI_TRY(p10_fbc_tdm_utils_tdm_query(
                 i_target,
                 i_even_not_odd,
                 l_selected_link_down),
             "Error from p10_fbc_tdm_utils_tdm_query (selected)");

    FAPI_TRY(p10_fbc_tdm_utils_tdm_query(
                 i_target,
                 !i_even_not_odd,
                 l_partner_link_down),
             "Error from p10_fbc_tdm_utils_tdm_query (partner)");

    FAPI_ASSERT(!l_partner_link_down,
                fapi2::P10_FBC_TDM_INJECT_PRE_CONDITION_ERR()
                .set_IOHS_TARGET(i_target)
                .set_PAUC_TARGET(i_target.getParent<fapi2::TARGET_TYPE_PAUC>())
                .set_EVEN_NOT_ODD(i_even_not_odd)
                .set_SELECTED_LINK_DOWN(l_selected_link_down)
                .set_PARTNER_LINK_DOWN(l_partner_link_down),
                "Partner link is not running!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Confirm that specified half-link has been quiesced
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to check (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_tdm_confirm_half(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");

    bool l_link_down = false;

    for (uint32_t i = 0; i < P10_FBC_TDM_INJECT_TDM_TRANSITION_MAX_WAIT_POLLS; i++)
    {
        FAPI_DBG("Polling link state..");
        FAPI_TRY(p10_fbc_tdm_utils_tdm_query(
                     i_target,
                     i_even_not_odd,
                     l_link_down),
                 "Error from p10_fbc_tdm_utils_tdm_query");

        if (l_link_down)
        {
            FAPI_DBG("Success! DL indicates it is in half-width mode");
            break;
        }

        FAPI_TRY(fapi2::delay(P10_FBC_TDM_INJECT_TDM_TRANSITION_HW_NS_DELAY, P10_FBC_TDM_INJECT_TDM_TRANSITION_SIM_CYCLE_DELAY),
                 "Error from fapi2 delay while waiting for dl transition to half-width to complete");
    }

    FAPI_ASSERT(l_link_down,
                fapi2::P10_FBC_TDM_INJECT_POST_CONDITION_ERR()
                .set_IOHS_TARGET(i_target)
                .set_PAUC_TARGET(i_target.getParent<fapi2::TARGET_TYPE_PAUC>())
                .set_EVEN_NOT_ODD(i_even_not_odd),
                "Link is not running in half-width mode!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Trigger recal stop on both sublinks
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to reset (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_tdm_recal_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc_target;
    fapi2::ATTR_CHIP_EC_FEATURE_HW532820_Type l_hw532820;
    l_proc_target = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY(p10_fbc_tdm_utils_recal_stop(i_target, i_even_not_odd));

    // call twice to avoid window condition on DD1
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW532820, l_proc_target, l_hw532820));

    if (l_hw532820)
    {
        FAPI_TRY(p10_fbc_tdm_utils_recal_stop(i_target, i_even_not_odd));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Confirm recal has stopped on both sublinks
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to reset (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_tdm_confirm_recal_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");
    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc_target;
    fapi2::ATTR_CHIP_EC_FEATURE_HW532820_Type l_hw532820;
    l_proc_target = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW532820, l_proc_target, l_hw532820));

    l_rc = p10_fbc_tdm_utils_confirm_recal_stop(i_target, i_even_not_odd);

    if (!l_hw532820)
    {
        FAPI_TRY(l_rc,
                 "Error from p10_fbc_tdm_utils_confirm_recal_stop");
    }
    else
    {
        // if recal is not stopped, then we haven't successfully avoided the window condition where
        // recal can restart if both endpoints do not stop recal within 20ms.
        // Attempt to stop recal again for n iterations until we are either
        // successful or ultimately give up.
        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            for (uint8_t l_count = 1; l_count <= P10_FBC_TDM_INJECT_RECAL_STOP_MAX_ATTEMPTS; l_count++)
            {
                FAPI_DBG("Recal did not stop, trying again (attempt %d/%d)",
                         l_count, P10_FBC_TDM_INJECT_RECAL_STOP_MAX_ATTEMPTS);

                FAPI_TRY(p10_fbc_tdm_recal_stop(i_target, i_even_not_odd));
                l_rc = p10_fbc_tdm_utils_confirm_recal_stop(i_target, i_even_not_odd);

                if (l_rc == fapi2::FAPI2_RC_SUCCESS)
                {
                    FAPI_DBG("Recal successfully stopped!");
                    break;
                }
                else if (l_count == P10_FBC_TDM_INJECT_RECAL_STOP_MAX_ATTEMPTS)
                {
                    FAPI_TRY(l_rc,
                             "Recal failed to stop after %d attempts!",
                             P10_FBC_TDM_INJECT_RECAL_STOP_MAX_ATTEMPTS);
                }
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Trigger partial reset on specified half-link
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to reset (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_tdm_partial_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");

    FAPI_TRY(p10_fbc_tdm_utils_dl_send_command(
                 i_target,
                 i_even_not_odd,
                 p10_fbc_tdm_utils_dl_cmd_t::PART_RESET),
             "Error from p10_fbc_tdm_utils_dl_send_command");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Power down PHY logic associated with selected half-link
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to target (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_tdm_phy_powerdown(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_iolink_pdwn;

    FAPI_TRY(p10_fbc_tdm_utils_get_iolink(i_target, i_even_not_odd, l_iolink_pdwn),
             "Error from p10_fbc_tdm_utils_get_iolink");

    FAPI_TRY(p10_io_iolink_power(l_iolink_pdwn, false),
             "Error from p10_io_iohs_power");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_fbc_tdm_inject(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd,
    const p10_fbc_tdm_inject_opt_t& i_opts)
{
    fapi2::ReturnCode l_rc;
    char l_target_str[fapi2::MAX_ECMD_STRING_LEN];
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOHS>> l_targets;

    fapi2::toString(i_target, l_target_str, sizeof(l_target_str));

    FAPI_DBG("Calling p10_fbc_tdm_inject for %s (even_not_odd: %d, run_all: %d [step: %d])",
             l_target_str,
             (i_even_not_odd) ? (1) : (0),
             (i_opts.run_all) ? (1) : (0),
             (i_opts.run_all) ? (0) : (static_cast<uint8_t>(i_opts.step)));

    // table of function pointers
    p10_fbc_tdm_inject_func_t l_funcs[] =
    {
        p10_fbc_tdm_confirm_partner,
        p10_fbc_tdm_utils_fir_mask,
        p10_fbc_tdm_enter,
        p10_fbc_tdm_confirm_half,
        p10_fbc_tdm_recal_stop,
        p10_fbc_tdm_confirm_recal_stop,
        p10_fbc_tdm_partial_reset,
        p10_fbc_tdm_phy_powerdown
    };

    // validate input target
    FAPI_TRY(p10_fbc_tdm_utils_validate_targets(i_target, l_targets),
             "Error from p10_fbc_tdm_utils_validate_targets");

    // execute selected recovery steps
    for (uint8_t l_step = 0; l_step < P10_FBC_TDM_INJECT_END; ++l_step)
    {
        FAPI_DBG("Checking step: %d", l_step);

        if (i_opts.run_all || (i_opts.step == l_step))
        {
            for (auto l_target : l_targets)
            {
                FAPI_DBG("Running...");
                FAPI_TRY(l_funcs[l_step](l_target, i_even_not_odd),
                         "Error from step %d (%s)", l_step, (i_even_not_odd) ? ("even") : ("odd"));
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
