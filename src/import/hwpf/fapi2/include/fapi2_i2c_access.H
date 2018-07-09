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
