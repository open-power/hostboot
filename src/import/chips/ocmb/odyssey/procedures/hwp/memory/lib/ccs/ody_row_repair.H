/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_row_repair.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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

///
/// @brief Enums to keep track of swizzle bit positions within the row repair class
///
enum swizzle_pos
{
    ROW_LEN = 18,
    ROW_START = 14,
    ROW_LAST = 31,
    BANK_LEN = 2,
    BANK_START = 6,
    BANK_LAST = 7,
    BG_LEN = 3,
    BG_START = 5,
    BG_LAST = 7,
    SRANK_LEN = 4,
    SRANK_START = 4,
    SRANK_LAST = 7,
};

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
/// @brief Swizzle CCS bits between two fapi2 buffers, and insert from source to destination
/// @param[in,out] io_repair the address repair information
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
/// @brief Perform a sPPR row repair operation during the IPL
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode standalone_row_repair( const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair);
} // row repair
} // ody
} // mss
#endif
