/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/exp_fw_adapter_properties.C $ */
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
/// @file exp_fw_adapter_properties.C
/// @brief implement EXP_FW_ADAPTER_PROPERTIES_GET command
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: MSS

#include <lib/shared/exp_consts.H>
#include <lib/inband/exp_inband.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/endian_utils.H>
#include <lib/inband/exp_fw_adapter_properties.H>
#include <mss_explorer_attribute_setters.H>

namespace mss
{

namespace exp
{

namespace ib
{

///
/// @brief Helper function to print a single entry in fw_adapter_properties_struct.fw_ver_str
/// @param[in] i_target The OCMB Target
/// @param[in] i_fw_adapter_data The response struct from OCMB
/// @param[in] i_image_number The ASCII image number to be printed
/// @param[in] i_image_index The index of the version to be printed in the i_fw_adapter_data.fw_ver_str array
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode process_fw_adapter_properties_image_version(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target,
        const fw_adapter_properties_struct& i_fw_adapter_data,
        const char i_image_number,
        const uint64_t i_image_index)
{
    auto l_image_version = i_fw_adapter_data.fw_ver_str[i_image_index];

    if (i_image_number == 'A')
    {
        FAPI_TRY( mss::attr::set_exp_fw_version_a(i_target, l_image_version.build_num) );
    }
    else
    {
        FAPI_TRY( mss::attr::set_exp_fw_version_b(i_target, l_image_version.build_num) );
    }

    FAPI_INF("%s image number: %c", mss::c_str(i_target), i_image_number);
    FAPI_INF("%s major: %d", mss::c_str(i_target), l_image_version.major);
    FAPI_INF("%s minor: %d", mss::c_str(i_target), l_image_version.minor);
    FAPI_INF("%s build_patch: %d", mss::c_str(i_target), l_image_version.build_patch);
    FAPI_INF("%s build_num: %08d", mss::c_str(i_target), l_image_version.build_num);
    // Note build_date is technically a hex value, but reads as a MMDDYYYY date so no '0x' necessary
    FAPI_INF("%s build_date: %08x", mss::c_str(i_target), l_image_version.build_date);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to print fw_adapter_properties_struct data and write to attributes
/// @param[in] i_target The OCMB Target
/// @param[in] i_fw_adapter_data The response struct from OCMB
/// @param[in] i_flash_auth_info SPI flash authorization response
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode process_fw_adapter_properties(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const fw_adapter_properties_struct& i_fw_adapter_data,
        const spi_flash_plat_auth_info_struct& i_flash_auth_info)
{
    // boot_partition_id is stored as an ASCII 'A' or 'B'.
    const auto boot_image_number = static_cast<char>(i_fw_adapter_data.boot_partion_id);

    FAPI_TRY( mss::attr::set_exp_fw_partition_id(i_target, i_fw_adapter_data.boot_partion_id) );

    FAPI_INF("%s fw_number_of_images: %d", mss::c_str(i_target), i_fw_adapter_data.fw_number_of_images);
    FAPI_INF("%s boot_partion_id: %c", mss::c_str(i_target), boot_image_number);

    // The first version in the struct is for the partition we booted
    // from, the second is for the other partition. They are not
    // stored in "alphabetical order". We call the same function twice
    // to print the information for each partition. The first time we
    // call with the image we booted from. The second time we use the
    // ternary to decide which is the other image.
    FAPI_TRY( process_fw_adapter_properties_image_version(i_target, i_fw_adapter_data, boot_image_number, 0) );
    FAPI_TRY( process_fw_adapter_properties_image_version(i_target, i_fw_adapter_data, boot_image_number == 'A' ? 'B' : 'A',
              1) );

    FAPI_INF("%s ram_size_in_bytes: 0x%08X", mss::c_str(i_target), i_fw_adapter_data.ram_size_in_bytes);
    FAPI_INF("%s chip_version: 0x%08X", mss::c_str(i_target), i_fw_adapter_data.chip_version);
    FAPI_INF("%s spi_flash_id: 0x%08X", mss::c_str(i_target), i_fw_adapter_data.spi_flash_id);
    FAPI_INF("%s spi_flash_sector_size: 0x%08X", mss::c_str(i_target), i_fw_adapter_data.spi_flash_sector_size);
    FAPI_INF("%s spi_flash_size: 0x%08X", mss::c_str(i_target), i_fw_adapter_data.spi_flash_size);
    FAPI_INF("%s error_buffer_size: 0x%08X", mss::c_str(i_target), i_fw_adapter_data.error_buffer_size);

    FAPI_INF("%s active_image_index: 0x%02X", mss::c_str(i_target), i_flash_auth_info.active_image_index);
    FAPI_INF("%s red_image_index: 0x%02X", mss::c_str(i_target), i_flash_auth_info.red_image_index);

    for (int i = 0; i < FW_ADAPTER_MAX_FW_IMAGE; ++i)
    {
        FAPI_INF("%s failed_authentication[%d]: 0x%02X", mss::c_str(i_target), i, i_flash_auth_info.failed_authentication[i]);
        FAPI_INF("%s uecc_detected[%d]: 0x%02X", mss::c_str(i_target), i, i_flash_auth_info.uecc_detected[i]);
    }

    FAPI_INF("%s uecc_compare: 0x%02X", mss::c_str(i_target), i_flash_auth_info.uecc_compare);
    FAPI_INF("%s image_updated: 0x%02X", mss::c_str(i_target), i_flash_auth_info.image_updated);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Create a FW_ADAPTER_PROPERTIES_GET command
/// @param[in] i_target The OCMB Target
/// @param[in,out] io_cmd the command data
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_fw_adapter_properties_cmd(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        host_fw_command_struct& io_cmd)
{
    memset(&io_cmd, 0, sizeof(host_fw_command_struct));

    io_cmd.cmd_id = mss::exp::omi::EXP_FW_ADAPTER_PROPERTIES_GET;
    io_cmd.cmd_flags = 0x00; // no additional data
    io_cmd.cmd_length = 0x00000000; // length of addditional data
    io_cmd.cmd_crc = 0xFFFFFFFF; // CRC-32 of no additional data
    io_cmd.host_work_area = 0x00000000;
    io_cmd.cmd_work_area = 0x00000000;

    // Retrieve a unique sequence id for this transaction
    uint32_t l_counter = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_COUNTER, i_target, l_counter));
    io_cmd.request_identifier = l_counter;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Convert fw_adapter_properties response structure to a fw_adapter_properties_struct
/// @param[in,out] io_data vector of little endian data
/// @param[out] o_response response structure
/// @param[out] o_flash_auth_info SPI flash authorization response (will populate if available)
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode fw_adapter_properties_struct_from_little_endian(
    std::vector<uint8_t>& io_data,
    fw_adapter_properties_struct& o_response,
    spi_flash_plat_auth_info_struct& o_flash_auth_info)
{
    uint32_t l_idx = 0;

    uint32_t l_response_fw_number_of_images = 0;
    uint32_t l_response_boot_partion_id = 0;
    uint32_t l_response_fw_ver_str_major[FW_ADAPTER_MAX_FW_IMAGE] = {0};
    uint32_t l_response_fw_ver_str_minor[FW_ADAPTER_MAX_FW_IMAGE] = {0};
    uint32_t l_response_fw_ver_str_build_patch[FW_ADAPTER_MAX_FW_IMAGE] = {0};
    uint32_t l_response_fw_ver_str_build_num[FW_ADAPTER_MAX_FW_IMAGE] = {0};
    uint32_t l_response_fw_ver_str_build_date[FW_ADAPTER_MAX_FW_IMAGE] = {0};
    uint32_t l_response_ram_size_in_bytes = 0;
    uint32_t l_response_chip_version = 0;
    uint32_t l_response_spi_flash_id = 0;
    uint32_t l_response_spi_flash_sector_size = 0;
    uint32_t l_response_spi_flash_size = 0;
    uint32_t l_response_error_buffer_size = 0;
    uint8_t l_response_active_image_index = 0;
    uint8_t l_response_red_image_index = 0;
    uint8_t l_response_failed_authentication[FW_ADAPTER_MAX_FW_IMAGE] = {0};
    uint8_t l_response_uecc_detected[FW_ADAPTER_MAX_FW_IMAGE] = {0};
    uint8_t l_response_uecc_compare = 0;
    uint8_t l_response_image_updated = 0;

    // Read out response into local variables first so we don't change o_response if we fail
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_fw_number_of_images));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_boot_partion_id));

    for (int i = 0; i < FW_ADAPTER_MAX_FW_IMAGE; ++i)
    {
        FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_fw_ver_str_major[i]));
        FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_fw_ver_str_minor[i]));
        FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_fw_ver_str_build_patch[i]));
        FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_fw_ver_str_build_num[i]));
        FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_fw_ver_str_build_date[i]));
    }

    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_ram_size_in_bytes));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_chip_version));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_spi_flash_id));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_spi_flash_sector_size));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_spi_flash_size));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_error_buffer_size));

    // If we have more data returned that means we have the new struct appended (spi_flash_plat_auth_info_struct),
    // so grab those fields too
    if (io_data.size() > sizeof(fw_adapter_properties_struct))
    {
        FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_active_image_index));
        FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_red_image_index));

        for (int i = 0; i < FW_ADAPTER_MAX_FW_IMAGE; ++i)
        {
            FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_failed_authentication[i]));
        }

        for (int i = 0; i < FW_ADAPTER_MAX_FW_IMAGE; ++i)
        {
            FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_uecc_detected[i]));
        }

        FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_uecc_compare));
        FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_image_updated));
    }

    // Now copy the local values into o_response
    o_response.fw_number_of_images = l_response_fw_number_of_images;
    o_response.boot_partion_id = l_response_boot_partion_id;

    for (int i = 0; i < FW_ADAPTER_MAX_FW_IMAGE; ++i)
    {
        o_response.fw_ver_str[i].major = l_response_fw_ver_str_major[i];
        o_response.fw_ver_str[i].minor = l_response_fw_ver_str_minor[i];
        o_response.fw_ver_str[i].build_patch = l_response_fw_ver_str_build_patch[i];
        o_response.fw_ver_str[i].build_num = l_response_fw_ver_str_build_num[i];
        o_response.fw_ver_str[i].build_date = l_response_fw_ver_str_build_date[i];
    }

    o_response.ram_size_in_bytes = l_response_ram_size_in_bytes;
    o_response.chip_version = l_response_chip_version;
    o_response.spi_flash_id = l_response_spi_flash_id;
    o_response.spi_flash_sector_size = l_response_spi_flash_sector_size;
    o_response.spi_flash_size = l_response_spi_flash_size;
    o_response.error_buffer_size = l_response_error_buffer_size;

    o_flash_auth_info.active_image_index = l_response_active_image_index;
    o_flash_auth_info.red_image_index = l_response_red_image_index;

    for (int i = 0; i < FW_ADAPTER_MAX_FW_IMAGE; ++i)
    {
        o_flash_auth_info.failed_authentication[i] = l_response_failed_authentication[i];
        o_flash_auth_info.uecc_detected[i] = l_response_uecc_detected[i];
    }

    o_flash_auth_info.uecc_compare = l_response_uecc_compare;
    o_flash_auth_info.image_updated = l_response_image_updated;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Convert fw_adapter_properties response structure to a fw_adapter_properties_struct
/// @param[in] i_target OCMB target on which to operate
/// @param[in,out] io_data little endian data to process
/// @param[out] o_response response structure
/// @param[out] o_flash_auth_info SPI flash authorization response (will populate if available)
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
/// @note helper function to allow for checking FFDC
///
fapi2::ReturnCode fw_adapter_properties_struct_from_little_endian(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    std::vector<uint8_t>& io_data,
    fw_adapter_properties_struct& o_response,
    spi_flash_plat_auth_info_struct& o_flash_auth_info)
{
    fapi2::current_err = fw_adapter_properties_struct_from_little_endian(io_data, o_response, o_flash_auth_info);

    // Re-assert here so we capture the OCMB target (lower level code uses FAPI_SYSTEM)
    FAPI_ASSERT(fapi2::current_err == fapi2::FAPI2_RC_SUCCESS,
                fapi2::EXP_INBAND_LE_DATA_RANGE()
                .set_TARGET(i_target)
                .set_FUNCTION(mss::exp::READ_FW_ADAPTER_PROPERTIES_STRUCT)
                .set_DATA_SIZE(io_data.size())
                .set_MAX_INDEX(sizeof(fw_adapter_properties_struct)),
                "%s Failed to convert from data to fw_adapter_properties_struct data size %u expected size %u",
                mss::c_str(i_target), io_data.size(), sizeof(fw_adapter_properties_struct));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Run the FW_ADAPTER_PROPERTIES_GET command and store the results in attributes
/// @param[in] i_target The OCMB Target
/// @param[out] o_image_a_good will be set to false if authentication failed for image A
/// @param[out] o_image_b_good will be set to false if authentication failed for image B
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode run_fw_adapter_properties_get(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        bool& o_image_a_good,
        bool& o_image_b_good)
{
    constexpr uint8_t IMAGE_A = 0;
    constexpr uint8_t IMAGE_B = 1;

    host_fw_command_struct l_cmd;
    host_fw_response_struct l_rsp;
    std::vector<uint8_t> l_rsp_data;
    fw_adapter_properties_struct l_fw_adapter_data;
    spi_flash_plat_auth_info_struct l_spi_flash_auth_data;

    // Create a fw_adapter_properties command
    FAPI_TRY(setup_fw_adapter_properties_cmd(i_target, l_cmd));

    FAPI_INF("Running FW_ADAPTER_PROPERTIES_GET on %s", mss::c_str(i_target));

    // send the command
    FAPI_TRY( mss::exp::ib::putCMD(i_target, l_cmd),
              "Error from putCMD for %s", mss::c_str(i_target) );

    // grab the response
    FAPI_TRY( mss::exp::ib::getRSP(i_target, l_rsp, l_rsp_data),
              "Error from getRSP for %s", mss::c_str(i_target) );

    // NOTE: the Simics model used in HB CI returns an incorrect value for response_length
    //       so skip this check in Hostboot until it gets fixed (SW493885)
#ifndef __HOSTBOOT_MODULE
    // Check for a valid data response length
    // Note: Explorer now has two potential response lengths depending upon the FW version
    // Unfortunately, to figure out the FW version, you have to run FW_ADAPTER_PROPERTIES
    // As such, we only check if we have enough data for the bare minimum at this point
    // This way, we do not fail out
    FAPI_ASSERT((l_rsp.response_length >= sizeof(fw_adapter_properties_struct)),
                fapi2::MSS_EXP_INVALID_FW_ADAPTER_PROPERTIES_RSP_DATA_LENGTH()
                .set_OCMB_TARGET(i_target)
                .set_EXPECTED_LENGTH(sizeof(fw_adapter_properties_struct))
                .set_ACTUAL_LENGTH(l_rsp.response_length),
                "%s FW_ADAPTER_PROPERTIES response data buffer size 0x%x did not match expected size 0x%x",
                mss::c_str(i_target), l_rsp.response_length, sizeof(fw_adapter_properties_struct));
#endif

    // Check if cmd was successful
    FAPI_TRY( check::response(i_target, l_rsp, l_cmd) );

    // Now convert the little endian response data into big endian
    FAPI_TRY( fw_adapter_properties_struct_from_little_endian(l_rsp_data, l_fw_adapter_data, l_spi_flash_auth_data) );

    // Print out the response values and store in attributes
    FAPI_TRY( process_fw_adapter_properties(i_target, l_fw_adapter_data, l_spi_flash_auth_data) );

    o_image_a_good = l_spi_flash_auth_data.failed_authentication[IMAGE_A] == 0;
    o_image_b_good = l_spi_flash_auth_data.failed_authentication[IMAGE_B] == 0;

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Run the FW_ADAPTER_PROPERTIES_GET command and store the results in attributes
/// @param[in] i_target The OCMB Target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode run_fw_adapter_properties_get(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    bool dummy_a;
    bool dummy_b;

    return run_fw_adapter_properties_get(i_target, dummy_a, dummy_b);
}

} // ns ib
} // ns exp
} // ns mss
