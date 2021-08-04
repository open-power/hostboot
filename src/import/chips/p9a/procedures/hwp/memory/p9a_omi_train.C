/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/p9a_omi_train.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file p9a_omi_train.C
/// @brief Check the omi status
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <lib/shared/axone_defaults.H>
#include <p9a_omi_train.H>

#include <fapi2.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <p9a_mc_scom_addresses_fixes.H>
#include <p9a_mc_scom_addresses_fld_fixes.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/mc/omi.H>
#include <lib/workarounds/p9a_omi_workarounds.H>
#include <generic/memory/mss_git_data_helper.H>
#include <exp_omi_train.H>


///
/// @brief Turn on Axone config regs to enable training
/// @param[in] i_target the OMI target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9a_omi_train( const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    mss::display_git_commit_info("p9a_omi_train");

    FAPI_INF("%s Start p9a_omi_train", mss::c_str(i_target));

    const auto& l_ocmbs = mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    if(l_ocmbs.empty())
    {
        // No ocmbs, no training needed
        return fapi2::FAPI2_RC_SUCCESS;
    }

    {
        // Only one OCMB per OMI for axone
        const auto& l_ocmb = l_ocmbs[0];
        const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(l_ocmb);
        uint8_t l_dl_x4_backoff_en = 0;
        bool l_gem_or_non_axone_workaround = false;
        bool l_axone_workarounds_required = false;
        uint8_t l_proc_type = 0;
        uint8_t l_ocmb_type = 0;

        // Get BACKOFF_ENABLE CHIP_EC attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE, l_ocmb, l_dl_x4_backoff_en),
                 "Error getting ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE");

        // Determine if workarounds will be performed, if so, perform them
        FAPI_TRY(mss::workarounds::mc::get_ocmb_proc_types(l_ocmb, l_proc, l_ocmb_type, l_proc_type));
        l_gem_or_non_axone_workaround = mss::workarounds::mc::is_prbs_omi_required(l_ocmb_type, l_proc_type);
        l_axone_workarounds_required = mss::workarounds::mc::is_prbs_omi_axone_required(l_ocmb_type, l_proc_type);

        if (l_axone_workarounds_required)
        {
            // TX_PATTERN_A
            FAPI_TRY(mss::workarounds::mc::omi_training_prbs(i_target, l_dl_x4_backoff_en));
        }
        else if (l_gem_or_non_axone_workaround)
        {
            // TX_TRAINING_STATE_3, TX_PATTERN_A
            FAPI_TRY(mss::workarounds::mc::omi_training_prbs_gem(i_target, l_dl_x4_backoff_en));

            // 2 second delay for gemini
            FAPI_TRY(fapi2::delay(2 * mss::common_timings::DELAY_1S, mss::common_timings::DELAY_1MS));
        }

        for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target))
        {
            FAPI_TRY(exp_omi_train_internal(l_ocmb));
        }

        // Enable auto training
        FAPI_TRY(mss::mc::setup_mc_config0(i_target, mss::omi::train_mode::ENABLE_AUTO_TRAINING, l_dl_x4_backoff_en));

        return fapi2::FAPI2_RC_SUCCESS;
    }

fapi_try_exit:
    return fapi2::current_err;

}// p9a_omi_train
