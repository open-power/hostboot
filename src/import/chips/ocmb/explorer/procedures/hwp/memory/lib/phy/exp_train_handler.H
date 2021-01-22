/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_train_handler.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_train_handler.H
/// @brief Procedure handle any training fails from the explorer
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __EXP_TRAIN_HANDLER_H__
#define __EXP_TRAIN_HANDLER_H__

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_rank.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/endian_utils.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>

namespace mss
{
namespace exp
{

///
/// @brief Holds all the masks for the MR attributes in MRs data
/// @note The values here are in terms of where they will be in the cronus buffers
///
enum mrs_bits : uint16_t
{
    // MR0 Values
    MR0_EFF_DRAM_RBT = 12,
    MR0_EFF_DRAM_TM = 8,
    MR0_EFF_DRAM_DLL_RESET = 7,
    MR0_EFF_BURST_LENGTH = 14,
    MR0_EFF_BURST_LENGTH_LEN = 2,

    // MR1 Values
    MR1_EFF_DRAM_DLL_ENABLE = 15,
    MR1_EFF_DRAM_ODIC = 13,
    MR1_EFF_DRAM_ODIC_LEN = 2,
    MR1_EFF_DRAM_AL = 11,
    MR1_EFF_DRAM_AL_LEN = 2,
    MR1_EFF_DRAM_WR_LVL_ENABLE = 8,
    MR1_EFF_DRAM_RTT_NOM = 5,
    MR1_EFF_DRAM_RTT_NOM_LEN = 3,
    MR1_EFF_DRAM_TDQS = 4,
    MR1_EFF_DRAM_OUTPUT_BUFFER = 3,

    // MR2 Values
    MR2_EFF_DRAM_LPASR = 8,
    MR2_EFF_DRAM_LPASR_LEN = 2,
    MR2_EFF_DRAM_RTT_WR = 4,
    MR2_EFF_DRAM_RTT_WR_LEN = 3,

    // MR3 Values
    MR3_EFF_MPR_MODE = 13, // Needs confirmation
    MR3_EFF_MPR_PAGE = 14,
    MR3_EFF_MPR_PAGE_LEN = 2,
    MR3_EFF_GEARDOWN_MODE = 12,
    MR3_EFF_PER_DRAM_ACCESS = 11,
    MR3_EFF_TEMP_READOUT = 10,
    MR3_EFF_CRC_WR_LATENCY = 5,
    MR3_EFF_CRC_WR_LATENCY_LEN = 2,
    MR3_EFF_MPR_RD_FORMAT = 3,
    MR3_EFF_MPR_RD_FORMAT_LEN = 2,

    // MR4 Values
    MR4_EFF_MAX_POWERDOWN_MODE = 14,
    MR4_EFF_INTERNAL_VREF_MONITOR = 11,
    MR4_EFF_SELF_REF_ABORT = 6,
    MR4_EFF_RD_PREAMBLE_TRAIN = 5,
    MR4_EFF_RD_PREAMBLE = 4,
    MR4_EFF_WR_PREAMBLE = 3,

    // MR5 Values
    MR5_EFF_CRC_ERROR_CLEAR = 12,
    MR5_EFF_CA_PARITY_ERROR_STATUS = 11,
    MR5_EFF_ODT_INPUT_BUFF = 10,
    MR5_EFF_CA_PARITY = 6,
    MR5_EFF_DATA_MASK = 5,
    MR5_EFF_WRITE_DBI = 4,
    MR5_EFF_READ_DBI = 3,
    MR5_EFF_DRAM_RTT_PARK = 7,
    MR5_EFF_DRAM_RTT_PARK_LEN = 3,

    // MR6 Values
    MR6_VREFDQ_TRAINING_VALUE = 10,
    MR6_VREFDQ_TRAINING_VALUE_LEN = 6,
    MR6_VREFDQ_TRAINING_RANGE = 9,
    MR6_VREFDQ_TRAINING_ENABLE = 8,
};

///
/// @brief Read eye capture response data from explorer data buffer
///
/// @tparam T Response struct type
/// @param[in] i_target OCMB target
/// @param[in] i_data Raw data bytes
/// @param[in,out] io_current_idx Current parsing index
/// @param[in,out] io_pass any errors occurred during reading/endian-swapping
/// @param[in,out] io_resp response struct
/// @note this function expects io_current_index to be set correctly to the start of eye capture data
///
template <typename T>
void read_eye_capture_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const std::vector<uint8_t>& i_data,
                               uint32_t& io_current_idx,
                               bool& io_pass,
                               T& io_resp);

///
/// @brief Read eye capture response data from explorer data buffer (eye capture step 1)
///
/// @param[in] i_target OCMB target
/// @param[in] i_data Raw data bytes
/// @param[in,out] io_current_idx Current parsing index
/// @param[in,out] io_pass any errors occurred during reading/endian-swapping
/// @param[in,out] io_resp train_2d_read_eye_msdg
/// @note this function expects io_current_index to be set correctly to the start of eye capture data
///
template<>
inline void read_eye_capture_response<user_2d_eye_response_1_msdg>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target,
        const std::vector<uint8_t>& i_data,
        uint32_t& io_current_idx,
        bool& io_pass,
        user_2d_eye_response_1_msdg& io_resp)
{
    // Eye capture step 1 struct
    uint32_t l_idx = io_current_idx;
    bool l_pass = io_pass;

    // VrefDAC0: 3D array of 2 1D arrays
    for (uint8_t l_num_ranks = 0; l_num_ranks < TRAINING_RESPONSE_NUM_RANKS; ++l_num_ranks)
    {
        for (uint8_t l_dbyte_n_size = 0; l_dbyte_n_size < DBYTE_N_SIZE; ++ l_dbyte_n_size)
        {
            for (uint8_t l_bit_n_sze = 0; l_bit_n_sze < BIT_N_SIZE; ++ l_bit_n_sze)
            {
                l_pass &= readLEArray(i_data, EYE_MIN_MAX_SIZE, l_idx,
                                      &io_resp.read_2d_eye_resp.VrefDAC0[l_num_ranks][l_dbyte_n_size][l_bit_n_sze].eye_min[0]);
                l_pass &= readLEArray(i_data, EYE_MIN_MAX_SIZE, l_idx,
                                      &io_resp.read_2d_eye_resp.VrefDAC0[l_num_ranks][l_dbyte_n_size][l_bit_n_sze].eye_max[0]);
            }
        }
    }

    // 2D array VrefDAC0_Center [DBYTE_N_SIZE][BIT_N_SIZE]
    l_pass &= readLEArray(i_data, (DBYTE_N_SIZE * BIT_N_SIZE), l_idx,
                          &io_resp.read_2d_eye_resp.VrefDAC0_Center[0][0]);

    // 2D array RxClkDly_Center [TRAINING_RESPONSE_NUM_RANKS][NIBBLE_N_SIZE]
    l_pass &= readLEArray(i_data, (TRAINING_RESPONSE_NUM_RANKS * NIBBLE_N_SIZE), l_idx,
                          &io_resp.read_2d_eye_resp.RxClkDly_Center[0][0]);

    io_pass = l_pass;
    io_current_idx = l_idx;
}

///
/// @brief Read eye capture response data from explorer data buffer (eye capture step 2)
///
/// @param[in] i_target OCMB target
/// @param[in] i_data Raw data bytes
/// @param[in,out] io_current_idx Current parsing index
/// @param[in,out] io_pass any errors occurred during reading/endian-swapping
/// @param[in,out] io_resp user_2d_eye_response_2_msdg
/// @note this function expects io_current_index to be set correctly to the start of eye capture data
///
template<>
inline void read_eye_capture_response<user_2d_eye_response_2_msdg>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target,
        const std::vector<uint8_t>& i_data,
        uint32_t& io_current_idx,
        bool& io_pass,
        user_2d_eye_response_2_msdg& io_resp)
{

    // Eye capture step 1 struct
    uint32_t l_idx = io_current_idx;
    bool l_pass = io_pass;

    // VrefDQ: 3D array of 2 1D arrays
    for (uint8_t l_num_ranks = 0; l_num_ranks < TRAINING_RESPONSE_NUM_RANKS; ++l_num_ranks)
    {
        for (uint8_t l_dbyte_n_size = 0; l_dbyte_n_size < DBYTE_N_SIZE; ++ l_dbyte_n_size)
        {
            for (uint8_t l_bit_n_sze = 0; l_bit_n_sze < BIT_N_SIZE; ++ l_bit_n_sze)
            {
                l_pass &= readLEArray(i_data, EYE_MIN_MAX_SIZE, l_idx,
                                      &io_resp.write_2d_eye_resp.VrefDQ[l_num_ranks][l_dbyte_n_size][l_bit_n_sze].eye_min[0]);
                l_pass &= readLEArray(i_data, EYE_MIN_MAX_SIZE, l_idx,
                                      &io_resp.write_2d_eye_resp.VrefDQ[l_num_ranks][l_dbyte_n_size][l_bit_n_sze].eye_max[0]);
            }
        }
    }

    // 2D array VrefDQ_Center [TRAINING_RESPONSE_NUM_RANKS][NIBBLE_N_SIZE]
    l_pass &= readLEArray(i_data, (TRAINING_RESPONSE_NUM_RANKS * NIBBLE_N_SIZE), l_idx,
                          &io_resp.write_2d_eye_resp.VrefDQ_Center[0][0]);

    // 3D array TxDqDly_Center [TRAINING_RESPONSE_NUM_RANKS][DBYTE_N_SIZE][DBYTE_N_SIZE]
    l_pass &= readLEArray(i_data, (TRAINING_RESPONSE_NUM_RANKS * DBYTE_N_SIZE * BIT_N_SIZE), l_idx,
                          &io_resp.write_2d_eye_resp.TxDqDly_Center[0][0][0]);

    io_pass = l_pass;
    io_current_idx = l_idx;

    return;
}

///
/// @brief Parse the MRS data from the response to correct attributes
/// @param[in] i_target OCMB chip
/// @param[in] i_resp MRS response struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode parse_mrs_data_attributes(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const user_response_mrs_msdg_t& i_resp);

///
/// @brief Read the common block of fields from the training response structs
///
/// @tparam T training repsonse struct type
/// @param[in] i_target OCMB chip
/// @param[in] i_data response data
/// @param[in] i_current_idx last index left off
/// @param[in] i_pass response parsing success thus far
/// @param[in,out] io_resp response struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template <typename T>
fapi2::ReturnCode read_tm_err_mrs_rc_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        const uint32_t i_current_idx,
        const bool i_pass,
        T& io_resp)
{
    uint32_t l_idx = i_current_idx;
    bool l_pass = i_pass;

    uint16_t l_DFIMRL_DDRCLK_trained = 0;

    // Reads in the timing portion of the training response
    l_pass &= readLE(i_data, l_idx, l_DFIMRL_DDRCLK_trained);
    l_pass &= readLEArray(i_data, TIMING_RESPONSE_2D_ARRAY_SIZE, l_idx, &io_resp.tm_resp.CDD_RR[0][0]);
    l_pass &= readLEArray(i_data, TIMING_RESPONSE_2D_ARRAY_SIZE, l_idx, &io_resp.tm_resp.CDD_WW[0][0]);
    l_pass &= readLEArray(i_data, TIMING_RESPONSE_2D_ARRAY_SIZE, l_idx, &io_resp.tm_resp.CDD_RW[0][0]);
    l_pass &= readLEArray(i_data, TIMING_RESPONSE_2D_ARRAY_SIZE, l_idx, &io_resp.tm_resp.CDD_WR[0][0]);

    // Write to user_response_msdg
    io_resp.tm_resp.DFIMRL_DDRCLK_trained = l_DFIMRL_DDRCLK_trained;

    // Error response
    l_pass &= readLEArray(i_data, 80, l_idx, io_resp.err_resp.Failure_Lane);

    uint16_t l_MR0 = 0;
    uint16_t l_MR3 = 0;
    uint16_t l_MR4 = 0;

    // MRS response
    l_pass &= readLE(i_data, l_idx, l_MR0);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RANKS, l_idx, io_resp.mrs_resp.MR1);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RANKS, l_idx, io_resp.mrs_resp.MR2);
    l_pass &= readLE(i_data, l_idx, l_MR3);
    l_pass &= readLE(i_data, l_idx, l_MR4);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RANKS, l_idx, io_resp.mrs_resp.MR5);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_MR6_SIZE, l_idx, &io_resp.mrs_resp.MR6[0][0]);

    io_resp.mrs_resp.MR0 = l_MR0;
    io_resp.mrs_resp.MR3 = l_MR3;
    io_resp.mrs_resp.MR4 = l_MR4;

    // Register Control Word (RCW) response
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RC, l_idx, io_resp.rc_resp.F0RC_D0);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RC, l_idx, io_resp.rc_resp.F1RC_D0);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RC, l_idx, io_resp.rc_resp.F0RC_D1);
    l_pass &= readLEArray(i_data, TRAINING_RESPONSE_NUM_RC, l_idx, io_resp.rc_resp.F1RC_D1);

    // Check if we have errors
    FAPI_ASSERT( l_pass,
                 fapi2::EXP_INBAND_LE_DATA_RANGE()
                 .set_TARGET(i_target)
                 .set_FUNCTION(mss::exp::READ_TRAINING_RESPONSE_STRUCT)
                 .set_DATA_SIZE(i_data.size())
                 .set_CURRENT_INDEX(i_current_idx)
                 .set_MAX_INDEX(sizeof(T)),
                 "%s Failed to convert from data to host_fw_response_struct data size %u expected size %u",
                 mss::c_str(i_target), i_data.size(), sizeof(T));

    // Set MR attributes based on settings
    FAPI_TRY( parse_mrs_data_attributes(i_target, io_resp.mrs_resp));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Explorer's bad bit interface class
/// @tparam T user response struct type
///
template <typename T>
class bad_bit_interface
{
    public:

        // Data that actually stores all of the bad bit information
        // We do some processing in the constructor
        uint8_t iv_bad_bits[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT];

        // No default constructor
        bad_bit_interface() = delete;

        ///
        /// @brief Default destructor
        ///
        ~bad_bit_interface() = default;

        ///
        /// @brief Constructor
        /// @param[in] i_response response data from training
        ///
        bad_bit_interface(const T& i_response )
        {
            // First, clear everything
            std::fill(&iv_bad_bits[0][0], &iv_bad_bits[0][0] + sizeof(iv_bad_bits), 0);

            // Loop through and process by bytes
            for(uint64_t l_byte = 0; l_byte < BAD_DQ_BYTE_COUNT; ++l_byte)
            {
                const auto l_bit_start = l_byte * BITS_PER_BYTE;

                fapi2::buffer<uint8_t> l_rank0;
                fapi2::buffer<uint8_t> l_rank1;
                fapi2::buffer<uint8_t> l_rank2;
                fapi2::buffer<uint8_t> l_rank3;

                // Process bit by bit for all ranks
                // TK update to be the real bits
                process_bit<0>(i_response.err_resp.Failure_Lane[l_bit_start], l_rank0, l_rank1, l_rank2, l_rank3);
                process_bit<1>(i_response.err_resp.Failure_Lane[l_bit_start + 1], l_rank0, l_rank1, l_rank2, l_rank3);
                process_bit<2>(i_response.err_resp.Failure_Lane[l_bit_start + 2], l_rank0, l_rank1, l_rank2, l_rank3);
                process_bit<3>(i_response.err_resp.Failure_Lane[l_bit_start + 3], l_rank0, l_rank1, l_rank2, l_rank3);
                process_bit<4>(i_response.err_resp.Failure_Lane[l_bit_start + 4], l_rank0, l_rank1, l_rank2, l_rank3);
                process_bit<5>(i_response.err_resp.Failure_Lane[l_bit_start + 5], l_rank0, l_rank1, l_rank2, l_rank3);
                process_bit<6>(i_response.err_resp.Failure_Lane[l_bit_start + 6], l_rank0, l_rank1, l_rank2, l_rank3);
                process_bit<7>(i_response.err_resp.Failure_Lane[l_bit_start + 7], l_rank0, l_rank1, l_rank2, l_rank3);

                // Assign the results to the bad bits internal structure
                // At this point, we want to assign all data
                // We'll only copy real data over to the bad bit attribute IFF
                iv_bad_bits[0][l_byte] = l_rank0;
                iv_bad_bits[1][l_byte] = l_rank1;
                iv_bad_bits[2][l_byte] = l_rank2;
                iv_bad_bits[3][l_byte] = l_rank3;
            }
        }

        ///
        /// @brief Processes a single bit from the response structure
        /// @tparam B the bit position to process
        /// @param[in] i_data the encoded data from the response structure
        /// @param[in,out] io_rank0 rank 0's values
        /// @param[in,out] io_rank1 rank 1's values
        /// @param[in,out] io_rank2 rank 2's values
        /// @param[in,out] io_rank3 rank 3's values
        ///
        template <uint64_t B>
        void process_bit(const fapi2::buffer<uint16_t>& i_data,
                         fapi2::buffer<uint8_t>& io_rank0,
                         fapi2::buffer<uint8_t>& io_rank1,
                         fapi2::buffer<uint8_t>& io_rank2,
                         fapi2::buffer<uint8_t>& io_rank3)
        {
            constexpr uint64_t RANK_LEN = 4;
            constexpr uint64_t RANK0 = 12;
            constexpr uint64_t RANK1 = 8;
            constexpr uint64_t RANK2 = 4;
            constexpr uint64_t RANK3 = 0;

            io_rank0.writeBit<B>(i_data.getBit<RANK0, RANK_LEN>());
            io_rank1.writeBit<B>(i_data.getBit<RANK1, RANK_LEN>());
            io_rank2.writeBit<B>(i_data.getBit<RANK2, RANK_LEN>());
            io_rank3.writeBit<B>(i_data.getBit<RANK3, RANK_LEN>());
        }

        ///
        /// @param[in] i_target the DIMM to record training results on
        /// @param[out] o_bad_bits the processed bad bits
        ///
        fapi2::ReturnCode record_bad_bits_interface( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t (&o_bad_dq)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]) const
        {
            std::vector<mss::rank::info<>> l_rank_infos;
            FAPI_TRY(mss::rank::ranks_on_dimm(i_target, l_rank_infos));

            for(const auto& l_rank_info : l_rank_infos)
            {
                // Note: we copy from the PHY rank to the DIMM rank
                // The we take in is taken from the PHY structure, which uses PHY rank perspective
                // Our attributes use the IBM rank perspective
                // If there is any swizzle (see quad encoded chip select bug JIRA355), then this will fix it for us
                std::copy(std::begin(iv_bad_bits[l_rank_info.get_phy_rank()]),
                          std::end(iv_bad_bits[l_rank_info.get_phy_rank()]),
                          std::begin(o_bad_dq[l_rank_info.get_dimm_rank()]));
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }
};


///
/// @brief Reads the training response structure
/// @param[in] i_target the target associated with the response data
/// @param[in] i_data the response data to read
/// @param[out] o_resp the processed training response class
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode read_normal_training_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        user_response_msdg& o_resp);

///
/// @brief Reads user 2d eye response 1
/// @tparam T response struct
/// @param[in] i_target the target associated with the response data
/// @param[in] i_data the response data to read
/// @param[out] o_resp the processed training response class
/// @return FAPI2_RC_SUCCESS if ok
///
template <typename T>
inline fapi2::ReturnCode read_user_2d_eye_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        T& o_resp)
{
    // First let's erase the struct
    memset(&o_resp, 0, sizeof(T));
    // We assert at the end to avoid LOTS of fapi asserts
    uint32_t l_idx = 0;
    uint32_t l_version_number = 0;
    bool l_pass = readLE(i_data, l_idx, l_version_number);
    o_resp.version_number = l_version_number;

    read_eye_capture_response<T>(i_target, i_data, l_idx, l_pass, o_resp);

    FAPI_TRY(read_tm_err_mrs_rc_response<T>(i_target, i_data, l_idx, l_pass, o_resp));

fapi_try_exit:
    return fapi2::current_err;
}


} // ns exp
} // ns mss

#endif
