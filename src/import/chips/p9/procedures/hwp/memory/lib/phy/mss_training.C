/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_training.C $ */
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
/// @file workarounds/mss_training_workarounds.C
/// @brief High level workarounds for training
/// Workarounds are very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <vector>
#include <initializer_list>
#include <fapi2.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <mss.H>
#include <lib/phy/ddr_phy.H>
#include <lib/phy/mss_training.H>
#include <lib/phy/mss_lrdimm_training.H>
#include <lib/workarounds/dp16_workarounds.H>
#include <lib/workarounds/wr_vref_workarounds.H>
#include <lib/dimm/ddr4/latch_wr_vref.H>
#include <lib/workarounds/seq_workarounds.H>
#include <lib/workarounds/dqs_align_workarounds.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/dimm/rank.H>
#include <lib/shared/mss_const.H>
#include <lib/dimm/ddr4/pda_nimbus.H>
#include <lib/phy/seq.H>
#include <lib/phy/read_cntrl.H>
#include <lib/mss_attribute_accessors.H>

#ifdef LRDIMM_CAPABLE
    #include <lib/phy/mss_dwl.H>
    #include <lib/phy/mss_mrd_coarse.H>
    #include <lib/phy/mss_mrd_fine.H>
    #include <lib/phy/mss_mwd_coarse.H>
    #include <lib/phy/mss_mwd_fine.H>
#endif

namespace mss
{

///
/// @brief Bad bit getter - Nimbus specialization
/// @param[in] i_target the fapi2 target oon which training was conducted
/// @param[out] o_array the bad bits
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
template <>
fapi2::ReturnCode get_bad_dq_bitmap<mss::mc_type::NIMBUS>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t (&o_array)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT])
{
    return mss::bad_dq_bitmap(i_target, &(o_array[0][0]));
}

namespace training
{
// Below definitions are used to avoid linker errors
constexpr custom_read_ctr::attr_func custom_read_ctr::DATA_PATTERNS[NUM_PATTERNS];

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode step::execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                 const uint64_t i_rp,
                                 const uint8_t i_abort_on_error ) const
{
    FAPI_INF("%s rp%u running %s", mss::c_str(i_target), i_rp, iv_name);

    // First, pre-workaround
    FAPI_TRY(pre_workaround(i_target, i_rp, i_abort_on_error));

    // Second, setup/run
    FAPI_TRY(run(i_target, i_rp, i_abort_on_error));

    // Finally, post workaround
    FAPI_TRY(post_workaround(i_target, i_rp, i_abort_on_error));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes the pre-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode wr_vref_latch::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    FAPI_INF("%s RP%d WR VREF latch workaround", mss::c_str(i_target), i_rp);

    // DD1 chip bugs require the WR VREF workarounds below
    // This DD1 chip bug might override the VREF values, as such
    // Runs WR VREF workarounds if needed
    // it will check and see if it needs to run, if not it will return success
    // Overrides will be set by mss::workarounds::wr_vref::execute.
    // If the execute code is skipped, then it will read from the attributes
    FAPI_TRY( mss::workarounds::wr_vref::execute(i_target,
              i_rp,
              iv_wr_vref,
              iv_vrefdq_train_range_override,
              iv_vrefdq_train_value_override) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode wr_vref_latch::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                      const uint64_t i_rp,
                                      const uint8_t i_abort_on_error ) const
{
    // Latches the WR VREF's on this rank pair, if required
    // Note: the VREF latching should be done before write centering
    // The latching is not a workaround (but is required by JEDEC), so we do not execute it in the workarounds steps
    // It's not a training step per-se but is part of the setup and is included in the cal step enable
    FAPI_INF("%s RP%d latching WR VREF values below", mss::c_str(i_target), i_rp);

    // Latches the VREF's
    FAPI_TRY( mss::ddr4::latch_wr_vref_commands_by_rank_pair(i_target,
              i_rp,
              iv_vrefdq_train_range_override,
              iv_vrefdq_train_value_override) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t wr_vref_latch::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    // The latch code figures out it's own cycles, so just return 1
    return 1;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode phy_step::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                 const uint64_t i_rp,
                                 const uint8_t i_abort_on_error ) const
{
    // Execute this cal step
    FAPI_INF("%s RP%d running cal step '%s'", mss::c_str(i_target), i_rp, get_name());
    FAPI_TRY(mss::execute_cal_steps_helper( i_target,
                                            i_rp,
                                            iv_init_cal_config,
                                            i_abort_on_error,
                                            calculate_cycles(i_target)));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes the pre-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode wr_lvl::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    std::vector< ccs::instruction_t > l_rtt_inst;

    FAPI_DBG("%s Running Pre-WR_LEVEL workaround steps on RP%d", mss::c_str(i_target), i_rp);
    // Setup WR_LEVEL specific terminations
    // JEDEC spec requires disabling RTT_WR during WR_LEVEL, and enabling equivalent terminations
    FAPI_TRY( setup_wr_level_terminations(i_target, i_rp, l_rtt_inst) );

    if (!l_rtt_inst.empty())
    {
        const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
        ccs::program l_program;
        l_program.iv_instructions.insert(l_program.iv_instructions.end(), l_rtt_inst.begin(), l_rtt_inst.end() );
        FAPI_TRY( mss::ccs::execute(l_mcbist, l_program, i_target) );
        l_program.iv_instructions.clear();
    }

    FAPI_INF("%s RP%lu %s WR_LVL workaround setup", mss::c_str(i_target), i_rp, iv_sim ? "skipping" : "running");

    if(!iv_sim)
    {
        FAPI_TRY( mss::ccs::workarounds::wr_lvl::configure_non_calibrating_ranks(i_target, i_rp, mss::states::OFF_N) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t wr_lvl::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    const uint64_t TWLO_TWLOE = mss::twlo_twloe(i_target);

    // Note: the following equation is taken from the PHY workbook - leaving the naked numbers in for parity to the workbook
    // This step runs for approximately (80 + TWLO_TWLOE) x NUM_VALID_SAMPLES x (384/(BIG_STEP + 1) +
    // (2 x (BIG_STEP + 1))/(SMALL_STEP + 1)) + 20 memory clock cycles per rank.

    const uint64_t l_wr_lvl_cycles = (80 + TWLO_TWLOE) * WR_LVL_NUM_VALID_SAMPLES * (384 / (WR_LVL_BIG_STEP + 1) +
                                     (2 * (WR_LVL_BIG_STEP + 1)) / (WR_LVL_SMALL_STEP + 1)) + 20;
    FAPI_DBG("%s wr_lvl_cycles: %llu(%lluns) (%llu, %llu, %llu, %llu)",
             mss::c_str(i_target),
             l_wr_lvl_cycles,
             mss::cycles_to_ns(i_target,
                               l_wr_lvl_cycles),
             TWLO_TWLOE, WR_LVL_NUM_VALID_SAMPLES, WR_LVL_BIG_STEP, WR_LVL_SMALL_STEP);

    return l_wr_lvl_cycles;
}

///
/// @brief Executes the post-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode wr_lvl::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    std::vector< ccs::instruction_t > l_rtt_inst;

    FAPI_DBG("%s Running Post-WR_LEVEL workaround steps on RP%d", mss::c_str(i_target), i_rp);

    FAPI_TRY( restore_mainline_terminations(i_target, i_rp, l_rtt_inst) );

    if (!l_rtt_inst.empty())
    {
        const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
        ccs::program l_program;
        l_program.iv_instructions.insert(l_program.iv_instructions.end(),
                                         l_rtt_inst.begin(),
                                         l_rtt_inst.end() );
        FAPI_TRY( mss::ccs::execute(l_mcbist, l_program, i_target) );
    }

    FAPI_INF("%s RP%lu %s WR_LVL workaround cleanup", mss::c_str(i_target), i_rp, iv_sim ? "skipping" : "running");

    if(!iv_sim)
    {
        FAPI_TRY( mss::ccs::workarounds::wr_lvl::configure_non_calibrating_ranks(i_target, i_rp, mss::states::ON_N) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t initial_pattern_write::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    // Not sure how long this should take, so we're gonna use 1 to make sure we get at least one polling loop
    return 1;
}

///
/// @brief Executes the post-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dqs_align::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{

    FAPI_DBG("%s Running Post-DQS_ALIGN workaround steps on RP%d", mss::c_str(i_target), i_rp);

    FAPI_TRY(mss::workarounds::dp16::dqs_align::dqs_align_workaround(i_target, i_rp, i_abort_on_error),
             "%s Failed to run dqs align workaround on rp %d", mss::c_str(i_target), i_rp);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t dqs_align::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    // Note: the following equation is taken from the PHY workbook - leaving the naked numbers in for parity to the workbook
    // This step runs for approximately 6 x 600 x 4 DRAM clocks per rank pair.
    const uint64_t l_dqs_align_cycles = 6 * 600 * 4;

    FAPI_DBG("%s dqs_align_cycles: %llu(%lluns)", mss::c_str(i_target), l_dqs_align_cycles,
             mss::cycles_to_ns(i_target,
                               l_dqs_align_cycles));
    return l_dqs_align_cycles;
}

///
/// @brief Executes the pre-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode rdclk_align::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    FAPI_DBG("%s Running Pre-RDCLK_ALIGN workaround steps on RP%d", mss::c_str(i_target), i_rp);
    // Turn off refresh
    FAPI_TRY( mss::workarounds::dqs_align::turn_off_refresh(i_target) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes the post-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode rdclk_align::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    FAPI_DBG("%s Running Post-RDCLK_ALIGN workaround steps on RP%d", mss::c_str(i_target), i_rp);

    // Run the red_waterfall workaround for low VDN sensitivity
    // Increments the waterfall forward by one
    FAPI_TRY( mss::workarounds::dp16::fix_red_waterfall_gate( i_target, i_rp) );

    // Turn refresh back on
    FAPI_TRY( mss::workarounds::dqs_align::turn_on_refresh(i_target) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t rdclk_align::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    // Note: the following equation is taken from the PHY workbook - leaving the naked numbers in for parity to the workbook
    // This step runs for approximately 24 x ((1024/COARSE_CAL_STEP_SIZE + 4 x COARSE_CAL_STEP_SIZE) x 4 + 32) DRAM
    // clocks per rank pair
    const uint64_t l_rdclk_align_cycles = 24 * ((1024 / COARSE_CAL_STEP_SIZE + 4 * COARSE_CAL_STEP_SIZE) * 4 + 32);
    FAPI_DBG("%s rdclk_align_cycles: %llu(%lluns) (%llu)", mss::c_str(i_target), l_rdclk_align_cycles,
             mss::cycles_to_ns(i_target, l_rdclk_align_cycles), COARSE_CAL_STEP_SIZE);
    return l_rdclk_align_cycles;
}

///
/// @brief Executes the pre-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode read_ctr::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    FAPI_DBG("%s Running Pre-RD_CTR workaround steps on RP%d", mss::c_str(i_target), i_rp);
    // Turn off refresh
    FAPI_TRY( mss::workarounds::dqs_align::turn_off_refresh(i_target) );

    // Sets up the RD VREF sense workaround
    FAPI_TRY( mss::workarounds::dp16::rd_vref_vref_sense_setup(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode read_ctr::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                 const uint64_t i_rp,
                                 const uint8_t i_abort_on_error ) const
{
    // Blast the VREF config with the proper setting for these cal bits if there were any enable bits set
    if (iv_rd_vref)
    {
        uint16_t l_vref_cal_enable = 0;

        // Blast the VREF_CAL_ENABLE to the registers that control which dp16's to use for rdvref
        FAPI_TRY( mss::rdvref_cal_enable(i_target, l_vref_cal_enable) );
        FAPI_TRY( mss::scom_blastah(i_target, dp16Traits<fapi2::TARGET_TYPE_MCA>::RD_VREF_CAL_ENABLE_REG, l_vref_cal_enable) );
    }

    // Now lets set the actual read_vref_config. We want to write/ clear this every time we run so seperate function
    FAPI_TRY( setup_read_vref_config1(i_target, iv_rd_ctr, iv_rd_vref),
              "%s Failed setting the read_vref_config1", mss::c_str(i_target) );

    // Now run the actual calibration
    FAPI_TRY(phy_step::run(i_target, i_rp, i_abort_on_error));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes the post-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode read_ctr::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    FAPI_DBG("%s Running Post-RD_CTR workaround steps on RP%d", mss::c_str(i_target), i_rp);

    // Now run the read centering workaround
    if(iv_rd_ctr)
    {
        FAPI_TRY(mss::workarounds::dp16::rd_dq::fix_delay_values(i_target, i_rp),
                 "%s Failed to run read centering workaround on rp %d", mss::c_str(i_target), i_rp);
    }

    // Turn refresh back on
    FAPI_TRY( mss::workarounds::dqs_align::turn_on_refresh(i_target) );

    // Sets up the RD VREF sense workaround
    FAPI_TRY( mss::workarounds::dp16::rd_vref_vref_sense_cleanup( i_target ) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t read_ctr::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    // Note: the following equation is taken from the PHY workbook - leaving the naked numbers in for parity to the workbook
    // This step runs for approximately 6 x (512/COARSE_CAL_STEP_SIZE + 4 x (COARSE_CAL_STEP_SIZE +
    // 4 x CONSEQ_PASS)) x 24 DRAM clocks per rank pair.

    const uint64_t l_read_ctr_cycles = 6 * (512 / COARSE_CAL_STEP_SIZE + 4 * (COARSE_CAL_STEP_SIZE + 4 * CONSEQ_PASS)) * 24;
    FAPI_DBG("%s read_ctr_cycles %llu(%lluns) (%llu, %llu)",
             mss::c_str(i_target),
             l_read_ctr_cycles,
             mss::cycles_to_ns(i_target, l_read_ctr_cycles),
             COARSE_CAL_STEP_SIZE,
             CONSEQ_PASS);

    // This calibration step could take up to read centering + RD VREF time, so let's just output that to make the math simpler
    return l_read_ctr_cycles + rc::vref_guess_time(i_target);
}

///
/// @brief Sets up and runs the calibration step according to an external 1D vs 2D input
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @param[in] i_wr_vref - true IFF write VREF calibration needs to be run
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode write_ctr::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                  const uint64_t i_rp,
                                  const uint8_t i_abort_on_error,
                                  const bool i_wr_vref ) const
{
    typedef mss::dp16Traits<fapi2::TARGET_TYPE_MCA> TT;
    std::vector<fapi2::buffer<uint64_t>> l_wr_vref_config;
    FAPI_TRY( mss::scom_suckah(i_target, TT::WR_VREF_CONFIG0_REG, l_wr_vref_config) );

    // Loops and sets or clears the 2D VREF bit on all DPs
    for(auto& l_data : l_wr_vref_config)
    {
        // 0: Run only the VREF (2D) write centering algorithm
        // 1: Run only the 1D
        l_data.writeBit<TT::WR_VREF_CONFIG0_1D_ONLY_SWITCH>(!i_wr_vref);
    }

    FAPI_TRY(mss::scom_blastah(i_target, TT::WR_VREF_CONFIG0_REG, l_wr_vref_config));

    FAPI_TRY(phy_step::run(i_target, i_rp, i_abort_on_error));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode write_ctr::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                  const uint64_t i_rp,
                                  const uint8_t i_abort_on_error ) const
{
    return run(i_target, i_rp, i_abort_on_error, iv_wr_vref);
}

///
/// @brief Executes the pre-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode write_ctr::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    iv_dram_to_check.clear();

    // Only add DRAMs to check if:
    // 1) WR VREF is enabled
    // 2) the part is a DD2 or above
    if(iv_wr_vref && (!mss::chip_ec_nimbus_lt_2_0(i_target)))
    {
        FAPI_INF("%s checking for clear DRAMs", mss::c_str(i_target));
        uint64_t l_num_dram = 0;

        uint8_t l_width[MAX_DIMM_PER_PORT] = {};
        FAPI_TRY( mss::eff_dram_width(i_target, l_width) );
        l_num_dram = (l_width[0] == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ? MAX_DRAMS_X8 : MAX_DRAMS_X4;

        // Loops through all the DRAM and adds them to be checked if they are clean of any bad bits
        // We only want to run the workaround on an entirely clean DRAM that goes bad
        // If we have a DRAM that already has bad bit(s), there could be something else going on and the workaround will not help or could make matters worse
        for(uint64_t l_dram = 0; l_dram < l_num_dram; l_dram++)
        {
            bool l_has_disables = false;

            FAPI_TRY(mss::workarounds::dp16::wr_vref::dram_has_disables(i_target, i_rp, l_dram, l_has_disables));

            FAPI_INF("%s RP%lu DRAM%lu Disables? %s", mss::c_str(i_target), i_rp, l_dram, l_has_disables ? "yes" : "no");

            // If there are no disables, then we need to check the DRAM
            if(!l_has_disables)
            {
                // Gets the starting WR DQ delay for the DRAM
                uint64_t l_value = 0;

                FAPI_TRY(mss::workarounds::dp16::wr_vref::get_starting_wr_dq_delay(i_target, i_rp, l_dram, l_value));

                iv_dram_to_check.push_back({l_dram, l_value});
            }
        }
    }
    else
    {
        FAPI_INF("%s workaround is not being run. WR VREF: %s chip version: %s", mss::c_str(i_target),
                 iv_wr_vref ? "enabled" : "disabled", mss::chip_ec_nimbus_lt_2_0(i_target) ? "DD1" : "DD2");
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes the post-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode write_ctr::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    // Loops through the DRAMs to check and creates a vector of bad DRAMs and their associated starting delays
    std::vector<std::pair<uint64_t, uint64_t>> l_bad_drams;
    uint8_t l_hybrid[mss::MAX_DIMM_PER_PORT] = {};
    uint8_t l_hybrid_type[mss::MAX_DIMM_PER_PORT] = {};

    // Get the hybrid type
    FAPI_TRY(mss::eff_hybrid(i_target, &l_hybrid[0]),
             "%s failed to access DIMM hybrid type", mss::c_str(i_target));
    FAPI_TRY(mss::eff_hybrid_memory_type(i_target, &l_hybrid_type[0]),
             "%s failed to access DIMM hybrid memory type", mss::c_str(i_target));

    // Checking all of the DRAMs that had been good before WR VREF
    // If any of them have gone bad, then note it and run the workaround
    for(const auto l_pair : iv_dram_to_check)
    {
        const auto l_dram = l_pair.first;
        const auto l_delay = l_pair.second;
        bool l_is_bad = false;
        FAPI_TRY(mss::workarounds::dp16::wr_vref::is_dram_disabled(i_target, i_rp, l_dram, l_is_bad));

        // If we have a bad DRAM, note it and add it to the DRAM to test
        if(l_is_bad)
        {
            FAPI_INF("%s RP%lu DRAM%lu is bad! Workaround will be run on it", mss::c_str(i_target), i_rp, l_dram);
            l_bad_drams.push_back({l_dram, l_delay});
        }
    }

    iv_dram_to_check.clear();

    // Only run the rest of the workaround if we have any bad DRAMs
    if(l_bad_drams.size() > 0)
    {
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
        std::vector<uint64_t> l_ranks;

        // Gets the ranks on which to latch the VREF's
        FAPI_TRY(mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks));

        // If the rank vector is empty log an error
        FAPI_ASSERT(!l_ranks.empty(),
                    fapi2::MSS_INVALID_RANK().
                    set_PORT_TARGET(i_target).
                    set_RANK(i_rp).
                    set_FUNCTION(mss::ffdc_function_codes::WR_VREF_TRAINING_WORKAROUND),
                    "%s rank pair is empty! %lu", mss::c_str(i_target), i_rp);

        FAPI_ASSERT(l_ranks[0] != NO_RANK,
                    fapi2::MSS_INVALID_RANK().
                    set_PORT_TARGET(i_target).
                    set_RANK(NO_RANK).
                    set_FUNCTION(mss::ffdc_function_codes::WR_VREF_TRAINING_WORKAROUND),
                    "%s rank pair has no ranks %lu", mss::c_str(i_target), i_rp);

        // Ensures we get a valid DIMM target / rank combo
        FAPI_TRY( mss::rank::get_dimm_target_from_rank(i_target, l_ranks[0], l_dimm),
                  "%s Failed get_dimm_target_from_rank in write_ctr::post_workaround",
                  mss::c_str(i_target));

        // Assembles the PDA container and fixes the disables
        {
            mss::ddr4::pda::commands<mss::ddr4::mrs06_data<mss::mc_type::NIMBUS>> l_container;

            // Loops through and sets up all the data needed the workaround
            for(const auto& l_pair : l_bad_drams )
            {
                const auto l_dram = l_pair.first;
                const auto l_delay = l_pair.second;

                // Adds in the PDA necessary for the latching commands
                fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);
                mss::ddr4::mrs06_data<mss::mc_type::NIMBUS> l_mrs(l_dimm, l_rc);
                FAPI_TRY(l_rc, "%s failed to create MRS06 data class", mss::c_str(l_dimm));

                // Updates the MRS06 settings to have the proper VREF settings
                FAPI_TRY(mss::workarounds::dp16::wr_vref::modify_mrs_vref_to_vpd( l_dimm, l_mrs));

                FAPI_TRY(l_container.add_command(l_dimm, l_ranks[0], l_mrs, l_dram));

                // Updates the WR VREF value in the DP
                FAPI_TRY(mss::workarounds::dp16::wr_vref::configure_wr_vref_to_nominal( l_dimm, i_rp, l_dram));

                // Restores the known good values for WR DQ delays
                FAPI_TRY(mss::workarounds::dp16::wr_vref::reset_wr_dq_delay( i_target, i_rp, l_dram, l_delay ));

                // Clears the disable bits for PDA latching
                FAPI_TRY(mss::workarounds::dp16::wr_vref::clear_dram_disable_bits( i_target, i_rp, l_dram ));
            }

            // Latches the failing DRAM's originally good values out to the DRAMs with PDA
            FAPI_TRY(mss::ddr4::pda::execute_wr_vref_latch(l_container));

            // Disabling bits prior to PDA could cause issues with DRAM latching in the VREF values
            // As such, we're setting disable bits after latching PDA
            for(const auto& l_pair : l_bad_drams )
            {
                const auto l_dram = l_pair.first;
                FAPI_TRY(mss::workarounds::dp16::wr_vref::disable_bits( i_target, i_rp, l_dram));
            }
        }

        FAPI_TRY(mss::workarounds::dp16::wr_vref::configure_skip_bits( i_target ));

        // Re-runs WR VREF calibration
        FAPI_TRY(run( i_target,
                      i_rp,
                      i_abort_on_error,
                      true ));

        // Clears the training FIR's
        FAPI_TRY(mss::workarounds::dp16::wr_vref::clear_training_firs( i_target ));

        // If the DRAM's are still bad, exit
        for(const auto& l_pair : l_bad_drams )
        {
            bool l_is_bad = false;
            const auto l_dram = l_pair.first;

            FAPI_TRY(mss::workarounds::dp16::wr_vref::is_dram_disabled(i_target, i_rp, l_dram, l_is_bad));

            if(l_is_bad)
            {
                FAPI_INF("%s RP%lu found DRAM%lu as bad after the second run of WR VREF! Exiting and letting ECC clean this up",
                         mss::c_str(i_target), i_rp, l_dram);
            }
            else
            {
                FAPI_INF("%s RP%lu found DRAM%lu as recovered after the second run of WR VREF! Restoring disable bits and running WR CTR 1D calibration",
                         mss::c_str(i_target), i_rp, l_dram);
                FAPI_TRY(mss::workarounds::dp16::wr_vref::clear_dram_disable_bits( i_target, i_rp, l_dram ));
            }

            // Logs the results for this DRAM
            // Note: always logged as recovered, as we want this to be informational
            FAPI_TRY(mss::workarounds::dp16::wr_vref::log_dram_results(i_target, i_rp, l_dram, l_is_bad));
        }

        // Re-runs WR VREF
        FAPI_TRY(run( i_target,
                      i_rp,
                      i_abort_on_error,
                      false ));
    }

    // If this port has nvdimm, run the workaround. When we do the restore we cannot do the
    // pda wr vref latch because it will break the refresh timing with multiple ccs sequences.
    // As such, let's run the nvdimm with rank median vref value so later on we can just load
    // the vref in 1 ccs sequence.
    if ((l_hybrid[0] ==  fapi2::ENUM_ATTR_EFF_HYBRID_IS_HYBRID) &&
        (l_hybrid_type[0] == fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NVDIMM) && iv_wr_vref)
    {
        FAPI_TRY(mss::workarounds::wr_vref::nvdimm_workaround(i_target, i_rp, i_abort_on_error));

        // Rerun the centering with the median vref
        FAPI_TRY(run( i_target,
                      i_rp,
                      i_abort_on_error,
                      false ));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t write_ctr::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    // Note: the following equation is taken from the PHY workbook - leaving the naked numbers in for parity to the workbook
    // 1000 + (NUM_VALID_SAMPLES * (FW_WR_RD + FW_RD_WR + 16) *
    // (1024/(SMALL_STEP +1) + 128/(BIG_STEP +1)) + 2 * (BIG_STEP+1)/(SMALL_STEP+1)) x 24 DRAM
    // clocks per rank pair.
    constexpr uint64_t WR_CNTR_FW_WR_RD = mss::fw_wr_rd();
    uint8_t l_fw_rd_wr = 0;
    uint64_t l_cycles = 1;

    FAPI_TRY( mss::fw_rd_wr(i_target, l_fw_rd_wr) );

    l_cycles = 1000 + (WR_LVL_NUM_VALID_SAMPLES * (WR_CNTR_FW_WR_RD + l_fw_rd_wr + 16) *
                       (1024 / (WR_LVL_SMALL_STEP + 1) + 128 / (WR_LVL_BIG_STEP + 1)) + 2 *
                       (WR_LVL_BIG_STEP + 1) / (WR_LVL_SMALL_STEP + 1)) * 24;

    FAPI_DBG("%s write_ctr_cycles: %lu(%luns) (%u, %u, %u, %u, %u)",
             mss::c_str(i_target),
             l_cycles,
             mss::cycles_to_ns(i_target, l_cycles),
             WR_LVL_NUM_VALID_SAMPLES,
             WR_CNTR_FW_WR_RD,
             l_fw_rd_wr,
             WR_LVL_BIG_STEP,
             WR_LVL_SMALL_STEP);

    return l_cycles;

fapi_try_exit:
    // We had an error, let's exit
    FAPI_ERR("%s had an error and is going to exit", mss::c_str(i_target));
    fapi2::Assert(false);

    // Error case, the return is to make the compiler happy
    return l_cycles;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t coarse_wr_rd::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    // Note: the following equation is taken from the PHY workbook - leaving the naked numbers in for parity to the workbook
    // The run length given here is the maximum run length for this calibration algorithm.
    // This step runs for approximately 40 DRAM clocks per rank pair.
    constexpr uint64_t COARSE_WR_CYCLES = 40;

    // The run length given here is the maximum run length for this calibration algorithm.
    // This step runs for approximately 32 DRAM clocks per rank pair.
    constexpr uint64_t COARSE_RD_CYCLES = 32;

    // Total coarse cycles
    constexpr uint64_t COARSE_WR_RD_CYCLES = COARSE_WR_CYCLES + COARSE_RD_CYCLES;

    FAPI_DBG("%s coarse_wr_cycles: %llu(%lluns) coarse_rd_cycles %llu(%lluns) coarse wr/rd cycles %llu(%lluns)",
             mss::c_str(i_target),
             COARSE_WR_CYCLES,
             mss::cycles_to_ns(i_target, COARSE_WR_CYCLES),
             COARSE_RD_CYCLES,
             mss::cycles_to_ns(i_target, COARSE_RD_CYCLES),
             COARSE_WR_RD_CYCLES,
             mss::cycles_to_ns(i_target, COARSE_WR_RD_CYCLES));
    return COARSE_WR_RD_CYCLES;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode custom_read_ctr::execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    reset_data_pattern();
    return step::execute(i_target, i_rp, i_abort_on_error);
}

///
/// @brief Executes the pre-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode custom_read_ctr::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    FAPI_DBG("%s Running Pre-Custom RD CTR workaround steps on RP%d", mss::c_str(i_target), i_rp);

    // Turn off refresh - this is an actual workaround
    FAPI_TRY( mss::workarounds::dqs_align::turn_off_refresh(i_target) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode custom_read_ctr::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                        const uint64_t i_rp,
                                        const uint8_t i_abort_on_error ) const
{
    constexpr bool RUN_RD_CTR = true;
    constexpr bool SKIP_RD_VREF = false;

    // Dummy RC value used to continue the loop
    const fapi2::ReturnCode DUMMY_FAIL = fapi2::FAPI2_RC_INVALID_PARAMETER;
    fapi2::ReturnCode l_fails_on_rp(DUMMY_FAIL);

    // Save off registers in case adv training fails
    mss::dp16::rd_ctr_settings<fapi2::TARGET_TYPE_MCA> l_original_settings(i_target, i_rp);


    const auto l_ipw = std::make_shared<initial_pattern_write>();

    // Sets up the DIMM target for the rank
    // It's not needed until we process init cal failures, but it's a tad dangerous to have an uninitialized target
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
    FAPI_TRY( mss::rank_pair_primary_to_dimm(i_target,
              i_rp,
              l_dimm),
              "Failed getting the DIMM for %s", mss::c_str(i_target) );

    // Setup the initial settings
    FAPI_TRY( l_original_settings.save() );

    // Set staggered mode
    FAPI_TRY( mss::rc::change_staggered_pattern(i_target) );

    // Set custom read centering mode
    FAPI_TRY( mss::dp16::setup_custom_read_centering_mode(i_target), "Error in p9_mss_draminit_training %s",
              mss::c_str(i_target) );

    // Loops through all patterns while we have a failing case
    while((iv_current_pattern < NUM_PATTERNS) && (l_fails_on_rp != fapi2::FAPI2_RC_SUCCESS))
    {
        uint32_t l_pattern = 0;

        // Log the error as recovered, IFF it's a real error
        if(l_fails_on_rp != DUMMY_FAIL)
        {
            // Logs our error as recovered, as we are about ready to recover from it
            fapi2::logError(l_fails_on_rp, fapi2::FAPI2_ERRL_SEV_RECOVERED);

            // Resets up the dummy fail
            l_fails_on_rp = DUMMY_FAIL;
            FAPI_TRY(l_original_settings.restore());
        }

        // Let's set the pattern to run
        FAPI_TRY( DATA_PATTERNS[iv_current_pattern]( i_target, l_pattern ) );
        FAPI_INF("%s rp%lu: custom read centering about to kick off pattern number %lu with a value of 0x%08x",
                 mss::c_str(i_target), i_rp, iv_current_pattern, l_pattern);
        FAPI_TRY( mss::configure_custom_pattern( i_target, l_pattern ) );
        FAPI_TRY(l_ipw->execute(i_target, i_rp, i_abort_on_error));

        // Clear all of the errors before we start
        FAPI_TRY(mss::clear_initial_cal_errors(i_target), "%s error resetting errors prior to init cal", mss::c_str(i_target));

        // Now lets set the actual read_vref_config. We want to write/ clear this every time we run so seperate function
        FAPI_TRY( setup_read_vref_config1(i_target, RUN_RD_CTR, SKIP_RD_VREF),
                  "%s Failed setting the read_vref_config1", mss::c_str(i_target) );

        FAPI_TRY( phy_step::run(i_target, i_rp, i_abort_on_error) );

        // Let's keep track of the error.
        // We don't want to error out here because we want to run on the other ports/ranks
        // We'll add this to io_fails if we fail too many DQ's
        l_fails_on_rp = mss::process_initial_cal_errors(l_dimm);

        // Goes to the next pattern
        ++iv_current_pattern;
    }

    // Log the error as recovered
    // It's a real error at this point, but we "recover" by restoring the original settings
    if((l_fails_on_rp != fapi2::FAPI2_RC_SUCCESS) && (l_fails_on_rp != DUMMY_FAIL))
    {
        // We detected an initcal error, set that training failed
        iv_training_failed = true;

        // Logs our error as recovered, as we are about ready to recovere from it
        fapi2::logError(l_fails_on_rp, fapi2::FAPI2_ERRL_SEV_RECOVERED);

        // Resets up the dummy fail
        // Setting to success just for safety's sake
        l_fails_on_rp = fapi2::FAPI2_RC_SUCCESS;

        FAPI_TRY(l_original_settings.restore());
    }
    // Training passes
    else
    {
        iv_training_failed = false;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes the post-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode custom_read_ctr::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    FAPI_DBG("%s Running Post-Custom RD CTR workaround steps on RP%d", mss::c_str(i_target), i_rp);

    // Turn refresh back on
    FAPI_TRY( mss::workarounds::dqs_align::turn_on_refresh(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t custom_read_ctr::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    // Note: the following equation is taken from the PHY workbook - leaving the naked numbers in for parity to the workbook
    // This step runs for approximately 6 x (512/COARSE_CAL_STEP_SIZE + 4 x (COARSE_CAL_STEP_SIZE +
    // 4 x CONSEQ_PASS)) x 24 DRAM clocks per rank pair.

    const uint64_t l_read_ctr_cycles = 6 * (512 / COARSE_CAL_STEP_SIZE + 4 * (COARSE_CAL_STEP_SIZE + 4 * CONSEQ_PASS)) * 24;
    FAPI_DBG("%s read_ctr_cycles %llu(%lluns) (%llu, %llu)",
             mss::c_str(i_target),
             l_read_ctr_cycles,
             mss::cycles_to_ns(i_target, l_read_ctr_cycles),
             COARSE_CAL_STEP_SIZE,
             CONSEQ_PASS);

    // This calibration step could take up to read centering + RD VREF time, so let's just output that to make the math simpler
    return l_read_ctr_cycles;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode custom_write_ctr::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    typedef mss::dp16Traits<fapi2::TARGET_TYPE_MCA> TT;
    std::vector<fapi2::buffer<uint64_t>> l_wr_vref_config;

    fapi2::ReturnCode l_rc (fapi2::FAPI2_RC_SUCCESS);
    // Save off registers in case adv training fails
    mss::dp16::wr_ctr_settings<fapi2::TARGET_TYPE_MCA> l_original_settings(i_target, i_rp);

    // Sets up the DIMM target for the rank
    // It's not needed until we process init cal failures, but it's a tad dangerous to have an uninitialized target
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
    FAPI_TRY( mss::rank_pair_primary_to_dimm(i_target,
              i_rp,
              l_dimm),
              "Failed getting the DIMM for %s", mss::c_str(i_target) );

    // Setup the initial settings
    FAPI_TRY( l_original_settings.save() );

    // Configure the WR config to only run the 1D algorithm
    FAPI_TRY( mss::scom_suckah(i_target, TT::WR_VREF_CONFIG0_REG, l_wr_vref_config) );

    // Loops ensures that only the 1D algorithm will run
    for(auto& l_data : l_wr_vref_config)
    {
        // 1: Run only the 1D
        l_data.setBit<TT::WR_VREF_CONFIG0_1D_ONLY_SWITCH>();
    }

    FAPI_TRY(mss::scom_blastah(i_target, TT::WR_VREF_CONFIG0_REG, l_wr_vref_config));

    // Let's set the pattern to run
    FAPI_TRY( mss::configure_custom_wr_pattern(i_target) );

    // Set staggered mode
    FAPI_TRY( mss::rc::change_staggered_pattern(i_target) );

    // Clear all of the errors before we start
    FAPI_TRY(mss::clear_initial_cal_errors(i_target), "%s error resetting errors prior to init cal", mss::c_str(i_target));

    // Run the calibrations tep
    FAPI_TRY( phy_step::run(i_target, i_rp, i_abort_on_error) );

    // Grab the error for processing
    l_rc = mss::process_initial_cal_errors(l_dimm);

    // If we took a fail, restore those settings
    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        // We detected an initcal error, set that training failed
        iv_training_failed = true;

        // Log the error as recovered
        fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);

        // Restores our original settings and disable bits
        FAPI_TRY( l_original_settings.restore() );
    }
    // Training passes
    else
    {
        iv_training_failed = false;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t custom_write_ctr::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    // Note: the following equation is taken from the PHY workbook - leaving the naked numbers in for parity to the workbook
    // 1000 + (NUM_VALID_SAMPLES * (FW_WR_RD + FW_RD_WR + 16) *
    // (1024/(SMALL_STEP +1) + 128/(BIG_STEP +1)) + 2 * (BIG_STEP+1)/(SMALL_STEP+1)) x 24 DRAM
    // clocks per rank pair.
    constexpr uint64_t WR_CNTR_FW_WR_RD = mss::fw_wr_rd();
    uint8_t l_fw_rd_wr = 0;
    uint64_t l_cycles = 1;

    FAPI_TRY( mss::fw_rd_wr(i_target, l_fw_rd_wr) );

    l_cycles = 1000 + (WR_LVL_NUM_VALID_SAMPLES * (WR_CNTR_FW_WR_RD + l_fw_rd_wr + 16) *
                       (1024 / (WR_LVL_SMALL_STEP + 1) + 128 / (WR_LVL_BIG_STEP + 1)) + 2 *
                       (WR_LVL_BIG_STEP + 1) / (WR_LVL_SMALL_STEP + 1)) * 24;

    FAPI_DBG("%s write_ctr_cycles: %lu(%luns) (%u, %u, %u, %u, %u)",
             mss::c_str(i_target),
             l_cycles,
             mss::cycles_to_ns(i_target, l_cycles),
             WR_LVL_NUM_VALID_SAMPLES,
             WR_CNTR_FW_WR_RD,
             l_fw_rd_wr,
             WR_LVL_BIG_STEP,
             WR_LVL_SMALL_STEP);

    return l_cycles;

fapi_try_exit:
    // We had an error, let's exit
    FAPI_ERR("%s had an error and is going to exit", mss::c_str(i_target));
    fapi2::Assert(false);

    // Error case, the return is to make the compiler happy
    return l_cycles;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode custom_training_facade::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    bool l_training_fail = false;

    // Original WR and RD settings - used to restore starting settings we take any fails
    mss::dp16::rd_ctr_settings<fapi2::TARGET_TYPE_MCA> l_rd_settings(i_target, i_rp);

    // Saves off the original settings
    FAPI_TRY(l_rd_settings.save());

    // Resets the RD CTR pattern count
    iv_rd_ctr->reset_data_pattern();

    // Loops until we pass OR RD CTR runs out of patterns to try
    do
    {
        // Run RD first
        FAPI_TRY(iv_rd_ctr->pre_workaround(i_target, i_rp, i_abort_on_error));
        FAPI_TRY(iv_rd_ctr->run(i_target, i_rp, i_abort_on_error));
        FAPI_TRY(iv_rd_ctr->post_workaround(i_target, i_rp, i_abort_on_error));

        // Gets our training result from custom RD CTR
        l_training_fail = iv_rd_ctr->training_failed();

        // If we didn't pass, exit out - we've exhausted all of our options
        if(l_training_fail)
        {
            FAPI_ERR("%s rp%lu exhausted all of the custom RD CTR patterns. Exiting!", mss::c_str(i_target), i_rp);
            return fapi2::FAPI2_RC_SUCCESS;
        }
        else
        {
            FAPI_INF("%s rp%lu passed on custom RD CTR. On to custom WR CTR", mss::c_str(i_target), i_rp);
        }

        // Here we know we're passing
        // Therefore we should try to run the writes
        FAPI_TRY(iv_wr_ctr->pre_workaround(i_target, i_rp, i_abort_on_error));
        FAPI_TRY(iv_wr_ctr->run(i_target, i_rp, i_abort_on_error));
        FAPI_TRY(iv_wr_ctr->post_workaround(i_target, i_rp, i_abort_on_error));

        // Gets our training result from custom WR CTR
        l_training_fail = iv_wr_ctr->training_failed();

        // If we fail the custom write centering, it could have been due to bad RD settings, so hit restore the original RD settings
        if(l_training_fail)
        {
            FAPI_ERR("%s rp%lu custom WR CTR failed. Restoring read values (in the hopes that the read caused the fail) and continuing.",
                     mss::c_str(i_target), i_rp);
            FAPI_TRY(l_rd_settings.restore());
        }
        else
        {
            FAPI_INF("%s rp%lu custom WR CTR passed! continuing..", mss::c_str(i_target), i_rp);
        }

        // Run while training is failing and we still have custom RD centering patterns to try
    }
    while((l_training_fail) && (!iv_rd_ctr->is_out_of_patterns()));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Creates the vector of training steps to loop over
/// @param[in] i_cal_steps - the bit mask of calibration steps
/// @param[in] i_sim - simulation mode or not
/// @return a vector of the calibration steps to run
///
std::vector<std::shared_ptr<step>> steps_factory(const fapi2::buffer<uint32_t>& i_cal_steps, const bool i_sim)
{
    FAPI_INF("Running factory for cal_steps:0x%08x %s mode", i_cal_steps, i_sim ? "simulation" : "hardware");
    std::vector<std::shared_ptr<step>> l_steps;

#ifdef LRDIMM_CAPABLE

    // MREP
    if(i_cal_steps.getBit<mss::cal_steps::MREP>())
    {
        FAPI_INF("LRDIMM: MREP is enabled");
        l_steps.push_back(std::make_shared<mss::training::lrdimm::mrep>());
    }

    // MRD_COARSE
    if(i_cal_steps.getBit<mss::cal_steps::MRD_COARSE>())
    {
        FAPI_INF("LRDIMM: MRD_COARSE is enabled");
        l_steps.push_back(std::make_shared<mss::training::lrdimm::mrd_coarse>());
    }

    //VREF BUFFER_RD_VREF
    if(i_cal_steps.getBit<mss::cal_steps::BUFFER_RD_VREF>())
    {
        FAPI_INF("LRDIMM: BUFFER_RD_VREF is enabled");
        l_steps.push_back(std::make_shared<mss::training::lrdimm::vref<mss::training::lrdimm::vref_types::BUFFER_RD_VREF>>());
    }

    // MRD_FINE
    if(i_cal_steps.getBit<mss::cal_steps::MRD_FINE>())
    {
        FAPI_INF("LRDIMM: MRD_FINE is enabled");
        l_steps.push_back(std::make_shared<mss::training::lrdimm::mrd_fine>());
    }

    // DWL
    if(i_cal_steps.getBit<mss::cal_steps::DWL>())
    {
        FAPI_INF("LRDIMM: DWL is enabled");
        l_steps.push_back(std::make_shared<mss::training::lrdimm::dwl>());
    }

#endif

    // WR LVL
    if(i_cal_steps.getBit<mss::cal_steps::WR_LEVEL>())
    {
        FAPI_INF("Write leveling is enabled");
        l_steps.push_back(std::make_shared<wr_lvl>(i_sim));
    }

#ifdef LRDIMM_CAPABLE

    //MWD COARSE
    if(i_cal_steps.getBit<mss::cal_steps::MWD_COARSE>())
    {
        FAPI_INF("LRDIMM: MWD COARSE is enabled");
        l_steps.push_back(std::make_shared<mss::training::lrdimm::mwd_coarse>());
    }

    //VREF DRAM_WR_VREF
    if(i_cal_steps.getBit<mss::cal_steps::DRAM_WR_VREF>())
    {
        FAPI_INF("LRDIMM: DRAM_WR_VREF is enabled");
        l_steps.push_back(std::make_shared<mss::training::lrdimm::vref<mss::training::lrdimm::vref_types::DRAM_WR_VREF>>());
    }

    //MWD FINE
    if(i_cal_steps.getBit<mss::cal_steps::MWD_FINE>())
    {
        FAPI_INF("LRDIMM: MWD FINE is enabled");
        l_steps.push_back(std::make_shared<mss::training::lrdimm::mwd_fine>());
    }

#endif

    // INITIAL_PAT_WR
    if(i_cal_steps.getBit<mss::cal_steps::INITIAL_PAT_WR>())
    {
        FAPI_INF("Initial pattern write is enabled");
        l_steps.push_back(std::make_shared<initial_pattern_write>());
    }

    // DQS_ALIGN
    if(i_cal_steps.getBit<mss::cal_steps::DQS_ALIGN>())
    {
        FAPI_INF("DQS align is enabled");
        l_steps.push_back(std::make_shared<dqs_align>());
    }

    // RDCLK_ALIGN
    if(i_cal_steps.getBit<mss::cal_steps::RDCLK_ALIGN>())
    {
        FAPI_INF("RDCLK align is enabled");
        l_steps.push_back(std::make_shared<rdclk_align>());
    }

    // READ_CTR_2D_VREF or READ_CTR
    const bool RD_VREF = i_cal_steps.getBit<mss::cal_steps::READ_CTR_2D_VREF>();
    const bool RD_CTR  = i_cal_steps.getBit<mss::cal_steps::READ_CTR>();

    if(RD_VREF || RD_CTR)
    {
        FAPI_INF("Read centering %s enabled read VREF %s enabled",
                 RD_CTR ? "is" : "isn't",
                 RD_VREF ? "is" : "isn't");
        l_steps.push_back(std::make_shared<read_ctr>(RD_VREF, RD_CTR));
    }

    // WR_VREF_LATCH additionally WRITE_CTR_2D_VREF is needed
    const bool WR_LATCH = i_cal_steps.getBit<mss::cal_steps::WR_VREF_LATCH>();
    const bool WR_VREF  = i_cal_steps.getBit<mss::cal_steps::WRITE_CTR_2D_VREF>();
    const bool WRITE_CTR   = i_cal_steps.getBit<mss::cal_steps::WRITE_CTR>();

    if(WR_LATCH)
    {
        FAPI_INF("Write VREF latching is enabled %s WR VREF",
                 WR_VREF ? "with" : "without");

        l_steps.push_back(std::make_shared<wr_vref_latch>( WR_VREF ));
    }

    // WRITE_CTR_2D_VREF or WRITE_CTR
    if(WR_VREF || WRITE_CTR)
    {
        FAPI_INF("Write centering is enabled %s WR VREF",
                 WR_VREF ? "with" : "without");

        l_steps.push_back(std::make_shared<write_ctr>( WR_VREF ));
    }

    // COARSE WR/RD
    if(i_cal_steps.getBit<mss::cal_steps::COARSE_WR>() || i_cal_steps.getBit<mss::cal_steps::COARSE_RD>())
    {
        FAPI_INF("Coarse WR/RD is enabled");
        l_steps.push_back(std::make_shared<coarse_wr_rd>());
    }

    // Run custom WR CTR and custom RD CTR together
    if(i_cal_steps.getBit<mss::cal_steps::TRAINING_ADV_RD>() && i_cal_steps.getBit<mss::cal_steps::TRAINING_ADV_WR>())
    {
        FAPI_INF("Custom RD_CTR and Custom WR_CTR are enabled");
        l_steps.push_back(std::make_shared<custom_training_facade>());
    }
    // Training Advanced Read - aka custom pattern RD CTR
    else if(i_cal_steps.getBit<mss::cal_steps::TRAINING_ADV_RD>())
    {
        FAPI_INF("Custom RD_CTR is enabled");
        l_steps.push_back(std::make_shared<custom_read_ctr>());
    }

    // Training Advanced Write - aka custom pattern WR CTR
    else if(i_cal_steps.getBit<mss::cal_steps::TRAINING_ADV_WR>())
    {
        FAPI_INF("Custom WR_CTR is enabled");
        l_steps.push_back(std::make_shared<custom_write_ctr>());
    }

#ifdef LRDIMM_CAPABLE

    //VREF BUFFER_WR_VREF
    if(i_cal_steps.getBit<mss::cal_steps::BUFFER_WR_VREF>())
    {
        FAPI_INF("LRDIMM: BUFFER_WR_VREF is enabled");
        l_steps.push_back(std::make_shared<mss::training::lrdimm::buffer_wr_vref>());
    }

#endif

    return l_steps;
}

///
/// @brief Creates the vector of training steps to loop over with an LRDIMM switch included
/// @param[in] i_dimm_type - the DIMM type - used to select LRDIMM vs not
/// @param[in] i_cal_steps - the bit mask of calibration steps
/// @param[in] i_sim - simulation mode or not
/// @return a vector of the calibration steps to run
///
std::vector<std::shared_ptr<step>> steps_factory(const uint8_t i_dimm_type, const fapi2::buffer<uint32_t>& i_cal_steps,
                                const bool i_sim)
{
    // We need to modify the calibration steps, so create a copy
    auto l_cal_steps = i_cal_steps;

    // Deconfigure based upon DIMM type (don't run LR if we're not LR)
    mss::training::lrdimm::deconfigure_steps(i_dimm_type, i_sim, l_cal_steps);

    // Deconfigure based upon simulation mode
    sim::deconfigure_steps(i_sim, l_cal_steps);

    // Print the configured calibration steps
    FAPI_INF("Configured calibration steps are 0x%08x for DIMM type: %u %s mode",
             l_cal_steps, i_dimm_type, i_sim ? "simulation" : "hardware");

    // Run the standard factory
    return steps_factory(l_cal_steps, i_sim);
}

namespace sim
{

///
/// @brief Deconfigures steps based upon simulation mode
/// @param[in] i_sim - simulation mode or not
/// @param[in,out] io_cal_steps calibration steps to deconfigure
///
void deconfigure_steps(const bool i_sim, fapi2::buffer<uint32_t>& io_cal_steps)
{
    // If we're not in sim mode, everything can run a-ok
    if(!i_sim)
    {
        FAPI_INF("We're not in simulation mode, we can run with all configured steps");
        return;
    }

    FAPI_INF("In simulation mode. Deconfiguring initial pattern write and training advanced read");
    // Otherwise, deconfigure those steps
    // Note: simulation contains a bug where the DDR4 model does not match the DDR4 hardware
    // As such, if the simulation IPW bug is set, do not create a step for initial pattern write
    io_cal_steps.clearBit<mss::cal_steps::INITIAL_PAT_WR>();

    // We can't run custom pattern RD as it requires initial pattern write, so skipping it in SIM mode
    io_cal_steps.clearBit<mss::cal_steps::TRAINING_ADV_RD>();
}

} // ns sim

} // ns training

} // ns mss
