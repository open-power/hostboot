/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_periodic_telemetry_utils_ddr5.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file pmic_periodic_telemetry_utils_ddr5.H
/// @brief To be run periodically at runtime to collect telemetry data of 4U parts
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#ifndef __PMIC_PERIODIC_TELEMETRY_UTILS_DDR5_H__
#define __PMIC_PERIODIC_TELEMETRY_UTILS_DDR5_H__

#include <fapi2.H>
#include <lib/utils/pmic_common_utils_ddr5.H>
#include <hwp_data_stream.H>

typedef fapi2::ReturnCode (*pmic_periodic_telemetry_ddr5_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    fapi2::hwp_data_ostream&);

static constexpr uint8_t NUMBER_PMIC_REGS_READ_TELE = 4;

static constexpr uint8_t ADC_U16_MAP_LEN = 8;
static constexpr uint8_t NUM_BYTES_TO_READ = 16;

///
/// @brief Read and store serial number and CCIN number
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
void read_serial_ccin_number(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                             mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

///
/// @brief Scale the ADC regs (value * 38147) / 1000000 to get the value in mV
///
/// @param[in,out] io_adc_fill_array scaled values to be written to
/// @param[in] i_data_buffer read ADC values
/// None
///
void scale_adc_readings(uint16_t* (&io_adc_fill_array)[ADC_U16_MAP_LEN],
                        const fapi2::buffer<uint8_t> (&i_data_buffer)[NUM_BYTES_TO_READ]);

///
/// @brief Read and store ADC regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_adc_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                   mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

///
/// @brief Read and store neg orfet value
///
/// @param[in,out] io_pmic_dt_pair PMIC and DT target info struct
/// @param[in] i_reg_sel reg selection
/// @param[in,out] read data
/// None
///
void read_neg_orfet_cnt(mss::pmic::ddr5::target_info_pmic_dt_pair& io_pmic_dt_pair,
                        const uint8_t i_reg_sel,
                        fapi2::buffer<uint8_t>& io_data_buffer);
///
/// @brief Scale DT VAUX regs
///
/// @param[in] i_reg_value reg DT VAUX raw value
/// @param[in] i_scaling_factor scaling factor from reg 0x62 of DT
/// None
///
uint16_t scale_dt_vaux_regs(const uint8_t& i_reg_value,
                            const uint8_t& i_scaling_factor);

///
/// @brief Read and neg orfet value
///
/// @param[in,out] io_pmic_dt_pair PMIC and DT target info struct
/// @param[in,out] io_periodic_dt_tele_info DT struct
/// None
///
void read_store_vaux_values(mss::pmic::ddr5::target_info_pmic_dt_pair& io_pmic_dt_pair,
                            mss::pmic::ddr5::dt_periodic_telemetry_data& io_periodic_dt_tele_info);

///
/// @brief Read and store DT regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_dt_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                  mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

///
/// @brief Read and store PMIC regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_pmic_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                    mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

///
/// @brief Read and store ADC/PMIC/DT
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void collect_periodic_tele_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

///
/// @brief Send the periodic_telemetry_data struct
///
/// @param[in] io_periodic_tele_info periodic telemetry struct
/// @param[out] o_data hwp_data_ostream of struct information
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode send_struct(mss::pmic::ddr5::periodic_telemetry_data& i_info,
                              fapi2::hwp_data_ostream& o_data);

///
/// @brief Runtime periodic telemetry data collection helper for 4U parts
///
/// @param[in] i_ocmb_target ocmb target
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_periodic_telemetry_ddr5_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

#endif
