/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_draminit_mc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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
/// @file ody_mss_draminit_mc.C
/// @brief Initialize the memory controller to take over the DRAM
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_draminit_mc.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <ody_deploy_row_repairs.H>

#include <lib/mc/ody_port_traits.H>
#include <lib/mc/ody_port.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <lib/workarounds/ody_dfi_complete_workarounds.H>

extern "C"
{
///
/// @brief Initialize the MC now that DRAM is up
/// @param[in] i_target, the MC of the ports
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_draminit_mc( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
    {
        mss::display_git_commit_info("ody_draminit_mc");

        FAPI_INF_NO_SBE( TARGTIDFORMAT " Start ody_draminit_mc", TARGTID );

        //skip this ocmb_chip if we have no DIMM's configured
        if(mss::count_dimm(i_target) == 0)
        {
            FAPI_INF_NO_SBE( "No DIMM's configured on " TARGTIDFORMAT " Skipping this OCMB_CHIP.", TARGTID ) ;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Enable Power management based off of mrw_power_control_requested
        FAPI_TRY( mss::enable_power_management<mss::mc_type::ODYSSEY>(i_target),
                  TARGTIDFORMAT " Failed to enable power management",
                  TARGTID );

        // TODO Zen:MST-1406 Check with design team if we have an "init complete" indicator in Odyssey.
        // This was assigned to an unused (and unnamed) bit on Explorer PMU8Q.
        // Set the IML Complete bit. Steve Powell to find a bit in the SRQ to use for this purpose
        // FAPI_TRY( mss::change_iml_complete<mss::mc_type::ODYSSEY>(i_target, mss::HIGH),  TARGTIDFORMAT " Failed to set_ipm_complete",
        //           TARGTID);

        // Set DFI init start. Toggle OFF then ON just in case we're re-running
        FAPI_TRY( mss::change_dfi_init_start<mss::mc_type::ODYSSEY>(i_target, mss::OFF ),
                  TARGTIDFORMAT " Failed to clear dfi_init_start",
                  TARGTID );

        FAPI_TRY( mss::change_dfi_init_start<mss::mc_type::ODYSSEY>(i_target, mss::ON ),
                  TARGTIDFORMAT " Failed to set dfi_init_start",
                  TARGTID );

        // Poll the DFI interface for completion
        FAPI_TRY( mss::ody::workarounds::check_dfi_init( i_target ), TARGTIDFORMAT " Failed to check if DFI init completed",
                  TARGTID );

        // Deasserts reset_n in certain simulation environments
        FAPI_TRY( mss::ody::workarounds::deassert_resetn( i_target ), TARGTIDFORMAT " Failed to deassert reset_n",
                  TARGTID );

        // Deploy any necessary row repairs
        FAPI_TRY(ody_deploy_row_repairs(i_target), TARGTIDFORMAT " Failed ody_deploy_row_repairs", TARGTID);

        // Start the refresh engines by setting MBAREF0Q(0) = 1. Note that the remaining bits in
        // MBAREF0Q should retain their initialization values.
        FAPI_TRY( mss::change_refresh_enable<mss::mc_type::ODYSSEY>(i_target, mss::HIGH),
                  TARGTIDFORMAT " Failed change_refresh_enable",
                  TARGTID );

        // Trigger the MC to take the DRAMs out of self refresh
        FAPI_TRY( mss::change_force_str<mss::mc_type::ODYSSEY>(i_target, mss::LOW), TARGTIDFORMAT " Failed change_force_str",
                  TARGTID );

        // Enable periodic short zq cal
        FAPI_TRY( mss::enable_zq_cal<mss::mc_type::ODYSSEY>(i_target), TARGTIDFORMAT " Failed enable_zq_cal", TARGTID );

        // Enable periodic mem calibration
        FAPI_TRY( mss::enable_periodic_cal<mss::mc_type::ODYSSEY>(i_target), TARGTIDFORMAT " Failed enable_periodic_cal",
                  TARGTID );

        // Unmask registers after draminit_mc
        FAPI_TRY( mss::unmask::after_draminit_mc<mss::mc_type::ODYSSEY>(i_target),
                  TARGTIDFORMAT " Failed unmask::after_draminit_mc",
                  TARGTID);

        FAPI_INF_NO_SBE( TARGTIDFORMAT " End ody_draminit MC", TARGTID );
        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }
}
