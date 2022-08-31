/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr34.H $         */
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
/// @file ddr5_mr34.H
/// @brief Run and manage the DDR5 MR34 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR34_H_
#define _GENERIC_DDR5_MR34_H_

#include <fapi2.H>

#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/num.H>

namespace mss
{

namespace ddr5
{

///
/// @brief Data structure for DDR5 MR34
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr34_data
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 34;

        ///
        /// @brief mr34_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr34_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc )
        {
            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            FAPI_TRY( mss::attr::get_si_dram_rtt_park(i_target, iv_rtt_park),
                      "Error in ddr5::mr34_data()" );
            FAPI_TRY( mss::attr::get_si_dram_rtt_wr(i_target, iv_rtt_wr),
                      "Error in ddr5::mr34_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr34", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr34_data() = default;

        static constexpr const pair<uint8_t, uint8_t> RTT_TABLE[8] =
        {
            {fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_DISABLE , 0b000},
            {fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM34   , 0b111},
            {fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM40   , 0b110},
            {fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM48   , 0b101},
            {fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM60   , 0b100},
            {fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM80   , 0b011},
            {fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM120  , 0b010},
            {fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM240  , 0b001},
        };

        ///
        /// @brief Checks and converts the attribute CA DQS value to its associated field value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the attr value is being checked
        /// @param[in] i_is_rtt_wr true if this is checking RTT_WR, otherwise false
        /// @param[in] i_value the value to check
        /// @param[out] o_field the generated field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_rtt_to_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_dimm_rank,
                const uint8_t i_is_rtt_wr,
                const uint8_t i_value,
                uint8_t& o_field) const
        {
            FAPI_ASSERT(find_value_from_key<8>(RTT_TABLE,
                                               i_value,
                                               o_field),
                        fapi2::MSS_DDR5_MR34_RTT_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_VALUE(i_value)
                        .set_IS_RTT_WR(i_is_rtt_wr),
                        TARGTIDFORMAT " DDR5 MR34. Bad RTT %s value on DIMM rank %u, Value: %u", TARGTID,
                        i_is_rtt_wr ? "WR" : "PARK", i_dimm_rank, i_value);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the field CA DQS value to its associated attribute value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the attr value is being checked
        /// @param[in] i_is_rtt_wr true if this is checking RTT_WR, otherwise false
        /// @param[in] i_field the field value to convert
        /// @param[out] o_value the generated field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_rtt_from_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_dimm_rank,
                const uint8_t i_is_rtt_wr,
                const uint8_t i_field,
                uint8_t& o_value) const
        {
            FAPI_ASSERT(find_key_from_value<8>(RTT_TABLE,
                                               i_field,
                                               o_value),
                        fapi2::MSS_DDR5_MR34_RTT_FIELD_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_FIELD(i_field)
                        .set_IS_RTT_WR(i_is_rtt_wr),
                        TARGTIDFORMAT " DDR5 MR34. Bad RTT %s field on DIMM rank %u. Field value: %u", TARGTID,
                        i_is_rtt_wr ? "WR" : "PARK", i_dimm_rank, i_field);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR34
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR34 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const
        {
            fapi2::buffer<uint8_t> l_data;
            uint8_t l_rtt_park_field = 0;
            uint8_t l_rtt_wr_field = 0;

            // Note: not checking DIMM rank as it was already checked by the rank info class
            const auto& l_dimm = i_rank_info.get_dimm_target();
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();
            FAPI_TRY(check_and_convert_rtt_to_field(l_dimm,
                                                    l_dimm_rank,
                                                    false,
                                                    iv_rtt_park[l_dimm_rank],
                                                    l_rtt_park_field));
            FAPI_TRY(check_and_convert_rtt_to_field(l_dimm,
                                                    l_dimm_rank,
                                                    true,
                                                    iv_rtt_wr[l_dimm_rank],
                                                    l_rtt_wr_field));

            l_data. template insertFromRight<RTT_PARK, RTT_PARK_LEN>(l_rtt_park_field)
            . template insertFromRight<RTT_WR, RTT_WR_LEN>(l_rtt_wr_field);
            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;

        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR34 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const
        {
            this->display(i_rank_info.get_dimm_target(), i_rank_info.get_dimm_rank());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR34 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR34 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0)
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_rtt_park_field = 0;
            uint8_t l_rtt_wr_field = 0;

            l_data. template extractToRight<RTT_WR, RTT_WR_LEN>(l_rtt_wr_field)
            . template extractToRight<RTT_PARK, RTT_PARK_LEN>(l_rtt_park_field);

            // Note: not checking DIMM rank as it was already checked by the rank info class
            const auto& l_dimm = i_rank_info.get_dimm_target();
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();

            FAPI_TRY(check_and_convert_rtt_from_field(l_dimm,
                     l_dimm_rank,
                     false,
                     l_rtt_park_field,
                     iv_rtt_park[l_dimm_rank]));
            FAPI_TRY(check_and_convert_rtt_from_field(l_dimm,
                     l_dimm_rank,
                     true,
                     l_rtt_wr_field,
                     iv_rtt_wr[l_dimm_rank]));


            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            RTT_PARK = 5,
            RTT_PARK_LEN = 3,
            RTT_WR = 2,
            RTT_WR_LEN = 3,
        };

        uint8_t iv_rtt_park[mr::ATTR_RANKS] = {};
        uint8_t iv_rtt_wr[mr::ATTR_RANKS] = {};

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank's value to print
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, const uint64_t i_dimm_rank) const
        {
            FAPI_INF(TARGTIDFORMAT
                     " DDR5 MR34 rank%u. RTT Park:%u. RTT WR:%u.", TARGTID, i_dimm_rank, iv_rtt_park[i_dimm_rank], iv_rtt_wr[i_dimm_rank]);
        }

};

template<mss::mc_type MC>
constexpr const pair<uint8_t, uint8_t> mr34_data<MC>::RTT_TABLE[8];

} // ns ddr5

} // ns mss

#endif
