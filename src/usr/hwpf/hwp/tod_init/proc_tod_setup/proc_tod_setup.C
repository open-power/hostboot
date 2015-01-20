/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_setup/proc_tod_setup.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
// $Id: proc_tod_setup.C,v 1.23 2015/01/08 19:50:38 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *!
// *! TITLE : proc_tod_setup.C
// *!
// *! DESCRIPTION : Configures the TOD topology
// *!
// *! OWNER NAME  : Nick Klazynski  Email: jklazyns@us.ibm.com
// *! BACKUP NAME :                 Email:
// *!
// *! ADDITIONAL COMMENTS :
// *!  Procedure implemented:
// *!   - First, configure topology delays
// *!     - The longest delay (node furthest away) needs to be found first.  This will
// *!       be the MDMT's delay and the children will be derived from this.  The node
// *!       that's furthest away should have a delay of 0 (step as soon as signal is
// *!       received
// *!   - Next, configure TOD registers based on pervasive workbook (section 17.8)
// *!     - Primary and Secondary topologies are configured in a similar manner
// *!       with different registers.  This code attempts to use common code to
// *!       implement this.
// *!   - Initialization is required (pervasive workbook 17.8.3.1) in order to verify
// *!     the topology is correctly configured
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_tod_setup.H"
#include "p8_scom_addresses.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: proc_tod_setup
//
// parameters: i_tod_node  Reference to TOD topology (FAPI targets included within)
//             i_tod_sel   Specifies the topology to configure
//             i_osc_sel   Specifies the oscillator to use for the master
//
// returns: FAPI_RC_SUCCESS if TOD topology is successfully configured
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode proc_tod_setup(tod_topology_node*           i_tod_node,
                                const proc_tod_setup_tod_sel i_tod_sel,
                                const proc_tod_setup_osc_sel i_osc_sel)
{
    fapi::ReturnCode rc;
    fapi::ATTR_IS_MPIPL_Type is_mpipl = 0x00;

    // Mark HWP entry
    FAPI_INF("proc_tod_setup: Start");

    do
    {
        if (i_tod_node == NULL || i_tod_node->i_target == NULL)
        {
            FAPI_ERR("proc_tod_setup: null node or target passed into function!");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_NULL_NODE);
            break;
        }
        if (!(i_tod_node->i_tod_master && i_tod_node->i_drawer_master))
        {
            FAPI_ERR("proc_tod_setup: non-root (slave) node passed into main function!");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_SETUP_INVALID_TOPOLOGY);
            break;
        }

        FAPI_INF("proc_tod_setup: Configuring %s topology (OSC0 is %s, OSC1 is %s)",
                  (i_tod_sel==TOD_PRIMARY)?"Primary":"Secondary",
                  (i_osc_sel==TOD_OSC_0             ||
                   i_osc_sel==TOD_OSC_0_AND_1       ||
                   i_osc_sel==TOD_OSC_0_AND_1_SEL_0 ||
                   i_osc_sel==TOD_OSC_0_AND_1_SEL_1)?"connected":"not connected",
                  (i_osc_sel==TOD_OSC_1             ||
                   i_osc_sel==TOD_OSC_0_AND_1       ||
                   i_osc_sel==TOD_OSC_0_AND_1_SEL_0 ||
                   i_osc_sel==TOD_OSC_0_AND_1_SEL_1)?"connected":"not connected");

        // calculate_node_delays populates o_int_path_delay for each node
        rc = calculate_node_delays(i_tod_node);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_setup: Failure calculating TOD delays!");
            break;
        }
        display_tod_nodes(i_tod_node,0);

        rc =  FAPI_ATTR_GET(ATTR_IS_MPIPL, NULL, is_mpipl);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_setup: fapiGetAttribute of ATTR_IS_MPIPL failed!");
            break;
        }

        // If there is a previous topology, it needs to be cleared
        rc = clear_tod_node(i_tod_node, i_tod_sel, is_mpipl);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_setup: Failure clearing previous TOD configuration!");
            break;
        }

        //Start configuring each node; (configure_tod_node will recurse on each child)
        rc = configure_tod_node(i_tod_node,i_tod_sel,i_osc_sel);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_setup: Failure configuring TOD!");
            break;
        }

    } while (0);

    FAPI_INF("proc_tod_setup: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: clear_tod_topology
//
// parameters: i_tod_node  Reference to TOD topology (FAPI targets included within)
//             i_tod_sel   Specifies the topology to clear
//             i_is_mpipl  if this IPL is an MPIPL, additional setup is needed;
//                         determined via an attribute
//
// returns: FAPI_RC_SUCCESS if TOD topology is successfully cleared
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode clear_tod_node(tod_topology_node*             i_tod_node,
                                const proc_tod_setup_tod_sel   i_tod_sel,
                                const fapi::ATTR_IS_MPIPL_Type i_is_mpipl)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase data(64);
    fapi::Target* target = i_tod_node->i_target;
    uint32_t port_ctrl_reg = 0;
    uint32_t port_ctrl_check_reg = 0;

    FAPI_INF("clear_tod_node: Clearing previous %s topology from %s",
              (i_tod_sel==TOD_PRIMARY)?"Primary":"Secondary",
              target->toEcmdString());
    do
    {
        if (i_tod_sel==TOD_PRIMARY)
        {
            FAPI_DBG("clear_tod_node: TOD_PRI_PORT_0_CTRL_REG_00040001 and TOD_SEC_PORT_0_CTRL_REG_00040003 will be cleared.");
            port_ctrl_reg = TOD_PRI_PORT_0_CTRL_REG_00040001;
            port_ctrl_check_reg = TOD_SEC_PORT_0_CTRL_REG_00040003;
        }
        else // (i_tod_sel==TOD_SECONDARY)
        {
            FAPI_DBG("clear_tod_node: TOD_PRI_PORT_1_CTRL_REG_00040002 and TOD_SEC_PORT_1_CTRL_REG_00040004 will be cleared.");
            port_ctrl_reg = TOD_SEC_PORT_1_CTRL_REG_00040004;
            port_ctrl_check_reg = TOD_PRI_PORT_1_CTRL_REG_00040002;
        }
        rc = fapiPutScom(*target,port_ctrl_reg,data);
        if (!rc.ok())
        {
            FAPI_ERR("clear_tod_node: fapiPutScom error for port_ctrl_reg SCOM.");
            break;
        }
        rc = fapiPutScom(*target,port_ctrl_check_reg,data);
        if (!rc.ok())
        {
            FAPI_ERR("clear_tod_node: fapiPutScom error for port_ctrl_check_reg SCOM.");
            break;
        }

        if (i_is_mpipl)
        {
            FAPI_INF("clear_tod_node: MPIPL: switch TOD to 'Not Set' state");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(0);
            if (rc_ecmd)
            {
                FAPI_ERR("clear_tod_node: Error 0x%08X in ecmdDataBuffer setup for TOD_TX_TTYPE_5_REG_00040016 SCOM.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(*target, TOD_TX_TTYPE_5_REG_00040016, data);
            if (!rc.ok())
            {
                FAPI_ERR("clear_tod_node: Could not write TOD_TX_TTYPE_5_REG_00040016");
                break;
            }
        }
        else
        {
            FAPI_INF("clear_tod_node: Normal IPL: Bypass TTYPE#5");
        }

        // TOD is cleared for this node; if it has children, start clearing their registers
        for (std::list<tod_topology_node*>::iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            rc = clear_tod_node(tod_node,i_tod_sel,i_is_mpipl);
            if (!rc.ok())
            {
                FAPI_ERR("clear_tod_node: Failure clearing downstream TOD node!");
                break;
            }
        }
        if (!rc.ok())
        {
            break;  // error in above for loop
        }
    } while(0);

    FAPI_INF("clear_tod_node: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: configure_tod_node
//
// parameters: i_tod_node  Reference to TOD topology (FAPI targets included within)
//             i_tod_sel   Specifies the topology to configure
//             i_osc_sel   Specifies the oscillator to use for the master
//
// returns: FAPI_RC_SUCCESS if TOD topology is successfully configured
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode configure_tod_node(tod_topology_node*           i_tod_node,
                                    const proc_tod_setup_tod_sel i_tod_sel,
                                    const proc_tod_setup_osc_sel i_osc_sel)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase data2(64);
    uint32_t rc_ecmd = 0;
    fapi::Target* target = i_tod_node->i_target;

    FAPI_INF("configure_tod_node: Start: Configuring %s", target->toEcmdString());

    do
    {
        const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);

        // Read TOD_PSS_MSS_CTRL_REG_00040007 in order to perserve any prior configuration
        rc=fapiGetScom(*target,TOD_PSS_MSS_CTRL_REG_00040007,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: Error from fapiGetScom when retrieving TOD_PSS_MSS_CTRL_REG_00040007!");
            break;
        }
        FAPI_DBG("configure_tod_node: Set Master TOD/Slave TOD and Master Drawer/Slave Drawer");
        if (i_tod_sel==TOD_PRIMARY)
        {
            if (is_mdmt)
            {
                rc_ecmd |= data.setBit(TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SEL);
                if (i_osc_sel == TOD_OSC_0             ||
                    i_osc_sel == TOD_OSC_0_AND_1       ||
                    i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
                {
                    rc_ecmd |= data.clearBit(TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SEL);
                }
                else if (i_osc_sel == TOD_OSC_1        ||
                         i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
                {
                    rc_ecmd |= data.setBit(TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SEL);
                }
                else // i_osc_sel == TOD_OSC_NONE
                {
                    FAPI_ERR("configure_tod_node: Invalid oscillator configuration!");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_SETUP_INVALID_TOPOLOGY);
                    break;
                }
            }
            else // Slave nodes (Drawer master is still a slave)
            {
                rc_ecmd |= data.clearBit(TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SEL);
            }
            if (i_tod_node->i_drawer_master)
            {
                rc_ecmd |= data.setBit(TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SEL);
            }
        }
        else // (i_tod_sel==TOD_SECONDARY)
        {
            if (is_mdmt)
            {
                rc_ecmd |= data.setBit(TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SEL);
                if (i_osc_sel == TOD_OSC_1       ||
                    i_osc_sel == TOD_OSC_0_AND_1 ||
                    i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
                {
                    rc_ecmd |= data.setBit(TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SEL);
                }
                else if (i_osc_sel == TOD_OSC_0  ||
                         i_osc_sel == TOD_OSC_0_AND_1_SEL_0)
                {
                    rc_ecmd |= data.clearBit(TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SEL);
                }
                else // i_osc_sel == TOD_OSC_NONE
                {
                    FAPI_ERR("configure_tod_node: Invalid oscillator configuration!");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_SETUP_INVALID_TOPOLOGY);
                    break;
                }
            }
            else // Slave nodes (Drawer master is still a slave)
            {
                rc_ecmd |= data.clearBit(TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SEL);
            }
            if (i_tod_node->i_drawer_master)
            {
                rc_ecmd |= data.setBit(TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SEL);
            }
        }
        if (rc_ecmd)
        {
            FAPI_ERR("configure_tod_node: Error 0x%08X in ecmdDataBuffer setup for TOD_PSS_MSS_CTRL_REG_00040007 SCOM.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(*target,TOD_PSS_MSS_CTRL_REG_00040007,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: fapiPutScom error for TOD_PSS_MSS_CTRL_REG_00040007 SCOM.");
            break;
        }

        // Read TOD_S_PATH_CTRL_REG_00040005 in order to perserve any prior configuration
        rc=fapiGetScom(*target,TOD_S_PATH_CTRL_REG_00040005,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: Error from fapiGetScom when retrieving TOD_S_PATH_CTRL_REG_00040005!");
            break;
        }

        // Slave TODs are enabled on all but the MDMT
        if (!is_mdmt)
        {
            FAPI_DBG("configure_tod_node: Selection of Slave OSC path");
            if (i_tod_sel==TOD_PRIMARY)
            {
                rc_ecmd |= data.clearBit(TOD_S_PATH_CTRL_REG_PRI_S_PATH_SEL); // For primary slave, use slave path 0 (path_0_sel=OFF)

                // Set CPS deviation to 75% (CPS deviation bits = 0xC, factor=1), 8 valid steps to enable step check
                rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_FACTOR_1,
                                                TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR,
                                                STEP_CHECK_CPS_DEVIATION_FACTOR_LEN);
                rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_75_00_PCENT,
                                                TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION,
                                                STEP_CHECK_CPS_DEVIATION_LEN);
                rc_ecmd |= data.insertFromRight(STEP_CHECK_VALIDITY_COUNT_8,
                                                TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT,
                                                STEP_CHECK_VALIDITY_COUNT_LEN);
            }
            else // (i_tod_sel==TOD_SECONDARY)
            {
                rc_ecmd |= data.setBit(TOD_S_PATH_CTRL_REG_SEC_S_PATH_SEL);   // For secondary slave, use slave path 1 (path_1_sel=ON)

                // Set CPS deviation to 75% (CPS deviation bits = 0xC, factor=1), 8 valid steps to enable step check
                rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_FACTOR_1,
                                                TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR,
                                                STEP_CHECK_CPS_DEVIATION_FACTOR_LEN);
                rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_75_00_PCENT,
                                                TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION,
                                                STEP_CHECK_CPS_DEVIATION_LEN);
                rc_ecmd |= data.insertFromRight(STEP_CHECK_VALIDITY_COUNT_8,
                                                TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT,
                                                STEP_CHECK_VALIDITY_COUNT_LEN);
            }
            if (rc_ecmd)
            {
                FAPI_ERR("configure_tod_node: Error 0x%08X in ecmdDataBuffer setup for TOD_S_PATH_CTRL_REG_00040005 SCOM.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(*target,TOD_S_PATH_CTRL_REG_00040005,data);
            if (!rc.ok())
            {
                FAPI_ERR("configure_tod_node: fapiPutScom error for TOD_S_PATH_CTRL_REG_00040005 SCOM.");
                break;
            }
        }

        // TOD_PRI_PORT_0_CTRL_REG_00040001 is only used for Primary configurations
        // TOD_SEC_PORT_1_CTRL_REG_00040004 is only used for Secondary configurations
        // In order to check primary and secondary networks are working simultaneously...
        //  - The result of TOD_PRI_PORT_0_CTRL_REG_00040001 are also inserted into TOD_SEC_PORT_0_CTRL_REG_00040003
        //    (preserving i_path_delay which can be different between 40001 and 40003)
        //  - The result of TOD_SEC_PORT_1_CTRL_REG_00040004 are also inserted into TOD_PRI_PORT_1_CTRL_REG_00040002
        uint32_t port_ctrl_reg = 0;
        uint32_t port_ctrl_check_reg = 0;
        if (i_tod_sel==TOD_PRIMARY)
        {
            FAPI_DBG("configure_tod_node: TOD_PRI_PORT_0_CTRL_REG_00040001 will be configured for primary topology");
            port_ctrl_reg = TOD_PRI_PORT_0_CTRL_REG_00040001;
            port_ctrl_check_reg = TOD_SEC_PORT_0_CTRL_REG_00040003;
        }
        else // (i_tod_sel==TOD_SECONDARY)
        {
            FAPI_DBG("configure_tod_node: TOD_SEC_PORT_1_CTRL_REG_00040004 will be configured for secondary topology");
            port_ctrl_reg = TOD_SEC_PORT_1_CTRL_REG_00040004;
            port_ctrl_check_reg = TOD_PRI_PORT_1_CTRL_REG_00040002;
        }

        // Read port_ctrl_reg in order to perserve any prior configuration
        rc = fapiGetScom(*target,port_ctrl_reg,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: Error from fapiGetScom when retrieving port_ctrl_reg!");
            break;
        }

        // Read port_ctrl_check_reg in order to perserve any prior configuration
        rc = fapiGetScom(*target,port_ctrl_check_reg,data2);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: Error from fapiGetScom when retrieving port_ctrl_check_reg!");
            break;
        }

        //Determine RX port
        uint32_t port_rx_select_val = 0;
        switch (i_tod_node->i_bus_rx)
        {
            case(NONE):  break; // MDMT has no rx
            case(XBUS0): port_rx_select_val = TOD_PORT_CTRL_REG_RX_X0_SEL; break;
            case(XBUS1): port_rx_select_val = TOD_PORT_CTRL_REG_RX_X1_SEL; break;
            case(XBUS2): port_rx_select_val = TOD_PORT_CTRL_REG_RX_X2_SEL; break;
            case(XBUS3): port_rx_select_val = TOD_PORT_CTRL_REG_RX_X3_SEL; break;
            case(ABUS0): port_rx_select_val = TOD_PORT_CTRL_REG_RX_A0_SEL; break;
            case(ABUS1): port_rx_select_val = TOD_PORT_CTRL_REG_RX_A1_SEL; break;
            case(ABUS2): port_rx_select_val = TOD_PORT_CTRL_REG_RX_A2_SEL; break;
        }
        rc_ecmd |= data.insertFromRight(port_rx_select_val,
                                        TOD_PORT_CTRL_REG_RX,
                                        TOD_PORT_CTRL_REG_RX_LEN);
        rc_ecmd |= data2.insertFromRight(port_rx_select_val,
                                        TOD_PORT_CTRL_REG_RX,
                                        TOD_PORT_CTRL_REG_RX_LEN);

        //Determine which tx path should be selected for all children
        uint32_t path_sel = 0;
        if (is_mdmt)
        {
            if (i_tod_sel==TOD_PRIMARY)
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
                else // i_osc_sel == TOD_OSC_NONE
                {
                    FAPI_ERR("configure_tod_node: Invalid oscillator configuration!");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_SETUP_INVALID_TOPOLOGY);
                    break;
                }
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
                else // i_osc_sel == TOD_OSC_NONE
                {
                    FAPI_ERR("configure_tod_node: Invalid oscillator configuration!");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_SETUP_INVALID_TOPOLOGY);
                    break;
                }
            }
        }
        else // Chip is not master; slave path selected
        {
            if (i_tod_sel==TOD_PRIMARY)
            {
                path_sel = TOD_PORT_CTRL_REG_S_PATH_0;
            }
            else // (i_tod_sel==TOD_SECONDARY)
            {
                path_sel = TOD_PORT_CTRL_REG_S_PATH_1;
            }
        }

        // Loop through all of the out busses, determine which tx buses to enable as senders
        uint32_t bus_sel    = 0;
        uint32_t bus_sel_en = 0;

        for (std::list<tod_topology_node*>::iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            switch (tod_node->i_bus_tx)
            {
                case(NONE):  FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_SETUP_INVALID_TOPOLOGY); break;
                case(XBUS0): bus_sel = TOD_PORT_CTRL_REG_TX_X0; bus_sel_en = TOD_PORT_CTRL_REG_TX_X0_EN; break;
                case(XBUS1): bus_sel = TOD_PORT_CTRL_REG_TX_X1; bus_sel_en = TOD_PORT_CTRL_REG_TX_X1_EN; break;
                case(XBUS2): bus_sel = TOD_PORT_CTRL_REG_TX_X2; bus_sel_en = TOD_PORT_CTRL_REG_TX_X2_EN; break;
                case(XBUS3): bus_sel = TOD_PORT_CTRL_REG_TX_X3; bus_sel_en = TOD_PORT_CTRL_REG_TX_X3_EN; break;
                case(ABUS0): bus_sel = TOD_PORT_CTRL_REG_TX_A0; bus_sel_en = TOD_PORT_CTRL_REG_TX_A0_EN; break;
                case(ABUS1): bus_sel = TOD_PORT_CTRL_REG_TX_A1; bus_sel_en = TOD_PORT_CTRL_REG_TX_A1_EN; break;
                case(ABUS2): bus_sel = TOD_PORT_CTRL_REG_TX_A2; bus_sel_en = TOD_PORT_CTRL_REG_TX_A2_EN; break;
            }
            if (!rc.ok())
            {
                break;  // error in above switch
            }
            rc_ecmd |= data.insertFromRight(path_sel, bus_sel, TOD_PORT_CTRL_REG_TX_LEN);
            rc_ecmd |= data.setBit(bus_sel_en);
            rc_ecmd |= data2.insertFromRight(path_sel, bus_sel, TOD_PORT_CTRL_REG_TX_LEN);
            rc_ecmd |= data2.setBit(bus_sel_en);
        }
        if (!rc.ok())
        {
            break;  // error in above for loop
        }
        if (rc_ecmd)
        {
            FAPI_ERR("configure_tod_node: Error 0x%08X in ecmdDataBuffer setup for port_ctrl_reg/port_ctrl_check_reg SCOM.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // All children have been configured; save both port configurations!
        rc = fapiPutScom(*target,port_ctrl_reg,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: fapiPutScom error for port_ctrl_reg SCOM.");
            break;
        }
        rc = fapiPutScom(*target,port_ctrl_check_reg,data2);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: fapiPutScom error for port_ctrl_check_reg SCOM.");
            break;
        }

        // Read TOD_M_PATH_CTRL_REG_00040000 in order to perserve any prior configuration
        rc=fapiGetScom(*target,TOD_M_PATH_CTRL_REG_00040000,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: Error from fapiGetScom when retrieving TOD_M_PATH_CTRL_REG_00040000!");
            break;
        }

        // Configure Master OSC0/OSC1 path
        if (is_mdmt)
        {
            FAPI_DBG("configure_tod_node: Configuring Master OSC path in TOD_M_PATH_CTRL_REG_00040000");

            if (i_osc_sel == TOD_OSC_0             ||
                i_osc_sel == TOD_OSC_0_AND_1       ||
                i_osc_sel == TOD_OSC_0_AND_1_SEL_0 ||
                i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
            {
                FAPI_DBG("configure_tod_node: OSC0 is valid; master path-0 will be configured.");

                // OSC0 is connected
                rc_ecmd |= data.clearBit(TOD_M_PATH_CTRL_REG_M_PATH_0_OSC_NOT_VALID);

                // OSC0 step alignment enabled
                rc_ecmd |= data.clearBit(TOD_M_PATH_CTRL_REG_M_PATH_0_STEP_ALIGN_DIS);

                // Set 512 steps per sync for path 0
                rc_ecmd |= data.insertFromRight(TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_512,
                                                TOD_M_PATH_CTRL_REG_M_PATH_0_SYNC_FREQ_SEL,
                                                TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_LEN);

                // Set step check CPS deviation to 50%
                rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_50_00_PCENT,
                                                TOD_M_PATH_CTRL_REG_M_PATH_0_STEP_CHECK_CPS_DEVIATION,
                                                STEP_CHECK_CPS_DEVIATION_LEN);

                // 8 valid steps are required before step check is enabled
                rc_ecmd |= data.insertFromRight(STEP_CHECK_VALIDITY_COUNT_8,
                                                TOD_M_PATH_CTRL_REG_M_PATH_0_STEP_CHECK_VALIDITY_COUNT,
                                                STEP_CHECK_VALIDITY_COUNT_LEN);
            }
            else
            {
                FAPI_DBG("configure_tod_node: OSC0 is not connected.");

                // OSC0 is not connected; any previous path-0 settings will be ignored
                rc_ecmd |= data.setBit(TOD_M_PATH_CTRL_REG_M_PATH_0_OSC_NOT_VALID);
            }
            if (i_osc_sel == TOD_OSC_1             ||
                i_osc_sel == TOD_OSC_0_AND_1       ||
                i_osc_sel == TOD_OSC_0_AND_1_SEL_0 ||
                i_osc_sel == TOD_OSC_0_AND_1_SEL_1)
            {
                FAPI_DBG("configure_tod_node: OSC1 is valid; master path-1 will be configured.");

                // OSC1 is connected
                rc_ecmd |= data.clearBit(TOD_M_PATH_CTRL_REG_M_PATH_1_OSC_NOT_VALID);

                // OSC1 step alignment enabled
                rc_ecmd |= data.clearBit(TOD_M_PATH_CTRL_REG_M_PATH_1_STEP_ALIGN_DIS);

                // Set 512 steps per sync for path 1
                rc_ecmd |= data.insertFromRight(TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_512,
                                                TOD_M_PATH_CTRL_REG_M_PATH_1_SYNC_FREQ_SEL,
                                                TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_LEN);

                // Set step check CPS deviation to 50%
                rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_50_00_PCENT,
                                                TOD_M_PATH_CTRL_REG_M_PATH_1_STEP_CHECK_CPS_DEVIATION,
                                                STEP_CHECK_CPS_DEVIATION_LEN);

                // 8 valid steps are required before step check is enabled
                rc_ecmd |= data.insertFromRight(STEP_CHECK_VALIDITY_COUNT_8,
                                                TOD_M_PATH_CTRL_REG_M_PATH_1_STEP_CHECK_VALIDITY_COUNT,
                                                STEP_CHECK_VALIDITY_COUNT_LEN);
            }
            else
            {
                FAPI_DBG("configure_tod_node: OSC1 is not connected.");

                // OSC1 is not connected; any previous path-1 settings will be ignored
                rc_ecmd |= data.setBit(TOD_M_PATH_CTRL_REG_M_PATH_1_OSC_NOT_VALID);
            }

            // CPS deviation factor configures both path-0 and path-1
            rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_FACTOR_1,
                                            TOD_M_PATH_CTRL_REG_M_PATH_STEP_CHECK_DEVIATION_FACTOR,
                                            STEP_CHECK_CPS_DEVIATION_FACTOR_LEN);

            if (rc_ecmd)
            {
                FAPI_ERR("configure_tod_node: Error 0x%08X in ecmdDataBuffer setup for TOD_M_PATH_CTRL_REG_00040000 SCOM.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(*target,TOD_M_PATH_CTRL_REG_00040000,data);
            if (!rc.ok())
            {
                FAPI_ERR("configure_tod_node: fapiPutScom error for TOD_M_PATH_CTRL_REG_00040000 SCOM.");
                break;
            }
        }

        FAPI_DBG("configure_tod_node: Setting internal path delay");
        // This is the number of TOD-grid-cycles to delay the internal path (0-0xFF valid); 1 TOD-grid-cycle = 400ps (default)
        if (i_tod_sel==TOD_PRIMARY)
        {
            // Primary topology internal path delay set TOD_PRI_PORT_0_CTRL_REG_00040001, regardless of master/slave/port
            FAPI_DBG("configure_tod_node: TOD_PRI_PORT_0_CTRL_REG_00040001 will be used to set internal delay");
            port_ctrl_reg = TOD_PRI_PORT_0_CTRL_REG_00040001;
        }
        else // (i_tod_sel==TOD_SECONDARY)
        {
            // Secondary topology internal path delay set TOD_SEC_PORT_0_CTRL_REG_00040003 regardless of master/slave/port
            FAPI_DBG("configure_tod_node: TOD_SEC_PORT_0_CTRL_REG_00040003 will be used to set internal delay");
            port_ctrl_reg = TOD_SEC_PORT_0_CTRL_REG_00040003;
        }
        rc=fapiGetScom(*target,port_ctrl_reg,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: Error from fapiGetScom when retrieving port_ctrl_reg!");
            break;
        }
        FAPI_DBG("configure_tod_node: configuring an internal delay of %d TOD-grid-cycles", i_tod_node->o_int_path_delay);
        rc_ecmd |= data.insertFromRight(i_tod_node->o_int_path_delay,
                                        TOD_PORT_CTRL_REG_I_PATH_DELAY,
                                        TOD_PORT_CTRL_REG_I_PATH_DELAY_LEN);
        if (rc_ecmd)
        {
            FAPI_ERR("configure_tod_node: Error 0x%08X in ecmdDataBuffer setup for port_ctrl_reg SCOM.", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(*target,port_ctrl_reg,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: fapiPutScom error for port_ctrl_reg SCOM.");
            break;
        }

        FAPI_DBG("configure_tod_node: Enable delay logic in TOD_I_PATH_CTRL_REG_00040006");
        // Read TOD_I_PATH_CTRL_REG_00040006 in order to perserve any prior configuration
        rc=fapiGetScom(*target,TOD_I_PATH_CTRL_REG_00040006,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: Error from fapiGetScom when retrieving TOD_I_PATH_CTRL_REG_00040006!");
            break;
        }

        // Ensure delay is enabled
        rc_ecmd |= data.clearBit(TOD_I_PATH_CTRL_REG_DELAY_DIS);
        rc_ecmd |= data.clearBit(TOD_I_PATH_CTRL_REG_DELAY_ADJUST_DIS);

        // Deviation for internal OSC should be set to max, allowing backup master TOD to run the active topology,
        // when switching from Slave OSC path to Master OSC path
        rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_93_75_PCENT,
                                        TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION,
                                        STEP_CHECK_CPS_DEVIATION_LEN);
        rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_FACTOR_1,
                                        TOD_M_PATH_CTRL_REG_M_PATH_STEP_CHECK_DEVIATION_FACTOR,
                                        STEP_CHECK_CPS_DEVIATION_FACTOR_LEN);
        rc_ecmd |= data.insertFromRight(STEP_CHECK_VALIDITY_COUNT_8,
                                        TOD_I_PATH_CTRL_REG_STEP_CHECK_VALIDITY_COUNT,
                                        STEP_CHECK_VALIDITY_COUNT_LEN);
        if (rc_ecmd)
        {
            FAPI_ERR("configure_tod_node: Error 0x%08X in ecmdDataBuffer setup for TOD_I_PATH_CTRL_REG_00040006 SCOM.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(*target,TOD_I_PATH_CTRL_REG_00040006,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: fapiPutScom error for TOD_I_PATH_CTRL_REG_00040006 SCOM.");
            break;
        }

        FAPI_DBG("configure_tod_node: Set low order step value to 3F in TOD_CHIP_CTRL_REG_00040010");
        // Read TOD_CHIP_CTRL_REG_00040010 in order to perserve any prior configuration
        rc=fapiGetScom(*target,TOD_CHIP_CTRL_REG_00040010,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: Error from fapiGetScom when retrieving TOD_CHIP_CTRL_REG_00040010!");
            break;
        }

        rc = init_chip_ctrl_reg(data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: Error from init_chip_ctrl_reg while setting TOD_CHIP_CTRL_REG_00040010");
            break;
        }

        rc = fapiPutScom(*target,TOD_CHIP_CTRL_REG_00040010,data);
        if (!rc.ok())
        {
            FAPI_ERR("configure_tod_node: fapiPutScom error for TOD_CHIP_CTRL_REG_00040010 SCOM.");
            break;
        }

        // TOD is configured for this node; if it has children, start their configuration
        for (std::list<tod_topology_node*>::iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            rc = configure_tod_node(tod_node,i_tod_sel,i_osc_sel);
            if (!rc.ok())
            {
                FAPI_ERR("configure_tod_node: Failure configuring downstream node!");
                break;
            }
        }
        if (!rc.ok())
        {
            break;  // error in above for loop
        }
    } while(0);

    FAPI_INF("configure_tod_node: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: display_tod_node
//
// parameters: i_tod_node  Reference to TOD topology
//
// returns: nothing (display-only helper function)
//------------------------------------------------------------------------------
void display_tod_nodes(const tod_topology_node* i_tod_node, const uint32_t i_depth)
{

    do
    {
        if (i_tod_node == NULL || i_tod_node->i_target == NULL)
        {
            FAPI_ERR("display_tod_nodes: NULL tod_node or target passed to display_tod_nodes()!");
            break;
        }
        FAPI_INF("display_tod_nodes: %s (Delay = %d)",i_tod_node->i_target->toEcmdString(),
                                                      i_tod_node->o_int_path_delay);

        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            display_tod_nodes(*child,i_depth+1);
        }
    } while(0);
}

//------------------------------------------------------------------------------
// function: calculate_node_delays
//
// parameters: i_tod_node  Reference to TOD topology
//
// returns: FAPI_RC_SUCCESS if TOD topology is successfully configured with delays
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode calculate_node_delays(tod_topology_node* i_tod_node)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);

    FAPI_INF("calculate_node_delays: Start");
    do
    {
        // retrieve X-bus and A-bus frequencies
        uint32_t freq_x = 0;
        uint32_t freq_a = 0;
        rc = FAPI_ATTR_GET(ATTR_FREQ_X, NULL, freq_x);
        if (!rc.ok())
        {
            FAPI_ERR("calculate_node_delays: Failure reading XBUS frequency attribute!");
            break;
        }
        rc = FAPI_ATTR_GET(ATTR_FREQ_A, NULL, freq_a);
        if (!rc.ok())
        {
            FAPI_ERR("calculate_node_delays: Failure reading ABUS frequency attribute!");
            break;
        }

        // Bus frequencies are global for the system (i.e. A0 and A1 will always run with the same frequency)
        FAPI_DBG("calculate_node_delays: XBUS=%dMHz ABUS=%dMHz", freq_x, freq_a);

        // Find the most-delayed path in the topology; this is the MDMT's delay
        uint32_t longest_delay = 0;
        rc = calculate_longest_topolopy_delay(i_tod_node, freq_x, freq_a, &longest_delay);
        if (!rc.ok())
        {
            FAPI_ERR("calculate_node_delays: Failure calculating longest topology delay!");
            break;
        }
        FAPI_DBG("calculate_node_delays: the longest delay is %d TOD-grid-cycles.", longest_delay);

        rc = set_topology_delays(i_tod_node, freq_x, freq_a, longest_delay);
        if (!rc.ok())
        {
            FAPI_ERR("calculate_node_delays: Unable to set topology delays!");
            break;
        }

        // Finally, the MDMT delay must include additional TOD-grid-cycles to account for staging latches in slaves
        i_tod_node->o_int_path_delay += MDMT_TOD_GRID_CYCLE_STAGING_DELAY;
    } while(0);

    FAPI_INF("calculate_node_delays: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: calculate_longest_topolopy_delay
//
// parameters: i_tod_node      Reference to TOD topology
//             i_freq_x        XBUS frequency in MHz
//             i_freq_a        ABUS frequency in MHz
//             o_longest_delay Contains the longest delay for the topology in TOD-grid-cycles
//                             (This is the delay of MDMT; children are derived from this)
//
// returns: FAPI_RC_SUCCESS if a longest TOD delay was found in topology
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode calculate_longest_topolopy_delay(tod_topology_node* i_tod_node,
                                                  const uint32_t     i_freq_x,
                                                  const uint32_t     i_freq_a,
                                                  uint32_t*          o_longest_delay)
{
    fapi::ReturnCode rc;

    FAPI_INF("calculate_longest_topolopy_delay: Start");

    do
    {
        uint32_t node_delay = 0;

        rc = calculate_node_link_delay(i_tod_node, i_freq_x, i_freq_a, &node_delay);
        if (!rc.ok())
        {
            FAPI_ERR("calculate_longest_topolopy_delay: Failure calculating single node delay!");
            break;
        }
        *o_longest_delay = node_delay;

        uint32_t current_longest_delay = 0;
        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            rc = calculate_longest_topolopy_delay(tod_node, i_freq_x, i_freq_a, &node_delay);
            if (!rc.ok())
            {
                FAPI_ERR("calculate_longest_topolopy_delay: Failure calculating topology delay!");
                break;
            }
            if (node_delay>current_longest_delay)
            {
                current_longest_delay=node_delay;
            }
        }
        if (!rc.ok())
        {
            break;  // error in above for loop
        }
        *o_longest_delay += current_longest_delay;
    } while(0);

    FAPI_INF("calculate_longest_topolopy_delay: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: calculate_node_link_delay
//
// parameters: i_tod_node      Reference to TOD topology
//             i_freq_x        XBUS frequency in MHz
//             i_freq_a        ABUS frequency in MHz
//             o_node_delay    Delay of a single node in TOD-grid-cycles
//                             (Does not include upstream or downstream delays)
//
// returns: FAPI_RC_SUCCESS if TOD node delay is successfully calculated
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode calculate_node_link_delay(tod_topology_node* i_tod_node,
                                           const uint32_t     i_freq_x,
                                           const uint32_t     i_freq_a,
                                           uint32_t*          o_node_delay)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    uint32_t rc_ecmd = 0;
    fapi::Target* target = i_tod_node->i_target;

    FAPI_INF("calculate_node_link_delay: Start");

    do
    {
        // MDMT is originator and therefore has no node delay
        if (i_tod_node->i_tod_master && i_tod_node->i_drawer_master)
        {
            *o_node_delay = 0;
        }
        else // slave node
        {
            uint32_t bus_mode_addr = 0;
            uint32_t bus_mode_sel = 0;
            uint32_t bus_freq = 0;
            uint8_t  bus_delay = 0;
            switch (i_tod_node->i_bus_rx)
            {
                case(NONE):  FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_SETUP_INVALID_TOPOLOGY); break;
                case(XBUS0): bus_freq = i_freq_x; bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X0_ROUND_TRIP_DELAY; break;
                case(XBUS1): bus_freq = i_freq_x; bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X1_ROUND_TRIP_DELAY; break;
                case(XBUS2): bus_freq = i_freq_x; bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X2_ROUND_TRIP_DELAY; break;
                case(XBUS3): bus_freq = i_freq_x; bus_mode_addr = PB_X_MODE_0x04010C0A; bus_mode_sel = PB_X_MODE_LINK_X3_ROUND_TRIP_DELAY; break;
                case(ABUS0): bus_freq = i_freq_a; bus_mode_addr = PB_A_MODE_0x0801080A; bus_mode_sel = PB_A_MODE_LINK_A0_ROUND_TRIP_DELAY; break;
                case(ABUS1): bus_freq = i_freq_a; bus_mode_addr = PB_A_MODE_0x0801080A; bus_mode_sel = PB_A_MODE_LINK_A1_ROUND_TRIP_DELAY; break;
                case(ABUS2): bus_freq = i_freq_a; bus_mode_addr = PB_A_MODE_0x0801080A; bus_mode_sel = PB_A_MODE_LINK_A2_ROUND_TRIP_DELAY; break;
            }
            if (!rc.ok())
            {
                break;  // error in above switch
            }
            rc=fapiGetScom(*target,bus_mode_addr,data);
            if (!rc.ok())
            {
                FAPI_ERR("calculate_node_link_delay: Error from fapiGetScom when retrieving bus_mode_addr!");
                break;
            }
            rc_ecmd = data.extract(&bus_delay, bus_mode_sel, LINK_ROUND_TRIP_DELAY_LEN);
            if (rc_ecmd)
            {
                FAPI_ERR("calculate_node_link_delay: Error 0x%08X in ecmdDataBuffer extract.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // By default, the TOD grid runs at 400ps; TOD counts its delay based on this
            // Example: Bus round trip delay is 35 cycles and the bus is running at 4800MHz
            //            - Divide by 2 to get one-way delay time
            //            - Divide by 4800 * 10^6 to get delay in seconds
            //            - Multiply by 10^12 to get delay in picoseconds
            //            - Divide by 400ps to get TOD-grid-cycles
            //            - (To avoid including math.h) Add 1 and cast to uint32_t to round up to nearest TOD-grid-cycle
            //            - (To avoid including math.h) 10^12/10^6=1000000
            //            - (uint32_t)((        35        / 2 /        (4800      * 10^6) * 10^12 / 400        ) + 1) = 10 TOD-grid-cycles
            *o_node_delay = (uint32_t)(((double)bus_delay / 2 / (double)bus_freq  * 1000000       / TOD_GRID_PS) + 1);
        }
        // This is not the final internal path delay, only saved so two calls aren't needed to calculate_node_link_delay
        i_tod_node->o_int_path_delay = *o_node_delay;

        FAPI_DBG("calculate_node_link_delay: TOD-grid-cycles for single link: %d", *o_node_delay);
    } while(0);

    FAPI_INF("calculate_node_link_delay: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: set_topology_delays
//
// parameters: i_tod_node      Reference to TOD topology
//             i_freq_x        XBUS frequency in MHz
//             i_freq_a        ABUS frequency in MHz
//             i_longest_delay Longest topology delay; sub-delays are computed from it
//
// returns: FAPI_RC_SUCCESS if o_int_path_delay was set for every node in the topology
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode set_topology_delays(tod_topology_node* i_tod_node,
                                     const uint32_t     i_freq_x,
                                     const uint32_t     i_freq_a,
                                     const uint32_t     i_longest_delay)
{
    fapi::ReturnCode rc;
    FAPI_INF("set_topology_delays: Start");

    do
    {
        // Retreive saved node_delay from calculate_node_link_delay instead of making a second call
        i_tod_node->o_int_path_delay=i_longest_delay-(i_tod_node->o_int_path_delay);

        // Verify the delay is between 0 and 255 inclusive.
        if (i_tod_node->o_int_path_delay<MIN_TOD_DELAY ||
            i_tod_node->o_int_path_delay>MAX_TOD_DELAY)
        {
            FAPI_ERR("set_topology_delays: Invalid delay of %d calculated!", i_tod_node->o_int_path_delay);
            FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_SETUP_INVALID_NODE_DELAY);
            break;
        }

        // Recurse on downstream nodes
        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            rc = set_topology_delays(tod_node,i_freq_x,i_freq_a,i_tod_node->o_int_path_delay);
            if (!rc.ok())
            {
                FAPI_ERR("set_topology_delays: Failure calculating topology delay!");
                break;
            }
        }
    } while(0);

    FAPI_INF("set_topology_delays: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: init_chip_ctrl_reg
//
// parameters: o_chic_ctrlReg_val => ecmdDataBuffer containing the
//          Chip Control Status Register configuration
//
// returns: FAPI_RC_SUCCESS if TOD_CHIP_CTRL_REG_00040010's value was successfully
//          calculated else ECMD error is sent back
//
//------------------------------------------------------------------------------
fapi::ReturnCode init_chip_ctrl_reg (ecmdDataBufferBase& o_chic_ctrlReg_val)
{
    fapi::ReturnCode rc;
    FAPI_INF("init_chip_ctrl_reg: Start");

    do
    {
        uint32_t rc_ecmd = 0;

        // Default core sync period is 8us
        rc_ecmd |= o_chic_ctrlReg_val.insertFromRight(TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_8,
                                                      TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL,
                                                      TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_LEN);

        // Enable internal path sync check
        rc_ecmd |= o_chic_ctrlReg_val.clearBit(TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DIS);

        // 1x sync boundaries for Move-TOD-To-Timebase
        rc_ecmd |= o_chic_ctrlReg_val.clearBit(TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_EN);

        // Use eclipz sync mechanism
        rc_ecmd |= o_chic_ctrlReg_val.clearBit(TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM);

        // Use timebase step sync from internal path
        rc_ecmd |= o_chic_ctrlReg_val.clearBit(TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC);

        // Chip TOD WOF incrementer ratio (eclipz mode)
        // 4-bit WOF counter is incremented with each 200MHz clock cycle
        rc_ecmd |= o_chic_ctrlReg_val.insertFromRight(TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_3F,
                                                      TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL,
                                                      TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_LEN);

        // Stop TOD when system checkstop occurs
        rc_ecmd |= o_chic_ctrlReg_val.clearBit(TOD_CHIP_CTRL_REG_XSTOP_GATE);

        if (rc_ecmd)
        {
            FAPI_ERR("init_chip_ctrl_reg: Error 0x%08X in ecmdDataBuffer",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

    } while(0);

    FAPI_INF("init_chip_ctrl_reg: End");
    return rc;
}

} // extern "C"
