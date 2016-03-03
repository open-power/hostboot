/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_fbc_eff_config_links.C $      */
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
/// @file p9_fbc_eff_config_links.C
/// @brief Set fabric effective link config attributes (FAPI2)
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
#include <p9_fbc_eff_config_links.H>
#include <p9_fbc_smp_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


///
/// @brief Determine fabric link enable state, given endpoint target
///
/// @tparam T template parameter, passed in target.
/// @param[in]  i_loc_target      Endpoint target (of type T)
/// @param[out] o_link_is_enabled 1=link enabled, 0=link disabled
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode p9_fbc_eff_config_links_query_link_en(
    const fapi2::Target<T>& i_target,
    uint8_t& o_link_is_enabled);

// template specialization for XBUS target type
template<>
fapi2::ReturnCode p9_fbc_eff_config_links_query_link_en(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
    uint8_t& o_link_is_enabled)
{
    o_link_is_enabled = 1;
    return fapi2::current_err;
}

// template specialization for OBUS target type
template<>
fapi2::ReturnCode p9_fbc_eff_config_links_query_link_en(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_target,
    uint8_t& o_link_is_enabled)
{
    // validate that link is configured for SMP operation
    fapi2::ATTR_OPTICS_CONFIG_MODE_Type l_link_config_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OPTICS_CONFIG_MODE, i_target, l_link_config_mode),
             "Error from FAPI_ATTR_GET (ATTR_OPTICS_CONFIG_MODE)");
    o_link_is_enabled = (l_link_config_mode == fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_SMP) ? (1) : (0);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Map endpoint target to X/A link ID
///
/// @tparam T template parameter, passed in target.
/// @param[in]  i_loc_target          Endpoint target (of type T) of local end of link
/// @param[in]  i_link_ctl_arr        Array of X/A link control structures
/// @param[in]  i_link_ctl_arr_size   Number of entries in i_link_ctl_arr
/// @param[in]  o_link_id             X/A logical link ID
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode p9_fbc_eff_config_links_map_endp(
    const fapi2::Target<T>& i_target,
    const p9_fbc_link_ctl_t i_link_ctl_arr[],
    const uint8_t i_link_ctl_arr_size,
    uint8_t& o_link_id)
{
    FAPI_DBG("Start");

    uint8_t l_loc_unit_id;
    bool l_found = false;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_loc_unit_id),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    for (uint8_t l_link_id = 0; (l_link_id < i_link_ctl_arr_size) && !l_found; l_link_id++)
    {
        if ((static_cast<fapi2::TargetType>(i_link_ctl_arr[l_link_id].endp_type) == T) &&
            (i_link_ctl_arr[l_link_id].endp_unit_id == l_loc_unit_id))
        {
            o_link_id = l_link_id;
            l_found = true;
        }
    }

    FAPI_ASSERT(l_found,
                fapi2::P9_FBC_EFF_CONFIG_LINKS_LOOKUP_ERR()
                .set_TARGET(i_target)
                .set_UNIT_ID(l_loc_unit_id),
                "Error finding matching X/A link for endpoint target");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Determine local/remote end parameters of link using endpoint target
///
/// @tparam T template parameter, passed in target.
/// @param[in]  i_loc_target          Endpoint target (of type T) of local end of link
/// @param[in]  i_loc_fbc_chip_id     FBC Chip ID of local end chip
/// @param[in]  i_loc_fbc_group_id    FBC Group ID of local end chip
/// @param[in]  i_link_ctl_arr        Array of X/A link control structures
/// @param[in]  i_link_ctl_arr_size   Number of entries in i_link_ctl_arr
/// @param[in]  i_rem_fbc_id_is_chip  True=return FBC Chip ID in o_rem_fbc_id, false=FBC Group ID
/// @param[out] o_loc_link_en         Array of local end link enables
/// @param[out] o_rem_link_id         Array of remote end link IDs
/// @param[out] o_rem_fbc_id          Array of remote end FBC Group/Chip IDs
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode p9_fbc_eff_config_links_query_endp(
    const fapi2::Target<T>& i_loc_target,
    const uint8_t i_loc_fbc_chip_id,
    const uint8_t i_loc_fbc_group_id,
    const p9_fbc_link_ctl_t i_link_ctl_arr[],
    const uint8_t i_link_ctl_arr_size,
    bool i_rem_fbc_id_is_chip,
    uint8_t o_loc_link_en[],
    uint8_t o_rem_link_id[],
    uint8_t o_rem_fbc_id[])
{
    FAPI_DBG("Start");

    // A/X link ID for local end
    uint8_t l_loc_link_id;
    // remote end target
    fapi2::Target<T> l_rem_target;

    // determine link ID/enable state for local end
    FAPI_TRY(p9_fbc_eff_config_links_map_endp<T>(
                 i_loc_target,
                 i_link_ctl_arr,
                 i_link_ctl_arr_size,
                 l_loc_link_id),
             "Error from p9_fbc_eff_config_links_map_endp (local)");

    FAPI_TRY(p9_fbc_eff_config_links_query_link_en<T>(i_loc_target, o_loc_link_en[l_loc_link_id]),
             "Error from p9_fbc_eff_config_links_query_link_en (local)");

    // local end link target is enabled, query remote end
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
            // endpoint target is configured, qualify local link enable with remote endpoint state
            FAPI_TRY(p9_fbc_eff_config_links_query_link_en<T>(l_rem_target, o_loc_link_en[l_loc_link_id]),
                     "Error from p9_fbc_eff_config_links_query_link_en (remote)");
        }
    }

    // link is enabled, gather remaining remote end parameters
    if (o_loc_link_en[l_loc_link_id])
    {
        uint8_t l_rem_fbc_group_id;
        uint8_t l_rem_fbc_chip_id;

        FAPI_TRY(p9_fbc_eff_config_links_map_endp<T>(
                     l_rem_target,
                     i_link_ctl_arr,
                     i_link_ctl_arr_size,
                     o_rem_link_id[l_loc_link_id]),
                 "Error from p9_fbc_eff_config_links_map_endp (remote)");

        // return either chip or group ID of remote chip
        FAPI_TRY(p9_fbc_utils_get_chip_id_attr(l_rem_target, l_rem_fbc_chip_id),
                 "Error from p9_fbc_utils_get_chip_id_attr (remote)");

        FAPI_TRY(p9_fbc_utils_get_group_id_attr(l_rem_target, l_rem_fbc_group_id),
                 "Error from p9_fbc_utils_get_group_id_attr (remote)");

        if (i_rem_fbc_id_is_chip)
        {
            // assert that group IDs match, return remote chip ID
            FAPI_ASSERT(l_rem_fbc_group_id == i_loc_fbc_group_id,
                        fapi2::P9_FBC_EFF_CONFIG_LINKS_GROUP_ID_ERR()
                        .set_LOC_TARGET(i_loc_target)
                        .set_REM_TARGET(l_rem_target)
                        .set_LOC_FBC_GROUP_ID(i_loc_fbc_group_id)
                        .set_REM_FBC_GROUP_ID(l_rem_fbc_group_id),
                        "X connected chips do not have the same group ID");
            o_rem_fbc_id[l_loc_link_id] = l_rem_fbc_chip_id;
        }
        else
        {
            // assert that chip IDs match, return remote group ID
            FAPI_ASSERT(l_rem_fbc_chip_id == i_loc_fbc_chip_id,
                        fapi2::P9_FBC_EFF_CONFIG_LINKS_CHIP_ID_ERR()
                        .set_LOC_TARGET(i_loc_target)
                        .set_REM_TARGET(l_rem_target)
                        .set_LOC_FBC_CHIP_ID(i_loc_fbc_chip_id)
                        .set_REM_FBC_CHIP_ID(l_rem_fbc_chip_id),
                        "A connected chips do not have the same chip ID");
            o_rem_fbc_id[l_loc_link_id] = l_rem_fbc_group_id;
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see doxygen comments in header
fapi2::ReturnCode
p9_fbc_eff_config_links(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                        p9_build_smp_operation i_op,
                        bool i_process_electrical,
                        bool i_process_optical)

{
    FAPI_DBG("Start");

    // local chip fabric chip/group IDs
    uint8_t l_loc_fbc_chip_id;
    uint8_t l_loc_fbc_group_id;

    // logical link (X/A) configuration parameters, init arrays to default values
    // enable on local end
    uint8_t l_x_en[P9_FBC_UTILS_MAX_X_LINKS] = { 0 };
    uint8_t l_a_en[P9_FBC_UTILS_MAX_A_LINKS] = { 0 };
    // link/fabric ID on remote end
    // indexed by link ID on local end
    uint8_t l_x_rem_link_id[P9_FBC_UTILS_MAX_X_LINKS] = { 0 };
    uint8_t l_x_rem_fbc_chip_id[P9_FBC_UTILS_MAX_X_LINKS] = { 0 };
    uint8_t l_a_rem_link_id[P9_FBC_UTILS_MAX_A_LINKS] = { 0 };
    uint8_t l_a_rem_fbc_group_id[P9_FBC_UTILS_MAX_A_LINKS] = { 0 };

    // seed arrays with previously written attribute state
    if (i_op == SMP_ACTIVATE_PHASE2)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_en),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID, i_target, l_x_rem_link_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, i_target, l_x_rem_fbc_chip_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, i_target, l_a_en),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID, i_target, l_a_rem_link_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, i_target, l_a_rem_fbc_group_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID)");
    }

    FAPI_TRY(p9_fbc_utils_get_chip_id_attr(i_target, l_loc_fbc_chip_id),
             "Error from p9_fbc_utils_get_chip_id_attr");
    FAPI_TRY(p9_fbc_utils_get_group_id_attr(i_target, l_loc_fbc_group_id),
             "Error from p9_fbc_utils_get_group_id_attr");

    if (i_process_electrical)
    {
        // process XBUS (electrical) endp targets
        auto l_electrical_targets = i_target.getChildren<fapi2::TARGET_TYPE_XBUS>();

        for (auto l_iter = l_electrical_targets.begin();
             l_iter != l_electrical_targets.end();
             l_iter++)
        {
            FAPI_TRY(p9_fbc_eff_config_links_query_endp<fapi2::TARGET_TYPE_XBUS>(
                         *l_iter,
                         l_loc_fbc_chip_id,
                         l_loc_fbc_group_id,
                         P9_FBC_XBUS_LINK_CTL_ARR,
                         P9_FBC_UTILS_MAX_X_LINKS,
                         true,
                         l_x_en,
                         l_x_rem_link_id,
                         l_x_rem_fbc_chip_id),
                     "Error from p9_fbc_eff_config_links_query_endp (electrical)");
        }
    }

    if (i_process_optical)
    {
        // process OBUS (optical) endp targets
        auto l_optical_targets = i_target.getChildren<fapi2::TARGET_TYPE_OBUS>();

        // determine optical link usage mode
        // - if configured for X link use, fill in logical X link attributes
        // - if configured for A link use, fill in logical A link attributes
        fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE_Type l_smp_optics_mode;
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE, FAPI_SYSTEM, l_smp_optics_mode),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_SMP_OPTICS_MODE)");

        for (auto l_iter = l_optical_targets.begin();
             l_iter != l_optical_targets.end();
             l_iter++)
        {
            if (l_smp_optics_mode == fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_X_BUS)
            {
                FAPI_TRY(p9_fbc_eff_config_links_query_endp<fapi2::TARGET_TYPE_OBUS>(
                             *l_iter,
                             l_loc_fbc_chip_id,
                             l_loc_fbc_group_id,
                             P9_FBC_XBUS_LINK_CTL_ARR,
                             P9_FBC_UTILS_MAX_X_LINKS,
                             true,
                             l_x_en,
                             l_x_rem_link_id,
                             l_x_rem_fbc_chip_id),
                         "Error from p9_fbc_eff_config_links_query_endp (optical, X)");
            }
            else
            {
                FAPI_TRY(p9_fbc_eff_config_links_query_endp<fapi2::TARGET_TYPE_OBUS>(
                             *l_iter,
                             l_loc_fbc_chip_id,
                             l_loc_fbc_group_id,
                             P9_FBC_ABUS_LINK_CTL_ARR,
                             P9_FBC_UTILS_MAX_A_LINKS,
                             false,
                             l_a_en,
                             l_a_rem_link_id,
                             l_a_rem_fbc_group_id),
                         "Error from p9_fbc_eff_config_links_query_endp (optical, A)");
            }
        }
    }

    // set attributes
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_en),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID, i_target, l_x_rem_link_id),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID)");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, i_target, l_x_rem_fbc_chip_id),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID)");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, i_target, l_a_en),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID, i_target, l_a_rem_link_id),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID)");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, i_target, l_a_rem_fbc_group_id),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID)");

    // initialize all link realted attributes?
    if (i_op == SMP_ACTIVATE_PHASE1)
    {
        // aggregate (local+remote) delays
        uint32_t l_x_agg_link_delay[P9_FBC_UTILS_MAX_X_LINKS];
        uint32_t l_a_agg_link_delay[P9_FBC_UTILS_MAX_A_LINKS];
        std::fill_n(l_x_agg_link_delay, P9_FBC_UTILS_MAX_X_LINKS, 0xFFFFFFFF);
        std::fill_n(l_a_agg_link_delay, P9_FBC_UTILS_MAX_A_LINKS, 0xFFFFFFFF);

        // aggregate model/address disable on local end
        uint8_t l_x_addr_dis[P9_FBC_UTILS_MAX_X_LINKS] = { 0 };
        uint8_t l_x_aggregate = 0;
        uint8_t l_a_addr_dis[P9_FBC_UTILS_MAX_A_LINKS] = { 0 };
        uint8_t l_a_aggregate = 0;

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
