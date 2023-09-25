/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_bist_init.C $ */
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
///
/// @file ody_omi_hss_bist_init.H
/// @brief Initializes the OMI SerDes for BIST functionality
///
/// *HWP HW Maintainer: Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_omi_hss_bist_init.H>
#include <ody_io_ppe_common.H>
#include <ody_scom_omi.H>

SCOMT_OMI_USE_D_REG_CMN_CONFIG
SCOMT_OMI_USE_D_REG_DL0_CONFIG0
SCOMT_OMI_USE_D_REG_DL0_DEBUG_AID
SCOMT_OMI_USE_D_REG_DL0_CYA_BITS

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_hss_bist_init(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Start - BIST Init");

    io_ppe_regs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_regs(PHY_ODY_OMI_BASE);

    ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_common(&l_ppe_regs);

    using namespace scomt::omi;

    D_REG_CMN_CONFIG_t l_cmn_config;
    D_REG_DL0_CONFIG0_t l_dl0_config0;
    D_REG_DL0_DEBUG_AID_t l_dl0_debug_aid;
    D_REG_DL0_CYA_BITS_t l_dl0_cya;

    const uint8_t c_thread = 0;
    fapi2::ATTR_OMI_RX_LTEG_Type l_rx_lte_gain = 0;
    fapi2::ATTR_OMI_RX_LTEZ_Type l_rx_lte_zero = 0;
    int32_t l_rx_peak1 = 0;
    int32_t l_rx_peak2 = 0;
    uint8_t l_dacTest = 0;
    uint8_t l_esdTest = 0;
    uint8_t l_bist_timer = 0;
    uint32_t l_rx_mask = 0;
    fapi2::ATTR_FREQ_OMI_MHZ_Type l_omi_freq;

    // Get the necessary attributes
    FAPI_DBG("Getting attributes");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_LANES, i_target, l_rx_mask));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_BIST_DAC_TEST, i_target, l_dacTest));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_BIST_ESD_TEST, i_target, l_esdTest));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_BIST_TIMER, i_target, l_bist_timer));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, i_target, l_omi_freq));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_LTEG, i_target, l_rx_lte_gain));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_LTEZ, i_target, l_rx_lte_zero));

    FAPI_TRY(l_cmn_config.getScom(i_target));
    l_cmn_config.set_DBG_EN(1);
    FAPI_TRY(l_cmn_config.putScom(i_target));

    FAPI_TRY(l_dl0_config0.getScom(i_target));
    l_dl0_config0.set_ENABLE(1);
    FAPI_TRY(l_dl0_config0.putScom(i_target));

    FAPI_TRY(l_dl0_debug_aid.getScom(i_target));
    l_dl0_debug_aid.set_PRBS_RESET(0);
    FAPI_TRY(l_dl0_debug_aid.putScom(i_target));

    FAPI_TRY(l_dl0_cya.getScom(i_target));
    l_dl0_cya.set_PRBS15_NPRBS7(1);
    FAPI_TRY(l_dl0_cya.putScom(i_target));

    FAPI_TRY(l_ppe_common.bist_init(i_target, 0, l_dacTest, l_esdTest),
             "Failed to run common HSS BIST init");

    FAPI_TRY(l_ppe_common.bist_init_thread(i_target, c_thread, l_rx_mask, l_omi_freq, l_bist_timer, 0),
             "Failed to run common HSS BIST init");

    if ( l_omi_freq < 32000)
    {
        l_rx_peak1 = 4;
    }
    else
    {
        l_rx_peak2 = 8;
    }

    FAPI_TRY(l_ppe_common.hss_init_rx(i_target,
                                      c_thread,
                                      l_rx_mask,
                                      l_rx_lte_gain,
                                      l_rx_lte_zero,
                                      l_rx_peak1,
                                      l_rx_peak2));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
