/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_row_repair.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/// @file ody_row_repair.C
/// @brief API for DDR5 row repair HWP
///
// *HWP HWP Owner: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <lib/shared/ody_consts.H>
#include <lib/ecc/ecc_traits_odyssey.H>
#include <lib/ccs/ody_ccs_traits.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <lib/ccs/ody_row_repair.H>
#include <generic/memory/lib/ccs/ccs_ddr5_commands.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <lib/dimm/ody_rank.H>

#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <mss_generic_attribute_getters.H>
#include <mss_odyssey_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <ody_scom_ody_odc.H>

#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

namespace row_repair
{

///
/// @brief Configures registers for ccs repair execution - Odyssey specialization
/// @param[in] i_mc_target The MC target
/// @param[in] i_mem_port_target The Mem Port target
/// @param[out] o_modeq_reg A buffer to return the original value of modeq
/// @return FAPI2_RC_SUCCESS iff okay
///
template <>
fapi2::ReturnCode config_ccs_regs<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_mc_target,
        const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_mem_port_target,
        fapi2::buffer<uint64_t>& o_modeq_reg)
{
    return mss::ccs::config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(i_mc_target, o_modeq_reg);
}

} // namespace row_repair

namespace ody
{

namespace row_repair
{

///
/// @brief Creates the DRAM bitmap for row repair
/// @param[in] i_dram the DRAM on which to conduct row repairs
/// @param[out] o_dram_bitmap the DRAM bitmap on which to conduct row repairs
/// @return FAPI2_RC_SUCCESS if and only if ok
///
// TODO:ZEN:MST-2263 Update Odyssey row repair to support x8 DIMM
fapi2::ReturnCode create_dram_bitmap(const uint64_t i_dram, fapi2::buffer<uint64_t>& o_dram_bitmap)
{
    o_dram_bitmap.flush<1>();
    FAPI_TRY(o_dram_bitmap.clearBit(DRAM_START_BIT + i_dram));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Swizzle CCS bits between two fapi2 buffers, and insert from source to destination
/// @param[in,out] io_repair the address repair information
///
void swizzle_repair_entry(mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& io_repair)
{
    // swizzle srank bits
    fapi2::buffer<uint8_t> l_temp_buffer_8_in(io_repair.iv_srank);
    fapi2::buffer<uint8_t> l_temp_buffer_8_out;
    swizzle<SRANK_START, SRANK_LEN, SRANK_LAST>( l_temp_buffer_8_in, l_temp_buffer_8_out );
    io_repair.iv_srank = l_temp_buffer_8_out;

    // swizzle bank group
    l_temp_buffer_8_in = io_repair.iv_bg;
    l_temp_buffer_8_out.flush<0>();
    swizzle<BG_START, BG_LEN, BG_LAST>( l_temp_buffer_8_in, l_temp_buffer_8_out );
    io_repair.iv_bg = l_temp_buffer_8_out;

    // swizzle bank
    l_temp_buffer_8_in = io_repair.iv_bank;
    l_temp_buffer_8_out.flush<0>();
    swizzle<BANK_START, BANK_LEN, BANK_LAST>( l_temp_buffer_8_in, l_temp_buffer_8_out );
    io_repair.iv_bank = l_temp_buffer_8_out;

    // swizzle row
    fapi2::buffer<uint32_t> l_temp_buffer_32_in(io_repair.iv_row);
    fapi2::buffer<uint32_t> l_temp_buffer_32_out;
    swizzle<ROW_START, ROW_LEN, ROW_LAST>( l_temp_buffer_32_in, l_temp_buffer_32_out );
    io_repair.iv_row = l_temp_buffer_32_out;
}

///
/// @brief Perform a sPPR row repair operation
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in, out] io_program the ccs program to setup for row repair
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_sppr( const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                              const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair,
                              mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    // Variable Declarations
    uint64_t l_freq = 0;

    // Use rank to determine ranks and targets
    // Get port rank and target
    const auto& l_port_target = i_rank_info.get_port_target();
    const auto& l_port_rank = i_rank_info.get_port_rank();

    // Get dimm rank and target
    const auto& l_dimm_target = i_rank_info.get_dimm_target();

    // Get the OCMB target
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Declare timings
    // tMRD value is taken from Table 20 of JEDEC spec revision JESD79-5B_v1.20
    const uint64_t tMRD = 34;
    // WL delay
    constexpr uint64_t WL = 128;

    uint8_t tRCD = 0;
    uint8_t tWR = 0;
    uint8_t tRP = 0;
    uint8_t l_odt_attr[4];

    // Commands and MR declarations
    constexpr uint8_t MR24_GUARD_KEY = 24;
    constexpr uint8_t MR23_PPR = 23;
    constexpr uint8_t ENABLE_SPPR = 0b00000010;
    constexpr uint8_t EXIT_SPPR = 0b00000000;

    // Copy and update the inputted class's address swizzle
    auto l_repair = i_repair;
    swizzle_repair_entry(l_repair);

    // Get timing from API and attributes
    FAPI_TRY( mss::attr::get_dram_trcd(l_port_target, tRCD) );
    FAPI_TRY( mss::attr::get_dram_twr(l_port_target, tWR) );
    FAPI_TRY( mss::attr::get_dram_trp(l_port_target, tRP) );

    // Get freq from attributes:
    FAPI_TRY( mss::freq<mss::mc_type::ODYSSEY>(l_ocmb_target, l_freq),
              "Failed to retrieve freq values on ",
              GENTARGTIDFORMAT, GENTARGTID(l_ocmb_target) );

    // Get ODT bits for ccs
    FAPI_TRY( mss::attr::get_si_odt_wr(l_dimm_target, l_odt_attr) );
    // TODO: ZEN-MST1680: Add DDR5 CCS ODT functionality

    //-------------------------------
    // SPPR COMMAND:
    //-------------------------------

    // 0. Add des command - handled by CCS execute

    // 1. Back up data.
    //    For static:
    //      Repairs deployed as part of draminit_mc, are done before memory contains valid data.
    //      So no need to backup/restore data in this case.
    //    For dynamic:
    //       Repairs are performed during runtime.
    //       In this case the memory controller will clean up after the row repair
    // 2. Check shared hppr resource destination registers (MR 54, 55, 56, 57)
    //    TODO: ZEN-MST:2222 Check shared hppr/sppr resource destination registers for row repair

    // 3. Precharge_all(): Create instruction for precharge and add it to the instruction array.
    io_program.iv_instructions.push_back(mss::ccs::ddr5::precharge_all_command<mss::mc_type::ODYSSEY>(l_port_rank,
                                         l_repair.iv_srank, tRP));

    FAPI_MFG( "Running srank fix on dimm " GENTARGTIDFORMAT "with srank %d", GENTARGTID(l_dimm_target), i_repair.iv_srank );

    // 4. Enable sPPR using MR23 bits "OP[2:1]=01" and wait tMRD.
    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>(l_port_rank, MR23_PPR,
                                         ENABLE_SPPR, tMRD));

    // 5. Guard Key Sequence:
    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                         (l_port_rank, MR24_GUARD_KEY, GUARDKEY_SEQ_ONE, tMRD));

    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                         (l_port_rank, MR24_GUARD_KEY, GUARDKEY_SEQ_TWO, tMRD));

    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                         (l_port_rank, MR24_GUARD_KEY, GUARDKEY_SEQ_THREE, tMRD));

    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                         (l_port_rank, MR24_GUARD_KEY, GUARDKEY_SEQ_FOUR, tMRD));

    // 6. ACT to failed bank/address
    io_program.iv_instructions.push_back(mss::ccs::ddr5::act_command<mss::mc_type::ODYSSEY>(l_port_rank, l_repair.iv_srank,
                                         l_repair.iv_bg, l_repair.iv_bank, l_repair.iv_row, tRCD));

    // Write + enable the data (and wait tPGM_sPPR => WL + 8 + tWR)
    {
        typedef ccsTraits<mss::mc_type::ODYSSEY> TT;
        constexpr auto BC_MODE = mss::states::OFF_N;
        constexpr auto PARTIAL_WRITE_MODE = mss::states::OFF_N;
        // The write to precharge delay is added after the data enables
        const uint64_t WR_TO_PRE_DELAY = 8 + tWR + WL;

        // 7. WR Command with dq bits low:
        auto l_inst_temp = mss::ccs::ddr5::wr_command<mss::mc_type::ODYSSEY>(l_port_rank, l_repair.iv_srank,
                           l_repair.iv_bg, l_repair.iv_bank, l_repair.iv_row, BC_MODE, PARTIAL_WRITE_MODE);
        fapi2::buffer<uint64_t> l_dram_bitmap;
        FAPI_TRY(create_dram_bitmap(l_repair.iv_dram, l_dram_bitmap));

        // Add the data to array 1
        l_inst_temp.arr1.template insertFromRight<TT::ARR1_READ_OR_WRITE_DATA, TT::ARR1_READ_OR_WRITE_DATA_LEN>(l_dram_bitmap);

        // 8. After WL, DQ[3:0] of the individual Target DRAM must be LOW for 8tCK
        // TODO: ZEN-MST1680: Add DDR5 CCS ODT functionality
        // update_ODT(l_idle = 0);
        FAPI_TRY(mss::ccs::ddr5::update_wr_to_wr_data_enable_timing<mss::mc_type::ODYSSEY>(l_port_target, l_inst_temp));
        io_program.iv_instructions.push_back(l_inst_temp);
        mss::ccs::ddr5::append_wr_data_enable_command<mss::mc_type::ODYSSEY>(l_port_rank, io_program.iv_instructions, false,
                WR_TO_PRE_DELAY);
    }

    // 9. PRE to Bank (and wait tPGM_Exit => tRP)
    // 10. Wait tRP to allow the DRAM to recognize repaired Row address (tRP comes from here)
    {
        // Delay for PRE command
        io_program.iv_instructions.push_back(mss::ccs::ddr5::precharge_bank_command<mss::mc_type::ODYSSEY>(l_port_rank,
                                             l_repair.iv_srank,
                                             l_repair.iv_bg, l_repair.iv_bank, tRP));
    }

    // 11. Exit sPPR with setting MR23 bit "OP[2:1]=00" and wait tMRD
    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>(l_port_rank, MR23_PPR,
                                         EXIT_SPPR, tMRD));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a sPPR row repair operation at runtime
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dynamic_row_repair( const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                      const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair)
{
    using CCS = ccsTraits<mss::mc_type::ODYSSEY>;
    using MCB = mss::mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_modeq_reg;
    fapi2::buffer<uint64_t> l_mcbist_status;
    fapi2::buffer<uint64_t> l_ccs_status;
    fapi2::buffer<uint64_t> l_reg_data;
    bool l_poll_result = false;

    // Get port rank and target
    const auto& l_port_target = i_rank_info.get_port_target();

    // Get OCMB Target
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Create Program
    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

    // Add des command to ensure that there's no timing violations between a refresh and another command
    // The time for this is tRFC
    // This is 410ns -> 984 clocks. rounded up to 1000 for saftey
    // Note: assuming that we will not be in powerdown or selftime refresh as it's unclear what happens when a PDX/SRX is done on an idle DRAM
    constexpr uint16_t POWER_DOWN_EXIT_DELAY = 1000;
    l_program.iv_instructions.push_back(mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(POWER_DOWN_EXIT_DELAY));

    // Setup SPPR CCS program
    FAPI_TRY( setup_sppr(i_rank_info, i_repair, l_program),
              "Failed sppr program setup for dynamic_row_repair on ",
              GENTARGTIDFORMAT, GENTARGTID(l_port_target) );

    // Stop the CCS engine just for giggles - it might be running ...
    FAPI_TRY( mss::ccs::start_stop<mss::mc_type::ODYSSEY>(l_ocmb_target, mss::states::STOP),
              "Error stopping CCS engine before ccs::execution on ",
              GENTARGTIDFORMAT, GENTARGTID(l_ocmb_target) );

    // Verify that the in-progress bit has not been set for CCS, meaning no other CCS is running
    l_poll_result = mss::poll(l_ocmb_target, CCS::STATQ_REG, poll_parameters(),
                              [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("ccs statq (stop) " UINT64FORMAT ", remaining: %d", UINT64_VALUE(stat_reg), poll_remaining);
        // We're done polling when we see ccs is not in progress.
        return stat_reg.getBit<CCS::CCS_IN_PROGRESS>() != 1;
    });

    // Check that ccs is not being used after poll
    FAPI_ASSERT(l_poll_result == true,
                fapi2::ODY_ROW_REPAIR_CCS_STUCK_IN_PROGRESS().
                set_OCMB_TARGET(l_ocmb_target),
                GENTARGTIDFORMAT
                " CCS engine is in use and is not available for repair",
                GENTARGTID(l_ocmb_target));

    // Stop any ongoing MCBIST command
    FAPI_TRY( mss::memdiags::stop<mss::mc_type::ODYSSEY>(l_ocmb_target),
              "MCBIST engine failed to stop current command in progress on ",
              GENTARGTIDFORMAT, GENTARGTID(l_ocmb_target) );

    // Verify that the in-progress bit has not been set for MCBIST, meaning the MCBIST is free
    l_poll_result = mss::poll(l_ocmb_target, MCB::STATQ_REG, poll_parameters(),
                              [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("mcbist statq (stop) ", UINT64FORMAT ", remaining: %d", UINT64_VALUE(stat_reg), poll_remaining);
        // We're done polling when we see mcbist is not in progress.
        return stat_reg.getBit<MCB::MCBIST_IN_PROGRESS>() != 1;
    });

    // Check that mcbist is not being used after poll
    FAPI_ASSERT(l_poll_result == true,
                fapi2::ODY_ROW_REPAIR_MCBIST_STUCK_IN_PROGRESS().
                set_OCMB_TARGET(l_ocmb_target),
                GENTARGTIDFORMAT
                " MCBIST failed to exit previous command and is not available for repair",
                GENTARGTID(l_ocmb_target));

    FAPI_INF(GENTARGTIDFORMAT " Deploying dynamic row repair", GENTARGTID(l_ocmb_target));

    // Configure CCS regs for execution
    FAPI_TRY( mss::ccs::config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg ) );

    // Backup ODC_SRQ_MBA_FARB0Q value before running Concurrent CCS
    FAPI_TRY( mss::ccs::pre_execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb_target, l_reg_data) );

    // Run CCS via MCBIST for Concurrent CCS
    FAPI_TRY( mss::ccs::execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb_target, l_program, l_port_target) );

    // Restore ODC_SRQ_MBA_FARB0Q value after running Concurrent CCS
    FAPI_TRY( mss::ccs::post_execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb_target, l_reg_data) );

    // Revert CCS regs after execution
    FAPI_TRY( mss::ccs::revert_config_regs<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a sPPR row repair operation during the IPL
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode standalone_row_repair( const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair)
{
    using CCS = ccsTraits<mss::mc_type::ODYSSEY>;

    fapi2::buffer<uint64_t> l_modeq_reg;
    fapi2::buffer<uint64_t> l_mcbist_status;
    fapi2::buffer<uint64_t> l_ccs_status;
    fapi2::buffer<uint64_t> l_reg_data;
    bool l_poll_result = false;

    // Get port rank and target
    const auto& l_port_target = i_rank_info.get_port_target();

    // Get OCMB Target
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Create Program
    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

    // Add des command to ensure that there's no timing violations between a refresh and another command
    // The time for this is tRFC
    // This is 410ns -> 984 clocks. rounded up to 1000 for saftey
    // Note: assuming that we will not be in powerdown or selftime refresh as it's unclear what happens when a PDX/SRX is done on an idle DRAM
    constexpr uint16_t POWER_DOWN_EXIT_DELAY = 1000;
    l_program.iv_instructions.push_back(mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(POWER_DOWN_EXIT_DELAY));

    // Setup SPPR CCS program
    FAPI_TRY( setup_sppr(i_rank_info, i_repair, l_program),
              "Failed sppr program setup for dynamic_row_repair on ",
              GENTARGTIDFORMAT, GENTARGTID(l_port_target) );

    // Stop the CCS engine just for giggles - it might be running ...
    FAPI_TRY( mss::ccs::start_stop<mss::mc_type::ODYSSEY>(l_ocmb_target, mss::states::STOP),
              "Error stopping CCS engine before ccs::execution on ",
              GENTARGTIDFORMAT, GENTARGTID(l_ocmb_target) );

    // Verify that the in-progress bit has not been set for CCS, meaning no other CCS is running
    l_poll_result = mss::poll(l_ocmb_target, CCS::STATQ_REG, poll_parameters(),
                              [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("ccs statq (stop) " UINT64FORMAT ", remaining: %d", UINT64_VALUE(stat_reg), poll_remaining);
        // We're done polling when we see ccs is not in progress.
        return stat_reg.getBit<CCS::CCS_IN_PROGRESS>() != 1;
    });

    // Check that ccs is not being used after poll
    FAPI_ASSERT(l_poll_result == true,
                fapi2::ODY_ROW_REPAIR_CCS_STUCK_IN_PROGRESS().
                set_OCMB_TARGET(l_ocmb_target),
                GENTARGTIDFORMAT
                " CCS engine is in use and is not available for repair",
                GENTARGTID(l_ocmb_target));



    FAPI_INF(GENTARGTIDFORMAT " Deploying row repair using standalone CCS", GENTARGTID(l_ocmb_target));

    // Configure CCS regs for execution
    FAPI_TRY( mss::ccs::config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg ) );

    // Run CCS standalone execution
    FAPI_TRY( mss::ccs::execute<mss::mc_type::ODYSSEY>(l_ocmb_target, l_program, l_port_target) );

    // Revert CCS regs after execution
    FAPI_TRY( mss::ccs::revert_config_regs<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg) );

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace row_repair
} // namespace ody
} // namespace mss
