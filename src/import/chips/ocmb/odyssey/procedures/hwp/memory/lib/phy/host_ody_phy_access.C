/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/host_ody_phy_access.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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
/// @file host_ody_phy_access.C
/// @brief Host Odyssey PHY access functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_scom_mp_apbonly0.H>
#include <ody_scom_mp_drtub0.H>
#include <lib/phy/ody_phy_access.H>
#include <lib/phy/host_ody_phy_access.H>
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/find.H>
#ifdef __PPE__
    #include <ody_fifo.H>
#endif

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
/// @note Specific function for the host to allow for scom specialization as needed
/// @note This function has been duplicated in pmic_periodic_telemetry_utils_ddr5.H since we did not want to include unnecessary
///       libraries in to the PMIC code. Please make sure that both the locations of the function are up to date
///
fapi2::ReturnCode host_configure_phy_scom_access(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const mss::states i_state,
        const bool i_runtime)
{
#ifndef __PPE__
    return configure_phy_scom_access(i_target, i_state, i_runtime);
#else

    fapi2::buffer<uint64_t> l_data;
    const auto OFFSET = get_port_addr_offset(i_target);
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    const auto MICROCONTMUXSEL = scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL | OFFSET;
    const auto UCCLKHCLKENABLES = scomt::mp::DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES | OFFSET;
    FAPI_TRY(ody_get_scom(l_ocmb, MICROCONTMUXSEL, l_data));

    l_data.writeBit<scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL_MICROCONTMUXSEL>(i_state);
    FAPI_TRY(ody_put_scom(l_ocmb, MICROCONTMUXSEL, l_data));

    // Turn UCCLK on/off if at runtime
    if (i_runtime)
    {
        FAPI_TRY(ody_get_scom(l_ocmb, UCCLKHCLKENABLES, l_data));
        l_data.writeBit<scomt::mp::DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES_UCCLKEN>(i_state == mss::states::ON_N);
        FAPI_TRY(ody_put_scom(l_ocmb, UCCLKHCLKENABLES, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
#endif
}

///
/// @brief Gets the port offset
/// @param[in] i_target the target on which to operate
/// @return the scom offset based upon the port
///
uint64_t get_port_addr_offset(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // Port 0 has no offset
    if(mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(i_target) == 0)
    {
        return 0;
    }

    return mss::ody::generic_consts::PORT1_ADDR_OFFSET;
}

} // namespace phy
} // namespace ody
} // namespace mss
