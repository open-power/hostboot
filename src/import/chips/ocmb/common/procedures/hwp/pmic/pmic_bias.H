/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/pmic_bias.H $ */
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
/// @file pmic_bias.H
/// @brief Procedure definition to bias PMIC
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __PMIC_BIAS_H__
#define __PMIC_BIAS_H__

#include <fapi2.H>
#include <lib/pmic/pmic_bias_utils.H>

typedef fapi2::ReturnCode (*pmic_bias_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        const mss::pmic::setting,
        const float,
        const mss::pmic::unit,
        const bool);

extern "C"
{
    ///
    /// @brief Bias procedure for PMIC devices
    ///
    /// @param[in] i_ocmb_target explorer target
    /// @param[in] i_setting setting to change (swa_volt, swb_volt, etc.)
    /// @param[in] i_amount amount to change by
    /// @param[in] i_unit percentage or value
    /// @param[in] i_force ignore 10% change limit
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
    ///
    fapi2::ReturnCode exp_pmic_bias(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                    const mss::pmic::setting i_setting =  mss::pmic::setting::NO_SETTING,
                                    const float i_amount = 0,
                                    const mss::pmic::unit i_unit = mss::pmic::unit::NO_UNIT,
                                    const bool i_force = false);
}
#endif
