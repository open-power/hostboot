/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_train_handler.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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

///
/// @file exp_train_handler.C
/// @brief Procedure handle any training fails from the explorer
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <generic/memory/lib/utils/endian_utils.H>
#include <mss_generic_attribute_setters.H>
#include <mss_generic_attribute_getters.H>
#include <exp_train_handler.H>

namespace mss
{
namespace exp
{

///
/// @brief Reads the training response structure
/// @param[in] i_target the target associated with the response data
/// @param[in] i_data the response data to read
/// @param[out] o_resp the processed training response class
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode read_normal_training_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        user_response_msdg& o_resp)
{
    // We assert at the end to avoid LOTS of fapi asserts
    uint32_t l_idx = 0;
    uint32_t l_version_number = 0;
    bool l_pass = readLE(i_data, l_idx, l_version_number);
    o_resp.version_number = l_version_number;

    FAPI_TRY(read_tm_err_mrs_rc_response<user_response_msdg>(i_target, i_data, l_idx, l_pass, o_resp));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads the mds training response structure
/// @param[in] i_target the target associated with the response data
/// @param[in] i_data the response data to read
/// @param[out] o_resp the processed training response class
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode read_mds_training_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        user_response_mds_msdg& o_resp)
{
    // We assert at the end to avoid LOTS of fapi asserts
    uint32_t l_idx = 0;
    uint32_t l_version_number = 0;
    bool l_pass = readLE(i_data, l_idx, l_version_number);
    o_resp.version_number = l_version_number;

    FAPI_TRY(read_mrs_err_mds_response<user_response_mds_msdg>(i_target, i_data, l_idx, l_pass, o_resp));

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Parse the MRS data from the response to correct attributes
/// @param[in] i_target OCMB chip
/// @param[in] i_resp MRS response struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode parse_mrs_data_attributes(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const user_response_mrs_msdg_t& i_resp)
{
    using TT = mss::rank::rankTraits<mss::mc_type::EXPLORER>;

    uint8_t l_temp_attr = 0;

    fapi2::buffer<uint16_t> l_MR0(i_resp.MR0);
    fapi2::buffer<uint16_t> l_MR1(i_resp.MR1[0]);
    fapi2::buffer<uint16_t> l_MR2(i_resp.MR2[0]);
    fapi2::buffer<uint16_t> l_MR3(i_resp.MR3);
    fapi2::buffer<uint16_t> l_MR4(i_resp.MR4);
    fapi2::buffer<uint16_t> l_MR5(i_resp.MR5[0]);
    fapi2::buffer<uint16_t> l_MR6(i_resp.MR6[0][0]);

    for (const auto& l_port_target : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        uint8_t l_odic_arr[mss::exp::MAX_DIMM_PER_PORT][TT::MAX_RANKS_PER_DIMM] = {0};
        uint8_t l_rtt_nom_arr[mss::exp::MAX_DIMM_PER_PORT][TT::MAX_RANKS_PER_DIMM] = {0};
        uint8_t l_rtt_wr_arr[mss::exp::MAX_DIMM_PER_PORT][TT::MAX_RANKS_PER_DIMM] = {0};
        uint8_t l_rtt_park_arr[mss::exp::MAX_DIMM_PER_PORT][TT::MAX_RANKS_PER_DIMM] = {0};
        uint8_t l_vrefdq_value[mss::exp::MAX_DIMM_PER_PORT][TT::MAX_RANKS_PER_DIMM][mss::exp::MAX_NIBBLES_PER_PORT] = {0};
        uint8_t l_vrefdq_range[mss::exp::MAX_DIMM_PER_PORT][TT::MAX_RANKS_PER_DIMM][mss::exp::MAX_NIBBLES_PER_PORT] = {0};
        uint8_t l_vrefdq_enable[mss::exp::MAX_DIMM_PER_PORT][TT::MAX_RANKS_PER_DIMM][mss::exp::MAX_NIBBLES_PER_PORT] = {0};

        std::vector<mss::rank::info<mss::mc_type::EXPLORER>> l_rank_infos;
        FAPI_TRY(mss::rank::ranks_on_port(l_port_target, l_rank_infos));

        // Parse MR0 Attributes
        l_temp_attr = l_MR0.getBit<MR0_EFF_DRAM_RBT>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DRAM_RBT, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR0.getBit<MR0_EFF_DRAM_TM>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DRAM_TM, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR0.getBit<MR0_EFF_DRAM_DLL_RESET>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DRAM_DLL_RESET, l_port_target, l_temp_attr) );

        l_temp_attr = 0;
        l_MR0.extractToRight<MR0_EFF_BURST_LENGTH, MR0_EFF_BURST_LENGTH_LEN>(l_temp_attr);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DRAM_BURST_LENGTH, l_port_target, l_temp_attr) );

        // Parse MR1 Attributes
        l_temp_attr = l_MR1.getBit<MR1_EFF_DRAM_DLL_ENABLE>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DRAM_DLL_ENABLE, l_port_target, l_temp_attr) );

        l_temp_attr = 0;
        l_MR1.extractToRight<MR1_EFF_DRAM_AL, MR1_EFF_DRAM_AL_LEN>(l_temp_attr);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DRAM_AL, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR1.getBit<MR1_EFF_DRAM_WR_LVL_ENABLE>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DRAM_WR_LVL_ENABLE, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR1.getBit<MR1_EFF_DRAM_TDQS>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DRAM_TDQS, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR1.getBit<MR1_EFF_DRAM_OUTPUT_BUFFER>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DRAM_OUTPUT_BUFFER, l_port_target, l_temp_attr) );

        // Parse MR2 Attributes
        l_temp_attr = 0;
        l_MR2.extractToRight<MR2_EFF_DRAM_LPASR, MR2_EFF_DRAM_LPASR_LEN>(l_temp_attr);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DRAM_LPASR, l_port_target, l_temp_attr) );

        // Parse MR3 Attributes
        l_temp_attr = 0;
        l_MR3.extractToRight<MR3_EFF_MPR_PAGE, MR3_EFF_MPR_PAGE_LEN>(l_temp_attr);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_MPR_PAGE, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR3.getBit<MR3_EFF_MPR_MODE>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_MPR_MODE, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR3.getBit<MR3_EFF_GEARDOWN_MODE>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_GEARDOWN_MODE, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR3.getBit<MR3_EFF_PER_DRAM_ACCESS>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_PER_DRAM_ACCESS, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR3.getBit<MR3_EFF_TEMP_READOUT>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_TEMP_READOUT, l_port_target, l_temp_attr) );

        l_temp_attr = 0;
        l_MR3.extractToRight<MR3_EFF_CRC_WR_LATENCY, MR3_EFF_CRC_WR_LATENCY_LEN>(l_temp_attr);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_CRC_WR_LATENCY, l_port_target, l_temp_attr) );

        l_temp_attr = 0;
        l_MR3.extractToRight<MR3_EFF_MPR_RD_FORMAT, MR3_EFF_MPR_RD_FORMAT_LEN>(l_temp_attr);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_MPR_RD_FORMAT, l_port_target, l_temp_attr) );

        // Parse MR4 Attributes
        l_temp_attr = l_MR4.getBit<MR4_EFF_MAX_POWERDOWN_MODE>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_MAX_POWERDOWN_MODE, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR4.getBit<MR4_EFF_INTERNAL_VREF_MONITOR>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_INTERNAL_VREF_MONITOR, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR4.getBit<MR4_EFF_SELF_REF_ABORT>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_SELF_REF_ABORT, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR4.getBit<MR4_EFF_RD_PREAMBLE_TRAIN>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_RD_PREAMBLE_TRAIN, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR4.getBit<MR4_EFF_RD_PREAMBLE>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_RD_PREAMBLE, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR4.getBit<MR4_EFF_WR_PREAMBLE>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_WR_PREAMBLE, l_port_target, l_temp_attr) );

        // Parse MR5 Attributes
        l_temp_attr = l_MR5.getBit<MR5_EFF_CRC_ERROR_CLEAR>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_CRC_ERROR_CLEAR, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR5.getBit<MR5_EFF_CA_PARITY_ERROR_STATUS>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_CA_PARITY_ERROR_STATUS, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR5.getBit<MR5_EFF_ODT_INPUT_BUFF>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_ODT_INPUT_BUFF, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR5.getBit<MR5_EFF_CA_PARITY>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_CA_PARITY, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR5.getBit<MR5_EFF_DATA_MASK>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_DATA_MASK, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR5.getBit<MR5_EFF_WRITE_DBI>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_WRITE_DBI, l_port_target, l_temp_attr) );

        l_temp_attr = l_MR5.getBit<MR5_EFF_READ_DBI>();
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_RESP_READ_DBI, l_port_target, l_temp_attr) );

        // Parse rank based MRs
        // Note: we're only parsing for existing ranks
        // Any ranks that do not exist will have 0 values for their attributes
        // That's ok, we should not use those values anyways
        for(const auto& l_rank_info : l_rank_infos)
        {
            // Microchip's firmware outputs their data in terms of the PHY perspective
            // Our attributes are encoded in terms of the IBM perspective
            // As such, we copy the data from the PHY perspective and record it as the DIMM perspective
            // Any swizzles should be taken into account in this way
            const auto l_phy_rank = l_rank_info.get_phy_rank();
            const auto l_dimm_rank = l_rank_info.get_dimm_rank();
            const auto l_dimm_index = mss::index(l_rank_info.get_dimm_target());

            // Set Rank level MRs
            fapi2::buffer<uint16_t> l_MR1_Rank(i_resp.MR1[l_phy_rank]);
            fapi2::buffer<uint16_t> l_MR2_Rank(i_resp.MR2[l_phy_rank]);
            fapi2::buffer<uint16_t> l_MR5_Rank(i_resp.MR5[l_phy_rank]);

            l_temp_attr = 0;
            l_MR1_Rank.extractToRight<MR1_EFF_DRAM_ODIC, MR1_EFF_DRAM_ODIC_LEN>(l_temp_attr);
            l_odic_arr[l_dimm_index][l_dimm_rank] = l_temp_attr;

            l_temp_attr = 0;
            l_MR1_Rank.extractToRight<MR1_EFF_DRAM_RTT_NOM, MR1_EFF_DRAM_RTT_NOM_LEN>(l_temp_attr);
            l_rtt_nom_arr[l_dimm_index][l_dimm_rank] = l_temp_attr;

            l_temp_attr = 0;
            l_MR2_Rank.extractToRight<MR2_EFF_DRAM_RTT_WR, MR2_EFF_DRAM_RTT_WR_LEN>(l_temp_attr);
            l_rtt_wr_arr[l_dimm_index][l_dimm_rank] = l_temp_attr;

            l_temp_attr = 0;
            l_MR5_Rank.extractToRight<MR5_EFF_DRAM_RTT_PARK, MR5_EFF_DRAM_RTT_PARK_LEN>(l_temp_attr);
            l_rtt_park_arr[l_dimm_index][l_dimm_rank] = l_temp_attr;

            // Set DRAM based MRs
            for (int d = 0; d < mss::exp::MAX_NIBBLES_PER_PORT; d++)
            {
                fapi2::buffer<uint16_t> l_MR6_Rank(i_resp.MR6[l_phy_rank][d]);

                l_temp_attr = l_MR6.getBit<MR6_VREFDQ_TRAINING_RANGE>();
                l_vrefdq_range[l_dimm_index][l_dimm_rank][d] = l_temp_attr;

                l_temp_attr = l_MR6.getBit<MR6_VREFDQ_TRAINING_ENABLE>();
                l_vrefdq_enable[l_dimm_index][l_dimm_rank][d] = l_temp_attr;

                l_temp_attr = 0;
                l_MR6_Rank.extractToRight<MR6_VREFDQ_TRAINING_VALUE, MR6_VREFDQ_TRAINING_VALUE_LEN>(l_temp_attr);
                l_vrefdq_value[l_dimm_index][l_dimm_rank][d] = l_temp_attr;

            } // End of DRAM loop

        } // End rank loop

        FAPI_TRY( mss::attr::set_exp_resp_vref_dq_train_value(l_port_target, l_vrefdq_value) );
        FAPI_TRY( mss::attr::set_exp_resp_vref_dq_train_range(l_port_target, l_vrefdq_range) );
        FAPI_TRY( mss::attr::set_exp_resp_vref_dq_train_enable(l_port_target, l_vrefdq_enable) );
        FAPI_TRY( mss::attr::set_exp_resp_dram_odic(l_port_target, l_odic_arr) );
        FAPI_TRY( mss::attr::set_exp_resp_dram_rtt_nom(l_port_target, l_rtt_nom_arr) );
        FAPI_TRY( mss::attr::set_exp_resp_dram_rtt_park(l_port_target, l_rtt_park_arr) );
        FAPI_TRY( mss::attr::set_exp_resp_dram_rtt_wr(l_port_target, l_rtt_wr_arr) );

    } // End port loop

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

} // ns exp
} // ns mss
