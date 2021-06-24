/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/mss_check_ddimm_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file mss_check_ddimm_config.C
/// @brief Procedure to assert valid PMIC/GI2C target config
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <mss_check_ddimm_config.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/utils/pmic_enable_utils.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <mss_generic_attribute_getters.H>

extern "C"
{
    ///
    /// @brief Assert valid PMIC/GI2C target config
    /// @param[in] i_target ocmb target
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode mss_check_ddimm_config(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
    {
        using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
        uint8_t l_module_height = 0;

        // Grab the module-height attribute to determine 1U/2U vs 4U
        FAPI_TRY(mss::attr::get_dram_module_height(i_ocmb_target, l_module_height));

        // Kick off the matching enable procedure
        if (l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
        {
            fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);

            // Try to create our target info object
            mss::pmic::target_info_redundancy l_target_info(i_ocmb_target, l_rc);

            // If platform did not provide a usable set of targets (4 GENERICI2CSLAVE, at least 2 PMICs),
            // Then we can't properly enable, this is asserted via this ReturnCode
            FAPI_TRY(l_rc, "Unusable PMIC/GENERICI2CSLAVE child target configuration found from %s",
                     mss::c_str(i_ocmb_target));
        }
        else
        {
            // 1U/2U case - we expect 2 PMICs
            const auto l_pmics = mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target, fapi2::TARGET_STATE_PRESENT);
            const auto NUM_PMICS = l_pmics.size();
            const auto NUM_PRIMARY_PMICS = CONSTS::NUM_PRIMARY_PMICS;

            FAPI_ASSERT(NUM_PMICS == NUM_PRIMARY_PMICS,
                        fapi2::INVALID_PMIC_TARGET_CONFIG()
                        .set_OCMB_TARGET(i_ocmb_target)
                        .set_NUM_PMICS(NUM_PMICS)
                        .set_EXPECTED_PMICS(NUM_PRIMARY_PMICS),
                        "%s pmic_enable requires %u PMIC targets. Given %u PMICs",
                        mss::c_str(i_ocmb_target), NUM_PRIMARY_PMICS, NUM_PMICS);
        }

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }
}
