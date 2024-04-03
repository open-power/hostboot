/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_ddr4_edpl.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file p10_omi_ddr4_edpl.C
/// @brief Apply P10 OMI DDR4 EDPL changes to active systems
///
// *HWP HWP Owner: Chris Steffen  <cwsteffen@us.ibm.com>
// *HWP HWP Backup: Josh Chica <josh.chica@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p10_omi_ddr4_edpl.H>
#include <p10_scom_omi.H>
#include <p10_scom_omic.H>
#include <explorer_scom_addresses.H>
#include <lib/shared/exp_consts.H>
#include <explorer_scom_addresses_fld.H>

fapi2::ReturnCode p10_omi_ddr4_edpl(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                    const bool i_enable_edpl)
{

    FAPI_INF("Starting p10_omi_ddr4_edpl");
    uint8_t l_ocmb_type = fapi2::ENUM_ATTR_NAME_NONE;
    fapi2::buffer<uint64_t> l_buffer;
    const auto l_omic_target = i_ocmb_target.getParent<fapi2::TARGET_TYPE_OMI>()
                               .getParent<fapi2::TARGET_TYPE_OMIC>();

    do
    {
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_ocmb_target, l_ocmb_type));
        FAPI_DBG("OCMB Type: %d", l_ocmb_type);

        if (l_ocmb_type != fapi2::ENUM_ATTR_NAME_EXPLORER)
        {
            FAPI_DBG("OCMB type is not Explorer, breaking");
            break;
        }

        FAPI_DBG("Setting Recal timer to 100ms");
        // Setting Recal Timer on Host side to 100ms
        // - The Host Recal Timer controls the OCMB Recal Rate
        FAPI_TRY(scomt::omic::PREP_CMN_CONFIG(l_omic_target));
        FAPI_TRY(scomt::omic::GET_CMN_CONFIG(l_omic_target, l_buffer));
        scomt::omic::SET_CMN_CONFIG_CFG_CMN_RECAL_TIMER(mss::omi::recal_timer::RECAL_TIMER_100MS, l_buffer);
        FAPI_TRY(scomt::omic::PUT_CMN_CONFIG(l_omic_target, l_buffer));

        // Enable or Disable the EDPL Feature
        FAPI_DBG("Setting EDPL Threshold to %d", i_enable_edpl);
        FAPI_TRY(fapi2::getScom(i_ocmb_target, EXPLR_DLX_DL0_CONFIG1, l_buffer));

        if (i_enable_edpl)
        {
            l_buffer.insertFromRight<EXPLR_DLX_DL0_CONFIG1_CFG_EDPL_THRESHOLD,
                                     EXPLR_DLX_DL0_CONFIG1_CFG_EDPL_THRESHOLD_LEN>(mss::omi::edpl_err_thres::EDPL_ERR_THRES_128);
        }
        else
        {
            l_buffer.insertFromRight<EXPLR_DLX_DL0_CONFIG1_CFG_EDPL_THRESHOLD,
                                     EXPLR_DLX_DL0_CONFIG1_CFG_EDPL_THRESHOLD_LEN>(mss::omi::edpl_err_thres::EDPL_ERR_THRES_DISABLED);
        }

        FAPI_TRY(fapi2::putScom(i_ocmb_target, EXPLR_DLX_DL0_CONFIG1, l_buffer));
    }
    while(0);

fapi_try_exit:
    FAPI_INF("End p10_omi_ddr4_edpl");
    return fapi2::current_err;
}
