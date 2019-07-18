/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_volt_dimm_count.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file p9c_mss_volt_dimm_count.C
/// @brief Determines number of dimms present behind a VDDR voltage domain
///
/// *HWP HWP Owner: Andre Marin <aamaring@us.ibm.com>
/// *HWP HWP Backup: Michael Pardeik <pardeik@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi2.H>
#include <p9c_mss_volt_dimm_count.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/utils/cumulus_find.H>

using fapi2::TARGET_TYPE_MBA;
using fapi2::TARGET_TYPE_DIMM;

extern "C" {
    ///
    /// @brief Determines number of dimms present behind a VDDR voltage domain
    /// @param[in] i_targets_memb  Reference to vector of present Centaur Targets in a particular VDDR power domain
    /// @return ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_volt_dimm_count(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>&
            i_targets_memb)
    {
        FAPI_INF("*** Running p9c_mss_volt_dimm_count ***");

        uint8_t l_memb_count = 0;
        uint8_t l_dimm_count = 0;
        uint8_t l_mrw_reg_power_limit_adj_enable = 0;
        uint8_t l_mrw_max_number_dimms_per_reg = 0;
        uint8_t l_spd_custom = 0;
        uint8_t l_custom_dimm = 0;
        uint8_t l_dimm_count_under_reg = 0;
        uint8_t l_max_dimm_count_per_reg = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mrw_reg_power_limit_adj_enable),
                 "Error gettting attribute ATTR_MSS_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE");

        if (l_mrw_reg_power_limit_adj_enable == fapi2::ENUM_ATTR_MSS_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE_TRUE)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MAX_NUMBER_DIMMS_POSSIBLE_PER_VMEM_REGULATOR,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mrw_max_number_dimms_per_reg),
                     "failed to get attribute ATTR_MSS_MRW_MAX_NUMBER_DIMMS_POSSIBLE_PER_VMEM_REGULATOR");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_max_dimm_count_per_reg), "Failed to get attribute ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT");

            // Iterate through the list of centaurs (configured and deconfigured)
            for (const auto& l_memb : i_targets_memb)
            {
                l_memb_count++;

                // Loop through the attached MBAs and their DIMMs to get a DIMM count
                for (const auto& l_mba : mss::find_targets<TARGET_TYPE_MBA>(l_memb, fapi2::TARGET_STATE_PRESENT))
                {
                    for (const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(l_mba, fapi2::TARGET_STATE_PRESENT))
                    {
                        l_dimm_count++;
                        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CUSTOM, l_dimm,  l_spd_custom),
                                 "failed to get ATTR_CEN_SPD_CUSTOM on dimm %s", mss::c_str(l_dimm));
                        l_custom_dimm = (l_spd_custom == fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_YES) ? 1 : l_custom_dimm;
                    }
                }

                // DIMM count will be number of centaurs for custom dimms
                // or number of dimms for non custom dimms
                l_dimm_count_under_reg = (l_custom_dimm == 1) ? l_memb_count : l_dimm_count;
                FAPI_INF("p9c_mss_volt_dimm_count:  DIMM Count %d/%d/%d after processing target %s", l_dimm_count_under_reg,
                         l_max_dimm_count_per_reg, l_mrw_max_number_dimms_per_reg, mss::c_str(l_memb));
            }

            // Error out if number of DIMMs counted is higher than expected
            FAPI_ASSERT((l_dimm_count_under_reg <= l_mrw_max_number_dimms_per_reg),
                        fapi2::CEN_MSS_DIMM_COUNT_EXCEEDS_MAX().
                        set_COUNT_CALC(l_dimm_count_under_reg).
                        set_COUNT_MAX(l_mrw_max_number_dimms_per_reg),
                        "DIMM count [%d] for targets exceeds max MRW limit [%d]", l_dimm_count_under_reg, l_mrw_max_number_dimms_per_reg);

            // Update attribute only if the DIMM count is higher than what was previously counted on other VDDR rails
            if (l_dimm_count_under_reg > l_max_dimm_count_per_reg)
            {
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                       l_dimm_count_under_reg), "Failed to set attr ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT");
            }
        }

        FAPI_INF("*** p9c_mss_volt_dimm_count COMPLETE ***");

    fapi_try_exit:
        return fapi2::current_err;
    }

} //end extern C
