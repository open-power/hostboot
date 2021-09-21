/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/exp_flash_utils.H $ */
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
/// @file exp_flash_utils.H
/// @brief implement Explorer flash programming command interface
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: MSS

#ifndef  _EXP_FLASH_UTILS_H_
#define  _EXP_FLASH_UTILS_H_

#include <fapi2.H>
#include <lib/inband/exp_inband.H>
#include <exp_data_structs.H>

namespace mss
{
namespace exp
{
namespace bupg
{

///
/// @brief Defines the sub-commands available for the EXP_FW_BINARY_UPGRADE
///        command
///
typedef enum sub_cmd_id
{
    SUB_CMD_NULL              = 0x00,
    SUB_CMD_WRITE             = 0x01,
    SUB_CMD_COMMIT            = 0x02,
    SUB_CMD_WRITE_ABORT       = 0x03,
    SUB_CMD_PART_INFO_GET     = 0x04,
    SUB_CMD_READ              = 0x05,
    SUB_CMD_PART_ERASE        = 0x06,
    SUB_CMD_MAX
} sub_cmd_id_t;

///
/// @brief Error codes for EXP_FW_BINARY_UPGRADE command
/// @note These are described in the MCHP FW doc, chapter 9
///
enum fw_binary_upgrade_rc
{
    // Device information retrieve error
    DEV_INF_ERR        = 0x05,

    // Device sector information retrieve error
    DEV_SECTOR_INF_ERR = 0x06,

    // Device erase error
    DEV_ERASE_ERR      = 0x07,

    // Write failure
    WRITE_FAIL         = 0x0C,

    // Invalid image length
    INV_IMAGE_LEN      = 0x0D,

    // Image authentication failure
    AUTH_FAIL          = 0x0E,
};

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
                                 const size_t i_image_sz);

}// ns bupg

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
    partition_info_struct& o_partition_info);

///
/// @brief host_fw_command_struct structure setup for get_partition_info
/// @param[in] i_target the OCMB_CHIP target
/// @param[out] o_cmd the command packet to update
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_partition_info_cmd(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        host_fw_command_struct& o_cmd);

///
/// @brief get the partition info from explorer
/// @param[in] i_target the OCMB_CHIP target
/// @param[out] o_partition_info the partition info structure
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode exp_get_partition_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        partition_info_struct& o_partition_info);

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
                                       host_fw_command_struct& o_cmd);

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
                                 const bool i_check_firs = true,
                                 const bool i_return_data = true);

///
/// @brief Reads Explorer SPI flash
/// @param[in] i_target the controller
/// @param[in] i_read_a set to true to read partition A (default true)
/// @param[in] i_read_b set to true to read partition B (default true)
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode exp_flash_read_test(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      const bool i_read_a = true,
                                      const bool i_read_b = true);

///
/// @brief Checks explorer response argument for a successful command
/// @param[in] i_target OCMB target
/// @param[in] i_rsp response from command
/// @param[in] i_cmd original command
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode check_flash_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const host_fw_response_struct& i_rsp,
                                       const host_fw_command_struct& i_cmd);

} // ns ib

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
        const size_t i_image_sz);

///
/// @brief Authenticate and commit a newly uploaded FW image
///
/// @param[in] i_target OCMB target that will be acted upon with this command
/// @param[in] i_image_sz size of the binary image
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode commit_fw_image(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const size_t i_image_sz);

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
                                        host_fw_command_struct& o_cmd);

///
/// @brief Sets the command_argument fields for flash_commit sub-command
///        in the correct endianness.
///
/// @param[in] i_target OCMB target that will be acted upon with this command
/// @param[out] o_cmd the command packet to update
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_flash_commit_cmd(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        host_fw_command_struct& o_cmd);

///
/// @brief Callouts out a specific error if the FW write command does not receive a doorbell
/// @param[in] i_target OCMB target that will be acted upon with this command
/// @param[in] i_seq_num the number of sequences ran in the FW burn process
/// @param[out] io_rc the ReturnCode to check and log
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode callout_fw_write_no_doorbell(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_seq_num,
        fapi2::ReturnCode& io_rc);

///
/// @brief Callouts out a specific error if the FW commit command does not receive a doorbell
/// @param[in] i_target OCMB target that will be acted upon with this command
/// @param[out] io_rc the ReturnCode to check and log
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode callout_fw_commit_no_doorbell(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        fapi2::ReturnCode& io_rc);

} // ns exp
} // ns mss

#endif
