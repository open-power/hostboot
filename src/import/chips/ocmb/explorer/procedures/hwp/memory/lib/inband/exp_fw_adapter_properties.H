/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/exp_fw_adapter_properties.H $ */
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
/// @file exp_fw_adapter_properties.H
/// @brief implement EXP_FW_ADAPTER_PROPERTIES_GET command
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: MSS

#ifndef  _EXP_FW_ADAPTER_PROPERTIES_GET_H_
#define  _EXP_FW_ADAPTER_PROPERTIES_GET_H_

#include <fapi2.H>
#include <lib/inband/exp_inband.H>
#include <exp_data_structs.H>

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
/// @return Success iff successful
///
fapi2::ReturnCode process_fw_adapter_properties_image_version(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target,
        const fw_adapter_properties_struct& i_fw_adapter_data,
        const char i_image_number,
        const uint64_t i_image_index);

///
/// @brief Helper function to print fw_adapter_properties_struct data and write to attributes
/// @param[in] i_target The OCMB Target
/// @param[in] i_fw_adapter_data The response struct from OCMB
/// @return Success iff successful
///
fapi2::ReturnCode process_fw_adapter_properties(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const fw_adapter_properties_struct& i_fw_adapter_data);

///
/// @brief Create a FW_ADAPTER_PROPERTIES_GET command
/// @param[in] i_target The OCMB Target
/// @param[in,out] io_cmd the command data
/// @return Success iff successful
///
fapi2::ReturnCode setup_fw_adapter_properties_cmd(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        host_fw_command_struct& io_cmd);

///
/// @brief Convert fw_adapter_properties response structure to a fw_adapter_properties_struct
/// @param[in,out] io_data vector of little endian data
/// @param[out] o_response response structure
/// @return Success iff successful
///
fapi2::ReturnCode fw_adapter_properties_struct_from_little_endian(
    std::vector<uint8_t>& io_data,
    fw_adapter_properties_struct& o_response);

///
/// @brief Convert fw_adapter_properties response structure to a fw_adapter_properties_struct
/// @param[in] i_target OCMB target on which to operate
/// @param[in,out] io_data little endian data to process
/// @param[out] o_response response structure
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
/// @note helper function to allow for checking FFDC
///
fapi2::ReturnCode fw_adapter_properties_struct_from_little_endian(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    std::vector<uint8_t>& io_data,
    fw_adapter_properties_struct& o_response);

///
/// @brief Run the FW_ADAPTER_PROPERTIES_GET command and store the results in attributes
/// @param[in] i_target The OCMB Target
/// @return Success iff successful
///
fapi2::ReturnCode run_fw_adapter_properties_get(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

} // ns ib
} // ns exp
} // ns mss

#endif
