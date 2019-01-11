/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training_helper.C $ */
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
/// @file lib/phy/mss_lrdimm_training.C
/// @brief LRDIMM training implementation
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

#ifdef LRDIMM_CAPABLE
    #include <lib/phy/mss_lrdimm_training_helper.H>
#endif

namespace mss
{

namespace training
{

namespace lrdimm
{

///
/// @brief Sets the comparison on a per-nibble or per-bit level
/// @param[in] i_target the DIMM target
/// @param[in] i_training_level the buffer's training level
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up buffer control word F6BC4x to do compares on a per-bit level
///
fapi2::ReturnCode set_training_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint64_t i_training_level)
{
    // Values taken from the JEDEC spec
    constexpr uint64_t TRAINING_LEVEL_POS = 7;
    constexpr uint64_t TRAINING_LEVEL_LEN = 1;

    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    fapi2::buffer<uint8_t> l_bcw_value;
    std::vector<cw_info> l_bcws;
    uint8_t l_sim = 0;

    // Gets the BCW value for the buffer training control word
    FAPI_TRY(eff_dimm_ddr4_f6bc4x(i_target, l_bcw_value));

    // Modifies the BCW value accordingly
    l_bcw_value.insertFromRight<TRAINING_LEVEL_POS, TRAINING_LEVEL_LEN>(i_training_level);
    l_bcws.push_back(cw_info(FUNC_SPACE_6, BUFF_TRAIN_CONFIG_CW, l_bcw_value, mss::tmrc(), mss::CW8_DATA_LEN,
                             cw_info::BCW));

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
    return fapi2::current_err;
}

///
/// @brief Sets preamble mode enable or disable
/// @param[in] i_target the DIMM target
/// @param[in] i_mode preamble mode enable or disable
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up buffer control word F0BC1x to do preamble mode enable or disable
///
fapi2::ReturnCode set_buffer_rd_preamble_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const bool i_mode)
{
    // Values taken from the JEDEC spec
    constexpr uint64_t PREAMBLE_MODE_POS = 3;
    constexpr uint64_t PREAMBLE_MODE_LEN = 1;

    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    fapi2::buffer<uint8_t> l_bcw_value;
    std::vector<cw_info> l_bcws;
    uint8_t l_sim = 0;

    // Gets the BCW value for the buffer training control word
    FAPI_TRY(eff_dimm_ddr4_f0bc1x(i_target, l_bcw_value));

    // Modifies the BCW value accordingly
    l_bcw_value.insertFromRight<PREAMBLE_MODE_POS, PREAMBLE_MODE_LEN>(i_mode);
    l_bcws.push_back(cw_info(FUNC_SPACE_0, BUFF_CONFIG_CW, l_bcw_value, mss::tmrc(), mss::CW8_DATA_LEN,
                             cw_info::BCW));

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
    return fapi2::current_err;
}

///
/// @brief Enter read preamble training mode
/// @param[in] i_target the DIMM target
/// @param[in] i_mode mode value 0/1
/// @param[in,out] io_inst the instruction to fixup
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets MR4 A10 for read preamble training mode
///
fapi2::ReturnCode set_dram_rd_preamble_mode_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_mode,
        const uint64_t i_rank,
        std::vector<ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>>& io_inst)
{
    // Enter rank into read preamble training mode
    fapi2::ReturnCode l_rc;
    mss::ddr4::mrs04_data l_data(i_target, l_rc);
    FAPI_TRY(l_rc, "%s. Failed to initialize mrs04_data for mpr_load", mss::c_str(i_target) );

    l_data.iv_rd_pre_train_mode = i_mode;

    FAPI_TRY( mrs_engine(i_target, l_data, i_rank, mss::tmod(i_target), io_inst),
              "Failed to send MRS04 on %s, rank: %d, delay (in cycles): %d",
              mss::c_str(i_target), i_rank, mss::tmod(i_target));

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Enter read preamble training mode
/// @param[in] i_target the DIMM target
/// @param[in] i_mode mode value 0/1
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets MR4 A10 for read preamble training mode
///
fapi2::ReturnCode set_dram_rd_preamble_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_mode,
        const uint64_t i_rank)
{

    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    set_dram_rd_preamble_mode_helper(i_target, i_mode, i_rank, l_program.iv_instructions);

    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the set_rank_presence operations
/// @param[in] i_target a DIMM target
/// @param[in] i_rank the rank target on which to operate
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode set_rank_presence( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint8_t i_rank)
{
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    uint8_t l_sim = 0;
    FAPI_TRY(mss::is_simulation(l_sim));

    static const std::vector< cw_info > l_bcw_info =
    {

        { FUNC_SPACE_0,  RANK_PRESENCE_CW, i_rank,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
    };

    // DES first - make sure those CKE go high and stay there
    l_program.iv_instructions.push_back(mss::ccs::des_command<fapi2::TARGET_TYPE_MCBIST>());

    // Issues the CW's
    FAPI_TRY( control_word_engine(i_target, l_bcw_info, l_sim, l_program.iv_instructions),
              "%s Failed control_word_engine", mss::c_str(i_target) );

    // Now, hold the CKE's high, so we don't power down the RCD and re power it back up
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    // Issue CCS
    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Creates the control words to set the expected MPR pattern into the buffer
/// @param[in] i_pattern the pattern to program into the buffer
/// @return cw_info vector containing the control words used to setup the MPR pattern into the buffer
/// @note Sets up the expected data pattern in buffer control words (F5BC0x,F5BC1x,F5BC2x,F5BC3x, F6BC0x,F6BC1x,F6BC2x,F6BC3x)
///
std::vector<cw_info> set_expected_mpr_pattern(const fapi2::buffer<uint8_t>& i_pattern )
{
    // BCW numbers
    constexpr uint8_t UI0_BCW_NUMBER = 0x0;
    constexpr uint8_t UI1_BCW_NUMBER = 0x1;
    constexpr uint8_t UI2_BCW_NUMBER = 0x2;
    constexpr uint8_t UI3_BCW_NUMBER = 0x3;
    constexpr uint8_t UI4_BCW_NUMBER = 0x0;
    constexpr uint8_t UI5_BCW_NUMBER = 0x1;
    constexpr uint8_t UI6_BCW_NUMBER = 0x2;
    constexpr uint8_t UI7_BCW_NUMBER = 0x3;

    // Pattern being converted into BCW values
    const uint8_t UI0_DATA = i_pattern.getBit<0>() ? 0xFF : 0x00;
    const uint8_t UI1_DATA = i_pattern.getBit<1>() ? 0xFF : 0x00;
    const uint8_t UI2_DATA = i_pattern.getBit<2>() ? 0xFF : 0x00;
    const uint8_t UI3_DATA = i_pattern.getBit<3>() ? 0xFF : 0x00;
    const uint8_t UI4_DATA = i_pattern.getBit<4>() ? 0xFF : 0x00;
    const uint8_t UI5_DATA = i_pattern.getBit<5>() ? 0xFF : 0x00;
    const uint8_t UI6_DATA = i_pattern.getBit<6>() ? 0xFF : 0x00;
    const uint8_t UI7_DATA = i_pattern.getBit<7>() ? 0xFF : 0x00;
    std::vector<cw_info> l_bcws =
    {
        {FUNC_SPACE_5, UI0_BCW_NUMBER, UI0_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_5, UI1_BCW_NUMBER, UI1_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_5, UI2_BCW_NUMBER, UI2_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_5, UI3_BCW_NUMBER, UI3_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_6, UI4_BCW_NUMBER, UI4_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_6, UI5_BCW_NUMBER, UI5_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_6, UI6_BCW_NUMBER, UI6_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_6, UI7_BCW_NUMBER, UI7_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
    };

    return l_bcws;
}

///
/// @brief Sets expected mpr pattern into the buffer
/// @param[in] i_target the DIMM target
/// @param[in] i_pattern the pattern to program into the buffer
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up the expected data pattern in buffer control words (F5BC0x,F5BC1x,F5BC2x,F5BC3x, F6BC0x,F6BC1x,F6BC2x,F6BC3x)
///
fapi2::ReturnCode set_expected_mpr_pattern(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const fapi2::buffer<uint8_t>& i_pattern )
{
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // Creates the BW's for the given pattern
    auto l_bcws = set_expected_mpr_pattern(i_pattern);

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
    return fapi2::current_err;
}

///
/// @brief Get the results for loop
/// @param[in] i_target the DIMM target
/// @param[in] i_buffer the buffer to operate on
/// @param[in] i_nibble the nibble to operate on
/// @param[in] i_delay the delay value
/// @param[in] i_result_nibble the nibble result value to analyze
/// @param[in,out] io_invalid_data_count the invalid data count
/// @param[out] o_result_nibble_bool the bool result value
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode get_result_nibble_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_buffer,
        const uint8_t i_nibble,
        const uint8_t i_delay,
        const uint8_t i_result_nibble,
        uint64_t& io_invalid_data_count,
        bool& o_result_nibble_bool)
{
    switch(i_result_nibble)
    {
        case 0:
            o_result_nibble_bool = false;
            break;

        case 0xF0:
            o_result_nibble_bool = true;
            break;

        default:
            io_invalid_data_count++;
            o_result_nibble_bool = false;
            FAPI_DBG("%s buffer%u nibble%u has seen invalid data at delay 0x%02x data:0x%02x --count%u",
                     mss::c_str(i_target), i_buffer, i_nibble, i_delay, i_result_nibble, io_invalid_data_count);
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Get the results for loop
/// @param[in] i_target the DIMM target
/// @param[in] i_calibration the current calibration step - used for error logging
/// @param[in] i_delay the delay value
/// @param[in,out] io_loop_result the result for all delay
/// @param[in,out] io_results_recorder a vector of the DWL final results
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode get_result( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const uint64_t i_calibration,
                              const uint8_t i_delay,
                              mrep_dwl_result& io_loop_result,
                              std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& io_results_recorder)
{
    data_response l_data;
    // Get's the MCA
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    FAPI_TRY( l_data.read(l_mca),
              "%s failed to read data response delay:0x%02x",
              mss::c_str(l_mca),
              i_delay );

    for(uint8_t l_buffer = 0; l_buffer < MAX_LRDIMM_BUFFERS; ++l_buffer)
    {
        // All beats should be the same, until proven otherwise, just use beat 0
        constexpr uint64_t DEFAULT_BEAT = 0;
        constexpr uint8_t NIBBLE0 = 0;
        constexpr uint8_t NIBBLE1 = 1;
        const uint8_t l_buffer_result = l_data.iv_buffer_beat[l_buffer][DEFAULT_BEAT];
        const auto l_result_nibble0 = l_buffer_result & MASK_NIBBLE0;
        const auto l_result_nibble1 = (l_buffer_result & MASK_NIBBLE1) << BITS_PER_NIBBLE;
        bool l_result_nibble0_bool = false;
        bool l_result_nibble1_bool = false;

        FAPI_ASSERT(io_results_recorder.size() >= MAX_LRDIMM_BUFFERS,
                    fapi2::MSS_LRDIMM_RECORDER_SIZE_SMALL()
                    .set_TARGET(i_target)
                    .set_BUFFER(l_buffer),
                    "%s io_results_recorder size: %d smaller than MAX_LRDIMM_BUFFERS",
                    mss::c_str(i_target), io_results_recorder.size());

        auto l_it_recorder = io_results_recorder.begin() + l_buffer;

        FAPI_DBG( "%s delay:0x%02x result buffer:%u data:0x%02x N0:0x%02x N1:0x%02x, N0_result:%u, N1_result:%u",
                  mss::c_str(i_target), i_delay,
                  l_buffer, l_buffer_result,
                  l_result_nibble0, l_result_nibble1, l_result_nibble0_bool, l_result_nibble1_bool);

        FAPI_TRY(get_result_nibble_helper(i_target, l_buffer, NIBBLE0, i_delay, l_result_nibble0,
                                          l_it_recorder->first.iv_invalid_data_count, l_result_nibble0_bool));
        FAPI_TRY(get_result_nibble_helper(i_target, l_buffer, NIBBLE1, i_delay, l_result_nibble1,
                                          l_it_recorder->second.iv_invalid_data_count, l_result_nibble1_bool));

        FAPI_TRY(io_loop_result.add_results(i_target, i_calibration, l_buffer, i_delay, l_result_nibble0_bool,
                                            l_result_nibble1_bool));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief analyze with each nibble
/// @param[in] i_target the DIMM target
/// @param[in] i_calibration the current calibration step - used for error logging
/// @param[in] i_result_nibble the result need to analyze
/// @param[in] i_buffer the buffer number
/// @param[in] i_nibble the nibble number
/// @param[in, out] io_recorder we need to get and record
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode analyze_result_for_each_nibble( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_calibration,
        const fapi2::buffer<uint64_t>& i_result_nibble,
        const uint8_t i_buffer,
        const uint8_t i_nibble,
        mrep_dwl_recorder& io_recorder )
{
    constexpr uint8_t MIN_CONTINUE0_NUM = 6;
    constexpr uint8_t MIN_CONTINUE1_NUM = 6;
    constexpr uint8_t NO_TRANSITION_FOUND = 0xff;
    constexpr uint8_t TOLERANCE_NUMBER = 2;
    bool final_delay_found = false;
    uint8_t l_first_transition = NO_TRANSITION_FOUND;

    // for the 0->1 transition is in 0th delay
    io_recorder.iv_seen0 = i_result_nibble.getBit<0>() && (!(i_result_nibble.getBit < MREP_DWL_MAX_DELAY - 1 > ()));

    for(uint8_t l_delay = 0; l_delay < MREP_DWL_MAX_DELAY; l_delay++)
    {
        switch(i_result_nibble.getBit(l_delay))
        {
            case false:
                io_recorder.iv_seen0 = true;
                break;

            case true:

                // We need to see a 0 prior to a 1 for a 0 to 1 transition
                if(io_recorder.iv_seen0)
                {
                    io_recorder.iv_seen1 = true;
                }

                break;
        }

        // Record the 0->1 transition only if:
        // 1) we've seen a 0
        // 2) we've seen a 1
        // 3) if find 0->1 transition, need check  5 delay before this point get 0 and after this point , more than 3 delay get 1

        if( (io_recorder.iv_seen0 == true) &&
            (io_recorder.iv_seen1 == true) &&
            (final_delay_found == false) )
        {

            uint8_t l_continue0 = 0;
            uint8_t l_continue1 = 0;

            // record first transition regardless of before/after
            if(l_first_transition == NO_TRANSITION_FOUND)
            {
                l_first_transition = l_delay;
            }

            //Check 5 delays before our suspected 0->1 transition to ensure
            //that we can find a non-noise related transition
            for(uint8_t l_delay_back = 1; l_delay_back < MIN_CONTINUE0_NUM; ++l_delay_back)
            {
                //see 0~63 delay as ring, if l_delay is 0, need check delay 63, 62 ...
                const uint8_t l_bit = (l_delay + MREP_DWL_MAX_DELAY  - l_delay_back ) % MREP_DWL_MAX_DELAY;

                if (!(i_result_nibble.getBit(l_bit)))
                {
                    l_continue0++;
                }
            }

            for(uint8_t l_delay_ahead = 1; l_delay_ahead < MIN_CONTINUE1_NUM; ++l_delay_ahead)
            {
                const uint8_t l_bit = (l_delay + l_delay_ahead) % MREP_DWL_MAX_DELAY;

                if (i_result_nibble.getBit(l_bit))
                {
                    l_continue1++;
                }
            }

            if((l_continue0 >= (MIN_CONTINUE0_NUM - TOLERANCE_NUMBER))
               && (l_continue1 >= (MIN_CONTINUE1_NUM - 1 - TOLERANCE_NUMBER)))
            {
                io_recorder.iv_delay = l_delay;
                final_delay_found = true;
                FAPI_DBG( "%s buffer:%u nibble:%u found a 0->1 transition at delay 0x%02x of result 0x%16lx, have 0x%02x continue 0 before it,have 0x%02x continue 1 after it",
                          mss::c_str(i_target), i_buffer, i_nibble, l_delay, i_result_nibble, l_continue0, l_continue1 );
            }
            else
            {
                io_recorder.iv_seen0 = false;
                io_recorder.iv_seen1 = false;
                FAPI_DBG( "%s buffer:%u nibble:%u found a wrong 0->1 transition at delay 0x%02x of result 0x%16lx, just have 0x%02x continue 0 before it,have 0x%02x continue 1 after it",
                          mss::c_str(i_target), i_buffer, i_nibble, l_delay, i_result_nibble, l_continue0, l_continue1 );
            }
        }

    }

    if(final_delay_found == false)
    {
        //found transition but have not enough 0/f count before/after it
        //use first transition as the final delay
        //report error
        if(l_first_transition != NO_TRANSITION_FOUND)
        {
            io_recorder.iv_delay = l_first_transition;
            io_recorder.iv_seen0 = true;
            io_recorder.iv_seen1 = true;

            FAPI_ASSERT(false,
                        fapi2::MSS_LRDIMM_CAL_NOISE()
                        .set_TARGET(i_target)
                        .set_BUFFER(i_buffer)
                        .set_CALIBRATION_STEP(i_calibration)
                        .set_CALIBRATION_RAW_DATA(i_result_nibble)
                        .set_NIBBLE(i_nibble),
                        "%s found a noise result in buffer%u nibble%u , the data is 0x%16lx",
                        mss::c_str(i_target), i_buffer, i_nibble, i_result_nibble);

        }

        // We will callout no 0->1 transitions when we do our full error checking
        FAPI_INF( "%s buffer:%u nibble:%u can not found a 0->1 transition of result 0x%16lx",
                  mss::c_str(i_target), i_buffer, i_nibble, i_result_nibble);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered
    // We "recover" by setting a default value and continuing with calibration
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}

///
/// @brief smoothing the result
/// @param[in] i_loop_results the results of loop times
/// @param[in, out] io_filter_result the result after smoothing
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode smoothing(const std::vector<mrep_dwl_result>& i_loop_results,
                            mrep_dwl_result& io_final_result)
{

    for(uint8_t l_buffer = 0; l_buffer < MAX_LRDIMM_BUFFERS; ++l_buffer)
    {
        for(uint8_t l_delay = 0; l_delay < MREP_DWL_MAX_DELAY; ++l_delay)
        {
            uint8_t nibble0_seen_1 = 0;
            uint8_t nibble1_seen_1 = 0;
            uint8_t loop_time = 0;

            //for each delay, collect how much times get 1
            for(auto& l_loop_result : i_loop_results )
            {
                auto l_it = l_loop_result.iv_results.begin() + l_buffer;

                if(l_it->first.getBit(l_delay))
                {
                    ++nibble0_seen_1;
                }

                if(l_it->second.getBit(l_delay))
                {
                    ++nibble1_seen_1;
                }

                loop_time++;
            }

            //if more than MREP_DWL_THRESHOLD get 1, the final result get 1
            {
                auto l_it_final = io_final_result.iv_results.begin() + l_buffer;

                if (nibble0_seen_1 >= MREP_DWL_THRESHOLD)
                {
                    FAPI_TRY(l_it_final->first.setBit(l_delay));
                }

                if (nibble1_seen_1 >= MREP_DWL_THRESHOLD)
                {
                    FAPI_TRY(l_it_final->second.setBit(l_delay));
                }

            }
        }//delay loop
    }//buffer loop

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief analyze the result
/// @param[in] i_target the MCA target
/// @param[in] i_calibration the current calibration step - used for error logging
/// @param[in] i_loop_results the results of loop times
/// @param[in, out] io_recorders a vector of the results
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode analyze_result( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint64_t i_calibration,
                                  const std::vector<mrep_dwl_result>& i_loop_results,
                                  std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& io_recorders)
{
    mrep_dwl_result l_final_result;
    uint8_t l_buffer = 0;
    constexpr uint8_t NIBBLE0 = 0;
    constexpr uint8_t NIBBLE1 = 1;

    //filter plus
    FAPI_TRY(smoothing(i_loop_results, l_final_result));

    // Note: we want to update the value of the results recorder, so no const
    for(auto& l_recorder : io_recorders)
    {

        const auto l_it_final = l_final_result.iv_results.begin() + l_buffer;
        const auto& l_result_nibble0 = l_it_final->first;
        const auto& l_result_nibble1 = l_it_final->second;
        // Temporary variables for some beautification below
        auto& l_recorder_nibble0 = l_recorder.first;
        auto& l_recorder_nibble1 = l_recorder.second;

        FAPI_TRY(analyze_result_for_each_nibble( i_target,
                 i_calibration,
                 l_result_nibble0,
                 l_buffer,
                 NIBBLE0,
                 l_recorder_nibble0) );
        FAPI_TRY(analyze_result_for_each_nibble( i_target,
                 i_calibration,
                 l_result_nibble1,
                 l_buffer,
                 NIBBLE1,
                 l_recorder_nibble1) );

        l_buffer++;
    }

fapi_try_exit:
    return fapi2::current_err;
}

namespace workarounds
{

///
/// @brief Clears error firs
/// @param[in] i_target The MCA Target
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode clear_firs(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    //Initialize
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    fapi2::ReturnCode l_mcbist_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_mca_rc = fapi2::FAPI2_RC_SUCCESS;
    fir::reg<MCBIST_MCBISTFIRQ> l_mcbist_fir(l_mcbist, l_mcbist_rc);
    fir::reg<MCA_FIR> l_mca_fir(i_target, l_mca_rc);

    // Checks the return codes from creating the FIR classes
    FAPI_TRY(l_mcbist_rc, "%s failed to create MCBIST FIR class", mss::c_str(l_mcbist) );
    FAPI_TRY(l_mca_rc, "%s failed to create MCA FIR class", mss::c_str(i_target) );

    //Clear Error Firs
    FAPI_TRY(l_mca_fir.clear<MCA_FIR_ECC_CORRECTOR_INTERNAL_PARITY_ERROR>());
    FAPI_TRY(l_mcbist_fir.clear<MCBIST_MCBISTFIRQ_MCBIST_BRODCAST_OUT_OF_SYNC>());

fapi_try_exit :
    return fapi2::current_err;
}
} // ns workarounds
} // ns training

} // ns lrdimm

} // ns mss
