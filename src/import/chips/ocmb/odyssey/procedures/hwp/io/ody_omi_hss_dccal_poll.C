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
            PHY_ODY_OMI_BASE);

    ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_common(&l_ppe_regs);

    static fapi2::buffer<uint64_t> l_cmd = ody_io::HW_REG_INIT_PG | ody_io::DCCAL_PL |
                                           ody_io::TX_ZCAL_PL | ody_io::TX_FFE_PL |
                                           ody_io::POWER_ON_PL | ody_io::TX_FIFO_INIT_PL;

    const uint8_t l_thread = 0;
    uint8_t l_done = 0;
    uint32_t l_fail = 0;

    l_ppe_regs.flushCache(i_target);
    FAPI_TRY(l_ppe_common.ext_cmd_poll(i_target, l_thread, l_cmd, l_done, l_fail));

    FAPI_ASSERT(l_done && !l_fail,
                fapi2::IO_PPE_DONE_DCCAL_FAILED()
                .set_TARGET(i_target)
                .set_FAIL(l_fail)
                .set_DONE(l_done),
                "IO PPE Dccal Done Fail :: Done(%d), Fail(0x%04X)",
                l_done, l_fail);

fapi_try_exit:
    FAPI_DBG("End ody_omi_hss_dccal_poll");
    return fapi2::current_err;
}
