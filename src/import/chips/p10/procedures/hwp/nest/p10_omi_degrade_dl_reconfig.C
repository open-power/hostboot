/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_omi_degrade_dl_reconfig.C $ */
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
// EKB-Mirror-To: hostboot
///
/// @file p10_omi_degrade_dl_reconfig.H
/// @brief Recofigure DL logic post-OMI degrade (from x8->x4)
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------
///

#include <p10_omi_degrade_dl_reconfig.H>
#include <p10_scom_mcc.H>
#include <p10_scom_omi.H>

/// @brief Reconfigure DL logic post-OMI degrade (from x8->x4)
///
/// @param[in] i_target OMI target to reconfigure
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_omi_degrade_dl_reconfig(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    FAPI_DBG("Begin");

    // confirm that interface is in x4 mode (check both host/buffer side
    // status register indicators)
    bool l_x4 = false;
    {
        using namespace scomt::omi;
        fapi2::buffer<uint64_t> l_dl_status = 0;
        uint8_t l_dl_actual_ln_width = 0;
        const uint8_t DL_LN_WIDTH_X4 = 0x2;

        // check host side first...
        FAPI_DBG("Polling host side DL status...");
        FAPI_TRY(fapi2::getScom(i_target, STATUS, l_dl_status));
        l_dl_status.extractToRight<STATUS_ACTUAL_LN_WIDTH, STATUS_ACTUAL_LN_WIDTH_LEN>
        (l_dl_actual_ln_width);
        l_x4 = (l_dl_actual_ln_width == DL_LN_WIDTH_X4);
        FAPI_DBG("  Width encoded: 0x%X (x4: %d)",
                 l_dl_actual_ln_width, ((l_x4) ? (1) : (0)));

        // ...and buffer next
        if (!l_x4)
        {
            FAPI_DBG("Polling buffer side DL status...");

            for (auto l_exp_target : i_target.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>())
            {
                const uint64_t EXP_DL_STATUS_ADDR = 0x8012816ull;
                FAPI_TRY(fapi2::getScom(l_exp_target, EXP_DL_STATUS_ADDR, l_dl_status));
                l_dl_status.extractToRight<STATUS_ACTUAL_LN_WIDTH, STATUS_ACTUAL_LN_WIDTH_LEN>
                (l_dl_actual_ln_width);
                l_x4 = (l_dl_actual_ln_width == DL_LN_WIDTH_X4);
                FAPI_DBG("  Width encoded: 0x%X (x4: %d)",
                         l_dl_actual_ln_width, ((l_x4) ? (1) : (0)));

                if (l_x4)
                {
                    break;
                }
            }
        }
    }

    // if in x4 mode, adjust DSTLCFG associated with this OMI channel
    if (l_x4)
    {
        using namespace scomt::mcc;
        const auto l_mcc_target = i_target.getParent<fapi2::TARGET_TYPE_MCC>();
        const uint8_t DSTLCFG_WR_DBL_THRESHOLD = 0xF;
        fapi2::buffer<uint64_t> l_dstlcfg = 0;

        FAPI_DBG("Adjusting DSTLCFG...");
        FAPI_TRY(GET_DSTL_DSTLCFG(l_mcc_target, l_dstlcfg));
        SET_DSTL_DSTLCFG_WR_DBL_THRESHOLD(DSTLCFG_WR_DBL_THRESHOLD, l_dstlcfg);
        FAPI_TRY(PUT_DSTL_DSTLCFG(l_mcc_target, l_dstlcfg));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
