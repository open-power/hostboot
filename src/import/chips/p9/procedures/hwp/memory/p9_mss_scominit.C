/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_mss_scominit.C
/// @brief SCOM inits for PHY, MC
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mss_scominit.H>
#include <p9n_mca_scom.H>
#include <p9n_mcbist_scom.H>
#include <p9n_ddrphy_scom.H>
#include <lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/phy/ddr_phy.H>
#include <lib/mc/mc.H>
#include <lib/fir/unmask.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::FAPI2_RC_SUCCESS;

///
/// @brief SCOM inits for PHY, MC
/// @param[in] i_target, the MCBIST
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_scominit( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("Start MSS SCOM init");

    // We need to make sure we scominit the magic port.
    const auto l_mca_targets = mss::find_targets_with_magic<TARGET_TYPE_MCA>(i_target);

    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    if (mss::count_dimm(i_target) == 0)
    {
        FAPI_INF("... skipping mss_scominit %s - no DIMM ...", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for (const auto& l_mca_target : l_mca_targets )
    {
        FAPI_INF("scominit for %s", mss::c_str(l_mca_target));

        // Can't MCA init ports with no DIMM, they don't have attributes like timing.
        if (mss::count_dimm(l_mca_target) != 0)
        {
            FAPI_INF("mca scominit for %s", mss::c_str(l_mca_target));
            FAPI_EXEC_HWP(l_rc, p9n_mca_scom, l_mca_target, i_target, l_mca_target.getParent<fapi2::TARGET_TYPE_MCS>(),
                          FAPI_SYSTEM, i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>());

            if (l_rc)
            {
                FAPI_ERR("Error from p9.mca.scom.initfile");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }

            FAPI_INF("mca thermal throttle scominit for %s", mss::c_str(l_mca_target));
            FAPI_TRY(mss::mc::thermal_throttle_scominit(l_mca_target));
        }

        // ... but we do scominit PHY's with no DIMM. There are no attributes needed and we need
        // to make sure we init the magic port.
        FAPI_INF("phy scominit for %s", mss::c_str(l_mca_target));
        FAPI_EXEC_HWP(l_rc, p9n_ddrphy_scom, l_mca_target, i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>());

        if (l_rc)
        {
            FAPI_ERR("Error from p9.ddrphy.scom.initfile");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }

    FAPI_EXEC_HWP(l_rc, p9n_mcbist_scom, i_target );

    if (l_rc)
    {
        FAPI_ERR("Error from p9.mcbist.scom.initfile");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    // Initialize via scoms for non-static PHY items.
    FAPI_TRY( mss::phy_scominit(i_target) );

    // Do FIRry things
    FAPI_TRY( mss::unmask::after_scominit(i_target) );

fapi_try_exit:
    FAPI_INF("End MSS SCOM init");
    return fapi2::current_err;
}
