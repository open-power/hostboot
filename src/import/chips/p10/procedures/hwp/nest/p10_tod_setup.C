/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_tod_setup.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
//--------------------------------------------------------------------------
//
// @file p10_tod_setup.C
// @brief Procedures to configure the TOD topology
//
// *HWP HW Maintainer    : Douglas Holtsinger <Douglas.Holtsinger@ibm.com>
// *HWP FW Maintainer    : Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by      : HB,FSP
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p10_tod_setup.H>
#include <p10_scom_perv.H>
#include <p10_scom_iohs.H>

//------------------------------------------------------------------------------
// Namespace declarations
//------------------------------------------------------------------------------

using namespace scomt;
using namespace scomt::perv;
using namespace scomt::iohs;

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
// Implement workaround for P10 defect HW480746.  P9 version of the defect is HW480181.
// FIXME @RTC 213485 update setting if/when hardware fix is available.
const bool IMPLEMENT_HW480746_WORKAROUND = true;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// @brief Lookup the IOHS target associated with the Bus number and check for link active
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_bus_enum       p10_tod_setup_bus enum
/// @param[out] o_bus_num       Bus number associated with p10_tod_setup_bus enum
/// @param[out] o_iohs_target   IOHS target associated with Bus number
/// @return FAPI2_RC_SUCCESS    If the link associated with the bus number was found
///                             and is active, else return error.
fapi2::ReturnCode p10_tod_lookup_iohs_target(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_tod_setup_bus i_bus_enum,
    uint8_t& o_bus_num,
    fapi2::Target<fapi2::TARGET_TYPE_IOHS>& o_iohs_target)
{
    fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_link_active = 0;
    bool l_bus_found = false;

    // convert enum to bus number
    switch (i_bus_enum)
    {
        case TOD_SETUP_BUS_IOHS0:
            o_bus_num = 0;
            break;

        case TOD_SETUP_BUS_IOHS1:
            o_bus_num = 1;
            break;

        case TOD_SETUP_BUS_IOHS2:
            o_bus_num = 2;
            break;

        case TOD_SETUP_BUS_IOHS3:
            o_bus_num = 3;
            break;

        case TOD_SETUP_BUS_IOHS4:
            o_bus_num = 4;
            break;

        case TOD_SETUP_BUS_IOHS5:
            o_bus_num = 5;
            break;

        case TOD_SETUP_BUS_IOHS6:
            o_bus_num = 6;
            break;

        case TOD_SETUP_BUS_IOHS7:
            o_bus_num = 7;
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY_TX()
                        .set_TARGET(i_target)
                        .set_TX(i_bus_enum),
                        "i_bus_enum does not represent a bus");
            break;
    }

    // search for bus number in configured links
    for (const auto& l_iohs_target : i_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
    {
        uint8_t l_bus_num = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_bus_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        if (l_bus_num == o_bus_num)
        {
            l_bus_found = true;
            o_iohs_target = l_iohs_target;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, l_iohs_target, l_link_active),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_ACTIVE)");

            break;
        }
    }

    // check that the i_bus_enum specifies a valid bus
    FAPI_ASSERT(l_bus_found,
                fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY_TX()
                .set_TARGET(i_target)
                .set_TX(i_bus_enum),
                "Invalid TOD Topology");

    // link must be fabric-active to use it in the TOD configuration
    FAPI_ASSERT(l_link_active == fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_TRUE,
                fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY_TX()
                .set_TARGET(i_target)
                .set_TX(i_bus_enum),
                "Link associated with the bus is not active");

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Lookup the sister target for the corner where a given IOHS lives
/// @param[in] i_iohs_target    Reference to IOHS target
/// @param[out] o_iohs_target   Reference to sister IOHS target
/// @return FAPI2_RC_SUCCESS    If successful, else return error.
fapi2::ReturnCode p10_tod_lookup_sister_iohs_target(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    fapi2::Target<fapi2::TARGET_TYPE_IOHS>& o_iohs_target)
{
    auto l_target = i_iohs_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
    p10_tod_setup_bus l_bus_enum;

    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_id, l_sister_iohs_id;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iohs_target, l_iohs_id),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    // determine the sister link for the corner
    // if link is odd, sister link is the even link in the corner
    // if link is even, sister link is the odd link in the corner
    if(l_iohs_id % 2)
    {
        l_sister_iohs_id = l_iohs_id - 1;
    }
    else
    {
        l_sister_iohs_id = l_iohs_id + 1;
    }

    // convert bus id to enum
    switch(l_sister_iohs_id)
    {
        case 0:
            l_bus_enum = TOD_SETUP_BUS_IOHS0;
            break;

        case 1:
            l_bus_enum = TOD_SETUP_BUS_IOHS1;
            break;

        case 2:
            l_bus_enum = TOD_SETUP_BUS_IOHS2;
            break;

        case 3:
            l_bus_enum = TOD_SETUP_BUS_IOHS3;
            break;

        case 4:
            l_bus_enum = TOD_SETUP_BUS_IOHS4;
            break;

        case 5:
            l_bus_enum = TOD_SETUP_BUS_IOHS5;
            break;

        case 6:
            l_bus_enum = TOD_SETUP_BUS_IOHS6;
            break;

        case 7:
            l_bus_enum = TOD_SETUP_BUS_IOHS7;
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY_TX()
                        .set_TARGET(l_target)
                        .set_TX(l_sister_iohs_id),
                        "l_sister_iohs_id does not correspond to a valid bus enum");
            break;
    }

    // search whether the sister link exists and verify it is fbc-configured
    FAPI_TRY(p10_tod_lookup_iohs_target(
                 l_target,
                 l_bus_enum,
                 l_sister_iohs_id,
                 o_iohs_target),
             "Error from p10_tod_lookup_iohs_target");

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Clear Fabric DL TOD configuration
/// @param[in]  i_iohs_target   Reference to IOHS target
/// @return FAPI2_RC_SUCCESS    If successful, otherwise error.
fapi2::ReturnCode fbc_dl_tod_config_clear(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target)
{
    fapi2::buffer<uint64_t> l_dlp_config_reg = 0;

    FAPI_TRY(GET_DLP_CONFIG(i_iohs_target, l_dlp_config_reg),
             "Error from GET_DLP_CONFIG");

    SET_DLP_CONFIG_INBOUND_TOD_SELECT(0x0, l_dlp_config_reg);
    SET_DLP_CONFIG_INBOUND_TOD_CROSS_SELECT(0x0, l_dlp_config_reg);
    CLEAR_DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT(l_dlp_config_reg);
    CLEAR_DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT(l_dlp_config_reg);

    FAPI_TRY(PUT_DLP_CONFIG(i_iohs_target, l_dlp_config_reg),
             "Error from PUT_DLP_CONFIG");

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Configure Fabric DL TOD Inbound register
/// @param[in]  i_iohs_target   Reference to IOHS target
/// @return FAPI2_RC_SUCCESS    If successful, otherwise error.
fapi2::ReturnCode fbc_dl_tod_config_inbound(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target)
{
    uint8_t l_inbound_tod_select_sublink;
    fapi2::buffer<uint64_t> l_dlp_config_reg = 0;
    fapi2::ATTR_IOHS_FABRIC_TOD_CROSS_CONFIG_Type l_tod_cross_config;
    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_sister_iohs_target;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_FABRIC_TOD_CROSS_CONFIG, i_iohs_target, l_tod_cross_config),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_FABRIC_TOD_CROSS_CONFIG)");

    if(l_tod_cross_config)
    {
        FAPI_TRY(p10_tod_lookup_sister_iohs_target(i_iohs_target, l_sister_iohs_target),
                 "Error from p10_tod_lookup_sister_iohs_target");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_sister_iohs_target, l_link_train),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");
    }
    else
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, i_iohs_target, l_link_train),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");
    }

    switch(l_link_train)
    {
        case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH:
        case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY:
            l_inbound_tod_select_sublink = DLP_INBOUND_TOD_SELECT_LINK1;
            break;

        case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY:
            l_inbound_tod_select_sublink = DLP_INBOUND_TOD_SELECT_LINK0;
            break;

        default:
            l_inbound_tod_select_sublink = DLP_INBOUND_TOD_SELECT_NONE;
            break;
    }

    if(l_tod_cross_config)
    {
        FAPI_TRY(GET_DLP_CONFIG(i_iohs_target, l_dlp_config_reg),
                 "Error from getScom (DLP_CONFIG)");
        SET_DLP_CONFIG_INBOUND_TOD_SELECT(DLP_INBOUND_TOD_SELECT_OTHER, l_dlp_config_reg);
        FAPI_TRY(PUT_DLP_CONFIG(i_iohs_target, l_dlp_config_reg),
                 "Error from putScom (DLP_CONFIG)");

        FAPI_TRY(GET_DLP_CONFIG(l_sister_iohs_target, l_dlp_config_reg),
                 "Error from getScom (DLP_CONFIG)");
        SET_DLP_CONFIG_INBOUND_TOD_CROSS_SELECT(l_inbound_tod_select_sublink, l_dlp_config_reg);
        FAPI_TRY(PUT_DLP_CONFIG(l_sister_iohs_target, l_dlp_config_reg),
                 "Error from putScom (DLP_CONFIG)");
    }
    else
    {
        FAPI_TRY(GET_DLP_CONFIG(i_iohs_target, l_dlp_config_reg),
                 "Error from getScom (DLP_CONFIG)");
        SET_DLP_CONFIG_INBOUND_TOD_SELECT(l_inbound_tod_select_sublink, l_dlp_config_reg);
        FAPI_TRY(PUT_DLP_CONFIG(i_iohs_target, l_dlp_config_reg),
                 "Error from putScom (DLP_CONFIG)");
    }

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Configure Fabric DL TOD Outbound register
/// @param[in]  i_iohs_target   Reference to IOHS target
/// @param[in]  i_bus_num       Chiplet unit num asssociated with target
/// @return FAPI2_RC_SUCCESS    If successful, otherwise error.
fapi2::ReturnCode fbc_dl_tod_config_outbound(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const uint8_t& i_bus_num)
{
    fapi2::buffer<uint64_t> l_dlp_config_reg = 0;

    fapi2::ATTR_IOHS_FABRIC_TOD_CROSS_CONFIG_Type l_tod_cross_config;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_FABRIC_TOD_CROSS_CONFIG, i_iohs_target, l_tod_cross_config),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_FABRIC_TOD_CROSS_CONFIG)");

    FAPI_TRY(GET_DLP_CONFIG(i_iohs_target, l_dlp_config_reg),
             "Error from getScom (DLP_CONFIG)");

    // send tp_xb_x(0,2,4,6)_tod_sync signal to even IOHS in the corner
    // send the opposite if cross config option is enabled
    if((((i_bus_num % 2) == 0) && (l_tod_cross_config == fapi2::ENUM_ATTR_IOHS_FABRIC_TOD_CROSS_CONFIG_OFF)) ||
       (((i_bus_num % 2) == 1) && (l_tod_cross_config == fapi2::ENUM_ATTR_IOHS_FABRIC_TOD_CROSS_CONFIG_ON)))
    {
        CLEAR_DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT(l_dlp_config_reg);
        CLEAR_DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT(l_dlp_config_reg);
    }
    // send tp_xb_x(1,3,5,7)_tod_sync signal to odd IOHS in the corner
    // send the opposite if cross config option is enabled
    else
    {
        SET_DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT(l_dlp_config_reg);
        SET_DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT(l_dlp_config_reg);
    }

    FAPI_TRY(PUT_DLP_CONFIG(i_iohs_target, l_dlp_config_reg),
             "Error from putScom (DLP_CONFIG)");

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Clear the previous fabric DL inits of a TOD node
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @return FAPI2_RC_SUCCESS if fabric DL inits are successfully cleared, else error
fapi2::ReturnCode fbc_dl_tod_node_config_clear(const tod_topology_node* i_tod_node)
{
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);

    FAPI_DBG("Start");

    // Clear DLP link layer inits
    FAPI_INF("Clearing Fabric DL TOD inits");

    for(auto l_iohs_target : l_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
    {
        FAPI_TRY(fbc_dl_tod_config_clear(l_iohs_target),
                 "Error from fbc_dl_tod_config_clear");
    }

    for(auto l_child = (i_tod_node->i_children).begin();
        l_child != (i_tod_node->i_children).end();
        ++l_child)
    {
        FAPI_TRY(fbc_dl_tod_node_config_clear(*l_child),
                 "Failure clearing downstream fabric DL TOD inits!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief MPIPL specific steps to disable the TOD step checkers, this should be
//  called only during MPIPL
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @return FAPI2_RC_SUCCESS if TOD step checkers are successfully disabled, else error
fapi2::ReturnCode mpipl_disable_step_checkers(
    const tod_topology_node* i_tod_node)
{
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);
    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_DBG("Start");

    FAPI_TRY(GET_TOD_PSS_MSS_CTRL_REG(l_target, l_data),
             "Error from GET_TOD_PSS_MSS_CTRL_REG");

    l_data.clearBit<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE>()
    .clearBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE>()
    .clearBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE>()
    .clearBit<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE>()
    .clearBit<TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE>()
    .clearBit<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE>()
    .clearBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE>()
    .clearBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE>()
    .clearBit<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE>()
    .clearBit<TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE>();

    FAPI_TRY(PUT_TOD_PSS_MSS_CTRL_REG(l_target, l_data),
             "Error from PUT_TOD_PSS_MSS_CTRL_REG");

    for(auto l_child = (i_tod_node->i_children).begin();
        l_child != (i_tod_node->i_children).end();
        ++l_child)
    {
        FAPI_TRY(mpipl_disable_step_checkers(*l_child),
                 "Failure disabling TOD step checkers!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;

}

/// @brief MPIPL specific steps to clear the previous topology, this should be
//  called only during MPIPL
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to clear
/// @return FAPI2_RC_SUCCESS if TOD topology is successfully cleared, else error
fapi2::ReturnCode mpipl_clear_tod_node(
    const tod_topology_node* i_tod_node,
    const p10_tod_setup_tod_sel i_tod_sel)
{
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);
    fapi2::buffer<uint64_t> l_s_path_ctrl_reg = 0;
    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_DBG("Start");

    fapi2::toString(l_target,
                    l_targetStr,
                    fapi2::MAX_ECMD_STRING_LEN);

    FAPI_INF("MPIPL-Clearing previous %s topology from %s",
             (i_tod_sel == TOD_PRIMARY) ? "Primary" : "Secondary", l_targetStr);

    // If necessary, clear IS_SPECIAL error status bit
    FAPI_TRY(GET_TOD_PSS_MSS_STATUS_REG(l_target, l_data),
             "Error from TOD_PSS_MSS_STATUS_REG");

    if (GET_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(l_data))
    {
        FAPI_INF("MPIPL: clear IS_SPECIAL error status bit");

        // Need to clear TOD errors first before clearing special status.
        l_data.flush<1>();
        FAPI_TRY(PREP_TOD_ERROR_REG(l_target));
        FAPI_TRY(PUT_TOD_ERROR_REG(l_target, l_data),
                 "Error from PUT_TOD_ERROR_REG");

        // This clears the IS_SPECIAL error status bit
        FAPI_TRY(PREP_TOD_LOAD_MOD_REG(l_target));
        l_data.flush<0>();
        SET_TOD_LOAD_MOD_REG_TRIGGER(l_data);
        FAPI_TRY(PUT_TOD_LOAD_MOD_REG(l_target, l_data),
                 "Master: Error from PUT_TOD_LOAD_MOD_REG");
    }

    FAPI_INF("MPIPL: switch TOD to 'Not Set' state");
    // Generate TType#5 (formats defined in section "TType Fabric Interface"
    // in the TOD workbook)
    FAPI_TRY(PREP_TOD_RX_TTYPE_CTRL_REG(l_target));
    FAPI_TRY(PUT_TOD_RX_TTYPE_CTRL_REG(l_target, TOD_TTYPE_CTRL_REG_TTYPE5),
             "Error from PUT_TOD_RX_TTYPE_CTRL_REG");

    FAPI_INF("MPIPL: switch all other TODs to 'Not Set' state");
    FAPI_TRY(PREP_TOD_TX_TTYPE_5_REG(l_target));
    l_data.flush<0>();
    SET_TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER(l_data);
    FAPI_TRY(PUT_TOD_TX_TTYPE_5_REG(l_target, l_data),
             "Error from PUT_TOD_TX_TTYPE_5_REG");

    //PUT TOD in stop state
    FAPI_INF("MPIPL: put TOD to stop state");
    FAPI_TRY(PREP_TOD_LOAD_REG(l_target));
    FAPI_TRY(PUT_TOD_LOAD_REG(l_target, TOD_LOAD_TOD_REG_GOTO_STOPPED_STATE),
             "Error from PUT_TOD_LOAD_REG");

    FAPI_INF("MPIPL: Clearing TOD_M_PATH_CTRL_REG");
    FAPI_TRY(PREP_TOD_M_PATH_CTRL_REG(l_target));
    FAPI_TRY(PUT_TOD_M_PATH_CTRL_REG(l_target, 0ULL),
             "Error in clearing TOD_M_PATH_CTRL_REG");

    FAPI_TRY(PREP_TOD_S_PATH_CTRL_REG(l_target));

    if (IMPLEMENT_HW480746_WORKAROUND)
    {
        // Workaround for HW480746: Init remote sync checker tolerance to maximum;
        // will be closed down by configure_tod_node (configure_s_path_ctrl_reg) later.
        FAPI_INF("Implementing workaround for defect HW480746");
        SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR(STEP_CHECK_CPS_DEVIATION_FACTOR_8,
                l_s_path_ctrl_reg);
        SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION(STEP_CHECK_CPS_DEVIATION_93_75_PCENT, l_s_path_ctrl_reg);
    }

    FAPI_INF("MPIPL: Clearing TOD_S_PATH_CTRL_REG");
    FAPI_TRY(PUT_TOD_S_PATH_CTRL_REG(l_target, l_s_path_ctrl_reg),
             "Error in clearing TOD_S_PATH_CTRL_REG");

    for(auto l_child = (i_tod_node->i_children).begin();
        l_child != (i_tod_node->i_children).end();
        ++l_child)
    {
        FAPI_TRY(mpipl_clear_tod_node(*l_child,
                                      i_tod_sel),
                 "Failure clearing downstream TOD node!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Specific steps to clear the previous topology.
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to clear
/// @return FAPI2_RC_SUCCESS if TOD topology is successfully cleared, else error
fapi2::ReturnCode clear_tod_node(
    const tod_topology_node* i_tod_node,
    const p10_tod_setup_tod_sel i_tod_sel)
{
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);

    FAPI_DBG("Start");

    fapi2::toString(l_target,
                    l_targetStr,
                    fapi2::MAX_ECMD_STRING_LEN);
    FAPI_INF("Clearing previous %s topology from %s",
             (i_tod_sel == TOD_PRIMARY) ? "Primary" : "Secondary", l_targetStr);

    if (i_tod_sel == TOD_PRIMARY)
    {
        FAPI_DBG("TOD_PRI_PORT_0_CTRL_REG and TOD_SEC_PORT_0_CTRL_REG will be cleared.");

        FAPI_TRY(PREP_TOD_PRI_PORT_0_CTRL_REG(l_target));
        FAPI_TRY(PUT_TOD_PRI_PORT_0_CTRL_REG(l_target, 0x0ULL),
                 "Error from PUT_TOD_PRI_PORT_0_CTRL_REG");

        FAPI_TRY(PREP_TOD_SEC_PORT_0_CTRL_REG(l_target));
        FAPI_TRY(PUT_TOD_SEC_PORT_0_CTRL_REG(l_target, 0x0ULL),
                 "Error from PUT_TOD_SEC_PORT_0_CTRL_REG");
    }
    else // (i_tod_sel==TOD_SECONDARY)
    {
        FAPI_DBG("TOD_PRI_PORT_1_CTRL_REG and TOD_SEC_PORT_1_CTRL_REG will be cleared.");

        FAPI_TRY(PREP_TOD_PRI_PORT_1_CTRL_REG(l_target));
        FAPI_TRY(PUT_TOD_PRI_PORT_1_CTRL_REG(l_target, 0x0ULL),
                 "Error from PUT_TOD_PRI_PORT_1_CTRL_REG");

        FAPI_TRY(PREP_TOD_SEC_PORT_1_CTRL_REG(l_target));
        FAPI_TRY(PUT_TOD_SEC_PORT_1_CTRL_REG(l_target, 0x0ULL),
                 "Error from PUT_TOD_SEC_PORT_1_CTRL_REG");
    }

    if (IMPLEMENT_HW480746_WORKAROUND && i_tod_sel == TOD_PRIMARY)
    {
        // Workaround for HW480746: Init remote sync checker tolerance to maximum;
        // will be closed down by configure_tod_node (configure_s_path_ctrl_reg) later.
        FAPI_INF("Implementing workaround for defect HW480746");
        fapi2::buffer<uint64_t> l_s_path_ctrl_reg;
        FAPI_TRY(GET_TOD_S_PATH_CTRL_REG(l_target, l_s_path_ctrl_reg),
                 "Error in GET_TOD_S_PATH_CTRL_REG");
        SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR(STEP_CHECK_CPS_DEVIATION_FACTOR_8,
                l_s_path_ctrl_reg);
        SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION(STEP_CHECK_CPS_DEVIATION_93_75_PCENT, l_s_path_ctrl_reg);
        FAPI_TRY(PUT_TOD_S_PATH_CTRL_REG(l_target, l_s_path_ctrl_reg),
                 "Error in PUT_TOD_S_PATH_CTRL_REG");
    }

    // TOD is cleared for this node; if it has children, start clearing their registers
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(clear_tod_node(*l_child,
                                i_tod_sel),
                 "Failure clearing downstream TOD node!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configures the fabric TOD registers; will be called by configure_tod_node
/// @param[in] i_tod_node       Reference to TOD topology (including FAPI targets)
/// @return FAPI2_RC_SUCCESS    If configuration is successful, else error.
fapi2::ReturnCode configure_fbc_tod_regs(
    const tod_topology_node* i_tod_node)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);
    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_iohs_target;
    uint8_t l_bus_num = 0;

    // Configure DL inbound settings
    FAPI_DBG("Configuring Fabric DL TOD inbound inits for RX ports");

    if((i_tod_node->i_bus_rx >= TOD_SETUP_BUS_IOHS0) && (i_tod_node->i_bus_rx <= TOD_SETUP_BUS_IOHS7))
    {
        FAPI_TRY(p10_tod_lookup_iohs_target(
                     l_target,
                     i_tod_node->i_bus_rx,
                     l_bus_num,
                     l_iohs_target),
                 "Error from p10_tod_lookup_iohs_target");

        FAPI_TRY(fbc_dl_tod_config_inbound(l_iohs_target),
                 "Error from fbc_dl_tod_config_inbound");
    }

    // Configure DL outbound settings
    FAPI_DBG("Configuring Fabric DL TOD outbound inits for TX ports");

    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        if(((*l_child)->i_bus_tx >= TOD_SETUP_BUS_IOHS0) && ((*l_child)->i_bus_tx <= TOD_SETUP_BUS_IOHS7))
        {
            FAPI_TRY(p10_tod_lookup_iohs_target(
                         l_target,
                         (*l_child)->i_bus_tx,
                         l_bus_num,
                         l_iohs_target),
                     "Error from p10_tod_lookup_iohs_target");

            FAPI_TRY(fbc_dl_tod_config_outbound(l_iohs_target, l_bus_num),
                     "Error from fbc_dl_tod_config_outbound");
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configures the PSS_MSS_CTRL_REG; will be called by configure_tod_node
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI2_RC_SUCCESS if the PSS_MSS_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_pss_mss_ctrl_reg(
    const tod_topology_node* i_tod_node,
    const p10_tod_setup_tod_sel i_tod_sel,
    const p10_tod_setup_osc_sel i_osc_sel)
{
    fapi2::buffer<uint64_t> l_pss_mss_ctrl_reg = 0;
    const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);

    FAPI_DBG("Start");

    // Read TOD_PSS_MSS_CTRL_REG in order to preserve any prior configuration
    FAPI_TRY(GET_TOD_PSS_MSS_CTRL_REG(l_target, l_pss_mss_ctrl_reg),
             "Error from GET_TOD_PSS_MSS_CTRL_REG");

    FAPI_DBG("Set Master TOD/Slave TOD and Master Drawer/Slave Drawer");

    if (i_tod_sel == TOD_PRIMARY)
    {
        if (is_mdmt)
        {
            SET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT(l_pss_mss_ctrl_reg);

            if (i_osc_sel == TOD_OSC_0             ||
                i_osc_sel == TOD_OSC_0_AND_1       ||
                i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
            {
                CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT(l_pss_mss_ctrl_reg);
            }
            else if (i_osc_sel == TOD_OSC_1        ||
                     i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
            {
                SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT(l_pss_mss_ctrl_reg);
            }

            FAPI_ASSERT(i_osc_sel != TOD_OSC_NONE,
                        fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY()
                        .set_TARGET(l_target)
                        .set_OSCSEL(i_osc_sel)
                        .set_TODSEL(i_tod_sel),
                        "Invalid oscillator configuration!");
        }
        else // Slave nodes (Drawer master is still a slave)
        {
            CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT(l_pss_mss_ctrl_reg);
        }

        if (i_tod_node->i_drawer_master)
        {
            SET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT(l_pss_mss_ctrl_reg);
        }
    }
    else // (i_tod_sel==TOD_SECONDARY)
    {
        if (is_mdmt)
        {
            SET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT(l_pss_mss_ctrl_reg);

            if (i_osc_sel == TOD_OSC_1       ||
                i_osc_sel == TOD_OSC_0_AND_1 ||
                i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
            {
                SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT(l_pss_mss_ctrl_reg); // SW440224
                SET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT(l_pss_mss_ctrl_reg);
            }
            else if (i_osc_sel == TOD_OSC_0  ||
                     i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
            {
                CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT(l_pss_mss_ctrl_reg); // SW440224
                CLEAR_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT(l_pss_mss_ctrl_reg);
            }

            FAPI_ASSERT(i_osc_sel != TOD_OSC_NONE,
                        fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY()
                        .set_TARGET(l_target)
                        .set_OSCSEL(i_osc_sel)
                        .set_TODSEL(i_tod_sel),
                        "Invalid oscillator configuration!");
        }
        else // Slave nodes (Drawer master is still a slave)
        {
            CLEAR_TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT(l_pss_mss_ctrl_reg);
        }

        if (i_tod_node->i_drawer_master)
        {
            SET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT(l_pss_mss_ctrl_reg);
        }
    }

    FAPI_TRY(PUT_TOD_PSS_MSS_CTRL_REG(l_target, l_pss_mss_ctrl_reg),
             "Error from PUT_TOD_PSS_MSS_CTRL_REG");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configures the S_PATH_CTRL_REG; will be called by configure_tod_node
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @return FAPI2_RC_SUCCESS if the S_PATH_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_s_path_ctrl_reg(
    const tod_topology_node* i_tod_node,
    const p10_tod_setup_tod_sel i_tod_sel)
{
    fapi2::buffer<uint64_t> l_s_path_ctrl_reg = 0;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);

    FAPI_DBG("Start");

    // Read TOD_S_PATH_CTRL_REG in order to preserve any prior configuration
    FAPI_TRY(GET_TOD_S_PATH_CTRL_REG(l_target, l_s_path_ctrl_reg),
             "Error from GET_TOD_S_PATH_CTRL_REG");

    // Slave TODs are enabled on all but the MDMT
    FAPI_DBG("Selection of Slave OSC path");

    if (i_tod_sel == TOD_PRIMARY)
    {
        // For primary slave, use slave path 0 (path_0_sel=OFF)
        CLEAR_TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT(l_s_path_ctrl_reg);

        // Set CPS deviation to 75% (CPS deviation bits = 0xC, factor=1),
        // 8 valid steps to enable step check
        SET_TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR(STEP_CHECK_CPS_DEVIATION_FACTOR_1, l_s_path_ctrl_reg);
        SET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION(STEP_CHECK_CPS_DEVIATION_75_00_PCENT, l_s_path_ctrl_reg);
        SET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT(STEP_CHECK_VALIDITY_COUNT_8, l_s_path_ctrl_reg);
        SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION(STEP_CHECK_CPS_DEVIATION_75_00_PCENT, l_s_path_ctrl_reg);
        SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR(STEP_CHECK_CPS_DEVIATION_FACTOR_1,
                l_s_path_ctrl_reg);
    }
    else // (i_tod_sel==TOD_SECONDARY)
    {
        // For secondary slave, use slave path 1 (path_1_sel=ON)
        SET_TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT(l_s_path_ctrl_reg);

        // Set CPS deviation to 75% (CPS deviation bits = 0xC, factor=1),
        // 8 valid steps to enable step check
        SET_TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR(STEP_CHECK_CPS_DEVIATION_FACTOR_1, l_s_path_ctrl_reg);
        SET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION(STEP_CHECK_CPS_DEVIATION_75_00_PCENT, l_s_path_ctrl_reg);
        SET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT(STEP_CHECK_VALIDITY_COUNT_8, l_s_path_ctrl_reg);
    }

    // In either case set the S_PATH_REMOTE_SYNC_MISS_COUNT_MAX
    SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX(TOD_S_PATH_CTRL_REG_REMOTE_SYNC_MISS_COUNT_2,
            l_s_path_ctrl_reg);

    FAPI_TRY(PUT_TOD_S_PATH_CTRL_REG(l_target, l_s_path_ctrl_reg),
             "Error from PUT_TOD_S_PATH_CTRL_REG");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configures the PORT_CTRL_REG; will be called by configure_tod_node
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI2_RC_SUCCESS if the PORT_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_port_ctrl_regs(
    const tod_topology_node* i_tod_node,
    const p10_tod_setup_tod_sel i_tod_sel,
    const p10_tod_setup_osc_sel i_osc_sel)
{
    fapi2::buffer<uint64_t> l_port_ctrl_reg = 0;
    uint32_t l_port_ctrl_addr = 0;
    fapi2::buffer<uint64_t> l_port_ctrl_check_reg = 0;
    uint32_t l_port_ctrl_check_addr = 0;
    uint32_t l_path_sel = 0;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);

    FAPI_DBG("Start");

    const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);

    // TOD_PRI_PORT_0_CTRL_REG is only used for Primary configurations
    // TOD_SEC_PORT_1_CTRL_REG is only used for Secondary configurations
    // In order to check primary and secondary networks are working
    // simultaneously...
    //  - The result of TOD_PRI_PORT_0_CTRL_REG are also inserted into
    //    TOD_SEC_PORT_0_CTRL_REG (preserving i_path_delay which can be
    //    different between 40001 and 40003)
    //  - The result of TOD_SEC_PORT_1_CTRL_REG are also inserted into
    //    TOD_PRI_PORT_1_CTRL_REG
    if (i_tod_sel == TOD_PRIMARY)
    {
        FAPI_DBG("TOD_PRI_PORT_0_CTRL_REG will be configured for primary topology");
        l_port_ctrl_addr = TOD_PRI_PORT_0_CTRL_REG;
        l_port_ctrl_check_addr = TOD_SEC_PORT_0_CTRL_REG;
    }
    else // (i_tod_sel==TOD_SECONDARY)
    {
        FAPI_DBG("TOD_SEC_PORT_1_CTRL_REG will be configured for secondary topology");
        l_port_ctrl_addr = TOD_SEC_PORT_1_CTRL_REG;
        l_port_ctrl_check_addr = TOD_PRI_PORT_1_CTRL_REG;
    }

    // Read port_ctrl_reg in order to preserve any prior configuration
    FAPI_TRY(fapi2::getScom(l_target,
                            l_port_ctrl_addr,
                            l_port_ctrl_reg),
             "Error from getScom (0x%08X)!", l_port_ctrl_addr);

    // Read port_ctrl_check_reg in order to preserve any prior configuration
    FAPI_TRY(fapi2::getScom(l_target,
                            l_port_ctrl_check_addr,
                            l_port_ctrl_check_reg),
             "Error from getScom (0x%08X)!", l_port_ctrl_check_addr);

    //Determine RX port if IOHS bus is selected for setup; MDMT has no rx
    if((i_tod_node->i_bus_rx >= TOD_SETUP_BUS_IOHS0) && (i_tod_node->i_bus_rx <= TOD_SETUP_BUS_IOHS7))
    {
        uint8_t l_bus_rx = 0;
        fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_iohs_target;
        fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;

        FAPI_TRY(p10_tod_lookup_iohs_target(
                     l_target,
                     i_tod_node->i_bus_rx,
                     l_bus_rx,
                     l_iohs_target),
                 "Error from p10_tod_lookup_iohs_target");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs_target, l_link_train),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");

        FAPI_ASSERT(l_link_train != fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_NONE,
                    fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY_RX()
                    .set_TARGET(l_target)
                    .set_RX(i_tod_node->i_bus_rx),
                    "i_tod_node->i_bus_rx is set to TOD_SETUP_BUS_IOHS%d and it is not enabled", l_bus_rx);

        l_port_ctrl_reg.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT,
                                        TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT_LEN>(l_bus_rx);
        l_port_ctrl_check_reg.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT,
                                              TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT_LEN>(l_bus_rx);
    }

    //Determine which tx path should be selected for all children
    if (is_mdmt)
    {
        if (i_tod_sel == TOD_PRIMARY)
        {
            if (i_osc_sel == TOD_OSC_0       ||
                i_osc_sel == TOD_OSC_0_AND_1 ||
                i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
            {
                l_path_sel = TOD_PORT_CTRL_REG_M_PATH_0;
            }
            else if (i_osc_sel == TOD_OSC_1  ||
                     i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
            {
                l_path_sel = TOD_PORT_CTRL_REG_M_PATH_1;
            }

            FAPI_ASSERT(i_osc_sel != TOD_OSC_NONE,
                        fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY()
                        .set_TARGET(l_target)
                        .set_OSCSEL(i_osc_sel)
                        .set_TODSEL(i_tod_sel),
                        "Invalid oscillator configuration!");
        }
        else // i_tod_sel==TOD_SECONDARY
        {
            if (i_osc_sel == TOD_OSC_1       ||
                i_osc_sel == TOD_OSC_0_AND_1 ||
                i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
            {
                l_path_sel = TOD_PORT_CTRL_REG_M_PATH_1;
            }
            else if (i_osc_sel == TOD_OSC_0  ||
                     i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
            {
                l_path_sel = TOD_PORT_CTRL_REG_M_PATH_0;
            }

            FAPI_ASSERT(i_osc_sel != TOD_OSC_NONE,
                        fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY()
                        .set_TARGET(l_target)
                        .set_OSCSEL(i_osc_sel)
                        .set_TODSEL(i_tod_sel),
                        "Invalid oscillator configuration!");
        }
    }
    else // Chip is not master; slave path selected
    {
        if (i_tod_sel == TOD_PRIMARY)
        {
            l_path_sel = TOD_PORT_CTRL_REG_S_PATH_0;
        }
        else // (i_tod_sel==TOD_SECONDARY)
        {
            l_path_sel = TOD_PORT_CTRL_REG_S_PATH_1;
        }
    }

    // Loop through all of the out busses, determine which tx buses to enable as senders
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        if(((*l_child)->i_bus_tx >= TOD_SETUP_BUS_IOHS0) && ((*l_child)->i_bus_tx <= TOD_SETUP_BUS_IOHS7))
        {
            uint8_t l_bus_tx = 0;
            fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_iohs_target;
            fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;

            FAPI_TRY(p10_tod_lookup_iohs_target(
                         l_target,
                         (*l_child)->i_bus_tx,
                         l_bus_tx,
                         l_iohs_target),
                     "Error from p10_tod_lookup_iohs_target");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs_target, l_link_train),
                     "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");

            FAPI_ASSERT(l_link_train != fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_NONE,
                        fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY_TX()
                        .set_TARGET(l_target)
                        .set_TX((*l_child)->i_bus_tx),
                        "l_child->i_bus_tx is set to TOD_SETUP_BUS_IOHS%d and it is not enabled", l_bus_tx);

            l_port_ctrl_reg.insertFromRight(l_path_sel, TOD_PORT_CTRL_REG_TX_X0_SEL + (TOD_PORT_CTRL_REG_TX_LEN * l_bus_tx),
                                            TOD_PORT_CTRL_REG_TX_LEN);
            l_port_ctrl_reg.setBit(TOD_PORT_CTRL_REG_TX_X0_EN + l_bus_tx);
            l_port_ctrl_check_reg.insertFromRight(l_path_sel, TOD_PORT_CTRL_REG_TX_X0_SEL + (TOD_PORT_CTRL_REG_TX_LEN * l_bus_tx),
                                                  TOD_PORT_CTRL_REG_TX_LEN);
            l_port_ctrl_check_reg.setBit(TOD_PORT_CTRL_REG_TX_X0_EN + l_bus_tx);
        }
        else
        {
            // all children should have a tx bus to enable, throw an error
            FAPI_ASSERT(false,
                        fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY_TX()
                        .set_TARGET(l_target)
                        .set_TX(TOD_SETUP_BUS_NONE),
                        "l_child->i_bus_tx is set to TOD_SETUP_BUS_NONE");
        }
    }

    // All children have been configured; save both port configurations!
    FAPI_TRY(fapi2::putScom(l_target,
                            l_port_ctrl_addr,
                            l_port_ctrl_reg),
             "Error from putScom (0x%08X)!", l_port_ctrl_addr);

    FAPI_TRY(fapi2::putScom(l_target,
                            l_port_ctrl_check_addr,
                            l_port_ctrl_check_reg),
             "Error from putScom (0x%08X)!", l_port_ctrl_check_addr);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief Configures the MDMT-related bit fields in the M_PATH_CTRL_REG register; called
///    only for the MDMT.
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @param[in,out] io_m_path_ctrl_reg  Reference to existing register value to operate on
/// @return FAPI2_RC_SUCCESS if the M_PATH_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_m_path_ctrl_reg_mdmt(
    const p10_tod_setup_osc_sel i_osc_sel,
    fapi2::buffer<uint64_t>& io_m_path_ctrl_reg)
{
    FAPI_DBG("Start");
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    if (i_osc_sel == TOD_OSC_0             ||
        i_osc_sel == TOD_OSC_0_AND_1       ||
        i_osc_sel == TOD_OSC_0_AND_1_SEL_0 ||
        i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
    {
        FAPI_DBG("OSC0 is valid; master path-0 will be configured.");

        // OSC0 is connected
        CLEAR_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID(io_m_path_ctrl_reg);

        // OSC0 step alignment enabled
        CLEAR_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE(io_m_path_ctrl_reg);

        // Set step check CPS deviation to 50%
        SET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION(STEP_CHECK_CPS_DEVIATION_50_00_PCENT, io_m_path_ctrl_reg);

        // 8 valid steps are required before step check is enabled
        SET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT(STEP_CHECK_VALIDITY_COUNT_8, io_m_path_ctrl_reg);
    }
    else
    {
        FAPI_DBG("OSC0 is not connected.");

        // OSC0 is not connected; any previous path-0 settings will be ignored
        SET_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID(io_m_path_ctrl_reg);
    }

    if (i_osc_sel == TOD_OSC_1             ||
        i_osc_sel == TOD_OSC_0_AND_1       ||
        i_osc_sel == TOD_OSC_0_AND_1_SEL_0 ||
        i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
    {
        FAPI_DBG("OSC1 is valid; master path-1 will be configured.");

        // OSC1 is connected
        CLEAR_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID(io_m_path_ctrl_reg);

        // OSC1 step alignment enabled
        CLEAR_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE(io_m_path_ctrl_reg);

        // Set step check CPS deviation to 50%
        SET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION(STEP_CHECK_CPS_DEVIATION_50_00_PCENT, io_m_path_ctrl_reg);

        // 8 valid steps are required before step check is enabled
        SET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT(STEP_CHECK_VALIDITY_COUNT_8, io_m_path_ctrl_reg);
    }
    else
    {
        FAPI_DBG("OSC1 is not connected.");

        // OSC1 is not connected; any previous path-1 settings will be ignored
        SET_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID(io_m_path_ctrl_reg);
    }

    // CPS deviation factor configures both path-0 and path-1
    SET_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR(STEP_CHECK_CPS_DEVIATION_FACTOR_1, io_m_path_ctrl_reg);

    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief Configures the M_PATH_CTRL_REG register for all nodes.  The DUAL_EDGE_DISABLE
///    bit needs to be configured for all nodes (master and slave); all other fields are
///    configured only for the MDMT node.
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @param[in] i_mdmt  Set true if the MDMT is being configured, false otherwise
/// @return FAPI2_RC_SUCCESS if the M_PATH_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_m_path_ctrl_reg(
    const tod_topology_node* i_tod_node,
    const p10_tod_setup_osc_sel i_osc_sel,
    const bool i_mdmt,
    const bool i_dual_edge_disable)
{
    fapi2::buffer<uint64_t> l_m_path_ctrl_reg = 0;
    fapi2::buffer<uint64_t> l_reset_reg = 0;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);

    FAPI_DBG("Start");

    // Configure Master Path Control Register
    FAPI_DBG("Configuring TOD_M_PATH_CTRL_REG");

    // Read TOD_M_PATH_CTRL_REG to preserve any prior configuration
    FAPI_TRY(GET_TOD_M_PATH_CTRL_REG(l_target, l_m_path_ctrl_reg),
             "Error from GET_TOD_M_PATH_CTRL_REG");

    // Disable clock doubling when running off LPC clock, otherwise enable it.
    if (i_dual_edge_disable)
    {
        // ON: sample only the rising edge of the oscillator
        SET_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE(l_m_path_ctrl_reg);

        // In single-edge mode the TOD expects a 16 MHz oscillator, and since all SPS values are specified in
        // terms of us instead of steps, the HW actually changes how it interprets the SPS values: Every setting
        // suddenly means half as many STEPs as before. Since we're staying at 32 MHz and want the same STEPs
        // per SYNC we have to adapt our SPS values to the next higher power of two.
        SET_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT(TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_1024, l_m_path_ctrl_reg);
    }
    else
    {
        // OFF: sample both edges of the oscillator
        CLEAR_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE(l_m_path_ctrl_reg);
        SET_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT(TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_512, l_m_path_ctrl_reg);
    }

    if (i_mdmt)
    {
        // Configure those bit fields only relevant for the MDMT
        FAPI_TRY(configure_m_path_ctrl_reg_mdmt(i_osc_sel,
                                                l_m_path_ctrl_reg),
                 "Error from configure_m_path_ctrl_reg_mdmt!");
    }

    FAPI_TRY(PUT_TOD_M_PATH_CTRL_REG(l_target, l_m_path_ctrl_reg),
             "Error from PUT_TOD_M_PATH_CTRL_REG");

    if (i_mdmt)
    {
        // When changing DUAL_EDGE_DISABLE, the Master sync counter can exceed the SPS limit and
        // take a long time to roll over.  So reset the Master sync counter and everything related
        // in the Master after changing DUAL_EDGE_DISABLE.
        FAPI_TRY(PREP_TOD_MISC_RESET_REG(l_target));
        SET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(l_reset_reg);
        SET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(l_reset_reg);

        SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(l_reset_reg);
        SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(l_reset_reg);
        SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(l_reset_reg);
        SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(l_reset_reg);

        FAPI_TRY(PUT_TOD_MISC_RESET_REG(l_target, l_reset_reg));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configures the I_PATH_CTRL_REG; will be called by configure_tod_node
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @return FAPI2_RC_SUCCESS if the I_PATH_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_i_path_ctrl_reg(
    const tod_topology_node* i_tod_node,
    const p10_tod_setup_tod_sel i_tod_sel)
{
    fapi2::buffer<uint64_t> l_i_path_ctrl_reg = 0;
    fapi2::buffer<uint64_t> l_port_ctrl_reg = 0;
    uint32_t l_port_ctrl_addr = 0;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);

    FAPI_DBG("Setting internal path delay");

    // This is the number of TOD-grid-cycles to delay the internal path
    // (0-0xFF valid); 1 TOD-grid-cycle = 400ps (default)
    if (i_tod_sel == TOD_PRIMARY)
    {
        // Primary topology internal path delay set TOD_PRI_PORT_0_CTRL_REG
        // regardless of master/slave/port
        FAPI_DBG("TOD_PRI_PORT_0_CTRL_REG will be used to set internal delay");
        l_port_ctrl_addr = TOD_PRI_PORT_0_CTRL_REG;
    }
    else // (i_tod_sel==TOD_SECONDARY)
    {
        // Secondary topology internal path delay set TOD_SEC_PORT_0_CTRL_REG
        // regardless of master/slave/port
        FAPI_DBG("TOD_SEC_PORT_0_CTRL_REG will be used to set internal delay");
        l_port_ctrl_addr = TOD_SEC_PORT_0_CTRL_REG;
    }

    FAPI_TRY(fapi2::getScom(l_target,
                            l_port_ctrl_addr,
                            l_port_ctrl_reg),
             "Error from getScom (0x%08X)!", l_port_ctrl_addr);

    FAPI_DBG("configuring an internal delay of %d TOD-grid-cycles",
             i_tod_node->o_int_path_delay);
    l_port_ctrl_reg.insertFromRight<TOD_PORT_CTRL_REG_I_PATH_DELAY,
                                    TOD_PORT_CTRL_REG_I_PATH_DELAY_LEN>(i_tod_node->o_int_path_delay);

    FAPI_TRY(fapi2::putScom(l_target,
                            l_port_ctrl_addr,
                            l_port_ctrl_reg),
             "Error from putScom (0x%08X)!", l_port_ctrl_addr);

    FAPI_DBG("Enable delay logic in TOD_I_PATH_CTRL_REG");
    // Read TOD_I_PATH_CTRL_REG in order to preserve prior configuration
    FAPI_TRY(GET_TOD_I_PATH_CTRL_REG(l_target, l_i_path_ctrl_reg),
             "Error from GET_TOD_I_PATH_CTRL_REG");

    // Ensure delay is enabled
    CLEAR_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE(l_i_path_ctrl_reg);
    CLEAR_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE(l_i_path_ctrl_reg);

    // Deviation for internal OSC should be set to max, allowing backup master
    // TOD to run the active topology, when switching from Slave OSC path to
    // Master OSC path
    SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION(STEP_CHECK_CPS_DEVIATION_93_75_PCENT, l_i_path_ctrl_reg);
    SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR(STEP_CHECK_CPS_DEVIATION_FACTOR_1, l_i_path_ctrl_reg);
    SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT(STEP_CHECK_VALIDITY_COUNT_8, l_i_path_ctrl_reg);

    FAPI_TRY(PUT_TOD_I_PATH_CTRL_REG(l_target, l_i_path_ctrl_reg),
             "Error from PUT_TOD_I_PATH_CTRL_REG");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configures the TOD_CHIP_CTRL_REG; will be called by configure_tod_node
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @return FAPI2_RC_SUCCESS if the TOD_CHIP_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode init_chip_ctrl_reg(
    const tod_topology_node* i_tod_node,
    const bool i_dual_edge_disable)
{
    fapi2::buffer<uint64_t> l_chip_ctrl_reg = 0;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);

    FAPI_DBG("Start");

    // In single-edge mode the TOD expects a 16 MHz oscillator, and since all SPS values are specified in
    // terms of us instead of steps, the HW actually changes how it interprets the SPS values: Every setting
    // suddenly means half as many STEPs as before. Since we're staying at 32 MHz and want the same STEPs
    // per SYNC we have to adapt our SPS values to the next higher power of two.
    const uint32_t l_sps_value = i_dual_edge_disable ?
                                 TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_32 :
                                 TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_16;

    // Read TOD_CHIP_CTRL_REG in order to preserve prior configuration
    FAPI_TRY(GET_TOD_CHIP_CTRL_REG(l_target, l_chip_ctrl_reg),
             "Error from GET_TOD_CHIP_CTRL_REG");

    // Default core sync period is 16us
    SET_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT(l_sps_value, l_chip_ctrl_reg);

    // Enable internal path sync check
    CLEAR_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE(l_chip_ctrl_reg);

    // 1x sync boundaries for Move-TOD-To-Timebase
    CLEAR_TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE(l_chip_ctrl_reg);

    // Use eclipz sync mechanism
    CLEAR_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM(l_chip_ctrl_reg);

    // Use timebase step sync from internal path
    CLEAR_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC(l_chip_ctrl_reg);

    // Chip TOD WOF incrementer ratio (eclipz mode)
    // 4-bit WOF counter is incremented with each 200MHz clock cycle
    SET_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE(TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_3F, l_chip_ctrl_reg);

    // Stop TOD when system checkstop occurs
    CLEAR_TOD_CHIP_CTRL_REG_XSTOP_GATE(l_chip_ctrl_reg);

    FAPI_TRY(PUT_TOD_CHIP_CTRL_REG(l_target, l_chip_ctrl_reg),
             "Error from PUT_TOD_CHIP_CTRL_REG");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configure the tod topology -- set up the oscilator select and the
///        primary or secondary tod
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI2_RC_SUCCESS if TOD topology is successfully configured
///         else error
fapi2::ReturnCode configure_tod_node(
    const tod_topology_node* i_tod_node,
    const p10_tod_setup_tod_sel i_tod_sel,
    const p10_tod_setup_osc_sel i_osc_sel)
{
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);
    fapi2::ATTR_CLOCK_PLL_MUX_TOD_Type l_attr_clock_pll_mux_tod;
    fapi2::toString(l_target,
                    l_targetStr,
                    fapi2::MAX_ECMD_STRING_LEN);
    FAPI_DBG("Start: Configuring %s", l_targetStr);

    bool dual_edge_disable = false;
    const bool is_mdmt = (i_tod_node->i_tod_master &&
                          i_tod_node->i_drawer_master);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_PLL_MUX_TOD, l_target, l_attr_clock_pll_mux_tod),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_PLL_MUX_TOD)");
    dual_edge_disable =
        l_attr_clock_pll_mux_tod == fapi2::ENUM_ATTR_CLOCK_PLL_MUX_TOD_LPC_REFCLOCK;

    FAPI_TRY(configure_fbc_tod_regs(i_tod_node),
             "Error from configure_fbc_tod_regs!");

    FAPI_TRY(configure_pss_mss_ctrl_reg(i_tod_node,
                                        i_tod_sel,
                                        i_osc_sel),
             "Error from configure_pss_mss_ctrl_reg!");

    if (!is_mdmt)
    {
        FAPI_TRY(configure_s_path_ctrl_reg(i_tod_node,
                                           i_tod_sel),
                 "Error from configure_s_path_ctrl_reg!");
    }

    FAPI_TRY(configure_port_ctrl_regs(i_tod_node,
                                      i_tod_sel,
                                      i_osc_sel),
             "Error from configure_port_ctrl_regs!");

    FAPI_TRY(configure_m_path_ctrl_reg(i_tod_node,
                                       i_osc_sel,
                                       is_mdmt,
                                       dual_edge_disable),
             "Error from configure_m_path_ctrl_reg!");

    FAPI_TRY(configure_i_path_ctrl_reg(i_tod_node,
                                       i_tod_sel),
             "Error from configure_i_path_ctrl_reg!");

    FAPI_TRY(init_chip_ctrl_reg(i_tod_node,
                                dual_edge_disable),
             "Error from init_chip_ctrl_reg!");

    // TOD is configured for this node; if it has children, start their
    // configuration
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(configure_tod_node(*l_child,
                                    i_tod_sel,
                                    i_osc_sel),
                 "Failure configuring downstream node!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Displays the TOD topology
/// @param[in] i_tod_node Reference to TOD topology
/// @param[in] i_depth Current depth into TOD topology network
/// @return void
void display_tod_nodes(
    const tod_topology_node* i_tod_node,
    const uint32_t i_depth)
{
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    uint8_t l_bus_rx; //, l_bus_tx;
    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_iohs_target_rx, l_iohs_target_tx;
    fapi2::ReturnCode l_rc;

    if (i_tod_node == NULL || i_tod_node->i_target == NULL)
    {
        FAPI_INF("NULL tod_node or target parameter!");
        goto fapi_try_exit;
    }

    fapi2::toString(i_tod_node->i_target,
                    l_targetStr,
                    fapi2::MAX_ECMD_STRING_LEN);
    FAPI_INF("%s",
             l_targetStr);
    FAPI_INF("  Parent = %p", i_tod_node->i_parent);
    FAPI_INF("  Master = %d",
             i_tod_node->i_tod_master);
    FAPI_INF("  Drawer master = %d",
             i_tod_node->i_drawer_master);

    if (i_tod_node->i_tod_master == 0)
    {
        // RX
        l_rc = p10_tod_lookup_iohs_target(*(i_tod_node->i_target),
                                          i_tod_node->i_bus_rx,
                                          l_bus_rx,
                                          l_iohs_target_rx);

        if (l_rc == fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::toString(l_iohs_target_rx,
                            l_targetStr,
                            fapi2::MAX_ECMD_STRING_LEN);

            FAPI_INF("  Bus RX = %d->%d (%s)",
                     i_tod_node->i_bus_rx, l_bus_rx, l_targetStr);
        }
        else
        {
            FAPI_INF("  Bus RX = %d (?)",
                     i_tod_node->i_bus_rx);
        }

        // TX
//        l_rc = p10_tod_lookup_iohs_target(*(i_tod_node->i_parent->i_target),
//                                          i_tod_node->i_bus_tx,
//                                          l_bus_tx,
//                                          l_iohs_target_tx);
//        if (l_rc == fapi2::FAPI2_RC_SUCCESS)
//        {
//            fapi2::toString(l_iohs_target_tx,
//                            l_targetStr,
//                            fapi2::MAX_ECMD_STRING_LEN);
//
//            FAPI_INF("  Bus TX = %d (%s)",
//                     l_bus_tx, l_targetStr);
//        }
//        else
//        {
        FAPI_INF("  Bus TX = %d (?)",
                 i_tod_node->i_bus_tx);
//        }
    }

    FAPI_INF("  Depth = %d",
             i_depth);
    FAPI_INF("  Delay = %d",
             i_tod_node->o_int_path_delay);

    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        display_tod_nodes(*l_child, i_depth + 1);
    }

fapi_try_exit:
    return;
}


/// @brief Returns the latency and round-trip values from the FBC-TOD Latency measure register
/// @param[in] i_iolink_targets => IOLINK targets to measure
/// @param[in] i_iohs_target  => IOHS target
/// @param[out] o_iohs_latency => Latency in IOHS clocks from the FBC-TOD Latency measure register
/// @param[out] o_iohs_round_trip_clocks => IOHS round-trip clocks from the FBC-TOD Latency measure register
/// @return FAPI2_RC_SUCCESS if successfully returned the values from the Latency measure register
///         else error
fapi2::ReturnCode p10_tod_get_iohs_latency_measures(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOLINK>>& i_iolink_targets,
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    iohs_latency_t& o_iohs_latency,
    iohs_latency_t& o_iohs_round_trip_clocks)
{
    fapi2::buffer<uint64_t> l_lat_measure_reg;
    iohs_latency_t l_iohs_local_latency_diff = 0 ;
    iohs_latency_t l_iohs_latency_link0 = 0 ;
    iohs_latency_t l_iohs_latency_link1 = 0 ;

    bool l_paired = true;
    bool l_link0_only = false;
    bool l_link1_only = false;

    if (i_iolink_targets.size() == 1)
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_pos;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iolink_targets.front(), l_unit_pos));

        l_paired = false;
        l_link0_only = ((l_unit_pos % 2) == 0) ? (true) : (false);
        l_link1_only = ((l_unit_pos % 2) == 0) ? (false) : (true);
    }

    FAPI_DBG("Start");

    // Initialize
    o_iohs_latency = 0;
    o_iohs_round_trip_clocks = 0;

    // Get the latency measure register
    FAPI_TRY(GET_DLP_LAT_MEASURE(i_iohs_target, l_lat_measure_reg),
             "Error from GET_DLP_LAT_MEASURE");

    // From the P10 FBC Workbook:
    // ---------------------------
    // "The latency of a TOD edge from the link layer input on one chip
    // to the link layer output on the other chip is determined from
    // the latency measure register values on the chip sending the
    // TOD pulse. The total latency in optic clock cycles is the
    // TOD Latency value (from the latency measure register) plus
    // half the round-trip time plus 5 cycles.
    //
    // For a link pair, the TOD Latency value is the smaller of
    // the two link's registers, and only one of the links has a
    // non-zero value in the round-trip time register.
    //
    // If the local and remote latency longer link bits (in the
    // latency measure register) are different for a link pair,
    // the local latency difference value should be added to the
    // round trip time register value to get the total round trip time."

    // ------------
    // determine TOD latency value
    // ------------

    if (l_paired)
    {
        GET_DLP_LAT_MEASURE_LINK0_TOD_LATENCY(l_lat_measure_reg, l_iohs_latency_link0);
        GET_DLP_LAT_MEASURE_LINK1_TOD_LATENCY(l_lat_measure_reg, l_iohs_latency_link1);
        o_iohs_latency = (l_iohs_latency_link0 < l_iohs_latency_link1) ? l_iohs_latency_link0 : l_iohs_latency_link1;
    }
    else if (l_link0_only)
    {
        GET_DLP_LAT_MEASURE_LINK0_TOD_LATENCY(l_lat_measure_reg, o_iohs_latency);
    }
    else
    {
        GET_DLP_LAT_MEASURE_LINK1_TOD_LATENCY(l_lat_measure_reg, o_iohs_latency);
    }

    // ------------
    // determine round-trip clocks
    // ------------
    if(l_link0_only)
    {
        GET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP(l_lat_measure_reg, o_iohs_round_trip_clocks);

        FAPI_ASSERT(GET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(l_lat_measure_reg)
                    && o_iohs_round_trip_clocks != 0,
                    fapi2::P10_TOD_SETUP_INVALID_LATENCY()
                    .set_TARGET(i_iohs_target)
                    .set_IOHS_LATENCY(o_iohs_latency)
                    .set_ROUND_TRIP_TIME(o_iohs_round_trip_clocks)
                    .set_LATENCY_MEASURE(l_lat_measure_reg),
                    "Invalid latency measure register value (EO)");

        FAPI_DBG("Latency measure values : o_iohs_latency = %u o_iohs_round_trip_clocks = %u",
                 o_iohs_latency, o_iohs_round_trip_clocks);

        goto fapi_try_exit;
    }

    if(l_link1_only)
    {
        GET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP(l_lat_measure_reg, o_iohs_round_trip_clocks);

        FAPI_ASSERT(GET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(l_lat_measure_reg)
                    && o_iohs_round_trip_clocks != 0,
                    fapi2::P10_TOD_SETUP_INVALID_LATENCY()
                    .set_TARGET(i_iohs_target)
                    .set_IOHS_LATENCY(o_iohs_latency)
                    .set_ROUND_TRIP_TIME(o_iohs_round_trip_clocks)
                    .set_LATENCY_MEASURE(l_lat_measure_reg),
                    "Invalid latency measure register value (OO)");

        FAPI_DBG("Latency measure values : o_iohs_latency = %u o_iohs_round_trip_clocks = %u",
                 o_iohs_latency, o_iohs_round_trip_clocks);

        goto fapi_try_exit;
    }

    // paired here on down:
    if (GET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(l_lat_measure_reg))
    {
        GET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP(l_lat_measure_reg, o_iohs_round_trip_clocks);
    }
    else if (GET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(l_lat_measure_reg))
    {
        GET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP(l_lat_measure_reg, o_iohs_round_trip_clocks);
    }

    FAPI_ASSERT(o_iohs_round_trip_clocks != 0,
                fapi2::P10_TOD_SETUP_INVALID_LATENCY()
                .set_TARGET(i_iohs_target)
                .set_IOHS_LATENCY(o_iohs_latency)
                .set_ROUND_TRIP_TIME(o_iohs_round_trip_clocks)
                .set_LATENCY_MEASURE(l_lat_measure_reg),
                "Invalid latency measure register value (zero)");

    if (GET_DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(l_lat_measure_reg) !=
        GET_DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(l_lat_measure_reg))
    {
        // Make sure valid bit is set before using latency difference
        FAPI_ASSERT(GET_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(l_lat_measure_reg),
                    fapi2::P10_TOD_SETUP_INVALID_LATENCY()
                    .set_TARGET(i_iohs_target)
                    .set_IOHS_LATENCY(o_iohs_latency)
                    .set_ROUND_TRIP_TIME(o_iohs_round_trip_clocks)
                    .set_LATENCY_MEASURE(l_lat_measure_reg),
                    "Invalid latency measure register value (diff valid)");

        // add the local latency difference value to total round trip time
        GET_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE(l_lat_measure_reg, l_iohs_local_latency_diff);
        o_iohs_round_trip_clocks += l_iohs_local_latency_diff;

        FAPI_DBG("Latency measure values : l_iohs_local_latency_diff = %u", l_iohs_local_latency_diff);
    }

    FAPI_DBG("Latency measure values: l_iohs_latency_link0 = %u l_iohs_latency_link1 = %u",
             l_iohs_latency_link0, l_iohs_latency_link1);

    FAPI_DBG("Latency measure values : o_iohs_latency = %u o_iohs_round_trip_clocks = %u",
             o_iohs_latency, o_iohs_round_trip_clocks);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;

}

/// @brief Convert the IOHS latency to TOD latency
/// @param[in] i_iohs_target  => IOHS target
/// @param[in] i_iohs_latency => IOHS latency in IOHS clocks
/// @param[out] o_tod_latency => TOD latency in TOD grid clocks
/// @return FAPI2_RC_SUCCESS if successfully returned the latency, else error
fapi2::ReturnCode p10_tod_convert_latency_iohs_to_tod(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const iohs_latency_t& i_iohs_latency,
    tod_latency_t& o_tod_latency)
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_FREQ_IOHS_MHZ_Type l_attr_freq_iohs_mhz;
    fapi2::ATTR_FREQ_PAU_MHZ_Type l_attr_freq_pau_mhz;

    FAPI_DBG("Start");

    // Get the frequency of this link.  Links can have different frequency settings
    // on the same chip.
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_IOHS_MHZ, i_iohs_target, l_attr_freq_iohs_mhz),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_IOHS_MHZ)");

    // This is the "TOD grid clock" (tpconst_gckn), which in turn should be driven
    // by the PAU DPLL.
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PAU_MHZ, FAPI_SYSTEM, l_attr_freq_pau_mhz),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_PAU_MHZ)");

    // Avoid division by zero and check that attributes are set
    FAPI_ASSERT(((l_attr_freq_iohs_mhz != 0) &&
                 (l_attr_freq_pau_mhz != 0)),
                fapi2::P10_TOD_SETUP_INVALID_CLOCK_ATTRIBUTES()
                .set_TARGET(i_iohs_target)
                .set_IOHS_CLOCK(l_attr_freq_iohs_mhz)
                .set_PAU_CLOCK(l_attr_freq_pau_mhz),
                "Invalid clock values");

    // convert IOHS latency to TOD latency using mathematical rounding
    o_tod_latency = ( ( i_iohs_latency * l_attr_freq_pau_mhz ) + l_attr_freq_iohs_mhz / 2 ) / l_attr_freq_iohs_mhz;

    FAPI_DBG("i_iohs_latency = %u o_tod_latency = %u", i_iohs_latency, o_tod_latency);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief Returns the FBC latency in terms of number of TOD grid clocks
/// @param[in] i_iolink_targets => Vector of IOLINK targets
/// @param[in] i_iohs_target => IOHS target
/// @param[out] o_fbc_latency => FBC Latency in terms of number of TOD grid clocks
/// @return FAPI2_RC_SUCCESS if successfully returned the FBC latency, else error
fapi2::ReturnCode p10_tod_get_fbc_latency(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOLINK>>& i_iolink_targets,
    fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    tod_latency_t& o_fbc_latency)
{
    iohs_latency_t l_iohs_tod_latency_measure = 0 ;
    iohs_latency_t l_iohs_round_trip_clocks = 0 ;
    tod_latency_t l_tod_latency_part = 0 ;

    FAPI_DBG("Start");

    // Get the FBC latency measures.  These are in terms of the IOHS clock
    FAPI_TRY(p10_tod_get_iohs_latency_measures(
                 i_iolink_targets,
                 i_iohs_target,
                 l_iohs_tod_latency_measure,
                 l_iohs_round_trip_clocks),
             "Error from p10_tod_get_iohs_latency_measures");

    // From the P10 FBC Workbook:
    // ---------------------------
    // The total latency in optic clock cycles is the TOD Latency value
    // (from the latency measure register) plus half the round-trip time
    // plus 5 cycles.

    // convert latency measure register value + 5 cycles to TOD grid clocks
    FAPI_TRY(p10_tod_convert_latency_iohs_to_tod(
                 i_iohs_target,
                 l_iohs_tod_latency_measure + P10_TOD_SETUP_LATENCY_FIXED_OPTIC_CYCLES,
                 l_tod_latency_part),
             "Error from p10_tod_convert_latency_iohs_to_tod");

    o_fbc_latency = l_tod_latency_part;

    // convert total round-trip latency to TOD grid clocks
    FAPI_TRY(p10_tod_convert_latency_iohs_to_tod(
                 i_iohs_target,
                 l_iohs_round_trip_clocks,
                 l_tod_latency_part),
             "Error from p10_tod_convert_latency_iohs_to_tod");

    // add in half the round-trip latency
    o_fbc_latency += ((l_tod_latency_part + 1) / 2);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;

}

/// @brief Determines the latency seen by the parent node transmiting Sync pulses to the
///     current node in TOD grid clock cycles.
/// @param[in] i_tod_node Reference to current TOD node
/// @param[out] o_tod_latency => Latency seen by parent sending Sync pulses to the child
///     in terms of TOD grid clock cycles.
/// @return FAPI2_RC_SUCCESS if successfully returned the FBC latency, else error
fapi2::ReturnCode p10_tod_get_tod_latency_from_parent(
    const tod_topology_node* i_tod_node,
    tod_latency_t& o_tod_latency)
{
    tod_topology_node* l_parent_tod_node;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_parent_target;
    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_parent_iohs_target;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOLINK>> l_parent_connected_iolink_targets;
    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_child_iohs_target;
    tod_latency_t l_fbc_latency = 0;
    uint8_t l_bus_num_unused = 0;

    FAPI_DBG("Start");

    // get parent node
    l_parent_tod_node = i_tod_node->i_parent;

    FAPI_ASSERT((l_parent_tod_node != NULL) &&
                (l_parent_tod_node->i_target != NULL),
                fapi2::P10_TOD_SETUP_NULL_NODE(),
                "Null node or target passed into function!");

    // get parent Chip target
    l_parent_target = *(l_parent_tod_node->i_target);

    // i_bus_tx is the upstream node's bus from which step/sync is transmitted
    // Lookup the IOHS target for the parent node.
    FAPI_TRY(p10_tod_lookup_iohs_target(
                 l_parent_target,
                 i_tod_node->i_bus_tx,
                 l_bus_num_unused,
                 l_parent_iohs_target),
             "Error from p10_tod_lookup_iohs_target (parent)");

    // i_bus_rx is the current node's bus from which step/sync is received
    // Lookup the IOHS target
    FAPI_TRY(p10_tod_lookup_iohs_target(
                 *(i_tod_node->i_target),
                 i_tod_node->i_bus_rx,
                 l_bus_num_unused,
                 l_child_iohs_target),
             "Error from p10_tod_lookup_iohs_target (child)");

    // Get the parent's FBC latency in terms of TOD grid clocks
    for (const auto l_parent_iolink_target : l_parent_iohs_target.getChildren<fapi2::TARGET_TYPE_IOLINK>())
    {
        fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_child_iolink_target;
        fapi2::ReturnCode l_rc = l_parent_iolink_target.getOtherEnd(l_child_iolink_target);

        if (l_rc == fapi2::FAPI2_RC_SUCCESS)
        {
            if (l_child_iolink_target.getParent<fapi2::TARGET_TYPE_IOHS>() ==
                l_child_iohs_target)
            {
                l_parent_connected_iolink_targets.push_back(l_parent_iolink_target);
            }
        }
    }

    FAPI_ASSERT(l_parent_connected_iolink_targets.size(),
                fapi2::P10_TOD_SETUP_IOLINK_TARGET_MATCH_ERR()
                .set_PARENT_IOHS(l_parent_iohs_target)
                .set_PARENT(l_parent_target)
                .set_CHILD(*(i_tod_node->i_target)),
                "No matching IOLINK targets found for IOHS target!");

    FAPI_TRY(p10_tod_get_fbc_latency(
                 l_parent_connected_iolink_targets,
                 l_parent_iohs_target,
                 l_fbc_latency),
             "Error from p10_tod_get_fbc_latency");

    // @RTC 213485 -- Add in the following Sync pulse latencies described
    //   in the P10 Pervasive Overview . pptx document
    //       1) TOD internal (Sync generation to SYNC output)
    //       2) On-chip distribution (includes synchronizers)
    o_tod_latency = l_fbc_latency + ((i_tod_node->i_children.size() > 0) ?
                                     P10_TOD_SETUP_SYNC_FORWARDING_LATENCY : P10_TOD_SETUP_SYNC_RECEIVE_LATENCY );

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;

}

/// @brief Calculates the delay for a node in TOD-grid-cycles.
///     Also saves the delay in the i_tod_node structure.
/// @param[in,out] i_tod_node Reference to TOD topology
/// @param[out] o_node_delay => Delay of a single node in TOD-grid-cycles
/// @return FAPI2_RC_SUCCESS if TOD node delay is successfully calculated else
///         error
fapi2::ReturnCode calculate_node_link_delay(
    tod_topology_node* i_tod_node,
    tod_latency_t& o_node_delay)
{
    tod_latency_t l_tod_latency = 0;

    FAPI_DBG("Start");

    // MDMT (master drawer, master TOD) is originator and therefore has no node delay
    if (i_tod_node->i_tod_master && i_tod_node->i_drawer_master)
    {
        o_node_delay = 0;
        goto fapi_try_exit;
    }

    // Get the FBC latency as seen by the parent to the current node.
    // The current node's TOD latency measurement is assigned the delay of what the parent node
    // sees transmitting Sync pulses to the current node.  This is based off the following
    // text in the P10 FBC workbook:
    //   "The latency of a TOD edge from the link layer input on one chip to the link layer
    //    output on the other chip is determined from the latency measure register values
    //    on the chip sending the TOD pulse."
    // In P9, the current node's TOD latency measurement was assigned based on the TL latency
    // in transmitting from the current node to the parent node.
    FAPI_TRY(p10_tod_get_tod_latency_from_parent(
                 i_tod_node,
                 l_tod_latency),
             "Error from p10_tod_get_tod_latency_from_parent");

    // total one-way latency calculation from the parent node to the current node.
    o_node_delay = l_tod_latency;

fapi_try_exit:
    // This is not the final internal path delay, only saved so two calls aren't needed to calculate_node_link_delay
    i_tod_node->o_int_path_delay = o_node_delay;

    FAPI_DBG("TOD-grid-cycles for single link: %u", o_node_delay);

    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Finds the longest delay in the topology tree (additionally sets each
///        node delay) from the current node
/// @param[in,out] i_tod_node Reference to current node in TOD topology
/// @param[in] i_parent_tod_node Reference to the parent node of the current node
/// @param[out] o_longest_delay Longest delay in TOD-grid-cycles
/// @return FAPI2_RC_SUCCESS if a longest TOD delay was found in topology
///         else error
fapi2::ReturnCode calculate_longest_topolopy_delay(
    tod_topology_node* i_tod_node,
    tod_topology_node* i_parent_tod_node,
    tod_latency_t& o_longest_delay)
{
    tod_latency_t l_node_delay = 0;
    tod_latency_t l_current_longest_delay = 0;

    FAPI_DBG("Start");

    // Fill in the parent relationship to the current node, NULL if no parent.
    i_tod_node->i_parent = i_parent_tod_node;

    // Calculate the delay of the current node
    FAPI_TRY(calculate_node_link_delay(i_tod_node,
                                       l_node_delay),
             "Error from calculate_node_link_delay!");

    o_longest_delay = l_node_delay;

    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        tod_topology_node* l_child_tod_node = *l_child;
        FAPI_TRY(calculate_longest_topolopy_delay(
                     l_child_tod_node,
                     i_tod_node,     // parent node of l_child_tod_node
                     l_node_delay),
                 "Error from calculate_longest_topology_delay!");

        if (l_node_delay > l_current_longest_delay)
        {
            l_current_longest_delay = l_node_delay;
        }
    }

    // Add the longest delay seen under the current node to the delay of the current node
    o_longest_delay += l_current_longest_delay;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Updates the topology struct with the final delay values
/// @param[in,out] i_tod_node Reference to the current node in the TOD topology tree
/// @param[in] i_longest_delay Longest delay in the topology from the MDMT
/// @return FAPI2_RC_SUCCESS if o_int_path_delay was set for every node in the
///         topology else error
fapi2::ReturnCode set_topology_delays(
    tod_topology_node* i_tod_node,
    const tod_latency_t i_longest_delay)
{
    FAPI_DBG("Start");
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);

    // Retrieve saved node_delay from calculate_node_link_delay instead of
    // making a second call.
    // o_int_path_delay now represents the internal delay configured in the current node
    // such that all nodes see the Sync pulses from the MDMT at around the same time.
    i_tod_node->o_int_path_delay = i_longest_delay -
                                   (i_tod_node->o_int_path_delay);

    // Verify the delay is between MIN_TOD_DELAY and MAX_TOD_DELAY inclusive.
    FAPI_ASSERT((i_tod_node->o_int_path_delay >= MIN_TOD_DELAY &&
                 i_tod_node->o_int_path_delay <= MAX_TOD_DELAY),
                fapi2::P10_TOD_SETUP_INVALID_NODE_DELAY()
                .set_TARGET(l_target)
                .set_PATH_DELAY(i_tod_node->o_int_path_delay)
                .set_LONGEST_DELAY(i_longest_delay),
                "Invalid delay calculated!");

    // Recurse on downstream nodes
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(set_topology_delays(*l_child,
                                     i_tod_node->o_int_path_delay),
                 "Error from set_topology_delays!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Calculates and populates the topology delays
/// @param[in,out] i_tod_node Reference to MDMT (master drawer, master TOD) node.
///    The MDMT node is the origin of the TOD topology tree.
/// @return FAPI2_RC_SUCCESS if TOD topology is successfully configured with
///         delays else error
fapi2::ReturnCode calculate_node_delays(tod_topology_node* i_tod_node)
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    tod_latency_t l_longest_delay = 0;

    FAPI_DBG("Start");

    // Find the most-delayed path in the topology; this is the MDMT's delay
    FAPI_TRY(calculate_longest_topolopy_delay(
                 i_tod_node,  // MDMT node
                 NULL,        // The topology tree's origin has no parent node
                 l_longest_delay),
             "Error from calculate_longest_topology_delay!");
    FAPI_DBG("The longest delay is %d TOD-grid-cycles.", l_longest_delay);
    FAPI_TRY(set_topology_delays(i_tod_node,
                                 l_longest_delay),
             "Error from set_topology_delays!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: description in header
fapi2::ReturnCode p10_tod_setup(
    tod_topology_node* i_tod_node,
    const p10_tod_setup_tod_sel i_tod_sel,
    const p10_tod_setup_osc_sel i_osc_sel)
{
    fapi2::ATTR_IS_MPIPL_Type l_is_mpipl = 0x00;

    FAPI_DBG("Start");

    FAPI_ASSERT((i_tod_node != NULL) &&
                (i_tod_node->i_target != NULL),
                fapi2::P10_TOD_SETUP_NULL_NODE(),
                "Null node or target passed into function!");

    FAPI_ASSERT((i_tod_node->i_tod_master) &&
                (i_tod_node->i_drawer_master),
                fapi2::P10_TOD_SETUP_INVALID_TOPOLOGY()
                .set_TARGET(*(i_tod_node->i_target))
                .set_OSCSEL(i_osc_sel)
                .set_TODSEL(i_tod_sel),
                "Non-root (slave) node passed into main function!");

    FAPI_INF("Configuring %s topology (OSC0 is %s, OSC1 is %s)",
             (i_tod_sel == TOD_PRIMARY) ? "Primary" : "Secondary",
             (i_osc_sel == TOD_OSC_0             ||
              i_osc_sel == TOD_OSC_0_AND_1       ||
              i_osc_sel == TOD_OSC_0_AND_1_SEL_0 ||
              i_osc_sel == TOD_OSC_0_AND_1_SEL_1) ? "connected" : "not connected",
             (i_osc_sel == TOD_OSC_1             ||
              i_osc_sel == TOD_OSC_0_AND_1       ||
              i_osc_sel == TOD_OSC_0_AND_1_SEL_0 ||
              i_osc_sel == TOD_OSC_0_AND_1_SEL_1) ? "connected" : "not connected");


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_MPIPL,
                           fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_is_mpipl),
             "Error from FAPI_ATTR_GET (ATTR_IS_MPIPL)!");

    if ( l_is_mpipl && ( i_tod_sel == TOD_PRIMARY))
    {
        // Disable the TOD step checkers
        FAPI_TRY(mpipl_disable_step_checkers(i_tod_node),
                 "Error from mpipl_disable_step_checkers!");

        // Put the TOD in the stopped state.
        FAPI_TRY(mpipl_clear_tod_node(i_tod_node, i_tod_sel),
                 "Error from mpipl_clear_tod_node!");
    }

    display_tod_nodes(i_tod_node, 0);

    // Start configuring each node
    // configure_tod_node will recurse on each child
    FAPI_TRY(calculate_node_delays(i_tod_node),
             "Error from calculate_node_delays!");

    display_tod_nodes(i_tod_node, 0);

    // If there is a previous topology, it needs to be cleared
    FAPI_TRY(clear_tod_node(i_tod_node, i_tod_sel),
             "Error from clear_tod_node!");

    if ( i_tod_sel == TOD_PRIMARY )
    {
        // Clear the previous Fabric DL inits once to prevent clearing
        // the configuration during the Secondary topology setup.
        FAPI_TRY(fbc_dl_tod_node_config_clear(i_tod_node),
                 "Error from fbc_dl_tod_node_config_clear!");
    }

    // Start configuring each node
    // configure_tod_node will recurse on each child
    FAPI_TRY(configure_tod_node(i_tod_node, i_tod_sel, i_osc_sel),
             "Error from configure_tod_node!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
