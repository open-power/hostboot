/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/mca_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file workarounds/mca_workarounds.C
/// @brief Workarounds for the MCA logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/workarounds/mca_workarounds.H>
#include <generic/memory/lib/utils/scom.H>

namespace mss
{

namespace workarounds
{

///
/// @brief Checks whether the workaround needs to be run for non-TSV parts
/// @param[in] const ref to the target
/// @param[in] i_power_control - MRW power control - passed in to make it easier to test
/// @param[in] i_idle_power_control - MRW idle power control value - passed in to make it easier to test
/// @return bool true iff we're on a Nimbus >= EC 2.0, non-TSV, and self-time-refresh
///
bool check_str_non_tsv_parity_workaround(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_power_control,
        const uint64_t i_idle_power_control)
{
    const auto l_less_than_dd2 = chip_ec_nimbus_lt_2_0(i_target);

    // If either STR is enabled, STR is enabled for the whole system
    // Per the power thermal team, we only need to check PD_AND_STR and PD_AND_STR_CLK_STOP
    const bool l_str_enabled = (i_power_control == fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR ||
                                i_power_control == fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP) ||
                               (i_idle_power_control == fapi2::ENUM_ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED_PD_AND_STR ||
                                i_idle_power_control == fapi2::ENUM_ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP);

    // Now checks whether the DIMM's are TSV
    // Note: eff_config plug rules will require that the whole MCA either have TSV or non-TSV DIMMs
    // As such, it is fine to just check DIMM0 for if it is a TSV DIMM or not
    uint8_t l_stack_type[MAX_DIMM_PER_PORT] = {};
    bool l_tsv = false;
    FAPI_TRY(mss::eff_prim_stack_type(i_target, l_stack_type));

    // If DIMM0 is a TSV, set to true (DIMM0 has to exist and needs to equal DIMM0 if it's 3DS)
    l_tsv = (l_stack_type[0] == fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_3DS);

    // The workaround is needed iff
    // 1) greater than or equal to DD2
    // 2) self time refresh is enabled
    // 3) the DIMM's are not TSV
    FAPI_INF("%s %s DD2 STR: %s DIMM %s TSV", mss::c_str(i_target),
             l_less_than_dd2 ? "less than" : "greater than or equal to",
             l_str_enabled ? "enabled" : "disabled",
             l_tsv ? "is" : "isn't");
    return (!l_less_than_dd2) && l_str_enabled && (!l_tsv);

fapi_try_exit:
    FAPI_ERR("failed calling check_str_non_tsv_parity_workaround: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief Blindly disables the CID parity
/// @param[in] i_target The MCA target on which to run
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Used for code beautification and unit testing
///
fapi2::ReturnCode disable_cid_parity(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    // constexpr's to make the code a little prettier
    constexpr uint64_t MBA_FARB1Q = MCA_MBA_FARB1Q;
    constexpr uint64_t CID_PARITY_DISABLE = MCA_MBA_FARB1Q_CFG_DDR4_PARITY_ON_CID_DIS;

    // Disables the parity
    fapi2::buffer<uint64_t> l_data;

    // TODO:RTC179509 - update getScom/putScom when we have register API for FARB1Q
    // Read...
    FAPI_TRY(mss::getScom(i_target, MBA_FARB1Q, l_data));

    // TODO:RTC179510 - update the set bit when we have register API for FARB1Q's parity disable bit
    // Modify...
    l_data.setBit<CID_PARITY_DISABLE>();

    // Write
    FAPI_TRY(mss::putScom(i_target, MBA_FARB1Q, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disables CID parity on non-TSV, DD2 parts that run self-time refresh
/// @param[in] i_target The MCA target on which to run
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode str_non_tsv_parity(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    bool l_workaround = false;

    // STR can be enabled via two attributes - ATTR_MSS_MRW_POWER_CONTROL_REQUESTED or ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED
    uint8_t l_power_control = 0;
    uint8_t l_idle_power_control = 0;
    FAPI_TRY( mss::mrw_power_control_requested(l_power_control) );
    FAPI_TRY( mss::mrw_idle_power_control_requested(l_idle_power_control) );

    // If the workaround is not needed, skip it
    l_workaround = check_str_non_tsv_parity_workaround(i_target, l_power_control, l_idle_power_control);

    if(!l_workaround)
    {
        FAPI_INF("%s self-time refresh parity workaround is not needed and is being skipped", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Disables the parity
    FAPI_TRY(disable_cid_parity(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns workarounds

} // ns mss
