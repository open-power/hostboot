/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_setup.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file p10_omi_setup.C
/// @brief Setup the OMI
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p10_omi_setup.H>
#include <lib/omi/p10_omi_utils.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

///
/// @brief Setup OMI for P10
/// @param[in] i_target the OMIC target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p10_omi_setup( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target )
{
    uint8_t l_sim = 0;

    mss::display_git_commit_info("p10_omi_setup");
    FAPI_INF("%s Start p10_omi_setup", mss::c_str(i_target));

    FAPI_TRY(mss::attr::get_is_simulation(l_sim));

    // No-op in sim, we will just perform auto training in p10_omi_train.C
    if (l_sim)
    {
        FAPI_INF("Sim, exiting p10_omi_setup %s", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(mss::omi::setup_mc_cmn_config(i_target));

    // Add 120ms delay before PRBS
    FAPI_TRY( fapi2::delay( 120 * mss::DELAY_1MS, 200) );

    // Two OMI per OMIC
    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        // One OCMB per OMI
        // We only need to set up host side registers if there is an OCMB on the other side,
        // otherwise, there's no need to train the link. So with no OCMB, we just skip
        // the below steps
        for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
        {
            FAPI_TRY(mss::omi::setup_mc_config1(l_omi));
            FAPI_TRY(mss::omi::setup_mc_cya_bits(l_omi));
            FAPI_TRY(mss::omi::setup_mc_error_action(l_omi));
            // No setup needed for rc_rmt_config, as we leave at default (0) value

            // Perform PRBS workarounds if needed
            FAPI_TRY(mss::omi::p10_omi_setup_prbs_helper(i_target, l_omi, l_ocmb));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}
