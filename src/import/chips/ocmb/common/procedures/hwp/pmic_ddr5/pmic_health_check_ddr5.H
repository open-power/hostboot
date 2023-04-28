/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/pmic_health_check_ddr5.H $ */
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
/// @file pmic_health_check_ddr5.H
/// @brief To be run periodically at runtime to determine n-mode states of 4U parts
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#ifndef __PMIC_HEALTH_CHECK_DDR5_H__
#define __PMIC_HEALTH_CHECK_DDR5_H__

#include <fapi2.H>
#include <lib/utils/pmic_common_utils_ddr5.H>
#include <hwp_data_stream.H>

///
/// @brief
///
enum data_position : uint8_t
{
    DATA_0   = 0,
    DATA_1   = 1,
    DATA_2   = 2,
    DATA_3   = 3,
    DATA_4   = 4,
    DATA_5   = 5,
    DATA_6   = 6,
    DATA_7   = 7,
    DATA_8   = 8,
    DATA_9   = 9,
    DATA_10  = 10,
    DATA_11  = 11,
};

static constexpr uint8_t NUMBER_DT_REGS_READ = 4;
static constexpr uint8_t NUMBER_PMIC_REGS_READ = 12;

///
/// @brief Check minimum phase value from the given array
///
/// @tparam N size of the phase value data buffer
/// @param[in] array of phase values
/// @return index of minimum phase value from the array
///
template <size_t N>
uint8_t check_phase_min(const uint32_t (&i_phase)[N]);

///
/// @brief Check maximum phase value from the given array
///
/// @tparam N size of the phase value data buffer
/// @param[in] array of phase values
/// @return index of maximum phase value from the array
///
template <size_t N>
uint8_t check_phase_max(const uint32_t (&i_phase)[N]);

///
/// @brief Reset bread crumbs for all PMICs
///
/// @param[in,out] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode reset_breadcrumb(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                   mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Check bread crumbs for a specific DT/PMIC
///
/// @param[in] i_target pmic target
/// @param[in,out] io_dt_health_check struct which contains DT regs info
/// @return FAPI2_RC_SUCCESS iff okay
///
void check_and_advance_breadcrumb_reg(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_target,
                                      mss::pmic::ddr5::pmic_health_check_telemetry& io_dt_health_check);

///
/// @brief Update bread crumbs for a specific PMIC/DT pair
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in] DT number to be checked for breadcrumbs
/// @return FAPI2_RC_SUCCESS iff okay
///
void update_pmic_breadcrumb(mss::pmic::ddr5::target_info_pmic_dt_pair& i_target_info,
                            mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
                            const uint8_t i_dt_number);

///
/// @brief Compare 4 phases provided from 4 pmics, update pmic states if needed
///
/// @tparam N size of the phase value data buffer
/// @tparam M size of the number of pmics
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in] array of phase values
/// @param[in] array of pmics to do phase comparison on
/// @return mss::pmic::ddr5::pmic_state Aggregate pmic state, to be updated if needed
///
template <size_t N, size_t M>
fapi2::ReturnCode phase_comparison(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                   mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
                                   const uint32_t (&i_phase_values)[N],
                                   const uint8_t (&i_pmic)[M]);

///
/// @brief Calculate VDDQ current and determine if any current imbalance
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivddq(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Calculate VIO current and determine if any current imbalance
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivio(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Calculate VPP current and determine if any current imbalance
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivpp(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Calculate VDD current and determine if any current imbalance
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivdd(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Convert raw current values to readble hex values
///
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return void
/// @note This function should be called only once to convert the raw values else we will keep multiplying
/// the values with 125 and get a wrong conversion.
///
void convert_raw_current_readable_values(mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Perform current imbalance to check PMIC faults
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return none
///
void check_current_imbalance(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                             mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Check PMIC faults for all given PMICs
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return mss::pmic::ddr5::pmic_state aggregrate state of all PMICs
/// @note As per the document provided by the Power team "Redundant PoD5 - Functional Specification
///      dated 20230412 version 0.07", the only data needed from the PMICs for health determination
///      are the rail currents to detect current imbalances (other status faults are summed up into
///      the DT IC “GPI_1” bit)
///
mss::pmic::ddr5::pmic_state check_pmic_faults(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Check for DT faults in regs of a specific DT
///
/// @param[in] dt_health_check_telemetry struct which contains DT regs data
/// @return mss::pmic::ddr5::dt_state fault state of current DT
///
mss::pmic::ddr5::dt_state get_dt_state(const mss::pmic::ddr5::dt_health_check_telemetry& i_dt_health_check);

///
/// @brief Check DT faults for all given DTs
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return mss::pmic::ddr5::dt_state aggregrate state of all DTs
///
mss::pmic::ddr5::dt_state check_dt_faults(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Store the read regs into struct
///
/// @param[in] i_data PMIC data to be filled into the health_check struct
/// @param[in,out] io_pmic_health_check struct to be filled in
/// @return None
///
void fill_pmic_struct(const fapi2::buffer<uint8_t> (&i_data)[NUMBER_PMIC_REGS_READ],
                      mss::pmic::ddr5::pmic_health_check_telemetry& io_pmic_health_check);

///
/// @brief Store the read regs into struct
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode read_pmic_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                 mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Store the read regs into struct
///
/// @param[in] i_data DT data to be filled into the health_check struct
/// @param[in,out] io_dt_health_check struct to be filled in
/// @return None
///
void fill_dt_struct(const fapi2::buffer<uint8_t> (&i_data)[NUMBER_DT_REGS_READ],
                    mss::pmic::ddr5::dt_health_check_telemetry& io_dt_health_check);

///
/// @brief Read all DT regs and store in the array of structs
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return None
///
void read_dt_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                  mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

extern "C"
{
    ///
    /// @brief Runtime health check tool for 4U parts
    /// @param[in] i_ocmb_target ocmb target
    /// @param[out] o_data hwp_data_ostream of struct information
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode pmic_health_check_ddr5(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        fapi2::hwp_data_ostream& o_data);
}

#endif
