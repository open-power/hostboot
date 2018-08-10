/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c/exp_i2c.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include <i2c_access.H>

#include <vector>
#include <lib/i2c/exp_i2c_fields.H>

namespace mss
{
namespace exp
{
namespace i2c
{
namespace check
{

///
/// @brief Checks the I2c explorer status codes
/// @param[in] i_target the OCMB target
/// @param[in] i_cmd_id the command ID
/// @param[in] i_data data to check from EXP_FW_STATUS
///
inline fapi2::ReturnCode status_code( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      const uint8_t i_cmd_id,
                                      const std::vector<uint8_t>& i_data )
{
    // Set to a high number to make sure check for SUCCESS (== 0) isn't a fluke
    size_t l_status = ~(0);
    FAPI_TRY( status::get_status_code(i_target, i_data, l_status) );

    // Technically many cmds have their own status code decoding..but SUCCESS is always 0.
    // If it's anything else we can just look up the status code
    FAPI_ASSERT( l_status == status_codes::SUCCESS,
                 fapi2::MSS_EXP_STATUS_CODE_UNSUCCESSFUL().
                 set_TARGET(i_target).
                 set_STATUS_CODE(l_status).
                 set_CMD_ID(i_cmd_id),
                 "Status code did not return SUCCESS (%d), received (%d) for %s",
                 status_codes::SUCCESS, l_status, mss::c_str(i_target) );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}// check

///
/// @brief EXP_FW_STATUS setup helper function - useful for testing
/// @param[out] o_size the size of data
/// @param[out] o_cmd_id the explorer command ID
///
inline void fw_status_setup(size_t& o_size,
                            std::vector<uint8_t>& o_cmd_id)
{
    o_size = FW_STATUS_BYTE_LEN;
    o_cmd_id.assign({FW_STATUS});
}

///
/// @brief EXP_FW_STATUS
/// @param[in] i_target the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode fw_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    // Retrieve setup data
    size_t l_size = 0;
    std::vector<uint8_t> l_cmd_id;
    fw_status_setup(l_size, l_cmd_id);

    // Get data and check for errors
    {
        std::vector<uint8_t> l_data;
        FAPI_TRY(fapi2::getI2c(i_target, l_size, l_cmd_id, l_data));
        FAPI_TRY( check::status_code(i_target, l_cmd_id[0], l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief EXP_FW_BOOT_CONFIG setup
/// @param[in,out] io_data the data to go to boot config
///
inline void boot_config_setup(std::vector<uint8_t>& io_data)

{
    io_data.insert(io_data.begin(), FW_BOOT_CONFIG);
}

///
/// @brief EXP_FW_BOOT_CONFIG
/// @param[in] i_target the OCMB target
/// @param[in] i_data the data to write
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode boot_config(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     const std::vector<uint8_t>& i_data)
{
    // Retrieve setup data
    std::vector<uint8_t> l_configured_data(i_data);
    boot_config_setup(l_configured_data);

    // Get data and check for errors
    FAPI_TRY(fapi2::putI2c(i_target, l_configured_data));
    FAPI_TRY(fw_status(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if the I2C interface returns an ACK
/// @param[in] i_target the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode is_ready(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    // We send a simple but valid command to poll the I2C
    // Arbitrarily send an EXP_FW_STATUS command id
    size_t l_size = 0;
    std::vector<uint8_t> l_cmd_id;
    fw_status_setup(l_size, l_cmd_id);

    // We just ignore the data.  We'll see FAPI2_RC_SUCCESS if
    // the I2C returns an ACK.
    std::vector<uint8_t> l_data;
    return fapi2::getI2c(i_target, l_size, l_cmd_id, l_data);
}

}// i2c
}// exp
}// mss

#endif
