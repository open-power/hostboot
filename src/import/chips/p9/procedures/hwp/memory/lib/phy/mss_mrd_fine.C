/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_mrd_fine.C $ */
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
/// @file lib/phy/mss_mrd_fine.C
/// @brief MRD coarse LRDIMM training step
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

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
#include <lib/phy/mss_mrd_fine.H>
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
fapi2::ReturnCode mrd_fine::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    FAPI_INF("MRD_FINE %s setting up the read pointer enable rp%u", mss::c_str(i_target), i_rp);
    FAPI_TRY( mss::setup_read_pointer_delay(i_target));

    // call function to force DQ capture in Read FIFO to support DDR4 LRDIMM calibration.
    FAPI_TRY( mss::dp16::write_force_dq_capture(i_target, mss::states::ON),
              "%s failed to write force dq capture", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes the post-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode mrd_fine::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
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
/// @brief find eye size and delay value for one dq
/// @param[in] i_bit dq number
/// @param[out] o_delay mid point of eye
/// @param[out] o_eye_size eye size
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode mrd_fine::recorder::find_eye_size_and_delay(const uint64_t i_bit,
        uint16_t& o_delay,
        uint16_t& o_eye_size) const
{
    // Ensure that the bit is within the range (programming error otherwise)
    // TODO:RTC200369 Update MRD_FINE for RAS
    if(i_bit >= MAX_DQ_BITS)
    {
        FAPI_ERR("bit%u is out of range of the maximum number of bits %u", i_bit, MAX_DQ_BITS);
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    {
        // Gets our current bit
        const auto l_it = l_results.begin() + i_bit;
        std::vector<std::pair<uint16_t, uint16_t>> l_delay_eyes;
        uint16_t l_left_edge = 0;
        uint16_t l_right_edge = 0;

        // If we have a case where we had a compare on our 0'th delay, we want to mark that as our left edge of the eye
        // So, seen0 needs to be initialized to the result from the test of our 0'th delay
        bool l_seen0 = l_it->getBit(0);
        bool l_seen1 = false;
        bool l_found_left_edge = false;
        bool l_found_right_edge = false;

        // Loops through all of the delays and assembles a vector of the eyes
        // The vector contains a pair and has the left and right edge noted
        for(uint16_t l_delay = 0; l_delay < MRD_MAX_DELAY; l_delay++)
        {
            // We've found that we're at a 0 (miscompare)
            if(l_it->getBit(l_delay) == false)
            {
                l_seen0 = true;

                // We're at a 0 now, and if we've found a 1 prior (1->0) transition
                // And have not found a right edge, so note that we've found a right edge and set the delay
                if((l_seen1 == true) && (l_found_right_edge == false))
                {
                    // Right edge is our current delay - 1
                    // This is the last time we saw a compare on the eye
                    l_right_edge = l_delay - 1;
                    l_found_right_edge = true;

                }

                l_seen1 = false;
            }

            // We've found that we're at a 1 (compare)
            if(l_it->getBit(l_delay) == true)
            {
                l_seen1 = true;

                // We're at a 1, have found a 0 prior (so 0->1 transition)
                // and not have a left edge, so note that we've found a left edge and set the delay
                if(l_seen0 == true && l_found_left_edge == false)
                {
                    l_left_edge = l_delay;
                    l_found_left_edge = true;
                }

                l_seen0 = false;
            }

            // If we've found a left and a right edge, then we've found an eye, so note it as such
            // We should always find our right edge after our first edge, set seen0 to true
            if(l_found_left_edge && l_found_right_edge)
            {
                l_delay_eyes.push_back({l_left_edge, l_right_edge});
                l_found_left_edge = l_found_right_edge = false;
                l_seen0 = true;
                l_seen1 = false;
            }
        }

        // If we have a case where we pass at the maximum delay, then add in an eye there
        if(l_found_left_edge && !l_found_right_edge)
        {
            l_delay_eyes.push_back({l_left_edge, MRD_MAX_DELAY - 1});
        }


        // Loops through and finds the best case eye
        uint16_t l_eye_size = 0;
        uint16_t l_mid_delay = 0;

        for(const auto& l_delay_eye : l_delay_eyes)
        {
            // Our eye size is our right minus our left edge
            const auto l_cur_eye_size = l_delay_eye.second - l_delay_eye.first;

            if(l_eye_size < l_cur_eye_size)
            {
                l_eye_size = l_cur_eye_size;

                // Our setpoint for the eye is the average of our left and right edges
                l_mid_delay = (l_delay_eye.second + l_delay_eye.first) / 2;
            }
        }

        // Checks error cases here
        // TODO:RTC200369 Update MRD_FINE for RAS

        // First error case, we never found a passing region, so our eye size is 0
        if(l_eye_size == 0)
        {
            FAPI_ERR("bit%u never found a passing region! results 0x%08x", i_bit, *l_it);
        }


        // Second error case: no failing region
        if(l_eye_size == MRD_MAX_DELAY)
        {
            FAPI_ERR("bit%u never found a failing region! results 0x%08x", i_bit, *l_it);
        }

        FAPI_DBG("bit%u found %u eyes. best case eye size%u with setpoint delay of %u from data 0x%08x",
                 i_bit, l_delay_eyes.size(), l_eye_size, l_mid_delay, *l_it);

        o_delay = l_mid_delay;
        o_eye_size = l_eye_size;
    }

    return fapi2::FAPI2_RC_SUCCESS;

}

///
/// @brief convert loop value to register definition for nibble
/// @param[in] i_delay the value to convert
/// @return the value after convert
/// @note BCW F[0:3]BC4x,F[0:3]BC5x
///
uint8_t mrd_fine::convert_loop_value_to_register_definition_nibble( const uint8_t& i_delay) const
{
    return (i_delay < 15) ? (31 - i_delay) : (i_delay - 15);
}

///
/// @brief Sets MRD_FINE Delay value
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank to operate on - drives the function space select
/// @param[in] delay value /64 Tck - MRD_FINE delay value on a per-nibble basis
/// @return FAPI2_RC_SUCCESS if okay
/// @note Sets up the MRD_FINE delay values in buffer control word (F[3:0]BC4x, F[3:0]BC5x)
///
fapi2::ReturnCode mrd_fine::set_delay(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const uint8_t i_rank,
                                      const uint8_t i_delay ) const
{
    constexpr uint8_t NIBBLE0_BCW_NUMBER = 0x04;
    constexpr uint8_t NIBBLE1_BCW_NUMBER = 0x05;
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    //adjust delay value to map register definition
    // the value 0..15 corresponds to -15/64..0/64 while 15..30 corresponds to 0/64..15/64
    uint8_t l_delay_register = convert_loop_value_to_register_definition_nibble(i_delay);
    // Devon and Stephen will need to verify the command delay here
    // Note: the function space corresponds to the rank we passed in
    std::vector<cw_info> l_bcws =
    {
        {i_rank, NIBBLE0_BCW_NUMBER, l_delay_register, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {i_rank, NIBBLE1_BCW_NUMBER, l_delay_register, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
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
/// @brief Analyze mrd_fine result
/// @param[in] i_target the MCA target
/// @param[in] i_delay delay value /64 Tck - MRD_FINE delay value
/// @param[in] i_data dq values
/// @param[in,out] io_recorders dq value for all DQs and all delays
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode mrd_fine::analyze_mrd_result_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint8_t i_delay,
        const data_response i_data,
        recorder& io_recorders) const
{
    // Now, looop through all of the DQ and analyze the results on a per DQ basis
    for(uint8_t l_dq = 0; l_dq < MAX_DQ_BITS; l_dq++)
    {

        // All beats should be the same, until proven otherwise, just use beat 0
        // We'll want to see this on the LA and verify it - SPG
        constexpr uint64_t DEFAULT_BEAT = 0;

        // Compute the buffer number for this DQ - used to get the data that we need to compare against
        const auto l_buffer = l_dq / MAX_DQ_PER_BUFFER;

        // Compute the DQ's relative position in the buffer - used for a getBit on that data
        const auto l_relative_dq = l_dq % MAX_DQ_PER_BUFFER;


        const fapi2::buffer<uint8_t> l_buffer_result(i_data.iv_buffer_beat[l_buffer][DEFAULT_BEAT]);
        const bool l_dq_result = l_buffer_result.getBit(l_relative_dq);


        FAPI_DBG("%s delay:0x%02x MRD_FINE result buffer %u result 0x%02x, dq %u result %u ",
                 mss::c_str(i_target), i_delay, l_dq / MAX_DQ_PER_BUFFER, uint8_t(l_buffer_result), l_dq, l_dq_result);

        FAPI_TRY(io_recorders.add_results(l_dq, i_delay, l_dq_result));

    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Analyze mrd_fine result
/// @param[in] i_target the MCA target
/// @param[in] i_delay delay value /64 Tck - MRD_FINE delay value
/// @param[in] io_recorders dq value for all DQs and all delays
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode mrd_fine::analyze_mrd_result( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint8_t i_delay,
        recorder& io_recorders) const
{
    // Reads out the data results from the MRD_FINE
    data_response l_data;
    static constexpr uint64_t MAX_NUM_BEATS = 8;
    FAPI_TRY(l_data.read(i_target), "%s failed to read MRD_FINE data response delay:0x%02x", mss::c_str(i_target), i_delay);

    // Displays all of the data here - just.in.case.
    for(uint8_t l_buffer_loop = 0; l_buffer_loop < MAX_LRDIMM_BUFFERS; ++l_buffer_loop)
    {
        for(uint8_t i = 0; i < MAX_NUM_BEATS; ++i)
        {
            FAPI_DBG("%s delay:0x%02x MRD_FINE result buffer%u BEAT%u data:0x%02x",
                     mss::c_str(i_target), i_delay, l_buffer_loop, i, l_data.iv_buffer_beat[l_buffer_loop][i]);
        }
    }

    FAPI_TRY(analyze_mrd_result_helper(i_target, i_delay, l_data, io_recorders));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief find best delay for one nibble
/// @param[in] i_recorder mrd_fine training recorder for each delay
/// @param[in] i_buffer the buffer number
/// @param[in] i_nibble the nibble number
/// @param[in,out] io_eye_sizes_dq a vector of eye size for all dq
/// @param[out] o_final_nibble_delays_buffer  the best delay value of one nibble and all dq
/// @return FAPI2_RC_SUCCESS if and only if ok
//
fapi2::ReturnCode mrd_fine::find_best_delay_for_nibble( const recorder& i_recorder,
        const uint64_t i_buffer,
        const uint64_t i_nibble,
        std::vector<uint16_t>& io_eye_sizes_dq,
        final_nibble_delay& o_final_nibble_delays_buffer)const
{
    constexpr int8_t MIN_DQ_OFFSET = -3;
    constexpr int8_t MAX_DQ_OFFSET =  3;
    // Error checks here - we don't want anything out of bounds

    const auto l_dq_start = i_buffer * MAX_DQ_PER_BUFFER + i_nibble * BITS_PER_NIBBLE;
    const auto l_dq_end = l_dq_start + BITS_PER_NIBBLE;

    uint16_t l_best_delays[BITS_PER_NIBBLE] = {};
    uint64_t l_index = 0;
    uint16_t l_nibble_average = 0;

    // Loops through all of the DQ in this nibble
    for(uint64_t l_dq = l_dq_start; l_dq < l_dq_end; ++l_dq)
    {
        FAPI_TRY(i_recorder.find_eye_size_and_delay(l_dq, l_best_delays[l_index], io_eye_sizes_dq[l_dq]));

        l_nibble_average += l_best_delays[l_index];
        l_index++;
    }

    // Computes the final set point for the nibble
    o_final_nibble_delays_buffer.iv_nibble_delay = (l_nibble_average / BITS_PER_NIBBLE);

    // Now computes all of the per bit offsets
    for(l_index = 0; l_index < BITS_PER_NIBBLE; ++l_index)
    {
        // Computes the offset
        o_final_nibble_delays_buffer.iv_offset[l_index] = l_best_delays[l_index] - o_final_nibble_delays_buffer.iv_nibble_delay;

        // Now limits the offset to be in range - we can't be below the minimum value..
        o_final_nibble_delays_buffer.iv_offset[l_index] = std::max(MIN_DQ_OFFSET,
                o_final_nibble_delays_buffer.iv_offset[l_index]);

        // We can't be above the maximum value
        o_final_nibble_delays_buffer.iv_offset[l_index] = std::min(MAX_DQ_OFFSET,
                o_final_nibble_delays_buffer.iv_offset[l_index]);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief find best delay for each DQ
/// @param[in] i_recorder mrd_fine training recorder for each delay
/// @param[in,out] io_eye_sizes_dq a vector of eye size for all dq
/// @param[in,out] io_final_nibble_delays_buffer a vector of the MRD_FINE results
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrd_fine::find_best_delay_for_each_dq( const recorder& i_recorder,
        std::vector<uint16_t>& io_eye_sizes_dq,
        std::vector<std::pair<final_nibble_delay, final_nibble_delay>>& io_final_nibble_delays_buffer) const
{
    constexpr uint8_t NIBBLE0 = 0x0;
    constexpr uint8_t NIBBLE1 = 0x1;
    uint64_t l_buffer = 0;

    for(auto& l_buffer_final_delays : io_final_nibble_delays_buffer)
    {
        FAPI_TRY(find_best_delay_for_nibble(i_recorder, l_buffer, NIBBLE0, io_eye_sizes_dq, l_buffer_final_delays.first));
        FAPI_TRY(find_best_delay_for_nibble(i_recorder, l_buffer, NIBBLE1, io_eye_sizes_dq, l_buffer_final_delays.second));
        ++l_buffer;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Converts per bit offset to register value
/// @param[in] i_delay the value to convert
/// @return the value after convert
/// @note F[4:7]BC8x F[4:7]BC9x F[4:7]BCAx F[4:7]BCBx
///
uint8_t mrd_fine::convert_delay_dq( const int8_t& i_delay) const
{

    return (i_delay >= 0) ? i_delay : (4 - i_delay);

}
///
/// @brief convert loop value to register definition for DQ
/// @param[in] i_target the port on which we are operating
/// @param[in] i_final_buffer_delay a pair variable for 8 dq offset delay of one buffer
/// @param[in] i_buffer the buffer on which we are operating
/// @param[out] io_bcw_bc8x_setting register F[4:7]BC8x setting
/// @param[out] io_bcw_bc9x_setting register F[4:7]BC9x setting
/// @param[out] io_bcw_bcax_setting register F[4:7]BCAx setting
/// @param[out] io_bcw_bcbx_setting register F[4:7]BCBx setting
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note F[4:7]BC8x F[4:7]BC9x F[4:7]BCAx F[4:7]BCBx
///
fapi2::ReturnCode mrd_fine::convert_loop_value_to_register_definition_dq(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    const std::pair<final_nibble_delay, final_nibble_delay>& i_final_buffer_delay,
    const uint64_t i_buffer,
    uint8_t& o_bcw_bc8x_setting,
    uint8_t& o_bcw_bc9x_setting,
    uint8_t& o_bcw_bcax_setting,
    uint8_t& o_bcw_bcbx_setting) const
{
    // Per Bit offsets need to have per bit swizzling
    // So, we end up setting up an array of bit values to make the assembly of individual control words easier
    uint8_t l_per_bit_offset[BITS_PER_BYTE] = {};

    // Sets up the helper array
    // Note we have a first/second pair, so only loop through one nibble
    const auto l_start = i_buffer * BITS_PER_BYTE;
    const auto l_end = l_start + BITS_PER_NIBBLE;

    for(uint64_t l_mc_dq = l_start; l_mc_dq < l_end; ++l_mc_dq)
    {
        const auto l_mc_nibble_dq = l_mc_dq % BITS_PER_NIBBLE;
        uint64_t l_nibble0_dq = 0;
        uint64_t l_nibble1_dq = 0;
        FAPI_TRY(mc_to_buffer(i_target, l_mc_dq, l_nibble0_dq));
        FAPI_TRY(mc_to_buffer(i_target, l_mc_dq + BITS_PER_NIBBLE, l_nibble1_dq));

        l_per_bit_offset[l_nibble0_dq] = convert_delay_dq(i_final_buffer_delay.first.iv_offset[l_mc_nibble_dq]);
        l_per_bit_offset[l_nibble1_dq] = convert_delay_dq(i_final_buffer_delay.second.iv_offset[l_mc_nibble_dq]);
    }

    o_bcw_bc8x_setting = l_per_bit_offset[0] | (l_per_bit_offset[4] << BITS_PER_NIBBLE) ;
    o_bcw_bc9x_setting = l_per_bit_offset[1] | (l_per_bit_offset[5] << BITS_PER_NIBBLE) ;
    o_bcw_bcax_setting = l_per_bit_offset[2] | (l_per_bit_offset[6] << BITS_PER_NIBBLE) ;
    o_bcw_bcbx_setting = l_per_bit_offset[3] | (l_per_bit_offset[7] << BITS_PER_NIBBLE) ;

    FAPI_DBG("%s buffer:%u made delays 0x%02x 0x%02x 0x%02x 0x%02x", mss::c_str(i_target), i_buffer, o_bcw_bc8x_setting,
             o_bcw_bc9x_setting, o_bcw_bcax_setting, o_bcw_bcbx_setting);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write the result to buffer
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank number
/// @param[in] i_final_nibble_delays_buffer a vector of the MRD_FINE results,pair for nibble0 and nibble1
/// @param[in,out] io_container pba command
/// @return FAPI2_RC_SUCCESS if and only if ok
//  @note Sets up buffer control word F[4:7]BC8x F[4:7]BC9x F[4:7]BCAx F[4:7]BCBx to for best delay of each dq
//        and F[0:3]BC4x,F[0:3]BC5x for best delay of each nibble
///
fapi2::ReturnCode mrd_fine::write_result_to_buffers_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<final_nibble_delay, final_nibble_delay>>& i_final_nibble_delays_buffer,
        mss::ddr4::pba::commands& io_container) const
{
    uint8_t l_buffer = 0;

    // Get's the MCA
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    for(const auto& l_best_delay : i_final_nibble_delays_buffer)
    {
        uint8_t l_bcw_delay_nibble0 = 0;
        uint8_t l_bcw_delay_nibble1 = 0;
        // 0~3 need set value 0~3 and  -1~-3 need set value 5~7
        uint8_t bcw_bc8x_setting = 0;
        uint8_t bcw_bc9x_setting = 0;
        uint8_t bcw_bcax_setting = 0;
        uint8_t bcw_bcbx_setting = 0;

        bool l_are_nibbles_swapped = false;
        FAPI_TRY(are_buffers_nibbles_swizzled(l_mca, l_buffer, l_are_nibbles_swapped));

        l_bcw_delay_nibble0 = l_are_nibbles_swapped ?
                              l_best_delay.second.iv_nibble_delay :
                              l_best_delay.first.iv_nibble_delay;
        l_bcw_delay_nibble1 = l_are_nibbles_swapped ?
                              l_best_delay.first.iv_nibble_delay :
                              l_best_delay.second.iv_nibble_delay;

        // Converts to the register setting
        l_bcw_delay_nibble0 = convert_loop_value_to_register_definition_nibble(l_bcw_delay_nibble0);
        l_bcw_delay_nibble1 = convert_loop_value_to_register_definition_nibble(l_bcw_delay_nibble1);

        // Function space is derived from the rank
        // 4 is for Nibble 0, 5 is for Nibble 1
        // Data corresponds to the final setting we have
        // Delay is for PBA, bumping it way out so we don't have issues
        constexpr uint64_t PBA_DELAY = 255;
        constexpr uint64_t BCW_NIBBLE0 = 0x04;
        constexpr uint64_t BCW_NIBBLE1 = 0x05;

        const mss::cw_info MRD_FINAL_SET_BCW_N0(i_rank,
                                                BCW_NIBBLE0,
                                                l_bcw_delay_nibble0,
                                                PBA_DELAY,
                                                mss::CW8_DATA_LEN,
                                                mss::cw_info::BCW);
        const mss::cw_info MRD_FINAL_SET_BCW_N1(i_rank,
                                                BCW_NIBBLE1,
                                                l_bcw_delay_nibble1,
                                                PBA_DELAY,
                                                mss::CW8_DATA_LEN,
                                                mss::cw_info::BCW);

        // Each buffer contains two nibbles
        // Each nibble corresponds to one BCW
        // Add in the buffer control words
        FAPI_TRY(io_container.add_command(i_target, l_buffer, MRD_FINAL_SET_BCW_N0));
        FAPI_TRY(io_container.add_command(i_target, l_buffer, MRD_FINAL_SET_BCW_N1));

        FAPI_TRY(convert_loop_value_to_register_definition_dq(l_mca,
                 l_best_delay,
                 l_buffer,
                 bcw_bc8x_setting,
                 bcw_bc9x_setting,
                 bcw_bcax_setting,
                 bcw_bcbx_setting));
        // Function space is derived from the rank
        // 2 is for Nibble 0, 3 is for Nibble 1
        // Data corresponds to the final setting we have
        // Delay is for PBA, bumping it way out so we don't have issues
        constexpr uint64_t RANK_SHIFT = 4;
        constexpr uint64_t BCW_DQ0 = 0x08;
        constexpr uint64_t BCW_DQ1 = 0x09;
        constexpr uint64_t BCW_DQ2 = 0x0a;
        constexpr uint64_t BCW_DQ3 = 0x0b;

        // TK make this a function?
        const mss::cw_info MRD_FINAL_SET_BCW_DQ0_DQ4(i_rank + RANK_SHIFT,
                BCW_DQ0,
                bcw_bc8x_setting,
                PBA_DELAY,
                mss::CW8_DATA_LEN,
                mss::cw_info::BCW);
        const mss::cw_info MRD_FINAL_SET_BCW_DQ1_DQ5(i_rank + RANK_SHIFT,
                BCW_DQ1,
                bcw_bc9x_setting,
                PBA_DELAY,
                mss::CW8_DATA_LEN,
                mss::cw_info::BCW);
        const mss::cw_info MRD_FINAL_SET_BCW_DQ2_DQ6(i_rank + RANK_SHIFT,
                BCW_DQ2,
                bcw_bcax_setting,
                PBA_DELAY,
                mss::CW8_DATA_LEN,
                mss::cw_info::BCW);
        const mss::cw_info MRD_FINAL_SET_BCW_DQ3_DQ7(i_rank + RANK_SHIFT,
                BCW_DQ3,
                bcw_bcbx_setting,
                PBA_DELAY,
                mss::CW8_DATA_LEN,
                mss::cw_info::BCW);
        // Each buffer contains two nibbles
        // Each nibble corresponds to one BCW
        // Add in the buffer control words
        FAPI_TRY(io_container.add_command(i_target, l_buffer, MRD_FINAL_SET_BCW_DQ0_DQ4));
        FAPI_TRY(io_container.add_command(i_target, l_buffer, MRD_FINAL_SET_BCW_DQ1_DQ5));
        FAPI_TRY(io_container.add_command(i_target, l_buffer, MRD_FINAL_SET_BCW_DQ2_DQ6));
        FAPI_TRY(io_container.add_command(i_target, l_buffer, MRD_FINAL_SET_BCW_DQ3_DQ7));
        ++l_buffer;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write the result to buffer
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank number
/// @param[in] i_final_nibble_delays_buffer a vector of the MRD_FINE results,pair for nibble0 and nibble1
/// @return FAPI2_RC_SUCCESS if and only if ok
//  @note Sets up buffer control word F[4:7]BC8x F[4:7]BC9x F[4:7]BCAx F[4:7]BCBx to for best delay of each dq
//        and F[0:3]BC4x,F[0:3]BC5x for best delay of each nibble
///
fapi2::ReturnCode mrd_fine::write_result_to_buffers( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<final_nibble_delay, final_nibble_delay>>& i_final_nibble_delays_buffer) const
{
    mss::ddr4::pba::commands l_container;

    FAPI_TRY(write_result_to_buffers_helper(i_target, i_rank, i_final_nibble_delays_buffer, l_container));

    // Issue the PBA to set the final MREP results
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
fapi2::ReturnCode mrd_fine::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                 const uint64_t i_rp,
                                 const uint8_t i_abort_on_error ) const
{
    // Taken from page 35 of the specification
    constexpr uint8_t MPR_LOCATION0 = 0;
    std::vector<uint64_t> l_ranks;
    uint8_t l_rank_index = 0;
    recorder l_recorder;
    constexpr uint8_t l_pattern = 0x2B;

    FAPI_INF("%s RP%d starting to try to calibrate MRD_FINE", mss::c_str(i_target), i_rp);

    const auto& l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target);

    // 1) Sets up the minimum eye sizes vector for this loop
    // Note: this is for the RD VREF training and is on a per-buffer basis (not per-rank, not per-nibble, but per-buffer)
    setup_minimum_eye_sizes();

    // 2) Do an initial pattern write to setup the MPR pattern we want to test - use configure custom pattern + initial_pattern_write
    // Will need to discuss patterns (and experiment to find the best ones), probably start off w/ 01 alternating
    FAPI_TRY(mpr_pattern_wr_all_ranks(i_target, i_rp, 0x2b2b2b2b),
             "%s failed setup_mpr_pattern ", mss::c_str(i_target));

    // Get the ranks in this rankpair and loop across all of the ranks
    FAPI_TRY(mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
             "Failed get_ranks_in_pair in mrd_fine::run %s",
             mss::c_str(i_target));

    for(const auto l_rank : l_ranks)
    {
        FAPI_INF("%s RP%u l_rank:%u", mss::c_str(i_target), i_rp, l_rank);
    }

    // Loops over all ranks within this rank pair
    // MRD_FINE is a buffer to DRAM calibration step, so we need to calibrate all ranks seperately
    for (const auto& l_rank : l_ranks)
    {
        // Skip over invalid ranks (NO_RANK)
        if(l_rank == NO_RANK)
        {
            FAPI_DBG("%s RP%u l_rank_index:%u is being skipped as it's not configured (%u)",
                     mss::c_str(i_target), i_rp, l_rank_index, l_rank);
            ++l_rank_index;
            continue;
        }

        // Gets the DIMM per RP
        const auto& l_dimm = l_dimms[mss::rank::get_dimm_from_rank(l_rank)];

        // Initialize the results information that we will store across this rank
        std::vector<uint16_t> l_eye_sizes_dq(MAX_DQ_BITS);
        std::vector<std::pair<final_nibble_delay, final_nibble_delay>> l_final_nibble_delays_buffer(MAX_LRDIMM_BUFFERS);

        // 3) Write the expected MPR pattern to the data buffers - host issues BCW commands to buffers (cw_info)
        FAPI_TRY(lrdimm::set_expected_mpr_pattern(l_dimm, l_pattern), "%s failed set_expected_mpr_pattern rank%u, pattern%u",
                 mss::c_str(l_dimm), l_rank, l_pattern);

        // 4) Configure the compare output on a per-bit level (each bit returns 0/1, rather than each nibble)
        FAPI_TRY(lrdimm::set_training_level(l_dimm, lrdimm::training_level::BIT), "%s failed set_per_lane_level rank%u",
                 mss::c_str(l_dimm), l_rank);

        // 5) Put the buffer into MRD_FINE training mode - host issues BCW commands
        FAPI_TRY(set_buffer_training(l_dimm, ddr4::MRD), "%s failed set_buffer_training", mss::c_str(l_dimm));

        // 6) Puts this DIMM rank into MPR mode
        FAPI_TRY( mpr_load(l_dimm, fapi2::ENUM_ATTR_EFF_MPR_MODE_ENABLE, l_rank), "%s failed mpr_load rank%u",
                  mss::c_str(l_dimm), l_rank);

        // Loop across all delays
        // Note: I think it will be easier if we have a conversion from this loop to the buffer value delays and back
        // So, 0 for this loop corresponds to -15/64 while +31 corresponds to 15/64
        for(uint8_t l_delay = 0; l_delay < MRD_MAX_DELAY; l_delay++)
        {
            // 7) Sets the delay across all buffers, all nibbles - host issues BCW commands to buffers (cw_info)
            FAPI_TRY(set_delay(l_dimm, l_rank, l_delay),
                     "%s failed set_delay rank%u delay%u", mss::c_str(l_dimm), l_rank, l_delay);
            // 8) Issues the MPR read
            FAPI_TRY( mpr_read(l_dimm, MPR_LOCATION0, l_rank), "%s failed mpr_read rank%u delay%u",
                      mss::c_str(l_dimm), l_rank, l_delay);

            // 8.1) add in NTTM mode read here - >forces the logic to read out the data
            FAPI_TRY(execute_nttm_mode_read(i_target));

            // 9) Analyzes the results
            FAPI_TRY(mrd_fine::analyze_mrd_result(i_target, l_delay, l_recorder), "%s failed analyze_mrd_result rank%u delay%u",
                     mss::c_str(l_dimm), l_rank, l_delay);
        }

        // 10) Finds the best delay for each bit
        // Note: also updates the minimum eye size vector here
        FAPI_TRY( find_best_delay_for_each_dq(l_recorder, l_eye_sizes_dq, l_final_nibble_delays_buffer),
                  "%s failed found_best_delay_for_each_dq %u", mss::c_str(l_dimm),
                  l_rank);

        // 11) Takes this rank out of MPR mode
        FAPI_TRY( mpr_load(l_dimm, fapi2::ENUM_ATTR_EFF_MPR_MODE_DISABLE, l_rank), "%s failed mpr_load %u", mss::c_str(l_dimm),
                  l_rank);
        // 12) Takes the buffer out of MRD_FINE and sets it into mainline mode
        FAPI_TRY(set_buffer_training(l_dimm, ddr4::NORMAL), "%s failed set_buffer_training", mss::c_str(l_dimm));

        // 13) Writes the best delays to the buffers using PBA
        FAPI_TRY( mrd_fine::write_result_to_buffers( l_dimm, l_rank, l_final_nibble_delays_buffer),
                  "%s failed write_result_to_buffers %u", mss::c_str(l_dimm), l_rank);

    }//rank loop

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t mrd_fine::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

} // ns training

} // ns lrdimm

} // ns mss
