/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_fw_log_data.C $ */
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
/// @file  exp_fw_log_data.C
///
/// @brief Collects Explorer firmware log data
// ----------------------------------------
// *HWP HWP Owner: Matt Derksen <mderkse1@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB
// ----------------------------------------
#include <exp_fw_log_data.H>
#include <fapi2.H>
#include <i2c_access.H>
#include <lib/inband/exp_inband.H>
#include <lib/inband/exp_fw_log.H>
#include <lib/shared/exp_consts.H>
#include <lib/i2c/exp_i2c.H>
#include <mss_explorer_attribute_getters.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/c_str.H>


extern "C"
{
    /// See header
    fapi2::ReturnCode exp_active_log(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget,
        std::vector<uint8_t>& o_data)
    {
        host_fw_command_struct l_active_errl_cmd;
        host_fw_response_struct l_response;

        // common interface (SUB_CMD_READ_ACTIVE_LOG ignores image and offset)
        mss::exp::ib::exp_fw_log_cmd_parms_struct_t l_cmd_parms =
        {
            mss::exp::ib::SUB_CMD_READ_ACTIVE_LOG,
            mss::exp::ib::EXP_IMAGE_A,
            0,
            static_cast<uint32_t>(o_data.size())
        };

        // Set up the command packet
        FAPI_TRY(mss::exp::ib::build_log_cmd(i_ocmbTarget,
                                             l_cmd_parms,
                                             l_active_errl_cmd),
                 "exp_active_log: Failed build_log_cmd() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Send the command packet
        FAPI_TRY(mss::exp::ib::putCMD(i_ocmbTarget, l_active_errl_cmd),
                 "exp_active_log: Failed putCMD() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Get the response
        FAPI_TRY(mss::exp::ib::getRSP(i_ocmbTarget, mss::exp::ib::SUB_CMD_READ_ACTIVE_LOG, l_response, o_data),
                 "exp_active_log: Failed getRSP() cmd for %s!",
                 mss::c_str(i_ocmbTarget));

        // Check if cmd was successful
        FAPI_TRY(mss::exp::ib::check_log_cmd_response(i_ocmbTarget, l_response),
                 "exp_active_log: Failed check_log_cmd_response() for %s!",
                 mss::c_str(i_ocmbTarget));

    fapi_try_exit:
        return fapi2::current_err;
    }


    /// See header
    fapi2::ReturnCode exp_saved_log(
        const mss::exp::ib::exp_image i_image,
        const uint32_t i_offset,
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget,
        std::vector<uint8_t>& io_data)
    {
        host_fw_command_struct l_saved_log_cmd;
        host_fw_response_struct l_response;

        mss::exp::ib::exp_fw_log_cmd_parms_struct_t l_cmd_parms =
        {
            mss::exp::ib::SUB_CMD_READ_SAVED_LOG,
            i_image,
            i_offset,
            static_cast<uint32_t>(io_data.size())
        };

        // Set up the command packet
        FAPI_TRY(mss::exp::ib::build_log_cmd(i_ocmbTarget,
                                             l_cmd_parms,
                                             l_saved_log_cmd),
                 "exp_saved_log: Failed build_log_cmd() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Send the command packet
        FAPI_TRY(mss::exp::ib::putCMD(i_ocmbTarget, l_saved_log_cmd),
                 "exp_saved_log: Failed putCMD() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Get the response
        FAPI_TRY(mss::exp::ib::getRSP(i_ocmbTarget, mss::exp::ib::SUB_CMD_READ_SAVED_LOG, l_response, io_data),
                 "exp_saved_log: Failed getRSP() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Check if cmd was successful
        FAPI_TRY(mss::exp::ib::check_log_cmd_response(i_ocmbTarget, l_response),
                 "exp_saved_log: Failed check_log_cmd_response()"
                 " for %s!", mss::c_str(i_ocmbTarget));
    fapi_try_exit:
        return fapi2::current_err;
    }

    /// See header
    fapi2::ReturnCode exp_active_log_from_ram(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget,
        const uint32_t i_start_addr,
        std::vector<uint8_t>& o_data)
    {
        const auto l_len = static_cast<uint32_t>(o_data.size());
        uint64_t l_mmio_start_addr = mss::exp::ib::EXPLR_IB_MMIO_OFFSET | i_start_addr;

        // make sure expected size is a multiple of 8
        const uint32_t l_padding = ((l_len % 8) > 0) ? (8 - (l_len % 8)) : 0;
        o_data.resize(l_len + l_padding);

        // check bounds of address and length
        if ((i_start_addr < EXP_RAM_START) ||
            (i_start_addr > EXP_RAM_END - l_len))
        {
            FAPI_ERR("start address and length must be in RAM range 0x%.8X to 0x%.8X\n",
                     EXP_RAM_START, EXP_RAM_END);
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
        }

        FAPI_DBG("Reading log data from Explorer RAM...");
        FAPI_TRY(fapi2::getMMIO(i_ocmbTarget, l_mmio_start_addr, mss::exp::ib::BUFFER_TRANSACTION_SIZE, o_data));
        FAPI_TRY(mss::exp::ib::correctMMIOEndianForStruct(o_data));
        FAPI_TRY(mss::exp::ib::correctMMIOword_order(o_data));

    fapi_try_exit:
        return fapi2::current_err;
    }

    /// See header
    fapi2::ReturnCode exp_clear_active_log(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget)
    {
        host_fw_command_struct l_clear_errl_cmd;
        host_fw_response_struct l_response;
        std::vector<uint8_t> l_data;

        // common interface (SUB_CMD_CLEAR_ACTIVE_LOG ignores last 3 parms)
        mss::exp::ib::exp_fw_log_cmd_parms_struct_t l_cmd_parms =
        {
            mss::exp::ib::SUB_CMD_CLEAR_ACTIVE_LOG,
            mss::exp::ib::EXP_IMAGE_A, 0, 0 // unused parameters
        };

        // Set up the command packet
        FAPI_TRY(mss::exp::ib::build_log_cmd(i_ocmbTarget,
                                             l_cmd_parms,
                                             l_clear_errl_cmd),
                 "exp_clear_active_log: Failed build_log_cmd() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Send the command packet
        FAPI_TRY(mss::exp::ib::putCMD(i_ocmbTarget, l_clear_errl_cmd),
                 "exp_clear_active_log: Failed putCMD() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Get the response
        FAPI_TRY(mss::exp::ib::getRSP(i_ocmbTarget, mss::exp::ib::SUB_CMD_CLEAR_ACTIVE_LOG, l_response, l_data),
                 "exp_clear_active_log: Failed getRSP() cmd for %s!",
                 mss::c_str(i_ocmbTarget));

        // Check if cmd was successful
        FAPI_TRY(mss::exp::ib::check_log_cmd_response(i_ocmbTarget, l_response),
                 "exp_clear_active_log: Failed check_log_cmd_response() for %s!",
                 mss::c_str(i_ocmbTarget));

    fapi_try_exit:
        return fapi2::current_err;
    }

    /// See header
    fapi2::ReturnCode exp_clear_saved_log(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget)
    {
        host_fw_command_struct l_clear_errl_cmd;
        host_fw_response_struct l_response;
        std::vector<uint8_t> l_data;

        // common interface (SUB_CMD_READ_ACTIVE_LOG ignores image and offset)
        mss::exp::ib::exp_fw_log_cmd_parms_struct_t l_cmd_parms =
        {
            mss::exp::ib::SUB_CMD_ERASE_SAVED_LOG,
            mss::exp::ib::EXP_IMAGE_A, 0, 0
        };

        // Set up the command packet
        FAPI_TRY(mss::exp::ib::build_log_cmd(i_ocmbTarget,
                                             l_cmd_parms,
                                             l_clear_errl_cmd),
                 "exp_clear_saved_log: Failed build_log_cmd() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Send the command packet
        FAPI_TRY(mss::exp::ib::putCMD(i_ocmbTarget, l_clear_errl_cmd),
                 "exp_clear_saved_log: Failed putCMD() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Get the response
        FAPI_TRY(mss::exp::ib::getRSP(i_ocmbTarget, mss::exp::ib::SUB_CMD_ERASE_SAVED_LOG, l_response, l_data),
                 "exp_clear_saved_log: Failed getRSP() cmd for %s!",
                 mss::c_str(i_ocmbTarget));

        // Check if cmd was successful
        FAPI_TRY(mss::exp::ib::check_log_cmd_response(i_ocmbTarget, l_response),
                 "exp_clear_saved_log: Failed check_log_cmd_response() for %s!",
                 mss::c_str(i_ocmbTarget));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Send FW_READ_ACTIVE_LOGS and return if we've reached the end
    /// @param[in] i_ocmbTarget the controller
    /// @param[out] o_log_complete true if we've read the last of the lag data
    /// @param[in,out] io_data - where to put error log data
    ///
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode send_i2c_read_active_logs(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget,
        bool& o_log_complete,
        std::vector<uint8_t>& io_data)
    {
        // Response size = 1 byte length + 1 byte log_continues + up to 256 bytes data
        constexpr uint16_t FW_READ_ACTIVE_LOGS_SIZE = 258;
        constexpr size_t LOG_CONTINUES_BYTE = 1;
        constexpr size_t DATA_START_BYTE = 2;
        std::vector<uint8_t> l_data_buf;
        std::vector<uint8_t> l_cmd;
        l_cmd.push_back(mss::exp::i2c::cmd_id::FW_READ_ACTIVE_LOGS);

        FAPI_TRY(fapi2::getI2c(i_ocmbTarget, FW_READ_ACTIVE_LOGS_SIZE, l_cmd, l_data_buf),
                 "getI2c returned error for FW_READ_ACTIVE_LOGS operation on %s",
                 mss::c_str(i_ocmbTarget));

        o_log_complete = (l_data_buf[LOG_CONTINUES_BYTE] == 0);
        io_data.insert(io_data.end(), l_data_buf.begin() + DATA_START_BYTE, l_data_buf.end());

    fapi_try_exit:
        return fapi2::current_err;
    }

    /// See header
    fapi2::ReturnCode exp_active_log_i2c(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget,
        std::vector<uint8_t>& o_data)
    {
        fapi2::ATTR_MSS_EXP_I2C_FW_LOG_DUMP_DISABLE_Type l_disable_dump = false;
        bool l_log_complete = false;
        constexpr uint32_t MAX_SEQUENCES = BUFFER_SIZE / DATA_PER_I2C_SEQUENCE + 1;
        uint32_t l_sequence_count = 0;

        FAPI_TRY(mss::attr::get_exp_i2c_fw_log_dump_disable(i_ocmbTarget, l_disable_dump));

        if (l_disable_dump == fapi2::ENUM_ATTR_MSS_EXP_I2C_FW_LOG_DUMP_DISABLE_DISABLE)
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        while (!l_log_complete && (l_sequence_count < MAX_SEQUENCES))
        {
            FAPI_TRY(send_i2c_read_active_logs(i_ocmbTarget, l_log_complete, o_data));
            l_sequence_count++;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

}
