/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_bist_poll.C $ */
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
/// @file ody_omi_hss_bist_poll.C
/// @brief Odyssey HSS BIST HWP
///
/// *HWP HW Maintainer : Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_omi_hss_bist_poll.H>
#include <ody_io_ppe_common.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_hss_bist_poll(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("HWP Start: ody_omi_hss_bist_poll");

    io_ppe_regs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_regs(PHY_PPE_WRAP0_ARB_CSAR,
            PHY_PPE_WRAP0_ARB_CSDR,
            PHY_PPE_WRAP0_XIXCR);

    ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_common(&l_ppe_regs);

    const fapi2::buffer<uint64_t> l_num_threads = 1;
    const fapi2::buffer<uint64_t> l_ext_cmd_override = 0;
    fapi2::buffer<uint64_t> l_done = 0;
    fapi2::buffer<uint64_t> l_fail = 0;

    FAPI_TRY(l_ppe_common.bist_poll(i_target, l_num_threads, l_done, l_fail, l_ext_cmd_override));

    FAPI_ASSERT(l_done && !l_fail,
                fapi2::IO_PPE_DONE_POLL_FAILED()
                .set_TARGET(i_target),
                "IO PPE done poll time-out or ext_cmd_fail seen!");


fapi_try_exit:
    FAPI_DBG("HWP End: ody_omi_hss_bist_poll");
    return fapi2::current_err;
}
