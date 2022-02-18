/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_chiplet_fabric_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file p10_chiplet_fabric_scominit.C
/// @brief Apply fabric scom inits to prepare for xlink enablement
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_chiplet_fabric_scominit.H>
#include <p10_smp_link_firs.H>
#include <p10_fbc_utils.H>
#include <p10_fbc_no_hp_scom.H>
#include <p10_fbc_ptl_scom.H>
#include <p10_fbc_dlp_scom.H>

#include <p10_scom_proc.H>
#include <p10_scom_pauc_9.H>
#include <p10_scom_perv.H>
#include <multicast_defs.H>
#include <multicast_group_defs.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Reconfigure TL transport mux logic to support configurations
///        where the half links are split to different remote endpoints
///
/// @param[in] i_pauc_target    Reference to PAUC target
/// @param[in] i_iohs_target    Reference to IOHS target
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_chiplet_fabric_scominit_tl_transport_reconfig(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target)
{
    using namespace scomt;
    using namespace scomt::pauc;

    FAPI_DBG("Start");

    fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_link_active;
    fapi2::ATTR_IOHS_LINK_SPLIT_Type l_link_split;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_id;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, i_iohs_target, l_link_active),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_ACTIVE");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_SPLIT, i_iohs_target, l_link_split),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_SPLIT)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iohs_target, l_iohs_id),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    if ((l_link_active == fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_TRUE) &&
        (l_link_split == fapi2::ENUM_ATTR_IOHS_LINK_SPLIT_TRUE))
    {
        fapi2::buffer<uint64_t> l_scom_data(0x0);

        FAPI_TRY(PREP_PB_MISC_CFG(i_pauc_target));

        // Note that split links are always mapped to
        // ptlx0 (even ptl, even half) and ptly1 (odd ptl, odd half)
        SET_PB_MISC_CFG_SCOM_PTLX0_ENABLE(l_scom_data);
        SET_PB_MISC_CFG_SCOM_PTLY1_ENABLE(l_scom_data);

        // Transport Inbound Mux; OPT0/1 are swizzled
        if ((l_iohs_id == 1) || (l_iohs_id == 2) || (l_iohs_id == 4) || (l_iohs_id == 6))
        {
            CLEAR_PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(l_scom_data);
            SET_PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(l_scom_data);
        }

        if ((l_iohs_id == 0) || (l_iohs_id == 3) || (l_iohs_id == 5) || (l_iohs_id == 7))
        {
            SET_PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(l_scom_data);
        }

        // Transport Outbound Mux
        if ((l_iohs_id == 1) || (l_iohs_id == 2))
        {
            SET_PB_MISC_CFG_TRANSPORT_0_ENABLE(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(l_scom_data);

            SET_PB_MISC_CFG_TRANSPORT_1_ENABLE(l_scom_data);
            SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(l_scom_data);
        }

        if ((l_iohs_id == 0) || (l_iohs_id == 3))
        {
            SET_PB_MISC_CFG_TRANSPORT_2_ENABLE(l_scom_data);
            SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(l_scom_data);

            SET_PB_MISC_CFG_TRANSPORT_3_ENABLE(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(l_scom_data);
        }

        if ((l_iohs_id == 4) || (l_iohs_id == 6))
        {
            SET_PB_MISC_CFG_TRANSPORT_0_ENABLE(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(l_scom_data);

            SET_PB_MISC_CFG_TRANSPORT_1_ENABLE(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(l_scom_data);
            SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(l_scom_data);
        }

        if ((l_iohs_id == 5) || (l_iohs_id == 7))
        {
            SET_PB_MISC_CFG_TRANSPORT_2_ENABLE(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(l_scom_data);
            SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(l_scom_data);

            SET_PB_MISC_CFG_TRANSPORT_3_ENABLE(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(l_scom_data);
            CLEAR_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(l_scom_data);
        }

        FAPI_TRY(PUT_PB_MISC_CFG(i_pauc_target, l_scom_data));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_chiplet_fabric_scominit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_config_intranode,
    const bool i_config_internode)
{
    FAPI_DBG("Start");
    FAPI_DBG("  i_config_intranode: %d", i_config_intranode);
    FAPI_DBG("  i_config_internode: %d", i_config_internode);

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_PROC_FABRIC_A_INDIRECT_Type l_a_indirect = 0;
    fapi2::ATTR_PROC_FABRIC_R_INDIRECT_EN_Type l_r_indirect_en = 0;
    auto l_iohs_targets = i_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::ReturnCode l_rc;


    // mask attentions from chiplets which are enabled but deemed non-functional
    // specifically added to help handle discrepancies between SBE/HB view of target functional state
    {
        using namespace scomt::perv;

        fapi2::buffer<uint64_t> l_hw_enabled = 0;
        fapi2::buffer<uint64_t> l_platform_functional = 0;
        fapi2::buffer<uint64_t> l_hw_mask = 0;

        // use multicast read of NET_CTRL0 to ascertain HW configured chiplets
        const auto l_mc_all_no_tp = i_target.getMulticast<fapi2::TARGET_TYPE_PERV, fapi2::MULTICAST_BITX>
                                    (fapi2::MCGROUP_GOOD_NO_TP);
        FAPI_TRY(fapi2::getScom(l_mc_all_no_tp, NET_CTRL0_RW, l_hw_enabled));
        // multicast group excludes TP, so statically OR it in
        l_hw_enabled.setBit<1>();
        FAPI_DBG("HW chiplet enable state: 0x%016llX", l_hw_enabled);

        // query platform to determine its view of functional targets
        for (const auto l_perv : i_target.getChildren<fapi2::TARGET_TYPE_PERV>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            FAPI_TRY(l_platform_functional.setBit(l_perv.getChipletNumber()));
        }

        FAPI_DBG("  Plat functional state: 0x%016llX", l_platform_functional);

        // mask attentions from any chiplet which is enabled but deemed non-functional
        l_hw_mask = l_hw_enabled & ~l_platform_functional;
        FAPI_DBG("    HW chiplets to mask: 0x%016llX", l_hw_mask);

        for (uint64_t l_chiplet = 0; l_chiplet < 64; l_chiplet++)
        {
            if (l_hw_mask.getBit(l_chiplet))
            {
                uint64_t l_chiplet_base_addr = l_chiplet << 24;
                fapi2::buffer<uint64_t> l_mask_data;
                l_mask_data.flush<1>();
                FAPI_DBG("Masking chiplet ID: %02X", l_chiplet);
                FAPI_TRY(fapi2::putScom(i_target, l_chiplet_base_addr | XSTOP_MASK_WO_OR, l_mask_data));
                FAPI_TRY(fapi2::putScom(i_target, l_chiplet_base_addr | RECOV_MASK_WO_OR, l_mask_data));
                FAPI_TRY(fapi2::putScom(i_target, l_chiplet_base_addr | SPATTN_MASK_WO_OR, l_mask_data));
                FAPI_TRY(fapi2::putScom(i_target, l_chiplet_base_addr | LOCAL_XSTOP_MASK_WO_OR, l_mask_data));
                FAPI_TRY(fapi2::putScom(i_target, l_chiplet_base_addr | HOSTATTN_MASK_WO_OR, l_mask_data));
            }
        }
    }

    // SW538816
    // - Qualify R_INDIRECT enablement based on number of X links per-chip across entire topology
    // - Initialize based on A_INDIRECT (calculated in p10_fbc_eff_config)
    // - If true, disable if less than 4 X links configured on any given chip in the topology
    //
    // Denali, FSP-based, 2-hop
    //   - A_INDIRECT will be false, leave R_INDIRECT as false
    // Denali, FSP-based, 1-hop F8
    //   - A_INDIRECT will be true if config is large enough (based on single hop attribute)
    //   - General HB attribute context is only a single drawer, so can't simply loop over chip targets
    ///  - Use ATTR_PROC_FABRIC_PRESENT_GROUPS to determine number of chips in entire CEC, this is especially filled by HWSV with system wide view
    //   - Given there are no aggregate links in the topology, assuming a well formed/fully connected topology, NUM_X_LINKS on each chip should be consistent
    //     NUM_X_LINKS = bits_set(ATTR_PROC_FABRIC_PRESENT_GROUPS)-1
    // Rainier/Everest, BMC-based, 1-hop
    //   - A_INDIRECT will be true if config is large enough (based on single hop attribute)
    //   - Use set of children targets to find minimum NUM_X_LINKS value, as all chips should be reflected, and aggregate links need to be considered

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_INDIRECT, FAPI_SYSTEM, l_a_indirect));
    l_r_indirect_en = l_a_indirect;

    if (l_r_indirect_en)
    {
        fapi2::ATTR_PROC_EPS_TABLE_TYPE_Type l_eps_table_type;
        uint8_t l_num_x_links = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_TABLE_TYPE, FAPI_SYSTEM, l_eps_table_type));

        // Denali F8
        if (l_eps_table_type == fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_HE)
        {
            fapi2::ATTR_PROC_FABRIC_PRESENT_GROUPS_Type l_fabric_present_groups = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PRESENT_GROUPS, FAPI_SYSTEM, l_fabric_present_groups));

            for (uint8_t i = 0; i < 8; i++)
            {
                l_num_x_links += (l_fabric_present_groups & 0x01);
                l_fabric_present_groups = (l_fabric_present_groups >> 1);
            }

            l_num_x_links = ((l_num_x_links) ? (l_num_x_links - 1) : (l_num_x_links));
            l_r_indirect_en = (l_num_x_links >= 4);
        }
        // Rainier, Everest
        else
        {
            for (const auto l_child : FAPI_SYSTEM.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, l_child, l_num_x_links));

                if (l_num_x_links < 4)
                {
                    l_r_indirect_en = false;
                    break;
                }
            }
        }
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_R_INDIRECT_EN, FAPI_SYSTEM, l_r_indirect_en));

    // apply FBC non-hotplug scom initfile
    fapi2::toString(i_target, l_tgt_str, sizeof(l_tgt_str));
    FAPI_DBG("Invoking p10.fbc.no_hp.scom.initfile on target %s...", l_tgt_str);
    FAPI_EXEC_HWP(l_rc, p10_fbc_no_hp_scom, i_target, FAPI_SYSTEM);
    FAPI_TRY(l_rc, "Error from p10_fbc_no_hp_scom");

    if (i_config_intranode)
    {
        // init all FIRs as inactive before applying configuration
        for(auto l_iohs : i_target.getChildren<fapi2::TARGET_TYPE_IOHS>(fapi2::TARGET_STATE_PRESENT))
        {
            FAPI_TRY(p10_smp_link_firs(l_iohs, sublink_t::BOTH_PAUE, action_t::INACTIVE, false),
                     "Error from p10_smp_link_firs when masking firs for all links");
            FAPI_TRY(p10_smp_link_firs(l_iohs, sublink_t::BOTH_PAUO, action_t::INACTIVE, false),
                     "Error from p10_smp_link_firs when masking firs for all links");
        }
    }

    for (auto l_iohs : l_iohs_targets)
    {
        fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_fabric_link_active;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, l_iohs, l_fabric_link_active),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_ACTIVE)");

        if (l_fabric_link_active == fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_TRUE)
        {
            fapi2::ATTR_IOHS_DRAWER_INTERCONNECT_Type l_drawer_interconnect;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_DRAWER_INTERCONNECT, l_iohs, l_drawer_interconnect),
                     "Error from FAPI_ATTR_GET (ATTR_IOHS_DRAWER_INTERCONNECT)");

            if((i_config_intranode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_FALSE)) ||
               (i_config_internode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_TRUE)))
            {
                auto l_pauc = l_iohs.getParent<fapi2::TARGET_TYPE_PAUC>();
                fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
                fapi2::ATTR_IOHS_LINK_SPLIT_Type l_link_split;
                fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_unit;
                sublink_t l_sublink_opt;
                fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_Type l_bad_lane_vec_valid = fapi2::ENUM_ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_FALSE;
                fapi2::ATTR_CHIP_EC_FEATURE_HW561216_Type l_hw561216 = 0;
                bool l_mask_dl_lane_errors = false;

                // apply FBC TL scom initfile
                // (depending on system configuration, same TL registers may be programmed
                // multiple times but should end up with consistent results)
                fapi2::toString(l_pauc, l_tgt_str, sizeof(l_tgt_str));
                FAPI_DBG("Invoking p10.fbc.ptl.scom.initfile on target %s...", l_tgt_str);
                FAPI_EXEC_HWP(l_rc, p10_fbc_ptl_scom, l_pauc, i_target, FAPI_SYSTEM);
                FAPI_TRY(l_rc, "Error from p10_fbc_ptl_scom");

                // reconfigure TL transport muxes for split links
                FAPI_TRY(p10_chiplet_fabric_scominit_tl_transport_reconfig(l_pauc, l_iohs),
                         "Error from p10_chiplet_fabric_scominit_tl_transport_reconfig");

                // apply FBC DL scom initfile
                fapi2::toString(l_iohs, l_tgt_str, sizeof(l_tgt_str));
                FAPI_DBG("Invoking p10.fbc.dlp.scom.initfile on target %s...", l_tgt_str);
                FAPI_EXEC_HWP(l_rc, p10_fbc_dlp_scom, l_iohs, i_target, FAPI_SYSTEM);
                FAPI_TRY(l_rc, "Error from p10_fbc_dlp_scom");

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs, l_link_train),
                         "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_SPLIT, l_iohs, l_link_split),
                         "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_SPLIT)");
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs, l_iohs_unit),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                switch(l_link_train)
                {
                    case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH:
                        l_sublink_opt = (l_link_split == fapi2::ENUM_ATTR_IOHS_LINK_SPLIT_FALSE) ?
                                        (((l_iohs_unit % 2) == 0) ? (sublink_t::BOTH_PAUE) : (sublink_t::BOTH_PAUO)) :
                                        (sublink_t::BOTH_PAUS);
                        break;

                    case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY:
                        l_sublink_opt = ((l_iohs_unit % 2) == 0) ? (sublink_t::EVEN_PAUE) : (sublink_t::EVEN_PAUO);
                        break;

                    case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY:
                        l_sublink_opt = ((l_iohs_unit % 2) == 0) ? (sublink_t::ODD_PAUE) : (sublink_t::ODD_PAUO);
                        break;

                    default:
                        l_sublink_opt = sublink_t::NONE;
                        break;
                }

                // setup and unmask EXTFIR/TL/DL/PHY FIRs
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID, l_iohs, l_bad_lane_vec_valid));
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW561216, i_target, l_hw561216));
                l_mask_dl_lane_errors = (l_hw561216 && (l_bad_lane_vec_valid == fapi2::ENUM_ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_FALSE));
                FAPI_TRY(p10_smp_link_firs(l_iohs, l_sublink_opt, action_t::RUNTIME, l_mask_dl_lane_errors),
                         "Error from p10_smp_link_firs when configuring for runtime operations");
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
