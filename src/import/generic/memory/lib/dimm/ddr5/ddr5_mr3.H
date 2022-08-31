/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr3.H $          */
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
/// @file ddr5_mr3.H
/// @brief Run and manage the DDR5 MR3 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR3_H_
#define _GENERIC_DDR5_MR3_H_

#include <fapi2.H>

#include <mss_generic_attribute_getters.H>
#include <mss_generic_attribute_setters.H>
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
/// @brief Data structure for DDR5 MR3
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr3_data
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 3;

        ///
        /// @brief mr3_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr3_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc )
        {
            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            FAPI_TRY( mss::attr::get_wl_internal_cycle_alignment(i_target, iv_wr_lvl_internal_lower),
                      "Error in ddr5::mr3_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr3", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr3_data() = default;

        ///
        /// @brief Checks to ensure the DRAM is in bounds
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dram the value to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_dram(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint8_t i_dram) const
        {
            constexpr uint64_t MAX = 19;
            FAPI_ASSERT( (i_dram <= MAX),
                         fapi2::MSS_DDR5_MR_BAD_DRAM()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MAX(MAX)
                         .set_MR(3)
                         .set_DRAM(i_dram),
                         TARGTIDFORMAT " DDR5 MR3. Bad dram input: %u <= %u", TARGTID, i_dram, MAX);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks to ensure the cycle alignment is in bounds
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_cycle_alignment the value to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_cycle_alignment(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                const uint8_t i_cycle_alignment) const
        {
            constexpr uint64_t MAX = 0xf;
            FAPI_ASSERT( (i_cycle_alignment <= MAX),
                         fapi2::MSS_DDR5_MR3_BAD_CYCLE_ALIGN()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MAX(MAX)
                         .set_VALUE(i_cycle_alignment),
                         TARGTIDFORMAT " DDR5 MR3. Bad cycle alignment: %u <= %u", TARGTID, i_cycle_alignment, MAX);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - if not supplied, will use DRAM 0
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR3 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const
        {
            // Note: not checking the rank input as it is already checked by the rank info class
            FAPI_TRY(check_dram(i_rank_info.get_dimm_target(), i_dram_number));

            {
                // Check DRAM checks the boundaries for the array bounds below
                // Linux on power compiles do not acknowledge that the assert is doing this check
                // As such, using pragmas to avoid the warning causing the error
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"

                fapi2::buffer<uint8_t> l_data;
                const auto l_alignment_value = iv_wr_lvl_internal_lower[i_rank_info.get_dimm_rank()][i_dram_number];
#pragma GCC diagnostic pop

                // Checks the cycle alignment
                FAPI_TRY(check_cycle_alignment(i_rank_info.get_dimm_target(), l_alignment_value));

                // Sets the value appropriately
                l_data.insertFromRight<LOWER, FIELD_LEN>(l_alignment_value);
                o_mr_data = l_data;
            }

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const
        {
            FAPI_TRY(check_dram(i_rank_info.get_dimm_target(), i_dram_number));
            // Note: not checking the rank input as it is already checked by the rank info class
            this->display(i_rank_info.get_dimm_target(), i_rank_info.get_dimm_rank(), i_dram_number);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info, const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0)
        {
            // Note: not checking the rank input as it is already checked by the rank info class

            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_field = 0;

            l_data.extractToRight<LOWER, FIELD_LEN>(l_field);
            FAPI_TRY(check_dram(i_rank_info.get_dimm_target(), i_dram_number));
            // Check DRAM checks the boundaries for the array bounds below
            // Linux on power compiles do not acknowledge that the assert is doing this check
            // As such, using pragmas to avoid the warning causing the error
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
            iv_wr_lvl_internal_lower[i_rank_info.get_dimm_rank()][i_dram_number] = l_field;
#pragma GCC diagnostic pop

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Sets the attribute for this MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode set_attribute(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
        {
            return mss::attr::set_wl_internal_cycle_alignment(i_target, iv_wr_lvl_internal_lower);
        }

        enum
        {
            LOWER = 4,
            FIELD_LEN = 4,
        };

        uint8_t iv_wr_lvl_internal_lower[mr::ATTR_RANKS][mr::ATTR_DRAM] = {};
        // Note: the upper byte is only used in x16 which ODY doesn't support - not including it for simplicity

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_rank the input rank to print
        /// @param[in] i_dram_number the input DRAM number
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                     const uint64_t i_rank,
                     const uint8_t i_dram_number) const
        {
            // Check DRAM checks the boundaries for the array bounds below
            // Linux on power compiles do not acknowledge that the assert is doing this check
            // As such, using pragmas to avoid the warning causing the error
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
            // Inputs were checked in the public display method
            FAPI_INF(TARGTIDFORMAT
                     " DDR5 MR3. WR LVL internal cycle rank%u, DRAM%u - lower byte: %u. Note: WR LVL internal cycle - upper byte is unused and will be 0",
                     TARGTID, i_rank, i_dram_number, iv_wr_lvl_internal_lower[i_rank][i_dram_number]);
#pragma GCC diagnostic pop
        }

};

} // ns ddr5

} // ns mss

#endif
