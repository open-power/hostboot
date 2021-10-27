/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ccs/exp_row_repair.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

/// @file exp_row_repair.H
/// @brief Contains functions necessary for row repair
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory HWP
// EKB-Mirror-To: hostboot

#ifndef __EXP_ROW_REPAIR_FUNCTIONS__
#define __EXP_ROW_REPAIR_FUNCTIONS__

#include <lib/shared/exp_consts.H>
#include <lib/ccs/ccs_explorer.H>
#include <generic/memory/lib/ccs/row_repair.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

namespace exp
{

namespace ccs
{

///
/// @brief Reads the inversion register and proceses out if the chip's data is inverted
/// @param[in] i_data register data to read
/// @param[out] o_state the state of the inversion on the chip
///
void get_inversion(const fapi2::buffer<uint64_t>& i_data, mss::states& o_state);

///
/// @brief Reads the inversion register and proceses out if the chip's data is inverted
/// @param[in] i_target the target on which to operate
/// @param[out] o_state the state of the inversion on the chip
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode process_inversion(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, mss::states& o_state);

///
/// @brief Set the WR data in INST_ARR1 for a ccs write command
/// @param[in] i_data CCS write data
/// @param[in] i_inverse ON if the data needs to be inverted
/// @param[in,out] io_inst The vector of ccs instructions to add to
///
void set_write_data( const fapi2::buffer<uint64_t>& i_data,
                     const mss::states i_inverse,
                     mss::ccs::instruction_t& io_inst);

} // namespace ccs

namespace row_repair
{

///
/// @brief Creates the DRAM bitmap for row repair on all DRAMS
/// @return the DRAM bitmap for repairs on all DRAMs
///
fapi2::buffer<uint64_t> select_all_drams_for_repair();

///
/// @brief Creates the DRAM bitmap for row repair
/// @param[in] i_dram the DRAM on which to conduct row repairs
/// @param[out] o_dram_bitmap the DRAM bitmap on which to conduct row repairs
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode create_dram_bitmap(const uint64_t i_dram, fapi2::buffer<uint64_t>& o_dram_bitmap);


typedef std::map< fapi2::Target<fapi2::TARGET_TYPE_DIMM>, std::vector<mss::row_repair::repair_entry<mss::mc_type::EXPLORER>> >
        REPAIR_MAP;

constexpr uint8_t DRAM_START_BIT = 44;
constexpr uint8_t DRAM_LEN = 64 - DRAM_START_BIT;

///
/// @brief The address data for each SPPR guardkey step
/// @note A0 is the leftmost bit
///
enum guard_key_step
{
    GUARDKEY_SEQ_ONE = 0xFF3,
    GUARDKEY_SEQ_TWO = 0xFFE,
    GUARDKEY_SEQ_THREE = 0xFFD,
    GUARDKEY_SEQ_FOUR = 0xFFC
};

///
/// @brief Clear a row repair entry from rank
/// @param[in] i_rank_info master rank
/// @param[in,out] io_row_repair_data data for this DIMM/rank
///
void clear_row_repair_entry( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                             uint8_t (&io_row_repair_data)[MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK]);

///
/// @brief Create CCS instruction with proper bits for guard key
/// @param[in] i_rank_info rank of address for instruction
/// @param[in] i_delay_in_cycles delay in cycles for instruction
/// @param[in] i_guard_key_addr guardkey sequence addr value
/// @param[in,out] io_inst ccs instruction to create guardkey for
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode add_sppr_guardkey( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                                     const uint64_t i_delay_in_cycles,
                                     const uint64_t i_guard_key_addr,
                                     std::vector< mss::ccs::instruction_t >& io_inst );

///
/// @brief Build a table of PPR row repairs from attribute data for a given DIMM
/// @param[in] i_target DIMM target
/// @param[in] i_row_repair_data array of row repair attribute values for the DIMM
/// @param[out] o_repairs_per_dimm array of row repair data buffers
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode build_row_repair_table(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_row_repair_data[mss::exp::MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK],
        std::vector<mss::row_repair::repair_entry<mss::mc_type::EXPLORER>>& o_repairs_per_dimm);

///
/// @brief Create an error log and return with a good error code if a valid row repair is found
/// @param[in] i_target the DIMM target
/// @param[in] i_repair the repair data to validate
/// @return successful error code
///
fapi2::ReturnCode log_repairs_disabled_errors(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair);

///
/// @brief Perform a PPR row repair operation
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
/// @param[in, out] io_program the ccs program to setup for row repair
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_sppr( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                              const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair,
                              const fapi2::buffer<uint64_t>& i_dram_bitmap,
                              mss::ccs::program& io_program);

///
/// @brief Perform a sPPR row repair operation during ipl
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode maint_row_repair( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                                    const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair,
                                    const fapi2::buffer<uint64_t>& i_dram_bitmap);


///
/// @brief Helper that adds power down disable for dynamic row repair
/// @param[in] i_target port target on which to operate
/// @param[in, out] io_program program holding CCS instructions to add to
///
void disable_power_down_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                               mss::ccs::program& io_program);

///
/// @brief Perform a sPPR row repair operation at runtime
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dynamic_row_repair( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                                      const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair,
                                      const fapi2::buffer<uint64_t>& i_dram_bitmap);

///
/// @brief Deploy enough PPR row repairs to test all spare rows
/// @param[in] i_target_ocmb ocmb target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode activate_all_spare_rows(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb);

///
/// @brief Gets the number of bad bits on a DRAM for a given row repair
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_row_repair_dram_byte the byte of data that contains the row repair's DRAM information
/// @param[in] i_bad_bits the array of bad bits for this rank
/// @param[out] o_num_bad_bits_for_dram the number of bad bits on this DRAM
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode get_num_bad_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint8_t i_row_repair_dram_byte,
                                   const uint8_t i_bad_bits[BAD_DQ_BYTE_COUNT],
                                   uint8_t& o_num_bad_bits_for_dram);

///
/// @brief Gets the row repair attribute and clears out any unneeded repairs
/// @param[in] i_target the DIMM target on which to operate
/// @param[out] o_row_repair_data the row repair data to process for this DIMM
/// @return FAPI2_RC_SUCCESS iff successful
/// @note Clears out the repairs if there is more than one bad bit on the DRAM that would be repaired
///
fapi2::ReturnCode clear_row_repairs_on_bad_dram(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t (&o_row_repair_data)[mss::exp::MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK]);

///
/// @brief Map all repair data to dimm target
/// @param[in] i_target_ocmb ocmb target
/// @param[out] o_repair_map the map to fill with repair pairs
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode map_repairs_per_dimm( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb,
                                        REPAIR_MAP& o_repair_map );

///
/// @brief Deploy mapped row repairs
/// @param[in] i_repair_map the map with repair data pairs
/// @param[in] i_runtime true if at runtime requiring dynamic
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode deploy_mapped_repairs( const REPAIR_MAP& i_repair_map,
        const bool i_runtime );

} // row repair
} // exp
} // mss
#endif
