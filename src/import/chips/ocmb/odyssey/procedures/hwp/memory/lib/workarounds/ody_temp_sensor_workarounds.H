/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_temp_sensor_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2025                        */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_temp_sensor_workarounds.H
/// @brief Workarounds for 4U temp sensor usage based on MRW attr
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _ODY_TEMP_SENSOR_WORKAROUNDS_H_
#define _ODY_TEMP_SENSOR_WORKAROUNDS_H_

#include <fapi2.H>

namespace mss
{
namespace ody
{
namespace workarounds
{
#ifndef __PPE__
    ///
    /// @brief Changes temp sensor usage depending on MRW attr and height of DIMM
    /// @param[in] i_target ocmb target on which to operate
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
    /// @note 4U DDIMMs would use MEMCTRL, MC_EXT, and MC_DRAM sensor types
    /// (where MC_EXT is really PMIC, and MC_DRAM is really DIMM).
    /// Helper function to unit test this functionality
    ///
    fapi2::ReturnCode change_temp_sensor_usage_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

    ///
    /// @brief Changes temp sensor usage depending on MRW attr and height of DIMM
    /// @param[in] i_target ocmb target on which to operate
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
    /// @note 4U DDIMMs would use MEMCTRL, MC_EXT, and MC_DRAM sensor types
    /// (where MC_EXT is really PMIC, and MC_DRAM is really DIMM)
    ///
    fapi2::ReturnCode change_temp_sensor_usage(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

    ///
    /// @brief Disables DIMM Thermal sensor that are not configured to use
    /// @param[in] i_target ocmb target on which to operate
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
    ///
    fapi2::ReturnCode disable_unused_temp_sensor(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);
#endif

///
/// @brief Set the sensor cache error bit if temperature read is a glitch (value changes more than it should between reads)
/// @param[in] i_ocmb the OCMB target
/// @param[in] i_reg_addr the register address with previous temperature value
/// @param[in] i_sensor_pos the sensor position index
/// @param[in,out] io_data register data to write to sensor cache
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode check_sensor_glitch(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
                                      const uint64_t i_reg_addr,
                                      const uint8_t i_sensor_pos,
                                      fapi2::buffer<uint64_t>& io_data);

///
/// @brief Reads the octs, dts0, dts1, dts2, dts3 and writes to the scratch register
/// @tparam START_POS starting position in the scratch register
/// @param[in] i_snsc_thermal_data sensor cache buffer data
/// @param[in,out] io_scratch_buffer Output scratch buffer that has the sensor cache values
/// @return None
///
template<uint8_t START_POS>
void wr_reg_data_to_scratch_helper(const fapi2::buffer<uint64_t>& i_snsc_thermal_data,
                                   fapi2::buffer<uint64_t>& io_scratch_buffer);
///
/// @brief Reads the octs, dts0, dts1 and writes to the scratch buffer
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note The proposed workaround is the following:
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | REGISTER  |      OCTS      |         DTS0        |             DTS1            | SRQ_LFIR |
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | 0x8011026 | 0 1 2 3  4:19  | 20 21 22 23  24:39  | 40 41 42 43 44:59  60 61 62 |     63   |
/// |           | 0 P V E <temp> | 0  P  V  E   <temp> | 0  P  V  E  <temp> 0  0  0  |   Event  |
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///
fapi2::ReturnCode wr_data_to_scratch0(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Reads the dts2, dts3, srq_pmu2q and writes to the scratch buffer
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note The proposed workaround is the following:
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | REGISTER  |      DTS2      |         DTS3        |         SR Cycle Count           |
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | 0x8011027 | 0 1 2 3  4:19  | 20 21 22 23  24:39  |             40:63                |
/// |           | 0 P V E <temp> | 0  P  V  E   <temp> |       (side 0 + side 1)          |
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///
fapi2::ReturnCode wr_data_to_scratch1(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Reads the srq_pmu0q and srq_pmu1q and writes to the scratch buffer
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note The proposed workaround is the following:
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | REGISTER  |             Reads               |                Writes                 |
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/// | 0x8011028 |          (0:31)                 |                (0:31)                 |
/// |           |    (side 0 + side 1)            |          (side 0 + side 1)            |
/// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///
fapi2::ReturnCode wr_data_to_scratch2(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Reset the PMU counters used in the workaround
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode reset_pmu_counts(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Start the PMU counters used in the workaround
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode start_pmu_counts(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Reads the sensor cache regs and repackaged into scratch registers
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode write_sensor_cache_into_scratch_regs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

} // workarounds
} // ody
} // mss

#endif
