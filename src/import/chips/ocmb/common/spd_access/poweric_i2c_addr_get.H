/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/spd_access/poweric_i2c_addr_get.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file poweric_i2c_addr_get.H
/// @brief Function to get POWER_IC i2c addresses given target REL_POS
///
// *HWP HWP Owner:
// *HWP HWP Owner: Dan Crowell <dcrowell@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __POWERIC_I2C_ADDR_GET__
#define __POWERIC_I2C_ADDR_GET__

#include <vector>
#include <ddimm_spd_common.H>

// Since we'll pass in numbers 0-3 we'll denote the Power IC as such,
//  these are the relative FAPI target numbers that correspond to
//  the i_pmic_id input parm
constexpr uint8_t POWERIC0 = 0;
constexpr uint8_t POWERIC1 = 1;
constexpr uint8_t POWERIC2 = 2;
constexpr uint8_t POWERIC3 = 3;

// Mapping from POWERIC ID to SPD byte for DDR5
constexpr uint16_t SPD_POWERIC0_I2C_BYTE = 247;
constexpr uint16_t SPD_POWERIC1_I2C_BYTE = 248;
constexpr uint16_t SPD_POWERIC2_I2C_BYTE = 249;
constexpr uint16_t SPD_POWERIC3_I2C_BYTE = 250;

// Mapping from REL_POS ID to GPIO/ADC address
static const std::vector<uint16_t> DDR5_POWERIC_I2C_ADDR_VECTOR =
{
    SPD_POWERIC0_I2C_BYTE, // 0 = DT0
    SPD_POWERIC1_I2C_BYTE, // 1 = DT1
    SPD_POWERIC2_I2C_BYTE, // 2 = DT2
    SPD_POWERIC3_I2C_BYTE, // 3 = DT3
};


///
/// @brief Get the GPIO/ADC i2c address for the given REL_POS
///
/// @param[in] i_spd SPD binary
/// @param[in] i_rel_pos REL_POS of POWER_IC target (0-3)
/// @return uint8_t I2C address of the device for the given rel pos
///
inline uint8_t get_poweric_i2c_addr(uint8_t const* i_spd, const uint8_t i_rel_pos)
{
    // Out of range, just return 0. Failsafe so we don't segfault
    // The caller is responsible for calling this with a valid ID
    if (i_rel_pos >= DDR5_POWERIC_I2C_ADDR_VECTOR.size())
    {
        return DDIMM_SPD::NO_DEVICE;
    }

    // Check the SPD to see which type of DIMM this is.

    // There are no POWER_ICs on DDR4 DIMMs
    if ( i_spd[DDIMM_SPD::DDR_BYTE] == DDIMM_SPD::MEM_DDR4 )
    {
        return DDIMM_SPD::NO_DEVICE;
    }

    // DDR5 DDIMM has 4 DoubleTops on the 4U and 0 on the 2U
    if ( (i_spd[DDIMM_SPD::DDR_BYTE] == DDIMM_SPD::MEM_DDR5)
         && (i_spd[DDIMM_SPD::DIMM_TYPE_BYTE] == DDIMM_SPD::MEM_DDIMM)
         && (i_spd[DDIMM_SPD::DDR5_DIMM_SIZE_BYTE] == DDIMM_SPD::MEM_4U) )
    {
        const uint16_t l_byte = DDR5_POWERIC_I2C_ADDR_VECTOR[i_rel_pos];
        return uint8_t(i_spd[l_byte]);
    }

    return DDIMM_SPD::NO_DEVICE;
}

#endif
