/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_scominit_phy_check_workaround.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/// @file ody_scominit_phy_check_workaround.C
/// @brief Odyssey workarounds set MBXLT0 bits relative to num PHY/ports found
///
// *HWP HWP Owner: David J Chung <dj.chung@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <lib/workarounds/ody_scominit_phy_check_workaround.H>
#include <ody_scom_ody_odc.H>

namespace mss
{
namespace ody
{
namespace workarounds
{
///
/// @brief Checks if 2 mem ports are found and sets MBXLT0 bits accordingly
/// @param[in] i_target the OCMB target to operate on
/// @param[in] i_num_ports num mem ports found on ocmb
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode mbxlt0_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                const int16_t i_num_ports)
{
    fapi2::buffer<uint64_t> l_buffer;

    if(i_num_ports == 2)
    {
        // Bits are set to 0 by default of scominit file
        FAPI_TRY(getScom(i_target, scomt::ody::ODC_SRQ_MBXLT0, l_buffer));

        // Set EN bit and D_BIT_MAP to 2 (0x010)
        l_buffer.setBit<scomt::ody::ODC_SRQ_MBXLT0_ROQ1_ENABLE>();
        // D_BIT_MAP dictates RDF side select addr, if 2 dimm are attached set to 2 (0x010) according to design team
        l_buffer.insertFromRight<scomt::ody::ODC_SRQ_MBXLT0_D_BIT_MAP,
                                 scomt::ody::ODC_SRQ_MBXLT0_D_BIT_MAP_LEN>
                                 (0x010);

        // Set reg accordingly
        FAPI_TRY(putScom(i_target, scomt::ody::ODC_SRQ_MBXLT0, l_buffer));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // ns workarounds
} // ns ody
} // ns mss
