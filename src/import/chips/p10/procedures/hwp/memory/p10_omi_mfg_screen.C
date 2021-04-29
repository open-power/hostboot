/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_mfg_screen.C $ */
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
// EKB-Mirror-To: hostboot

///
/// @file p10_omi_mfg_screen.C
/// @brief Perform checks for the OMI manufacturing screen
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p10_omi_mfg_screen.H>
#include <lib/omi/p10_omi_utils.H>
#include <lib/omi/exp_omi_utils.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <lib/p10_attribute_accessors_manual.H>

///
/// @brief Perform checks for the OMI manufacturing screen
/// @param[in] i_target the OMIC target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p10_omi_mfg_screen( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target )
{
    constexpr uint8_t CHIP_EC_DD2_0 = 0x20;

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_sim = 0;
    fapi2::ATTR_EC_Type l_ec = 0;
    const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    bool l_mnfg_screen_test_crc = false;
    bool l_mnfg_screen_test_edpl = false;

    mss::display_git_commit_info("p10_omi_mfg_screen");
    FAPI_INF("%s Start p10_omi_mfg_screen", mss::c_str(i_target));

    FAPI_TRY(mss::attr::get_is_simulation(l_sim));

    // No-op in sim, we will just perform auto training in p10_omi_train.C
    if (l_sim)
    {
        FAPI_INF("%s Sim, exiting p10_omi_mfg_screen", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check EC level, because we don't run this for DD1
    FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, l_proc, l_ec));

    if (l_ec < CHIP_EC_DD2_0)
    {
        FAPI_INF("%s p10_omi_mfg_screen skipped for DD1 chip (EC level 0x%02X)",
                 mss::c_str(l_proc), l_ec);
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check for mnfg OMI screen settings
    FAPI_TRY(mss::check_omi_mfg_screen_crc_setting(l_mnfg_screen_test_crc));
    FAPI_TRY(mss::check_omi_mfg_screen_edpl_setting(l_mnfg_screen_test_edpl));

    // Perform checks on CRCs
    if (l_mnfg_screen_test_crc)
    {
        l_rc = mss::omi::check_omi_mfg_screen_crc_counts(i_target);

        // Throw out the RC if we went over the threshold
        // the underlying function logs this error, and the RC is only used in unit tests
        if ((l_rc == static_cast<uint32_t>(fapi2::RC_P10_MFG_OMI_SCREEN_DOWNSTREAM_CRC)) ||
            (l_rc == static_cast<uint32_t>(fapi2::RC_P10_MFG_OMI_SCREEN_UPSTREAM_CRC)))
        {
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        // Any other error RC should be returned
        FAPI_TRY(l_rc);
    }
    else
    {
        FAPI_INF("%s skipping CRC checks because attributes not set up", mss::c_str(i_target));
    }

    // Perform checks on EDPL
    if (l_mnfg_screen_test_edpl)
    {
        l_rc = mss::omi::check_omi_mfg_screen_edpl_counts(i_target);

        // Throw out the RC if we went over the threshold
        // the underlying function logs this error, and the RC is only used in unit tests
        if (l_rc == static_cast<uint32_t>(fapi2::RC_P10_MFG_OMI_SCREEN_UPSTREAM_EDPL))
        {
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        // Any other error RC should be returned
        FAPI_TRY(l_rc);

        for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
        {
            for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
            {
                l_rc = mss::exp::omi::check_omi_mfg_screen_edpl_counts(l_ocmb);

                // Throw out the RC if we went over the threshold
                // the underlying function logs this error, and the RC is only used in unit tests
                if (l_rc == static_cast<uint32_t>(fapi2::RC_P10_MFG_OMI_SCREEN_DOWNSTREAM_EDPL))
                {
                    l_rc = fapi2::FAPI2_RC_SUCCESS;
                }

                // Any other error RC should be returned
                FAPI_TRY(l_rc);
            }
        }
    }
    else
    {
        FAPI_INF("%s skipping EDPL checks because attributes not set up", mss::c_str(i_target));
    }

    FAPI_INF("%s End p10_omi_mfg_screen", mss::c_str(i_target));

    return l_rc;

fapi_try_exit:
    return fapi2::current_err;
}
