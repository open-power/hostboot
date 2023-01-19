/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ccs/ccs_ddr5_commands.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file ccs_ddr5_commands.H
/// @brief Create DDR5 CCS commands
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CCS_DDR5_COMMANDS_H_
#define _MSS_CCS_DDR5_COMMANDS_H_

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

namespace ccs
{

namespace ddr5
{

///
/// @brief DDR5 command encodings
/// @note Excluding commands that are currently marked as RFU
/// Command abbreviations are taken from the JEDEC spec's truth table (version 1.7.1)
/// encodings are from CA[0:4] - additional per command notes are included inline below
///
enum cmd_encoding : size_t
{
    // Technically only CA[0:1] are used, but activate will re-write the row bits below
    ACT    = 0b00000,

    WRP    = 0b10010,
    WRPA   = 0b10010,

    MRW    = 0b10100,

    MRR    = 0b10101,

    WR     = 0b10110,
    WRA    = 0b10110,

    RD     = 0b10111,
    RDA    = 0b10111,

    VREFCA = 0b11000,
    VREFCS = 0b11000,

    REFAB  = 0b11001,
    RFMAB  = 0b11001,
    REFSB  = 0b11001,
    REFMSB = 0b11001,

    PREAB  = 0b11010,
    PRESB  = 0b11010,

    PREPB  = 0b11011,

    SRE    = 0b11101,
    SREF   = 0b11101,
    PDE    = 0b11101,

    MPC    = 0b11110,

    NOP    = 0b11111,
    PDX    = 0b11111,
    // Note: DES is not included as CS_n is high and the command pins are don't cares
};

///
/// @brief DDR5 internal API address bit locations
///
enum api_addr_bits
{
    CID2_0      = 61,
    CID2_0_LEN  = 3,
    CID3        = 60,

    BA1_0       = 62,
    BA1_0_LEN   = 2,

    BG2_0       = 61,
    BG2_0_LEN   = 3,

    COL10_3     = 53,
    COL10_3_LEN = 8,

    MRA7_0      = 56,
    MRA7_0_LEN  = 8,

    MR_OP7_0      = 56,
    MR_OP7_0_LEN  = 8,

    ROW3_0      = 60,
    ROW3_0_LEN  = 4,
    ROW16_4     = 47,
    ROW16_4_LEN = 13,
    ROW17       = 46,
};

/////////////////////////////////////////////
//////// Helper functions for adding signals
/////////////////////////////////////////////

///
/// @brief Swizzle CCS bits between two fapi2 buffers, and insert from source to destination
/// @tparam DS the start bit in the destination buffer - swizzle will count up from here
/// @tparam L how many bits to swizzle
/// @tparam SS the start bit in the source buffer - will count up from here
/// @param[in] i_source  source buffer
/// @param[in,out] io_destination destination buffer
///
template<uint64_t DS, uint64_t L, uint64_t SS>
inline void addr_bit_swizzle( const fapi2::buffer<uint64_t>& i_source, fapi2::buffer<uint64_t>& io_destination )
{
    // The mss::swizzle API needs to count down from the last valid bit for this field
    constexpr uint64_t SOURCE = SS + L - 1;
    swizzle<DS, L, SOURCE>(i_source, io_destination);
}

///
/// @brief Adds CID[2:0] to a command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_cid the CID to add in - CID is in the format of CID[3:0]
/// @param[in,out] io_inst0 the instruction on which to operate
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void add_cid2_0(const fapi2::buffer<uint64_t>& i_cid, fapi2::buffer<uint64_t>& io_inst0)
{
    addr_bit_swizzle<TT::CID0_2, api_addr_bits::CID2_0_LEN, api_addr_bits::CID2_0>( i_cid, io_inst0 );
}

///
/// @brief Adds BA[1:0] to a command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_ba the BA to add in - BA is in the format of BA[1:0]
/// @param[in,out] io_inst0 the instruction on which to operate
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void add_ba1_0(const fapi2::buffer<uint64_t>& i_ba, fapi2::buffer<uint64_t>& io_inst0)
{
    addr_bit_swizzle<TT::BA0_1, api_addr_bits::BA1_0_LEN, api_addr_bits::BA1_0>( i_ba, io_inst0 );
}

///
/// @brief Adds BG[2:0] to a command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_bg the BG to add in - BG is in the format of BG[2:0]
/// @param[in,out] io_inst0 the instruction on which to operate
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void add_bg2_0(const fapi2::buffer<uint64_t>& i_bg, fapi2::buffer<uint64_t>& io_inst0)
{
    addr_bit_swizzle<TT::BG0_2, api_addr_bits::BG2_0_LEN, api_addr_bits::BG2_0>( i_bg, io_inst0 );
}

///
/// @brief Adds COL[10:3] to a command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_col the COL to add in - COL is in the format of COL[10:0]
/// @param[in,out] io_inst0 the instruction on which to operate
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void add_col10_3(const fapi2::buffer<uint64_t>& i_col, fapi2::buffer<uint64_t>& io_inst0)
{
    addr_bit_swizzle<TT::C3_C10, api_addr_bits::COL10_3_LEN, api_addr_bits::COL10_3>( i_col, io_inst0 );
}

///
/// @brief Adds MRA[7:0] to a command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_mra the MRA to add in - MRA is in the format of MRA[7:0]
/// @param[in,out] io_inst0 the instruction on which to operate
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void add_mra7_0(const fapi2::buffer<uint64_t>& i_mra, fapi2::buffer<uint64_t>& io_inst0)
{
    addr_bit_swizzle<TT::MRA0_7, api_addr_bits::MRA7_0_LEN, api_addr_bits::MRA7_0>( i_mra, io_inst0 );
}

///
/// @brief Adds MROP[7:0] to a command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_mro the MRO to add in - MRO is in the format of MRO[7:0]
/// @param[in,out] io_inst0 the instruction on which to operate
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
void add_mr_op7_0(const fapi2::buffer<uint64_t>& i_mro, fapi2::buffer<uint64_t>& io_inst0)
{
    addr_bit_swizzle<TT::MR_OP0_7, api_addr_bits::MR_OP7_0_LEN, api_addr_bits::MR_OP7_0>( i_mro, io_inst0 );
}

/////////////////////////////////////////////
///////// Function to default WRDATA_CSN bits
/////////////////////////////////////////////

///
/// @brief function to update wrdata_csn bits
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @return Buffer with wrdata_csn bits set
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline fapi2::buffer<uint64_t> default_inst_arr0()
{
    fapi2::buffer<uint64_t> o_boilerplate_arr0;
    o_boilerplate_arr0.setBit<TT::wrdata_csn::WRITE_DATA_PHASE0_POS, TT::wrdata_csn::WRITE_DATA_PHASE0_LEN>();
    o_boilerplate_arr0.setBit<TT::wrdata_csn::WRITE_DATA_PHASE1_POS, TT::wrdata_csn::WRITE_DATA_PHASE1_LEN>();
    return o_boilerplate_arr0;
}

/////////////////////////////////////////////
//////// DDR5 commands
/////////////////////////////////////////////

///
/// @brief Setup activate command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the rank on this dimm
/// @param[in] i_cid the CID for this instruction -> right justified CID[3:0]
/// @param[in] i_bank_group_addr the bank group for this instruction -> right justified BG[2:0]
/// @param[in] i_bank_addr the bank address for this instruction -> right justified BA[1:0]
/// @param[in] i_row_addr the row address for this instruction -> right justified ROW[17:0]
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return Returns the activate CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> act_command( const uint64_t i_port_rank,
                                      const fapi2::buffer<uint64_t>& i_cid = 0,
                                      const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                      const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                      const fapi2::buffer<uint64_t>& i_row_addr = 0,
                                      const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::ACT);

    // Append the address information into the command
    add_cid2_0<MC>(i_cid, l_boilerplate_arr0);
    add_ba1_0<MC>(i_bank_addr, l_boilerplate_arr0);
    add_bg2_0<MC>(i_bank_group_addr, l_boilerplate_arr0);

    // Handle the row bits
    addr_bit_swizzle<TT::R0_3, api_addr_bits::ROW3_0_LEN, api_addr_bits::ROW3_0>( i_row_addr, l_boilerplate_arr0 );
    addr_bit_swizzle<TT::R4_16, api_addr_bits::ROW16_4_LEN, api_addr_bits::ROW16_4>( i_row_addr, l_boilerplate_arr0 );

    // Row 17 and CID3 share this bit
    // Or'ing and writing them in
    l_boilerplate_arr0.writeBit<TT::WR_RD_CID3>(i_row_addr.getBit<api_addr_bits::CID3>()
            || i_cid.getBit<api_addr_bits::ROW17>());

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Common setup for all MRS/RCD instructions
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_num the mode register number for this command
/// @param[in] i_data the mode register data for this command
/// @param[in,out] i_arr0 fapi2::buffer<uint64_t> representing the ARR0 of the instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
static void mrs_rcd_helper( const uint64_t i_num, const uint64_t i_data, fapi2::buffer<uint64_t>& io_arr0 )
{
    io_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::MRW);
    add_mra7_0<MC>(i_num, io_arr0);

    add_mr_op7_0<MC>(i_data, io_arr0);
}

///
/// @brief Create, initialize an RCD (RCW - JEDEC) CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_rcd the RCD number for this instruction
/// @param[in] i_rcd_data the specific op code for the MR in this format MR[7:0]
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the RCD CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> rcd_command(const uint64_t i_rcd,
                                     const uint64_t i_rcd_data,
                                     const uint16_t i_idle = 0)
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    mrs_rcd_helper<MC>(i_rcd, i_rcd_data, l_boilerplate_arr0);

    l_boilerplate_arr0.template setBit<TT::CW>();

    // Always use rank 0 here -> only one DIMM per PHY for DDR5
    return instruction_t<MC>(0, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Create, initialize an MRW CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_mrs the specific MRS
/// @param[in] i_mr_data the specific op code for the MR in this format MR[7:0]
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the MRW CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> mrw_command ( const uint64_t i_port_rank,
                                       const uint64_t i_mrs,
                                       const uint64_t i_mr_data,
                                       const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    mrs_rcd_helper<MC>(i_mrs, i_mr_data, l_boilerplate_arr0);

    l_boilerplate_arr0.template clearBit<TT::CW>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Create, initialize an MRR CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_mrs the specific MRS
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the MRR CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> mrr_command ( const uint64_t i_port_rank,
                                       const uint64_t i_mrs,
                                       const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::MRR)
    .template clearBit<TT::CW>();

    add_mra7_0<MC>(i_mrs, l_boilerplate_arr0);

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Create, initialize a JEDEC Device Power Down Entry CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the rank on this dimm
/// @param[in] i_odt ON_N if the ODT should be active during this powerdown, otherwise OFF_N
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the Device Deselect CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> pde_command( const uint64_t i_port_rank,
                                      const mss::states i_odt,
                                      const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::PDE)
    .template setBit<TT::PDE_SRE>()
    .template writeBit<TT::PDE_ODT>(i_odt == mss::states::OFF_N);

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup read command helper function
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_cid the CID for this instruction -> right justified CID[3:0]
/// @param[in] i_bank_group_addr the bank group for this instruction -> right justified BG[2:0]
/// @param[in] i_bank_addr the bank address for this instruction -> right justified BA[1:0]
/// @param[in] i_column_addr the column address for this instruction -> COL[10:0] (only 10:3] is used)
/// @return the write/read command CCS boilerplate
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
static fapi2::buffer<uint64_t> wr_rd_cmd_boilerplate(const fapi2::buffer<uint64_t>& i_cid = 0,
        const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
        const fapi2::buffer<uint64_t>& i_bank_addr = 0,
        const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    fapi2::buffer<uint64_t> l_inst0 = default_inst_arr0<MC>();

    add_cid2_0<MC>(i_cid, l_inst0);
    add_ba1_0<MC>(i_bank_addr, l_inst0);
    add_bg2_0<MC>(i_bank_group_addr, l_inst0);
    add_col10_3<MC>(i_column_addr, l_inst0);

    l_inst0.writeBit<TT::WR_RD_CID3>(i_cid.getBit<api_addr_bits::CID3>());

    return l_inst0;
}

///
/// @brief Setup write command (Fixed BL8 or BC4) instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_cid the CID for this instruction -> right justified CID[3:0]
/// @param[in] i_bank_group_addr the bank group for this instruction -> right justified BG[2:0]
/// @param[in] i_bank_addr the bank address for this instruction -> right justified BA[1:0]
/// @param[in] i_column_addr the column address for this instruction -> COL[10:0] (only 10:3] is used)
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the write command CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> wr_command( const uint64_t i_port_rank,
                                     const fapi2::buffer<uint64_t>& i_cid = 0,
                                     const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                     const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                     const fapi2::buffer<uint64_t>& i_column_addr = 0,
                                     const uint16_t i_idle = 0)
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = wr_rd_cmd_boilerplate<MC>(i_cid, i_bank_group_addr, i_bank_addr,
            i_column_addr );
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::WR)
    .template setBit<TT::AP>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup read command (Fixed BL8 or BC4) instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_cid the CID for this instruction -> right justified CID[3:0]
/// @param[in] i_bank_group_addr the bank group for this instruction -> right justified BG[2:0]
/// @param[in] i_bank_addr the bank address for this instruction -> right justified BA[1:0]
/// @param[in] i_column_addr the column address for this instruction -> COL[10:0] (only 10:3] is used)
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the read command CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> rd_command( const uint64_t i_port_rank,
                                     const fapi2::buffer<uint64_t>& i_cid = 0,
                                     const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                     const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                     const fapi2::buffer<uint64_t>& i_column_addr = 0,
                                     const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = wr_rd_cmd_boilerplate<MC>(i_cid, i_bank_group_addr, i_bank_addr,
            i_column_addr );
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::RD)
    .template setBit<TT::AP>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}
///
/// @brief Setup read w/auto precharge command (Fixed BL8 or BC4) instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_cid the CID for this instruction -> right justified CID[3:0]
/// @param[in] i_bank_group_addr the bank group for this instruction -> right justified BG[2:0]
/// @param[in] i_bank_addr the bank address for this instruction -> right justified BA[1:0]
/// @param[in] i_column_addr the column address for this instruction -> COL[10:0] (only 10:3] is used)
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the read command CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> rda_command( const uint64_t i_port_rank,
                                      const fapi2::buffer<uint64_t>& i_cid = 0,
                                      const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                      const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                      const fapi2::buffer<uint64_t>& i_column_addr = 0,
                                      const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = wr_rd_cmd_boilerplate<MC>(i_cid, i_bank_group_addr, i_bank_addr,
            i_column_addr );
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::RDA)
    .template clearBit<TT::AP>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup precharge all banks command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_cid the CID for this instruction -> right justified CID[3:0]
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the precharge all banks command CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> precharge_all_command( const uint64_t i_port_rank,
        const fapi2::buffer<uint64_t>& i_cid = 0,
        const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::PREAB)
    .template clearBit<TT::AP>();

    // Handle the CID's
    add_cid2_0<MC>(i_cid, l_boilerplate_arr0);
    l_boilerplate_arr0.template writeBit<TT::PRE_REF_CID3>(i_cid.getBit<api_addr_bits::CID3>());

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup self-refresh entry command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the self-refresh entry command CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> self_refresh_entry_command( const uint64_t i_port_rank, const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::SRE)
    .template clearBit<TT::SRE_VS_PDE>()
    .template setBit<TT::SRE_FREQ_CHANGE>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup self-refresh exit
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the self-refresh exit command CCS instruction
///
// TK doing this as a PDX for now -> DDR5 does not have an explicit self refresh exit. When I talk to the lab team I'll ask if this is correct
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> self_refresh_exit_command( const uint64_t i_port_rank, const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::PDX);

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup refresh command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_cid the CID for this instruction -> right justified CID[3:0]
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the self-refresh entry command CCS instruction
///
// Doing this as a refresh all
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> refresh_command( const uint64_t i_port_rank,
        const fapi2::buffer<uint64_t>& i_cid = 0,
        const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // Sets up a refresh all without management
    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::REFAB)
    .template setBit<TT::REF_MAN>()
    .template clearBit<TT::REF_ALL>();

    // Handle the CID's
    add_cid2_0<MC>(i_cid, l_boilerplate_arr0);
    l_boilerplate_arr0.template writeBit<TT::PRE_REF_CID3>(i_cid.getBit<api_addr_bits::CID3>());

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup MPC command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_op the operator for this MPC command OP[7:0]
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the MPC CCS command
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> mpc_command( const uint64_t i_port_rank, const uint64_t i_op, const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::MPC);

    add_mra7_0<MC>(i_op, l_boilerplate_arr0);

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup VREFCA command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_value the VREFCA value to program VREFCA[6:0]
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the VREFCA command
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> vrefca_command( const uint64_t i_port_rank,
        const fapi2::buffer<uint64_t>& i_value,
        const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // Technically, only MRA6:0 are used, but we'll overwrite MRA7 below (VREFCA)
    add_mra7_0<MC>(i_value, l_boilerplate_arr0);

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::VREFCA)
    .template clearBit<TT::VREFCA>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Setup VREFCS command instruction
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_port_rank the port rank
/// @param[in] i_value the VREFCS value to program VREFCS[6:0]
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the VREFCS command
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> vrefcs_command( const uint64_t i_port_rank,
        const fapi2::buffer<uint64_t>& i_value,
        const uint16_t i_idle = 0 )
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // Technically, only MRA6:0 are used, but we'll overwrite MRA7 below (VREFCA)
    add_mra7_0<MC>(i_value, l_boilerplate_arr0);

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::VREFCS)
    .template setBit<TT::VREFCA>();

    return instruction_t<MC>(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1, i_idle);
}

///
/// @brief Create, initialize a JEDEC Device Deselect CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the Device Deselect CCS instruction
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> des_command(const uint16_t i_idle = 0)
{
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::NOP);

    // Device Deslect wants CS_n always high (select nothing using rank NO_CHIP_SELECT_ACTIVE)
    return instruction_t<MC>( NO_CHIP_SELECT_ACTIVE,
                              l_boilerplate_arr0,
                              l_boilerplate_arr1,
                              i_idle);
}

///
/// @brief Create, initialize a NTTM read CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @return the Device Deselect CCS instruction
/// @note need to setup 8 cycles delay
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline instruction_t<MC> nttm_read_command()
{
    // This was a 4 on DDR4, so using an 8 for DDR5 (burst length is 2x as long on DDR5)
    constexpr uint64_t IDLES = 8;

    fapi2::buffer<uint64_t> l_boilerplate_arr0 = default_inst_arr0<MC>();
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0.template insertFromRight<TT::CMD, TT::CMD_LEN>(cmd_encoding::NOP);
    l_boilerplate_arr1.template setBit<TT::NTTM_MODE_FORCE_READ>();

    // Device Deslect wants CS_n always high (select nothing using rank NO_CHIP_SELECT_ACTIVE)
    return instruction_t<MC>( NO_CHIP_SELECT_ACTIVE,
                              l_boilerplate_arr0,
                              l_boilerplate_arr1,
                              IDLES);
}

// TK commands to add
// termination update for writes/reads
// write data select/timing update/adds (it's weird for ODY + DDR5 CCS)

} // ends namespace ddr5
} // ends namespace ccs
} // ends namespace mss
#endif
