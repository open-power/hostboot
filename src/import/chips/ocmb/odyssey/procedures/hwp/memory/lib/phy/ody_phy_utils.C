/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_phy_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file ody_phy_utils.C
/// @brief Odyssey PHY utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

#include <lib/phy/ody_phy_utils.H>
// TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB

namespace mss
{
namespace ody
{
namespace phy
{

///
/// @brief Configure the PHY to allow/disallow register accesses via scom
/// @param[in] i_target the target on which to operate
/// @param[in] i_state the state to set the PHY to - either mss::states::ON_N (scom access) or mss::states::OFF_N (training access)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_phy_scom_access(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const mss::states i_state)
{
    // TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
    // For now using the Synopsys register location documentation
    constexpr uint64_t MICROCONTMUXSEL = 0x000d0000;
    constexpr uint64_t MICROCONTMUXSEL_MICROCONTMUXSEL = 63;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(fapi2::getScom(i_target, MICROCONTMUXSEL, l_data));

    l_data.writeBit<MICROCONTMUXSEL_MICROCONTMUXSEL>(i_state);

    FAPI_TRY(fapi2::putScom(i_target, MICROCONTMUXSEL, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace phy
} // namespace ody
} // namespace mss
