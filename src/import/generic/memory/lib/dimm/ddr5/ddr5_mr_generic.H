/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr_generic.H $   */
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
/// @file ddr5_mr_generic.H
/// @brief Generic class for DDR5 mode registers
///
// *HWP HWP Owner: Adithi Ganapathi <adithi.t.ganapathi@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
#ifndef _DDR5_MR_GENERIC_H_
#define _DDR5_MR_GENERIC_H_

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
/// @brief Data structure for DDR5 Generic MR numbers
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr_generic_data : public mr_base_data<MC>
{
    public:
        ///
        /// @brief mr_generic_data ctor
        /// @param[in] iv_mr the generic mr number
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr_generic_data( const uint64_t iv_mr, fapi2::ReturnCode& io_rc ) :
            mr_base_data<MC>(iv_mr),
            iv_op_code(0) {}

        ///Default Constructor
        mr_generic_data(): mr_base_data<MC>(1) {};

        /// @brief display_data - displays the data and returns success only if it passes
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR0 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
        {
            const uint64_t l_mr_number = mr_base_data<MC>::get_mr();

            FAPI_INF(TARGTIDFORMAT " DDR5 Generic MR: %u , Dram Number: %u - OP_CODE: %u",
                     GENTARGTID(i_rank_info.get_dimm_target()), l_mr_number,
                     i_dram_number,
                     iv_op_code);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief read_from_data - reads the assembled data and returns success only if it passes
        /// @param[in] i_rank_info the rank on which to operate - unused for MR0 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR0 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info, const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {
            iv_op_code = i_mr_data;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Sets the attribute for this MR for lab tool
        /// @param[in] i_rank_info the rank on which to operate
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode attr_setter(const mss::rank::info<MC>& i_rank_info) override
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief assemble_data - assembles the data and returns success only if it passes
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR0
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            o_mr_data = iv_op_code;
            return fapi2::FAPI2_RC_SUCCESS;
        }
        uint8_t iv_op_code = 0;
};
} // ns ddr5

} // ns mss

#endif
