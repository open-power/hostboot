/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_row_repair.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __P9C_MSS_ROW_REPAIR__
#define __P9C_MSS_ROW_REPAIR__

#include <fapi2.H>
#include <dimmConsts.H>

typedef fapi2::ReturnCode (*p9c_mss_row_repair_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
        const uint8_t  i_port,
        const uint8_t  i_mrank,
        const uint8_t  i_srank,
        const uint8_t  i_bg,
        const uint8_t  i_bank,
        const uint32_t i_row,
        const uint32_t i_dram_bitmap);

// These consts describe the organization of ATTR_ROW_REPAIR_DATA
constexpr size_t ROW_REPAIR_BYTES_PER_RANK = 4;
constexpr size_t DRAM_POS = 0;
constexpr size_t DRAM_POS_LEN = 5;
constexpr size_t SRANK = 5;
constexpr size_t SRANK_LEN = 3;
constexpr size_t BANK_GROUP = 8;
constexpr size_t BANK_GROUP_LEN = 2;
constexpr size_t BANK = 10;
constexpr size_t BANK_LEN = 3;
constexpr size_t ROW_ADDR = 13;
constexpr size_t ROW_ADDR_LEN = 18;
constexpr size_t REPAIR_VALID = 31;
constexpr uint8_t MC_MAX_DRAMS_PER_RANK_X4 = MAX_DRAMS_PER_RANK_X4 + 1;

// This is the value to shift the input DRAM position to the last 20 bits of l_write_pattern
constexpr uint8_t DRAM_START_BIT = 44;
constexpr uint8_t DRAM_LEN = 64 - DRAM_START_BIT;

extern "C"
{

    /// @brief Perform a PPR row repair operation
    /// @param[in] i_target_mba mba target
    /// @param[in] i_port port for repair
    /// @param[in] i_mrank master rank of address to repair
    /// @param[in] i_srank slave rank of address to repair
    /// @param[in] i_bg bank group bits of address to repair
    /// @param[in] i_bank bank bits of address to repair
    /// @param[in] i_row row bits of address to repair
    /// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode p9c_mss_row_repair(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                         const uint8_t  i_port,
                                         const uint8_t  i_mrank,
                                         const uint8_t  i_srank,
                                         const uint8_t  i_bg,
                                         const uint8_t  i_bank,
                                         const uint32_t i_row,
                                         const uint32_t i_dram_bitmap);


    /// @brief Deploy PPR row repairs, if supported, according to VPD attributes
    /// @param[in] i_target_mba mba target
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode p9c_mss_deploy_row_repairs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    /// @brief Check the bad bits data to see if a DRAM was not calibrated
    /// @param[in] i_dram_width the DRAM width
    /// @param[in] i_dram the DRAM index
    /// @param[in] i_rankpair_table table of rank to rank pairs for this port
    /// @param[in] i_bad_bits array bad bits data from VPD for all ranks on the port
    /// @param[out] o_uncalibrated true if DRAM was marked bad in all ranks, false otherwise
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode check_for_uncalibrated_dram(const uint8_t i_dram_width,
            const uint8_t i_dram,
            const uint8_t (&i_rankpair_table)[MAX_RANKS_PER_PORT],
            const uint8_t (&i_bad_bits)[MAX_RANKS_PER_PORT][DIMM_DQ_RANK_BITMAP_SIZE],
            bool& o_uncalibrated);

    /// @brief Deploy enough PPR row repairs to test all spare rows
    /// @param[in] i_target_mba mba target
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode p9c_mss_activate_all_spare_rows(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    /// @brief Clear the corresponding bad_bits after a row repair operation
    /// @param[in] i_dram_width the DRAM width
    /// @param[in] i_dram the DRAM index
    /// @param[in,out] io_bad_bits array bad bits data from VPD
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode clear_bad_dq_for_row_repair(const uint8_t i_dram_width,
            const uint8_t i_dram,
            uint8_t (&io_bad_bits)[DIMM_DQ_RANK_BITMAP_SIZE]);

    /// @brief Clear a row repair entry from the VPD data
    /// @param[in] i_rank master rank
    /// @param[in,out] io_row_repair_data data for this DIMM/rank from the VPD
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode clear_row_repair_entry(const uint8_t i_rank,
            uint8_t (&io_row_repair_data)[MAX_RANKS_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK]);

    /// @brief Decode a row repair entry from an encoded buffer
    /// @param[in] i_repair row repair data buffer
    /// @param[out] o_dram DRAM position
    /// @param[out] o_srank slave rank
    /// @param[out] o_bg bank group
    /// @param[out] o_bank bank address
    /// @param[out] o_row row address
    /// @return true if the repair request is valid, false otherwise
    bool valid_row_repair_entry( const fapi2::buffer<uint32_t> i_repair,
                                 uint8_t& o_dram,
                                 uint8_t& o_srank,
                                 uint8_t& o_bg,
                                 uint8_t& o_bank,
                                 uint32_t& o_row );

    /// @brief Build a table of PPR row repairs from attribute data for a given DIMM
    /// @param[in] i_target DIMM target
    /// @param[in] i_dram_width the DRAM width
    /// @param[in] i_row_repair_data array of row repair attribute values for the DIMM
    /// @param[out] o_repairs_per_dimm array of row repair data buffers
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode build_row_repair_table(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const uint8_t i_dram_width,
            const uint8_t i_row_repair_data[MAX_RANKS_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK],
            std::vector<fapi2::buffer<uint32_t>>& o_repairs_per_dimm);
}

#endif
