/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/pmic_check_and_clear_ddr5.C $ */
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
/// @file pmic_check_and_clear_ddr5.C
/// @brief To be run to clear the status bits after issuing a reset
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <pmic_regs.H>
#include <pmic_check_and_clear_ddr5.H>
#include <lib/utils/pmic_common_utils_ddr5.H>

extern "C"
{
    ///
    /// @brief To be run to clear the status bits after issuing a reset
    ///
    /// @param[in] i_ocmb_target ocmb target
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
    /// @note For 4U: The below HWP is based on section 10.8 of
    ///       "Redundant PoD5 - Functional Specification dated 20240219 version 0.16"
    ///       document provided by the Power team
    ///       For 2U: The below HWP is based on section 10.8 of
    ///       "Non-Redundant PoD5 - Functional Specification dated 20240220 version 0.04"
    ///       document provided by the Power team
    ///
    fapi2::ReturnCode pmic_check_and_clear_ddr5(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
    {
        FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Running pmic_check_and_clear_ddr5 HWP", GENTARGTID(i_ocmb_target));

        using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        fapi2::buffer<uint8_t> l_data_to_write[] = {CLEAR_STATUS_0, CLEAR_STATUS_1, CLEAR_STATUS_2, CLEAR_STATUS_3};

        uint8_t l_module_height = 0;

#ifndef __PPE__
        // Grab the module-height attribute to determine 1U/2U vs 4U
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT, i_ocmb_target, l_module_height));

        // Kick off the matching enable procedure
        if (l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
#endif
        {
            // Grab the targets as a struct, if they exist
            mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

            // If platform did not provide a usable set of targets (1 GENERIC_I2C_DEV, at least 3 PMICs and 3 DTs),
            // Then we can't properly enable
            FAPI_TRY(l_rc, "Unusable PMIC child target configuration found from " GENTARGTIDFORMAT, GENTARGTID(i_ocmb_target));

            // Clearing status regs of only PMIC0, 1 and 3 as this HWP is only for clearing VDD status warnings and PMIC2
            // does not support VDD
            FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present(l_target_info, mss::pmic::id::PMIC0, [&l_data_to_write]
                              (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
            {
                FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_contiguous(i_pmic, REGS::R10, l_data_to_write));

                return fapi2::FAPI2_RC_SUCCESS;

            fapi_try_exit_lambda:
                fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                return fapi2::FAPI2_RC_SUCCESS;
            }));

            FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present(l_target_info, mss::pmic::id::PMIC1, [&l_data_to_write]
                              (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
            {
                FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_contiguous(i_pmic, REGS::R10, l_data_to_write));

                return fapi2::FAPI2_RC_SUCCESS;

            fapi_try_exit_lambda:
                fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                return fapi2::FAPI2_RC_SUCCESS;
            }));

            FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present(l_target_info, mss::pmic::id::PMIC3, [&l_data_to_write]
                              (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
            {
                FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_contiguous(i_pmic, REGS::R10, l_data_to_write));

                return fapi2::FAPI2_RC_SUCCESS;

            fapi_try_exit_lambda:
                fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                return fapi2::FAPI2_RC_SUCCESS;
            }));
        }

#ifndef __PPE__
        else
        {
            // We're guaranteed to have at least one PMIC here due to the check in pmic_enable
            auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target, fapi2::TARGET_STATE_PRESENT);

            for (const auto& l_pmic : l_pmics)
            {
                l_rc = mss::pmic::i2c::reg_write_contiguous(l_pmic, REGS::R10, l_data_to_write);

                if (l_rc != fapi2::FAPI2_RC_SUCCESS)
                {
                    fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                }
            }
        }

#endif

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern C
