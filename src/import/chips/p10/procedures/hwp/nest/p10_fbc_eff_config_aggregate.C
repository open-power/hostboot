/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_eff_config_aggregate.C $ */
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
/// @file p10_fbc_eff_config_aggregate.C
/// @brief Set fabric effective config attributes for aggregate links (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB,FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fbc_eff_config_aggregate.H>
#include <p10_fbc_utils.H>
#include <p10_smp_wrap.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Determine link address/data & aggregation settings
///
/// @param[in]  i_target          Reference to processor chip target
/// @param[in]  i_en              Set of local link enables
/// @param[in]  i_loc_fbc_id      Local chip fabric ID
/// @param[in]  i_rem_link_id     Set of remote link IDs
/// @param[in]  i_rem_fbc_id      Set of remote fabric IDs
/// @param[in]  l_agg_link_delay  Set of link delay values
/// @param[out] o_aggregate_mode  Aggregate mode (1=configure aggregate link mode, 0=all links are coherent)
/// @param[out] o_addr_dis        Per-link address disable values (1=data only, 0=address/data)
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_eff_config_aggregate_link_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_en[],
    const uint8_t i_loc_fbc_id,
    const uint8_t i_rem_link_id[],
    const uint8_t i_rem_fbc_id[],
    const uint32_t i_agg_link_delay[],
    uint8_t& o_aggregate_mode,
    uint8_t o_addr_dis[])
{
    uint8_t l_fbc_id_active_count[P10_FBC_UTILS_MAX_CHIPS] = { 0 };
    uint8_t l_aggregate_rem_fbc_id;

    // determine number of links targeting each fabric ID and disable aggregate mode by default
    for (uint8_t l_loc_link_id = 0; l_loc_link_id < P10_FBC_UTILS_MAX_LINKS; l_loc_link_id++)
    {
        if (i_en[l_loc_link_id])
        {
            l_fbc_id_active_count[i_rem_fbc_id[l_loc_link_id]]++;
        }

        o_addr_dis[l_loc_link_id] = 0;
    }

    for (uint8_t l_loc_link_id = 0; l_loc_link_id < P10_FBC_UTILS_MAX_LINKS; l_loc_link_id++)
    {
        FAPI_DBG("loc_fbc_id %d: l_fbc_id_active_count[%d]=%d\n",
                 i_loc_fbc_id, l_loc_link_id, l_fbc_id_active_count[l_loc_link_id]);
    }

    o_aggregate_mode = 0;

    // set aggregate mode if more than one link is pointed at the same remote fabric ID
    for (uint8_t l_rem_fbc_id = 0; l_rem_fbc_id < P10_FBC_UTILS_MAX_CHIPS; l_rem_fbc_id++)
    {
        // continue to process next remote fabric ID if one link or less connected
        if(l_fbc_id_active_count[l_rem_fbc_id] <= 1)
        {
            continue;
        }

        // only one set of aggregate links are supported, throw error if more than one set
        FAPI_ASSERT(!o_aggregate_mode,
                    fapi2::P10_FBC_EFF_CONFIG_AGGREGATE_INVALID_CONFIG_ERR().
                    set_TARGET(i_target).
                    set_LOCAL_FBC_ID(i_loc_fbc_id).
                    set_REMOTE_FBC_ID1(l_aggregate_rem_fbc_id).
                    set_REMOTE_FBC_ID2(l_rem_fbc_id),
                    "Invalid aggregate link configuration!");

        o_aggregate_mode = 1;
        l_aggregate_rem_fbc_id = l_rem_fbc_id;

        // scan link delays for smallest value
        uint8_t l_loc_coherent_link_id = 0xFF;
        uint32_t l_loc_coherent_link_delay = 0xFFFFFFFF;

        for (uint8_t l_loc_link_id = 0; l_loc_link_id < P10_FBC_UTILS_MAX_LINKS; l_loc_link_id++)
        {
            if (i_en[l_loc_link_id] && (i_agg_link_delay[l_loc_link_id] < l_loc_coherent_link_delay))
            {
                l_loc_coherent_link_delay = i_agg_link_delay[l_loc_link_id];
                FAPI_DBG("Setting coherent_link_delay = %d", l_loc_coherent_link_delay);
            }
        }

        // determine if more than one link matches the minimum delay
        uint8_t l_matches = 0;

        for (uint8_t l_loc_link_id = 0; l_loc_link_id < P10_FBC_UTILS_MAX_LINKS; l_loc_link_id++)
        {
            if (i_en[l_loc_link_id] && (i_agg_link_delay[l_loc_link_id] == l_loc_coherent_link_delay))
            {
                l_matches++;
                l_loc_coherent_link_id = l_loc_link_id;
            }
        }

        // ties must be broken consistently on both connected chips; we
        // need to pick both ends of the same link to carry coherency
        // select link with lowest link ID number on chip with smaller fabric ID
        if (l_matches != 1)
        {
            FAPI_DBG("Breaking tie");

            if (i_loc_fbc_id < l_rem_fbc_id)
            {
                // local fabric ID is smaller than remote
                for (uint8_t l_loc_link_id = 0; l_loc_link_id < P10_FBC_UTILS_MAX_LINKS; l_loc_link_id++)
                {
                    if (i_en[l_loc_link_id] && (i_agg_link_delay[l_loc_link_id] == l_loc_coherent_link_delay))
                    {
                        l_loc_coherent_link_id = l_loc_link_id;
                        break;
                    }
                }

                FAPI_DBG("Selecting coherent link = link %d based on local chip", l_loc_coherent_link_id);
            }
            else
            {
                // remote fabric ID is smaller than local
                uint8_t l_rem_coherent_link_id = 0xFF;

                for (uint8_t l_loc_link_id = 0; l_loc_link_id < P10_FBC_UTILS_MAX_LINKS; l_loc_link_id++)
                {
                    if (i_en[l_loc_link_id]
                        && (i_agg_link_delay[l_loc_link_id] == l_loc_coherent_link_delay)
                        && (i_rem_link_id[l_loc_link_id] < l_rem_coherent_link_id))
                    {
                        l_rem_coherent_link_id = i_rem_link_id[l_loc_link_id];
                        l_loc_coherent_link_id = l_loc_link_id;
                    }
                }

                FAPI_DBG("Selecting coherent link = link %d based on remote chip", l_loc_coherent_link_id);
            }
        }

        // disable coherent traffic on all other links connected to same remote chip as selected coherent link
        for (uint8_t l_loc_link_id = 0; l_loc_link_id < P10_FBC_UTILS_MAX_LINKS; l_loc_link_id++)
        {
            if (i_en[l_loc_link_id]
                && (i_rem_fbc_id[l_loc_link_id] == i_rem_fbc_id[l_loc_coherent_link_id])
                && (l_loc_link_id != l_loc_coherent_link_id))
            {
                FAPI_DBG("Setting addr_dis[%d] = 1\n", l_loc_link_id);
                o_addr_dis[l_loc_link_id] = 1;
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_fbc_eff_config_aggregate(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    ////////////////////////////////////////////////////////
    // Local variables
    ////////////////////////////////////////////////////////

    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_x_en;
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_a_en;
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID_Type l_x_rem_link_id;
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID_Type l_a_rem_link_id;
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID_Type l_x_rem_fbc_id;
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID_Type l_a_rem_fbc_id;
    fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY_Type l_x_agg_link_delay;
    fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY_Type l_a_agg_link_delay;
    fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS_Type l_x_addr_dis;
    fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS_Type l_a_addr_dis;
    fapi2::ATTR_PROC_FABRIC_X_AGGREGATE_Type l_x_aggregate;
    fapi2::ATTR_PROC_FABRIC_A_AGGREGATE_Type l_a_aggregate;

    fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_broadcast_mode;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint8_t l_loc_fbc_chip_id;
    uint8_t l_loc_fbc_group_id;
    uint8_t l_loc_fbc_id;

    ////////////////////////////////////////////////////////
    // Skip aggregate link config in manufacturing mode
    ////////////////////////////////////////////////////////
    bool l_smp_wrap_config;
    FAPI_TRY(p10_smp_wrap_mfg_mode(l_smp_wrap_config),
             "Error from p10_smp_wrap_mfg_mode");

    if(l_smp_wrap_config)
    {
        FAPI_DBG("Skipping aggregate links setup (MNFG_SMP_WRAP_CONFIG)");
        goto fapi_try_exit;
    }

    ////////////////////////////////////////////////////////
    // Read attributes
    ////////////////////////////////////////////////////////
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID, i_target, l_x_rem_link_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, i_target, l_x_rem_fbc_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY, i_target, l_x_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINK_DELAYS)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS, i_target, l_x_addr_dis),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ADDR_DIS)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_AGGREGATE, i_target, l_x_aggregate),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_AGGREGATE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, i_target, l_a_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID, i_target, l_a_rem_link_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, i_target, l_a_rem_fbc_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY, i_target, l_a_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINK_DELAYS)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS, i_target, l_a_addr_dis),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ADDR_DIS)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_AGGREGATE, i_target, l_a_aggregate),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_AGGREGATE)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_BROADCAST_MODE)");
    FAPI_TRY(p10_fbc_utils_get_topology_id(i_target, l_loc_fbc_group_id, l_loc_fbc_chip_id),
             "Error from p10_fbc_utils_get_topology_id");

    ////////////////////////////////////////////////////////
    // Determine whether group or chip bits should be used
    // for the fabric id for smpx-configured links
    ////////////////////////////////////////////////////////
    l_loc_fbc_id = (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP) ?
                   (l_loc_fbc_group_id) : (l_loc_fbc_chip_id);

    FAPI_DBG("Processing l_loc_fbc_id = %d\n", l_loc_fbc_id);

    ////////////////////////////////////////////////////////
    // Calculate aggregate configuration
    ////////////////////////////////////////////////////////
    FAPI_TRY(p10_fbc_eff_config_aggregate_link_setup(
                 i_target,
                 l_x_en,
                 l_loc_fbc_id,
                 l_x_rem_link_id,
                 l_x_rem_fbc_id,
                 l_x_agg_link_delay,
                 l_x_aggregate,
                 l_x_addr_dis),
             "Error from p10_fbc_eff_config_aggregate_link_setup (X)");

    FAPI_TRY(p10_fbc_eff_config_aggregate_link_setup(
                 i_target,
                 l_a_en,
                 l_loc_fbc_group_id,
                 l_a_rem_link_id,
                 l_a_rem_fbc_id,
                 l_a_agg_link_delay,
                 l_a_aggregate,
                 l_a_addr_dis),
             "Error from p10_fbc_eff_config_aggregate_link_setup (A)");

    ////////////////////////////////////////////////////////
    // Write attributes
    ////////////////////////////////////////////////////////
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS, i_target, l_x_addr_dis),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_ADDR_DIS)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_AGGREGATE, i_target, l_x_aggregate),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_AGGREGATE)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS, i_target, l_a_addr_dis),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_ADDR_DIS)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_AGGREGATE, i_target, l_a_aggregate),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_AGGREGATE)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
