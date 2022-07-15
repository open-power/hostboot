/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ccs/ccs_ddr4_commands.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
// EKB-Mirror-To: hostboot

///
/// @file ccs_ddr4_commands.H
/// @brief Create DDR4 CCS commands
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CCS_DDR4_COMMANDS_H_
#define _MSS_CCS_DDR4_COMMANDS_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <generic/memory/lib/ccs/ccs_instruction.H>

namespace mss
{

static constexpr uint64_t CKE_HIGH = 0b1111;
static constexpr uint64_t CKE_LOW  = 0b0000;


// CKE setup for rank 0-7 to support
// Currently only support 0, 1, 4, 5
// Not supported ranks will always get 0
// For self_refresh_entry_command()
static constexpr uint64_t CKE_ARY_SRE[]  =
{
    //   0,      1, 2, 3,
    0b0111, 0b1011, 0, 0,
    //   4,      5, 6, 7
    0b0111, 0b1011, 0, 0
};

// For self_refresh_exit_command()
static constexpr uint64_t CKE_ARY_SRX[]  =
{
    //   0,      1, 2, 3,
    0b1000, 0b0100, 0, 0,
    //   4,      5, 6, 7
    0b1000, 0b0100, 0, 0
};

namespace ccs
{

namespace ddr4
{


///
/// @brief Common setup for all MRS/RCD instructions
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in,out] i_arr0 fapi2::buffer<uint64_t> representing the ARR0 of the instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
static void mrs_rcd_helper( fapi2::buffer<uint64_t>& i_arr0 )
{
    //
    // Generic DDR4 MRS setup (RCD is an MRS)
    //
    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. BRS
    i_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    i_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS, CAS, WE low
    i_arr0.clearBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();
}

///
/// @brief Setup activate command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_port_rank the rank on this dimm
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> act_command( const uint64_t i_port_rank )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // Set all CKE to high
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ACTN>();

    // RAS low, CAS low, WE low
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();

    // Just leaving the row addresses to all 0 for now
    // row, bg, ba set to 0
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_17>();
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_0_13, TT::ARR0_DDR_ADDRESS_0_13_LEN>();
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_GROUP_1>();
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_GROUP_0>();
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_0_1, TT::ARR0_DDR_BANK_0_1_LEN>();
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_2>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Create, initialize an RCD (RCW - JEDEC) CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_turn_on_cke flag that states whether we want CKE on for this RCW (defaulted to true)
/// @return the RCD CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> rcd_command( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const bool i_sim,
                                      const bool i_turn_on_cke = true)
{
    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;

    //
    // Generic DDR4 MRS setup (RCD is an MRS)
    //
    mrs_rcd_helper<MC>(rcd_boilerplate_arr0);

    // Not adding i_turn_on_cke in the mrs_rcd helper because we only need this
    // for RCWs and there is no need to complicate/change the MRS cmd API with
    // uneeded functionality. Little duplication, but this isolates the change.
    if( !i_sim )
    {
        const uint64_t l_cke = i_turn_on_cke ? CKE_HIGH : CKE_LOW;
        rcd_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(l_cke);
    }

    //
    // RCD setup
    //
    // DDR4: Set BG1 to 0 during an MRS.
    // BG0, BA1:BA0 to 0b111 selects RCW (aka MR7).
    rcd_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_GROUP_1>()
    .template insertFromRight<TT::ARR0_DDR_BANK_0_1, TT::ARR0_DDR_BANK_0_1_LEN>(0b11)
    .template setBit<TT::ARR0_DDR_BANK_GROUP_0>();

    // RCD always goes to the 0th rank on the DIMM; either 0 or 4.
    return instruction_t<MC>((mss::index(i_target) == 0) ? 0 : 4, rcd_boilerplate_arr0, rcd_boilerplate_arr1);
}

///
/// @brief Create, initialize an MRS CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_port_rank the port rank
/// @param[in] i_mrs the specific MRS
/// @return the MRS CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> mrs_command ( const uint64_t i_port_rank,
                                       const uint64_t i_mrs )
{
    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;
    fapi2::buffer<uint8_t> mrs(i_mrs);

    //
    // Generic DDR4 MRS setup (RCD is an MRS)
    //
    mrs_rcd_helper<MC>(rcd_boilerplate_arr0);

    //
    // MRS setup
    //
    // DDR4: Set BG1 to 0. BG0, BA1:BA0 to i_mrs
    rcd_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_GROUP_1>();
    mss::swizzle<TT::ARR0_DDR_BANK_0_1, 3, 7>(mrs, rcd_boilerplate_arr0);
    FAPI_DBG("mrs rcd boiler 0x%016lx 0x%llx", uint8_t(mrs), uint64_t(rcd_boilerplate_arr0));
    return instruction_t<MC>(i_port_rank, rcd_boilerplate_arr0, rcd_boilerplate_arr1);
}

///
/// @brief Create, initialize a JEDEC Device Deselect CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the Device Deselect CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> des_command(const uint16_t i_idle = 0)
{
    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;

    // ACT is high. It's a no-care in the spec but it seems to raise questions when
    // people look at the trace, so lets set it high.
    rcd_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. BRS
    rcd_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high no-care
    // RAS, CAS, WE no-care

    // Device Deslect wants CS_n always high (select nothing using rank NO_CHIP_SELECT_ACTIVE)
    return instruction_t<MC>( NO_CHIP_SELECT_ACTIVE,
                              rcd_boilerplate_arr0,
                              rcd_boilerplate_arr1,
                              i_idle);
}

///
/// @brief Converts an ODT attribute to CCS array input
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_attr_value ODT attribute value
/// @param[in] i_target PORT target type
/// @param[out] CCS value for the ODT's
/// @return FAPI2_RC_SUCCESS iff success, else error code
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline fapi2::ReturnCode convert_odt_attr_to_ccs(
    const fapi2::buffer<uint8_t>& i_attr_value,
    const fapi2::Target<TT::PORT_TARGET_TYPE>& i_target,
    uint8_t& o_ccs_value)
{
    // ODT value buffer
    fapi2::buffer<uint8_t> l_ccs_value;
    l_ccs_value.template writeBit<TT::CCS_ODT_DIMM0_R0>(i_attr_value.template getBit<TT::ATTR_ODT_DIMM0_R0>())
    .template writeBit<TT::CCS_ODT_DIMM0_R1>(i_attr_value.template getBit<TT::ATTR_ODT_DIMM0_R1>())
    .template writeBit<TT::CCS_ODT_DIMM0_R0>(i_attr_value.template getBit<TT::ATTR_ODT_DIMM0_R0>())
    .template writeBit<TT::CCS_ODT_DIMM1_R0>(i_attr_value.template getBit<TT::ATTR_ODT_DIMM1_R0>())
    .template writeBit<TT::CCS_ODT_DIMM1_R1>(i_attr_value.template getBit<TT::ATTR_ODT_DIMM1_R1>());

    // Set ODT_DIMM1_R0 & R1 <-- ODT_DIMM0_R0 & R1 if CS/ODt needs to be tied
    FAPI_TRY(TT::odt_tied(i_target, l_ccs_value));

    o_ccs_value = uint8_t(l_ccs_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Create, initialize an ODT CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_odt_values CCS defined ODT values
/// @param[in] i_cycles the number of cycles to hold the ODT for - defaults to DEFAULT_ODT_CYCLE_LEN
/// @return the Device Deselect CCS instruction
/// @note This technically is not a JEDEC command, but is needed for CCS to hold the ODT cycles
/// CCS by design does not repeat or latch ODT's appropriately
/// As such, it's up to the programmers to hold the ODT's appropriately
/// This "command" will greatly help us do that
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> odt_command(const uint8_t i_odt_values, const uint64_t i_cycles = TT::DEFAULT_ODT_CYCLE_LEN)
{
    auto l_odt_cmd = des_command<MC>();
    l_odt_cmd.arr0.template insertFromRight<TT::ARR0_DDR_ODT, TT::ARR0_DDR_ODT_LEN>(i_odt_values);
    l_odt_cmd.iv_repeats = i_cycles;

    return l_odt_cmd;
}


///
/// @brief Create, initialize a NTTM read CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @return the Device Deselect CCS instruction
/// @note need to setup 4 cycles delay
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> nttm_read_command()
{
    // get the des_command
    auto l_command = des_command<MC>(TT::NTTM_READ_DELAY);
    // set to CCS_INST_ARR1 register
    l_command.arr1.template setBit<TT::NTTM_MODE_FORCE_READ>();

    return l_command;
}

///
/// @brief Create, initialize a JEDEC Device Power Down Entry CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @return the Device Deselect CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> pde_command()
{
    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;

    // Power Down Entry just like a DES, but we set CKE low
    instruction_t<MC> l_inst = des_command<MC>(TT::TIMING_TCPDED);

    // CKE is low. Note: P8 set all 4 of these low - not sure if that's correct.
    l_inst.arr0.template insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_LOW);

    return l_inst;
}

///
/// @brief Setup ZQ Long instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the MRS CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> zqcl_command( const uint64_t i_port_rank,
                                       const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. BRS
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS/CAS high, WE low
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_16>()
    .template setBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();

    // ADDR10/AP is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_10>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup read command helper function
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_bank_addr bank address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the read command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
static fapi2::buffer<uint64_t> read_cmd_boilerplate( const uint64_t i_port_rank,
        const fapi2::buffer<uint64_t>& i_bank_addr = 0,
        const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
        const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    // TODO - RTC 166175 Encapsulate command truth table in a subclass for ccs.H
    fapi2::buffer<uint64_t> l_boilerplate_arr0;

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. AAM
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE,
                                       TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS high, CAS low, WE high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template setBit<TT::ARR0_DDR_ADDRESS_14>();

    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_BANK_0_1,
                                       TT::ARR0_DDR_BANK_0_1_LEN>(i_bank_addr);

    // Bank Group takes a little effort - the bits aren't contiguous
    constexpr uint64_t BG0_BIT = 62;
    constexpr uint64_t BG1_BIT = 63;

    l_boilerplate_arr0.writeBit<TT::ARR0_DDR_BANK_GROUP_0>(i_bank_group_addr.getBit<BG0_BIT>())
    .template writeBit<TT::ARR0_DDR_BANK_GROUP_1>(i_bank_group_addr.getBit<BG1_BIT>());

    // CA is A[0:9]
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_ADDRESS_0_9,
                                       TT::ARR0_DDR_ADDRESS_0_9_LEN>(i_column_addr);

    return l_boilerplate_arr0;
}

///
/// @brief Setup write command (Fixed BL8 or BC4) instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_bank_addr bank address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the write command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> wr_command( const uint64_t i_port_rank,
                                     const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                     const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                     const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    // WR's and RD's are very similar, so we just use the RD command boiler plate and modify the command to a WR
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = read_cmd_boilerplate<MC>(i_port_rank,
            i_bank_addr,
            i_bank_group_addr,
            i_column_addr);
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // RAS high, CAS low, WE low
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup read command (Fixed BL8 or BC4) instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_bank_addr bank address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the read command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> rd_command( const uint64_t i_port_rank,
                                     const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                     const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                     const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0 = read_cmd_boilerplate<MC>(i_port_rank,
                         i_bank_addr,
                         i_bank_group_addr,
                         i_column_addr);

    // Setup ADDR10/AP based on read type
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_10>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup read w/auto precharge command (Fixed BL8 or BC4) instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_bank_addr bank address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the read command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> rda_command( const uint64_t i_port_rank,
                                      const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                      const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                      const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0 = read_cmd_boilerplate<MC>(i_port_rank,
                         i_bank_addr,
                         i_bank_group_addr,
                         i_column_addr);

    // Setup ADDR10/AP based on read type
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_10>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup precharge all banks command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the precharge all banks command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> precharge_all_command( const uint64_t i_port_rank,
        const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. AAM
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS low, CAS high, WE low
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_16>()
    .template setBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();

    // Setup ADDR10/AP high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_10>();

    // From DDR4 Spec table 17:
    // All other bits from the command truth table or 'V', for valid (1 or 0)

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup self-refresh entry command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the self-refresh entry command CCS instruction
/// @note THIS IS FOR DDR4 NON-LRDIMM ONLY RIGHT NOW
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> self_refresh_entry_command( const uint64_t i_port_rank, const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // Set all CKE to high except the rank passed in
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_ARY_SRE[i_port_rank]);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS low, CAS low, WE high
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template setBit<TT::ARR0_DDR_ADDRESS_14>();

    // From DDR4 Spec table 17:
    // All other bits from the command truth table are 'V', for valid (1 or 0)

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup self-refresh exit using NOP command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the self-refresh exit command CCS instruction
/// @note Using NOP in case SDRAM is in gear down mode and max power saving mode exit
/// @note THIS IS FOR DDR4 NON-LRDIMM ONLY RIGHT NOW
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> self_refresh_exit_command( const uint64_t i_port_rank, const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // Set all CKE to low except the rank passed in
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_ARY_SRX[i_port_rank]);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS high, CAS high, WE high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_16>()
    .template setBit<TT::ARR0_DDR_ADDRESS_15>()
    .template setBit<TT::ARR0_DDR_ADDRESS_14>();

    // From DDR4 Spec table 17:
    // All other bits from the command truth table are 'V', for valid (1 or 0)

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup refresh command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the self-refresh entry command CCS instruction
/// @note THIS IS FOR DDR4 NON-LRDIMM ONLY RIGHT NOW
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> refresh_command( const uint64_t i_port_rank, const uint16_t i_idle = 0 )
{
    // Refresh is self-refresh entry with CKE high
    auto l_refresh_template = self_refresh_entry_command<MC>(i_port_rank, i_idle);

    // CKE is high
    l_refresh_template.arr0.template insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    return l_refresh_template;
}


} // ends namespace ddr4
} // ends namespace ccs
} // ends namespace mss
#endif
