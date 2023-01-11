/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_config.C $ */
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
/// @file ody_omi_hss_config.C
/// @brief Sets up the threads for the IO PPE
///
/// *HWP HW Maintainer: Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_omi_hss_config.H>
#include <ody_io_ppe_common.H>
#include <ody_scom_omi.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_hss_config(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Start");

    io_ppe_regs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_regs(scomt::omi::PHY_PPE_WRAP0_ARB_CSAR,
            scomt::omi::PHY_PPE_WRAP0_ARB_CSDR,
            scomt::omi::PHY_PPE_WRAP0_XIXCR);

    ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_common(&l_ppe_regs);

    const fapi2::buffer<uint64_t> l_gcr_ids[] = { 0 };
    const fapi2::buffer<uint64_t> l_rx_lanes[] = { 8 };
    const fapi2::buffer<uint64_t> l_tx_lanes[] = { 8 };
    FAPI_TRY(l_ppe_common.config(i_target,
                                 1, //num_threads
                                 l_gcr_ids,
                                 l_rx_lanes,
                                 l_tx_lanes,
                                 0, // spread_en
                                 0, // pcie_mode
                                 1)); //serdes_16_to_1

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
