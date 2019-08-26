/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/pmic_enable.C $ */
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
/// @file pmic_enable.C
/// @brief Procedure definition to enable PMIC
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <pmic_enable.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/utils/pmic_common_utils.H>
#include <lib/utils/pmic_enable_utils.H>
#include <lib/utils/pmic_consts.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <mss_generic_attribute_getters.H>

extern "C"
{
    ///
    /// @brief Enable function for pmic module. Calls appropriate enable func with matching DIMM target
    /// @param[in] i_target ocmb target
    /// @param[in] i_mode enable mode operation
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode pmic_enable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                  const mss::pmic::enable_mode i_mode)
    {
        auto l_dimms = mss::find_targets_sorted_by_index<fapi2::TARGET_TYPE_DIMM>(i_ocmb_target);
        auto l_pmics = mss::find_targets_sorted_by_index<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target);

        // Check that we have PMICs (we wouldn't on gemini, for example)
        if (l_pmics.empty())
        {
            FAPI_INF("No PMICs to enable on %s, exiting.", mss::c_str(i_ocmb_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // // If we're enabling via internal settings, we can just run VR ENABLE down the line
        if (i_mode == mss::pmic::enable_mode::MANUAL)
        {
            FAPI_TRY(mss::pmic::enable_manual(l_pmics));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        if (!l_dimms.empty())
        {
            uint8_t l_module_height = 0;
            FAPI_TRY(mss::attr::get_dram_module_height(l_dimms[0], l_module_height));

            FAPI_ASSERT(l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_1U ||
                        l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U,
                        fapi2::PMIC_DIMM_SPD_UNSUPPORTED_MODULE_HEIGHT()
                        .set_TARGET(l_dimms[0])
                        .set_VALUE(l_module_height),
                        "DIMM %s module height attribute not identified as 1U or 2U. "
                        "ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT of %u . Not supported yet.",
                        mss::c_str(l_dimms[0]), l_module_height);

            // Else, 1 or 2
            {
                static constexpr uint8_t PMICS_PER_DIMM = 2;

                for (uint8_t l_dimm_index = 0; l_dimm_index < l_dimms.size(); ++l_dimm_index)
                {
                    // The PMICs are in sorted order
                    const auto& l_dimm = l_dimms[l_dimm_index];
                    FAPI_TRY(mss::pmic::order_pmics_by_sequence(l_dimm, l_dimm_index, PMICS_PER_DIMM, l_pmics));

                    // Now the PMICs are in the right order of DIMM and the right order by their defined SPD sequence within each dimm
                    // Let's kick off the enables
                    for (const auto& l_pmic : l_pmics)
                    {
                        // Get the corresponding DIMM target to feed to the helpers
                        const auto& l_dimm = l_dimms[mss::index(l_pmic) / PMICS_PER_DIMM];
                        uint16_t l_vendor_id = 0;

                        // Get vendor ID
                        FAPI_TRY(mss::pmic::get_mfg_id[mss::index(l_pmic)](l_dimm, l_vendor_id));

                        // Poll to make sure PBULK reports good, then we can enable the chip and write/read registers
                        FAPI_TRY(mss::pmic::poll_for_pbulk_good(l_pmic),
                                 "pmic_enable: poll for pbulk good either failed, or returned not good status on PMIC %s",
                                 mss::c_str(l_pmic));

                        // Call the enable procedure
                        FAPI_TRY((mss::pmic::enable_chip_1U_2U
                                  (l_pmic, l_dimm, l_vendor_id)),
                                 "pmic_enable: Error enabling PMIC %s", mss::c_str(l_pmic));
                    }
                }
            }
        }

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern C
