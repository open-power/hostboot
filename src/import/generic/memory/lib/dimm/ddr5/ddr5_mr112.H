/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr112.H $        */
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
/// @file ddr5_mr112.H
/// @brief Run and manage the DDR5 MR112 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR112_H_
#define _GENERIC_DDR5_MR112_H_

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
/// @brief Data structure for DDR5 MR112
/// @tparam MC the memory controller type
/// @note This same style of MR data is used for MR112, MR120... and can be repurposed for those MR's
///
template<mss::mc_type MC>
class mr112_data : public mr_base_data<MC>
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 112;

        ///
        /// @brief mr112_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr112_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc ) : mr_base_data<MC>(iv_mr)
        {

            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            FAPI_TRY( mss::attr::get_ddr5_dfe_gain_bias(i_target, iv_dfe_gain_bias),
                      "Error in ddr5::mr112_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dfe_sign_bit(i_target, iv_dfe_sign_bit),
                      "Error in ddr5::mr112_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr112", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr112_data(): mr_base_data<MC>(iv_mr) {};

        ///
        /// @brief Checks to ensure the DFE gain bias for a specific rank is in bounds
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_rank the rank
        /// @param[in] i_value the value to be checked
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_gain_bias(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                          const uint64_t i_rank,
                                          const uint8_t i_value) const
        {
            constexpr uint64_t MAX = 0b11;
            FAPI_ASSERT( (i_value <= MAX),
                         fapi2::MSS_DDR5_MR112_BAD_DFE_GAIN_BIAS()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MAX(MAX)
                         .set_RANK(i_rank)
                         .set_VALUE(i_value),
                         TARGTIDFORMAT " DDR5 MR112. rank%u. Bad DFE gain bias input: %u <= ", TARGTID, i_rank, i_value );

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR112
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR112 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            // Note: not checking the rank input as it is already checked by the rank info class
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();
            fapi2::buffer<uint8_t> l_data;

            // Checks the gain bias
            FAPI_TRY(check_gain_bias(i_rank_info.get_dimm_target(), l_dimm_rank, iv_dfe_gain_bias[l_dimm_rank]));

            l_data . template writeBit<SIGN>(iv_dfe_sign_bit[l_dimm_rank])
            . template insertFromRight<BIAS, BIAS_LEN>(iv_dfe_gain_bias[l_dimm_rank]);

            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR112 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
        {
            // Note: not checking the rank input as it is already checked by the rank info class
            this->display(i_rank_info.get_dimm_target(), i_rank_info.get_dimm_rank());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR112 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR112 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {
            // Note: not checking the rank input as it is already checked by the rank info class
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();
            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_gain_bias_field = 0;
            iv_dfe_sign_bit[l_dimm_rank] = l_data . template getBit<SIGN>();
            l_data . template extractToRight<BIAS, BIAS_LEN>(l_gain_bias_field);

            // Checks the gain bias
            FAPI_TRY(check_gain_bias(i_rank_info.get_dimm_target(), l_dimm_rank, l_gain_bias_field));
            iv_dfe_gain_bias[l_dimm_rank] = l_gain_bias_field;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            BIAS = 5,
            BIAS_LEN = 3,
            SIGN = 4,
        };

        uint8_t iv_dfe_gain_bias[mr::ATTR_RANKS] = {};
        // Note: per JEDEC, positive is a 0, negative is a 1
        // Think 2's complement
        uint8_t iv_dfe_sign_bit[mr::ATTR_RANKS] = {};

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the input rank to print
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, const uint64_t i_dimm_rank) const
        {
            FAPI_INF(TARGTIDFORMAT
                     " DDR5 MR112 Rank%u. Gain Bias:%u Sign Bit:%u",
                     TARGTID, i_dimm_rank, iv_dfe_gain_bias[i_dimm_rank], iv_dfe_sign_bit[i_dimm_rank]);
        }

};

} // ns ddr5

} // ns mss

#endif
