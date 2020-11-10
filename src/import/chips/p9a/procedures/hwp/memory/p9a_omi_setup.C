/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/p9a_omi_setup.C $  */
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
/// @file p9a_omi_setup.C
/// @brief Setup the OMI
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/axone_defaults.H>
#include <p9a_omi_setup.H>
#include <lib/mc/omi.H>
#include <generic/memory/mss_git_data_helper.H>
#include <lib/workarounds/p9a_omi_workarounds.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

///
/// @brief Setup OMI for axone
/// @param[in] i_target the axone OMI target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9a_omi_setup( const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target )
{
    mss::display_git_commit_info("p9a_omi_setup");

    FAPI_INF("%s Start p9a_omi_setup", mss::c_str(i_target));

    const auto& l_mc = mss::find_target<fapi2::TARGET_TYPE_MC>(i_target);
    const auto& l_ocmbs = mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    FAPI_TRY(mss::mc::setup_mc_mcn_config(l_mc));
    FAPI_TRY(mss::mc::setup_mc_config1(i_target));
    FAPI_TRY(mss::mc::setup_mc_cya_bits(i_target));
    FAPI_TRY(mss::mc::setup_mc_error_action(i_target));
    FAPI_TRY(mss::mc::setup_mc_rmt_config(i_target));

    if(l_ocmbs.empty())
    {
        // No ocmbs, no training needed
        // Ensuring we don't try to access an empty vector
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Add 120ms delay before PRBS
    FAPI_TRY( fapi2::delay( 120 * mss::DELAY_1MS, 200) );

    {
        // Only one OCMB per OMI for axone
        const auto& l_ocmb = l_ocmbs[0];
        const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
        uint8_t l_dl_x4_backoff_en = 0;
        bool l_axone_workarounds_required = false;
        uint8_t l_proc_type = 0;
        uint8_t l_ocmb_type = 0;

        // Get BACKOFF_ENABLE CHIP_EC attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE, l_ocmb, l_dl_x4_backoff_en),
                 "Error getting ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE");

        // Determine if workaround will be performed, if so, perform it
        FAPI_TRY(mss::workarounds::mc::get_ocmb_proc_types(l_ocmb, l_proc, l_ocmb_type, l_proc_type));
        l_axone_workarounds_required = mss::workarounds::mc::is_prbs_omi_axone_required(l_ocmb_type, l_proc_type);

        if (l_axone_workarounds_required)
        {
            // TX_TRAINING_STATE1
            FAPI_TRY(mss::workarounds::mc::pre_omi_training_prbs(i_target, l_dl_x4_backoff_en));
        }

        return fapi2::FAPI2_RC_SUCCESS;
    }

fapi_try_exit:
    return fapi2::current_err;
}
