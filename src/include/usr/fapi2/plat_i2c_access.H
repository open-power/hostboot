/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_i2c_access.H $                     */
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
/// @file plat_i2c_access.H
///
/// @brief Platform i2c-access definitions
///

#ifndef _FAPI2_PLAT_I2CACCESS_H_
#define _FAPI2_PLAT_I2CACCESS_H_

namespace fapi2
{

  /**
   * @brief Platform-level implementation of getI2c()
   * @param[in]  i_target     FAPI HW target to operate on.
   * @param[in]  i_get_size   Size that getI2c will read from the HW target.
   * @param[in]  i_cfgData    Buffer that holds data to write to the HW target.
   *                          May be empty if no address/command is required
   *                          before the read.
   * @param[out] o_data       Buffer that holds data read from HW target.
   * @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
   */
  ReturnCode platGetI2c( const Target<TARGET_TYPE_ALL>& i_target,
                         const size_t i_get_size,
                         const std::vector<uint8_t>& i_cfgData,
                         std::vector<uint8_t>& o_data );

  /**
   * @brief Platform-level implementation of putI2c()
   * @param[in] i_target     FAPI HW target to operate on.
   * @param[in] i_data       Buffer that holds data to write to the HW target.
   * @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
   */
  ReturnCode platPutI2c( const Target<TARGET_TYPE_ALL>& i_target,
                         const std::vector<uint8_t>& i_data );

};
#endif // _FAPI2_PLAT_I2CACCESS_H_
