/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr5/ddr5_mr2.H $          */
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
/// @file ddr5_mr2.H
/// @brief Run and manage the DDR5 MR2 loading
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR5_MR2_H_
#define _GENERIC_DDR5_MR2_H_

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
/// @brief Data structure for DDR5 MR2
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class mr2_data
{
    public:
        // Needed as we need to know what MR for the CCS instruction created by the lab tooling
        static constexpr uint64_t iv_mr = 2;

        ///
        /// @brief mr2_data ctor
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
        ///
        mr2_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc ) :
            iv_rd_preamble_train(0),
            iv_wr_leveling(0),
            iv_2n_mode_read_only(0),
            iv_mpsm(0),
            iv_cs_during_mpc(0),
            iv_device15_mpsm(0),
            iv_internal_wr_timing(0)
        {
            const auto l_port_target = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
            const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

            FAPI_TRY( mss::attr::get_mem_2n_mode(l_ocmb, iv_2n_mode_read_only), "Error in ddr5::mr2_data()" );
            FAPI_TRY( mss::attr::get_mpsm(l_port_target, iv_mpsm), "Error in ddr5::mr2_data()" );
            FAPI_TRY( mss::attr::get_cs_assert_in_mpc(l_port_target, iv_cs_during_mpc), "Error in ddr5::mr2_data()" );
            FAPI_TRY( mss::attr::get_device15_mpsm(l_port_target, iv_device15_mpsm), "Error in ddr5::mr2_data()" );
            FAPI_TRY( mss::attr::get_internal_wr_timing_mode(l_port_target, iv_internal_wr_timing), "Error in ddr5::mr2_data()" );

            o_rc = fapi2::FAPI2_RC_SUCCESS;
            return;
        fapi_try_exit:
            o_rc = fapi2::current_err;
            FAPI_ERR(TARGTIDFORMAT " unable to get attributes for ddr5::mr2", TARGTID);
            return;
        }

        ///
        /// @brief Default constructor
        /// @note Default constructor is defined to allow for the use of STL data structures
        ///
        mr2_data() = default;

        ///
        /// @brief Assembles the MR based upon the passed in rank info and DRAM number
        /// @param[in] i_rank_info the rank information class
        /// @param[out] o_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM number - not used for MR2
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note DRAM number is not used for MR2 but is kept to keep the interface common across all MR
        ///
        fapi2::ReturnCode assemble_data(const mss::rank::info<MC>& i_rank_info, uint8_t& o_mr_data,
                                        const uint8_t i_dram_number = 0) const
        {
            fapi2::buffer<uint8_t> l_data;

            l_data. template writeBit<RD_PREAMBLE_TRAIN>(iv_rd_preamble_train)
            . template writeBit<WR_LVL_TRAIN>(iv_wr_leveling)
            . template writeBit<MODE_2N>(iv_2n_mode_read_only)
            . template writeBit<CS_DURING_MPC>(iv_cs_during_mpc)
            . template writeBit<DEVICE15_MPSM>(iv_device15_mpsm)
            . template writeBit<INTERNAL_WR_TIMING>(iv_internal_wr_timing)
            . template writeBit<MPSM>(iv_mpsm);

            o_mr_data = l_data;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] i_rank_info the rank on which to operate
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR2 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode display(const mss::rank::info<MC>& i_rank_info, const uint8_t i_dram_number = 0) const
        {
            this->display(i_rank_info.get_dimm_target());
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Reads in the MR information into this data class
        /// @param[in] i_rank_info the rank on which to operate - unused for MR2 but keeping to match existing API
        /// @param[in] i_mr_data the mode register OP data in [7:0] format
        /// @param[in] i_dram_number the DRAM on which to operate - not used for MR2 but included to keep the API common
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note This can be used for decoding mode register reads
        ///
        fapi2::ReturnCode read_from_data(const mss::rank::info<MC>& i_rank_info, const uint8_t i_mr_data,
                                         const uint8_t i_dram_number = 0)
        {

            fapi2::buffer<uint8_t> l_data(i_mr_data);

            iv_rd_preamble_train = l_data.getBit<RD_PREAMBLE_TRAIN>();
            iv_wr_leveling = l_data.getBit<WR_LVL_TRAIN>();
            iv_2n_mode_read_only = l_data.getBit<MODE_2N>();
            iv_mpsm = l_data.getBit<MPSM>();
            iv_cs_during_mpc = l_data.getBit<CS_DURING_MPC>();
            iv_device15_mpsm = l_data.getBit<DEVICE15_MPSM>();
            iv_internal_wr_timing = l_data.getBit<INTERNAL_WR_TIMING>();
            return fapi2::FAPI2_RC_SUCCESS;
        }

        enum
        {
            RD_PREAMBLE_TRAIN = 7,
            WR_LVL_TRAIN = 6,
            MODE_2N = 5,
            MPSM = 4,
            CS_DURING_MPC = 3,
            DEVICE15_MPSM = 2,
            INTERNAL_WR_TIMING = 0,
        };

        uint8_t iv_rd_preamble_train = 0; // Note: does not have ATTR control as normal operation requires a 0
        uint8_t iv_wr_leveling = 0; // Note: does not have ATTR control as normal operation requires a 0
        uint8_t iv_2n_mode_read_only = 0;
        uint8_t iv_mpsm = 0;
        uint8_t iv_cs_during_mpc = 0;
        uint8_t iv_device15_mpsm = 0;
        uint8_t iv_internal_wr_timing = 0;

    private:

        ///
        /// @brief Displays the information that makes up the MR
        /// @param[in] a fapi2::TARGET_TYPE_DIMM target
        ///
        void display(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
        {

            FAPI_INF(TARGTIDFORMAT " DDR5 MR2. RD preamble train: %u. burst length: %u. 2N mode (read only) %u", TARGTID,
                     iv_rd_preamble_train, iv_wr_leveling, iv_2n_mode_read_only);
            FAPI_INF(TARGTIDFORMAT " DDR5 MR2. MPSM: %u. CS during MPC: %u. device 15 MPSM %u", TARGTID, iv_mpsm, iv_cs_during_mpc,
                     iv_device15_mpsm);
            FAPI_INF(TARGTIDFORMAT " DDR5 MR2. internal WR timing %u", TARGTID, iv_internal_wr_timing);
        }
};

} // ns ddr5

} // ns mss

#endif
