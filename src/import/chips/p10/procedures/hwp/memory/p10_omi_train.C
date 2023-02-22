/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_train.C $  */
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
/// @file p10_omi_train.C
/// @brief Train the OMI link after p10_omi_setup
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p10_omi_train.H>
#include <lib/omi/p10_omi_utils.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/mss_git_data_helper.H>
#include <p10_io_omi_prbs.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <exp_omi_train.H>

///
/// @brief Start DL link training on the selected OMIC
/// @param[in] i_target Reference to OMIC endpoint target
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_train(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    uint8_t l_sim = 0;
    uint8_t l_is_apollo = 0;
    FAPI_INF("%s Start p10_omi_train", mss::c_str(i_target));
    mss::display_git_commit_info("p10_omi_train");
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_TRY(mss::attr::get_is_simulation(l_sim));

    FAPI_TRY(mss::attr::get_is_apollo(l_is_apollo));

    if (l_sim)
    {
        FAPI_TRY(mss::omi::p10_omi_train_sim(i_target));
        FAPI_INF("Sim, exiting p10_omi_train %s", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Start BOOTCONFIG1
    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
        {
            FAPI_TRY(exp_omi_train_internal(l_ocmb));
        }
    }

    // Enable DL Tx PATTERN A
    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
        {
            FAPI_TRY(mss::omi::p10_omi_train_prbs_helper1(l_omi, l_ocmb));
        }
    }

    // Disable PHY PRBS23 Pattern
    FAPI_TRY(p10_io_omi_prbs(i_target, false));

    // Start Host DL Training Sequence
    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
        {
            FAPI_TRY(mss::omi::p10_omi_train_prbs_helper2(l_omi, l_ocmb));
        }
    }

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        return l_rc;
    }

fapi_try_exit:
    return fapi2::current_err;
}
