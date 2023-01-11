/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_bist_init.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_hss_bist_init(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Start - BIST Init");

    io_ppe_regs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_regs(PHY_PPE_WRAP0_ARB_CSAR,
            PHY_PPE_WRAP0_ARB_CSDR,
            PHY_PPE_WRAP0_XIXCR);

    ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_common(&l_ppe_regs);

    const uint32_t c_odyOmiBaseAddr = 0x0000000008010C00;

    uint32_t l_numTxLanes = 0;
    uint32_t l_numRxLanes = 0;
    uint8_t l_dacTest = 0;
    uint8_t l_esdTest = 0;
    uint8_t l_bist_timer = 0;

    // Get the necessary attributes
    FAPI_DBG("Getting attributes");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_TX_LANES, i_target, l_numTxLanes));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_LANES, i_target, l_numRxLanes));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_BIST_DAC_TEST, i_target, l_dacTest));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_BIST_ESD_TEST, i_target, l_esdTest));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_BIST_TIMER, i_target, l_bist_timer));

    FAPI_TRY(l_ppe_common.bist_init(i_target, 0, l_bist_timer),
             "Failed to run common HSS BIST init");
    FAPI_TRY(l_ppe_common.bist_init_rx(i_target, c_odyOmiBaseAddr, 0, l_esdTest, l_dacTest, l_numRxLanes),
             "Failed to run common HSS BIST Rx init");
    FAPI_TRY(l_ppe_common.bist_init_tx(i_target, 0, l_numTxLanes),
             "Failed to run common HSS BIST Tx init");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
