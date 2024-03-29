/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c/exp_i2c.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2024                        */
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
/// @file exp_i2c.C
/// @brief explorer I2C utility function implementation
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hw/ppe

#include <i2c_access.H>

// reused TARGTIDFORMAT defined in generic/memory/lib/utils/mss_generic_check.H

#ifdef __PPE__
    #include <exp_i2c.H>
    #include <exp_i2c_fields.H>
    #include <endian_utils.H>
    //Macro
    #define MSSTARGID i_target.get()
#else
    #include <lib/i2c/exp_i2c.H>
    #include <generic/memory/lib/utils/poll.H>
    #include <generic/memory/lib/utils/find.H>
    #include <lib/i2c/exp_i2c_fields.H>
    #include <generic/memory/lib/utils/pos.H>
    #include <generic/memory/lib/utils/endian_utils.H>
    #include <mss_explorer_attribute_setters.H>
    //Macro
    #define MSSTARGID mss::c_str(i_target)
#endif

namespace mss
{
namespace exp
{
namespace i2c
{

///
/// @brief convert data from vector of bytes into single uint64_t variable
/// @param[in] i_data data in vector of bytes
/// @return uint64_t variable
///
uint64_t convert_to_long(const std::vector<uint8_t>& i_data)
{
    uint64_t o_data_var = 0;

    for( const auto l_byte : i_data )
    {
        o_data_var <<= BITS_PER_BYTE;
        o_data_var |= l_byte;
    }

    return o_data_var;
}

///
/// @brief capture EXP_FW_STATUS data from vector into single uint64_t variable
/// @param[in] i_target the OCMB target
/// @param[in] i_data data to capture from EXP_FW_STATUS
/// @param[out] o_fw_status_data all bytes from EXP_FW_STATUS data
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode capture_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 const std::vector<uint8_t>& i_data,
                                 uint64_t& o_fw_status_data )
{
    // Commenting out the below code due to the "Lab debug" section in the fw_status function.
    // Because we continue polling if FW_STATUS doesn't return, it's possible that we can get
    // here from fw_status without ever filling up i_data
    // TK #622 : update once EDBC-671 is resolved
#if 0
    FAPI_ASSERT ((i_data.size() == FW_STATUS_BYTE_LEN),
                 fapi2::MSS_EXP_I2C_FW_STATUS_INVALID_SIZE().
                 set_OCMB_TARGET(i_target).
                 set_STATUS_CODE_SIZE(i_data.size()),
                 "Data length returned from FW_STATUS was incorrect when attempting to print to error log. (%d when expecting %d)"
                 TARGTIDFORMAT,
                 i_data.size(), FW_STATUS_BYTE_LEN , MSSTARGID);
#endif
    o_fw_status_data = convert_to_long(i_data);

    return fapi2::FAPI2_RC_SUCCESS;
#if 0
fapi_try_exit:
    return fapi2::current_err;
#endif
}

///
/// @brief EXP_FW_STATUS setup helper function - useful for testing
/// @param[out] o_size the size of data
/// @param[out] o_cmd_id the explorer command ID
///
void fw_status_setup(size_t& o_size,
                     std::vector<uint8_t>& o_cmd_id)
{
    o_size = FW_STATUS_BYTE_LEN;
    o_cmd_id.clear();
    o_cmd_id.push_back(FW_STATUS);
}

#ifndef __PPE__
///
/// @brief EXP_FW_BYPASS_4SEC_TIMEOUT setup helper function
/// @param[out] o_cmd_id the explorer command ID
///
void fw_bypass_download_window_setup(std::vector<uint8_t>& o_cmd_id)
{
    o_cmd_id.clear();
    o_cmd_id.push_back(FW_BYPASS_4SEC_TIMEOUT);
}
#endif

///
/// @brief get EXP_FW_STATUS bytes
/// @param[in] i_target the OCMB target
/// @param[out] o_data the return data from FW_STATUS command
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode get_fw_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                std::vector<uint8_t>& o_data)
{
    // Retrieve setup data
    size_t l_size = 0;
    std::vector<uint8_t> l_cmd_id;
    fw_status_setup(l_size, l_cmd_id);

    // Get data and check for errors
    FAPI_TRY(fapi2::getI2c(i_target, l_size, l_cmd_id, o_data),
             TARGTIDFORMAT " Failed getI2c for FW_STATUS command", MSSTARGID);
#ifndef __PPE__
    // PPE plat supports a maximum of 4 arguments to FAPI_DBG so this statement must be excluded
    FAPI_DBG( "status returned ( 5 bytes ) : 0x%.02X 0x%.02X 0x%.02X 0x%.02X 0x%.02X",
              o_data[0], o_data[1] , o_data[2], o_data[3], o_data[4]);
#endif
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Save FW API version into attribute
/// @param[in] i_target the OCMB target
/// @param[in] i_data response data from FW_STATUS command
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode save_fw_api_version(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      const std::vector<uint8_t>& i_data)
{
    uint8_t l_version = 0;

    FAPI_TRY(status::get_fw_api_version(i_target, i_data, l_version));
    FAPI_INF( TARGTIDFORMAT " Explorer I2C FW API version: %d",
              MSSTARGID, l_version);

#ifndef __PPE__
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_FW_API_VERSION, i_target, l_version));
#endif

fapi_try_exit:
    return fapi2::current_err;
}

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
                                      bool& o_done)
{
    constexpr uint8_t EXPECTED_BOOT_STAGE = boot_stages::RUNTIME_FW;

    uint8_t l_status = 0;
    uint8_t l_boot_stage = 0;

    FAPI_TRY( status::get_status_code(i_target, i_data, l_status) );
    FAPI_TRY( status::get_boot_stage(i_target, i_data, l_boot_stage) );

    if (l_status == status_codes::FW_BUSY)
    {
        FAPI_DBG( TARGTIDFORMAT " returned FW_BUSY status. Retrying...", MSSTARGID );
        o_done = false;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    if (l_boot_stage != EXPECTED_BOOT_STAGE)
    {
        FAPI_DBG( TARGTIDFORMAT " returned non-RUNTIME boot stage (0x%02x). Retrying...",
                  MSSTARGID, l_boot_stage );
        o_done = false;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    if ((l_status != status_codes::I2C_SUCCESS) &&
        (i_stop_if_bad_status == CONTINUE_IF_BAD_FW_STATUS))
    {
        o_done = false;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    o_done = true;
fapi_try_exit:
    return fapi2::current_err;
}

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
                                 const stop_if_bad_fw_status i_stop_if_bad_status)
{
    o_data.clear();

    // So, why aren't we using the memory team's polling API?
    // This is a base function that will be utilized by the platform code
    // As such, we don't want to pull in more libraries than we need to: it would cause extra dependencies
    // So, we're decomposing the polling library below
    fapi2::ReturnCode l_fw_status_rc = fapi2::FAPI2_RC_SUCCESS;
    uint64_t l_loop = 0;

    // Loop until we max our our loop count or get a non-busy response
    for(; l_loop < i_loops; ++l_loop)
    {
        // These i2c transactions can timeout during check_for_ready and OMI training
        // so remove FAPI_TRY around get_fw_status to avoid bailing out of polling loop
        l_fw_status_rc = get_fw_status(i_target, o_data);

        if (l_fw_status_rc == fapi2::FAPI2_RC_SUCCESS)
        {
            bool l_loop_done = false;
            FAPI_TRY(fw_status_loop_done(i_target, o_data, i_stop_if_bad_status, l_loop_done));

            if (l_loop_done)
            {
                break;
            }
        }
        else
        {
            FAPI_ERR(TARGTIDFORMAT " got an i2c timeout during FW_STATUS loop %u. Ignoring and continuing...",
                     MSSTARGID , l_loop);
            // Need to reset fapi2::current_err so we don't return the ignored error
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY( fapi2::delay( i_delay, 200) );
    }

    // Check the RC from the last get_fw_status and if it's bad we'll log it as recovered
    // then return an RC specific to the FW_STATUS loop
    if (l_fw_status_rc != fapi2::FAPI2_RC_SUCCESS)
    {
#ifndef __PPE__
        fapi2::logError(l_fw_status_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
#endif
        FAPI_ASSERT(false,
                    fapi2::MSS_EXP_FW_STATUS_POLLING_TIMEOUT().
                    set_OCMB_TARGET(i_target),
                    TARGTIDFORMAT " failed to reply over i2c during FW_STATUS loop", MSSTARGID);
    }

    FAPI_DBG(TARGTIDFORMAT " stopped on loop %u/%u", MSSTARGID , l_loop, i_loops);

fapi_try_exit:
    return fapi2::current_err;
}

#ifndef __PPE__
///
/// @brief EXP_FW_BOOT_CONFIG setup
/// @param[in,out] io_data the data to go to boot config
///
void boot_config_setup(std::vector<uint8_t>& io_data)
{
    // Need data length as well - boot config can only ever be written
    io_data.insert(io_data.begin(), FW_BOOT_CONFIG_BYTE_LEN);

    // Then add the command
    io_data.insert(io_data.begin(), FW_BOOT_CONFIG);
}

///
/// @brief EXP_FW_BOOT_CONFIG
/// @param[in] i_target the OCMB target
/// @param[in,out] io_data the data to write
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode boot_config(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              std::vector<uint8_t>& io_data)
{
    // Retrieve setup data
    boot_config_setup(io_data);

    // Send the command
    FAPI_TRY(fapi2::putI2c(i_target, io_data));


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if the I2C interface returns an ACK
/// @param[in] i_target the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode is_ready(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    // We send a simple but valid command to poll the I2C
    // Arbitrarily send an EXP_FW_STATUS command id
    size_t l_size = 0;
    std::vector<uint8_t> l_cmd_id;
    fw_status_setup(l_size, l_cmd_id);

    // We'll see FAPI2_RC_SUCCESS if the I2C returns an ACK.
    // We just ignore the data
    std::vector<uint8_t> l_data;
    return fapi2::getI2c(i_target, l_size, l_cmd_id, l_data);
}

///
/// @brief EXP_FW_BYPASS_4SEC_TIMEOUT
/// @param[in] i_target the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode fw_bypass_download_window(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    std::vector<uint8_t> l_cmd_id;
    fw_bypass_download_window_setup(l_cmd_id);

    constexpr uint64_t MAX_LOOPS = 3;

    // WORKAROUND: Loop a few times on this because sometimes Explorer doesn't ACK
    for (uint64_t l_loop = 0; l_loop < MAX_LOOPS; ++l_loop)
    {
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        // We'll see FAPI2_RC_SUCCESS if the I2C returns an ACK.
        l_rc = fapi2::putI2c(i_target, l_cmd_id);

        if (l_rc == fapi2::FAPI2_RC_SUCCESS)
        {
            return l_rc;
        }

        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        FAPI_TRY( fapi2::delay( mss::DELAY_1MS, 200) );
    }

    // Hide the bad RC if this completely fails, and we'll wait through the remainder of the window.
    FAPI_ERR(TARGTIDFORMAT " Failed to send EXP_FW_BYPASS_4SEC_TIMEOUT command."
             "This may cause FW_STATUS loop to timeout later",
             MSSTARGID);
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for exp_check_for_ready
/// @param[in] i_target the controller
/// @param[in] i_poll_count the number of times to run the fw_status command (default = 200)
/// @param[in] i_delay delay in ns between fw_status command attempts (default = 1ms)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode exp_check_for_ready_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_poll_count,
        const uint64_t i_delay)
{
    std::vector<uint8_t> l_data;
    uint8_t l_status = 0;
    uint8_t l_boot_stage = 0;
    uint64_t l_fw_status_data = 0;
    const auto& l_proc = i_target.getParent<fapi2::TARGET_TYPE_OMI>()
                         .getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // Using using default parameters from class, with overrides for delay and poll_count
    mss::poll_parameters l_poll_params(DELAY_10NS,
                                       200,
                                       i_delay,
                                       200,
                                       i_poll_count);

    // From MSCC explorer firmware arch spec
    // 4.1.5: After power-up, the Explorer Chip will respond with NACK to all incoming I2C requests
    // from the HOST until the I2C slave interface is ready to receive commands.
    // Here, we are checking if the Explorer reset ok
    FAPI_ASSERT( mss::poll(i_target, l_poll_params, [i_target]()->bool
    {
        return mss::exp::i2c::is_ready(i_target) == fapi2::FAPI2_RC_SUCCESS;
    }),
    fapi2::MSS_EXP_I2C_POLLING_TIMEOUT_RESET().
    set_OCMB_TARGET(i_target).
    set_PROC_TARGET(l_proc),
    "Failed to see an ACK from I2C -- polling timeout coming out of reset %s",
    mss::c_str(i_target) );

    // If we're already in RUNTIME_FW stage, due to fuse settings or running procedures manually,
    // we can (and should) skip the bypass and polling here
    FAPI_TRY( get_fw_status(i_target, l_data) );
    FAPI_TRY( status::get_boot_stage(i_target, l_data, l_boot_stage) );

    if (l_boot_stage == boot_stages::RUNTIME_FW)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // MSCC explorer firmware arch spec 4.1.6.5
    // Boot ROM will wait 4 secs and will proceed for normal boot operation. During this time,
    // I2C channel will be disabled and Host will see NACK on the bus for subsequent EXP_FW_STATUS
    // command.
    // Sending FW_BYPASS_4SEC_TIMEOUT command will bypass the 4 secs
    // and immediately load the runtime firmware.
    FAPI_TRY(fw_bypass_download_window(i_target));

    // Loop again until we get an ACK from i2c
    // EXP reset OK
    FAPI_ASSERT( mss::poll(i_target, l_poll_params, [i_target]()->bool
    {
        return mss::exp::i2c::is_ready(i_target) == fapi2::FAPI2_RC_SUCCESS;
    }),
    fapi2::MSS_EXP_I2C_POLLING_TIMEOUT_BOOT_ROM().
    set_OCMB_TARGET(i_target),
    "Failed to see an ACK from I2C -- polling timeout booting FW %s",
    mss::c_str(i_target) );

    // Now poll the EXP_FW_STATUS command until it returns SUCCESS and RUNTIME_FW
    FAPI_TRY(poll_fw_status(i_target, i_delay, i_poll_count, l_data));

    FAPI_TRY( status::get_status_code(i_target, l_data, l_status) );
    FAPI_TRY( status::get_boot_stage(i_target, l_data, l_boot_stage) );

    FAPI_TRY(capture_status(i_target, l_data, l_fw_status_data));

    // Check that Explorer is not still in FW_BUSY state
    FAPI_ASSERT( (l_status != status_codes::FW_BUSY),
                 fapi2::MSS_EXP_I2C_FW_STATUS_BUSY().
                 set_OCMB_TARGET(i_target).
                 set_CMD_ID(FW_STATUS).
                 set_STATUS_DATA(l_fw_status_data).
                 set_EXP_ACTIVE_LOG_SIZE(4096),
                 "Polling timeout on FW_STATUS command (still FW_BUSY) for " TARGTIDFORMAT,
                 MSSTARGID );
    // Check that Explorer is in RUNTIME_FW boot stage
    FAPI_ASSERT( (l_boot_stage == boot_stages::RUNTIME_FW),
                 fapi2::MSS_EXP_I2C_WRONG_BOOT_STAGE().
                 set_OCMB_TARGET(i_target).
                 set_BOOT_STAGE(l_boot_stage).
                 set_EXPECTED_BOOT_STAGE(boot_stages::RUNTIME_FW).
                 set_STATUS_DATA(l_fw_status_data),
                 "Polling timeout on FW_STATUS command (wrong boot stage: 0x%01x, expected 0x%01x) for " TARGTIDFORMAT,
                 l_boot_stage, boot_stages::RUNTIME_FW, MSSTARGID );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

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
                               const fapi2::buffer<uint32_t>& i_data_buffer)
{
    // create byte vector that will hold command bytes in sequence that will do the scom
    std::vector<uint8_t> l_cmd_vector;
    std::vector<uint8_t> l_byte_vector;
    std::vector<uint8_t> l_data;

    uint32_t l_input_data = static_cast<uint32_t>(i_data_buffer);

    // Start building the cmd vector for the write operation
    l_cmd_vector.push_back(FW_REG_WRITE);              // Byte 0 = 0x05 (FW_REG_WRITE)
    l_cmd_vector.push_back(FW_WRITE_REG_DATA_SIZE);    // Byte 1 = 0x08 (FW_SCOM_DATA_SIZE)

    // i_addr and i_data_buffer were converted to LE above so we can
    // write them directly to the cmd_vector in the same order they
    // currently are
    // Byte 2:5 = Address
    forceBE(i_addr, l_byte_vector);

    for(const auto l_byte : l_byte_vector)
    {
        l_cmd_vector.push_back(l_byte);
    }

    l_byte_vector.clear();
    forceBE(l_input_data, l_byte_vector);

    // Byte 6:9 = Data
    for(const auto l_byte : l_byte_vector)
    {
        l_cmd_vector.push_back(l_byte);
    }

    // Use fapi2 putI2c interface to execute command
    FAPI_TRY(fapi2::putI2c(i_target, l_cmd_vector),
             "I2C FW_REG_WRITE op failed to write to 0x%.8X on OCMB w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));

    // Check status of operation
    FAPI_TRY(poll_fw_status(i_target, DELAY_1MS, 20, l_data));
    FAPI_TRY(check::command_result(i_target, FW_REG_WRITE, l_cmd_vector, l_data),
             "Invalid Status after FW_REG_WRITE operation to 0x%.8X on OCMB w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register write operation on the given OCMB chip
/// @param[in] i_target the OCMB target
/// @param[in] i_addr   The translated address on the OCMB chip
/// @param[in] o_data_buffer buffer of data we will write the contents of the register to
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode fw_reg_read(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              const uint32_t i_addr,
                              fapi2::buffer<uint32_t>& o_data_buffer)
{
    // create byte vector that will hold command bytes in sequence that will do the scom
    std::vector<uint8_t> l_cmd_vector;
    std::vector<uint8_t> l_byte_vector;
    std::vector<uint8_t> l_data;

    // Flush o_data_buffer w/ all 0's to avoid stale data
    o_data_buffer.flush<0>();

    // Force the address to be BE
    forceBE(i_addr, l_byte_vector);

    // Build the cmd vector for the Read
    l_cmd_vector.push_back(FW_REG_ADDR_LATCH);         // Byte 0 = 0x03 (FW_REG_ADDR_LATCH)
    l_cmd_vector.push_back(FW_REG_ADDR_LATCH_SIZE);    // Byte 1 = 0x04 (FW_REG_ADDR_LATCH_SIZE)

    // i_addr was converted to BE above so we can write it
    // directly to the cmd_vector in the same order it
    // currently is in
    // Byte 2:5 = Address

    for(const auto l_byte : l_byte_vector)
    {
        l_cmd_vector.push_back(l_byte);
    }

    // Use fapi2 putI2c interface to execute command
    FAPI_TRY(fapi2::putI2c(i_target, l_cmd_vector),
             "putI2c returned error for FW_REG_ADDR_LATCH operation to 0x%.8X on OCMB w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));

    // Check i2c status after operation
    FAPI_TRY(poll_fw_status(i_target, DELAY_1MS, 20, l_data));
    FAPI_TRY(check::command_result(i_target, FW_REG_ADDR_LATCH, l_cmd_vector, l_data),
             "Invalid Status after FW_REG_ADDR_LATCH operation to 0x%.8X on OCMB w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));


    // Clear out cmd vector as i2c op is complete and we must prepare for next
    l_cmd_vector.clear();

    // Cmd vector is a single byte with FW_REG_READ code
    l_cmd_vector.push_back(FW_REG_READ); // Byte 0 = 0x04 (FW_REG_READ)
    l_cmd_vector.push_back(0x4); // length of read

    // i_addr was converted to BE above so we can write it
    // directly to the cmd_vector in the same order it
    // currently is in
    // Byte 2:5 = Address
    // NOTE: Techinically Explorer says this is not needed but was found
    // to be needed in Gemini and Explorer says they don't care why the
    // next 4 bytes are so we will fill it in regardless
    for(const auto l_byte : l_byte_vector)
    {
        l_cmd_vector.push_back(l_byte);
    }

    // Clear out the tmp_vector because we will re-use as the read buffer
    l_byte_vector.clear();

    // Use fapi2 getI2c interface to execute command
    FAPI_TRY(fapi2::getI2c(i_target, FW_I2C_SCOM_READ_SIZE,  l_cmd_vector, l_byte_vector),
             "getI2c returned error for FW_REG_READ operation to 0x%.8X on OCMB w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));

    // The first byte returned should be the size of the remaining data
    // We requested FW_REG_ADDR_LATCH_SIZE bytes so that is what we
    // expect to see as the first byte.
    FAPI_ASSERT(  (l_byte_vector.front() == FW_REG_ADDR_LATCH_SIZE),
                  fapi2::I2C_GET_SCOM_INVALID_READ_SIZE()
                  .set_OCMB_TARGET(i_target)
                  .set_ADDRESS(i_addr)
                  .set_SIZE_RETURNED(l_byte_vector[0])
                  .set_SIZE_REQUESTED(FW_REG_ADDR_LATCH_SIZE),
                  "First byte of read data was expected to be 0x%lx but byte read = 0x%x",
                  FW_REG_ADDR_LATCH_SIZE, l_byte_vector[0] );

    // Check i2c status after operation
    FAPI_TRY(poll_fw_status(i_target, DELAY_1MS, 20, l_data));
    FAPI_TRY(check::command_result(i_target, FW_REG_READ, l_cmd_vector, l_data),
             "Invalid Status after FW_REG_READ operation to 0x%.8X on OCMB w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));

    // Build uint32_t from bytes 1-4 of the returned data. Bytes are
    // returned in BE so no translation neccesary. Faster to just access
    // the 4 bytes and shift than to perform vector operations to pop off front
    // entry and convert vector to uint32.
    o_data_buffer = ( l_byte_vector[1] << 24 |
                      l_byte_vector[2] << 16 |
                      l_byte_vector[3] << 8 |
                      l_byte_vector[4]);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register write operation on the given OCMB chip
/// @param[in] i_addr   The raw address that needs to be translated to IBM scom addr
/// @param[in] i_side   LHS or RHS of the IBM i2c scom. IBM addresses expect 64 bits of
///                     data returned from them so we must have a LHS and a RHS which is offset
///                     by 4 bytes. This is because the OCMB is a 32 bit architecture
/// @return uint32 of translated address
///
uint32_t trans_ibm_i2c_scom_addr(const uint32_t i_addr,
                                 const addrSide i_side)
{
    return (i_side == LHS) ?
           ((LAST_THREE_BYTES_MASK & i_addr) << OCMB_ADDR_SHIFT) | IBM_SCOM_OFFSET_LHS | OCMB_UNCACHED_OFFSET :
           ((LAST_THREE_BYTES_MASK & i_addr) << OCMB_ADDR_SHIFT) | IBM_SCOM_OFFSET_RHS | OCMB_UNCACHED_OFFSET ;
}

///
/// @brief Perform a register write operation on the given OCMB chip
/// @param[in] i_addr   The raw address that needs to be translated to Microchip scom addr
/// @return uint32 of translated address
///
uint32_t trans_micro_i2c_scom_addr(const uint32_t i_addr)
{
    return (i_addr | OCMB_UNCACHED_OFFSET) ;
}

#ifndef __PPE__

///
/// @brief Issue the DOWNLOAD command to the given OCMB chip
/// @param[in] i_target the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode fw_download(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    // create byte vector that will hold command bytes in sequence that will do the scom
    std::vector<uint8_t> l_download_cmd;
    std::vector<uint8_t> l_status_data;
    uint8_t              l_boot_stage = 0;

    //create variable to hold EXP_FW_STATUS data
    uint64_t l_fw_status_data = 0;

    // Read status to get the current boot_stage
    FAPI_TRY(get_fw_status(i_target, l_status_data));

    // Extract the boot_stage value
    FAPI_TRY(status::get_boot_stage(i_target, l_status_data, l_boot_stage));
    FAPI_TRY(capture_status(i_target, l_status_data, l_fw_status_data));

    // Check that we are in the BOOT_ROM or FW_UPGRADE stage of booting.
    // The FW_DOWNLOAD command can only be sent in one of these modes
    // (see table 13-1, pboot flowchart in FW arch doc for more info)
    // Note that a fail here means we've missed our window of opportunity to
    // perform this kind of FW update (the only other boot stage is RUNTIME_FW)
    // TK this function is not supported in HB yet, so we should revisit to
    // make sure we handle this properly when we add that support.
    FAPI_ASSERT(((l_boot_stage == BOOT_ROM_STAGE) ||
                 (l_boot_stage == FW_UPGRADE_MODE)),
                fapi2::MSS_EXP_I2C_FW_DOWNLOAD_INVALID_STATE().
                set_OCMB_TARGET(i_target).
                set_BOOT_STAGE(l_boot_stage).
                set_STATUS_DATA(l_fw_status_data),
                "Invalid boot stage[0x%02x] for FW_DOWNLOAD command on %s",
                l_boot_stage, mss::c_str(i_target));

    // Start building the cmd vector for the write operation
    // Byte 0 = 0x06 (FW_DOWNLOAD)
    l_download_cmd.push_back(FW_DOWNLOAD);

    // Use fapi2 putI2c interface to execute command
    FAPI_TRY(fapi2::putI2c(i_target, l_download_cmd),
             "I2C FW_DOWNLOAD op failed to send FW_DOWNLOAD cmd to %s",
             mss::c_str(i_target));

    // NOTE: The EXP_FW_STATUS command will not work after sending the
    //       EXP_FW_DOWNLOAD because we will be in TWI mode from this point on.

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief FW_TWI_FFE_SETTINGS setup
/// @param[in,out] io_data the data to go to the command
///
void ffe_settings_setup(std::vector<uint8_t>& io_data)
{

    // Need data length as well - ffe_settings can only ever be written
    io_data.insert(io_data.begin(), FW_TWI_FFE_SETTINGS_BYTE_LEN);

    // Then add the command
    io_data.insert(io_data.begin(), FW_TWI_FFE_SETTINGS);
}

///
/// @brief FW_TWI_FFE_SETTINGS
/// @param[in] i_target the OCMB target
/// @param[in] i_data the data to write
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode send_ffe_settings(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const std::vector<uint8_t>& i_data)
{
    // Retrieve setup data
    std::vector<uint8_t> l_configured_data(i_data);
    ffe_settings_setup(l_configured_data);

    // Send the command
    FAPI_TRY(fapi2::putI2c(i_target, l_configured_data));

fapi_try_exit:
    return fapi2::current_err;
}

#endif

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
                                  const std::vector<uint8_t>& i_rsp_data )
{
    uint8_t l_status = 0;
    uint64_t l_fw_status_data = 0;
    uint64_t l_cmd_data = convert_to_long(i_cmd_data);

    FAPI_TRY(status::get_status_code(i_target, i_rsp_data, l_status));
    FAPI_TRY(capture_status(i_target, i_rsp_data, l_fw_status_data));

    // Check that Explorer is not still in FW_BUSY state
    FAPI_ASSERT( (l_status != status_codes::FW_BUSY),
                 fapi2::MSS_EXP_I2C_FW_STATUS_BUSY().
                 set_OCMB_TARGET(i_target).
                 set_CMD_ID(i_cmd_id).
                 set_COMMAND(l_cmd_data).
                 set_STATUS_DATA(l_fw_status_data).
                 set_EXP_ACTIVE_LOG_SIZE(4096),
                 "command_result> Polling timeout on command 0x%02X (still FW_BUSY) for " TARGTIDFORMAT,
                 i_cmd_id, MSSTARGID );
    // Check that Explorer gave a successful return code
    FAPI_ASSERT( (l_status == status_codes::I2C_SUCCESS),
                 fapi2::MSS_EXP_I2C_CMD_FAIL().
                 set_OCMB_TARGET(i_target).
                 set_CMD_ID(i_cmd_id).
                 set_COMMAND(l_cmd_data).
                 set_STATUS(l_status).
                 set_STATUS_DATA(l_fw_status_data).
                 set_EXP_ACTIVE_LOG_SIZE(4096),
                 "Failing RC (0x%016X, RC 0x%02X) from command 0x%02X for " TARGTIDFORMAT,
                 l_fw_status_data, l_status, i_cmd_id, MSSTARGID );

fapi_try_exit:
    return fapi2::current_err;
}

#ifndef __PPE__

///
/// @brief Check FW_STATUS for completion/results of FW_BOOT_CONFIG
/// @param[in] i_target the OCMB target
/// @param[in] i_cmd_data the command
/// @param[in] i_rsp_data data to check from EXP_FW_STATUS
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode boot_config( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const std::vector<uint8_t>& i_cmd_data,
                               const std::vector<uint8_t>& i_rsp_data,
                               const bool i_skip_logs )
{
    uint8_t l_boot_mode = 0;
    uint8_t l_status = 0;
    uint8_t l_ext_err = 0;
    uint64_t l_fw_status_data = 0;
    uint64_t l_cmd_data = convert_to_long(i_cmd_data);
    const auto& l_omi = i_target.getParent<fapi2::TARGET_TYPE_OMI>();
    uint32_t l_log_size = 4096;

    FAPI_TRY(exp::i2c::boot_cfg::get_dl_layer_boot_mode(i_target, i_cmd_data, l_boot_mode));
    FAPI_TRY(status::get_status_code(i_target, i_rsp_data, l_status));
    FAPI_TRY(status::get_fw_status_ext_err(i_target, i_rsp_data, l_ext_err));
    FAPI_TRY(capture_status(i_target, i_rsp_data, l_fw_status_data));

    // Zero out the log size to skip collecting them if asked.
    // This can be necessary because the attempt to collect the logs may
    // actually disrupt the operation in progress if the FW is still BUSY.
    if( i_skip_logs )
    {
        l_log_size = 0;
    }

    // Check that Explorer is not still in FW_BUSY state
    FAPI_ASSERT( (l_status != status_codes::FW_BUSY),
                 fapi2::MSS_EXP_I2C_FW_STATUS_BUSY().
                 set_OCMB_TARGET(i_target).
                 set_CMD_ID(FW_BOOT_CONFIG).
                 set_COMMAND(l_cmd_data).
                 set_STATUS_DATA(l_fw_status_data).
                 set_EXP_ACTIVE_LOG_SIZE(l_log_size),
                 "boot_config> Polling timeout on FW_BOOT_CONFIG command (still FW_BUSY) for " TARGTIDFORMAT,
                 MSSTARGID );

    // Check Explorer return code
    FAPI_ASSERT( (l_status != fw_boot_cfg_status::INVALID_CMD),
                 fapi2::MSS_EXP_BOOT_CONFIG_INVALID_CMD().
                 set_OCMB_TARGET(i_target).
                 set_COMMAND(l_cmd_data).
                 set_BOOT_MODE(l_boot_mode).
                 set_STATUS_DATA(l_fw_status_data).
                 set_EXP_ACTIVE_LOG_SIZE(4096),
                 "BOOT_CONFIG invalid command error (CMD 0x%08X, BOOT_MODE 0x%02X, full status 0x%016X) for " TARGTIDFORMAT,
                 l_cmd_data, l_boot_mode, l_fw_status_data, MSSTARGID );
    FAPI_ASSERT( (l_status != fw_boot_cfg_status::LOOPBACK_FAIL),
                 fapi2::MSS_EXP_BOOT_CONFIG_LOOPBACK_FAIL().
                 set_OCMB_TARGET(i_target).
                 set_COMMAND(l_cmd_data).
                 set_BOOT_MODE(l_boot_mode).
                 set_STATUS_DATA(l_fw_status_data).
                 set_EXP_ACTIVE_LOG_SIZE(4096),
                 "BOOT_CONFIG loopback test fail (BOOT_MODE 0x%02X, full status 0x%016X) for " TARGTIDFORMAT,
                 l_boot_mode, l_fw_status_data, MSSTARGID );
    FAPI_ASSERT( (l_status != fw_boot_cfg_status::DLX_CONFIG_FAIL),
                 fapi2::MSS_EXP_BOOT_CONFIG_DLX_CONFIG_FAIL().
                 set_OCMB_TARGET(i_target).
                 set_COMMAND(l_cmd_data).
                 set_BOOT_MODE(l_boot_mode).
                 set_STATUS_DATA(l_fw_status_data).
                 set_EXP_ACTIVE_LOG_SIZE(4096),
                 "BOOT_CONFIG DLx config fail (BOOT_MODE 0x%02X, full status 0x%016X) for " TARGTIDFORMAT,
                 l_boot_mode, l_fw_status_data, MSSTARGID );
    FAPI_ASSERT( (l_status != fw_boot_cfg_status::LANE_INV_FAIL),
                 fapi2::MSS_EXP_BOOT_CONFIG_LANE_INV_FAIL().
                 set_OCMB_TARGET(i_target).
                 set_COMMAND(l_cmd_data).
                 set_BOOT_MODE(l_boot_mode).
                 set_STATUS_DATA(l_fw_status_data).
                 set_EXP_ACTIVE_LOG_SIZE(4096),
                 "BOOT_CONFIG Lane Inversion configuration fail (BOOT_MODE 0x%02X, full status 0x%016X) for " TARGTIDFORMAT,
                 l_boot_mode, l_fw_status_data, MSSTARGID );
    FAPI_ASSERT( (l_status != fw_boot_cfg_status::PARITY_UECC_ERROR),
                 fapi2::MSS_EXP_BOOT_CONFIG_PARITY_UECC_ERROR().
                 set_OCMB_TARGET(i_target).
                 set_COMMAND(l_cmd_data).
                 set_BOOT_MODE(l_boot_mode).
                 set_STATUS_DATA(l_fw_status_data).
                 set_EXP_ACTIVE_LOG_SIZE(4096),
                 "BOOT_CONFIG reported SerDes parity and/or UECC errors (BOOT_MODE 0x%02X, full status 0x%016X) for " TARGTIDFORMAT,
                 l_boot_mode, l_fw_status_data, MSSTARGID );

    if (l_status == fw_boot_cfg_status::SERDES_INIT_FAIL)
    {
        // DLL lock fail is a special case for this error, as it causes the host OMI target to be called out
        FAPI_ASSERT( (l_ext_err != fw_boot_cfg_ext_err::DLL_LOCK_FAIL),
                     fapi2::MSS_EXP_BOOT_CONFIG_SERDES_DLL_LOCK_FAIL().
                     set_OCMB_TARGET(i_target).
                     set_OMI_TARGET(l_omi).
                     set_COMMAND(l_cmd_data).
                     set_BOOT_MODE(l_boot_mode).
                     set_STATUS_DATA(l_fw_status_data).
                     set_EXT_ERR_CODE(l_ext_err).
                     set_EXP_ACTIVE_LOG_SIZE(4096),
                     "BOOT_CONFIG OpenCapi SerDes PLL lock fail (BOOT_MODE 0x%02X, full status 0x%016X) for " TARGTIDFORMAT,
                     l_boot_mode, l_fw_status_data, MSSTARGID );

        FAPI_ASSERT( false,
                     fapi2::MSS_EXP_BOOT_CONFIG_SERDES_INIT_FAIL().
                     set_OCMB_TARGET(i_target).
                     set_COMMAND(l_cmd_data).
                     set_BOOT_MODE(l_boot_mode).
                     set_STATUS_DATA(l_fw_status_data).
                     set_EXT_ERR_CODE(l_ext_err).
                     set_EXP_ACTIVE_LOG_SIZE(4096),
                     "BOOT_CONFIG OpenCapi SerDes init fail (BOOT_MODE 0x%02X, full status 0x%016X) for " TARGTIDFORMAT,
                     l_boot_mode, l_fw_status_data, MSSTARGID );

    }

    FAPI_ASSERT( (l_status == status_codes::I2C_SUCCESS),
                 fapi2::MSS_EXP_I2C_CMD_FAIL().
                 set_OCMB_TARGET(i_target).
                 set_CMD_ID(FW_BOOT_CONFIG).
                 set_COMMAND(l_cmd_data).
                 set_STATUS(l_status).
                 set_STATUS_DATA(l_fw_status_data).
                 set_EXP_ACTIVE_LOG_SIZE(4096),
                 "Failing RC (0x%02X, full status 0x%016X) from BOOT_CONFIG command (BOOT_MODE 0x%02X) for " TARGTIDFORMAT,
                 l_status, l_fw_status_data, l_boot_mode, MSSTARGID );

fapi_try_exit:
    return fapi2::current_err;
}

#endif

}// ns check

}// i2c
}// exp
}// mss
