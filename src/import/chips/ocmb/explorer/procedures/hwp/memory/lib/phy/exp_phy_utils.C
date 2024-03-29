/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_phy_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file exp_phy_utils.C
/// @brief Utility functions to control phy access
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <explorer_scom_addresses_fixes.H>
#include <explorer_scom_addresses_fld_fixes.H>

namespace mss
{
namespace exp
{
namespace phy
{

///
/// @brief Configure the PHY to allow/disallow register accesses via scom
/// @param[in] i_target the target on which to operate
/// @param[in] i_state the state to set the PHY to - either mss::states::ON_N or mss::states::OFF_N
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_phy_access(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                       const mss::states i_state)
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(fapi2::getScom(i_target, EXP_APBONLY0_MICROCONTMUXSEL, l_data));

    l_data.writeBit<EXP_APBONLY0_MICROCONTMUXSEL_MICROCONTMUXSEL>(i_state);

    FAPI_TRY(fapi2::putScom(i_target, EXP_APBONLY0_MICROCONTMUXSEL, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disable the ALERT_N bit in MCHP PHY
///
/// @param[in] i_target MEM_PORT target
/// @param[in] i_is_planar true if this is a planar system
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode disable_alert_n(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint8_t i_is_planar)
{
    // Skips this functionality if the system is a planar
    // The alert_n signal is not wired back for DDIMM's, but is for planar systems
    // As such, this functioanlity can be skipped for planar systems
    if(i_is_planar == fapi2::ENUM_ATTR_MEM_MRW_IS_PLANAR_TRUE)
    {
        FAPI_INF("%s is in a planar system. Keeping alert_n enabled", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    fapi2::buffer<uint64_t> l_data;

    // Need to enable PHY access in order to scom the PHY regs
    FAPI_TRY(mss::exp::phy::configure_phy_access(i_target, mss::states::ON_N));

    FAPI_TRY(fapi2::getScom(i_target, EXP_DDR4_PHY_MASTER0_MEMALERTCONTROL, l_data));

    // Clear MEMALERTCONTROL
    l_data.clearBit<EXP_DDR4_PHY_MASTER0_MEMALERTCONTROL_MALERTRXEN>();
    FAPI_TRY(fapi2::putScom(i_target, EXP_DDR4_PHY_MASTER0_MEMALERTCONTROL, l_data));

    FAPI_TRY(mss::exp::phy::configure_phy_access(i_target, mss::states::OFF_N));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable async drive of the ALERT_N receiver in MCHP PHY for planar
///
/// @param[in] i_target MEM_PORT target
/// @param[in] i_is_planar true if this is a planar system
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode enable_alert_n_sync_bypass(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_is_planar)
{
    // Skips this functionality if the system is not planar
    if(i_is_planar == fapi2::ENUM_ATTR_MEM_MRW_IS_PLANAR_FALSE)
    {
        FAPI_INF("%s is not in a planar system. Skipping alert_n sync bypass enable", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    fapi2::buffer<uint64_t> l_data;

    // Need to enable PHY access in order to scom the PHY regs
    FAPI_TRY(mss::exp::phy::configure_phy_access(i_target, mss::states::ON_N));

    FAPI_TRY(fapi2::getScom(i_target, EXP_DDR4_PHY_MASTER0_MEMALERTCONTROL2, l_data));

    // Set MALERTSTNCBYPASS
    l_data.setBit<EXP_DDR4_PHY_MASTER0_MEMALERTCONTROL2_MALERTSTNCBYPASS>();
    FAPI_TRY(fapi2::putScom(i_target, EXP_DDR4_PHY_MASTER0_MEMALERTCONTROL2, l_data));

    FAPI_TRY(mss::exp::phy::configure_phy_access(i_target, mss::states::OFF_N));

fapi_try_exit:
    return fapi2::current_err;
}

} // phy
} // exp
} // mss
