/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_draminit_training_adv.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <mss.H>
#include <vector>

#include <p9_mss_draminit_training_adv.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/shared/mss_const.H>
#include <lib/phy/dp16.H>
#include <lib/phy/seq.H>
#include <lib/phy/ddr_phy.H>
#include <lib/phy/mss_training.H>
#include <lib/workarounds/dp16_workarounds.H>

#ifdef LRDIMM_CAPABLE
    #include <lib/phy/mss_lrdimm_training_helper.H>
#endif

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
            // DIMM type
            uint8_t l_dimm_type[mss::MAX_DIMM_PER_PORT] = {};
            FAPI_TRY(mss::eff_dimm_type(p, &l_dimm_type[0]), "%s failed to access DIMM type", mss::c_str(p));
            FAPI_TRY( mss::cal_step_enable(p, l_cal_steps_enabled), "Error in p9_mss_draminit_training %s", mss::c_str(i_target) );

            if (!((l_cal_steps_enabled.getBit<mss::TRAINING_ADV_RD>()) || (l_cal_steps_enabled.getBit<mss::TRAINING_ADV_WR>())))
            {
                FAPI_INF("ATTR_MSS_CAL_STEPS_ENABLED says to skip draminit training advance, so skipping %s",
                         mss::c_str(i_target));
                continue;
            }

            // Clear all non training advanced bits
            l_cal_steps_enabled.clearBit<0, mss::TRAINING_ADV_RD>();
            l_cal_steps_enabled.clearBit<mss::BUFFER_RD_VREF>().clearBit<mss::DRAM_WR_VREF>();
            // Gets the training steps to calibrate
            l_steps = mss::training::steps_factory(l_dimm_type[0], l_cal_steps_enabled, l_sim);

            // Keep track of the last error seen by a rank pair
            fapi2::ReturnCode l_rank_pair_error(fapi2::FAPI2_RC_SUCCESS);

            // Returned from set_rank_pairs, it tells us how many rank pairs
            // we configured on this port.
            std::vector<uint64_t> l_pairs;

            // Get our rank pairs.
            FAPI_TRY( mss::rank::get_rank_pairs(p, l_pairs), "Error in p9_mss_draminit_training" );

            // For each rank pair we need to calibrate, pop a ccs instruction in an array and execute it.
            // NOTE: IF YOU CALIBRATE MORE THAN ONE RANK PAIR PER CCS PROGRAM, MAKE SURE TO CHANGE
            // THE PROCESSING OF THE ERRORS. (it's hard to figure out which DIMM failed, too) BRS.
            for (const auto& rp : l_pairs)
            {
                // Loop through all of the steps (should just be initial pattern write and custom read centering)
                for(const auto l_step : l_steps)
                {
                    FAPI_TRY( l_step->execute(p, rp, l_cal_abort_on_error) );
                }

                // Adjusts values for NVDIMM's
                FAPI_TRY(mss::workarounds::nvdimm::adjust_rd_dq_delay(p, rp));

#ifdef LRDIMM_CAPABLE
                //add workaround after all step
                {
                    fapi2::buffer<uint8_t> l_is_m386a8k40cm2_ctd7y = 0;
                    FAPI_TRY( mss::is_m386a8k40cm2_ctd7y(p, l_is_m386a8k40cm2_ctd7y), "Error in p9_mss_draminit_training %s",
                              mss::c_str(i_target) );

                    if(l_is_m386a8k40cm2_ctd7y)
                    {
                        FAPI_TRY(mss::training::lrdimm::workarounds::timing_workaround(p, rp, l_cal_abort_on_error), "%s add timing workaround",
                                 mss::c_str(i_target));
                    }
                }
#endif

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
