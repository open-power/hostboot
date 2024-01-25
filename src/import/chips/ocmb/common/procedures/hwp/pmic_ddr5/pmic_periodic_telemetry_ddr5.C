/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/pmic_periodic_telemetry_ddr5.C $ */
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
#include <lib/utils/pmic_periodic_telemetry_utils_ddr5.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>

extern "C"
{

    ///
    /// @brief Runtime periodic telemetry data collection for 4U parts
    ///
    /// @param[in] i_ocmb_target ocmb target
    /// @param[out] o_data hwp_data_ostream of struct information
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
    /// @note The functional flow of the periodic telemetry tool has been take from
    ///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
    ///       document provided by the Power team
    ///
    fapi2::ReturnCode pmic_periodic_telemetry_ddr5(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
            fapi2::hwp_data_ostream& o_data)
    {
        FAPI_INF(GENTARGTIDFORMAT " Running pmic_periodic_telemetry HWP", GENTARGTID(i_ocmb_target));
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        mss::pmic::ddr5::periodic_telemetry_data l_info;

        // Temp workaround: Return success if this is a 2U
        // TODO Zen:MST-2318 Add telemetry collecton for DDR5 2U PMIC
        uint8_t l_module_height = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT, i_ocmb_target, l_module_height));

        if (l_module_height != fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
        {
            FAPI_INF_NO_SBE(GENTARGTIDFORMAT " DIMM is not 4U height, exiting pmic_periodic_telemetry_ddr5",
                            GENTARGTID(i_ocmb_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        {
            // Grab the targets as a struct, if they exist
            mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

            FAPI_TRY(mss::pmic::ddr5::set_pmic_dt_states(l_target_info));

            FAPI_TRY(pmic_periodic_telemetry_ddr5_helper(i_ocmb_target, l_target_info, l_info));

            FAPI_TRY(send_struct(l_info, o_data));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern C
