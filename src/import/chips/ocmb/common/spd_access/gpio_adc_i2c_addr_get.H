/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/spd_access/gpio_adc_i2c_addr_get.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file gpio_adc_i2c_addr_get.H
/// @brief Function to get GPIO/ADC i2c addresses given target REL_POS
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Owner: Dan Crowell <dcrowell@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __GPIO_ADC_I2C_ADDR_GET__
#define __GPIO_ADC_I2C_ADDR_GET__

#include <vector>

// Mapping from REL_POS ID to GPIO/ADC address
static const std::vector<uint8_t> GPIO_ADC_I2C_ADDR_VECTOR =
{
    0x20, // 0 = ADC1
    0x2E, // 1 = ADC2
    0x70, // 2 = GPIO1
    0x7E, // 3 = GPIO2
};

// 4U DDIMM bytes
constexpr uint8_t MEM_DDR4  = 0xC;
constexpr uint8_t MEM_DDIMM = 0xA;
constexpr uint8_t MEM_4U    = 0x80;
// SPD bytes to check the various details of the DIMM
constexpr uint16_t SPD_DDR_BYTE       = 2;
constexpr uint16_t SPD_DIMM_TYPE_BYTE = 3;
constexpr uint16_t SPD_DIMM_SIZE_BYTE = 193;

///
/// @brief Get the GPIO/ADC i2c address for the given REL_POS
///
/// @param[in] i_spd SPD binary
/// @param[in] i_rel_pos REL_POS of GENERICI2CSLAVE target (0-3)
/// @return uint8_t I2C address of the device for the given rel pos
///
inline uint8_t get_gpio_adc_i2c_addr(uint8_t const* const i_spd, const uint8_t i_rel_pos)
{
    // Out of range, just return 0. Failsafe so we don't segfault
    // The caller is responsible for calling this with a valid ID
    if (i_rel_pos >= GPIO_ADC_I2C_ADDR_VECTOR.size())
    {
        return 0;
    }

    // Check the SPD to see which type of DIMM this is. GPIO devices only exist for 4U DDIMMs.
    if ( !((i_spd[SPD_DDR_BYTE] == MEM_DDR4)
           && (i_spd[SPD_DIMM_TYPE_BYTE] == MEM_DDIMM)
           && (i_spd[SPD_DIMM_SIZE_BYTE] == MEM_4U)))
    {
        // This is not a DDR4 4U DDIMM which means there isn't a GPIO device. Return 0 and let caller handle.
        return 0;
    }

    return GPIO_ADC_I2C_ADDR_VECTOR[i_rel_pos];
}

#endif
