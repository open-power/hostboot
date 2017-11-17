/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_draminit_training_adv.C $ */
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
/// @file p9_mss_draminit_training_adv.C
/// @brief Perform read_centering again but with a custom pattern for better eye
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <mss.H>
#include <vector>

#include <p9_mss_draminit_training_adv.H>
#include <lib/utils/count_dimm.H>
#include <lib/shared/mss_const.H>
#include <lib/phy/dp16.H>
#include <lib/phy/seq.H>
#include <lib/phy/ddr_phy.H>
#include <lib/phy/mss_training.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;

extern "C"
{
///
/// @brief Perform training_adv on the dimms (perform read centering with custom pattern)
/// @param[in] i_target, the McBIST of the ports of the dram you're training
/// @param[in] i_abort_on_error, optional CAL_ABORT_ON_ERROR override. Used in sim, debug
/// @return FAPI2_RC_SUCCESS iff ok
/// @note turn off rd cntr periodic cal if training_adv is run. Add OFF value for CUSTOM_PATTERN?
///

    fapi2::ReturnCode p9_mss_draminit_training_adv( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
            const uint8_t i_abort_on_error)
    {
        uint8_t l_cal_abort_on_error = i_abort_on_error;
        uint8_t l_sim = 0;
        FAPI_TRY( mss::is_simulation (l_sim) );

        FAPI_INF("Start draminit training advance %s", mss::c_str(i_target));

        // If there are no DIMMs installed, we don't need to bother. In fact, we can't as we didn't setup
        // attributes for the PHY, etc.
        if (mss::count_dimm(i_target) == 0 || l_sim)
        {
            FAPI_INF("... skipping draminit_training_adv %s... %s Dimms. %s SIM.",
                     mss::c_str(i_target),
                     mss::count_dimm(i_target) == 0 ? "Has no" : "Has",
                     l_sim ? "Is" : "Is not");
            return fapi2::FAPI2_RC_SUCCESS;
        }

        if (i_abort_on_error == CAL_ADV_ABORT_SENTINAL)
        {
            FAPI_TRY( mss::cal_abort_on_error(l_cal_abort_on_error) );
        }

        // If Custom Read Centering or Custom Write Centering was performed,
        // an Initial Pattern Write of 5555 hex, the reset value of the registers described in,
        // must be performed before any periodic calibration routines are performed.
        // Clean out any previous calibration results, set bad-bits and configure the ranks.
        for( const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
        {
            fapi2::buffer<uint32_t> l_cal_steps_enabled;
            std::vector<std::shared_ptr<mss::training::step>> l_steps;
            FAPI_TRY( mss::cal_step_enable(p, l_cal_steps_enabled), "Error in p9_mss_draminit_training %s", mss::c_str(i_target) );

            if (!l_cal_steps_enabled.getBit<mss::TRAINING_ADV>())
            {
                FAPI_INF("ATTR_MSS_CAL_STEPS_ENABLED says to skip draminit training advance, so skipping %s",
                         mss::c_str(i_target));
                continue;
            }

            // If we see the bit to for training_adv, let's set up our cal config.
            // As per the PHY spec, only INITIAL_PAT_WRITE and the CUSTOM_RD_PATTERN bits should be set
            // TRAINING_ADV == CUSTOM_RD_PATTERN
            l_cal_steps_enabled = 0;
            l_cal_steps_enabled.setBit<mss::INITIAL_PAT_WR>().setBit<mss::TRAINING_ADV>();

            // Gets the training steps to calibrate
            l_steps = mss::training::steps_factory(l_cal_steps_enabled, l_sim);

            // Keep track of the last error seen by a rank pair
            fapi2::ReturnCode l_rank_pair_error(fapi2::FAPI2_RC_SUCCESS);

            // Clear all of the errors before we start
            FAPI_TRY(mss::clear_initial_cal_errors(p), "%s error resetting errors prior to init cal", mss::c_str(p));

            // Returned from set_rank_pairs, it tells us how many rank pairs
            // we configured on this port.
            std::vector<uint64_t> l_pairs;

            // Let's set the pattern to run
            FAPI_TRY( mss::configure_custom_pattern(p) );

            // Set staggered mode
            FAPI_TRY( mss::rc::change_staggered_pattern(p) );

            // Set custom read centering mode
            FAPI_TRY( mss::dp16::setup_custom_read_centering_mode(p), "Error in p9_mss_draminit_training %s",
                      mss::c_str(i_target) );

            // Get our rank pairs.
            FAPI_TRY( mss::rank::get_rank_pairs(p, l_pairs), "Error in p9_mss_draminit_training" );

            // For each rank pair we need to calibrate, pop a ccs instruction in an array and execute it.
            // NOTE: IF YOU CALIBRATE MORE THAN ONE RANK PAIR PER CCS PROGRAM, MAKE SURE TO CHANGE
            // THE PROCESSING OF THE ERRORS. (it's hard to figure out which DIMM failed, too) BRS.
            for (const auto& rp : l_pairs)
            {
                bool l_cal_fail = false;

                // Save off registers in case adv training fails
                mss::dp16::rd_ctr_settings<TARGET_TYPE_MCA> l_original_settings(p, rp);
                FAPI_TRY( l_original_settings.save() );

                std::vector<fapi2::ReturnCode> l_fails_on_rp;

                // Loop through all of the steps (should just be initial pattern write and custom read centering)
                for(const auto l_step : l_steps)
                {
                    FAPI_TRY( l_step->execute(p, rp, l_cal_abort_on_error) );
                }

                FAPI_TRY( mss::find_and_log_cal_errors(p, rp, l_cal_abort_on_error, l_cal_fail, l_fails_on_rp) );

                // If we got a fail, let's ignore the previous fails and run backup pattern
                if (l_fails_on_rp.size() != 0)
                {
                    l_cal_fail = false;
                    l_fails_on_rp.clear();

                    // Clear the disable bits from last run.
                    // This function restores bad_bits to how the attribute has them
                    // (which was updated at the end of regular training)
                    // So we won't run on known bad bits, but will rerun on the iffy bits from last custom_pattern run
                    FAPI_TRY( mss::dp16::reset_bad_bits( p ) );
                    FAPI_INF("%s rp%x running back up pattern for draminit_training_adv", mss::c_str(p), rp);

                    // Clear the cal errors so we can retry
                    FAPI_TRY(mss::clear_initial_cal_errors(p), "%s error resetting errors prior to init cal", mss::c_str(p));

                    fapi2::buffer<uint32_t> l_backup;
                    FAPI_TRY( mss::custom_training_adv_backup_patterns( p, l_backup) );

                    // Put the backup into the registers
                    FAPI_TRY( mss::seq::setup_rd_wr_data( p, l_backup) );

                    // Rerun the training for this rp
                    // Loop through all of the steps (should just be initial pattern write and custom read centering)
                    for(const auto l_step : l_steps)
                    {
                        FAPI_TRY( l_step->execute(p, rp, l_cal_abort_on_error) );
                    }

                    FAPI_TRY( mss::find_and_log_cal_errors(p, rp, l_cal_abort_on_error, l_cal_fail, l_fails_on_rp) );

                    // If we got fails from the backup pattern, restore the pre-adv training settings for this rank pair
                    if (l_fails_on_rp.size() != 0)
                    {
                        l_fails_on_rp.clear();
                        FAPI_INF("%s rp%d draminit_training_adv failed. Restoring original settings", mss::c_str(p), rp);

                        // Restore pre-training_adv settings
                        FAPI_TRY( l_original_settings.restore() );
                    }
                }
            }// rank pairs

            // Resetting current_err.
            // The error has either already been "logged" or we have exited and returned the error up the call stack.
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }

        return fapi2::FAPI2_RC_SUCCESS;
    fapi_try_exit:
        return fapi2::current_err;
    }
}
