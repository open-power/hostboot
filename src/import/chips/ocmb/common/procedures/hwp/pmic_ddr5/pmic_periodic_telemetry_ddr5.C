/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/pmic_periodic_telemetry_ddr5.C $ */
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
/// @file pmic_periodic_telemetry_ddr5.C
/// @brief To be run periodically at runtime to collect telemetry data of 4U parts
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <pmic_periodic_telemetry_ddr5.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>

///
/// @brief Read and store serial number and CCIN number
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
void read_serial_ccin_number(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                             mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    // TODO: ZEN-MST1906 Periodic telemetry data collection
}

///
/// @brief Read and store ADC regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_adc_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                   mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    // TODO: ZEN-MST1906 Periodic telemetry data collection
}

///
/// @brief Read and store DT regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_dt_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                  mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    // TODO: ZEN-MST1906 Periodic telemetry data collection
}

///
/// @brief Read and store PMIC regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_pmic_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                    mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    // TODO: ZEN-MST1906 Periodic telemetry data collection
}

///
/// @brief Read and store ADC/PMIC/DT
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void collect_periodic_tele_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    // Read and store serial number and CCIN number
    read_serial_ccin_number(io_target_info, io_periodic_tele_info);

    // Read and store ADC regs
    read_adc_regs(io_target_info, io_periodic_tele_info);

    // Read and store DT regs
    read_dt_regs(io_target_info, io_periodic_tele_info);

    // Read and store PMIC regs
    read_pmic_regs(io_target_info, io_periodic_tele_info);
}

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
        mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    mss::pmic::ddr5::aggregate_state l_aggregate_state_not_used = mss::pmic::ddr5::aggregate_state::N_PLUS_1;

    // Check for all the asserts (correct PMIC/DT pair received, DIMM is 4U)
    FAPI_TRY(health_check_tele_tool_assert_helper(i_ocmb_target,
             io_target_info,
             l_aggregate_state_not_used));

    if((l_aggregate_state_not_used == mss::pmic::ddr5::aggregate_state::DIMM_NOT_4U))
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Read and store ADC/DT/PMIC regs
    collect_periodic_tele_data(io_target_info, io_periodic_tele_info);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Runtime periodic telemetry data collection for 4U parts
///
/// @param[in] i_ocmb_target ocmb target
/// @param[out] o_data hwp_data_ostream of struct information
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_periodic_telemetry_ddr5(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        fapi2::hwp_data_ostream& o_data)
{
    FAPI_INF(GENTARGTIDFORMAT " Running pmic_periodic_telemetry HWP", GENTARGTID(i_ocmb_target));
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    mss::pmic::ddr5::periodic_telemetry_data l_info;

    // Grab the targets as a struct, if they exist
    mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

    FAPI_TRY(mss::pmic::ddr5::set_pmic_dt_states(l_target_info));

    FAPI_TRY(pmic_periodic_telemetry_ddr5_helper(i_ocmb_target, l_target_info, l_info));

    // TODO: ZEN-MST1906 Periodic telemetry data collection
    //FAPI_TRY(generate_and_send_response(l_target_info, l_info, o_data));

fapi_try_exit:
    return fapi2::current_err;
}
