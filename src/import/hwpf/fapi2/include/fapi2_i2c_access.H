/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/fapi2_i2c_access.H $            */
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
/// @file fapi2_i2c_access.H
/// @brief Common file that defines the i2c access functions that
/// platform code must implement.
///

#ifndef _FAPI2_COMMON_I2C_ACCESS_H_
#define _FAPI2_COMMON_I2C_ACCESS_H_

#include <stdint.h>
#include <vector>

#include <return_code.H>
#include <target.H>

namespace fapi2
{

/// @brief Reads data via i2c from the target
///
/// Example use (seeprom read 8 bytes w/ 2-byte address: 0x01B0):
/// std::vector<uint8_t> addr = {0x01, 0xB0};
/// std::vector<uint8_t> data;
/// size_t len = 8;
/// FAPI_TRY(getI2c(target, len, addr, data));
/// data should contain the 8 bytes starting at address 0x01B0
///
/// Example use (smbus read 5 bytes w/ 1-byte command: 0x02):
/// std::vector<uint8_t> command = {0x02};
/// std::vector<uint8_t> data;
/// size_t len = 5;
/// FAPI_TRY(getI2c(target, len, command, data));
/// data should contain 5 bytes, first byte with the data length(4)
/// remaining four bytes will be the data requested from the command
///
/// @tparam K the type (Kind) of target, from i_target
/// @tparam V the type of the target's Value, from i_target
/// @param[in]  i_target     HW target to operate on.
/// @param[in]  i_get_size   Size that getI2c will read from the HW target.
/// @param[in]  i_data       Buffer that holds data to write to the HW target.
///                          May be empty if no address/command is required
///                          before the read.
/// @param[out] o_data       Buffer that holds data read from HW target.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, typename V >
inline ReturnCode getI2c(const Target<K, V>& i_target,
                         const size_t i_get_size,
                         const std::vector<uint8_t>& i_data,
                         std::vector<uint8_t>& o_data);

/// @brief Writes data via i2c to the target.
///
/// Example use (seeprom write 4 bytes of zeros w/ 2-byte address: 0x0208):
/// std::vector<uint8_t> addr_data = {0x02, 0x08, 0x00, 0x00, 0x00, 0x00};
/// FAPI_TRY(putI2c(target, addr_data));
///
/// Example use (smbus write 1 data length byte + 4 bytes of zeros w/ 1-byte command: 0x01):
/// std::vector<uint8_t> command_data = {0x01, 0x04, 0x00, 0x00, 0x00, 0x00};
/// FAPI_TRY(putI2c(target, command_data));
///
/// @tparam K the type (Kind) of target, from i_target
/// @tparam V the type of the target's Value, from i_target
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_data       Buffer that holds data to write to the HW target.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, typename V >
inline ReturnCode putI2c(const Target<K, V>& i_target,
                         const std::vector<uint8_t>& i_data);

};

#endif // _FAPI2_COMMON_I2C_ACCESS_H_
