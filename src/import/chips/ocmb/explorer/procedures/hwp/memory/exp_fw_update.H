/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_fw_update.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file exp_fw_update.H
/// @brief Procedure declaration to update explorer firmware
///
// *HWP HWP Owner: Glenn Miles <milesg@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __MSS_EXP_FW_UPDATE__
#define __MSS_EXP_FW_UPDATE__

#include <fapi2.H>
#include <exp_data_structs.H>

// Required for Cronus
typedef fapi2::ReturnCode (*exp_fw_update_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        const uint8_t*, const size_t);

extern "C"
{

///
/// @brief Updates explorer firmware
/// @param[in] i_target the controller
/// @param[in] i_image_ptr pointer to the binary image
/// @param[in] i_image_sz size of the binary image
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode exp_fw_update(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const uint8_t* i_image_ptr, const size_t i_image_sz);

}// extern C

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

}// ns exp
}// ns mss

#endif
