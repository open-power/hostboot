/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/utils/ody_bad_bits.H $ */
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
/// @file ody_bad_bits.H
/// @brief Odyssey bad DQ bits handling classes
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_BAD_BITS_H_
#define _ODY_BAD_BITS_H_

#include <fapi2.H>
#include <lib/shared/ody_consts.H>
#include <lib/dimm/ody_rank.H>
#include <lib/phy/ody_snps_dram_train_msg_blk.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>

namespace mss
{
namespace ody
{
namespace phy
{

///
/// @brief Odyssey's bad bit interface class
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
        /// @brief Constructor from PHY response struct
        /// @param[in] i_response response data from training
        ///
        bad_bit_interface(const _PMU_SMB_DDR5_1D_t& i_response )
        {
            // Assign the results to the bad bits internal structure
            // At this point, we want to assign all data
            // TODO Zen:MST-1933 Handle byte swizzle to put the attribute into the MC perspective
            iv_bad_bits[0][0] = i_response.DisabledDB0LaneR0;
            iv_bad_bits[0][1] = i_response.DisabledDB1LaneR0;
            iv_bad_bits[0][2] = i_response.DisabledDB2LaneR0;
            iv_bad_bits[0][3] = i_response.DisabledDB3LaneR0;
            iv_bad_bits[0][4] = i_response.DisabledDB4LaneR0;
            iv_bad_bits[0][5] = i_response.DisabledDB5LaneR0;
            iv_bad_bits[0][6] = i_response.DisabledDB6LaneR0;
            iv_bad_bits[0][7] = i_response.DisabledDB7LaneR0;
            iv_bad_bits[0][8] = i_response.DisabledDB8LaneR0;
            iv_bad_bits[0][9] = i_response.DisabledDB9LaneR0;

            iv_bad_bits[1][0] = i_response.DisabledDB0LaneR1;
            iv_bad_bits[1][1] = i_response.DisabledDB1LaneR1;
            iv_bad_bits[1][2] = i_response.DisabledDB2LaneR1;
            iv_bad_bits[1][3] = i_response.DisabledDB3LaneR1;
            iv_bad_bits[1][4] = i_response.DisabledDB4LaneR1;
            iv_bad_bits[1][5] = i_response.DisabledDB5LaneR1;
            iv_bad_bits[1][6] = i_response.DisabledDB6LaneR1;
            iv_bad_bits[1][7] = i_response.DisabledDB7LaneR1;
            iv_bad_bits[1][8] = i_response.DisabledDB8LaneR1;
            iv_bad_bits[1][9] = i_response.DisabledDB9LaneR1;

            iv_bad_bits[2][0] = i_response.DisabledDB0LaneR2;
            iv_bad_bits[2][1] = i_response.DisabledDB1LaneR2;
            iv_bad_bits[2][2] = i_response.DisabledDB2LaneR2;
            iv_bad_bits[2][3] = i_response.DisabledDB3LaneR2;
            iv_bad_bits[2][4] = i_response.DisabledDB4LaneR2;
            iv_bad_bits[2][5] = i_response.DisabledDB5LaneR2;
            iv_bad_bits[2][6] = i_response.DisabledDB6LaneR2;
            iv_bad_bits[2][7] = i_response.DisabledDB7LaneR2;
            iv_bad_bits[2][8] = i_response.DisabledDB8LaneR2;
            iv_bad_bits[2][9] = i_response.DisabledDB9LaneR2;

            iv_bad_bits[3][0] = i_response.DisabledDB0LaneR3;
            iv_bad_bits[3][1] = i_response.DisabledDB1LaneR3;
            iv_bad_bits[3][2] = i_response.DisabledDB2LaneR3;
            iv_bad_bits[3][3] = i_response.DisabledDB3LaneR3;
            iv_bad_bits[3][4] = i_response.DisabledDB4LaneR3;
            iv_bad_bits[3][5] = i_response.DisabledDB5LaneR3;
            iv_bad_bits[3][6] = i_response.DisabledDB6LaneR3;
            iv_bad_bits[3][7] = i_response.DisabledDB7LaneR3;
            iv_bad_bits[3][8] = i_response.DisabledDB8LaneR3;
            iv_bad_bits[3][9] = i_response.DisabledDB9LaneR3;
        }

        ///
        /// @brief Swizzle the bad bits to the attribute's perspective
        /// @param[in] i_target the DIMM to record training results on
        /// @param[out] o_bad_dq the processed bad bits
        ///
        fapi2::ReturnCode record_bad_bits_interface( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t (&o_bad_dq)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]) const
        {
            std::vector<mss::rank::info<mss::mc_type::ODYSSEY>> l_rank_infos;
            FAPI_TRY(mss::rank::ranks_on_dimm(i_target, l_rank_infos));

            for(const auto& l_rank_info : l_rank_infos)
            {
                // Note: we copy from the PHY rank to the DIMM rank
                // The rank we take in is taken from the PHY structure, which uses PHY rank perspective
                // Our attributes use the IBM rank perspective
                // If there is any swizzle, then this will fix it for us
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
/// @brief bad bit interface class for ody_host_draminit (read attr and update SPD)
///
class host_bad_bit_interface
{
    public:

        // Data that actually stores all of the bad bit information
        // We do some processing in the constructor
        uint8_t iv_bad_bits[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT];

        // No default constructor
        host_bad_bit_interface() = delete;

        ///
        /// @brief Default destructor
        ///
        ~host_bad_bit_interface() = default;

        ///
        /// @brief Constructor from DIMM bad bits attribute
        /// @param[in] i_target the DIMM to record training results on
        /// @param[out] o_rc the return code from attribute access
        ///
        host_bad_bit_interface(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                               fapi2::ReturnCode& o_rc)
        {
            o_rc = mss::attr::get_bad_dq_bitmap(i_target, iv_bad_bits);
        }

        ///
        /// @brief Update the bad bits attribute (and SPD)
        /// @param[in] i_target the DIMM to record training results on
        /// @param[out] o_bad_dq the processed bad bits
        ///
        fapi2::ReturnCode record_bad_bits_interface( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t (&o_bad_dq)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]) const
        {
            for(uint8_t l_rank = 0; l_rank < BAD_BITS_RANKS; l_rank++)
            {
                // Note: any rank swizzle is taken care of in the sppe_draminit procedure
                std::copy(std::begin(iv_bad_bits[l_rank]),
                          std::end(iv_bad_bits[l_rank]),
                          std::begin(o_bad_dq[l_rank]));
            }

            return fapi2::FAPI2_RC_SUCCESS;
        }
};

} // namespace phy
} // namespace ody
} // namespace mss
#endif