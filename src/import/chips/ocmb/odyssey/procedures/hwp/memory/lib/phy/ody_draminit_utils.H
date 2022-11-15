/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_draminit_utils.H $ */
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
/// @file ody_draminit_utils.H
/// @brief Odyssey PHY draminit utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_DRAMINIT_UTILS_H_
#define _ODY_DRAMINIT_UTILS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <lib/shared/ody_consts.H>
#include <lib/dimm/ody_rank.H>
#include <lib/phy/ody_snps_dram_train_msg_blk.H>
#include <lib/dimm/ody_rank.H>
#include <hwp_data_stream.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <mss_odyssey_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr0.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr2.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr3.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr4.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr5.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr6.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr32.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr8.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr10.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr11.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr12.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr13.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr14.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr15.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr111.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr33.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr34.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr35.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr37.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr38.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr39.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr50.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr51.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr52.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr112.H>

namespace mss
{
namespace ody
{
namespace phy
{

constexpr uint8_t NUM_RCW = 0x80;

///
/// @class msg_block_vars
/// @brief Structure of attribute values used in the PHY message block
///
struct msg_block_vars
{
    uint8_t iv_AdvTrainOpt = 0;
    uint8_t iv_MsgMisc = 0;
    uint8_t iv_Pstate = 0;
    uint8_t iv_PllBypassEn = 0;
    uint64_t iv_DRAMFreq = 0;
    uint8_t iv_RCW05_next = 0;
    uint8_t iv_RCW06_next = 0;
    uint8_t iv_RXEN_ADJ = 0;
    uint8_t iv_RX2D_DFE_Misc = 0;
    uint8_t iv_PhyVref = 0;
    uint8_t iv_D5Misc = 0;
    uint8_t iv_WL_ADJ = 0;
    uint16_t iv_SequenceCtrl = 0;
    uint8_t iv_HdtCtrl = 0;
    uint8_t iv_PhyCfg = 0;
    uint8_t iv_DFIMRLMargin = 0;
    uint8_t iv_X16Present = 0;
    uint8_t iv_UseBroadcastMR = 0;
    uint8_t iv_D5Quickboot = 0;
    uint8_t iv_DisabledDbyte = 0;
    uint8_t iv_CATrainOpt = 0;
    uint8_t iv_TX2D_DFE_Misc = 0;
    uint8_t iv_RX2D_TrainOpt = 0;
    uint8_t iv_TX2D_TrainOpt = 0;
    uint8_t iv_Share2DVrefResult = 0;
    uint8_t iv_MRE_MIN_PULSE = 0;
    uint8_t iv_DWL_MIN_PULSE = 0;
    uint16_t iv_PhyConfigOverride = 0;
    uint8_t iv_EnabledDQsChA = 0;
    uint8_t iv_EnabledDQsChB = 0;
    uint8_t iv_CsPresentChA[mss::ody::MAX_DIMM_PER_PORT] = {0};
    uint8_t iv_CsPresentChB[mss::ody::MAX_DIMM_PER_PORT] = {0};
    uint8_t iv_MR0[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR2[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR3[mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] = {0};
    uint8_t iv_MR4[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR5[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR6[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR32[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR32_ORG[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR8[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR10[mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] = {0};
    uint8_t iv_MR11[mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] = {0};
    uint8_t iv_MR12[mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] = {0};
    uint8_t iv_MR13[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR14[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR15[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR111[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR33[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR33_ORG[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR34[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR35[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR37[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR38[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR39[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR50[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR51[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_MR52[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_DFE_GainBias[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_ReservedF6 = 0;
    uint8_t iv_ReservedF7 = 0;
    uint8_t iv_ReservedF8 = 0;
    uint8_t iv_ReservedF9 = 0;
    uint8_t iv_RD_RTT_PARK_attr[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_WR_RTT_PARK_attr[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t iv_RD_RTT_PARK[mss::ody::MAX_RANK_PER_PHY] = {0};
    uint8_t iv_WR_RTT_PARK[mss::ody::MAX_RANK_PER_PHY] = {0};
    uint8_t iv_Reserved1E2 = 0;
    uint8_t iv_Reserved1E3 = 0;
    uint8_t iv_Reserved1E4 = 0;
    uint8_t iv_Reserved1E5 = 0;
    uint8_t iv_Reserved1E6 = 0;
    uint8_t iv_Reserved1E7 = 0;
    uint8_t iv_WL_ADJ_START = 0;
    uint8_t iv_WL_ADJ_END = 0;
    uint8_t iv_RCW[NUM_RCW] = {0};
    uint8_t iv_DisabledDB[mss::ody::MAX_BYTES_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
};

///
/// @class msg_block_params
/// @brief Provides storage and methods for setting up message block structure
/// @note Since this is a large class, here's a description of how it works:
///  constructor:
///   - read attributes into iv_msg_block_vars
///   - set up MR values in iv_msg_block_vars
///   - swizzle rank-based fields from port rank to phy rank
///  setup_<field> functions:
///   - force certain values required for RCD or non-RCD
///   - force certain values required for sim
///   - force RFU values as needed
///   - copy values from iv_msg_block_vars into PMU_SMB_DDR5U_1D_t struct
///
class msg_block_params
{
    private:

        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> iv_target;
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_dimm;
        msg_block_vars iv_msg_block_vars;
        std::vector<mss::rank::info<mss::mc_type::ODYSSEY>> iv_rank_infos;

    public:

        /// default constructor is deleted
        msg_block_params() = delete;

        ///
        /// @brief Constructor to fetch attributes
        ///
        /// @brief fetch the attributes and initialize it to the params
        /// @param[in] i_target the mem_port target
        /// @param[out] ReturnCode to report error in class construction
        ///
        msg_block_params(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                         fapi2::ReturnCode& o_rc):
            iv_target(i_target)
        {
            const auto l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target);
            uint8_t l_dram_width[mss::ody::MAX_DIMM_PER_PORT] = {0};

            if (l_dimms.size() == 0)
            {
                FAPI_INF(TARGTIDFORMAT " No DIMM targets found on port target. Skipping message block setup.", TARGTID);
                o_rc = fapi2::FAPI2_RC_SUCCESS;
                return;
            }

            iv_dimm = l_dimms[0];

            // Create MR data structs
            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
            const auto l_mr0 = mss::ddr5::mr0_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr2 = mss::ddr5::mr2_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr3 = mss::ddr5::mr3_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr4 = mss::ddr5::mr4_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr5 = mss::ddr5::mr5_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr6 = mss::ddr5::mr6_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr32 = mss::ddr5::mr32_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr8 = mss::ddr5::mr8_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr10 = mss::ddr5::mr10_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr11 = mss::ddr5::mr11_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr12 = mss::ddr5::mr12_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr13 = mss::ddr5::mr13_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr14 = mss::ddr5::mr14_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr15 = mss::ddr5::mr15_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr111 = mss::ddr5::mr111_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr33 = mss::ddr5::mr33_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr34 = mss::ddr5::mr34_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr35 = mss::ddr5::mr35_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr37 = mss::ddr5::mr37_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr38 = mss::ddr5::mr38_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr39 = mss::ddr5::mr39_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr50 = mss::ddr5::mr50_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr51 = mss::ddr5::mr51_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr52 = mss::ddr5::mr52_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);
            const auto l_mr112 = mss::ddr5::mr112_data<mss::mc_type::ODYSSEY>(iv_dimm, l_rc);

            FAPI_TRY(l_rc, TARGTIDFORMAT " Failed attribute access during MR setup", TARGTID);

            FAPI_TRY(mss::rank::ranks_on_port(i_target, iv_rank_infos));


            // Fetch attributes and populate the member variables
            // Note: doing this in field order to match PMU_SMB_DDR5U_1D_t definition

            FAPI_TRY(mss::attr::get_phy_adv_train_opt(i_target, iv_msg_block_vars.iv_AdvTrainOpt));
            FAPI_TRY(mss::attr::get_phy_msg_misc(i_target, iv_msg_block_vars.iv_MsgMisc));
            // Pstate is always zero for Odyssey
            iv_msg_block_vars.iv_Pstate = 0;
            FAPI_TRY(mss::attr::get_phy_pll_bypass_en(i_target, iv_msg_block_vars.iv_PllBypassEn));
            FAPI_TRY(mss::attr::get_freq(i_target, iv_msg_block_vars.iv_DRAMFreq));

            // TODO: Zen:MST-1668 RCW05_next and RCW06_next: need to decide how to set these
            //FAPI_TRY(mss::attr::get_rcw05_next(i_target, iv_msg_block_vars.iv_RCW05_next));
            //FAPI_TRY(mss::attr::get_rcw06_next(i_target, iv_msg_block_vars.iv_RCW06_next));

            FAPI_TRY(mss::attr::get_ddr5_rxen_adj(i_target, iv_msg_block_vars.iv_RXEN_ADJ));
            FAPI_TRY(mss::attr::get_phy_rx2d_dfe_misc(i_target, iv_msg_block_vars.iv_RX2D_DFE_Misc));
            FAPI_TRY(mss::attr::get_ddr5_phy_vref_rd(i_target, iv_msg_block_vars.iv_PhyVref));
            FAPI_TRY(mss::attr::get_phy_d5misc(i_target, iv_msg_block_vars.iv_D5Misc));
            FAPI_TRY(mss::attr::get_phy_wl_adj(i_target, iv_msg_block_vars.iv_WL_ADJ));
            FAPI_TRY(mss::attr::get_phy_sequence_ctrl(i_target, iv_msg_block_vars.iv_SequenceCtrl));
            FAPI_TRY(mss::attr::get_ody_draminit_verbosity(i_target, iv_msg_block_vars.iv_HdtCtrl));
            FAPI_TRY(mss::attr::get_phy_cfg(i_target, iv_msg_block_vars.iv_PhyCfg));
            FAPI_TRY(mss::attr::get_dfimrl_margin(i_target, iv_msg_block_vars.iv_DFIMRLMargin));
            // X16Present is always zero for Odyssey
            iv_msg_block_vars.iv_X16Present = 0;
            FAPI_TRY(mss::attr::get_phy_use_broadcast_mr(i_target, iv_msg_block_vars.iv_UseBroadcastMR));
            // D5Quickboot is always zero for Odyssey
            iv_msg_block_vars.iv_D5Quickboot = 0;
            FAPI_TRY(mss::attr::get_disabled_dbyte(i_target, iv_msg_block_vars.iv_DisabledDbyte));
            FAPI_TRY(mss::attr::get_ca_train_options(i_target, iv_msg_block_vars.iv_CATrainOpt));
            FAPI_TRY(mss::attr::get_tx2d_dfe_misc(i_target, iv_msg_block_vars.iv_TX2D_DFE_Misc));
            FAPI_TRY(mss::attr::get_rx2d_train_opt(i_target, iv_msg_block_vars.iv_RX2D_TrainOpt));
            FAPI_TRY(mss::attr::get_tx2d_train_opt(i_target, iv_msg_block_vars.iv_TX2D_TrainOpt));
            // Share2DVrefResult, MRE_MIN_PULSE, and DWL_MIN_PULSE are always zero for Odyssey
            iv_msg_block_vars.iv_Share2DVrefResult = 0;
            iv_msg_block_vars.iv_MRE_MIN_PULSE = 0;
            iv_msg_block_vars.iv_DWL_MIN_PULSE = 0;
            FAPI_TRY(mss::attr::get_phy_config_override(i_target, iv_msg_block_vars.iv_PhyConfigOverride));
            FAPI_TRY(mss::attr::get_phy_enabled_dq_cha(i_target, iv_msg_block_vars.iv_EnabledDQsChA));
            FAPI_TRY(mss::attr::get_phy_enabled_dq_chb(i_target, iv_msg_block_vars.iv_EnabledDQsChB));
            FAPI_TRY(mss::attr::get_dimm_ranks_configed(i_target, iv_msg_block_vars.iv_CsPresentChA));
            FAPI_TRY(mss::attr::get_dimm_ranks_configed(i_target, iv_msg_block_vars.iv_CsPresentChB));

            FAPI_TRY(mss::attr::get_dram_width(i_target, l_dram_width));
            FAPI_ASSERT((l_dram_width != 0),
                        fapi2::ODY_DRAMINIT_ZERO_DRAM_WIDTH()
                        .set_PORT_TARGET(i_target),
                        TARGTIDFORMAT " saw a zero value in ATTR_MEM_EFF_DRAM_WIDTH", TARGTID);

            for (const auto& l_rank_info : iv_rank_infos)
            {
                // TODO Zen:MST-1782 Create API to walk through DRAM/nibble indexes
                const uint8_t l_nibble_increment = (l_dram_width[0] / 4);
                const uint8_t l_max_drams = mss::ody::MAX_NIBBLES_PER_PORT / l_nibble_increment;
                const auto l_phy_rank = l_rank_info.get_phy_rank();

                FAPI_TRY(l_mr0.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR0[l_phy_rank]));
                FAPI_TRY(l_mr2.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR2[l_phy_rank]));
                FAPI_TRY(l_mr4.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR4[l_phy_rank]));
                FAPI_TRY(l_mr5.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR5[l_phy_rank]));
                FAPI_TRY(l_mr6.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR6[l_phy_rank]));
                FAPI_TRY(l_mr32.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR32[l_phy_rank]));
                FAPI_TRY(l_mr32.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR32_ORG[l_phy_rank], mss::ddr5::mr::STRAPB));
                FAPI_TRY(l_mr8.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR8[l_phy_rank]));
                FAPI_TRY(l_mr13.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR13[l_phy_rank]));
                FAPI_TRY(l_mr14.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR14[l_phy_rank]));
                FAPI_TRY(l_mr15.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR15[l_phy_rank]));
                FAPI_TRY(l_mr111.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR111[l_phy_rank]));
                FAPI_TRY(l_mr33.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR33[l_phy_rank]));
                FAPI_TRY(l_mr33.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR33_ORG[l_phy_rank], mss::ddr5::mr::STRAPB));
                FAPI_TRY(l_mr34.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR34[l_phy_rank]));
                FAPI_TRY(l_mr35.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR35[l_phy_rank]));
                FAPI_TRY(l_mr37.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR37[l_phy_rank]));
                FAPI_TRY(l_mr38.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR38[l_phy_rank]));
                FAPI_TRY(l_mr39.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR39[l_phy_rank]));
                FAPI_TRY(l_mr50.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR50[l_phy_rank]));
                FAPI_TRY(l_mr51.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR51[l_phy_rank]));
                FAPI_TRY(l_mr52.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR52[l_phy_rank]));
                FAPI_TRY(l_mr112.assemble_data(l_rank_info, iv_msg_block_vars.iv_DFE_GainBias[l_phy_rank]));

                // Get per-DRAM values
                for (uint8_t l_dram = 0, l_nibble_idx = 0; l_dram < l_max_drams; l_dram++, l_nibble_idx += l_nibble_increment)
                {
                    FAPI_TRY(l_mr3.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR3[l_phy_rank][l_nibble_idx], l_dram));
                    FAPI_TRY(l_mr10.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR10[l_phy_rank][l_nibble_idx], l_dram));
                    FAPI_TRY(l_mr11.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR11[l_phy_rank][l_nibble_idx], l_dram));
                    FAPI_TRY(l_mr12.assemble_data(l_rank_info, iv_msg_block_vars.iv_MR12[l_phy_rank][l_nibble_idx], l_dram));
                }
            }

            // Reserved fields are always zero for Odyssey
            iv_msg_block_vars.iv_ReservedF6 = 0;
            iv_msg_block_vars.iv_ReservedF7 = 0;
            iv_msg_block_vars.iv_ReservedF8 = 0;
            iv_msg_block_vars.iv_ReservedF9 = 0;

            FAPI_TRY(mss::attr::get_ddr5_rtt_park_rd(iv_dimm, iv_msg_block_vars.iv_RD_RTT_PARK_attr));
            FAPI_TRY(mss::attr::get_ddr5_rtt_park_wr(iv_dimm, iv_msg_block_vars.iv_WR_RTT_PARK_attr));

            // Swizzle DRAM index from port rank to phy rank
            for (const auto& l_rank_info : iv_rank_infos)
            {
                const auto l_port_rank = l_rank_info.get_port_rank();
                const auto l_phy_rank = l_rank_info.get_phy_rank();

                iv_msg_block_vars.iv_RD_RTT_PARK[l_phy_rank] = iv_msg_block_vars.iv_RD_RTT_PARK_attr[l_port_rank];
                iv_msg_block_vars.iv_WR_RTT_PARK[l_phy_rank] = iv_msg_block_vars.iv_WR_RTT_PARK_attr[l_port_rank];
            }

            FAPI_TRY(mss::attr::get_ca_dfe_train_options(i_target, iv_msg_block_vars.iv_Reserved1E2));
            // Reserved fields are always zero for Odyssey
            iv_msg_block_vars.iv_Reserved1E3 = 0;
            FAPI_TRY(mss::attr::get_debug_train_options(i_target, iv_msg_block_vars.iv_Reserved1E4));
            // Reserved fields are always zero for Odyssey
            iv_msg_block_vars.iv_Reserved1E5 = 0;
            iv_msg_block_vars.iv_Reserved1E6 = 0;
            iv_msg_block_vars.iv_Reserved1E7 = 0;
            FAPI_TRY(mss::attr::get_ddr5_wl_adj_start(i_target, iv_msg_block_vars.iv_WL_ADJ_START));
            FAPI_TRY(mss::attr::get_ddr5_wl_adj_end(i_target, iv_msg_block_vars.iv_WL_ADJ_END));

            // TODO: Zen:MST-1732 Fill in RCW fields in ody_draminit message block from attributes

        fapi_try_exit:
            o_rc = fapi2::current_err;
        }

        ///
        /// @brief Constructor
        ///
        /// @brief Set params as per the value initialized (useful for testing)
        /// @param[in] i_target the fapi2 target
        /// @param[in] i_phy_param_attrs explorer specific data structure
        /// @param[in] i_rank_info rank information
        ///
        msg_block_params(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                         const msg_block_vars& i_msg_block_vars,
                         const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>> i_rank_infos):
            iv_target(i_target), iv_msg_block_vars(i_msg_block_vars), iv_rank_infos(i_rank_infos)
        {}

        ///
        /// @brief default copy assignment operator
        ///
        msg_block_params& operator= (const msg_block_params&) = default;

        ///
        /// @brief default copy constructor
        ///
        msg_block_params(const msg_block_params&) = default;

        ///
        /// @brief default move assignment operator
        ///
        msg_block_params& operator= (msg_block_params&&) = default;

        ///
        /// @brief default move constructor
        ///
        msg_block_params(msg_block_params&&) = default;

        ///
        /// @brief default dtor
        ///
        ~msg_block_params() = default;

        ///
        /// @brief msg_block_params structure setup for parameter AdvTrainOpt
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_AdvTrainOpt(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.AdvTrainOpt = iv_msg_block_vars.iv_AdvTrainOpt;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter MsgMisc
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MsgMisc(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MsgMisc = iv_msg_block_vars.iv_MsgMisc;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter Pstate
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_Pstate(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.Pstate = iv_msg_block_vars.iv_Pstate;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter PllBypassEn
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_PllBypassEn(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.PllBypassEn = iv_msg_block_vars.iv_PllBypassEn;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter DRAMFreq
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_DRAMFreq(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.DRAMFreq = static_cast<uint16_t>(iv_msg_block_vars.iv_DRAMFreq);

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter RCW05_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_RCW05_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.RCW05_next = iv_msg_block_vars.iv_RCW05_next;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter RCW06_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_RCW06_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.RCW06_next = iv_msg_block_vars.iv_RCW06_next;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter RXEN_ADJ
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_RXEN_ADJ(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.RXEN_ADJ = iv_msg_block_vars.iv_RXEN_ADJ;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter RX2D_DFE_Misc
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_RX2D_DFE_Misc(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.RX2D_DFE_Misc = iv_msg_block_vars.iv_RX2D_DFE_Misc;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter PhyVref
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_PhyVref(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.PhyVref = iv_msg_block_vars.iv_PhyVref;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter D5Misc
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_D5Misc(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.D5Misc = iv_msg_block_vars.iv_D5Misc;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter WL_ADJ
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_WL_ADJ(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.WL_ADJ = iv_msg_block_vars.iv_WL_ADJ;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter SequenceCtrl
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_SequenceCtrl(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            constexpr uint8_t RCD_CSCA = 1;

            fapi2::buffer<uint16_t> l_buffer(iv_msg_block_vars.iv_SequenceCtrl);
            bool l_has_rcd = false;
            FAPI_TRY(mss::has_rcd(iv_target, l_has_rcd));

            // Make sure Run RCD_CSCA is disabled for UDIMM
            if (!l_has_rcd)
            {
                l_buffer.clearBit<RCD_CSCA>();
            }

            io_msg_block.SequenceCtrl = l_buffer;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameter HdtCtrl
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_HdtCtrl(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.HdtCtrl = iv_msg_block_vars.iv_HdtCtrl;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter PhyCfg
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_PhyCfg(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // Note: naming fields after Synopsys's structure spec, and they count bits from right to left
            constexpr uint8_t RFU7 = 0;

            fapi2::buffer<uint8_t> l_buffer(iv_msg_block_vars.iv_PhyCfg);

            // Force PhyCfg[7] to be false
            l_buffer.clearBit<RFU7>();

            io_msg_block.PhyCfg = l_buffer;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter DFIMRLMargin
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_DFIMRLMargin(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.DFIMRLMargin = iv_msg_block_vars.iv_DFIMRLMargin;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter X16Present
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_X16Present(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.X16Present = iv_msg_block_vars.iv_X16Present;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter UseBroadcastMR
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_UseBroadcastMR(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.UseBroadcastMR = iv_msg_block_vars.iv_UseBroadcastMR;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter D5Quickboot
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_D5Quickboot(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.D5Quickboot = iv_msg_block_vars.iv_D5Quickboot;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter DisabledDbyte
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_DisabledDbyte(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.DisabledDbyte = iv_msg_block_vars.iv_DisabledDbyte;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter CATrainOpt
        /// @param[in] i_sim value of ATTR_IS_SIMULATION
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_CATrainOpt(const uint8_t i_sim,
                                           PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // Note: naming fields after Synopsys's structure spec, and they count bits from right to left
            constexpr uint8_t RFU6 = 1;
            constexpr uint8_t CS_2D_TRAINING = 2;
            constexpr uint8_t CSCA_TRAINING_STEP_SIZE = 4;
            constexpr uint8_t CSCA_TRAINING_STEP_SIZE_LEN = 2;
            constexpr uint8_t CA_DFE_TRAINING = 6;
            constexpr uint8_t CA_2D_TRAINING = 7;

            fapi2::buffer<uint8_t> l_buffer(iv_msg_block_vars.iv_CATrainOpt);

            bool l_has_rcd = false;

            FAPI_TRY(mss::has_rcd(iv_target, l_has_rcd));

            // Make sure RDIMM-only training options are disabled for UDIMM
            if (!l_has_rcd)
            {
                l_buffer.clearBit<CS_2D_TRAINING>()
                .clearBit<CA_DFE_TRAINING>()
                .clearBit<CA_2D_TRAINING>();
            }

            // Set max step size for CS and CA training for sim
            if (i_sim)
            {
                l_buffer.setBit<CSCA_TRAINING_STEP_SIZE, CSCA_TRAINING_STEP_SIZE_LEN>();
            }

            // Disable the reserved bit
            l_buffer.clearBit<RFU6>();

            // TODO Zen:MST-1771 Override bit 3 (Skip CA13 during CA training) if needed

            io_msg_block.CATrainOpt = l_buffer;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameter TX2D_DFE_Misc
        /// @param[in] i_sim value of ATTR_IS_SIMULATION
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_TX2D_DFE_Misc(const uint8_t i_sim,
                                              PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            constexpr uint8_t DSTEP_SIZE_X = 0;
            constexpr uint8_t DSTEP_SIZE_X_LEN = 2;
            constexpr uint8_t VSTEP_SIZE_X = 2;
            constexpr uint8_t VSTEP_SIZE_X_LEN = 2;
            constexpr uint8_t TAP_BIAS_STEP = 4;
            constexpr uint8_t TAP_BIAS_STEP_LEN = 2;
            constexpr uint8_t NB_TAP_M1 = 6;
            constexpr uint8_t NB_TAP_M1_LEN = 2;

            fapi2::buffer<uint8_t> l_buffer(iv_msg_block_vars.iv_TX2D_DFE_Misc);

            // Set min NbTAP to train for sim
            // Set max step size for voltage and delay training for sim
            if (i_sim)
            {
                l_buffer.clearBit<NB_TAP_M1, NB_TAP_M1_LEN>()
                .setBit<TAP_BIAS_STEP, TAP_BIAS_STEP_LEN>()
                .setBit<DSTEP_SIZE_X, DSTEP_SIZE_X_LEN>()
                .setBit<VSTEP_SIZE_X, VSTEP_SIZE_X_LEN>();
            }

            io_msg_block.TX2D_DFE_Misc = l_buffer;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameter RX2D_TrainOpt
        /// @param[in] i_sim value of ATTR_IS_SIMULATION
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_RX2D_TrainOpt(const uint8_t i_sim,
                                              PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // Note: naming fields after Synopsys's structure spec, and they count bits from right to left
            constexpr uint8_t RFU7 = 0;
            constexpr uint8_t DELAY_STEP_SIZE = 3;
            constexpr uint8_t DELAY_STEP_SIZE_LEN = 2;
            constexpr uint8_t VOLTAGE_STEP_SIZE = 5;
            constexpr uint8_t VOLTAGE_STEP_SIZE_LEN = 2;
            constexpr uint8_t RX2D_DFE = 7;

            fapi2::buffer<uint8_t> l_buffer(iv_msg_block_vars.iv_RX2D_TrainOpt);

            // Set min NbTAP to train for sim
            // Set max step size for voltage and delay training for sim
            if (i_sim)
            {
                l_buffer.clearBit<RX2D_DFE>()
                .setBit<DELAY_STEP_SIZE, DELAY_STEP_SIZE_LEN>()
                .setBit<VOLTAGE_STEP_SIZE, VOLTAGE_STEP_SIZE_LEN>();
            }

            // Disable the reserved bit
            l_buffer.clearBit<RFU7>();

            io_msg_block.RX2D_TrainOpt = l_buffer;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameter TX2D_TrainOpt
        /// @param[in] i_sim value of ATTR_IS_SIMULATION
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_TX2D_TrainOpt(const uint8_t i_sim,
                                              PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // Note: naming fields after Synopsys's structure spec, and they count bits from right to left
            constexpr uint8_t RFU7 = 0;
            constexpr uint8_t DELAY_STEP_SIZE = 3;
            constexpr uint8_t DELAY_STEP_SIZE_LEN = 2;
            constexpr uint8_t VOLTAGE_STEP_SIZE = 5;
            constexpr uint8_t VOLTAGE_STEP_SIZE_LEN = 2;
            constexpr uint8_t TX2D_DFE = 7;

            fapi2::buffer<uint8_t> l_buffer(iv_msg_block_vars.iv_TX2D_TrainOpt);

            // Set min NbTAP to train for sim
            // Set max step size for voltage and delay training for sim
            if (i_sim)
            {
                l_buffer.clearBit<TX2D_DFE>()
                .setBit<DELAY_STEP_SIZE, DELAY_STEP_SIZE_LEN>()
                .setBit<VOLTAGE_STEP_SIZE, VOLTAGE_STEP_SIZE_LEN>();
            }

            // Disable the reserved bit
            l_buffer.clearBit<RFU7>();

            io_msg_block.TX2D_TrainOpt = l_buffer;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameter Share2DVrefResult
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_Share2DVrefResult(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.Share2DVrefResult = iv_msg_block_vars.iv_Share2DVrefResult;

        fapi_try_exit:
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter MRE_MIN_PULSE
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MRE_MIN_PULSE(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MRE_MIN_PULSE = iv_msg_block_vars.iv_MRE_MIN_PULSE;

        fapi_try_exit:
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter DWL_MIN_PULSE
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_DWL_MIN_PULSE(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.DWL_MIN_PULSE = iv_msg_block_vars.iv_DWL_MIN_PULSE;

        fapi_try_exit:
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter PhyConfigOverride
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_PhyConfigOverride(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.PhyConfigOverride = iv_msg_block_vars.iv_PhyConfigOverride;

        fapi_try_exit:
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter EnabledDQsChA
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_EnabledDQsChA(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.EnabledDQsChA = iv_msg_block_vars.iv_EnabledDQsChA;

        fapi_try_exit:
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter EnabledDQsChB
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_EnabledDQsChB(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.EnabledDQsChB = iv_msg_block_vars.iv_EnabledDQsChB;

        fapi_try_exit:
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter CsPresentChA
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_CsPresentChA(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            fapi2::buffer<uint8_t> l_ranks_configed_buf(iv_msg_block_vars.iv_CsPresentChA[0]);

            l_ranks_configed_buf.reverse();

            io_msg_block.CsPresentChA = l_ranks_configed_buf;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameter CsPresentChB
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_CsPresentChB(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            fapi2::buffer<uint8_t> l_ranks_configed_buf(iv_msg_block_vars.iv_CsPresentChB[0]);

            l_ranks_configed_buf.reverse();

            io_msg_block.CsPresentChB = l_ranks_configed_buf;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR0_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR0(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR0_A0 = iv_msg_block_vars.iv_MR0[0];
            io_msg_block.MR0_A1 = iv_msg_block_vars.iv_MR0[1];
            io_msg_block.MR0_A2 = iv_msg_block_vars.iv_MR0[2];
            io_msg_block.MR0_A3 = iv_msg_block_vars.iv_MR0[3];
            io_msg_block.MR0_B0 = iv_msg_block_vars.iv_MR0[0];
            io_msg_block.MR0_B1 = iv_msg_block_vars.iv_MR0[1];
            io_msg_block.MR0_B2 = iv_msg_block_vars.iv_MR0[2];
            io_msg_block.MR0_B3 = iv_msg_block_vars.iv_MR0[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR2_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR2(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR2_A0 = iv_msg_block_vars.iv_MR2[0];
            io_msg_block.MR2_A1 = iv_msg_block_vars.iv_MR2[1];
            io_msg_block.MR2_A2 = iv_msg_block_vars.iv_MR2[2];
            io_msg_block.MR2_A3 = iv_msg_block_vars.iv_MR2[3];
            io_msg_block.MR2_B0 = iv_msg_block_vars.iv_MR2[0];
            io_msg_block.MR2_B1 = iv_msg_block_vars.iv_MR2[1];
            io_msg_block.MR2_B2 = iv_msg_block_vars.iv_MR2[2];
            io_msg_block.MR2_B3 = iv_msg_block_vars.iv_MR2[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR3_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR3(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR3_A0 = iv_msg_block_vars.iv_MR3[0][0];
            io_msg_block.MR3_A1 = iv_msg_block_vars.iv_MR3[1][0];
            io_msg_block.MR3_A2 = iv_msg_block_vars.iv_MR3[2][0];
            io_msg_block.MR3_A3 = iv_msg_block_vars.iv_MR3[3][0];
            io_msg_block.MR3_B0 = iv_msg_block_vars.iv_MR3[0][0];
            io_msg_block.MR3_B1 = iv_msg_block_vars.iv_MR3[1][0];
            io_msg_block.MR3_B2 = iv_msg_block_vars.iv_MR3[2][0];
            io_msg_block.MR3_B3 = iv_msg_block_vars.iv_MR3[3][0];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR4_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR4(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR4_A0 = iv_msg_block_vars.iv_MR4[0];
            io_msg_block.MR4_A1 = iv_msg_block_vars.iv_MR4[1];
            io_msg_block.MR4_A2 = iv_msg_block_vars.iv_MR4[2];
            io_msg_block.MR4_A3 = iv_msg_block_vars.iv_MR4[3];
            io_msg_block.MR4_B0 = iv_msg_block_vars.iv_MR4[0];
            io_msg_block.MR4_B1 = iv_msg_block_vars.iv_MR4[1];
            io_msg_block.MR4_B2 = iv_msg_block_vars.iv_MR4[2];
            io_msg_block.MR4_B3 = iv_msg_block_vars.iv_MR4[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR5_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR5(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR5_A0 = iv_msg_block_vars.iv_MR5[0];
            io_msg_block.MR5_A1 = iv_msg_block_vars.iv_MR5[1];
            io_msg_block.MR5_A2 = iv_msg_block_vars.iv_MR5[2];
            io_msg_block.MR5_A3 = iv_msg_block_vars.iv_MR5[3];
            io_msg_block.MR5_B0 = iv_msg_block_vars.iv_MR5[0];
            io_msg_block.MR5_B1 = iv_msg_block_vars.iv_MR5[1];
            io_msg_block.MR5_B2 = iv_msg_block_vars.iv_MR5[2];
            io_msg_block.MR5_B3 = iv_msg_block_vars.iv_MR5[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR6_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR6(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR6_A0 = iv_msg_block_vars.iv_MR6[0];
            io_msg_block.MR6_A1 = iv_msg_block_vars.iv_MR6[1];
            io_msg_block.MR6_A2 = iv_msg_block_vars.iv_MR6[2];
            io_msg_block.MR6_A3 = iv_msg_block_vars.iv_MR6[3];
            io_msg_block.MR6_B0 = iv_msg_block_vars.iv_MR6[0];
            io_msg_block.MR6_B1 = iv_msg_block_vars.iv_MR6[1];
            io_msg_block.MR6_B2 = iv_msg_block_vars.iv_MR6[2];
            io_msg_block.MR6_B3 = iv_msg_block_vars.iv_MR6[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR32_A/B[RANK]_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR32_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // TODO Zen:MST-1770 Set *_next fields differently if needed
            io_msg_block.MR32_A0_next = iv_msg_block_vars.iv_MR32[0];
            io_msg_block.MR32_A1_next = iv_msg_block_vars.iv_MR32[1];
            io_msg_block.MR32_A2_next = iv_msg_block_vars.iv_MR32[2];
            io_msg_block.MR32_A3_next = iv_msg_block_vars.iv_MR32[3];
            io_msg_block.MR32_B0_next = iv_msg_block_vars.iv_MR32[0];
            io_msg_block.MR32_B1_next = iv_msg_block_vars.iv_MR32[1];
            io_msg_block.MR32_B2_next = iv_msg_block_vars.iv_MR32[2];
            io_msg_block.MR32_B3_next = iv_msg_block_vars.iv_MR32[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR8_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR8(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR8_A0 = iv_msg_block_vars.iv_MR8[0];
            io_msg_block.MR8_A1 = iv_msg_block_vars.iv_MR8[1];
            io_msg_block.MR8_A2 = iv_msg_block_vars.iv_MR8[2];
            io_msg_block.MR8_A3 = iv_msg_block_vars.iv_MR8[3];
            io_msg_block.MR8_B0 = iv_msg_block_vars.iv_MR8[0];
            io_msg_block.MR8_B1 = iv_msg_block_vars.iv_MR8[1];
            io_msg_block.MR8_B2 = iv_msg_block_vars.iv_MR8[2];
            io_msg_block.MR8_B3 = iv_msg_block_vars.iv_MR8[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR32_ORG_A/B[RANK]_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR32_ORG_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // TODO Zen:MST-1770 Set *_next fields differently if needed
            io_msg_block.MR32_ORG_A0_next = iv_msg_block_vars.iv_MR32_ORG[0];
            io_msg_block.MR32_ORG_A1_next = iv_msg_block_vars.iv_MR32_ORG[1];
            io_msg_block.MR32_ORG_A2_next = iv_msg_block_vars.iv_MR32_ORG[2];
            io_msg_block.MR32_ORG_A3_next = iv_msg_block_vars.iv_MR32_ORG[3];
            io_msg_block.MR32_ORG_B0_next = iv_msg_block_vars.iv_MR32_ORG[0];
            io_msg_block.MR32_ORG_B1_next = iv_msg_block_vars.iv_MR32_ORG[1];
            io_msg_block.MR32_ORG_B2_next = iv_msg_block_vars.iv_MR32_ORG[2];
            io_msg_block.MR32_ORG_B3_next = iv_msg_block_vars.iv_MR32_ORG[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR10_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR10(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR10_A0 = iv_msg_block_vars.iv_MR10[0][0];
            io_msg_block.MR10_A1 = iv_msg_block_vars.iv_MR10[1][0];
            io_msg_block.MR10_A2 = iv_msg_block_vars.iv_MR10[2][0];
            io_msg_block.MR10_A3 = iv_msg_block_vars.iv_MR10[3][0];
            io_msg_block.MR10_B0 = iv_msg_block_vars.iv_MR10[0][0];
            io_msg_block.MR10_B1 = iv_msg_block_vars.iv_MR10[1][0];
            io_msg_block.MR10_B2 = iv_msg_block_vars.iv_MR10[2][0];
            io_msg_block.MR10_B3 = iv_msg_block_vars.iv_MR10[3][0];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR11_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR11(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR11_A0 = iv_msg_block_vars.iv_MR11[0][0];
            io_msg_block.MR11_A1 = iv_msg_block_vars.iv_MR11[1][0];
            io_msg_block.MR11_A2 = iv_msg_block_vars.iv_MR11[2][0];
            io_msg_block.MR11_A3 = iv_msg_block_vars.iv_MR11[3][0];
            io_msg_block.MR11_B0 = iv_msg_block_vars.iv_MR11[0][0];
            io_msg_block.MR11_B1 = iv_msg_block_vars.iv_MR11[1][0];
            io_msg_block.MR11_B2 = iv_msg_block_vars.iv_MR11[2][0];
            io_msg_block.MR11_B3 = iv_msg_block_vars.iv_MR11[3][0];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR12_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR12(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR12_A0 = iv_msg_block_vars.iv_MR12[0][0];
            io_msg_block.MR12_A1 = iv_msg_block_vars.iv_MR12[1][0];
            io_msg_block.MR12_A2 = iv_msg_block_vars.iv_MR12[2][0];
            io_msg_block.MR12_A3 = iv_msg_block_vars.iv_MR12[3][0];
            io_msg_block.MR12_B0 = iv_msg_block_vars.iv_MR12[0][0];
            io_msg_block.MR12_B1 = iv_msg_block_vars.iv_MR12[1][0];
            io_msg_block.MR12_B2 = iv_msg_block_vars.iv_MR12[2][0];
            io_msg_block.MR12_B3 = iv_msg_block_vars.iv_MR12[3][0];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR13_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR13(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR13_A0 = iv_msg_block_vars.iv_MR13[0];
            io_msg_block.MR13_A1 = iv_msg_block_vars.iv_MR13[1];
            io_msg_block.MR13_A2 = iv_msg_block_vars.iv_MR13[2];
            io_msg_block.MR13_A3 = iv_msg_block_vars.iv_MR13[3];
            io_msg_block.MR13_B0 = iv_msg_block_vars.iv_MR13[0];
            io_msg_block.MR13_B1 = iv_msg_block_vars.iv_MR13[1];
            io_msg_block.MR13_B2 = iv_msg_block_vars.iv_MR13[2];
            io_msg_block.MR13_B3 = iv_msg_block_vars.iv_MR13[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR14_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR14(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR14_A0 = iv_msg_block_vars.iv_MR14[0];
            io_msg_block.MR14_A1 = iv_msg_block_vars.iv_MR14[1];
            io_msg_block.MR14_A2 = iv_msg_block_vars.iv_MR14[2];
            io_msg_block.MR14_A3 = iv_msg_block_vars.iv_MR14[3];
            io_msg_block.MR14_B0 = iv_msg_block_vars.iv_MR14[0];
            io_msg_block.MR14_B1 = iv_msg_block_vars.iv_MR14[1];
            io_msg_block.MR14_B2 = iv_msg_block_vars.iv_MR14[2];
            io_msg_block.MR14_B3 = iv_msg_block_vars.iv_MR14[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR15_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR15(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR15_A0 = iv_msg_block_vars.iv_MR15[0];
            io_msg_block.MR15_A1 = iv_msg_block_vars.iv_MR15[1];
            io_msg_block.MR15_A2 = iv_msg_block_vars.iv_MR15[2];
            io_msg_block.MR15_A3 = iv_msg_block_vars.iv_MR15[3];
            io_msg_block.MR15_B0 = iv_msg_block_vars.iv_MR15[0];
            io_msg_block.MR15_B1 = iv_msg_block_vars.iv_MR15[1];
            io_msg_block.MR15_B2 = iv_msg_block_vars.iv_MR15[2];
            io_msg_block.MR15_B3 = iv_msg_block_vars.iv_MR15[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR111_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR111(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR111_A0 = iv_msg_block_vars.iv_MR111[0];
            io_msg_block.MR111_A1 = iv_msg_block_vars.iv_MR111[1];
            io_msg_block.MR111_A2 = iv_msg_block_vars.iv_MR111[2];
            io_msg_block.MR111_A3 = iv_msg_block_vars.iv_MR111[3];
            io_msg_block.MR111_B0 = iv_msg_block_vars.iv_MR111[0];
            io_msg_block.MR111_B1 = iv_msg_block_vars.iv_MR111[1];
            io_msg_block.MR111_B2 = iv_msg_block_vars.iv_MR111[2];
            io_msg_block.MR111_B3 = iv_msg_block_vars.iv_MR111[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR32_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR32(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR32_A0 = iv_msg_block_vars.iv_MR32[0];
            io_msg_block.MR32_A1 = iv_msg_block_vars.iv_MR32[1];
            io_msg_block.MR32_A2 = iv_msg_block_vars.iv_MR32[2];
            io_msg_block.MR32_A3 = iv_msg_block_vars.iv_MR32[3];
            io_msg_block.MR32_B0 = iv_msg_block_vars.iv_MR32[0];
            io_msg_block.MR32_B1 = iv_msg_block_vars.iv_MR32[1];
            io_msg_block.MR32_B2 = iv_msg_block_vars.iv_MR32[2];
            io_msg_block.MR32_B3 = iv_msg_block_vars.iv_MR32[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR33_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR33(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR33_A0 = iv_msg_block_vars.iv_MR33[0];
            io_msg_block.MR33_A1 = iv_msg_block_vars.iv_MR33[1];
            io_msg_block.MR33_A2 = iv_msg_block_vars.iv_MR33[2];
            io_msg_block.MR33_A3 = iv_msg_block_vars.iv_MR33[3];
            io_msg_block.MR33_B0 = iv_msg_block_vars.iv_MR33[0];
            io_msg_block.MR33_B1 = iv_msg_block_vars.iv_MR33[1];
            io_msg_block.MR33_B2 = iv_msg_block_vars.iv_MR33[2];
            io_msg_block.MR33_B3 = iv_msg_block_vars.iv_MR33[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR34_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR34(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR34_A0 = iv_msg_block_vars.iv_MR34[0];
            io_msg_block.MR34_A1 = iv_msg_block_vars.iv_MR34[1];
            io_msg_block.MR34_A2 = iv_msg_block_vars.iv_MR34[2];
            io_msg_block.MR34_A3 = iv_msg_block_vars.iv_MR34[3];
            io_msg_block.MR34_B0 = iv_msg_block_vars.iv_MR34[0];
            io_msg_block.MR34_B1 = iv_msg_block_vars.iv_MR34[1];
            io_msg_block.MR34_B2 = iv_msg_block_vars.iv_MR34[2];
            io_msg_block.MR34_B3 = iv_msg_block_vars.iv_MR34[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR35_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR35(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR35_A0 = iv_msg_block_vars.iv_MR35[0];
            io_msg_block.MR35_A1 = iv_msg_block_vars.iv_MR35[1];
            io_msg_block.MR35_A2 = iv_msg_block_vars.iv_MR35[2];
            io_msg_block.MR35_A3 = iv_msg_block_vars.iv_MR35[3];
            io_msg_block.MR35_B0 = iv_msg_block_vars.iv_MR35[0];
            io_msg_block.MR35_B1 = iv_msg_block_vars.iv_MR35[1];
            io_msg_block.MR35_B2 = iv_msg_block_vars.iv_MR35[2];
            io_msg_block.MR35_B3 = iv_msg_block_vars.iv_MR35[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR32_ORG_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR32_ORG(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR32_ORG_A0 = iv_msg_block_vars.iv_MR32_ORG[0];
            io_msg_block.MR32_ORG_A1 = iv_msg_block_vars.iv_MR32_ORG[1];
            io_msg_block.MR32_ORG_A2 = iv_msg_block_vars.iv_MR32_ORG[2];
            io_msg_block.MR32_ORG_A3 = iv_msg_block_vars.iv_MR32_ORG[3];
            io_msg_block.MR32_ORG_B0 = iv_msg_block_vars.iv_MR32_ORG[0];
            io_msg_block.MR32_ORG_B1 = iv_msg_block_vars.iv_MR32_ORG[1];
            io_msg_block.MR32_ORG_B2 = iv_msg_block_vars.iv_MR32_ORG[2];
            io_msg_block.MR32_ORG_B3 = iv_msg_block_vars.iv_MR32_ORG[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR37_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR37(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR37_A0 = iv_msg_block_vars.iv_MR37[0];
            io_msg_block.MR37_A1 = iv_msg_block_vars.iv_MR37[1];
            io_msg_block.MR37_A2 = iv_msg_block_vars.iv_MR37[2];
            io_msg_block.MR37_A3 = iv_msg_block_vars.iv_MR37[3];
            io_msg_block.MR37_B0 = iv_msg_block_vars.iv_MR37[0];
            io_msg_block.MR37_B1 = iv_msg_block_vars.iv_MR37[1];
            io_msg_block.MR37_B2 = iv_msg_block_vars.iv_MR37[2];
            io_msg_block.MR37_B3 = iv_msg_block_vars.iv_MR37[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR38_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR38(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR38_A0 = iv_msg_block_vars.iv_MR38[0];
            io_msg_block.MR38_A1 = iv_msg_block_vars.iv_MR38[1];
            io_msg_block.MR38_A2 = iv_msg_block_vars.iv_MR38[2];
            io_msg_block.MR38_A3 = iv_msg_block_vars.iv_MR38[3];
            io_msg_block.MR38_B0 = iv_msg_block_vars.iv_MR38[0];
            io_msg_block.MR38_B1 = iv_msg_block_vars.iv_MR38[1];
            io_msg_block.MR38_B2 = iv_msg_block_vars.iv_MR38[2];
            io_msg_block.MR38_B3 = iv_msg_block_vars.iv_MR38[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR39_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR39(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR39_A0 = iv_msg_block_vars.iv_MR39[0];
            io_msg_block.MR39_A1 = iv_msg_block_vars.iv_MR39[1];
            io_msg_block.MR39_A2 = iv_msg_block_vars.iv_MR39[2];
            io_msg_block.MR39_A3 = iv_msg_block_vars.iv_MR39[3];
            io_msg_block.MR39_B0 = iv_msg_block_vars.iv_MR39[0];
            io_msg_block.MR39_B1 = iv_msg_block_vars.iv_MR39[1];
            io_msg_block.MR39_B2 = iv_msg_block_vars.iv_MR39[2];
            io_msg_block.MR39_B3 = iv_msg_block_vars.iv_MR39[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR33_ORG_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR33_ORG(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR33_ORG_A0 = iv_msg_block_vars.iv_MR33_ORG[0];
            io_msg_block.MR33_ORG_A1 = iv_msg_block_vars.iv_MR33_ORG[1];
            io_msg_block.MR33_ORG_A2 = iv_msg_block_vars.iv_MR33_ORG[2];
            io_msg_block.MR33_ORG_A3 = iv_msg_block_vars.iv_MR33_ORG[3];
            io_msg_block.MR33_ORG_B0 = iv_msg_block_vars.iv_MR33_ORG[0];
            io_msg_block.MR33_ORG_B1 = iv_msg_block_vars.iv_MR33_ORG[1];
            io_msg_block.MR33_ORG_B2 = iv_msg_block_vars.iv_MR33_ORG[2];
            io_msg_block.MR33_ORG_B3 = iv_msg_block_vars.iv_MR33_ORG[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR11_A/B[RANK]_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR11_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // TODO Zen:MST-1770 Set *_next fields differently if needed
            io_msg_block.MR11_A0_next = iv_msg_block_vars.iv_MR11[0][0];
            io_msg_block.MR11_A1_next = iv_msg_block_vars.iv_MR11[1][0];
            io_msg_block.MR11_A2_next = iv_msg_block_vars.iv_MR11[2][0];
            io_msg_block.MR11_A3_next = iv_msg_block_vars.iv_MR11[3][0];
            io_msg_block.MR11_B0_next = iv_msg_block_vars.iv_MR11[0][0];
            io_msg_block.MR11_B1_next = iv_msg_block_vars.iv_MR11[1][0];
            io_msg_block.MR11_B2_next = iv_msg_block_vars.iv_MR11[2][0];
            io_msg_block.MR11_B3_next = iv_msg_block_vars.iv_MR11[3][0];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR12_A/B[RANK]_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR12_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // TODO Zen:MST-1770 Set *_next fields differently if needed
            io_msg_block.MR12_A0_next = iv_msg_block_vars.iv_MR12[0][0];
            io_msg_block.MR12_A1_next = iv_msg_block_vars.iv_MR12[1][0];
            io_msg_block.MR12_A2_next = iv_msg_block_vars.iv_MR12[2][0];
            io_msg_block.MR12_A3_next = iv_msg_block_vars.iv_MR12[3][0];
            io_msg_block.MR12_B0_next = iv_msg_block_vars.iv_MR12[0][0];
            io_msg_block.MR12_B1_next = iv_msg_block_vars.iv_MR12[1][0];
            io_msg_block.MR12_B2_next = iv_msg_block_vars.iv_MR12[2][0];
            io_msg_block.MR12_B3_next = iv_msg_block_vars.iv_MR12[3][0];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR13_A/B[RANK]_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR13_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // TODO Zen:MST-1770 Set *_next fields differently if needed
            io_msg_block.MR13_A0_next = iv_msg_block_vars.iv_MR13[0];
            io_msg_block.MR13_A1_next = iv_msg_block_vars.iv_MR13[1];
            io_msg_block.MR13_A2_next = iv_msg_block_vars.iv_MR13[2];
            io_msg_block.MR13_A3_next = iv_msg_block_vars.iv_MR13[3];
            io_msg_block.MR13_B0_next = iv_msg_block_vars.iv_MR13[0];
            io_msg_block.MR13_B1_next = iv_msg_block_vars.iv_MR13[1];
            io_msg_block.MR13_B2_next = iv_msg_block_vars.iv_MR13[2];
            io_msg_block.MR13_B3_next = iv_msg_block_vars.iv_MR13[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR33_ORG_A/B[RANK]_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR33_ORG_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // TODO Zen:MST-1770 Set *_next fields differently if needed
            io_msg_block.MR33_ORG_A0_next = iv_msg_block_vars.iv_MR33_ORG[0];
            io_msg_block.MR33_ORG_A1_next = iv_msg_block_vars.iv_MR33_ORG[1];
            io_msg_block.MR33_ORG_A2_next = iv_msg_block_vars.iv_MR33_ORG[2];
            io_msg_block.MR33_ORG_A3_next = iv_msg_block_vars.iv_MR33_ORG[3];
            io_msg_block.MR33_ORG_B0_next = iv_msg_block_vars.iv_MR33_ORG[0];
            io_msg_block.MR33_ORG_B1_next = iv_msg_block_vars.iv_MR33_ORG[1];
            io_msg_block.MR33_ORG_B2_next = iv_msg_block_vars.iv_MR33_ORG[2];
            io_msg_block.MR33_ORG_B3_next = iv_msg_block_vars.iv_MR33_ORG[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR33_A/B[RANK]_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR33_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // TODO Zen:MST-1770 Set *_next fields differently if needed
            io_msg_block.MR33_A0_next = iv_msg_block_vars.iv_MR33[0];
            io_msg_block.MR33_A1_next = iv_msg_block_vars.iv_MR33[1];
            io_msg_block.MR33_A2_next = iv_msg_block_vars.iv_MR33[2];
            io_msg_block.MR33_A3_next = iv_msg_block_vars.iv_MR33[3];
            io_msg_block.MR33_B0_next = iv_msg_block_vars.iv_MR33[0];
            io_msg_block.MR33_B1_next = iv_msg_block_vars.iv_MR33[1];
            io_msg_block.MR33_B2_next = iv_msg_block_vars.iv_MR33[2];
            io_msg_block.MR33_B3_next = iv_msg_block_vars.iv_MR33[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR50_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR50(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR50_A0 = iv_msg_block_vars.iv_MR50[0];
            io_msg_block.MR50_A1 = iv_msg_block_vars.iv_MR50[1];
            io_msg_block.MR50_A2 = iv_msg_block_vars.iv_MR50[2];
            io_msg_block.MR50_A3 = iv_msg_block_vars.iv_MR50[3];
            io_msg_block.MR50_B0 = iv_msg_block_vars.iv_MR50[0];
            io_msg_block.MR50_B1 = iv_msg_block_vars.iv_MR50[1];
            io_msg_block.MR50_B2 = iv_msg_block_vars.iv_MR50[2];
            io_msg_block.MR50_B3 = iv_msg_block_vars.iv_MR50[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR51_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR51(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR51_A0 = iv_msg_block_vars.iv_MR51[0];
            io_msg_block.MR51_A1 = iv_msg_block_vars.iv_MR51[1];
            io_msg_block.MR51_A2 = iv_msg_block_vars.iv_MR51[2];
            io_msg_block.MR51_A3 = iv_msg_block_vars.iv_MR51[3];
            io_msg_block.MR51_B0 = iv_msg_block_vars.iv_MR51[0];
            io_msg_block.MR51_B1 = iv_msg_block_vars.iv_MR51[1];
            io_msg_block.MR51_B2 = iv_msg_block_vars.iv_MR51[2];
            io_msg_block.MR51_B3 = iv_msg_block_vars.iv_MR51[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR52_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR52(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR52_A0 = iv_msg_block_vars.iv_MR52[0];
            io_msg_block.MR52_A1 = iv_msg_block_vars.iv_MR52[1];
            io_msg_block.MR52_A2 = iv_msg_block_vars.iv_MR52[2];
            io_msg_block.MR52_A3 = iv_msg_block_vars.iv_MR52[3];
            io_msg_block.MR52_B0 = iv_msg_block_vars.iv_MR52[0];
            io_msg_block.MR52_B1 = iv_msg_block_vars.iv_MR52[1];
            io_msg_block.MR52_B2 = iv_msg_block_vars.iv_MR52[2];
            io_msg_block.MR52_B3 = iv_msg_block_vars.iv_MR52[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameters DFE_GainBias_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_DFE_GainBias(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.DFE_GainBias_A0 = iv_msg_block_vars.iv_DFE_GainBias[0];
            io_msg_block.DFE_GainBias_A1 = iv_msg_block_vars.iv_DFE_GainBias[1];
            io_msg_block.DFE_GainBias_A2 = iv_msg_block_vars.iv_DFE_GainBias[2];
            io_msg_block.DFE_GainBias_A3 = iv_msg_block_vars.iv_DFE_GainBias[3];
            io_msg_block.DFE_GainBias_B0 = iv_msg_block_vars.iv_DFE_GainBias[0];
            io_msg_block.DFE_GainBias_B1 = iv_msg_block_vars.iv_DFE_GainBias[1];
            io_msg_block.DFE_GainBias_B2 = iv_msg_block_vars.iv_DFE_GainBias[2];
            io_msg_block.DFE_GainBias_B3 = iv_msg_block_vars.iv_DFE_GainBias[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameter ReservedF6
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_ReservedF6(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.ReservedF6 = iv_msg_block_vars.iv_ReservedF6;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter ReservedF7
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_ReservedF7(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.ReservedF7 = iv_msg_block_vars.iv_ReservedF7;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter ReservedF8
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_ReservedF8(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.ReservedF8 = iv_msg_block_vars.iv_ReservedF8;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter ReservedF9
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_ReservedF9(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.ReservedF9 = iv_msg_block_vars.iv_ReservedF9;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter BCW04_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_BCW04_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // BCW fields are always zero for Odyssey
            io_msg_block.BCW04_next = 0;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter BCW05_next
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_BCW05_next(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // BCW fields are always zero for Odyssey
            io_msg_block.BCW05_next = 0;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameters WR_RD_RTT_PARK_A/B[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_WR_RD_RTT_PARK(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            constexpr uint8_t RD_SHIFT = 4;

            io_msg_block.WR_RD_RTT_PARK_A0 = (iv_msg_block_vars.iv_RD_RTT_PARK[0] << RD_SHIFT) |
                                             iv_msg_block_vars.iv_WR_RTT_PARK[0];
            io_msg_block.WR_RD_RTT_PARK_A1 = (iv_msg_block_vars.iv_RD_RTT_PARK[1] << RD_SHIFT) |
                                             iv_msg_block_vars.iv_WR_RTT_PARK[1];
            io_msg_block.WR_RD_RTT_PARK_A2 = (iv_msg_block_vars.iv_RD_RTT_PARK[2] << RD_SHIFT) |
                                             iv_msg_block_vars.iv_WR_RTT_PARK[2];
            io_msg_block.WR_RD_RTT_PARK_A3 = (iv_msg_block_vars.iv_RD_RTT_PARK[3] << RD_SHIFT) |
                                             iv_msg_block_vars.iv_WR_RTT_PARK[3];
            io_msg_block.WR_RD_RTT_PARK_B0 = (iv_msg_block_vars.iv_RD_RTT_PARK[0] << RD_SHIFT) |
                                             iv_msg_block_vars.iv_WR_RTT_PARK[0];
            io_msg_block.WR_RD_RTT_PARK_B1 = (iv_msg_block_vars.iv_RD_RTT_PARK[1] << RD_SHIFT) |
                                             iv_msg_block_vars.iv_WR_RTT_PARK[1];
            io_msg_block.WR_RD_RTT_PARK_B2 = (iv_msg_block_vars.iv_RD_RTT_PARK[2] << RD_SHIFT) |
                                             iv_msg_block_vars.iv_WR_RTT_PARK[2];
            io_msg_block.WR_RD_RTT_PARK_B3 = (iv_msg_block_vars.iv_RD_RTT_PARK[3] << RD_SHIFT) |
                                             iv_msg_block_vars.iv_WR_RTT_PARK[3];

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief msg_block_params structure setup for parameter Reserved1E2
        /// @param[in] i_sim value of ATTR_IS_SIMULATION
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_Reserved1E2(const uint8_t i_sim,
                                            PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            constexpr uint8_t BIAS_STEP_SIZE = 4;
            constexpr uint8_t BIAS_STEP_SIZE_LEN = 2;

            fapi2::buffer<uint8_t> l_buffer(iv_msg_block_vars.iv_Reserved1E2);

            // Set max bias step size for sim
            if (i_sim)
            {
                l_buffer.setBit<BIAS_STEP_SIZE, BIAS_STEP_SIZE_LEN>();
            }

            io_msg_block.Reserved1E2 = l_buffer;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter Reserved1E3
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_Reserved1E3(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.Reserved1E3 = iv_msg_block_vars.iv_Reserved1E3;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter Reserved1E4
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_Reserved1E4(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.Reserved1E4 = iv_msg_block_vars.iv_Reserved1E4;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter Reserved1E5
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_Reserved1E5(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.Reserved1E5 = iv_msg_block_vars.iv_Reserved1E5;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter Reserved1E6
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_Reserved1E6(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.Reserved1E6 = iv_msg_block_vars.iv_Reserved1E6;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter Reserved1E7
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_Reserved1E7(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.Reserved1E7 = iv_msg_block_vars.iv_Reserved1E7;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter RCW[N]_CHA/B_D[DIMM]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_RCW(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // TODO: Zen:MST-1732 Fill in RCW fields in ody_draminit message block from attributes
            io_msg_block.RCW00_ChA_D0 = iv_msg_block_vars.iv_RCW[0];
            io_msg_block.RCW01_ChA_D0 = iv_msg_block_vars.iv_RCW[1];
            io_msg_block.RCW02_ChA_D0 = iv_msg_block_vars.iv_RCW[2];
            io_msg_block.RCW03_ChA_D0 = iv_msg_block_vars.iv_RCW[3];
            io_msg_block.RCW04_ChA_D0 = iv_msg_block_vars.iv_RCW[4];
            io_msg_block.RCW05_ChA_D0 = iv_msg_block_vars.iv_RCW[5];
            io_msg_block.RCW06_ChA_D0 = iv_msg_block_vars.iv_RCW[6];
            io_msg_block.RCW07_ChA_D0 = iv_msg_block_vars.iv_RCW[7];
            io_msg_block.RCW08_ChA_D0 = iv_msg_block_vars.iv_RCW[8];
            io_msg_block.RCW09_ChA_D0 = iv_msg_block_vars.iv_RCW[9];
            io_msg_block.RCW0A_ChA_D0 = iv_msg_block_vars.iv_RCW[10];
            io_msg_block.RCW0B_ChA_D0 = iv_msg_block_vars.iv_RCW[11];
            io_msg_block.RCW0C_ChA_D0 = iv_msg_block_vars.iv_RCW[12];
            io_msg_block.RCW0D_ChA_D0 = iv_msg_block_vars.iv_RCW[13];
            io_msg_block.RCW0E_ChA_D0 = iv_msg_block_vars.iv_RCW[14];
            io_msg_block.RCW0F_ChA_D0 = iv_msg_block_vars.iv_RCW[15];
            io_msg_block.RCW10_ChA_D0 = iv_msg_block_vars.iv_RCW[16];
            io_msg_block.RCW11_ChA_D0 = iv_msg_block_vars.iv_RCW[17];
            io_msg_block.RCW12_ChA_D0 = iv_msg_block_vars.iv_RCW[18];
            io_msg_block.RCW13_ChA_D0 = iv_msg_block_vars.iv_RCW[19];
            io_msg_block.RCW14_ChA_D0 = iv_msg_block_vars.iv_RCW[20];
            io_msg_block.RCW15_ChA_D0 = iv_msg_block_vars.iv_RCW[21];
            io_msg_block.RCW16_ChA_D0 = iv_msg_block_vars.iv_RCW[22];
            io_msg_block.RCW17_ChA_D0 = iv_msg_block_vars.iv_RCW[23];
            io_msg_block.RCW18_ChA_D0 = iv_msg_block_vars.iv_RCW[24];
            io_msg_block.RCW19_ChA_D0 = iv_msg_block_vars.iv_RCW[25];
            io_msg_block.RCW1A_ChA_D0 = iv_msg_block_vars.iv_RCW[26];
            io_msg_block.RCW1B_ChA_D0 = iv_msg_block_vars.iv_RCW[27];
            io_msg_block.RCW1C_ChA_D0 = iv_msg_block_vars.iv_RCW[28];
            io_msg_block.RCW1D_ChA_D0 = iv_msg_block_vars.iv_RCW[29];
            io_msg_block.RCW1E_ChA_D0 = iv_msg_block_vars.iv_RCW[30];
            io_msg_block.RCW1F_ChA_D0 = iv_msg_block_vars.iv_RCW[31];
            io_msg_block.RCW20_ChA_D0 = iv_msg_block_vars.iv_RCW[32];
            io_msg_block.RCW21_ChA_D0 = iv_msg_block_vars.iv_RCW[33];
            io_msg_block.RCW22_ChA_D0 = iv_msg_block_vars.iv_RCW[34];
            io_msg_block.RCW23_ChA_D0 = iv_msg_block_vars.iv_RCW[35];
            io_msg_block.RCW24_ChA_D0 = iv_msg_block_vars.iv_RCW[36];
            io_msg_block.RCW25_ChA_D0 = iv_msg_block_vars.iv_RCW[37];
            io_msg_block.RCW26_ChA_D0 = iv_msg_block_vars.iv_RCW[38];
            io_msg_block.RCW27_ChA_D0 = iv_msg_block_vars.iv_RCW[39];
            io_msg_block.RCW28_ChA_D0 = iv_msg_block_vars.iv_RCW[40];
            io_msg_block.RCW29_ChA_D0 = iv_msg_block_vars.iv_RCW[41];
            io_msg_block.RCW2A_ChA_D0 = iv_msg_block_vars.iv_RCW[42];
            io_msg_block.RCW2B_ChA_D0 = iv_msg_block_vars.iv_RCW[43];
            io_msg_block.RCW2C_ChA_D0 = iv_msg_block_vars.iv_RCW[44];
            io_msg_block.RCW2D_ChA_D0 = iv_msg_block_vars.iv_RCW[45];
            io_msg_block.RCW2E_ChA_D0 = iv_msg_block_vars.iv_RCW[46];
            io_msg_block.RCW2F_ChA_D0 = iv_msg_block_vars.iv_RCW[47];
            io_msg_block.RCW30_ChA_D0 = iv_msg_block_vars.iv_RCW[48];
            io_msg_block.RCW31_ChA_D0 = iv_msg_block_vars.iv_RCW[49];
            io_msg_block.RCW32_ChA_D0 = iv_msg_block_vars.iv_RCW[50];
            io_msg_block.RCW33_ChA_D0 = iv_msg_block_vars.iv_RCW[51];
            io_msg_block.RCW34_ChA_D0 = iv_msg_block_vars.iv_RCW[52];
            io_msg_block.RCW35_ChA_D0 = iv_msg_block_vars.iv_RCW[53];
            io_msg_block.RCW36_ChA_D0 = iv_msg_block_vars.iv_RCW[54];
            io_msg_block.RCW37_ChA_D0 = iv_msg_block_vars.iv_RCW[55];
            io_msg_block.RCW38_ChA_D0 = iv_msg_block_vars.iv_RCW[56];
            io_msg_block.RCW39_ChA_D0 = iv_msg_block_vars.iv_RCW[57];
            io_msg_block.RCW3A_ChA_D0 = iv_msg_block_vars.iv_RCW[58];
            io_msg_block.RCW3B_ChA_D0 = iv_msg_block_vars.iv_RCW[59];
            io_msg_block.RCW3C_ChA_D0 = iv_msg_block_vars.iv_RCW[60];
            io_msg_block.RCW3D_ChA_D0 = iv_msg_block_vars.iv_RCW[61];
            io_msg_block.RCW3E_ChA_D0 = iv_msg_block_vars.iv_RCW[62];
            io_msg_block.RCW3F_ChA_D0 = iv_msg_block_vars.iv_RCW[63];
            io_msg_block.RCW40_ChA_D0 = iv_msg_block_vars.iv_RCW[64];
            io_msg_block.RCW41_ChA_D0 = iv_msg_block_vars.iv_RCW[65];
            io_msg_block.RCW42_ChA_D0 = iv_msg_block_vars.iv_RCW[66];
            io_msg_block.RCW43_ChA_D0 = iv_msg_block_vars.iv_RCW[67];
            io_msg_block.RCW44_ChA_D0 = iv_msg_block_vars.iv_RCW[68];
            io_msg_block.RCW45_ChA_D0 = iv_msg_block_vars.iv_RCW[69];
            io_msg_block.RCW46_ChA_D0 = iv_msg_block_vars.iv_RCW[70];
            io_msg_block.RCW47_ChA_D0 = iv_msg_block_vars.iv_RCW[71];
            io_msg_block.RCW48_ChA_D0 = iv_msg_block_vars.iv_RCW[72];
            io_msg_block.RCW49_ChA_D0 = iv_msg_block_vars.iv_RCW[73];
            io_msg_block.RCW4A_ChA_D0 = iv_msg_block_vars.iv_RCW[74];
            io_msg_block.RCW4B_ChA_D0 = iv_msg_block_vars.iv_RCW[75];
            io_msg_block.RCW4C_ChA_D0 = iv_msg_block_vars.iv_RCW[76];
            io_msg_block.RCW4D_ChA_D0 = iv_msg_block_vars.iv_RCW[77];
            io_msg_block.RCW4E_ChA_D0 = iv_msg_block_vars.iv_RCW[78];
            io_msg_block.RCW4F_ChA_D0 = iv_msg_block_vars.iv_RCW[79];
            io_msg_block.RCW50_ChA_D0 = iv_msg_block_vars.iv_RCW[80];
            io_msg_block.RCW51_ChA_D0 = iv_msg_block_vars.iv_RCW[81];
            io_msg_block.RCW52_ChA_D0 = iv_msg_block_vars.iv_RCW[82];
            io_msg_block.RCW53_ChA_D0 = iv_msg_block_vars.iv_RCW[83];
            io_msg_block.RCW54_ChA_D0 = iv_msg_block_vars.iv_RCW[84];
            io_msg_block.RCW55_ChA_D0 = iv_msg_block_vars.iv_RCW[85];
            io_msg_block.RCW56_ChA_D0 = iv_msg_block_vars.iv_RCW[86];
            io_msg_block.RCW57_ChA_D0 = iv_msg_block_vars.iv_RCW[87];
            io_msg_block.RCW58_ChA_D0 = iv_msg_block_vars.iv_RCW[88];
            io_msg_block.RCW59_ChA_D0 = iv_msg_block_vars.iv_RCW[89];
            io_msg_block.RCW5A_ChA_D0 = iv_msg_block_vars.iv_RCW[90];
            io_msg_block.RCW5B_ChA_D0 = iv_msg_block_vars.iv_RCW[91];
            io_msg_block.RCW5C_ChA_D0 = iv_msg_block_vars.iv_RCW[92];
            io_msg_block.RCW5D_ChA_D0 = iv_msg_block_vars.iv_RCW[93];
            io_msg_block.RCW5E_ChA_D0 = iv_msg_block_vars.iv_RCW[94];
            io_msg_block.RCW5F_ChA_D0 = iv_msg_block_vars.iv_RCW[95];
            io_msg_block.RCW60_ChA_D0 = iv_msg_block_vars.iv_RCW[96];
            io_msg_block.RCW61_ChA_D0 = iv_msg_block_vars.iv_RCW[97];
            io_msg_block.RCW62_ChA_D0 = iv_msg_block_vars.iv_RCW[98];
            io_msg_block.RCW63_ChA_D0 = iv_msg_block_vars.iv_RCW[99];
            io_msg_block.RCW64_ChA_D0 = iv_msg_block_vars.iv_RCW[100];
            io_msg_block.RCW65_ChA_D0 = iv_msg_block_vars.iv_RCW[101];
            io_msg_block.RCW66_ChA_D0 = iv_msg_block_vars.iv_RCW[102];
            io_msg_block.RCW67_ChA_D0 = iv_msg_block_vars.iv_RCW[103];
            io_msg_block.RCW68_ChA_D0 = iv_msg_block_vars.iv_RCW[104];
            io_msg_block.RCW69_ChA_D0 = iv_msg_block_vars.iv_RCW[105];
            io_msg_block.RCW6A_ChA_D0 = iv_msg_block_vars.iv_RCW[106];
            io_msg_block.RCW6B_ChA_D0 = iv_msg_block_vars.iv_RCW[107];
            io_msg_block.RCW6C_ChA_D0 = iv_msg_block_vars.iv_RCW[108];
            io_msg_block.RCW6D_ChA_D0 = iv_msg_block_vars.iv_RCW[109];
            io_msg_block.RCW6E_ChA_D0 = iv_msg_block_vars.iv_RCW[110];
            io_msg_block.RCW6F_ChA_D0 = iv_msg_block_vars.iv_RCW[111];
            io_msg_block.RCW70_ChA_D0 = iv_msg_block_vars.iv_RCW[112];
            io_msg_block.RCW71_ChA_D0 = iv_msg_block_vars.iv_RCW[113];
            io_msg_block.RCW72_ChA_D0 = iv_msg_block_vars.iv_RCW[114];
            io_msg_block.RCW73_ChA_D0 = iv_msg_block_vars.iv_RCW[115];
            io_msg_block.RCW74_ChA_D0 = iv_msg_block_vars.iv_RCW[116];
            io_msg_block.RCW75_ChA_D0 = iv_msg_block_vars.iv_RCW[117];
            io_msg_block.RCW76_ChA_D0 = iv_msg_block_vars.iv_RCW[118];
            io_msg_block.RCW77_ChA_D0 = iv_msg_block_vars.iv_RCW[119];
            io_msg_block.RCW78_ChA_D0 = iv_msg_block_vars.iv_RCW[120];
            io_msg_block.RCW79_ChA_D0 = iv_msg_block_vars.iv_RCW[121];
            io_msg_block.RCW7A_ChA_D0 = iv_msg_block_vars.iv_RCW[122];
            io_msg_block.RCW7B_ChA_D0 = iv_msg_block_vars.iv_RCW[123];
            io_msg_block.RCW7C_ChA_D0 = iv_msg_block_vars.iv_RCW[124];
            io_msg_block.RCW7D_ChA_D0 = iv_msg_block_vars.iv_RCW[125];
            io_msg_block.RCW7E_ChA_D0 = iv_msg_block_vars.iv_RCW[126];
            io_msg_block.RCW7F_ChA_D0 = iv_msg_block_vars.iv_RCW[127];

            io_msg_block.RCW00_ChB_D0 = iv_msg_block_vars.iv_RCW[0];
            io_msg_block.RCW01_ChB_D0 = iv_msg_block_vars.iv_RCW[1];
            io_msg_block.RCW02_ChB_D0 = iv_msg_block_vars.iv_RCW[2];
            io_msg_block.RCW03_ChB_D0 = iv_msg_block_vars.iv_RCW[3];
            io_msg_block.RCW04_ChB_D0 = iv_msg_block_vars.iv_RCW[4];
            io_msg_block.RCW05_ChB_D0 = iv_msg_block_vars.iv_RCW[5];
            io_msg_block.RCW06_ChB_D0 = iv_msg_block_vars.iv_RCW[6];
            io_msg_block.RCW07_ChB_D0 = iv_msg_block_vars.iv_RCW[7];
            io_msg_block.RCW08_ChB_D0 = iv_msg_block_vars.iv_RCW[8];
            io_msg_block.RCW09_ChB_D0 = iv_msg_block_vars.iv_RCW[9];
            io_msg_block.RCW0A_ChB_D0 = iv_msg_block_vars.iv_RCW[10];
            io_msg_block.RCW0B_ChB_D0 = iv_msg_block_vars.iv_RCW[11];
            io_msg_block.RCW0C_ChB_D0 = iv_msg_block_vars.iv_RCW[12];
            io_msg_block.RCW0D_ChB_D0 = iv_msg_block_vars.iv_RCW[13];
            io_msg_block.RCW0E_ChB_D0 = iv_msg_block_vars.iv_RCW[14];
            io_msg_block.RCW0F_ChB_D0 = iv_msg_block_vars.iv_RCW[15];
            io_msg_block.RCW10_ChB_D0 = iv_msg_block_vars.iv_RCW[16];
            io_msg_block.RCW11_ChB_D0 = iv_msg_block_vars.iv_RCW[17];
            io_msg_block.RCW12_ChB_D0 = iv_msg_block_vars.iv_RCW[18];
            io_msg_block.RCW13_ChB_D0 = iv_msg_block_vars.iv_RCW[19];
            io_msg_block.RCW14_ChB_D0 = iv_msg_block_vars.iv_RCW[20];
            io_msg_block.RCW15_ChB_D0 = iv_msg_block_vars.iv_RCW[21];
            io_msg_block.RCW16_ChB_D0 = iv_msg_block_vars.iv_RCW[22];
            io_msg_block.RCW17_ChB_D0 = iv_msg_block_vars.iv_RCW[23];
            io_msg_block.RCW18_ChB_D0 = iv_msg_block_vars.iv_RCW[24];
            io_msg_block.RCW19_ChB_D0 = iv_msg_block_vars.iv_RCW[25];
            io_msg_block.RCW1A_ChB_D0 = iv_msg_block_vars.iv_RCW[26];
            io_msg_block.RCW1B_ChB_D0 = iv_msg_block_vars.iv_RCW[27];
            io_msg_block.RCW1C_ChB_D0 = iv_msg_block_vars.iv_RCW[28];
            io_msg_block.RCW1D_ChB_D0 = iv_msg_block_vars.iv_RCW[29];
            io_msg_block.RCW1E_ChB_D0 = iv_msg_block_vars.iv_RCW[30];
            io_msg_block.RCW1F_ChB_D0 = iv_msg_block_vars.iv_RCW[31];
            io_msg_block.RCW20_ChB_D0 = iv_msg_block_vars.iv_RCW[32];
            io_msg_block.RCW21_ChB_D0 = iv_msg_block_vars.iv_RCW[33];
            io_msg_block.RCW22_ChB_D0 = iv_msg_block_vars.iv_RCW[34];
            io_msg_block.RCW23_ChB_D0 = iv_msg_block_vars.iv_RCW[35];
            io_msg_block.RCW24_ChB_D0 = iv_msg_block_vars.iv_RCW[36];
            io_msg_block.RCW25_ChB_D0 = iv_msg_block_vars.iv_RCW[37];
            io_msg_block.RCW26_ChB_D0 = iv_msg_block_vars.iv_RCW[38];
            io_msg_block.RCW27_ChB_D0 = iv_msg_block_vars.iv_RCW[39];
            io_msg_block.RCW28_ChB_D0 = iv_msg_block_vars.iv_RCW[40];
            io_msg_block.RCW29_ChB_D0 = iv_msg_block_vars.iv_RCW[41];
            io_msg_block.RCW2A_ChB_D0 = iv_msg_block_vars.iv_RCW[42];
            io_msg_block.RCW2B_ChB_D0 = iv_msg_block_vars.iv_RCW[43];
            io_msg_block.RCW2C_ChB_D0 = iv_msg_block_vars.iv_RCW[44];
            io_msg_block.RCW2D_ChB_D0 = iv_msg_block_vars.iv_RCW[45];
            io_msg_block.RCW2E_ChB_D0 = iv_msg_block_vars.iv_RCW[46];
            io_msg_block.RCW2F_ChB_D0 = iv_msg_block_vars.iv_RCW[47];
            io_msg_block.RCW30_ChB_D0 = iv_msg_block_vars.iv_RCW[48];
            io_msg_block.RCW31_ChB_D0 = iv_msg_block_vars.iv_RCW[49];
            io_msg_block.RCW32_ChB_D0 = iv_msg_block_vars.iv_RCW[50];
            io_msg_block.RCW33_ChB_D0 = iv_msg_block_vars.iv_RCW[51];
            io_msg_block.RCW34_ChB_D0 = iv_msg_block_vars.iv_RCW[52];
            io_msg_block.RCW35_ChB_D0 = iv_msg_block_vars.iv_RCW[53];
            io_msg_block.RCW36_ChB_D0 = iv_msg_block_vars.iv_RCW[54];
            io_msg_block.RCW37_ChB_D0 = iv_msg_block_vars.iv_RCW[55];
            io_msg_block.RCW38_ChB_D0 = iv_msg_block_vars.iv_RCW[56];
            io_msg_block.RCW39_ChB_D0 = iv_msg_block_vars.iv_RCW[57];
            io_msg_block.RCW3A_ChB_D0 = iv_msg_block_vars.iv_RCW[58];
            io_msg_block.RCW3B_ChB_D0 = iv_msg_block_vars.iv_RCW[59];
            io_msg_block.RCW3C_ChB_D0 = iv_msg_block_vars.iv_RCW[60];
            io_msg_block.RCW3D_ChB_D0 = iv_msg_block_vars.iv_RCW[61];
            io_msg_block.RCW3E_ChB_D0 = iv_msg_block_vars.iv_RCW[62];
            io_msg_block.RCW3F_ChB_D0 = iv_msg_block_vars.iv_RCW[63];
            io_msg_block.RCW40_ChB_D0 = iv_msg_block_vars.iv_RCW[64];
            io_msg_block.RCW41_ChB_D0 = iv_msg_block_vars.iv_RCW[65];
            io_msg_block.RCW42_ChB_D0 = iv_msg_block_vars.iv_RCW[66];
            io_msg_block.RCW43_ChB_D0 = iv_msg_block_vars.iv_RCW[67];
            io_msg_block.RCW44_ChB_D0 = iv_msg_block_vars.iv_RCW[68];
            io_msg_block.RCW45_ChB_D0 = iv_msg_block_vars.iv_RCW[69];
            io_msg_block.RCW46_ChB_D0 = iv_msg_block_vars.iv_RCW[70];
            io_msg_block.RCW47_ChB_D0 = iv_msg_block_vars.iv_RCW[71];
            io_msg_block.RCW48_ChB_D0 = iv_msg_block_vars.iv_RCW[72];
            io_msg_block.RCW49_ChB_D0 = iv_msg_block_vars.iv_RCW[73];
            io_msg_block.RCW4A_ChB_D0 = iv_msg_block_vars.iv_RCW[74];
            io_msg_block.RCW4B_ChB_D0 = iv_msg_block_vars.iv_RCW[75];
            io_msg_block.RCW4C_ChB_D0 = iv_msg_block_vars.iv_RCW[76];
            io_msg_block.RCW4D_ChB_D0 = iv_msg_block_vars.iv_RCW[77];
            io_msg_block.RCW4E_ChB_D0 = iv_msg_block_vars.iv_RCW[78];
            io_msg_block.RCW4F_ChB_D0 = iv_msg_block_vars.iv_RCW[79];
            io_msg_block.RCW50_ChB_D0 = iv_msg_block_vars.iv_RCW[80];
            io_msg_block.RCW51_ChB_D0 = iv_msg_block_vars.iv_RCW[81];
            io_msg_block.RCW52_ChB_D0 = iv_msg_block_vars.iv_RCW[82];
            io_msg_block.RCW53_ChB_D0 = iv_msg_block_vars.iv_RCW[83];
            io_msg_block.RCW54_ChB_D0 = iv_msg_block_vars.iv_RCW[84];
            io_msg_block.RCW55_ChB_D0 = iv_msg_block_vars.iv_RCW[85];
            io_msg_block.RCW56_ChB_D0 = iv_msg_block_vars.iv_RCW[86];
            io_msg_block.RCW57_ChB_D0 = iv_msg_block_vars.iv_RCW[87];
            io_msg_block.RCW58_ChB_D0 = iv_msg_block_vars.iv_RCW[88];
            io_msg_block.RCW59_ChB_D0 = iv_msg_block_vars.iv_RCW[89];
            io_msg_block.RCW5A_ChB_D0 = iv_msg_block_vars.iv_RCW[90];
            io_msg_block.RCW5B_ChB_D0 = iv_msg_block_vars.iv_RCW[91];
            io_msg_block.RCW5C_ChB_D0 = iv_msg_block_vars.iv_RCW[92];
            io_msg_block.RCW5D_ChB_D0 = iv_msg_block_vars.iv_RCW[93];
            io_msg_block.RCW5E_ChB_D0 = iv_msg_block_vars.iv_RCW[94];
            io_msg_block.RCW5F_ChB_D0 = iv_msg_block_vars.iv_RCW[95];
            io_msg_block.RCW60_ChB_D0 = iv_msg_block_vars.iv_RCW[96];
            io_msg_block.RCW61_ChB_D0 = iv_msg_block_vars.iv_RCW[97];
            io_msg_block.RCW62_ChB_D0 = iv_msg_block_vars.iv_RCW[98];
            io_msg_block.RCW63_ChB_D0 = iv_msg_block_vars.iv_RCW[99];
            io_msg_block.RCW64_ChB_D0 = iv_msg_block_vars.iv_RCW[100];
            io_msg_block.RCW65_ChB_D0 = iv_msg_block_vars.iv_RCW[101];
            io_msg_block.RCW66_ChB_D0 = iv_msg_block_vars.iv_RCW[102];
            io_msg_block.RCW67_ChB_D0 = iv_msg_block_vars.iv_RCW[103];
            io_msg_block.RCW68_ChB_D0 = iv_msg_block_vars.iv_RCW[104];
            io_msg_block.RCW69_ChB_D0 = iv_msg_block_vars.iv_RCW[105];
            io_msg_block.RCW6A_ChB_D0 = iv_msg_block_vars.iv_RCW[106];
            io_msg_block.RCW6B_ChB_D0 = iv_msg_block_vars.iv_RCW[107];
            io_msg_block.RCW6C_ChB_D0 = iv_msg_block_vars.iv_RCW[108];
            io_msg_block.RCW6D_ChB_D0 = iv_msg_block_vars.iv_RCW[109];
            io_msg_block.RCW6E_ChB_D0 = iv_msg_block_vars.iv_RCW[110];
            io_msg_block.RCW6F_ChB_D0 = iv_msg_block_vars.iv_RCW[111];
            io_msg_block.RCW70_ChB_D0 = iv_msg_block_vars.iv_RCW[112];
            io_msg_block.RCW71_ChB_D0 = iv_msg_block_vars.iv_RCW[113];
            io_msg_block.RCW72_ChB_D0 = iv_msg_block_vars.iv_RCW[114];
            io_msg_block.RCW73_ChB_D0 = iv_msg_block_vars.iv_RCW[115];
            io_msg_block.RCW74_ChB_D0 = iv_msg_block_vars.iv_RCW[116];
            io_msg_block.RCW75_ChB_D0 = iv_msg_block_vars.iv_RCW[117];
            io_msg_block.RCW76_ChB_D0 = iv_msg_block_vars.iv_RCW[118];
            io_msg_block.RCW77_ChB_D0 = iv_msg_block_vars.iv_RCW[119];
            io_msg_block.RCW78_ChB_D0 = iv_msg_block_vars.iv_RCW[120];
            io_msg_block.RCW79_ChB_D0 = iv_msg_block_vars.iv_RCW[121];
            io_msg_block.RCW7A_ChB_D0 = iv_msg_block_vars.iv_RCW[122];
            io_msg_block.RCW7B_ChB_D0 = iv_msg_block_vars.iv_RCW[123];
            io_msg_block.RCW7C_ChB_D0 = iv_msg_block_vars.iv_RCW[124];
            io_msg_block.RCW7D_ChB_D0 = iv_msg_block_vars.iv_RCW[125];
            io_msg_block.RCW7E_ChB_D0 = iv_msg_block_vars.iv_RCW[126];
            io_msg_block.RCW7F_ChB_D0 = iv_msg_block_vars.iv_RCW[127];

            io_msg_block.RCW00_ChA_D1 = iv_msg_block_vars.iv_RCW[0];
            io_msg_block.RCW01_ChA_D1 = iv_msg_block_vars.iv_RCW[1];
            io_msg_block.RCW02_ChA_D1 = iv_msg_block_vars.iv_RCW[2];
            io_msg_block.RCW03_ChA_D1 = iv_msg_block_vars.iv_RCW[3];
            io_msg_block.RCW04_ChA_D1 = iv_msg_block_vars.iv_RCW[4];
            io_msg_block.RCW05_ChA_D1 = iv_msg_block_vars.iv_RCW[5];
            io_msg_block.RCW06_ChA_D1 = iv_msg_block_vars.iv_RCW[6];
            io_msg_block.RCW07_ChA_D1 = iv_msg_block_vars.iv_RCW[7];
            io_msg_block.RCW08_ChA_D1 = iv_msg_block_vars.iv_RCW[8];
            io_msg_block.RCW09_ChA_D1 = iv_msg_block_vars.iv_RCW[9];
            io_msg_block.RCW0A_ChA_D1 = iv_msg_block_vars.iv_RCW[10];
            io_msg_block.RCW0B_ChA_D1 = iv_msg_block_vars.iv_RCW[11];
            io_msg_block.RCW0C_ChA_D1 = iv_msg_block_vars.iv_RCW[12];
            io_msg_block.RCW0D_ChA_D1 = iv_msg_block_vars.iv_RCW[13];
            io_msg_block.RCW0E_ChA_D1 = iv_msg_block_vars.iv_RCW[14];
            io_msg_block.RCW0F_ChA_D1 = iv_msg_block_vars.iv_RCW[15];
            io_msg_block.RCW10_ChA_D1 = iv_msg_block_vars.iv_RCW[16];
            io_msg_block.RCW11_ChA_D1 = iv_msg_block_vars.iv_RCW[17];
            io_msg_block.RCW12_ChA_D1 = iv_msg_block_vars.iv_RCW[18];
            io_msg_block.RCW13_ChA_D1 = iv_msg_block_vars.iv_RCW[19];
            io_msg_block.RCW14_ChA_D1 = iv_msg_block_vars.iv_RCW[20];
            io_msg_block.RCW15_ChA_D1 = iv_msg_block_vars.iv_RCW[21];
            io_msg_block.RCW16_ChA_D1 = iv_msg_block_vars.iv_RCW[22];
            io_msg_block.RCW17_ChA_D1 = iv_msg_block_vars.iv_RCW[23];
            io_msg_block.RCW18_ChA_D1 = iv_msg_block_vars.iv_RCW[24];
            io_msg_block.RCW19_ChA_D1 = iv_msg_block_vars.iv_RCW[25];
            io_msg_block.RCW1A_ChA_D1 = iv_msg_block_vars.iv_RCW[26];
            io_msg_block.RCW1B_ChA_D1 = iv_msg_block_vars.iv_RCW[27];
            io_msg_block.RCW1C_ChA_D1 = iv_msg_block_vars.iv_RCW[28];
            io_msg_block.RCW1D_ChA_D1 = iv_msg_block_vars.iv_RCW[29];
            io_msg_block.RCW1E_ChA_D1 = iv_msg_block_vars.iv_RCW[30];
            io_msg_block.RCW1F_ChA_D1 = iv_msg_block_vars.iv_RCW[31];
            io_msg_block.RCW20_ChA_D1 = iv_msg_block_vars.iv_RCW[32];
            io_msg_block.RCW21_ChA_D1 = iv_msg_block_vars.iv_RCW[33];
            io_msg_block.RCW22_ChA_D1 = iv_msg_block_vars.iv_RCW[34];
            io_msg_block.RCW23_ChA_D1 = iv_msg_block_vars.iv_RCW[35];
            io_msg_block.RCW24_ChA_D1 = iv_msg_block_vars.iv_RCW[36];
            io_msg_block.RCW25_ChA_D1 = iv_msg_block_vars.iv_RCW[37];
            io_msg_block.RCW26_ChA_D1 = iv_msg_block_vars.iv_RCW[38];
            io_msg_block.RCW27_ChA_D1 = iv_msg_block_vars.iv_RCW[39];
            io_msg_block.RCW28_ChA_D1 = iv_msg_block_vars.iv_RCW[40];
            io_msg_block.RCW29_ChA_D1 = iv_msg_block_vars.iv_RCW[41];
            io_msg_block.RCW2A_ChA_D1 = iv_msg_block_vars.iv_RCW[42];
            io_msg_block.RCW2B_ChA_D1 = iv_msg_block_vars.iv_RCW[43];
            io_msg_block.RCW2C_ChA_D1 = iv_msg_block_vars.iv_RCW[44];
            io_msg_block.RCW2D_ChA_D1 = iv_msg_block_vars.iv_RCW[45];
            io_msg_block.RCW2E_ChA_D1 = iv_msg_block_vars.iv_RCW[46];
            io_msg_block.RCW2F_ChA_D1 = iv_msg_block_vars.iv_RCW[47];
            io_msg_block.RCW30_ChA_D1 = iv_msg_block_vars.iv_RCW[48];
            io_msg_block.RCW31_ChA_D1 = iv_msg_block_vars.iv_RCW[49];
            io_msg_block.RCW32_ChA_D1 = iv_msg_block_vars.iv_RCW[50];
            io_msg_block.RCW33_ChA_D1 = iv_msg_block_vars.iv_RCW[51];
            io_msg_block.RCW34_ChA_D1 = iv_msg_block_vars.iv_RCW[52];
            io_msg_block.RCW35_ChA_D1 = iv_msg_block_vars.iv_RCW[53];
            io_msg_block.RCW36_ChA_D1 = iv_msg_block_vars.iv_RCW[54];
            io_msg_block.RCW37_ChA_D1 = iv_msg_block_vars.iv_RCW[55];
            io_msg_block.RCW38_ChA_D1 = iv_msg_block_vars.iv_RCW[56];
            io_msg_block.RCW39_ChA_D1 = iv_msg_block_vars.iv_RCW[57];
            io_msg_block.RCW3A_ChA_D1 = iv_msg_block_vars.iv_RCW[58];
            io_msg_block.RCW3B_ChA_D1 = iv_msg_block_vars.iv_RCW[59];
            io_msg_block.RCW3C_ChA_D1 = iv_msg_block_vars.iv_RCW[60];
            io_msg_block.RCW3D_ChA_D1 = iv_msg_block_vars.iv_RCW[61];
            io_msg_block.RCW3E_ChA_D1 = iv_msg_block_vars.iv_RCW[62];
            io_msg_block.RCW3F_ChA_D1 = iv_msg_block_vars.iv_RCW[63];
            io_msg_block.RCW40_ChA_D1 = iv_msg_block_vars.iv_RCW[64];
            io_msg_block.RCW41_ChA_D1 = iv_msg_block_vars.iv_RCW[65];
            io_msg_block.RCW42_ChA_D1 = iv_msg_block_vars.iv_RCW[66];
            io_msg_block.RCW43_ChA_D1 = iv_msg_block_vars.iv_RCW[67];
            io_msg_block.RCW44_ChA_D1 = iv_msg_block_vars.iv_RCW[68];
            io_msg_block.RCW45_ChA_D1 = iv_msg_block_vars.iv_RCW[69];
            io_msg_block.RCW46_ChA_D1 = iv_msg_block_vars.iv_RCW[70];
            io_msg_block.RCW47_ChA_D1 = iv_msg_block_vars.iv_RCW[71];
            io_msg_block.RCW48_ChA_D1 = iv_msg_block_vars.iv_RCW[72];
            io_msg_block.RCW49_ChA_D1 = iv_msg_block_vars.iv_RCW[73];
            io_msg_block.RCW4A_ChA_D1 = iv_msg_block_vars.iv_RCW[74];
            io_msg_block.RCW4B_ChA_D1 = iv_msg_block_vars.iv_RCW[75];
            io_msg_block.RCW4C_ChA_D1 = iv_msg_block_vars.iv_RCW[76];
            io_msg_block.RCW4D_ChA_D1 = iv_msg_block_vars.iv_RCW[77];
            io_msg_block.RCW4E_ChA_D1 = iv_msg_block_vars.iv_RCW[78];
            io_msg_block.RCW4F_ChA_D1 = iv_msg_block_vars.iv_RCW[79];
            io_msg_block.RCW50_ChA_D1 = iv_msg_block_vars.iv_RCW[80];
            io_msg_block.RCW51_ChA_D1 = iv_msg_block_vars.iv_RCW[81];
            io_msg_block.RCW52_ChA_D1 = iv_msg_block_vars.iv_RCW[82];
            io_msg_block.RCW53_ChA_D1 = iv_msg_block_vars.iv_RCW[83];
            io_msg_block.RCW54_ChA_D1 = iv_msg_block_vars.iv_RCW[84];
            io_msg_block.RCW55_ChA_D1 = iv_msg_block_vars.iv_RCW[85];
            io_msg_block.RCW56_ChA_D1 = iv_msg_block_vars.iv_RCW[86];
            io_msg_block.RCW57_ChA_D1 = iv_msg_block_vars.iv_RCW[87];
            io_msg_block.RCW58_ChA_D1 = iv_msg_block_vars.iv_RCW[88];
            io_msg_block.RCW59_ChA_D1 = iv_msg_block_vars.iv_RCW[89];
            io_msg_block.RCW5A_ChA_D1 = iv_msg_block_vars.iv_RCW[90];
            io_msg_block.RCW5B_ChA_D1 = iv_msg_block_vars.iv_RCW[91];
            io_msg_block.RCW5C_ChA_D1 = iv_msg_block_vars.iv_RCW[92];
            io_msg_block.RCW5D_ChA_D1 = iv_msg_block_vars.iv_RCW[93];
            io_msg_block.RCW5E_ChA_D1 = iv_msg_block_vars.iv_RCW[94];
            io_msg_block.RCW5F_ChA_D1 = iv_msg_block_vars.iv_RCW[95];
            io_msg_block.RCW60_ChA_D1 = iv_msg_block_vars.iv_RCW[96];
            io_msg_block.RCW61_ChA_D1 = iv_msg_block_vars.iv_RCW[97];
            io_msg_block.RCW62_ChA_D1 = iv_msg_block_vars.iv_RCW[98];
            io_msg_block.RCW63_ChA_D1 = iv_msg_block_vars.iv_RCW[99];
            io_msg_block.RCW64_ChA_D1 = iv_msg_block_vars.iv_RCW[100];
            io_msg_block.RCW65_ChA_D1 = iv_msg_block_vars.iv_RCW[101];
            io_msg_block.RCW66_ChA_D1 = iv_msg_block_vars.iv_RCW[102];
            io_msg_block.RCW67_ChA_D1 = iv_msg_block_vars.iv_RCW[103];
            io_msg_block.RCW68_ChA_D1 = iv_msg_block_vars.iv_RCW[104];
            io_msg_block.RCW69_ChA_D1 = iv_msg_block_vars.iv_RCW[105];
            io_msg_block.RCW6A_ChA_D1 = iv_msg_block_vars.iv_RCW[106];
            io_msg_block.RCW6B_ChA_D1 = iv_msg_block_vars.iv_RCW[107];
            io_msg_block.RCW6C_ChA_D1 = iv_msg_block_vars.iv_RCW[108];
            io_msg_block.RCW6D_ChA_D1 = iv_msg_block_vars.iv_RCW[109];
            io_msg_block.RCW6E_ChA_D1 = iv_msg_block_vars.iv_RCW[110];
            io_msg_block.RCW6F_ChA_D1 = iv_msg_block_vars.iv_RCW[111];
            io_msg_block.RCW70_ChA_D1 = iv_msg_block_vars.iv_RCW[112];
            io_msg_block.RCW71_ChA_D1 = iv_msg_block_vars.iv_RCW[113];
            io_msg_block.RCW72_ChA_D1 = iv_msg_block_vars.iv_RCW[114];
            io_msg_block.RCW73_ChA_D1 = iv_msg_block_vars.iv_RCW[115];
            io_msg_block.RCW74_ChA_D1 = iv_msg_block_vars.iv_RCW[116];
            io_msg_block.RCW75_ChA_D1 = iv_msg_block_vars.iv_RCW[117];
            io_msg_block.RCW76_ChA_D1 = iv_msg_block_vars.iv_RCW[118];
            io_msg_block.RCW77_ChA_D1 = iv_msg_block_vars.iv_RCW[119];
            io_msg_block.RCW78_ChA_D1 = iv_msg_block_vars.iv_RCW[120];
            io_msg_block.RCW79_ChA_D1 = iv_msg_block_vars.iv_RCW[121];
            io_msg_block.RCW7A_ChA_D1 = iv_msg_block_vars.iv_RCW[122];
            io_msg_block.RCW7B_ChA_D1 = iv_msg_block_vars.iv_RCW[123];
            io_msg_block.RCW7C_ChA_D1 = iv_msg_block_vars.iv_RCW[124];
            io_msg_block.RCW7D_ChA_D1 = iv_msg_block_vars.iv_RCW[125];
            io_msg_block.RCW7E_ChA_D1 = iv_msg_block_vars.iv_RCW[126];
            io_msg_block.RCW7F_ChA_D1 = iv_msg_block_vars.iv_RCW[127];

            io_msg_block.RCW00_ChB_D1 = iv_msg_block_vars.iv_RCW[0];
            io_msg_block.RCW01_ChB_D1 = iv_msg_block_vars.iv_RCW[1];
            io_msg_block.RCW02_ChB_D1 = iv_msg_block_vars.iv_RCW[2];
            io_msg_block.RCW03_ChB_D1 = iv_msg_block_vars.iv_RCW[3];
            io_msg_block.RCW04_ChB_D1 = iv_msg_block_vars.iv_RCW[4];
            io_msg_block.RCW05_ChB_D1 = iv_msg_block_vars.iv_RCW[5];
            io_msg_block.RCW06_ChB_D1 = iv_msg_block_vars.iv_RCW[6];
            io_msg_block.RCW07_ChB_D1 = iv_msg_block_vars.iv_RCW[7];
            io_msg_block.RCW08_ChB_D1 = iv_msg_block_vars.iv_RCW[8];
            io_msg_block.RCW09_ChB_D1 = iv_msg_block_vars.iv_RCW[9];
            io_msg_block.RCW0A_ChB_D1 = iv_msg_block_vars.iv_RCW[10];
            io_msg_block.RCW0B_ChB_D1 = iv_msg_block_vars.iv_RCW[11];
            io_msg_block.RCW0C_ChB_D1 = iv_msg_block_vars.iv_RCW[12];
            io_msg_block.RCW0D_ChB_D1 = iv_msg_block_vars.iv_RCW[13];
            io_msg_block.RCW0E_ChB_D1 = iv_msg_block_vars.iv_RCW[14];
            io_msg_block.RCW0F_ChB_D1 = iv_msg_block_vars.iv_RCW[15];
            io_msg_block.RCW10_ChB_D1 = iv_msg_block_vars.iv_RCW[16];
            io_msg_block.RCW11_ChB_D1 = iv_msg_block_vars.iv_RCW[17];
            io_msg_block.RCW12_ChB_D1 = iv_msg_block_vars.iv_RCW[18];
            io_msg_block.RCW13_ChB_D1 = iv_msg_block_vars.iv_RCW[19];
            io_msg_block.RCW14_ChB_D1 = iv_msg_block_vars.iv_RCW[20];
            io_msg_block.RCW15_ChB_D1 = iv_msg_block_vars.iv_RCW[21];
            io_msg_block.RCW16_ChB_D1 = iv_msg_block_vars.iv_RCW[22];
            io_msg_block.RCW17_ChB_D1 = iv_msg_block_vars.iv_RCW[23];
            io_msg_block.RCW18_ChB_D1 = iv_msg_block_vars.iv_RCW[24];
            io_msg_block.RCW19_ChB_D1 = iv_msg_block_vars.iv_RCW[25];
            io_msg_block.RCW1A_ChB_D1 = iv_msg_block_vars.iv_RCW[26];
            io_msg_block.RCW1B_ChB_D1 = iv_msg_block_vars.iv_RCW[27];
            io_msg_block.RCW1C_ChB_D1 = iv_msg_block_vars.iv_RCW[28];
            io_msg_block.RCW1D_ChB_D1 = iv_msg_block_vars.iv_RCW[29];
            io_msg_block.RCW1E_ChB_D1 = iv_msg_block_vars.iv_RCW[30];
            io_msg_block.RCW1F_ChB_D1 = iv_msg_block_vars.iv_RCW[31];
            io_msg_block.RCW20_ChB_D1 = iv_msg_block_vars.iv_RCW[32];
            io_msg_block.RCW21_ChB_D1 = iv_msg_block_vars.iv_RCW[33];
            io_msg_block.RCW22_ChB_D1 = iv_msg_block_vars.iv_RCW[34];
            io_msg_block.RCW23_ChB_D1 = iv_msg_block_vars.iv_RCW[35];
            io_msg_block.RCW24_ChB_D1 = iv_msg_block_vars.iv_RCW[36];
            io_msg_block.RCW25_ChB_D1 = iv_msg_block_vars.iv_RCW[37];
            io_msg_block.RCW26_ChB_D1 = iv_msg_block_vars.iv_RCW[38];
            io_msg_block.RCW27_ChB_D1 = iv_msg_block_vars.iv_RCW[39];
            io_msg_block.RCW28_ChB_D1 = iv_msg_block_vars.iv_RCW[40];
            io_msg_block.RCW29_ChB_D1 = iv_msg_block_vars.iv_RCW[41];
            io_msg_block.RCW2A_ChB_D1 = iv_msg_block_vars.iv_RCW[42];
            io_msg_block.RCW2B_ChB_D1 = iv_msg_block_vars.iv_RCW[43];
            io_msg_block.RCW2C_ChB_D1 = iv_msg_block_vars.iv_RCW[44];
            io_msg_block.RCW2D_ChB_D1 = iv_msg_block_vars.iv_RCW[45];
            io_msg_block.RCW2E_ChB_D1 = iv_msg_block_vars.iv_RCW[46];
            io_msg_block.RCW2F_ChB_D1 = iv_msg_block_vars.iv_RCW[47];
            io_msg_block.RCW30_ChB_D1 = iv_msg_block_vars.iv_RCW[48];
            io_msg_block.RCW31_ChB_D1 = iv_msg_block_vars.iv_RCW[49];
            io_msg_block.RCW32_ChB_D1 = iv_msg_block_vars.iv_RCW[50];
            io_msg_block.RCW33_ChB_D1 = iv_msg_block_vars.iv_RCW[51];
            io_msg_block.RCW34_ChB_D1 = iv_msg_block_vars.iv_RCW[52];
            io_msg_block.RCW35_ChB_D1 = iv_msg_block_vars.iv_RCW[53];
            io_msg_block.RCW36_ChB_D1 = iv_msg_block_vars.iv_RCW[54];
            io_msg_block.RCW37_ChB_D1 = iv_msg_block_vars.iv_RCW[55];
            io_msg_block.RCW38_ChB_D1 = iv_msg_block_vars.iv_RCW[56];
            io_msg_block.RCW39_ChB_D1 = iv_msg_block_vars.iv_RCW[57];
            io_msg_block.RCW3A_ChB_D1 = iv_msg_block_vars.iv_RCW[58];
            io_msg_block.RCW3B_ChB_D1 = iv_msg_block_vars.iv_RCW[59];
            io_msg_block.RCW3C_ChB_D1 = iv_msg_block_vars.iv_RCW[60];
            io_msg_block.RCW3D_ChB_D1 = iv_msg_block_vars.iv_RCW[61];
            io_msg_block.RCW3E_ChB_D1 = iv_msg_block_vars.iv_RCW[62];
            io_msg_block.RCW3F_ChB_D1 = iv_msg_block_vars.iv_RCW[63];
            io_msg_block.RCW40_ChB_D1 = iv_msg_block_vars.iv_RCW[64];
            io_msg_block.RCW41_ChB_D1 = iv_msg_block_vars.iv_RCW[65];
            io_msg_block.RCW42_ChB_D1 = iv_msg_block_vars.iv_RCW[66];
            io_msg_block.RCW43_ChB_D1 = iv_msg_block_vars.iv_RCW[67];
            io_msg_block.RCW44_ChB_D1 = iv_msg_block_vars.iv_RCW[68];
            io_msg_block.RCW45_ChB_D1 = iv_msg_block_vars.iv_RCW[69];
            io_msg_block.RCW46_ChB_D1 = iv_msg_block_vars.iv_RCW[70];
            io_msg_block.RCW47_ChB_D1 = iv_msg_block_vars.iv_RCW[71];
            io_msg_block.RCW48_ChB_D1 = iv_msg_block_vars.iv_RCW[72];
            io_msg_block.RCW49_ChB_D1 = iv_msg_block_vars.iv_RCW[73];
            io_msg_block.RCW4A_ChB_D1 = iv_msg_block_vars.iv_RCW[74];
            io_msg_block.RCW4B_ChB_D1 = iv_msg_block_vars.iv_RCW[75];
            io_msg_block.RCW4C_ChB_D1 = iv_msg_block_vars.iv_RCW[76];
            io_msg_block.RCW4D_ChB_D1 = iv_msg_block_vars.iv_RCW[77];
            io_msg_block.RCW4E_ChB_D1 = iv_msg_block_vars.iv_RCW[78];
            io_msg_block.RCW4F_ChB_D1 = iv_msg_block_vars.iv_RCW[79];
            io_msg_block.RCW50_ChB_D1 = iv_msg_block_vars.iv_RCW[80];
            io_msg_block.RCW51_ChB_D1 = iv_msg_block_vars.iv_RCW[81];
            io_msg_block.RCW52_ChB_D1 = iv_msg_block_vars.iv_RCW[82];
            io_msg_block.RCW53_ChB_D1 = iv_msg_block_vars.iv_RCW[83];
            io_msg_block.RCW54_ChB_D1 = iv_msg_block_vars.iv_RCW[84];
            io_msg_block.RCW55_ChB_D1 = iv_msg_block_vars.iv_RCW[85];
            io_msg_block.RCW56_ChB_D1 = iv_msg_block_vars.iv_RCW[86];
            io_msg_block.RCW57_ChB_D1 = iv_msg_block_vars.iv_RCW[87];
            io_msg_block.RCW58_ChB_D1 = iv_msg_block_vars.iv_RCW[88];
            io_msg_block.RCW59_ChB_D1 = iv_msg_block_vars.iv_RCW[89];
            io_msg_block.RCW5A_ChB_D1 = iv_msg_block_vars.iv_RCW[90];
            io_msg_block.RCW5B_ChB_D1 = iv_msg_block_vars.iv_RCW[91];
            io_msg_block.RCW5C_ChB_D1 = iv_msg_block_vars.iv_RCW[92];
            io_msg_block.RCW5D_ChB_D1 = iv_msg_block_vars.iv_RCW[93];
            io_msg_block.RCW5E_ChB_D1 = iv_msg_block_vars.iv_RCW[94];
            io_msg_block.RCW5F_ChB_D1 = iv_msg_block_vars.iv_RCW[95];
            io_msg_block.RCW60_ChB_D1 = iv_msg_block_vars.iv_RCW[96];
            io_msg_block.RCW61_ChB_D1 = iv_msg_block_vars.iv_RCW[97];
            io_msg_block.RCW62_ChB_D1 = iv_msg_block_vars.iv_RCW[98];
            io_msg_block.RCW63_ChB_D1 = iv_msg_block_vars.iv_RCW[99];
            io_msg_block.RCW64_ChB_D1 = iv_msg_block_vars.iv_RCW[100];
            io_msg_block.RCW65_ChB_D1 = iv_msg_block_vars.iv_RCW[101];
            io_msg_block.RCW66_ChB_D1 = iv_msg_block_vars.iv_RCW[102];
            io_msg_block.RCW67_ChB_D1 = iv_msg_block_vars.iv_RCW[103];
            io_msg_block.RCW68_ChB_D1 = iv_msg_block_vars.iv_RCW[104];
            io_msg_block.RCW69_ChB_D1 = iv_msg_block_vars.iv_RCW[105];
            io_msg_block.RCW6A_ChB_D1 = iv_msg_block_vars.iv_RCW[106];
            io_msg_block.RCW6B_ChB_D1 = iv_msg_block_vars.iv_RCW[107];
            io_msg_block.RCW6C_ChB_D1 = iv_msg_block_vars.iv_RCW[108];
            io_msg_block.RCW6D_ChB_D1 = iv_msg_block_vars.iv_RCW[109];
            io_msg_block.RCW6E_ChB_D1 = iv_msg_block_vars.iv_RCW[110];
            io_msg_block.RCW6F_ChB_D1 = iv_msg_block_vars.iv_RCW[111];
            io_msg_block.RCW70_ChB_D1 = iv_msg_block_vars.iv_RCW[112];
            io_msg_block.RCW71_ChB_D1 = iv_msg_block_vars.iv_RCW[113];
            io_msg_block.RCW72_ChB_D1 = iv_msg_block_vars.iv_RCW[114];
            io_msg_block.RCW73_ChB_D1 = iv_msg_block_vars.iv_RCW[115];
            io_msg_block.RCW74_ChB_D1 = iv_msg_block_vars.iv_RCW[116];
            io_msg_block.RCW75_ChB_D1 = iv_msg_block_vars.iv_RCW[117];
            io_msg_block.RCW76_ChB_D1 = iv_msg_block_vars.iv_RCW[118];
            io_msg_block.RCW77_ChB_D1 = iv_msg_block_vars.iv_RCW[119];
            io_msg_block.RCW78_ChB_D1 = iv_msg_block_vars.iv_RCW[120];
            io_msg_block.RCW79_ChB_D1 = iv_msg_block_vars.iv_RCW[121];
            io_msg_block.RCW7A_ChB_D1 = iv_msg_block_vars.iv_RCW[122];
            io_msg_block.RCW7B_ChB_D1 = iv_msg_block_vars.iv_RCW[123];
            io_msg_block.RCW7C_ChB_D1 = iv_msg_block_vars.iv_RCW[124];
            io_msg_block.RCW7D_ChB_D1 = iv_msg_block_vars.iv_RCW[125];
            io_msg_block.RCW7E_ChB_D1 = iv_msg_block_vars.iv_RCW[126];
            io_msg_block.RCW7F_ChB_D1 = iv_msg_block_vars.iv_RCW[127];

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter BCW[N]_CHA/B_D[DIMM]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_BCW(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            // BCW values are all left as zero for Odyssey
            io_msg_block.BCW00_ChA_D0 = 0;
            io_msg_block.BCW01_ChA_D0 = 0;
            io_msg_block.BCW02_ChA_D0 = 0;
            io_msg_block.BCW03_ChA_D0 = 0;
            io_msg_block.BCW04_ChA_D0 = 0;
            io_msg_block.BCW05_ChA_D0 = 0;
            io_msg_block.BCW06_ChA_D0 = 0;
            io_msg_block.BCW07_ChA_D0 = 0;
            io_msg_block.BCW08_ChA_D0 = 0;
            io_msg_block.BCW09_ChA_D0 = 0;
            io_msg_block.BCW0A_ChA_D0 = 0;
            io_msg_block.BCW0B_ChA_D0 = 0;
            io_msg_block.BCW0C_ChA_D0 = 0;
            io_msg_block.BCW0D_ChA_D0 = 0;
            io_msg_block.BCW0E_ChA_D0 = 0;
            io_msg_block.BCW0F_ChA_D0 = 0;
            io_msg_block.BCW10_ChA_D0 = 0;
            io_msg_block.BCW11_ChA_D0 = 0;
            io_msg_block.BCW12_ChA_D0 = 0;
            io_msg_block.BCW13_ChA_D0 = 0;
            io_msg_block.BCW14_ChA_D0 = 0;
            io_msg_block.BCW15_ChA_D0 = 0;
            io_msg_block.BCW16_ChA_D0 = 0;
            io_msg_block.BCW17_ChA_D0 = 0;
            io_msg_block.BCW18_ChA_D0 = 0;
            io_msg_block.BCW19_ChA_D0 = 0;
            io_msg_block.BCW1A_ChA_D0 = 0;
            io_msg_block.BCW1B_ChA_D0 = 0;
            io_msg_block.BCW1C_ChA_D0 = 0;
            io_msg_block.BCW1D_ChA_D0 = 0;
            io_msg_block.BCW1E_ChA_D0 = 0;
            io_msg_block.BCW1F_ChA_D0 = 0;
            io_msg_block.BCW20_ChA_D0 = 0;
            io_msg_block.BCW21_ChA_D0 = 0;
            io_msg_block.BCW22_ChA_D0 = 0;
            io_msg_block.BCW23_ChA_D0 = 0;
            io_msg_block.BCW24_ChA_D0 = 0;
            io_msg_block.BCW25_ChA_D0 = 0;
            io_msg_block.BCW26_ChA_D0 = 0;
            io_msg_block.BCW27_ChA_D0 = 0;
            io_msg_block.BCW28_ChA_D0 = 0;
            io_msg_block.BCW29_ChA_D0 = 0;
            io_msg_block.BCW2A_ChA_D0 = 0;
            io_msg_block.BCW2B_ChA_D0 = 0;
            io_msg_block.BCW2C_ChA_D0 = 0;
            io_msg_block.BCW2D_ChA_D0 = 0;
            io_msg_block.BCW2E_ChA_D0 = 0;
            io_msg_block.BCW2F_ChA_D0 = 0;
            io_msg_block.BCW30_ChA_D0 = 0;
            io_msg_block.BCW31_ChA_D0 = 0;
            io_msg_block.BCW32_ChA_D0 = 0;
            io_msg_block.BCW33_ChA_D0 = 0;
            io_msg_block.BCW34_ChA_D0 = 0;
            io_msg_block.BCW35_ChA_D0 = 0;
            io_msg_block.BCW36_ChA_D0 = 0;
            io_msg_block.BCW37_ChA_D0 = 0;
            io_msg_block.BCW38_ChA_D0 = 0;
            io_msg_block.BCW39_ChA_D0 = 0;
            io_msg_block.BCW3A_ChA_D0 = 0;
            io_msg_block.BCW3B_ChA_D0 = 0;
            io_msg_block.BCW3C_ChA_D0 = 0;
            io_msg_block.BCW3D_ChA_D0 = 0;
            io_msg_block.BCW3E_ChA_D0 = 0;
            io_msg_block.BCW3F_ChA_D0 = 0;
            io_msg_block.BCW40_ChA_D0 = 0;
            io_msg_block.BCW41_ChA_D0 = 0;
            io_msg_block.BCW42_ChA_D0 = 0;
            io_msg_block.BCW43_ChA_D0 = 0;
            io_msg_block.BCW44_ChA_D0 = 0;
            io_msg_block.BCW45_ChA_D0 = 0;
            io_msg_block.BCW46_ChA_D0 = 0;
            io_msg_block.BCW47_ChA_D0 = 0;
            io_msg_block.BCW48_ChA_D0 = 0;
            io_msg_block.BCW49_ChA_D0 = 0;
            io_msg_block.BCW4A_ChA_D0 = 0;
            io_msg_block.BCW4B_ChA_D0 = 0;
            io_msg_block.BCW4C_ChA_D0 = 0;
            io_msg_block.BCW4D_ChA_D0 = 0;
            io_msg_block.BCW4E_ChA_D0 = 0;
            io_msg_block.BCW4F_ChA_D0 = 0;
            io_msg_block.BCW50_ChA_D0 = 0;
            io_msg_block.BCW51_ChA_D0 = 0;
            io_msg_block.BCW52_ChA_D0 = 0;
            io_msg_block.BCW53_ChA_D0 = 0;
            io_msg_block.BCW54_ChA_D0 = 0;
            io_msg_block.BCW55_ChA_D0 = 0;
            io_msg_block.BCW56_ChA_D0 = 0;
            io_msg_block.BCW57_ChA_D0 = 0;
            io_msg_block.BCW58_ChA_D0 = 0;
            io_msg_block.BCW59_ChA_D0 = 0;
            io_msg_block.BCW5A_ChA_D0 = 0;
            io_msg_block.BCW5B_ChA_D0 = 0;
            io_msg_block.BCW5C_ChA_D0 = 0;
            io_msg_block.BCW5D_ChA_D0 = 0;
            io_msg_block.BCW5E_ChA_D0 = 0;
            io_msg_block.BCW5F_ChA_D0 = 0;
            io_msg_block.BCW60_ChA_D0 = 0;
            io_msg_block.BCW61_ChA_D0 = 0;
            io_msg_block.BCW62_ChA_D0 = 0;
            io_msg_block.BCW63_ChA_D0 = 0;
            io_msg_block.BCW64_ChA_D0 = 0;
            io_msg_block.BCW65_ChA_D0 = 0;
            io_msg_block.BCW66_ChA_D0 = 0;
            io_msg_block.BCW67_ChA_D0 = 0;
            io_msg_block.BCW68_ChA_D0 = 0;
            io_msg_block.BCW69_ChA_D0 = 0;
            io_msg_block.BCW6A_ChA_D0 = 0;
            io_msg_block.BCW6B_ChA_D0 = 0;
            io_msg_block.BCW6C_ChA_D0 = 0;
            io_msg_block.BCW6D_ChA_D0 = 0;
            io_msg_block.BCW6E_ChA_D0 = 0;
            io_msg_block.BCW6F_ChA_D0 = 0;
            io_msg_block.BCW70_ChA_D0 = 0;
            io_msg_block.BCW71_ChA_D0 = 0;
            io_msg_block.BCW72_ChA_D0 = 0;
            io_msg_block.BCW73_ChA_D0 = 0;
            io_msg_block.BCW74_ChA_D0 = 0;
            io_msg_block.BCW75_ChA_D0 = 0;
            io_msg_block.BCW76_ChA_D0 = 0;
            io_msg_block.BCW77_ChA_D0 = 0;
            io_msg_block.BCW78_ChA_D0 = 0;
            io_msg_block.BCW79_ChA_D0 = 0;
            io_msg_block.BCW7A_ChA_D0 = 0;
            io_msg_block.BCW7B_ChA_D0 = 0;
            io_msg_block.BCW7C_ChA_D0 = 0;
            io_msg_block.BCW7D_ChA_D0 = 0;
            io_msg_block.BCW7E_ChA_D0 = 0;
            io_msg_block.BCW7F_ChA_D0 = 0;

            io_msg_block.BCW00_ChB_D0 = 0;
            io_msg_block.BCW01_ChB_D0 = 0;
            io_msg_block.BCW02_ChB_D0 = 0;
            io_msg_block.BCW03_ChB_D0 = 0;
            io_msg_block.BCW04_ChB_D0 = 0;
            io_msg_block.BCW05_ChB_D0 = 0;
            io_msg_block.BCW06_ChB_D0 = 0;
            io_msg_block.BCW07_ChB_D0 = 0;
            io_msg_block.BCW08_ChB_D0 = 0;
            io_msg_block.BCW09_ChB_D0 = 0;
            io_msg_block.BCW0A_ChB_D0 = 0;
            io_msg_block.BCW0B_ChB_D0 = 0;
            io_msg_block.BCW0C_ChB_D0 = 0;
            io_msg_block.BCW0D_ChB_D0 = 0;
            io_msg_block.BCW0E_ChB_D0 = 0;
            io_msg_block.BCW0F_ChB_D0 = 0;
            io_msg_block.BCW10_ChB_D0 = 0;
            io_msg_block.BCW11_ChB_D0 = 0;
            io_msg_block.BCW12_ChB_D0 = 0;
            io_msg_block.BCW13_ChB_D0 = 0;
            io_msg_block.BCW14_ChB_D0 = 0;
            io_msg_block.BCW15_ChB_D0 = 0;
            io_msg_block.BCW16_ChB_D0 = 0;
            io_msg_block.BCW17_ChB_D0 = 0;
            io_msg_block.BCW18_ChB_D0 = 0;
            io_msg_block.BCW19_ChB_D0 = 0;
            io_msg_block.BCW1A_ChB_D0 = 0;
            io_msg_block.BCW1B_ChB_D0 = 0;
            io_msg_block.BCW1C_ChB_D0 = 0;
            io_msg_block.BCW1D_ChB_D0 = 0;
            io_msg_block.BCW1E_ChB_D0 = 0;
            io_msg_block.BCW1F_ChB_D0 = 0;
            io_msg_block.BCW20_ChB_D0 = 0;
            io_msg_block.BCW21_ChB_D0 = 0;
            io_msg_block.BCW22_ChB_D0 = 0;
            io_msg_block.BCW23_ChB_D0 = 0;
            io_msg_block.BCW24_ChB_D0 = 0;
            io_msg_block.BCW25_ChB_D0 = 0;
            io_msg_block.BCW26_ChB_D0 = 0;
            io_msg_block.BCW27_ChB_D0 = 0;
            io_msg_block.BCW28_ChB_D0 = 0;
            io_msg_block.BCW29_ChB_D0 = 0;
            io_msg_block.BCW2A_ChB_D0 = 0;
            io_msg_block.BCW2B_ChB_D0 = 0;
            io_msg_block.BCW2C_ChB_D0 = 0;
            io_msg_block.BCW2D_ChB_D0 = 0;
            io_msg_block.BCW2E_ChB_D0 = 0;
            io_msg_block.BCW2F_ChB_D0 = 0;
            io_msg_block.BCW30_ChB_D0 = 0;
            io_msg_block.BCW31_ChB_D0 = 0;
            io_msg_block.BCW32_ChB_D0 = 0;
            io_msg_block.BCW33_ChB_D0 = 0;
            io_msg_block.BCW34_ChB_D0 = 0;
            io_msg_block.BCW35_ChB_D0 = 0;
            io_msg_block.BCW36_ChB_D0 = 0;
            io_msg_block.BCW37_ChB_D0 = 0;
            io_msg_block.BCW38_ChB_D0 = 0;
            io_msg_block.BCW39_ChB_D0 = 0;
            io_msg_block.BCW3A_ChB_D0 = 0;
            io_msg_block.BCW3B_ChB_D0 = 0;
            io_msg_block.BCW3C_ChB_D0 = 0;
            io_msg_block.BCW3D_ChB_D0 = 0;
            io_msg_block.BCW3E_ChB_D0 = 0;
            io_msg_block.BCW3F_ChB_D0 = 0;
            io_msg_block.BCW40_ChB_D0 = 0;
            io_msg_block.BCW41_ChB_D0 = 0;
            io_msg_block.BCW42_ChB_D0 = 0;
            io_msg_block.BCW43_ChB_D0 = 0;
            io_msg_block.BCW44_ChB_D0 = 0;
            io_msg_block.BCW45_ChB_D0 = 0;
            io_msg_block.BCW46_ChB_D0 = 0;
            io_msg_block.BCW47_ChB_D0 = 0;
            io_msg_block.BCW48_ChB_D0 = 0;
            io_msg_block.BCW49_ChB_D0 = 0;
            io_msg_block.BCW4A_ChB_D0 = 0;
            io_msg_block.BCW4B_ChB_D0 = 0;
            io_msg_block.BCW4C_ChB_D0 = 0;
            io_msg_block.BCW4D_ChB_D0 = 0;
            io_msg_block.BCW4E_ChB_D0 = 0;
            io_msg_block.BCW4F_ChB_D0 = 0;
            io_msg_block.BCW50_ChB_D0 = 0;
            io_msg_block.BCW51_ChB_D0 = 0;
            io_msg_block.BCW52_ChB_D0 = 0;
            io_msg_block.BCW53_ChB_D0 = 0;
            io_msg_block.BCW54_ChB_D0 = 0;
            io_msg_block.BCW55_ChB_D0 = 0;
            io_msg_block.BCW56_ChB_D0 = 0;
            io_msg_block.BCW57_ChB_D0 = 0;
            io_msg_block.BCW58_ChB_D0 = 0;
            io_msg_block.BCW59_ChB_D0 = 0;
            io_msg_block.BCW5A_ChB_D0 = 0;
            io_msg_block.BCW5B_ChB_D0 = 0;
            io_msg_block.BCW5C_ChB_D0 = 0;
            io_msg_block.BCW5D_ChB_D0 = 0;
            io_msg_block.BCW5E_ChB_D0 = 0;
            io_msg_block.BCW5F_ChB_D0 = 0;
            io_msg_block.BCW60_ChB_D0 = 0;
            io_msg_block.BCW61_ChB_D0 = 0;
            io_msg_block.BCW62_ChB_D0 = 0;
            io_msg_block.BCW63_ChB_D0 = 0;
            io_msg_block.BCW64_ChB_D0 = 0;
            io_msg_block.BCW65_ChB_D0 = 0;
            io_msg_block.BCW66_ChB_D0 = 0;
            io_msg_block.BCW67_ChB_D0 = 0;
            io_msg_block.BCW68_ChB_D0 = 0;
            io_msg_block.BCW69_ChB_D0 = 0;
            io_msg_block.BCW6A_ChB_D0 = 0;
            io_msg_block.BCW6B_ChB_D0 = 0;
            io_msg_block.BCW6C_ChB_D0 = 0;
            io_msg_block.BCW6D_ChB_D0 = 0;
            io_msg_block.BCW6E_ChB_D0 = 0;
            io_msg_block.BCW6F_ChB_D0 = 0;
            io_msg_block.BCW70_ChB_D0 = 0;
            io_msg_block.BCW71_ChB_D0 = 0;
            io_msg_block.BCW72_ChB_D0 = 0;
            io_msg_block.BCW73_ChB_D0 = 0;
            io_msg_block.BCW74_ChB_D0 = 0;
            io_msg_block.BCW75_ChB_D0 = 0;
            io_msg_block.BCW76_ChB_D0 = 0;
            io_msg_block.BCW77_ChB_D0 = 0;
            io_msg_block.BCW78_ChB_D0 = 0;
            io_msg_block.BCW79_ChB_D0 = 0;
            io_msg_block.BCW7A_ChB_D0 = 0;
            io_msg_block.BCW7B_ChB_D0 = 0;
            io_msg_block.BCW7C_ChB_D0 = 0;
            io_msg_block.BCW7D_ChB_D0 = 0;
            io_msg_block.BCW7E_ChB_D0 = 0;
            io_msg_block.BCW7F_ChB_D0 = 0;

            io_msg_block.BCW00_ChA_D1 = 0;
            io_msg_block.BCW01_ChA_D1 = 0;
            io_msg_block.BCW02_ChA_D1 = 0;
            io_msg_block.BCW03_ChA_D1 = 0;
            io_msg_block.BCW04_ChA_D1 = 0;
            io_msg_block.BCW05_ChA_D1 = 0;
            io_msg_block.BCW06_ChA_D1 = 0;
            io_msg_block.BCW07_ChA_D1 = 0;
            io_msg_block.BCW08_ChA_D1 = 0;
            io_msg_block.BCW09_ChA_D1 = 0;
            io_msg_block.BCW0A_ChA_D1 = 0;
            io_msg_block.BCW0B_ChA_D1 = 0;
            io_msg_block.BCW0C_ChA_D1 = 0;
            io_msg_block.BCW0D_ChA_D1 = 0;
            io_msg_block.BCW0E_ChA_D1 = 0;
            io_msg_block.BCW0F_ChA_D1 = 0;
            io_msg_block.BCW10_ChA_D1 = 0;
            io_msg_block.BCW11_ChA_D1 = 0;
            io_msg_block.BCW12_ChA_D1 = 0;
            io_msg_block.BCW13_ChA_D1 = 0;
            io_msg_block.BCW14_ChA_D1 = 0;
            io_msg_block.BCW15_ChA_D1 = 0;
            io_msg_block.BCW16_ChA_D1 = 0;
            io_msg_block.BCW17_ChA_D1 = 0;
            io_msg_block.BCW18_ChA_D1 = 0;
            io_msg_block.BCW19_ChA_D1 = 0;
            io_msg_block.BCW1A_ChA_D1 = 0;
            io_msg_block.BCW1B_ChA_D1 = 0;
            io_msg_block.BCW1C_ChA_D1 = 0;
            io_msg_block.BCW1D_ChA_D1 = 0;
            io_msg_block.BCW1E_ChA_D1 = 0;
            io_msg_block.BCW1F_ChA_D1 = 0;
            io_msg_block.BCW20_ChA_D1 = 0;
            io_msg_block.BCW21_ChA_D1 = 0;
            io_msg_block.BCW22_ChA_D1 = 0;
            io_msg_block.BCW23_ChA_D1 = 0;
            io_msg_block.BCW24_ChA_D1 = 0;
            io_msg_block.BCW25_ChA_D1 = 0;
            io_msg_block.BCW26_ChA_D1 = 0;
            io_msg_block.BCW27_ChA_D1 = 0;
            io_msg_block.BCW28_ChA_D1 = 0;
            io_msg_block.BCW29_ChA_D1 = 0;
            io_msg_block.BCW2A_ChA_D1 = 0;
            io_msg_block.BCW2B_ChA_D1 = 0;
            io_msg_block.BCW2C_ChA_D1 = 0;
            io_msg_block.BCW2D_ChA_D1 = 0;
            io_msg_block.BCW2E_ChA_D1 = 0;
            io_msg_block.BCW2F_ChA_D1 = 0;
            io_msg_block.BCW30_ChA_D1 = 0;
            io_msg_block.BCW31_ChA_D1 = 0;
            io_msg_block.BCW32_ChA_D1 = 0;
            io_msg_block.BCW33_ChA_D1 = 0;
            io_msg_block.BCW34_ChA_D1 = 0;
            io_msg_block.BCW35_ChA_D1 = 0;
            io_msg_block.BCW36_ChA_D1 = 0;
            io_msg_block.BCW37_ChA_D1 = 0;
            io_msg_block.BCW38_ChA_D1 = 0;
            io_msg_block.BCW39_ChA_D1 = 0;
            io_msg_block.BCW3A_ChA_D1 = 0;
            io_msg_block.BCW3B_ChA_D1 = 0;
            io_msg_block.BCW3C_ChA_D1 = 0;
            io_msg_block.BCW3D_ChA_D1 = 0;
            io_msg_block.BCW3E_ChA_D1 = 0;
            io_msg_block.BCW3F_ChA_D1 = 0;
            io_msg_block.BCW40_ChA_D1 = 0;
            io_msg_block.BCW41_ChA_D1 = 0;
            io_msg_block.BCW42_ChA_D1 = 0;
            io_msg_block.BCW43_ChA_D1 = 0;
            io_msg_block.BCW44_ChA_D1 = 0;
            io_msg_block.BCW45_ChA_D1 = 0;
            io_msg_block.BCW46_ChA_D1 = 0;
            io_msg_block.BCW47_ChA_D1 = 0;
            io_msg_block.BCW48_ChA_D1 = 0;
            io_msg_block.BCW49_ChA_D1 = 0;
            io_msg_block.BCW4A_ChA_D1 = 0;
            io_msg_block.BCW4B_ChA_D1 = 0;
            io_msg_block.BCW4C_ChA_D1 = 0;
            io_msg_block.BCW4D_ChA_D1 = 0;
            io_msg_block.BCW4E_ChA_D1 = 0;
            io_msg_block.BCW4F_ChA_D1 = 0;
            io_msg_block.BCW50_ChA_D1 = 0;
            io_msg_block.BCW51_ChA_D1 = 0;
            io_msg_block.BCW52_ChA_D1 = 0;
            io_msg_block.BCW53_ChA_D1 = 0;
            io_msg_block.BCW54_ChA_D1 = 0;
            io_msg_block.BCW55_ChA_D1 = 0;
            io_msg_block.BCW56_ChA_D1 = 0;
            io_msg_block.BCW57_ChA_D1 = 0;
            io_msg_block.BCW58_ChA_D1 = 0;
            io_msg_block.BCW59_ChA_D1 = 0;
            io_msg_block.BCW5A_ChA_D1 = 0;
            io_msg_block.BCW5B_ChA_D1 = 0;
            io_msg_block.BCW5C_ChA_D1 = 0;
            io_msg_block.BCW5D_ChA_D1 = 0;
            io_msg_block.BCW5E_ChA_D1 = 0;
            io_msg_block.BCW5F_ChA_D1 = 0;
            io_msg_block.BCW60_ChA_D1 = 0;
            io_msg_block.BCW61_ChA_D1 = 0;
            io_msg_block.BCW62_ChA_D1 = 0;
            io_msg_block.BCW63_ChA_D1 = 0;
            io_msg_block.BCW64_ChA_D1 = 0;
            io_msg_block.BCW65_ChA_D1 = 0;
            io_msg_block.BCW66_ChA_D1 = 0;
            io_msg_block.BCW67_ChA_D1 = 0;
            io_msg_block.BCW68_ChA_D1 = 0;
            io_msg_block.BCW69_ChA_D1 = 0;
            io_msg_block.BCW6A_ChA_D1 = 0;
            io_msg_block.BCW6B_ChA_D1 = 0;
            io_msg_block.BCW6C_ChA_D1 = 0;
            io_msg_block.BCW6D_ChA_D1 = 0;
            io_msg_block.BCW6E_ChA_D1 = 0;
            io_msg_block.BCW6F_ChA_D1 = 0;
            io_msg_block.BCW70_ChA_D1 = 0;
            io_msg_block.BCW71_ChA_D1 = 0;
            io_msg_block.BCW72_ChA_D1 = 0;
            io_msg_block.BCW73_ChA_D1 = 0;
            io_msg_block.BCW74_ChA_D1 = 0;
            io_msg_block.BCW75_ChA_D1 = 0;
            io_msg_block.BCW76_ChA_D1 = 0;
            io_msg_block.BCW77_ChA_D1 = 0;
            io_msg_block.BCW78_ChA_D1 = 0;
            io_msg_block.BCW79_ChA_D1 = 0;
            io_msg_block.BCW7A_ChA_D1 = 0;
            io_msg_block.BCW7B_ChA_D1 = 0;
            io_msg_block.BCW7C_ChA_D1 = 0;
            io_msg_block.BCW7D_ChA_D1 = 0;
            io_msg_block.BCW7E_ChA_D1 = 0;
            io_msg_block.BCW7F_ChA_D1 = 0;

            io_msg_block.BCW00_ChB_D1 = 0;
            io_msg_block.BCW01_ChB_D1 = 0;
            io_msg_block.BCW02_ChB_D1 = 0;
            io_msg_block.BCW03_ChB_D1 = 0;
            io_msg_block.BCW04_ChB_D1 = 0;
            io_msg_block.BCW05_ChB_D1 = 0;
            io_msg_block.BCW06_ChB_D1 = 0;
            io_msg_block.BCW07_ChB_D1 = 0;
            io_msg_block.BCW08_ChB_D1 = 0;
            io_msg_block.BCW09_ChB_D1 = 0;
            io_msg_block.BCW0A_ChB_D1 = 0;
            io_msg_block.BCW0B_ChB_D1 = 0;
            io_msg_block.BCW0C_ChB_D1 = 0;
            io_msg_block.BCW0D_ChB_D1 = 0;
            io_msg_block.BCW0E_ChB_D1 = 0;
            io_msg_block.BCW0F_ChB_D1 = 0;
            io_msg_block.BCW10_ChB_D1 = 0;
            io_msg_block.BCW11_ChB_D1 = 0;
            io_msg_block.BCW12_ChB_D1 = 0;
            io_msg_block.BCW13_ChB_D1 = 0;
            io_msg_block.BCW14_ChB_D1 = 0;
            io_msg_block.BCW15_ChB_D1 = 0;
            io_msg_block.BCW16_ChB_D1 = 0;
            io_msg_block.BCW17_ChB_D1 = 0;
            io_msg_block.BCW18_ChB_D1 = 0;
            io_msg_block.BCW19_ChB_D1 = 0;
            io_msg_block.BCW1A_ChB_D1 = 0;
            io_msg_block.BCW1B_ChB_D1 = 0;
            io_msg_block.BCW1C_ChB_D1 = 0;
            io_msg_block.BCW1D_ChB_D1 = 0;
            io_msg_block.BCW1E_ChB_D1 = 0;
            io_msg_block.BCW1F_ChB_D1 = 0;
            io_msg_block.BCW20_ChB_D1 = 0;
            io_msg_block.BCW21_ChB_D1 = 0;
            io_msg_block.BCW22_ChB_D1 = 0;
            io_msg_block.BCW23_ChB_D1 = 0;
            io_msg_block.BCW24_ChB_D1 = 0;
            io_msg_block.BCW25_ChB_D1 = 0;
            io_msg_block.BCW26_ChB_D1 = 0;
            io_msg_block.BCW27_ChB_D1 = 0;
            io_msg_block.BCW28_ChB_D1 = 0;
            io_msg_block.BCW29_ChB_D1 = 0;
            io_msg_block.BCW2A_ChB_D1 = 0;
            io_msg_block.BCW2B_ChB_D1 = 0;
            io_msg_block.BCW2C_ChB_D1 = 0;
            io_msg_block.BCW2D_ChB_D1 = 0;
            io_msg_block.BCW2E_ChB_D1 = 0;
            io_msg_block.BCW2F_ChB_D1 = 0;
            io_msg_block.BCW30_ChB_D1 = 0;
            io_msg_block.BCW31_ChB_D1 = 0;
            io_msg_block.BCW32_ChB_D1 = 0;
            io_msg_block.BCW33_ChB_D1 = 0;
            io_msg_block.BCW34_ChB_D1 = 0;
            io_msg_block.BCW35_ChB_D1 = 0;
            io_msg_block.BCW36_ChB_D1 = 0;
            io_msg_block.BCW37_ChB_D1 = 0;
            io_msg_block.BCW38_ChB_D1 = 0;
            io_msg_block.BCW39_ChB_D1 = 0;
            io_msg_block.BCW3A_ChB_D1 = 0;
            io_msg_block.BCW3B_ChB_D1 = 0;
            io_msg_block.BCW3C_ChB_D1 = 0;
            io_msg_block.BCW3D_ChB_D1 = 0;
            io_msg_block.BCW3E_ChB_D1 = 0;
            io_msg_block.BCW3F_ChB_D1 = 0;
            io_msg_block.BCW40_ChB_D1 = 0;
            io_msg_block.BCW41_ChB_D1 = 0;
            io_msg_block.BCW42_ChB_D1 = 0;
            io_msg_block.BCW43_ChB_D1 = 0;
            io_msg_block.BCW44_ChB_D1 = 0;
            io_msg_block.BCW45_ChB_D1 = 0;
            io_msg_block.BCW46_ChB_D1 = 0;
            io_msg_block.BCW47_ChB_D1 = 0;
            io_msg_block.BCW48_ChB_D1 = 0;
            io_msg_block.BCW49_ChB_D1 = 0;
            io_msg_block.BCW4A_ChB_D1 = 0;
            io_msg_block.BCW4B_ChB_D1 = 0;
            io_msg_block.BCW4C_ChB_D1 = 0;
            io_msg_block.BCW4D_ChB_D1 = 0;
            io_msg_block.BCW4E_ChB_D1 = 0;
            io_msg_block.BCW4F_ChB_D1 = 0;
            io_msg_block.BCW50_ChB_D1 = 0;
            io_msg_block.BCW51_ChB_D1 = 0;
            io_msg_block.BCW52_ChB_D1 = 0;
            io_msg_block.BCW53_ChB_D1 = 0;
            io_msg_block.BCW54_ChB_D1 = 0;
            io_msg_block.BCW55_ChB_D1 = 0;
            io_msg_block.BCW56_ChB_D1 = 0;
            io_msg_block.BCW57_ChB_D1 = 0;
            io_msg_block.BCW58_ChB_D1 = 0;
            io_msg_block.BCW59_ChB_D1 = 0;
            io_msg_block.BCW5A_ChB_D1 = 0;
            io_msg_block.BCW5B_ChB_D1 = 0;
            io_msg_block.BCW5C_ChB_D1 = 0;
            io_msg_block.BCW5D_ChB_D1 = 0;
            io_msg_block.BCW5E_ChB_D1 = 0;
            io_msg_block.BCW5F_ChB_D1 = 0;
            io_msg_block.BCW60_ChB_D1 = 0;
            io_msg_block.BCW61_ChB_D1 = 0;
            io_msg_block.BCW62_ChB_D1 = 0;
            io_msg_block.BCW63_ChB_D1 = 0;
            io_msg_block.BCW64_ChB_D1 = 0;
            io_msg_block.BCW65_ChB_D1 = 0;
            io_msg_block.BCW66_ChB_D1 = 0;
            io_msg_block.BCW67_ChB_D1 = 0;
            io_msg_block.BCW68_ChB_D1 = 0;
            io_msg_block.BCW69_ChB_D1 = 0;
            io_msg_block.BCW6A_ChB_D1 = 0;
            io_msg_block.BCW6B_ChB_D1 = 0;
            io_msg_block.BCW6C_ChB_D1 = 0;
            io_msg_block.BCW6D_ChB_D1 = 0;
            io_msg_block.BCW6E_ChB_D1 = 0;
            io_msg_block.BCW6F_ChB_D1 = 0;
            io_msg_block.BCW70_ChB_D1 = 0;
            io_msg_block.BCW71_ChB_D1 = 0;
            io_msg_block.BCW72_ChB_D1 = 0;
            io_msg_block.BCW73_ChB_D1 = 0;
            io_msg_block.BCW74_ChB_D1 = 0;
            io_msg_block.BCW75_ChB_D1 = 0;
            io_msg_block.BCW76_ChB_D1 = 0;
            io_msg_block.BCW77_ChB_D1 = 0;
            io_msg_block.BCW78_ChB_D1 = 0;
            io_msg_block.BCW79_ChB_D1 = 0;
            io_msg_block.BCW7A_ChB_D1 = 0;
            io_msg_block.BCW7B_ChB_D1 = 0;
            io_msg_block.BCW7C_ChB_D1 = 0;
            io_msg_block.BCW7D_ChB_D1 = 0;
            io_msg_block.BCW7E_ChB_D1 = 0;
            io_msg_block.BCW7F_ChB_D1 = 0;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter WL_ADJ_START
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_WL_ADJ_START(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.WL_ADJ_START = iv_msg_block_vars.iv_WL_ADJ_START;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameter WL_ADJ_END
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_WL_ADJ_END(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.WL_ADJ_END = iv_msg_block_vars.iv_WL_ADJ_END;

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameters VrefDqR[RANK]Nib[DRAM]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_VrefDq(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.VrefDqR0Nib0 = iv_msg_block_vars.iv_MR10[0][0];
            io_msg_block.VrefDqR0Nib1 = iv_msg_block_vars.iv_MR10[0][1];
            io_msg_block.VrefDqR0Nib2 = iv_msg_block_vars.iv_MR10[0][2];
            io_msg_block.VrefDqR0Nib3 = iv_msg_block_vars.iv_MR10[0][3];
            io_msg_block.VrefDqR0Nib4 = iv_msg_block_vars.iv_MR10[0][4];
            io_msg_block.VrefDqR0Nib5 = iv_msg_block_vars.iv_MR10[0][5];
            io_msg_block.VrefDqR0Nib6 = iv_msg_block_vars.iv_MR10[0][6];
            io_msg_block.VrefDqR0Nib7 = iv_msg_block_vars.iv_MR10[0][7];
            io_msg_block.VrefDqR0Nib8 = iv_msg_block_vars.iv_MR10[0][8];
            io_msg_block.VrefDqR0Nib9 = iv_msg_block_vars.iv_MR10[0][9];
            io_msg_block.VrefDqR0Nib10 = iv_msg_block_vars.iv_MR10[0][10];
            io_msg_block.VrefDqR0Nib11 = iv_msg_block_vars.iv_MR10[0][11];
            io_msg_block.VrefDqR0Nib12 = iv_msg_block_vars.iv_MR10[0][12];
            io_msg_block.VrefDqR0Nib13 = iv_msg_block_vars.iv_MR10[0][13];
            io_msg_block.VrefDqR0Nib14 = iv_msg_block_vars.iv_MR10[0][14];
            io_msg_block.VrefDqR0Nib15 = iv_msg_block_vars.iv_MR10[0][15];
            io_msg_block.VrefDqR0Nib16 = iv_msg_block_vars.iv_MR10[0][16];
            io_msg_block.VrefDqR0Nib17 = iv_msg_block_vars.iv_MR10[0][17];
            io_msg_block.VrefDqR0Nib18 = iv_msg_block_vars.iv_MR10[0][18];
            io_msg_block.VrefDqR0Nib19 = iv_msg_block_vars.iv_MR10[0][19];

            io_msg_block.VrefDqR1Nib0 = iv_msg_block_vars.iv_MR10[1][0];
            io_msg_block.VrefDqR1Nib1 = iv_msg_block_vars.iv_MR10[1][1];
            io_msg_block.VrefDqR1Nib2 = iv_msg_block_vars.iv_MR10[1][2];
            io_msg_block.VrefDqR1Nib3 = iv_msg_block_vars.iv_MR10[1][3];
            io_msg_block.VrefDqR1Nib4 = iv_msg_block_vars.iv_MR10[1][4];
            io_msg_block.VrefDqR1Nib5 = iv_msg_block_vars.iv_MR10[1][5];
            io_msg_block.VrefDqR1Nib6 = iv_msg_block_vars.iv_MR10[1][6];
            io_msg_block.VrefDqR1Nib7 = iv_msg_block_vars.iv_MR10[1][7];
            io_msg_block.VrefDqR1Nib8 = iv_msg_block_vars.iv_MR10[1][8];
            io_msg_block.VrefDqR1Nib9 = iv_msg_block_vars.iv_MR10[1][9];
            io_msg_block.VrefDqR1Nib10 = iv_msg_block_vars.iv_MR10[1][10];
            io_msg_block.VrefDqR1Nib11 = iv_msg_block_vars.iv_MR10[1][11];
            io_msg_block.VrefDqR1Nib12 = iv_msg_block_vars.iv_MR10[1][12];
            io_msg_block.VrefDqR1Nib13 = iv_msg_block_vars.iv_MR10[1][13];
            io_msg_block.VrefDqR1Nib14 = iv_msg_block_vars.iv_MR10[1][14];
            io_msg_block.VrefDqR1Nib15 = iv_msg_block_vars.iv_MR10[1][15];
            io_msg_block.VrefDqR1Nib16 = iv_msg_block_vars.iv_MR10[1][16];
            io_msg_block.VrefDqR1Nib17 = iv_msg_block_vars.iv_MR10[1][17];
            io_msg_block.VrefDqR1Nib18 = iv_msg_block_vars.iv_MR10[1][18];
            io_msg_block.VrefDqR1Nib19 = iv_msg_block_vars.iv_MR10[1][19];

            io_msg_block.VrefDqR2Nib0 = iv_msg_block_vars.iv_MR10[2][0];
            io_msg_block.VrefDqR2Nib1 = iv_msg_block_vars.iv_MR10[2][1];
            io_msg_block.VrefDqR2Nib2 = iv_msg_block_vars.iv_MR10[2][2];
            io_msg_block.VrefDqR2Nib3 = iv_msg_block_vars.iv_MR10[2][3];
            io_msg_block.VrefDqR2Nib4 = iv_msg_block_vars.iv_MR10[2][4];
            io_msg_block.VrefDqR2Nib5 = iv_msg_block_vars.iv_MR10[2][5];
            io_msg_block.VrefDqR2Nib6 = iv_msg_block_vars.iv_MR10[2][6];
            io_msg_block.VrefDqR2Nib7 = iv_msg_block_vars.iv_MR10[2][7];
            io_msg_block.VrefDqR2Nib8 = iv_msg_block_vars.iv_MR10[2][8];
            io_msg_block.VrefDqR2Nib9 = iv_msg_block_vars.iv_MR10[2][9];
            io_msg_block.VrefDqR2Nib10 = iv_msg_block_vars.iv_MR10[2][10];
            io_msg_block.VrefDqR2Nib11 = iv_msg_block_vars.iv_MR10[2][11];
            io_msg_block.VrefDqR2Nib12 = iv_msg_block_vars.iv_MR10[2][12];
            io_msg_block.VrefDqR2Nib13 = iv_msg_block_vars.iv_MR10[2][13];
            io_msg_block.VrefDqR2Nib14 = iv_msg_block_vars.iv_MR10[2][14];
            io_msg_block.VrefDqR2Nib15 = iv_msg_block_vars.iv_MR10[2][15];
            io_msg_block.VrefDqR2Nib16 = iv_msg_block_vars.iv_MR10[2][16];
            io_msg_block.VrefDqR2Nib17 = iv_msg_block_vars.iv_MR10[2][17];
            io_msg_block.VrefDqR2Nib18 = iv_msg_block_vars.iv_MR10[2][18];
            io_msg_block.VrefDqR2Nib19 = iv_msg_block_vars.iv_MR10[2][19];

            io_msg_block.VrefDqR3Nib0 = iv_msg_block_vars.iv_MR10[3][0];
            io_msg_block.VrefDqR3Nib1 = iv_msg_block_vars.iv_MR10[3][1];
            io_msg_block.VrefDqR3Nib2 = iv_msg_block_vars.iv_MR10[3][2];
            io_msg_block.VrefDqR3Nib3 = iv_msg_block_vars.iv_MR10[3][3];
            io_msg_block.VrefDqR3Nib4 = iv_msg_block_vars.iv_MR10[3][4];
            io_msg_block.VrefDqR3Nib5 = iv_msg_block_vars.iv_MR10[3][5];
            io_msg_block.VrefDqR3Nib6 = iv_msg_block_vars.iv_MR10[3][6];
            io_msg_block.VrefDqR3Nib7 = iv_msg_block_vars.iv_MR10[3][7];
            io_msg_block.VrefDqR3Nib8 = iv_msg_block_vars.iv_MR10[3][8];
            io_msg_block.VrefDqR3Nib9 = iv_msg_block_vars.iv_MR10[3][9];
            io_msg_block.VrefDqR3Nib10 = iv_msg_block_vars.iv_MR10[3][10];
            io_msg_block.VrefDqR3Nib11 = iv_msg_block_vars.iv_MR10[3][11];
            io_msg_block.VrefDqR3Nib12 = iv_msg_block_vars.iv_MR10[3][12];
            io_msg_block.VrefDqR3Nib13 = iv_msg_block_vars.iv_MR10[3][13];
            io_msg_block.VrefDqR3Nib14 = iv_msg_block_vars.iv_MR10[3][14];
            io_msg_block.VrefDqR3Nib15 = iv_msg_block_vars.iv_MR10[3][15];
            io_msg_block.VrefDqR3Nib16 = iv_msg_block_vars.iv_MR10[3][16];
            io_msg_block.VrefDqR3Nib17 = iv_msg_block_vars.iv_MR10[3][17];
            io_msg_block.VrefDqR3Nib18 = iv_msg_block_vars.iv_MR10[3][18];
            io_msg_block.VrefDqR3Nib19 = iv_msg_block_vars.iv_MR10[3][19];

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameters MR3R[RANK]Nib[DRAM]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_MR3_per_dram(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.MR3R0Nib0 = iv_msg_block_vars.iv_MR3[0][0];
            io_msg_block.MR3R0Nib1 = iv_msg_block_vars.iv_MR3[0][1];
            io_msg_block.MR3R0Nib2 = iv_msg_block_vars.iv_MR3[0][2];
            io_msg_block.MR3R0Nib3 = iv_msg_block_vars.iv_MR3[0][3];
            io_msg_block.MR3R0Nib4 = iv_msg_block_vars.iv_MR3[0][4];
            io_msg_block.MR3R0Nib5 = iv_msg_block_vars.iv_MR3[0][5];
            io_msg_block.MR3R0Nib6 = iv_msg_block_vars.iv_MR3[0][6];
            io_msg_block.MR3R0Nib7 = iv_msg_block_vars.iv_MR3[0][7];
            io_msg_block.MR3R0Nib8 = iv_msg_block_vars.iv_MR3[0][8];
            io_msg_block.MR3R0Nib9 = iv_msg_block_vars.iv_MR3[0][9];
            io_msg_block.MR3R0Nib10 = iv_msg_block_vars.iv_MR3[0][10];
            io_msg_block.MR3R0Nib11 = iv_msg_block_vars.iv_MR3[0][11];
            io_msg_block.MR3R0Nib12 = iv_msg_block_vars.iv_MR3[0][12];
            io_msg_block.MR3R0Nib13 = iv_msg_block_vars.iv_MR3[0][13];
            io_msg_block.MR3R0Nib14 = iv_msg_block_vars.iv_MR3[0][14];
            io_msg_block.MR3R0Nib15 = iv_msg_block_vars.iv_MR3[0][15];
            io_msg_block.MR3R0Nib16 = iv_msg_block_vars.iv_MR3[0][16];
            io_msg_block.MR3R0Nib17 = iv_msg_block_vars.iv_MR3[0][17];
            io_msg_block.MR3R0Nib18 = iv_msg_block_vars.iv_MR3[0][18];
            io_msg_block.MR3R0Nib19 = iv_msg_block_vars.iv_MR3[0][19];

            io_msg_block.MR3R1Nib0 = iv_msg_block_vars.iv_MR3[1][0];
            io_msg_block.MR3R1Nib1 = iv_msg_block_vars.iv_MR3[1][1];
            io_msg_block.MR3R1Nib2 = iv_msg_block_vars.iv_MR3[1][2];
            io_msg_block.MR3R1Nib3 = iv_msg_block_vars.iv_MR3[1][3];
            io_msg_block.MR3R1Nib4 = iv_msg_block_vars.iv_MR3[1][4];
            io_msg_block.MR3R1Nib5 = iv_msg_block_vars.iv_MR3[1][5];
            io_msg_block.MR3R1Nib6 = iv_msg_block_vars.iv_MR3[1][6];
            io_msg_block.MR3R1Nib7 = iv_msg_block_vars.iv_MR3[1][7];
            io_msg_block.MR3R1Nib8 = iv_msg_block_vars.iv_MR3[1][8];
            io_msg_block.MR3R1Nib9 = iv_msg_block_vars.iv_MR3[1][9];
            io_msg_block.MR3R1Nib10 = iv_msg_block_vars.iv_MR3[1][10];
            io_msg_block.MR3R1Nib11 = iv_msg_block_vars.iv_MR3[1][11];
            io_msg_block.MR3R1Nib12 = iv_msg_block_vars.iv_MR3[1][12];
            io_msg_block.MR3R1Nib13 = iv_msg_block_vars.iv_MR3[1][13];
            io_msg_block.MR3R1Nib14 = iv_msg_block_vars.iv_MR3[1][14];
            io_msg_block.MR3R1Nib15 = iv_msg_block_vars.iv_MR3[1][15];
            io_msg_block.MR3R1Nib16 = iv_msg_block_vars.iv_MR3[1][16];
            io_msg_block.MR3R1Nib17 = iv_msg_block_vars.iv_MR3[1][17];
            io_msg_block.MR3R1Nib18 = iv_msg_block_vars.iv_MR3[1][18];
            io_msg_block.MR3R1Nib19 = iv_msg_block_vars.iv_MR3[1][19];

            io_msg_block.MR3R2Nib0 = iv_msg_block_vars.iv_MR3[2][0];
            io_msg_block.MR3R2Nib1 = iv_msg_block_vars.iv_MR3[2][1];
            io_msg_block.MR3R2Nib2 = iv_msg_block_vars.iv_MR3[2][2];
            io_msg_block.MR3R2Nib3 = iv_msg_block_vars.iv_MR3[2][3];
            io_msg_block.MR3R2Nib4 = iv_msg_block_vars.iv_MR3[2][4];
            io_msg_block.MR3R2Nib5 = iv_msg_block_vars.iv_MR3[2][5];
            io_msg_block.MR3R2Nib6 = iv_msg_block_vars.iv_MR3[2][6];
            io_msg_block.MR3R2Nib7 = iv_msg_block_vars.iv_MR3[2][7];
            io_msg_block.MR3R2Nib8 = iv_msg_block_vars.iv_MR3[2][8];
            io_msg_block.MR3R2Nib9 = iv_msg_block_vars.iv_MR3[2][9];
            io_msg_block.MR3R2Nib10 = iv_msg_block_vars.iv_MR3[2][10];
            io_msg_block.MR3R2Nib11 = iv_msg_block_vars.iv_MR3[2][11];
            io_msg_block.MR3R2Nib12 = iv_msg_block_vars.iv_MR3[2][12];
            io_msg_block.MR3R2Nib13 = iv_msg_block_vars.iv_MR3[2][13];
            io_msg_block.MR3R2Nib14 = iv_msg_block_vars.iv_MR3[2][14];
            io_msg_block.MR3R2Nib15 = iv_msg_block_vars.iv_MR3[2][15];
            io_msg_block.MR3R2Nib16 = iv_msg_block_vars.iv_MR3[2][16];
            io_msg_block.MR3R2Nib17 = iv_msg_block_vars.iv_MR3[2][17];
            io_msg_block.MR3R2Nib18 = iv_msg_block_vars.iv_MR3[2][18];
            io_msg_block.MR3R2Nib19 = iv_msg_block_vars.iv_MR3[2][19];

            io_msg_block.MR3R3Nib0 = iv_msg_block_vars.iv_MR3[3][0];
            io_msg_block.MR3R3Nib1 = iv_msg_block_vars.iv_MR3[3][1];
            io_msg_block.MR3R3Nib2 = iv_msg_block_vars.iv_MR3[3][2];
            io_msg_block.MR3R3Nib3 = iv_msg_block_vars.iv_MR3[3][3];
            io_msg_block.MR3R3Nib4 = iv_msg_block_vars.iv_MR3[3][4];
            io_msg_block.MR3R3Nib5 = iv_msg_block_vars.iv_MR3[3][5];
            io_msg_block.MR3R3Nib6 = iv_msg_block_vars.iv_MR3[3][6];
            io_msg_block.MR3R3Nib7 = iv_msg_block_vars.iv_MR3[3][7];
            io_msg_block.MR3R3Nib8 = iv_msg_block_vars.iv_MR3[3][8];
            io_msg_block.MR3R3Nib9 = iv_msg_block_vars.iv_MR3[3][9];
            io_msg_block.MR3R3Nib10 = iv_msg_block_vars.iv_MR3[3][10];
            io_msg_block.MR3R3Nib11 = iv_msg_block_vars.iv_MR3[3][11];
            io_msg_block.MR3R3Nib12 = iv_msg_block_vars.iv_MR3[3][12];
            io_msg_block.MR3R3Nib13 = iv_msg_block_vars.iv_MR3[3][13];
            io_msg_block.MR3R3Nib14 = iv_msg_block_vars.iv_MR3[3][14];
            io_msg_block.MR3R3Nib15 = iv_msg_block_vars.iv_MR3[3][15];
            io_msg_block.MR3R3Nib16 = iv_msg_block_vars.iv_MR3[3][16];
            io_msg_block.MR3R3Nib17 = iv_msg_block_vars.iv_MR3[3][17];
            io_msg_block.MR3R3Nib18 = iv_msg_block_vars.iv_MR3[3][18];
            io_msg_block.MR3R3Nib19 = iv_msg_block_vars.iv_MR3[3][19];

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameters VrefCSR[RANK]Nib[DRAM]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_VrefCS(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.VrefCSR0Nib0 = iv_msg_block_vars.iv_MR12[0][0];
            io_msg_block.VrefCSR0Nib1 = iv_msg_block_vars.iv_MR12[0][1];
            io_msg_block.VrefCSR0Nib2 = iv_msg_block_vars.iv_MR12[0][2];
            io_msg_block.VrefCSR0Nib3 = iv_msg_block_vars.iv_MR12[0][3];
            io_msg_block.VrefCSR0Nib4 = iv_msg_block_vars.iv_MR12[0][4];
            io_msg_block.VrefCSR0Nib5 = iv_msg_block_vars.iv_MR12[0][5];
            io_msg_block.VrefCSR0Nib6 = iv_msg_block_vars.iv_MR12[0][6];
            io_msg_block.VrefCSR0Nib7 = iv_msg_block_vars.iv_MR12[0][7];
            io_msg_block.VrefCSR0Nib8 = iv_msg_block_vars.iv_MR12[0][8];
            io_msg_block.VrefCSR0Nib9 = iv_msg_block_vars.iv_MR12[0][9];
            io_msg_block.VrefCSR0Nib10 = iv_msg_block_vars.iv_MR12[0][10];
            io_msg_block.VrefCSR0Nib11 = iv_msg_block_vars.iv_MR12[0][11];
            io_msg_block.VrefCSR0Nib12 = iv_msg_block_vars.iv_MR12[0][12];
            io_msg_block.VrefCSR0Nib13 = iv_msg_block_vars.iv_MR12[0][13];
            io_msg_block.VrefCSR0Nib14 = iv_msg_block_vars.iv_MR12[0][14];
            io_msg_block.VrefCSR0Nib15 = iv_msg_block_vars.iv_MR12[0][15];
            io_msg_block.VrefCSR0Nib16 = iv_msg_block_vars.iv_MR12[0][16];
            io_msg_block.VrefCSR0Nib17 = iv_msg_block_vars.iv_MR12[0][17];
            io_msg_block.VrefCSR0Nib18 = iv_msg_block_vars.iv_MR12[0][18];
            io_msg_block.VrefCSR0Nib19 = iv_msg_block_vars.iv_MR12[0][19];

            io_msg_block.VrefCSR1Nib0 = iv_msg_block_vars.iv_MR12[1][0];
            io_msg_block.VrefCSR1Nib1 = iv_msg_block_vars.iv_MR12[1][1];
            io_msg_block.VrefCSR1Nib2 = iv_msg_block_vars.iv_MR12[1][2];
            io_msg_block.VrefCSR1Nib3 = iv_msg_block_vars.iv_MR12[1][3];
            io_msg_block.VrefCSR1Nib4 = iv_msg_block_vars.iv_MR12[1][4];
            io_msg_block.VrefCSR1Nib5 = iv_msg_block_vars.iv_MR12[1][5];
            io_msg_block.VrefCSR1Nib6 = iv_msg_block_vars.iv_MR12[1][6];
            io_msg_block.VrefCSR1Nib7 = iv_msg_block_vars.iv_MR12[1][7];
            io_msg_block.VrefCSR1Nib8 = iv_msg_block_vars.iv_MR12[1][8];
            io_msg_block.VrefCSR1Nib9 = iv_msg_block_vars.iv_MR12[1][9];
            io_msg_block.VrefCSR1Nib10 = iv_msg_block_vars.iv_MR12[1][10];
            io_msg_block.VrefCSR1Nib11 = iv_msg_block_vars.iv_MR12[1][11];
            io_msg_block.VrefCSR1Nib12 = iv_msg_block_vars.iv_MR12[1][12];
            io_msg_block.VrefCSR1Nib13 = iv_msg_block_vars.iv_MR12[1][13];
            io_msg_block.VrefCSR1Nib14 = iv_msg_block_vars.iv_MR12[1][14];
            io_msg_block.VrefCSR1Nib15 = iv_msg_block_vars.iv_MR12[1][15];
            io_msg_block.VrefCSR1Nib16 = iv_msg_block_vars.iv_MR12[1][16];
            io_msg_block.VrefCSR1Nib17 = iv_msg_block_vars.iv_MR12[1][17];
            io_msg_block.VrefCSR1Nib18 = iv_msg_block_vars.iv_MR12[1][18];
            io_msg_block.VrefCSR1Nib19 = iv_msg_block_vars.iv_MR12[1][19];

            io_msg_block.VrefCSR2Nib0 = iv_msg_block_vars.iv_MR12[2][0];
            io_msg_block.VrefCSR2Nib1 = iv_msg_block_vars.iv_MR12[2][1];
            io_msg_block.VrefCSR2Nib2 = iv_msg_block_vars.iv_MR12[2][2];
            io_msg_block.VrefCSR2Nib3 = iv_msg_block_vars.iv_MR12[2][3];
            io_msg_block.VrefCSR2Nib4 = iv_msg_block_vars.iv_MR12[2][4];
            io_msg_block.VrefCSR2Nib5 = iv_msg_block_vars.iv_MR12[2][5];
            io_msg_block.VrefCSR2Nib6 = iv_msg_block_vars.iv_MR12[2][6];
            io_msg_block.VrefCSR2Nib7 = iv_msg_block_vars.iv_MR12[2][7];
            io_msg_block.VrefCSR2Nib8 = iv_msg_block_vars.iv_MR12[2][8];
            io_msg_block.VrefCSR2Nib9 = iv_msg_block_vars.iv_MR12[2][9];
            io_msg_block.VrefCSR2Nib10 = iv_msg_block_vars.iv_MR12[2][10];
            io_msg_block.VrefCSR2Nib11 = iv_msg_block_vars.iv_MR12[2][11];
            io_msg_block.VrefCSR2Nib12 = iv_msg_block_vars.iv_MR12[2][12];
            io_msg_block.VrefCSR2Nib13 = iv_msg_block_vars.iv_MR12[2][13];
            io_msg_block.VrefCSR2Nib14 = iv_msg_block_vars.iv_MR12[2][14];
            io_msg_block.VrefCSR2Nib15 = iv_msg_block_vars.iv_MR12[2][15];
            io_msg_block.VrefCSR2Nib16 = iv_msg_block_vars.iv_MR12[2][16];
            io_msg_block.VrefCSR2Nib17 = iv_msg_block_vars.iv_MR12[2][17];
            io_msg_block.VrefCSR2Nib18 = iv_msg_block_vars.iv_MR12[2][18];
            io_msg_block.VrefCSR2Nib19 = iv_msg_block_vars.iv_MR12[2][19];

            io_msg_block.VrefCSR3Nib0 = iv_msg_block_vars.iv_MR12[3][0];
            io_msg_block.VrefCSR3Nib1 = iv_msg_block_vars.iv_MR12[3][1];
            io_msg_block.VrefCSR3Nib2 = iv_msg_block_vars.iv_MR12[3][2];
            io_msg_block.VrefCSR3Nib3 = iv_msg_block_vars.iv_MR12[3][3];
            io_msg_block.VrefCSR3Nib4 = iv_msg_block_vars.iv_MR12[3][4];
            io_msg_block.VrefCSR3Nib5 = iv_msg_block_vars.iv_MR12[3][5];
            io_msg_block.VrefCSR3Nib6 = iv_msg_block_vars.iv_MR12[3][6];
            io_msg_block.VrefCSR3Nib7 = iv_msg_block_vars.iv_MR12[3][7];
            io_msg_block.VrefCSR3Nib8 = iv_msg_block_vars.iv_MR12[3][8];
            io_msg_block.VrefCSR3Nib9 = iv_msg_block_vars.iv_MR12[3][9];
            io_msg_block.VrefCSR3Nib10 = iv_msg_block_vars.iv_MR12[3][10];
            io_msg_block.VrefCSR3Nib11 = iv_msg_block_vars.iv_MR12[3][11];
            io_msg_block.VrefCSR3Nib12 = iv_msg_block_vars.iv_MR12[3][12];
            io_msg_block.VrefCSR3Nib13 = iv_msg_block_vars.iv_MR12[3][13];
            io_msg_block.VrefCSR3Nib14 = iv_msg_block_vars.iv_MR12[3][14];
            io_msg_block.VrefCSR3Nib15 = iv_msg_block_vars.iv_MR12[3][15];
            io_msg_block.VrefCSR3Nib16 = iv_msg_block_vars.iv_MR12[3][16];
            io_msg_block.VrefCSR3Nib17 = iv_msg_block_vars.iv_MR12[3][17];
            io_msg_block.VrefCSR3Nib18 = iv_msg_block_vars.iv_MR12[3][18];
            io_msg_block.VrefCSR3Nib19 = iv_msg_block_vars.iv_MR12[3][19];

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameters VrefCAR[RANK]Nib[DRAM]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_VrefCA(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.VrefCAR0Nib0 = iv_msg_block_vars.iv_MR11[0][0];
            io_msg_block.VrefCAR0Nib1 = iv_msg_block_vars.iv_MR11[0][1];
            io_msg_block.VrefCAR0Nib2 = iv_msg_block_vars.iv_MR11[0][2];
            io_msg_block.VrefCAR0Nib3 = iv_msg_block_vars.iv_MR11[0][3];
            io_msg_block.VrefCAR0Nib4 = iv_msg_block_vars.iv_MR11[0][4];
            io_msg_block.VrefCAR0Nib5 = iv_msg_block_vars.iv_MR11[0][5];
            io_msg_block.VrefCAR0Nib6 = iv_msg_block_vars.iv_MR11[0][6];
            io_msg_block.VrefCAR0Nib7 = iv_msg_block_vars.iv_MR11[0][7];
            io_msg_block.VrefCAR0Nib8 = iv_msg_block_vars.iv_MR11[0][8];
            io_msg_block.VrefCAR0Nib9 = iv_msg_block_vars.iv_MR11[0][9];
            io_msg_block.VrefCAR0Nib10 = iv_msg_block_vars.iv_MR11[0][10];
            io_msg_block.VrefCAR0Nib11 = iv_msg_block_vars.iv_MR11[0][11];
            io_msg_block.VrefCAR0Nib12 = iv_msg_block_vars.iv_MR11[0][12];
            io_msg_block.VrefCAR0Nib13 = iv_msg_block_vars.iv_MR11[0][13];
            io_msg_block.VrefCAR0Nib14 = iv_msg_block_vars.iv_MR11[0][14];
            io_msg_block.VrefCAR0Nib15 = iv_msg_block_vars.iv_MR11[0][15];
            io_msg_block.VrefCAR0Nib16 = iv_msg_block_vars.iv_MR11[0][16];
            io_msg_block.VrefCAR0Nib17 = iv_msg_block_vars.iv_MR11[0][17];
            io_msg_block.VrefCAR0Nib18 = iv_msg_block_vars.iv_MR11[0][18];
            io_msg_block.VrefCAR0Nib19 = iv_msg_block_vars.iv_MR11[0][19];

            io_msg_block.VrefCAR1Nib0 = iv_msg_block_vars.iv_MR11[1][0];
            io_msg_block.VrefCAR1Nib1 = iv_msg_block_vars.iv_MR11[1][1];
            io_msg_block.VrefCAR1Nib2 = iv_msg_block_vars.iv_MR11[1][2];
            io_msg_block.VrefCAR1Nib3 = iv_msg_block_vars.iv_MR11[1][3];
            io_msg_block.VrefCAR1Nib4 = iv_msg_block_vars.iv_MR11[1][4];
            io_msg_block.VrefCAR1Nib5 = iv_msg_block_vars.iv_MR11[1][5];
            io_msg_block.VrefCAR1Nib6 = iv_msg_block_vars.iv_MR11[1][6];
            io_msg_block.VrefCAR1Nib7 = iv_msg_block_vars.iv_MR11[1][7];
            io_msg_block.VrefCAR1Nib8 = iv_msg_block_vars.iv_MR11[1][8];
            io_msg_block.VrefCAR1Nib9 = iv_msg_block_vars.iv_MR11[1][9];
            io_msg_block.VrefCAR1Nib10 = iv_msg_block_vars.iv_MR11[1][10];
            io_msg_block.VrefCAR1Nib11 = iv_msg_block_vars.iv_MR11[1][11];
            io_msg_block.VrefCAR1Nib12 = iv_msg_block_vars.iv_MR11[1][12];
            io_msg_block.VrefCAR1Nib13 = iv_msg_block_vars.iv_MR11[1][13];
            io_msg_block.VrefCAR1Nib14 = iv_msg_block_vars.iv_MR11[1][14];
            io_msg_block.VrefCAR1Nib15 = iv_msg_block_vars.iv_MR11[1][15];
            io_msg_block.VrefCAR1Nib16 = iv_msg_block_vars.iv_MR11[1][16];
            io_msg_block.VrefCAR1Nib17 = iv_msg_block_vars.iv_MR11[1][17];
            io_msg_block.VrefCAR1Nib18 = iv_msg_block_vars.iv_MR11[1][18];
            io_msg_block.VrefCAR1Nib19 = iv_msg_block_vars.iv_MR11[1][19];

            io_msg_block.VrefCAR2Nib0 = iv_msg_block_vars.iv_MR11[2][0];
            io_msg_block.VrefCAR2Nib1 = iv_msg_block_vars.iv_MR11[2][1];
            io_msg_block.VrefCAR2Nib2 = iv_msg_block_vars.iv_MR11[2][2];
            io_msg_block.VrefCAR2Nib3 = iv_msg_block_vars.iv_MR11[2][3];
            io_msg_block.VrefCAR2Nib4 = iv_msg_block_vars.iv_MR11[2][4];
            io_msg_block.VrefCAR2Nib5 = iv_msg_block_vars.iv_MR11[2][5];
            io_msg_block.VrefCAR2Nib6 = iv_msg_block_vars.iv_MR11[2][6];
            io_msg_block.VrefCAR2Nib7 = iv_msg_block_vars.iv_MR11[2][7];
            io_msg_block.VrefCAR2Nib8 = iv_msg_block_vars.iv_MR11[2][8];
            io_msg_block.VrefCAR2Nib9 = iv_msg_block_vars.iv_MR11[2][9];
            io_msg_block.VrefCAR2Nib10 = iv_msg_block_vars.iv_MR11[2][10];
            io_msg_block.VrefCAR2Nib11 = iv_msg_block_vars.iv_MR11[2][11];
            io_msg_block.VrefCAR2Nib12 = iv_msg_block_vars.iv_MR11[2][12];
            io_msg_block.VrefCAR2Nib13 = iv_msg_block_vars.iv_MR11[2][13];
            io_msg_block.VrefCAR2Nib14 = iv_msg_block_vars.iv_MR11[2][14];
            io_msg_block.VrefCAR2Nib15 = iv_msg_block_vars.iv_MR11[2][15];
            io_msg_block.VrefCAR2Nib16 = iv_msg_block_vars.iv_MR11[2][16];
            io_msg_block.VrefCAR2Nib17 = iv_msg_block_vars.iv_MR11[2][17];
            io_msg_block.VrefCAR2Nib18 = iv_msg_block_vars.iv_MR11[2][18];
            io_msg_block.VrefCAR2Nib19 = iv_msg_block_vars.iv_MR11[2][19];

            io_msg_block.VrefCAR3Nib0 = iv_msg_block_vars.iv_MR11[3][0];
            io_msg_block.VrefCAR3Nib1 = iv_msg_block_vars.iv_MR11[3][1];
            io_msg_block.VrefCAR3Nib2 = iv_msg_block_vars.iv_MR11[3][2];
            io_msg_block.VrefCAR3Nib3 = iv_msg_block_vars.iv_MR11[3][3];
            io_msg_block.VrefCAR3Nib4 = iv_msg_block_vars.iv_MR11[3][4];
            io_msg_block.VrefCAR3Nib5 = iv_msg_block_vars.iv_MR11[3][5];
            io_msg_block.VrefCAR3Nib6 = iv_msg_block_vars.iv_MR11[3][6];
            io_msg_block.VrefCAR3Nib7 = iv_msg_block_vars.iv_MR11[3][7];
            io_msg_block.VrefCAR3Nib8 = iv_msg_block_vars.iv_MR11[3][8];
            io_msg_block.VrefCAR3Nib9 = iv_msg_block_vars.iv_MR11[3][9];
            io_msg_block.VrefCAR3Nib10 = iv_msg_block_vars.iv_MR11[3][10];
            io_msg_block.VrefCAR3Nib11 = iv_msg_block_vars.iv_MR11[3][11];
            io_msg_block.VrefCAR3Nib12 = iv_msg_block_vars.iv_MR11[3][12];
            io_msg_block.VrefCAR3Nib13 = iv_msg_block_vars.iv_MR11[3][13];
            io_msg_block.VrefCAR3Nib14 = iv_msg_block_vars.iv_MR11[3][14];
            io_msg_block.VrefCAR3Nib15 = iv_msg_block_vars.iv_MR11[3][15];
            io_msg_block.VrefCAR3Nib16 = iv_msg_block_vars.iv_MR11[3][16];
            io_msg_block.VrefCAR3Nib17 = iv_msg_block_vars.iv_MR11[3][17];
            io_msg_block.VrefCAR3Nib18 = iv_msg_block_vars.iv_MR11[3][18];
            io_msg_block.VrefCAR3Nib19 = iv_msg_block_vars.iv_MR11[3][19];

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for parameters DisabledDB[BYTE]LaneR[RANK]
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_DisabledDB(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.DisabledDB0LaneR0 = iv_msg_block_vars.iv_DisabledDB[0][0];
            io_msg_block.DisabledDB0LaneR1 = iv_msg_block_vars.iv_DisabledDB[0][1];
            io_msg_block.DisabledDB0LaneR2 = iv_msg_block_vars.iv_DisabledDB[0][2];
            io_msg_block.DisabledDB0LaneR3 = iv_msg_block_vars.iv_DisabledDB[0][3];
            io_msg_block.DisabledDB1LaneR0 = iv_msg_block_vars.iv_DisabledDB[1][0];
            io_msg_block.DisabledDB1LaneR1 = iv_msg_block_vars.iv_DisabledDB[1][1];
            io_msg_block.DisabledDB1LaneR2 = iv_msg_block_vars.iv_DisabledDB[1][2];
            io_msg_block.DisabledDB1LaneR3 = iv_msg_block_vars.iv_DisabledDB[1][3];
            io_msg_block.DisabledDB2LaneR0 = iv_msg_block_vars.iv_DisabledDB[2][0];
            io_msg_block.DisabledDB2LaneR1 = iv_msg_block_vars.iv_DisabledDB[2][1];
            io_msg_block.DisabledDB2LaneR2 = iv_msg_block_vars.iv_DisabledDB[2][2];
            io_msg_block.DisabledDB2LaneR3 = iv_msg_block_vars.iv_DisabledDB[2][3];
            io_msg_block.DisabledDB3LaneR0 = iv_msg_block_vars.iv_DisabledDB[3][0];
            io_msg_block.DisabledDB3LaneR1 = iv_msg_block_vars.iv_DisabledDB[3][1];
            io_msg_block.DisabledDB3LaneR2 = iv_msg_block_vars.iv_DisabledDB[3][2];
            io_msg_block.DisabledDB3LaneR3 = iv_msg_block_vars.iv_DisabledDB[3][3];
            io_msg_block.DisabledDB4LaneR0 = iv_msg_block_vars.iv_DisabledDB[4][0];
            io_msg_block.DisabledDB4LaneR1 = iv_msg_block_vars.iv_DisabledDB[4][1];
            io_msg_block.DisabledDB4LaneR2 = iv_msg_block_vars.iv_DisabledDB[4][2];
            io_msg_block.DisabledDB4LaneR3 = iv_msg_block_vars.iv_DisabledDB[4][3];
            io_msg_block.DisabledDB5LaneR0 = iv_msg_block_vars.iv_DisabledDB[5][0];
            io_msg_block.DisabledDB5LaneR1 = iv_msg_block_vars.iv_DisabledDB[5][1];
            io_msg_block.DisabledDB5LaneR2 = iv_msg_block_vars.iv_DisabledDB[5][2];
            io_msg_block.DisabledDB5LaneR3 = iv_msg_block_vars.iv_DisabledDB[5][3];
            io_msg_block.DisabledDB6LaneR0 = iv_msg_block_vars.iv_DisabledDB[6][0];
            io_msg_block.DisabledDB6LaneR1 = iv_msg_block_vars.iv_DisabledDB[6][1];
            io_msg_block.DisabledDB6LaneR2 = iv_msg_block_vars.iv_DisabledDB[6][2];
            io_msg_block.DisabledDB6LaneR3 = iv_msg_block_vars.iv_DisabledDB[6][3];
            io_msg_block.DisabledDB7LaneR0 = iv_msg_block_vars.iv_DisabledDB[7][0];
            io_msg_block.DisabledDB7LaneR1 = iv_msg_block_vars.iv_DisabledDB[7][1];
            io_msg_block.DisabledDB7LaneR2 = iv_msg_block_vars.iv_DisabledDB[7][2];
            io_msg_block.DisabledDB7LaneR3 = iv_msg_block_vars.iv_DisabledDB[7][3];
            io_msg_block.DisabledDB8LaneR0 = iv_msg_block_vars.iv_DisabledDB[8][0];
            io_msg_block.DisabledDB8LaneR1 = iv_msg_block_vars.iv_DisabledDB[8][1];
            io_msg_block.DisabledDB8LaneR2 = iv_msg_block_vars.iv_DisabledDB[8][2];
            io_msg_block.DisabledDB8LaneR3 = iv_msg_block_vars.iv_DisabledDB[8][3];
            io_msg_block.DisabledDB9LaneR0 = iv_msg_block_vars.iv_DisabledDB[9][0];
            io_msg_block.DisabledDB9LaneR1 = iv_msg_block_vars.iv_DisabledDB[9][1];
            io_msg_block.DisabledDB9LaneR2 = iv_msg_block_vars.iv_DisabledDB[9][2];
            io_msg_block.DisabledDB9LaneR3 = iv_msg_block_vars.iv_DisabledDB[9][3];

            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief msg_block_params structure setup for output parameters
        /// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode setup_output_fields(PMU_SMB_DDR5U_1D_t& io_msg_block) const
        {
            io_msg_block.PmuRevision = 0;
            io_msg_block.CsTestFail = 0;
            io_msg_block.ResultAddrOffset = 0;
            io_msg_block.CDD_ChA_RR_3_2 = 0;
            io_msg_block.CDD_ChA_RR_3_1 = 0;
            io_msg_block.CDD_ChA_RR_3_0 = 0;
            io_msg_block.CDD_ChA_RR_2_3 = 0;
            io_msg_block.CDD_ChA_RR_2_1 = 0;
            io_msg_block.CDD_ChA_RR_2_0 = 0;
            io_msg_block.CDD_ChA_RR_1_3 = 0;
            io_msg_block.CDD_ChA_RR_1_2 = 0;
            io_msg_block.CDD_ChA_RR_1_0 = 0;
            io_msg_block.CDD_ChA_RR_0_3 = 0;
            io_msg_block.CDD_ChA_RR_0_2 = 0;
            io_msg_block.CDD_ChA_RR_0_1 = 0;
            io_msg_block.CDD_ChA_RW_3_3 = 0;
            io_msg_block.CDD_ChA_RW_3_2 = 0;
            io_msg_block.CDD_ChA_RW_3_1 = 0;
            io_msg_block.CDD_ChA_RW_3_0 = 0;
            io_msg_block.CDD_ChA_RW_2_3 = 0;
            io_msg_block.CDD_ChA_RW_2_2 = 0;
            io_msg_block.CDD_ChA_RW_2_1 = 0;
            io_msg_block.CDD_ChA_RW_2_0 = 0;
            io_msg_block.CDD_ChA_RW_1_3 = 0;
            io_msg_block.CDD_ChA_RW_1_2 = 0;
            io_msg_block.CDD_ChA_RW_1_1 = 0;
            io_msg_block.CDD_ChA_RW_1_0 = 0;
            io_msg_block.CDD_ChA_RW_0_3 = 0;
            io_msg_block.CDD_ChA_RW_0_2 = 0;
            io_msg_block.CDD_ChA_RW_0_1 = 0;
            io_msg_block.CDD_ChA_RW_0_0 = 0;
            io_msg_block.CDD_ChA_WR_3_3 = 0;
            io_msg_block.CDD_ChA_WR_3_2 = 0;
            io_msg_block.CDD_ChA_WR_3_1 = 0;
            io_msg_block.CDD_ChA_WR_3_0 = 0;
            io_msg_block.CDD_ChA_WR_2_3 = 0;
            io_msg_block.CDD_ChA_WR_2_2 = 0;
            io_msg_block.CDD_ChA_WR_2_1 = 0;
            io_msg_block.CDD_ChA_WR_2_0 = 0;
            io_msg_block.CDD_ChA_WR_1_3 = 0;
            io_msg_block.CDD_ChA_WR_1_2 = 0;
            io_msg_block.CDD_ChA_WR_1_1 = 0;
            io_msg_block.CDD_ChA_WR_1_0 = 0;
            io_msg_block.CDD_ChA_WR_0_3 = 0;
            io_msg_block.CDD_ChA_WR_0_2 = 0;
            io_msg_block.CDD_ChA_WR_0_1 = 0;
            io_msg_block.CDD_ChA_WR_0_0 = 0;
            io_msg_block.CDD_ChA_WW_3_2 = 0;
            io_msg_block.CDD_ChA_WW_3_1 = 0;
            io_msg_block.CDD_ChA_WW_3_0 = 0;
            io_msg_block.CDD_ChA_WW_2_3 = 0;
            io_msg_block.CDD_ChA_WW_2_1 = 0;
            io_msg_block.CDD_ChA_WW_2_0 = 0;
            io_msg_block.CDD_ChA_WW_1_3 = 0;
            io_msg_block.CDD_ChA_WW_1_2 = 0;
            io_msg_block.CDD_ChA_WW_1_0 = 0;
            io_msg_block.CDD_ChA_WW_0_3 = 0;
            io_msg_block.CDD_ChA_WW_0_2 = 0;
            io_msg_block.CDD_ChA_WW_0_1 = 0;
            io_msg_block.CDD_ChA_RR_3_2 = 0;
            io_msg_block.CDD_ChB_RR_3_1 = 0;
            io_msg_block.CDD_ChB_RR_3_0 = 0;
            io_msg_block.CDD_ChB_RR_2_3 = 0;
            io_msg_block.CDD_ChB_RR_2_1 = 0;
            io_msg_block.CDD_ChB_RR_2_0 = 0;
            io_msg_block.CDD_ChB_RR_1_3 = 0;
            io_msg_block.CDD_ChB_RR_1_2 = 0;
            io_msg_block.CDD_ChB_RR_1_0 = 0;
            io_msg_block.CDD_ChB_RR_0_3 = 0;
            io_msg_block.CDD_ChB_RR_0_2 = 0;
            io_msg_block.CDD_ChB_RR_0_1 = 0;
            io_msg_block.CDD_ChB_RW_3_3 = 0;
            io_msg_block.CDD_ChB_RW_3_2 = 0;
            io_msg_block.CDD_ChB_RW_3_1 = 0;
            io_msg_block.CDD_ChB_RW_3_0 = 0;
            io_msg_block.CDD_ChB_RW_2_3 = 0;
            io_msg_block.CDD_ChB_RW_2_2 = 0;
            io_msg_block.CDD_ChB_RW_2_1 = 0;
            io_msg_block.CDD_ChB_RW_2_0 = 0;
            io_msg_block.CDD_ChB_RW_1_3 = 0;
            io_msg_block.CDD_ChB_RW_1_2 = 0;
            io_msg_block.CDD_ChB_RW_1_1 = 0;
            io_msg_block.CDD_ChB_RW_1_0 = 0;
            io_msg_block.CDD_ChB_RW_0_3 = 0;
            io_msg_block.CDD_ChB_RW_0_2 = 0;
            io_msg_block.CDD_ChB_RW_0_1 = 0;
            io_msg_block.CDD_ChB_RW_0_0 = 0;
            io_msg_block.CDD_ChB_WR_3_3 = 0;
            io_msg_block.CDD_ChB_WR_3_2 = 0;
            io_msg_block.CDD_ChB_WR_3_1 = 0;
            io_msg_block.CDD_ChB_WR_3_0 = 0;
            io_msg_block.CDD_ChB_WR_2_3 = 0;
            io_msg_block.CDD_ChB_WR_2_2 = 0;
            io_msg_block.CDD_ChB_WR_2_1 = 0;
            io_msg_block.CDD_ChB_WR_2_0 = 0;
            io_msg_block.CDD_ChB_WR_1_3 = 0;
            io_msg_block.CDD_ChB_WR_1_2 = 0;
            io_msg_block.CDD_ChB_WR_1_1 = 0;
            io_msg_block.CDD_ChB_WR_1_0 = 0;
            io_msg_block.CDD_ChB_WR_0_3 = 0;
            io_msg_block.CDD_ChB_WR_0_2 = 0;
            io_msg_block.CDD_ChB_WR_0_1 = 0;
            io_msg_block.CDD_ChB_WR_0_0 = 0;
            io_msg_block.CDD_ChB_WW_3_2 = 0;
            io_msg_block.CDD_ChB_WW_3_1 = 0;
            io_msg_block.CDD_ChB_WW_3_0 = 0;
            io_msg_block.CDD_ChB_WW_2_3 = 0;
            io_msg_block.CDD_ChB_WW_2_1 = 0;
            io_msg_block.CDD_ChB_WW_2_0 = 0;
            io_msg_block.CDD_ChB_WW_1_3 = 0;
            io_msg_block.CDD_ChB_WW_1_2 = 0;
            io_msg_block.CDD_ChB_WW_1_0 = 0;
            io_msg_block.CDD_ChB_WW_0_3 = 0;
            io_msg_block.CDD_ChB_WW_0_2 = 0;
            io_msg_block.CDD_ChB_WW_0_1 = 0;
            io_msg_block.CS_Dly_Margin_A0 = 0;
            io_msg_block.CS_Dly_Margin_A1 = 0;
            io_msg_block.CS_Dly_Margin_A2 = 0;
            io_msg_block.CS_Dly_Margin_A3 = 0;
            io_msg_block.CS_Dly_Margin_B0 = 0;
            io_msg_block.CS_Dly_Margin_B1 = 0;
            io_msg_block.CS_Dly_Margin_B2 = 0;
            io_msg_block.CS_Dly_Margin_B3 = 0;
            io_msg_block.CS_Vref_Margin_A0 = 0;
            io_msg_block.CS_Vref_Margin_A1 = 0;
            io_msg_block.CS_Vref_Margin_A2 = 0;
            io_msg_block.CS_Vref_Margin_A3 = 0;
            io_msg_block.CS_Vref_Margin_B0 = 0;
            io_msg_block.CS_Vref_Margin_B1 = 0;
            io_msg_block.CS_Vref_Margin_B2 = 0;
            io_msg_block.CS_Vref_Margin_B3 = 0;
            io_msg_block.CA_Dly_Margin_A0 = 0;
            io_msg_block.CA_Dly_Margin_A1 = 0;
            io_msg_block.CA_Dly_Margin_A2 = 0;
            io_msg_block.CA_Dly_Margin_A3 = 0;
            io_msg_block.CA_Dly_Margin_B0 = 0;
            io_msg_block.CA_Dly_Margin_B1 = 0;
            io_msg_block.CA_Dly_Margin_B2 = 0;
            io_msg_block.CA_Dly_Margin_B3 = 0;
            io_msg_block.CA_Vref_Margin_A0 = 0;
            io_msg_block.CA_Vref_Margin_A1 = 0;
            io_msg_block.CA_Vref_Margin_A2 = 0;
            io_msg_block.CA_Vref_Margin_A3 = 0;
            io_msg_block.CA_Vref_Margin_B0 = 0;
            io_msg_block.CA_Vref_Margin_B1 = 0;
            io_msg_block.CA_Vref_Margin_B2 = 0;
            io_msg_block.CA_Vref_Margin_B3 = 0;
            io_msg_block.RxClkDly_Margin_A0 = 0;
            io_msg_block.RxClkDly_Margin_A1 = 0;
            io_msg_block.RxClkDly_Margin_A2 = 0;
            io_msg_block.RxClkDly_Margin_A3 = 0;
            io_msg_block.RxClkDly_Margin_B0 = 0;
            io_msg_block.RxClkDly_Margin_B1 = 0;
            io_msg_block.RxClkDly_Margin_B2 = 0;
            io_msg_block.RxClkDly_Margin_B3 = 0;
            io_msg_block.VrefDac_Margin_A0 = 0;
            io_msg_block.VrefDac_Margin_A1 = 0;
            io_msg_block.VrefDac_Margin_A2 = 0;
            io_msg_block.VrefDac_Margin_A3 = 0;
            io_msg_block.VrefDac_Margin_B0 = 0;
            io_msg_block.VrefDac_Margin_B1 = 0;
            io_msg_block.VrefDac_Margin_B2 = 0;
            io_msg_block.VrefDac_Margin_B3 = 0;
            io_msg_block.TxDqDly_Margin_A0 = 0;
            io_msg_block.TxDqDly_Margin_A1 = 0;
            io_msg_block.TxDqDly_Margin_A2 = 0;
            io_msg_block.TxDqDly_Margin_A3 = 0;
            io_msg_block.TxDqDly_Margin_B0 = 0;
            io_msg_block.TxDqDly_Margin_B1 = 0;
            io_msg_block.TxDqDly_Margin_B2 = 0;
            io_msg_block.TxDqDly_Margin_B3 = 0;
            io_msg_block.DeviceVref_Margin_A0 = 0;
            io_msg_block.DeviceVref_Margin_A1 = 0;
            io_msg_block.DeviceVref_Margin_A2 = 0;
            io_msg_block.DeviceVref_Margin_A3 = 0;
            io_msg_block.DeviceVref_Margin_B0 = 0;
            io_msg_block.DeviceVref_Margin_B1 = 0;
            io_msg_block.DeviceVref_Margin_B2 = 0;
            io_msg_block.DeviceVref_Margin_B3 = 0;
            io_msg_block.QCS_Dly_Margin_A0 = 0;
            io_msg_block.QCS_Dly_Margin_A1 = 0;
            io_msg_block.QCS_Dly_Margin_A2 = 0;
            io_msg_block.QCS_Dly_Margin_A3 = 0;
            io_msg_block.QCS_Dly_Margin_B0 = 0;
            io_msg_block.QCS_Dly_Margin_B1 = 0;
            io_msg_block.QCS_Dly_Margin_B2 = 0;
            io_msg_block.QCS_Dly_Margin_B3 = 0;
            io_msg_block.QCA_Dly_Margin_A0 = 0;
            io_msg_block.QCA_Dly_Margin_A1 = 0;
            io_msg_block.QCA_Dly_Margin_A2 = 0;
            io_msg_block.QCA_Dly_Margin_A3 = 0;
            io_msg_block.QCA_Dly_Margin_B0 = 0;
            io_msg_block.QCA_Dly_Margin_B1 = 0;
            io_msg_block.QCA_Dly_Margin_B2 = 0;
            io_msg_block.QCA_Dly_Margin_B3 = 0;
            io_msg_block.PmuInternalRev0 = 0;
            io_msg_block.PmuInternalRev1 = 0;

            return fapi2::FAPI2_RC_SUCCESS;
        }

};

///
/// @class rcw_id
/// @brief Contains information for RCW's as processed from the SMBus messages
///
struct rcw_id
{
    // Note: the comments show the Synopsys mappings
    // The IBM data starts at bit 32 and increases from there
    // So a Synopsys mapping of 31:28 will be an IBM mapping of 32:35
    enum bit_mappings
    {
        CHANNEL_ID     = 32, // Synopsys 31:28
        CHANNEL_ID_LEN = 4,
        DIMM_ID        = 36, // Synopsys 27:24
        DIMM_ID_LEN    = 4,
        RCW_ID         = 40, // Synopsys 23:16
        RCW_ID_LEN     = 8,
        RCW_PAGE       = 48, // Synopsys 15: 8
        RCW_PAGE_LEN   = 8,
        RCW_VAL        = 56, // Synopsys  7: 0
        RCW_VAL_LEN    = 8,
    };

    rcw_id() = delete;

    ///
    /// @brief Reads in and processes the SMBus formatted message
    ///
    rcw_id(const fapi2::buffer<uint64_t>& i_mail) :
        iv_channel_id(0),
        iv_dimm_id(0),
        iv_rcw_id(0),
        iv_rcw_page(0),
        iv_rcw_val(0)
    {
        i_mail.extractToRight<CHANNEL_ID, CHANNEL_ID_LEN>(iv_channel_id)
        .extractToRight<DIMM_ID, DIMM_ID_LEN>(iv_dimm_id)
        .extractToRight<RCW_ID, RCW_ID_LEN>(iv_rcw_id)
        .extractToRight<RCW_PAGE, RCW_PAGE_LEN>(iv_rcw_page)
        .extractToRight<RCW_VAL, RCW_VAL_LEN>(iv_rcw_val);
    }

    ///
    /// @brief rcw_id default destructor
    ///
    ~rcw_id() = default;

    uint8_t iv_channel_id = 0;
    uint8_t iv_dimm_id = 0;
    uint8_t iv_rcw_id = 0;
    uint8_t iv_rcw_page = 0;
    uint8_t iv_rcw_val = 0;
};

///
/// @brief Configures the DRAM training message block using attributes
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_sim value of ATTR_IS_SIMULATION
/// @param[out] o_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_sim,
        PMU_SMB_DDR5U_1D_t& o_struct);

///
/// @brief Loads binary into registers
/// @param[in] i_target the target on which to operate
/// @param[in] i_is_first_load value noting if this is the first load of the given memory array
/// @param[in] i_start_addr start address of  imem/dmem binary to be read through istream
/// @param[in] i_data_start data pointer  of imem/dmem
/// @param[in] i_mem_size size of the dmem/imem istream to be trasferred per loop
/// @param[in] i_mem_total_size total size of the dmem/imem istream
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode load_mem_bin_data(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const uint8_t i_is_first_load,
                                    const uint32_t i_start_addr,
                                    uint8_t* i_data_start,
                                    const uint32_t i_mem_size,
                                    const uint32_t i_mem_total_size);

///
/// @brief Initializes the protocol for mailbox interaction
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode init_mailbox_protocol(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Get the message passed through the mailbox protocol
/// @param[in] i_target the target on which to operate
/// @param[in] i_mode 16 bit or 32 bit to read major message or streaming & SMBus messages
/// @param[in] i_loop_count poll count for reading UCT_PROT_SHADOW.
/// @param[out] o_mail message read from the mailbox protocol.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode get_mail (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                            const uint8_t i_mode,
                            const uint64_t i_loop_count,
                            fapi2::buffer<uint64_t>& o_mail);

///
/// @brief Poll for mail to be available
/// @param[in] i_target the target on which to operate
/// @param[in] i_mailbox_poll_count poll count for reading UCT_PROT_SHADOW.
/// note: mode is set in the calling function. mail is returned based on that.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_message_available (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_mailbox_poll_count);

///
/// @brief reads the message after it is available
/// @param[in] i_target the target on which to operate
/// @param[in] i_mode 16 bit or 32 bit to read major message or streaming & SMBus messages
/// @param[out] o_mail message read from the mailbox protocol.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                               const uint8_t i_mode,
                               fapi2::buffer<uint64_t>& o_mail);

//
/// @brief Acknowledges that mail is received
/// @param[in] i_target the target on which to operate
/// @param[in] i_mailbox_poll_count poll count for reading UCT_PROT_SHADOW.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode acknowledge_mail (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                    const uint64_t i_mailbox_poll_count);


///
/// @brief Polls the mail until completion message is received
/// @param[in] i_target the target on which to operate
/// @param[in] i_training_poll_count poll count for getting mail.
/// @param[out] o_status final mail message from training, PASS/FAIL status if it completed
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_completion(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      const uint64_t i_training_poll_count,
                                      uint64_t& o_status,
                                      fapi2::hwp_data_ostream& o_log_data );

///
/// @brief Checks the completion condition for training and decodes respective message
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_mail mail content to check for completion
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @param[out] o_loop_end flags that completion was detected, ending polling loop and skipping delay.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_for_completion_and_decode(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const fapi2::buffer<uint64_t>& i_mail,
        fapi2::hwp_data_ostream& o_log_data,
        bool& o_loop_end);

///
/// @brief Configures the DRAM training message block using sim environment hardcoded values
/// @param[in] i_target the memory port on which to operate
/// @param[out] o_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_dram_train_message_block_hardcodes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target,
        PMU_SMB_DDR5U_1D_t& o_struct);

///
/// @brief Configure and load the msg block on to snps phy
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_msg_block the message block to configure and load
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_and_load_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block);

///
/// @brief Processes a streaming message from the mailbox protocol
/// @param[in] i_target the target on which to operate
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode process_streaming_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        fapi2::hwp_data_ostream& o_log_data);

///
/// @brief Processes an SMBus message request (aka runs an RCW via i2c)
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note This function only handles the message interface for right now
/// TODO:ZEN:MST-1541 Add DDR5 RCW writes using i2c when SMBus message is received
///
fapi2::ReturnCode process_smbus_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Starts the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Assumes that the firmware binaries and data structures are loaded appropriately
///
fapi2::ReturnCode start_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Stops the ARC processor
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode stall_arc_processor(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Cleans up from the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note puts the processor into a stall state
///
fapi2::ReturnCode cleanup_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief constants for mailbox interaction
///
enum mailbox_consts
{
    // Initialization of protocol
    PROTOCOL_INIT = 1,

    // Responses received as major message
    SUCCESSFUL_COMPLETION = 0x07,
    FAILED_COMPLETION = 0xFF,
    STREAMING_MSG = 0x08,
    SMBUS_MSG = 0x50,
    SMBUS_SYNC = 0x51,

    // Stage completion Major messaging
    END_OF_INITILIAZATION = 0x00,
    END_OF_FINE_WRITE_LEVELING = 0x01,
    END_OF_READ_ENABLE_TRAINING = 0x02,
    END_OF_RD_DLY_CNTR_OPT = 0x03,
    END_OF_WR_DLY_CNTR_OPT = 0x04,
    END_OF_2D_RD_DLY_V_CNTR_OPT = 0x05,
    END_OF_2D_WR_DLY_V_CNTR_OPT = 0x06,
    END_OF_MAX_RD_LAT_TRAINING = 0x09,
    END_OF_RD_DQ_DSKEW_TRAINING = 0x0A,
    TRAINING_STAGE_RESERVED = 0x0B,
    END_OF_CS_CA_TRAINING = 0x0D,
    END_OF_RCD_QCS_QCA_TRAINING = 0x1D,
    END_OF_LRDIMM_MREP_TRAINING = 0x20,
    END_OF_LRDIMM_DWL_TRAINING = 0x21,
    END_OF_LRDIMM_MRD_TRAINING = 0x22,
    END_OF_LRDIMM_MWD_TRAINING = 0x23,
    GEN_WRT_NOISE_SYN = 0xA0,
    END_OF_MPR_RD_DLY_CNTR_OPT = 0xFD,
    END_OF_WR_LVL_COARSE_DLY = 0xFE,

    // Mode for reading major message vs streaming msg/SMBus msg
    MAJOR_MSG_MODE = 16,
    STREAMING_SMBUS_MSG_MODE = 32,

    // Register data for different messages
    MESSAGE_AVAILABLE = 0,
    RECEPTION_ACK = 0,
    ACK_MESSAGE = 1,
};

///
/// @brief Calculates the end addr of IMEM/DMEM image
/// @param[in] i_start_addr starting address of the image
/// @param[in] i_size size that needs to transferred at a time
/// @return uint32_t calculated end address
///
uint32_t calculate_image_end_addr(const uint32_t i_start_addr, const uint32_t i_size);

///
/// @brief Assembles a single registers worth of data from the buffer
/// @param[in] i_mem_size size of the dmem/imem istream to be transferred per loop
/// @param[in,out] io_bytes_copied the number of bytes copied
/// @param[in] i_current_byte the pointer to the current byte
/// @param[in,out] io_data the data for this register address
/// @return The updated pointer to the current byte
///
const uint8_t* assemble_mem_bin_data_reg(const uint32_t i_mem_size,
        uint32_t& io_bytes_copied,
        const uint8_t* i_current_byte,
        fapi2::buffer<uint64_t>& io_data);

///
/// @brief Helper function to ody_load_dmem()
/// @param[in] i_target the ocmb chip target
/// @param[in] i_dmem_data dmem data image
/// @param[in] i_dmem_size size that needs to transferred at a time
/// @param[in] i_dmem_offset address offset of this chunk within the dmem image(in bytes)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_load_dmem_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       uint8_t* const i_dmem_data,
                                       const uint32_t i_dmem_size,
                                       const uint32_t i_dmem_offset);

///
/// @brief Helper function to ody_load_imem()
/// @param[in] i_target the ocmb chip target
/// @param[in] i_imem_data imem data image
/// @param[in] i_imem_size size that needs to transferred at a time
/// @param[in] i_imem_offset address offset of this chunk within the imem image(in bytes)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_load_imem_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       uint8_t* const i_imem_data,
                                       const uint32_t i_imem_size,
                                       const uint32_t i_imem_offset);

///
/// @brief Loads the message block into the DMEM
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Only loads the "input" fields
/// @note The guts of this function is auto-generated using gen_dmem_func.py
///       located in the ekb-lab/ody/mem/tools
///
fapi2::ReturnCode load_msg_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 const _PMU_SMB_DDR5_1D_t& i_struct);

///
/// @brief Reads the message block from the DMEM
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Only loads the "output" fields
/// @note The guts of this function is auto-generated using gen_dmem_func.py
///       located in the ekb-lab/ody/mem/tools
///
fapi2::ReturnCode read_msg_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 _PMU_SMB_DDR5_1D_t& io_struct);

///
/// @brief Sets the mode register attributes based upon the outputted data from draminit
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_mr_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                    const _PMU_SMB_DDR5_1D_t& i_msg_block);

///
/// @brief Sets the generic attributes based upon the outputted data from draminit
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_generic_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const _PMU_SMB_DDR5_1D_t& i_msg_block);

///
/// @brief Sets the attributes based upon the outputted data from draminit
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 const _PMU_SMB_DDR5_1D_t& i_msg_block);

/// @brief Prints the fields from the message block structure
/// @param[in] i_target the target on which to operate
/// @param[in] i_msg_blk message block structure
/// @return None
///
void display_msg_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                       const _PMU_SMB_DDR5_1D_t& i_msg_block);

///
/// @brief Checks the training status from mail and message block
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_status the final mail status from training
/// @param[in] i_msg_block_response the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_training_result(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        const uint64_t i_status,
                                        const _PMU_SMB_DDR5_1D_t& i_msg_block_response);


///
/// @brief Odyssey's bad bit interface class
///
class bad_bit_interface
{
    public:

        // Data that actually stores all of the bad bit information
        // We do some processing in the constructor
        uint8_t iv_bad_bits[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT];

        // No default constructor
        bad_bit_interface() = delete;

        ///
        /// @brief Default destructor
        ///
        ~bad_bit_interface() = default;

        ///
        /// @brief Constructor from PHY response struct
        /// @param[in] i_response response data from training
        ///
        bad_bit_interface(const _PMU_SMB_DDR5_1D_t& i_response )
        {
            // Assign the results to the bad bits internal structure
            // At this point, we want to assign all data
            iv_bad_bits[0][0] = i_response.DisabledDB0LaneR0;
            iv_bad_bits[0][1] = i_response.DisabledDB1LaneR0;
            iv_bad_bits[0][2] = i_response.DisabledDB2LaneR0;
            iv_bad_bits[0][3] = i_response.DisabledDB3LaneR0;
            iv_bad_bits[0][4] = i_response.DisabledDB4LaneR0;
            iv_bad_bits[0][5] = i_response.DisabledDB5LaneR0;
            iv_bad_bits[0][6] = i_response.DisabledDB6LaneR0;
            iv_bad_bits[0][7] = i_response.DisabledDB7LaneR0;
            iv_bad_bits[0][8] = i_response.DisabledDB8LaneR0;
            iv_bad_bits[0][9] = i_response.DisabledDB9LaneR0;

            iv_bad_bits[1][0] = i_response.DisabledDB0LaneR1;
            iv_bad_bits[1][1] = i_response.DisabledDB1LaneR1;
            iv_bad_bits[1][2] = i_response.DisabledDB2LaneR1;
            iv_bad_bits[1][3] = i_response.DisabledDB3LaneR1;
            iv_bad_bits[1][4] = i_response.DisabledDB4LaneR1;
            iv_bad_bits[1][5] = i_response.DisabledDB5LaneR1;
            iv_bad_bits[1][6] = i_response.DisabledDB6LaneR1;
            iv_bad_bits[1][7] = i_response.DisabledDB7LaneR1;
            iv_bad_bits[1][8] = i_response.DisabledDB8LaneR1;
            iv_bad_bits[1][9] = i_response.DisabledDB9LaneR1;

            iv_bad_bits[2][0] = i_response.DisabledDB0LaneR2;
            iv_bad_bits[2][1] = i_response.DisabledDB1LaneR2;
            iv_bad_bits[2][2] = i_response.DisabledDB2LaneR2;
            iv_bad_bits[2][3] = i_response.DisabledDB3LaneR2;
            iv_bad_bits[2][4] = i_response.DisabledDB4LaneR2;
            iv_bad_bits[2][5] = i_response.DisabledDB5LaneR2;
            iv_bad_bits[2][6] = i_response.DisabledDB6LaneR2;
            iv_bad_bits[2][7] = i_response.DisabledDB7LaneR2;
            iv_bad_bits[2][8] = i_response.DisabledDB8LaneR2;
            iv_bad_bits[2][9] = i_response.DisabledDB9LaneR2;

            iv_bad_bits[3][0] = i_response.DisabledDB0LaneR3;
            iv_bad_bits[3][1] = i_response.DisabledDB1LaneR3;
            iv_bad_bits[3][2] = i_response.DisabledDB2LaneR3;
            iv_bad_bits[3][3] = i_response.DisabledDB3LaneR3;
            iv_bad_bits[3][4] = i_response.DisabledDB4LaneR3;
            iv_bad_bits[3][5] = i_response.DisabledDB5LaneR3;
            iv_bad_bits[3][6] = i_response.DisabledDB6LaneR3;
            iv_bad_bits[3][7] = i_response.DisabledDB7LaneR3;
            iv_bad_bits[3][8] = i_response.DisabledDB8LaneR3;
            iv_bad_bits[3][9] = i_response.DisabledDB9LaneR3;
        }

        ///
        /// @brief Swizzle the bad bits to the attribute's perspective
        /// @param[in] i_target the DIMM to record training results on
        /// @param[out] o_bad_dq the processed bad bits
        ///
        fapi2::ReturnCode record_bad_bits_interface( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t (&o_bad_dq)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]) const
        {
            std::vector<mss::rank::info<mss::mc_type::ODYSSEY>> l_rank_infos;
            FAPI_TRY(mss::rank::ranks_on_dimm(i_target, l_rank_infos));

            for(const auto& l_rank_info : l_rank_infos)
            {
                // Note: we copy from the PHY rank to the DIMM rank
                // The rank we take in is taken from the PHY structure, which uses PHY rank perspective
                // Our attributes use the IBM rank perspective
                // If there is any swizzle, then this will fix it for us
                std::copy(std::begin(iv_bad_bits[l_rank_info.get_phy_rank()]),
                          std::end(iv_bad_bits[l_rank_info.get_phy_rank()]),
                          std::begin(o_bad_dq[l_rank_info.get_dimm_rank()]));
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief bad bit interface class for ody_host_draminit (read attr and update SPD)
///
class host_bad_bit_interface
{
    public:

        // Data that actually stores all of the bad bit information
        // We do some processing in the constructor
        uint8_t iv_bad_bits[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT];

        // No default constructor
        host_bad_bit_interface() = delete;

        ///
        /// @brief Default destructor
        ///
        ~host_bad_bit_interface() = default;

        ///
        /// @brief Constructor from DIMM bad bits attribute
        /// @param[in] i_target the DIMM to record training results on
        /// @param[out] o_rc the return code from attribute access
        ///
        host_bad_bit_interface(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                               fapi2::ReturnCode& o_rc)
        {
            o_rc = mss::attr::get_bad_dq_bitmap(i_target, iv_bad_bits);
        }

        ///
        /// @brief Update the bad bits attribute (and SPD)
        /// @param[in] i_target the DIMM to record training results on
        /// @param[out] o_bad_dq the processed bad bits
        ///
        fapi2::ReturnCode record_bad_bits_interface( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t (&o_bad_dq)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]) const
        {
            for(uint8_t l_rank = 0; l_rank < BAD_BITS_RANKS; l_rank++)
            {
                // Note: any rank swizzle is taken care of in the sppe_draminit procedure
                std::copy(std::begin(iv_bad_bits[l_rank]),
                          std::end(iv_bad_bits[l_rank]),
                          std::begin(o_bad_dq[l_rank]));
            }

            return fapi2::FAPI2_RC_SUCCESS;
        }
};

} // namespace phy
} // namespace ody
} // namespace mss
#endif
