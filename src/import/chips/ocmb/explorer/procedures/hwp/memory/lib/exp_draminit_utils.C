/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_draminit_utils.C $ */
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
/// @file exp_draminit_utils.C
/// @brief Procedure definition to initialize DRAM
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
#include <lib/exp_draminit_utils.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/c_str.H>
#include <exp_inband.H>
#include <lib/eff_config/explorer_attr_engine_traits.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/shared/exp_consts.H>

namespace mss
{
namespace exp
{

///
/// @brief Check that the rsp_data size returned from the PHY_INIT command matches the expected size
///
/// @param[in] i_target OCMB target
/// @param[in] i_actual_size size enum expected for the given phy init mode
/// @param[in] i_mode phy init mode. Expected to be a valid enum value since we asserted as such in exp_draminit.C
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff matching, else MSS_EXP_INVALID_PHY_INIT_RSP_DATA_LENGTH
///
fapi2::ReturnCode check_rsp_data_size(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint16_t i_actual_size,
    const phy_init_mode i_mode)
{
    uint16_t l_expected_size = 0;

    switch (i_mode)
    {
        case phy_init_mode::NORMAL:
            l_expected_size = sizeof(user_response_msdg_t);
            break;

        case phy_init_mode::EYE_CAPTURE_STEP_1:
            l_expected_size = sizeof(user_2d_eye_response_1_msdg_t);
            break;

        case phy_init_mode::EYE_CAPTURE_STEP_2:
            l_expected_size = sizeof(user_2d_eye_response_2_msdg_t);
            break;

        default:
            // This really can't occur since we asserted phy_init_mode was valid in exp_draminit.C
            // We have bigger problems if we get here, implying somehow this bad value was passed to explorer
            FAPI_ASSERT(false,
                        fapi2::MSS_EXP_UNKNOWN_PHY_INIT_MODE()
                        .set_TARGET(i_target)
                        .set_VALUE(i_mode),
                        "%s Value for phy init mode for exp_draminit is unknown: %u expected 0 (NORMAL), 1 (EYE_CAPTURE_STEP_1), 2 (EYE_CAPTURE_STEP_2)",
                        mss::c_str(i_target), i_mode);
            break;
    }

    FAPI_ASSERT(l_expected_size == i_actual_size,
                fapi2::MSS_EXP_INVALID_PHY_INIT_RSP_DATA_LENGTH()
                .set_OCMB_TARGET(i_target)
                .set_PHY_INIT_MODE(i_mode)
                .set_EXPECTED_LENGTH(l_expected_size)
                .set_ACTUAL_LENGTH(i_actual_size),
                "%s PHY INIT response data buffer size 0x%x did not match expected size 0x%x for phy_init_mode %u",
                mss::c_str(i_target), i_actual_size, l_expected_size, i_mode);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform host FW phy init based upon the requested PHY initialization mode
///
/// @param[in] i_target OCMB target
/// @param[in] i_phy_info phy information of interest
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note In hostboot, this function will return SUCCESS upon taking a training fail
/// where bad bits can be successfully logged. If we can log bad bits, then we want
/// PRD and memdiags to attempt to run with the correct repairs
/// In cronus mode, any RC's we take due to training is returned directly
///
fapi2::ReturnCode host_fw_phy_init(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   const uint8_t i_phy_init_mode)
{
    user_input_msdg l_phy_params;
    mss::exp::phy_param_info l_phy_info;
    FAPI_TRY(mss::exp::init_phy_params(i_target, l_phy_params, l_phy_info));

    // Call appropriate init function
    if (i_phy_init_mode == fapi2::ENUM_ATTR_MSS_OCMB_PHY_INIT_MODE_NORMAL)
    {
        FAPI_TRY(mss::exp::host_fw_phy_normal_init(i_target, l_phy_info));
    }
    else
    {
        FAPI_TRY(mss::exp::host_fw_phy_init_with_eye_capture(i_target, l_phy_params, l_phy_info));
    }

fapi_try_exit:
#ifdef __HOSTBOOT_MODULE
    // In hostboot, we do not want to exit on a training fail, RC's will flow through
    return handle_training_error(i_target, fapi2::current_err);
#else
    // In cronus, just return the RC
    return fapi2::current_err;
#endif
}

///
/// @brief Perform normal host FW phy init
///
/// @param[in] i_target OCMB target
/// @param[in] i_phy_info phy information of interest
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode host_fw_phy_normal_init(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const phy_param_info& i_phy_info)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    host_fw_command_struct l_cmd;
    std::vector<uint8_t> l_rsp_data;

    // Issue full boot mode cmd though EXP-FW REQ buffer
    FAPI_TRY(send_host_phy_init_cmd(i_target, i_phy_info, phy_init_mode::NORMAL, l_cmd));

    // Note: don't FAPI_TRY here!
    // We want to grab this error, then try to update the bad bits appropriately
    // Logging of bad bits happens in read_and_display_normal_training_response
    l_rc = mss::exp::check::host_fw_response(i_target, l_cmd, l_rsp_data);

    FAPI_TRY(check_rsp_data_size(i_target, l_rsp_data.size(), phy_init_mode::NORMAL));
    FAPI_TRY(mss::exp::read_and_display_normal_training_response(i_target, l_rsp_data, l_rc));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform host FW phy init with eye capture
/// @param[in] i_target OCMB target
/// @param[in] i_phy_params phy initialization resp. struct
/// @param[in] i_phy_info phy information of interest
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note the goal here is to attempt to send both phy_inits even
/// in the event of a bad return code from the read & display
///
fapi2::ReturnCode host_fw_phy_init_with_eye_capture(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const user_input_msdg& i_phy_params,
    const phy_param_info& i_phy_info)
{
    fapi2::ReturnCode l_check_response_1_rc;
    fapi2::ReturnCode l_read_display_response_1_rc;
    fapi2::ReturnCode l_check_response_2_rc;
    fapi2::ReturnCode l_read_display_response_2_rc;

    user_2d_eye_response_1_msdg l_response_1;
    user_2d_eye_response_2_msdg l_response_2;

    // If the data is the right size, we can read and display it.
    // Otherwise, skip the reading and try step 2
    FAPI_TRY(impl_details::common_init_eye_capture(i_target,
             phy_init_mode::EYE_CAPTURE_STEP_1,
             i_phy_info,
             l_check_response_1_rc,
             l_read_display_response_1_rc,
             l_response_1));

    // Put user_input_msdg again for step 2 (overwritten by data buffer from step 1)
    {
        phy_param_info l_phy_info = i_phy_info;

        FAPI_TRY( mss::exp::ib::putUserInputMsdg(i_target, i_phy_params, l_phy_info.iv_crc),
                  "Failed putUserInputMsdg() for %s", mss::c_str(i_target) );

        FAPI_TRY(impl_details::common_init_eye_capture(i_target,
                 phy_init_mode::EYE_CAPTURE_STEP_2,
                 l_phy_info,
                 l_check_response_2_rc,
                 l_read_display_response_2_rc,
                 l_response_2));
    }

    // Set Explorer RC response attributes
    FAPI_TRY(set_rc_resp_attrs(i_target,
                               l_read_display_response_1_rc,
                               l_read_display_response_2_rc,
                               l_response_1,
                               l_response_2));

    // Check the return codes and skip attr_engine
    FAPI_TRY(process_eye_capture_return_codes(i_target,
             l_response_1,
             l_response_2,
             l_check_response_1_rc,
             l_check_response_2_rc));

    // Finally, check the display response return codes
    FAPI_TRY(l_read_display_response_1_rc, "Error ocurred reading/displaying eye capture response 1 of %s",
             mss::c_str(i_target));
    FAPI_TRY(l_read_display_response_2_rc, "Error ocurred reading/displaying eye capture response 2 of %s",
             mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to set rc response attrs
/// @param[in] i_target the fapi2 OCMB target
/// @param[in] i_rc_resp the Explorer rc response
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode set_rc_resp_attrs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const user_response_rc_msdg_t& i_rc_resp)
{
    for (const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        uint8_t l_is_rcd_supported = 0;
        FAPI_TRY(mss::attr::get_supported_rcd(d, l_is_rcd_supported));

        if(l_is_rcd_supported != fapi2::ENUM_ATTR_MEM_EFF_SUPPORTED_RCD_NO_RCD)
        {
            mss::exp::rc_resp_adaptor l_rcws(d, i_rc_resp);
            FAPI_TRY(mss::exp::rc_resp_engine(l_rcws));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to set rc response attrs
/// @param[in] i_target the fapi2 OCMB target
/// @param[in] i_read_display_response_1_rc ReturnCode for display_response_1
/// @param[in] i_read_display_response_2_rc ReturnCode for display_response_2
/// @param[in] i_response_1 the user_2d_eye_response_1_msdg
/// @param[in] i_response_2 user_2d_eye_response_2_msdg
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode set_rc_resp_attrs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const fapi2::ReturnCode& i_read_display_response_1_rc,
                                    const fapi2::ReturnCode& i_read_display_response_2_rc,
                                    const user_2d_eye_response_1_msdg& i_response_1,
                                    const user_2d_eye_response_2_msdg& i_response_2)
{
    if (i_read_display_response_1_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        // If both init cmds pass, we use the 1st response arbitrarily
        FAPI_TRY(set_rc_resp_attrs(i_target, i_response_1.rc_resp));
    }

    else if (i_read_display_response_2_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        // If 1 of 2 init cmds fail, we run the attr_engine on the passing one.
        FAPI_TRY(set_rc_resp_attrs(i_target, i_response_2.rc_resp));
    }

    else
    {
        // If both init cmds fail, we don't run set the attributes (defaulted to 0)
        FAPI_DBG("Bad ReturnCode for read display response 1 and 2, "
                 "will NOT set Explorer rc response attrs for %s.",
                 mss::c_str(i_target));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Process return codes from PHY init with eye capture operations
///
/// @param[in] i_target OCMB target
/// @param[in] i_response_1 response struct for EYE_CAPTURE_STEP_1
/// @param[in] i_response_2 response struct for EYE_CAPTURE_STEP_2
/// @param[in] i_response_1_rc response from check::host_fw_response from EYE_CAPTURE_STEP_1
/// @param[in] i_response_2_rc response from check::host_fw_response from EYE_CAPTURE_STEP_2
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else an error from above as defined in the function algorithm
/// @note return codes are passed by value, caller should not expect these to change
/// @note processes the bad bits based upon the passed in ReturnCodes
///
fapi2::ReturnCode process_eye_capture_return_codes(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const user_2d_eye_response_1_msdg& i_response_1,
        const user_2d_eye_response_2_msdg& i_response_2,
        fapi2::ReturnCode i_response_1_rc,
        fapi2::ReturnCode i_response_2_rc)
{
    const bool l_response_1_failed = i_response_1_rc != fapi2::FAPI2_RC_SUCCESS;
    const bool l_response_2_failed = i_response_2_rc != fapi2::FAPI2_RC_SUCCESS;

    if (l_response_2_failed)
    {
        FAPI_ERR("%s check_fw_host_response() for %s returned error code 0x%016llu",
                 mss::c_str(i_target), "EYE_CAPTURE_STEP_2", uint64_t(i_response_2_rc));

        // So, why aren't we logging the bad bits here?
        // Turns out, Microchip's firmware assumes that all bad bits are found in train_response1
        // As such, they won't log any bad bits in train_response2, even if they they take a training fail
        // No point to go through the effort if the data isn't there

        if (l_response_1_failed)
        {
            // Log response 2's error, and let's return response 1
            fapi2::logError(i_response_2_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);

            // logError sets the return code& to NULL. Set to FAPI2_RC_SUCCESS in case of use
            i_response_2_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY(i_response_2_rc);
    }

    if (l_response_1_failed)
    {
        FAPI_ERR("%s check_fw_host_response() for %s returned error code 0x%016llu",
                 mss::c_str(i_target), "EYE_CAPTURE_STEP_1", uint64_t(i_response_1_rc));

        // Handles the bad bit error processing
        return bad_bit_processing(i_target, i_response_1, i_response_1_rc);
    }

    // Else, we did not see errors!
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Send PHY init command given the provided phy mode and CRC
///
/// @param[in] i_target OCMB target
/// @param[in] i_phy_info phy information of interest
/// @param[in] i_phy_init_mode normal / eye capture step 1 or 2
/// @param[out] host_fw_command_struct used for initialization
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode send_host_phy_init_cmd(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const phy_param_info& i_phy_info,
        const uint8_t i_phy_init_mode,
        host_fw_command_struct& o_cmd)
{
    host_fw_command_struct l_cmd;

    // Issue full boot mode cmd though EXP-FW REQ buffer
    FAPI_TRY(setup_cmd_params(i_target, i_phy_info.iv_crc, i_phy_info.iv_size, i_phy_init_mode, l_cmd));
    FAPI_TRY(mss::exp::ib::putCMD(i_target, l_cmd), "Failed putCMD() for  %s", mss::c_str(i_target));

    // Wait a bit for the command (and training) to complete
    // Value based on initial Explorer hardware in Cronus in i2c mode.
    // Training takes ~10ms with no trace, ~450ms with Explorer UART debug
    FAPI_TRY(fapi2::delay((mss::DELAY_1MS * 8), 200));

    o_cmd = l_cmd;

fapi_try_exit:
    return fapi2::current_err;
}

namespace check
{

///
/// @brief Check the error code returned from DDR_PHY_INIT
///
/// @param[in] i_target OCMB chip
/// @param[in] i_cmd host_fw_command_struct used to generate the response
/// @param[in] i_rsp_arg response arguement buffer
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode fw_ddr_phy_init_response_code(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const host_fw_command_struct& i_cmd,
        const uint8_t i_rsp_arg[ARGUMENT_SIZE])
{
    const uint8_t l_rsp_status = i_rsp_arg[0];

    // If the response isn't a success check the return code
    if (l_rsp_status != omi::response_arg::RESPONSE_SUCCESS)
    {
        fapi2::buffer<uint32_t> l_error_extended_code;
        const uint8_t l_error_code = i_rsp_arg[5];

        l_error_extended_code.insertFromRight<0, BITS_PER_BYTE>(i_rsp_arg[4]).
        insertFromRight<BITS_PER_BYTE, BITS_PER_BYTE>(i_rsp_arg[3]).
        insertFromRight<2 * BITS_PER_BYTE, BITS_PER_BYTE>(i_rsp_arg[2]).
        insertFromRight<3 * BITS_PER_BYTE, BITS_PER_BYTE>(i_rsp_arg[1]);

        // Check Explorer return code
        FAPI_ASSERT( (l_error_code != FW_DDR_PHY_INIT_UNSUPPORTED_MODE),
                     fapi2::MSS_EXP_DDR_PHY_INIT_UNSUPPORTED_MODE().
                     set_TARGET(i_target).
                     set_PHY_INIT_MODE(i_cmd.command_argument[0]).
                     set_ERROR_CODE(l_error_code).
                     set_EXTENDED_ERROR_CODE(l_error_extended_code),
                     "DDR_PHY_INIT unsupported mode error (TARGET %s, PHY_INIT_MODE 0x%08X, "
                     "error_code 0x%02X, extended_error_code=0x%08X)",
                     mss::c_str(i_target), i_cmd.command_argument[0], l_error_code, l_error_extended_code);

        FAPI_ASSERT( (l_error_code != mss::exp::fw_ddr_phy_init_status::FW_DDR_PHY_INIT_USER_MSDG_SIZE_ERR),
                     fapi2::MSS_EXP_DDR_PHY_INIT_USER_INPUT_MSDG_SIZE_ERROR().
                     set_TARGET(i_target).
                     set_COMMAND_SIZE(i_cmd.cmd_length).
                     set_ERROR_CODE(l_error_code).
                     set_EXTENDED_ERROR_CODE(l_error_extended_code),
                     "DDR_PHY_INIT incorrect user_input_msdg size error (TARGET %s, CMD SIZE 0x%08X, "
                     "error_code 0x%02X, extended_error_code=0x%08X)",
                     mss::c_str(i_target), i_cmd.cmd_length, l_error_code, l_error_extended_code);

        FAPI_ASSERT( (l_error_code != fw_ddr_phy_init_status::FW_DDR_PHY_INIT_USER_MSDG_FLAG_ERR),
                     fapi2::MSS_EXP_DDR_PHY_INIT_USER_INPUT_MSDG_MISSING_FLAG().
                     set_TARGET(i_target).
                     set_COMMAND_FLAGS(i_cmd.cmd_flags).
                     set_ERROR_CODE(l_error_code).
                     set_EXTENDED_ERROR_CODE(l_error_extended_code),
                     "DDR_PHY_INIT user_input_msdg missing extended data flag (TARGET %s, CMD FLAGS 0x%08X, "
                     "error_code 0x%02X, extended_error_code=0x%08X)",
                     mss::c_str(i_target), i_cmd.cmd_flags, l_error_code, l_error_extended_code);

        FAPI_ASSERT( (l_error_code != fw_ddr_phy_init_status::FW_DDR_PHY_INIT_USER_MSDG_ERROR),
                     fapi2::MSS_EXP_DDR_PHY_INIT_USER_INPUT_MSDG_ERROR().
                     set_TARGET(i_target).
                     set_ERROR_CODE(l_error_code).
                     set_EXTENDED_ERROR_CODE(l_error_extended_code),
                     "DDR_PHY_INIT encountered a user_input_msdg error (TARGET %s, error_code 0x%02X, extended_error_code=0x%08X)",
                     mss::c_str(i_target), l_error_code, l_error_extended_code);

        // TODO: Zenhub #818: Training callout will need to be updated
        //       Pending additional followup meetings with MCHP
        FAPI_ASSERT( (l_error_code != fw_ddr_phy_init_status::FW_DDR_PHY_INIT_TRAINING_FAIL),
                     fapi2::MSS_EXP_DDR_PHY_INIT_TRAINING_FAIL().
                     set_TARGET(i_target).
                     set_ERROR_CODE(l_error_code).
                     set_EXTENDED_ERROR_CODE(l_error_extended_code),
                     "DDR_PHY_INIT encountered a training fail (TARGET %s, error_code 0x%02X, extended_error_code=0x%08X)",
                     mss::c_str(i_target), l_error_code, l_error_extended_code);

        FAPI_ASSERT( false,
                     fapi2::MSS_EXP_DDR_PHY_INIT_UNKNOWN_ERROR().
                     set_TARGET(i_target).
                     set_ERROR_CODE(l_error_code).
                     set_EXTENDED_ERROR_CODE(l_error_extended_code),
                     "DDR_PHY_INIT encountered an unknown error code causing a fail(TARGET %s, error_code 0x%02X, extended_error_code=0x%08X) for ",
                     mss::c_str(i_target), l_error_code, l_error_extended_code);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get and check the host fw response from the explorer
///
/// @param[in] i_target OCMB chip
/// @param[in] i_cmd host_fw_command_struct used to generate the response
/// @param[out] o_rsp_data response data
/// @param[out] o_rc return code from mss::exp::check::response()
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode host_fw_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   const host_fw_command_struct& i_cmd,
                                   std::vector<uint8_t>& o_rsp_data)
{
    host_fw_response_struct l_response;

    FAPI_TRY(mss::exp::ib::getRSP(i_target, l_response, o_rsp_data),
             "Failed getRSP() for  %s", mss::c_str(i_target));

    FAPI_TRY(mss::exp::check::fw_ddr_phy_init_response_code(i_target, i_cmd, l_response.response_argument),
             "Encountered error from host fw ddr_phy_init for %s", mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} //namespace check

///
/// @brief Reads and displays the normal draminit training response
///
/// @param[in] i_target OCMB target
/// @param[in] i_resp_data RESP data
/// @param[in,out] io_rc return code from checking response
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff success
/// @note processes the bad bits based upon the passed in ReturnCode
///
fapi2::ReturnCode read_and_display_normal_training_response(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const std::vector<uint8_t> i_resp_data,
    fapi2::ReturnCode& io_rc)
{
    user_response_msdg l_train_response;

    // Proccesses the response data
    FAPI_TRY( mss::exp::read_normal_training_response(i_target, i_resp_data, l_train_response),
              "Failed read_normal_training_response for %s", mss::c_str(i_target));

    // Displays the training response
    FAPI_INF("%s displaying user response data version %u", mss::c_str(i_target), l_train_response.version_number)
    FAPI_TRY( mss::exp::train::display_normal_info(i_target, l_train_response));

    // Set RC response attributes
    FAPI_TRY(set_rc_resp_attrs(i_target, l_train_response.rc_resp));

    // Handles bad bit error processing
    FAPI_TRY(bad_bit_processing(i_target, l_train_response, io_rc));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief host_fw_phy_init_command_struct structure setup
///
/// @param[in] i_target OCMB target
/// @param[in] i_cmd_data_crc the command data CRC
/// @param[in] i_cmd_length the length of the command present in the data buffer (if any)
/// @param[in] i_phy_init_mode PHY init mode
/// @param[out] o_cmd the command parameters to set
///
fapi2::ReturnCode setup_cmd_params(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint32_t i_cmd_data_crc,
    const uint32_t i_cmd_length,
    const uint8_t i_phy_init_mode,
    host_fw_command_struct& o_cmd)
{
    memset(&o_cmd, 0, sizeof(host_fw_command_struct));
    // Issue full boot mode cmd though EXP-FW REQ buffer
    // Explicit with all of these (including 0 values) to avoid ambiguity
    o_cmd.cmd_id = mss::exp::omi::EXP_FW_DDR_PHY_INIT;

    // Retrieve a unique sequence id for this transaction
    uint32_t l_counter = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_COUNTER, i_target, l_counter));
    o_cmd.request_identifier = l_counter;

    // With cmd_length > 0, data exists in the extended data buffer. Must set cmd_flags to 1.
    o_cmd.cmd_flags = (i_cmd_length > 0) ? 1 : 0;

    o_cmd.cmd_length = i_cmd_length;
    o_cmd.cmd_crc = i_cmd_data_crc;
    o_cmd.host_work_area = 0;
    o_cmd.cmd_work_area = 0;

    // According to the spec Table 5-2, phy_init_mode takes the place of command_argument[0]
    o_cmd.command_argument[0] = i_phy_init_mode;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief user_input_msdg structure setup
/// @param[in] i_target the fapi2 target
/// @param[out] o_phy_params the phy params data struct
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode setup_phy_params(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   user_input_msdg& o_phy_params)
{
    for (const auto l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        fapi2::ReturnCode l_rc;
        const phy_params l_set_phy_params(l_port, l_rc);
        FAPI_TRY(l_rc, "Unable to instantiate phy_params for target %s", mss::c_str(i_target));

        // Set the params by fetching them from the attributes
        FAPI_TRY(l_set_phy_params.set_version_number(o_phy_params));
        FAPI_TRY(l_set_phy_params.setup_DimmType(o_phy_params));
        FAPI_TRY(l_set_phy_params.setup_CsPresent(o_phy_params));
        FAPI_TRY(l_set_phy_params.setup_DramDataWidth(o_phy_params));
        FAPI_TRY(l_set_phy_params.setup_Height3DS(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ActiveDBYTE(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ActiveNibble(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_AddrMirror(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ColumnAddrWidth(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RowAddrWidth(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_SpdCLSupported(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_SpdtAAmin(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_Rank4Mode(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_EncodedQuadCs(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_DDPCompatible(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_TSV8HSupport(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_MRAMSupport(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_MDSSupport(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_NumPStates(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_Frequency(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_PhyOdtImpedance(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_PhyDrvImpedancePU(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_PhyDrvImpedancePD(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_PhySlewRate(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ATxImpedance(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ATxSlewRate(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_CKTxImpedance(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_CKTxSlewRate(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_AlertOdtImpedance(o_phy_params));

        FAPI_TRY(l_set_phy_params.set_RttNom(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RttWr(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RttPark(o_phy_params));

        FAPI_TRY(l_set_phy_params.set_DramDic(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_DramWritePreamble(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_DramReadPreamble(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_PhyEqualization(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_InitVrefDQ(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_InitPhyVref(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_OdtWrMapCs(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_OdtRdMapCs(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_Geardown(o_phy_params));

        // TK need to check if this also includes RC0E
        FAPI_TRY(l_set_phy_params.set_CALatencyAdder(o_phy_params));

        FAPI_TRY(l_set_phy_params.set_BistCALMode(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_BistCAParityLatency(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RcdDic(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RcdVoltageCtrl(o_phy_params));

        // TK check bit ordering here for RcdIBTCtrl and RcdDBDic
        FAPI_TRY(l_set_phy_params.set_RcdIBTCtrl(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_RcdDBDic(o_phy_params));

        FAPI_TRY(l_set_phy_params.set_RcdSlewRate(o_phy_params));

        FAPI_TRY(l_set_phy_params.set_DFIMRL_DDRCLK(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ATxDly_A(o_phy_params));
        FAPI_TRY(l_set_phy_params.set_ATxDly_B(o_phy_params));

        {
            uint32_t l_fw_version = 0;
            FAPI_TRY(mss::get_booted_fw_version(i_target, l_fw_version));

            if(is_new_fw_msdg_supported(l_fw_version))
            {
                FAPI_TRY(l_set_phy_params.set_F1RC1x(o_phy_params));
                FAPI_TRY(l_set_phy_params.set_F1RC2x(o_phy_params));
                FAPI_TRY(l_set_phy_params.set_F1RC3x(o_phy_params));
                FAPI_TRY(l_set_phy_params.set_F1RC4x(o_phy_params));
                FAPI_TRY(l_set_phy_params.set_F1RC5x(o_phy_params));
                FAPI_TRY(l_set_phy_params.set_F1RC6x(o_phy_params));
                FAPI_TRY(l_set_phy_params.set_F1RC7x(o_phy_params));
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Print user_input_msdg structure
/// @param[in] i_target the fapi2 target
/// @param[in] i_phy_params the phy params data struct
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode print_phy_params(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const user_input_msdg& i_phy_params)
{
    // Hostboot doesn't implement FAPI_LAB
#ifndef __HOSTBOOT_MODULE

    for (const auto l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_LAB("// Struct passed to data buffer during EXP_FW_DDR_PHY_INIT for %s", mss::c_str(l_port));
        FAPI_LAB("//     NOTE: Ranks are in terms of the PHY perspective %s", mss::c_str(l_port));
        FAPI_LAB("//           This means ranks 1/2 will be swizzled from the IBM perspective for quad encoded CS mode %s",
                 mss::c_str(l_port));
        FAPI_LAB("struct user_input_msdg m = {");
        // Note: Format here is important. We want the prints to be compilable C code for Microchip
        FAPI_LAB("  .version_number         = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.version_number,
                 mss::c_str(i_target));
        FAPI_LAB("  .DimmType               = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.DimmType,
                 mss::c_str(i_target));
        FAPI_LAB("  .CsPresent              = 0x%04X, // %s", i_phy_params.iv_user_msdg_upto_ver397559.CsPresent,
                 mss::c_str(i_target));
        FAPI_LAB("  .DramDataWidth          = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.DramDataWidth,
                 mss::c_str(i_target));
        FAPI_LAB("  .Height3DS              = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.Height3DS,
                 mss::c_str(i_target));
        FAPI_LAB("  .ActiveDBYTE            = 0x%04X, // %s", i_phy_params.iv_user_msdg_upto_ver397559.ActiveDBYTE,
                 mss::c_str(i_target));
        FAPI_LAB("  .ActiveNibble           = 0x%08X, // %s", i_phy_params.iv_user_msdg_upto_ver397559.ActiveNibble,
                 mss::c_str(i_target));
        FAPI_LAB("  .AddrMirror             = 0x%04X, // %s", i_phy_params.iv_user_msdg_upto_ver397559.AddrMirror,
                 mss::c_str(i_target));
        FAPI_LAB("  .ColumnAddrWidth        = 0x%04X, // %s", i_phy_params.iv_user_msdg_upto_ver397559.ColumnAddrWidth,
                 mss::c_str(i_target));
        FAPI_LAB("  .RowAddrWidth           = 0x%04X, // %s", i_phy_params.iv_user_msdg_upto_ver397559.RowAddrWidth,
                 mss::c_str(i_target));
        FAPI_LAB("  .SpdCLSupported         = 0x%08X, // %s", i_phy_params.iv_user_msdg_upto_ver397559.SpdCLSupported,
                 mss::c_str(i_target));
        FAPI_LAB("  .SpdtAAmin              = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.SpdtAAmin,
                 mss::c_str(i_target));
        FAPI_LAB("  .Rank4Mode              = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.Rank4Mode,
                 mss::c_str(i_target));
        FAPI_LAB("  .EncodedQuadCs          = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.EncodedQuadCs,
                 mss::c_str(i_target));
        FAPI_LAB("  .DDPCompatible          = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.DDPCompatible,
                 mss::c_str(i_target));
        FAPI_LAB("  .TSV8HSupport           = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.TSV8HSupport,
                 mss::c_str(i_target));
        FAPI_LAB("  .MRAMSupport            = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.MRAMSupport,
                 mss::c_str(i_target));
        FAPI_LAB("  .MDSSupport             = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.MDSSupport,
                 mss::c_str(i_target));
        FAPI_LAB("  .NumPStates             = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.NumPStates,
                 mss::c_str(i_target));

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .Frequency[%u]           = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.Frequency[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .PhyOdtImpedance[%u]     = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.PhyOdtImpedance[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .PhyDrvImpedancePU[%u]   = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.PhyDrvImpedancePU[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .PhyDrvImpedancePD[%u]   = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.PhyDrvImpedancePD[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .PhySlewRate[%u]         = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.PhySlewRate[l_pstate], mss::c_str(i_target));
        }

        FAPI_LAB("  .ATxImpedance           = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.ATxImpedance,
                 mss::c_str(i_target));
        FAPI_LAB("  .ATxSlewRate            = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.ATxSlewRate,
                 mss::c_str(i_target));
        FAPI_LAB("  .CKTxImpedance          = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.CKTxImpedance,
                 mss::c_str(i_target));
        FAPI_LAB("  .CKTxSlewRate           = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.CKTxSlewRate,
                 mss::c_str(i_target));
        FAPI_LAB("  .AlertOdtImpedance      = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.AlertOdtImpedance,
                 mss::c_str(i_target));

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttNomR0[%u]        = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttNomR0[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttNomR1[%u]        = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttNomR1[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttNomR2[%u]        = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttNomR2[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttNomR3[%u]        = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttNomR3[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttWrR0[%u]         = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttWrR0[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttWrR1[%u]         = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttWrR1[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttWrR2[%u]         = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttWrR2[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttWrR3[%u]         = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttWrR3[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttParkR0[%u]       = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttParkR0[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttParkR1[%u]       = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttParkR1[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttParkR2[%u]       = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttParkR2[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramRttParkR3[%u]       = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramRttParkR3[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramDic[%u]             = %u, // %s", l_pstate, i_phy_params.iv_user_msdg_upto_ver397559.DramDic[l_pstate],
                     mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramWritePreamble[%u]   = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramWritePreamble[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DramReadPreamble[%u]    = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.DramReadPreamble[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .PhyEqualization[%u]     = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.PhyEqualization[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .InitVrefDQ[%u]          = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.InitVrefDQ[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .InitPhyVref[%u]         = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.InitPhyVref[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .OdtWrMapCs[%u]          = 0x%04X, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.OdtWrMapCs[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .OdtRdMapCs[%u]          = 0x%04X, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.OdtRdMapCs[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .Geardown[%u]            = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.Geardown[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .CALatencyAdder[%u]      = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.CALatencyAdder[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .BistCALMode[%u]         = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.BistCALMode[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .BistCAParityLatency[%u] = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.BistCAParityLatency[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .RcdDic[%u]              = %u, // %s", l_pstate, i_phy_params.iv_user_msdg_upto_ver397559.RcdDic[l_pstate],
                     mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .RcdVoltageCtrl[%u]      = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.RcdVoltageCtrl[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .RcdIBTCtrl[%u]          = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.RcdIBTCtrl[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .RcdDBDic[%u]            = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.RcdDBDic[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .RcdSlewRate[%u]         = %u, // %s", l_pstate,
                     i_phy_params.iv_user_msdg_upto_ver397559.RcdSlewRate[l_pstate], mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            FAPI_LAB("  .DFIMRL_DDRCLK          = %u, // %s", i_phy_params.iv_user_msdg_upto_ver397559.DFIMRL_DDRCLK,
                     mss::c_str(i_target));
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            for(uint8_t l_addr = 0; l_addr < DRAMINIT_NUM_ADDR_DELAYS; ++l_addr)
            {
                FAPI_LAB("  .ATxDly_A[%u][%u]         = 0x%02X, // %s", l_pstate, l_addr,
                         i_phy_params.iv_user_msdg_upto_ver397559.ATxDly_A[l_pstate][l_addr], mss::c_str(i_target));
            }
        }

        for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
        {
            for(uint8_t l_addr = 0; l_addr < DRAMINIT_NUM_ADDR_DELAYS; ++l_addr)
            {
                FAPI_LAB("  .ATxDly_B[%u][%u]         = 0x%02X, // %s", l_pstate, l_addr,
                         i_phy_params.iv_user_msdg_upto_ver397559.ATxDly_B[l_pstate][l_addr], mss::c_str(i_target));
            }
        }

        uint32_t l_fw_version = 0;
        FAPI_TRY(mss::get_booted_fw_version(i_target, l_fw_version));

        if(is_new_fw_msdg_supported(l_fw_version))
        {
            FAPI_LAB("  .F1RC1x      = %u, // %s", i_phy_params.F1RC1x, mss::c_str(i_target));
            FAPI_LAB("  .F1RC2x      = %u, // %s", i_phy_params.F1RC2x, mss::c_str(i_target));
            FAPI_LAB("  .F1RC3x      = %u, // %s", i_phy_params.F1RC3x, mss::c_str(i_target));
            FAPI_LAB("  .F1RC4x      = %u, // %s", i_phy_params.F1RC4x, mss::c_str(i_target));
            FAPI_LAB("  .F1RC5x      = %u, // %s", i_phy_params.F1RC5x, mss::c_str(i_target));
            FAPI_LAB("  .F1RC6x      = %u, // %s", i_phy_params.F1RC6x, mss::c_str(i_target));
            FAPI_LAB("  .F1RC7x      = %u, // %s", i_phy_params.F1RC7x, mss::c_str(i_target));
        }

        FAPI_LAB("};");
    }

fapi_try_exit:
    return fapi2::current_err;

#else

    return fapi2::FAPI2_RC_SUCCESS;

#endif // __HOSTBOOT_MODULE

}

///
/// @brief Initialize user_input_msdg_t and copy to Explorer internal buffer
/// @param[in] i_target an explorer chip
/// @param[out] o_phy_data phy information we want to pass around
/// @return FAPI2_RC_SUCCESS iff okay
/// @note attr for fw_version will select proper initialization at run-time
///
fapi2::ReturnCode init_phy_params(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  mss::exp::phy_param_info& o_phy_info)
{
    user_input_msdg l_phy_params; // not used, just reusing interface below
    return init_phy_params(i_target, l_phy_params, o_phy_info);
}

///
/// @brief Initialize user_input_msdg_t and copy to Explorer internal buffer
/// @param[in] i_target an explorer chip
/// @param[out] o_phy_params phy initialization struct
/// @param[out] o_phy_data phy information we want to pass around
/// @return FAPI2_RC_SUCCESS iff okay
/// @note attr for fw_version will select proper initialization at run-time
///
fapi2::ReturnCode init_phy_params(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  user_input_msdg& o_phy_params,
                                  mss::exp::phy_param_info& o_phy_info)
{
    uint32_t l_fw_version = 0;
    FAPI_TRY(mss::get_booted_fw_version(i_target, l_fw_version));

    FAPI_TRY(mss::exp::setup_phy_params(i_target, o_phy_params),
             "Failed setup_phy_params() for %s", mss::c_str(i_target));

    FAPI_TRY(mss::exp::print_phy_params(i_target, o_phy_params),
             "Failed print_phy_params() for %s", mss::c_str(i_target));

    // Copy the PHY initialization parameters into the internal buffer of Explorer
    FAPI_TRY( mss::exp::ib::putUserInputMsdg(i_target, o_phy_params, o_phy_info.iv_crc),
              "Failed putUserInputMsdg() for %s", mss::c_str(i_target) );

    {
        const bool l_is_new_fw_ver = is_new_fw_msdg_supported(l_fw_version);
        constexpr auto l_new_struct_size = sizeof(o_phy_params);
        constexpr auto l_old_struct_size = sizeof(o_phy_params.iv_user_msdg_upto_ver397559);

        o_phy_info.iv_size = l_is_new_fw_ver ? l_new_struct_size : l_old_struct_size;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if we should log the bad bits
/// @param[in] i_training_rc the ReturnCode from conducting draminit training
/// @return true if we need to log the bad bits based upon the passed in error, otherwise false
///
fapi2::ReturnCode is_bad_bits_logging_needed(const fapi2::ReturnCode& i_training_rc)
{
    // TODO: Zenhub #818: Training callout will need to be updated
    //       Pending additional followup meetings with MCHP
    return uint64_t(i_training_rc) == uint64_t(fapi2::RC_MSS_EXP_DDR_PHY_INIT_TRAINING_FAIL);
}

///
/// @brief Handles the training error
/// @param[in] i_target the fapi2 target
/// @param[in,out] io_training_rc the ReturnCode from conducting draminit training
/// @return FAPI2_RC_SUCCESS iff okay
/// @note will log the error as recovered if it is a training related error
/// Otherwise, it will pass out the error as is
/// This is a helper function and should only be called in hostboot (for cronus we want to always assert out)
///
fapi2::ReturnCode handle_training_error(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        fapi2::ReturnCode& io_training_rc)
{
    // If the error is a TRAINING_FAIL, then we want to log it as recovered and continue
    if(is_bad_bits_logging_needed(io_training_rc))
    {
        fapi2::log_related_error(i_target, io_training_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        io_training_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Now, return the error
    // If we logged a training fail? we've succeeded
    // Otherwise, we're just passing in what the user had given us
    return io_training_rc;
}

} // namespace exp
} // namespace mss
