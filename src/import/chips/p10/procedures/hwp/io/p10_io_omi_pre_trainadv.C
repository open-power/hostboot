/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_omi_pre_trainadv.C $ */
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
/// @file p10_io_omi_pre_trainadv.C
/// @brief Placeholder for OMI PHY pre train settings (FAPI2)
///
/// *HWP HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_io_omi_pre_trainadv.H>
#include <p10_omi_isolation.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


fapi2::ReturnCode p10_omi_tx_tdr_screen_check(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
    std::vector<TdrStruct>& i_data)
{

    const uint32_t c_groupa_mask = 0xA5;
    const uint32_t c_groupb_mask = 0x5A;
    uint32_t l_groupa = 0x0;
    uint32_t l_groupb = 0x0;
    fapi2::errlSeverity_t l_sev;
    fapi2::ATTR_MFG_FLAGS_Type l_mfg_flags = {0};

    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_omi, l_tgt_str, sizeof(l_tgt_str));

    char l_ocmb_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_ocmb, l_ocmb_str, sizeof(l_ocmb_str));

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MFG_FLAGS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mfg_flags) );


    for (const auto& l_data : i_data)
    {
        FAPI_DBG("Checking %s on lane %d with status %d.", l_tgt_str, l_data.iv_lane, l_data.iv_status);

        if (l_data.iv_status != TdrResult::Good)
        {
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::P10_IO_TX_TDR_SCREEN_ERROR()
                               .set_OMI_TARGET(i_omi)
                               .set_OCMB_TARGET(i_ocmb)
                               .set_TDR_LANE(l_data.iv_lane)
                               .set_TDR_STATUS(l_data.iv_status),
                               "OMI Tx TDR Screen Fail on %s - %s :: lane(%d), status(0x%04X)...",
                               l_tgt_str, l_ocmb_str, l_data.iv_lane, l_data.iv_status);

            if (l_mfg_flags[fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS / 32] & (1 << (31 -
                    (fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS % 32))))
            {
                l_sev = fapi2::FAPI2_ERRL_SEV_PREDICTIVE;
            }
            else
            {
                l_sev = fapi2::FAPI2_ERRL_SEV_RECOVERED;
            }

            fapi2::logError(fapi2::current_err, l_sev);

            l_groupa |= (0x1 << l_data.iv_lane) & c_groupa_mask;
            l_groupb |= (0x1 << l_data.iv_lane) & c_groupb_mask;
        }
    }

    if (l_groupa && l_groupb)
    {
        FAPI_ASSERT_NOEXIT(false,
                           fapi2::P10_IO_TX_TDR_SCREEN_MULTI_GROUP_ERROR()
                           .set_OMI_TARGET(i_omi)
                           .set_OCMB_TARGET(i_ocmb)
                           .set_OMI_GROUPA(l_groupa)
                           .set_OMI_GROUPB(l_groupb),
                           "OMI Tx TDR Screen Multiple Degrade Groups Fail on %s - %s :: groupa(0x%02X), groupb(0x%02X)...",
                           l_tgt_str, l_ocmb_str, l_groupa, l_groupb);
        fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_PREDICTIVE);
    }

fapi_try_exit:
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}



/// Main function, see description in header
fapi2::ReturnCode p10_io_omi_pre_trainadv(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    std::vector<TdrStruct> l_data;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_IS_SIMICS_Type l_attr_is_simics;

    FAPI_DBG("Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, FAPI_SYSTEM, l_attr_is_simics));

    if (l_attr_is_simics)
    {
        FAPI_DBG("Skipping if in simics ...");
        goto fapi_try_exit;
    }


    for (const auto& l_pauc_target : i_target.getChildren<fapi2::TARGET_TYPE_PAUC>())
    {
        for (const auto& l_omic_target : l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>())
        {
            for (const auto& l_omi_target : l_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>())
            {
                const auto& l_ocmbs = l_omi_target.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>();

                // Sanity check for no empty vector
                if (l_ocmbs.empty())
                {
                    continue;
                }

                const auto& l_ocmb = l_ocmbs[0];

                l_data.clear();
                FAPI_TRY(p10_omi_isolation(l_omi_target, l_data));
                FAPI_TRY(p10_omi_tx_tdr_screen_check(l_omi_target, l_ocmb, l_data))
            }
        }
    }


fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}
