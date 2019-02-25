/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9a_mmio_util.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
//------------------------------------------------------------------------------------
//
/// @file p9a_mmio_util.C
/// @brief MMIO utility functions
//
// *HWP HWP Owner: Ben Gass bgass@us.ibm.com
// *HWP FW Owner: Daniel Crowell dcrowell@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

#include <p9a_mmio_util.H>
#include <p9_fbc_utils.H>
#include <p9_adu_setup.H>
#include <p9_adu_access.H>
#include <p9_adu_coherent_utils.H>


fapi2::ReturnCode addOMIBase(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                             uint64_t& io_mmioAddr)
{
    std::vector<uint64_t> l_base_addr_nm0;
    std::vector<uint64_t> l_base_addr_nm1;
    std::vector<uint64_t> l_base_addr_m;
    uint64_t l_addr_offset;
    uint64_t l_base_addr_mmio;

    fapi2::Target<fapi2::TARGET_TYPE_OMI> l_omi_target;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_chip_target;

    l_omi_target = i_target.getParent<fapi2::TARGET_TYPE_OMI>();
    l_chip_target = l_omi_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // determine base address of chip MMIO range
    FAPI_TRY(p9_fbc_utils_get_chip_base_address(l_chip_target,
             EFF_FBC_GRP_CHIP_IDS,
             l_base_addr_nm0,
             l_base_addr_nm1,
             l_base_addr_m,
             l_base_addr_mmio),
             "Error from p9_fbc_utils_get_chip_base_address");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET,
                           l_omi_target,
                           l_addr_offset),
             "Error from FAPI_ATTR_GET (ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET)");

    io_mmioAddr |= (l_base_addr_mmio | l_addr_offset);

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}
