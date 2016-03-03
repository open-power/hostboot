/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_fbc_eff_config_aggregate.C $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_fbc_eff_config_aggregate.C
/// @brief Set fabric effective config attributes for aggregate links (FAPI2)
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
/// *HWP Consumed by: HB,FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_fbc_eff_config_aggregate.H>
#include <p9_fbc_smp_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


/// @brief Determine link address/data & aggregation settings
///
/// @param[in]  i_max_links       Size of input/output arrays
/// @param[in]  i_en              Set of local link enables (index = local link ID)
/// @param[in]  i_loc_fbc_id      Local chip fabric ID
/// @param[in]  i_rem_link_id     Set of remote link IDs (index = local link ID)
/// @param[in]  i_rem_fbc_id      Set of remote fabric IDs (index = local link ID)
/// @param[in]  l_agg_link_delay  Set of link delay values (index = local link ID)
/// @param[out] o_aggregate_mode  1=Configure aggregate link mode, 0=all links are coherent
/// @param[out] o_addr_dis        Per-link address disable values (index = local link ID)
///                               (1=address only, 0=address/data)
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_fbc_eff_config_aggregate_link_setup(
    const uint8_t i_max_links,
    const uint8_t i_en[],
    const uint8_t i_loc_fbc_id,
    const uint8_t i_rem_link_id[],
    const uint8_t i_rem_fbc_id[],
    const uint32_t i_agg_link_delay[],
    uint8_t& o_aggregate_mode,
    uint8_t o_addr_dis[])
{
    fapi2::ReturnCode l_rc;

    // mark number of links targeting each fabric ID
    // set output defaults to disable aggregate mode (all links carry coherent traffic)
    uint8_t l_fbc_id_active_count[P9_FBC_UTILS_NUM_CHIP_IDS] = { 0 };

    for (uint8_t l_loc_link_id = 0; l_loc_link_id < i_max_links; l_loc_link_id++)
    {
        // if link is valid, bump fabric ID usage count
        if (i_en[l_loc_link_id])
        {
            l_fbc_id_active_count[i_rem_link_id[l_loc_link_id]]++;
        }

        o_addr_dis[l_loc_link_id] = 0;
    }

    o_aggregate_mode = 0;

    // set aggregate mode if more than one link is pointed at the same remote
    // fabric ID
    for (uint8_t l_rem_fbc_id = 0; l_rem_fbc_id < P9_FBC_UTILS_NUM_CHIP_IDS; l_rem_fbc_id++)
    {
        if (l_fbc_id_active_count[l_rem_fbc_id] > 1)
        {
            // only one set of aggregate links are supported
            FAPI_ASSERT(!o_aggregate_mode,
                        fapi2::P9_FBC_EFF_CONFIG_AGGREGATE_INVALID_CONFIG_ERR(),
                        "Invalid aggregate link configuration!");
            o_aggregate_mode = 1;

            // flip default value for link address disable
            for (uint8_t l_loc_link_id = 0; l_loc_link_id < i_max_links; l_loc_link_id++)
            {
                o_addr_dis[l_loc_link_id] = i_en[l_loc_link_id];
            }

            // scan link delays for smallest value
            uint8_t l_loc_coherent_link_id = 0xFF;
            uint32_t l_loc_coherent_link_delay = 0xFFFFFFFF;

            for (uint8_t l_loc_link_id = 0; l_loc_link_id < i_max_links; l_loc_link_id++)
            {
                if (i_en[l_loc_link_id] &&
                    (i_agg_link_delay[l_loc_link_id] < l_loc_coherent_link_delay))
                {
                    l_loc_coherent_link_delay = i_agg_link_delay[l_loc_link_id];
                    FAPI_DBG("Setting coherent_link_delay = %d", l_loc_coherent_link_delay);
                }
            }

            // determine if more than one link matches the minimum delay
            uint8_t l_matches = 0;

            for (uint8_t l_loc_link_id = 0; l_loc_link_id < i_max_links; l_loc_link_id++)
            {
                if (i_en[l_loc_link_id] &&
                    (i_agg_link_delay[l_loc_link_id] == l_loc_coherent_link_delay))
                {
                    l_matches++;
                    l_loc_coherent_link_id = l_loc_link_id;
                }
            }

            // ties must be broken consistenty on both connected chips (i.e., we
            // need to pick both ends of the same link to carry coherency
            // select link with lowest link ID number on chip with smaller fabric ID
            // (chip ID if X links, group ID if A links)
            if (l_matches != 1)
            {
                FAPI_DBG("Breaking tie");

                if (i_loc_fbc_id < l_rem_fbc_id)
                {
                    // local fabric ID is smaller than remote
                    for (uint8_t l_loc_link_id = 0; l_loc_link_id < i_max_links; l_loc_link_id++)
                    {
                        if (i_en[l_loc_link_id] &&
                            (i_agg_link_delay[l_loc_link_id] == l_loc_coherent_link_delay))
                        {
                            l_loc_coherent_link_id = l_loc_link_id;
                            break;
                        }
                    }

                    FAPI_DBG("Selecting coherent link = link %d based on local chip",
                             l_loc_coherent_link_id);
                }
                else
                {
                    // remote fabric ID is smaller than local
                    uint8_t l_rem_coherent_link_id = 0xFF;

                    for (uint8_t l_loc_link_id = 0; l_loc_link_id < i_max_links; l_loc_link_id++)
                    {
                        if (i_en[l_loc_link_id] &&
                            (i_agg_link_delay[l_loc_link_id] == l_loc_coherent_link_delay) &&
                            (i_rem_link_id[l_loc_link_id] < l_rem_coherent_link_id))
                        {
                            l_rem_coherent_link_id = i_rem_link_id[l_loc_link_id];
                            l_loc_coherent_link_id = l_loc_link_id;
                        }
                    }
                }
            }

            o_addr_dis[l_loc_coherent_link_id] = 0;
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see doxygen comments in header
fapi2::ReturnCode
p9_fbc_eff_config_aggregate(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    // local chip fabric chip/group IDs
    uint8_t l_loc_fbc_chip_id;
    uint8_t l_loc_fbc_group_id;

    // logical link (X/A) configuration parameters
    // arrays indexed by link ID on local end
    // enable on local end
    uint8_t l_x_en[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_a_en[P9_FBC_UTILS_MAX_A_LINKS];
    // link/fabric ID on other end
    uint8_t l_x_rem_link_id[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_x_rem_fbc_chip_id[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_a_rem_link_id[P9_FBC_UTILS_MAX_A_LINKS];
    uint8_t l_a_rem_fbc_group_id[P9_FBC_UTILS_MAX_A_LINKS];
    // aggregate (local+remote) delays
    uint32_t l_x_agg_link_delay[P9_FBC_UTILS_MAX_X_LINKS];
    uint32_t l_a_agg_link_delay[P9_FBC_UTILS_MAX_A_LINKS];
    // aggregate model/address disable on local end
    uint8_t l_x_addr_dis[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_x_aggregate;
    uint8_t l_a_addr_dis[P9_FBC_UTILS_MAX_A_LINKS];
    uint8_t l_a_aggregate;

    // read attributes for this chip
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID, i_target, l_x_rem_link_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, i_target, l_x_rem_fbc_chip_id),
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

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, i_target, l_a_rem_fbc_group_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY, i_target, l_a_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINK_DELAYS)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS, i_target, l_a_addr_dis),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ADDR_DIS)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_AGGREGATE, i_target, l_a_aggregate),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_AGGREGATE)");

    FAPI_TRY(p9_fbc_utils_get_chip_id_attr(i_target, l_loc_fbc_chip_id),
             "Error from p9_fbc_utils_get_chip_id_attr");
    FAPI_TRY(p9_fbc_utils_get_group_id_attr(i_target, l_loc_fbc_group_id),
             "Error from p9_fbc_utils_get_group_id_attr");

    // calculate aggregate configuration
    FAPI_TRY(p9_fbc_eff_config_aggregate_link_setup(P9_FBC_UTILS_MAX_X_LINKS,
             l_x_en,
             l_loc_fbc_chip_id,
             l_x_rem_link_id,
             l_x_rem_fbc_chip_id,
             l_x_agg_link_delay,
             l_x_aggregate,
             l_x_addr_dis),
             "Error from p9_fbc_eff_config_aggregate_link_setup (X)");

    FAPI_TRY(p9_fbc_eff_config_aggregate_link_setup(P9_FBC_UTILS_MAX_A_LINKS,
             l_a_en,
             l_loc_fbc_group_id,
             l_a_rem_link_id,
             l_a_rem_fbc_group_id,
             l_a_agg_link_delay,
             l_a_aggregate,
             l_a_addr_dis),
             "Error from p9_fbc_eff_config_aggregate_link_setup (A)");

    // set attributes
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS, i_target, l_x_addr_dis),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_ADDR_DIS)");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_AGGREGATE, i_target, l_x_aggregate),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_AGGREGATE)");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS, i_target, l_a_addr_dis),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_ADDR_DIS)");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_AGGREGATE, i_target, l_a_aggregate),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_AGGREGATE)");

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}
