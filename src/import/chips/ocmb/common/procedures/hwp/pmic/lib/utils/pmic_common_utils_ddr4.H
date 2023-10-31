/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_common_utils_ddr4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/// @file pmic_common_utils_ddr4.H
/// @brief Utility functions common for several PMIC procedures
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef __PMIC_COMMON_UTILS_DDR4_H__
#define __PMIC_COMMON_UTILS_DDR4_H__

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/utils/pmic_consts.H>
#include <mss_pmic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/fapi_try_lambda.H>

namespace mss
{
namespace pmic
{

///
/// @brief Run the provided function if the PMIC is present and not overridden to N-Mode
///
/// @tparam F function type (expected to be lambda)
/// @param[in] i_pmic_map Map of pmic ID to pmic target
/// @param[in] i_pmic_id desired pmic ID to key on
/// @param[in] i_func lambda function to run if given PMIC is not disabled
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
template<typename F>
fapi2::ReturnCode run_if_present(
    const std::map<size_t, fapi2::Target<fapi2::TARGET_TYPE_PMIC>>& i_pmic_map,
    const uint8_t i_pmic_id,
    const F i_func)
{
    // No const here due to the HB implementation of map/iterator: Does not allow for
    // const iterators to perform the -> operator (has trouble de-const'ing)
    auto l_pmic_it = i_pmic_map.find(i_pmic_id);
    bool l_disabled = false;

    // If we don't have the PMIC in the map, then platform never provided it as present,
    // so we should just exit, do not run i_func()
    if ( l_pmic_it == i_pmic_map.end() )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    const auto& l_pmic = l_pmic_it->second;

    // PMIC does exist, now see if it was overridden to disabled via ATTR_PMIC_FORCE_N_MODE
    FAPI_TRY(mss::pmic::disabled(l_pmic, l_disabled));

    // PMIC target provided here. Other arguments to be provided via capture list
    if (!l_disabled)
    {
        FAPI_TRY(i_func(l_pmic));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks PMIC for VIN_BULK above minimum tolerance
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode success if good, else, error code
///
fapi2::ReturnCode check_vin_bulk_good(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Get the minimum vin bulk threshold
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_vin_bulk_min VIN bulk minimum value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_minimum_vin_bulk_threshold(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    uint16_t& o_vin_bulk_min);

///
/// @brief Helper function to get the minimum vin bulk threshold
///
/// @param[in] i_vin_bulk_min_threshold
/// @param[in] i_is_ti PMIC is TI
/// @param[in] i_rev PMIC revision
/// return VIN bulk minimum value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
uint16_t get_minimum_vin_bulk_threshold_helper(
    const uint8_t i_vin_bulk_min_threshold,
    const bool i_is_ti,
    const uint8_t i_rev);

///
/// @brief Disable the ADC for the pmic
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode disable_pmic_adc(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Enable the ADC for the pmic
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode enable_pmic_adc(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);;

///
/// @brief Get the valid pmics for id object
///
/// @param[in] i_ocmb_target OCMB target to get PMIC(s) for
/// @param[in] i_id index of PMIC requested
/// @return vector of PMICs that match the id
///
inline std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>> get_valid_pmics_for_id(
            const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
            const mss::pmic::id i_id)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>> l_output_pmics;

    const auto l_pmics = mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target, fapi2::TARGET_STATE_PRESENT);

    for (const auto& l_pmic : l_pmics)
    {
        if (mss::index(l_pmic) % CONSTS::NUM_PRIMARY_PMICS == i_id)
        {
            l_output_pmics.push_back(l_pmic);
        }
    }

    return l_output_pmics;
}

///
/// @brief Calculate nominal rail voltages
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_id ID of pmic (0,1)
/// @param[in] i_rail SWA through SWD mapped as 0 to 3
/// @param[out] o_nominal_voltage calculated nominal voltage, shifted in place for register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode calculate_4u_nominal_voltage(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_id,
    const uint8_t i_rail,
    uint8_t& o_nominal_voltage);

} // pmic
} // mss

#endif
