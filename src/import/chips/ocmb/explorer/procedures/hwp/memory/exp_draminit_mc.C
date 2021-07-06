/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_draminit_mc.C $ */
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
/// @file exp_mss_draminit_mc.C
/// @brief Initialize the memory controller to take over the DRAM
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/shared/exp_defaults.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/count_dimm.H>

#include <lib/mc/exp_port.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <exp_deploy_row_repairs.H>

extern "C"
{
///
/// @brief Initialize the MC now that DRAM is up
/// @param[in] i_target, the MC of the ports
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode exp_draminit_mc( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
    {
        mss::display_git_commit_info("exp_draminit_mc");

        FAPI_INF("%s Start exp_draminit MC", mss::c_str(i_target));

        //skip this ocmb_chip if we have no DIMM's configured
        if(mss::count_dimm(i_target) == 0)
        {
            FAPI_INF("No DIMM's configured on %s. Skipping this OCMB_CHIP.", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Enable Power management based off of mrw_power_control_requested
        FAPI_TRY( mss::enable_power_management(i_target), "%s Failed to enable power management",
                  mss::c_str(i_target) );

        // Set the IML Complete bit. Steve Powell to find a bit in the SRQ to use for this purpose
        FAPI_TRY( mss::change_iml_complete(i_target, mss::HIGH), "%s Failed to set_ipm_complete",
                  mss::c_str(i_target));

        // Run any necessary row repairs
        // Note: this needs to be run before we start our periodics or before we start refresh
        FAPI_TRY(exp_deploy_row_repairs(i_target), "%s Failed exp_deploy_row_repairs", mss::c_str(i_target));

        // Set DFI init start requested from Stephen Powell
        FAPI_TRY( mss::change_dfi_init_start(i_target, mss::ON ), "%s Failed to change_dfi_init_start",
                  mss::c_str(i_target));

        // Start the refresh engines by setting MBAREF0Q(0) = 1. Note that the remaining bits in
        // MBAREF0Q should retain their initialization values.
        FAPI_TRY( mss::change_refresh_enable(i_target, mss::HIGH), "%s Failed change_refresh_enable",
                  mss::c_str(i_target) );

        // Trigger the MC to take the DRAMs out of self refresh
        FAPI_TRY( mss::change_force_str<mss::mc_type::EXPLORER>(i_target, mss::LOW), "%s Failed change_force_str",
                  mss::c_str(i_target) );

        // Enable periodic short zq cal
        FAPI_TRY( mss::enable_zq_cal(i_target), "%s Failed enable_zq_cal", mss::c_str(i_target) );

        // Enable periodic mem calibration
        FAPI_TRY( mss::enable_periodic_cal<mss::mc_type::EXPLORER>(i_target), "%s Failed enable_periodic_cal",
                  mss::c_str(i_target) );

        // Enable ecc checking
        FAPI_TRY( mss::enable_read_ecc<mss::mc_type::EXPLORER>(i_target), "%s Failed enable_read_ecc", mss::c_str(i_target) );

        // Unmask registers after draminit_mc
        FAPI_TRY(mss::unmask::after_draminit_mc(i_target), "%s Failed after_draminit_mc", mss::c_str(i_target));

        FAPI_INF("%s End exp_draminit MC", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:

        // As we are running row repairs that require CCS,
        // we need to try to blame any FIR's we see on CCS's FIR list// Due to the RAS/PRD requirements, we need to check for FIR's
        // If any FIR's have lit up, this draminit fail could have been caused by the FIR, rather than bad hardware
        // So, let PRD retrigger this step to see if we can resolve the issue
        return mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER,
               mss::check::firChecklist::CCS>(i_target, fapi2::current_err);
    }
}
