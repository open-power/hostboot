/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr15.H $         */
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
/// @file ddr5_mr15.H
/// @brief Run and manage the DDR5 MR15 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR15_H_
#define _GENERIC_DDR5_MR15_H_

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
/// @brief Data structure for DDR5 MR15
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr15_data
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 15;

        ///
        /// @brief mr15_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr15_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc )
        {
            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

            FAPI_TRY( mss::attr::get_ddr5_dram_ecs_threshold_count(l_port, iv_ecs_err_threshold),
                      "Error in ddr5::mr15_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dram_ecs_in_self_refresh(l_port, iv_ecs_in_str),
                      "Error in ddr5::mr15_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dram_ecs_writeback(l_port, iv_ecs_writeback),
                      "Error in ddr5::mr15_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dram_ecs_x4_writes(l_port, iv_x4_writes),
                      "Error in ddr5::mr15_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr15", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr15_data() = default;

        ///
        /// @brief Checks that the ECS error threshold is inbounds
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_threshold the ECS error threshold to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_error_threshold(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                const uint8_t i_threshold) const
        {
            constexpr uint8_t MAX = 0b101;
            FAPI_ASSERT( (i_threshold <= MAX),
                         fapi2::MSS_DDR5_MR15_ECS_ERROR_THRESHOLD()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MAX(MAX)
                         .set_THRESHOLD(i_threshold),
                         TARGTIDFORMAT " DDR5 MR15. Bad ECS error threshold: %u <= %u", TARGTID, i_threshold, MAX);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR15
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR15 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const
        {
            fapi2::buffer<uint8_t> l_data;

            FAPI_TRY(check_error_threshold(i_rank_info.get_dimm_target(), iv_ecs_err_threshold));

            {
                l_data. template insertFromRight<ECS_THRESHOLD, ECS_THRESHOLD_LEN>(iv_ecs_err_threshold)
                . template writeBit<ECS_STR>(iv_ecs_in_str)
                . template writeBit<ECS_WRITEBACK>(iv_ecs_writeback)
                . template writeBit<ECS_X4>(iv_x4_writes);

                o_mr_data = l_data;
            }

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR15 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const
        {
            this->display(i_rank_info.get_dimm_target());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR15 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR15 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0)
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_threshold_field = 0;

            l_data. template extractToRight<ECS_THRESHOLD, ECS_THRESHOLD_LEN>(l_threshold_field);
            iv_ecs_in_str = l_data. template getBit<ECS_STR>();
            iv_ecs_writeback = l_data. template getBit<ECS_WRITEBACK>();
            iv_x4_writes = l_data. template getBit<ECS_X4>();

            FAPI_TRY(check_error_threshold(i_rank_info.get_dimm_target(), l_threshold_field));

            iv_ecs_err_threshold = l_threshold_field;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            ECS_THRESHOLD = 5,
            ECS_THRESHOLD_LEN = 3,
            ECS_STR = 4,
            ECS_WRITEBACK = 1,
            ECS_X4 = 0,
        };

        uint8_t iv_ecs_err_threshold = 0;
        uint8_t iv_ecs_in_str = 0;
        uint8_t iv_ecs_writeback = 0;
        uint8_t iv_x4_writes = 0;


    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
        {
            FAPI_INF(TARGTIDFORMAT " DDR5 MR15. ECS error threshold: %u. ECS in STR: %u", TARGTID, iv_ecs_err_threshold,
                     iv_ecs_in_str);
            FAPI_INF(TARGTIDFORMAT " DDR5 MR15. ECS writeback: %u. ECS x4 writes: %u", TARGTID, iv_ecs_writeback, iv_x4_writes);
        }

};

} // ns ddr5

} // ns mss

#endif
