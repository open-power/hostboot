/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/pmic_bias.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file pmic_bias.C
/// @brief Procedure definition to bias PMIC
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/utils/pmic_bias_utils.H>
#include <lib/utils/pmic_common_utils.H>
#include <pmic_bias.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/i2c/i2c_pmic.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/utils/pmic_bias_utils.H>
#include <lib/utils/pmic_consts.H>
#include <generic/memory/lib/utils/c_str.H>

extern "C"
{
    ///
    /// @brief Bias procedure for PMIC devices
    ///
    /// @param[in] i_ocmb_target explorer target
    /// @param[in] i_id the PMIC to change (PMIC0,PMIC1)
    /// @param[in] i_setting setting to change (swa_volt, swb_volt, etc.)
    /// @param[in] i_amount amount to change by
    /// @param[in] i_unit percentage or value
    /// @param[in] i_force ignore 10% change limit
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
    ///
    fapi2::ReturnCode pmic_bias(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                const mss::pmic::id i_id,
                                const mss::pmic::setting i_setting,
                                const float i_amount,
                                const mss::pmic::unit i_unit,
                                const bool i_force)
    {
        // Check that our inputs are valid
        FAPI_ASSERT(i_id != mss::pmic::id::UNKNOWN_ID,
                    fapi2::PMIC_NO_PMIC_SPECIFIED()
                    .set_TARGET(i_ocmb_target)
                    .set_PMIC_ID(uint8_t(i_id)),
                    "pmic_bias(): PMIC ID %u was unknown for bias procedure call on OCMB %s",
                    uint8_t(i_id), i_ocmb_target);

        FAPI_ASSERT(i_setting != mss::pmic::setting::NO_SETTING,
                    fapi2::PMIC_NO_SETTING_SPECIFIED()
                    .set_TARGET(i_ocmb_target)
                    .set_SETTING_ID(uint8_t(i_setting)),
                    "pmic_bias(): PMIC setting ID %u was unknown for bias procedure call on OCMB %s",
                    uint8_t(i_setting), i_ocmb_target);

        FAPI_ASSERT(i_unit != mss::pmic::unit::NO_UNIT,
                    fapi2::PMIC_NO_UNIT_SPECIFIED()
                    .set_TARGET(i_ocmb_target)
                    .set_UNIT_ID(uint8_t(i_unit)),
                    "pmic_bias(): Biasing unit ID %u was unknown for bias procedure call on OCMB %s",
                    uint8_t(i_unit), i_ocmb_target);

        for (const auto& l_pmic : mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target))
        {
            // If matching ID (pmic0, pmic1), then we will bias it
            if ((mss::index(l_pmic) % mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>::NUM_UNIQUE_PMICS) == i_id)
            {
                // Poll to make sure PBULK reports good, then we can be sure we can write/read registers
                FAPI_TRY(mss::pmic::poll_for_pbulk_good(l_pmic),
                         "pmic_enable: poll for pbulk good either failed, or returned not good status on PMIC %s",
                         mss::c_str(l_pmic));

                FAPI_INF("Performing BIAS on PMIC %s", mss::c_str(l_pmic));

                // Now call the bias function
                FAPI_TRY(mss::pmic::bias_chip(l_pmic, i_setting, i_amount, i_unit, i_force),
                         "Error biasing PMIC %s", mss::c_str(l_pmic));
            }
        }

        return fapi2::FAPI2_RC_SUCCESS;
    fapi_try_exit:
        return fapi2::current_err;
    }
} // extern C
