/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_phy_reset.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file exp_phy_reset.C
/// @brief Procedures to reset the Explorer PHY
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

#include <generic/memory/lib/utils/c_str.H>
#include <lib/shared/exp_defaults.H>
#include <lib/exp_draminit_utils.H>
#include <lib/phy/exp_train_display.H>
#include <lib/phy/exp_train_handler.H>
#include <exp_inband.H>
#include <lib/eff_config/explorer_attr_engine_traits.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <lib/phy/exp_phy_reset.H>
#include <lib/exp_attribute_accessors_manual.H>

namespace mss
{
namespace exp
{
namespace phy
{

///
/// @brief Resets the explorer's PHY if needed
/// @param[in] i_target the explorer chip target in question
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode reset( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    // Checks if the PHY reset is needed
    mss::states l_is_reset_supported = mss::states::YES;
    FAPI_TRY(is_reset_supported(i_target, l_is_reset_supported));

    if(l_is_reset_supported == mss::states::NO)
    {
        FAPI_INF("%s does not support the separate PHY reset procedure", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Runs the PHY initialization workaround
    {
        uint32_t l_crc = 0;
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        host_fw_command_struct l_cmd;
        std::vector<uint8_t> l_rsp_data;

        user_input_msdg l_phy_params;
        FAPI_TRY(mss::exp::setup_phy_params(i_target, l_phy_params),
                 "Failed setup_phy_params() for %s", mss::c_str(i_target));

        FAPI_TRY(mss::exp::print_phy_params(i_target, l_phy_params),
                 "Failed print_phy_params() for %s", mss::c_str(i_target));

        // Copy the PHY initialization parameters into the internal buffer of Explorer
        FAPI_TRY( mss::exp::ib::putUserInputMsdg(i_target, l_phy_params, l_crc),
                  "Failed putUserInputMsdg() for %s", mss::c_str(i_target) );

        // Issue the PHY reset cmd though EXP-FW REQ buffer
        FAPI_TRY(send_host_phy_init_cmd(i_target, l_crc, mss::exp::phy_init_mode::RESET, l_cmd));
        FAPI_TRY(mss::exp::check_host_fw_response(i_target, l_cmd, l_rsp_data, l_rc));
        FAPI_TRY(l_rc, "%s Explorer received a bad response from PHY reset", mss::c_str(i_target));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_INF("PHY reset - errors reported - trying to blame FIR's %s",
             mss::c_str(i_target));

    // Due to the RAS/PRD requirements, we need to check for FIR's
    // If any FIR's have lit up, this fail could have been caused by the FIR, rather than bad hardware
    // So, let PRD retrigger this step to see if we can resolve the issue
    // Note: the DRAMINIT FIR's are used as this function is coupled with the DRAMINIT logic
    return mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER, mss::check::firChecklist::DRAMINIT>(
               i_target, fapi2::current_err);
}

///
/// @brief Checks if the Explorer FW supports the separate reset procedure
/// @param[in] i_target the explorer chip target in question
/// @param[out] o_is_ext_reset_supported YES if the external PHY reset is needed, otherwise no
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode is_reset_supported( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      mss::states& o_is_reset_supported )
{
    // Microchip FW does not support the PHY reset at a version of CL397559 or lower
    constexpr uint32_t PHY_RESET_UNSUPPORTED = 397559;

    // Grab the firmware revision that was booted
    o_is_reset_supported = mss::states::NO;
    uint32_t l_fw_revision = 0;
    FAPI_TRY(mss::get_booted_fw_version(i_target, l_fw_revision));

    // If we're at or below the unsupported value? the reset is unsupported
    // Otherwise it's supported
    o_is_reset_supported = l_fw_revision <= PHY_RESET_UNSUPPORTED ? mss::states::NO : mss::states::YES;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns phy
} // ns exp
} // ns mss