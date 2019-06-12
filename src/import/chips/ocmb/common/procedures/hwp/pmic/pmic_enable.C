/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/pmic_enable.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
        auto l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_ocmb_target);
        auto l_pmics = mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target);

        // Sort by index (low to high) since find_targets may not return the correct order
        std::sort(l_dimms.begin(), l_dimms.end(),
                  [] (const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& l_first_dimm,
                      const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& l_second_dimm) -> bool
        {
            return mss::index(l_first_dimm) < mss::index(l_second_dimm);
        });

        std::sort(l_pmics.begin(), l_pmics.end(),
                  [] (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& l_first_pmic,
                      const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& l_second_pmic) -> bool
        {
            return mss::index(l_first_pmic) < mss::index(l_second_pmic);
        });

        // Start at PMIC0. If there was ever a weird case where there is a 4U dimm
        // on the same OCMB as a 2U dimm (is this possible?),
        // we would have 6 total PMICs. So, we need to keep
        // track of where we left off for the last pmic we enabled
        uint8_t l_pmic_index = 0;

        // Not asserting vectors non-empty because there could be OCMBs without DIMMs on them
        for (const auto& l_dimm : l_dimms)
        {
            // Get module height for DIMM to determine the number of PMICs we should be using
            uint8_t l_module_height = 0;
            FAPI_TRY(mss::attr::get_dram_module_height(l_dimm, l_module_height));

            if (l_module_height == mss::pmic::module_height::HEIGHT_1U ||
                l_module_height == mss::pmic::module_height::HEIGHT_2U)
            {
                // 1U and 2U are the same sequence, use 1U traits
                using PMIC_TRAITS = mss::pmic::pmic_traits<mss::pmic::module_height::HEIGHT_1U>;

                uint16_t l_vendor_id = 0;

                // PMIC0 and PMIC1 of each DIMM
                for (uint8_t l_current_pmic = 0; l_current_pmic < PMIC_TRAITS::PMICS_PER_DIMM; ++l_current_pmic)
                {
                    const auto l_current_pmic_target = l_pmics[l_pmic_index + l_current_pmic];
                    // Get vendor ID
                    FAPI_TRY(mss::pmic::get_mfg_id[l_current_pmic](l_dimm, l_vendor_id));

                    // Poll to make sure PBULK reports good, then we can enable the chip and write/read registers
                    FAPI_TRY(mss::pmic::poll_for_pbulk_good(l_current_pmic_target),
                             "pmic_enable: poll for pbulk good either failed, or returned not good status on PMIC %s",
                             mss::c_str(l_current_pmic_target));

                    // Call the enable procedure
                    FAPI_TRY((mss::pmic::enable_chip
                              <mss::pmic::module_height::HEIGHT_1U>
                              (l_current_pmic_target, l_dimm, l_vendor_id, i_mode)),
                             "pmic_enable: Error enabling PMIC %s", mss::c_str(l_current_pmic_target));

                }

                // Increment by the number of PMICs that were enabled and move on to the next dimm
                l_pmic_index += PMIC_TRAITS::PMICS_PER_DIMM;
            }
            else // 4U DIMM:
            {
                // Asserting out here as if we see a 4U at this point we shouldn't be able to proceed
                // Ugly assert false, but we need the above else later so we will use this for now
                FAPI_ASSERT(false,
                            fapi2::PMIC_DIMM_SPD_4U()
                            .set_TARGET(l_dimm),
                            "DIMM %s module height attribute identified as 4U. Not supported yet.",
                            mss::c_str(l_dimm));

                // The enable algorithm will be:
                // Load SPD for PMIC0 and PMIC1
                // Broadcast enable both together

                // Load SPD for PMIC2 and PMIC3 (which should be the same data as for PMIC0 and PMIC1)
                // Broadcast and enable both together

                // using PMIC_TRAITS = mss::pmic::pmic_traits<mss::pmic::module_height::HEIGHT_4U>;
                // l_pmic_index += PMIC_TRAITS::PMICS_PER_DIMM;
            }
        }

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern C
