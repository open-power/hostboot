/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_phy_access.C $ */
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
// EKB-Mirror-To: hostboot
///
/// @file ody_phy_access.C
/// @brief Odyssey PHY access functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/phy/ody_phy_access.H>
#include <ody_scom_mp_apbonly0.H>
#include <ody_scom_mp_drtub0.H>

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
/// @param[in] i_runtime true if running at runtime, meaning the UCCLK needs to be switched on/off (default: false)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note This function has been duplicated in pmic_periodic_telemetry_utils_ddr5.C since we did not want to include unnecessary
///       libraries in to the PMIC code. Please make sure that both the locations of the function are up to date
///
fapi2::ReturnCode configure_phy_scom_access(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const mss::states i_state,
        const bool i_runtime)
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL, l_data));

    l_data.writeBit<scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL_MICROCONTMUXSEL>(i_state);
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL, l_data));

    // Turn UCCLK on/off if at runtime
    if (i_runtime)
    {
        FAPI_TRY(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES, l_data));
        l_data.writeBit<scomt::mp::DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES_UCCLKEN>(i_state == mss::states::ON_N);
        FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace phy
} // namespace ody
} // namespace mss
