/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/pmic_enable.C $ */
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
/// @file pmic_enable.C
/// @brief Procedure definition to enable PMIC
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <pmic_enable.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/utils/pmic_common_utils.H>
#include <lib/utils/pmic_enable_utils.H>
#include <lib/utils/pmic_enable_utils_ddr5.H>
#include <lib/utils/pmic_consts.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/c_str.H>
#include <mss_generic_attribute_getters.H>

extern "C"
{
    ///
    /// @brief Enable function for pmic modules either on ddr4 or on ddr5
    /// @param[in] i_target ocmb target
    /// @param[in] i_mode enable mode operation
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode pmic_enable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                  const mss::pmic::enable_mode i_mode)
    {
        uint8_t l_dram_gen = 0;

        // Check if there are any DIMM targets
        if (mss::count_dimm(i_ocmb_target) == 0)
        {
            FAPI_INF("Skipping %s because it has no DIMM targets", mss::c_str(i_ocmb_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // We need to run pmic_enable for ddr4 or ddr5 based on the DRAM gen attribute
        // We just need get dram gen of 1 dimm
        // This is ok because we do not allow mixing of DRAM generation
        for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_ocmb_target))
        {
            FAPI_TRY(mss::attr::get_dram_gen(l_dimm, l_dram_gen));
            break;
        }

        if (l_dram_gen == fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4)
        {
            FAPI_TRY(mss::pmic::ddr4::pmic_enable(i_ocmb_target, i_mode));
        }
        else
        {
            FAPI_TRY(mss::pmic::ddr5::pmic_enable(i_ocmb_target, i_mode));
        }

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern C
