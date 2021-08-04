/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_train.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
#include <p10_io_lib.H>
#include <mss_generic_system_attribute_getters.H>
#include <exp_omi_train.H>

///
/// @brief Start DL link training on the selected OMIC
/// @param[in] i_target Reference to OMIC endpoint target
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_train(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    uint8_t l_sim = 0;
    FAPI_INF("%s Start p10_omi_train", mss::c_str(i_target));
    mss::display_git_commit_info("p10_omi_train");
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_TRY(mss::attr::get_is_simulation(l_sim));

    if (l_sim)
    {
        FAPI_TRY(mss::omi::p10_omi_train_sim(i_target));
        FAPI_INF("Sim, exiting p10_omi_train %s", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Two OMIs per OMIC
    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        // Poll that P10 is done with its PHY training
        // NOTE: need to do this here to not break parallelization of p10_omi_setup
        fapi2::current_err = p10_io_omi_poll_init_done(l_omi);

        if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
        {
            if (l_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE);
            }

            l_rc = fapi2::current_err;
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }
        else
        {
            // One OCMB per OMI
            // We only need to set up host side registers if there is an OCMB on the other side,
            // otherwise, there's no need to train the link. So with no OCMB, we just skip
            // the below step
            for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
            {

                // Helper to perform upstream PRBS sequence if needed
                FAPI_TRY(mss::omi::p10_omi_train_prbs_helper1(l_omi, l_ocmb));

                FAPI_TRY(exp_omi_train_internal(l_ocmb));

                // kick off ENABLE_AUTO_TRAINING
                FAPI_TRY(mss::omi::p10_omi_train_prbs_helper2(l_omi, l_ocmb));
            }
        }
    }

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        return l_rc;
    }

fapi_try_exit:
    return fapi2::current_err;
}
