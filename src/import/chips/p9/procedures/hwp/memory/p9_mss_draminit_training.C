/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_draminit_training.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p9_mss_draminit_training.C
/// @brief Train dram
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <mss.H>
#include <vector>

#include <p9_mss_draminit_training.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/shared/mss_const.H>
#include <lib/workarounds/dp16_workarounds.H>
#include <lib/workarounds/dqs_align_workarounds.H>
#include <lib/phy/mss_training.H>
#include <lib/fir/unmask.H>
#include <lib/dimm/ddr4/zqcal.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;

extern "C"
{
    ///
    /// @brief Train dram
    /// @param[in] i_target, the McBIST of the ports of the dram you're training
    /// @param[in] i_special_training, optional CAL_STEP_ENABLE override. Used in sim, debug
    /// @param[in] i_abort_on_error, optional CAL_ABORT_ON_ERROR override. Used in sim, debug
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_draminit_training( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
            const uint32_t i_special_training,
            const uint8_t i_abort_on_error)
    {

        // Keep track of the last error seen by a port
        fapi2::ReturnCode l_port_error ( fapi2::FAPI2_RC_SUCCESS );

        fapi2::buffer<uint32_t> l_cal_steps_enabled( i_special_training );

        std::vector<fapi2::ReturnCode> l_fails;

        FAPI_INF("%s Start draminit training", mss::c_str(i_target));

        // If there are no DIMM we don't need to bother. In fact, we can't as we didn't setup
        // attributes for the PHY, etc.
        if (mss::count_dimm(i_target) == 0)
        {
            FAPI_INF("... skipping draminit_training %s - no DIMM ...", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        uint8_t l_reset_disable = 0;
        uint8_t l_cal_abort_on_error = i_abort_on_error;
        uint8_t l_sim = 0;
        FAPI_TRY( mss::is_simulation (l_sim) );
        FAPI_TRY( mss::mrw_reset_delay_before_cal(l_reset_disable), "%s Error in p9_mss_draminit_training",
                  mss::c_str(i_target) );
        // Flag to abort on error

        if (i_abort_on_error == CAL_ABORT_SENTINAL)
        {
            FAPI_TRY( mss::cal_abort_on_error(l_cal_abort_on_error) );
        }

        // Configure the CCS engine.
        {
            fapi2::buffer<uint64_t> l_ccs_config;

            FAPI_TRY( mss::ccs::read_mode(i_target, l_ccs_config), "%s Error in p9_mss_draminit_training", mss::c_str(i_target) );

            // It's unclear if we want to run with this true or false. Right now (10/15) this
            // has to be false. Shelton was unclear if this should be on or off in general BRS
            mss::ccs::stop_on_err(i_target, l_ccs_config, mss::LOW);
            mss::ccs::ue_disable(i_target, l_ccs_config, mss::LOW);
            mss::ccs::copy_cke_to_spare_cke(i_target, l_ccs_config, mss::HIGH);
            mss::ccs::parity_after_cmd(i_target, l_ccs_config, mss::HIGH);

            // Hm. Centaur sets this up for the longest duration possible. Can we do better?
            mss::ccs::cal_count(i_target, l_ccs_config, ~0, ~0);
            FAPI_TRY( mss::ccs::write_mode(i_target, l_ccs_config), "%s Error in p9_mss_draminit_training", mss::c_str(i_target) );
        }

        // Clean out any previous calibration results, set bad-bits and configure the ranks.
        FAPI_DBG("%s MCA's on this McBIST: %d", mss::c_str(i_target), mss::find_targets<TARGET_TYPE_MCA>(i_target).size());

        for( const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
        {
            // Returned from set_rank_pairs, it tells us how many rank pairs
            // we configured on this port.
            std::vector<uint64_t> l_pairs;

            // DIMM type
            uint8_t l_dimm_type[mss::MAX_DIMM_PER_PORT] = {};
            FAPI_TRY(mss::eff_dimm_type(p, &l_dimm_type[0]), "%s failed to access DIMM type", mss::c_str(p));

            // Grab the attribute which contains the information on what cal steps we should run
            // if the i_specal_training bits have not been specified.
            if (i_special_training == 0)
            {
                FAPI_TRY( mss::cal_step_enable(p, l_cal_steps_enabled), "Error in p9_mss_draminit_training" );
            }

            // Clear the Training Advance bit because this is used in training_adv and not in training
            l_cal_steps_enabled.clearBit<mss::TRAINING_ADV_RD>().clearBit<mss::TRAINING_ADV_WR>().clearBit<mss::BUFFER_WR_VREF>();

            FAPI_DBG("cal steps enabled: 0x%x special training: 0x%x", l_cal_steps_enabled, i_special_training);

            // ZQCAL (for DRAMs and LRDIMM data buffers) isn't a PHY calibration,
            // so we don't add it in the PHY calibration setup and do it separately here.
            FAPI_TRY( mss::setup_and_execute_zqcal(p, l_cal_steps_enabled), "Error in p9_mss_draminit_training" );

            FAPI_TRY( mss::putScom(p, MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0, 0) );

            // Disable port fails as it doesn't appear the MC handles initial cal timeouts
            // correctly (cal_length.) BRS, see conversation with Brad Michael
            FAPI_TRY( mss::change_port_fail_disable(p, mss::ON ), "Error in p9_mss_draminit_training" );

            // The following registers must be configured to the correct operating environment:

            // These are reset in phy_scominit
            // Section 5.2.5.10 SEQ ODT Write Configuration {0-3} on page 422
            // Section 5.2.6.1 WC Configuration 0 Register on page 434
            // Section 5.2.6.2 WC Configuration 1 Register on page 436
            // Section 5.2.6.3 WC Configuration 2 Register on page 438

            // Get our rank pairs.
            FAPI_TRY( mss::rank::get_rank_pairs(p, l_pairs), "Error in p9_mss_draminit_training" );

            // Hits the resets iff zqcal is set so we don't unnecessarily reset errors
            if  ((l_cal_steps_enabled.getBit<mss::cal_steps::DRAM_ZQCAL>()) ||
                 (l_cal_steps_enabled.getBit<mss::cal_steps::DB_ZQCAL>()))
            {
                FAPI_TRY(mss::clear_initial_cal_errors(p), "%s error resetting errors prior to init cal", mss::c_str(p));
            }

            // Check to see if we're supposed to reset the delay values before starting training
            // don't reset if we're running special training - assumes there's a checkpoint which has valid state.
            if ((l_reset_disable == fapi2::ENUM_ATTR_MSS_MRW_RESET_DELAY_BEFORE_CAL_YES) && (i_special_training == 0))
            {
                FAPI_INF("resetting delay values before cal %s", mss::c_str(p));
                FAPI_TRY( mss::dp16::reset_delay_values(p, l_pairs), "Error in p9_mss_draminit_training" );
            }

            FAPI_DBG("generating calibration CCS instructions: %d rank-pairs %s", l_pairs.size(), mss::c_str(p));

            // Turn on refresh for training
            FAPI_TRY( mss::workarounds::dqs_align::turn_on_refresh(p), "Error in p9_mss_draminit_training %s", mss::c_str(p) );

            // For each rank pair we need to calibrate, pop a ccs instruction in an array and execute it.
            // NOTE: IF YOU CALIBRATE MORE THAN ONE RANK PAIR PER CCS PROGRAM, MAKE SURE TO CHANGE
            // THE PROCESSING OF THE ERRORS. (it's hard to figure out which DIMM failed, too) BRS.
            for (const auto& rp : l_pairs)
            {
                bool l_cal_fail = false;
                FAPI_INF("Execute cal on rp %d %s", rp, mss::c_str(p));

                // Per plug rules, mixing LRDIMM and RDIMM shouldn't be allowed, so we're ok grabbing the value from DIMM0
                for(const auto& l_step : mss::training::steps_factory(l_dimm_type[0], l_cal_steps_enabled, l_sim))
                {
                    FAPI_TRY( l_step->execute( p, rp, l_cal_abort_on_error) );
                }

                FAPI_TRY( mss::find_and_log_cal_errors(p, rp, l_cal_abort_on_error, l_cal_fail, l_fails) );

            }// rank pairs

            // Let's update the attribute with the new DQ disable bits
            // The only fail we get here is a scom error, so we should error out
            // Hostboot will write the info to SPD and Cronus will write it to the attribute
            // Hostboot will only do the reconfig loop/ write if it finds new bits
            FAPI_TRY( mss::dp16::record_bad_bits(p) );

            {
                // Conducts workarounds after training if needed
                // if we get fails here,it's due to scom errors
                FAPI_TRY( mss::workarounds::dp16::post_training_workarounds( p, l_cal_steps_enabled ));
            }
        }

        // Let's handle the cal fails on the MCBIST
        // We do it here in order to train every port
        FAPI_TRY( mss::draminit_training_error_handler(l_fails) );
        // Unmask FIR
        FAPI_TRY( mss::unmask::after_draminit_training(i_target), "Error in p9_mss_draminit" );

    fapi_try_exit:
        FAPI_INF("End draminit training");
        return fapi2::current_err;
    }
}
