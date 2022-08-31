/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr111.H $        */
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
/// @file ddr5_mr111.H
/// @brief Run and manage the DDR5 MR111 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR111_H_
#define _GENERIC_DDR5_MR111_H_

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
/// @brief Data structure for DDR5 MR111
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr111_data
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 111;

        ///
        /// @brief mr111_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr111_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc )
        {
            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
            FAPI_TRY( mss::attr::get_ddr5_global_dfe_gain(l_port, iv_global_dfe_gain_enable),
                      "Error in ddr5::mr111_data()" );
            FAPI_TRY( mss::attr::get_ddr5_global_dfe_tap1(l_port, iv_global_dfe1_enable),
                      "Error in ddr5::mr111_data()" );
            FAPI_TRY( mss::attr::get_ddr5_global_dfe_tap2(l_port, iv_global_dfe2_enable),
                      "Error in ddr5::mr111_data()" );
            FAPI_TRY( mss::attr::get_ddr5_global_dfe_tap3(l_port, iv_global_dfe3_enable),
                      "Error in ddr5::mr111_data()" );
            FAPI_TRY( mss::attr::get_ddr5_global_dfe_tap4(l_port, iv_global_dfe4_enable),
                      "Error in ddr5::mr111_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr111", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr111_data() = default;

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR111
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR111 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const
        {
            fapi2::buffer<uint8_t> l_data;
            l_data . template writeBit<GAIN>(iv_global_dfe_gain_enable)
            . template writeBit<TAP1>(iv_global_dfe1_enable)
            . template writeBit<TAP2>(iv_global_dfe2_enable)
            . template writeBit<TAP3>(iv_global_dfe3_enable)
            . template writeBit<TAP4>(iv_global_dfe4_enable);

            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR111 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const
        {
            this->display(i_rank_info.get_dimm_target());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR111 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR111 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0)
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            iv_global_dfe_gain_enable = l_data . template getBit<GAIN>();
            iv_global_dfe1_enable = l_data . template getBit<TAP1>();
            iv_global_dfe2_enable = l_data . template getBit<TAP2>();
            iv_global_dfe3_enable = l_data . template getBit<TAP3>();
            iv_global_dfe4_enable = l_data . template getBit<TAP4>();

            return fapi2::FAPI2_RC_SUCCESS;
        }

        enum
        {
            GAIN = 7,
            TAP1 = 6,
            TAP2 = 5,
            TAP3 = 4,
            TAP4 = 3,
        };

        // Note: oddly enough, according to JEDEC, a value of 0 means ENABLE
        // These register fields default to ENABLE (0)
        // Just noting a gotcha here to avoid confusion
        uint8_t iv_global_dfe_gain_enable = 0;
        uint8_t iv_global_dfe1_enable = 0;
        uint8_t iv_global_dfe2_enable = 0;
        uint8_t iv_global_dfe3_enable = 0;
        uint8_t iv_global_dfe4_enable = 0;

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
        {
            FAPI_INF(TARGTIDFORMAT
                     " DDR5 MR111. DFE gain:%u DFE tap-1:%u DFE tap-2:%u",
                     TARGTID, iv_global_dfe_gain_enable, iv_global_dfe1_enable, iv_global_dfe2_enable);
            FAPI_INF(TARGTIDFORMAT
                     " DDR5 MR111. DFE tap-3:%u DFE tap-4:%u",
                     TARGTID, iv_global_dfe3_enable, iv_global_dfe4_enable);
        }

};

} // ns ddr5

} // ns mss

#endif
