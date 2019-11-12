/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/ccs_workarounds.C $ */
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
/// @file ccs_workarounds.H
/// @brief Contains CCS workarounds
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#include <lib/shared/mss_const.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/dimm/rank.H>
#include <p9_mc_scom_addresses.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/eff_config/timing.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/mc/port.H>
#include <lib/mc/mc.H>

namespace mss
{

namespace ccs
{

namespace workarounds
{

///
/// @brief Re-enables PDA mode on a given rank in the shadow registers
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///
fapi2::ReturnCode enable_pda_shadow_reg( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank )
{
    static const std::vector<uint64_t> RP_TO_REG =
    {
        MCA_DDRPHY_PC_MR3_PRI_RP0_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP1_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP2_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP3_P0,
    };

    uint64_t l_rp = 0;
    FAPI_TRY( mss::rank::get_pair_from_rank( i_target, i_rank, l_rp ), "%s failed to get pair from rank %lu",
              mss::c_str(i_target), i_rank );

    // Reads, modifies, and writes the value back out
    {
        // The bits in the shadow register are one block, we only want to set the PDA enable bit, which corresponds to bit 59
        constexpr uint64_t PDA_BIT = 59;
        fapi2::buffer<uint64_t> l_data;

        // Read
        FAPI_TRY( mss::getScom(i_target, RP_TO_REG[l_rp], l_data) );

        // Modify
        l_data.setBit<PDA_BIT>();

        // Write
        FAPI_TRY( mss::putScom(i_target, RP_TO_REG[l_rp], l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Issues the PDA exit command
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @param[in,out] io_program - the CCS program
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
/// @note The PHY traps both the a-side and b-side MRS's into the same shadow register
/// After the a-side MRS exits PDA, the b-side MRS will not be taken out of PDA mode
/// To workaround this problem, a-side MRS is issued, then the shadow register is modified to have PDA mode enabled
/// Then the b-side MRS is issued
///
fapi2::ReturnCode exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const uint64_t i_rank,
                        ccs::program& io_program )
{
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    // Issues A-side MRS
    {
        auto l_a_side = io_program;
        l_a_side.iv_instructions.clear();
        l_a_side.iv_instructions.push_back(io_program.iv_instructions[0]);

        FAPI_TRY( ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target),
                               l_a_side,
                               l_mca),
                  "unable to execute CCS for MR03 a-side PDA exit rank %d %s",
                  i_rank, mss::c_str(i_target) );
    }

    // Re-enable PDA mode in the PHY
    {
        FAPI_TRY( enable_pda_shadow_reg(l_mca, i_rank) );
    }

    // Sets up the B-side MRS - the outside code will issue it
    // This allows the workaround to be encapuslated and the exit code to function properly for cases where the workaround should not be executed
    {
        auto l_b_side = io_program;
        l_b_side.iv_instructions.clear();
        l_b_side.iv_instructions.push_back(io_program.iv_instructions[1]);
        io_program = l_b_side;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Preload the CCS program for epow
/// @param[in] i_target the target to effect
/// @param[in] i_program the vector of instructions
/// @return FAPI2_RC_SUCCSS iff ok
/// @note This is written specifically to support EPOW on NVDIMM
///       This function loads the input program to the CCS arrays
///       without execute as opposed to ccs::execute(). The actual
///       ccs program execution will be handled by OCC
///
fapi2::ReturnCode preload_ccs_for_epow( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                        ccs::program& i_program)
{
    typedef ccsTraits<mss::mc_type::NIMBUS> TT;

    // Subtract one for the idle we insert at the end
    constexpr size_t CCS_INSTRUCTION_DEPTH = 32 - 1;
    constexpr uint64_t CCS_ARR0_ZERO = MCBIST_CCS_INST_ARR0_00;
    constexpr uint64_t CCS_ARR1_ZERO = MCBIST_CCS_INST_ARR1_00;

    FAPI_INF("loading ccs instructions (%d) for epow on %s", i_program.iv_instructions.size(), mss::c_str(i_target));

    auto l_inst_iter = i_program.iv_instructions.begin();

    // Stop the CCS engine just for giggles - it might be running ...
    FAPI_TRY( start_stop(i_target, mss::states::STOP), "Error in ccs::workarounds::preload_ccs_for_epow" );

    FAPI_ASSERT( mss::poll(i_target, TT::STATQ_REG, poll_parameters(),
                           [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("ccs statq (stop) 0x%llx, remaining: %d", stat_reg, poll_remaining);
        return stat_reg.getBit<TT::CCS_IN_PROGRESS>() != 1;
    }),
    fapi2::MSS_CCS_HUNG_TRYING_TO_STOP().set_MCBIST_TARGET(i_target) );

    while (l_inst_iter != i_program.iv_instructions.end())
    {
        size_t l_inst_count = 0;

        // Shove the instructions into the CCS engine, in 32 instruction chunks, and execute them
        for (; l_inst_iter != i_program.iv_instructions.end()
             && l_inst_count < CCS_INSTRUCTION_DEPTH; ++l_inst_count, ++l_inst_iter)
        {
            // If we are on the last instruction we want to stay there. If we exit
            // the sequencer could take back the control. This is also the reason
            // we are not adding up the delays here.
            if (l_inst_iter + 1 == i_program.iv_instructions.end())
            {
                l_inst_iter->arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_GOTO_CMD,
                            MCBIST_CCS_INST_ARR1_00_GOTO_CMD_LEN>(l_inst_count);
            }
            else
            {
                l_inst_iter->arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_GOTO_CMD,
                            MCBIST_CCS_INST_ARR1_00_GOTO_CMD_LEN>(l_inst_count + 1);
            }

            FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + l_inst_count, l_inst_iter->arr0),
                      "Error in ccs::workarounds::preload_ccs_for_epow" );
            FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + l_inst_count, l_inst_iter->arr1),
                      "Error in ccs::workarounds::preload_ccs_for_epow" );

            FAPI_INF("css inst %d: 0x%016lX 0x%016lX (0x%lx, 0x%lx)",
                     l_inst_count, l_inst_iter->arr0, l_inst_iter->arr1,
                     CCS_ARR0_ZERO + l_inst_count, CCS_ARR1_ZERO + l_inst_count,
                     mss::c_str(i_target));
        }
    }

    // No need to set the ports here. This will be done by OCC before poking the start bit

fapi_try_exit:
    i_program.iv_instructions.clear();
    return fapi2::current_err;
}

namespace nvdimm
{

///
/// @brief add_refreshes() helper
/// @param[in] i_target The MCA target where the program will be executed on
/// @param[in,out] i_program the MCBIST ccs program to append the refreshes
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode add_refreshes_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                       mss::ccs::program& io_program)
{
    typedef ccsTraits<mss::mc_type::NIMBUS> TT;

    uint16_t l_trefi = 0;

    // 3 refreshes because the maximum number of instructions we can have is 28 for
    // dual-rank NVDIMM (MRS)
    constexpr size_t l_num_refreshes = 3;
    constexpr uint64_t CS_N_ACTIVE = 0b00;

    //get tREFI
    FAPI_TRY(mss::eff_dram_trefi(i_target, l_trefi));

    //load the refreshes into the program
    for (size_t i = 0; i < l_num_refreshes; i++)
    {
        // We want to make sure the refresh hit all the ranks, so let's get the refresh command and change the chip select manually later
        mss::ccs::instruction_t l_inst = mss::ccs::refresh_command(0, l_trefi);
        l_inst.arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1, TT::ARR0_DDR_CSN_0_1_LEN>(CS_N_ACTIVE);
        l_inst.arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3, TT::ARR0_DDR_CSN_2_3_LEN>(CS_N_ACTIVE);
        l_inst.iv_update_rank = false;
        io_program.iv_instructions.push_back(l_inst);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Adds refreshes at the beginning and end of the program
/// @param[in] i_target The MCA target where the program will be executed on
/// @param[in,out] io_program the MCBIST ccs program to add the refreshes
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode add_refreshes(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                mss::ccs::program& io_program)
{
    mss::ccs::program l_program;

    // Add the refreshes at the beginning
    FAPI_TRY(add_refreshes_helper(i_target, l_program));

    // Append the instructions from io_program
    l_program.iv_instructions.insert(l_program.iv_instructions.end(), io_program.iv_instructions.begin(),
                                     io_program.iv_instructions.end());

    io_program = l_program;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute the contents of the CCS array with ccs_addr_mux_sel control
/// @param[in] i_target The MCBIST containing the array
/// @param[in] i_program the MCBIST ccs program - to get the polling parameters
/// @param[in] i_port The port target that the array is for
/// @return FAPI2_RC_SUCCESS iff success
/// @note This is the exact same copy of execute_inst_array() in ccs.H with changes
///       to ccs_addr_mux_sel before and after the execute. This is required to ensure
///       CCS can properly drive the bus during the nvdimm post-restore sequence.
///
fapi2::ReturnCode execute_inst_array(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                     mss::ccs::program& i_program,
                                     const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_port)
{
    typedef ccsTraits<mss::mc_type::NIMBUS> TT;

    fapi2::buffer<uint64_t> status;

    // Change ccs_add_mux_sel to high to make sure the CCS logic is driving the bus
    FAPI_TRY(mss::change_addr_mux_sel(i_port, mss::HIGH));

    FAPI_TRY(mss::ccs::start_stop(i_target, mss::START), "%s Error in execute_inst_array", mss::c_str(i_port) );

    // ccs_add_mux_sel back to low. Per Shelton, it is okay to change the mux while ccs is running
    // when doing single port execute. ccs will remain in control until the end of the program then
    // mainline takes over
    FAPI_TRY(mss::change_addr_mux_sel(i_port, mss::LOW));

    mss::poll(i_target, TT::STATQ_REG, i_program.iv_poll,
              [&status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("ccs statq 0x%llx, remaining: %d", stat_reg, poll_remaining);
        status = stat_reg;
        return status.getBit<TT::CCS_IN_PROGRESS>() != 1;
    },
    i_program.iv_probes);

    // Check for done and success. DONE being the only bit set.
    if (status == TT::STAT_QUERY_SUCCESS)
    {
        FAPI_INF("%s CCS Executed Successfully.", mss::c_str(i_port) );
        goto fapi_try_exit;
    }

    // So we failed or we're still in progress. Mask off the fail bits
    // and run this through the FFDC generator.
    // TK: Put the const below into a traits class? -- JLH
    FAPI_TRY( mss::ccs::fail_type(i_target, status & 0x1C00000000000000, i_port), "Error in execute_inst_array" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute a set of CCS instructions
/// @param[in] i_target the target to effect
/// @param[in] i_program the vector of instructions
/// @param[in] i_port The port target that the array is for
/// @return FAPI2_RC_SUCCSS iff ok
/// @note This is a copy of execute() with minor tweaks to the namespace and single port only
///
fapi2::ReturnCode execute( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                           mss::ccs::program& i_program,
                           const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_port)
{
    typedef ccsTraits<mss::mc_type::NIMBUS> TT;

    // Subtract one for the idle we insert at the end
    constexpr size_t CCS_INSTRUCTION_DEPTH = 32 - 1;
    constexpr uint64_t CCS_ARR0_ZERO = MCBIST_CCS_INST_ARR0_00;
    constexpr uint64_t CCS_ARR1_ZERO = MCBIST_CCS_INST_ARR1_00;
    mss::states l_str_state = mss::states::OFF;
    fapi2::buffer<uint64_t> l_farb6q;

    mss::ccs::instruction_t l_des = ccs::des_command();

    FAPI_INF("loading ccs instructions (%d) for %s", i_program.iv_instructions.size(), mss::c_str(i_target));

    //Check if we are in str. If we are not, throw some refreshes into the program
    FAPI_TRY(mss::mc::read_farb6q(i_port, l_farb6q));
    mss::mc::get_self_time_refresh_state(l_farb6q, l_str_state);

    if (l_str_state == mss::states::OFF)
    {
        // Since we are executing the CCS program with data in the DRAMs, we need to be congnizant
        // about the refreshes. Refresh from mc is fenced off when CCS has the bus, and by the time
        // the control is given back to the mc, we would have violated 8*trefi refresh window.
        // As such, let's start off each program with couple of refreshes so we don't violate the
        // rolling 8*trefi window (verified on logic analyzer)
        FAPI_TRY(add_refreshes(i_port, i_program));
    }

    {
        auto l_inst_iter = i_program.iv_instructions.begin();

        std::vector<rank_configuration> l_rank_configs;
        FAPI_TRY(get_rank_config(i_target, l_rank_configs));

        // Stop the CCS engine just for giggles - it might be running ...
        FAPI_TRY( mss::ccs::start_stop(i_target, mss::states::STOP), "Error in ccs::execute" );

        FAPI_ASSERT( mss::poll(i_target, TT::STATQ_REG, poll_parameters(),
                               [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
        {
            FAPI_INF("ccs statq (stop) 0x%llx, remaining: %d", stat_reg, poll_remaining);
            return stat_reg.getBit<TT::CCS_IN_PROGRESS>() != 1;
        }),
        fapi2::MSS_CCS_HUNG_TRYING_TO_STOP().set_MCBIST_TARGET(i_target) );

        while (l_inst_iter != i_program.iv_instructions.end())
        {
            size_t l_inst_count = 0;

            uint64_t l_total_delay = 0;
            uint64_t l_delay = 0;
            uint64_t l_repeat = 0;
            uint8_t l_current_cke = 0;
            const auto l_port_index = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_port);

            // Shove the instructions into the CCS engine, in 32 instruction chunks, and execute them
            for (; l_inst_iter != i_program.iv_instructions.end()
                 && l_inst_count < CCS_INSTRUCTION_DEPTH; ++l_inst_count, ++l_inst_iter)
            {
                // First, update the current instruction's chip selects for the current port
                FAPI_TRY(l_inst_iter->configure_rank(i_port, l_rank_configs[l_port_index]), "Error in rank config");

                l_inst_iter->arr0.extractToRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(l_current_cke);

                // Make sure this instruction leads to the next. Notice this limits this mechanism to pretty
                // simple (straight line) CCS programs. Anything with a loop or such will need another mechanism.
                l_inst_iter->arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_GOTO_CMD,
                            MCBIST_CCS_INST_ARR1_00_GOTO_CMD_LEN>(l_inst_count + 1);
                FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + l_inst_count, l_inst_iter->arr0), "Error in ccs::execute" );
                FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + l_inst_count, l_inst_iter->arr1), "Error in ccs::execute" );

                // arr1 contains a specification of the delay and repeat after this instruction, as well
                // as a repeat. Total up the delays as we go so we know how long to wait before polling
                // the CCS engine for completion
                l_inst_iter->arr1.extractToRight<MCBIST_CCS_INST_ARR1_00_IDLES, MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(l_delay);
                l_inst_iter->arr1.extractToRight<MCBIST_CCS_INST_ARR1_00_REPEAT_CMD_CNT,
                            MCBIST_CCS_INST_ARR1_00_REPEAT_CMD_CNT>(l_repeat);

                l_total_delay += l_delay * (l_repeat + 1);

                FAPI_INF("css inst %d: 0x%016lX 0x%016lX (0x%lx, 0x%lx) delay: 0x%x (0x%x) %s",
                         l_inst_count, l_inst_iter->arr0, l_inst_iter->arr1,
                         CCS_ARR0_ZERO + l_inst_count, CCS_ARR1_ZERO + l_inst_count,
                         l_delay, l_total_delay, mss::c_str(i_target));
            }

            // Check our program for any delays. If there isn't a iv_initial_delay configured, then
            // we use the delay we just summed from the instructions.
            if (i_program.iv_poll.iv_initial_delay == 0)
            {
                i_program.iv_poll.iv_initial_delay = cycles_to_ns(i_target, l_total_delay);
            }

            if (i_program.iv_poll.iv_initial_sim_delay == 0)
            {
                i_program.iv_poll.iv_initial_sim_delay = cycles_to_simcycles(l_total_delay);
            }

            FAPI_INF("executing ccs instructions (%d:%d, %d) for %s",
                     i_program.iv_instructions.size(), l_inst_count, i_program.iv_poll.iv_initial_delay, mss::c_str(i_target));

            // Deselect
            l_des.arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(l_current_cke);

            // Insert a DES as our last instruction. DES is idle state anyway and having this
            // here as an instruction forces the CCS engine to wait the delay specified in
            // the last instruction in this array (which it otherwise doesn't do.)
            l_des.arr1.setBit<MCBIST_CCS_INST_ARR1_00_END>();
            FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + l_inst_count, l_des.arr0), "Error in ccs::execute" );
            FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + l_inst_count, l_des.arr1), "Error in ccs::execute" );

            FAPI_INF("css inst %d fixup: 0x%016lX 0x%016lX (0x%lx, 0x%lx) %s",
                     l_inst_count, l_des.arr0, l_des.arr1,
                     CCS_ARR0_ZERO + l_inst_count, CCS_ARR1_ZERO + l_inst_count, mss::c_str(i_target));

            // Kick off the CCS engine - per port. No broadcast mode for CCS (per Shelton 9/23/15)
            FAPI_INF("executing CCS array for port %d (%s)", mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_port),
                     mss::c_str(i_port));
            FAPI_TRY( mss::ccs::select_ports<mss::mc_type::NIMBUS>( i_target, mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_port)),
                      "Error in ccs execute" );
            FAPI_TRY( execute_inst_array(i_target, i_program, i_port), "Error in ccs execute" );
        }
    }

fapi_try_exit:
    i_program.iv_instructions.clear();
    return fapi2::current_err;
}

} // ns nvdimm

namespace wr_lvl
{

///
/// @brief Updates an MRS to have the desired Qoff value
/// @param[in,out] io_mrs - the MRS to update
/// @param[in] i_state - the state for the qoff in the MRS
///
void update_mrs(mss::ddr4::mrs01_data& io_mrs, const mss::states i_state)
{
    io_mrs.iv_qoff = i_state;
    io_mrs.iv_wl_enable = i_state;
}

///
/// @brief Adds in an MRS on a per-rank basis based upon qoff
/// @param[in] i_target - the target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @param[in] i_state - the state of qoff
/// @param[in,out] io_inst the instruction to fixup
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode add_mrs(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                          const uint64_t i_rank,
                          const mss::states& i_state,
                          std::vector<ccs::instruction_t>& io_inst)
{
    // First, get the DIMM target
    // Note: the target is setup below based upon the rank
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm(0);
    FAPI_TRY( mss::rank::get_dimm_target_from_rank(i_target, i_rank, l_dimm) );

    // Updates and adds in the MRS information
    {
        // Get the MRS data
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        mss::ddr4::mrs01_data l_mrs(l_dimm, l_rc);
        FAPI_TRY( l_rc, "%s failed to create MRS for rank %lu", mss::c_str(l_dimm), i_rank);

        // Update the MRS data for qoff
        update_mrs(l_mrs, i_state);

        // Add the MRS data to the ccs instructions
        FAPI_TRY( mrs_engine(l_dimm, l_mrs, i_rank, mss::tmod(i_target), io_inst) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets a vector of ranks that are not going to be calibrated in the given rank pair
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[out] o_ranks - the vector of ranks that are not being calibrated
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode get_non_calibrating_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        std::vector<uint64_t>& o_ranks)
{
    o_ranks.clear();
    std::vector<uint64_t> l_pairs;

    // Get our rank pairs
    FAPI_TRY( mss::rank::get_rank_pairs(i_target, l_pairs) );

    // Loops through all of the rank pairs
    for(const auto l_rp : l_pairs)
    {
        // If this is our current rank pair, add in all non-primary ranks
        if(l_rp == i_rp)
        {
            FAPI_TRY( add_non_primary_ranks(i_target, l_rp, o_ranks) );
        }
        else
        {
            FAPI_TRY( add_ranks_from_pair(i_target, l_rp, o_ranks) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Adds the non-primary ranks from a rank pair to a ranks vector
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[in,out] io_ranks - the vector of ranks that are not being calibrated
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode add_non_primary_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                        const uint64_t i_rp,
                                        std::vector<uint64_t>& io_ranks)
{
    std::vector<uint64_t> l_ranks_in_pair;
    FAPI_TRY( mss::rank::get_ranks_in_pair(i_target, i_rp, l_ranks_in_pair) );

    // Loops through the ranks and adds them as need be
    {
        // Primary rank is first, so we skip that one
        const auto l_begin = l_ranks_in_pair.begin() + 1;
        const auto l_end = l_ranks_in_pair.end();

        // Loops through the ranks
        for(auto l_it = l_begin; l_it < l_end; ++l_it)
        {
            const auto l_rank = *l_it;
            add_rank_to_vector(l_rank, io_ranks);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Adds all ranks from a rank pair to a ranks vector
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[in,out] io_ranks - the vector of ranks that are not being calibrated
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode add_ranks_from_pair(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                      const uint64_t i_rp,
                                      std::vector<uint64_t>& io_ranks)
{
    std::vector<uint64_t> l_ranks_in_pair;
    FAPI_TRY( mss::rank::get_ranks_in_pair(i_target, i_rp, l_ranks_in_pair) );

    // Loops through the ranks
    for(const auto l_rank : l_ranks_in_pair)
    {
        add_rank_to_vector(l_rank, io_ranks);
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Adds a rank to the ranks vector if it is valid
/// @param[in] i_rank - the rank to add to the vector
/// @param[in,out] io_ranks - the vector of ranks that are not being calibrated
///
void add_rank_to_vector(const uint64_t i_rank, std::vector<uint64_t>& io_ranks)
{
    if(i_rank != mss::NO_RANK)
    {
        io_ranks.push_back(i_rank);
    }
}

///
/// @brief Enables or disables the DQ outputs on all non-calibrating ranks
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[in] i_state - the state of qoff
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode configure_non_calibrating_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const mss::states& i_state)
{
    // Declares variables
    ccs::program l_program;
    std::vector<uint64_t> l_ranks;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // Gets the ranks to configure
    FAPI_TRY( get_non_calibrating_ranks(i_target, i_rp, l_ranks) );

    // Adds in the MRS instructions to configure qoff
    for(const auto l_rank : l_ranks)
    {
        FAPI_TRY( add_mrs(i_target, l_rank, i_state, l_program.iv_instructions) );
    }

    // Executes the CCS instructions
    FAPI_TRY( mss::ccs::execute(l_mcbist, l_program, i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

} // ns wr_lvl

} // ns workarounds

} // ns ccs

} // ns mss
