/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr_base.H $      */
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
/// @file ddr5_mr_base.H
/// @brief Base class for DDR5 mode registers
///
// *HWP HWP Owner: Adithi Ganapathi <adithi.t.ganapathi@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
#ifndef _DDR5_MR_BASE_H_
#define _DDR5_MR_BASE_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>


namespace mss
{
namespace ddr5
{

///
/// @brief declares a generic MR class
/// @tparam mss::mc_type MC memory controller type
/// @tparam MR class traits
///
template <mss::mc_type MC>
class mr_base_data
{

    private:
        //MR value for each CSS instruction
        uint64_t iv_mr;

    public:

        //
        // @brief constructor - deletes default
        // notes deletes default to force user to pass in the MR number
        //
        mr_base_data() = delete;

        ///
        /// @brief parameterized constructor - sets the MR value for mode registers
        ///
        mr_base_data(const uint64_t i_mr)
        {
            iv_mr = i_mr;
        }

        ///
        /// @brief destructor - use default destructor
        ///
        ~mr_base_data() = default;

        ///
        /// @brief get_mr - gets the MR value for mode registers
        ///
        uint64_t get_mr() const
        {
            return iv_mr;
        }

        ///
        /// @brief assemble_data - assembles the data and returns success only if it passes
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR0
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        virtual fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info, uint8_t& o_mr_data,
                                                const uint8_t i_dram_number = 0) const = 0 ;


        ///
        /// @brief read_from_data - reads the assembled data and returns success only if it passes
        /// @param[in] i_rank_info the rank on which to operate - unused for MR0 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR0 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        virtual fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info, const uint8_t i_mr_data,
                const uint8_t i_dram_number = 0) = 0;

        ///
        /// @brief display_data - displays the data and returns success only if it passes
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR0 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        virtual fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const = 0 ;


};

} // ns ddr5

} // ns mss

#endif
