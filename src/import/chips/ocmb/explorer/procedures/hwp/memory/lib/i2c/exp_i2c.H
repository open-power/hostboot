/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c/exp_i2c.H $ */
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
/// @file exp_i2c.H
/// @brief explorer I2C utility function declarations
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EXP_I2C_H_
#define _MSS_EXP_I2C_H_

#include <fapi2.H>
#include <vector>

#ifdef __PPE__
    #include <exp_consts.H>
#else
    #include <generic/memory/lib/utils/shared/mss_generic_consts.H>
    #include <lib/shared/exp_consts.H>
#endif

namespace mss
{
namespace exp
{
namespace i2c
{

///
/// @brief Poll settings for when a FW_STATUS response shows a non-SUCCESS status
/// @note Allows the caller of poll_fw_status to continue polling if we expect a command to fail
///
enum stop_if_bad_fw_status
{
    STOP_IF_BAD_FW_STATUS,
    CONTINUE_IF_BAD_FW_STATUS,
};

///
/// @brief capture EXP_FW_STATUS data from vector into single uint64_t variable
/// @param[in] i_target the OCMB target
/// @param[in] i_data data to capture from EXP_FW_STATUS
/// @param[out] o_fw_status_data all bytes from EXP_FW_STATUS data
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode capture_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 const std::vector<uint8_t>& i_data,
                                 uint64_t& o_fw_status_data );
namespace check
{

///
/// @brief Check EXP_FW_STATUS for completion/results of previous command
/// @param[in] i_target the OCMB target
/// @param[in] i_cmd_id the command id
/// @param[in] i_cmd_data the command in byte vector format
/// @param[in] i_rsp_data data to check from EXP_FW_STATUS
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode command_result( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const uint8_t i_cmd_id,
                                  const std::vector<uint8_t>& i_cmd_data,
                                  const std::vector<uint8_t>& i_rsp_data );

///
/// @brief Check FW_STATUS for completion/results of FW_BOOT_CONFIG
/// @param[in] i_target the OCMB target
/// @param[in] i_cmd_data the command
/// @param[in] i_rsp_data data to check from EXP_FW_STATUS
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode boot_config( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const std::vector<uint8_t>& i_cmd_data,
                               const std::vector<uint8_t>& i_rsp_data );

}// check

///
/// @brief EXP_FW_STATUS setup helper function - useful for testing
/// @param[out] o_size the size of data
/// @param[out] o_cmd_id the explorer command ID
///
void fw_status_setup(size_t& o_size,
                     std::vector<uint8_t>& o_cmd_id);

#ifndef __PPE__
    ///
    /// @brief EXP_FW_BYPASS_4SEC_TIMEOUT setup helper function
    /// @param[out] o_cmd_id the explorer command ID
    ///
    void fw_bypass_download_window_setup(std::vector<uint8_t>& o_cmd_id);
#endif

///
/// @brief get EXP_FW_STATUS bytes
/// @param[in] i_target the OCMB target
/// @param[out] o_data the return data from FW_STATUS command
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode get_fw_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                std::vector<uint8_t>& o_data);

///
/// @brief Helper function to check FW_STATUS loop termination, for unit testing
/// @param[in] i_target the OCMB target
/// @param[in] i_data response data from FW_STATUS command
/// @param[in] i_stop_if_bad_status set to STOP if polling should stop if FW_STATUS returns a bad status value (default CONTINUE)
/// @param[out] o_done true if we should break out of the loop, false otherwise
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode fw_status_loop_done(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      const std::vector<uint8_t>& i_data,
                                      const stop_if_bad_fw_status i_stop_if_bad_status,
                                      bool& o_done);

///
/// @brief Poll EXP_FW_STATUS command
/// @param[in] i_target the OCMB target
/// @param[in] i_delay delay between polls
/// @param[in] i_loops number of polling loops to perform
/// @param[out] o_data result of final FW_STATUS command sent
/// @param[in] i_stop_if_bad_status set to CONTINUE if polling should continue if FW_STATUS returns a bad status value (default STOP)
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode poll_fw_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 const uint64_t i_delay,
                                 const uint64_t i_loops,
                                 std::vector<uint8_t>& o_data,
                                 const stop_if_bad_fw_status i_stop_if_bad_status = STOP_IF_BAD_FW_STATUS);

#ifndef __PPE__
///
/// @brief EXP_FW_BOOT_CONFIG setup
/// @param[in,out] io_data the data to go to boot config
///
void boot_config_setup(std::vector<uint8_t>& io_data);

///
/// @brief EXP_FW_BOOT_CONFIG
/// @param[in] i_target the OCMB target
/// @param[in,out] io_data the data to write
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode boot_config(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              std::vector<uint8_t>& io_data);

///
/// @brief Check that the FW status code returns a busy status (expected for exp_omi_train)
///
/// @param[in] i_target OCMB
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff busy and no error code, else, error code
///
fapi2::ReturnCode check_fw_status_busy(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Checks if the I2C interface returns an ACK
/// @param[in] i_target the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode is_ready(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief EXP_FW_BYPASS_4SEC_TIMEOUT
/// @param[in] i_target the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode fw_bypass_download_window(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Helper function for exp_check_for_ready
/// @param[in] i_target the controller
/// @param[in] i_poll_count the number of times to run the fw_status command (default = 200)
/// @param[in] i_delay delay in ns between fw_status command attempts (default = 1ms)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode exp_check_for_ready_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_poll_count = 200,
        const uint64_t i_delay = mss::DELAY_1MS);
#endif

///
/// @brief Perform a register write operation on the given OCMB chip
/// @param[in] i_target the OCMB target
/// @param[in] i_addr   The translated address on the OCMB chip
/// @param[in] i_data_buffer buffer of data we want to write to the register
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode fw_reg_write(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const uint32_t i_addr,
                               const fapi2::buffer<uint32_t>& i_data_buffer);

///
/// @brief Perform a register write operation on the given OCMB chip
/// @param[in] i_target the OCMB target
/// @param[in] i_addr   The translated address on the OCMB chip
/// @param[in] o_data_buffer buffer of data we will write the contents of the register to
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode fw_reg_read(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              const uint32_t i_addr,
                              fapi2::buffer<uint32_t>& o_data_buffer);

///
/// @brief Perform a register write operation on the given OCMB chip
/// @param[in] i_addr   The raw address that needs to be translated to IBM scom addr
/// @param[in] i_side   LHS or RHS of the IBM i2c scom. IBM addresses expect 64 bits of
///                     data returned from them so we must have a LHS and a RHS which is offset
///                     by 4 bytes. This is because the OCMB is a 32 bit architecture
/// @return uint32 of translated address
///
uint32_t trans_ibm_i2c_scom_addr(const uint32_t i_addr,
                                 const addrSide i_side);

///
/// @brief Perform a register write operation on the given OCMB chip
/// @param[in] i_addr   The raw address that needs to be translated to Microchip scom addr
/// @return uint32 of translated address
///
uint32_t trans_micro_i2c_scom_addr(const uint32_t i_addr);

#ifndef __PPE__
///
/// @brief Issue the DOWNLOAD command to the given OCMB chip
/// @param[in] i_target the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode fw_download(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief FW_TWI_FFE_SETTINGS setup
/// @param[in,out] io_data the data to go to the command
///
void ffe_settings_setup(std::vector<uint8_t>& io_data);

///
/// @brief FW_TWI_FFE_SETTINGS
/// @param[in] i_target the OCMB target
/// @param[in] i_data the data to write
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode send_ffe_settings(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const std::vector<uint8_t>& i_data);
#endif

}// i2c
}// exp
}// mss

#endif
