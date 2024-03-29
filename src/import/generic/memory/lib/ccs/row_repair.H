/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ccs/row_repair.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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

/// @file row_repair.H
/// @brief Contains functions necessary for row repair
///
// *HWP HWP Owner: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory HWP
// EKB-Mirror-To: hostboot

#ifndef __ROW_REPAIR_FUNCTIONS__
#define __ROW_REPAIR_FUNCTIONS__

#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <generic/memory/lib/dimm/mrs_traits.H>
#include <generic/memory/lib/utils/mc/gen_mss_port_traits.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <mss_generic_system_attribute_getters.H>
#ifndef __PPE__
    #include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
    #include <generic/memory/lib/ccs/ccs_ddr4_commands.H>
#endif

namespace mss
{

#ifndef __PPE__
// CCS functions related to SPPR
// Uses mrs and ccs api so here to utilize both
namespace ccs
{

namespace ddr4
{


///
/// @brief Adds a delay to the ccs instruction, performing necessary mirroring/swizzling
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_rank_info rank information class
/// @param[in] i_delay_in_cyles The delay to be added after instruction
/// @param[in,out] io_inst_a_side The ccs instruction to process
/// @param[in,out] io_inst The vector of ccs instructions to add to
/// @return FAPI2_RC_SUCCESS iff okay
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
fapi2::ReturnCode process_inst(const mss::rank::info<MC>& i_rank_info,
                               const uint64_t i_delay_in_cycles,
                               mss::ccs::instruction_t<MC>& io_instruction,
                               std::vector< mss::ccs::instruction_t<MC> >& io_inst)
{
    // Insert the delay into arr1 (conroll reg)
    io_instruction.iv_idles = i_delay_in_cycles;

    // Add both to the CCS program
    io_inst.push_back(io_instruction);

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Set the col bits of the passed in instruction array
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_column_addr Column Address
/// @param[in, out] io_inst The ccs instruction to add to
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void set_col_addr( const fapi2::buffer<uint64_t>& i_column_addr,
                   mss::ccs::instruction_t<MC>& io_inst)
{
    // Column Address is A[0:9]
    io_inst.arr0.template insertFromRight<TT::ARR0_DDR_ADDRESS_0_9,
                          TT::ARR0_DDR_ADDRESS_0_9_LEN>(i_column_addr);
}

///
/// @brief Set the row bits of the passed in instruction array
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_row_addr Row Address
/// @param[in, out] io_inst The ccs instruction to add to
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void set_row_addr( const fapi2::buffer<uint64_t>& i_row_addr,
                   mss::ccs::instruction_t<MC>& io_inst)
{
    constexpr uint64_t LAST_ADDR_BIT = 63;
    constexpr uint64_t LAST_ROW_BIT = 17;

    // Set Row address:
    // Insert reversed from input
    io_inst.arr0.template insert < TT::ARR0_DDR_ADDRESS_0_13,
                          TT::ARR0_DDR_ADDRESS_0_13_LEN, LAST_ADDR_BIT - LAST_ROW_BIT > (i_row_addr);
    io_inst.arr0.template writeBit<TT::ARR0_DDR_ADDRESS_14>(i_row_addr.getBit<60>());
    io_inst.arr0.template writeBit<TT::ARR0_DDR_ADDRESS_15>(i_row_addr.getBit<61>());
    io_inst.arr0.template writeBit<TT::ARR0_DDR_ADDRESS_16>(i_row_addr.getBit<62>());
    io_inst.arr0.template writeBit<TT::ARR0_DDR_ADDRESS_17>(i_row_addr.getBit<63>());
}

///
/// @brief Set the bank bits of the passed in instruction array
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_bank_addr Bank Address
/// @param[in] i_bank_group_addr Bank Group Address
/// @param[in, out] io_inst The ccs instruction to add to
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void set_bank_group_addr( const fapi2::buffer<uint64_t>& i_bank_addr,
                          const fapi2::buffer<uint64_t>& i_bank_group_addr,
                          mss::ccs::instruction_t<MC>& io_inst)
{
    // The row repair attribute includes BA2, which doesn't exist for DDR4
    // We want to grab BA0 and BA1
    constexpr uint64_t BA0 = 61;
    // Set Bank Bits
    io_inst.arr0.template insert<TT::ARR0_DDR_BANK_0_1,
                          TT::ARR0_DDR_BANK_0_1_LEN, BA0>(i_bank_addr);

    // Bank Group bits aren't contiguous
    constexpr uint64_t BG0_BIT = 62;
    constexpr uint64_t BG1_BIT = 63;

    // Set Bank Group Bits
    io_inst.arr0.template writeBit<TT::ARR0_DDR_BANK_GROUP_0>(i_bank_group_addr.getBit<BG0_BIT>())
    .template writeBit<TT::ARR0_DDR_BANK_GROUP_1>(i_bank_group_addr.getBit<BG1_BIT>());
}

///
/// @brief Set the row bits of the passed in instruction array
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_row_addr Row Address
/// @param[in, out] io_inst The ccs instruction to add to
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void set_srank_addr( const fapi2::buffer<uint64_t>& i_srank_addr,
                     mss::ccs::instruction_t<MC>& io_inst)
{
    // Sub-rank bits aren't contiguous
    constexpr uint64_t CID01_BIT = 61;
    constexpr uint64_t CID_2_BIT = 63;

    // Sub-rank is used for the Chip ID Bits
    io_inst.arr0.template insert<TT::ARR0_DDR_CID_0_1,
                          TT::ARR0_DDR_CID_0_1_LEN, CID01_BIT>(i_srank_addr);
    io_inst.arr0.template writeBit<TT::ARR0_DDR_CID_2>(i_srank_addr.getBit<CID_2_BIT>());

    FAPI_MFG("Debug srank information: srank bit 0: %d 1: %d 2: %d",
             i_srank_addr.getBit<CID01_BIT>(), i_srank_addr.getBit < CID01_BIT + 1 > (), i_srank_addr.getBit<CID_2_BIT>());
}

///
/// @brief Set odt bits in INST_ARR0 for a ccs write command
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_odt_bits the odt bits to set
/// @param[in, out] io_inst The ccs instruction to add to
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void set_odt_bits( const uint8_t i_odt_bits,
                   mss::ccs::instruction_t<MC>& io_inst )
{
    // set data
    io_inst.arr0.template insertFromRight<TT::ARR0_DDR_ODT, TT::ARR0_DDR_ODT_LEN>(i_odt_bits);
}

///
/// @brief Loads an Activate command to the program of ccs instructions
/// @tparam MC the memory controller type which executes the CCS instruction
/// @param[in] i_rank_info Rank information class
/// @param[in] i_bank_addr Bank Address
/// @param[in] i_bank_group_addr Bank Group Address
/// @param[in] i_row_addr Row Address to activate
/// @param[in] i_srank_addr Sub-Rank Address to activate
/// @param[in] i_delay_in_cycles Delay to add after instruction
/// @return ccs::instruction_t for a loaded act command
///
template< mss::mc_type MC >
mss::ccs::instruction_t<MC> act_load( const mss::rank::info<MC>& i_rank_info,
                                      const fapi2::buffer<uint64_t>& i_bank_addr,
                                      const fapi2::buffer<uint64_t>& i_bank_group_addr,
                                      const fapi2::buffer<uint64_t>& i_row_addr,
                                      const fapi2::buffer<uint64_t>& i_srank_addr,
                                      const uint64_t i_delay_in_cycles )
{
    // Create Activate command
    mss::ccs::instruction_t<MC> l_inst = mss::ccs::ddr4::act_command<MC>(i_rank_info.get_port_rank());

    // Set Sub-rank address
    set_srank_addr<MC>(i_srank_addr, l_inst);

    // Set Row address
    set_row_addr<MC>(i_row_addr, l_inst);

    // Set Bank address
    set_bank_group_addr<MC>(i_bank_addr, i_bank_group_addr, l_inst);

    return l_inst;
}

///
/// @brief Loads a WRITE command to the program of ccs instructions
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_rank_info Rank information class
/// @param[in] i_bank_addr Bank Address
/// @param[in] i_bank_group_addr Bank Group Address
/// @param[in] i_srank_addr Sub-Rank Address to activate
/// @param[in] i_delay_in_cycles Delay to add after instruction
/// @return ccs::instruction_t for a loaded act command
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
mss::ccs::instruction_t<MC> wr_load( const mss::rank::info<MC>& i_rank_info,
                                     const fapi2::buffer<uint64_t>& i_bank_addr,
                                     const fapi2::buffer<uint64_t>& i_bank_group_addr,
                                     const fapi2::buffer<uint64_t>& i_srank_addr,
                                     const uint64_t i_delay_in_cycles)
{
    // Need to shift the bank address because it comes in as BA[0:2] and the wr_command function expects BA[0:1]
    constexpr uint64_t BA0 = 61;
    constexpr uint64_t CORRECTED_BA0 = 62;

    fapi2::buffer<uint64_t> l_corrected_bank_addr;
    l_corrected_bank_addr.template insert<CORRECTED_BA0,
                                   TT::ARR0_DDR_BANK_0_1_LEN, BA0>(i_bank_addr);

    // Create Write command
    mss::ccs::instruction_t<MC> l_inst = mss::ccs::ddr4::wr_command<MC>(i_rank_info.get_port_rank(),
                                         l_corrected_bank_addr,
                                         i_bank_group_addr);

    // Set Sub-rank address
    set_srank_addr<MC>(i_srank_addr, l_inst);

    // Set A10 low
    l_inst.arr0.template clearBit<TT::ARR0_DDR_ADDRESS_10>();
    // Set A12 hi for burst 8
    l_inst.arr0.template setBit<TT::ARR0_DDR_ADDRESS_12>();

    return l_inst;
}

///
/// @brief Loads a PRECHARGE command to the program of ccs instructions
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_rank_info Rank information class
/// @param[in] i_bank_addr Buffer of all Bank Addresses
/// @param[in] i_bank_group_addr Buffer of all Bank Group Addresses
/// @param[in] i_srank_addr Sub-Rank Address to activate
/// @param[in] i_delay_in_cycles Delay to add after instruction
/// @return ccs::instruction_t for a loaded act command
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
mss::ccs::instruction_t<MC> pre_load( const mss::rank::info<MC>& i_rank_info,
                                      const fapi2::buffer<uint64_t>& i_bank_addr,
                                      const fapi2::buffer<uint64_t>& i_bank_group_addr,
                                      const fapi2::buffer<uint64_t>& i_srank_addr,
                                      const uint64_t i_delay_in_cycles)
{
    // Create Precharge command
    mss::ccs::instruction_t<MC> l_inst = mss::ccs::ddr4::precharge_all_command<MC>(i_rank_info.get_port_rank(),
                                         i_delay_in_cycles);

    // Set Sub-rank address
    set_srank_addr<MC>(i_srank_addr, l_inst);

    // Set Bank address
    set_bank_group_addr<MC>( i_bank_addr, i_bank_group_addr, l_inst );

    // Set A10 low
    l_inst.arr0.template clearBit<TT::ARR0_DDR_ADDRESS_10>();

    return l_inst;
}

///
/// @brief Loads a PRECHARGE command for the initial sppr ccs instruction
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_rank_info Rank information class
/// @param[in] i_srank_addr Sub-Rank Address to activate
/// @return ccs::instruction_t for a loaded precharge command
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
mss::ccs::instruction_t<MC> init_pre_load( const mss::rank::info<MC>& i_rank_info,
        const fapi2::buffer<uint64_t>& i_srank_addr)
{
    // Create Precharge command
    mss::ccs::instruction_t<MC> l_inst = mss::ccs::ddr4::precharge_all_command<MC>(i_rank_info.get_port_rank());

    // Set Sub-rank address
    set_srank_addr<MC>(i_srank_addr, l_inst);

    return l_inst;
}

}// namespace ddr4

///
/// @brief Set number of repeats in INST_ARR1 for a ccs write command
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_rep number of repeats
/// @param[in, out] io_inst The ccs instruction to add to
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void set_wr_repeats( const uint64_t i_rep,
                     mss::ccs::instruction_t<MC>& io_inst )
{
    // set data
    io_inst.iv_repeats = i_rep;
}

}// namespace ccs
#endif

// Row Repair specific functions
namespace row_repair
{

///
/// @brief A row repair entry
/// @tparam MC the memory controller type which executes the CCS instruction
/// @note contains repair data from the attribute
/// Bit formats for the internal variables follow the attribute and how they were logged from the hardware
/// Format: field (start_bit:end_bit) - bits are right justified in the fields
/// iv_srank (0:2)
/// iv_bg    (0:1) for DDR4, (0:2) for DDR5
/// iv_ba    (0:2) for DDR4, (0:1) for DDR5
/// iv_row   (0:17)
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
struct repair_entry
{
    bool iv_valid = true;
    uint8_t iv_dimm_rank = 0;
    uint8_t iv_dram = 0;
    uint8_t iv_srank = 0;
    uint8_t iv_bg = 0;
    uint8_t iv_bank = 0;
    uint32_t iv_row = 0;

    ///
    /// @brief repair_entry ctor
    /// @param[in] i_buffer the attr row repair data
    /// @param[in] i_dimm_rank the dimm rank number of the repair
    ///
    repair_entry( const fapi2::buffer<uint32_t>& i_buffer, const uint8_t i_dimm_rank):
        iv_valid(i_buffer.getBit<TT::ROW_REPAIR_VALID>())
    {
        fapi2::buffer<uint32_t> l_data;
        iv_dimm_rank = i_dimm_rank;
        i_buffer.extractToRight<TT::ROW_REPAIR_DRAM_POS, TT::ROW_REPAIR_DRAM_POS_LEN>(iv_dram);

        // srank, BG, BA, and row address are stored in reverse bit order in the VPD, so need to swizzle these values
        mss::swizzle < 32 - TT::ROW_REPAIR_SRANK_LEN,
            TT::ROW_REPAIR_SRANK_LEN,
            TT::ROW_REPAIR_SRANK + TT::ROW_REPAIR_SRANK_LEN - 1 > (i_buffer, l_data);
        iv_srank = l_data;

        l_data.flush<0>();
        mss::swizzle < 32 - TT::ROW_REPAIR_BANK_GROUP_LEN,
            TT::ROW_REPAIR_BANK_GROUP_LEN,
            TT::ROW_REPAIR_BANK_GROUP + TT::ROW_REPAIR_BANK_GROUP_LEN - 1 > (i_buffer, l_data);
        iv_bg = l_data;

        l_data.flush<0>();
        mss::swizzle < 32 - TT::ROW_REPAIR_BANK_LEN,
            TT::ROW_REPAIR_BANK_LEN,
            TT::ROW_REPAIR_BANK + TT::ROW_REPAIR_BANK_LEN - 1 > (i_buffer, l_data);
        iv_bank = l_data;

        l_data.flush<0>();
        mss::swizzle < 32 - TT::ROW_REPAIR_ROW_ADDR_LEN,
            TT::ROW_REPAIR_ROW_ADDR_LEN,
            TT::ROW_REPAIR_ROW_ADDR + TT::ROW_REPAIR_ROW_ADDR_LEN - 1 > (i_buffer, l_data);
        iv_row = l_data;
    }

    ///
    /// @brief repair_entry ctor
    /// @param[in] i_valid the repair valid bit
    /// @param[in] i_dimm_rank the dimm rank number of the repair
    /// @param[in] i_dram the dram for the repair
    /// @param[in] i_srank the slave rank for the repair
    /// @param[in] i_bg the bank group for the repair
    /// @param[in] i_bank the bank for the repair
    /// @param[in] i_row the row for the repair
    ///
    repair_entry( const bool i_valid = false,
                  const uint8_t i_dimm_rank = 0,
                  const uint8_t i_dram = 0,
                  const uint8_t i_srank = 0,
                  const uint8_t i_bg = 0,
                  const uint8_t i_bank = 0,
                  const uint32_t i_row = 0 ):
        iv_valid(i_valid),
        iv_dimm_rank(i_dimm_rank),
        iv_dram(i_dram),
        iv_srank(i_srank),
        iv_bg(i_bg),
        iv_bank(i_bank),
        iv_row(i_row)
    {
    }

    ///
    /// @brief Returns valid bit of repair
    /// @return True if repair is valid, false otherwise
    ///
    bool is_valid() const
    {
        return iv_valid;
    }

    ///
    /// @brief Equals comparison operator
    /// @param[in] i_rhs - the repair_entry to compare to
    /// @return True if both instructions are equal
    ///
    inline bool operator==( const repair_entry& i_rhs ) const
    {
        FAPI_DBG("Comparing repair: DRAM %d, dimm rank %d, subrank %d, bg %d, bank %d, row 0x%05x",
                 iv_dram, iv_dimm_rank, iv_srank, iv_bg, iv_bank, iv_row);
        FAPI_DBG("To second repair: DRAM %d, dimm rank %d, subrank %d, bg %d, bank %d, row 0x%05x",
                 i_rhs.iv_dram, i_rhs.iv_dimm_rank, i_rhs.iv_srank, i_rhs.iv_bg, i_rhs.iv_bank, i_rhs.iv_row);
        return iv_dram == i_rhs.iv_dram &&
               iv_dimm_rank == i_rhs.iv_dimm_rank &&
               iv_srank == i_rhs.iv_srank &&
               iv_bg == i_rhs.iv_bg &&
               iv_bank == i_rhs.iv_bank &&
               iv_row == i_rhs.iv_row &&
               iv_valid == i_rhs.iv_valid;
    }

    ///
    /// @brief Equals assign operator
    /// @param[in] i_rhs - the repair_entry to compare to
    /// @return True if both instructions are equal
    ///
    inline void operator=( const repair_entry& i_rhs )
    {
        iv_dram = i_rhs.iv_dram;
        iv_dimm_rank = i_rhs.iv_dimm_rank;
        iv_srank = i_rhs.iv_srank;
        iv_bg = i_rhs.iv_bg;
        iv_bank = i_rhs.iv_bank;
        iv_row = i_rhs.iv_row;
        iv_valid = i_rhs.iv_valid;
    }


    ///
    /// @brief default dtor
    ///
    ~repair_entry() = default;
} __attribute__ ((aligned (8)));

///
/// @brief Configures registers for ccs repair execution
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT ccsTraits for MC
/// @tparam PT portTraits for MC
/// @param[in] i_mc_target The MC target
/// @param[in] i_mem_port_target The Mem Port target
/// @param[out] o_modeq_reg A buffer to return the original value of modeq
/// @return FAPI2_RC_SUCCESS iff okay
///
template < mss::mc_type MC, typename TT = ccsTraits<MC>, typename PT = mss::portTraits<MC> >
fapi2::ReturnCode config_ccs_regs(const fapi2::Target<PT::MC_TARGET_TYPE>& i_mc_target,
                                  const fapi2::Target<PT::PORT_TYPE>& i_mem_port_target,
                                  fapi2::buffer<uint64_t>& o_modeq_reg);

} // row repair
} // mss
#endif
