/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/spd_access/mds_i2c_addr_get.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file mds_i2c_addr_get.H
/// @brief Function to get MDS controller i2c address given full SPD binary
///
// *HWP HWP Owner: Daniel Melnikov  <Daniel.Melnikov@ibm.com>
// *HWP HWP Owner: Dan Crowell <dcrowell@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef __MDS_I2C_ADDR_GET__
#define __MDS_I2C_ADDR_GET__

// SPD byte address that contains the MDS controller address
constexpr uint8_t SPD_MDS_I2C_BYTE = 415;

///
/// @brief Get the mds i2c address from the given spd
///
/// @param[in] i_spd SPD binary containing DDR JEDEC and the extended DDIMM portion
/// @return uint8_t I2C address for MDS controller
///
inline uint8_t get_mds_i2c_addr(const char* i_spd)
{
    return uint8_t(i_spd[SPD_MDS_I2C_BYTE]);
}

#endif
