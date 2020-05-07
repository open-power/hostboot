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

extern "C"
{
    ///
    /// @brief Enable function for pmic modules
    /// @param[in] i_target ocmb target
    /// @param[in] i_mode enable mode operation
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode pmic_enable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                  const mss::pmic::enable_mode i_mode)
    {
        auto l_pmics = mss::find_targets_sorted_by_index<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target);

        // Check that we have PMICs (we wouldn't on gemini, for example)
        if (l_pmics.empty())
        {
            FAPI_INF("No PMICs to enable on %s, exiting.", mss::c_str(i_ocmb_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Disable PMICs and clear status bits so we are starting at a known off state
        FAPI_TRY(mss::pmic::disable_and_reset_pmics(i_ocmb_target));

        //
        // TK - plug rules here in next commit for 4U attribute/target validation
        //

        if (mss::find_targets<fapi2::TARGET_TYPE_GENERICI2CSLAVE>(i_ocmb_target).size() > 0)
        {
            // We have I2C slave devices, so we will do the "4U" redundancy enable process
            FAPI_TRY(mss::pmic::enable_with_redundancy(i_ocmb_target, i_mode));
        }
        else
        {
            FAPI_TRY(mss::pmic::enable_1u_2u(i_ocmb_target, i_mode));
        }

        // If we're enabling via internal settings, we can just run VR ENABLE down the line

        // Check that all the PMIC statuses are good post-enable
        FAPI_TRY(mss::pmic::status::check_all_pmics(i_ocmb_target),
                 "Bad statuses returned, or error checking statuses of PMICs on %s", mss::c_str(i_ocmb_target));

        // If we get here, statuses are good
        FAPI_INF("All status codes were OK for PMICs on %s", mss::c_str(i_ocmb_target));

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern C
