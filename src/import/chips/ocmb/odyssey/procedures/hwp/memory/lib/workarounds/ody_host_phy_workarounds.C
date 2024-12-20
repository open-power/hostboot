/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_host_phy_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024,2025                        */
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
/// @file ody_host_phy_workarounds.C
/// @brief Workarounds for host to check Odyssey PHY related issues
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/phy/ody_phy_utils.H>
#include <ody_scom_mp_mastr_b0.H>
#include <lib/workarounds/ody_host_phy_workarounds.H>
#include <lib/phy/host_ody_phy_access.H>
#include <lib/shared/ody_consts.H>
#ifdef __PPE__
    #include <ody_fifo.H>
#endif

namespace mss
{
namespace ody
{
namespace phy
{
namespace workarounds
{

///
/// @brief Catches and asserts out if the Odyssey suffered a fatal error
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Identifies a fatal error by if the ODT disable bit is set
///
fapi2::ReturnCode gard_fatal_errors( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target )
{
    // If the bit is disabled, then the ODT are enabled
    // Enabled ODT indicates that the port trained cleanly
    constexpr bool ODT_ENABLED = false;
    fapi2::buffer<uint64_t> l_data;

    // Enables scom access
    FAPI_TRY(host_configure_phy_scom_access(i_target, mss::states::ON_N));

#ifdef __PPE__
    // Grabs the ODT register value
    {
        const auto OFFSET = get_port_addr_offset(i_target);
        const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
        const auto ODTDEBUGDISABLE = scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_ODTDEBUGDISABLE | OFFSET;
        FAPI_TRY(ody_get_scom(l_ocmb, ODTDEBUGDISABLE, l_data));
    }
#else
    FAPI_TRY(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_ODTDEBUGDISABLE, l_data));
#endif

    // Disables scom access
    FAPI_TRY(host_configure_phy_scom_access(i_target, mss::states::OFF_N));

    // Checks that the register value is good
    FAPI_ASSERT(l_data.getBit<scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_ODTDEBUGDISABLE_ODTDBYTEDEBUGDISABLE>() == ODT_ENABLED,
                fapi2::ODY_DRAMINIT_FATAL_ERROR_NOT_RECOVERED()
                .set_PORT_TARGET(i_target)
                .set_ODT_REG_VALUE(l_data),
                TARGTIDFORMAT " took a fatal error! register value:" UINT64FORMAT, TARGTID,
                UINT64_VALUE(l_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns workarounds
} // ns phy
} // ns ody
} // ns mss
