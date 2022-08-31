/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr5.H $          */
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
/// @file ddr5_mr5.H
/// @brief Run and manage the DDR5 MR5 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR5_H_
#define _GENERIC_DDR5_MR5_H_

#include <fapi2.H>

#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/num.H>
#include <generic/memory/lib/utils/mss_pair.H>

namespace mss
{

namespace ddr5
{

///
/// @brief Data structure for DDR5 MR5
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr5_data
{
    public:

        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 5;

        ///
        /// @brief mr5_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr5_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc )
        {
            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
            FAPI_TRY( mss::attr::get_dram_pu_drv_imp(i_target, iv_pu_drv_imp), "Error in ddr5::mr5_data()" );
            FAPI_TRY( mss::attr::get_ddr5_dram_test_mode(l_port, iv_drv_test_mode_supported_read_only),
                      "Error in ddr5::mr5_data()" );
            FAPI_TRY( mss::attr::get_dram_pd_drv_imp(i_target, iv_pd_drv_imp), "Error in ddr5::mr5_data()" );

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr5", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr5_data() = default;


        static constexpr const pair<uint8_t, uint8_t> DRV_IMP_TABLE[3] =
        {
            {fapi2::ENUM_ATTR_DRAM_PU_DRV_IMP_OHM_34, 0b00},
            {fapi2::ENUM_ATTR_DRAM_PU_DRV_IMP_OHM_40, 0b01},
            {fapi2::ENUM_ATTR_DRAM_PU_DRV_IMP_OHM_48, 0b10},
        };

        ///
        /// @brief Checks and converts a drive impedance attribute value to the MR field value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the code is operating
        /// @param[in] i_attr the attribute value to check and convert
        /// @param[in] i_is_pu true if the value being checked is for the pull up field
        /// @param[out] o_field the MR field value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_drv_imp_to_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint64_t i_dimm_rank,
                const uint8_t i_attr,
                const bool i_is_pu,
                uint8_t& o_field) const
        {
            FAPI_ASSERT(find_value_from_key<3>(DRV_IMP_TABLE,
                                               i_attr,
                                               o_field),
                        fapi2::MSS_DDR5_MR5_DRV_IMP_ATTR_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_VALUE(i_attr)
                        .set_IS_PULL_UP(i_is_pu),
                        TARGTIDFORMAT " DDR5 MR5. Bad %s DRV impedance value on DIMM rank %u. Value: %u", TARGTID,
                        i_is_pu ? "pull up" : "pull down", i_dimm_rank, i_attr);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks and converts a mode register field value to an impedance attribute value
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which the code is operating
        /// @param[in] i_field the MR field value to check and convert
        /// @param[in] i_is_pu true if the value being checked is for the pull up field
        /// @param[out] o_value the attribute value
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_and_convert_drv_imp_from_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint64_t i_dimm_rank,
                const uint8_t i_field,
                const bool i_is_pu,
                uint8_t& o_value) const
        {
            FAPI_ASSERT(find_key_from_value<3>(DRV_IMP_TABLE,
                                               i_field,
                                               o_value),
                        fapi2::MSS_DDR5_MR5_DRV_IMP_FIELD_VALUE()
                        .set_DIMM_IN_ERROR(i_target)
                        .set_DIMM_RANK(i_dimm_rank)
                        .set_FIELD(i_field)
                        .set_IS_PULL_UP(i_is_pu),
                        TARGTIDFORMAT " DDR5 MR5. Bad %s DRV impedance value on DIMM rank %u. field: %u", TARGTID,
                        i_is_pu ? "pull up" : "pull down", i_dimm_rank, i_field);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR5
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR5 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const
        {
            fapi2::buffer<uint8_t> l_data;
            uint8_t l_pu_field = 0;
            uint8_t l_pd_field = 0;

            const auto& l_dimm_target = i_rank_info.get_dimm_target();
            const auto l_dimm_rank = i_rank_info.get_dimm_rank();

            // Checks and conducts the lookups to the field values
            FAPI_TRY(check_and_convert_drv_imp_to_field(l_dimm_target,
                     l_dimm_rank,
                     iv_pu_drv_imp[l_dimm_rank],
                     true,
                     l_pu_field));
            FAPI_TRY(check_and_convert_drv_imp_to_field(l_dimm_target,
                     l_dimm_rank,
                     iv_pd_drv_imp[l_dimm_rank],
                     false,
                     l_pd_field));

            l_data. template writeBit<DATA_OUTPUT_DISABLE>(iv_data_output_disable)
            . template writeBit<DRV_TEST_MODE>(iv_drv_test_mode_supported_read_only)
            . template writeBit<TDQS_ENABLE>(iv_tdqs_enable)
            . template writeBit<DM_ENABLE>(iv_dm_enable)
            . template insertFromRight<PD_DRV_IMP, PD_DRV_IMP_LEN>(l_pd_field). template
            insertFromRight<PU_DRV_IMP, PU_DRV_IMP_LEN>(l_pu_field);

            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR5 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const
        {
            display(i_rank_info.get_dimm_target(), i_rank_info.get_dimm_rank());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR5 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info, const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0)
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);
            uint8_t l_pu_field = 0;
            uint8_t l_pd_field = 0;

            iv_tdqs_enable = l_data.getBit<TDQS_ENABLE>();
            iv_dm_enable = l_data.getBit<DM_ENABLE>();
            iv_drv_test_mode_supported_read_only = l_data.getBit<DRV_TEST_MODE>();


            l_data. template extractToRight<PU_DRV_IMP, PU_DRV_IMP_LEN>(l_pu_field)
            . template extractToRight<PD_DRV_IMP, PD_DRV_IMP_LEN>(l_pd_field);


            FAPI_TRY(check_and_convert_drv_imp_from_field(i_rank_info.get_dimm_target(),
                     0,
                     l_pu_field,
                     true,
                     iv_pu_drv_imp[i_rank_info.get_dimm_rank()]));
            FAPI_TRY(check_and_convert_drv_imp_from_field(i_rank_info.get_dimm_target(),
                     0,
                     l_pd_field,
                     false,
                     iv_pd_drv_imp[i_rank_info.get_dimm_rank()]));

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            DATA_OUTPUT_DISABLE = 7,
            PU_DRV_IMP = 5,
            PU_DRV_IMP_LEN = 2,
            DRV_TEST_MODE = 4,
            TDQS_ENABLE = 3,
            DM_ENABLE = 2,
            PD_DRV_IMP = 0,
            PD_DRV_IMP_LEN = 2,
        };

        uint8_t iv_data_output_disable = 0; // Write only - will not be read
        uint8_t iv_pu_drv_imp[mr::ATTR_RANKS] = {};
        uint8_t iv_drv_test_mode_supported_read_only = 0; // Read only - will not be written
        uint8_t iv_tdqs_enable = 0;
        uint8_t iv_dm_enable = 0;
        uint8_t iv_pd_drv_imp[mr::ATTR_RANKS] = {};

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_dimm_rank the DIMM rank's value to print
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, const uint64_t i_dimm_rank) const
        {
            FAPI_INF(TARGTIDFORMAT
                     " DDR5 MR5 rank%u. data output disable %u. PU drive impedance %u.", TARGTID, i_dimm_rank,
                     iv_data_output_disable, iv_pu_drv_imp[i_dimm_rank]);

            FAPI_INF(TARGTIDFORMAT
                     " DDR5 MR5 rank%u. drive test mode support (Read only): %u. tDQS enable %u.", TARGTID, i_dimm_rank,
                     iv_drv_test_mode_supported_read_only, iv_tdqs_enable);
            FAPI_INF(TARGTIDFORMAT " DDR5 MR5 rank%u. DM enable %u. PD drive impedance %u.", TARGTID, i_dimm_rank,
                     iv_dm_enable, iv_pd_drv_imp[i_dimm_rank]);
        }
};

template<mss::mc_type MC>
constexpr const pair<uint8_t, uint8_t> mr5_data<MC>::DRV_IMP_TABLE[3];

} // ns ddr5

} // ns mss

#endif
