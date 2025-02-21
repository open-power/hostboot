/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_error_check_scrub.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2025                        */
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
/// @file ody_error_check_scrub.C
/// @brief Odyssey error check scrub functionality
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/shared/ody_consts.H>
#include <ody_scom_ody_odc.H>
#include <ody_error_check_scrub.H>
#include <generic/memory/lib/ccs/ccs_ddr5_commands.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <lib/mc/ody_port_traits.H>
#include <generic/memory/lib/utils/mss_math.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <lib/ccs/ody_ccs.H>


namespace mss
{
namespace ccs
{
namespace ody
{
///
/// @brief Get unique port ranks from the vector of rank infos
/// @param[in] i_rank_info Vector of rank infos of the target
/// @return vector of unique ranks
///
std::vector<uint8_t>  get_unique_port_ranks(const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_vec_rank_info)
{
    std::vector<uint8_t> l_vec_ranks;

    // Get unique ranks from the rank infos.
    for(const auto& l_rank_info : i_vec_rank_info)
    {
        // Boolean to keep track of if the rank exists in the vector
        bool l_rank_exists = false;

        // Check to see if the rank is in the vector
        for (const auto& l_rank : l_vec_ranks)
        {
            if(l_rank == l_rank_info.get_port_rank())
            {
                l_rank_exists = true;
                break;
            }
        }

        // Push the current rank if it is not in the vector
        if(!l_rank_exists)
        {
            l_vec_ranks.push_back(l_rank_info.get_port_rank());
        }
    }

    FAPI_INF_NO_SBE("vec_size: %d", l_vec_ranks.size());
    return l_vec_ranks;
}

///
/// @brief Setsup the loop count, GOTO offset for the CCS command
/// @param[in] i_loop_count - loop count that needs to go into the CCS command
/// @param[in] i_start_loop - starting loop index that command needs to loop back to
/// @param[in,out] io_ccs_instructions - vector of ccs instructions
/// @return none
/// @note This function is called after the instruction copies for all mranks have been added to the program
///       hence it is safe to say that it is called on the last instruction
///
void setup_goto_offset(const uint8_t i_loop_count,
                       const uint8_t i_start_loop,
                       std::vector< instruction_t<mss::mc_type::ODYSSEY> >& io_ccs_instructions)
{

    using TT = ccsTraits<mss::mc_type::ODYSSEY>;

    const uint8_t l_last_instr_idx = io_ccs_instructions.size() - 1;
    const auto l_last_instr = io_ccs_instructions.end() - 1;

    // We want this setup only when we have single rank or
    // If we have multiple port ranks say n ranks then the setup is only for the last rank n-1
    // Set the loop count
    l_last_instr->arr0.template insertFromRight<TT::ARR0_NESTED_LOOP_COUNT, TT::ARR0_NESTED_LOOP_COUNT_LEN>(i_loop_count);

    // Need to break out the nested loop
    l_last_instr->arr1.template insertFromRight<TT::ARR1_BREAK_MODE, TT::ARR1_BREAK_MODE_LEN>(0b01);

    // GOTO the next instruction
    // Instruction class variable io_ccs_command.iv_goto_next_instr_offset
    l_last_instr->iv_goto_instr_offset = i_start_loop - l_last_instr_idx;

    // Else do nothing, the rest of the ranks should have default settings
}

///
/// @brief Setup the CCS instructions for performing ECS test
/// @param[in] i_rank_info Vector of rank infos of the target
/// @param[in] i_srank chipid/srank that needs to be run
/// @param[in,out] io_program io_program object of program class that has the vector of CCS instructions
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode  setup_arrays_with_ecs_instructions(const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>&
        i_vec_rank_info,
        const uint8_t i_srank,
        mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    // Exit if the vector is empty
    if (i_vec_rank_info.empty())
    {
        FAPI_INF_NO_SBE("Vector of rank_infos is empty, exiting setup_arrays_with_ecs_instructions()" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Get unique ranks from the rank infos.
    const std::vector<uint8_t> l_vec_ranks = get_unique_port_ranks(i_vec_rank_info);

    // Exit if the vector is empty
    if (l_vec_ranks.empty())
    {
        FAPI_INF_NO_SBE("Vector of ranks is empty, exiting setup_arrays_with_ecs_instructions()" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Starting loop index of the instruction that other instructions need to loop back to
    uint8_t l_loop_mpc_start_index = 0;

    uint64_t l_dram_freq = 0;
    uint8_t l_dram_density = 0;

    // Use rank to determine ranks and targets
    // Get port rank and dimm
    const auto& l_port_target = i_vec_rank_info[0].get_port_target();

    // Calling function code
    const uint16_t l_func_code = mss::ody::ffdc_codes::SET_ODY_SETUP_ARRAYS_WITH_ECS_INSTRUCTIONS;

    uint64_t l_tecsc_nck = 0;
    uint64_t l_tecsc_idles = 0;
    uint64_t l_tecsc_idles_per_rank = 0;
    uint16_t l_trfc_nck = 0;
    uint16_t l_trfc_idle = 0;
    uint16_t l_trfc_idle_per_rank = 0;
    // tMRD value is taken from Table 20 of JEDEC spec revision JESD79-5B_v1.20
    const uint64_t tMRD = 34;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    constexpr uint64_t TECSC_VAL_IN_NS = 110;
    constexpr uint64_t l_176_nck = 176;
    const auto l_110ns_nck = mss::ns_to_cycles(l_port_target, TECSC_VAL_IN_NS, l_rc);
    FAPI_TRY(l_rc);

    // The idles for Precharge comes from ATTR_MEM_EFF_DRAM_TRFC
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRFC, l_port_target, l_trfc_nck));
    // The trfc_nck should be divided by 2 so we can get the correct multiplier
    // Round up when not divisible by 2
    FAPI_TRY(mss::divide_and_round(l_trfc_nck, uint16_t(2), l_func_code, l_trfc_idle));

    // Get the trfc per rank
    FAPI_TRY(mss::divide_and_round(l_trfc_idle, uint16_t(l_vec_ranks.size()), l_func_code, l_trfc_idle_per_rank));

    // Get the DRAM frequency to calculate the idles for MPC:ECS operation
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FREQ, l_port_target, l_dram_freq));

    // Get the DRAM density
    FAPI_TRY(mss::attr::get_dram_density(i_vec_rank_info[0].get_dimm_target(), l_dram_density));

    // Write to MR14 and 15
    {
        uint8_t l_mr14_value0 = 0xe0;
        uint8_t l_mr14_value1 = 0xa0;

        // The ECC Transparency and Error Scrub counters are
        // set to zero and the internal ECS Address Counters are
        // initialized either by a RESET or by manually writing a 1 to MR14 OP[6].
        // Resets counters (MR16-20) and initialize:
        // Manual ECS mode enable: MR14 OP[7] set to 1 for Manual ECS mode
        //                         MR14 OP[6] set to 1 then 0
        // Row vs Code word count: MR14 OP[5] set to 1 for Code word
        // (use Code Word for finer granularity of counts)
        //             [CID/SRANK]
        // 7  6  5  4  3  2  1  0
        // 1  1  1  0  0  0  0  0 (0xE0)
        // 1  0  1  0  0  0  0  0 (0xA0)
        // MR OP are in reversed order so we need to reverse the CID bits

        l_mr14_value0 |= i_srank;
        l_mr14_value1 |= i_srank;

        for(const auto& l_rank : l_vec_ranks)
        {
            auto l_mr14_wr_instr1 = mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                    (l_rank, MR14_ECC_CONFIG, l_mr14_value0, tMRD);
            // Push the mrw command
            io_program.iv_instructions.push_back(l_mr14_wr_instr1);

            // CCS instruction to write to the MR14 register
            auto l_mr14_wr_instr2 = mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                    (l_rank, MR14_ECC_CONFIG, l_mr14_value1, tMRD);
            // Push the mrw command
            io_program.iv_instructions.push_back(l_mr14_wr_instr2);

            // Setup Error Threshold: MR15 [2:0] set to 011b for 256 errors (default is 011b for 256 errors)
            // 7  6  5  4  3  2  1  0
            // 0  0  0  0  0  0  1  1
            auto l_mr15_wr_instr = mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>(l_rank, MR15_ECC_THRESHOLD, 0x03,
                                   tMRD);

            // Push the mrw command
            io_program.iv_instructions.push_back(l_mr15_wr_instr);
        }
    }

    // Case 0: Flow chart of the ccs instructions for ECS test (2 ranks in parallel)
    // 0. PREab0(trfc_idle/2)
    //      |
    //      v
    // 1. PREab1(trfc_idle/2)
    //      |
    //      v
    // 2. REFab0(trfc_idle/2)<------|    (nested loop=0, goto offset=1)     if (l_rank != l_vec_ranks.size()-1)
    //      |                       |
    //      v                       |
    // 3. REFab1(trfc_idle/2)       |    (nested loop=10, goto offset=-1)   else
    //      |   |    10X            |
    //      v   ---------------------
    // 4. MPC_ECS0(tEcsc/2)<------| <-----| <-----| <-----| <-----| (nested loop=0, goto offset=1)
    //      |                     |       |       |       |       |
    //      v                     |       |       |       |       |
    // 5. MPC_ECS1(tEcsc/2)       |       |       |       |       | (nested loop=32, goto offset=-1)
    //      |        |     32X    |  128X |  128X |  128X | 2X or |
    //      v        --------------       |       |       | 4X    |
    // 6. REFab0(trfc_idle/2)             |       |       |       | (nested loop=0, goto offset=1)
    //      |                             |       |       |       |
    //      v                             |       |       |       |
    // 7. REFab1(trfc_idle/2)--------------       |       |       | (nested loop=128, goto offset=-3)
    //      |                                     |       |       |
    //      v                                     |       |       |
    // 8. NOP(0)-----------------------------------       |       | (nested loop=128, goto offset=-4)
    //      |                                             |       |
    //      v                                             |       |
    // 9. NOP(0)-------------------------------------------       | (nested loop=128, goto offset=-5)
    //      |                                                     |
    //      v                                                     |
    // 10.NOP(0)--------------------------------------------------- (nested loop=2 or 4, goto offset=-6)
    //      |
    //      v
    // 11.NOP(32)
    // ===================================================================================================
    // Case 1: Flow chart of the ccs instructions for ECS test for single rank
    // 0. PREab(trfc_nck)
    //      |
    //      v
    // 1. REFab(0)<------|
    //      |   |    10X |
    //      v    ---------
    // 2. MPC_ECS(tEcsc)<------| <-----| <-----| <-----| <-----|
    //      |        |     32X |  128X |  128X |  128X | 2X or |
    //      v        -----------       |       |       | 4X    |
    // 3. REFab(0)----------------------       |       |       |
    //      |                                  |       |       |
    //      v                                  |       |       |
    // 4. NOP(0)--------------------------------       |       |
    //      |                                          |       |
    //      v                                          |       |
    // 5. NOP(0)----------------------------------------       |
    //      |                                                  |
    //      v                                                  |
    // 6. NOP(0)------------------------------------------------
    //      |
    //      v
    // 7. NOP(32)

    // Notes:
    // * loop 2-->1 runs 32 ECS commands between refreshes, with tECSc between them
    // * loop 5-->4 implements tREF delay
    // * loops 6/7/8/9-->1 make enough ECS commands to cover entire DRAM address space
    // * Addr space: (32 * 128 * 128 * 128 * 2) = 134,217,728 (2^27) for 16Gb DRAM
    // * Addr space: (32 * 128 * 128 * 128 * 4) = 268,435,456 (2^28) for 32Gb DRAM
    // * instruction 10 is the "end" CCS instruction
    // The DRAM has an internal address counter that auto increments.
    // Setting up the loop counts to cover the full address range
    // and let the internal address counters increment the address.
    // Once the loop counter is 0 it automatically goes to the next
    // instruction.

    // PreCharge instruction
    // Set CCS instruction for PREab
    {
        for(const auto& l_rank : l_vec_ranks)
        {
            //====================================================
            // Case        | Multiple ranks      |  Single rank  |
            //-------------|---------------------|---------------|
            // Ranks       |  r0    |    r1      |      r0       |
            //====================================================
            // idles       | l_trfc_idle/#ofranks|  l_trfc_idle  |
            //====================================================
            // goto_offset |     1   |    1      |        1      |
            //====================================================
            // loop_count  |     0   |    0      |        0      |
            //====================================================
            // Create Precharge instruction for the selected srank
            auto l_pre_all_instr = mss::ccs::ddr5::precharge_all_command<mss::mc_type::ODYSSEY>(l_rank, i_srank,
                                   l_trfc_idle_per_rank);

            FAPI_INF_NO_SBE("l_rank: %d, l_trfc_idle_per_rank: 0x%02x for target: " GENTARGTIDFORMAT, l_rank, l_trfc_idle_per_rank,
                            GENTARGTID(i_vec_rank_info[0].get_port_target()));
            FAPI_INF_NO_SBE("l_rank: %d, l_trfc_nck: 0x%02x, l_trfc_idle: 0x%02x for target: " GENTARGTIDFORMAT, l_rank, l_trfc_nck,
                            l_trfc_idle, GENTARGTID(i_vec_rank_info[0].get_port_target()));

            // GOTO the next instruction
            // Instruction class variable l_pre_all_instr.iv_goto_next_instr_offset
            // Both cases the offset is 1
            // defaults to 1 that takes it to the next instruction

            // Push the precharge command
            io_program.iv_instructions.push_back(l_pre_all_instr);
        }
    }

    // REFresh instruction
    // Due to prior commands, the sequencer might have delayed several refreshes,
    // which can lead to a tREFI violation. Adds in 10x refresh prior to the ECS
    // loop to ensure that there is no tREFI violation
    {
        // Get the index of the refresh instruction
        const uint8_t l_refab_instr0_loop_index = io_program.iv_instructions.size();
        const uint8_t l_loop_count = 10;

        for(const auto& l_rank : l_vec_ranks)
        {
            //====================================================
            // Case        | Multiple ranks      |  Single rank  |
            //-------------|---------------------|---------------|
            // Ranks       |  r0    |    r1      |      r0       |
            //====================================================
            // idles       | l_trfc_idle/#ofranks|  l_trfc_idle  |
            //====================================================
            // goto_offset |     1  |    -1      |        1      |
            //====================================================
            // loop_count  |     0  |    10      |        0      |
            //====================================================

            // Create the REFab instruction for the selected srank
            auto l_refab_instr_0 = mss::ccs::ddr5::refresh_command<mss::mc_type::ODYSSEY>(l_rank, i_srank, l_trfc_idle_per_rank);

            // Push the refresh command
            io_program.iv_instructions.push_back(l_refab_instr_0);
        }

        // Update the loop count and goto fields on the instruction for the
        // last mrank (the last instruction we added to io_program)
        // so it loops back to the first REFab
        setup_goto_offset(l_loop_count, l_refab_instr0_loop_index, io_program.iv_instructions);
    }

    // Get the starting loop index for mpc so that all instructions can loop back to.
    l_loop_mpc_start_index = io_program.iv_instructions.size();

    // Jedec table-154: ECS Operation Timing Parameter is:
    // max(176nck, 110ns)/2. We need to divide it by 2 for the idles in the CCS instr
    l_tecsc_nck = std::max(l_176_nck, l_110ns_nck);
    FAPI_TRY(mss::divide_and_round(l_tecsc_nck, uint64_t(2), l_func_code, l_tecsc_idles));
    FAPI_TRY(mss::divide_and_round(l_tecsc_idles, uint64_t(l_vec_ranks.size()), l_func_code, l_tecsc_idles_per_rank));

    // MPC_ECS instruction
    // Set CCS instruction for MPC
    {
        const uint8_t l_loop_count = 32;

        for(const auto& l_rank : l_vec_ranks)
        {
            //======================================================
            // Case        | Multiple ranks        |  Single rank  |
            //-------------|-----------------------|---------------|
            // Ranks       |  r0    |    r1        |      r0       |
            //======================================================
            // idles       | l_tecsc_idles/#ofranks| l_tecsc_idle  |
            //======================================================
            // goto_offset |     1  |    -1        |        0      |
            //======================================================
            // loop_count  |     0  |    32        |       32      |
            //======================================================

            // Set the CCS instruction for MPC:ECS
            auto l_mpc_instr = mss::ccs::ddr5::mpc_command<mss::mc_type::ODYSSEY>(l_rank,
                               mss::ccs::ddr5::mpc_op_encoding::MANUAL_ECS_OP, l_tecsc_idles_per_rank);

            // Push the mpc command
            io_program.iv_instructions.push_back(l_mpc_instr);
        }

        // Update the loop count and goto fields on the instruction for the
        // last mrank (the last instruction we added to io_program)
        // so it loops back to the first MPC
        setup_goto_offset(l_loop_count, l_loop_mpc_start_index, io_program.iv_instructions);

    }

    // REFab instruction
    // Set the CCS instruction for REFab
    {
        const uint8_t l_loop_count = 128;

        for(const auto& l_rank : l_vec_ranks)
        {
            //======================================================
            // Case        | Multiple ranks        |  Single rank  |
            //-------------|-----------------------|---------------|
            // Ranks       |  r0    |    r1        |      r0       |
            //======================================================
            // idles       | l_trfc_idle/#ofranks  | l_trfc_idle   |
            //======================================================
            // goto_offset |     1  |    -3        |        -1     |
            //======================================================
            // loop_count  |     0  |    128       |      128      |
            //======================================================
            // Create the REFab instruction for the selected srank
            auto l_refab_instr = mss::ccs::ddr5::refresh_command<mss::mc_type::ODYSSEY>(l_rank, i_srank, l_trfc_idle_per_rank);


            // Push the refresh command
            io_program.iv_instructions.push_back(l_refab_instr);
        }

        // Update the loop count and goto fields on the instruction for the
        // last mrank (the last instruction we added to io_program)
        // so it loops back to the first MPC
        setup_goto_offset(l_loop_count, l_loop_mpc_start_index, io_program.iv_instructions);
    }

    // NOP instruction
    // Set the CCS instruction for NOP
    {
        //======================================================
        // Case        | Multiple ranks        |  Single rank  |
        //-------------|-----------------------|---------------|
        // Ranks       |   r0   |    r1        |      r0       |
        //======================================================
        // idles       |         0             |       0       |
        //======================================================
        // goto_offset |        -4             |      -2       |
        //======================================================
        // loop_count  |        128            |      128      |
        //======================================================
        auto l_nop_instr1 = mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(0);
        const uint8_t l_loop_count = 128;
        // Here for single and multiple there is only one instruction that needs to be setup
        // Push the nop command
        io_program.iv_instructions.push_back(l_nop_instr1);

        // Loops back to the first MPC in the program
        setup_goto_offset(l_loop_count, l_loop_mpc_start_index, io_program.iv_instructions);
    }

    // NOP instruction
    // Set the CCS instruction for NOP
    {
        //======================================================
        // Case        | Multiple ranks        |  Single rank  |
        //-------------|-----------------------|---------------|
        // Ranks       |   r0   |    r1        |      r0       |
        //======================================================
        // idles       |         0             |       0       |
        //======================================================
        // goto_offset |        -5             |      -3       |
        //======================================================
        // loop_count  |        128            |      128      |
        //======================================================
        auto l_nop_instr2 = mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(0);
        const uint8_t l_loop_count = 128;
        // Here for single and multiple there is only one instruction that needs to be setup
        // Push the nop command
        io_program.iv_instructions.push_back(l_nop_instr2);

        // Loops back to the first MPC in the program
        setup_goto_offset(l_loop_count, l_loop_mpc_start_index, io_program.iv_instructions);
    }

    // NOP instruction
    // Set the CCS instruction for NOP
    {
        //======================================================
        // Case        | Multiple ranks        |  Single rank  |
        //-------------|-----------------------|---------------|
        // Ranks       |   r0   |    r1        |      r0       |
        //======================================================
        // idles       |         0             |       0       |
        //======================================================
        // goto_offset |        -6             |      -4       |
        //======================================================
        // loop_count  |        2 or 4         |   2 or 4      |
        //======================================================
        auto l_nop_instr3 = mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(0);
        // Here for single and multiple there is only one instruction that needs to be setup
        // Note: the comments bellow refer to gigabit not gigabyte inentionally, as the die density is the determining factor here
        // Set the loop count to 2 for 16Gb DRAM width
        // (32 * 128 * 128 * 128 * 2) = 134,217,728 (2^27) for 16Gb DRAM
        // Set the loop count to 4 for 32Gb DRAM width
        // (32 * 128 * 128 * 128 * 4) = 268,435,456 (2^28) for 32Gb DRAM
        const uint8_t l_loop_count = l_dram_density == fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_16G ? 2 : 4;

        // Push the nop command
        io_program.iv_instructions.push_back(l_nop_instr3);

        // Loops back to the first MPC in the program
        setup_goto_offset(l_loop_count, l_loop_mpc_start_index, io_program.iv_instructions);
    }

    // Exit the CCS loop
    // Set the CCS instruction for NOP
    {
        auto l_nop_last_instr = mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(32);

        // Push the nop command
        io_program.iv_instructions.push_back(l_nop_last_instr);
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Mask the refresh overrun errors
/// @param[in] i_target OCMB target
/// @param[out] o_ref_overrun_reg_fir_mask_save buffer to return the
///             original value of refresh overrun register
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mask_refresh_overrun(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       fapi2::buffer<uint64_t>& o_ref_overrun_reg_fir_mask_save)
{
    fapi2::buffer<uint64_t> l_ref_overrun_reg_fir_mask;

    // Save the original mask value
    FAPI_TRY( mss::getScom(i_target, scomt::ody::ODC_SRQ_MASK_RW_WCLEAR, o_ref_overrun_reg_fir_mask_save) );

    // Mask the fir bits ref0_overrun_err and ref1_overrun_err
    l_ref_overrun_reg_fir_mask.setBit<scomt::ody::ODC_SRQ_LFIR_IN02>();
    l_ref_overrun_reg_fir_mask.setBit<scomt::ody::ODC_SRQ_LFIR_IN32>();
    FAPI_TRY( mss::putScom(i_target, scomt::ody::ODC_SRQ_MASK_WO_OR, l_ref_overrun_reg_fir_mask) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restore the ref0 and ref1 overrun errors
/// @brief Mask the refresh overrun errors
/// @param[in] i_target OCMB target
/// @param[in] i_ref_overrun_reg_fir_mask_save buffer to check the in02 and in32 bits
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode clear_and_restore_refresh_overrun(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const fapi2::buffer<uint64_t>& i_ref_overrun_reg_fir_mask_save )
{
    fapi2::buffer<uint64_t> l_ref_overrun_reg_fir;
    fapi2::buffer<uint64_t> l_ref_overrun_reg_fir_mask;

    // Clear the refresh bits and write to fir register
    l_ref_overrun_reg_fir.setBit<scomt::ody::ODC_SRQ_LFIR_IN02>();
    l_ref_overrun_reg_fir.setBit<scomt::ody::ODC_SRQ_LFIR_IN32>();
    FAPI_TRY( mss::putScom(i_target, scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR, l_ref_overrun_reg_fir) );

    // Check the fir reg's refresh overrun bits and clear the mask only if the errors are 0
    if (i_ref_overrun_reg_fir_mask_save.getBit<scomt::ody::ODC_SRQ_LFIR_IN02>() == 0)
    {
        l_ref_overrun_reg_fir_mask.setBit<scomt::ody::ODC_SRQ_LFIR_IN02>();
    }

    if ( i_ref_overrun_reg_fir_mask_save.getBit<scomt::ody::ODC_SRQ_LFIR_IN32>() == 0)
    {
        l_ref_overrun_reg_fir_mask.setBit<scomt::ody::ODC_SRQ_LFIR_IN32>();
    }

    FAPI_TRY( mss::putScom(i_target, scomt::ody::ODC_SRQ_MASK_RW_WCLEAR, l_ref_overrun_reg_fir_mask) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup to execute CCS
/// @param[in] i_vec_rank_info vector of rank_infos for all ports on a single rank
/// @param[in] i_srank the srank that needs to be executed
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_to_execute_ecs(const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_vec_rank_info,
                                       const uint8_t i_srank)
{
    if (i_vec_rank_info.empty())
    {
        FAPI_INF_NO_SBE("Vector of rank_infos is empty, exiting setup_to_execute_ecs()");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    fapi2::buffer<uint64_t> l_modeq_reg;
    fapi2::buffer<uint64_t> l_ref_overrun_reg_fir_mask;

    // Get OCMB Target
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_vec_rank_info[0].get_port_target());
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> > l_vec_ports;

    for(const auto& l_rank_info : i_vec_rank_info)
    {
        l_vec_ports.push_back(l_rank_info.get_port_target());
    }

    // Create Program
    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

    // Setup the arrays with CCS instruction to perform ECS for the selected SRANK
    FAPI_TRY(setup_arrays_with_ecs_instructions(i_vec_rank_info, i_srank, l_program));

    FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Deploying ecs using standalone CCS", GENTARGTID(l_ocmb_target));

    // Configure CCS regs for execution and enable the nested loop in modeq register.
    // Note: It is important to set the nested loop bit modeq register if you
    // have nested loop in the CCS instruction otherwise the CCS will timeout
    FAPI_TRY( mss::ccs::config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg, NTTM_MODE_OFF,
              NESTED_LOOP_ON ) );

    // Mask the refresh overrun FIR's while we run the ECS program
    FAPI_TRY(mask_refresh_overrun(l_ocmb_target, l_ref_overrun_reg_fir_mask));

    // Adjust the polling delays because ECS takes atleast couple of minutes to run
    // Set initial delay(ns) to be couple of minutes which is 120 sec
    l_program.iv_poll.iv_initial_delay = uint64_t(120) * mss::common_timings::DELAY_1S;
    // Set delays(ns) in between the polls to be half a minute which is 30 sec
    l_program.iv_poll.iv_delay = uint64_t(30) * mss::common_timings::DELAY_1S;
    // Set the poll count to be 60
    l_program.iv_poll.iv_poll_count = 60;

    // Run CCS execution for single and multiple ports
    FAPI_TRY( mss::ccs::execute_parallel_ports<mss::mc_type::ODYSSEY>(l_ocmb_target, l_vec_ports, l_program) );

    // Revert CCS regs after execution
    FAPI_TRY( mss::ccs::revert_config_regs<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg) );

    // Restore the refresh overrun FIR's while we run the ECS program
    FAPI_TRY(clear_and_restore_refresh_overrun(l_ocmb_target, l_ref_overrun_reg_fir_mask));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief esets the error counters and initialize
/// @param[in] i_rank_info  vector of rank infos for all ports on a single rank
/// @param[in] i_srank the srank that needs to be executed
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode reset_error_counters(const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_vec_rank_info,
                                       const uint8_t i_srank)
{
    // Exit if the vector is empty
    if (i_vec_rank_info.empty())
    {
        FAPI_INF_NO_SBE("Vector of rank_infos is empty, exiting reset_error_counters() run");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Constant to help with readability
    constexpr bool STATIC = false;

    // tMRD value is taken from Table 20 of JEDEC spec revision JESD79-5B_v1.20
    const uint64_t tMRD = 34;

    for (const auto& l_rank_info : i_vec_rank_info)
    {
        const auto& l_port_target = l_rank_info.get_port_target();
        const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

        uint8_t l_mr14_value0 = 0xe0;
        uint8_t l_mr14_value1 = 0xa0;

        // The ECC Transparency and Error Scrub counters are
        // set to zero and the internal ECS Address Counters are
        // initialized either by a RESET or by manually writing a 1 to MR14 OP[6].
        // Resets counters (MR16-20) and initialize:
        // Manual ECS mode enable: MR14 OP[7] set to 1 for Manual ECS mode
        //                         MR14 OP[6] set to 1 then 0
        // Row vs Code word count: MR14 OP[5] set to 1 for Code word
        // (use Code Word for finer granularity of counts)
        //             [CID/SRANK]
        // 7  6  5  4  3  2  1  0
        // 1  1  1  0  0  0  0  0 (0xE0)
        // 1  0  1  0  0  0  0  0 (0xA0)
        // MR OP are in reversed order so we need to reverse the CID bits

        l_mr14_value0 |= i_srank;
        l_mr14_value1 |= i_srank;

        const auto& l_port_rank = l_rank_info.get_port_rank();
        mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

        l_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                            (l_port_rank, MR14_ECC_CONFIG, l_mr14_value0, tMRD));
        l_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                            (l_port_rank, MR14_ECC_CONFIG, l_mr14_value1, tMRD));
        FAPI_TRY(mss::ccs::setup_execute_restore<mss::mc_type::ODYSSEY>(l_ocmb_target, l_program, l_port_target, STATIC));
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Disables the ecc mode
/// @param[in] i_target OCMB target
/// @param[out] o_ecc_reg buffer to return the original value of ecc reg
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode disable_ecc_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   fapi2::buffer<uint64_t>& o_ecc_reg)
{
    using PT = portTraits<mss::mc_type::ODYSSEY>;
    constexpr uint8_t RECR_MBSECCQ_DATA_INVERSION_NO_INVERSION = 0b00;

    fapi2::buffer<uint64_t> l_ecc_data;

    // Save the original data
    FAPI_TRY( fapi2::getScom(i_target, PT::ECC_REG, l_ecc_data) );
    o_ecc_reg = l_ecc_data;

    // Disable ECC mode
    l_ecc_data.setBit<PT::ECC_CHECK_DISABLE>();
    l_ecc_data.writeBit<PT::ECC_USE_ADDR_HASH>(mss::states::LOW);
    l_ecc_data.insertFromRight<PT::RECR_MBSECCQ_DATA_INVERSION, PT::RECR_MBSECCQ_DATA_INVERSION_LEN>
    (RECR_MBSECCQ_DATA_INVERSION_NO_INVERSION);
    l_ecc_data.clearBit<PT::RECR_ENABLE_MPE_NOISE_WINDOW>();
    l_ecc_data.clearBit<PT::RECR_RETRY_UNMARKED_ERRORS>();
    l_ecc_data.setBit<PT::RECR_CFG_MAINT_USE_TIMERS>();
    FAPI_TRY( fapi2::putScom(i_target, PT::ECC_REG, l_ecc_data) );
    FAPI_INF_NO_SBE("ECC mode disabled: 0x%016lx", l_ecc_data);


fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Disables the periodic calibration
/// @param[in] i_target OCMB target
/// @param[out] o_periodic_calib buffer to return the original value of FARB9Q reg
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode disable_periodic_cal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       fapi2::buffer<uint64_t>& o_periodic_calib)
{
    using PT = portTraits<mss::mc_type::ODYSSEY>;
    fapi2::buffer<uint64_t> l_periodic_calib_data;

    // Save the original data
    FAPI_TRY( fapi2::getScom(i_target, PT::FARB9Q_REG, l_periodic_calib_data) );
    o_periodic_calib = l_periodic_calib_data;

    // Disable periodic calibration.
    l_periodic_calib_data.clearBit<PT::CFG_MC_PER_CAL_ENABLE>();
    FAPI_TRY( fapi2::putScom(i_target, PT::FARB9Q_REG, l_periodic_calib_data) );
    FAPI_INF_NO_SBE("Periodic calibration mode disabled: 0x%016lx", l_periodic_calib_data);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Enables the needed modes after running ecs test
/// @param[in] i_target OCMB target
/// @param[in] i_ecc_reg value to set the ecc reg
/// @param[in] i_periodic_calib value to set the FARB9Q_REG
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode enable_periodic_cal_ecc_modes(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const fapi2::buffer<uint64_t>& i_ecc_reg,
        const fapi2::buffer<uint64_t>& i_periodic_calib)
{
    using PT = portTraits<mss::mc_type::ODYSSEY>;

    // Enable ecc checking
    FAPI_TRY( fapi2::putScom(i_target, PT::ECC_REG, i_ecc_reg) );

    // Enable periodic calibration
    FAPI_TRY( fapi2::putScom(i_target, PT::FARB9Q_REG, i_periodic_calib) );


fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Initialize the memory on a specific srank with a specific data pattern
/// @param[in] i_rank_info - rank_info for a single port on a single rank
/// @param[in] i_srank the srank to initialize
/// @param[in] i_pattern mcbist pattern
/// @param[out] o_ecc_data output buffer to get the original ecc reg value
/// @return FAPI2_RC_SUCCESS iff successful
///

fapi2::ReturnCode memory_init_via_memdiags(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const uint8_t i_srank,
        const uint64_t i_pattern,
        fapi2::buffer<uint64_t>& o_ecc_data)
{
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>( i_rank_info.get_port_target() );
    fapi2::buffer<uint64_t> l_fir_mask_save;

    // Disable the ecc mode
    FAPI_TRY(disable_ecc_mode(l_ocmb, o_ecc_data));

    // Mask the mcbist program complete
    FAPI_TRY( mss::memdiags::mask_program_complete<mss::mc_type::ODYSSEY>(l_ocmb, l_fir_mask_save) );

    // Call the memdiags to initialize the memory
    FAPI_TRY( mss::memdiags::sf_init_per_srank<mss::mc_type::ODYSSEY>(l_ocmb, i_srank, i_pattern) );

    // Polls for completion
    FAPI_TRY(mss::memdiags::mss_async_polling_loop<mss::mc_type::ODYSSEY>(l_ocmb));

    // Clear the mcbist program complete
    FAPI_TRY( mss::memdiags::clear_and_restore_program_complete<mss::mc_type::ODYSSEY>(l_ocmb, l_fir_mask_save) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads the MR registers
/// @param[in] i_rank_info the rank info
/// @param[in] i_mrs the specific MRS
/// @param[out] o_data array of mr values per dram
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_mr_error_regs(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                     const uint64_t i_mrs,
                                     uint8_t (&o_data)[mss::ody::ODY_NUM_DRAM_X4])
{
    // Constant to help with readability
    constexpr bool STATIC = false;

    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

    const auto& l_port = i_rank_info.get_port_target();

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port);
    std::vector<mss::ccs::channel_select> l_channels;

    FAPI_TRY(mss::ccs::get_channels(l_ocmb, l_channels));

    // Runs on all the configure channels
    for(const auto l_channel : l_channels)
    {
        l_program.iv_instructions.push_back(mss::ccs::ddr5::mrr_command<mss::mc_type::ODYSSEY>
                                            (i_rank_info.get_port_rank(), i_mrs, ccsTraits<mss::mc_type::ODYSSEY>::MRR_SAFE_IDLE));
        l_program.iv_channel_select = l_channel;
        FAPI_TRY(mss::ccs::setup_execute_restore<mss::mc_type::ODYSSEY>(l_ocmb, l_program, l_port, STATIC));

        FAPI_INF_NO_SBE("Read data from MR%d in port: " GENTARGTIDFORMAT,
                        i_mrs,
                        GENTARGTID(l_port));

        FAPI_TRY(mss::ccs::mr_data_process<mss::mc_type::ODYSSEY>(l_port, l_channel, o_data));
        l_program.iv_instructions.clear();
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Run the workaround for Hynix DIMMS
/// @param[in] i_vec_rank_infos vector of rank infos for all ports on a single rank
/// @param[in] i_srank the srank that currently being executed
/// @param[in] i_pattern data pattern to test
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode run_hynix_workaround(const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_vec_rank_infos,
                                       const uint8_t i_srank,
                                       const uint64_t i_pattern)
{

    if (i_vec_rank_infos.empty())
    {
        FAPI_INF_NO_SBE("Vector of rank_infos is empty, exiting run_hynix_workaround()");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    uint16_t l_dram_mfg_id = 0;
    fapi2::buffer<uint64_t> l_ecc_reg_data;
    fapi2::buffer<uint64_t> l_periodic_calib_data;
    const auto& l_port = i_vec_rank_infos[0].get_port_target();
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port);

    // Get the dram mfg id
    FAPI_TRY( mss::attr::get_dram_mfg_id(i_vec_rank_infos[0].get_dimm_target(), l_dram_mfg_id));

    // Workaround for Hynx fails, run an extra pattern
    // to get a clean MR20 for the later patterns
    if(l_dram_mfg_id == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MFG_ID_HYNIX &&
       i_pattern == mss::mcbist::PATTERN_0)
    {
        FAPI_INF_NO_SBE("Starting workaround for Hynix dimms running on port:  "
                        GENTARGTIDFORMAT
                        ", mrank: %u, srank: %u for pattern: %u",
                        GENTARGTID(l_port),
                        i_vec_rank_infos[0].get_port_rank(), i_srank, i_pattern);
        // Do mem init for each srank
        FAPI_TRY(memory_init_via_memdiags(i_vec_rank_infos[0], i_srank, mss::mcbist::PATTERN_0, l_ecc_reg_data));

        // Disable periodic calibration
        FAPI_TRY(disable_periodic_cal(l_ocmb, l_periodic_calib_data));

        // Setup the ecs to execute
        FAPI_TRY(setup_to_execute_ecs(i_vec_rank_infos, i_srank));

        // Reset the error counters MR16-MR20 for the next run
        FAPI_TRY(reset_error_counters(i_vec_rank_infos, i_srank));

        // Enable periodic calibration and ecc mode
        FAPI_TRY(enable_periodic_cal_ecc_modes(l_ocmb, l_ecc_reg_data, l_periodic_calib_data));

        FAPI_INF_NO_SBE("Ending workaround for Hynix dimms running on port:  "
                        GENTARGTIDFORMAT
                        ", mrank: %u, srank: %u for pattern: %u",
                        GENTARGTID(l_ocmb),
                        i_vec_rank_infos[0].get_port_rank(), i_srank, i_pattern);
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Run the ecs test
/// @param[in] i_vec_ranks vector of rank infos
/// @param[in] i_pattern data pattern to test
/// @param[out] o_mr20_arr array to keep the mr20 data
/// @param[out] o_mr16_19_arr array to keep the mr16-19 data
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode run_ecs_helper(const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_vec_ranks,
                                 const uint64_t i_pattern,
                                 uint8_t (&o_mr20_arr)[mss::ody::MAX_PORT_PER_OCMB][mss::ody::HW_MAX_MRANK_PER_PORT][mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4],
                                 uint32_t (
                                     &o_mr16_19_arr)[mss::ody::MAX_PORT_PER_OCMB][mss::ody::HW_MAX_MRANK_PER_PORT][mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4])
{
    // Exit if the vector is empty
    if (i_vec_ranks.empty())
    {
        FAPI_INF_NO_SBE("Vector of rank_infos is empty, exiting ECS run");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    uint8_t l_dram_splits[mss::ody::ODY_NUM_DRAM_X4] = {};
    fapi2::buffer<uint64_t> l_ecc_reg_data;
    fapi2::buffer<uint64_t> l_periodic_calib_data;

    memset(&o_mr20_arr, 0, sizeof(o_mr20_arr) / sizeof(uint8_t));
    memset(&o_mr16_19_arr, 0, sizeof(o_mr16_19_arr) / sizeof(o_mr16_19_arr));

    uint8_t l_mranks = 0;
    uint8_t l_logical_ranks = 0;
    uint8_t l_num_sranks = 1;


    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_vec_ranks[0].get_port_target());

    // Assuming that the configuration is the same between ports, we are using rank_info from index 0
    // Get the logical ranks
    FAPI_TRY( mss::attr::get_logical_ranks_per_dimm(i_vec_ranks[0].get_dimm_target(), l_logical_ranks) );
    // Get the master ranks
    FAPI_TRY( mss::attr::get_num_master_ranks_per_dimm(i_vec_ranks[0].get_dimm_target(), l_mranks) );

    // Get the number of CID
    if(l_mranks != 0)
    {
        l_num_sranks = l_logical_ranks / l_mranks;
    }

    // Run this for each SRANK for the rank info that the user selected
    for(uint8_t l_srank = 0; l_srank < l_num_sranks; l_srank++)
    {
        // Workaround for HYNIX DIMM
        // should take full set of ranks i_vec_ranks
        FAPI_TRY(run_hynix_workaround(i_vec_ranks, l_srank, i_pattern));

        // Do mem init for each srank
        FAPI_TRY(memory_init_via_memdiags(i_vec_ranks[0], l_srank, i_pattern, l_ecc_reg_data));

        // Disable periodic calibration
        FAPI_TRY(disable_periodic_cal(l_ocmb, l_periodic_calib_data));

        // Setup the ecs to execute
        // change: should take full set of rank infos i_vec_ranks
        FAPI_TRY(setup_to_execute_ecs(i_vec_ranks, l_srank));

        // Collect the mr error info into arrays from the  rank infos only
        // Looping through all ranks
        for (const auto& l_rank_info : i_vec_ranks)
        {
            const uint8_t l_mrank_idx = l_rank_info.get_port_rank();
            const auto& l_port_target = l_rank_info.get_port_target();
            const uint8_t l_rel_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

            FAPI_INF_NO_SBE(GENTARGTIDFORMAT " In run_ecs_helper(): l_rel_pos: %d", GENTARGTID(l_port_target), l_rel_pos);
            FAPI_TRY(read_mr_error_regs(l_rank_info, MR20_ERROR_COUNT, l_dram_splits));
            memcpy(&o_mr20_arr[l_rel_pos][l_mrank_idx][l_srank][0], &l_dram_splits[0],
                   sizeof(o_mr20_arr[l_rel_pos][l_mrank_idx][l_srank]));

#ifndef __HOSTBOOT_MODULE

            for (uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++)
            {
                FAPI_INF_NO_SBE("Error count from MR20 in port: " GENTARGTIDFORMAT
                                ", mrank: %u, srank: %d, DRAM %d, OPCODE: 0x%02x for pattern:%u",
                                GENTARGTID(l_port_target),
                                l_rank_info.get_port_rank(), l_srank, l_dram, l_dram_splits[l_dram], i_pattern);
            }

#endif
            FAPI_TRY(read_mr_error_regs(l_rank_info, MR16_ERROR_COUNT, l_dram_splits));

            for (uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++)
            {
                // Each element in this array is concatenation of MR16171819
                // [MR16MR17MR18MR19, MR16MR17MR18MR19 ......]
                // Shifting the MR data to the correct position in a 32 byte value
                o_mr16_19_arr[l_rel_pos][l_mrank_idx][l_srank][l_dram] |= static_cast<uint32_t>(l_dram_splits[l_dram]) << 24;
                FAPI_DBG("Added MR16:0x%02x: to the array 0x%016lx", l_dram_splits[l_dram],
                         o_mr16_19_arr[l_rel_pos][l_mrank_idx][l_srank][l_dram]);
            }

            FAPI_TRY(read_mr_error_regs(l_rank_info, MR17_ERROR_COUNT, l_dram_splits));

            for (uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++)
            {
                o_mr16_19_arr[l_rel_pos][l_mrank_idx][l_srank][l_dram] |= static_cast<uint32_t>(l_dram_splits[l_dram]) << 16;
                FAPI_DBG("Added MR17:0x%02x: to the array 0x%016lx", l_dram_splits[l_dram],
                         o_mr16_19_arr[l_rel_pos][l_mrank_idx][l_srank][l_dram]);
            }

            FAPI_TRY(read_mr_error_regs(l_rank_info, MR18_ERROR_COUNT, l_dram_splits));

            for (uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++)
            {
                o_mr16_19_arr[l_rel_pos][l_mrank_idx][l_srank][l_dram] |= static_cast<uint32_t>(l_dram_splits[l_dram]) << 8;
                FAPI_DBG("Added MR18:0x%02x: to the array 0x%016lx", l_dram_splits[l_dram],
                         o_mr16_19_arr[l_rel_pos][l_mrank_idx][l_srank][l_dram]);
            }

            FAPI_TRY(read_mr_error_regs(l_rank_info, MR19_ERROR_COUNT, l_dram_splits));

            for (uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++)
            {
                o_mr16_19_arr[l_rel_pos][l_mrank_idx][l_srank][l_dram] |= l_dram_splits[l_dram];
                FAPI_DBG("Added MR19:0x%02x: to the array 0x%016lx", l_dram_splits[l_dram],
                         o_mr16_19_arr[l_rel_pos][l_mrank_idx][l_srank][l_dram]);
            }
        } // end of rank_info vector

        // Reset the error counters MR16-MR20 for the next run
        FAPI_TRY(reset_error_counters(i_vec_ranks, l_srank));
        // Enable periodic calibration and ecc mode
        FAPI_TRY(enable_periodic_cal_ecc_modes(l_ocmb, l_ecc_reg_data, l_periodic_calib_data));
    } // end of l_srank

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Run the ecs test
/// @param[in] i_vec_rank vector of rank infos
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode run_ecs(const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_vec_ranks)
{
    uint8_t l_ecs_threshold = 0;
    bool l_errors_over_threshold = false;

    // Arrays to populate MR20 data per MRANK per SRANK per DRAM
    uint8_t l_mr20_arr_pat0[mss::ody::MAX_PORT_PER_OCMB][mss::ody::HW_MAX_MRANK_PER_PORT][mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4]
        = {};
    uint8_t l_mr20_arr_pat1[mss::ody::MAX_PORT_PER_OCMB][mss::ody::HW_MAX_MRANK_PER_PORT][mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4]
        = {};
    // Arrays to populate MR16, MR17, MR18, MR19 data per MRANK per SRANK per DRAM
    // Each element in this array is like the following:
    //           DRAM0             DRAM1            ......... DRAM19
    //             |                 |
    //             V                 V
    // SRANK0 ->[MR16MR17MR18MR19, MR16MR17MR18MR19 ................]
    // SRANK1 ->[MR16MR17MR18MR19, MR16MR17MR18MR19 ................]

    uint32_t l_mr16_19_arr_pat0[mss::ody::MAX_PORT_PER_OCMB][mss::ody::HW_MAX_MRANK_PER_PORT][mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4]
        = {};
    uint32_t l_mr16_19_arr_pat1[mss::ody::MAX_PORT_PER_OCMB][mss::ody::HW_MAX_MRANK_PER_PORT][mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4]
        = {};

    // Get the threshold value
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_ECS_ERROR_COUNT_THRESHOLD, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_ecs_threshold) );

    // Run ecs with pattern0 memory initialization
    FAPI_TRY(run_ecs_helper(i_vec_ranks, mss::mcbist::PATTERN_0, l_mr20_arr_pat0, l_mr16_19_arr_pat0));

    // Run ecs with pattern1 initialization
    FAPI_TRY(run_ecs_helper(i_vec_ranks, mss::mcbist::PATTERN_1, l_mr20_arr_pat1, l_mr16_19_arr_pat1));

    for(const auto& l_rank_info : i_vec_ranks)
    {
        const auto& l_port_target = l_rank_info.get_port_target();
        const uint8_t l_mrank = l_rank_info.get_port_rank();
        const uint8_t l_rel_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

        // Check for threshold here for MR20 for pattern 0, pattern 1
        for(uint8_t l_srank_id = 0; l_srank_id < mss::ody::MAX_SRANKS; l_srank_id++)
        {
            // Go through all the MR20 values for each DRAM
            for(uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++ )
            {
                // Check the if we are above the threshold
                if(l_mr20_arr_pat0[l_rel_pos][l_mrank][l_srank_id][l_dram] > l_ecs_threshold ||
                   l_mr20_arr_pat1[l_rel_pos][l_mrank][l_srank_id][l_dram] > l_ecs_threshold)
                {
                    // Flag an error if we are above the threshold
                    l_errors_over_threshold = true;
                }
            }
        }

        FAPI_ASSERT_NOEXIT(!(l_errors_over_threshold),
                           fapi2::ODY_ECS_FAIL()
                           .set_PORT_TARGET(l_port_target)
                           .set_THRESHOLD(l_ecs_threshold)
                           .set_MRANK(l_mrank)
                           .set_MR20_PAT0((void*)l_mr20_arr_pat0)
                           .set_MR20_PAT0_SIZE(sizeof(l_mr20_arr_pat0))
                           .set_MR16_TO_19_PAT0((void*)l_mr16_19_arr_pat0)
                           .set_MR16_TO_19_PAT0_SIZE(sizeof(l_mr16_19_arr_pat0))
                           .set_MR20_PAT1((void*)l_mr20_arr_pat1)
                           .set_MR20_PAT1_SIZE(sizeof(l_mr20_arr_pat1))
                           .set_MR16_TO_19_PAT1((void*)l_mr16_19_arr_pat1)
                           .set_MR16_TO_19_PAT1_SIZE(sizeof(l_mr16_19_arr_pat1)),
                           "Error counts MR20 and MR16 to MR19 in port: " GENTARGTIDFORMAT " ecs_threshold: %d",
                           GENTARGTID(l_port_target), l_ecs_threshold);

        // Reset the current error is needed here
        // As long the errors saved in the arrays this function can pass a FAPI2_RC_SUCCESS
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns ody
} // ns ccs
} // ns mss
