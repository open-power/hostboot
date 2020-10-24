/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_eff_config_links.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_fbc_eff_config_links.C
/// @brief Set fabric effective link config attributes (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB,FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fbc_eff_config_links.H>
#include <p10_fbc_utils.H>
#include <p10_build_smp.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Determine fabric link enable state, given endpoint target
///
/// @param[in]  i_target           Endpoint iohs target
/// @param[out] o_link_is_enabled  0=link disabled, else enabled
///
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_eff_config_links_query_link_en(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    uint8_t& o_link_is_enabled)
{
    FAPI_DBG("Start");

    fapi2::ATTR_IOHS_CONFIG_MODE_Type l_iohs_config_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, i_target, l_iohs_config_mode),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");

    if ((l_iohs_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX) ||
        (l_iohs_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA))
    {
        fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, i_target, l_link_train),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");

        switch(l_link_train)
        {
            case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH:
                o_link_is_enabled = fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE;
                break;

            case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY:
                o_link_is_enabled = fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_EVEN_ONLY;
                break;

            case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY:
                o_link_is_enabled = fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ODD_ONLY;
                break;

            default:
                o_link_is_enabled = fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE;
                break;
        }
    }
    else
    {
        o_link_is_enabled = fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE;
    }

fapi_try_exit:
    FAPI_DBG("End, o_link_is_enabled: 0x%x", o_link_is_enabled);
    return fapi2::current_err;
}

///
/// @brief Verify the validity of fabric IDs for the mapped loc/rem endpoints
///        and return the remote fabric group or chip bits if valid
///
/// @param[in]  i_loc_target      Local processor target
/// @param[in]  i_rem_target      Remote processor target
/// @param[in]  i_fbc_id_is_chip  Fabric chip ID if true; else group ID
/// @param[out] o_rem_fbc_id      Remote fabric group/chip ID
///
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_eff_config_links_rem_fbc_id(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_loc_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_rem_target,
    const bool i_fbc_id_is_chip,
    uint8_t& o_rem_fbc_id)
{
    FAPI_DBG("Start");

    uint8_t l_loc_fbc_group_id = 0;
    uint8_t l_rem_fbc_group_id = 0;
    uint8_t l_loc_fbc_chip_id = 0;
    uint8_t l_rem_fbc_chip_id = 0;

    FAPI_TRY(p10_fbc_utils_get_topology_id(i_loc_target, l_loc_fbc_group_id, l_loc_fbc_chip_id),
             "Error from p10_fbc_utils_get_topology_id (local target)");
    FAPI_TRY(p10_fbc_utils_get_topology_id(i_rem_target, l_rem_fbc_group_id, l_rem_fbc_chip_id),
             "Error from p10_fbc_utils_get_topology_id (remote target)");

    if(i_fbc_id_is_chip)
    {
        FAPI_ASSERT(l_loc_fbc_group_id == l_rem_fbc_group_id,
                    fapi2::P10_FBC_EFF_CONFIG_LINKS_SAME_GROUP_ID_ERR()
                    .set_LOC_TARGET(i_loc_target)
                    .set_REM_TARGET(i_rem_target)
                    .set_LOC_FBC_GROUP_ID(l_loc_fbc_group_id)
                    .set_REM_FBC_GROUP_ID(l_rem_fbc_group_id)
                    .set_LOC_FBC_CHIP_ID(l_loc_fbc_chip_id)
                    .set_REM_FBC_CHIP_ID(l_rem_fbc_chip_id),
                    "Local and remote endpoints in the same group should have the same group IDs");

        o_rem_fbc_id = l_rem_fbc_chip_id;
    }
    else
    {
        FAPI_ASSERT(l_loc_fbc_group_id != l_rem_fbc_group_id,
                    fapi2::P10_FBC_EFF_CONFIG_LINKS_DIFF_GROUP_ID_ERR()
                    .set_LOC_TARGET(i_loc_target)
                    .set_REM_TARGET(i_rem_target)
                    .set_LOC_FBC_GROUP_ID(l_loc_fbc_group_id)
                    .set_REM_FBC_GROUP_ID(l_rem_fbc_group_id)
                    .set_LOC_FBC_CHIP_ID(l_loc_fbc_chip_id)
                    .set_REM_FBC_CHIP_ID(l_rem_fbc_chip_id),
                    "Local and remote endpoints in different groups should have different group IDs");

        o_rem_fbc_id = l_rem_fbc_group_id;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Determine local/remote end parameters of link using endpoint target
///
/// @param[in]  i_loc_target      Endpoint iohs target of local end of link
/// @param[in]  i_fbc_id_is_chip  Fabric chip ID if true; else group ID
/// @param[out] o_loc_link_en     Array of local end link enables
/// @param[out] o_rem_link_id     Array of remote end link IDs
/// @param[out] o_rem_fbc_id      Array of remote end fabric topology IDs
///
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_eff_config_links_query_endp(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_loc_target,
    const bool i_fbc_id_is_chip,
    uint8_t o_loc_link_en[],
    uint8_t o_rem_link_id[],
    uint8_t o_rem_fbc_id[])
{
    FAPI_DBG("Start");

    fapi2::ATTR_CHIP_UNIT_POS_Type l_loc_link_id;
    fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_link_active;

    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_rem_target;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_rem_proc_target;
    auto l_loc_proc_target = i_loc_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_loc_target, l_loc_link_id),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    FAPI_TRY(p10_fbc_eff_config_links_query_link_en(i_loc_target, o_loc_link_en[l_loc_link_id]),
             "Error from p10_fbc_eff_config_links_query_link_en (local)");

    ////////////////////////////////////////////////////////
    // Local end link target is enabled, query remote end
    ////////////////////////////////////////////////////////
    if (o_loc_link_en[l_loc_link_id])
    {
        // obtain endpoint target associated with remote end of link
        fapi2::ReturnCode l_rc = i_loc_target.getOtherEnd(l_rem_target);

        if (l_rc)
        {
            // endpoint target for remote end of link is not configured
            o_loc_link_en[l_loc_link_id] = 0;
        }
        else
        {
            // verify that remote link end is also enabled, otherwise assert that
            // local link is also not enabled. avoid directly qualifying the local link
            // enable with the remote endpoint state since this can be problematic for
            // links with lane swap where one link end may have even-only trained, while
            // the remote end may have odd-only trained

            uint8_t l_rem_link_en = 0;
            FAPI_TRY(p10_fbc_eff_config_links_query_link_en(l_rem_target, l_rem_link_en),
                     "Error from p10_fbc_eff_config_links_query_link_en (remote)");

            if(l_rem_link_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
            {
                o_loc_link_en[l_loc_link_id] = fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE;
            }
        }
    }

    ////////////////////////////////////////////////////////
    // Both local and remote endpoints are enabled, gather
    // remaining remote end parameters
    ////////////////////////////////////////////////////////
    if (o_loc_link_en[l_loc_link_id])
    {
        fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_Type l_loc_proc_id, l_rem_proc_id;
        l_rem_proc_target = l_rem_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

        // obtain remote link id
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_rem_target, o_rem_link_id[l_loc_link_id]),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        // obtain remote fbc id
        FAPI_TRY(p10_fbc_eff_config_links_rem_fbc_id(
                     l_loc_proc_target,
                     l_rem_proc_target,
                     i_fbc_id_is_chip,
                     o_rem_fbc_id[l_loc_link_id]),
                 "Error from p10_fbc_eff_config_links_rem_fbc_id");

        // print out mapped local and remote endpoints for debug
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID, l_loc_proc_target, l_loc_proc_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_TOPOLOGY_ID)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID, l_rem_proc_target, l_rem_proc_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_TOPOLOGY_ID)");
        FAPI_DBG("Local proc ID: 0x%x, Remote proc ID: 0x%x, Link ID: %d", l_loc_proc_id, l_rem_proc_id, l_loc_link_id);
    }

    ////////////////////////////////////////////////////////
    // Update attributes based on link state
    // Note that these need to be configured both when link
    // is enabled and disabled to support alink repair
    ////////////////////////////////////////////////////////

    // write fabric link active attribute to indicate that the link is used for fabric operations
    l_link_active = (o_loc_link_en[l_loc_link_id]) ?
                    (fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_TRUE) : (fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_FALSE);
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, i_loc_target, l_link_active),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_LINK_ACTIVE");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_fbc_eff_config_links(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    p10_build_smp_operation i_op)
{
    FAPI_DBG("Start, i_op = %d", i_op);

    ////////////////////////////////////////////////////////
    // Local variables
    ////////////////////////////////////////////////////////
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    auto l_iohs_targets = i_target.getChildren<fapi2::TARGET_TYPE_IOHS>();

    // logical link (X/A) configuration parameters; enable on local end
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_x_en = { 0 };
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_a_en = { 0 };
    fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG_Type l_x_num = 0;
    fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG_Type l_a_num = 0;
    uint8_t l_link_id = 0;

    // link/fabric ID on remote end; indexed by link ID on local end
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID_Type l_x_rem_link_id = { 0 };
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID_Type l_a_rem_link_id = { 0 };
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID_Type l_x_rem_fbc_id  = { 0 };
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID_Type l_a_rem_fbc_id  = { 0 };

    // fabric id type for proc connected to remote end
    fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_broadcast_mode;
    bool l_fbc_id_is_chip = false;

    ////////////////////////////////////////////////////////
    // Seed arrays with previously written attribute state
    ////////////////////////////////////////////////////////
    if (i_op == SMP_ACTIVATE_PHASE2)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_en),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, i_target, l_x_num),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINKS_CNFG)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID, i_target, l_x_rem_link_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, i_target, l_x_rem_fbc_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, i_target, l_a_en),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG, i_target, l_a_num),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINKS_CNFG)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID, i_target, l_a_rem_link_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, i_target, l_a_rem_fbc_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID)");
    }

    ////////////////////////////////////////////////////////
    // Determine whether the group or chip is used to
    // represent the attached_chip_id for smpx; note that
    // smpa will always use the group for attached_chip_id
    ////////////////////////////////////////////////////////
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_BROADCAST_MODE)");

    l_fbc_id_is_chip = (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP) ?
                       (false) : (true);

    ////////////////////////////////////////////////////////
    // Obtain endpoint info to write to X/A link attributes
    ////////////////////////////////////////////////////////
    for (auto& l_iohs_target : l_iohs_targets)
    {
        fapi2::ATTR_IOHS_CONFIG_MODE_Type l_iohs_config_mode;
        fapi2::ATTR_IOHS_DRAWER_INTERCONNECT_Type l_drawer_interconnect;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs_target, l_iohs_config_mode),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_DRAWER_INTERCONNECT, l_iohs_target, l_drawer_interconnect),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_DRAWER_INTERCONNECT)");

        if (((i_op == SMP_ACTIVATE_PHASE1) && (l_drawer_interconnect != fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_FALSE)) ||
            ((i_op == SMP_ACTIVATE_PHASE2) && (l_drawer_interconnect != fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_TRUE)))
        {
            continue;
        }

        if (l_iohs_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX)
        {
            FAPI_TRY(p10_fbc_eff_config_links_query_endp(
                         l_iohs_target,
                         l_fbc_id_is_chip,
                         l_x_en,
                         l_x_rem_link_id,
                         l_x_rem_fbc_id),
                     "Error from p10_fbc_eff_config_links_query_endp (SMPX)");
        }
        else
        {
            FAPI_TRY(p10_fbc_eff_config_links_query_endp(
                         l_iohs_target,
                         false,
                         l_a_en,
                         l_a_rem_link_id,
                         l_a_rem_fbc_id),
                     "Error from p10_fbc_eff_config_links_query_endp (SMPA)");
        }
    }

    // determine number of enabled X/A links respectively
    for (l_link_id = 0, l_x_num = 0, l_a_num = 0; l_link_id < P10_FBC_UTILS_MAX_LINKS; l_link_id++)
    {
        if (l_x_en[l_link_id])
        {
            l_x_num++;
        }

        if (l_a_en[l_link_id])
        {
            l_a_num++;
        }
    }

    ////////////////////////////////////////////////////////
    // Write determined info into X/A link attributes
    ////////////////////////////////////////////////////////
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_en),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, i_target, l_x_num),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_LINKS_CNFG)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID, i_target, l_x_rem_link_id),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, i_target, l_x_rem_fbc_id),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, i_target, l_a_en),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG, i_target, l_a_num),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_LINKS_CNFG)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID, i_target, l_a_rem_link_id),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, i_target, l_a_rem_fbc_id),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID)");

    ////////////////////////////////////////////////////////
    // For SMP_ACTIVE_PHASE1, init aggregate link attrs
    ////////////////////////////////////////////////////////
    if (i_op == SMP_ACTIVATE_PHASE1)
    {
        fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY_Type l_x_agg_link_delay;
        fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY_Type l_a_agg_link_delay;
        fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS_Type l_x_addr_dis = { 0 };
        fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS_Type l_a_addr_dis = { 0 };
        fapi2::ATTR_PROC_FABRIC_X_AGGREGATE_Type l_x_aggregate = 0;
        fapi2::ATTR_PROC_FABRIC_A_AGGREGATE_Type l_a_aggregate = 0;

        std::fill_n(l_x_agg_link_delay, P10_FBC_UTILS_MAX_LINKS, 0xFFFFFFFF);
        std::fill_n(l_a_agg_link_delay, P10_FBC_UTILS_MAX_LINKS, 0xFFFFFFFF);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY, i_target, l_x_agg_link_delay),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINK_DELAY");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS, i_target, l_x_addr_dis),
                 "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_ADDR_DIS)");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_AGGREGATE, i_target, l_x_aggregate),
                 "Error setting FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_AGGREGATE)");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY, i_target, l_a_agg_link_delay),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINK_DELAY");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS, i_target, l_a_addr_dis),
                 "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_ADDR_DIS)");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_AGGREGATE, i_target, l_a_aggregate),
                 "Error setting FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_AGGREGATE)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
