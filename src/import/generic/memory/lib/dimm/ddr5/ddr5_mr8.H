/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr8.H $          */
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
/// @file ddr5_mr8.H
/// @brief Run and manage the DDR5 MR8 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR8_H_
#define _GENERIC_DDR5_MR8_H_

#include <fapi2.H>

#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/num.H>
#include <generic/memory/lib/utils/mss_pair.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr_base.H>

namespace mss
{

namespace ddr5
{

///
/// @brief Data structure for DDR5 MR8
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr8_data : public mr_base_data<MC>
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 8;

        ///
        /// @brief mr8_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr8_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc ) : mr_base_data<MC>(iv_mr)
        {

            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            const auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

            FAPI_TRY( mss::attr::get_ddr5_dram_rd_preamble(l_port_target, iv_rd_preamble), "Error in ddr5::mr8_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dram_wr_preamble(l_port_target, iv_wr_preamble), "Error in ddr5::mr8_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dram_rd_postamble(l_port_target, iv_rd_postamble), "Error in ddr5::mr8_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dram_wr_postamble(l_port_target, iv_wr_postamble), "Error in ddr5::mr8_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr4", TARGTID);
            return;
        }
        static constexpr const pair<uint8_t, uint8_t> WR_TABLE[3] =
        {
            {fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK2, 0b001},
            {fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK3, 0b010},
            {fapi2::ENUM_ATTR_DDR5_DRAM_WR_PREAMBLE_TCK4, 0b011},
        };

        static constexpr const pair<uint8_t, uint8_t> RD_TABLE[5] =
        {
            {fapi2::ENUM_ATTR_DDR5_DRAM_RD_PREAMBLE_TCK1,      0b000},
            {fapi2::ENUM_ATTR_DDR5_DRAM_RD_PREAMBLE_TCK2_OPT1, 0b001},
            {fapi2::ENUM_ATTR_DDR5_DRAM_RD_PREAMBLE_TCK2_OPT2, 0b010},
            {fapi2::ENUM_ATTR_DDR5_DRAM_RD_PREAMBLE_TCK3,      0b011},
            {fapi2::ENUM_ATTR_DDR5_DRAM_RD_PREAMBLE_TCK4,      0b100},
        };

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr8_data(): mr_base_data<MC>(iv_mr) {};

        ///
        /// @brief Checks and converts the write preamble from the attribute value to the MR field value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_attr the attribute value
        /// @param[out] o_field the field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_wr_preamble_to_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_attr,
                uint8_t& o_field) const
        {
            FAPI_ASSERT(find_value_from_key<3>(WR_TABLE,
                                               i_attr,
                                               o_field),
                        fapi2::MSS_DDR5_MR8_WR_PREAMBLE_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_VALUE(i_attr),
                        TARGTIDFORMAT " DDR5 MR8. Bad WR preamble attr value: %u", TARGTID, i_attr);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the read preamble from the attribute value to the MR field value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_attr the attribute value
        /// @param[out] o_field the field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_rd_preamble_to_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_attr,
                uint8_t& o_field) const
        {
            FAPI_ASSERT(find_value_from_key<5>(RD_TABLE,
                                               i_attr,
                                               o_field),
                        fapi2::MSS_DDR5_MR8_RD_PREAMBLE_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_VALUE(i_attr),
                        TARGTIDFORMAT " DDR5 MR8. Bad RD preamble attr value: %u", TARGTID, i_attr);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the write preamble from the MR field value to the attribute value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_field the field value
        /// @param[out] o_value the attribute value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_wr_preamble_from_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_field,
                uint8_t& o_value) const
        {
            FAPI_ASSERT(find_key_from_value<3>(WR_TABLE,
                                               i_field,
                                               o_value),
                        fapi2::MSS_DDR5_MR8_WR_PREAMBLE_FIELD_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_FIELD(i_field),
                        TARGTIDFORMAT " DDR5 MR8. Bad WR preamble field value: %u", TARGTID, i_field);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the read preamble from the MR field value to the attribute value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_field the field value
        /// @param[out] o_value the attribute value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_rd_preamble_from_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_field,
                uint8_t& o_value) const
        {
            FAPI_ASSERT(find_key_from_value<5>(RD_TABLE,
                                               i_field,
                                               o_value),
                        fapi2::MSS_DDR5_MR8_RD_PREAMBLE_FIELD_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_FIELD(i_field),
                        TARGTIDFORMAT " DDR5 MR8. Bad RD preamble field value: %u", TARGTID, i_field);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR8
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR8 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            fapi2::buffer<uint8_t> l_data;
            uint8_t l_wr_preamble_field = 0;
            uint8_t l_rd_preamble_field = 0;

            FAPI_TRY(check_and_convert_wr_preamble_to_field(i_rank_info.get_dimm_target(), iv_wr_preamble, l_wr_preamble_field));
            FAPI_TRY(check_and_convert_rd_preamble_to_field(i_rank_info.get_dimm_target(), iv_rd_preamble, l_rd_preamble_field));

            l_data. template insertFromRight<RD_PREAMBLE, RD_PREAMBLE_LEN>(l_rd_preamble_field)
            . template insertFromRight<WR_PREAMBLE, WR_PREAMBLE_LEN>(l_wr_preamble_field)
            . template writeBit<RD_POSTAMBLE>(fapi2::ENUM_ATTR_DDR5_DRAM_RD_POSTAMBLE_TCK1P5 == iv_rd_postamble)
            . template writeBit<WR_POSTAMBLE>(fapi2::ENUM_ATTR_DDR5_DRAM_WR_POSTAMBLE_TCK1P5 == iv_wr_postamble);
            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR8 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
        {
            display(i_rank_info.get_dimm_target());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR8 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR8 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info, const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {

            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_wr_preamble_field = 0;
            uint8_t l_rd_preamble_field = 0;

            l_data. template extractToRight<RD_PREAMBLE, RD_PREAMBLE_LEN>(l_rd_preamble_field)
            . template extractToRight<WR_PREAMBLE, WR_PREAMBLE_LEN>(l_wr_preamble_field);

            FAPI_TRY(check_and_convert_wr_preamble_from_field(i_rank_info.get_dimm_target(), l_wr_preamble_field, iv_wr_preamble));
            FAPI_TRY(check_and_convert_rd_preamble_from_field(i_rank_info.get_dimm_target(), l_rd_preamble_field, iv_rd_preamble));


            iv_rd_postamble = l_data.getBit<RD_POSTAMBLE>() ? fapi2::ENUM_ATTR_DDR5_DRAM_RD_POSTAMBLE_TCK1P5 :
                              fapi2::ENUM_ATTR_DDR5_DRAM_RD_POSTAMBLE_TCK0P5;
            iv_wr_postamble = l_data.getBit<WR_POSTAMBLE>() ? fapi2::ENUM_ATTR_DDR5_DRAM_WR_POSTAMBLE_TCK1P5 :
                              fapi2::ENUM_ATTR_DDR5_DRAM_WR_POSTAMBLE_TCK0P5;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            RD_PREAMBLE = 5,
            RD_PREAMBLE_LEN = 3,
            WR_PREAMBLE = 3,
            WR_PREAMBLE_LEN = 2,
            RD_POSTAMBLE = 1,
            WR_POSTAMBLE = 0,
        };

        uint8_t iv_rd_preamble = 0;
        uint8_t iv_wr_preamble = 0;
        uint8_t iv_rd_postamble = 0;
        uint8_t iv_wr_postamble = 0;

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
        {
            FAPI_INF(TARGTIDFORMAT " DDR5 MR8. RD preamble:  %u. WR preamble:  %u", TARGTID, iv_rd_preamble,  iv_wr_preamble);
            FAPI_INF(TARGTIDFORMAT " DDR5 MR8. RD postamble: %u. WR postamble: %u", TARGTID, iv_rd_postamble, iv_wr_postamble);
        }
};

// Adds in linkage
template<mss::mc_type MC>
constexpr const pair<uint8_t, uint8_t> mr8_data<MC>::WR_TABLE[3];
template<mss::mc_type MC>
constexpr const pair<uint8_t, uint8_t> mr8_data<MC>::RD_TABLE[5];

} // ns ddr5

} // ns mss

#endif
