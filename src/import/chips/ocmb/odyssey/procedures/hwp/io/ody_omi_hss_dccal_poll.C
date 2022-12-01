/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_dccal_poll.C $ */
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
///------------------------------------------------------------------------------
/// @file ody_omi_hss_dccal_poll.C
/// @brief Polls DC cal
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------

#include <ody_omi_hss_dccal_poll.H>
#include <ody_io_ppe_common.H>

///
/// @brief Polls DC cal
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode ody_omi_hss_dccal_poll(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Starting ody_omi_hss_dccal_poll");
    fapi2::buffer<uint64_t> l_data = 0;

    io_ppe_regs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_regs(PHY_PPE_WRAP0_ARB_CSAR,
            PHY_PPE_WRAP0_ARB_CSDR,
            PHY_PPE_WRAP0_XIXCR);

    ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_common(&l_ppe_regs);

    const fapi2::buffer<uint64_t> l_rx_lanes = 0xFF000000;
    const fapi2::buffer<uint64_t> l_tx_lanes = 0xFF000000;
    const fapi2::buffer<uint64_t> l_num_threads = 1;
    fapi2::buffer<uint8_t> l_done = 0;
    int l_trys = ody_io::IO_PPE_DCCAL_DONE_POLL_TRYS;

    while (!l_done && l_trys > 0)
    {
        l_ppe_regs.flushCache(i_target);
        FAPI_TRY(l_ppe_common.check_init_start_done(i_target, l_num_threads,
                 l_rx_lanes, l_tx_lanes, l_done));

        if (!l_done)
        {
            fapi2::delay(ody_io::IO_PPE_DCCAL_DONE_POLL_DELAY_NS, ody_io::IO_PPE_DCCAL_DONE_POLL_DELAY_SIM_CYCLES);
        }

        l_trys--;
    }

    FAPI_ASSERT(l_done,
                fapi2::IO_PPE_DONE_POLL_FAILED()
                .set_TARGET(i_target),
                "IO PPE done poll time-out" );

fapi_try_exit:
    FAPI_DBG("End ody_omi_hss_dccal_poll");
    return fapi2::current_err;
}
