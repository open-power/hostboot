/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr13.H $         */
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
/// @file ddr5_mr13.H
/// @brief Run and manage the DDR5 MR13 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR13_H_
#define _GENERIC_DDR5_MR13_H_

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
/// @brief Data structure for DDR5 MR13
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr13_data
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 13;

        ///
        /// @brief mr13_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr13_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc )
        {
            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
            FAPI_TRY( mss::attr::get_dram_tccd_l(l_port, iv_tccd_l),
                      "Error in ddr5::mr13_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr13", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr13_data() = default;

        ///
        /// @brief Checks the TCCD_L value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_tccd_l the tCDD_L value to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_tccd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, const uint8_t i_tccd_l) const
        {
            FAPI_ASSERT( (i_tccd_l >= TCCD_L_ATTR_MIN) && (i_tccd_l <= TCCD_L_ATTR_MAX),
                         fapi2::MSS_DDR5_MR13_BAD_TCCD_L()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MAX(TCCD_L_ATTR_MAX)
                         .set_MIN(TCCD_L_ATTR_MIN)
                         .set_TCCD_L(i_tccd_l),
                         TARGTIDFORMAT " DDR5 MR13. Bad tCCD_L input: %u <= %u <= %u", TARGTID, TCCD_L_ATTR_MIN, i_tccd_l, TCCD_L_ATTR_MAX);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR13
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR13 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const
        {
            fapi2::buffer<uint8_t> l_data;

            FAPI_TRY(check_tccd_l(i_rank_info.get_dimm_target(), iv_tccd_l));

            {
                const uint8_t l_tccd_l_field = iv_tccd_l - TCCD_L_ATTR_MIN;
                l_data.insertFromRight<TCCD_L, TCCD_L_LEN>(l_tccd_l_field);
                o_mr_data = l_data;
            }

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR13 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const
        {
            this->display(i_rank_info.get_dimm_target());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR13 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR13 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0)
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_tccd_l_field = 0;

            l_data.extractToRight<TCCD_L, TCCD_L_LEN>(l_tccd_l_field);
            iv_tccd_l = l_tccd_l_field + TCCD_L_ATTR_MIN;

            FAPI_TRY(check_tccd_l(i_rank_info.get_dimm_target(), iv_tccd_l));

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            TCCD_L_ATTR_MIN = 8,
            TCCD_L_ATTR_MAX = 16,
            TCCD_L = 4,
            TCCD_L_LEN = 4,
        };

        uint8_t iv_tccd_l = 0;

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
        {
            FAPI_INF(TARGTIDFORMAT " DDR5 MR13. tCCD_L: %u", TARGTID, iv_tccd_l);
        }

};

} // ns ddr5

} // ns mss

#endif
