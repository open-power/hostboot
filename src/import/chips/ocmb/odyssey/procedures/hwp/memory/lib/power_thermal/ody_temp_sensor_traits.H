/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/power_thermal/ody_temp_sensor_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
/// @file ody_temp_sensor_traits.H
/// @brief Odyssey temperature senor traits
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB, FSP, SBE
// EKB-Mirror-To: hostboot

#ifndef _ODY_TEMP_SENSOR_TRAITS_H_
#define _ODY_TEMP_SENSOR_TRAITS_H_

#include <fapi2.H>
#include <ody_scom_ody_odc.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/power_thermal/gen_temp_sensor_traits.H>

namespace mss
{
template<>
class temp_sensor_traits<mss::mc_type::ODYSSEY>
{
    public:
        // ocmb sensor cache thermal register bits for sensor temperature present, valid, and error
        static constexpr uint8_t SENSOR_PRESENT_BIT = 45;
        static constexpr uint8_t SENSOR_VALID_BIT   = 46;
        static constexpr uint8_t SENSOR_ERROR_BIT   = 47;

        // NXP SE98A temperature sensor (same for other supported vendors)
        // Temperature sensor Temperature Data Register (addr 0x05) bit definition
        // B15   B14  B13 B12  B11 B10 B9 B8 B7 B6 B5 B4 B3  B2   B1    B0
        // TCRIT HIGH LOW Sign 128 64  32 16 8  4  2  1  0.5 0.25 0.125 0.0625
        // Corresponding bit in ocmb sensor cache thermal registers (note that MSB and LSB are not swapped)
        // 48   49    50  51   52  53  54 55 56 57 58 59 60  61   62    63
        // LSB resolution is 0.0625 C (divisor is 16)
        static constexpr uint8_t SENSOR_SIGN_BIT             = 51;
        static constexpr uint8_t SENSOR_TEMP_MSB_START_VALUE = 16;
        static constexpr uint8_t SENSOR_TEMP_MSB_INT_START   = 52;
        static constexpr uint8_t SENSOR_TEMP_MSB_INT_LENGTH  =  4;
        static constexpr uint8_t SENSOR_TEMP_LSB_INT_START   = 56;
        static constexpr uint8_t SENSOR_TEMP_LSB_INT_LENGTH  =  4;
        static constexpr uint8_t SENSOR_TEMP_LSB_BIT3_BIT    = 60;
        static constexpr uint8_t SENSOR_TEMP_LSB_BIT2_BIT    = 61;
        static constexpr uint8_t SENSOR_TEMP_LSB_BIT1_BIT    = 62;
        static constexpr uint8_t SENSOR_TEMP_LSB_BIT0_BIT    = 63;
        static constexpr uint8_t SENSOR_TEMP_BIT3_VALUE_X100        =  50;
        static constexpr uint8_t SENSOR_TEMP_BIT2_VALUE_X100        =  25;
        static constexpr uint8_t SENSOR_TEMP_BIT1_VALUE_X100       =  12;
        static constexpr uint8_t SENSOR_TEMP_BIT0_VALUE_X100        =  6;
#ifndef __PPE__
        static constexpr float SENSOR_TEMP_BIT3_VALUE        =  0.5;
        static constexpr float SENSOR_TEMP_BIT2_VALUE        =  0.25;
        static constexpr float SENSOR_TEMP_BIT1_VALUE        =  0.125;
        static constexpr float SENSOR_TEMP_BIT0_VALUE        =  0.0625;
#endif

        // OCMB DTM temperature comes from scom bits 48:63
        // temperature is expressed in 1/16th degrees C
        static constexpr uint8_t DTM_SENSOR_TEMP_START_BIT   =  48;
        static constexpr uint8_t DTM_SENSOR_TEMP_BIT_LENGTH  =  16;
        static constexpr uint8_t DTM_SENSOR_TEMP_DIVISOR     =  16;

        // MicroChip EMC1412 temperature sensor for OCMB DTM workaround (read thermal diodes)
        // default range is 0 to 127 C (all temperatures >127.875 C will be reported as 127.875 C)
        // Temperature sensor External Diode High Byte Register (addr 0x01) bit definition
        // Temperature sensor External Diode Low Byte Register (addr 0x10) bit definition
        // addr 0x01                |  addr 0x10
        // B7  B6 B5 B4 B3 B2 B1 B0 |  B7  B6   B5    B4 B3 B2 B1 B0
        // 128 64 32 16  8  4  2  1 |  0.5 0.25 0.125  -  -  -  -  -
        // Corresponding bit in ocmb sensor cache thermal registers
        // 48  49 50 51 52 53 54 55 |  56  57   58    59 60 61 62 63
        static constexpr uint8_t EXT_SENSOR_TEMP_START_BIT   = 48;
        static constexpr uint8_t EXT_SENSOR_TEMP_BIT_LENGTH  = 11;
        static constexpr uint8_t EXT_SENSOR_TEMP_DIVISOR     =  8;

        // temperature sensor types
        enum temp_sensor
        {
            OCMB        = 0,
            DIMM0       = 1,
            DIMM1       = 2,
            DIMM2       = 3,
            DIMM3       = 4,
            NUM_SENSORS = 5,
        };

#ifndef __PPE__
        // temperature sensor names
        static const char* SENSOR_NAME_MAP[];

        static std::map<temp_sensor, uint64_t> SENSOR_REG_MAP;
#endif
};
} //mss ns
#endif
