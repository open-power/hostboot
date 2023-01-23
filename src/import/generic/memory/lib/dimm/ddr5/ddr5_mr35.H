/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr35.H $         */
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
/// @file ddr5_mr35.H
/// @brief Run and manage the DDR5 MR35 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR35_H_
#define _GENERIC_DDR5_MR35_H_

#include <fapi2.H>

#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/num.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr_base.H>

namespace mss
{

namespace ddr5
{

///
/// @brief Data structure for DDR5 MR35
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr35_data : public mr_base_data<MC>
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 35;

        ///
        /// @brief mr35_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr35_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc ) : mr_base_data<MC>(iv_mr)
        {

            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            FAPI_TRY( mss::attr::get_ddr5_dram_rtt_nom_wr(i_target, iv_rtt_nom_wr),
                      "Error in ddr5::mr35_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dram_rtt_nom_rd(i_target, iv_rtt_nom_rd),
                      "Error in ddr5::mr35_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr35", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr35_data(): mr_base_data<MC>(iv_mr) {};

        // For DDR5, RTT Park and RTT WR have the same decodes
        static const pair<uint8_t, uint8_t> RTT_TABLE[8];

        ///
        /// @brief Checks and converts the attribute CA DQS value to its associated field value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the attr value is being checked
        /// @param[in] i_is_read true if this is checking RTT_NOM_RD, otherwise false
        /// @param[in] i_value the value to check
        /// @param[out] o_field the generated field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_rtt_to_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_dimm_rank,
                const uint8_t i_is_read,
                const uint8_t i_value,
                uint8_t& o_field) const
        {
            FAPI_ASSERT(find_value_from_key<8>(RTT_TABLE,
                                               i_value,
                                               o_field),
                        fapi2::MSS_DDR5_MR35_RTT_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_VALUE(i_value)
                        .set_IS_RTT_NOM_RD(i_is_read),
#ifdef __PPE__
                        TARGTIDFORMAT " DDR5 MR35. Bad RTT %u value on DIMM rank %u, Value: %u", TARGTID,
                        i_is_read, i_dimm_rank, i_value);
#else
                        TARGTIDFORMAT " DDR5 MR35. Bad RTT %s value on DIMM rank %u, Value: %u", TARGTID,
                        i_is_read ? "RD" : "WR", i_dimm_rank, i_value);
#endif

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the field CA DQS value to its associated attribute value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the attr value is being checked
        /// @param[in] i_is_read true if this is checking RTT_NOM_RD, otherwise false
        /// @param[in] i_field the field value to convert
        /// @param[out] o_value the generated field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_rtt_from_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_dimm_rank,
                const uint8_t i_is_read,
                const uint8_t i_field,
                uint8_t& o_value) const
        {
            FAPI_ASSERT(find_key_from_value<8>(RTT_TABLE,
                                               i_field,
                                               o_value),
                        fapi2::MSS_DDR5_MR35_RTT_FIELD_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_FIELD(i_field)
                        .set_IS_RTT_NOM_RD(i_is_read),
#ifdef __PPE__
                        TARGTIDFORMAT " DDR5 MR35. Bad RTT %u field on DIMM rank %u, strap%u. Field value: %u", TARGTID,
                        i_is_read, i_dimm_rank, i_field);
#else
                        TARGTIDFORMAT " DDR5 MR35. Bad RTT %s field on DIMM rank %u, strap%u. Field value: %u", TARGTID,
                        i_is_read ? "RD" : "WR", i_dimm_rank, i_field);
#endif

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR35
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR35 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            fapi2::buffer<uint8_t> l_data;
            uint8_t l_rtt_nom_wr_field = 0;
            uint8_t l_rtt_nom_rd_field = 0;

            // Note: not checking DIMM rank as it was already checked by the rank info class
            const auto& l_dimm = i_rank_info.get_dimm_target();
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();
            FAPI_TRY(check_and_convert_rtt_to_field(l_dimm,
                                                    l_dimm_rank,
                                                    false,
                                                    iv_rtt_nom_wr[l_dimm_rank],
                                                    l_rtt_nom_wr_field));
            FAPI_TRY(check_and_convert_rtt_to_field(l_dimm,
                                                    l_dimm_rank,
                                                    true,
                                                    iv_rtt_nom_rd[l_dimm_rank],
                                                    l_rtt_nom_rd_field));

            l_data. template insertFromRight<RTT_NOM_WR, RTT_NOM_WR_LEN>(l_rtt_nom_wr_field)
            . template insertFromRight<RTT_NOM_RD, RTT_NOM_RD_LEN>(l_rtt_nom_rd_field);
            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;

        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR35 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
        {
            this->display(i_rank_info.get_dimm_target(), i_rank_info.get_dimm_rank());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR35 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR35 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_rtt_nom_wr_field = 0;
            uint8_t l_rtt_nom_rd_field = 0;

            l_data. template extractToRight<RTT_NOM_RD, RTT_NOM_RD_LEN>(l_rtt_nom_rd_field)
            . template extractToRight<RTT_NOM_WR, RTT_NOM_WR_LEN>(l_rtt_nom_wr_field);

            // Note: not checking DIMM rank as it was already checked by the rank info class
            const auto& l_dimm = i_rank_info.get_dimm_target();
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();

            FAPI_TRY(check_and_convert_rtt_from_field(l_dimm,
                     l_dimm_rank,
                     false,
                     l_rtt_nom_wr_field,
                     iv_rtt_nom_wr[l_dimm_rank]));
            FAPI_TRY(check_and_convert_rtt_from_field(l_dimm,
                     l_dimm_rank,
                     true,
                     l_rtt_nom_rd_field,
                     iv_rtt_nom_rd[l_dimm_rank]));


            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            RTT_NOM_WR = 5,
            RTT_NOM_WR_LEN = 3,
            RTT_NOM_RD = 2,
            RTT_NOM_RD_LEN = 3,
        };

        uint8_t iv_rtt_nom_wr[mr::ATTR_RANKS] = {};
        uint8_t iv_rtt_nom_rd[mr::ATTR_RANKS] = {};

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank's value to print
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, const uint64_t i_dimm_rank)  const
        {
            FAPI_INF(TARGTIDFORMAT
                     " DDR5 MR35 rank%u. RTT NOM WR:%u. RTT NOM RD:%u.", TARGTID, i_dimm_rank, iv_rtt_nom_wr[i_dimm_rank],
                     iv_rtt_nom_rd[i_dimm_rank]);
        }

};

template<mss::mc_type MC>
const pair<uint8_t, uint8_t> mr35_data<MC>::RTT_TABLE[8] =
{
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_DISABLE , 0b000),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM34   , 0b111),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM40   , 0b110),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM48   , 0b101),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM60   , 0b100),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM80   , 0b011),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM120  , 0b010),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_RTT_NOM_WR_OHM240  , 0b001),
};

} // ns ddr5

} // ns mss

#endif
