/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_pm_utils.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file  p10_pm_utils.H
/// @brief General utility functions
///
/// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner         : Prasad BG Ranganath <prasadbgr@in.ibm.com>
/// *Team                 : PM
/// *Consumed by          : HB:CRO
///

#ifndef __PM_UTILS_H__
#define __PM_UTILS_H__

#include <p10_pm_get_poundv_bucket.H>

// Byte-reverse a 16-bit integer if on a little-endian machine
uint16_t revle16(const uint16_t i_x);

// Byte-reverse a 32-bit integer if on a little-endian machine
uint32_t revle32(const uint32_t i_x);

// Byte-reverse a 64-bit integer if on a little-endian machine
uint64_t revle64(const uint64_t i_x);

/// ----------------------------------------------------------------------------
/// @brief Compute bias value for pre-defined percentage unit
/// @param[in]     i_value Biased value
/// @return bias value
/// ----------------------------------------------------------------------------
double calc_bias(const int8_t i_value);

/// ----------------------------------------------------------------------------
/// @brief Compute smallest value for a given input
/// @param[in]     x value
/// @return smallest value
/// ----------------------------------------------------------------------------
double internal_ceil(double x);

/// ----------------------------------------------------------------------------
/// @brief Compute largest value for a given input
/// @param[in]     x value
/// @return largest value
/// ----------------------------------------------------------------------------
double internal_floor(double x);

/// ----------------------------------------------------------------------------
/// @brief Adjust bias value for given frequency value
/// @param[in]     i_value  frequency value
/// @param[in]     i_bias_0p5pct  bias value
/// @return computed biase value
/// ----------------------------------------------------------------------------
uint32_t bias_adjust_mhz(
    const uint32_t i_value,
    const int32_t i_bias_0p5pct);

/// ----------------------------------------------------------------------------
/// @brief Adjust bias value for given vdd/vcs voltage
/// @param[in]     i_value vdd/vcs value
/// @param[in]     i_bias_0p5pct  bias value
/// @return computed biase value
/// ----------------------------------------------------------------------------
uint32_t bias_adjust_mv(
    const uint32_t i_value,
    const int8_t i_bias_0p5pct);

/// ----------------------------------------------------------------------------
/// @brief Get the WOF Table Header
/// @param[in]    i_proc_target Chip Target
/// @param[out]   i_wof_table_data points to WOF data tables
/// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------------------
fapi2::ReturnCode wof_get_tables(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::ATTR_WOF_TABLE_DATA_Type* i_wof_table_data);

/// ----------------------------------------------------------------------------
/// @brief Validate the WOF Table Header
/// @param[in]    i_proc_target Chip Target
/// @param[in]    i_wof_table_data points to WOF data tables
/// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------------------
fapi2::ReturnCode wof_validate_header(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::ATTR_WOF_TABLE_DATA_Type* i_wof_table_data);

/// ----------------------------------------------------------------------------
/// @brief Apply the WOF Table Overrides to #V
/// @param[in]    i_proc_target Chip Target
/// @param[inout] o_wof_table_data points to WOF data tables
/// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------------------
fapi2::ReturnCode wof_apply_overrides(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::voltageBucketData_t* o_poundV_data);

/// ----------------------------------------------------------------------------
/// @brief Print the raw #V bucket structure
/// @param[in]    o_poundV_data Pointer to structure
/// ----------------------------------------------------------------------------
fapi2::ReturnCode print_voltage_bucket(
    fapi2::voltageBucketData_t* o_poundV_data);

#endif  // __PM_UTILS_H__
