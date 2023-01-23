/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr6.H $          */
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
/// @file ddr5_mr6.H
/// @brief Run and manage the DDR5 MR6 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR6_H_
#define _GENERIC_DDR5_MR6_H_

#include <fapi2.H>

#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/num.H>
#include <generic/memory/lib/utils/mss_pair.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr_base.H>

namespace mss
{

namespace ddr5
{

///
/// @brief Data structure for DDR5 MR6
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr6_data : public mr_base_data<MC>
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 6;

        ///
        /// @brief mr6_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr6_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc ) : mr_base_data<MC>(iv_mr)
        {

            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            const auto& l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

            FAPI_TRY( mss::attr::get_dram_twr(l_port_target, iv_wr_recovery), "Error in ddr5::mr6_data()" );
            FAPI_TRY( mss::attr::get_dram_trtp(l_port_target, iv_trtp), "Error in ddr5::mr6_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr4", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr6_data(): mr_base_data<MC>(iv_mr) {};

        static const pair<uint8_t, uint8_t> TRTP_TABLE[9];
        static const pair<uint8_t, uint8_t> WR_TABLE[9];

        ///
        /// @brief Checks and converts the write recovery value from an attribute to the MR field value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_attr the attribute value to check and convert
        /// @param[out] o_field the MR field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_wr_recovery_to_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_attr,
                uint8_t& o_field) const
        {
            FAPI_ASSERT(find_value_from_key<9>(WR_TABLE,
                                               i_attr,
                                               o_field),
                        fapi2::MSS_DDR5_MR6_WR_RECOVERY_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_VALUE(i_attr),
                        TARGTIDFORMAT " DDR5 MR6. Bad WR Recovery time: %u", TARGTID, i_attr);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the write recovery value from the MR field value to the attribute value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_field the MR field value
        /// @param[out] o_value the attribute value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_wr_recovery_from_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_field,
                uint8_t& o_value) const
        {
            FAPI_ASSERT(find_key_from_value<9>(WR_TABLE,
                                               i_field,
                                               o_value),
                        fapi2::MSS_DDR5_MR6_WR_RECOVERY_FIELD_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_FIELD(i_field),
                        TARGTIDFORMAT " DDR5 MR6. Bad WR Recovery field value: %u", TARGTID, i_field);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the tRTP value from an attribute to the MR field value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_attr the attribute value to check and convert
        /// @param[out] o_field the MR field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_trtp_to_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_attr,
                uint8_t& o_field) const
        {
            FAPI_ASSERT(find_value_from_key<9>(TRTP_TABLE,
                                               i_attr,
                                               o_field),
                        fapi2::MSS_DDR5_MR6_TRTP_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_VALUE(i_attr),
                        TARGTIDFORMAT " DDR5 MR6. Bad tRTP time: %u", TARGTID, i_attr);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts the tRTP value from the MR field value to the attribute value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_field the MR field value
        /// @param[out] o_value the attribute value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_trtp_from_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_field,
                uint8_t& o_value) const
        {
            FAPI_ASSERT(find_key_from_value<9>(TRTP_TABLE,
                                               i_field,
                                               o_value),
                        fapi2::MSS_DDR5_MR6_TRTP_FIELD_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_FIELD(i_field),
                        TARGTIDFORMAT " DDR5 MR6. Bad tRTP field value: %u", TARGTID, i_field);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR6
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR6 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info, uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            fapi2::buffer<uint8_t> l_data;
            uint8_t l_wr_recovery_field = 0;
            uint8_t l_trtp_field = 0;

            FAPI_TRY(check_and_convert_wr_recovery_to_field(i_rank_info.get_dimm_target(),
                     iv_wr_recovery,
                     l_wr_recovery_field));
            FAPI_TRY(check_and_convert_trtp_to_field(i_rank_info.get_dimm_target(),
                     iv_trtp,
                     l_trtp_field));

            l_data. template insertFromRight<WR_RECOVERY, WR_RECOVERY_LEN>(l_wr_recovery_field)
            . template insertFromRight<TRTP, TRTP_LEN>(l_trtp_field);
            o_mr_data = l_data;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR6 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
        {
            display(i_rank_info.get_dimm_target());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR6 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR6 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info, const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_wr_recovery_field = 0;
            uint8_t l_trtp_field = 0;


            l_data. template extractToRight<WR_RECOVERY, WR_RECOVERY_LEN>(l_wr_recovery_field)
            . template extractToRight<TRTP, TRTP_LEN>(l_trtp_field);
            FAPI_ERR("0x%02x %u %u", l_data, l_wr_recovery_field, l_trtp_field);

            FAPI_TRY(check_and_convert_wr_recovery_from_field(i_rank_info.get_dimm_target(),
                     l_wr_recovery_field,
                     iv_wr_recovery));
            FAPI_TRY(check_and_convert_trtp_from_field(i_rank_info.get_dimm_target(),
                     l_trtp_field,
                     iv_trtp));

        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            WR_RECOVERY = 4,
            WR_RECOVERY_LEN = 4,
            TRTP = 0,
            TRTP_LEN = 4,
        };

        uint8_t iv_wr_recovery = 0;
        uint8_t iv_trtp = 0;

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
        {
            FAPI_INF(TARGTIDFORMAT " DDR5 MR6. WR recovery time %u. tRTP: %u", TARGTID, iv_wr_recovery, iv_trtp);
        }
};

// Add declarations to ensure proper linking
template<mss::mc_type MC>
const pair<uint8_t, uint8_t> mr6_data<MC>::TRTP_TABLE[9] =
{
    pair<uint8_t, uint8_t>(12, 0b0000),
    pair<uint8_t, uint8_t>(14, 0b0001),
    pair<uint8_t, uint8_t>(15, 0b0010),
    pair<uint8_t, uint8_t>(17, 0b0011),
    pair<uint8_t, uint8_t>(18, 0b0100),
    pair<uint8_t, uint8_t>(20, 0b0101),
    pair<uint8_t, uint8_t>(21, 0b0110),
    pair<uint8_t, uint8_t>(23, 0b0111),
    pair<uint8_t, uint8_t>(24, 0b1000),
};
template<mss::mc_type MC>
const pair<uint8_t, uint8_t> mr6_data<MC>::WR_TABLE[9] =
{
    pair<uint8_t, uint8_t>(48, 0b0000),
    pair<uint8_t, uint8_t>(54, 0b0001),
    pair<uint8_t, uint8_t>(60, 0b0010),
    pair<uint8_t, uint8_t>(66, 0b0011),
    pair<uint8_t, uint8_t>(72, 0b0100),
    pair<uint8_t, uint8_t>(78, 0b0101),
    pair<uint8_t, uint8_t>(84, 0b0110),
    pair<uint8_t, uint8_t>(90, 0b0111),
    pair<uint8_t, uint8_t>(96, 0b1000),
};

} // ns ddr5

} // ns mss

#endif
