/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_row_repair.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2024                        */
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
/// @file ody_row_repair.H
/// @brief API for DDR5 row repair HWP
///
// *HWP HWP Owner: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef __ODY_ROW_REPAIR__
#define __ODY_ROW_REPAIR__

#include <lib/shared/ody_consts.H>
#include <lib/ccs/ody_ccs.H>
#include <generic/memory/lib/ccs/row_repair.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

namespace ody
{

namespace row_repair
{

typedef mss::row_repair::repair_entry<mss::mc_type::ODYSSEY> REPAIR_ARR[mss::ody::MAX_RANK_PER_DIMM];
typedef REPAIR_ARR REPAIR_MAP[mss::ody::MAX_DIMM_PER_OCMB];

constexpr uint8_t DRAM_START_BIT = 44;
constexpr uint8_t DRAM_LEN = 64 - DRAM_START_BIT;

///
/// @brief The address data for each SPPR guardkey step
/// @note OP0 is the rightmost bit
///
enum guard_key_step
{
    GUARDKEY_SEQ_ONE   = 0xCF,
    GUARDKEY_SEQ_TWO   = 0x73,
    GUARDKEY_SEQ_THREE = 0xBB,
    GUARDKEY_SEQ_FOUR  = 0x3B
};

///
/// @brief Creates the DRAM bitmap for row repair
/// @param[in] i_dram the DRAM on which to conduct row repairs
/// @param[out] o_dram_bitmap the DRAM bitmap on which to conduct row repairs
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode create_dram_bitmap(const uint64_t i_dram, fapi2::buffer<uint64_t>& o_dram_bitmap);

///
/// @brief Initializes the DRAM repair entry array with invalid entries per dimm
/// @param [in,out] io_repairs_per_dimm Array of repair enteries
///
void init_repair_entry_arr(REPAIR_ARR& io_repairs_per_dimm);

///
/// @brief Initializes the DRAM repair map with invalid entries per dimm
/// @param [in,out] io_repair_map Array of Array repair enteries per dimm
///
void init_repair_map(REPAIR_MAP& io_repair_map);

///
/// @brief Retrieves number of DRAM on DIMM
/// @param[in] i_dram_width width of DRAM
/// @param[in,out] io_dram_num DRAM index
///
void get_dram_count(const uint8_t i_dram_width,
                    uint8_t& io_dram_num);

///
/// @brief Get MR index for a given BG
/// @param[in] i_bg the given bank group index
/// @return MR index (54/55/56/57) for the given BG
///
inline uint8_t get_ppr_resource_mr(const uint8_t i_bg)
{
    // map the BG to the MR which contains the PPR resource info for it
    // BG[0:1]=MR54, BG[2:3]=MR55, BG[4:5]=MR56, BG[6:7]=MR57
    return (i_bg / 2) + 54;
}

///
/// @brief Get "hPPR resource available" bit for a given BG and BA
/// @param[in] i_bg the given bank group index
/// @param[in] i_ba the given bank index
/// @return index into MR54/55/56 for the resultant bit
///
inline uint8_t get_ppr_resource_bit(const uint8_t i_bg, const uint8_t i_ba)
{
    constexpr uint8_t OFFSET_FOR_EVEN_BG = 4;

    // Map the BA into the bit in the MR that contains the resource info
    // Per Jedec DRAM spec it's {BG_ODD[3:0], BG_EVEN[3:0]}
    return (3 - i_ba) + (mss::is_odd(i_bg) ? 0 : OFFSET_FOR_EVEN_BG);
}

///
/// @brief Read PPR resource availability
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_runtime true if at runtime requiring dynamic
/// @param[out] o_data array of mr values per dram
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode get_ppr_resources(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair,
    const bool i_runtime,
    uint8_t (&o_data)[ccsTraits<mss::mc_type::ODYSSEY>::NUM_DRAM_X4]);

///
/// @brief Check if PPR resource is available
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_runtime true if at runtime requiring dynamic
/// @param[out] o_available will be set to true if PPR resource is available on given BG, false otherwise
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode get_ppr_available(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair,
    const bool i_runtime,
    bool& o_available);

///
/// @brief Read PPR resource availability for entire DIMM
/// @param[in] i_target_ocmb ocmb target
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode get_all_ppr_resources(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port_target);

///
/// @brief Calculates appropriate byte and byte mask per DRAM width
/// @param[in] i_target i_target DIMM target
/// @param[in] i_dram_nibbles  DRAM nibbles
/// @param[in] i_dram_width  DRAM width
/// @param[in,out] io_byte  DRAM byte index
/// @param[in,out] io_mask  Byte mask
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode get_dram_byte_mask(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint8_t i_dram_nibbles,
    const uint8_t i_dram_width,
    uint8_t& io_byte,
    uint8_t& io_mask
);

///
/// @brief Build a table of PPR row repairs from attribute data for a given DIMM
/// @param[in] i_target DIMM target
/// @param[in] i_row_repair_data array of row repair attribute values for the DIMM
/// @param[out] o_repairs_per_dimm array of row repair data buffers
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode build_row_repair_table(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_row_repair_data[mss::ody::MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK],
        REPAIR_ARR&  o_repairs_per_dimm);

///
/// @brief Create an error log and return with a good error code if a valid row repair is found
/// @param[in] i_target the DIMM target
/// @param[in] i_repair the repair data to validate
/// @return successful error code
///
fapi2::ReturnCode log_repairs_disabled_errors(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair);

///
/// @brief Swizzle CCS bits between two fapi2 buffers, and insert from source to destination
/// @param[in,out] io_repair the address repair information
/// @note srank, BG, BA, and row fields are reversed in repair_entry class due to backward-compatibility.
/// See class definition for field format
///
void swizzle_repair_entry(mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& io_repair);

///
/// @brief Perform a sPPR row repair operation
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in, out] io_program the ccs program to setup for row repair
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_sppr( const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                              const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair,
                              mss::ccs::program<mss::mc_type::ODYSSEY>& io_program);

///
/// @brief Perform a sPPR row repair operation at runtime
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dynamic_row_repair( const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                      const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair);

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
        uint8_t (&o_row_repair_data)[mss::ody::MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK]);

///
/// @brief Map all repair data to dimm target
/// @param[in] i_target_ocmb ocmb target
/// @param[out] o_repair_map the map to fill with repair pairs
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode map_repairs_per_dimm( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb,
                                        REPAIR_MAP& o_repair_map );

///
/// @brief Perform a sPPR row repair operation during the IPL
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode standalone_row_repair( const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair);

///
/// @brief Deploy mapped row repairs
/// @param[in] i_target ocmb target
/// @param[in] i_repair_map the map with repair data pairs
/// @param[in] i_runtime true if at runtime requiring dynamic
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode deploy_mapped_repairs( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const REPAIR_MAP& i_repair_map,
        const bool i_runtime );

} // row repair
} // ody
} // mss
#endif
