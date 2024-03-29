/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr14.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
/// @file ddr5_mr14.H
/// @brief Run and manage the DDR5 MR14 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR14_H_
#define _GENERIC_DDR5_MR14_H_

#include <fapi2.H>

#include <mss_generic_attribute_getters.H>
#include <mss_generic_attribute_setters.H>
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
/// @brief Data structure for DDR5 MR14
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr14_data : public mr_base_data<MC>
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 14;

        ///
        /// @brief mr14_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr14_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc ) : mr_base_data<MC>(iv_mr)
        {

            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_DDR5_DRAM_ECS_MODE, l_port, iv_ecs_mode),
                      "Error in ddr5::mr14_data()" );
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_DDR5_DRAM_ECS_RESET_COUNTER, l_port, iv_ecs_reset),
                      "Error in ddr5::mr14_data()" );
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_DDR5_DRAM_ECS_COUNT_MODE, l_port, iv_row_count),
                      "Error in ddr5::mr14_data()" );
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_DDR5_DRAM_ECS_SRANK_SELECT, l_port, iv_ecs_reg_index),
                      "Error in ddr5::mr14_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr14", TARGTID);
            return;

        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr14_data(): mr_base_data<MC>(iv_mr) {};

        ///
        /// @brief Checks that the CID's selected for the ECS are in rage
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_cid the CID indexing to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_cid(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, const uint8_t i_cid) const
        {
            constexpr uint8_t MAX = 0xf;
            FAPI_ASSERT( (i_cid <= MAX),
                         fapi2::MSS_DDR5_MR14_BAD_ECS_CID()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MAX(MAX)
                         .set_CID(i_cid),
                         TARGTIDFORMAT " DDR5 MR14. Bad ECS CID input: %u <= %u", TARGTID, i_cid, MAX);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR14
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR14 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            fapi2::buffer<uint8_t> l_data;

            FAPI_TRY(check_cid(i_rank_info.get_dimm_target(), iv_ecs_reg_index));

            l_data. template writeBit<ECS_MODE>(iv_ecs_mode)
            . template writeBit<ECS_RESET>(iv_ecs_reset)
            . template writeBit<CODE_MODE>(iv_row_count)
            . template insertFromRight<CID, CID_LEN>(iv_ecs_reg_index);

            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR14 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
        {
            this->display(i_rank_info.get_dimm_target());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR14 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR14 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);

            iv_ecs_reg_index = 0;

            iv_ecs_mode = l_data. template getBit<ECS_MODE>();
            iv_ecs_reset = l_data. template getBit<ECS_RESET>();
            iv_row_count = l_data. template getBit<CODE_MODE>();
            l_data. template extractToRight<CID, CID_LEN>(iv_ecs_reg_index);

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Sets the attribute for this MR for lab tool
        /// @param[in] i_rank_info the rank on which to operate
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode attr_setter(const mss::rank::info<MC>& i_rank_info) override
        {
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_DDR5_DRAM_ECS_MODE, i_rank_info.get_port_target(), iv_ecs_mode),
                      "Unable to set attributes for ddr5::mr14_data()" );
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_DDR5_DRAM_ECS_RESET_COUNTER, i_rank_info.get_port_target(), iv_ecs_reset),
                      "Unable to set attributes for ddr5::mr14_data()" );
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_DDR5_DRAM_ECS_COUNT_MODE, i_rank_info.get_port_target(), iv_row_count),
                      "Unable to set attributes for ddr5::mr14_data()" );
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_DDR5_DRAM_ECS_SRANK_SELECT, i_rank_info.get_port_target(), iv_ecs_reg_index),
                      "Unable to set attributes for ddr5::mr14_data()" );

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            CID = 4,
            CID_LEN = 4,
            CODE_MODE = 2,
            ECS_RESET = 1,
            ECS_MODE = 0,
        };

        uint8_t iv_ecs_mode = 0;
        uint8_t iv_ecs_reset = 0;
        uint8_t iv_row_count = 0;
        uint8_t iv_ecs_reg_index = 0;


    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
        {
            FAPI_INF_NO_SBE(TARGTIDFORMAT " DDR5 MR14. ECS mode: %u. ECS reset counter: %u", TARGTID, iv_ecs_mode, iv_ecs_reset);
            FAPI_INF_NO_SBE(TARGTIDFORMAT " DDR5 MR14. ECS count mode: %u. ECS CID select: %u", TARGTID, iv_ecs_reset, iv_ecs_mode);
        }

};

} // ns ddr5

} // ns mss

#endif
