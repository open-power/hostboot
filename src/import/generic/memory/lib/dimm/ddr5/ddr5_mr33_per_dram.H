/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr33_per_dram.H $ */
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
/// @file ddr5_mr33_per_dram.H
/// @brief Run and manage the DDR5 MR33 (per-device) loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR33_PER_DRAM_H_
#define _GENERIC_DDR5_MR33_PER_DRAM_H_

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
/// @brief Data structure for DDR5 MR33 (per device)
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr33_per_dram_data : public mr_base_data<MC>
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 33;

        ///
        /// @brief mr33_per_dram_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr33_per_dram_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                            fapi2::ReturnCode& io_rc ): mr_base_data<MC>(iv_mr)
        {

            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            FAPI_TRY( mss::attr::get_ddr5_dram_ca_odt_per_dram(i_target, iv_ca_odt),
                      "Error in ddr5::mr33_per_dram_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dram_dqs_rtt_park_per_dram(i_target, iv_dqs_rtt_park),
                      "Error in ddr5::mr33_per_dram_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr33", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr33_per_dram_data(): mr_base_data<MC>(iv_mr) {};

        static const pair<uint16_t, uint8_t> ODT_TABLE[7];
        static const pair<uint8_t, uint8_t> DQS_TABLE[8];

        ///
        /// @brief Checks to ensure the DRAM is in bounds
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dram_number the value to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_dram(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint8_t i_dram_number) const
        {
            constexpr uint64_t MAX = 19;
            FAPI_ASSERT( (i_dram_number <= MAX),
                         fapi2::MSS_DDR5_MR_BAD_DRAM()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MAX(MAX)
                         .set_MR(33)
                         .set_DRAM(i_dram_number),
                         TARGTIDFORMAT " DDR5 MR33. Bad dram input: %u <= %u", TARGTID, i_dram_number, MAX);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the attribute CA ODT value to its associated field value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the attr value is being checked
        /// @param[in] i_dram_number the DRAM index on which the attr value is being checked
        /// @param[in] i_value the value to check
        /// @param[out] o_field the generated field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_odt_to_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_dimm_rank,
                const uint8_t i_dram_number,
                const uint16_t i_value,
                uint8_t& o_field) const
        {
            FAPI_ASSERT(find_value_from_key<7>(ODT_TABLE,
                                               i_value,
                                               o_field),
                        fapi2::MSS_DDR5_MR33_CA_ODT_PER_DRAM_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_VALUE(i_value)
                        .set_DRAM(i_dram_number),
                        TARGTIDFORMAT " DDR5 MR33. Bad CA ODT impedance value on DIMM rank %u, DRAM %u. Value: %u", TARGTID,
                        i_dimm_rank, i_dram_number, i_value);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the field CA ODT value to its associated attribute value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the attr value is being checked
        /// @param[in] i_dram_number the DRAM index on which the attr value is being checked
        /// @param[in] i_field the field value to convert
        /// @param[out] o_value the generated field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_odt_from_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_dimm_rank,
                const uint8_t i_dram_number,
                const uint8_t i_field,
                uint16_t& o_value) const
        {
            FAPI_ASSERT(find_key_from_value<7>(ODT_TABLE,
                                               i_field,
                                               o_value),
                        fapi2::MSS_DDR5_MR33_CA_ODT_PER_DRAM_FIELD_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_FIELD(i_field)
                        .set_DRAM(i_dram_number),
                        TARGTIDFORMAT " DDR5 MR33. Bad CA ODT impedance field on DIMM rank %u, DRAM %u. Field value: %u", TARGTID,
                        i_dimm_rank, i_dram_number, i_field);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the attribute CA DQS value to its associated field value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the attr value is being checked
        /// @param[in] i_dram_number the DRAM index on which the attr value is being checked
        /// @param[in] i_value the value to check
        /// @param[out] o_field the generated field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_dqs_to_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_dimm_rank,
                const uint8_t i_dram_number,
                const uint8_t i_value,
                uint8_t& o_field) const
        {
            FAPI_ASSERT(find_value_from_key<8>(DQS_TABLE,
                                               i_value,
                                               o_field),
                        fapi2::MSS_DDR5_MR33_DQS_RTT_PARK_PER_DRAM_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_VALUE(i_value)
                        .set_DRAM(i_dram_number),
                        TARGTIDFORMAT " DDR5 MR33. Bad DQS RTT park value on DIMM rank %u, DRAM %u. Value: %u", TARGTID,
                        i_dimm_rank, i_dram_number, i_value);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the field CA DQS value to its associated attribute value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the attr value is being checked
        /// @param[in] i_dram_number the DRAM index on which the attr value is being checked
        /// @param[in] i_field the field value to convert
        /// @param[out] o_value the generated field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_dqs_from_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_dimm_rank,
                const uint8_t i_dram_number,
                const uint8_t i_field,
                uint8_t& o_value) const
        {
            FAPI_ASSERT(find_key_from_value<8>(DQS_TABLE,
                                               i_field,
                                               o_value),
                        fapi2::MSS_DDR5_MR33_DQS_RTT_PARK_PER_DRAM_FIELD_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_FIELD(i_field)
                        .set_DRAM(i_dram_number),
                        TARGTIDFORMAT " DDR5 MR33. Bad DQS RTT park field on DIMM rank %u, DRAM %u. Field value: %u", TARGTID,
                        i_dimm_rank, i_dram_number, i_field);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM index on which the attr value is being checked
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            fapi2::buffer<uint8_t> l_data;
            uint8_t l_ca_field = 0;
            uint8_t l_dqs_rtt_park_field = 0;

            // Note: not checking DIMM rank as it was already checked by the rank info class
            const auto& l_dimm = i_rank_info.get_dimm_target();
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();

            // Check DRAM checks the boundaries for the array bounds below
            FAPI_TRY(check_dram(l_dimm, i_dram_number));
            // Check DRAM checks the boundaries for the array bounds below
            // Linux on power compiles do not acknowledge that the assert is doing this check
            // As such, using pragmas to avoid the warning causing the error
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
            FAPI_TRY(check_and_convert_odt_to_field(l_dimm,
                                                    l_dimm_rank,
                                                    i_dram_number,
                                                    iv_ca_odt[l_dimm_rank][i_dram_number],
                                                    l_ca_field));
            FAPI_TRY(check_and_convert_dqs_to_field(l_dimm,
                                                    l_dimm_rank,
                                                    i_dram_number,
                                                    iv_dqs_rtt_park[l_dimm_rank][i_dram_number],
                                                    l_dqs_rtt_park_field));
#pragma GCC diagnostic pop

            l_data. template insertFromRight<CA_ODT, CA_ODT_LEN>(l_ca_field)
            . template insertFromRight<DQS_RTT_PARK, DQS_RTT_PARK_LEN>(l_dqs_rtt_park_field);
            o_mr_data = l_data;

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
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
        {
            FAPI_TRY(check_dram(i_rank_info.get_dimm_target(), i_dram_number));
            this->display(i_rank_info.get_dimm_target(), i_rank_info.get_dimm_rank(), i_dram_number);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR33 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_ca_field = 0;
            uint8_t l_dqs_rtt_park_field = 0;

            l_data. template extractToRight<CA_ODT, CA_ODT_LEN>(l_ca_field)
            . template extractToRight<DQS_RTT_PARK, DQS_RTT_PARK_LEN>(l_dqs_rtt_park_field);

            // Note: not checking DIMM rank as it was already checked by the rank info class
            const auto& l_dimm = i_rank_info.get_dimm_target();
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();

            // Check DRAM checks the boundaries for the array bounds below
            FAPI_TRY(check_dram(l_dimm, i_dram_number));
            // Check DRAM checks the boundaries for the array bounds below
            // Linux on power compiles do not acknowledge that the assert is doing this check
            // As such, using pragmas to avoid the warning causing the error
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
            FAPI_TRY(check_and_convert_odt_from_field(l_dimm,
                     l_dimm_rank,
                     i_dram_number,
                     l_ca_field,
                     iv_ca_odt[l_dimm_rank][i_dram_number]));
            FAPI_TRY(check_and_convert_dqs_from_field(l_dimm,
                     l_dimm_rank,
                     i_dram_number,
                     l_dqs_rtt_park_field,
                     iv_dqs_rtt_park[l_dimm_rank][i_dram_number]));
#pragma GCC diagnostic pop


            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Sets the attribute for this MR for lab tool
        /// @param[in] i_rank_info the rank on which to operate
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode attr_setter(const mss::rank::info<MC>& i_rank_info) override
        {
            FAPI_TRY( mss::attr::set_ddr5_dram_ca_odt_per_dram(i_rank_info.get_dimm_target(), iv_ca_odt),
                      "Unable to set attributes for ddr5::mr33_per_dram_data()" );
            FAPI_TRY( mss::attr::set_ddr5_dram_dqs_rtt_park_per_dram(i_rank_info.get_dimm_target(), iv_dqs_rtt_park),
                      "Unable to set attributes for ddr5::mr33_per_dram_data()" );

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            CA_ODT = 5,
            CA_ODT_LEN = 3,
            DQS_RTT_PARK = 2,
            DQS_RTT_PARK_LEN = 3,
        };

        uint16_t iv_ca_odt[mr::ATTR_RANKS][mr::ATTR_DRAM] = {};
        uint8_t iv_dqs_rtt_park[mr::ATTR_RANKS][mr::ATTR_DRAM] = {};

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank's value to print
        /// @param[in] i_dram_number the DRAM on which to operate
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, const uint64_t i_dimm_rank,
                     const uint8_t i_dram_number) const
        {
            // Linux on power compiles do not acknowledge that the assert is doing this check
            // As such, using pragmas to avoid the warning causing the error
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
            FAPI_INF_NO_SBE(TARGTIDFORMAT
                            " DDR5 MR33 rank%u. DRAM %u. CA ODT:%u.", TARGTID, i_dimm_rank,
                            i_dram_number, iv_ca_odt[i_dimm_rank][i_dram_number]);
            FAPI_INF_NO_SBE(TARGTIDFORMAT
                            " DDR5 MR33 rank%u. DRAM %u. DQS RTT park:%u.", TARGTID, i_dimm_rank,
                            i_dram_number, iv_dqs_rtt_park[i_dimm_rank][i_dram_number]);
#pragma GCC diagnostic pop
        }

};

// Declarations here to make the compiler happy with the linkage
template<mss::mc_type MC>
const pair<uint16_t, uint8_t> mr33_per_dram_data<MC>::ODT_TABLE[7] =
{
    pair<uint16_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_DISABLE , 0b000),
    pair<uint16_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM40   , 0b111),
    pair<uint16_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM60   , 0b101),
    pair<uint16_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM80   , 0b100),
    pair<uint16_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM120  , 0b011),
    pair<uint16_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM240  , 0b010),
    pair<uint16_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_CA_ODT_OHM480  , 0b001),
};
template<mss::mc_type MC>
const pair<uint8_t, uint8_t> mr33_per_dram_data<MC>::DQS_TABLE[8] =
{
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_DISABLE , 0b000),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM34   , 0b111),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM40   , 0b110),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM48   , 0b101),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM60   , 0b100),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM80   , 0b011),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM120  , 0b010),
    pair<uint8_t, uint8_t>(fapi2::ENUM_ATTR_DDR5_DRAM_DQS_RTT_PARK_OHM240  , 0b001),
};

} // ns ddr5

} // ns mss

#endif
