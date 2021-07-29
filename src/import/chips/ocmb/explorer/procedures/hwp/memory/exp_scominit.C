/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file exp_scominit.C
/// @brief Contains explorer scominits
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/shared/exp_defaults.H>
#include <lib/power_thermal/exp_throttle.H>
#include <explorer_scom.H>
#include <explorer_mds_scom.H>
#include <lib/dimm/exp_kind.H>
#include <generic/memory/mss_git_data_helper.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <lib/inband/exp_fw_adapter_properties.H>
#include <lib/phy/exp_phy_reset.H>

extern "C"
{

    ///
    /// @brief Scominit for Explorer
    /// @param[in] i_target the OCMB target to operate on
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_scominit( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("exp_scominit");
        bool l_is_mds = false;
        uint8_t l_sim = 0;

        if (mss::count_dimm(i_target) == 0)
        {
            FAPI_INF("... skipping mss_scominit %s - no DIMM ...", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // We need to make sure we hit all ports
        const auto& l_port_targets = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        const auto& l_mc = i_target.getParent<fapi2::TARGET_TYPE_OMI>()
                           .getParent<fapi2::TARGET_TYPE_MCC>()
                           .getParent<fapi2::TARGET_TYPE_MI>()
                           .getParent<fapi2::TARGET_TYPE_MC>();

        FAPI_TRY( mss::attr::get_is_simulation( l_sim) );

        for(const auto& l_port : l_port_targets)
        {
            fapi2::ReturnCode l_rc;
            FAPI_INF("phy scominit for %s", mss::c_str(l_port));

            // Check if mds and run appropriate initfile
            FAPI_TRY( mss::dimm::is_mds<mss::mc_type::EXPLORER>(l_port, l_is_mds) );

            if (l_is_mds)
            {
                FAPI_INF("Running explorer.mds.scom.initfile for %s", mss::c_str(l_port));
                FAPI_EXEC_HWP(l_rc, explorer_mds_scom, i_target, l_port, FAPI_SYSTEM, l_mc);
                FAPI_TRY(l_rc, "Error from explorer.mds.scom.initfile %s", mss::c_str(l_port));
            }
            else
            {
                FAPI_INF("Running explorer.scom.initfile for %s", mss::c_str(l_port));
                FAPI_EXEC_HWP(l_rc, explorer_scom, i_target, l_port, FAPI_SYSTEM, l_mc);
                FAPI_TRY(l_rc, "Error from explorer.scom.initfile %s", mss::c_str(l_port));
            }

            // Write power controls and emergency throttle settings
            FAPI_TRY(mss::power_thermal::thermal_throttle_scominit<mss::mc_type::EXPLORER>(l_port));
        }

        // Run required unmasks for LOCAL_FIR, FABR0, SRQFIR after scominit
        FAPI_TRY(mss::unmask::after_scominit<mss::mc_type::EXPLORER>(i_target));

        if (!l_sim)
        {
            bool l_image_a_good = true;
            bool l_image_b_good = true;

            FAPI_INF("mss::exp::ib::run_fw_adapter_properties_get %s", mss::c_str(i_target));
            // Print and record Explorer FW version info
            FAPI_TRY( mss::exp::ib::run_fw_adapter_properties_get(i_target, l_image_a_good, l_image_b_good) );

            // Assert MNFG_SPI_FLASH_AUTHENTICATION_FAIL if fw_adapter_properties says one of the images is bad
            if (!l_image_a_good || !l_image_b_good)
            {
                // Note: there is no way we could see both images bad here, because then we would not have booted this far
                const uint8_t l_image_num = !l_image_a_good ? 0 : 1;

                // In normal IPL, this fail should produce a recovered log and pass the procedure
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::EXP_SPI_FLASH_AUTH_FAIL(fapi2::FAPI2_ERRL_SEV_RECOVERED).
                                   set_OCMB_TARGET(i_target).
                                   set_IMAGE(l_image_num),
                                   "%s Explorer SPI flash authentication failed for image %s",
                                   mss::c_str(i_target), (!l_image_a_good ? "A" : "B"));

                // Set current_err back to success
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }

        // Resets the explorer PHY if needed
        FAPI_TRY(mss::exp::phy::reset(i_target));

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        FAPI_INF("End MSS SCOM init");
        return fapi2::current_err;
    }
}
