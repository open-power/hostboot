/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c/exp_i2c.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
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
/// @brief Assert/callout settings for when a FW_STATUS response shows a non-SUCCESS status
/// @note Allows the caller of check::status_code or fw_status to suppress asserts if we expect a command to fail
///
enum assert_if_bad_fw_status
{
    ASSERT_IF_BAD_FW_STATUS,
    NO_ASSERT_IF_BAD_FW_STATUS,
};

///
/// @brief Assert/callout settings for when a FW_STATUS response shows a BUSY status
/// @note Allows the caller of fw_status to suppress asserts if the polling loop ends with a BUSY state
///
enum assert_if_busy_fw_status
{
    ASSERT_IF_BUSY_FW_STATUS,
    NO_ASSERT_IF_BUSY_FW_STATUS,
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
/// @brief Checks the I2c explorer status codes
/// @param[in] i_target the OCMB target
/// @param[in] i_cmd_id the command ID
/// @param[in] i_data data to check from EXP_FW_STATUS
/// @param[out] o_busy true if explorer returns FW_BUSY status, false otherwise
/// @param[in] i_assert set to ASSERT if function should assert if FW_STATUS returns a bad status value (default ASSERT)
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode status_code( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const uint8_t i_cmd_id,
                               const std::vector<uint8_t>& i_data,
                               bool& o_busy,
                               const assert_if_bad_fw_status i_assert = ASSERT_IF_BAD_FW_STATUS );

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
/// @param[in] i_busy busy flag from check::status_code
/// @param[in] i_boot_stage boot_stage output from status::get_boot_stage
/// @return true if we should break out of the loop, false otherwise
///
bool fw_status_loop_done(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                         const bool i_busy,
                         const uint8_t i_boot_stage);

///
/// @brief EXP_FW_STATUS
/// @param[in] i_target the OCMB target
/// @param[in] i_delay delay between polls
/// @param[in] i_loops number of polling loops to perform
/// @param[in] i_assert_if_busy set to ASSERT if function should assert if polling ends with BUSY state (default ASSERT)
/// @param[in] i_assert_if_bad_status set to ASSERT if function should assert if FW_STATUS returns a bad status value (default ASSERT)
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode fw_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                            const uint64_t i_delay,
                            const uint64_t i_loops,
                            const assert_if_busy_fw_status i_assert_if_busy = ASSERT_IF_BUSY_FW_STATUS,
                            const assert_if_bad_fw_status i_assert_if_bad_status = ASSERT_IF_BAD_FW_STATUS);

#ifndef __PPE__
///
/// @brief EXP_FW_BOOT_CONFIG setup
/// @param[in,out] io_data the data to go to boot config
///
void boot_config_setup(std::vector<uint8_t>& io_data);

///
/// @brief EXP_FW_BOOT_CONFIG
/// @param[in] i_target the OCMB target
/// @param[in] i_data the data to write
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode boot_config(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              const std::vector<uint8_t>& i_data);

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
