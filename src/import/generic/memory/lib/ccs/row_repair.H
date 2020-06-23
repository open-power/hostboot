/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ccs/row_repair.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
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
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <generic/memory/lib/utils/mc/gen_mss_port_traits.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>

namespace mss
{

// CCS functions related to SPPR
// Uses mrs and ccs api so here to utilize both
namespace ccs
{

///
/// @brief Adds a delay to the ccs instruction, performing necessary mirroring/swizzling
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_rank rank
/// @param[in] i_delay_in_cyles The delay to be added after instruction
/// @param[in,out] io_inst_a_side The ccs instruction to process
/// @param[in,out] io_inst The vector of ccs instructions to add to
/// @return FAPI2_RC_SUCCESS iff okay
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
fapi2::ReturnCode process_inst(const mss::rank::info<MC>& i_rank,
                               const uint64_t i_delay_in_cycles,
                               mss::ccs::instruction_t& io_instruction,
                               std::vector< mss::ccs::instruction_t >& io_inst)
{
    const auto l_port_rank = i_rank.get_port_rank();
    const auto l_dimm_target = i_rank.get_dimm_target();

    // Perform Address Mirroring if necessary
    FAPI_TRY( mss::address_mirror<MC>(l_dimm_target, l_port_rank, io_instruction),
              "Failed mirroring rank %d on %s",
              l_port_rank, mss::c_str(l_dimm_target) );

    // Insert the delay into arr1 (conroll reg)
    io_instruction.arr1.template insertFromRight < TT::ARR1_IDLES,
                                 TT::ARR1_IDLES_LEN>(i_delay_in_cycles);

    // Add both to the CCS program
    io_inst.push_back(io_instruction);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
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
                   mss::ccs::instruction_t& io_inst)
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
                   mss::ccs::instruction_t& io_inst)
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
                          mss::ccs::instruction_t& io_inst)
{
    // Set Bank Bits
    io_inst.arr0.template insertFromRight<TT::ARR0_DDR_BANK_0_1,
                          TT::ARR0_DDR_BANK_0_1_LEN>(i_bank_addr);

    // Bank Group bits aren't contiguous
    constexpr uint64_t BG0_BIT = 62;
    constexpr uint64_t BG1_BIT = 63;

    // Set Bank Group Bits
    io_inst.arr0.template writeBit<TT::ARR0_DDR_BANK_GROUP_0>(i_bank_group_addr.getBit<BG0_BIT>())
    .template writeBit<TT::ARR0_DDR_BANK_GROUP_1>(i_bank_group_addr.getBit<BG1_BIT>());
}

///
/// @brief Set number of repeats in INST_ARR1 for a ccs write command
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_rep number of repeats
/// @param[in, out] io_inst The ccs instruction to add to
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void set_wr_repeats( const uint64_t i_rep,
                     mss::ccs::instruction_t& io_inst )
{
    // set data
    io_inst.arr1.template insertFromRight<TT::ARR1_REPEAT_CMD_CNT,
                          TT::ARR1_REPEAT_CMD_CNT_LEN>(i_rep);
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
                   mss::ccs::instruction_t& io_inst )
{
    // set data
    io_inst.arr0.template insertFromRight<TT::ARR0_DDR_ODT, TT::ARR0_DDR_ODT_LEN>(i_odt_bits);
}

///
/// @brief Loads an Activate command to the program of ccs instructions
/// @tparam MC the memory controller type which executes the CCS instruction
/// @param[in] i_rank Rank
/// @param[in] i_bank_addr Bank Address
/// @param[in] i_bank_group_addr Bank Group Address
/// @param[in] i_row_addr Row Address to activate
/// @param[in] i_delay_in_cycles Delay to add after instruction
/// @return ccs::instruction_t for a loaded act command
///
template< mss::mc_type MC >
mss::ccs::instruction_t act_load( const mss::rank::info<MC>& i_rank,
                                  const fapi2::buffer<uint64_t>& i_bank_addr,
                                  const fapi2::buffer<uint64_t>& i_bank_group_addr,
                                  const fapi2::buffer<uint64_t>& i_row_addr,
                                  const uint64_t i_delay_in_cycles )
{
    // Create Activate command
    mss::ccs::instruction_t l_inst = act_command(i_rank.get_port_rank());

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
/// @param[in] i_rank Rank
/// @param[in] i_bank_addr Bank Address
/// @param[in] i_bank_group_addr Bank Group Address
/// @param[in] i_delay_in_cycles Delay to add after instruction
/// @return ccs::instruction_t for a loaded act command
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
mss::ccs::instruction_t wr_load( const mss::rank::info<MC>& i_rank,
                                 const fapi2::buffer<uint64_t>& i_bank_addr,
                                 const fapi2::buffer<uint64_t>& i_bank_group_addr,
                                 const uint64_t i_delay_in_cycles)
{
    // Create Write command
    mss::ccs::instruction_t l_inst = wr_command(i_rank.get_port_rank(), i_bank_addr, i_bank_group_addr);

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
/// @param[in] i_rank Rank
/// @param[in] i_bank_addr Buffer of all Bank Addresses
/// @param[in] i_bank_group_addr Buffer of all Bank Group Addresses
/// @param[in] i_delay_in_cycles Delay to add after instruction
/// @return ccs::instruction_t for a loaded act command
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
mss::ccs::instruction_t pre_load( const mss::rank::info<MC>& i_rank,
                                  const fapi2::buffer<uint64_t>& i_bank_addr,
                                  const fapi2::buffer<uint64_t>& i_bank_group_addr,
                                  const uint64_t i_delay_in_cycles)
{
    // Create Precharge command
    mss::ccs::instruction_t l_inst = precharge_all_command(i_rank.get_port_rank());

    // Set Bank address
    set_bank_group_addr<MC>( i_bank_addr, i_bank_group_addr, l_inst );

    // Set A10 low
    l_inst.arr0.template clearBit<TT::ARR0_DDR_ADDRESS_10>();

    return l_inst;
}

}// namespace ccs

// Row Repair specific functions
namespace row_repair
{

///
/// @brief A row repair entry
/// @tparam MC the memory controller type which executes the CCS instruction
/// @note contains repair data from attribtemplate <mss::mc_type MC = DEFAULT_MC_TYPE>
template< mss::mc_type MC >
struct repair_entry
{
    const bool iv_valid = true;
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
        iv_valid(i_buffer.getBit<ROW_REPAIR_VALID>())
    {
        iv_dimm_rank = i_dimm_rank;
        i_buffer.extractToRight<ROW_REPAIR_DRAM_POS, ROW_REPAIR_DRAM_POS_LEN>(iv_dram);
        i_buffer.extractToRight<ROW_REPAIR_SRANK, ROW_REPAIR_SRANK_LEN>(iv_srank);
        i_buffer.extractToRight<ROW_REPAIR_BANK_GROUP, ROW_REPAIR_BANK_GROUP_LEN>(iv_bg);
        i_buffer.extractToRight<ROW_REPAIR_BANK, ROW_REPAIR_BANK_LEN>(iv_bank);
        i_buffer.extractToRight<ROW_REPAIR_ROW_ADDR, ROW_REPAIR_ROW_ADDR_LEN>(iv_row);
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
        return iv_dram == i_rhs.iv_dram &&
               iv_dimm_rank == i_rhs.iv_dimm_rank &&
               iv_srank == i_rhs.iv_srank &&
               iv_bg == i_rhs.iv_bg &&
               iv_bank == i_rhs.iv_bank &&
               iv_row == i_rhs.iv_row &&
               iv_valid == i_rhs.iv_valid;
    }

    ///
    /// @brief default dtor
    ///
    ~repair_entry() = default;
};

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
                                  fapi2::buffer<uint64_t>& o_modeq_reg)
{
    // Use a temp buffer to save original settings
    fapi2::buffer<uint64_t> l_temp = 0;

    // Configure modeq register
    FAPI_TRY(mss::getScom(i_mc_target, TT::MODEQ_REG, o_modeq_reg));
    l_temp = o_modeq_reg;
    l_temp.template clearBit<TT::NTTM_MODE>();            // 1 = nontraditional transparent mode
    l_temp.template clearBit<TT::STOP_ON_ERR>();          // 1 = stop on ccs error
    l_temp.template setBit<TT::UE_DISABLE>();             // 1 = hardware ignores UEs
    l_temp.template setBit<TT::COPY_CKE_TO_SPARE_CKE>();  // 1 = copy CKE to spare CKE
    l_temp.template setBit<TT::CFG_PARITY_AFTER_CMD>();   // 1 = OE driven on parity cycle
    l_temp.template setBit<TT::IDLE_PAT_ACTN>();          // ACTn Idle
    l_temp.template setBit<TT::IDLE_PAT_ADDRESS_16>();    // RASn Idle
    l_temp.template setBit<TT::IDLE_PAT_ADDRESS_15>();    // CASn Idle
    l_temp.template setBit<TT::IDLE_PAT_ADDRESS_14>();    // WEn Idle
    l_temp.template clearBit<TT::ARR0_DDR_PARITY>();      // 0 = hardware sets parity
    FAPI_TRY(mss::putScom(i_mc_target, TT::MODEQ_REG, l_temp));

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Sets config registers to passed values
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT ccsTraits for MC
/// @tparam PT portTraits for MC
/// @param[in] i_mc_target The MC target
/// @param[in] i_mem_port_target The Mem Port target
/// @param[in] i_modeq_reg The value to set modeq
/// @return FAPI2_RC_SUCCESS iff okay
///
template <mss::mc_type MC, typename TT = ccsTraits<MC>, typename PT = mss::portTraits<MC> >
fapi2::ReturnCode revert_config_regs(const fapi2::Target<PT::MC_TARGET_TYPE>& i_mc_target,
                                     const fapi2::Target<PT::PORT_TYPE>& i_mem_port_target,
                                     const fapi2::buffer<uint64_t>& i_modeq_reg)
{
    // Configure ccs mode register:
    FAPI_TRY(mss::putScom(i_mc_target, TT::MODEQ_REG, i_modeq_reg));

fapi_try_exit:
    return fapi2::current_err;
}

} // row repair
} // mss
#endif
