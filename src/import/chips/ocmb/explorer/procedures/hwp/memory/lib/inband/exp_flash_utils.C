/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/exp_flash_utils.C $ */
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
/// EKB-Mirror-To: hostboot

///
/// @file exp_flash_utils.C
/// @brief implement Explorer flash programming command interface
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: MSS

#include <fapi2.H>
#include <lib/inband/exp_flash_utils.H>
#include <lib/inband/exp_inband.H>
#include <lib/shared/exp_consts.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <generic/memory/lib/utils/endian_utils.H>
#include <lib/omi/crc32.H>
#include <mmio_access.H>
#include <lib/inband/exp_fw_adapter_properties.H>
#include <mss_explorer_attribute_getters.H>

#ifndef __HOSTBOOT_MODULE
    // Included for progress / time left reporting (Cronus only)
    #include <ctime>
#endif

namespace mss
{

namespace exp
{

constexpr uint32_t FLASH_WRITE_BLOCK_SIZE = 256;

namespace ib
{

///
/// @brief Converts little endian data array to big endian data and saves into partition_info_struct
/// @param[in,out] io_data little endian data to process
/// @param[out] o_partition_info partition_info_struct
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode partition_info_struct_from_little_endian(
    std::vector<uint8_t>& io_data,
    partition_info_struct& o_partition_info)
{
    uint32_t l_idx = 0;
    uint32_t l_temp_var = 0;

    FAPI_TRY(readCrctEndian(io_data, l_idx, l_temp_var));
    o_partition_info.actv_img_flag = l_temp_var;

    FAPI_TRY(readCrctEndianArray(io_data, VERSION_INFO_SIZE, l_idx,
                                 &o_partition_info.fw_img_A_version_info[0]));

    FAPI_TRY(readCrctEndian(io_data, l_idx, l_temp_var));
    o_partition_info.fw_img_A_length = l_temp_var;

    FAPI_TRY(readCrctEndianArray(io_data, VERSION_INFO_SIZE, l_idx,
                                 &o_partition_info.fw_img_B_version_info[0]));

    FAPI_TRY(readCrctEndian(io_data, l_idx, l_temp_var));
    o_partition_info.fw_img_B_length = l_temp_var;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief host_fw_command_struct structure setup for get_partition_info
/// @param[in] i_target the OCMB_CHIP target
/// @param[out] o_cmd the command packet to update
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_partition_info_cmd(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        host_fw_command_struct& o_cmd)
{
    std::vector<uint8_t> cmd_args;

    memset(&o_cmd, 0, sizeof(host_fw_command_struct));

    // Issue EXP_FW_BINARY_UPGRADE cmd though EXP-FW REQ buffer
    o_cmd.cmd_id = mss::exp::omi::EXP_FW_BINARY_UPGRADE;
    o_cmd.cmd_flags = mss::exp::omi::NO_FLAGS;

    // Host generated id number (returned in response packet)
    uint32_t l_counter = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_COUNTER, i_target, l_counter));
    o_cmd.request_identifier = l_counter;

    o_cmd.cmd_length = 0;
    o_cmd.cmd_crc = 0xFFFFFFFF;
    o_cmd.host_work_area = 0;
    o_cmd.cmd_work_area = 0;
    memset(o_cmd.padding, 0, sizeof(o_cmd.padding));

    // populate command arguments using correct endian byte ordering
    cmd_args.push_back(bupg::SUB_CMD_PART_INFO_GET);

    // copy cmd_args vector into command_args array
    std::copy(cmd_args.begin(), cmd_args.end(), &o_cmd.command_argument[0]);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief get the partition info from explorer
/// @param[in] i_target the OCMB_CHIP target
/// @param[out] o_partition_info the partition info structure
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode exp_get_partition_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        partition_info_struct& o_partition_info)
{
    // Issue flash_read sub-command through EXP-FW request buffer
    host_fw_command_struct l_partition_info_cmd;
    {
        // Set up the command packet
        FAPI_TRY(setup_partition_info_cmd(i_target, l_partition_info_cmd),
                 "%s Failed setup_partition_info_cmd()",
                 mss::c_str(i_target));

        // Send the command packet
        FAPI_TRY(mss::exp::ib::putCMD(i_target, l_partition_info_cmd),
                 "%s Failed partition_info putCMD()",
                 mss::c_str(i_target));
    }

    // Read the response message from EXP-FW RESP buffer
    {
        host_fw_response_struct l_response;
        std::vector<uint8_t> l_rsp_data;

        // Read response from buffer
        FAPI_TRY(mss::exp::ib::getRSP(i_target, l_partition_info_cmd, l_response, l_rsp_data),
                 "%s getRSP() failed for partition_info",
                 mss::c_str(i_target));

        // Check status in response packet
        FAPI_TRY(check_flash_response(i_target, l_response, l_partition_info_cmd),
                 "%s error response for partition_info",
                 mss::c_str(i_target));
        // endian swap
        FAPI_TRY(partition_info_struct_from_little_endian(l_rsp_data, o_partition_info));
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief host_fw_command_struct structure setup for flash_read
/// @param[in] i_target the OCMB_CHIP target
/// @param[in] i_addr_offset the address offset within the partition
/// @param[in] i_length the length of data to read (max 256 bytes)
/// @param[in] i_partition_id the partition ID to read from
/// @param[in] i_seq_number the sequence number of this command
/// @param[out] o_cmd the command packet to update
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_flash_read_cmd(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const uint32_t i_addr_offset,
                                       const uint16_t i_length,
                                       const uint8_t i_partition_id,
                                       const uint16_t i_seq_number,
                                       host_fw_command_struct& o_cmd)
{
    std::vector<uint8_t> cmd_args;
    uint8_t l_partition_char = 0;

    FAPI_DBG("i_addr_offset = %d", i_addr_offset);
    FAPI_DBG("i_length = %d", i_length);
    FAPI_DBG("i_partition_id = %d", i_partition_id);
    FAPI_DBG("i_seq_number = %d", i_seq_number);
    memset(&o_cmd, 0, sizeof(host_fw_command_struct));

    // Issue EXP_FW_BINARY_UPGRADE cmd though EXP-FW REQ buffer
    o_cmd.cmd_id = mss::exp::omi::EXP_FW_BINARY_UPGRADE;
    o_cmd.cmd_flags = mss::exp::omi::NO_FLAGS;

    // Host generated id number (returned in response packet)
    uint32_t l_counter = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_COUNTER, i_target, l_counter));
    o_cmd.request_identifier = l_counter;

    o_cmd.cmd_length = 0;
    o_cmd.cmd_crc = 0xFFFFFFFF;
    o_cmd.host_work_area = 0;
    o_cmd.cmd_work_area = 0;
    memset(o_cmd.padding, 0, sizeof(o_cmd.padding));

    // populate command arguments using correct endian byte ordering
    cmd_args.push_back(bupg::SUB_CMD_READ);
    l_partition_char = (i_partition_id == 0) ? static_cast<uint8_t>('A') : static_cast<uint8_t>('B');
    cmd_args.push_back(l_partition_char);

    FAPI_TRY(mss::exp::ib::forceCrctEndian(i_seq_number, cmd_args));

    // NOTE: Per MCHP support, these two arguments must go in big endian byte order
    mss::forceBE(i_addr_offset, cmd_args);
    mss::forceBE(i_length, cmd_args);

    // copy cmd_args vector into command_args array
    std::copy(cmd_args.begin(), cmd_args.end(), &o_cmd.command_argument[0]);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief perform a flash_read of the given partition
/// @param[in] i_target the OCMB_CHIP target
/// @param[in] i_size the size of the data to read
/// @param[in] i_addr_offset the address offset within the partition
/// @param[in] i_partition_id the partition ID to read from
/// @param[out] o_data the data read from the SPI flash, corrected for endianness
/// @param[in] i_check_firs set to true if we should check the CE FIR bit after each read command (default true)
/// @param[in] i_return_data set to true if caller wants the data returned (default true)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode exp_flash_read(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 const uint32_t i_size,
                                 const uint32_t i_addr_offset,
                                 const uint8_t i_partition_id,
                                 std::vector<uint8_t>& o_data,
                                 const bool i_check_firs,
                                 const bool i_return_data)
{
    // Max read size of FLASH_READ command is 256 bytes
    constexpr uint32_t MAX_READ_SIZE = 256;

    const uint32_t l_num_sequences = (i_size / MAX_READ_SIZE) +
                                     (((i_size % MAX_READ_SIZE) == 0) ? 0 : 1);
    const uint32_t l_last_seq_size = ((i_size % MAX_READ_SIZE) == 0) ? MAX_READ_SIZE : (i_size % MAX_READ_SIZE);

    uint32_t l_offset = 0;

    for (uint32_t l_seq_num = 0; l_seq_num < l_num_sequences; l_seq_num++)
    {
        FAPI_DBG("Running seq[%d] out of %d sequences", l_seq_num, l_num_sequences);
        // If we're on the last sequence, read only the remaining data size
        const uint16_t l_read_size = (l_seq_num == l_num_sequences - 1) ? l_last_seq_size : MAX_READ_SIZE;

        host_fw_command_struct l_flash_read_cmd;
        std::vector<uint8_t> l_rsp_data;

        // Issue flash_read sub-command through EXP-FW request buffer
        {
            // Set up the command packet
            FAPI_TRY(setup_flash_read_cmd(
                         i_target,
                         l_offset,
                         l_read_size,
                         i_partition_id,
                         0,
                         l_flash_read_cmd),
                     "%s Failed setup_flash_read_cmd() seq_num[%u]",
                     mss::c_str(i_target), l_seq_num);

            // Send the command packet
            FAPI_TRY(mss::exp::ib::putCMD(i_target, l_flash_read_cmd),
                     "%s Failed flash_read putCMD() seq_num[%u]",
                     mss::c_str(i_target), l_seq_num);
        }

        // Read the response message from EXP-FW RESP buffer
        {
            host_fw_response_struct l_response;

            // Read response from buffer
            l_rsp_data.clear();
            FAPI_TRY(mss::exp::ib::getRSP(i_target, l_flash_read_cmd, l_response, l_rsp_data),
                     "%s getRSP() failed for flash_read seq_num[%u]",
                     mss::c_str(i_target), l_seq_num);

            // Check status in response packet
            FAPI_TRY(check_flash_response(i_target, l_response, l_flash_read_cmd),
                     "%s error response for flash_read seq_num[%u]",
                     mss::c_str(i_target), l_seq_num);
        }

        // Read the image data
        if (i_return_data)
        {
            // copy to output
            o_data.insert(o_data.end(), l_rsp_data.begin(), l_rsp_data.end());
        }

        l_offset += l_read_size;

        // Read the FIR bit if needed
        if (i_check_firs)
        {
            fapi2::buffer<uint64_t> l_fir_data;
            // Read LOCAL_FIR[23], assert MNFG_SPI_FLASH_CE if set
            FAPI_DBG("%s Reading MNFG_SPI_FLASH_CE...", mss::c_str(i_target));
            FAPI_TRY(fapi2::getScom(i_target, EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR, l_fir_data));

            FAPI_ASSERT((l_fir_data.getBit<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PCS_GPBC_IRQ_112>() == 0),
                        fapi2::EXP_MNFG_SPI_FLASH_CE().
                        set_OCMB_TARGET(i_target).
                        set_EXP_ACTIVE_LOG_SIZE(4096),
                        "%s Explorer LOCAL_FIR[23] SPI FLASH CE was set during a SPI flash read operation",
                        mss::c_str(i_target));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Reads Explorer SPI flash
/// @param[in] i_target the controller
/// @param[in] i_read_a set to true to read partition A (default true)
/// @param[in] i_read_b set to true to read partition B (default true)
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode exp_flash_read_test(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      const bool i_read_a,
                                      const bool i_read_b)
{
    constexpr uint8_t IMAGE_A = 0;
    constexpr uint8_t NUM_FLASH_SECTORS = 2;

    std::vector<uint8_t> l_data;
    partition_info_struct l_partition_info;
    uint8_t l_failed_auth_a = 0;
    uint8_t l_failed_auth_b = 0;
    fapi2::buffer<uint64_t> l_fir_data;

    FAPI_INF("%s Entering exp_flash_read_test", mss::c_str(i_target));

    // Get partition authentication result info from attributes
    FAPI_TRY( mss::attr::get_exp_fw_failed_authentication_a(i_target, l_failed_auth_a) );
    FAPI_TRY( mss::attr::get_exp_fw_failed_authentication_b(i_target, l_failed_auth_b) );

    // Run get_partition_info to get image size(s)
    FAPI_TRY(exp_get_partition_info(i_target, l_partition_info));

    // Read image A, assert MNFG_SPI_FLASH_TIMEOUT_READING_IMAGE_A if timeout
    // Read image B, assert MNFG_SPI_FLASH_TIMEOUT_READING_IMAGE_B if timeout
    for (uint8_t l_partition = 0; l_partition < NUM_FLASH_SECTORS; l_partition++)
    {
        const auto l_failed_auth = (l_partition == IMAGE_A) ? l_failed_auth_a : l_failed_auth_b;
        const auto l_read_selected = (l_partition == IMAGE_A) ? i_read_a : i_read_b;

        if (!l_read_selected)
        {
            FAPI_INF("%s Requested to skip exp_flash_read_test on image %s",
                     mss::c_str(i_target), (l_partition == IMAGE_A) ? "A" : "B");
            continue;
        }
        else if (l_failed_auth != 0)
        {
            FAPI_INF("%s Skipping exp_flash_read_test on image %s because it failed authentication",
                     mss::c_str(i_target), (l_partition == IMAGE_A) ? "A" : "B");
            continue;
        }

        const auto l_flash_sector_size = (l_partition == IMAGE_A) ?
                                         l_partition_info.fw_img_A_length :
                                         l_partition_info.fw_img_B_length;

        fapi2::current_err = exp_flash_read(i_target, l_flash_sector_size, 0, l_partition, l_data, true, false);

        FAPI_ASSERT((fapi2::current_err == fapi2::FAPI2_RC_SUCCESS),
                    fapi2::EXP_MNFG_SPI_FLASH_TIMEOUT_READING_IMAGE().
                    set_OCMB_TARGET(i_target).
                    set_IMAGE(l_partition).
                    set_EXP_ACTIVE_LOG_SIZE(4096),
                    "%s Explorer SPI FLASH read failed for image %s during SPI flash read test",
                    mss::c_str(i_target), ((l_partition == IMAGE_A) ? "A" : "B"));

        FAPI_INF("%s exp_flash_read_test PASSED on image %s",
                 mss::c_str(i_target), (l_partition == IMAGE_A) ? "A" : "B");
    }

    {
        // Read LOCAL_FIR[23], assert MNFG_SPI_FLASH_CE if set
        FAPI_TRY(fapi2::getScom(i_target, EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR, l_fir_data));

        FAPI_ASSERT((l_fir_data.getBit<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PCS_GPBC_IRQ_112>() == 0),
                    fapi2::EXP_MNFG_SPI_FLASH_CE().
                    set_OCMB_TARGET(i_target).
                    set_EXP_ACTIVE_LOG_SIZE(4096),
                    "%s Explorer LOCAL_FIR[23] SPI FLASH CE was set during SPI flash read test",
                    mss::c_str(i_target));

        FAPI_INF("%s MNFG_SPI_FLASH_CE bit was not set. No CE errors detected", mss::c_str(i_target));
    }

fapi_try_exit:
    FAPI_INF("Exiting exp_flash_read_test(%s) with return code : 0x%08x...",
             mss::c_str(i_target), (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Checks explorer response argument for a successful command
/// @param[in] i_target OCMB target
/// @param[in] i_rsp response from command
/// @param[in] i_cmd original command
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode check_flash_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const host_fw_response_struct& i_rsp,
                                       const host_fw_command_struct& i_cmd)
{
    static constexpr uint8_t MCHP_STATUS_CODE  = 0;
    static constexpr uint8_t MCHP_ERROR_CODE_1 = 1;
    static constexpr uint8_t MCHP_ERROR_CODE_2 = 2;
    static constexpr uint8_t MCHP_ERROR_CODE_3 = 3;
    static constexpr uint8_t MCHP_ERROR_CODE_4 = 4;

    FAPI_ASSERT((i_rsp.response_argument[0] == omi::response_arg::RESPONSE_SUCCESS),
                fapi2::EXP_FLASH_COMMAND_ERR().
                set_OCMB_TARGET(i_target).
                set_RSP_ID(i_rsp.response_id).
                set_REQ_ID(i_rsp.request_identifier).
                set_MCHP_STATUS_CODE(i_rsp.response_argument[MCHP_STATUS_CODE]).
                set_MCHP_ERROR_CODE_1(i_rsp.response_argument[MCHP_ERROR_CODE_1]).
                set_MCHP_ERROR_CODE_2(i_rsp.response_argument[MCHP_ERROR_CODE_2]).
                set_MCHP_ERROR_CODE_3(i_rsp.response_argument[MCHP_ERROR_CODE_3]).
                set_MCHP_ERROR_CODE_4(i_rsp.response_argument[MCHP_ERROR_CODE_4]).
                set_EXP_ACTIVE_LOG_SIZE(4096),
                "%s Flash command encountered an error. "
                "MCHP Error codes: response_argument[1] = 0x%02X, [2] = 0x%02X, [3] = 0x%02X, [4] = 0x%02X",
                mss::c_str(i_target),
                i_rsp.response_argument[MCHP_ERROR_CODE_1],
                i_rsp.response_argument[MCHP_ERROR_CODE_2],
                i_rsp.response_argument[MCHP_ERROR_CODE_3],
                i_rsp.response_argument[MCHP_ERROR_CODE_4]);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


} // ns ib

namespace bupg
{

///
/// @brief Checks explorer response argument for a successful command
/// @param[in] i_target OCMB target
/// @param[in] i_rsp response from command
/// @param[in] i_cmd original command
/// @param[in] i_image_sz size of the binary image
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode check_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 const host_fw_response_struct& i_rsp,
                                 const host_fw_command_struct& i_cmd,
                                 const size_t i_image_sz)
{
    static constexpr uint8_t MCHP_STATUS_CODE  = 0;
    static constexpr uint8_t MCHP_ERROR_CODE_1 = 1;
    static constexpr uint8_t MCHP_ERROR_CODE_2 = 2;
    static constexpr uint8_t MCHP_ERROR_CODE_3 = 3;

    // Now if we get a bad success_flag, switch on the error code to give
    // corresponding error log
    if (i_rsp.response_argument[0] != omi::response_arg::RESPONSE_SUCCESS)
    {
        uint32_t l_partition_id = 0;
        uint32_t l_fw_version_a = 0;
        uint32_t l_fw_version_b = 0;

        FAPI_TRY(mss::attr::get_exp_fw_partition_id(i_target, l_partition_id));
        FAPI_TRY(mss::attr::get_exp_fw_version_a(i_target, l_fw_version_a));
        FAPI_TRY(mss::attr::get_exp_fw_version_b(i_target, l_fw_version_b));

        switch(i_rsp.response_argument[MCHP_ERROR_CODE_1])
        {
            case bupg::fw_binary_upgrade_rc::DEV_INF_ERR:
                FAPI_ASSERT(false,
                            fapi2::EXP_UPDATE_DEV_INF_ERR().
                            set_OCMB_TARGET(i_target).
                            set_RSP_ID(i_rsp.response_id).
                            set_REQ_ID(i_rsp.request_identifier).
                            set_MCHP_STATUS_CODE(i_rsp.response_argument[MCHP_STATUS_CODE]).
                            set_MCHP_ERROR_CODE_1(i_rsp.response_argument[MCHP_ERROR_CODE_1]).
                            set_MCHP_ERROR_CODE_2(i_rsp.response_argument[MCHP_ERROR_CODE_2]).
                            set_MCHP_ERROR_CODE_3(i_rsp.response_argument[MCHP_ERROR_CODE_3]).
                            set_FW_PARTITION_ID(l_partition_id).
                            set_FW_VERSION_A(l_fw_version_a).
                            set_FW_VERSION_B(l_fw_version_b).
                            set_EXP_ACTIVE_LOG_SIZE(4096),
                            "%s Firmware update command encountered device info retrieve error. "
                            "MCHP Error codes: response_argument[1] = 0x%02X, [2] = 0x%02X, [3] = 0x%02X",
                            mss::c_str(i_target),
                            i_rsp.response_argument[MCHP_ERROR_CODE_1],
                            i_rsp.response_argument[MCHP_ERROR_CODE_2],
                            i_rsp.response_argument[MCHP_ERROR_CODE_3]);
                break;

            case bupg::fw_binary_upgrade_rc::DEV_SECTOR_INF_ERR:
                FAPI_ASSERT(false,
                            fapi2::EXP_UPDATE_DEV_SECTOR_INF_ERR().
                            set_OCMB_TARGET(i_target).
                            set_RSP_ID(i_rsp.response_id).
                            set_REQ_ID(i_rsp.request_identifier).
                            set_MCHP_STATUS_CODE(i_rsp.response_argument[MCHP_STATUS_CODE]).
                            set_MCHP_ERROR_CODE_1(i_rsp.response_argument[MCHP_ERROR_CODE_1]).
                            set_MCHP_ERROR_CODE_2(i_rsp.response_argument[MCHP_ERROR_CODE_2]).
                            set_MCHP_ERROR_CODE_3(i_rsp.response_argument[MCHP_ERROR_CODE_3]).
                            set_FW_PARTITION_ID(l_partition_id).
                            set_FW_VERSION_A(l_fw_version_a).
                            set_FW_VERSION_B(l_fw_version_b).
                            set_EXP_ACTIVE_LOG_SIZE(4096),
                            "%s Firmware update command encountered device sector info retrieve error. "
                            "MCHP Error codes: response_argument[1] = 0x%02X, [2] = 0x%02X, [3] = 0x%02X",
                            mss::c_str(i_target),
                            i_rsp.response_argument[MCHP_ERROR_CODE_1],
                            i_rsp.response_argument[MCHP_ERROR_CODE_2],
                            i_rsp.response_argument[MCHP_ERROR_CODE_3]);
                break;

            case bupg::fw_binary_upgrade_rc::DEV_ERASE_ERR:
                FAPI_ASSERT(false,
                            fapi2::EXP_UPDATE_DEV_ERASE_ERR().
                            set_OCMB_TARGET(i_target).
                            set_RSP_ID(i_rsp.response_id).
                            set_REQ_ID(i_rsp.request_identifier).
                            set_MCHP_STATUS_CODE(i_rsp.response_argument[MCHP_STATUS_CODE]).
                            set_MCHP_ERROR_CODE_1(i_rsp.response_argument[MCHP_ERROR_CODE_1]).
                            set_MCHP_ERROR_CODE_2(i_rsp.response_argument[MCHP_ERROR_CODE_2]).
                            set_MCHP_ERROR_CODE_3(i_rsp.response_argument[MCHP_ERROR_CODE_3]).
                            set_FW_PARTITION_ID(l_partition_id).
                            set_FW_VERSION_A(l_fw_version_a).
                            set_FW_VERSION_B(l_fw_version_b).
                            set_EXP_ACTIVE_LOG_SIZE(4096),
                            "%s Firmware update command encountered device erase error. "
                            "MCHP Error codes: response_argument[1] = 0x%02X, [2] = 0x%02X, [3] = 0x%02X",
                            mss::c_str(i_target),
                            i_rsp.response_argument[MCHP_ERROR_CODE_1],
                            i_rsp.response_argument[MCHP_ERROR_CODE_2],
                            i_rsp.response_argument[MCHP_ERROR_CODE_3]);
                break;

            case bupg::fw_binary_upgrade_rc::WRITE_FAIL:
                FAPI_ASSERT(false,
                            fapi2::EXP_UPDATE_WRITE_FAIL().
                            set_OCMB_TARGET(i_target).
                            set_RSP_ID(i_rsp.response_id).
                            set_REQ_ID(i_rsp.request_identifier).
                            set_MCHP_STATUS_CODE(i_rsp.response_argument[MCHP_STATUS_CODE]).
                            set_MCHP_ERROR_CODE_1(i_rsp.response_argument[MCHP_ERROR_CODE_1]).
                            set_MCHP_ERROR_CODE_2(i_rsp.response_argument[MCHP_ERROR_CODE_2]).
                            set_MCHP_ERROR_CODE_3(i_rsp.response_argument[MCHP_ERROR_CODE_3]).
                            set_FW_PARTITION_ID(l_partition_id).
                            set_FW_VERSION_A(l_fw_version_a).
                            set_FW_VERSION_B(l_fw_version_b).
                            set_EXP_ACTIVE_LOG_SIZE(4096),
                            "%s Firmware update command encountered device write error. "
                            "MCHP Error codes: response_argument[1] = 0x%02X, [2] = 0x%02X, [3] = 0x%02X",
                            mss::c_str(i_target),
                            i_rsp.response_argument[MCHP_ERROR_CODE_1],
                            i_rsp.response_argument[MCHP_ERROR_CODE_2],
                            i_rsp.response_argument[MCHP_ERROR_CODE_3]);
                break;

            case bupg::fw_binary_upgrade_rc::INV_IMAGE_LEN:
                FAPI_ASSERT(false,
                            fapi2::EXP_UPDATE_INV_IMAGE_LEN().
                            set_OCMB_TARGET(i_target).
                            set_RSP_ID(i_rsp.response_id).
                            set_REQ_ID(i_rsp.request_identifier).
                            set_IMAGE_LEN(i_image_sz).
                            set_MCHP_STATUS_CODE(i_rsp.response_argument[MCHP_STATUS_CODE]).
                            set_MCHP_ERROR_CODE_1(i_rsp.response_argument[MCHP_ERROR_CODE_1]).
                            set_MCHP_ERROR_CODE_2(i_rsp.response_argument[MCHP_ERROR_CODE_2]).
                            set_MCHP_ERROR_CODE_3(i_rsp.response_argument[MCHP_ERROR_CODE_3]).
                            set_FW_PARTITION_ID(l_partition_id).
                            set_FW_VERSION_A(l_fw_version_a).
                            set_FW_VERSION_B(l_fw_version_b).
                            set_EXP_ACTIVE_LOG_SIZE(4096),
                            "%s Firmware update command encountered invalid image length error. "
                            "MCHP Error codes: response_argument[1] = 0x%02X, [2] = 0x%02X, [3] = 0x%02X",
                            mss::c_str(i_target),
                            i_rsp.response_argument[MCHP_ERROR_CODE_1],
                            i_rsp.response_argument[MCHP_ERROR_CODE_2],
                            i_rsp.response_argument[MCHP_ERROR_CODE_3]);
                break;

            case bupg::fw_binary_upgrade_rc::AUTH_FAIL:
                FAPI_ASSERT(false,
                            fapi2::EXP_UPDATE_AUTH_FAIL().
                            set_OCMB_TARGET(i_target).
                            set_RSP_ID(i_rsp.response_id).
                            set_REQ_ID(i_rsp.request_identifier).
                            set_MCHP_STATUS_CODE(i_rsp.response_argument[MCHP_STATUS_CODE]).
                            set_MCHP_ERROR_CODE_1(i_rsp.response_argument[MCHP_ERROR_CODE_1]).
                            set_MCHP_ERROR_CODE_2(i_rsp.response_argument[MCHP_ERROR_CODE_2]).
                            set_MCHP_ERROR_CODE_3(i_rsp.response_argument[MCHP_ERROR_CODE_3]).
                            set_FW_PARTITION_ID(l_partition_id).
                            set_FW_VERSION_A(l_fw_version_a).
                            set_FW_VERSION_B(l_fw_version_b).
                            set_EXP_ACTIVE_LOG_SIZE(4096),
                            "%s Firmware update command reported an authentication failure. "
                            "MCHP Error codes: response_argument[1] = 0x%02X, [2] = 0x%02X, [3] = 0x%02X",
                            mss::c_str(i_target),
                            i_rsp.response_argument[MCHP_ERROR_CODE_1],
                            i_rsp.response_argument[MCHP_ERROR_CODE_2],
                            i_rsp.response_argument[MCHP_ERROR_CODE_3]);
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::EXP_UPDATE_CMD_FAILED().
                            set_OCMB_TARGET(i_target).
                            set_RSP_ID(i_rsp.response_id).
                            set_REQ_ID(i_rsp.request_identifier).
                            set_MCHP_STATUS_CODE(i_rsp.response_argument[MCHP_STATUS_CODE]).
                            set_MCHP_ERROR_CODE_1(i_rsp.response_argument[MCHP_ERROR_CODE_1]).
                            set_MCHP_ERROR_CODE_2(i_rsp.response_argument[MCHP_ERROR_CODE_2]).
                            set_MCHP_ERROR_CODE_3(i_rsp.response_argument[MCHP_ERROR_CODE_3]).
                            set_FW_PARTITION_ID(l_partition_id).
                            set_FW_VERSION_A(l_fw_version_a).
                            set_FW_VERSION_B(l_fw_version_b).
                            set_EXP_ACTIVE_LOG_SIZE(4096),
                            "%s Received unknown failure response for firmware update command. "
                            "MCHP Error codes: response_argument[1] = 0x%02X, [2] = 0x%02X, [3] = 0x%02X",
                            mss::c_str(i_target),
                            i_rsp.response_argument[MCHP_ERROR_CODE_1],
                            i_rsp.response_argument[MCHP_ERROR_CODE_2],
                            i_rsp.response_argument[MCHP_ERROR_CODE_3]);
                break;
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}// ns bupg

///
/// @brief Write an image to the temp partition in the SPI flash
///
/// @param[in] i_target OCMB target that will be acted upon with this command
/// @param[in] i_image_ptr pointer to the binary image
/// @param[in] i_image_sz size of the binary image
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode write_fw_image_to_flash(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t* i_image_ptr,
        const size_t i_image_sz)
{
    uint16_t seq_num = 0;
    uint32_t block_crc = 0;
    std::vector<uint8_t> buffer;
    const uint8_t* end_ptr = i_image_ptr + i_image_sz;

    FAPI_INF("%s Writing image to SPI flash temp area...", mss::c_str(i_target));

#ifndef __HOSTBOOT_MODULE
    constexpr uint64_t SECONDS_PER_MINUTE = 60;
    constexpr uint64_t MINUTES_PER_HOUR   = 60;

    uint32_t l_progress_pct = 0;
    // Passing in a nullptr gets us the current time
    const auto l_start_time = time(nullptr);
#endif

    //Check that i_image_sz value is not larger than 3 bytes, which
    //is the actual field size for this value in the packet.
    FAPI_ASSERT(((i_image_sz & 0xff000000) == 0),
                fapi2::EXP_UPDATE_INVALID_IMAGE_SIZE()
                .set_OCMB_TARGET(i_target)
                .set_IMAGE_SIZE(i_image_sz),
                "%s exp_fw_update: image size[0x%08x] must be less than 16MB!",
                mss::c_str(i_target), i_image_sz);

    // Write successive blocks until the entire image is written
    buffer.reserve(mss::exp::FLASH_WRITE_BLOCK_SIZE);

    for(uint8_t* cur_ptr = const_cast<uint8_t*>(i_image_ptr);
        cur_ptr < end_ptr;
        cur_ptr += mss::exp::FLASH_WRITE_BLOCK_SIZE)
    {
        const uint32_t bytes_left = end_ptr - cur_ptr;
        const uint32_t data_size = (bytes_left <
                                    mss::exp::FLASH_WRITE_BLOCK_SIZE) ?
                                   bytes_left :
                                   mss::exp::FLASH_WRITE_BLOCK_SIZE;

        // copy data into a vector (required by crc32_gen)
        buffer.assign(cur_ptr, cur_ptr + data_size);

        // pad end with FF's if smaller than block size
        buffer.resize(mss::exp::FLASH_WRITE_BLOCK_SIZE, 0xFF);

        // calculate the crc
        block_crc = crc32_gen(buffer);

        // endian swap
        FAPI_TRY(mss::exp::ib::correctMMIOEndianForStruct(buffer));
        FAPI_TRY(mss::exp::ib::correctMMIOword_order(buffer));

        // write block to data buffer on explorer
        FAPI_TRY(fapi2::putMMIO(i_target,
                                mss::exp::ib::EXPLR_IB_DATA_ADDR,
                                mss::exp::ib::BUFFER_TRANSACTION_SIZE,
                                buffer));

        // Issue flash_write sub-command through EXP-FW request buffer
        host_fw_command_struct flash_write_cmd;
        {
            // Set up the command packet
            FAPI_TRY(mss::exp::setup_flash_write_cmd(
                         i_target,
                         i_image_sz,
                         seq_num,
                         block_crc,
                         flash_write_cmd),
                     "exp_fw_update: Failed setup_flash_write_cmd() "
                     "for %s! seq_num[%u]",
                     mss::c_str(i_target), seq_num);

            // Send the command packet
            FAPI_TRY(mss::exp::ib::putCMD(i_target, flash_write_cmd),
                     "exp_fw_update: Failed flash_write putCMD() "
                     "for %s! seq_num[%u]",
                     mss::c_str(i_target), seq_num);
        }

        // Read the response message from EXP-FW RESP buffer
        {
            host_fw_response_struct response;
            std::vector<uint8_t> rsp_data;

            // Normally we need to poll the outbound doorbell and read/check the
            // fw_response_struct to make sure the command completed. In this case,
            // we will only check the fw_response_struct for every 16th transfer to
            // speed things up.
            // We still have to poll the doorbell to make sure the command completed
            if ((seq_num % 16) == 0)
            {
                fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
                // Read response from buffer
                l_rc = mss::exp::ib::getRSP(i_target, flash_write_cmd, response, rsp_data);

                FAPI_TRY(mss::exp::callout_fw_write_no_doorbell(i_target, seq_num, l_rc),
                         "exp_fw_update: getRSP() failed for flash_write "
                         "on %s! seq_num[%u]",
                         mss::c_str(i_target), seq_num);

                // Check status in response packet
                FAPI_TRY(mss::exp::bupg::check_response(i_target, response, flash_write_cmd, i_image_sz),
                         "exp_fw_update: error response for flash_write "
                         "on %s! seq_num[%u]",
                         mss::c_str(i_target), seq_num);
            }
            else
            {
                fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

                // Poll response doorbell only
                l_rc = mss::exp::ib::poll_for_response_ready(i_target, mss::exp::omi::cmd_and_response_id::EXP_FW_BINARY_UPGRADE);

                FAPI_TRY(mss::exp::callout_fw_write_no_doorbell(i_target, seq_num, l_rc),
                         "exp_fw_update: getRSP() failed for flash_write "
                         "on %s! seq_num[%u]",
                         mss::c_str(i_target), seq_num);

                // Clear response doorbell
                FAPI_TRY(mss::exp::ib::clear_outbound_doorbell(i_target));
            }
        }

        //increment sequence number after each 256 byte block is written
        seq_num++;

#ifndef __HOSTBOOT_MODULE
        {
            // Report progress at 1% intervals (only in Cronus)
            uint32_t l_new_progress_pct = 100 * (i_image_sz - bytes_left) / i_image_sz;

            const auto l_current_time = time(nullptr);
            const auto l_elapsed_time = difftime(l_current_time, l_start_time);
            const uint32_t l_predicted_total_time = 100 * l_elapsed_time /
                                                    ((l_new_progress_pct < 1) ? 1 : l_new_progress_pct);
            const auto l_remaining_time = static_cast<uint64_t>(l_predicted_total_time - l_elapsed_time);
            const auto l_remaining_minutes = (l_remaining_time / SECONDS_PER_MINUTE) % MINUTES_PER_HOUR;

            if (l_progress_pct != l_new_progress_pct)
            {
                FAPI_INF("%s FW upload progress: %d%% (about %d minutes remaining)",
                         mss::c_str(i_target), l_new_progress_pct, l_remaining_minutes);
            }

            l_progress_pct = l_new_progress_pct;
        }
#endif
    }

    FAPI_INF("%s Completed writing image to SPI flash temp area", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Authenticate and commit a newly uploaded FW image
///
/// @param[in] i_target OCMB target that will be acted upon with this command
/// @param[in] i_image_sz size of the binary image
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode commit_fw_image(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const size_t i_image_sz)
{
    FAPI_INF("%s Committing new FW image...", mss::c_str(i_target));

    host_fw_command_struct flash_commit_cmd;
    // Issue the flash_commit sub-command through EXP-FW request buffer
    {
        FAPI_TRY(mss::exp::setup_flash_commit_cmd(i_target,
                 flash_commit_cmd));
        FAPI_TRY(mss::exp::ib::putCMD(i_target, flash_commit_cmd),
                 "exp_fw_update: putCMD() failed for flash_commit on %s!",
                 mss::c_str(i_target));
    }

    // Read the response message from EXP-FW RESP buffer
    {
        host_fw_response_struct response;
        std::vector<uint8_t> rsp_data;
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        // Wait a little while first (value based on MCHP estimations):
        // 2 sec for image authentication
        // 7 sec to erase 600K on flash part
        // 1800 usec to program flash image
        // = 10.8 sec, so wait 15 sec to be safe
        FAPI_INF("Waiting for flash image commit to complete on %s...", mss::c_str(i_target));

        for (uint64_t l_seconds = 0; l_seconds < 15; ++l_seconds)
        {
            FAPI_TRY(fapi2::delay(mss::DELAY_1S, 200));
        }

        l_rc = mss::exp::ib::getRSP(i_target, flash_commit_cmd, response, rsp_data);
        FAPI_TRY(mss::exp::callout_fw_commit_no_doorbell( i_target, l_rc),
                 "exp_fw_update: getRSP() failed for flash_commit on %s!",
                 mss::c_str(i_target) );

        // Check if cmd was successful
        FAPI_TRY(mss::exp::bupg::check_response(i_target, response, flash_commit_cmd, i_image_sz),
                 "exp_fw_update: error response for flash_commit on %s!",
                 mss::c_str(i_target) );
    }

    FAPI_INF("%s Completed committing image", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief host_fw_command_struct structure setup for flash_write
/// @param[in] i_target OCMB target that will be acted upon with this command
/// @param[in] i_binary_size the total size of the binary image
/// @param[in] i_seq_number the sequence number of this command
/// @param[in] i_cmd_data_crc the command data CRC
/// @param[out] o_cmd the command packet to update
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_flash_write_cmd(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        const uint32_t i_binary_size,
                                        const uint16_t i_seq_number,
                                        const uint32_t i_cmd_data_crc,
                                        host_fw_command_struct& o_cmd)
{
    std::vector<uint8_t> swapped32;
    std::vector<uint8_t> cmd_args;
    std::vector<uint8_t> test16_vec;
    const uint16_t test16_value = 1;

    memset(&o_cmd, 0, sizeof(host_fw_command_struct));

    // Issue EXP_FW_BINARY_UPGRADE cmd though EXP-FW REQ buffer
    o_cmd.cmd_id = mss::exp::omi::EXP_FW_BINARY_UPGRADE;
    o_cmd.cmd_flags = mss::exp::omi::ADDITIONAL_DATA;

    // Host generated id number (returned in response packet)
    uint32_t l_counter = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_COUNTER, i_target, l_counter));
    o_cmd.request_identifier = l_counter;

    //always send a block of data
    o_cmd.cmd_length = FLASH_WRITE_BLOCK_SIZE;

    o_cmd.cmd_crc = i_cmd_data_crc;
    o_cmd.host_work_area = 0;
    o_cmd.cmd_work_area = 0;
    memset(o_cmd.padding, 0, sizeof(o_cmd.padding));

    //populate command arguments using correct endian byte ordering
    //NOTE: putCMD can not do the byte ordering of the command_arguments
    //      field for us.

    //sub-command id is single byte.  Never requires byte-swapping.
    cmd_args.push_back(bupg::SUB_CMD_WRITE);

    //forceCrctEndian can only handle 1, 2, 4, and 8 byte integers, so
    //for the flash_binary_size field, which is a 3 byte integer, treat
    //it as a 4 byte value and shift result right or left one byte
    //depending on if it is little or big endian.
    FAPI_TRY(mss::exp::ib::forceCrctEndian(i_binary_size, swapped32));

    // Test for big or little endian value on a known value (0x1)
    FAPI_TRY(mss::exp::ib::forceCrctEndian(test16_value, test16_vec));

    //if the least significant byte ended up in byte 0, then the
    //result is a little endian value.
    if(test16_vec[0] == 1)
    {
        //use first 3 bytes of 4 byte value
        cmd_args.insert(cmd_args.end(), swapped32.begin(), swapped32.end() - 1);
    }
    else //big endian
    {
        //use last 3 bytes of 4 byte value
        cmd_args.insert(cmd_args.end(), swapped32.begin() + 1, swapped32.end());
    }

    //add the sequence number
    FAPI_TRY(mss::exp::ib::forceCrctEndian(i_seq_number, cmd_args));

    //copy cmd_args vector into command_args array
    std::copy(cmd_args.begin(), cmd_args.end(), &o_cmd.command_argument[0]);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the command_argument fields for flash_commit sub-command
///        in the correct endianness.
///
/// @param[in] i_target OCMB target that will be acted upon with this command
/// @param[out] o_cmd the command packet to update
///
fapi2::ReturnCode setup_flash_commit_cmd(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    host_fw_command_struct& o_cmd)
{
    memset(&o_cmd, 0, sizeof(host_fw_command_struct));

    // Issue EXP_FW_BINARY_UPGRADE cmd though EXP-FW REQ buffer
    o_cmd.cmd_id = mss::exp::omi::EXP_FW_BINARY_UPGRADE;
    o_cmd.cmd_flags = 0;

    // Retrieve a unique sequence id for this transaction
    uint32_t l_counter = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_COUNTER, i_target, l_counter));
    o_cmd.request_identifier = l_counter;
    o_cmd.cmd_length = 0;

    o_cmd.cmd_crc = 0xffffffff;
    o_cmd.host_work_area = 0;
    o_cmd.cmd_work_area = 0;
    memset(o_cmd.padding, 0, sizeof(o_cmd.padding));

    // Set the sub-command ID in the command argument field to FLASH_COMMIT
    o_cmd.command_argument[0] = bupg::SUB_CMD_COMMIT;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Callouts out a specific error if the FW write command does not receive a doorbell
/// @param[in] i_target OCMB target that will be acted upon with this command
/// @param[in] i_seq_num the number of sequences ran in the FW burn process
/// @param[out] io_rc the ReturnCode to check and log
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode callout_fw_write_no_doorbell(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_seq_num,
        fapi2::ReturnCode& io_rc)
{
    // If we have the no-doorbell RC, log it and then assert out with our specific error
    if(uint64_t(io_rc) == uint64_t(fapi2::RC_EXP_INBAND_RSP_NO_DOORBELL))
    {
        uint32_t l_partition_id = 0;
        uint32_t l_fw_version_a = 0;
        uint32_t l_fw_version_b = 0;

        FAPI_TRY(mss::attr::get_exp_fw_partition_id(i_target, l_partition_id));
        FAPI_TRY(mss::attr::get_exp_fw_version_a(i_target, l_fw_version_a));
        FAPI_TRY(mss::attr::get_exp_fw_version_b(i_target, l_fw_version_b));

        fapi2::logError(io_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        io_rc = fapi2::FAPI2_RC_SUCCESS;

        // Now log the specific error for the FW write command
        FAPI_ASSERT(false,
                    fapi2::EXP_FW_UPDATE_WRITE_NO_DOORBELL()
                    .set_OCMB_TARGET(i_target)
                    .set_SEQUENCE_NUMBER(i_seq_num)
                    .set_FW_PARTITION_ID(l_partition_id)
                    .set_FW_VERSION_A(l_fw_version_a)
                    .set_FW_VERSION_B(l_fw_version_b)
                    .set_EXP_ACTIVE_LOG_SIZE(4096),
                    "%s FW write failed by not finding a doorbell", mss::c_str(i_target));
    }

    return io_rc;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Callouts out a specific error if the FW commit command does not receive a doorbell
/// @param[in] i_target OCMB target that will be acted upon with this command
/// @param[out] io_rc the ReturnCode to check and log
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode callout_fw_commit_no_doorbell(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        fapi2::ReturnCode& io_rc)
{
    // If we have the no-doorbell RC, log it and then assert out with our specific error
    if(uint64_t(io_rc) == uint64_t(fapi2::RC_EXP_INBAND_RSP_NO_DOORBELL))
    {
        uint32_t l_partition_id = 0;
        uint32_t l_fw_version_a = 0;
        uint32_t l_fw_version_b = 0;

        FAPI_TRY(mss::attr::get_exp_fw_partition_id(i_target, l_partition_id));
        FAPI_TRY(mss::attr::get_exp_fw_version_a(i_target, l_fw_version_a));
        FAPI_TRY(mss::attr::get_exp_fw_version_b(i_target, l_fw_version_b));

        fapi2::logError(io_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        io_rc = fapi2::FAPI2_RC_SUCCESS;

        // Now log the specific error for the FW write command
        FAPI_ASSERT(false,
                    fapi2::EXP_FW_UPDATE_COMMIT_NO_DOORBELL()
                    .set_OCMB_TARGET(i_target)
                    .set_FW_PARTITION_ID(l_partition_id)
                    .set_FW_VERSION_A(l_fw_version_a)
                    .set_FW_VERSION_B(l_fw_version_b)
                    .set_EXP_ACTIVE_LOG_SIZE(4096),
                    "%s FW commit failed by not finding a doorbell", mss::c_str(i_target));
    }

    return io_rc;
fapi_try_exit:
    return fapi2::current_err;
}

} // ns exp
} // ns mss
