/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_bist_cleanup.C $ */
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
/// @file ody_omi_hss_bist_cleanup.C
/// @brief Cleans up the BIST operations
///
/// *HWP HW Maintainer: Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_omi_hss_bist_cleanup.H>
#include <ody_io_ppe_common.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_hss_bist_cleanup(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Start - BIST Cleanup");

    io_ppe_regs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_regs(PHY_PPE_WRAP0_ARB_CSAR,
            PHY_PPE_WRAP0_ARB_CSDR,
            PHY_ODY_OMI_BASE);

    ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_common(&l_ppe_regs);

    uint32_t l_rx_lanes = 0;
    uint32_t l_tx_lanes = 0;
    const uint8_t l_thread = 0;
    uint8_t l_done = 0;
    uint32_t l_fail = 0;
    uint8_t l_pos = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BUS_POS, i_target, l_pos));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_LANES, i_target, l_rx_lanes));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_TX_LANES, i_target, l_tx_lanes));

    FAPI_TRY(l_ppe_common.ext_cmd_start(i_target, l_thread, l_rx_lanes, l_tx_lanes, ody_io::CLEAR))
    FAPI_TRY(l_ppe_common.ext_cmd_poll(i_target, l_thread, ody_io::CLEAR, l_done, l_fail));

    FAPI_ASSERT(l_done && !l_fail,
                fapi2::IO_PPE_DONE_POLL_FAILED()
                .set_POS(l_pos)
                .set_FAIL(l_fail)
                .set_DONE(l_done)
                .set_TARGET(i_target),
                "IO PPE Ext Cmd Clear Done Fail on %d :: Done(%d), Fail(0x%04X)",
                l_pos, l_done, l_fail);

    FAPI_TRY(l_ppe_common.bist_cleanup(i_target, l_thread, l_rx_lanes, l_tx_lanes, l_done, l_fail),
             "Failed to run common HSS BIST cleanup");

    FAPI_ASSERT(l_done && !l_fail,
                fapi2::IO_PPE_DONE_CLEANUP_FAILED()
                .set_POS(l_pos)
                .set_FAIL(l_fail)
                .set_DONE(l_done)
                .set_TARGET(i_target),
                "IO PPE Bist Cleanup Done Fail on %d :: Done(%d), Fail(0x%04X)",
                l_pos, l_done, l_fail);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
