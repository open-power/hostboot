/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_error_check_scrub.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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


namespace mss
{
namespace ccs
{
namespace ody
{
///
/// @brief Setup the CCS instructions for performing ECS test
/// @param[in] i_rank_info Rank info of the target
/// @param[in] i_srank chipid/srank that needs to be run
/// @param[in,out] io_program io_program object of program class that has the vector of CCS instructions
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode  setup_arrays_with_ecs_instructions(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const uint8_t i_srank,
        mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    using TT = ccsTraits<mss::mc_type::ODYSSEY>;

    uint64_t l_dram_freq = 0;
    uint8_t l_dram_density = 0;

    // Use rank to determine ranks and targets
    // Get port rank and dimm
    const auto& l_port_target = i_rank_info.get_port_target();
    const auto& l_port_rank = i_rank_info.get_port_rank();

    uint64_t l_tecsc_nck = 0;
    uint64_t l_tecsc_idles = 0;
    uint16_t l_trfc_nck = 0;
    uint16_t l_trfc_idle = 0;
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
    FAPI_TRY(mss::divide_and_round(l_trfc_nck, uint16_t(2), 0, l_trfc_idle));

    // Get the DRAM frequency to calculate the idles for MPC:ECS operation
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FREQ, l_port_target, l_dram_freq));

    // Get the DRAM density
    FAPI_TRY(mss::attr::get_dram_density(i_rank_info.get_dimm_target(), l_dram_density));

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
        // Row vs Code word count: MR14 OP[5] set to 1 for Code Word
        // (use Code Word for finer granularity of counts)
        //             [CID/SRANK]
        // 7  6  5  4  3  2  1  0
        // 1  1  1  0  0  0  0  0 (0xE0)
        // 1  0  1  0  0  0  0  0 (0xA0)
        // MR OP are in reversed order so we need to reverse the CID bits

        l_mr14_value0 |= i_srank;
        l_mr14_value1 |= i_srank;

        // CCS instruction to write to the MR14 register
        auto l_mr14_wr_instr1 = mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                (l_port_rank, MR14_ECC_CONFIG, l_mr14_value0, tMRD);
        // Push the mrw command
        io_program.iv_instructions.push_back(l_mr14_wr_instr1);

        // CCS instruction to write to the MR14 register
        auto l_mr14_wr_instr2 = mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                (l_port_rank, MR14_ECC_CONFIG, l_mr14_value1, tMRD);
        // Push the mrw command
        io_program.iv_instructions.push_back(l_mr14_wr_instr2);

        // Setup Error Threshold: MR15 [2:0] set to 011b for 256 errors (default is 011b for 256 errors)
        // 7  6  5  4  3  2  1  0
        // 0  0  0  0  0  0  1  1
        auto l_mr15_wr_instr = mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>(l_port_rank, MR15_ECC_THRESHOLD, 0x03, tMRD);

        // Push the mrw command
        io_program.iv_instructions.push_back(l_mr15_wr_instr);

    }

    // Flow chart of the ccs instructions for ECS test
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

    // 0th instruction
    // Set CCS instruction for PREab
    {
        // Create Precharge instruction for the selected srank
        auto l_pre_all_instr = mss::ccs::ddr5::precharge_all_command<mss::mc_type::ODYSSEY>(l_port_rank, i_srank,
                               l_trfc_idle);

        // GOTO the 1st instruction
        // Instruction class variable l_pre_all_instr.iv_goto_next_instr_offset
        // defaults to 1 that takes it to the next instruction

        // Push the precharge command
        io_program.iv_instructions.push_back(l_pre_all_instr);

    }

    // 1st instruction
    // Due to prior commands, the sequencer might have delayed several refreshes,
    // which can lead to a tREFI violation. Adds in 10x refresh prior to the ECS
    // loop to ensure that there is no tREFI violation
    {
        // Create the REFab instruction for the selected srank
        auto l_refab_instr_0 = mss::ccs::ddr5::refresh_command<mss::mc_type::ODYSSEY>(l_port_rank, i_srank, l_trfc_idle);

        // Set the loop count to 10 to refresh all the drams
        l_refab_instr_0.arr0.template insertFromRight<TT::ARR0_NESTED_LOOP_COUNT, TT::ARR0_NESTED_LOOP_COUNT_LEN>(10);

        // Need to break out the nested loop
        l_refab_instr_0.arr1.template insertFromRight<TT::ARR1_BREAK_MODE, TT::ARR1_BREAK_MODE_LEN>(0b01);

        // GOTO the 1st instruction
        // Instruction class variable l_mpc_instr.iv_goto_next_instr_offset
        // need to be set to 0 to loop around itself
        l_refab_instr_0.iv_goto_instr_offset = 0;

        // Push the refresh command
        io_program.iv_instructions.push_back(l_refab_instr_0);
    }

    // Jedec table-154: ECS Operation Timing Parameter is:
    // max(176nck, 110ns)/2. We need to divide it by 2 for the idles in the CCS instr
    l_tecsc_nck = std::max(l_176_nck, l_110ns_nck);
    FAPI_TRY(mss::divide_and_round(l_tecsc_nck, uint64_t(2), 0, l_tecsc_idles));

    // 2nd instruction
    // Set CCS instruction for MPC
    {
        // Set the CCS instruction for MPC:ECS
        auto l_mpc_instr = mss::ccs::ddr5::mpc_command<mss::mc_type::ODYSSEY>(l_port_rank,
                           mss::ccs::ddr5::mpc_op_encoding::MANUAL_ECS_OP, l_tecsc_idles);

        // Set the loop count to 32
        l_mpc_instr.arr0.template insertFromRight<TT::ARR0_NESTED_LOOP_COUNT, TT::ARR0_NESTED_LOOP_COUNT_LEN>(32);

        // Need to break out the nested loop
        l_mpc_instr.arr1.template insertFromRight<TT::ARR1_BREAK_MODE, TT::ARR1_BREAK_MODE_LEN>(0b01);

        // GOTO the 1st instruction
        // Instruction class variable l_mpc_instr.iv_goto_next_instr_offset
        // need to be set to 0 to loop around itself
        l_mpc_instr.iv_goto_instr_offset = 0;

        // Push the mpc command
        io_program.iv_instructions.push_back(l_mpc_instr);
    }

    // 3rd instruction
    // Set the CCS instruction for REFab
    {
        // Create the REFab instruction for the selected srank
        auto l_refab_instr = mss::ccs::ddr5::refresh_command<mss::mc_type::ODYSSEY>(l_port_rank, i_srank, l_trfc_idle);

        // Set the loop count to 128
        l_refab_instr.arr0.template insertFromRight<TT::ARR0_NESTED_LOOP_COUNT, TT::ARR0_NESTED_LOOP_COUNT_LEN>(128);

        // Need to break out the nested loop
        l_refab_instr.arr1.template insertFromRight<TT::ARR1_BREAK_MODE, TT::ARR1_BREAK_MODE_LEN>(0b01);

        // GOTO to the 4th instruction
        // Instruction class variable l_refab_instr.iv_goto_next_instr_offset
        // Need to be set to -1 to go back to 1st instruction
        l_refab_instr.iv_goto_instr_offset = -1;

        // Push the refresh command
        io_program.iv_instructions.push_back(l_refab_instr);
    }

    // 4th instruction
    // Set the CCS instruction for NOP
    {
        auto l_nop_instr1 = mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(0);

        // Set the loop count to 128
        l_nop_instr1.arr0.template insertFromRight<TT::ARR0_NESTED_LOOP_COUNT, TT::ARR0_NESTED_LOOP_COUNT_LEN>(128);

        // Need to break out the nested loop
        l_nop_instr1.arr1.template insertFromRight<TT::ARR1_BREAK_MODE, TT::ARR1_BREAK_MODE_LEN>(0b01);

        // GOTO back to the 1st instruction for a loop count of 128
        // Instruction class variable l_nop_instr1.iv_goto_next_instr_offset
        // need to be set to -2 to go back to 1st instruction
        l_nop_instr1.iv_goto_instr_offset = -2;

        // Push the nop command
        io_program.iv_instructions.push_back(l_nop_instr1);
    }

    // 5th instruction
    // Set the CCS instruction for NOP
    {
        auto l_nop_instr2 = mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(0);
        // Set the loop count to 4
        l_nop_instr2.arr0.template insertFromRight<TT::ARR0_NESTED_LOOP_COUNT, TT::ARR0_NESTED_LOOP_COUNT_LEN>(128);

        // Need to break out the nested loop
        l_nop_instr2.arr1.template insertFromRight<TT::ARR1_BREAK_MODE, TT::ARR1_BREAK_MODE_LEN>(0b01);

        // GOTO back to the 1st instruction for a loop count of 128
        // Instruction class variable l_nop_instr2.iv_goto_next_instr_offset
        // need to be set to -3 that takes it back to 1st instruction
        l_nop_instr2.iv_goto_instr_offset = -3;

        // Push the nop command
        io_program.iv_instructions.push_back(l_nop_instr2);
    }

    // 6th instruction
    // Set the CCS instruction for NOP
    {
        uint8_t l_loop_cnt = 0;
        auto l_nop_instr3 = mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(0);

        // Note: the comments bellow refer to gigabit not gigabyte inentionally, as the die density is the determining factor here
        // Set the loop count to 2 for 16Gb DRAM width
        // (32 * 128 * 128 * 128 * 2) = 134,217,728 (2^27) for 16Gb DRAM
        // Set the loop count to 4 for 32Gb DRAM width
        // (32 * 128 * 128 * 128 * 4) = 268,435,456 (2^28) for 32Gb DRAM
        l_loop_cnt = l_dram_density == fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_16G ? 2 : 4;
        l_nop_instr3.arr0.template insertFromRight<TT::ARR0_NESTED_LOOP_COUNT, TT::ARR0_NESTED_LOOP_COUNT_LEN>(l_loop_cnt);

        // Need to break out the nested loop
        l_nop_instr3.arr1.template insertFromRight<TT::ARR1_BREAK_MODE, TT::ARR1_BREAK_MODE_LEN>(0b01);

        // GOTO back to the 1st instruction for a loop count of 2 or 4
        // Instruction class variable l_nop_instr3.iv_goto_next_instr_offset
        // need to be set to -3 that takes it back to 1st instruction
        l_nop_instr3.iv_goto_instr_offset = -4;

        // Push the nop command
        io_program.iv_instructions.push_back(l_nop_instr3);
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
/// @param[in] i_rank_info Rank info of the target
/// @param[in] i_srank the srank that needs to be executed
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_to_execute_ecs(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                       const uint8_t i_srank)
{
    fapi2::buffer<uint64_t> l_modeq_reg;
    fapi2::buffer<uint64_t> l_ref_overrun_reg_fir_mask;

    // Get port rank and target
    const auto& l_port_target = i_rank_info.get_port_target();

    // Get OCMB Target
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Create Program
    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

    // Setup the arrays with CCS instruction to perform ECS for the selected SRANK
    FAPI_TRY(setup_arrays_with_ecs_instructions(i_rank_info, i_srank, l_program));
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
    // Run CCS execution
    FAPI_TRY( mss::ccs::execute<mss::mc_type::ODYSSEY>(l_ocmb_target, l_program, l_port_target) );

    // Revert CCS regs after execution
    FAPI_TRY( mss::ccs::revert_config_regs<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg) );

    // Restore the refresh overrun FIR's while we run the ECS program
    FAPI_TRY(clear_and_restore_refresh_overrun(l_ocmb_target, l_ref_overrun_reg_fir_mask));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief esets the error counters and initialize
/// @param[in] i_rank_info Rank info of the target
/// @param[in] i_srank the srank that needs to be executed
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode reset_error_counters(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                       const uint8_t i_srank)
{
    // Constant to help with readability
    constexpr bool STATIC = false;
    const auto& l_port_target = i_rank_info.get_port_target();
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    uint8_t l_mr14_value0 = 0xe0;
    uint8_t l_mr14_value1 = 0xa0;

    // The ECC Transparency and Error Scrub counters are
    // set to zero and the internal ECS Address Counters are
    // initialized either by a RESET or by manually writing a 1 to MR14 OP[6].
    // Resets counters (MR16-20) and initialize:
    // Manual ECS mode enable: MR14 OP[7] set to 1 for Manual ECS mode
    //                         MR14 OP[6] set to 1 then 0
    // Row vs Code word count: MR14 OP[5] set to 1 for Code Word
    // (use Code Word for finer granularity of counts)
    //             [CID/SRANK]
    // 7  6  5  4  3  2  1  0
    // 1  1  1  0  0  0  0  0 (0xE0)
    // 1  0  1  0  0  0  0  0 (0xA0)
    // MR OP are in reversed order so we need to reverse the CID bits

    l_mr14_value0 |= i_srank;
    l_mr14_value1 |= i_srank;

    const auto& l_port_rank = i_rank_info.get_port_rank();
    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

    l_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                        (l_port_rank, MR14_ECC_CONFIG, l_mr14_value0));
    FAPI_TRY(mss::ccs::setup_execute_restore<mss::mc_type::ODYSSEY>(l_ocmb_target, l_program, l_port_target, STATIC));

    l_program.iv_instructions.clear();
    l_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                        (l_port_rank, MR14_ECC_CONFIG, l_mr14_value1));
    FAPI_TRY(mss::ccs::setup_execute_restore<mss::mc_type::ODYSSEY>(l_ocmb_target, l_program, l_port_target, STATIC));

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
/// @param[in] i_target OCMB Chip
/// @param[in] i_srank the srank to initialize
/// @param[in] i_pattern mcbist pattern
/// @return FAPI2_RC_SUCCESS iff successful
///

fapi2::ReturnCode memory_init_via_memdiags(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const uint8_t i_srank,
        const uint64_t i_pattern)
{
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_rank_info.get_port_target());
    fapi2::buffer<uint64_t> l_ecc_data;
    fapi2::buffer<uint64_t> l_fir_mask_save;

    // Disable the ecc mode
    FAPI_TRY(disable_ecc_mode(l_ocmb, l_ecc_data));

    // Mask the mcbist program complete
    FAPI_TRY( mss::memdiags::mask_program_complete<mss::mc_type::ODYSSEY>(l_ocmb, l_fir_mask_save) );

    // Call the memdiags to initialize the memory
    FAPI_TRY( mss::memdiags::sf_init<mss::mc_type::ODYSSEY>(l_ocmb, i_pattern) );

    // Polls for completion
    FAPI_TRY(mss::memdiags::mss_async_polling_loop<mss::mc_type::ODYSSEY>(l_ocmb));

    // Clear the mcbist program complete
    FAPI_TRY( mss::memdiags::clear_and_restore_program_complete<mss::mc_type::ODYSSEY>(l_ocmb, l_fir_mask_save) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads the MR registers
/// @param[in] i_port_rank the port rank
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

    l_program.iv_instructions.push_back(mss::ccs::ddr5::mrr_command<mss::mc_type::ODYSSEY>
                                        (i_rank_info.get_port_rank(), i_mrs, ccsTraits<mss::mc_type::ODYSSEY>::MRR_SAFE_IDLE));

    const auto& l_port = i_rank_info.get_port_target();

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port);

    FAPI_TRY(mss::ccs::setup_execute_restore<mss::mc_type::ODYSSEY>(l_ocmb, l_program, l_port, STATIC));

    FAPI_INF_NO_SBE("Read data from MR%d in port: " GENTARGTIDFORMAT,
                    i_mrs,
                    GENTARGTID(l_port));

    FAPI_TRY(mss::ccs::mr_data_process<mss::mc_type::ODYSSEY>(l_port, o_data));

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Run the ecs test
/// @param[in] i_rank_info rank info
/// @param[in] i_pattern data pattern to test
/// @param[out] o_mr20_arr array to keep the mr20 data
/// @param[out] o_mr16_19_arr array to keep the mr16-19 data
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode run_ecs_helper(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                 const uint64_t i_pattern,
                                 uint8_t (&o_mr20_arr)[mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4],
                                 uint32_t (&o_mr16_19_arr)[mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4])
{

    // Since we pass in the vector of ranks now we need to have a
    // loop over the vector of rank_info and do  the rest in a for loop
    const auto& l_port = i_rank_info.get_port_target();
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port);
    uint8_t l_dram_splits[mss::ody::ODY_NUM_DRAM_X4] = {};
    fapi2::buffer<uint64_t> l_ecc_reg_data;
    fapi2::buffer<uint64_t> l_periodic_calib_data;

    memset(&o_mr20_arr, 0, sizeof(o_mr20_arr) / sizeof(uint8_t));
    memset(&o_mr16_19_arr, 0, sizeof(o_mr16_19_arr) / sizeof(o_mr16_19_arr));

    uint8_t l_mranks = 0;
    uint8_t l_logical_ranks = 0;
    uint8_t l_num_sranks = 1;

    // Get the logical ranks
    FAPI_TRY( mss::attr::get_logical_ranks_per_dimm(i_rank_info.get_dimm_target(), l_logical_ranks) );
    // Get the master ranks
    FAPI_TRY( mss::attr::get_num_master_ranks_per_dimm(i_rank_info.get_dimm_target(), l_mranks) );

    // Get the number of CID
    if(l_mranks != 0)
    {
        l_num_sranks = l_logical_ranks / l_mranks;
    }

    // Run this for each SRANK
    for(uint8_t l_srank = 0; l_srank < l_num_sranks; l_srank++)
    {
        // Do mem init for each srank
        FAPI_TRY(memory_init_via_memdiags(i_rank_info, l_srank, i_pattern));

        // Disable periodic calibration, refresh, and ecc mode
        FAPI_TRY(disable_periodic_cal(l_ocmb, l_periodic_calib_data));

        // Setup the ecs to execute
        FAPI_TRY(setup_to_execute_ecs(i_rank_info, l_srank));

        // Collect the mr error info into arrays
        FAPI_TRY(read_mr_error_regs(i_rank_info, MR20_ERROR_COUNT, l_dram_splits));
        memcpy(&o_mr20_arr[l_srank][0], &l_dram_splits[0], sizeof(o_mr20_arr[l_srank]));

#ifndef __HOSTBOOT_MODULE

        for (uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++)
        {
            FAPI_INF_NO_SBE("Error count from MR20 in port: " GENTARGTIDFORMAT
                            ", mrank: %u, srank: %d, DRAM %d, OPCODE: 0x%02x for pattern:%u",
                            GENTARGTID(l_port),
                            i_rank_info.get_port_rank(), l_srank, l_dram, l_dram_splits[l_dram], i_pattern);
        }

#endif

        FAPI_TRY(read_mr_error_regs(i_rank_info, MR16_ERROR_COUNT, l_dram_splits));

        for (uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++)
        {
            // Each element in this array is concatenation of MR16171819
            // [MR16MR17MR18MR19, MR16MR17MR18MR19 ......]
            // Shifting the MR data to the correct position in a 32 byte value
            o_mr16_19_arr[l_srank][l_dram] |= static_cast<uint32_t>(l_dram_splits[l_dram]) << 24;
            FAPI_DBG("Added MR16:0x%02x: to the array 0x%016lx", l_dram_splits[l_dram],
                     o_mr16_19_arr[l_srank][l_dram]);
        }

        FAPI_TRY(read_mr_error_regs(i_rank_info, MR17_ERROR_COUNT, l_dram_splits));

        for (uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++)
        {
            o_mr16_19_arr[l_srank][l_dram] |= static_cast<uint32_t>(l_dram_splits[l_dram]) << 16;
            FAPI_DBG("Added MR17:0x%02x: to the array 0x%016lx", l_dram_splits[l_dram],
                     o_mr16_19_arr[l_srank][l_dram]);
        }

        FAPI_TRY(read_mr_error_regs(i_rank_info, MR18_ERROR_COUNT, l_dram_splits));

        for (uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++)
        {
            o_mr16_19_arr[l_srank][l_dram] |= static_cast<uint32_t>(l_dram_splits[l_dram]) << 8;
            FAPI_DBG("Added MR18:0x%02x: to the array 0x%016lx", l_dram_splits[l_dram],
                     o_mr16_19_arr[l_srank][l_dram]);
        }

        FAPI_TRY(read_mr_error_regs(i_rank_info, MR19_ERROR_COUNT, l_dram_splits));

        for (uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++)
        {
            o_mr16_19_arr[l_srank][l_dram] |= l_dram_splits[l_dram];
            FAPI_DBG("Added MR19:0x%02x: to the array 0x%016lx", l_dram_splits[l_dram],
                     o_mr16_19_arr[l_srank][l_dram]);
        }

        // Reset the error counters MR16-MR20 for the next run
        FAPI_TRY(reset_error_counters(i_rank_info, l_srank));

        // Enable periodic calibration and ecc mode
        FAPI_TRY(enable_periodic_cal_ecc_modes(l_ocmb, l_ecc_reg_data, l_periodic_calib_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Run the ecs test
/// @param[in] i_vec_rank vector of ranks
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode run_ecs(const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_vec_ranks)
{
    uint8_t l_ecs_threshold = 0;
    bool l_errors_over_threshold = false;

    // Get the threshold value
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_ECS_ERROR_COUNT_THRESHOLD, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_ecs_threshold) );

    for (const auto& l_rank_info : i_vec_ranks)
    {
        // Arrays to populate MR20 data per MRANK per SRANK per DRAM
        uint8_t l_mr20_arr_pat0[mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4] = {};
        uint8_t l_mr20_arr_pat1[mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4] = {};
        // Arrays to populate MR16, MR17, MR18, MR19 data per MRANK per SRANK per DRAM
        // Each element in this array is like the following:
        //           DRAM0             DRAM1            ......... DRAM19
        //             |                 |
        //             V                 V
        // SRANK0 ->[MR16MR17MR18MR19, MR16MR17MR18MR19 ................]
        // SRANK1 ->[MR16MR17MR18MR19, MR16MR17MR18MR19 ................]

        uint32_t l_mr16_19_arr_pat0[mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4] = {};
        uint32_t l_mr16_19_arr_pat1[mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4] = {};

        // Run ecs with pattern0 memory initialization
        FAPI_TRY(run_ecs_helper(l_rank_info, mss::mcbist::PATTERN_0, l_mr20_arr_pat0, l_mr16_19_arr_pat0));

        // Run ecs with pattern1 initialzation
        FAPI_TRY(run_ecs_helper(l_rank_info, mss::mcbist::PATTERN_1, l_mr20_arr_pat1, l_mr16_19_arr_pat1));

        // Check for threshold here for MR20 for pattern 0, pattern 1
        for(uint8_t l_srank_id = 0; l_srank_id < mss::ody::MAX_SRANKS; l_srank_id++)
        {
            // Go through all the MR20 values for each DRAM
            for(uint8_t l_dram = 0; l_dram < mss::ody::ODY_NUM_DRAM_X4; l_dram++ )
            {
                // Check the if we are abve the threshold
                if(l_mr20_arr_pat0[l_srank_id][l_dram] > l_ecs_threshold ||
                   l_mr20_arr_pat1[l_srank_id][l_dram] > l_ecs_threshold)
                {
                    // Flag an error if we are above the threshold
                    l_errors_over_threshold = true;
                }
            }
        }

        FAPI_ASSERT_NOEXIT(!(l_errors_over_threshold),
                           fapi2::ODY_ECS_FAIL()
                           .set_PORT_TARGET(l_rank_info.get_port_target())
                           .set_THRESHOLD(l_ecs_threshold)
                           .set_MRANK(l_rank_info.get_port_rank())
                           .set_MR20_PAT0(&l_mr20_arr_pat0)
                           .set_MR20_PAT0_SIZE(sizeof(l_mr20_arr_pat0))
                           .set_MR16_TO_19_PAT0(&l_mr16_19_arr_pat0)
                           .set_MR16_TO_19_PAT0_SIZE(sizeof(l_mr16_19_arr_pat0))
                           .set_MR20_PAT1(&l_mr20_arr_pat1)
                           .set_MR20_PAT1_SIZE(sizeof(l_mr20_arr_pat1))
                           .set_MR16_TO_19_PAT1(&l_mr16_19_arr_pat1)
                           .set_MR16_TO_19_PAT1_SIZE(sizeof(l_mr16_19_arr_pat1)),
                           "Error counts MR20 and MR16 to MR19 in port: " GENTARGTIDFORMAT " ecs_threshold: %d",
                           GENTARGTID(l_rank_info.get_port_target()), l_ecs_threshold);

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
