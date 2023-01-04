/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/common_io_omi_tdr.C $ */
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
/// @file common_io_omi_tdr.C
/// @brief OMI TDR procedure
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <common_io_omi_tdr.H>
#include <common_io_tdr.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


fapi2::ReturnCode common_io_omi_tdr(
    const fapi2::Target < fapi2::TARGET_TYPE_OCMB_CHIP | fapi2::TARGET_TYPE_OMI > & i_tgt,
    const uint64_t& i_base_addr)
{

    const uint32_t c_groupa_mask = 0xA5;
    const uint32_t c_groupb_mask = 0x5A;
    uint32_t l_groupa = 0x0;
    uint32_t l_groupb = 0x0;
    fapi2::errlSeverity_t l_sev;
    fapi2::ATTR_MFG_FLAGS_Type l_mfg_flags = {0};
    TdrResult l_status = TdrResult::None;
    uint32_t l_length = 0;

    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_tgt, l_tgt_str, sizeof(l_tgt_str));

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MFG_FLAGS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mfg_flags) );

    for (uint8_t l_lane = 0; l_lane < 8; l_lane++)
    {
        FAPI_TRY(common_io_tdr(i_tgt, i_base_addr, l_lane, l_status, l_length));

        FAPI_DBG("Checking %s on lane %d with status %d.", l_tgt_str, l_lane, l_status);

        if (l_status != TdrResult::Good)
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
                               .set_TARGET_CHIP(i_tgt)
                               .set_LANE(l_lane)
                               .set_STATUS(l_status)
                               .set_DISTANCE(l_length),
                               "OMI Tx TDR Fail on %s :: lane(%d), status(0x%04X) length(%d)...",
                               l_tgt_str, l_tgt_str, l_lane, l_status, l_length);

            l_groupa |= (0x1 << l_lane) & c_groupa_mask;
            l_groupb |= (0x1 << l_lane) & c_groupb_mask;
        }
    }

    if (l_groupa && l_groupb)
    {
        // note - FAPI_ASSERT_NOEXIT clears current_err on return
        FAPI_ASSERT_NOEXIT(false,
                           fapi2::POZ_IO_TX_TDR_MULTI_GROUP_ERROR()
                           .set_TARGET_CHIP(i_tgt)
                           .set_GROUPA(l_groupa)
                           .set_GROUPB(l_groupb),
                           "OMI Tx TDR Multiple Degrade Groups Fail on %s :: groupa(0x%02X), groupb(0x%02X)...",
                           l_tgt_str, l_groupa, l_groupb);
    }

fapi_try_exit:
    return fapi2::current_err;
}
