/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr50.H $         */
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
/// @file ddr5_mr50.H
/// @brief Run and manage the DDR5 MR50 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR50_H_
#define _GENERIC_DDR5_MR50_H_

#include <fapi2.H>

#include <mss_generic_attribute_getters.H>
#include <mss_generic_attribute_setters.H>
#include <mss_generic_system_attribute_getters.H>
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
/// @brief Data structure for DDR5 MR50
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr50_data : public mr_base_data<MC>
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 50;

        ///
        /// @brief mr50_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[in,out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr50_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& io_rc ) : mr_base_data<MC>(iv_mr)
        {

            if (io_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                return;
            }

            const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DDR5_DRAM_READ_CRC, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   iv_rd_crc_enable), "Error in ddr5::mr50_data()");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DRAM_WRITE_CRC, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   iv_wr_crc_enable_lower_nibble), "Error in ddr5::mr50_data()");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DRAM_WRITE_CRC, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   iv_wr_crc_enable_upper_nibble), "Error in ddr5::mr50_data()");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_DDR5_WR_CRC_ERR_STATUS, l_port, iv_wr_crc_error_status),
                     "Error in ddr5::mr50_data()");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_DDR5_WR_CRC_AUTODISABLE_ENABLE, l_port, iv_wr_crc_autodisable_enable),
                     "Error in ddr5::mr50_data()");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_DDR5_WR_CRC_AUTODISABLE_STATUS, l_port, iv_wr_crc_autodisable_status),
                     "Error in ddr5::mr50_data()");

            io_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            io_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr50", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr50_data(): mr_base_data<MC>(iv_mr) {};

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR50
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR50 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info,
                                        uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const override
        {
            fapi2::buffer<uint8_t> l_data;

            l_data. template writeBit<RD_CRC>(iv_rd_crc_enable)
            . template writeBit<WR_CRC_LOWER>(iv_wr_crc_enable_lower_nibble)
            . template writeBit<WR_CRC_UPPER>(iv_wr_crc_enable_upper_nibble)
            . template writeBit<WR_CRC_ERR_STATUS>(iv_wr_crc_error_status)
            . template writeBit<WR_CRC_AUTODISABLE_ENABLE>(iv_wr_crc_autodisable_enable)
            . template writeBit<WR_CRC_AUTODISABLE_STATUS>(iv_wr_crc_autodisable_status);

            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR50 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const override
        {
            this->display(i_rank_info.get_dimm_target());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR50 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR50 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info,
                                         const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0) override
        {
            const fapi2::buffer<uint8_t> l_data(i_mr_data);

            iv_rd_crc_enable = l_data. template getBit<RD_CRC>();
            iv_wr_crc_enable_lower_nibble = l_data. template getBit<WR_CRC_LOWER>();
            iv_wr_crc_enable_upper_nibble = l_data. template getBit<WR_CRC_UPPER>();
            iv_wr_crc_error_status = l_data. template getBit<WR_CRC_ERR_STATUS>();
            iv_wr_crc_autodisable_enable = l_data. template getBit<WR_CRC_AUTODISABLE_ENABLE>();
            iv_wr_crc_autodisable_status = l_data. template getBit<WR_CRC_AUTODISABLE_STATUS>();

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Sets the attribute for this MR for lab tool
        /// @param[in] i_rank_info the rank on which to operate
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode attr_setter(const mss::rank::info<MC>& i_rank_info) override
        {
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_DDR5_WR_CRC_ERR_STATUS, i_rank_info.get_port_target(), iv_wr_crc_error_status),
                     "Unable to set attributes for ddr5::mr50_data()");
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_DDR5_WR_CRC_AUTODISABLE_ENABLE, i_rank_info.get_port_target(),
                                   iv_wr_crc_autodisable_enable),
                     "Unable to set attributes for ddr5::mr50_data()");
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_DDR5_WR_CRC_AUTODISABLE_STATUS, i_rank_info.get_port_target(),
                                   iv_wr_crc_autodisable_status),
                     "Unable to set attributes for ddr5::mr50_data()");

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        enum
        {
            RD_CRC = 7,
            WR_CRC_LOWER = 6,
            WR_CRC_UPPER = 5,
            WR_CRC_ERR_STATUS = 4,
            WR_CRC_AUTODISABLE_ENABLE = 3,
            WR_CRC_AUTODISABLE_STATUS = 2,
        };

        uint8_t iv_rd_crc_enable = 0;
        uint8_t iv_wr_crc_enable_lower_nibble = 0;
        uint8_t iv_wr_crc_enable_upper_nibble = 0;
        uint8_t iv_wr_crc_error_status = 0;
        uint8_t iv_wr_crc_autodisable_enable = 0;
        uint8_t iv_wr_crc_autodisable_status = 0;

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
        {
            FAPI_INF_NO_SBE(TARGTIDFORMAT
                            " DDR5 MR50. RD CRC enable: %u. WR CRC enable lower nibble: %u. WR CRC enable upper nibble: %u.",
                            TARGTID, iv_rd_crc_enable, iv_wr_crc_enable_lower_nibble, iv_wr_crc_enable_upper_nibble);
            FAPI_INF_NO_SBE(TARGTIDFORMAT
                            " DDR5 MR50. WR CRC error status: %u. WR CRC auto-disable enable: %u. WR CRC auto-disable status: %u.",
                            TARGTID, iv_wr_crc_error_status, iv_wr_crc_autodisable_enable, iv_wr_crc_autodisable_status);
        }

};

} // ns ddr5

} // ns mss

#endif
