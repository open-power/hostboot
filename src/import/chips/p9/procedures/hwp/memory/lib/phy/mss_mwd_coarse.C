/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_mwd_coarse.C $ */
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
/// @file lib/phy/mss_mwd_coarse.C
/// @brief MWD coarse LRDIMM training step
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
#include <lib/phy/mss_training.H>
#include <lib/dimm/rank.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>
#include <lib/dimm/ddr4/data_buffer_ddr4.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/ccs/ccs.H>
#include <lib/mc/port.H>
#include <lib/rosetta_map/rosetta_map.H>
#include <lib/eff_config/timing.H>
#include <lib/phy/mss_mwd_coarse.H>
#include <lib/phy/mss_lrdimm_training_helper.H>

namespace mss
{

namespace training
{

namespace lrdimm
{

///
/// @brief Executes the pre-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mwd_coarse::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    // Add in set FIFO ON
    // call function to force DQ capture in Read FIFO to support DDR4 LRDIMM calibration.
    FAPI_TRY( mss::dp16::write_force_dq_capture(i_target, mss::states::ON),
              "%s failed to write force dq capture", mss::c_str(i_target) );

    // Add in set read pointer
    FAPI_INF("%s setting up the read pointer enable rp%u", mss::c_str(i_target), i_rp);
    FAPI_TRY( mss::setup_read_pointer_delay(i_target));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Sets the delay for a given rank
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the DIMM rank on which to set the delay
/// @param[in] i_delay the indexed delay to set
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up buffer control word F0BCDx F0BCFx F1BCDx F1BCFx
///
fapi2::ReturnCode mwd_coarse::set_delay(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint64_t i_dimm_rank,
                                        const uint8_t i_delay) const
{
    // Gets us into the BCW nomenclature instead of the indexed nomenclature
    const auto l_bcw_delay = convert_delay_to_bcw(i_delay);

    // Creates the BCW data value
    // Simply copy the data across both nibbles in the BCW
    const uint8_t l_bcw_data = l_bcw_delay | (l_bcw_delay << BITS_PER_NIBBLE);

    // Gets the function space
    const uint8_t l_func_space = generate_func_space(i_dimm_rank);

    // Gets the BCW number
    const uint8_t l_bcw_number = generate_bcw_number(i_dimm_rank);

    std::vector<cw_info> l_bcws =
    {
        {l_func_space, l_bcw_number, l_bcw_data, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
    };
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

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
/// @brief Analyzes the results for a given run
/// @param[in] i_target the MCA target
/// @param[in] i_dimm_rank the DIMM rank on which to set the delay
/// @param[in] i_delay the delay for this run
/// @param[in,out] io_results the results
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode mwd_coarse::analyze_results(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_dimm_rank,
        const uint8_t i_delay,
        std::vector<std::pair<coarse_recorder, coarse_recorder>>& io_results) const
{
    uint8_t l_buffer = 0;
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // Reads out the data results from the MWD
    data_response l_data;
    FAPI_TRY(l_data.read(l_mca), "%s failed to read MWD_COARSE data response delay:0x%02x", mss::c_str(i_target), i_delay);

#ifndef __HOSTBOOT_MODULE

    // Displays all of the data here
    for(uint8_t l_buffer_loop = 0; l_buffer_loop < MAX_LRDIMM_BUFFERS; ++l_buffer_loop)
    {
        for(uint8_t i = 0; i < 8; ++i)
        {
            FAPI_DBG("%s delay:0x%02x MWD_COARSE result buffer%u BEAT%u data:0x%02x",
                     mss::c_str(i_target), i_delay, l_buffer_loop, i, l_data.iv_buffer_beat[l_buffer_loop][i]);
        }
    }

#endif

    // Now, loop through all of the buffers and analyze the results on a per-nibble basis
    for(auto& l_buffer_results : io_results)
    {

        // All beats should be the same, until proven otherwise, just use beat 0
        constexpr uint64_t DEFAULT_BEAT = 0;

        // Data for nibble 0/1
        uint8_t l_data_nibble0 = 0;
        uint8_t l_data_nibble1 = 0;

        const fapi2::buffer<uint8_t> l_buffer_result(l_data.iv_buffer_beat[l_buffer][DEFAULT_BEAT]);
        l_buffer_result.extractToRight<0, BITS_PER_NIBBLE>(l_data_nibble0);
        l_buffer_result.extractToRight<BITS_PER_NIBBLE, BITS_PER_NIBBLE>(l_data_nibble1);


        FAPI_DBG("%s delay:0x%02x MWD_COARSE result buffer:%u result 0x%02x nibble0:0x%02x nibble1:0x%02x",
                 mss::c_str(i_target), i_delay, l_buffer, uint8_t(l_buffer_result), l_data_nibble0, l_data_nibble1);

        FAPI_TRY(l_buffer_results.first.add_results(i_delay, l_data_nibble0));
        FAPI_TRY(l_buffer_results.second.add_results(i_delay, l_data_nibble1));
        l_buffer++;
    }

fapi_try_exit:
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
uint32_t mwd_coarse::flag_invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint8_t i_rank,
                                        const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_recorders,
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
        append_nibble_flags(l_recorder.first.iv_invalid_data_count != coarse_recorder::CLEAN,
                            l_recorder.second.iv_invalid_data_count != coarse_recorder::CLEAN,
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
fapi2::ReturnCode mwd_coarse::callout_invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_recorders) const
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
                                    mss::cal_steps::MWD_COARSE,
                                    "MWD_COARSE"));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Creates the nibble flags for the not one passing region callout
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return passing region nibble flags
///
uint32_t mwd_coarse::flag_not_one_passing_region( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_recorders) const
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

        const bool l_nibble0_not_one_passing_region = (1 != mss::bit_count((uint8_t) l_recorder.first.iv_results));
        const bool l_nibble1_not_one_passing_region = (1 != mss::bit_count((uint8_t) l_recorder.second.iv_results));

        // Updates the bitmap
        append_nibble_flags(l_nibble0_not_one_passing_region, l_nibble1_not_one_passing_region, l_per_nibble_flags);

        l_buffer++;
    }

    return l_per_nibble_flags;
}

///
/// @brief Calls out if a rank found not one passing region
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode mwd_coarse::callout_not_one_passing_region( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_recorders) const
{
    // Per nibble weird data and no transition flags - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    uint32_t l_per_nibble_flags = flag_not_one_passing_region( i_target, i_rank, i_recorders);

    FAPI_TRY(callout::not_one_passing_region( i_target,
             i_rank,
             l_per_nibble_flags,
             mss::cal_steps::MWD_COARSE,
             "MWD_COARSE"));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Finds the final results for the whole DIMM rank
/// @param[in] i_target the MCA target
/// @param[in] i_dimm_rank the DIMM rank on which to set the delay
/// @param[in,out] io_results the results
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mwd_coarse::find_final_results(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_dimm_rank,
        std::vector<std::pair<coarse_recorder, coarse_recorder>>& io_results) const
{
    uint8_t l_buffer = 0;
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    for(auto& l_buffer_result : io_results)
    {
        FAPI_TRY(l_buffer_result.first.find_final_delay(i_target, i_dimm_rank));
        FAPI_TRY(l_buffer_result.second.find_final_delay(i_target, i_dimm_rank));

        FAPI_DBG("%s MWD_COARSE rank%u buffer:%u final results raw data: 0x%02x 0x%02x, results 0x%02x 0x%02x",
                 mss::c_str(l_mca), i_dimm_rank, l_buffer,
                 uint8_t(l_buffer_result.first.iv_results), uint8_t(l_buffer_result.second.iv_results),
                 l_buffer_result.first.iv_final_delay, l_buffer_result.second.iv_final_delay);
        ++l_buffer;
    }

    FAPI_TRY(callout_invalid_data(i_target, i_dimm_rank, io_results));
    FAPI_TRY(callout_not_one_passing_region(i_target, i_dimm_rank, io_results));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the final delays for a DIMM/rank target
/// @param[in] i_target the DIMM target
/// @param[in] i_dimm_rank the DIMM rank on which to set the delay
/// @param[in] i_results the results
/// @param[out] o_container the PBA commands structure
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mwd_coarse::set_final_delays_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_dimm_rank,
        const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_results,
        mss::ddr4::pba::commands& o_container) const
{
    uint8_t l_buffer = 0;
    constexpr uint64_t PBA_DELAY = 255;
    // Gets the function space
    const uint8_t l_func_space = generate_func_space(i_dimm_rank);

    // Gets the BCW number
    const uint8_t l_bcw_number = generate_bcw_number(i_dimm_rank);

    // Get's the MCA
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    for(const auto& l_result : i_results)
    {
        fapi2::buffer<uint8_t> l_data;
        bool l_are_nibbles_swapped = false;
        FAPI_TRY(are_buffers_nibbles_swizzled(l_mca, l_buffer, l_are_nibbles_swapped));


        auto l_bcw_result0 = l_are_nibbles_swapped ?
                             l_result.second.iv_final_delay :
                             l_result.first.iv_final_delay;
        auto l_bcw_result1 = l_are_nibbles_swapped ?
                             l_result.first.iv_final_delay :
                             l_result.second.iv_final_delay;

        FAPI_DBG("%s MWD coarse rank%u buffer:%u final values (0x%02x,0x%02x) %s swapped nibble0:0x%02x nibble1:0x%02x",
                 mss::c_str(l_mca), i_dimm_rank, l_buffer, l_result.first.iv_final_delay, l_result.second.iv_final_delay,
                 l_are_nibbles_swapped ? "are" : "not", l_bcw_result0, l_bcw_result1);

        l_bcw_result0 = convert_delay_to_bcw(l_bcw_result0);
        l_bcw_result1 = convert_delay_to_bcw(l_bcw_result1);
        l_data.insertFromRight<0, BITS_PER_NIBBLE>(l_bcw_result1);
        l_data.insertFromRight<BITS_PER_NIBBLE, BITS_PER_NIBBLE>(l_bcw_result0);

        const mss::cw_info MWD_FINAL_SET_BCW_N0(l_func_space,
                                                l_bcw_number,
                                                l_data,
                                                PBA_DELAY,
                                                mss::CW8_DATA_LEN,
                                                mss::cw_info::BCW);

        // Adds the PBA command for this buffer
        FAPI_TRY(o_container.add_command(i_target, l_buffer, MWD_FINAL_SET_BCW_N0));

        ++l_buffer;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the final delays for a DIMM/rank target
/// @param[in] i_target the DIMM target
/// @param[in] i_dimm_rank the DIMM rank on which to set the delay
/// @param[in] i_results the results
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mwd_coarse::set_final_delays(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_dimm_rank,
        const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_results) const
{

    mss::ddr4::pba::commands l_container;

    // Sets up the PBA commands
    FAPI_TRY(set_final_delays_helper( i_target,
                                      i_dimm_rank,
                                      i_results,
                                      l_container),
             "%s rank%u failed generating PBA commands",
             mss::c_str(i_target), i_dimm_rank);

    // Issue the PBA to set the final MWD COARSE results
    FAPI_TRY(mss::ddr4::pba::execute_commands(l_container));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief conduct write then read
/// @param[in] i_target the DIMM target for the data
/// @param[in] i_rank the DIMM rank on which to set the delay
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mwd_coarse::conduct_write_read( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank) const
{
    constexpr uint64_t ODT_CYCLE_LEN = 5;
    using TT = ccsTraits<fapi2::TARGET_TYPE_MCBIST>;
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // Used for ODT values
    const auto l_dimm_rank = mss::index(i_rank);

    // Gets WR/RD ODT values
    uint8_t l_rd_odt[MAX_RANK_PER_DIMM] = {};
    uint8_t l_wr_odt[MAX_RANK_PER_DIMM] = {};

    FAPI_TRY(mss::eff_odt_rd(i_target, &l_rd_odt[0]));
    FAPI_TRY(mss::eff_odt_wr(i_target, &l_wr_odt[0]));
    FAPI_DBG("%s fine wr/rd", mss::c_str(i_target));

    // Using the default values for addressing (all 0's) as it should not matter for LR calibration
    // Creates the activate and updates the timing for the activate command
    {
        // Creates the instruciton
        auto l_activate = ccs::act_command<fapi2::TARGET_TYPE_MCBIST>(i_target, i_rank);

        // Gets the command to command timing we need activate to write
        // This is a RAS command to a CAS command, so RAS to CAS delay -> tRCD
        uint8_t l_trcd = 0;
        FAPI_TRY(mss::eff_dram_trcd(i_target, l_trcd));
        l_activate.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>((uint64_t)l_trcd);

        // Adds the instructions to the CCS program
        l_program.iv_instructions.push_back(l_activate);
    }

    // Smash some ODT's high originally
    {
        // ODT value buffer
        const auto l_ccs_value = mss::ccs::convert_odt_attr_to_ccs<fapi2::TARGET_TYPE_MCBIST>(fapi2::buffer<uint8_t>
                                 (l_wr_odt[l_dimm_rank]));
        // Inserts ODT values
        auto l_odt = mss::ccs::odt_command<fapi2::TARGET_TYPE_MCBIST>(l_ccs_value, ODT_CYCLE_LEN + 2);
        // Adds the instructions to the CCS program
        l_program.iv_instructions.push_back(l_odt);
    }

    // Creates the write command and updates
    {
        // Creates the instruciton
        auto l_wr = ccs::wr_command<fapi2::TARGET_TYPE_MCBIST>(i_target, i_rank);

        // ODT value buffer
        const auto l_ccs_value = mss::ccs::convert_odt_attr_to_ccs<fapi2::TARGET_TYPE_MCBIST>(fapi2::buffer<uint8_t>
                                 (l_wr_odt[l_dimm_rank]));

        // Ensures that we do not have any default idles or repeats
        l_wr.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(0);
        l_wr.arr1.template insertFromRight<TT::ARR1_REPEAT_CMD_CNT, TT::ARR1_REPEAT_CMD_CNT_LEN>(0);

        // Inserts ODT values
        l_wr.arr0.template insertFromRight<TT::ARR0_DDR_ODT, TT::ARR0_DDR_ODT_LEN>(l_ccs_value);

        // Adds the instructions to the CCS program
        l_program.iv_instructions.push_back(l_wr);
    }

    // Hold the ODT's high for the whole write cycle
    {
        // ODT value buffer
        const auto l_ccs_value = mss::ccs::convert_odt_attr_to_ccs<fapi2::TARGET_TYPE_MCBIST>(fapi2::buffer<uint8_t>
                                 (l_wr_odt[l_dimm_rank]));

        // Inserts ODT values
        // Timing is ODT_CYCLE_LEN + 1
        // We could have up to +2 cycles needing to be added to our WR data
        // We have already held the ODT for one cycle due to the writes, so we use +1 instead
        auto l_odt = mss::ccs::odt_command<fapi2::TARGET_TYPE_MCBIST>(l_ccs_value, ODT_CYCLE_LEN + 1);

        // Gets the command to command timing we need for WR to RD
        // Taken from the JEDEC spec
        // Timing is CWL + BL8_clock_cycles + tWTR_L
        // We then subtract out ODT cycle length as we have already held the bus for that amout of time
        constexpr uint64_t BL8_CLOCK_CYCLES = 4;
        uint8_t l_cwl = 0;
        uint8_t l_twtr_l = 0;
        FAPI_TRY( mss::eff_dram_cwl(i_target, l_cwl) );
        FAPI_TRY( mss::eff_dram_twtr_l(i_target, l_twtr_l) );
        l_odt.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_cwl + BL8_CLOCK_CYCLES + l_twtr_l -
                ODT_CYCLE_LEN);

        // Adds the instructions to the CCS program
        l_program.iv_instructions.push_back(l_odt);
    }

    // Read auto-precharge, so we don't need to send our own precharge command
    {
        auto l_rd = ccs::rda_command<fapi2::TARGET_TYPE_MCBIST>(i_target, i_rank);

        // Wait until we should start our RD ODT's
        uint8_t l_cl = 0;
        uint8_t l_cwl = 0;
        FAPI_TRY( mss::eff_dram_cwl(i_target, l_cwl) );
        FAPI_TRY( mss::eff_dram_cl(i_target, l_cl) );
        l_rd.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_cl - l_cwl);
        l_program.iv_instructions.push_back(l_rd);
    }

    // Holds the RD ODT's for 5 cycles
    {
        const auto l_ccs_value = mss::ccs::convert_odt_attr_to_ccs<fapi2::TARGET_TYPE_MCBIST>(fapi2::buffer<uint8_t>
                                 (l_rd_odt[l_dimm_rank]));
        auto l_odt = mss::ccs::odt_command<fapi2::TARGET_TYPE_MCBIST>(l_ccs_value, ODT_CYCLE_LEN);
        l_program.iv_instructions.push_back(l_odt);
    }

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    // Issue CCS
    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );

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
fapi2::ReturnCode mwd_coarse::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_rp,
                                   const uint8_t i_abort_on_error ) const
{
    std::vector<uint64_t> l_ranks;
    uint8_t l_patterns[NUM_LRDIMM_TRAINING_PATTERNS] = {};

    const auto& l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target);
    // Get ranks
    FAPI_TRY(mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
             "Failed get_ranks_in_pair in mwd_coarse::run %s",
             mss::c_str(i_target));

    // Gets the patterns to use
    FAPI_TRY(mss::lrdimm_training_pattern(mss::find_target<fapi2::TARGET_TYPE_MCS>(i_target), l_patterns));

    // Loop through all ranks
    for(const auto l_rank : l_ranks)
    {
        // Skip any ranks that are no rank (they don't exist)
        // Skip over invalid ranks (NO_RANK)
        if(l_rank == NO_RANK)
        {
            FAPI_DBG("%s RP%u single rank is being skipped as it's not configured (%u)",
                     mss::c_str(i_target), i_rp, l_rank);
            continue;
        }

        // Gets the DIMM from the rank
        FAPI_DBG("%s RP%u is calibrating rank%u",
                 mss::c_str(i_target), i_rp, l_rank);

        // Gets the DIMM rank - we need this to ID what function spaces and control words to use
        const auto l_dimm_rank = mss::index(l_rank);

        // Creates our structure of data for the recorders
        std::vector<std::pair<coarse_recorder, coarse_recorder>> l_results(MAX_LRDIMM_BUFFERS);

        // Gets our DIMM from this rank
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
        FAPI_TRY(mss::rank::get_dimm_target_from_rank(i_target, l_rank, l_dimm),
                 "%s failed to get DIMM from rank%u", mss::c_str(i_target), l_dimm_rank);

        // Setup per-lane compare for MWD
        // 1) Configure the compare output on a per-bit level (each bit returns 0/1, rather than each nibble)
        FAPI_TRY(lrdimm::set_training_level(l_dimm, lrdimm::training_level::BIT), "%s failed set_per_lane_level rank %u",
                 mss::c_str(l_dimm), l_dimm_rank);

        // 2) set the rank presence
        FAPI_TRY(set_rank_presence(l_dimm, generate_rank_presence(l_rank)),
                 "%s failed set rank%u",
                 mss::c_str(l_dimm), l_rank);

        // 3) Buffer into MWD mode
        FAPI_TRY(set_buffer_training(l_dimm, ddr4::MWD), "%s failed set_buffer_training rank%u", mss::c_str(l_dimm),
                 l_dimm_rank);

        // For all delays
        for(uint8_t l_delay = 0; l_delay < NUM_DELAYS; ++l_delay)
        {
            // Set delay (broadcast across rank)
            // 4) Setup our delays across the buffer
            FAPI_TRY(set_delay(l_dimm, l_dimm_rank, l_delay), "%s rank%u failed set_delay delay:%u", mss::c_str(l_dimm),
                     l_dimm_rank, l_delay);

            // Loop over all patterns
            for(uint8_t l_pattern_num = 0; l_pattern_num < NUM_LRDIMM_TRAINING_PATTERNS; ++l_pattern_num)
            {
                // 5) Setup data pattern in the buffer MPR regs
                FAPI_TRY(lrdimm::set_expected_mpr_pattern(l_dimm, l_patterns[l_pattern_num]),
                         "%s failed set_expect_mpr_pattern rank%u, pattern%u",
                         mss::c_str(l_dimm), l_dimm_rank, l_patterns[l_pattern_num]);

                // Conduct a WR/RD
                // Write sends data from the buffer MPR
                // 6) Read reads back what was written and does a bitwise compare
                FAPI_TRY(conduct_write_read(l_dimm, l_rank), "%s rank%u failed conduct_write_read", mss::c_str(l_dimm),
                         l_dimm_rank);

                // 7) Conduct an NTTM mode read
                FAPI_TRY(execute_nttm_mode_read(i_target), "%s rank%u failed execute_nttm_mode_read", mss::c_str(l_dimm), l_dimm_rank);

                // 8) Analyze results
                FAPI_TRY(analyze_results(l_dimm, l_dimm_rank, l_delay, l_results), "%s rank%u failed process_results",
                         mss::c_str(i_target), l_dimm_rank);
            }
        }

        // 9) Buffer out of training mode
        FAPI_TRY(set_buffer_training(l_dimm, ddr4::NORMAL), "%s failed set_buffer_training rank%u", mss::c_str(l_dimm),
                 l_dimm_rank);

        // 10) Analyze the results across the whole buffer
        FAPI_TRY(find_final_results(l_dimm, l_dimm_rank, l_results), "%s rank%u failed find_final_results", mss::c_str(l_dimm),
                 l_dimm_rank);

        // 11) Write the results into the buffer on a per-buffer basis
        FAPI_TRY(set_final_delays(l_dimm, l_dimm_rank, l_results), "%s rank%u failed set_final_delays", mss::c_str(l_dimm),
                 l_dimm_rank);
    }

    // 12) set for two or four rank dimms
    for (const auto& l_dimm : l_dimms)
    {
        uint8_t l_rank_num = 0;
        FAPI_TRY( eff_num_master_ranks_per_dimm(l_dimm, l_rank_num) );
        FAPI_TRY(set_rank_presence(l_dimm, generate_rank_presence_value(l_rank_num)));
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
fapi2::ReturnCode mwd_coarse::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    // Add in set FIFO OFF
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
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t mwd_coarse::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

} // ns lrdimm

} // ns training

} // ns mss
