/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/i2c_access.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file i2c_access.H
///
/// @brief Hardware access functions that needs to be specialized for
/// platform implementation.
///

#ifndef _FAPI2_I2CACCESS_H_
#define _FAPI2_I2CACCESS_H_

#include <fapi2_i2c_access.H>
#include <plat_i2c_access.H>

namespace fapi2
{

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------
/**
 * @brief Platform-level implementation of getI2c()
 * @tparam K the type (Kind) of target, from i_target
 * @param[in]  i_target     HW target to operate on.
 * @param[in]  i_get_size   Size that getI2c will read from the HW target.
 * @param[in]  i_data       Buffer that holds data to write to the HW target.
 *                          May be empty if no address/command is required
 *                          before the read.
 * @param[out] o_data       Buffer that holds data read from HW target.
 * @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
 */
template< TargetType K >
inline ReturnCode getI2c(const Target<K>& i_target,
                         const size_t i_get_size,
                         const std::vector<uint8_t>& i_data,
                         std::vector<uint8_t>& o_data)
{
    return platGetI2c(i_target, i_get_size, i_data, o_data);
}


/**
 * @brief Platform-level implementation of putI2c()
 * @tparam K the type (Kind) of target, from i_target
 * @param[in] i_target     HW target to operate on.
 * @param[in] i_data       Buffer that holds data to write to the HW target.
 * @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
 */
template< TargetType K >
inline ReturnCode putI2c(const Target<K>& i_target,
                         const std::vector<uint8_t>& i_data)
{
    return platPutI2c(i_target, i_data);
}

};

#endif // _FAPI2_I2CACCESS_H_
