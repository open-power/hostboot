/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/mss_pmic_attribute_accessors_manual.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file mss_pmic_attribute_accessors_manual.C
/// @brief Manual PMIC attribute accessors
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <mss_pmic_attribute_accessors_manual.H>

namespace mss
{
namespace attr
{

///
/// @brief Get pmic n mode state for the given PMIC ID
///
/// @param[in] i_ocmb OCMB target
/// @param[in] i_pmic_id PMIC ID [0-3]
/// @param[out] o_n_mode N-Mode state
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode get_n_mode_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
    const uint8_t i_pmic_id,
    mss::pmic::n_mode& o_n_mode)
{
    o_n_mode = mss::pmic::n_mode::N_PLUS_1_MODE;

    fapi2::buffer<uint8_t> l_attr_buffer;
    uint8_t l_attr = 0;

    // Get current state
    FAPI_TRY(mss::attr::get_pmic_n_mode(i_ocmb, l_attr));
    l_attr_buffer = l_attr;

    // Grab matching bit
    o_n_mode = static_cast<mss::pmic::n_mode>(l_attr_buffer.getBit(i_pmic_id));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set pmic n mode state for the given PMIC ID
///
/// @param[in] i_ocmb OCMB target
/// @param[in] i_pmic_id PMIC ID [0-3]
/// @param[in] i_n_mode N-Mode state
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode set_n_mode_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
    const uint8_t i_pmic_id,
    const mss::pmic::n_mode i_n_mode)
{
    fapi2::buffer<uint8_t> l_attr_buffer;
    uint8_t l_attr = 0;

    // Get current state
    FAPI_TRY(mss::attr::get_pmic_n_mode(i_ocmb, l_attr));
    l_attr_buffer = l_attr;

    FAPI_TRY(l_attr_buffer.writeBit(i_n_mode, i_pmic_id));

    // Using () operator to grab buffer.iv_data
    FAPI_TRY(mss::attr::set_pmic_n_mode(i_ocmb, l_attr_buffer()));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns attr
} // ns mss
