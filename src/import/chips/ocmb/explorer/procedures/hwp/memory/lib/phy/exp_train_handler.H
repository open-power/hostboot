/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_train_handler.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __EXP_TRAIN_HANDLER_H__
#define __EXP_TRAIN_HANDLER_H__

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <generic/memory/lib/mss_generic_attribute_setters.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>

namespace mss
{
namespace exp
{

///
/// @brief Reads the training response structure
/// @param[in] i_target the target associated with the response data
/// @param[in] i_data the response data to read
/// @param[out] o_resp the processed training response class
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode read_training_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        user_response_msdg& o_resp);

///
/// @brief Explorer's bad bit interface class
/// @brief Explorer's bad bit interface class
///
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
        bad_bit_interface(const user_response_msdg_t& i_response )
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
            // Gets the rank offset for this DIMM
            const uint64_t DIMM_OFFSET = mss::index(i_target) == 0 ? 0 : 2;

            // Loops through all of the ranks on this DIMM
            uint8_t l_num_ranks = 0;
            FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_target, l_num_ranks));

            // TK Add in num ranks check here
            // TK update for the ranks API

            for(uint64_t l_rank = 0; l_rank < l_num_ranks; ++l_rank)
            {
                const uint64_t RANK = DIMM_OFFSET + l_rank;
                FAPI_ASSERT(RANK < mss::exp::MAX_RANK_PER_DIMM,
                            fapi2::MSS_EXP_DRAMINIT_BAD_NUM_RANKS()
                            .set_NUM_RANKS(RANK)
                            .set_MAX_RANKS(mss::exp::MAX_RANK_PER_DIMM)
                            .set_TARGET(i_target),
                            "%s bad number of ranks passed num:%u, max:%u",
                            mss::c_str(i_target), RANK, mss::exp::MAX_RANK_PER_DIMM);

                memcpy(&o_bad_dq[RANK], &iv_bad_bits[RANK], sizeof(uint8_t[BAD_DQ_BYTE_COUNT]));
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }
};

} // ns exp
} // ns mss

#endif
