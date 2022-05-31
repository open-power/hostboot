/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr4.H $          */
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
/// @file ddr5_mr4.H
/// @brief Run and manage the DDR5 MR4 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR4_H_
#define _GENERIC_DDR5_MR4_H_

#include <fapi2.H>

#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
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
/// @brief Data structure for DDR5 MR4
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr4_data
{
    public:

        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 4;

        ///
        /// @brief mr4_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr4_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc )
        {
            const auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

            FAPI_TRY( mss::attr::get_ddr5_min_ref_rate(l_port_target, iv_min_refresh_rate_read_only), "Error in ddr5::mr4_data()" );
            FAPI_TRY( mss::attr::get_ddr5_ref_wide_range(l_port_target, iv_wide_range_read_only), "Error in ddr5::mr4_data()" );
            FAPI_TRY( mss::attr::get_ddr5_ref_tuf(l_port_target, iv_tuf_read_only), "Error in ddr5::mr4_data()" );
            FAPI_TRY( mss::attr::get_ref_rate_indic(l_port_target, iv_refresh_interval_rate), "Error in ddr5::mr4_data()" );
            FAPI_TRY( mss::attr::get_mrw_fine_refresh_mode(iv_refresh_trfc_mode), "Error in ddr5::mr4_data()" );

            o_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            o_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr4", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr4_data() = default;

        ///
        /// @brief Checks the minimum refresh rate based upon the wide range support
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in] i_wide_range setting for the wide temperate range support for refreshes
        /// @param[in] i_min_ref_rate setting for the minimum refresh rate to check
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode check_min_refresh_range(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_wide_range,
                const uint8_t i_min_ref_rate) const
        {
            constexpr uint8_t MIN_NORMAL_RANGE = 0b001;
            constexpr uint8_t MAX_NORMAL_RANGE = 0b101;
            constexpr uint8_t MAX_WIDE_RANGE   = 0b110;
            // Wide range is always good if we're in the normal range. Otherwise check the range
            const bool WIDE_RANGE_GOOD = (i_wide_range == fapi2::ENUM_ATTR_MEM_REF_WIDE_RANGE_UNSUPPORTED) ||
                                         (i_min_ref_rate <= MAX_WIDE_RANGE);
            // Normal range is always good if we're in wide range. Otherwise check the values
            const bool NORMAL_RANGE_GOOD = (i_wide_range == fapi2::ENUM_ATTR_MEM_REF_WIDE_RANGE_SUPPORTED) ||
                                           (i_min_ref_rate >= MIN_NORMAL_RANGE && i_min_ref_rate <= MAX_NORMAL_RANGE);
            FAPI_ASSERT( WIDE_RANGE_GOOD && NORMAL_RANGE_GOOD,
                         fapi2::MSS_DDR5_MR4_BAD_MIN_REFRESH_RATE()
                         .set_DIMM_IN_ERROR(i_target)
                         .set_MIN_REFRESH_RATE(i_min_ref_rate)
                         .set_WIDE_RANGE(i_wide_range),
                         TARGTIDFORMAT " DDR5 MR4. Bad refresh rate: %u. Wide range is: %u. Consult the DDR5 JEDEC spec (MR4) for details",
                         TARGTID, i_min_ref_rate, i_wide_range);

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR4
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR4 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const
        {
            fapi2::buffer<uint8_t> l_data;

            // Only NORMAL or DDR5_FINE are allowable values
            // Note: not including the DIMM target here as this comes from an MRW value and will impact ALL DIMM's
            FAPI_ASSERT(iv_refresh_trfc_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_DDR5_FINE ||
                        iv_refresh_trfc_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL,
                        fapi2::MSS_DDR5_MR4_BAD_TRFC_MODE()
                        .set_VALUE(iv_refresh_trfc_mode),
                        "Bad value for TRFC mode: %u. Only NORMAL(%u) and DDR5_FINE(%u) are allowed",
                        iv_refresh_trfc_mode, fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL,
                        fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_DDR5_FINE);

            FAPI_TRY(check_min_refresh_range(i_rank_info.get_dimm_target(),
                                             iv_wide_range_read_only,
                                             iv_min_refresh_rate_read_only));

            l_data. template writeBit<REF_INT_RATE>(iv_refresh_interval_rate)
            . template writeBit<REF_TRFC_MODE>(iv_refresh_trfc_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_DDR5_FINE)
            . template writeBit<TUF>(iv_tuf_read_only)
            . template writeBit<WIDE_RANGE>(iv_wide_range_read_only)
            . template insertFromRight<MIN_REF_RATE, MIN_REF_RATE_LEN>(iv_min_refresh_rate_read_only);

            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR2 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const
        {
            display(i_rank_info.get_dimm_target());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR4 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR4 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0)
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);

            // Note: checking the refresh rate below after getting the wide range mode
            l_data. template extractToRight<MIN_REF_RATE, MIN_REF_RATE_LEN>(iv_min_refresh_rate_read_only);

            iv_refresh_interval_rate = l_data. template getBit<REF_INT_RATE>();
            iv_refresh_trfc_mode = l_data. template getBit<REF_TRFC_MODE>() ? fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_DDR5_FINE :
            fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL;
            iv_wide_range_read_only = l_data. template getBit<WIDE_RANGE>() ?  fapi2::ENUM_ATTR_MEM_REF_WIDE_RANGE_SUPPORTED :
            fapi2::ENUM_ATTR_MEM_REF_WIDE_RANGE_UNSUPPORTED;
            iv_tuf_read_only = l_data. template getBit<TUF>();

            FAPI_TRY(check_min_refresh_range(i_rank_info.get_dimm_target(),
                                             iv_wide_range_read_only,
                                             iv_min_refresh_rate_read_only));

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            MIN_REF_RATE = 5,
            MIN_REF_RATE_LEN = 3,
            REF_INT_RATE = 4,
            REF_TRFC_MODE = 3,
            WIDE_RANGE = 2,
            TUF = 0,
        };

        uint8_t iv_min_refresh_rate_read_only = 0;
        uint8_t iv_refresh_interval_rate = 0;
        uint8_t iv_refresh_trfc_mode = 0;
        uint8_t iv_wide_range_read_only = 0;
        uint8_t iv_tuf_read_only = 0;

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
        {
            FAPI_INF(TARGTIDFORMAT " DDR5 MR4. min refresh rate %u. refresh interval rate %u. tRFC mode: %u", TARGTID,
                     iv_min_refresh_rate_read_only, iv_refresh_interval_rate, iv_refresh_trfc_mode);
            FAPI_INF(TARGTIDFORMAT " DDR5 MR4. wide range %u. TUF %u", TARGTID, iv_wide_range_read_only, iv_tuf_read_only);
        }
};

} // ns ddr5

} // ns mss

#endif
