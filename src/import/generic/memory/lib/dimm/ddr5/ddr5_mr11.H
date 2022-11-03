/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr11.H $         */
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
/// @file ddr5_mr11.H
/// @brief Run and manage the DDR5 MR11 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR11_H_
#define _GENERIC_DDR5_MR11_H_

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
/// @brief Data structure for DDR5 MR11
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr11_data : public mr_base_data<MC>
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 11;

        ///
        /// @brief mr11_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr11_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc ) : mr_base_data<MC>(iv_mr)
        {

            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            FAPI_TRY( mss::attr::get_ddr5_dram_vrefca(i_target, iv_vrefca_value),
                      "Error in ddr5::mr11_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr11", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr11_data(): mr_base_data<MC>(iv_mr) {};

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
                         .set_MR(11)
                         .set_DRAM(i_dram),
                         TARGTIDFORMAT " DDR5 MR11. Bad dram input: %u <= %u", TARGTID, i_dram, MAX);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks to ensure the VREF for a specific rank and DRAM is in bounds
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_rank the rank
        /// @param[in] i_dram the dram
        /// @param[in] i_vref the vref value to be checked
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_vref_value(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                           const uint64_t i_rank,
                                           const uint8_t i_dram,
                                           const uint8_t i_vref) const
        {
            constexpr uint64_t MAX = 0b01111101;
            FAPI_ASSERT( (i_vref <= MAX),
                         fapi2::MSS_DDR5_MR11_BAD_VREFCA()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MAX(MAX)
                         .set_RANK(i_rank)
                         .set_DRAM(i_dram),
                         TARGTIDFORMAT " DDR5 MR11. rank%u, dram:%u. Bad VREFCA input: %u", TARGTID, i_rank, i_dram, i_vref );

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR11
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR11 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            FAPI_TRY(check_dram(i_rank_info.get_dimm_target(), i_dram_number));
            // Note: not checking the rank input as it is already checked by the rank info class
            FAPI_TRY(check_vref_value(i_rank_info.get_dimm_target(), i_rank_info.get_dimm_rank(), i_dram_number,
                                      iv_vrefca_value[i_rank_info.get_dimm_rank()][i_dram_number]));

            // Check DRAM checks the boundaries for the array bounds below
            // Linux on power compiles do not acknowledge that the assert is doing this check
            // As such, using pragmas to avoid the warning causing the error
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
            o_mr_data = iv_vrefca_value[i_rank_info.get_dimm_rank()][i_dram_number];
#pragma GCC diagnostic pop

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR11 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
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
        /// @param[in] i_rank_info the rank on which to operate - unused for MR11 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR11 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {
            FAPI_TRY(check_dram(i_rank_info.get_dimm_target(), i_dram_number));
            // Note: not checking the rank input as it is already checked by the rank info class
            FAPI_TRY(check_vref_value(i_rank_info.get_dimm_target(), i_rank_info.get_dimm_rank(), i_dram_number, i_mr_data));

            // Check DRAM checks the boundaries for the array bounds below
            // Linux on power compiles do not acknowledge that the assert is doing this check
            // As such, using pragmas to avoid the warning causing the error
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
            iv_vrefca_value[i_rank_info.get_dimm_rank()][i_dram_number] = i_mr_data;
#pragma GCC diagnostic pop
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
            return mss::attr::set_ddr5_dram_vrefca(i_target, iv_vrefca_value);
        }

        // All 8 bits are used, no need for bit enumerators
        uint8_t iv_vrefca_value[mr::ATTR_RANKS][mr::ATTR_DRAM] = {};

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
            FAPI_INF(TARGTIDFORMAT
                     " DDR5 MR11. rank%u, DRAM%u VREFCA: 0x%02",
                     TARGTID, i_rank, i_dram_number, iv_vrefca_value[i_rank][i_dram_number]);
#pragma GCC diagnostic pop
        }

};

} // ns ddr5

} // ns mss

#endif
