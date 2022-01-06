/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/spd_access/mds_i2c_addr_get.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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

// SPD byte address that contains the memory type of the DDIMM
constexpr uint8_t SPD_MEM_TYPE_ADDR = 2;

// The memory type value to indicate the SPD format for an MDS, the same format as DDR4
constexpr uint8_t SPD_MDS_MEM_TYPE = 0x0C;

// SPD byte address that contains the module type of the DDIMM
constexpr uint8_t SPD_MOD_TYPE_ADDR = 3;

// The module type value to indicate working with an MDS DDIMM
constexpr uint8_t SPD_MDS_MOD_TYPE = 0xBA;

// SPD byte address for the Registered Clock Drivers (RCD)
constexpr uint16_t SPD_RCD_ADDR = 264;

// The Registered Clock Drivers (RCD) value to indicate that the DDIMM is an MDS
constexpr uint8_t SPD_MDS_RCD_VALUE = 0x15;

// Invalid return value if an issue retrieving the MDS I2C address
constexpr uint8_t SPD_INVALID_I2C_ADDR = 0xFF;

// SPD byte address that contains the MDS controller I2C address
constexpr uint16_t SPD_MDS_I2C_ADDR = 415;

///
/// @brief Get the mds i2c address from the given spd
///
/// @param[in] i_spd SPD binary containing DDR JEDEC and the extended DDIMM portion
/// @return uint8_t I2C address for MDS controller
///                 or return 0xFF(SPD_INVALID_I2C_ADDR) if SPD is not for an MDS DDIMM.
///
inline uint8_t get_mds_i2c_addr(const char* i_spd)
{
    // Default to invalid until proven otherwise
    uint8_t l_mdsI2cAddress = SPD_INVALID_I2C_ADDR;

    // If SPD belongs to a DDIMM of MDS memory type, then retrieve I2C address
    if (  (SPD_MDS_MEM_TYPE == i_spd[SPD_MEM_TYPE_ADDR]) &&
          (SPD_MDS_MOD_TYPE == i_spd[SPD_MOD_TYPE_ADDR]) &&
          (SPD_MDS_RCD_VALUE == i_spd[SPD_RCD_ADDR]) )
    {
        l_mdsI2cAddress = uint8_t(i_spd[SPD_MDS_I2C_ADDR]);
    }

    return l_mdsI2cAddress;
}

#endif
