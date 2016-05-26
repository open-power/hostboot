/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_setup.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
// *HWP HWP Owner Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_tod_setup.H>

extern "C"
{

    //--------------------------------------------------------------------------
    //  HWP entry point
    //--------------------------------------------------------------------------
    fapi2::ReturnCode p9_tod_setup(
        tod_topology_node* i_tod_node,
        const p9_tod_setup_tod_sel i_tod_sel,
        const p9_tod_setup_osc_sel i_osc_sel)
    {
        fapi2::ATTR_IS_MPIPL_Type is_mpipl = 0x00;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        // mark HWP entry
        FAPI_DBG("Entering ...\n");

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

        FAPI_TRY(calculate_node_delays(i_tod_node), "Failure calculating TOD delays!");

        display_tod_nodes(i_tod_node, 0);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_MPIPL, FAPI_SYSTEM, is_mpipl),
                 "fapiGetAttribute of ATTR_IS_MPIPL failed!");

        // If there is a previous topology, it needs to be cleared
        FAPI_TRY(clear_tod_node(i_tod_node, i_tod_sel, is_mpipl),
                 "Failure clearing previous TOD configuration!");

        //Start configuring each node; (configure_tod_node will recurse on each child)
        FAPI_TRY(configure_tod_node(i_tod_node, i_tod_sel, i_osc_sel), "Failure configuring TOD!");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode clear_tod_node(tod_topology_node*             i_tod_node,
                                     const p9_tod_setup_tod_sel   i_tod_sel,
                                     const fapi2::ATTR_IS_MPIPL_Type i_is_mpipl)
    {
        fapi2::buffer<uint64_t> data(0x0);
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;
        uint32_t port_ctrl_reg = 0;
        uint32_t port_ctrl_check_reg = 0;
        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];

        fapi2::toString(target, l_targetStr, fapi2::MAX_ECMD_STRING_LEN);
        FAPI_INF("Clearing previous %s topology from %s",
                 (i_tod_sel == TOD_PRIMARY) ? "Primary" : "Secondary", l_targetStr);

        if (i_tod_sel == TOD_PRIMARY)
        {
            FAPI_DBG("PERV_TOD_PRI_PORT_0_CTRL_REG and PERV_TOD_SEC_PORT_0_CTRL_REG will be cleared.");
            port_ctrl_reg = PERV_TOD_PRI_PORT_0_CTRL_REG;
            port_ctrl_check_reg = PERV_TOD_SEC_PORT_0_CTRL_REG;
        }
        else // (i_tod_sel==TOD_SECONDARY)
        {
            FAPI_DBG("PERV_TOD_PRI_PORT_1_CTRL_REG and PERV_TOD_SEC_PORT_1_CTRL_REG will be cleared.");
            port_ctrl_reg = PERV_TOD_SEC_PORT_1_CTRL_REG;
            port_ctrl_check_reg = PERV_TOD_PRI_PORT_1_CTRL_REG;
        }

        FAPI_TRY(fapi2::putScom(*target, port_ctrl_reg, data), "fapiPutScom error for port_ctrl_reg SCOM.");
        FAPI_TRY(fapi2::putScom(*target, port_ctrl_check_reg, data),
                 "fapiPutScom error for port_ctrl_check_reg SCOM.");

        if (i_is_mpipl)
        {
            FAPI_INF("MPIPL: switch TOD to 'Not Set' state");
            data.flush<0>();

            // Generate TType#5 (formats defined in section "TType Fabric Interface" in the TOD workbook)
            data.setBit<5>().setBit<56>();
            FAPI_TRY(fapi2::putScom(*target, PERV_TOD_RX_TTYPE_CTRL_REG, data),
                     "Could not write PERV_TOD_RX_TTYPE_CTRL_REG");

            FAPI_INF("MPIPL: switch all other TODs to 'Not Set' state");
            data.flush<0>().setBit<PERV_TOD_TX_TTYPE_5_REG_TRIGGER>();
            FAPI_TRY(fapi2::putScom(*target, PERV_TOD_TX_TTYPE_5_REG, data),
                     "Could not write PERV_TOD_TX_TTYPE_5_REG");
        }
        else
        {
            FAPI_INF("Normal IPL: Bypass TTYPE#5");
        }

        // TOD is cleared for this node; if it has children, start clearing their registers
        for (std::list<tod_topology_node*>::iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            FAPI_TRY(clear_tod_node(tod_node, i_tod_sel, i_is_mpipl), "Failure clearing downstream TOD node!");
        }

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode configure_tod_node(tod_topology_node*           i_tod_node,
                                         const p9_tod_setup_tod_sel i_tod_sel,
                                         const p9_tod_setup_osc_sel i_osc_sel)
    {
        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;

        fapi2::toString(target, l_targetStr, fapi2::MAX_ECMD_STRING_LEN);
        FAPI_DBG("Start: Configuring %s", l_targetStr);

        const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);

        FAPI_TRY(configure_pss_mss_ctrl_reg(i_tod_node, i_tod_sel, i_osc_sel), "Failure configuring pss_mss_ctrl_reg");

        if (!is_mdmt)
        {
            FAPI_TRY(configure_s_path_ctrl_reg(i_tod_node, i_tod_sel, i_osc_sel), "Failure configuring s_path_ctrl_reg");
        }

        FAPI_TRY(configure_port_ctrl_regs(i_tod_node, i_tod_sel, i_osc_sel), "Failure configuring port_ctrl_regs");

        if (is_mdmt)
        {
            FAPI_TRY(configure_m_path_ctrl_reg(i_tod_node, i_tod_sel, i_osc_sel), "Failure configuring m_path_ctrl_reg");
        }

        FAPI_TRY(configure_i_path_ctrl_reg(i_tod_node, i_tod_sel, i_osc_sel), "Failure configuring i_path_ctrl_reg");

        FAPI_TRY(init_chip_ctrl_reg(i_tod_node, i_tod_sel, i_osc_sel), "Failure configuring init_chip_ctrl_reg");

        // TOD is configured for this node; if it has children, start their configuration
        for (std::list<tod_topology_node*>::iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            FAPI_TRY(configure_tod_node(tod_node, i_tod_sel, i_osc_sel),
                     "Failure configuring downstream node!");
        }

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode configure_pss_mss_ctrl_reg(tod_topology_node*           i_tod_node,
            const p9_tod_setup_tod_sel i_tod_sel,
            const p9_tod_setup_osc_sel i_osc_sel)
    {
        fapi2::buffer<uint64_t> data(0x0);

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;

        FAPI_DBG("Start");

        const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);

        // Read PERV_TOD_PSS_MSS_CTRL_REG in order to perserve any prior configuration
        FAPI_TRY(fapi2::getScom(*target, PERV_TOD_PSS_MSS_CTRL_REG, data),
                 "Error from fapiGetScom when retrieving PERV_TOD_PSS_MSS_CTRL_REG!");
        FAPI_DBG("Set Master TOD/Slave TOD and Master Drawer/Slave Drawer");

        if (i_tod_sel == TOD_PRIMARY)
        {
            if (is_mdmt)
            {
                data.setBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_S_SELECT>();

                if (i_osc_sel == TOD_OSC_0             ||
                    i_osc_sel == TOD_OSC_0_AND_1       ||
                    i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
                {
                    data.clearBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT>();
                }
                else if (i_osc_sel == TOD_OSC_1        ||
                         i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
                {
                    data.setBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT>();
                }

                FAPI_ASSERT(i_osc_sel != TOD_OSC_NONE, fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY().set_TARGET(target).set_OSCSEL(i_osc_sel),
                            "Invalid oscillator configuration!");
            }
            else // Slave nodes (Drawer master is still a slave)
            {
                data.clearBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_S_SELECT>();
            }

            if (i_tod_node->i_drawer_master)
            {
                data.setBit<PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT>();
            }
        }
        else // (i_tod_sel==TOD_SECONDARY)
        {
            if (is_mdmt)
            {
                data.setBit<PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_S_SELECT>();

                if (i_osc_sel == TOD_OSC_1       ||
                    i_osc_sel == TOD_OSC_0_AND_1 ||
                    i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
                {
                    data.setBit<PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT>();
                }
                else if (i_osc_sel == TOD_OSC_0  ||
                         i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
                {
                    data.clearBit<PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT>();
                }

                FAPI_ASSERT(i_osc_sel != TOD_OSC_NONE, fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY().set_TARGET(target).set_OSCSEL(i_osc_sel),
                            "Invalid oscillator configuration!");
            }
            else // Slave nodes (Drawer master is still a slave)
            {
                data.clearBit<PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_S_SELECT>();
            }

            if (i_tod_node->i_drawer_master)
            {
                data.setBit<PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT>();
            }
        }

        FAPI_TRY(fapi2::putScom(*target, PERV_TOD_PSS_MSS_CTRL_REG, data),
                 "fapiPutScom error for PERV_TOD_PSS_MSS_CTRL_REG SCOM.");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode configure_s_path_ctrl_reg(tod_topology_node*           i_tod_node,
            const p9_tod_setup_tod_sel i_tod_sel,
            const p9_tod_setup_osc_sel i_osc_sel)
    {
        fapi2::buffer<uint64_t> data(0x0);

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;

        // Read PERV_TOD_S_PATH_CTRL_REG in order to perserve any prior configuration
        FAPI_TRY(fapi2::getScom(*target, PERV_TOD_S_PATH_CTRL_REG, data),
                 "Error from fapiGetScom when retrieving PERV_TOD_S_PATH_CTRL_REG!");

        // Slave TODs are enabled on all but the MDMT
        FAPI_DBG("Selection of Slave OSC path");

        if (i_tod_sel == TOD_PRIMARY)
        {
            data.clearBit<PERV_TOD_S_PATH_CTRL_REG_PRI_SELECT>(); // For primary slave, use slave path 0 (path_0_sel=OFF)

            // Set CPS deviation to 75% (CPS deviation bits = 0xC, factor=1), 8 valid steps to enable step check
            data.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
                                 PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(STEP_CHECK_CPS_DEVIATION_FACTOR_1);
            data.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION,
                                 PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN>(STEP_CHECK_CPS_DEVIATION_75_00_PCENT);
            data.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT,
                                 PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN>(STEP_CHECK_VALIDITY_COUNT_8);
        }
        else // (i_tod_sel==TOD_SECONDARY)
        {
            data.setBit<PERV_TOD_S_PATH_CTRL_REG_SEC_SELECT>();   // For secondary slave, use slave path 1 (path_1_sel=ON)

            // Set CPS deviation to 75% (CPS deviation bits = 0xC, factor=1), 8 valid steps to enable step check
            data.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
                                 PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(STEP_CHECK_CPS_DEVIATION_FACTOR_1);
            data.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION,
                                 PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN>(STEP_CHECK_CPS_DEVIATION_75_00_PCENT);
            data.insertFromRight<PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT,
                                 PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN>(STEP_CHECK_VALIDITY_COUNT_8);
        }

        FAPI_TRY(fapi2::putScom(*target, PERV_TOD_S_PATH_CTRL_REG, data),
                 "fapiPutScom error for PERV_TOD_S_PATH_CTRL_REG SCOM.");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode configure_port_ctrl_regs(tod_topology_node*           i_tod_node,
            const p9_tod_setup_tod_sel i_tod_sel,
            const p9_tod_setup_osc_sel i_osc_sel)
    {
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;
        fapi2::buffer<uint64_t> data(0x0);
        fapi2::buffer<uint64_t> data2(0x0);
        uint32_t port_ctrl_reg = 0;
        uint32_t port_ctrl_check_reg = 0;
        uint32_t port_rx_select_val = 0;
        uint32_t path_sel = 0;

        const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);

        // PERV_TOD_PRI_PORT_0_CTRL_REG is only used for Primary configurations
        // PERV_TOD_SEC_PORT_1_CTRL_REG is only used for Secondary configurations
        // In order to check primary and secondary networks are working simultaneously...
        //  - The result of PERV_TOD_PRI_PORT_0_CTRL_REG are also inserted into PERV_TOD_SEC_PORT_0_CTRL_REG
        //    (preserving i_path_delay which can be different between 40001 and 40003)
        //  - The result of PERV_TOD_SEC_PORT_1_CTRL_REG are also inserted into PERV_TOD_PRI_PORT_1_CTRL_REG
        if (i_tod_sel == TOD_PRIMARY)
        {
            FAPI_DBG("PERV_TOD_PRI_PORT_0_CTRL_REG will be configured for primary topology");
            port_ctrl_reg = PERV_TOD_PRI_PORT_0_CTRL_REG;
            port_ctrl_check_reg = PERV_TOD_SEC_PORT_0_CTRL_REG;
        }
        else // (i_tod_sel==TOD_SECONDARY)
        {
            FAPI_DBG("PERV_TOD_SEC_PORT_1_CTRL_REG will be configured for secondary topology");
            port_ctrl_reg = PERV_TOD_SEC_PORT_1_CTRL_REG;
            port_ctrl_check_reg = PERV_TOD_PRI_PORT_1_CTRL_REG;
        }

        // Read port_ctrl_reg in order to perserve any prior configuration
        FAPI_TRY(fapi2::getScom(*target, port_ctrl_reg, data),
                 "Error from fapiGetScom when retrieving port_ctrl_reg!");

        // Read port_ctrl_check_reg in order to perserve any prior configuration
        FAPI_TRY(fapi2::getScom(*target, port_ctrl_check_reg, data2),
                 "Error from fapiGetScom when retrieving port_ctrl_check_reg!");

        //Determine RX port
        switch (i_tod_node->i_bus_rx)
        {
            case(XBUS0):
                port_rx_select_val = TOD_PORT_CTRL_REG_RX_X0_SEL;
                break;

            case(XBUS1):
                port_rx_select_val = TOD_PORT_CTRL_REG_RX_X1_SEL;
                break;

            case(XBUS2):
                port_rx_select_val = TOD_PORT_CTRL_REG_RX_X2_SEL;
                break;

            case(XBUS3):
                port_rx_select_val = TOD_PORT_CTRL_REG_RX_X3_SEL;
                break;

            case(XBUS4):
                port_rx_select_val = TOD_PORT_CTRL_REG_RX_X4_SEL;
                break;

            case(XBUS5):
                port_rx_select_val = TOD_PORT_CTRL_REG_RX_X5_SEL;
                break;

            case(XBUS6):
                port_rx_select_val = TOD_PORT_CTRL_REG_RX_X6_SEL;
                break;

            case(XBUS7):
                port_rx_select_val = TOD_PORT_CTRL_REG_RX_X7_SEL;
                break;

            case(NONE):
                break; //MDMT has no rx
        }

        data.insertFromRight<TOD_PORT_CTRL_REG_RX_SEL,
                             TOD_PORT_CTRL_REG_RX_LEN>(port_rx_select_val);
        data2.insertFromRight<TOD_PORT_CTRL_REG_RX_SEL,
                              TOD_PORT_CTRL_REG_RX_LEN>(port_rx_select_val);

        //Determine which tx path should be selected for all children
        if (is_mdmt)
        {
            if (i_tod_sel == TOD_PRIMARY)
            {
                if (i_osc_sel == TOD_OSC_0       ||
                    i_osc_sel == TOD_OSC_0_AND_1 ||
                    i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
                {
                    path_sel = TOD_PORT_CTRL_REG_M_PATH_0;
                }
                else if (i_osc_sel == TOD_OSC_1  ||
                         i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
                {
                    path_sel = TOD_PORT_CTRL_REG_M_PATH_1;
                }

                FAPI_ASSERT(i_osc_sel != TOD_OSC_NONE, fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY().set_TARGET(target).set_OSCSEL(i_osc_sel),
                            "Invalid oscillator configuration!");
            }
            else // i_tod_sel==TOD_SECONDARY
            {
                if (i_osc_sel == TOD_OSC_1       ||
                    i_osc_sel == TOD_OSC_0_AND_1 ||
                    i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
                {
                    path_sel = TOD_PORT_CTRL_REG_M_PATH_1;
                }
                else if (i_osc_sel == TOD_OSC_0  ||
                         i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
                {
                    path_sel = TOD_PORT_CTRL_REG_M_PATH_0;
                }

                FAPI_ASSERT(i_osc_sel != TOD_OSC_NONE, fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY().set_TARGET(target).set_OSCSEL(i_osc_sel),
                            "Invalid oscillator configuration!");
            }
        }
        else // Chip is not master; slave path selected
        {
            if (i_tod_sel == TOD_PRIMARY)
            {
                path_sel = TOD_PORT_CTRL_REG_S_PATH_0;
            }
            else // (i_tod_sel==TOD_SECONDARY)
            {
                path_sel = TOD_PORT_CTRL_REG_S_PATH_1;
            }
        }

        for (std::list<tod_topology_node*>::iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            // Loop through all of the out busses, determine which tx buses to enable as senders
            tod_topology_node* tod_node = *child;

            switch (tod_node->i_bus_tx)
            {
                case(XBUS0):
                    data.insertFromRight<TOD_PORT_CTRL_REG_TX_X0_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data.setBit<TOD_PORT_CTRL_REG_TX_X0_EN>();
                    data2.insertFromRight<TOD_PORT_CTRL_REG_TX_X0_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data2.setBit<TOD_PORT_CTRL_REG_TX_X0_EN>();
                    break;

                case(XBUS1):
                    data.insertFromRight<TOD_PORT_CTRL_REG_TX_X1_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data.setBit<TOD_PORT_CTRL_REG_TX_X1_EN>();
                    data2.insertFromRight<TOD_PORT_CTRL_REG_TX_X1_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data2.setBit<TOD_PORT_CTRL_REG_TX_X1_EN>();
                    break;

                case(XBUS2):
                    data.insertFromRight<TOD_PORT_CTRL_REG_TX_X2_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data.setBit<TOD_PORT_CTRL_REG_TX_X2_EN>();
                    data2.insertFromRight<TOD_PORT_CTRL_REG_TX_X2_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data2.setBit<TOD_PORT_CTRL_REG_TX_X2_EN>();
                    break;

                case(XBUS3):
                    data.insertFromRight<TOD_PORT_CTRL_REG_TX_X3_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data.setBit<TOD_PORT_CTRL_REG_TX_X3_EN>();
                    data2.insertFromRight<TOD_PORT_CTRL_REG_TX_X3_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data2.setBit<TOD_PORT_CTRL_REG_TX_X3_EN>();
                    break;

                case(XBUS4):
                    data.insertFromRight<TOD_PORT_CTRL_REG_TX_X4_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data.setBit<TOD_PORT_CTRL_REG_TX_X4_EN>();
                    data2.insertFromRight<TOD_PORT_CTRL_REG_TX_X4_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data2.setBit<TOD_PORT_CTRL_REG_TX_X4_EN>();
                    break;

                case(XBUS5):
                    data.insertFromRight<TOD_PORT_CTRL_REG_TX_X5_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data.setBit<TOD_PORT_CTRL_REG_TX_X5_EN>();
                    data2.insertFromRight<TOD_PORT_CTRL_REG_TX_X5_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data2.setBit<TOD_PORT_CTRL_REG_TX_X5_EN>();
                    break;

                case(XBUS6):
                    data.insertFromRight<TOD_PORT_CTRL_REG_TX_X6_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data.setBit<TOD_PORT_CTRL_REG_TX_X6_EN>();
                    data2.insertFromRight<TOD_PORT_CTRL_REG_TX_X6_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data2.setBit<TOD_PORT_CTRL_REG_TX_X6_EN>();
                    break;

                case(XBUS7):
                    data.insertFromRight<TOD_PORT_CTRL_REG_TX_X7_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data.setBit<TOD_PORT_CTRL_REG_TX_X7_EN>();
                    data2.insertFromRight<TOD_PORT_CTRL_REG_TX_X7_SEL, TOD_PORT_CTRL_REG_TX_LEN>(path_sel);
                    data2.setBit<TOD_PORT_CTRL_REG_TX_X7_EN>();
                    break;

                case(NONE):
                    FAPI_ASSERT((tod_node->i_bus_tx != NONE),
                                fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY().set_TARGET(target).set_OSCSEL(i_osc_sel), "i_tod_node->i_bus_rx is set to NONE");
                    break;
            }
        }

        // All children have been configured; save both port configurations!
        FAPI_TRY(fapi2::putScom(*target, port_ctrl_reg, data), "fapiPutScom error for port_ctrl_reg SCOM.");
        FAPI_TRY(fapi2::putScom(*target, port_ctrl_check_reg, data2),
                 "fapiPutScom error for port_ctrl_check_reg SCOM.");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode configure_m_path_ctrl_reg(tod_topology_node*           i_tod_node,
            const p9_tod_setup_tod_sel i_tod_sel,
            const p9_tod_setup_osc_sel i_osc_sel)
    {
        fapi2::buffer<uint64_t> data(0x0);

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;

        // Read PERV_TOD_M_PATH_CTRL_REG in order to perserve any prior configuration
        FAPI_TRY(fapi2::getScom(*target, PERV_TOD_M_PATH_CTRL_REG, data),
                 "Error from fapiGetScom when retrieving PERV_TOD_M_PATH_CTRL_REG!");

        // Configure Master OSC0/OSC1 path
        FAPI_DBG("Configuring Master OSC path in PERV_TOD_M_PATH_CTRL_REG");

        if (i_osc_sel == TOD_OSC_0             ||
            i_osc_sel == TOD_OSC_0_AND_1       ||
            i_osc_sel == TOD_OSC_0_AND_1_SEL_0 ||
            i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
        {
            FAPI_DBG("OSC0 is valid; master path-0 will be configured.");

            // OSC0 is connected
            data.clearBit<PERV_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID>();

            // OSC0 step alignment enabled
            data.clearBit<PERV_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE>();

            // Set 512 steps per sync for path 0
            data.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT,
                                 PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT_LEN>(TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_512);

            // Set step check CPS deviation to 50%
            data.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION,
                                 PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN>(STEP_CHECK_CPS_DEVIATION_50_00_PCENT);

            // 8 valid steps are required before step check is enabled
            data.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT,
                                 PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN>(STEP_CHECK_VALIDITY_COUNT_8);
        }
        else
        {
            FAPI_DBG("OSC0 is not connected.");

            // OSC0 is not connected; any previous path-0 settings will be ignored
            data.setBit<PERV_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID>();
        }

        if (i_osc_sel == TOD_OSC_1             ||
            i_osc_sel == TOD_OSC_0_AND_1       ||
            i_osc_sel == TOD_OSC_0_AND_1_SEL_0 ||
            i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
        {
            FAPI_DBG("OSC1 is valid; master path-1 will be configured.");

            // OSC1 is connected
            data.clearBit<PERV_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID>();

            // OSC1 step alignment enabled
            data.clearBit<PERV_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE>();

            // Set 512 steps per sync for path 1
            data.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT,
                                 PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT_LEN>(TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_512);

            // Set step check CPS deviation to 50%
            data.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION,
                                 PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN>(STEP_CHECK_CPS_DEVIATION_50_00_PCENT);

            // 8 valid steps are required before step check is enabled
            data.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT,
                                 PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN>(STEP_CHECK_VALIDITY_COUNT_8);
        }
        else
        {
            FAPI_DBG("OSC1 is not connected.");

            // OSC1 is not connected; any previous path-1 settings will be ignored
            data.setBit<PERV_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID>();
        }

        // CPS deviation factor configures both path-0 and path-1
        data.insertFromRight<PERV_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
                             PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(STEP_CHECK_CPS_DEVIATION_FACTOR_1);

        FAPI_TRY(fapi2::putScom(*target, PERV_TOD_M_PATH_CTRL_REG, data),
                 "fapiPutScom error for PERV_TOD_M_PATH_CTRL_REG SCOM.");



    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode configure_i_path_ctrl_reg(tod_topology_node*           i_tod_node,
            const p9_tod_setup_tod_sel i_tod_sel,
            const p9_tod_setup_osc_sel i_osc_sel)
    {
        fapi2::buffer<uint64_t> data(0x0);
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;
        uint32_t port_ctrl_reg = 0;

        FAPI_DBG("Setting internal path delay");

        // This is the number of TOD-grid-cycles to delay the internal path (0-0xFF valid); 1 TOD-grid-cycle = 400ps (default)
        if (i_tod_sel == TOD_PRIMARY)
        {
            // Primary topology internal path delay set PERV_TOD_PRI_PORT_0_CTRL_REG, regardless of master/slave/port
            FAPI_DBG("PERV_TOD_PRI_PORT_0_CTRL_REG will be used to set internal delay");
            port_ctrl_reg = PERV_TOD_PRI_PORT_0_CTRL_REG;
        }
        else // (i_tod_sel==TOD_SECONDARY)
        {
            // Secondary topology internal path delay set PERV_TOD_SEC_PORT_0_CTRL_REG regardless of master/slave/port
            FAPI_DBG("PERV_TOD_SEC_PORT_0_CTRL_REG will be used to set internal delay");
            port_ctrl_reg = PERV_TOD_SEC_PORT_0_CTRL_REG;
        }

        FAPI_TRY(fapi2::getScom(*target, port_ctrl_reg, data),
                 "Error from fapiGetScom when retrieving port_ctrl_reg!");
        FAPI_DBG("configuring an internal delay of %d TOD-grid-cycles", i_tod_node->o_int_path_delay);
        data.insertFromRight<TOD_PORT_CTRL_REG_I_PATH_DELAY,
                             TOD_PORT_CTRL_REG_I_PATH_DELAY_LEN>(i_tod_node->o_int_path_delay);
        FAPI_TRY(fapi2::putScom(*target, port_ctrl_reg, data), "fapiPutScom error for port_ctrl_reg SCOM.");

        FAPI_DBG("Enable delay logic in PERV_TOD_I_PATH_CTRL_REG");
        // Read PERV_TOD_I_PATH_CTRL_REG in order to perserve any prior configuration
        FAPI_TRY(fapi2::getScom(*target, PERV_TOD_I_PATH_CTRL_REG, data),
                 "Error from fapiGetScom when retrieving PERV_TOD_I_PATH_CTRL_REG!");

        // Ensure delay is enabled
        data.clearBit<PERV_TOD_I_PATH_CTRL_REG_DELAY_DISABLE>();
        data.clearBit<PERV_TOD_I_PATH_CTRL_REG_DELAY_ADJUST_DISABLE>();

        // Deviation for internal OSC should be set to max, allowing backup master TOD to run the active topology,
        // when switching from Slave OSC path to Master OSC path
        data.insertFromRight<PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION,
                             PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_LEN>(STEP_CHECK_CPS_DEVIATION_93_75_PCENT);
        data.insertFromRight<PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
                             PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(STEP_CHECK_CPS_DEVIATION_FACTOR_1);
        data.insertFromRight<PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_VALIDITY_COUNT,
                             PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN>(STEP_CHECK_VALIDITY_COUNT_8);
        FAPI_TRY(fapi2::putScom(*target, PERV_TOD_I_PATH_CTRL_REG, data),
                 "fapiPutScom error for PERV_TOD_I_PATH_CTRL_REG SCOM.");
    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    // NOTE: description in header
    //---------------------------------------------------------------------------------
    void display_tod_nodes(const tod_topology_node* i_tod_node, const uint32_t i_depth)
    {
        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];

        if (i_tod_node == NULL || i_tod_node->i_target == NULL)
        {
            FAPI_ERR("NULL tod_node or target passed to display_tod_nodes()!");
        }


        fapi2::toString(i_tod_node->i_target, l_targetStr, fapi2::MAX_ECMD_STRING_LEN);
        FAPI_INF("%s (Delay = %d)", l_targetStr, i_tod_node->o_int_path_delay);

        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            display_tod_nodes(*child, i_depth + 1);
        }
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode calculate_node_delays(tod_topology_node* i_tod_node)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::buffer<uint64_t> data(0x0);
        uint32_t longest_delay = 0;
        uint32_t freq_x = 0;
        uint32_t freq_a = 0;


        FAPI_DBG("Start");
        // retrieve X-bus and A-bus frequencies
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_X_MHZ, FAPI_SYSTEM, freq_x),
                 "Failure reading XBUS frequency attribute!");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_A_MHZ, FAPI_SYSTEM, freq_a),
                 "Failure reading ABUS frequency attribute!");

        // Bus frequencies are global for the system (i.e. A0 and A1 will always run with the same frequency)
        FAPI_DBG("XBUS=%dMHz ABUS=%dMHz", freq_x, freq_a);

        // Find the most-delayed path in the topology; this is the MDMT's delay
        FAPI_TRY(calculate_longest_topolopy_delay(i_tod_node, freq_x, freq_a, longest_delay),
                 "Failure calculating longest topology delay!");
        FAPI_DBG("the longest delay is %d TOD-grid-cycles.", longest_delay);

        FAPI_TRY(set_topology_delays(i_tod_node, freq_x, freq_a, longest_delay),
                 "Unable to set topology delays!");

        // Finally, the MDMT delay must include additional TOD-grid-cycles to account for staging latches in slaves
        i_tod_node->o_int_path_delay += MDMT_TOD_GRID_CYCLE_STAGING_DELAY;

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode calculate_longest_topolopy_delay(tod_topology_node* i_tod_node,
            const uint32_t     i_freq_x,
            const uint32_t     i_freq_a,
            uint32_t&          o_longest_delay)
    {
        uint32_t node_delay = 0;
        uint32_t current_longest_delay = 0;

        FAPI_DBG("Start");

        FAPI_TRY(calculate_node_link_delay(i_tod_node, i_freq_x, i_freq_a, node_delay),
                 "Failure calculating single node delay!");
        o_longest_delay = node_delay;

        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            FAPI_TRY(calculate_longest_topolopy_delay(tod_node, i_freq_x, i_freq_a, node_delay),
                     "Failure calculating topology delay!");

            if (node_delay > current_longest_delay)
            {
                current_longest_delay = node_delay;
            }
        }

        o_longest_delay += current_longest_delay;

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode calculate_node_link_delay(tod_topology_node* i_tod_node,
            const uint32_t     i_freq_x,
            const uint32_t     i_freq_a,
            uint32_t&          o_node_delay)
    {
        fapi2::buffer<uint64_t> data(0x0);
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;

        FAPI_DBG("Start");

        // MDMT is originator and therefore has no node delay
        if (i_tod_node->i_tod_master && i_tod_node->i_drawer_master)
        {
            o_node_delay = 0;
        }
        else // slave node
        {
            uint32_t bus_mode_addr = 0;
            //uint32_t bus_mode_sel = 0;
            uint32_t bus_freq = 0;
            uint8_t  bus_delay = 0;

            switch (i_tod_node->i_bus_rx)
            {
                case(XBUS0):
                    bus_freq = i_freq_x; /*bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X0_ROUND_TRIP_DELAY;*/ break;

                case(XBUS1):
                    bus_freq = i_freq_x; /*bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X1_ROUND_TRIP_DELAY;*/ break;

                case(XBUS2):
                    bus_freq = i_freq_x; /*bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X2_ROUND_TRIP_DELAY;*/ break;

                case(XBUS3):
                    bus_freq = i_freq_x; /*bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X3_ROUND_TRIP_DELAY;*/ break;

                case(XBUS4):
                    bus_freq = i_freq_x; /*bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X4_ROUND_TRIP_DELAY;*/ break;

                case(XBUS5):
                    bus_freq = i_freq_x; /*bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X5_ROUND_TRIP_DELAY;*/ break;

                case(XBUS6):
                    bus_freq = i_freq_x; /*bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X6_ROUND_TRIP_DELAY;*/ break;

                case(XBUS7):
                    bus_freq = i_freq_x; /*bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X7_ROUND_TRIP_DELAY;*/ break;

                case(NONE):
                    FAPI_ASSERT((i_tod_node->i_bus_rx != NONE),
                                fapi2::P9_TOD_SETUP_INVALID_TOPOLOGY().set_TARGET(target).set_OSCSEL(i_freq_x), "i_tod_node->i_bus_rx is set to NONE");
                    break;
            }

            FAPI_TRY(fapi2::getScom(*target, bus_mode_addr, data),
                     "Error from fapiGetScom when retrieving bus_mode_addr!");
            //TODO Figure out where LINK_ROUND_TRIP_DELAY_LEN is coming from data.extract(&bus_delay, bus_mode_sel, LINK_ROUND_TRIP_DELAY_LEN);

            // By default, the TOD grid runs at 400ps; TOD counts its delay based on this
            // Example: Bus round trip delay is 35 cycles and the bus is running at 4800MHz
            //            - Divide by 2 to get one-way delay time
            //            - Divide by 4800 * 10^6 to get delay in seconds
            //            - Multiply by 10^12 to get delay in picoseconds
            //            - Divide by 400ps to get TOD-grid-cycles
            //            - (To avoid including math.h) Add 1 and cast to uint32_t to round up to nearest TOD-grid-cycle
            //            - (To avoid including math.h) 10^12/10^6=1000000
            //            - (uint32_t)((        35        / 2 /        (4800      * 10^6) * 10^12 / 400        ) + 1) = 10 TOD-grid-cycles
            o_node_delay = (uint32_t)(((double)bus_delay / 2 / (double)bus_freq  * 1000000       / TOD_GRID_PS) + 1);
        }

        // This is not the final internal path delay, only saved so two calls aren't needed to calculate_node_link_delay
        i_tod_node->o_int_path_delay = o_node_delay;

        FAPI_DBG("TOD-grid-cycles for single link: %d", o_node_delay);

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode set_topology_delays(tod_topology_node* i_tod_node,
                                          const uint32_t     i_freq_x,
                                          const uint32_t     i_freq_a,
                                          const uint32_t     i_longest_delay)
    {
        FAPI_DBG("Start");

        // Retrieve saved node_delay from calculate_node_link_delay instead of making a second call
        i_tod_node->o_int_path_delay = i_longest_delay - (i_tod_node->o_int_path_delay);

        // Verify the delay is between 0 and 255 inclusive.
        FAPI_ASSERT((i_tod_node->o_int_path_delay >= MIN_TOD_DELAY &&
                     i_tod_node->o_int_path_delay <= MAX_TOD_DELAY),
                    fapi2::P9_TOD_SETUP_INVALID_NODE_DELAY().set_TARGET(i_tod_node->i_target).set_DELAY(i_tod_node->o_int_path_delay),
                    "Invalid delay of %d calculated!");

        // Recurse on downstream nodes
        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            FAPI_TRY(set_topology_delays(tod_node, i_freq_x, i_freq_a, i_tod_node->o_int_path_delay),
                     "Failure calculating topology delay!");
        }

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode init_chip_ctrl_reg (tod_topology_node*           i_tod_node,
                                          const p9_tod_setup_tod_sel i_tod_sel,
                                          const p9_tod_setup_osc_sel i_osc_sel)
    {
        fapi2::buffer<uint64_t> chic_ctrlReg_val(0x0);

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target = i_tod_node->i_target;

        FAPI_DBG("Start");

        FAPI_DBG("Set low order step value to 3F in PERV_TOD_CHIP_CTRL_REG");
        // Read PERV_TOD_CHIP_CTRL_REG in order to perserve any prior configuration
        FAPI_TRY(fapi2::getScom(*target, PERV_TOD_CHIP_CTRL_REG, chic_ctrlReg_val),
                 "Error from fapiGetScom when retrieving PERV_TOD_CHIP_CTRL_REG!");

        // Default core sync period is 8us
        chic_ctrlReg_val.insertFromRight<PERV_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT,
                                         PERV_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT_LEN>(TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_8);

        // Enable internal path sync check
        chic_ctrlReg_val.clearBit<PERV_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE>();

        // 1x sync boundaries for Move-TOD-To-Timebase
        chic_ctrlReg_val.clearBit<PERV_TOD_CHIP_CTRL_REG_MOVE_TO_TB_ON_2X_SYNC_ENABLE>();

        // Use eclipz sync mechanism
        chic_ctrlReg_val.clearBit<PERV_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM>();

        // Use timebase step sync from internal path
        chic_ctrlReg_val.clearBit<PERV_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC>();

        // Chip TOD WOF incrementer ratio (eclipz mode)
        // 4-bit WOF counter is incremented with each 200MHz clock cycle
        chic_ctrlReg_val.insertFromRight<PERV_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE,
                                         PERV_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE_LEN>(TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_3F);

        // Stop TOD when system checkstop occurs
        chic_ctrlReg_val.clearBit<PERV_TOD_CHIP_CTRL_REG_XSTOP_GATE>();

        FAPI_TRY(fapi2::putScom(*target, PERV_TOD_CHIP_CTRL_REG, chic_ctrlReg_val),
                 "fapiPutScom error for PERV_TOD_CHIP_CTRL_REG SCOM.");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

} // extern "C"
