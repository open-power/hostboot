/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_dwl.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file lib/phy/mss_dwl.H
/// @brief DWL LRDIMM training
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <lib/shared/nimbus_defaults.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/phy/mss_lrdimm_training.H>
#include <lib/phy/mss_dwl.H>
#include <lib/phy/mss_training.H>
#include <lib/dimm/rank.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>
#include <lib/dimm/ddr4/data_buffer_ddr4.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/ccs/ccs.H>
#include <lib/mc/port.H>
#include <lib/rosetta_map/rosetta_map.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/dimm/ddr4/pba.H>
#include <lib/phy/mss_lrdimm_training_helper.H>

namespace mss
{

namespace training
{

namespace lrdimm
{
///
/// @brief Configures the given rank into WR LVL mode
/// @param[in] i_target DIMM target on which to operate
/// @paran[in] i_rank the rank on which to operate
/// @paran[in] i_mode mode for the WR LVL
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dwl::dram_wr_lvl( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint64_t i_rank,
                                    const mss::states i_mode) const
{
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    FAPI_TRY( mss::ddr4::wr_lvl(i_target,
                                i_mode,
                                i_rank,
                                l_program.iv_instructions) );

    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );
fapi_try_exit:
    // If we are here then we FAPI_ASSERT'ed out
    return fapi2::current_err;
}

///
/// @brief Executes the pre-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dwl::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                       const uint64_t i_rp,
                                       const uint8_t i_abort_on_error ) const
{
    FAPI_INF("%s setting up the read pointer enable rp%u", mss::c_str(i_target), i_rp);
    FAPI_TRY( mss::setup_read_pointer_delay(i_target));

    // call function to force DQ capture in Read FIFO to support DDR4 LRDIMM calibration.
    FAPI_TRY( mss::dp16::write_force_dq_capture(i_target, mss::states::ON),
              "%s failed to write force dq capture", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode dwl::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                        const uint64_t i_rp,
                                        const uint8_t i_abort_on_error ) const
{
    // call function to force DQ capture in Read FIFO to support DDR4 LRDIMM calibration.
    FAPI_TRY( mss::dp16::write_force_dq_capture(i_target, mss::states::OFF),
              "%s failed to write exit dq capture", mss::c_str(i_target) );

    // Clears the FIR's that can get set by training
    // They're not real, so we want to clear them and move on
    FAPI_TRY(mss::training::lrdimm::workarounds::clear_firs(i_target), "%s failed to clear FIRs", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the rank to calibrate for WR LVL in the buffer
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the rank target on which to operate
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dwl::set_rank(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                const uint64_t i_rank) const
{
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    std::vector<cw_info> l_bcws =
    {
        {FUNC_SPACE_0, RANK_SELECTION_CW, mss::index(i_rank), mss::tmrc(), mss::CW4_DATA_LEN, cw_info::BCW},
    };

    uint8_t l_sim = 0;
    FAPI_TRY(mss::is_simulation(l_sim));

    // Ensure our CKE's are powered on
    l_program.iv_instructions.push_back(mss::ccs::des_command<fapi2::TARGET_TYPE_MCBIST>());

    // Inserts the function space selects
    FAPI_TRY(mss::ddr4::insert_function_space_select(l_bcws));

    // Sets up the CCS instructions
    FAPI_TRY(control_word_engine(i_target,
                                 l_bcws,
                                 l_sim,
                                 l_program.iv_instructions));

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    // Issue CCS
    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );

fapi_try_exit:
    // If we are here then we FAPI_ASSERT'ed out
    return fapi2::current_err;
}

///
/// @brief Sets DWL Delay value
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank to operate on - drives the function space select
/// @param[in] delay value /64 Tck - DWL delay value
/// @return FAPI2_RC_SUCCESS if okay
/// @note Sets DA setting for buffer control word (F[3:0]BC2x, F[3:0]BC3x)
///
fapi2::ReturnCode dwl::set_delay(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint8_t i_rank,
                                 const uint8_t i_delay ) const
{
    constexpr uint8_t NIBBLE0_BCW_NUMBER = 0x0A;
    constexpr uint8_t NIBBLE1_BCW_NUMBER = 0x0B;
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // The rank just corresponds to the function space
    std::vector<cw_info> l_bcws =
    {
        {i_rank, NIBBLE0_BCW_NUMBER, i_delay, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {i_rank, NIBBLE1_BCW_NUMBER, i_delay, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
    };

    uint8_t l_sim = 0;
    FAPI_TRY(mss::is_simulation(l_sim));

    // Ensure our CKE's are powered on
    l_program.iv_instructions.push_back(mss::ccs::des_command<fapi2::TARGET_TYPE_MCBIST>());

    // Inserts the function space selects
    FAPI_TRY(mss::ddr4::insert_function_space_select(l_bcws));

    // Sets up the CCS instructions
    FAPI_TRY(control_word_engine(i_target,
                                 l_bcws,
                                 l_sim,
                                 l_program.iv_instructions));

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    // Issue CCS
    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );

fapi_try_exit:
    // If we are here then we FAPI_ASSERT'ed out
    return fapi2::current_err;
}

///
/// @brief Creates the nibble flags for the invalid data callout
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @param[out] o_invalid_count number of invalid data occurances seen
/// @return invalid data nibble flags
/// @note Invalid data is defined as not having all zeros or all ones
///
uint32_t dwl::flag_invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint8_t i_rank,
                                 const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders,
                                 uint64_t& o_invalid_count) const
{
    o_invalid_count = 0;
    uint8_t l_buffer = 0;

    // Per nibble invalid data flags - bitmap
    uint32_t l_per_nibble_flags = 0;

    for(const auto& l_recorder : i_recorders)
    {

        // This is a coding issue here, just break out of the loop
        // We should never have more data than recorders
        // No need to log it, just recover and continue
        if(l_buffer >= MAX_LRDIMM_BUFFERS)
        {
            FAPI_ERR("%s rank%u saw buffer%u when number of buffers is %u. Continuing gracefully",
                     mss::c_str(i_target), i_rank, l_buffer, MAX_LRDIMM_BUFFERS);
            break;
        }

        // Updates the bitmap
        o_invalid_count += l_recorder.first.iv_invalid_data_count + l_recorder.second.iv_invalid_data_count;
        append_nibble_flags(l_recorder.first.iv_invalid_data_count != mrep_dwl_recorder::CLEAN,
                            l_recorder.second.iv_invalid_data_count != mrep_dwl_recorder::CLEAN,
                            l_per_nibble_flags);

        l_buffer++;
    }

    return l_per_nibble_flags;
}

///
/// @brief Calls out if invalid data is seen during this calibration step
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return FAPI2_RC_SUCCESS if okay
/// @note Invalid data is defined as not having all zeros or all ones
///
fapi2::ReturnCode dwl::callout_invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    // Per nibble invalid data - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    // We also count the number of occurances of invalid data across the port/rank
    // This count gives more insight into the fails
    // Low counts mean one off data glitches
    // High counts indicate that one or more nibbles are having issues
    uint64_t l_invalid_data_count = 0;
    const auto l_per_nibble_flags = flag_invalid_data( i_target, i_rank, i_recorders, l_invalid_data_count);

    FAPI_TRY(callout::invalid_data( i_target,
                                    i_rank,
                                    l_per_nibble_flags,
                                    l_invalid_data_count,
                                    mss::cal_steps::DWL,
                                    "DWL"));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Creates the nibble flags for the no transition callout
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return no transition nibble flags
///
uint32_t dwl::flag_no_transition( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint8_t i_rank,
                                  const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    uint8_t l_buffer = 0;

    // Per nibble invalid data flags - bitmap
    uint32_t l_per_nibble_flags = 0;

    for(const auto& l_recorder : i_recorders)
    {

        // This is a coding issue here, just break out of the loop
        // We should never have more data than recorders
        // No need to log it, just recover and continue
        if(l_buffer >= MAX_LRDIMM_BUFFERS)
        {
            FAPI_ERR("%s rank%u saw buffer%u when number of buffers is %u. Continuing gracefully",
                     mss::c_str(i_target), i_rank, l_buffer, MAX_LRDIMM_BUFFERS);
            break;
        }

        const bool l_nibble0_no_transition = !l_recorder.first.iv_seen0 || !l_recorder.first.iv_seen1;
        const bool l_nibble1_no_transition = !l_recorder.second.iv_seen0 || !l_recorder.second.iv_seen1;

        // Updates the bitmap
        append_nibble_flags(l_nibble0_no_transition, l_nibble1_no_transition, l_per_nibble_flags);

        l_buffer++;
    }

    return l_per_nibble_flags;
}

///
/// @brief Calls out if a rank does not see a 0->1 transition
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode dwl::callout_no_transition( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    // Per nibble weird data and no transition flags - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    uint32_t l_per_nibble_flags = flag_no_transition( i_target, i_rank, i_recorders);

    // Error checking here
    FAPI_TRY(callout::no_transition( i_target,
                                     i_rank,
                                     l_per_nibble_flags,
                                     mss::cal_steps::DWL,
                                     "DWL"));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Analyzes the results for a given DWL run
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode dwl::check_errors( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint8_t i_rank,
                                     const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    FAPI_TRY(callout_no_transition(i_target, i_rank, i_recorders));
    FAPI_TRY(callout_invalid_data(i_target, i_rank, i_recorders));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write the results to buffer generate PBA commands
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank number
/// @param[in] i_recorders a vector of the DWL result
/// @param[out] o_container the PBA commands structure
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note a little helper to allow us to unit test that we generate the PBA commands ok
///
fapi2::ReturnCode dwl::write_result_to_buffers_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders,
        mss::ddr4::pba::commands& o_container) const
{
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    uint8_t l_buffer = 0;

    // Maybe make setting up the pba::commands a helper function so we can unit test this better?
    for(const auto& l_recorder : i_recorders)
    {
        // Note: nibbles are swapped if the nibbles are swizzled in the buffer
        bool l_are_nibbles_swapped = false;
        FAPI_TRY(are_buffers_nibbles_swizzled(l_mca, l_buffer, l_are_nibbles_swapped));

        {
            const auto l_result_nibble0 = l_are_nibbles_swapped ?
                                          l_recorder.second.iv_delay :
                                          l_recorder.first.iv_delay;
            const auto l_result_nibble1 = l_are_nibbles_swapped ?
                                          l_recorder.first.iv_delay :
                                          l_recorder.second.iv_delay;

            FAPI_DBG("%s DWL rank%u buffer:%u final values (0x%02x,0x%02x) %s swapped BC2x:0x%02x BC3x:0x%02x",
                     mss::c_str(i_target), i_rank, l_buffer, l_recorder.first.iv_delay, l_recorder.second.iv_delay,
                     l_are_nibbles_swapped ? "are" : "not", l_result_nibble0, l_result_nibble1);

            // Function space is derived from the rank
            // 2 is for Nibble 0, 3 is for Nibble 1
            // Data corresponds to the final setting we have
            // Delay is for PBA, bumping it way out so we don't have issues
            constexpr uint64_t PBA_DELAY = 255;
            constexpr uint64_t BCW_NIBBLE0 = 0x0A;
            constexpr uint64_t BCW_NIBBLE1 = 0x0B;

            const mss::cw_info FINAL_SET_BCW_N0(i_rank,
                                                BCW_NIBBLE0,
                                                l_result_nibble0,
                                                PBA_DELAY,
                                                mss::CW8_DATA_LEN,
                                                mss::cw_info::BCW);
            const mss::cw_info FINAL_SET_BCW_N1(i_rank,
                                                BCW_NIBBLE1,
                                                l_result_nibble1,
                                                PBA_DELAY,
                                                mss::CW8_DATA_LEN,
                                                mss::cw_info::BCW);

            // Each buffer contains two nibbles
            // Each nibble corresponds to one BCW
            // Add in the buffer control words
            FAPI_TRY(o_container.add_command(i_target, l_buffer, FINAL_SET_BCW_N0));
            FAPI_TRY(o_container.add_command(i_target, l_buffer, FINAL_SET_BCW_N1));

            ++l_buffer;
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Writes the results to the buffers for a given DIMM-rank
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode dwl::write_result_to_buffers( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    mss::ddr4::pba::commands l_container;

    // Sets up the PBA commands
    FAPI_TRY(write_result_to_buffers_helper( i_target,
             i_rank,
             i_recorders,
             l_container),
             "%s rank%u failed generating PBA commands",
             mss::c_str(i_target), i_rank);

    // Issue the PBA to set the final DWL results
    FAPI_TRY(mss::ddr4::pba::execute_commands(l_container));

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
fapi2::ReturnCode dwl::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                            const uint64_t i_rp,
                            const uint8_t i_abort_on_error ) const
{
    std::vector<uint64_t> l_ranks;
    FAPI_INF("%s RP%d starting to try to calibrate DWL", mss::c_str(i_target), i_rp);

    const auto& l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target);

    FAPI_TRY(mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
             "Failed get_ranks_in_pair in dwl::run %s",
             mss::c_str(i_target));

    // Disable all rank of 2 dimm's before training
    for (const auto& l_dimm : l_dimms)
    {
        FAPI_TRY(set_rank_presence(l_dimm, RANK_PRESENCE_MASK));
    }

    // Loops over all ranks within this rank pair
    // DWL is a buffer to DRAM calibration step, so we need to calibrate all ranks seperately
    for (const auto& l_rank : l_ranks)
    {
        // Skip over invalid ranks (NO_RANK)
        if(l_rank == NO_RANK)
        {
            continue;
        }

        FAPI_DBG("%s RP%u rank%u is going to run DWL", mss::c_str(i_target), i_rp, l_rank);
        const auto& l_dimm = l_dimms[mss::rank::get_dimm_from_rank(l_rank)];
        const auto l_dimm_rank = mss::index(l_rank);

        // Vector represents the number of LRDIMM buffers
        // The pair represents the two nibbles that we need to calibrate within the buffer
        std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>> l_results_recorder(MAX_LRDIMM_BUFFERS);
        //Loop through all of our delays multiple times to reduce noise issues
        std::vector<mrep_dwl_result> l_loop_results(MREP_DWL_LOOP_TIMES);

        // 1) Puts the DRAM into WR LVL mode
        FAPI_TRY(dram_wr_lvl(l_dimm, l_rank, mss::states::ON), "%s failed set_buffer_training",
                 mss::c_str(l_dimm));

        // 2) set the rank presence
        FAPI_TRY(set_rank_presence(l_dimm, generate_rank_presence(l_rank)),
                 "%s failed set rank%u",
                 mss::c_str(l_dimm), l_rank);

        // 3) Selects the rank to calibrate on the buffer
        FAPI_TRY(set_rank(l_dimm, l_rank), "%s failed to set_rank", mss::c_str(l_dimm));

        // 4) Puts the buffer into WR LVL mode
        FAPI_TRY(set_buffer_training(l_dimm, ddr4::DWL), "%s failed set_buffer_training", mss::c_str(l_dimm));

        for(auto& l_loop_result : l_loop_results)
        {
            // Loop through all of our delays
            for(uint8_t l_delay = 0; l_delay < MREP_DWL_MAX_DELAY; ++l_delay)
            {
                // 5) Set the DWL l_delay -> host issues BCW's
                FAPI_TRY(set_delay(l_dimm, l_dimm_rank, l_delay), "%s failed set_delay rank%u delay%u", mss::c_str(l_dimm),
                         l_rank, l_delay);

                // 6) Do an NTTM mode read -> forces the logic to read out the data
                FAPI_TRY(execute_nttm_mode_read(i_target));

                // 7) Get the results for this delay and updates result and the recorder
                FAPI_TRY(get_result(l_dimm, mss::cal_steps::DWL, l_delay, l_loop_result, l_results_recorder),
                         "%s failed get_result rank%u delay%u",
                         mss::c_str(l_dimm), l_rank, l_delay);
            } //l_delay loop
        }

        // 8) Takes the buffer out of WR LVL mode
        FAPI_TRY(set_buffer_training(l_dimm, ddr4::NORMAL), "%s failed set_buffer_training", mss::c_str(l_dimm));

        // 9) Takes the DRAM out of WR LVL mode
        FAPI_TRY(dram_wr_lvl(l_dimm, l_rank, mss::states::OFF), "%s failed set_buffer_training",
                 mss::c_str(l_dimm));

        // 10) Analyze loop results
        FAPI_TRY( analyze_result(l_dimm, mss::cal_steps::DWL, l_loop_results, l_results_recorder),
                  "%s failed analyze_dwl_result rank%u",
                  mss::c_str(l_dimm), l_rank);

        // 11) Checks for errors
        FAPI_TRY(check_errors(l_dimm, l_rank, l_results_recorder), "%s failed error_check rank:%u", mss::c_str(l_dimm),
                 l_rank);

        // 12) Write final values into the buffers -> host issues BCW's in PBA mode (values are calculated in step 7)
        FAPI_TRY( write_result_to_buffers(l_dimm, l_dimm_rank, l_results_recorder), "%s failed write_result_to_buffers rank%u",
                  mss::c_str(l_dimm), l_rank);
    }//l_rank loop

    // 13) set for two or four rank dimms
    for (const auto& l_dimm : l_dimms)
    {
        uint8_t l_rank_num = 0;
        FAPI_TRY( eff_num_master_ranks_per_dimm(l_dimm, l_rank_num) );
        FAPI_TRY(set_rank_presence(l_dimm, generate_rank_presence_value(l_rank_num)));
    }

fapi_try_exit:
    // If we are here then we FAPI_ASSERT'ed out
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t dwl::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

} // ns lrdimm

} // ns training

} // ns mss
