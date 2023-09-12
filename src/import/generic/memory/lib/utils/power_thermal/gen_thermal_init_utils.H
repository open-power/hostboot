/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/power_thermal/gen_thermal_init_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file gen_thermal_init_utils.H
/// @brief Temperature sensor cache reading functions
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB, FSP, SBE
// EKB-Mirror-To: hostboot

#ifndef _GEN_THERMAL_INIT_UTILS_H
#define _GEN_THERMAL_INIT_UTILS_H

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>
#include <math.h>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/power_thermal/gen_temp_sensor_traits.H>

namespace mss
{
///
/// @brief calculate DIMM0 and DIMM1 temperature from sensor cache thermal register scom data
///
/// @tparam MC the mc type of the T
/// @tparam TT temp_sensor_traits for MC - derived
/// @param[in]  i_scom_data  temperature register scom data to calculate temperature from
///
/// @return int16_t temperature value with sign
///
template< mss::mc_type MC, typename TT = mss::temp_sensor_traits<MC> >
int16_t calc_dimm_temp_X100(const fapi2::buffer<uint64_t>& i_scom_data);

///
/// @brief calculate OCMB temperature from sensor cache thermal register scom data
///        comes from internal thermal diode read from external temperature sensor
///
/// @tparam MC the mc type of the T
/// @tparam TT temp_sensor_traits for MC - derived
/// @param[in]  i_scom_data  temperature register scom data to calculate temperature from
///
/// @return int16_t temperature value with sign
///
template< mss::mc_type MC, typename TT = mss::temp_sensor_traits<MC> >
int16_t calc_ocmb_thermal_diode_temp_X100(const fapi2::buffer<uint64_t>& i_scom_data);

///
/// @brief calculate OCMB temperature from sensor cache thermal register scom data
///        comes from internal DTM
///
/// @tparam MC the mc type of the T
/// @tparam TT temp_sensor_traits for MC - derived
/// @param[in]  i_scom_data  temperature register scom data to calculate temperature from
///
/// @return int16_t temperature value with sign
///
template< mss::mc_type MC, typename TT = mss::temp_sensor_traits<MC> >
int16_t calc_ocmb_dtm_temp_X100(const fapi2::buffer<uint64_t>& i_scom_data);

///
/// @brief calculate and display temperature sensor temperature data for ocmb
///
/// @tparam MC the mc type of the T
/// @tparam TT temp_sensor_traits for MC - derived
/// @param[in]  i_ocmb_target  ocmb chip target
/// @param[in]  i_temperature_scom_data  temperature value from the sensor to read
/// @param[out] o_present value of the sensor's present bit
/// @param[out] o_error value of the sensor's error bit
/// @param[out] o_temperature temperature_value from the given sensor in centigrade
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template< mss::mc_type MC, typename TT = mss::temp_sensor_traits<MC> >
fapi2::ReturnCode get_sensor_data_for_ocmb_x100(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        const fapi2::buffer<uint64_t>& i_temperature_scom_data,
        uint8_t& o_present,
        uint8_t& o_error,
        int16_t& o_temperature);

///
/// @brief calculate and display temperature sensor temperature data for ddimms
///
/// @tparam MC the mc type of the T
/// @tparam TT temp_sensor_traits for MC - derived
/// @param[in]  i_ocmb_target  ocmb chip target
/// @param[in]  i_temperature_scom_data  temperature value from the sensor to read
/// @param[out] o_present value of the sensor's present bit
/// @param[out] o_error value of the sensor's error bit
///
/// @return temperature_value from the given sensor in centigrade
///
template< mss::mc_type MC, typename TT = mss::temp_sensor_traits<MC> >
int16_t get_sensor_data_for_ddimm_x100(
    const fapi2::buffer<uint64_t>& i_temperature_scom_data,
    uint8_t& o_present,
    uint8_t& o_error);


}// mss ns

#endif
