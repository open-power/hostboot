/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
/// @file ody_scominit.C
/// @brief Contains Odyssey scominits
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <fapi2.H>

#ifndef __PPE__
    #include <generic/memory/lib/utils/c_str.H>
    #include <generic/memory/mss_git_data_helper.H>
#endif

#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/power_thermal/ody_throttle.H>
#include <lib/fir/ody_unmask.H>
#include <odyssey_mp_scom.H>
#include <odyssey_scom.H>
#include <ody_scominit.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/power_thermal/ody_throttle_traits.H>
#include <lib/workarounds/ody_scominit_phy_check_workaround.H>
#include <generic/memory/lib/utils/power_thermal/gen_throttle.H>

extern "C"
{
    ///
    /// @brief Scominit for Odyssey
    /// @param[in] i_target the OCMB target to operate on
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode ody_scominit( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
#ifndef __PPE__
        mss::display_git_commit_info("ody_scominit");
#endif

        const auto& l_port_targets = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

        if (l_port_targets.empty())
        {
            FAPI_INF(TARGTIDFORMAT "... skipping mss_scominit no Ports ...", TARGTID);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        // Assuming RDF0/1 are the same across all kind traits will need to add plug rule to confirm this
        FAPI_INF( TARGTIDFORMAT " running odyssey.scom.initfile", TARGTID);
        FAPI_EXEC_HWP(l_rc, odyssey_scom, i_target, l_port_targets[0], FAPI_SYSTEM);
        FAPI_TRY(l_rc, TARGTIDFORMAT " error from odyssey.scom.initfile", TARGTID);

        for(const auto& l_port : l_port_targets)
        {
            FAPI_INF(GENTARGTIDFORMAT " phy scominit for MEM_PORT type ATTRs on port", GENTARGTID(l_port));

            FAPI_INF( GENTARGTIDFORMAT " running odyssey.mp.scom.initfile", GENTARGTID(l_port));
            FAPI_EXEC_HWP(l_rc, odyssey_mp_scom, l_port);
            FAPI_TRY(l_rc, GENTARGTIDFORMAT " error from odyssey.mp.scom.initfile", GENTARGTID(l_port));

        }

        // Helper funct to set MBXLT0 bits if 2 phy/ports found
        FAPI_TRY(mss::ody::workarounds::mbxlt0_helper(i_target, l_port_targets.size()));

        // Write power controls and emergency throttle settings
        FAPI_TRY(mss::power_thermal::thermal_throttle_scominit<mss::mc_type::ODYSSEY>(i_target));

        // Unmask the FIRs
        FAPI_TRY(mss::unmask::after_scominit<mss::mc_type::ODYSSEY>(i_target));

    fapi_try_exit:
        FAPI_INF("End MSS SCOM init");
        return fapi2::current_err;
    }
}
