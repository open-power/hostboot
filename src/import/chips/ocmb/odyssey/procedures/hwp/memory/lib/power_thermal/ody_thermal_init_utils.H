/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/power_thermal/ody_thermal_init_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file ody_thermal_init_utils.H
/// @brief Odyssey's thermal init utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB, FSP, SBE
// EKB-Mirror-To: hostboot

#ifndef _ODY_THERMAL_INIT_UTILS_H_
#define _ODY_THERMAL_INIT_UTILS_H_

#include <fapi2.H>
#include <i2c_access.H>
#include <vector>
#include <mss_generic_attribute_getters.H>

namespace mss
{
namespace ody
{
namespace thermal
{
namespace i2c
{

///
/// @brief Helper function setup i2c reads to the DIMM thermal sensors
/// @param[in] i_reg the register to read
/// @param[in,out] io_vector the vector of i2c data
///
void read_dts_helper(const uint8_t i_reg, std::vector<uint8_t>& io_vector);

///
/// @brief Helper function setup i2c reads from the DIMM thermal sensors
/// @param[in] i_target the i2c responder target
/// @param[in] i_reg the register to write to
/// @param[out] o_data the data
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode read_dts(const fapi2::Target<fapi2::TARGET_TYPE_TEMP_SENSOR>& i_target,
                           const uint8_t i_reg,
                           fapi2::buffer<uint16_t>& o_data);

} // ns i2c

///
/// @brief Processes the results for this thermal sensor and writes them into the sensor cache register
/// @param[in] i_ocmb the OCMB target
/// @param[in] i_reg_addr the register address upon which to operate
/// @param[in] i_data register data to write. Note: this is not a pass-by-reference as it could be updated internally
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode process_results(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
                                  const uint64_t i_reg_addr,
                                  fapi2::buffer<uint64_t> i_data);

///
/// @brief Class containing information for reading thermal sensors
/// @note Uses function pointers to allow the code to easily run in the SPPE (as opposed to using inheritance)
///
class thermal_sensor
{
    private:

        uint64_t iv_reg_addr;

    public:

        ///
        /// @brief Constructor
        /// @param[in] i_reg_addr the register address where the thermal information is logged
        ///
        constexpr thermal_sensor(const uint64_t i_reg_addr) :
            iv_reg_addr(i_reg_addr)
        {}

        // A thermal sensor with no data does not make sense, as such delete the null constructor
        constexpr thermal_sensor() = delete;

        ///
        /// @brief Function that reads and processes the thermal information
        /// @param[in] i_ocmb the OCMB target
        /// @param[in] i_i2c the i2c responder target
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode read(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
                               const fapi2::Target<fapi2::TARGET_TYPE_TEMP_SENSOR>& i_i2c) const;

        ///
        /// @brief Helper function to conduct the i2c reads
        /// @param[in] i_i2c the i2c responder target
        /// @param[out] o_i2c_data the data read from the i2c register
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @note Virtual declaration allows for a shim to be made for unit testing
        ///
        virtual fapi2::ReturnCode i2c_read_helper(const fapi2::Target<fapi2::TARGET_TYPE_TEMP_SENSOR>& i_i2c,
                fapi2::buffer<uint16_t>& o_i2c_data) const;
};

///
/// @brief Function that reads and processes all thermal sensors
/// @param[in] i_ocmb the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode read_dts_sensors(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb);

///
/// @brief Processes the results for the On-Chip (OC) thermal sensor
/// @param[in] i_ocmb the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode read_oc_results(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb);


namespace mc
{

///
/// @brief set the N/M throttle register to safemode values
/// @param[in] i_target the ocmb target
/// @return fapi2::fapi2_rc_success if ok
/// @Will be overwritten by OCC/cronus later in IPL
///
fapi2::ReturnCode setup_emergency_throttles(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief disable emergency mode throttle for thermal_init
/// @param[in] i_target the ocmb target
/// @return fapi2::fapi2_rc_success if ok
/// @note clears MBA_FARB7Q bit
///
fapi2::ReturnCode disable_safe_mode_throttles (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

} // ns mc

} // ns thermal
} // ns ody
} // ns mss

#endif
