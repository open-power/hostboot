/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_setup.C $      */
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
//
/// @file p9_tod_setup.C
/// @brief Procedures to configure the TOD topology
///
// *HWP HWP Owner: Nick Klazynski jklazyns@us.ibm.com
// *HWP HWP Owner: Joachim Fenkes fenkes@de.ibm.com
// *HWP FW Owner: Manish Chowdhary manichow@in.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_tod_setup.H>

const uint64_t M_PATH_CTRL_REG_CLEAR_VALUE = 0x0000000000000000;
const uint64_t S_PATH_CTRL_REG_CLEAR_VALUE = 0x0000003F00000000;
static const uint8_t P9A_PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL9_DC = 21;

/// @brief MPIPL specific steps to clear the previous topology, this should be
//  called only during MPIPL
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to clear
/// @return FAPI_RC_SUCCESS if TOD topology is successfully cleared, else error
fapi2::ReturnCode mpipl_clear_tod_node(
    tod_topology_node* i_tod_node,
    const p9_tod_setup_tod_sel i_tod_sel)
{
    uint32_t l_port_ctrl_check_reg = 0;
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];

    fapi2::toString(*(i_tod_node->i_target),
                    l_targetStr,
                    fapi2::MAX_ECMD_STRING_LEN);

    FAPI_INF("MPIPL-Clearing previous %s topology from %s",
             (i_tod_sel == TOD_PRIMARY) ? "Primary" : "Secondary", l_targetStr);


    fapi2::buffer<uint64_t> l_rx_ttype_ctrl_reg = 0;
    fapi2::buffer<uint64_t> l_tx_ttype5_reg = 0;
    fapi2::buffer<uint64_t> l_tod_load_reg = 0;
    fapi2::buffer<uint64_t> l_m_path_ctrl_reg = M_PATH_CTRL_REG_CLEAR_VALUE;
    fapi2::buffer<uint64_t> l_s_path_ctrl_reg = S_PATH_CTRL_REG_CLEAR_VALUE;

    FAPI_INF("MPIPL: stop step checkers");
    //Stop step checkers
    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_PSS_MSS_CTRL_REG,
                            0x0ULL),
             "Error from putScom (0x%08X)!", l_port_ctrl_check_reg);

    FAPI_INF("MPIPL: switch TOD to 'Not Set' state");
    // Generate TType#5 (formats defined in section "TType Fabric Interface"
    // in the TOD workbook)
    l_rx_ttype_ctrl_reg.setBit<5>().setBit<56>();
    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_RX_TTYPE_CTRL_REG,
                            l_rx_ttype_ctrl_reg),
             "Error from putScom (PERV_TOD_RX_TTYPE_CTRL_REG)");

    FAPI_INF("MPIPL: switch all other TODs to 'Not Set' state");
    l_tx_ttype5_reg.setBit<PERV_TOD_TX_TTYPE_5_REG_TRIGGER>();
    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_TX_TTYPE_5_REG,
                            l_tx_ttype5_reg),
             "Error from putScom (PERV_TOD_TX_TTYPE_5_REG)");

    //PUT TOD in stop state
    FAPI_INF("MPIPL: put TOD to stop state");
    l_tod_load_reg.setBit<63>();
    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_LOAD_TOD_REG,
                            l_tod_load_reg),
             "Error from putScom (PERV_TOD_TX_TTYPE_5_REG)");

    FAPI_INF("Clearing PERV_TOD_M_PATH_CTRL_REG");
    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_M_PATH_CTRL_REG,
                            l_m_path_ctrl_reg),
             "Error in clearing PERV_TOD_M_PATH_CTRL_REG");

    FAPI_INF("Clearing PERV_TOD_S_PATH_CTRL_REG");
    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_S_PATH_CTRL_REG,
                            l_s_path_ctrl_reg),
             "Error in clearing PERV_TOD_S_PATH_CTRL_REG");


    for(auto l_child = (i_tod_node->i_children).begin();
        l_child != (i_tod_node->i_children).end();
        ++l_child)
    {
        FAPI_INF("Going to sleep for 1 second ");
        FAPI_TRY(mpipl_clear_tod_node(*l_child,
                                      i_tod_sel),
                 "Failure clearing downstream TOD node!");
    }

fapi_try_exit:
    FAPI_INF("Exiting...");
    return fapi2::current_err;
}


/// @brief Specific steps to clear the previous topology.
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to clear
/// @return FAPI_RC_SUCCESS if TOD topology is successfully cleared, else error
fapi2::ReturnCode clear_tod_node(
    tod_topology_node* i_tod_node,
    const p9_tod_setup_tod_sel i_tod_sel,
    const fapi2::ATTR_IS_MPIPL_Type i_is_mpipl)
{
    uint32_t l_port_ctrl_reg = 0;
    uint32_t l_port_ctrl_check_reg = 0;
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];

    fapi2::toString(*(i_tod_node->i_target),
                    l_targetStr,
                    fapi2::MAX_ECMD_STRING_LEN);
    FAPI_INF("Clearing previous %s topology from %s",
             (i_tod_sel == TOD_PRIMARY) ? "Primary" : "Secondary", l_targetStr);

    if (i_tod_sel == TOD_PRIMARY)
    {
        FAPI_DBG("PERV_TOD_PRI_PORT_0_CTRL_REG and PERV_TOD_SEC_PORT_0_CTRL_REG will be cleared.");
        l_port_ctrl_reg = PERV_TOD_PRI_PORT_0_CTRL_REG;
        l_port_ctrl_check_reg = PERV_TOD_SEC_PORT_0_CTRL_REG;
    }
    else // (i_tod_sel==TOD_SECONDARY)
    {
        FAPI_DBG("PERV_TOD_PRI_PORT_1_CTRL_REG and PERV_TOD_SEC_PORT_1_CTRL_REG will be cleared.");
        l_port_ctrl_reg = PERV_TOD_SEC_PORT_1_CTRL_REG;
        l_port_ctrl_check_reg = PERV_TOD_PRI_PORT_1_CTRL_REG;
    }

    // zero registers
    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            l_port_ctrl_reg,
                            0x0ULL),
             "Error from putScom (0x%08X)!", l_port_ctrl_reg);
    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            l_port_ctrl_check_reg,
                            0x0ULL),
             "Error from putScom (0x%08X)!", l_port_ctrl_check_reg);

    if (i_tod_sel == TOD_PRIMARY)
    {
        // Workaround for HW480181: Init remote sync checker tolerance to maximum;
        // will be closed down by configure_tod_node later.
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target), PERV_TOD_S_PATH_CTRL_REG, l_data),
                 "Error from getScom (PERV_TOD_S_PATH_CTRL_REG)!");
        l_data.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION,
                               PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_LEN>
                               (STEP_CHECK_CPS_DEVIATION_93_75_PCENT);
        l_data.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR,
                               PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR_LEN>
                               (STEP_CHECK_CPS_DEVIATION_FACTOR_8);
        FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target), PERV_TOD_S_PATH_CTRL_REG, l_data),
                 "Error from putScom (PERV_TOD_S_PATH_CTRL_REG)!");
    }


    // TOD is cleared for this node; if it has children, start clearing
    // their registers
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(clear_tod_node(*l_child,
                                i_tod_sel,
                                i_is_mpipl),
                 "Failure clearing downstream TOD node!");
    }

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Configures the PSS_MSS_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the PSS_MSS_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_pss_mss_ctrl_reg(
    tod_topology_node* i_tod_node,
    const p9_tod_setup_tod_sel i_tod_sel,
    const p9_tod_setup_osc_sel i_osc_sel)
{
    fapi2::buffer<uint64_t> l_pss_mss_ctrl_reg = 0;
    const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);

    FAPI_DBG("Start");

    // Read PERV_TOD_PSS_MSS_CTRL_REG in order to preserve any prior configuration
    FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                            PERV_TOD_PSS_MSS_CTRL_REG,
                            l_pss_mss_ctrl_reg),
             "Error from getScom (PERV_TOD_PSS_MSS_CTRL_REG)!");

    FAPI_DBG("Set Master TOD/Slave TOD and Master Drawer/Slave Drawer");

    if (i_tod_sel == TOD_PRIMARY)
    {
        if (is_mdmt)
        {
            l_pss_mss_ctrl_reg.setBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_S_SELECT>();

            if (i_osc_sel == TOD_OSC_0             ||
                i_osc_sel == TOD_OSC_0_AND_1       ||
                i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
            {
                l_pss_mss_ctrl_reg.clearBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT>();
            }
            else if (i_osc_sel == TOD_OSC_1        ||
                     i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
            {
                l_pss_mss_ctrl_reg.setBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT>();
            }

            FAPI_ASSERT(i_osc_sel != TOD_OSC_NONE,
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_OSCSEL(i_osc_sel)
                        .set_TODSEL(i_tod_sel),
                        "Invalid oscillator configuration!");
        }
        else // Slave nodes (Drawer master is still a slave)
        {
            l_pss_mss_ctrl_reg.clearBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_S_SELECT>();
        }

        if (i_tod_node->i_drawer_master)
        {
            l_pss_mss_ctrl_reg.setBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT>();
        }
    }
    else // (i_tod_sel==TOD_SECONDARY)
    {
        if (is_mdmt)
        {
            l_pss_mss_ctrl_reg.setBit<PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_S_SELECT>();

            if (i_osc_sel == TOD_OSC_1       ||
                i_osc_sel == TOD_OSC_0_AND_1 ||
                i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
            {
                l_pss_mss_ctrl_reg.setBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT>(); // SW440224
                l_pss_mss_ctrl_reg.setBit<PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT>();
            }
            else if (i_osc_sel == TOD_OSC_0  ||
                     i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
            {
                l_pss_mss_ctrl_reg.clearBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT>(); // SW440224
                l_pss_mss_ctrl_reg.clearBit<PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT>();
            }

            FAPI_ASSERT(i_osc_sel != TOD_OSC_NONE,
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_OSCSEL(i_osc_sel)
                        .set_TODSEL(i_tod_sel),
                        "Invalid oscillator configuration!");
        }
        else // Slave nodes (Drawer master is still a slave)
        {
            l_pss_mss_ctrl_reg.clearBit<PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_S_SELECT>();
        }

        if (i_tod_node->i_drawer_master)
        {
            l_pss_mss_ctrl_reg.setBit<PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT>();
        }
    }

    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_PSS_MSS_CTRL_REG,
                            l_pss_mss_ctrl_reg),
             "Error from putScom (PERV_TOD_PSS_MSS_CTRL_REG)!");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Configures the S_PATH_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the S_PATH_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_s_path_ctrl_reg(
    tod_topology_node* i_tod_node,
    const p9_tod_setup_tod_sel i_tod_sel,
    const p9_tod_setup_osc_sel i_osc_sel)
{
    fapi2::buffer<uint64_t> l_s_path_ctrl_reg = 0;

    // Read PERV_TOD_S_PATH_CTRL_REG in order to preserve any prior configuration
    FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                            PERV_TOD_S_PATH_CTRL_REG,
                            l_s_path_ctrl_reg),
             "Error from getScom (PERV_TOD_S_PATH_CTRL_REG)!");

    // Slave TODs are enabled on all but the MDMT
    FAPI_DBG("Selection of Slave OSC path");

    if (i_tod_sel == TOD_PRIMARY)
    {
        // For primary slave, use slave path 0 (path_0_sel=OFF)
        l_s_path_ctrl_reg.clearBit<PERV_TOD_S_PATH_CTRL_REG_PRI_SELECT>();

        // Set CPS deviation to 75% (CPS deviation bits = 0xC, factor=1),
        // 8 valid steps to enable step check
        l_s_path_ctrl_reg.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
                                          PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>
                                          (STEP_CHECK_CPS_DEVIATION_FACTOR_1);
        l_s_path_ctrl_reg.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION,
                                          PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN>
                                          (STEP_CHECK_CPS_DEVIATION_75_00_PCENT);
        l_s_path_ctrl_reg.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT,
                                          PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN>
                                          (STEP_CHECK_VALIDITY_COUNT_8);
        l_s_path_ctrl_reg.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION,
                                          PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_LEN>
                                          (STEP_CHECK_CPS_DEVIATION_75_00_PCENT);
        l_s_path_ctrl_reg.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR,
                                          PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR_LEN>
                                          (STEP_CHECK_CPS_DEVIATION_FACTOR_1);
    }
    else // (i_tod_sel==TOD_SECONDARY)
    {
        // For secondary slave, use slave path 1 (path_1_sel=ON)
        l_s_path_ctrl_reg.setBit<PERV_TOD_S_PATH_CTRL_REG_SEC_SELECT>();

        // Set CPS deviation to 75% (CPS deviation bits = 0xC, factor=1),
        // 8 valid steps to enable step check
        l_s_path_ctrl_reg.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
                                          PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>
                                          (STEP_CHECK_CPS_DEVIATION_FACTOR_1);
        l_s_path_ctrl_reg.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION,
                                          PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION_LEN>
                                          (STEP_CHECK_CPS_DEVIATION_75_00_PCENT);
        l_s_path_ctrl_reg.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT,
                                          PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT_LEN>
                                          (STEP_CHECK_VALIDITY_COUNT_8);
    }

    // In either case set the S_PATH_REMOTE_SYNC_MISS_COUNT_MAX to 1
    l_s_path_ctrl_reg.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_MISS_COUNT_MAX,
                                      PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_MISS_COUNT_MAX_LEN>
                                      (TOD_S_PATH_CTRL_REG_REMOTE_SYNC_MISS_COUNT_2);

    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_S_PATH_CTRL_REG,
                            l_s_path_ctrl_reg),
             "Error from putScom (PERV_TOD_S_PATH_CTRL_REG)!");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Configures the PORT_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the PORT_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_port_ctrl_regs(
    tod_topology_node* i_tod_node,
    const p9_tod_setup_tod_sel i_tod_sel,
    const p9_tod_setup_osc_sel i_osc_sel)
{
    fapi2::buffer<uint64_t> l_port_ctrl_reg = 0;
    uint32_t l_port_ctrl_addr = 0;
    fapi2::buffer<uint64_t> l_port_ctrl_check_reg = 0;
    uint32_t l_port_ctrl_check_addr = 0;
    uint32_t l_port_rx_select_val = 0;
    uint32_t l_path_sel = 0;
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_x_attached_chip_cnfg;
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_a_attached_chip_cnfg;

    const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG,
                           *(i_tod_node->i_target),
                           l_x_attached_chip_cnfg),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)!");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG,
                           *(i_tod_node->i_target),
                           l_a_attached_chip_cnfg),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)!");

    // PERV_TOD_PRI_PORT_0_CTRL_REG is only used for Primary configurations
    // PERV_TOD_SEC_PORT_1_CTRL_REG is only used for Secondary configurations
    // In order to check primary and secondary networks are working
    // simultaneously...
    //  - The result of PERV_TOD_PRI_PORT_0_CTRL_REG are also inserted into
    //    PERV_TOD_SEC_PORT_0_CTRL_REG (preserving i_path_delay which can be
    //    different between 40001 and 40003)
    //  - The result of PERV_TOD_SEC_PORT_1_CTRL_REG are also inserted into
    //    PERV_TOD_PRI_PORT_1_CTRL_REG
    if (i_tod_sel == TOD_PRIMARY)
    {
        FAPI_DBG("PERV_TOD_PRI_PORT_0_CTRL_REG will be configured for primary topology");
        l_port_ctrl_addr = PERV_TOD_PRI_PORT_0_CTRL_REG;
        l_port_ctrl_check_addr = PERV_TOD_SEC_PORT_0_CTRL_REG;
    }
    else // (i_tod_sel==TOD_SECONDARY)
    {
        FAPI_DBG("PERV_TOD_SEC_PORT_1_CTRL_REG will be configured for secondary topology");
        l_port_ctrl_addr = PERV_TOD_SEC_PORT_1_CTRL_REG;
        l_port_ctrl_check_addr = PERV_TOD_PRI_PORT_1_CTRL_REG;
    }

    // Read port_ctrl_reg in order to preserve any prior configuration
    FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                            l_port_ctrl_addr,
                            l_port_ctrl_reg),
             "Error from getScom (0x%08X)!", l_port_ctrl_addr);

    // Read port_ctrl_check_reg in order to preserve any prior configuration
    FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                            l_port_ctrl_check_addr,
                            l_port_ctrl_check_reg),
             "Error from getScom (0x%08X)!", l_port_ctrl_check_addr);

    //Determine RX port
    switch (i_tod_node->i_bus_rx)
    {
        case (XBUS0):
            // If XBUS0 is not enabled throw an error
            FAPI_ASSERT((l_x_attached_chip_cnfg[0] != 0),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(XBUS0),
                        "i_tod_node->i_bus_rx is set to XBUS0 and it is not enabled");
            l_port_rx_select_val = TOD_PORT_CTRL_REG_RX_X0_SEL;
            break;

        case (XBUS1):
            // If XBUS1 is not enabled throw an error
            FAPI_ASSERT((l_x_attached_chip_cnfg[1] != 0),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(XBUS1),
                        "i_tod_node->i_bus_rx is set to XBUS1 and it is not enabled");
            l_port_rx_select_val = TOD_PORT_CTRL_REG_RX_X1_SEL;
            break;

        case (XBUS2):
            // If XBUS2 is not enabled throw an error
            FAPI_ASSERT((l_x_attached_chip_cnfg[2] != 0),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(XBUS2),
                        "i_tod_node->i_bus_rx is set to XBUS2 and it is not enabled");
            l_port_rx_select_val = TOD_PORT_CTRL_REG_RX_X2_SEL;
            break;

        case (OBUS0):
            // If OBUS0 is not enabled throw an error
            FAPI_ASSERT(((l_x_attached_chip_cnfg[3] != 0) ||
                         (l_a_attached_chip_cnfg[0] != 0)),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(OBUS0),
                        "i_tod_node->i_bus_rx is set to OBUS0 and it is not enabled");
            l_port_rx_select_val = TOD_PORT_CTRL_REG_RX_X3_SEL;
            break;

        case (OBUS1):
            // If OBUS1 is not enabled throw an error
            FAPI_ASSERT(((l_x_attached_chip_cnfg[4] != 0) ||
                         (l_a_attached_chip_cnfg[1] != 0)),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(OBUS1),
                        "i_tod_node->i_bus_rx is set to OBUS1 and it is not enabled");
            l_port_rx_select_val = TOD_PORT_CTRL_REG_RX_X4_SEL;
            break;

        case (OBUS2):
            // If OBUS2 is not enabled throw an error
            FAPI_ASSERT(((l_x_attached_chip_cnfg[5] != 0) ||
                         (l_a_attached_chip_cnfg[2] != 0)),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(OBUS2),
                        "i_tod_node->i_bus_rx is set to OBUS2 and it is not enabled");
            l_port_rx_select_val = TOD_PORT_CTRL_REG_RX_X5_SEL;
            break;

        case (OBUS3):
            // If OBUS3 is not enabled throw an error
            FAPI_ASSERT(((l_x_attached_chip_cnfg[6] != 0) ||
                         (l_a_attached_chip_cnfg[3] != 0)),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(OBUS3),
                        "i_tod_node->i_bus_rx is set to OBUS3 and it is not enabled");
            l_port_rx_select_val = TOD_PORT_CTRL_REG_RX_X6_SEL;
            break;

        case (XBUS7):
            FAPI_ASSERT(false,
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(XBUS7),
                        "i_tod_node->i_bus_rx is set to XBUS7");
            break;

        case (NONE):
            break; //MDMT has no rx
    }

    l_port_ctrl_reg.insertFromRight<PERV_TOD_PRI_PORT_0_CTRL_REG_RX_SELECT,
                                    PERV_TOD_PRI_PORT_0_CTRL_REG_RX_SELECT_LEN>(l_port_rx_select_val);
    l_port_ctrl_check_reg.insertFromRight<PERV_TOD_PRI_PORT_0_CTRL_REG_RX_SELECT,
                                          PERV_TOD_PRI_PORT_0_CTRL_REG_RX_SELECT_LEN>(l_port_rx_select_val);

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
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY()
                        .set_TARGET(*(i_tod_node->i_target))
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
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY()
                        .set_TARGET(*(i_tod_node->i_target))
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

    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        // Loop through all of the out busses, determine which tx buses to
        // enable as senders
        switch ((*l_child)->i_bus_tx)
        {
            case (XBUS0):
                // If XBUS0 is not enabled throw an error
                FAPI_ASSERT((l_x_attached_chip_cnfg[0] != 0),
                            fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_TX()
                            .set_TARGET(*(i_tod_node->i_target))
                            .set_TX(XBUS0),
                            "i_tod_node->i_bus_rx is set to XBUS0 and it is not enabled");
                l_port_ctrl_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X0_SEL,
                                                TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_reg.setBit<TOD_PORT_CTRL_REG_TX_X0_EN>();
                l_port_ctrl_check_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X0_SEL,
                                                      TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_check_reg.setBit<TOD_PORT_CTRL_REG_TX_X0_EN>();
                break;

            case (XBUS1):
                // If XBUS1 is not enabled throw an error
                FAPI_ASSERT((l_x_attached_chip_cnfg[1] != 0),
                            fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_TX()
                            .set_TARGET(*(i_tod_node->i_target))
                            .set_TX(XBUS1),
                            "i_tod_node->i_bus_rx is set to XBUS1 and it is not enabled");
                l_port_ctrl_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X1_SEL,
                                                TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_reg.setBit<TOD_PORT_CTRL_REG_TX_X1_EN>();
                l_port_ctrl_check_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X1_SEL,
                                                      TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_check_reg.setBit<TOD_PORT_CTRL_REG_TX_X1_EN>();
                break;

            case (XBUS2):
                // If XBUS2 is not enabled throw an error
                FAPI_ASSERT((l_x_attached_chip_cnfg[2] != 0),
                            fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_TX()
                            .set_TARGET(*(i_tod_node->i_target))
                            .set_TX(XBUS2),
                            "i_tod_node->i_bus_rx is set to XBUS2 and it is not enabled");
                l_port_ctrl_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X2_SEL,
                                                TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_reg.setBit<TOD_PORT_CTRL_REG_TX_X2_EN>();
                l_port_ctrl_check_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X2_SEL,
                                                      TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_check_reg.setBit<TOD_PORT_CTRL_REG_TX_X2_EN>();
                break;

            case (OBUS0):
                // If OBUS0 is not enabled throw an error
                FAPI_ASSERT(((l_x_attached_chip_cnfg[3] != 0)
                             || (l_a_attached_chip_cnfg[0] != 0)),
                            fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_TX()
                            .set_TARGET(*(i_tod_node->i_target))
                            .set_TX(OBUS0),
                            "i_tod_node->i_bus_rx is set to OBUS0 and it is not enabled");
                l_port_ctrl_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X3_SEL,
                                                TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_reg.setBit<TOD_PORT_CTRL_REG_TX_X3_EN>();
                l_port_ctrl_check_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X3_SEL,
                                                      TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_check_reg.setBit<TOD_PORT_CTRL_REG_TX_X3_EN>();
                break;

            case (OBUS1):
                // If OBUS1 is not enabled throw an error
                FAPI_ASSERT(((l_x_attached_chip_cnfg[4] != 0) ||
                             (l_a_attached_chip_cnfg[1] != 0)),
                            fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_TX()
                            .set_TARGET(*(i_tod_node->i_target))
                            .set_TX(OBUS1),
                            "i_tod_node->i_bus_rx is set to OBUS1 and it is not enabled");
                l_port_ctrl_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X4_SEL,
                                                TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_reg.setBit<TOD_PORT_CTRL_REG_TX_X4_EN>();
                l_port_ctrl_check_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X4_SEL,
                                                      TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_check_reg.setBit<TOD_PORT_CTRL_REG_TX_X4_EN>();
                break;

            case (OBUS2):
                // If OBUS2 is not enabled throw an error
                FAPI_ASSERT(((l_x_attached_chip_cnfg[5] != 0) ||
                             (l_a_attached_chip_cnfg[2] != 0)),
                            fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_TX()
                            .set_TARGET(*(i_tod_node->i_target))
                            .set_TX(OBUS2),
                            "i_tod_node->i_bus_rx is set to OBUS2 and it is not enabled");
                l_port_ctrl_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X5_SEL,
                                                TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_reg.setBit<TOD_PORT_CTRL_REG_TX_X5_EN>();
                l_port_ctrl_check_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X5_SEL,
                                                      TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_check_reg.setBit<TOD_PORT_CTRL_REG_TX_X5_EN>();
                break;

            case (OBUS3):
                // If OBUS3 is not enabled throw an error
                FAPI_ASSERT(((l_x_attached_chip_cnfg[6] != 0) ||
                             (l_a_attached_chip_cnfg[3] != 0)),
                            fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_TX()
                            .set_TARGET(*(i_tod_node->i_target))
                            .set_TX(OBUS3),
                            "i_tod_node->i_bus_rx is set to OBUS3 and it is not enabled");
                l_port_ctrl_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X6_SEL,
                                                TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_reg.setBit<TOD_PORT_CTRL_REG_TX_X6_EN>();
                l_port_ctrl_check_reg.insertFromRight<TOD_PORT_CTRL_REG_TX_X6_SEL,
                                                      TOD_PORT_CTRL_REG_TX_LEN>(l_path_sel);
                l_port_ctrl_check_reg.setBit<TOD_PORT_CTRL_REG_TX_X6_EN>();
                break;

            case (XBUS7):
                FAPI_ASSERT(false,
                            fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_TX()
                            .set_TARGET(*(i_tod_node->i_target))
                            .set_TX(XBUS7),
                            "i_tod_node->i_bus_tx is set to XBUS7");
                break;

            case (NONE):
                FAPI_ASSERT(((*l_child)->i_bus_tx != NONE),
                            fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_TX()
                            .set_TARGET(*(i_tod_node->i_target))
                            .set_TX(NONE),
                            "i_tod_node->i_bus_tx is set to NONE");
                break;
        }
    }

    // All children have been configured; save both port configurations!
    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            l_port_ctrl_addr,
                            l_port_ctrl_reg),
             "Error from putScom (0x%08X)!", l_port_ctrl_addr);

    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            l_port_ctrl_check_addr,
                            l_port_ctrl_check_reg),
             "Error from putScom (0x%08X)!", l_port_ctrl_check_addr);

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Configures the M_PATH_CTRL_REG; will be called by configure_tod_node
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the M_PATH_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_m_path_ctrl_reg(
    tod_topology_node* i_tod_node,
    const p9_tod_setup_tod_sel i_tod_sel,
    const p9_tod_setup_osc_sel i_osc_sel,
    const bool i_dual_edge_disable)
{
    fapi2::buffer<uint64_t> l_m_path_ctrl_reg = 0;

    const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);

    // Read PERV_TOD_M_PATH_CTRL_REG to preserve any prior configuration
    FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                            PERV_TOD_M_PATH_CTRL_REG,
                            l_m_path_ctrl_reg),
             "Error from getScom (PERV_TOD_M_PATH_CTRL_REG)!");

    // Configure single or dual edge detect based on tod clock select
    if (i_dual_edge_disable)
    {
        // ON: sample only the rising edge of the oscillator
        l_m_path_ctrl_reg.setBit<PERV_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE>();

        // In single-edge mode the TOD expects a 16 MHz oscillator, and since all SPS values are specified in
        // terms of us instead of steps, the HW actually changes how it interprets the SPS values: Every setting
        // suddenly means half as many STEPs as before. Since we're staying at 32 MHz and want the same STEPs
        // per SYNC we have to adapt our SPS values to the next higher power of two.
        l_m_path_ctrl_reg.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT,
                                          PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT_LEN>(TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_1024);
    }
    else
    {
        // OFF: sample both edges of the oscillator
        l_m_path_ctrl_reg.clearBit<PERV_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE>();

        l_m_path_ctrl_reg.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT,
                                          PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT_LEN>(TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_512);
    }

    if (is_mdmt)
    {
        // Configure Master OSC0/OSC1 path
        FAPI_DBG("Configuring Master OSC path in PERV_TOD_M_PATH_CTRL_REG");

        if (i_osc_sel == TOD_OSC_0             ||
            i_osc_sel == TOD_OSC_0_AND_1       ||
            i_osc_sel == TOD_OSC_0_AND_1_SEL_0 ||
            i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
        {
            FAPI_DBG("OSC0 is valid; master path-0 will be configured.");

            // OSC0 is connected
            l_m_path_ctrl_reg.clearBit<PERV_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID>();

            // OSC0 step alignment enabled
            l_m_path_ctrl_reg.clearBit<PERV_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE>();

            // Set step check CPS deviation to 50%
            l_m_path_ctrl_reg.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION,
                                              PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN>(
                                                  STEP_CHECK_CPS_DEVIATION_50_00_PCENT);

            // 8 valid steps are required before step check is enabled
            l_m_path_ctrl_reg.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT,
                                              PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN>(
                                                  STEP_CHECK_VALIDITY_COUNT_8);
        }
        else
        {
            FAPI_DBG("OSC0 is not connected.");

            // OSC0 is not connected; any previous path-0 settings will be ignored
            l_m_path_ctrl_reg.setBit<PERV_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID>();
        }

        if (i_osc_sel == TOD_OSC_1             ||
            i_osc_sel == TOD_OSC_0_AND_1       ||
            i_osc_sel == TOD_OSC_0_AND_1_SEL_0 ||
            i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
        {
            FAPI_DBG("OSC1 is valid; master path-1 will be configured.");

            // OSC1 is connected
            l_m_path_ctrl_reg.clearBit<PERV_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID>();

            // OSC1 step alignment enabled
            l_m_path_ctrl_reg.clearBit<PERV_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE>();

            // Set step check CPS deviation to 50%
            l_m_path_ctrl_reg.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION,
                                              PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION_LEN>(
                                                  STEP_CHECK_CPS_DEVIATION_50_00_PCENT);

            // 8 valid steps are required before step check is enabled
            l_m_path_ctrl_reg.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT,
                                              PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT_LEN>(
                                                  STEP_CHECK_VALIDITY_COUNT_8);
        }
        else
        {
            FAPI_DBG("OSC1 is not connected.");

            // OSC1 is not connected; any previous path-1 settings will be ignored
            l_m_path_ctrl_reg.setBit<PERV_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID>();
        }

        // CPS deviation factor configures both path-0 and path-1
        l_m_path_ctrl_reg.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
                                          PERV_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(
                                              STEP_CHECK_CPS_DEVIATION_FACTOR_1);
    }

    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_M_PATH_CTRL_REG,
                            l_m_path_ctrl_reg),
             "Error from putScom (PERV_TOD_M_PATH_CTRL_REG)!");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Configures the I_PATH_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the I_PATH_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode configure_i_path_ctrl_reg(
    tod_topology_node* i_tod_node,
    const p9_tod_setup_tod_sel i_tod_sel,
    const p9_tod_setup_osc_sel i_osc_sel)
{
    fapi2::buffer<uint64_t> l_i_path_ctrl_reg = 0;
    fapi2::buffer<uint64_t> l_port_ctrl_reg = 0;
    uint32_t l_port_ctrl_addr = 0;

    FAPI_DBG("Setting internal path delay");

    // This is the number of TOD-grid-cycles to delay the internal path
    // (0-0xFF valid); 1 TOD-grid-cycle = 400ps (default)
    if (i_tod_sel == TOD_PRIMARY)
    {
        // Primary topology internal path delay set PERV_TOD_PRI_PORT_0_CTRL_REG
        // regardless of master/slave/port
        FAPI_DBG("PERV_TOD_PRI_PORT_0_CTRL_REG will be used to set internal delay");
        l_port_ctrl_addr = PERV_TOD_PRI_PORT_0_CTRL_REG;
    }
    else // (i_tod_sel==TOD_SECONDARY)
    {
        // Secondary topology internal path delay set PERV_TOD_SEC_PORT_0_CTRL_REG
        // regardless of master/slave/port
        FAPI_DBG("PERV_TOD_SEC_PORT_0_CTRL_REG will be used to set internal delay");
        l_port_ctrl_addr = PERV_TOD_SEC_PORT_0_CTRL_REG;
    }

    FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                            l_port_ctrl_addr,
                            l_port_ctrl_reg),
             "Error from getScom (0x%08X)!", l_port_ctrl_addr);

    FAPI_DBG("configuring an internal delay of %d TOD-grid-cycles",
             i_tod_node->o_int_path_delay);
    l_port_ctrl_reg.insertFromRight<TOD_PORT_CTRL_REG_I_PATH_DELAY,
                                    TOD_PORT_CTRL_REG_I_PATH_DELAY_LEN>(i_tod_node->o_int_path_delay);

    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            l_port_ctrl_addr,
                            l_port_ctrl_reg),
             "Error from putScom (0x%08X)!", l_port_ctrl_addr);

    FAPI_DBG("Enable delay logic in PERV_TOD_I_PATH_CTRL_REG");
    // Read PERV_TOD_I_PATH_CTRL_REG in order to preserve prior configuration
    FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                            PERV_TOD_I_PATH_CTRL_REG,
                            l_i_path_ctrl_reg),
             "Error from getScom (PERV_TOD_I_PATH_CTRL_REG)!");

    // Ensure delay is enabled
    l_i_path_ctrl_reg.clearBit<PERV_TOD_I_PATH_CTRL_REG_DELAY_DISABLE>();
    l_i_path_ctrl_reg.clearBit<PERV_TOD_I_PATH_CTRL_REG_DELAY_ADJUST_DISABLE>();

    // Deviation for internal OSC should be set to max, allowing backup master
    // TOD to run the active topology, when switching from Slave OSC path to
    // Master OSC path
    l_i_path_ctrl_reg.insertFromRight<PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION,
                                      PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_LEN>(
                                          STEP_CHECK_CPS_DEVIATION_93_75_PCENT);
    l_i_path_ctrl_reg.insertFromRight<PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
                                      PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(
                                          STEP_CHECK_CPS_DEVIATION_FACTOR_1);
    l_i_path_ctrl_reg.insertFromRight<PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_VALIDITY_COUNT,
                                      PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_VALIDITY_COUNT_LEN>(
                                          STEP_CHECK_VALIDITY_COUNT_8);

    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_I_PATH_CTRL_REG,
                            l_i_path_ctrl_reg),
             "Error from putScom (PERV_TOD_I_PATH_CTRL_REG)!");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Configures the INIT_CHIP_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the INIT_CHIP_CTRL_REG is successfully configured
///         else error
fapi2::ReturnCode init_chip_ctrl_reg(
    tod_topology_node* i_tod_node,
    const p9_tod_setup_tod_sel i_tod_sel,
    const p9_tod_setup_osc_sel i_osc_sel,
    const bool i_dual_edge_disable)
{
    fapi2::buffer<uint64_t> l_chip_ctrl_reg = 0;

    // In single-edge mode the TOD expects a 16 MHz oscillator, and since all SPS values are specified in
    // terms of us instead of steps, the HW actually changes how it interprets the SPS values: Every setting
    // suddenly means half as many STEPs as before. Since we're staying at 32 MHz and want the same STEPs
    // per SYNC we have to adapt our SPS values to the next higher power of two.
    const uint32_t l_sps_value = i_dual_edge_disable ?
                                 TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_16 :
                                 TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_8;

    FAPI_DBG("Start");
    FAPI_DBG("Set low order step value to 3F in PERV_TOD_CHIP_CTRL_REG");

    // Read PERV_TOD_CHIP_CTRL_REG in order to preserve prior configuration
    FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                            PERV_TOD_CHIP_CTRL_REG,
                            l_chip_ctrl_reg),
             "Error from getScom (PERV_TOD_CHIP_CTRL_REG)!");

    // Default core sync period is 8us
    l_chip_ctrl_reg.insertFromRight<PERV_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT,
                                    PERV_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT_LEN>(l_sps_value);

    // Enable internal path sync check
    l_chip_ctrl_reg.clearBit<PERV_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE>();

    // 1x sync boundaries for Move-TOD-To-Timebase
    l_chip_ctrl_reg.clearBit<PERV_TOD_CHIP_CTRL_REG_MOVE_TO_TB_ON_2X_SYNC_ENABLE>();

    // Use eclipz sync mechanism
    l_chip_ctrl_reg.clearBit<PERV_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM>();

    // Use timebase step sync from internal path
    l_chip_ctrl_reg.clearBit<PERV_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC>();

    // Chip TOD WOF incrementer ratio (eclipz mode)
    // 4-bit WOF counter is incremented with each 200MHz clock cycle
    l_chip_ctrl_reg.insertFromRight<PERV_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE,
                                    PERV_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE_LEN>(
                                        TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_3F);

    // Stop TOD when system checkstop occurs
    l_chip_ctrl_reg.clearBit<PERV_TOD_CHIP_CTRL_REG_XSTOP_GATE>();

    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            PERV_TOD_CHIP_CTRL_REG,
                            l_chip_ctrl_reg),
             "Error from putScom (PERV_TOD_CHIP_CTRL_REG)!");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Configure the tod topology -- set up the oscilator select and the
///        primary or secondary tod
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if TOD topology is successfully configured
///         else error
fapi2::ReturnCode configure_tod_node(
    tod_topology_node* i_tod_node,
    const p9_tod_setup_tod_sel i_tod_sel,
    const p9_tod_setup_osc_sel i_osc_sel)
{
    bool l_dual_edge_disable = false;
    fapi2::buffer<uint64_t> l_root_ctrl8_reg = 0;

    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(*(i_tod_node->i_target),
                    l_targetStr,
                    fapi2::MAX_ECMD_STRING_LEN);
    FAPI_DBG("Start: Configuring %s", l_targetStr);

    const bool is_mdmt = (i_tod_node->i_tod_master &&
                          i_tod_node->i_drawer_master);

    // Read ROOT_CTRL8 to determine TOD input clock selection
    FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                            PERV_ROOT_CTRL8_SCOM,
                            l_root_ctrl8_reg),
             "Error from getScom (PERV_ROOT_CTRL8_SCOM)!");

    l_dual_edge_disable = l_root_ctrl8_reg.getBit<P9A_PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL9_DC>();

    FAPI_TRY(configure_pss_mss_ctrl_reg(i_tod_node,
                                        i_tod_sel,
                                        i_osc_sel),
             "Error from configure_pss_mss_ctrl_reg!");

    if (!is_mdmt)
    {
        FAPI_TRY(configure_s_path_ctrl_reg(i_tod_node,
                                           i_tod_sel,
                                           i_osc_sel),
                 "Error from configure_s_path_ctrl_reg!");
    }

    FAPI_TRY(configure_port_ctrl_regs(i_tod_node,
                                      i_tod_sel,
                                      i_osc_sel),
             "Error from configure_port_ctrl_regs!");

    FAPI_TRY(configure_m_path_ctrl_reg(i_tod_node,
                                       i_tod_sel,
                                       i_osc_sel,
                                       l_dual_edge_disable),
             "Error from configure_m_path_ctrl_reg!");

    FAPI_TRY(configure_i_path_ctrl_reg(i_tod_node,
                                       i_tod_sel,
                                       i_osc_sel),
             "Error from configure_i_path_ctrl_reg!");

    FAPI_TRY(init_chip_ctrl_reg(i_tod_node,
                                i_tod_sel,
                                i_osc_sel,
                                l_dual_edge_disable),
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
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Displays the TOD topology
/// @param[in] i_tod_node Reference to TOD topology
/// @param[in] depth Current depth into TOD topology network
/// @return void
void display_tod_nodes(
    const tod_topology_node* i_tod_node,
    const uint32_t i_depth)
{
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];

    if (i_tod_node == NULL || i_tod_node->i_target == NULL)
    {
        FAPI_INF("NULL tod_node or target parameter!");
        goto fapi_try_exit;
    }

    fapi2::toString(i_tod_node->i_target,
                    l_targetStr,
                    fapi2::MAX_ECMD_STRING_LEN);
    FAPI_INF("%s (Delay = %d)",
             l_targetStr, i_tod_node->o_int_path_delay);

    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        display_tod_nodes(*l_child, i_depth + 1);
    }

fapi_try_exit:
    return;
}


/// @brief Calculates the delay for a node in TOD-grid-cycles
/// @param[in] i_tod_node Reference to TOD topology
/// @param[in] i_freq_x XBUS frequency in MHz
/// @param[in] i_freq_a OBUS frequency in MHz
/// @param[out] o_node_delay => Delay of a single node in TOD-grid-cycles
/// @return FAPI_RC_SUCCESS if TOD node delay is successfully calculated else
///         error
fapi2::ReturnCode calculate_node_link_delay(
    tod_topology_node* i_tod_node,
    const uint32_t i_freq_x,
    const uint32_t i_freq_a,
    uint32_t& o_node_delay)
{
    fapi2::buffer<uint64_t> l_rt_delay_ctl_reg = 0;
    uint32_t l_rt_delay_ctl_addr = 0;
    fapi2::buffer<uint64_t> l_bus_mode_reg = 0;
    uint32_t l_bus_mode_addr = 0;
    uint32_t l_bus_mode_sel_even = 0;
    uint32_t l_bus_mode_sel_odd = 0;
    uint32_t l_bus_freq = 0;
    uint32_t l_bus_delay = 0;
    uint32_t l_bus_delay_even = 0;
    uint32_t l_bus_delay_odd = 0;

    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_x_attached_chip_cnfg;
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_a_attached_chip_cnfg;

    FAPI_DBG("Start");

    // MDMT is originator and therefore has no node delay
    if (i_tod_node->i_tod_master && i_tod_node->i_drawer_master)
    {
        o_node_delay = 0;
        goto fapi_try_exit;
    }

    // else slave
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG,
                           *(i_tod_node->i_target),
                           l_x_attached_chip_cnfg),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)!");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG,
                           *(i_tod_node->i_target),
                           l_a_attached_chip_cnfg),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)!");

    switch (i_tod_node->i_bus_rx)
    {
        case (XBUS0):
            // If XBUS0 is not enabled throw an error
            FAPI_ASSERT((l_x_attached_chip_cnfg[0] != 0),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(XBUS0),
                        "i_tod_node->i_bus_rx is set to XBUS0 and it is not enabled");
            l_bus_freq = i_freq_x;
            l_rt_delay_ctl_reg.setBit<PB_ELINK_RT_DELAY_CTL_SET_LINK_0>()
            .setBit<PB_ELINK_RT_DELAY_CTL_SET_LINK_1>();
            l_rt_delay_ctl_addr = PU_PB_ELINK_RT_DELAY_CTL_REG;
            l_bus_mode_addr = PU_PB_ELINK_DLY_0123_REG;
            l_bus_mode_sel_even = PU_PB_ELINK_DLY_0123_REG_FMR0_LINK_DELAY;
            l_bus_mode_sel_odd = PU_PB_ELINK_DLY_0123_REG_FMR1_LINK_DELAY;
            break;

        case (XBUS1):
            // If XBUS1 is not enabled throw an error
            FAPI_ASSERT((l_x_attached_chip_cnfg[1] != 0),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(XBUS1),
                        "i_tod_node->i_bus_rx is set to XBUS1 and it is not enabled");
            l_bus_freq = i_freq_x;
            l_rt_delay_ctl_reg.setBit<PB_ELINK_RT_DELAY_CTL_SET_LINK_2>()
            .setBit<PB_ELINK_RT_DELAY_CTL_SET_LINK_3>();
            l_rt_delay_ctl_addr = PU_PB_ELINK_RT_DELAY_CTL_REG;
            l_bus_mode_addr = PU_PB_ELINK_DLY_0123_REG;
            l_bus_mode_sel_even = PU_PB_ELINK_DLY_0123_REG_FMR2_LINK_DELAY;
            l_bus_mode_sel_odd = PU_PB_ELINK_DLY_0123_REG_FMR3_LINK_DELAY;
            break;

        case (XBUS2):
            // If XBUS2 is not enabled throw an error
            FAPI_ASSERT((l_x_attached_chip_cnfg[2] != 0),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(XBUS2),
                        "i_tod_node->i_bus_rx is set to XBUS2 and it is not enabled");
            l_bus_freq = i_freq_x;
            l_rt_delay_ctl_reg.setBit<PB_ELINK_RT_DELAY_CTL_SET_LINK_4>()
            .setBit<PB_ELINK_RT_DELAY_CTL_SET_LINK_5>();
            l_rt_delay_ctl_addr = PU_PB_ELINK_RT_DELAY_CTL_REG;
            l_bus_mode_addr = PU_PB_ELINK_DLY_45_REG;
            l_bus_mode_sel_even = PU_PB_ELINK_DLY_45_REG_FMR4_LINK_DELAY;
            l_bus_mode_sel_odd = PU_PB_ELINK_DLY_45_REG_FMR5_LINK_DELAY;
            break;

        case (OBUS0):
            // If OBUS0 is not enabled throw an error
            FAPI_ASSERT(((l_x_attached_chip_cnfg[3] != 0) ||
                         (l_a_attached_chip_cnfg[0] != 0)),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(OBUS0),
                        "i_tod_node->i_bus_rx is set to OBUS0 and it is not enabled");
            l_bus_freq = i_freq_a;
            l_rt_delay_ctl_reg.setBit<PB_OLINK_RT_DELAY_CTL_SET_LINK_0>()
            .setBit<PB_OLINK_RT_DELAY_CTL_SET_LINK_1>();
            l_rt_delay_ctl_addr = PU_IOE_PB_OLINK_RT_DELAY_CTL_REG;
            l_bus_mode_addr = PU_IOE_PB_OLINK_DLY_0123_REG;
            l_bus_mode_sel_even = PU_IOE_PB_OLINK_DLY_0123_REG_FMR0_LINK_DELAY;
            l_bus_mode_sel_odd = PU_IOE_PB_OLINK_DLY_0123_REG_FMR1_LINK_DELAY;
            break;

        case (OBUS1):
            // If OBUS1 is not enabled throw an error
            FAPI_ASSERT(((l_x_attached_chip_cnfg[4] != 0) ||
                         (l_a_attached_chip_cnfg[1] != 0)),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(OBUS1),
                        "i_tod_node->i_bus_rx is set to OBUS1 and it is not enabled");
            l_bus_freq = i_freq_a;
            l_rt_delay_ctl_reg.setBit<PB_OLINK_RT_DELAY_CTL_SET_LINK_2>()
            .setBit<PB_OLINK_RT_DELAY_CTL_SET_LINK_3>();
            l_rt_delay_ctl_addr = PU_IOE_PB_OLINK_RT_DELAY_CTL_REG;
            l_bus_mode_addr = PU_IOE_PB_OLINK_DLY_0123_REG;
            l_bus_mode_sel_even = PU_IOE_PB_OLINK_DLY_0123_REG_FMR2_LINK_DELAY;
            l_bus_mode_sel_odd = PU_IOE_PB_OLINK_DLY_0123_REG_FMR3_LINK_DELAY;
            break;

        case (OBUS2):
            // If OBUS2 is not enabled throw an error
            FAPI_ASSERT(((l_x_attached_chip_cnfg[5] != 0) ||
                         (l_a_attached_chip_cnfg[2] != 0)),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(OBUS2),
                        "i_tod_node->i_bus_rx is set to OBUS2 and it is not enabled");
            l_bus_freq = i_freq_a;
            l_rt_delay_ctl_reg.setBit<PB_OLINK_RT_DELAY_CTL_SET_LINK_4>()
            .setBit<PB_OLINK_RT_DELAY_CTL_SET_LINK_5>();
            l_rt_delay_ctl_addr = PU_IOE_PB_OLINK_RT_DELAY_CTL_REG;
            l_bus_mode_addr = PU_IOE_PB_OLINK_DLY_4567_REG;
            l_bus_mode_sel_even = PU_IOE_PB_OLINK_DLY_4567_REG_FMR4_LINK_DELAY;
            l_bus_mode_sel_odd = PU_IOE_PB_OLINK_DLY_4567_REG_FMR5_LINK_DELAY;
            break;

        case (OBUS3):
            // If OBUS3 is not enabled throw an error
            FAPI_ASSERT(((l_x_attached_chip_cnfg[6] != 0) ||
                         (l_a_attached_chip_cnfg[3] != 0)),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(OBUS3),
                        "i_tod_node->i_bus_rx is set to OBUS3 and it is not enabled");
            l_bus_freq = i_freq_a;
            l_rt_delay_ctl_reg.setBit<PB_OLINK_RT_DELAY_CTL_SET_LINK_6>()
            .setBit<PB_OLINK_RT_DELAY_CTL_SET_LINK_7>();
            l_rt_delay_ctl_addr = PU_IOE_PB_OLINK_RT_DELAY_CTL_REG;
            l_bus_mode_addr = PU_IOE_PB_OLINK_DLY_4567_REG;
            l_bus_mode_sel_even = PU_IOE_PB_OLINK_DLY_4567_REG_FMR6_LINK_DELAY;
            l_bus_mode_sel_odd = PU_IOE_PB_OLINK_DLY_4567_REG_FMR7_LINK_DELAY;
            break;

        case (XBUS7):
            FAPI_ASSERT(false,
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(XBUS7),
                        "i_tod_node->i_bus_rx is set to XBUS7");
            break;

        case (NONE):
            FAPI_ASSERT((i_tod_node->i_bus_rx != NONE),
                        fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY_RX()
                        .set_TARGET(*(i_tod_node->i_target))
                        .set_RX(NONE),
                        "i_tod_node->i_bus_rx is set to NONE");
            break;
    }

    FAPI_TRY(fapi2::putScom(*(i_tod_node->i_target),
                            l_rt_delay_ctl_addr,
                            l_rt_delay_ctl_reg),
             "Error from putScom (0x%08X)!", l_rt_delay_ctl_addr);
    FAPI_TRY(fapi2::getScom(*(i_tod_node->i_target),
                            l_bus_mode_addr,
                            l_bus_mode_reg),
             "Error from getScom (0x%08X)!", l_bus_mode_addr);
    FAPI_TRY(l_bus_mode_reg.extractToRight(l_bus_delay_even,
                                           l_bus_mode_sel_even,
                                           // all counters are the same length
                                           PB_EOLINK_DLY_FMR_LINK_DELAY_LEN),
             "Error trying to extract delay (even)!");
    FAPI_TRY(l_bus_mode_reg.extractToRight(l_bus_delay_odd,
                                           l_bus_mode_sel_odd,
                                           // all counters are the same length
                                           PB_EOLINK_DLY_FMR_LINK_DELAY_LEN),
             "Error trying to extract delay (odd)!");

    l_bus_delay = (l_bus_delay_even + l_bus_delay_odd) / 2;

    // By default, the TOD grid runs at 400ps; TOD counts its delay based on this
    // Example: Bus round trip delay is 35 cycles and the bus is running at 4800MHz
    //            - Divide by 2 to get one-way delay time
    //            - Divide by 4800 * 10^6 to get delay in seconds
    //            - Multiply by 10^12 to get delay in picoseconds
    //            - Divide by 400ps to get TOD-grid-cycles
    //            - (To avoid including math.h) Add 1 and cast to uint32_t to round up to nearest TOD-grid-cycle
    //            - (To avoid including math.h) 10^12/10^6=1000000
    //            - (uint32_t)((         35        / 2 /        (4800        * 10^6) * 10^12 / 400        ) + 1) = 10 TOD-grid-cycles
    o_node_delay = (uint32_t)(((double)l_bus_delay / 2 / (double)l_bus_freq  * 1000000       / TOD_GRID_PS) + 1);

fapi_try_exit:
    // This is not the final internal path delay, only saved so two calls aren't needed to calculate_node_link_delay
    i_tod_node->o_int_path_delay = o_node_delay;

    FAPI_DBG("TOD-grid-cycles for single link: %d", o_node_delay);

    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Finds the longest delay in the topology (additionally sets each
///        node delay)
/// @param[in] i_tod_node Reference to TOD topology
/// @param[in] i_freq_x XBUS frequency in MHz
/// @param[in] i_freq_a OBUS frequency in MHz
/// @param[out] o_longest_delay Longest delay in TOD-grid-cycles
/// @return FAPI_RC_SUCCESS if a longest TOD delay was found in topology
///         else error
fapi2::ReturnCode calculate_longest_topolopy_delay(
    tod_topology_node* i_tod_node,
    const uint32_t i_freq_x,
    const uint32_t i_freq_a,
    uint32_t& o_longest_delay)
{
    uint32_t l_node_delay = 0;
    uint32_t l_current_longest_delay = 0;

    FAPI_DBG("Start");

    FAPI_TRY(calculate_node_link_delay(i_tod_node,
                                       i_freq_x,
                                       i_freq_a,
                                       l_node_delay),
             "Error from calculate_node_link_delay!");
    o_longest_delay = l_node_delay;

    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        tod_topology_node* l_tod_node = *l_child;
        FAPI_TRY(calculate_longest_topolopy_delay(l_tod_node,
                 i_freq_x,
                 i_freq_a,
                 l_node_delay),
                 "Error from calculate_longest_topology_delay!");

        if (l_node_delay > l_current_longest_delay)
        {
            l_current_longest_delay = l_node_delay;
        }
    }

    o_longest_delay += l_current_longest_delay;

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Updates the topology struct with the final delay values
/// @param[in] i_tod_node Reference to TOD topology
/// @param[in] i_freq_x  XBUS frequency in MHz
/// @param[in] i_freq_a  OBUS frequency in MHz
/// @param[in] i_longest_delay Longest delay in the topology
/// @return FAPI_RC_SUCCESS if o_int_path_delay was set for every node in the
///         topology else error
fapi2::ReturnCode set_topology_delays(
    tod_topology_node* i_tod_node,
    const uint32_t i_freq_x,
    const uint32_t i_freq_a,
    const uint32_t i_longest_delay)
{
    FAPI_DBG("Start");

    // Retrieve saved node_delay from calculate_node_link_delay instead of
    // making a second call
    i_tod_node->o_int_path_delay = i_longest_delay -
                                   (i_tod_node->o_int_path_delay);

    // Verify the delay is between 0 and 255 inclusive.
    FAPI_ASSERT((i_tod_node->o_int_path_delay >= MIN_TOD_DELAY &&
                 i_tod_node->o_int_path_delay <= MAX_TOD_DELAY),
                fapi2::P9_TOD_SETUP_INVALID_NODE_DELAY()
                .set_TARGET(i_tod_node->i_target)
                .set_PATH_DELAY(i_tod_node->o_int_path_delay)
                .set_LONGEST_DELAY(i_longest_delay)
                .set_XBUS_FREQ(i_freq_x)
                .set_OBUS_FREQ(i_freq_a),
                "Invalid delay of %d calculated!");

    // Recurse on downstream nodes
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(set_topology_delays(*l_child,
                                     i_freq_x,
                                     i_freq_a,
                                     i_tod_node->o_int_path_delay),
                 "Error from set_topology_delays!");
    }

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


/// @brief Calculates and populates the topology delays
/// @param[in] i_tod_node Reference to TOD topology
/// @return FAPI_RC_SUCCESS if TOD topology is successfully configured with
///         delays else error
fapi2::ReturnCode calculate_node_delays(tod_topology_node* i_tod_node)
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint32_t l_longest_delay = 0;
    uint32_t l_freq_x = 0;
    uint32_t l_freq_a = 0;

    FAPI_DBG("Start");
    // retrieve X-bus and A-bus frequencies
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_X_MHZ, FAPI_SYSTEM, l_freq_x),
             "Failure reading XBUS frequency attribute!");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_A_MHZ, FAPI_SYSTEM, l_freq_a),
             "Failure reading OBUS frequency attribute!");

    // multiply attribute (mesh speed) speed by link factor
    l_freq_x *= 8;
    l_freq_a *= 16;

    // Bus frequencies are global for the system (i.e. A0 and A1 will always
    //  run with the same frequency)
    FAPI_DBG("XBUS=%dMHz OBUS=%dMHz", l_freq_x, l_freq_a);

    // Find the most-delayed path in the topology; this is the MDMT's delay
    FAPI_TRY(calculate_longest_topolopy_delay(i_tod_node,
             l_freq_x,
             l_freq_a,
             l_longest_delay),
             "Error from calculate_longest_topology_delay!");
    FAPI_DBG("The longest delay is %d TOD-grid-cycles.", l_longest_delay);
    FAPI_TRY(set_topology_delays(i_tod_node,
                                 l_freq_x,
                                 l_freq_a,
                                 l_longest_delay),
             "Error from set_topology_delays!");

    // Finally, the MDMT delay must include additional TOD-grid-cycles to
    // account for staging latches in slaves
    i_tod_node->o_int_path_delay += MDMT_TOD_GRID_CYCLE_STAGING_DELAY;

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


// NOTE: description in header
fapi2::ReturnCode p9_tod_setup(
    tod_topology_node* i_tod_node,
    const p9_tod_setup_tod_sel i_tod_sel,
    const p9_tod_setup_osc_sel i_osc_sel)
{
    fapi2::ATTR_IS_MPIPL_Type l_is_mpipl = 0x00;

    FAPI_DBG("Entering ...\n");

    FAPI_ASSERT((i_tod_node != NULL) &&
                (i_tod_node->i_target != NULL),
                fapi2::P9_TOD_SETUP_NULL_NODE(),
                "Null node or target passed into function!");

    FAPI_ASSERT((i_tod_node->i_tod_master) &&
                (i_tod_node->i_drawer_master),
                fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY()
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
        // Put the TOD in reset state, and clear the register
        // PERV_TOD_PSS_MSS_CTRL_REG, we do it before the primary
        // topology is configured and not repeat it to prevent overwriting
        // the configuration.
        FAPI_TRY(mpipl_clear_tod_node(i_tod_node, i_tod_sel),
                 "Error from mpipl_clear_tod_node!");
    }

    // Start configuring each node
    // configure_tod_node will recurse on each child
    FAPI_TRY(calculate_node_delays(i_tod_node),
             "Error from calculate_node_delays!");

    display_tod_nodes(i_tod_node, 0);

    // If there is a previous topology, it needs to be cleared
    FAPI_TRY(clear_tod_node(i_tod_node, i_tod_sel, l_is_mpipl),
             "Error from clear_tod_node!");

    // Start configuring each node
    // configure_tod_node will recurse on each child
    FAPI_TRY(configure_tod_node(i_tod_node, i_tod_sel, i_osc_sel),
             "Error from configure_tod_node!");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}
