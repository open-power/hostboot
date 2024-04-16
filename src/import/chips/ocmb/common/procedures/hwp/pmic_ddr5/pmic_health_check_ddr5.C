/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/pmic_health_check_ddr5.C $ */
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
/// @file pmic_health_check_ddr5.C
/// @brief To be run periodically at runtime to determine health of 4U parts
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <lib/utils/pmic_health_check_utils_ddr5.H>
#include <lib/utils/pmic_periodic_telemetry_utils_ddr5.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <mss_generic_attribute_getters.H>

extern "C"
{
    ///
    /// @brief Runtime Health check for 4U parts
    ///
    /// @param[in] i_ocmb_target ocmb target
    /// @param[out] o_data hwp_data_ostream of struct information
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
    ///
    fapi2::ReturnCode pmic_health_check_ddr5(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
            fapi2::hwp_data_ostream& o_data)
    {
        FAPI_INF(GENTARGTIDFORMAT " Running pmic_health_check HWP", GENTARGTID(i_ocmb_target));
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        mss::pmic::ddr5::health_check_telemetry_data l_health_check_info;
        mss::pmic::ddr5::additional_n_mode_telemetry_data l_additional_info;
        mss::pmic::ddr5::periodic_telemetry_data l_periodic_telemetry_data;
        mss::pmic::ddr5::consolidated_health_check_data l_consolidated_health_check_data;
        uint8_t l_number_bytes_to_send = 0;

        // Grab the targets as a struct, if they exist
        mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

        FAPI_TRY(mss::pmic::ddr5::set_pmic_dt_states(l_target_info));

        FAPI_TRY(pmic_health_check_ddr5_helper(i_ocmb_target, l_target_info, l_health_check_info, l_additional_info,
                                               l_periodic_telemetry_data, l_consolidated_health_check_data, l_number_bytes_to_send));

        FAPI_TRY(generate_and_send_response(l_target_info, l_health_check_info, l_additional_info,
                                            l_periodic_telemetry_data, l_consolidated_health_check_data, l_number_bytes_to_send,
                                            o_data));

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern C
