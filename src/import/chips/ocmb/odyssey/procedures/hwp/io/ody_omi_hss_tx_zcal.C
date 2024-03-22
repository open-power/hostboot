/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_tx_zcal.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
///------------------------------------------------------------------------------
/// @file ody_omi_hss_tx_zcal.C
/// @brief Odyssey HWP that runs TDR on links
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_omi_hss_tx_zcal.H>
#include <ody_io_tdr_utils.H>
#include <ody_io_ppe_common.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_hss_tx_zcal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Start");

    constexpr uint32_t c_groupa_mask = 0xA5;
    constexpr uint32_t c_groupb_mask = 0x5A;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys;
    fapi2::ATTR_IS_SIMULATION_Type l_sim = 0;
    fapi2::ATTR_IS_SIMICS_Type l_simics = fapi2::ENUM_ATTR_IS_SIMICS_REALHW;
    fapi2::ATTR_MSS_IS_APOLLO_Type l_is_apollo;

    uint32_t l_groupa = 0x0;
    uint32_t l_groupb = 0x0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, l_sys, l_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, l_sys, l_simics));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_IS_APOLLO, l_sys, l_is_apollo));

    if (!l_sim && !l_is_apollo && !(l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS))
    {
        fapi2::ATTR_FREQ_OMI_MHZ_Type l_freq;

        FAPI_DBG("Running OMI TDR");
        // Run TDR isolation
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, i_target, l_freq));

        fapi2::errlSeverity_t l_sev;
        fapi2::ATTR_MFG_FLAGS_Type l_mfg_flags = {0};
        TdrResult l_status = TdrResult::None;
        uint32_t l_length = 0;

        char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(i_target, l_tgt_str, sizeof(l_tgt_str));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MFG_FLAGS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mfg_flags));

        for (uint8_t l_lane = 0; l_lane < 8; l_lane++)
        {
            FAPI_TRY(ody_io_tdr(i_target, PHY_ODY_OMI_BASE, l_groupa, l_lane, l_freq, l_status, l_length));

            FAPI_DBG("Checking %s on lane %d with status %d.", l_tgt_str, l_lane, l_status);

            if (l_status != TdrResult::NoIssues)
            {
                if (l_mfg_flags[fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS / 32] & (1 << (31 -
                        (fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS % 32))))
                {
                    l_sev = fapi2::FAPI2_ERRL_SEV_PREDICTIVE;
                }
                else
                {
                    l_sev = fapi2::FAPI2_ERRL_SEV_RECOVERED;
                }

                // note - FAPI_ASSERT_NOEXIT clears current_err on return
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::POZ_IO_TX_TDR_ERROR(l_sev)
                                   .set_TARGET_CHIP(i_target)
                                   .set_LANE(l_lane)
                                   .set_STATUS(l_status)
                                   .set_DISTANCE(l_length),
                                   "OMI Tx TDR Fail on %s :: lane(%d), status(0x%04X) length(%d)...",
                                   l_tgt_str, l_lane, l_status, l_length);
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

                l_groupa |= (0x1 << l_lane) & c_groupa_mask;
                l_groupb |= (0x1 << l_lane) & c_groupb_mask;
            }
        }

        if (l_groupa && l_groupb)
        {
            // note - FAPI_ASSERT_NOEXIT clears current_err on return
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::POZ_IO_TX_TDR_MULTI_GROUP_ERROR()
                               .set_TARGET_CHIP(i_target)
                               .set_GROUPA(l_groupa)
                               .set_GROUPB(l_groupb),
                               "OMI Tx TDR Multiple Degrade Groups Fail on %s :: groupa(0x%02X), groupb(0x%02X)...",
                               l_tgt_str, l_groupa, l_groupb);
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
