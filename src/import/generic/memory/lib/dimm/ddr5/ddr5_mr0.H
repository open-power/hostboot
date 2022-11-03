/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr0.H $          */
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
/// @file ddr5_mr0.H
/// @brief Run and manage the DDR5 MR0 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR0_H_
#define _GENERIC_DDR5_MR0_H_

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
/// @brief Data structure for DDR5 MR0
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr0_data : public mr_base_data<MC>
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 0;

        ///
        /// @brief mr0_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr0_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc ) :
            mr_base_data<MC>(iv_mr),
            iv_cas_latency(0),
            iv_burst_length(0)
        {

            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            const auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

            FAPI_TRY( mss::attr::get_dram_cl(l_port_target, iv_cas_latency), "Error in ddr5::mr0_data()" );
            FAPI_TRY( mss::attr::get_burst_length(l_port_target, iv_burst_length), "Error in ddr5::mr0_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr0", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr0_data(): mr_base_data<MC>(iv_mr) {};

        ///
        /// @brief Asserts out for a bad CAS latency
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_attr the actual CAS latency value to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_cas_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                            const uint8_t i_attr) const
        {

            // 1. CAS latency needs to be even according to the DDR5 JEDEC spec (version 1.7.1)
            // 2. CAS latency needs to be between 22 and 66 (inclusive)
            constexpr uint64_t MAX_CAS_LATENCY = 66;
            constexpr uint64_t MIN_CAS_LATENCY = 22;
            FAPI_ASSERT( (!mss::is_odd(i_attr)) &&
                         (i_attr >= MIN_CAS_LATENCY && i_attr <= MAX_CAS_LATENCY),
                         fapi2::MSS_DDR5_MR0_BAD_CAS_LATENCY()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MAX_CAS_LATENCY(MAX_CAS_LATENCY)
                         .set_MIN_CAS_LATENCY(MIN_CAS_LATENCY)
                         .set_CAS_LATENCY(i_attr),
                         TARGTIDFORMAT " DDR5 MR0. Bad CAS latency: %u (should be even). Acceptable range: %u <= CL <= %u", TARGTID,
                         i_attr, MIN_CAS_LATENCY, MAX_CAS_LATENCY);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Asserts out for a bad burst length
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_attr the attribute encoded burst length to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_burst_length(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint8_t i_attr) const
        {

            // Burst length needs to be less than or equal to 3
            constexpr uint64_t MAX_BURST_LENGTH = 3;
            FAPI_ASSERT( (i_attr <= MAX_BURST_LENGTH),
                         fapi2::MSS_DDR5_MR0_BAD_BURST_LENGTH()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MAX_BURST_LENGTH(MAX_BURST_LENGTH)
                         .set_BURST_LENGTH(i_attr),
                         TARGTIDFORMAT " DDR5 MR0. Bad burst length: %u <= %u", TARGTID, i_attr, MAX_BURST_LENGTH);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR0
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR0 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            fapi2::buffer<uint8_t> l_mr_temp_value;
            uint8_t l_field_cl = 0;
            uint8_t l_field_bl = 0;
            o_mr_data = 0;

            // Checks for a bad CAS latency and computes the field value
            {
                FAPI_TRY(check_cas_latency(i_rank_info.get_dimm_target(), iv_cas_latency));

                // Field CL can be handled by an equation
                // the JEDEC spec has the following table:
                // 0b00000: 22
                // 0b00001: 24
                // 0b00002: 26
                // ....
                // 0b10110: 66
                // Each value increase of CL 2 equates to a single bit increase
                l_field_cl = iv_cas_latency - 22;
                l_field_cl /= 2;
            }

            // Checks the burst length and computes the field value
            {
                // The field value is the same as the attribute enumerations
                // Check that the attribute is in bounds for the field then assign the value
                FAPI_TRY(check_burst_length(i_rank_info.get_dimm_target(), iv_burst_length));

                l_field_bl = iv_burst_length;
            }
            // Generate the MR0 data
            l_mr_temp_value. template insertFromRight< CAS_LATENCY, CAS_LATENCY_LEN >(l_field_cl)
            . template insertFromRight< BURST_LENGTH, BURST_LENGTH_LEN >(l_field_bl);
            o_mr_data = l_mr_temp_value;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR0 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
        {
            this->display(i_rank_info.get_dimm_target());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR0 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR0 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info, const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {
            fapi2::buffer<uint8_t> l_mr_temp_value(i_mr_data);
            uint8_t l_field_cl = 0;
            uint8_t l_field_bl = 0;

            // Read in the field data
            l_mr_temp_value. template extractToRight< CAS_LATENCY, CAS_LATENCY_LEN >(l_field_cl)
            . template extractToRight< BURST_LENGTH, BURST_LENGTH_LEN >(l_field_bl);

            // Post process CAS latency data (and assert for bad values)
            {

                // Field CL can be handled by an equation
                // the JEDEC spec has the following table:
                // 0b00000: 22
                // 0b00001: 24
                // 0b00002: 26
                // ....
                // 0b10110: 66
                // Each value increase of CL 2 equates to a single bit increase
                l_field_cl *= 2;
                l_field_cl += 22;

                // CAS latency needs to be between 22 and 66 (inclusive)
                FAPI_TRY(check_cas_latency(i_rank_info.get_dimm_target(), l_field_cl));

                iv_cas_latency = l_field_cl;
            }

            // Post process burst length data (and assert for bad values)
            {
                // The field value is the same as the attribute enumerations
                // It is also guaranteed to be within the attributes bounds
                iv_burst_length = l_field_bl;
            }

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            CAS_LATENCY = 1,
            CAS_LATENCY_LEN = 5,

            BURST_LENGTH = 6,
            BURST_LENGTH_LEN = 2,
        };

        uint8_t iv_cas_latency = 0;
        uint8_t iv_burst_length = 0;

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
        {
            FAPI_INF(TARGTIDFORMAT " DDR5 MR0. CAS latency: %u. burst length: %u", TARGTID, iv_cas_latency, iv_burst_length);
        }

};

} // ns ddr5

} // ns mss

#endif
