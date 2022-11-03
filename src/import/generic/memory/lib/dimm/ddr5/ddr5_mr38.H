/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr38.H $         */
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
/// @file ddr5_mr38.H
/// @brief Run and manage the DDR5 MR38 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR38_H_
#define _GENERIC_DDR5_MR38_H_

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
/// @brief Data structure for DDR5 MR38
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr38_data : public mr_base_data<MC>
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 38;

        ///
        /// @brief mr38_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr38_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc ) : mr_base_data<MC>(iv_mr)
        {

            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            FAPI_TRY( mss::attr::get_ddr5_dram_odtlon_wr_nt(i_target, iv_odtlon_wr_nt_offset),
                      "Error in ddr5::mr38_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dram_odtloff_wr_nt(i_target, iv_odtloff_wr_nt_offset),
                      "Error in ddr5::mr38_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr38", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr38_data(): mr_base_data<MC>(iv_mr) {};

        ///
        /// @brief Converts the ODTLon to the field value
        /// @param[in] i_value the attribute value
        /// @return the field value
        ///
        uint8_t odtlon_to_field(const int8_t i_value) const
        {
            return static_cast<uint8_t>(i_value + ON_OFFSET);
        }

        ///
        /// @brief Converts the ODTLon field to the attribute value
        /// @param[in] i_value the field value
        /// @return the attribute value
        ///
        int8_t odtlon_to_attr(const uint8_t i_value) const
        {
            int8_t l_value = static_cast<uint8_t>(i_value);
            return l_value - ON_OFFSET;
        }

        ///
        /// @brief Converts the ODTLoff to the field value
        /// @param[in] i_value the attribute value
        /// @return the field value
        ///
        uint8_t odtloff_to_field(const int8_t i_value) const
        {
            return odtlon_to_field(-1 * i_value);
        }

        ///
        /// @brief Converts the ODTLoff field to the attribute value
        /// @param[in] i_value the field value
        /// @return the attribute value
        ///
        int8_t odtloff_to_attr(const uint8_t i_value) const
        {
            return -1 * odtlon_to_attr(i_value);
        }

        ///
        /// @brief Checks that the ODTLon WR attribute is in range
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the attr value is being checked
        /// @param[in] i_value the value to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_odtlon(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const uint8_t i_dimm_rank,
                                       const int8_t i_value) const
        {
            // Note: if these are updated, update the prints below
            constexpr int8_t MIN = -4;
            constexpr int8_t MAX =  2;
            FAPI_ASSERT(MIN <= i_value && MAX >= i_value,
                        fapi2::MSS_DDR5_MR38_ODTLON_NT_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_VALUE(i_value)
                        .set_MIN(MIN)
                        .set_MAX(MAX),
                        TARGTIDFORMAT " DDR5 MR38. Bad ODTLon_WR value on DIMM rank %u, -4 <= %u <= 2", TARGTID,
                        i_dimm_rank, i_value);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks that the ODTLoff WR attribute is in range
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the attr value is being checked
        /// @param[in] i_value the value to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_odtloff(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint8_t i_dimm_rank,
                                        const int8_t i_value) const
        {
            // Note: if these are updated, update the prints below
            constexpr int8_t MIN = -2;
            constexpr int8_t MAX =  4;
            FAPI_ASSERT(MIN <= i_value && MAX >= i_value,
                        fapi2::MSS_DDR5_MR38_ODTLOFF_NT_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_VALUE(i_value)
                        .set_MIN(MIN)
                        .set_MAX(MAX),
                        TARGTIDFORMAT " DDR5 MR38. Bad ODTLoff_WR value on DIMM rank %u, -2 <= %u <= 4", TARGTID,
                        i_dimm_rank, i_value);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR38
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR38 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            fapi2::buffer<uint8_t> l_data;

            const auto& l_dimm = i_rank_info.get_dimm_target();
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();
            FAPI_TRY(check_odtlon(l_dimm, l_dimm_rank, iv_odtlon_wr_nt_offset[l_dimm_rank]));
            FAPI_TRY(check_odtloff(l_dimm, l_dimm_rank, iv_odtloff_wr_nt_offset[l_dimm_rank]));

            l_data. template insertFromRight<ON, ON_LEN>(odtlon_to_field(iv_odtlon_wr_nt_offset[l_dimm_rank]))
            . template insertFromRight<OFF, OFF_LEN>(odtloff_to_field(iv_odtloff_wr_nt_offset[l_dimm_rank]));
            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR38 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
        {
            this->display(i_rank_info.get_dimm_target(), i_rank_info.get_dimm_rank());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR38 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR38 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_on_field = 0;
            uint8_t l_off_field = 0;

            const auto& l_dimm = i_rank_info.get_dimm_target();
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();

            l_data. template extractToRight<ON, ON_LEN>(l_on_field)
            . template extractToRight<OFF, OFF_LEN>(l_off_field);

            iv_odtlon_wr_nt_offset[l_dimm_rank] = odtlon_to_attr(l_on_field);
            iv_odtloff_wr_nt_offset[l_dimm_rank] = odtloff_to_attr(l_off_field);

            FAPI_TRY(check_odtlon(l_dimm, l_dimm_rank, iv_odtlon_wr_nt_offset[l_dimm_rank]));
            FAPI_TRY(check_odtloff(l_dimm, l_dimm_rank, iv_odtloff_wr_nt_offset[l_dimm_rank]));


            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            ON = 5,
            ON_LEN = 3,
            OFF = 2,
            OFF_LEN = 3,
            ON_OFFSET = 5,
        };

        int8_t iv_odtlon_wr_nt_offset[mr::ATTR_RANKS] = {};
        int8_t iv_odtloff_wr_nt_offset[mr::ATTR_RANKS] = {};

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank's value to print
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, const uint64_t i_dimm_rank)  const
        {
            FAPI_INF(TARGTIDFORMAT
                     " DDR5 MR38 rank%u. ODTLon NT WR:%u. ODTLoff NT WR:%u.", TARGTID, i_dimm_rank, iv_odtlon_wr_nt_offset[i_dimm_rank],
                     iv_odtloff_wr_nt_offset[i_dimm_rank]);
        }

};

} // ns ddr5

} // ns mss

#endif
